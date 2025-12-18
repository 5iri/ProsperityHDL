// spike_injector.v ─────────────────────────────────────────────────────────
// Input Spike Injector for SNN Simulation
//
// Loads input spike patterns into the detector TCAM at the start of each
// timestep. Stores input spikes for all timesteps and rows, then sequences
// them into the TCAM when triggered.
//
// Memory organization:
//   input_buffer[timestep * ROWS + row] = spike_pattern
//
// Operation sequence per timestep:
//   1. Receive tile_start pulse from timestep controller
//   2. Read all rows for current timestep from buffer
//   3. Write each pattern to TCAM via set interface
//   4. Assert inject_done when complete
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module spike_injector #(
    parameter integer ROWS           = 256,  // Number of TCAM rows
    parameter integer SPIKES         = 16,   // Spike pattern width
    parameter integer TIMESTEP_WIDTH = 16,   // Timestep counter width
    parameter integer MAX_TIMESTEPS  = 256   // Max buffer depth
) (
    input  wire                         clk,
    input  wire                         rst_n,

    // Control interface
    input  wire                         tile_start,      // Start loading spikes for current timestep
    input  wire [TIMESTEP_WIDTH-1:0]    timestep_idx,    // Current timestep index
    output reg                          inject_done,     // Loading complete

    // Host configuration interface (for loading spike patterns)
    input  wire                         host_wr_en,      // Write enable from host
    input  wire [$clog2(MAX_TIMESTEPS*ROWS)-1:0] host_wr_addr, // Buffer write address
    input  wire [SPIKES-1:0]            host_wr_data,    // Spike pattern to write

    // TCAM interface (output to detector)
    output reg                          tcam_set_en,     // TCAM write enable
    output reg  [$clog2(ROWS)-1:0]      tcam_set_addr,   // TCAM row address
    output reg  [SPIKES-1:0]            tcam_set_key     // Spike pattern
);

    // =========================================================================
    // Input Spike Buffer
    // =========================================================================
    reg [SPIKES-1:0] input_buffer [0:MAX_TIMESTEPS*ROWS-1];

    // Initialize buffer to zeros
    integer i;
    initial begin
        for (i = 0; i < MAX_TIMESTEPS*ROWS; i = i + 1) begin
            input_buffer[i] = {SPIKES{1'b0}};
        end
    end

    // Host write interface
    always @(posedge clk) begin
        if (host_wr_en) begin
            input_buffer[host_wr_addr] <= host_wr_data;
        end
    end

    // =========================================================================
    // FSM States
    // =========================================================================
    localparam [1:0] ST_IDLE  = 2'd0;  // Waiting for tile_start
    localparam [1:0] ST_LOAD  = 2'd1;  // Loading spikes into TCAM
    localparam [1:0] ST_DONE  = 2'd2;  // Loading complete

    reg [1:0] state, next_state;

    // Row counter for loading
    reg [$clog2(ROWS)-1:0] row_cnt;

    // Latched timestep index - captured on tile_start to avoid race conditions
    reg [TIMESTEP_WIDTH-1:0] latched_timestep_idx;

    // Base address for current timestep (use latched value)
    wire [$clog2(MAX_TIMESTEPS*ROWS)-1:0] base_addr;
    assign base_addr = latched_timestep_idx * ROWS;

    // =========================================================================
    // FSM State Transitions
    // =========================================================================
    always @(*) begin
        next_state = state;
        case (state)
            ST_IDLE: begin
                if (tile_start)
                    next_state = ST_LOAD;
            end

            ST_LOAD: begin
                if (row_cnt >= ROWS - 1)
                    next_state = ST_DONE;
            end

            ST_DONE: begin
                next_state = ST_IDLE;
            end

            default: next_state = ST_IDLE;
        endcase
    end

    // =========================================================================
    // FSM State Register
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n)
            state <= ST_IDLE;
        else
            state <= next_state;
    end

    // =========================================================================
    // Control Logic
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            row_cnt      <= {$clog2(ROWS){1'b0}};
            tcam_set_en  <= 1'b0;
            tcam_set_addr<= {$clog2(ROWS){1'b0}};
            tcam_set_key <= {SPIKES{1'b0}};
            inject_done  <= 1'b0;
            latched_timestep_idx <= {TIMESTEP_WIDTH{1'b0}};
        end else begin
            // Default values
            tcam_set_en <= 1'b0;
            inject_done <= 1'b0;

            case (state)
                ST_IDLE: begin
                    if (tile_start) begin
                        row_cnt <= {$clog2(ROWS){1'b0}};
                        // Latch timestep_idx to avoid race conditions during loading
                        latched_timestep_idx <= timestep_idx;
                    end
                end

                ST_LOAD: begin
                    // Load spike pattern from buffer and write to TCAM
                    tcam_set_en   <= 1'b1;
                    tcam_set_addr <= row_cnt;
                    tcam_set_key  <= input_buffer[base_addr + row_cnt];

                    // Increment row counter
                    if (row_cnt < ROWS - 1) begin
                        row_cnt <= row_cnt + 1;
                    end
                end

                ST_DONE: begin
                    inject_done <= 1'b1;
                end
            endcase
        end
    end

endmodule

`default_nettype wire
