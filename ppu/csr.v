// csr.v ─────────────────────────────────────────────────────────────────────
// Control/Status Register File for Prosperity PPU
//
// Provides memory-mapped configuration and status registers for:
//   - PPU control (start, stop, reset)
//   - LIF neuron parameters (threshold, leak, reset, refractory)
//   - Timestep configuration
//   - Status readback (busy, done, spike counts)
//   - Debug/performance counters
//
// Register Map (32-bit registers, byte-addressable):
//   0x00: CTRL        - Control register [0]=start, [1]=stop, [2]=sw_reset
//   0x04: STATUS      - Status register [0]=ready, [1]=busy, [2]=done, [3]=error
//   0x08: CONFIG      - Configuration [0]=lif_enable, [1]=auto_repeat, [7:4]=reserved
//   0x0C: TIMESTEPS   - Number of timesteps [15:0]
//   0x10: LIF_THRESH  - LIF threshold (FP16 in lower 16 bits)
//   0x14: LIF_LEAK    - LIF leak value (FP16 in lower 16 bits)
//   0x18: LIF_RESET   - LIF reset potential (FP16 in lower 16 bits)
//   0x1C: LIF_REFRAC  - LIF refractory period [3:0]
//   0x20: TIMESTEP_IDX- Current timestep index (read-only)
//   0x24: SPIKE_COUNT - Total spikes collected (read-only)
//   0x28: CYCLE_COUNT - Cycle counter (read-only, lower 32 bits)
//   0x2C: CYCLE_COUNT_H - Cycle counter (read-only, upper 32 bits)
//   0x30: TILE_COUNT  - Tiles processed counter (read-only)
//   0x34: IRQ_STATUS  - Interrupt status [0]=sim_done, [1]=error
//   0x38: IRQ_ENABLE  - Interrupt enable [0]=sim_done_en, [1]=error_en
//   0x3C: VERSION     - Hardware version (read-only)
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module csr #(
    parameter integer ADDR_WIDTH     = 6,        // 64 bytes of register space
    parameter integer DATA_WIDTH     = 32,       // 32-bit registers
    parameter integer TIMESTEP_WIDTH = 16,       // Timestep counter width
    parameter integer PE_COUNT       = 128,      // Number of PEs
    parameter integer ROWS           = 256,      // Number of rows
    parameter integer MAX_TIMESTEPS  = 256,      // Max timesteps
    parameter [31:0]  VERSION        = 32'h0002_0000  // Version 2.0.0 (Phase 2)
) (
    input  wire                      clk,
    input  wire                      rst_n,

    // Register Interface (directly addressable or from AXI-Lite bridge)
    input  wire [ADDR_WIDTH-1:0]     reg_addr,
    input  wire [DATA_WIDTH-1:0]     reg_wdata,
    input  wire                      reg_wr_en,
    input  wire                      reg_rd_en,
    output reg  [DATA_WIDTH-1:0]     reg_rdata,
    output reg                       reg_ready,

    // ─────────────────── PPU Control Outputs ────────────────────────────
    output reg                       ctrl_start,          // Pulse to start simulation
    output reg                       ctrl_stop,           // Pulse to stop simulation
    output reg                       ctrl_sw_reset,       // Software reset pulse

    // ─────────────────── Configuration Outputs ──────────────────────────
    output reg                       cfg_lif_enable,      // Enable LIF neurons
    output reg                       cfg_auto_repeat,     // Auto-repeat tile processing
    output reg  [TIMESTEP_WIDTH-1:0] cfg_num_timesteps,   // Number of timesteps

    // ─────────────────── LIF Configuration Outputs ──────────────────────
    output reg  [15:0]               cfg_lif_threshold,   // FP16 threshold
    output reg  [15:0]               cfg_lif_leak,        // FP16 leak
    output reg  [15:0]               cfg_lif_reset,       // FP16 reset potential
    output reg  [3:0]                cfg_lif_refractory,  // Refractory cycles

    // ─────────────────── Status Inputs ──────────────────────────────────
    input  wire                      ppu_ready,           // PPU ready
    input  wire                      ppu_busy,            // PPU busy
    input  wire                      sim_done,            // Simulation complete
    input  wire                      sim_active,          // Simulation in progress
    input  wire [TIMESTEP_WIDTH-1:0] timestep_idx,        // Current timestep
    input  wire [$clog2(MAX_TIMESTEPS*ROWS):0] spike_count, // Spikes collected
    input  wire                      tile_done,           // Tile processing complete

    // ─────────────────── Interrupt Output ───────────────────────────────
    output wire                      irq                  // Interrupt request
);

    // =========================================================================
    // Register Address Definitions
    // =========================================================================
    localparam [ADDR_WIDTH-1:0] REG_CTRL         = 6'h00;
    localparam [ADDR_WIDTH-1:0] REG_STATUS       = 6'h04;
    localparam [ADDR_WIDTH-1:0] REG_CONFIG       = 6'h08;
    localparam [ADDR_WIDTH-1:0] REG_TIMESTEPS    = 6'h0C;
    localparam [ADDR_WIDTH-1:0] REG_LIF_THRESH   = 6'h10;
    localparam [ADDR_WIDTH-1:0] REG_LIF_LEAK     = 6'h14;
    localparam [ADDR_WIDTH-1:0] REG_LIF_RESET    = 6'h18;
    localparam [ADDR_WIDTH-1:0] REG_LIF_REFRAC   = 6'h1C;
    localparam [ADDR_WIDTH-1:0] REG_TIMESTEP_IDX = 6'h20;
    localparam [ADDR_WIDTH-1:0] REG_SPIKE_COUNT  = 6'h24;
    localparam [ADDR_WIDTH-1:0] REG_CYCLE_COUNT  = 6'h28;
    localparam [ADDR_WIDTH-1:0] REG_CYCLE_COUNT_H= 6'h2C;
    localparam [ADDR_WIDTH-1:0] REG_TILE_COUNT   = 6'h30;
    localparam [ADDR_WIDTH-1:0] REG_IRQ_STATUS   = 6'h34;
    localparam [ADDR_WIDTH-1:0] REG_IRQ_ENABLE   = 6'h38;
    localparam [ADDR_WIDTH-1:0] REG_VERSION      = 6'h3C;

    // =========================================================================
    // Internal Registers
    // =========================================================================
    
    // Control register (directly written)
    reg [DATA_WIDTH-1:0] r_ctrl;
    
    // Configuration register
    reg [DATA_WIDTH-1:0] r_config;
    
    // Interrupt registers
    reg [DATA_WIDTH-1:0] r_irq_status;
    reg [DATA_WIDTH-1:0] r_irq_enable;
    
    // Performance counters
    reg [63:0] cycle_counter;
    reg [31:0] tile_counter;
    
    // Edge detection for tile_done
    reg tile_done_d;
    wire tile_done_rising;
    assign tile_done_rising = tile_done && !tile_done_d;

    // Edge detection for sim_done (interrupt generation)
    reg sim_done_d;
    wire sim_done_rising;
    assign sim_done_rising = sim_done && !sim_done_d;

    // =========================================================================
    // Cycle Counter
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n || ctrl_sw_reset) begin
            cycle_counter <= 64'd0;
        end else if (sim_active) begin
            cycle_counter <= cycle_counter + 1;
        end
    end

    // =========================================================================
    // Tile Counter
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n || ctrl_sw_reset) begin
            tile_counter <= 32'd0;
            tile_done_d <= 1'b0;
        end else begin
            tile_done_d <= tile_done;
            if (tile_done_rising) begin
                tile_counter <= tile_counter + 1;
            end
        end
    end

    // =========================================================================
    // Interrupt Status
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n || ctrl_sw_reset) begin
            r_irq_status <= 32'd0;
            sim_done_d <= 1'b0;
        end else begin
            sim_done_d <= sim_done;
            
            // Set interrupt status bits (sticky until cleared by write)
            if (sim_done_rising) begin
                r_irq_status[0] <= 1'b1;  // sim_done interrupt
            end
            
            // Clear on write-1-to-clear
            if (reg_wr_en && reg_addr == REG_IRQ_STATUS) begin
                r_irq_status <= r_irq_status & ~reg_wdata;
            end
        end
    end

    // Interrupt output
    assign irq = |(r_irq_status & r_irq_enable);

    // =========================================================================
    // Register Write Logic
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            r_ctrl <= 32'd0;
            r_config <= 32'd0;
            cfg_num_timesteps <= 16'd1;
            cfg_lif_threshold <= 16'h3C00;  // FP16 1.0
            cfg_lif_leak <= 16'h2E66;       // FP16 0.1
            cfg_lif_reset <= 16'h0000;      // FP16 0.0
            cfg_lif_refractory <= 4'd2;
            r_irq_enable <= 32'd0;
            
            ctrl_start <= 1'b0;
            ctrl_stop <= 1'b0;
            ctrl_sw_reset <= 1'b0;
            cfg_lif_enable <= 1'b0;
            cfg_auto_repeat <= 1'b0;
        end else begin
            // Clear pulse signals
            ctrl_start <= 1'b0;
            ctrl_stop <= 1'b0;
            ctrl_sw_reset <= 1'b0;

            if (reg_wr_en) begin
                case (reg_addr)
                    REG_CTRL: begin
                        r_ctrl <= reg_wdata;
                        // Generate pulses for control bits
                        ctrl_start <= reg_wdata[0];
                        ctrl_stop <= reg_wdata[1];
                        ctrl_sw_reset <= reg_wdata[2];
                    end
                    
                    REG_CONFIG: begin
                        r_config <= reg_wdata;
                        cfg_lif_enable <= reg_wdata[0];
                        cfg_auto_repeat <= reg_wdata[1];
                    end
                    
                    REG_TIMESTEPS: begin
                        cfg_num_timesteps <= reg_wdata[TIMESTEP_WIDTH-1:0];
                    end
                    
                    REG_LIF_THRESH: begin
                        cfg_lif_threshold <= reg_wdata[15:0];
                    end
                    
                    REG_LIF_LEAK: begin
                        cfg_lif_leak <= reg_wdata[15:0];
                    end
                    
                    REG_LIF_RESET: begin
                        cfg_lif_reset <= reg_wdata[15:0];
                    end
                    
                    REG_LIF_REFRAC: begin
                        cfg_lif_refractory <= reg_wdata[3:0];
                    end
                    
                    REG_IRQ_ENABLE: begin
                        r_irq_enable <= reg_wdata;
                    end
                    
                    // REG_IRQ_STATUS handled separately (write-1-to-clear)
                    
                    default: ; // Ignore writes to read-only or invalid registers
                endcase
            end
        end
    end

    // =========================================================================
    // Register Read Logic
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            reg_rdata <= 32'd0;
            reg_ready <= 1'b0;
        end else begin
            reg_ready <= reg_rd_en | reg_wr_en;
            
            if (reg_rd_en) begin
                case (reg_addr)
                    REG_CTRL:         reg_rdata <= r_ctrl;
                    REG_STATUS:       reg_rdata <= {28'd0, 1'b0, sim_done, ppu_busy, ppu_ready};
                    REG_CONFIG:       reg_rdata <= r_config;
                    REG_TIMESTEPS:    reg_rdata <= {{(32-TIMESTEP_WIDTH){1'b0}}, cfg_num_timesteps};
                    REG_LIF_THRESH:   reg_rdata <= {16'd0, cfg_lif_threshold};
                    REG_LIF_LEAK:     reg_rdata <= {16'd0, cfg_lif_leak};
                    REG_LIF_RESET:    reg_rdata <= {16'd0, cfg_lif_reset};
                    REG_LIF_REFRAC:   reg_rdata <= {28'd0, cfg_lif_refractory};
                    REG_TIMESTEP_IDX: reg_rdata <= {{(32-TIMESTEP_WIDTH){1'b0}}, timestep_idx};
                    REG_SPIKE_COUNT:  reg_rdata <= {{(32-$clog2(MAX_TIMESTEPS*ROWS)-1){1'b0}}, spike_count};
                    REG_CYCLE_COUNT:  reg_rdata <= cycle_counter[31:0];
                    REG_CYCLE_COUNT_H:reg_rdata <= cycle_counter[63:32];
                    REG_TILE_COUNT:   reg_rdata <= tile_counter;
                    REG_IRQ_STATUS:   reg_rdata <= r_irq_status;
                    REG_IRQ_ENABLE:   reg_rdata <= r_irq_enable;
                    REG_VERSION:      reg_rdata <= VERSION;
                    default:          reg_rdata <= 32'hDEAD_BEEF;  // Invalid register
                endcase
            end
        end
    end

endmodule

`default_nettype wire
