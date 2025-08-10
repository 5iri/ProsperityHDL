// dispatcher.v ─────────────────────────────────────────────────────────────
// Prosperity ProSparsity Dispatcher - Minimal Working Version
//   • Based on "Prosperity: Accelerating Spiking Neural Networks via Product Sparsity"
//   • Implements core dispatcher functionality from Section V-D
//   • Collects spatial information from Pruner
//   • Sorts by popcount then row index (stable sort)
//   • Dispatches in correct prefix-before-suffix order
//
`timescale 1ns / 1ps
`default_nettype none

module dispatcher #(
    parameter integer ROWS          = 256,
    parameter integer SPIKES        = 16,
    parameter integer PATTERN_WIDTH = SPIKES,
    parameter integer NO_WIDTH      = 8,
    parameter integer IDX_W         = $clog2(ROWS)
) (
    input wire clk,
    input wire rst_n,

    // From Pruner (spatial information)
    input  wire                     row_info_valid,
    output wire                     row_info_ready,
    input  wire [        IDX_W-1:0] row_idx,
    input  wire [        IDX_W-1:0] row_prefix_id,
    input  wire [PATTERN_WIDTH-1:0] row_pattern,
    input  wire [     NO_WIDTH-1:0] row_popcnt,
    input  wire                     row_last,

    // To Processor
    input  wire                     proc_ready,
    output reg                      task_valid,
    output reg  [        IDX_W-1:0] task_row_id,
    output reg  [        IDX_W-1:0] task_prefix_id,
    output reg  [PATTERN_WIDTH-1:0] task_pattern,

    // Control
    input  wire prev_compute_busy,
    input  wire pruner_done,
    output reg  tile_done
);

    // ═════════════════════════════════════════════════════════════════════
    //  Product Sparsity Table (O(m) space complexity)
    // ═════════════════════════════════════════════════════════════════════
    reg [        IDX_W-1:0] pst_prefix_id [0:ROWS-1];
    reg [PATTERN_WIDTH-1:0] pst_pattern   [0:ROWS-1];
    reg [     NO_WIDTH-1:0] pst_popcnt    [0:ROWS-1];
    reg [        IDX_W-1:0] pst_row_id    [0:ROWS-1];
    reg                     pst_valid     [0:ROWS-1];

    // Sorting arrays - only for collected rows
    reg [        IDX_W-1:0] sort_row_id   [0:ROWS-1];
    reg [     NO_WIDTH-1:0] sort_popcnt   [0:ROWS-1];
    reg [        IDX_W-1:0] collected_rows[0:ROWS-1];  // Actual collected row indices

    // Temporary variables for sorting swap operations
    reg [     NO_WIDTH-1:0] temp_pc;
    reg [        IDX_W-1:0] temp_row;

    // ═════════════════════════════════════════════════════════════════════
    //  FSM States
    // ═════════════════════════════════════════════════════════════════════
    // Verilog-2005 style
    localparam S_IDLE     = 3'd0;
    localparam S_COLLECT  = 3'd1;
    localparam S_SORT     = 3'd2;
    localparam S_DISPATCH = 3'd3;
    localparam S_DONE     = 3'd4;

    reg [2:0] state, next_state;

    // Control signals
    reg [$clog2(ROWS+1)-1:0] collect_count;
    reg [$clog2(ROWS+1)-1:0] dispatch_count;
    reg [$clog2(ROWS+1)-1:0] sort_count;
    reg                      last_row_seen;
    reg [              15:0] timeout_counter;
    reg                      collect_timeout;

    // Three-stage sorting variables
    reg [               1:0] sort_stage;  // 0=find_min, 1=store_temp, 2=swap
    reg [      NO_WIDTH-1:0] sort_temp_pc;
    reg [         IDX_W-1:0] sort_temp_row;

    // At the top of the always block:
    reg [31:0] i;
    reg [31:0] j;
    reg [$clog2(ROWS)-1:0] current_row;
    integer min_idx_found;
    integer min_pc_found;
    integer min_row_found;

    // ═════════════════════════════════════════════════════════════════════
    //  FSM Logic
    // ═════════════════════════════════════════════════════════════════════
    always @(*) begin
        next_state = state;
        case (state)
            S_IDLE: begin
                if (row_info_valid) next_state = S_COLLECT;
            end
            S_COLLECT: begin
                if (collect_count == ROWS || pruner_done || collect_timeout || last_row_seen)
                    next_state = S_SORT;
            end
            S_SORT: begin
                if (sort_count >= collect_count) next_state = S_DISPATCH;
            end
            S_DISPATCH: begin
                if (dispatch_count >= collect_count) next_state = S_DONE;
            end
            S_DONE: begin
                next_state = S_IDLE;
            end
            default: begin
                next_state = S_IDLE;
            end
        endcase
    end

    assign row_info_ready = (state == S_IDLE || state == S_COLLECT);

    // ═════════════════════════════════════════════════════════════════════
    //  Main Sequential Logic
    // ═════════════════════════════════════════════════════════════════════
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= S_IDLE;
            collect_count <= 0;
            dispatch_count <= 0;
            sort_count <= 0;
            last_row_seen <= 1'b0;
            task_valid <= 1'b0;
            tile_done <= 1'b0;
            timeout_counter <= 0;
            collect_timeout <= 1'b0;
            sort_stage <= 0;
            // min_idx_found <= 0;
            // min_pc_found <= 0;
            // min_row_found <= 0;
            sort_temp_pc <= 0;
            sort_temp_row <= 0;

            // Initialize arrays
            for (i = 0; i < ROWS; i = i + 1) begin
                pst_valid[i]   <= 1'b0;
                sort_row_id[i] <= i;
                sort_popcnt[i] <= 0;
            end
        end else begin
            state <= next_state;
            task_valid <= 1'b0;
            tile_done <= 1'b0;

            case (state)
                S_IDLE: begin
                    collect_count <= 0;
                    dispatch_count <= 0;
                    sort_count <= 0;
                    last_row_seen <= 1'b0;
                    timeout_counter <= 0;
                    collect_timeout <= 1'b0;
                    sort_stage <= 0;
                    // min_idx_found <= 0;
                    // min_pc_found <= 0;
                    // min_row_found <= 0;
                    sort_temp_pc <= 0;
                    sort_temp_row <= 0;

                    // Clear valid flags
                    for (i = 0; i < ROWS; i = i + 1) begin
                        pst_valid[i]      <= 1'b0;
                        sort_row_id[i]    <= 0;
                        sort_popcnt[i]    <= 0;
                        collected_rows[i] <= 0;
                    end

                    // Handle data that arrives during IDLE->COLLECT transition
                    if (row_info_valid && row_info_ready) begin
                        // Store spatial information for the transition case
                        pst_prefix_id[row_idx] <= row_prefix_id;
                        pst_pattern[row_idx] <= row_pattern;
                        pst_popcnt[row_idx] <= row_popcnt;
                        pst_row_id[row_idx] <= row_idx;
                        pst_valid[row_idx] <= 1'b1;

                        // Set up for sorting - store in collection order
                        collected_rows[0] <= row_idx;
                        sort_row_id[0]    <= row_idx;
                        sort_popcnt[0]    <= row_popcnt;

                        collect_count <= 1;  // First row, so count = 1

                        if (row_last) begin
                            last_row_seen <= 1'b1;
                        end

                    end
                end

                S_COLLECT: begin
                    if (row_info_valid && row_info_ready) begin
                        // Store spatial information
                        pst_prefix_id[row_idx] <= row_prefix_id;
                        pst_pattern[row_idx] <= row_pattern;
                        pst_popcnt[row_idx] <= row_popcnt;
                        pst_row_id[row_idx] <= row_idx;
                        pst_valid[row_idx] <= 1'b1;

                        // Set up for sorting - store in collection order
                        collected_rows[collect_count] <= row_idx;
                        sort_row_id[collect_count]    <= row_idx;
                        sort_popcnt[collect_count]    <= row_popcnt;

                        collect_count <= collect_count + 1;
                        timeout_counter <= 0;  // Reset timeout on new data

                        if (row_last) begin
                            last_row_seen <= 1'b1;
                        end

                    end else begin
                        // Increment timeout counter when no new data
                        timeout_counter <= timeout_counter + 1;
                        if (timeout_counter > 5000) begin  // Much longer timeout for debugging
                            collect_timeout <= 1'b1;
                        end
                    end
                end

                S_SORT: begin
                    // Three-stage selection sort to handle non-blocking assignment timing
                    if (sort_count < collect_count) begin
                        // Use local variables for sorting (already declared at top)
                        case (sort_stage)
                            2'd0: begin
                                // Stage 0: Find minimum from sort_count to collect_count-1
                                min_idx_found = sort_count;
                                min_pc_found  = sort_popcnt[sort_count];
                                min_row_found = sort_row_id[sort_count];

                                // Search among collected rows
                                for (i = 0; i < ROWS; i = i + 1) begin
                                    if (i >= sort_count + 1 && i < collect_count) begin
                                        if (sort_popcnt[i] < min_pc_found ||
                                            (sort_popcnt[i] == min_pc_found && sort_row_id[i] < min_row_found)) begin
                                            min_idx_found = i;
                                            min_pc_found  = sort_popcnt[i];
                                            min_row_found = sort_row_id[i];
                                        end
                                    end
                                end

                                // Store found minimum for next stage
                                // (No need to assign to state variables)

                                if (min_idx_found != sort_count) begin
                                    sort_stage <= 2'd1;  // Need swap, go to temp storage stage
                                    // Save min_idx_found, min_pc_found, min_row_found in temp regs for next stage
                                    sort_temp_pc <= min_pc_found;
                                    sort_temp_row <= min_row_found;
                                    // Save index for swap
                                    temp_pc <= min_idx_found;
                                end else begin
                                    sort_count <= sort_count + 1;  // No swap needed, advance
                                    sort_stage <= 2'd0;
                                end
                            end

                            2'd1: begin
                                // Stage 1: Store current values in temporary variables
                                // Already done in previous stage
                                sort_stage <= 2'd2;  // Move to swap stage
                            end

                            2'd2: begin
                                // Stage 2: Perform the actual swap
                                // Use temp_pc as min_idx_found
                                sort_popcnt[sort_count] <= sort_temp_pc;
                                sort_row_id[sort_count] <= sort_temp_row;
                                sort_popcnt[temp_pc] <= sort_popcnt[sort_count];
                                sort_row_id[temp_pc] <= sort_row_id[sort_count];

                                // Move to next position
                                sort_count <= sort_count + 1;
                                sort_stage <= 2'd0;  // Back to find stage
                            end

                            default: begin
                                sort_stage <= 2'd0;
                            end
                        endcase
                    end
                end

                S_DISPATCH: begin
                    if (proc_ready && dispatch_count < collect_count) begin
                        current_row = sort_row_id[dispatch_count];

                        if (pst_valid[current_row]) begin
                            task_valid <= 1'b1;
                            task_row_id <= current_row;
                            task_prefix_id <= pst_prefix_id[current_row];
                            task_pattern <= pst_pattern[current_row];

                            dispatch_count <= dispatch_count + 1;
                        end else begin
                            // Skip invalid entries but still increment to avoid infinite loop
                            dispatch_count <= dispatch_count + 1;
                        end
                    end
                end

                S_DONE: begin
                    tile_done <= 1'b1;
                end

                default: begin
                    state <= S_IDLE;
                end
            endcase
        end
    end

endmodule
`default_nettype wire
