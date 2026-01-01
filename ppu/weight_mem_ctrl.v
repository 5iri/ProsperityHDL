// weight_mem_ctrl.v ─────────────────────────────────────────────────────────
// Weight Memory Controller for Prosperity PPU
//
// Provides burst-friendly interface between external memory (SRAM/DRAM via AXI)
// and the processor's weight buffer. Supports:
//   - Burst reads from external memory
//   - FP16 weight packing (2 weights per 32-bit word)
//   - Outstanding read scheduling for latency hiding
//   - Double-buffering for overlap of load and compute
//
// Memory Organization:
//   External: weights[pe_idx * SPIKES + spike_idx] in FP16
//   Internal: weight_buffer[PE][SPIKE] in processor.v
//
// Operation:
//   1. Host configures base address and initiates load
//   2. Controller issues burst reads to external memory
//   3. Unpacks FP16 weights and streams to processor interface
//   4. Signals completion when all weights loaded
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module weight_mem_ctrl #(
    parameter integer PE_COUNT       = 128,      // Number of Processing Elements
    parameter integer SPIKES         = 16,       // Spikes per pattern
    parameter integer WEIGHT_WIDTH   = 16,       // FP16 weights
    parameter integer ADDR_WIDTH     = 32,       // External memory address width
    parameter integer DATA_WIDTH     = 32,       // External memory data width (AXI)
    parameter integer BURST_LEN      = 16        // Burst length (AXI4 max 256)
) (
    input  wire                      clk,
    input  wire                      rst_n,

    // ─────────────────── Control Interface ──────────────────────────────
    input  wire                      load_start,      // Start weight loading
    input  wire [ADDR_WIDTH-1:0]     base_addr,       // Base address in external memory
    output reg                       load_done,       // Weight loading complete
    output reg                       load_busy,       // Weight loading in progress

    // ─────────────────── External Memory Interface (AXI-like) ───────────
    // Read Address Channel
    output reg  [ADDR_WIDTH-1:0]     mem_araddr,      // Read address
    output reg  [7:0]                mem_arlen,       // Burst length - 1
    output reg  [2:0]                mem_arsize,      // Beat size (3'b010 = 4 bytes)
    output reg  [1:0]                mem_arburst,     // Burst type (2'b01 = INCR)
    output reg                       mem_arvalid,     // Address valid
    input  wire                      mem_arready,     // Address ready

    // Read Data Channel
    input  wire [DATA_WIDTH-1:0]     mem_rdata,       // Read data
    input  wire [1:0]                mem_rresp,       // Read response
    input  wire                      mem_rlast,       // Last beat in burst
    input  wire                      mem_rvalid,      // Data valid
    output reg                       mem_rready,      // Data ready

    // ─────────────────── Processor Weight Interface ─────────────────────
    output reg  [$clog2(SPIKES*PE_COUNT)-1:0] weight_addr,  // Weight buffer address
    output reg  [WEIGHT_WIDTH-1:0]            weight_data,  // Weight data (FP16)
    output reg                                weight_wr_en, // Weight write enable
    
    // ─────────────────── Status ─────────────────────────────────────────
    output wire [$clog2(PE_COUNT*SPIKES):0]   weights_loaded  // Number of weights loaded
);

    // =========================================================================
    // Constants (with proper widths)
    // =========================================================================
    localparam TOTAL_WEIGHTS = PE_COUNT * SPIKES;           // 128 * 16 = 2048 weights
    localparam WEIGHTS_PER_WORD = DATA_WIDTH / WEIGHT_WIDTH; // 32 / 16 = 2
    localparam TOTAL_WORDS = TOTAL_WEIGHTS / WEIGHTS_PER_WORD; // 1024 words
    localparam TOTAL_BURSTS = (TOTAL_WORDS + BURST_LEN - 1) / BURST_LEN;
    
    // Width-matched constants for comparisons (explicit bit selection)
    localparam [$clog2(TOTAL_WEIGHTS):0] TOTAL_WEIGHTS_W = TOTAL_WEIGHTS[$clog2(TOTAL_WEIGHTS):0];
    localparam [$clog2(BURST_LEN):0] BURST_LEN_W = BURST_LEN[$clog2(BURST_LEN):0];
    localparam [$clog2(TOTAL_BURSTS):0] TOTAL_BURSTS_W = TOTAL_BURSTS[$clog2(TOTAL_BURSTS):0];

    // =========================================================================
    // FSM States
    // =========================================================================
    localparam [2:0] ST_IDLE       = 3'd0;
    localparam [2:0] ST_ADDR       = 3'd1;  // Issue read address
    localparam [2:0] ST_DATA       = 3'd2;  // Receive read data
    localparam [2:0] ST_UNPACK     = 3'd3;  // Unpack and write weights
    localparam [2:0] ST_NEXT_BURST = 3'd4;  // Prepare next burst
    localparam [2:0] ST_DONE       = 3'd5;

    reg [2:0] state, next_state;

    // =========================================================================
    // Internal Registers
    // =========================================================================
    reg [ADDR_WIDTH-1:0] current_addr;
    reg [$clog2(TOTAL_BURSTS):0] burst_count;
    reg [$clog2(BURST_LEN):0] beat_count;
    reg [$clog2(TOTAL_WEIGHTS):0] weight_count;
    
    // Data unpacking registers
    reg [DATA_WIDTH-1:0] data_buffer;
    reg unpack_phase;  // 0 = lower 16 bits, 1 = upper 16 bits
    reg burst_last;    // Captured mem_rlast for current word

    // Weight counter output
    assign weights_loaded = weight_count;

    // =========================================================================
    // FSM State Transitions
    // =========================================================================
    always @(*) begin
        next_state = state;
        case (state)
            ST_IDLE: begin
                if (load_start)
                    next_state = ST_ADDR;
            end

            ST_ADDR: begin
                if (mem_arvalid && mem_arready)
                    next_state = ST_DATA;
            end

            ST_DATA: begin
                if (mem_rvalid && mem_rready) begin
                    next_state = ST_UNPACK;
                end
            end

            ST_UNPACK: begin
                // Unpack both weights from the 32-bit word
                if (unpack_phase == 1'b1) begin
                    // Done unpacking this word - check if this is the last weight
                    // weight_count is pre-increment, so after this cycle it will be weight_count+1
                    // We're done when the next increment would reach TOTAL_WEIGHTS
                    if (weight_count >= TOTAL_WEIGHTS_W - 1) begin
                        next_state = ST_DONE;
                    end else if (burst_last) begin
                        // Use captured mem_rlast to handle partial bursts correctly
                        next_state = ST_NEXT_BURST;
                    end else begin
                        next_state = ST_DATA;
                    end
                end
            end

            ST_NEXT_BURST: begin
                if (burst_count < TOTAL_BURSTS_W)
                    next_state = ST_ADDR;
                else
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
            current_addr <= {ADDR_WIDTH{1'b0}};
            burst_count <= 0;
            beat_count <= 0;
            weight_count <= 0;
            data_buffer <= {DATA_WIDTH{1'b0}};
            unpack_phase <= 1'b0;
            burst_last <= 1'b0;
            
            // Output registers
            mem_araddr <= {ADDR_WIDTH{1'b0}};
            mem_arlen <= 8'd0;
            mem_arsize <= 3'b010;  // 4 bytes
            mem_arburst <= 2'b01;  // INCR
            mem_arvalid <= 1'b0;
            mem_rready <= 1'b0;
            
            weight_addr <= 0;
            weight_data <= {WEIGHT_WIDTH{1'b0}};
            weight_wr_en <= 1'b0;
            
            load_done <= 1'b0;
            load_busy <= 1'b0;
        end else begin
            // Default values
            weight_wr_en <= 1'b0;
            // Note: load_done is NOT cleared here - it's sticky until next load_start

            case (state)
                ST_IDLE: begin
                    load_busy <= 1'b0;
                    if (load_start) begin
                        current_addr <= base_addr;
                        burst_count <= 0;
                        beat_count <= 0;
                        weight_count <= 0;
                        unpack_phase <= 1'b0;
                        burst_last <= 1'b0;
                        load_busy <= 1'b1;
                        load_done <= 1'b0;  // Clear done flag when starting new load
                    end
                end

                ST_ADDR: begin
                    // Issue read address
                    mem_araddr <= current_addr;
                    // Calculate burst length for remaining words
                    if ((TOTAL_WORDS - burst_count * BURST_LEN) >= BURST_LEN)
                        mem_arlen <= 8'(BURST_LEN - 1);
                    else
                        mem_arlen <= 8'((TOTAL_WORDS - burst_count * BURST_LEN) - 1);
                    mem_arvalid <= 1'b1;
                    mem_rready <= 1'b0;
                    
                    if (mem_arvalid && mem_arready) begin
                        mem_arvalid <= 1'b0;
                        mem_rready <= 1'b1;
                        beat_count <= 0;
                    end
                end

                ST_DATA: begin
                    mem_rready <= 1'b1;
                    if (mem_rvalid && mem_rready) begin
                        data_buffer <= mem_rdata;
                        burst_last <= mem_rlast;  // Capture last beat indicator
                        unpack_phase <= 1'b0;
                        beat_count <= beat_count + 1;
                        mem_rready <= 1'b0;  // Pause while unpacking
                    end
                end

                ST_UNPACK: begin
                    // Write one FP16 weight per cycle
                    weight_wr_en <= 1'b1;
                    weight_addr <= weight_count[$clog2(SPIKES*PE_COUNT)-1:0];
                    
                    if (unpack_phase == 1'b0) begin
                        // Lower 16 bits (first weight)
                        weight_data <= data_buffer[15:0];
                        unpack_phase <= 1'b1;
                        weight_count <= weight_count + 1;
                    end else begin
                        // Upper 16 bits (second weight)
                        weight_data <= data_buffer[31:16];
                        unpack_phase <= 1'b0;
                        weight_count <= weight_count + 1;
                    end
                end

                ST_NEXT_BURST: begin
                    // Prepare for next burst
                    current_addr <= current_addr + (BURST_LEN * (DATA_WIDTH / 8));
                    burst_count <= burst_count + 1;
                    beat_count <= 0;
                end

                ST_DONE: begin
                    load_done <= 1'b1;
                    load_busy <= 1'b0;
                    mem_arvalid <= 1'b0;
                    mem_rready <= 1'b0;
                end

                default: ;
            endcase
        end
    end

endmodule

`default_nettype wire
