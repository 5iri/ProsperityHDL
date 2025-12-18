// lif.v ────────────────────────────────────────────────────────────────────
// Leaky Integrate-and-Fire (LIF) Neuron - Single Neuron Unit (IEEE FP16)
//
// This module implements ONE LIF neuron using IEEE 754 half-precision (FP16)
// for all computations. Instantiate multiple in processor.v to create the 
// full PE array with integrated neuron dynamics.
//
// All values are in FP16 format:
//   - Membrane potential (vmem)
//   - Synaptic input
//   - Threshold
//   - Leak
//   - Reset potential
//
// Neuron dynamics (per timestep):
//   1. If in refractory: decrement counter, hold state, no spike
//   2. Else: V_mem = V_mem - leak + synaptic_input (FP16 arithmetic)
//   3. If V_mem >= threshold: spike=1, V_mem=reset, enter refractory
//   4. Clamp V_mem to 0 if negative
//
// FP16 Format: [15]=sign, [14:10]=exponent (bias=15), [9:0]=mantissa
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

/* verilator lint_off UNUSEDPARAM */

module lif #(
    parameter integer INPUT_WIDTH   = 16,           // Width of synaptic input (FP16)
    parameter integer VMEM_WIDTH    = 16,           // Membrane potential width (FP16)
    parameter integer THRESH_WIDTH  = 16,           // Threshold width (FP16)
    parameter integer LEAK_WIDTH    = 16,           // Leak value width (FP16)
    parameter integer REFRAC_WIDTH  = 4             // Refractory counter width (integer)
) (
    input  wire clk,
    input  wire rst_n,

    // Configuration (all FP16 except refractory which is integer cycles)
    input  wire [THRESH_WIDTH-1:0]  cfg_threshold,       // Firing threshold (FP16)
    input  wire [LEAK_WIDTH-1:0]    cfg_leak,            // Leak per timestep (FP16)
    input  wire [VMEM_WIDTH-1:0]    cfg_reset_potential, // Reset value after spike (FP16)
    input  wire [REFRAC_WIDTH-1:0]  cfg_refractory,      // Refractory period (integer cycles)

    // Synaptic input (from MAC result, FP16)
    input  wire [INPUT_WIDTH-1:0]        synaptic_input,
    input  wire                          input_valid,     // Pulse when input ready

    // Control
    input  wire                          update_en,       // Enable neuron update

    // Outputs
    output reg                           spike_out,       // Spike output
    output reg  [VMEM_WIDTH-1:0]         vmem_out,        // Membrane potential (for debug)
    output wire                          in_refractory    // Refractory status
);

    // =========================================================================
    // FP16 Constants
    // =========================================================================
    localparam [15:0] FP16_ZERO     = 16'h0000;  // 0.0
    localparam [15:0] FP16_NEG_ZERO = 16'h8000;  // -0.0

    // =========================================================================
    // Internal State
    // =========================================================================

    reg [VMEM_WIDTH-1:0] vmem;              // Membrane potential (FP16)
    reg [REFRAC_WIDTH-1:0] refrac_cnt;      // Refractory counter (integer)

    assign in_refractory = (refrac_cnt != 0);

    // =========================================================================
    // FP16 Adder Function (same as in processor.v)
    // =========================================================================
    function [15:0] fp16_add;
        input [15:0] a;
        input [15:0] b;
        
        reg        sign_a, sign_b;
        reg [4:0]  exp_a, exp_b;
        reg [9:0]  mant_a, mant_b;
        
        reg        a_is_zero, b_is_zero;
        reg [4:0]  exp_diff;
        reg        a_larger;
        
        reg [11:0] full_mant_a, full_mant_b;
        reg [11:0] mant_large, mant_small;
        reg        sign_large, sign_small;
        reg [4:0]  result_exp;
        reg        effective_sub;
        
        reg [12:0] mant_sum;
        reg        result_sign;
        reg [12:0] mant_abs;
        
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
            
            if (a_is_zero && b_is_zero) begin
                fp16_add = FP16_ZERO;
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
                
                // Determine larger operand
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
                
                // Add or subtract
                effective_sub = sign_large ^ sign_small;
                
                if (effective_sub) begin
                    mant_sum = {1'b0, mant_large} - {1'b0, mant_small};
                    result_sign = sign_large;
                end else begin
                    mant_sum = {1'b0, mant_large} + {1'b0, mant_small};
                    result_sign = sign_large;
                end
                
                mant_abs = mant_sum;
                
                if (mant_abs == 13'd0) begin
                    fp16_add = FP16_ZERO;
                end else begin
                    // Normalize
                    if (mant_abs[12]) begin
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
                    
                    final_mant = mant_norm[10:1];
                    
                    if (exp_adj[5]) begin
                        // Severe underflow (negative exponent) - flush to zero
                        fp16_add = FP16_ZERO;
                    end else if (exp_adj == 6'd0) begin
                        // Result is subnormal (exp=0, non-zero mantissa)
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

    // =========================================================================
    // FP16 Subtraction (a - b = a + (-b))
    // =========================================================================
    function [15:0] fp16_sub;
        input [15:0] a;
        input [15:0] b;
        reg [15:0] neg_b;
        begin
            // Negate b by flipping sign bit
            neg_b = {~b[15], b[14:0]};
            fp16_sub = fp16_add(a, neg_b);
        end
    endfunction

    // =========================================================================
    // FP16 Comparison: returns 1 if a >= b
    // =========================================================================
    function fp16_gte;
        input [15:0] a;
        input [15:0] b;
        
        reg sign_a, sign_b;
        reg [4:0] exp_a, exp_b;
        reg [9:0] mant_a, mant_b;
        reg a_is_zero, b_is_zero;
        reg a_is_neg, b_is_neg;
        
        begin
            sign_a = a[15];
            sign_b = b[15];
            exp_a  = a[14:10];
            exp_b  = b[14:10];
            mant_a = a[9:0];
            mant_b = b[9:0];
            
            a_is_zero = (exp_a == 5'd0) && (mant_a == 10'd0);
            b_is_zero = (exp_b == 5'd0) && (mant_b == 10'd0);
            a_is_neg = sign_a && !a_is_zero;
            b_is_neg = sign_b && !b_is_zero;
            
            // Handle zeros (both +0 and -0 are equal)
            if (a_is_zero && b_is_zero) begin
                fp16_gte = 1'b1;
            end
            // Positive >= Negative
            else if (!a_is_neg && b_is_neg) begin
                fp16_gte = 1'b1;
            end
            // Negative < Positive
            else if (a_is_neg && !b_is_neg) begin
                fp16_gte = 1'b0;
            end
            // Both positive: compare magnitude
            else if (!a_is_neg && !b_is_neg) begin
                if (exp_a > exp_b) begin
                    fp16_gte = 1'b1;
                end else if (exp_a < exp_b) begin
                    fp16_gte = 1'b0;
                end else begin
                    fp16_gte = (mant_a >= mant_b);
                end
            end
            // Both negative: larger magnitude is smaller value
            else begin
                if (exp_a > exp_b) begin
                    fp16_gte = 1'b0;
                end else if (exp_a < exp_b) begin
                    fp16_gte = 1'b1;
                end else begin
                    fp16_gte = (mant_a <= mant_b);
                end
            end
        end
    endfunction

    // =========================================================================
    // FP16 Is Negative Check
    // =========================================================================
    function fp16_is_negative;
        input [15:0] a;
        reg [4:0] exp_a;
        reg [9:0] mant_a;
        begin
            exp_a = a[14:10];
            mant_a = a[9:0];
            // Check sign bit, but zero is not negative
            fp16_is_negative = a[15] && !((exp_a == 5'd0) && (mant_a == 10'd0));
        end
    endfunction

    // =========================================================================
    // Neuron Update Logic (FP16 Arithmetic)
    // =========================================================================

    reg [15:0] vmem_after_leak;
    reg [15:0] vmem_after_input;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            vmem <= FP16_ZERO;
            refrac_cnt <= {REFRAC_WIDTH{1'b0}};
            spike_out <= 1'b0;
        end else if (update_en) begin
            spike_out <= 1'b0;

            if (refrac_cnt != 0) begin
                // In refractory period - just decrement counter
                refrac_cnt <= refrac_cnt - 1'b1;
            end else begin
                // Active neuron - apply dynamics in FP16

                // Step 1: Apply leak (vmem = vmem - leak)
                vmem_after_leak = fp16_sub(vmem, cfg_leak);
                
                // Clamp to 0 if negative
                if (fp16_is_negative(vmem_after_leak)) begin
                    vmem_after_leak = FP16_ZERO;
                end

                // Step 2: Add synaptic input (if valid)
                if (input_valid) begin
                    vmem_after_input = fp16_add(vmem_after_leak, synaptic_input);
                end else begin
                    vmem_after_input = vmem_after_leak;
                end

                // Clamp to 0 if negative (no negative membrane potential)
                if (fp16_is_negative(vmem_after_input)) begin
                    vmem_after_input = FP16_ZERO;
                end

                // Step 3: Threshold check (FP16 comparison)
                if (fp16_gte(vmem_after_input, cfg_threshold)) begin
                    // Fire!
                    spike_out <= 1'b1;
                    vmem <= cfg_reset_potential;
                    refrac_cnt <= cfg_refractory;
                end else begin
                    vmem <= vmem_after_input;
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

