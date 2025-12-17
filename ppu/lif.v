// lif.v ────────────────────────────────────────────────────────────────────
// Leaky Integrate-and-Fire (LIF) Neuron - Single Neuron Unit
//
// This module implements ONE LIF neuron. Instantiate multiple in processor.v
// to create the full PE array with integrated neuron dynamics.
//
// Neuron dynamics (per timestep):
//   1. If in refractory: decrement counter, hold state, no spike
//   2. Else: V_mem = V_mem - leak + synaptic_input
//   3. If V_mem >= threshold: spike=1, V_mem=reset, enter refractory
//   4. Clamp V_mem to 0 if negative (configurable)
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module lif #(
    parameter integer INPUT_WIDTH   = 16,           // Width of synaptic input
    parameter integer VMEM_WIDTH    = 16,           // Membrane potential width
    parameter integer THRESH_WIDTH  = 16,           // Threshold width
    parameter integer LEAK_WIDTH    = 8,            // Leak value width
    parameter integer REFRAC_WIDTH  = 4             // Refractory counter width
) (
    input  wire clk,
    input  wire rst_n,

    // Configuration
    input  wire [THRESH_WIDTH-1:0]  cfg_threshold,       // Firing threshold
    input  wire [LEAK_WIDTH-1:0]    cfg_leak,            // Leak per timestep
    input  wire [VMEM_WIDTH-1:0]    cfg_reset_potential, // Reset value after spike
    input  wire [REFRAC_WIDTH-1:0]  cfg_refractory,      // Refractory period

    // Synaptic input (from MAC result)
    input  wire signed [INPUT_WIDTH-1:0] synaptic_input,
    input  wire                          input_valid,     // Pulse when input ready

    // Control
    input  wire                          update_en,       // Enable neuron update

    // Outputs
    output reg                           spike_out,       // Spike output
    output reg  [VMEM_WIDTH-1:0]         vmem_out,        // Membrane potential (for debug)
    output wire                          in_refractory    // Refractory status
);

    // =========================================================================
    // Internal State
    // =========================================================================

    reg signed [VMEM_WIDTH-1:0] vmem;           // Membrane potential
    reg [REFRAC_WIDTH-1:0]      refrac_cnt;     // Refractory counter

    // Intermediate calculations
    reg signed [VMEM_WIDTH:0] vmem_after_leak;   // Extra bit for underflow
    reg signed [VMEM_WIDTH:0] vmem_after_input;  // Extra bit for overflow

    assign in_refractory = (refrac_cnt != 0);

    // =========================================================================
    // Neuron Update Logic
    // =========================================================================

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            vmem <= {VMEM_WIDTH{1'b0}};
            refrac_cnt <= {REFRAC_WIDTH{1'b0}};
            spike_out <= 1'b0;
        end else if (update_en) begin
            // Only clear spike at the START of a new update cycle
            // (spike_out will be set again below if threshold exceeded)
            spike_out <= 1'b0;
            
            // Debug output
            $display("[LIF] update_en=1, input_valid=%b, vmem=%0d, threshold=%0d, synaptic_input=%0d, refrac_cnt=%0d",
                     input_valid, vmem, cfg_threshold, $signed(synaptic_input), refrac_cnt);

            if (refrac_cnt != 0) begin
                // In refractory period - just decrement counter
                refrac_cnt <= refrac_cnt - 1'b1;
            end else begin
                // Active neuron - apply dynamics

                // Step 1: Apply leak
                vmem_after_leak = $signed({1'b0, vmem}) - $signed({{(VMEM_WIDTH-LEAK_WIDTH+1){1'b0}}, cfg_leak});
                
                // Clamp to 0 if negative
                if (vmem_after_leak < 0) begin
                    vmem_after_leak = 0;
                end

                // Step 2: Add synaptic input (if valid)
                if (input_valid) begin
                    vmem_after_input = vmem_after_leak + $signed(synaptic_input);
                end else begin
                    vmem_after_input = vmem_after_leak;
                end

                // Clamp to max positive on overflow
                if (vmem_after_input > $signed({1'b0, {VMEM_WIDTH{1'b1}}})) begin
                    vmem_after_input = {1'b0, {VMEM_WIDTH{1'b1}}};
                end else if (vmem_after_input < 0) begin
                    vmem_after_input = 0;
                end

                // Debug intermediate values
                $display("[LIF] vmem_after_leak=%0d, vmem_after_input=%0d, compare: %0d >= %0d ? %b",
                         $signed(vmem_after_leak), $signed(vmem_after_input), 
                         $signed(vmem_after_input), cfg_threshold,
                         (vmem_after_input >= $signed({1'b0, cfg_threshold})));

                // Step 3: Threshold check
                if (vmem_after_input >= $signed({1'b0, cfg_threshold})) begin
                    // Fire!
                    $display("[LIF] SPIKE! vmem_after_input=%0d >= threshold=%0d", $signed(vmem_after_input), cfg_threshold);
                    spike_out <= 1'b1;
                    vmem <= cfg_reset_potential;
                    refrac_cnt <= cfg_refractory;
                end else begin
                    vmem <= vmem_after_input[VMEM_WIDTH-1:0];
                end
            end
        end
    end

    // Membrane potential output for debug
    always @(*) begin
        vmem_out = vmem;
    end

endmodule

`default_nettype wire

