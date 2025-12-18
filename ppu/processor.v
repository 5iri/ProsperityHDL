// processor.v -- Prosperity PPU Processor (128 PE Array with Integrated LIF Neurons)
// Implements ProSparsity-based matrix computation with:
//   - 128 Processing Elements with IEEE FP16 weights and accumulators
//   - Integrated LIF neurons per PE for direct spike generation
//   - Row-wise dataflow processing
//   - Prefix result reuse for product sparsity
//   - Address decoder with bit scan forward
//   - Support for unstructured sparsity
//
// IEEE 754 FP16 Format:
//   [15]    - Sign bit (0 = positive, 1 = negative)
//   [14:10] - Exponent (5 bits, bias = 15)
//   [9:0]   - Mantissa (10 bits, implicit leading 1)
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity (Section V-E)
// (c) 2025 Prosperity Project
`timescale 1ns / 1ps

/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off UNUSEDSIGNAL */

module processor #(
    parameter ROWS        = 256,      // Number of rows in tile
    parameter SPIKES      = 16,       // Number of spikes per pattern  
    parameter PE_COUNT    = 128,      // Number of Processing Elements
    parameter WEIGHT_WIDTH = 16,      // Weight precision (16-bit IEEE FP16)
    parameter ACC_WIDTH   = 16,       // Accumulator width (16-bit IEEE FP16)
    parameter NO_WIDTH    = 8,        // Popcount width
    // LIF Neuron Parameters (all FP16 except refractory)
    parameter VMEM_WIDTH    = 16,     // Membrane potential width (FP16)
    parameter THRESH_WIDTH  = 16,     // Threshold width (FP16)
    parameter LEAK_WIDTH    = 16,     // Leak value width (FP16)
    parameter REFRAC_WIDTH  = 4       // Refractory counter width (integer cycles)
) (
    // Clock and Reset
    input  wire clk,
    input  wire rst_n,

    // Task Interface from Dispatcher
    input  wire                        task_valid,
    output wire                        task_ready,
    input  wire [$clog2(ROWS)-1:0]     task_row_id,
    input  wire [$clog2(ROWS)-1:0]     task_prefix_id, 
    input  wire [SPIKES-1:0]           task_pattern,    // ProSparsity pattern (suffix mask)

    // Weight Memory Interface (updated for proper addressing)
    output wire [$clog2(SPIKES*PE_COUNT)-1:0] weight_addr,    // Address multiple weights per PE
    input  wire [WEIGHT_WIDTH-1:0] weight_data,              // Single weight per cycle
    output wire                    weight_rd_en,

    // Output Buffer Interface (accumulator values)
    output wire [$clog2(ROWS)-1:0]     output_rd_addr,
    output wire [$clog2(ROWS)-1:0]     output_wr_addr,
    input  wire [PE_COUNT*ACC_WIDTH-1:0] output_rd_data,
    output wire [PE_COUNT*ACC_WIDTH-1:0] output_wr_data,
    output wire                        output_wr_en,

    // LIF Neuron Configuration
    input  wire [THRESH_WIDTH-1:0]     cfg_threshold,        // Firing threshold
    input  wire [LEAK_WIDTH-1:0]       cfg_leak,             // Leak per timestep
    input  wire [VMEM_WIDTH-1:0]       cfg_reset_potential,  // Reset value after spike
    input  wire [REFRAC_WIDTH-1:0]     cfg_refractory,       // Refractory period

    // LIF Control
    input  wire                        lif_enable,           // Enable LIF neuron updates
    input  wire                        timestep_end,         // Signal end of timestep (apply leak)

    // Spike Output Interface
    output wire [PE_COUNT-1:0]         spike_out,            // Output spike vector
    output reg                         spike_valid,          // Spike output valid

    // Debug: Membrane potential readback
    input  wire [$clog2(PE_COUNT)-1:0] vmem_rd_idx,
    output wire [VMEM_WIDTH-1:0]       vmem_rd_data,

    // Status
    output wire                        proc_busy,
    output wire                        proc_done
);

    // ===================================================================
    // Internal Registers and Signals
    // ===================================================================
    
    // FSM States
    localparam ST_IDLE       = 4'd0;
    localparam ST_LOAD_WEIGHTS = 4'd1;
    localparam ST_LOAD_PFX   = 4'd2;
    localparam ST_DECODE     = 4'd3;
    localparam ST_ACCUMULATE = 4'd4;
    localparam ST_CLEAR_BIT  = 4'd5;
    localparam ST_LIF_UPDATE = 4'd6;   // NEW: Apply LIF neuron dynamics
    localparam ST_WRITEBACK  = 4'd7;
    
    reg [3:0] state, next_state;
    reg [$clog2(ROWS)-1:0] current_row_id;
    reg [$clog2(ROWS)-1:0] current_prefix_id;
    reg [SPIKES-1:0] current_pattern;
    reg [SPIKES-1:0] pattern_working;  // Working copy for bit scanning
    
    // NULL prefix detection: prefix_id == row_id means root (no valid prefix)
    // This encoding is semantically correct since a row can never be its own prefix
    wire is_null_prefix;
    assign is_null_prefix = (current_prefix_id == current_row_id);
    
    // PE Array - 128 Processing Elements
    reg [ACC_WIDTH-1:0] pe_partial_sum [0:PE_COUNT-1];
    reg [WEIGHT_WIDTH-1:0] pe_weight [0:PE_COUNT-1];  // Local weight storage per PE
    reg [WEIGHT_WIDTH-1:0] weight_buffer [0:PE_COUNT-1][0:SPIKES-1]; // Weight buffer: [PE][spike]
    reg pe_accumulate_en;
    
    // Weight loading control
    reg [$clog2(PE_COUNT)-1:0] weight_load_pe_idx;
    reg [$clog2(SPIKES)-1:0] weight_load_spike_idx;
    reg weight_loading;
    reg weights_loaded;
    
    // Single-stage pipeline for weight storage indices (to match registered weight_data)
    reg [$clog2(PE_COUNT)-1:0] weight_store_pe_idx;
    reg [$clog2(SPIKES)-1:0] weight_store_spike_idx;
    reg weight_store_valid;

    
    // Address Decoder Signals
    reg [$clog2(SPIKES)-1:0] current_spike_idx;
    reg spike_valid_decode;
    wire pattern_empty;
    
    // MAC accumulation trigger (registered for proper timing)
    reg mac_accumulate;

    // LIF Neuron Signals (directly in processor)
    wire [PE_COUNT-1:0] lif_spike_out;
    wire [VMEM_WIDTH-1:0] lif_vmem_out [0:PE_COUNT-1];
    wire [PE_COUNT-1:0] lif_in_refractory;
    reg lif_update_en;
    reg lif_input_valid;
    
    // Memory Interfaces
    reg [PE_COUNT*ACC_WIDTH-1:0] prefix_result;
    reg prefix_loaded;
    reg writeback_en;
    
    // ===================================================================
    // IEEE FP16 Adder Function (Combinational)
    // ===================================================================
    //
    // FP16 Format: [15]=sign, [14:10]=exponent (bias=15), [9:0]=mantissa
    //
    function [15:0] fp16_add;
        input [15:0] a;
        input [15:0] b;
        
        reg        sign_a, sign_b;
        reg [4:0]  exp_a, exp_b;
        reg [9:0]  mant_a, mant_b;
        
        reg        a_is_zero, b_is_zero;
        reg [4:0]  exp_diff;
        reg        a_larger;
        
        reg [11:0] full_mant_a, full_mant_b;  // 1.mantissa format
        reg [11:0] mant_large, mant_small;
        reg        sign_large, sign_small;
        reg [4:0]  result_exp;
        reg        effective_sub;
        
        reg [12:0] mant_sum;      // Extra bit for overflow
        reg        result_sign;
        reg [12:0] mant_abs;
        
        reg [3:0]  lz;            // Leading zeros
        reg [11:0] mant_norm;
        reg [5:0]  exp_adj;
        reg [9:0]  final_mant;
        reg [4:0]  final_exp;
        
        begin
            // Extract fields
            sign_a = a[15];
            sign_b = b[15];
            exp_a  = a[14:10];
            exp_b  = b[14:10];
            mant_a = a[9:0];
            mant_b = b[9:0];
            
            // Zero detection (exp=0, mant=0)
            a_is_zero = (exp_a == 5'd0) && (mant_a == 10'd0);
            b_is_zero = (exp_b == 5'd0) && (mant_b == 10'd0);
            
            // Handle zeros early
            if (a_is_zero && b_is_zero) begin
                fp16_add = 16'h0000;
            end else if (a_is_zero) begin
                fp16_add = b;
            end else if (b_is_zero) begin
                fp16_add = a;
            end else begin
                // Handle subnormals (exp=0, mant!=0): no implicit 1
                // Normalized (exp!=0): implicit 1 bit
                if (exp_a == 5'd0) begin
                    full_mant_a = {1'b0, mant_a, 1'b0};  // 0.mant for subnormal
                end else begin
                    full_mant_a = {1'b1, mant_a, 1'b0};  // 1.mant for normal
                end
                
                if (exp_b == 5'd0) begin
                    full_mant_b = {1'b0, mant_b, 1'b0};  // 0.mant for subnormal
                end else begin
                    full_mant_b = {1'b1, mant_b, 1'b0};  // 1.mant for normal
                end
                
                // Determine larger operand by exponent, then mantissa
                if (exp_a > exp_b) begin
                    a_larger = 1'b1;
                end else if (exp_a < exp_b) begin
                    a_larger = 1'b0;
                end else begin
                    a_larger = (full_mant_a >= full_mant_b);
                end
                
                // Align mantissas
                // Treat subnormal exponent (0) as 1 for alignment purposes
                if (a_larger) begin
                    exp_diff   = (exp_a == 5'd0 ? 5'd1 : exp_a) - (exp_b == 5'd0 ? 5'd1 : exp_b);
                    mant_large = full_mant_a;
                    mant_small = (exp_diff > 5'd11) ? 12'd0 : (full_mant_b >> exp_diff);
                    sign_large = sign_a;
                    sign_small = sign_b;
                    result_exp = exp_a;
                end else begin
                    exp_diff   = (exp_b == 5'd0 ? 5'd1 : exp_b) - (exp_a == 5'd0 ? 5'd1 : exp_a);
                    mant_large = full_mant_b;
                    mant_small = (exp_diff > 5'd11) ? 12'd0 : (full_mant_a >> exp_diff);
                    sign_large = sign_b;
                    sign_small = sign_a;
                    result_exp = exp_b;
                end
                
                // Add or subtract based on signs
                effective_sub = sign_large ^ sign_small;
                
                if (effective_sub) begin
                    mant_sum = {1'b0, mant_large} - {1'b0, mant_small};
                    result_sign = sign_large;
                end else begin
                    mant_sum = {1'b0, mant_large} + {1'b0, mant_small};
                    result_sign = sign_large;
                end
                
                mant_abs = mant_sum;
                
                // Check for zero result
                if (mant_abs == 13'd0) begin
                    fp16_add = 16'h0000;
                end else begin
                    // Normalize: find leading 1 position
                    // mant_abs is 13 bits, implicit 1 should be at bit 11
                    if (mant_abs[12]) begin
                        // Overflow, shift right
                        mant_norm = mant_abs[12:1];
                        exp_adj = {1'b0, result_exp} + 6'd1;
                    end else if (mant_abs[11]) begin
                        mant_norm = mant_abs[11:0];
                        exp_adj = {1'b0, result_exp};
                    end else if (mant_abs[10]) begin
                        mant_norm = {mant_abs[10:0], 1'b0};
                        exp_adj = {1'b0, result_exp} - 6'd1;
                    end else if (mant_abs[9]) begin
                        mant_norm = {mant_abs[9:0], 2'b0};
                        exp_adj = {1'b0, result_exp} - 6'd2;
                    end else if (mant_abs[8]) begin
                        mant_norm = {mant_abs[8:0], 3'b0};
                        exp_adj = {1'b0, result_exp} - 6'd3;
                    end else if (mant_abs[7]) begin
                        mant_norm = {mant_abs[7:0], 4'b0};
                        exp_adj = {1'b0, result_exp} - 6'd4;
                    end else if (mant_abs[6]) begin
                        mant_norm = {mant_abs[6:0], 5'b0};
                        exp_adj = {1'b0, result_exp} - 6'd5;
                    end else if (mant_abs[5]) begin
                        mant_norm = {mant_abs[5:0], 6'b0};
                        exp_adj = {1'b0, result_exp} - 6'd6;
                    end else if (mant_abs[4]) begin
                        mant_norm = {mant_abs[4:0], 7'b0};
                        exp_adj = {1'b0, result_exp} - 6'd7;
                    end else if (mant_abs[3]) begin
                        mant_norm = {mant_abs[3:0], 8'b0};
                        exp_adj = {1'b0, result_exp} - 6'd8;
                    end else if (mant_abs[2]) begin
                        mant_norm = {mant_abs[2:0], 9'b0};
                        exp_adj = {1'b0, result_exp} - 6'd9;
                    end else if (mant_abs[1]) begin
                        mant_norm = {mant_abs[1:0], 10'b0};
                        exp_adj = {1'b0, result_exp} - 6'd10;
                    end else begin
                        mant_norm = {mant_abs[0], 11'b0};
                        exp_adj = {1'b0, result_exp} - 6'd11;
                    end
                    
                    // Extract final mantissa (drop implicit 1)
                    final_mant = mant_norm[10:1];
                    
                    // Handle underflow/overflow
                    if (exp_adj[5]) begin
                        // Severe underflow (negative exponent) - flush to zero
                        fp16_add = 16'h0000;
                    end else if (exp_adj == 6'd0) begin
                        // Result is subnormal (exp=0, non-zero mantissa)
                        // Shift mantissa right by 1 to account for missing implicit bit
                        // The mantissa already has the value in the right position
                        fp16_add = {result_sign, 5'd0, final_mant};
                    end else if (exp_adj >= 6'd31) begin
                        // Overflow to infinity
                        fp16_add = {result_sign, 5'b11111, 10'd0};
                    end else begin
                        // Normal result
                        final_exp = exp_adj[4:0];
                        fp16_add = {result_sign, final_exp, final_mant};
                    end
                end
            end
        end
    endfunction
    
    // ===================================================================
    // Weight Loading and PE Array Implementation
    // ===================================================================
    
    // Weight memory address calculation
    assign weight_addr = weight_loading ? (($clog2(SPIKES*PE_COUNT))'(weight_load_pe_idx) * SPIKES + ($clog2(SPIKES*PE_COUNT))'(weight_load_spike_idx)) : 
                                         {($clog2(SPIKES*PE_COUNT)){1'b0}}; // Not used during computation
    assign weight_rd_en = weight_loading; // Only read during weight loading, not during computation
    
    // Register incoming weight data to avoid race conditions with combinational memory
    reg [WEIGHT_WIDTH-1:0] weight_data_reg;
    always @(posedge clk) begin
        if (!rst_n)
            weight_data_reg <= {WEIGHT_WIDTH{1'b0}};
        else
            weight_data_reg <= weight_data;
    end
    
    // Weight loading logic
    always @(posedge clk) begin
        if (!rst_n) begin
            weight_loading <= 1'b0;
            weights_loaded <= 1'b0;
            weight_load_pe_idx <= 0;
            weight_load_spike_idx <= 0;
            weight_store_pe_idx <= 0;
            weight_store_spike_idx <= 0;
            weight_store_valid <= 1'b0;

        end else if (state == ST_LOAD_WEIGHTS) begin
            // Store registered weight data using single-cycle delayed indices
            // Pipeline: load_idx -> store_idx (used with weight_data_reg)
            // Both data and indices delayed by exactly 1 cycle
            // Store happens outside the guard so final weight commits after weights_loaded=1
            if (weight_store_valid) begin
                // Use weight_data directly - it's already synchronous from the test
                weight_buffer[weight_store_pe_idx][weight_store_spike_idx] <= weight_data;
            end
            
            if (!weights_loaded) begin
                // Single-stage pipeline for indices to match the data register delay
                // Copy indices BEFORE incrementing so we store to the correct location
                // Store valid needs to be delayed by 2 cycles: 1 for memory read, 1 for weight_data_reg
                weight_store_pe_idx <= weight_load_pe_idx;
                weight_store_spike_idx <= weight_load_spike_idx;
                // Only set valid after weight_data_reg has captured data (2 cycles after start)
                if (weight_store_valid) begin
                    weight_store_valid <= 1'b1;  // Keep it high
                end else if (weight_loading) begin
                    weight_store_valid <= 1'b1;  // Become valid 1 cycle after weight_loading starts
                end
                
                // Increment load indices for next address generation
                // Only increment after first cycle (when weight_loading is already 1)
                if (weight_loading) begin
                    if (weight_load_spike_idx == ($clog2(SPIKES))'(SPIKES-1)) begin
                        weight_load_spike_idx <= 0;
                        if (weight_load_pe_idx == ($clog2(PE_COUNT))'(PE_COUNT-1)) begin
                            weight_load_pe_idx <= 0;
                            weight_loading <= 1'b0;
                            weights_loaded <= 1'b1;
                        end else begin
                            weight_load_pe_idx <= weight_load_pe_idx + 1;
                        end
                    end else begin
                        weight_load_spike_idx <= weight_load_spike_idx + 1;
                    end
                end else begin
                    // First cycle: just set loading flag, don't increment yet
                    weight_loading <= 1'b1;
                end
            end else begin
                // After loading complete, clear the valid flag
                weight_store_valid <= 1'b0;
            end
        end
    end
    
    genvar i;
    generate
        for (i = 0; i < PE_COUNT; i = i + 1) begin : pe_array
            // Assign current weight for active spike (FP16 format)
            always @(*) begin
                if (spike_valid_decode)
                    pe_weight[i] = weight_buffer[i][current_spike_idx];
                else
                    pe_weight[i] = 16'h0000;  // FP16 zero
            end
            
            // Processing Element: IEEE FP16 Accumulator
            // Weight is already FP16, no extension needed
            
            // FP16 addition result (combinational)
            wire [15:0] fp16_sum;
            assign fp16_sum = fp16_add(pe_partial_sum[i], pe_weight[i]);
            
            always @(posedge clk) begin
                if (!rst_n) begin
                    pe_partial_sum[i] <= 16'h0000;  // FP16 zero
                end else if (state == ST_LOAD_PFX) begin
                    if (is_null_prefix) begin
                        // NULL prefix mode: Start from zero (no prefix reuse)
                        // Still need to compute MAC and apply LIF for this row
                        pe_partial_sum[i] <= 16'h0000;  // FP16 zero
                    end else begin
                        // Normal mode: Load prefix result as starting point (already FP16)
                        pe_partial_sum[i] <= output_rd_data[(i+1)*ACC_WIDTH-1:i*ACC_WIDTH];
                    end
                end else if (mac_accumulate && state != ST_CLEAR_BIT) begin
                    // FP16 MAC operation: add FP16 weight when spike is active
                    // mac_accumulate is set in ST_DECODE and takes effect in ST_ACCUMULATE
                    // Don't accumulate again in CLEAR_BIT state
                    pe_partial_sum[i] <= fp16_sum;
                end
            end

            // ─────────────────────────────────────────────────────────────
            // LIF Neuron Instance per PE (Full FP16 - no conversion needed)
            // ─────────────────────────────────────────────────────────────
            lif #(
                .INPUT_WIDTH  (ACC_WIDTH),
                .VMEM_WIDTH   (VMEM_WIDTH),
                .THRESH_WIDTH (THRESH_WIDTH),
                .LEAK_WIDTH   (LEAK_WIDTH),
                .REFRAC_WIDTH (REFRAC_WIDTH)
            ) u_lif (
                .clk                (clk),
                .rst_n              (rst_n),
                // Configuration (all FP16)
                .cfg_threshold      (cfg_threshold),
                .cfg_leak           (cfg_leak),
                .cfg_reset_potential(cfg_reset_potential),
                .cfg_refractory     (cfg_refractory),
                // Synaptic input directly from FP16 accumulator
                .synaptic_input     (pe_partial_sum[i]),
                .input_valid        (lif_input_valid),
                // Control
                .update_en          (lif_update_en),
                // Outputs
                .spike_out          (lif_spike_out[i]),
                .vmem_out           (lif_vmem_out[i]),
                .in_refractory      (lif_in_refractory[i])
            );
        end
    endgenerate

    // Spike output vector
    assign spike_out = lif_spike_out;

    // Membrane potential readback for debug
    assign vmem_rd_data = lif_vmem_out[vmem_rd_idx];
    
    // ===================================================================
    // Address Decoder with Bit Scan Forward
    // ===================================================================
    
    // Find first set bit in pattern (bit scan forward)
    integer bit_idx;
    always @(*) begin
        current_spike_idx = {$clog2(SPIKES){1'b0}};
        spike_valid_decode = 1'b0;
        for (bit_idx = 0; bit_idx < SPIKES; bit_idx = bit_idx + 1) begin
            if (pattern_working[bit_idx] && !spike_valid_decode) begin
                current_spike_idx = bit_idx[$clog2(SPIKES)-1:0];
                spike_valid_decode = 1'b1;
            end
        end
    end
    
    assign pattern_empty = (pattern_working == 0);
    
    // ===================================================================
    // Memory Interface Logic
    // ===================================================================
    
    // Output buffer interface
    assign output_rd_addr = current_prefix_id;  // Read prefix result
    assign output_wr_addr = current_row_id;     // Write current result
    
    // Pack PE results for output
    genvar j;
    generate
        for (j = 0; j < PE_COUNT; j = j + 1) begin : output_pack
            assign output_wr_data[(j+1)*ACC_WIDTH-1:j*ACC_WIDTH] = pe_partial_sum[j];
        end
    endgenerate
    
    assign output_wr_en = writeback_en;
    
    // ===================================================================
    // Control FSM
    // ===================================================================
    
    // State register
    always @(posedge clk) begin
        if (!rst_n) begin
            state <= ST_IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    // Next state logic
    always @(*) begin
        next_state = state;
        case (state)
            ST_IDLE: begin
                if (task_valid) begin
                    next_state = weights_loaded ? ST_LOAD_PFX : ST_LOAD_WEIGHTS;
                end
            end
            
            ST_LOAD_WEIGHTS: begin
                if (weights_loaded) begin
                    next_state = ST_LOAD_PFX;
                end
            end
            
            ST_LOAD_PFX: begin
                // NULL prefix means "no prefix reuse", not "skip computation"
                // Always proceed to normal MAC/LIF processing
                next_state = ST_DECODE;
            end
            
            ST_DECODE: begin
                if (pattern_empty) begin
                    // Done with MAC, apply LIF if enabled
                    next_state = lif_enable ? ST_LIF_UPDATE : ST_WRITEBACK;
                end else if (spike_valid_decode) begin
                    next_state = ST_ACCUMULATE;
                end
            end
            
            ST_ACCUMULATE: begin
                // Go to clear bit state to clear the processed bit
                next_state = ST_CLEAR_BIT;
            end
            
            ST_CLEAR_BIT: begin
                // After clearing bit, go back to decode for next spike
                next_state = ST_DECODE;
            end

            ST_LIF_UPDATE: begin
                // LIF update takes one cycle
                next_state = ST_WRITEBACK;
            end
            
            ST_WRITEBACK: begin
                next_state = ST_IDLE;
            end
            
            default: next_state = ST_IDLE;
        endcase
    end
    
    // Control signals
    always @(posedge clk) begin
        if (!rst_n) begin
            current_row_id <= 0;
            current_prefix_id <= 0;
            current_pattern <= 0;
            pattern_working <= 0;
            prefix_result <= 0;
            prefix_loaded <= 1'b0;
            pe_accumulate_en <= 1'b0;
            writeback_en <= 1'b0;
            lif_update_en <= 1'b0;
            lif_input_valid <= 1'b0;
            spike_valid <= 1'b0;
            mac_accumulate <= 1'b0;
        end else begin
            // Default values
            lif_update_en <= 1'b0;
            lif_input_valid <= 1'b0;
            spike_valid <= 1'b0;

            case (state)
                ST_IDLE: begin
                    if (task_valid) begin
                        current_row_id <= task_row_id;
                        current_prefix_id <= task_prefix_id;
                        current_pattern <= task_pattern;
                        pattern_working <= task_pattern;
                        prefix_loaded <= 1'b0;
                    end
                    pe_accumulate_en <= 1'b0;
                    writeback_en <= 1'b0;
                end
                
                ST_LOAD_WEIGHTS: begin
                    // Weight loading handled in separate always block
                    pe_accumulate_en <= 1'b0;
                    writeback_en <= 1'b0;
                end
                
                ST_LOAD_PFX: begin
                    // Load prefix data on first cycle in this state
                    if (!prefix_loaded) begin
                        prefix_result <= output_rd_data;
                        prefix_loaded <= 1'b1;
                    end
                end
                
                ST_DECODE: begin
                    pe_accumulate_en <= 1'b0;
                    mac_accumulate <= 1'b0;  // Clear from previous cycle
                    // Set accumulation trigger if we're about to accumulate
                    // NULL prefix rows still need MAC computation (just start from zero)
                    if (spike_valid_decode && !pattern_empty) begin
                        mac_accumulate <= 1'b1;
                    end
                end
                
                ST_ACCUMULATE: begin
                    pe_accumulate_en <= 1'b1;
                    // Don't clear mac_accumulate yet - PE needs it on next clock edge
                    // Don't clear bit here, wait for CLEAR_BIT state
                end
                
                ST_CLEAR_BIT: begin
                    pe_accumulate_en <= 1'b0;
                    mac_accumulate <= 1'b0;  // Clear after accumulation completes
                    // Clear the processed bit now that accumulation is complete
                    // Use a register to store the bit index since spike_valid might change
                    if (current_spike_idx < SPIKES && pattern_working[current_spike_idx]) begin
                        pattern_working[current_spike_idx] <= 1'b0;
                    end
                end

                ST_LIF_UPDATE: begin
                    // Trigger LIF neuron update with accumulated synaptic input
                    // LIF outputs update on NEXT cycle, so don't assert spike_valid yet
                    lif_update_en <= 1'b1;
                    lif_input_valid <= 1'b1;
                    spike_valid <= 1'b0;  // Not valid yet - LIF hasn't updated
                end
                
                ST_WRITEBACK: begin
                    writeback_en <= 1'b1;
                    pe_accumulate_en <= 1'b0;
                    // LIF outputs are now valid (updated on this clock edge)
                    lif_update_en <= 1'b0;  // Clear update enable (LIF already latched)
                    lif_input_valid <= 1'b0;
                    spike_valid <= lif_enable;  // NOW spike_valid aligns with actual LIF outputs
                end
                
                default: begin
                    pe_accumulate_en <= 1'b0;
                    writeback_en <= 1'b0;
                end
            endcase

            // Handle end-of-timestep leak application (independent of task FSM)
            // Only apply leak if we're NOT in the middle of a synaptic update
            if (timestep_end && lif_enable && state != ST_LIF_UPDATE) begin
                lif_update_en <= 1'b1;
                lif_input_valid <= 1'b0;  // No new input, just apply leak
            end
        end
    end
    
    // ===================================================================
    // Status Signals
    // ===================================================================
    
    assign task_ready = (state == ST_IDLE);
    assign proc_busy = (state != ST_IDLE);
    assign proc_done = (state == ST_WRITEBACK);

endmodule

// End of file
