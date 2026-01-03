// axi_lite_bridge.v ─────────────────────────────────────────────────────────
// AXI4-Lite Slave Bridge for Prosperity PPU
//
// Provides standard AXI4-Lite slave interface for host communication:
//   - CSR register access (configuration, status, control)
//   - Spike injection buffer writes
//   - Spike collection buffer reads
//   - Weight memory control
//
// Address Map (directly addressable from AXI fabric):
//   0x0000 - 0x003F: CSR registers (see csr.v for register map)
//   0x0040 - 0x004F: Weight memory control
//   0x1000 - 0x1FFF: Spike injection buffer (write-only)
//   0x2000 - 0x2FFF: Spike collection buffer (read-only)
//   0x4000 - 0x7FFF: Weight memory (via DMA, optional direct access)
//
// AXI4-Lite Protocol:
//   - 32-bit data width
//   - Single-beat transactions only
//   - No burst support (use AXI4 full for DMA)
//
// Based on: Prosperity - Accelerating SNNs via Product Sparsity
// (c) 2025 Prosperity Project
// ──────────────────────────────────────────────────────────────────────────
`timescale 1ns / 1ps
`default_nettype none

module axi_lite_bridge #(
    parameter integer AXI_ADDR_WIDTH  = 16,       // Address width
    parameter integer AXI_DATA_WIDTH  = 32,       // Data width (must be 32)
    parameter integer ROWS            = 256,      // Number of rows
    parameter integer PE_COUNT        = 128,      // Number of PEs
    parameter integer SPIKES          = 16,       // Spikes per pattern
    parameter integer TIMESTEP_WIDTH  = 16,       // Timestep width
    parameter integer MAX_TIMESTEPS   = 256       // Max timesteps
) (
    input  wire                         clk,
    input  wire                         rst_n,

    // ─────────────────── AXI4-Lite Slave Interface ──────────────────────
    // Write Address Channel
    input  wire [AXI_ADDR_WIDTH-1:0]    s_axi_awaddr,
    input  wire [2:0]                   s_axi_awprot,
    input  wire                         s_axi_awvalid,
    output reg                          s_axi_awready,

    // Write Data Channel
    input  wire [AXI_DATA_WIDTH-1:0]    s_axi_wdata,
    input  wire [AXI_DATA_WIDTH/8-1:0]  s_axi_wstrb,
    input  wire                         s_axi_wvalid,
    output reg                          s_axi_wready,

    // Write Response Channel
    output reg  [1:0]                   s_axi_bresp,
    output reg                          s_axi_bvalid,
    input  wire                         s_axi_bready,

    // Read Address Channel
    input  wire [AXI_ADDR_WIDTH-1:0]    s_axi_araddr,
    input  wire [2:0]                   s_axi_arprot,
    input  wire                         s_axi_arvalid,
    output reg                          s_axi_arready,

    // Read Data Channel
    output reg  [AXI_DATA_WIDTH-1:0]    s_axi_rdata,
    output reg  [1:0]                   s_axi_rresp,
    output reg                          s_axi_rvalid,
    input  wire                         s_axi_rready,

    // ─────────────────── CSR Interface ──────────────────────────────────
    output wire [5:0]                   csr_addr,
    output reg  [31:0]                  csr_wdata,
    output reg                          csr_wr_en,
    output reg                          csr_rd_en,
    input  wire [31:0]                  csr_rdata,
    input  wire                         csr_ready,

    // ─────────────────── Spike Injection Interface ──────────────────────
    output reg                          spike_inject_wr_en,
    output reg  [$clog2(MAX_TIMESTEPS*ROWS)-1:0] spike_inject_wr_addr,
    output reg  [SPIKES-1:0]            spike_inject_wr_data,

    // ─────────────────── Spike Collection Interface ─────────────────────
    output reg                          spike_collect_rd_en,
    output reg  [$clog2(MAX_TIMESTEPS*ROWS)-1:0] spike_collect_rd_addr,
    input  wire [PE_COUNT-1:0]          spike_collect_rd_data,

    // ─────────────────── Weight Memory Control ──────────────────────────
    output reg                          weight_load_start,
    output reg  [31:0]                  weight_base_addr,
    input  wire                         weight_load_done,
    input  wire                         weight_load_busy
);

    // =========================================================================
    // Address Decode Constants
    // Note: With 16-bit AXI addresses (64KB), we can access:
    //   - Spike inject: up to 16K entries (32KB / 2 bytes per entry)
    //   - Spike collect: up to 1K entries (16KB / 16 bytes per entry)
    // For full 256×256=65K entry buffers, increase AXI_ADDR_WIDTH or use paging
    // =========================================================================
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_CSR_BASE      = 16'h0000;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_CSR_END       = 16'h003F;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_WEIGHT_CTRL   = 16'h0040;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_WEIGHT_BASE   = 16'h0044;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_WEIGHT_STATUS = 16'h0048;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_INJECT_BASE   = 16'h1000;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_INJECT_END    = 16'h8FFF;  // 32KB for spike inject
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_COLLECT_BASE  = 16'h9000;
    localparam [AXI_ADDR_WIDTH-1:0] ADDR_COLLECT_END   = 16'hCFFF;  // 16KB for spike collect

    // AXI Response Codes
    localparam [1:0] RESP_OKAY   = 2'b00;
    localparam [1:0] RESP_SLVERR = 2'b10;

    // =========================================================================
    // FSM States
    // =========================================================================
    localparam [2:0] ST_IDLE      = 3'd0;
    localparam [2:0] ST_WR_ADDR   = 3'd1;
    localparam [2:0] ST_WR_DATA   = 3'd2;
    localparam [2:0] ST_WR_RESP   = 3'd3;
    localparam [2:0] ST_RD_ADDR   = 3'd4;
    localparam [2:0] ST_RD_DATA   = 3'd5;

    reg [2:0] state, next_state;

    // =========================================================================
    // Internal Registers - Separate per channel to avoid multi-driver issues
    // =========================================================================
    // Write channel registers
    reg [AXI_ADDR_WIDTH-1:0] wr_addr_latch;
    reg [AXI_DATA_WIDTH-1:0] wdata_latch;
    reg [AXI_DATA_WIDTH/8-1:0] wstrb_latch;
    reg [5:0] csr_wr_addr;  // CSR address for write channel
    
    // Read channel registers
    reg [AXI_ADDR_WIDTH-1:0] rd_addr_latch;
    reg rd_pending;
    reg [1:0] rd_wait_cnt;  // Wait cycles for read data
    reg [5:0] csr_rd_addr;  // CSR address for read channel

    // CSR address mux - select based on which operation is active
    assign csr_addr = csr_wr_en ? csr_wr_addr : csr_rd_addr;

    // Address decode signals - write channel
    wire wr_addr_is_csr;
    wire wr_addr_is_weight_ctrl;
    wire wr_addr_is_inject;

    assign wr_addr_is_csr = (wr_addr_latch <= ADDR_CSR_END);
    assign wr_addr_is_weight_ctrl = (wr_addr_latch >= ADDR_WEIGHT_CTRL) && (wr_addr_latch <= ADDR_WEIGHT_STATUS);
    assign wr_addr_is_inject = (wr_addr_latch >= ADDR_INJECT_BASE) && (wr_addr_latch <= ADDR_INJECT_END);

    // Address decode signals - read channel
    wire rd_addr_is_csr;
    wire rd_addr_is_weight_ctrl;
    wire rd_addr_is_collect;

    assign rd_addr_is_csr = (rd_addr_latch <= ADDR_CSR_END);
    assign rd_addr_is_weight_ctrl = (rd_addr_latch >= ADDR_WEIGHT_CTRL) && (rd_addr_latch <= ADDR_WEIGHT_STATUS);
    assign rd_addr_is_collect = (rd_addr_latch >= ADDR_COLLECT_BASE) && (rd_addr_latch <= ADDR_COLLECT_END);

    // =========================================================================
    // FSM State Transitions
    // =========================================================================
    always @(*) begin
        next_state = state;
        case (state)
            ST_IDLE: begin
                if (s_axi_awvalid)
                    next_state = ST_WR_ADDR;
                else if (s_axi_arvalid)
                    next_state = ST_RD_ADDR;
            end

            ST_WR_ADDR: begin
                next_state = ST_WR_DATA;
            end

            ST_WR_DATA: begin
                if (s_axi_wvalid)
                    next_state = ST_WR_RESP;
            end

            ST_WR_RESP: begin
                if (s_axi_bready)
                    next_state = ST_IDLE;
            end

            ST_RD_ADDR: begin
                next_state = ST_RD_DATA;
            end

            ST_RD_DATA: begin
                // Wait for read data to be ready
                if (s_axi_rvalid && s_axi_rready)
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
    // AXI Write Logic
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            s_axi_awready <= 1'b0;
            s_axi_wready <= 1'b0;
            s_axi_bvalid <= 1'b0;
            s_axi_bresp <= RESP_OKAY;
            wr_addr_latch <= {AXI_ADDR_WIDTH{1'b0}};
            wdata_latch <= {AXI_DATA_WIDTH{1'b0}};
            wstrb_latch <= {(AXI_DATA_WIDTH/8){1'b0}};
            
            csr_wr_en <= 1'b0;
            csr_wr_addr <= 6'd0;
            csr_wdata <= 32'd0;
            spike_inject_wr_en <= 1'b0;
            spike_inject_wr_addr <= 0;
            spike_inject_wr_data <= {SPIKES{1'b0}};
            weight_load_start <= 1'b0;
            weight_base_addr <= 32'd0;
        end else begin
            // Default pulse signals
            s_axi_awready <= 1'b0;
            s_axi_wready <= 1'b0;
            csr_wr_en <= 1'b0;
            spike_inject_wr_en <= 1'b0;
            weight_load_start <= 1'b0;

            case (state)
                ST_IDLE: begin
                    s_axi_bvalid <= 1'b0;
                end

                ST_WR_ADDR: begin
                    s_axi_awready <= 1'b1;
                    wr_addr_latch <= s_axi_awaddr;
                end

                ST_WR_DATA: begin
                    s_axi_wready <= 1'b1;
                    if (s_axi_wvalid) begin
                        wdata_latch <= s_axi_wdata;
                        wstrb_latch <= s_axi_wstrb;
                        
                        // Perform the write based on address
                        if (wr_addr_is_csr) begin
                            csr_wr_addr <= wr_addr_latch[5:0];
                            csr_wdata <= s_axi_wdata;
                            csr_wr_en <= 1'b1;
                            s_axi_bresp <= RESP_OKAY;
                        end else if (wr_addr_is_weight_ctrl) begin
                            case (wr_addr_latch[3:0])
                                4'h0: begin
                                    weight_load_start <= s_axi_wdata[0];  // WEIGHT_CTRL
                                    s_axi_bresp <= RESP_OKAY;
                                end
                                4'h4: begin
                                    weight_base_addr <= s_axi_wdata;      // WEIGHT_BASE
                                    s_axi_bresp <= RESP_OKAY;
                                end
                                default: s_axi_bresp <= RESP_SLVERR;
                            endcase
                        end else if (wr_addr_is_inject) begin
                            // Spike injection buffer write
                            // AXI writes are 32-bit word-aligned, so divide byte offset by 4
                            spike_inject_wr_addr <= (wr_addr_latch - ADDR_INJECT_BASE) >> 2;
                            spike_inject_wr_data <= s_axi_wdata[SPIKES-1:0];
                            spike_inject_wr_en <= 1'b1;
                            s_axi_bresp <= RESP_OKAY;
                        end else begin
                            // Invalid address or read-only region
                            s_axi_bresp <= RESP_SLVERR;
                        end
                    end
                end

                ST_WR_RESP: begin
                    s_axi_bvalid <= 1'b1;
                end

                default: ;
            endcase
        end
    end

    // =========================================================================
    // AXI Read Logic
    // =========================================================================
    always @(posedge clk) begin
        if (!rst_n) begin
            s_axi_arready <= 1'b0;
            s_axi_rvalid <= 1'b0;
            s_axi_rdata <= {AXI_DATA_WIDTH{1'b0}};
            s_axi_rresp <= RESP_OKAY;
            rd_pending <= 1'b0;
            rd_wait_cnt <= 2'd0;
            rd_addr_latch <= {AXI_ADDR_WIDTH{1'b0}};
            
            csr_rd_en <= 1'b0;
            csr_rd_addr <= 6'd0;
            spike_collect_rd_en <= 1'b0;
            spike_collect_rd_addr <= 0;
        end else begin
            // Default pulse signals
            s_axi_arready <= 1'b0;
            csr_rd_en <= 1'b0;
            spike_collect_rd_en <= 1'b0;

            case (state)
                ST_IDLE: begin
                    s_axi_rvalid <= 1'b0;
                    rd_pending <= 1'b0;
                end

                ST_RD_ADDR: begin
                    s_axi_arready <= 1'b1;
                    rd_addr_latch <= s_axi_araddr;
                    rd_pending <= 1'b1;
                    rd_wait_cnt <= 2'd0;
                    
                    // Initiate read based on address (CSR base is 0)
                    if (s_axi_araddr <= ADDR_CSR_END) begin
                        csr_rd_addr <= s_axi_araddr[5:0];
                        csr_rd_en <= 1'b1;
                    end else if ((s_axi_araddr >= ADDR_COLLECT_BASE) && (s_axi_araddr <= ADDR_COLLECT_END)) begin
                        // Each entry is PE_COUNT bits (128 bits = 16 bytes)
                        // Divide byte offset by 16 to get row index
                        spike_collect_rd_addr <= (s_axi_araddr - ADDR_COLLECT_BASE) >> 4;
                        spike_collect_rd_en <= 1'b1;
                    end
                end

                ST_RD_DATA: begin
                    // Wait one cycle for read data to be ready
                    rd_wait_cnt <= rd_wait_cnt + 1;
                    
                    if (rd_wait_cnt >= 2'd1 && !s_axi_rvalid) begin
                        s_axi_rvalid <= 1'b1;
                        
                        // Return read data based on address
                        if (rd_addr_is_csr) begin
                            s_axi_rdata <= csr_rdata;
                            s_axi_rresp <= RESP_OKAY;
                        end else if (rd_addr_is_weight_ctrl) begin
                            case (rd_addr_latch[3:0])
                                4'h0: s_axi_rdata <= {31'd0, weight_load_busy};  // WEIGHT_CTRL/STATUS
                                4'h4: s_axi_rdata <= weight_base_addr;           // WEIGHT_BASE
                                4'h8: s_axi_rdata <= {30'd0, weight_load_busy, weight_load_done}; // WEIGHT_STATUS
                                default: s_axi_rdata <= 32'hDEAD_BEEF;
                            endcase
                            s_axi_rresp <= RESP_OKAY;
                        end else if (rd_addr_is_collect) begin
                            // Spike collection buffer read
                            // PE_COUNT=128 bits = 4 x 32-bit words per entry
                            // Use rd_addr_latch[3:2] to select which 32-bit slice
                            case (rd_addr_latch[3:2])
                                2'b00: s_axi_rdata <= spike_collect_rd_data[31:0];
                                2'b01: s_axi_rdata <= spike_collect_rd_data[63:32];
                                2'b10: s_axi_rdata <= spike_collect_rd_data[95:64];
                                2'b11: s_axi_rdata <= spike_collect_rd_data[127:96];
                            endcase
                            s_axi_rresp <= RESP_OKAY;
                        end else begin
                            // Invalid address
                            s_axi_rdata <= 32'hDEAD_BEEF;
                            s_axi_rresp <= RESP_SLVERR;
                        end
                    end
                    
                    if (s_axi_rvalid && s_axi_rready) begin
                        s_axi_rvalid <= 1'b0;
                        rd_pending <= 1'b0;
                    end
                end

                default: ;
            endcase
        end
    end

endmodule

`default_nettype wire
