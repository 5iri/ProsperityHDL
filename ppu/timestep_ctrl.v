// timestep_ctrl.v ──────────────────────────────────────────────────────────
// Timestep Controller for SNN Simulation
//
// Manages the global simulation timebase:
//   1. Counts timesteps from 0 to (num_timesteps - 1)
//   2. Coordinates tile processing per timestep
//   3. Signals timestep boundaries for LIF leak application
//   4. Indicates simulation completion
//
// Interface:
//   - start:         Pulse to begin simulation
//   - num_timesteps: Total timesteps to simulate (set before start)
//   - tile_start:    Output pulse to trigger tile processing
//   - tile_done:     Input signal that tile processing is complete
//   - timestep_idx:  Current timestep index
//   - timestep_end:  Pulse at end of each timestep (for LIF leak)
//   - sim_done:      High when all timesteps complete
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module timestep_ctrl #(
    parameter integer TIMESTEP_WIDTH = 16   // Max 65535 timesteps
) (
    input  wire                         clk,
    input  wire                         rst_n,

    // Configuration
    input  wire [TIMESTEP_WIDTH-1:0]    num_timesteps,   // Total timesteps to run

    // Control
    input  wire                         start,           // Pulse to begin simulation
    input  wire                         tile_done,       // Tile processing complete

    // Status outputs
    output reg  [TIMESTEP_WIDTH-1:0]    timestep_idx,    // Current timestep (0-indexed)
    output reg                          tile_start,      // Pulse to start tile processing
    output reg                          timestep_end,    // Pulse at end of timestep
    output reg                          sim_active,      // Simulation in progress
    output reg                          sim_done         // All timesteps complete
);

    // =========================================================================
    // FSM States
    // =========================================================================
    localparam [2:0] ST_IDLE        = 3'd0;  // Waiting for start
    localparam [2:0] ST_START_TILE  = 3'd1;  // Issue tile_start pulse
    localparam [2:0] ST_WAIT_TILE   = 3'd2;  // Wait for tile_done
    localparam [2:0] ST_TIMESTEP_END= 3'd3;  // Signal end of timestep
    localparam [2:0] ST_NEXT        = 3'd4;  // Increment timestep or finish
    localparam [2:0] ST_DONE        = 3'd5;  // Simulation complete

    reg [2:0] state, next_state;

    // =========================================================================
    // FSM State Transitions
    // =========================================================================
    always @(*) begin
        next_state = state;
        case (state)
            ST_IDLE: begin
                if (start && num_timesteps > 0)
                    next_state = ST_START_TILE;
            end

            ST_START_TILE: begin
                next_state = ST_WAIT_TILE;
            end

            ST_WAIT_TILE: begin
                if (tile_done)
                    next_state = ST_TIMESTEP_END;
            end

            ST_TIMESTEP_END: begin
                next_state = ST_NEXT;
            end

            ST_NEXT: begin
                if (timestep_idx >= num_timesteps - 1)
                    next_state = ST_DONE;
                else
                    next_state = ST_START_TILE;
            end

            ST_DONE: begin
                // Stay in done until reset or new start
                if (start)
                    next_state = ST_IDLE;  // Allow restart
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
    // Output Logic
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            timestep_idx <= {TIMESTEP_WIDTH{1'b0}};
            tile_start   <= 1'b0;
            timestep_end <= 1'b0;
            sim_active   <= 1'b0;
            sim_done     <= 1'b0;
        end else begin
            // Default pulse signals to 0
            tile_start   <= 1'b0;
            timestep_end <= 1'b0;

            case (state)
                ST_IDLE: begin
                    sim_done   <= 1'b0;
                    // Only reset sim_active on new start, not when cycling back between timesteps
                    if (start && num_timesteps > 0) begin
                        timestep_idx <= {TIMESTEP_WIDTH{1'b0}};
                        sim_active   <= 1'b1;
                    end
                end

                ST_START_TILE: begin
                    tile_start <= 1'b1;  // Pulse to start tile processing
                end

                ST_WAIT_TILE: begin
                    // Just waiting for tile_done
                end

                ST_TIMESTEP_END: begin
                    timestep_end <= 1'b1;  // Pulse for LIF leak application
                end

                ST_NEXT: begin
                    if (timestep_idx < num_timesteps - 1) begin
                        timestep_idx <= timestep_idx + 1;
                    end
                end

                ST_DONE: begin
                    sim_active <= 1'b0;
                    sim_done   <= 1'b1;
                end
            endcase
        end
    end

endmodule

`default_nettype wire
