// spike_collector.v ────────────────────────────────────────────────────────
// Output Spike Collector for SNN Simulation
//
// Captures output spikes from LIF neurons and stores them in a buffer for
// host readback. Organizes spikes by timestep and row ID.
//
// Memory organization:
//   output_buffer[timestep * ROWS + row] = spike_vector[PE_COUNT-1:0]
//
// Operation:
//   1. Monitor spike_valid signal from processor
//   2. When spike_valid asserts, capture spike_out and current row_id
//   3. Store in buffer indexed by timestep and row
//   4. Provide host read interface for retrieving results
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module spike_collector #(
    parameter integer ROWS           = 256,  // Number of rows
    parameter integer PE_COUNT       = 128,  // Number of PEs (spike width)
    parameter integer TIMESTEP_WIDTH = 16,   // Timestep counter width
    parameter integer MAX_TIMESTEPS  = 256   // Max buffer depth
) (
    input  wire                         clk,
    input  wire                         rst_n,

    // Spike input interface (from processor)
    input  wire [PE_COUNT-1:0]          spike_in,        // Spike vector from LIF
    input  wire                         spike_valid,     // Spike data valid
    input  wire [$clog2(ROWS)-1:0]      spike_row_id,    // Row ID for current spike
    input  wire [TIMESTEP_WIDTH-1:0]    timestep_idx,    // Current timestep

    // Control
    input  wire                         collect_enable,  // Enable spike collection
    input  wire                         clear_buffer,    // Clear all stored spikes

    // Host read interface
    input  wire                         host_rd_en,      // Read enable from host
    input  wire [$clog2(MAX_TIMESTEPS*ROWS)-1:0] host_rd_addr, // Buffer read address
    output reg  [PE_COUNT-1:0]          host_rd_data,    // Spike data output

    // Statistics
    output reg  [$clog2(MAX_TIMESTEPS*ROWS):0] spike_count // Total spikes collected
);

    // =========================================================================
    // Output Spike Buffer
    // =========================================================================
    reg [PE_COUNT-1:0] output_buffer [0:MAX_TIMESTEPS*ROWS-1];

    // Initialize buffer to zeros
    integer i;
    initial begin
        for (i = 0; i < MAX_TIMESTEPS*ROWS; i = i + 1) begin
            output_buffer[i] = {PE_COUNT{1'b0}};
        end
    end

    // =========================================================================
    // Spike Collection Logic
    // =========================================================================
    
    // Calculate buffer address: timestep * ROWS + row_id
    wire [$clog2(MAX_TIMESTEPS*ROWS)-1:0] write_addr;
    assign write_addr = timestep_idx * ROWS + spike_row_id;

    // Spike collection
    always @(posedge clk) begin
        if (!rst_n || clear_buffer) begin
            spike_count <= {($clog2(MAX_TIMESTEPS*ROWS)+1){1'b0}};
            // Note: buffer clearing handled separately below
        end else if (collect_enable && spike_valid) begin
            // Store spike vector
            output_buffer[write_addr] <= spike_in;
            
            // Increment spike count if any spikes are active
            if (|spike_in) begin
                spike_count <= spike_count + 1;
            end
        end
    end

    // Clear buffer when requested
    integer j;
    always @(posedge clk) begin
        if (!rst_n || clear_buffer) begin
            for (j = 0; j < MAX_TIMESTEPS*ROWS; j = j + 1) begin
                output_buffer[j] <= {PE_COUNT{1'b0}};
            end
        end
    end

    // =========================================================================
    // Host Read Interface
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            host_rd_data <= {PE_COUNT{1'b0}};
        end else if (host_rd_en) begin
            host_rd_data <= output_buffer[host_rd_addr];
        end
    end

endmodule

`default_nettype wire
