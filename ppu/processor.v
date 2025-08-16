// processor.v -- Prosperity PPU Processor (128 PE Array)
// Implements ProSparsity-based matrix computation with:
//   - 128 Processing Elements (8-bit adders)
//   - Row-wise dataflow processing
//   - Prefix result reuse for product sparsity
//   - Address decoder with bit scan forward
//   - Support for unstructured sparsity
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity (Section V-E)
// (c) 2025 Prosperity Project
`timescale 1ns / 1ps

module processor #(
    parameter ROWS        = 256,      // Number of rows in tile
    parameter SPIKES      = 16,       // Number of spikes per pattern  
    parameter PE_COUNT    = 128,      // Number of Processing Elements
    parameter WEIGHT_WIDTH = 8,       // Weight precision (8-bit)
    parameter ACC_WIDTH   = 16,       // Accumulator width (16-bit for overflow protection)
    parameter NO_WIDTH    = 8         // Popcount width
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

    // Output Buffer Interface
    output wire [$clog2(ROWS)-1:0]     output_rd_addr,
    output wire [$clog2(ROWS)-1:0]     output_wr_addr,
    input  wire [PE_COUNT*ACC_WIDTH-1:0] output_rd_data,
    output wire [PE_COUNT*ACC_WIDTH-1:0] output_wr_data,
    output wire                        output_wr_en,

    // Status
    output wire                        proc_busy,
    output wire                        proc_done
);

    // ===================================================================
    // Internal Registers and Signals
    // ===================================================================
    
    // FSM States
    localparam ST_IDLE       = 3'd0;
    localparam ST_LOAD_WEIGHTS = 3'd1;
    localparam ST_LOAD_PFX   = 3'd2;
    localparam ST_DECODE     = 3'd3;
    localparam ST_ACCUMULATE = 3'd4;
    localparam ST_WRITEBACK  = 3'd5;
    
    reg [2:0] state, next_state;
    reg [$clog2(ROWS)-1:0] current_row_id;
    reg [$clog2(ROWS)-1:0] current_prefix_id;
    reg [SPIKES-1:0] current_pattern;
    reg [SPIKES-1:0] pattern_working;  // Working copy for bit scanning
    
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
    
    // Address Decoder Signals
    reg [$clog2(SPIKES)-1:0] current_spike_idx;
    reg spike_valid;
    wire pattern_empty;
    
    // Memory Interfaces
    reg [PE_COUNT*ACC_WIDTH-1:0] prefix_result;
    reg prefix_loaded;
    reg writeback_en;
    
    // ===================================================================
    // Weight Loading and PE Array Implementation
    // ===================================================================
    
    // Weight memory address calculation
    assign weight_addr = weight_loading ? (($clog2(SPIKES*PE_COUNT))'(weight_load_pe_idx) * SPIKES + ($clog2(SPIKES*PE_COUNT))'(weight_load_spike_idx)) : 
                                         (($clog2(SPIKES*PE_COUNT))'(current_spike_idx) * PE_COUNT + ($clog2(SPIKES*PE_COUNT))'(weight_load_pe_idx));
    assign weight_rd_en = weight_loading || (spike_valid && (state == ST_ACCUMULATE));
    
    // Weight loading logic
    always @(posedge clk) begin
        if (!rst_n) begin
            weight_loading <= 1'b0;
            weights_loaded <= 1'b0;
            weight_load_pe_idx <= 0;
            weight_load_spike_idx <= 0;
        end else if (state == ST_LOAD_WEIGHTS) begin
            if (!weights_loaded) begin
                weight_loading <= 1'b1;
                // Load weights sequentially
                if (weight_loading) begin
                    weight_buffer[weight_load_pe_idx][weight_load_spike_idx] <= weight_data;
                    
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
                if (spike_valid && current_spike_idx < ($clog2(SPIKES))'(SPIKES))
                    pe_weight[i] = weight_buffer[i][current_spike_idx];
                else
                    pe_weight[i] = {WEIGHT_WIDTH{1'b0}};
            end
            
            // Processing Element: 8-bit Multiply + 16-bit Accumulator (MAC)
            wire [WEIGHT_WIDTH:0] pe_spike_input;  // Spike input (0 or 1) extended to match weight width
            wire [WEIGHT_WIDTH+1-1:0] pe_product; // Multiplication result
            
            // Spike input is binary (0 or 1), weights are 8-bit signed
            assign pe_spike_input = spike_valid ? {{WEIGHT_WIDTH{1'b0}}, 1'b1} : {(WEIGHT_WIDTH+1){1'b0}};
            assign pe_product = pe_weight[i] * pe_spike_input[0]; // Multiply by 0 or 1
            
            always @(posedge clk) begin
                if (!rst_n) begin
                    pe_partial_sum[i] <= 0;
                end else if (state == ST_LOAD_PFX && prefix_loaded) begin
                    // Load prefix result as starting point
                    pe_partial_sum[i] <= prefix_result[(i+1)*ACC_WIDTH-1:i*ACC_WIDTH];
                end else if (pe_accumulate_en && spike_valid) begin
                    // MAC operation: accumulate weight * spike_input
                    pe_partial_sum[i] <= pe_partial_sum[i] + {{(ACC_WIDTH-WEIGHT_WIDTH-1){pe_product[WEIGHT_WIDTH]}}, pe_product};
                end
            end
        end
    endgenerate
    
    // ===================================================================
    // Address Decoder with Bit Scan Forward
    // ===================================================================
    
    // Find first set bit in pattern (bit scan forward)
    integer bit_idx;
    always @(*) begin
        current_spike_idx = {$clog2(SPIKES){1'b0}};
        spike_valid = 1'b0;
        for (bit_idx = 0; bit_idx < SPIKES; bit_idx = bit_idx + 1) begin
            if (pattern_working[bit_idx] && !spike_valid) begin
                current_spike_idx = bit_idx[$clog2(SPIKES)-1:0];
                spike_valid = 1'b1;
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
                if (prefix_loaded) begin
                    next_state = ST_DECODE;
                end
            end
            
            ST_DECODE: begin
                if (pattern_empty) begin
                    next_state = ST_WRITEBACK;
                end else if (spike_valid) begin
                    next_state = ST_ACCUMULATE;
                end
            end
            
            ST_ACCUMULATE: begin
                next_state = ST_DECODE;  // Continue processing next spike
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
        end else begin
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
                    if (!prefix_loaded) begin
                        prefix_result <= output_rd_data;
                        prefix_loaded <= 1'b1;
                    end
                end
                
                ST_DECODE: begin
                    pe_accumulate_en <= 1'b0;
                end
                
                ST_ACCUMULATE: begin
                    if (spike_valid) begin
                        pe_accumulate_en <= 1'b1;
                        // Clear the processed bit (flip to 0)
                        pattern_working[current_spike_idx] <= 1'b0;
                    end
                end
                
                ST_WRITEBACK: begin
                    writeback_en <= 1'b1;
                    pe_accumulate_en <= 1'b0;
                end
                
                default: begin
                    pe_accumulate_en <= 1'b0;
                    writeback_en <= 1'b0;
                end
            endcase
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
