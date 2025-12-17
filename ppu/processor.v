// processor.v -- Prosperity PPU Processor (128 PE Array with Integrated LIF Neurons)
// Implements ProSparsity-based matrix computation with:
//   - 128 Processing Elements (8-bit weights, 16-bit accumulators)
//   - Integrated LIF neurons per PE for direct spike generation
//   - Row-wise dataflow processing
//   - Prefix result reuse for product sparsity
//   - Address decoder with bit scan forward
//   - Support for unstructured sparsity
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity (Section V-E)
// (c) 2025 Prosperity Project
`timescale 1ns / 1ps

/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off UNUSEDPARAM */

module processor #(
    parameter ROWS        = 256,      // Number of rows in tile
    parameter SPIKES      = 16,       // Number of spikes per pattern  
    parameter PE_COUNT    = 128,      // Number of Processing Elements
    parameter WEIGHT_WIDTH = 8,       // Weight precision (8-bit)
    parameter ACC_WIDTH   = 16,       // Accumulator width (16-bit for overflow protection)
    parameter NO_WIDTH    = 8,        // Popcount width
    // LIF Neuron Parameters
    parameter VMEM_WIDTH    = 16,     // Membrane potential width
    parameter THRESH_WIDTH  = 16,     // Threshold width  
    parameter LEAK_WIDTH    = 8,      // Leak value width
    parameter REFRAC_WIDTH  = 4       // Refractory counter width
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
    
    // NULL prefix constant (ID 255 indicates no prefix/passthrough mode)
    localparam NULL_PREFIX_ID = 8'hFF;
    
    reg [3:0] state, next_state;
    reg [$clog2(ROWS)-1:0] current_row_id;
    reg [$clog2(ROWS)-1:0] current_prefix_id;
    reg [SPIKES-1:0] current_pattern;
    reg [SPIKES-1:0] pattern_working;  // Working copy for bit scanning
    
    // NULL prefix detection
    wire is_null_prefix;
    assign is_null_prefix = (current_prefix_id == NULL_PREFIX_ID);
    
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
    
    // Two-stage pipeline for weight storage indices (to match registered weight_data)
    reg [$clog2(PE_COUNT)-1:0] weight_store_pe_idx_d1;
    reg [$clog2(SPIKES)-1:0] weight_store_spike_idx_d1;
    reg weight_store_valid_d1;
    reg [$clog2(PE_COUNT)-1:0] weight_store_pe_idx;
    reg [$clog2(SPIKES)-1:0] weight_store_spike_idx;
    reg weight_store_valid;

    
    // Address Decoder Signals
    reg [$clog2(SPIKES)-1:0] current_spike_idx;
    reg spike_valid_decode;
    wire pattern_empty;

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
            weight_store_pe_idx_d1 <= 0;
            weight_store_spike_idx_d1 <= 0;
            weight_store_valid_d1 <= 1'b0;
            weight_store_pe_idx <= 0;
            weight_store_spike_idx <= 0;
            weight_store_valid <= 1'b0;

        end else if (state == ST_LOAD_WEIGHTS) begin
            if (!weights_loaded) begin
                weight_loading <= 1'b1;
                
                // Store registered weight data using delayed indices (two cycles behind current)
                // Pipeline: load_idx -> store_idx_d1 -> store_idx (used with weight_data_reg)
                if (weight_store_valid) begin
                    weight_buffer[weight_store_pe_idx][weight_store_spike_idx] <= weight_data_reg;
                end
                
                // Two-stage pipeline for indices to match the data register delay
                weight_store_pe_idx <= weight_store_pe_idx_d1;
                weight_store_spike_idx <= weight_store_spike_idx_d1;
                weight_store_pe_idx_d1 <= weight_load_pe_idx;
                weight_store_spike_idx_d1 <= weight_load_spike_idx;
                weight_store_valid <= weight_store_valid_d1;
                weight_store_valid_d1 <= weight_loading; // Valid after first cycle
                
                // Increment load indices for next address generation
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
                end
            end
        end
    end
    
    genvar i;
    generate
        for (i = 0; i < PE_COUNT; i = i + 1) begin : pe_array
            // Assign current weight for active spike
            always @(*) begin
                if (spike_valid_decode)
                    pe_weight[i] = weight_buffer[i][current_spike_idx];
                else
                    pe_weight[i] = {WEIGHT_WIDTH{1'b0}};
            end
            
            // Processing Element: 8-bit Multiply + 16-bit Accumulator (MAC)
            wire signed [ACC_WIDTH-1:0] pe_weight_extended;
            
            // Sign extend weight to accumulator width
            assign pe_weight_extended = {{(ACC_WIDTH-WEIGHT_WIDTH){pe_weight[i][WEIGHT_WIDTH-1]}}, pe_weight[i]};
            
            always @(posedge clk) begin
                if (!rst_n) begin
                    pe_partial_sum[i] <= 0;
                end else if (state == ST_LOAD_PFX) begin
                    if (is_null_prefix) begin
                        // NULL prefix mode: Output the input pattern bits directly
                        // Map pattern bits to PE outputs (16 pattern bits -> 128 PEs)
                        // Each pattern bit maps to 8 consecutive PEs (128/16 = 8)
                        if (i < SPIKES * (PE_COUNT/SPIKES)) begin
                            // Extract the corresponding pattern bit for this PE group
                            pe_partial_sum[i] <= current_pattern[i / (PE_COUNT/SPIKES)] ? 16'h0001 : 16'h0000;
                        end else begin
                            pe_partial_sum[i] <= 16'h0000;
                        end
                    end else begin
                        // Normal mode: Load prefix result as starting point
                        pe_partial_sum[i] <= output_rd_data[(i+1)*ACC_WIDTH-1:i*ACC_WIDTH];
                    end
                end else if (state == ST_ACCUMULATE && spike_valid_decode && !is_null_prefix) begin
                    // MAC operation: add weight when spike is active (skip if NULL prefix)
                    pe_partial_sum[i] <= pe_partial_sum[i] + pe_weight_extended;
                end
            end

            // ─────────────────────────────────────────────────────────────
            // LIF Neuron Instance per PE
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
                // Configuration
                .cfg_threshold      (cfg_threshold),
                .cfg_leak           (cfg_leak),
                .cfg_reset_potential(cfg_reset_potential),
                .cfg_refractory     (cfg_refractory),
                // Synaptic input from accumulator
                .synaptic_input     ($signed(pe_partial_sum[i])),
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
                // For NULL prefix, skip directly to writeback (passthrough mode)
                if (is_null_prefix) begin
                    next_state = ST_WRITEBACK;
                end else begin
                    next_state = ST_DECODE; // Normal processing
                end
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
                        
                        // Debug print for NULL prefix detection
                        if (task_prefix_id == NULL_PREFIX_ID) begin
                            $display("[PROCESSOR] NULL PREFIX detected: row=%0d, pattern=0x%04x", 
                                   task_row_id, task_pattern);
                        end
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
                end
                
                ST_ACCUMULATE: begin
                    pe_accumulate_en <= 1'b1;
                    // Don't clear bit here, wait for CLEAR_BIT state
                end
                
                ST_CLEAR_BIT: begin
                    pe_accumulate_en <= 1'b0;
                    // Clear the processed bit now that accumulation is complete
                    // Use a register to store the bit index since spike_valid might change
                    if (current_spike_idx < SPIKES && pattern_working[current_spike_idx]) begin
                        pattern_working[current_spike_idx] <= 1'b0;
                    end
                end

                ST_LIF_UPDATE: begin
                    // Trigger LIF neuron update with accumulated synaptic input
                    lif_update_en <= 1'b1;
                    lif_input_valid <= 1'b1;
                    spike_valid <= 1'b1;  // Spikes will be valid after this cycle
                end
                
                ST_WRITEBACK: begin
                    writeback_en <= 1'b1;
                    pe_accumulate_en <= 1'b0;
                    // Keep LIF signals stable for one more cycle so LIF module sees the update
                    lif_update_en <= 1'b0;  // Clear update enable (LIF already latched)
                    lif_input_valid <= 1'b0;
                    spike_valid <= lif_enable;  // Keep spike_valid if LIF was used
                    
                    // Debug print for NULL prefix writeback
                    if (is_null_prefix) begin
                        $display("[PROCESSOR] NULL PREFIX writeback: row=%0d, pattern=0x%04x -> PE[0:7]=0x%04x_%04x_%04x_%04x_%04x_%04x_%04x_%04x", 
                               current_row_id, current_pattern,
                               pe_partial_sum[7], pe_partial_sum[6], pe_partial_sum[5], pe_partial_sum[4],
                               pe_partial_sum[3], pe_partial_sum[2], pe_partial_sum[1], pe_partial_sum[0]);
                    end
                end
                
                default: begin
                    pe_accumulate_en <= 1'b0;
                    writeback_en <= 1'b0;
                end
            endcase

            // Handle end-of-timestep leak application (independent of task FSM)
            if (timestep_end && lif_enable) begin
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
