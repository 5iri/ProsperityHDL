// top.v  ──────────────────────────────────────────────────────────────
// Prosperity PPU - Top Level Module
// Implements the complete processing pipeline:
//   • Detector: TCAM-based subset detection
//   • Pruner: Eliminates redundant computations
//   • Dispatcher: Manages task distribution to compute cores
// 
// Key features:
//   • Pipelined architecture for high throughput
//   • Memory-mapped interface for configuration
//   • Support for dynamic pattern loading
//   • Configurable parameters for different use cases
//
// (c) 2025 Prosperity Project
`timescale 1ns / 1ps

/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off PINCONNECTEMPTY */

module top #(
    parameter ROWS         = 256,     // Maximum number of rows per tile
    parameter SPIKES       = 16,      // Number of spikes per pattern
    parameter NO_WIDTH     = 8,       // Width of number-of-ones counter (log2(SPIKES)+1)
    parameter PE_COUNT     = 128,     // Number of Processing Elements
    parameter WEIGHT_WIDTH = 16,      // Weight precision (IEEE FP16)
    parameter ACC_WIDTH    = 16,      // Accumulator width (IEEE FP16)
    // LIF Neuron Parameters (all FP16 except refractory)
    parameter VMEM_WIDTH    = 16,     // Membrane potential width (FP16)
    parameter THRESH_WIDTH  = 16,     // Threshold width (FP16)
    parameter LEAK_WIDTH    = 16,     // Leak value width (FP16)
    parameter REFRAC_WIDTH  = 4,      // Refractory counter width (integer cycles)
    // Timestep parameters
    parameter TIMESTEP_WIDTH = 16,    // Timestep counter width
    parameter MAX_TIMESTEPS  = 256,   // Maximum timesteps for buffers
    // AXI Parameters
    parameter AXI_ADDR_WIDTH = 16,
    parameter AXI_DATA_WIDTH = 32
) (
    // Clock and Reset
    input  wire clk,
    input  wire rst_n,

    // ─────────────────── AXI4-Lite Slave Interface ──────────────────────
    // All host access (CSR, spike injection, spike collection) via AXI
    input  wire [AXI_ADDR_WIDTH-1:0]   s_axi_awaddr,
    input  wire [2:0]                  s_axi_awprot,
    input  wire                        s_axi_awvalid,
    output wire                        s_axi_awready,
    input  wire [AXI_DATA_WIDTH-1:0]   s_axi_wdata,
    input  wire [AXI_DATA_WIDTH/8-1:0] s_axi_wstrb,
    input  wire                        s_axi_wvalid,
    output wire                        s_axi_wready,
    output wire [1:0]                  s_axi_bresp,
    output wire                        s_axi_bvalid,
    input  wire                        s_axi_bready,
    input  wire [AXI_ADDR_WIDTH-1:0]   s_axi_araddr,
    input  wire [2:0]                  s_axi_arprot,
    input  wire                        s_axi_arvalid,
    output wire                        s_axi_arready,
    output wire [AXI_DATA_WIDTH-1:0]   s_axi_rdata,
    output wire [1:0]                  s_axi_rresp,
    output wire                        s_axi_rvalid,
    input  wire                        s_axi_rready,

    // ─────────────────── External Weight Memory AXI Master ──────────────
    // DMA interface for weight loading from external memory
    output wire [31:0]                 m_axi_araddr,
    output wire [7:0]                  m_axi_arlen,
    output wire [2:0]                  m_axi_arsize,
    output wire [1:0]                  m_axi_arburst,
    output wire                        m_axi_arvalid,
    input  wire                        m_axi_arready,
    input  wire [31:0]                 m_axi_rdata,
    input  wire [1:0]                  m_axi_rresp,
    input  wire                        m_axi_rlast,
    input  wire                        m_axi_rvalid,
    output wire                        m_axi_rready,

    // ─────────────────── Status Outputs ─────────────────────────────────
    output wire              ppu_ready,        // PPU ready for new work
    output wire              ppu_busy,         // PPU is processing
    output wire              sim_active,       // Simulation in progress
    output wire              sim_done,         // All timesteps complete
    output wire              weight_load_done, // Weight loading complete
    output wire              weight_load_busy, // Weight loading in progress
    output wire              irq,              // Interrupt request

    // ─────────────────── Debug Outputs ──────────────────────────────────
    output wire [3:0]                    dbg_state,       // FSM state
    output wire [TIMESTEP_WIDTH-1:0]    dbg_timestep     // Current timestep
);

  // ===================================================================
  // Internal Signals and Registers
  // ===================================================================
  
  // Tile memory (dual-port)
  reg [SPIKES-1:0] tile_ram [0:ROWS-1];
  reg [NO_WIDTH-1:0] popcount_ram [0:ROWS-1];

  // ===================================================================
  // AXI Bridge, CSR, Weight Memory Controller
  // ===================================================================
  
  // CSR Interface signals
  wire [5:0]  csr_addr;
  wire [31:0] csr_wdata;
  wire        csr_wr_en;
  wire        csr_rd_en;
  wire [31:0] csr_rdata;
  wire        csr_ready;
  
  // CSR configuration outputs
  wire        ctrl_start;
  wire        ctrl_stop;
  wire        ctrl_sw_reset;
  wire        cfg_lif_enable;
  wire        cfg_auto_repeat;
  wire [TIMESTEP_WIDTH-1:0] cfg_num_timesteps;
  wire [15:0] cfg_lif_threshold;
  wire [15:0] cfg_lif_leak;
  wire [15:0] cfg_lif_reset;
  wire [3:0]  cfg_lif_refractory;
  
  // AXI bridge spike injection signals
  wire        spike_inject_wr_en;
  wire [$clog2(MAX_TIMESTEPS*ROWS)-1:0] spike_inject_wr_addr;
  wire [SPIKES-1:0] spike_inject_wr_data;
  
  // AXI bridge spike collection signals  
  wire        spike_collect_rd_en;
  wire [$clog2(MAX_TIMESTEPS*ROWS)-1:0] spike_collect_rd_addr;
  wire [PE_COUNT-1:0] spike_collect_rd_data;
  
  // Weight memory controller signals
  wire        weight_load_start;
  wire [31:0] weight_base_addr;
  wire        weight_load_done_i;
  wire        weight_load_busy_i;
  wire [$clog2(SPIKES*PE_COUNT)-1:0] weight_wr_addr;
  wire [WEIGHT_WIDTH-1:0] weight_wr_data;
  wire        weight_wr_en;
  
  // Internal weight buffer (loaded by DMA)
  reg [WEIGHT_WIDTH-1:0] weight_buffer [0:SPIKES*PE_COUNT-1];
  wire [$clog2(SPIKES*PE_COUNT)-1:0] weight_rd_addr;
  wire [WEIGHT_WIDTH-1:0] weight_rd_data;
  assign weight_rd_data = weight_buffer[weight_rd_addr];
  
  // Weight buffer write from DMA
  always @(posedge clk) begin
    if (weight_wr_en) weight_buffer[weight_wr_addr] <= weight_wr_data;
  end
  
  // Export status
  assign weight_load_done = weight_load_done_i;
  assign weight_load_busy = weight_load_busy_i;
  assign dbg_timestep = timestep_idx_internal;

  // ===================================================================
  // AXI-Lite Bridge Instance
  // ===================================================================
  axi_lite_bridge #(
    .AXI_ADDR_WIDTH(AXI_ADDR_WIDTH),
    .AXI_DATA_WIDTH(AXI_DATA_WIDTH),
    .ROWS(ROWS),
    .PE_COUNT(PE_COUNT),
    .SPIKES(SPIKES),
    .TIMESTEP_WIDTH(TIMESTEP_WIDTH),
    .MAX_TIMESTEPS(MAX_TIMESTEPS)
  ) u_axi_bridge (
    .clk(clk), .rst_n(rst_n),
    .s_axi_awaddr(s_axi_awaddr), .s_axi_awprot(s_axi_awprot),
    .s_axi_awvalid(s_axi_awvalid), .s_axi_awready(s_axi_awready),
    .s_axi_wdata(s_axi_wdata), .s_axi_wstrb(s_axi_wstrb),
    .s_axi_wvalid(s_axi_wvalid), .s_axi_wready(s_axi_wready),
    .s_axi_bresp(s_axi_bresp), .s_axi_bvalid(s_axi_bvalid), .s_axi_bready(s_axi_bready),
    .s_axi_araddr(s_axi_araddr), .s_axi_arprot(s_axi_arprot),
    .s_axi_arvalid(s_axi_arvalid), .s_axi_arready(s_axi_arready),
    .s_axi_rdata(s_axi_rdata), .s_axi_rresp(s_axi_rresp),
    .s_axi_rvalid(s_axi_rvalid), .s_axi_rready(s_axi_rready),
    .csr_addr(csr_addr), .csr_wdata(csr_wdata),
    .csr_wr_en(csr_wr_en), .csr_rd_en(csr_rd_en),
    .csr_rdata(csr_rdata), .csr_ready(csr_ready),
    .spike_inject_wr_en(spike_inject_wr_en),
    .spike_inject_wr_addr(spike_inject_wr_addr),
    .spike_inject_wr_data(spike_inject_wr_data),
    .spike_collect_rd_en(spike_collect_rd_en),
    .spike_collect_rd_addr(spike_collect_rd_addr),
    .spike_collect_rd_data(spike_collect_rd_data),
    .weight_load_start(weight_load_start),
    .weight_base_addr(weight_base_addr),
    .weight_load_done(weight_load_done_i),
    .weight_load_busy(weight_load_busy_i)
  );

  // ===================================================================
  // CSR Register File Instance
  // ===================================================================
  csr #(
    .TIMESTEP_WIDTH(TIMESTEP_WIDTH),
    .ROWS(ROWS),
    .MAX_TIMESTEPS(MAX_TIMESTEPS)
  ) u_csr (
    .clk(clk), .rst_n(rst_n),
    .reg_addr(csr_addr), .reg_wdata(csr_wdata),
    .reg_wr_en(csr_wr_en), .reg_rd_en(csr_rd_en),
    .reg_rdata(csr_rdata), .reg_ready(csr_ready),
    .ctrl_start(ctrl_start), .ctrl_stop(ctrl_stop), .ctrl_sw_reset(ctrl_sw_reset),
    .cfg_lif_enable(cfg_lif_enable), .cfg_auto_repeat(cfg_auto_repeat),
    .cfg_num_timesteps(cfg_num_timesteps),
    .cfg_lif_threshold(cfg_lif_threshold), .cfg_lif_leak(cfg_lif_leak),
    .cfg_lif_reset(cfg_lif_reset), .cfg_lif_refractory(cfg_lif_refractory),
    .ppu_ready(ppu_ready), .ppu_busy(ppu_busy),
    .sim_done(sim_done), .sim_active(sim_active),
    .timestep_idx(timestep_idx_internal),
    .spike_count(collect_spike_count),
    .tile_done(tile_done),
    .irq(irq)
  );

  // ===================================================================
  // Weight Memory Controller Instance
  // ===================================================================
  weight_mem_ctrl #(
    .PE_COUNT(PE_COUNT), .SPIKES(SPIKES), .WEIGHT_WIDTH(WEIGHT_WIDTH),
    .ADDR_WIDTH(32), .DATA_WIDTH(32), .BURST_LEN(16)
  ) u_weight_ctrl (
    .clk(clk), .rst_n(rst_n),
    .load_start(weight_load_start), .base_addr(weight_base_addr),
    .load_done(weight_load_done_i), .load_busy(weight_load_busy_i),
    .mem_araddr(m_axi_araddr), .mem_arlen(m_axi_arlen),
    .mem_arsize(m_axi_arsize), .mem_arburst(m_axi_arburst),
    .mem_arvalid(m_axi_arvalid), .mem_arready(m_axi_arready),
    .mem_rdata(m_axi_rdata), .mem_rresp(m_axi_rresp),
    .mem_rlast(m_axi_rlast), .mem_rvalid(m_axi_rvalid), .mem_rready(m_axi_rready),
    .weight_addr(weight_wr_addr), .weight_data(weight_wr_data),
    .weight_wr_en(weight_wr_en), .weights_loaded()
  );
  
  // ===================================================================
  // Phase 1 Integration: Timestep Control and Spike I/O
  // ===================================================================
  
  // Timestep controller signals
  wire timestep_tile_start;
  wire timestep_tile_done;
  wire [TIMESTEP_WIDTH-1:0] timestep_idx_internal;
  wire timestep_end_internal;
  
  // Spike injector signals
  wire inject_done;
  wire inject_tcam_set_en;
  wire [$clog2(ROWS)-1:0] inject_tcam_set_addr;
  wire [SPIKES-1:0] inject_tcam_set_key;
  
  // Spike collector signals
  wire [PE_COUNT-1:0] collect_rd_data;
  wire [$clog2(MAX_TIMESTEPS*ROWS):0] collect_spike_count;
  
  // Internal tile_done signal
  wire tile_done;
  
  // Control FSM states
  localparam ST_IDLE      = 3'd0;
  localparam ST_LOAD      = 3'd1;
  localparam ST_INIT      = 3'd2;
  localparam ST_PROCESS   = 3'd3;
  localparam ST_DONE      = 3'd4;
  localparam ST_INJECT    = 3'd5;  // Wait for spike injection to complete
  
  reg [2:0] state, next_state;
  reg [$clog2(ROWS)-1:0] row_counter;
  reg processing_done;
  
  // ===================================================================
  // Memory Interface
  // ===================================================================
  
  // Tile memory write from spike injector only (no direct host access)
  always @(posedge clk) begin
    if (inject_tcam_set_en) begin
      tile_ram[inject_tcam_set_addr] <= inject_tcam_set_key;
      popcount_ram[inject_tcam_set_addr] <= $countones(inject_tcam_set_key);
    end
  end
  
  // ===================================================================
  // Control FSM
  // ===================================================================
  
  always @(posedge clk) begin
    if (!rst_n || ctrl_sw_reset) begin
      state <= ST_IDLE;
      row_counter <= 0;
      processing_done <= 0;
    end else begin
      state <= next_state;
      
      case (state)
        ST_LOAD: begin
          if (row_counter < ROWS - 1) begin
            row_counter <= row_counter + 1;
          end
        end

        // Reset counter when entering INIT state so processing starts at row 0
        ST_INIT: begin
          row_counter <= 0;
        end

        // During PROCESS state iterate through all rows once
        ST_PROCESS: begin
          if (row_done && row_counter < ROWS - 1) begin
            row_counter <= row_counter + 1;
          end
        end
        
        default: row_counter <= 0;
      endcase
      
      processing_done <= (row_counter == ROWS - 1) & row_done;
    end
  end
  
  always @(*) begin
    next_state = state;
    
    case (state)
      ST_IDLE: begin
        if (tile_start_internal && ppu_ready) begin
          // When sim_active, spike_injector loads TCAM, wait for inject_done
          next_state = sim_active ? ST_INJECT : ST_LOAD;
        end
      end
      
      ST_INJECT: begin
        // Wait for spike injector to finish loading TCAM
        if (inject_done) begin
          next_state = ST_INIT;
        end
      end
      
      ST_LOAD: begin
        if (row_counter == ROWS - 1) begin
          next_state = ST_INIT;
        end
      end
      
      ST_INIT: begin
        if (detector_init_done) begin
          next_state = ST_PROCESS;
        end
      end
      
      ST_PROCESS: begin
        if (processing_done) begin
          next_state = cfg_auto_repeat ? ST_LOAD : ST_DONE;
        end
      end
      
      ST_DONE: begin
        next_state = ST_IDLE;
      end
      
      default: next_state = ST_IDLE;
    endcase
  end
  
  // Status outputs
  assign ppu_ready = (state == ST_IDLE) || (state == ST_DONE);
  assign ppu_busy = (state != ST_IDLE) && (state != ST_DONE);
  
  // Tile start comes from timestep controller (triggered by CSR ctrl_start)
  wire tile_start_internal = timestep_tile_start;
  
  // Debug outputs
  assign dbg_state = {1'b0, state};
  

  // ===================================================================
  // Detector Interface
  // ===================================================================
  wire det_q_ready;
  wire [ROWS-1:0] det_si_vec;
  wire det_si_valid;
  wire det_done_flag;
  wire [NO_WIDTH-1:0] det_row_pc;
  wire detector_init_done;
  
  // Detector instance
  detector #(
    .SPIKES(SPIKES),
    .ROWS(ROWS),
    .NO_WIDTH(NO_WIDTH)
  ) u_detector (
    .clk(clk),
    .rst(!rst_n),
    
    // Query interface
    .query_pattern(tile_ram[row_counter]),
    .q_valid(state == ST_PROCESS && !processing_done && ready_for_new_row),
    .q_ready(det_q_ready),
    
    // Result interface
    .si_vec(det_si_vec),
    .si_valid(det_si_valid),
    .det_done(det_done_flag),
    .row_idx(row_counter),
    .row_popcnt(det_row_pc),
    .detector_init_done(detector_init_done),
    
    // Memory interface - from spike injector only
    .tile_mem_addr(inject_tcam_set_addr),
    .tile_mem_data_in(inject_tcam_set_key),
    .tile_mem_wr_en(inject_tcam_set_en),
    .popcount_mem_addr(inject_tcam_set_addr),
    .popcount_mem_data_in($countones(inject_tcam_set_key)),
    .popcount_mem_wr_en(inject_tcam_set_en)
  );

  // ===================================================================
  // Timestep Controller Instance
  // ===================================================================
  timestep_ctrl #(
    .TIMESTEP_WIDTH(TIMESTEP_WIDTH)
  ) u_timestep_ctrl (
    .clk(clk),
    .rst_n(rst_n),
    
    // Configuration from CSR
    .num_timesteps(cfg_num_timesteps),
    
    // Control from CSR
    .start(ctrl_start),
    .tile_done(timestep_tile_done),
    
    // Status outputs
    .timestep_idx(timestep_idx_internal),
    .tile_start(timestep_tile_start),
    .timestep_end(timestep_end_internal),
    .sim_active(sim_active),
    .sim_done(sim_done)
  );
  
  // Connect tile_done from dispatcher when simulation active
  // Use the full tile completion (when top FSM reaches ST_DONE) for multi-timestep mode
  // This ensures both spike injection AND processing complete before next timestep
  assign timestep_tile_done = sim_active ? (state == ST_DONE) : 1'b0;

  // ===================================================================
  // Spike Injector Instance
  // ===================================================================
  spike_injector #(
    .ROWS(ROWS),
    .SPIKES(SPIKES),
    .TIMESTEP_WIDTH(TIMESTEP_WIDTH),
    .MAX_TIMESTEPS(MAX_TIMESTEPS)
  ) u_spike_injector (
    .clk(clk),
    .rst_n(rst_n),
    
    // Control interface
    .tile_start(timestep_tile_start),
    .timestep_idx(timestep_idx_internal),
    .inject_done(inject_done),
    
    // Host configuration interface - from AXI bridge
    .host_wr_en(spike_inject_wr_en),
    .host_wr_addr(spike_inject_wr_addr),
    .host_wr_data(spike_inject_wr_data),
    
    // TCAM interface (output to detector)
    .tcam_set_en(inject_tcam_set_en),
    .tcam_set_addr(inject_tcam_set_addr),
    .tcam_set_key(inject_tcam_set_key)
  );

  // ===================================================================
  // Pruner Interface
  // ===================================================================
  wire prn_ready;
  wire prn_valid;
  wire [NO_WIDTH-1:0] prn_popcnt;
  // Row complete when detector produces result and pruner idle to accept
  wire row_done = det_si_valid & prn_ready;
  // Ready to launch new query when both detector ready and pruner idle
  wire ready_for_new_row = det_q_ready & prn_ready;
  wire prune_done;
  wire [SPIKES-1:0] prn_pattern;
  wire [$clog2(ROWS)-1:0] prn_row_id;
  wire [$clog2(ROWS)-1:0] prn_prefix_id;
  
  // Pruner instance
  pruner #(
    .N(ROWS),
    .M(SPIKES),
    .NO_WIDTH(NO_WIDTH)
    // NULL prefix now encoded as prefix_id == row_id (self-reference)
  ) u_pruner (
    .clk(clk),
    .rst_n(rst_n),
    
    // Input from detector
    .si_vector(det_si_vec),
    .row_index(row_counter),
    .row_NO(det_row_pc),
    .si_valid(det_si_valid),
    .pruner_ready(prn_ready),
    
    // Output to dispatcher
    .prefix_id(prn_prefix_id),
    .row_id_out(prn_row_id),
    .pattern(prn_pattern),
    .prune_valid(prn_valid),
    .prune_done(prune_done),
    .mem_NO_out(prn_popcnt),
    .mem_spike_out(/* unused */),
    .dispatch_ready(dsp_ready),
    
    // Memory interface - driven by spike injector
    .mem_addr(inject_tcam_set_addr),
    .mem_NO_in($countones(inject_tcam_set_key)),
    .mem_spike_in(inject_tcam_set_key),
    .mem_wr_en(inject_tcam_set_en),
    .mem_sel(1'b1)
  );

  // ===================================================================
  // Dispatcher Interface
  // ===================================================================
  wire dsp_ready;
  wire dsp_tile_done;
  
  // Pipeline registers for timing
  reg [SPIKES-1:0] pattern_r;
  reg [$clog2(ROWS)-1:0] row_idx_r, prefix_id_r;
  reg [NO_WIDTH-1:0] row_popcnt_r;
  reg prn_valid_r;
  
  // Best prefix selection logic
  reg [$clog2(ROWS)-1:0] best_prefix;
  reg [SPIKES-1:0] best_prefix_pattern;
  reg [SPIKES-1:0] output_pattern;
  reg [NO_WIDTH-1:0] output_popcount;
  reg [ROWS-1:0] valid_mask;
  
  // Simple priority encoder to find best prefix (combinational)
  integer k;
  always @(*) begin
    best_prefix = row_counter;  // Default to current row
    best_prefix_pattern = tile_ram[row_counter];
    valid_mask = det_si_vec;   // Valid mask from detector
    
    // Find highest popcount, lowest index
    for (k = 0; k < ROWS; k = k + 1) begin
      if (valid_mask[k] && k != row_counter) begin
        if (best_prefix == row_counter ||
            popcount_ram[k] > popcount_ram[best_prefix] ||
            (popcount_ram[k] == popcount_ram[best_prefix] && k < best_prefix)) begin
          best_prefix = k;
          best_prefix_pattern = tile_ram[k];
        end
      end
    end

    // Compute output pattern (XOR)
    output_pattern = tile_ram[row_counter] ^ best_prefix_pattern;
    output_popcount = popcnt16(output_pattern);
  end
  
  // Pipeline registers update
  always @(posedge clk) begin
    if (!rst_n) begin
      prn_valid_r <= 0;
      row_idx_r <= 0;
      prefix_id_r <= 0;
      pattern_r <= 0;
      row_popcnt_r <= 0;
    end else if (det_si_valid && dsp_ready) begin
      prn_valid_r <= 1;
      row_idx_r <= row_counter;
      prefix_id_r <= best_prefix;
      pattern_r <= output_pattern;
      row_popcnt_r <= output_popcount;
    end else begin
      prn_valid_r <= 0;
    end
  end
  
  // ===================================================================
  // Dispatcher Interface
  // ===================================================================
  // Only one declaration of dsp_ready and dsp_tile_done
  
  // Dispatcher instance
  dispatcher #(
    .ROWS(ROWS),
    .SPIKES(SPIKES),
    .NO_WIDTH(NO_WIDTH)
  ) u_dispatcher (
    .clk(clk),
    .rst_n(rst_n),
    // From Pruner
    .row_info_valid(prn_valid),
    .row_info_ready(dsp_ready),
    .row_idx(prn_row_id),
    .row_prefix_id(prn_prefix_id),
    .row_pattern(prn_pattern),
    .row_popcnt(prn_popcnt),
    .row_last(prn_row_id == ROWS - 1),
    // To Processor
    .proc_ready(proc_ready),
    .task_valid(task_valid_i),
    .task_row_id(task_row_id_i),
    .task_prefix_id(task_prefix_id_i),
    .task_pattern(task_pattern_i),
    // Control
    .prev_compute_busy(1'b0),
    .pruner_done(prune_done),
    .tile_done(dsp_tile_done)
  );
  
  // Internal task signals
  wire task_valid_i;
  wire [$clog2(ROWS)-1:0] task_row_id_i;
  wire [$clog2(ROWS)-1:0] task_prefix_id_i;
  wire [SPIKES-1:0] task_pattern_i;
  
  // ===================================================================
  // Processor Interface (128 PEs with Integrated LIF Neurons)
  // ===================================================================
  wire proc_ready;
  wire proc_busy;
  wire proc_done;
  wire [PE_COUNT-1:0] proc_spike_out;
  wire proc_spike_valid;
  wire [$clog2(ROWS)-1:0] output_rd_addr_i;
  wire [$clog2(ROWS)-1:0] output_wr_addr_i;
  wire [PE_COUNT*ACC_WIDTH-1:0] output_wr_data_i;
  wire output_wr_en_i;
  
  // Processor instance
  processor #(
    .ROWS(ROWS),
    .SPIKES(SPIKES),
    .PE_COUNT(PE_COUNT),
    .WEIGHT_WIDTH(WEIGHT_WIDTH),
    .ACC_WIDTH(ACC_WIDTH),
    .NO_WIDTH(NO_WIDTH),
    .VMEM_WIDTH(VMEM_WIDTH),
    .THRESH_WIDTH(THRESH_WIDTH),
    .LEAK_WIDTH(LEAK_WIDTH),
    .REFRAC_WIDTH(REFRAC_WIDTH)
  ) u_processor (
    .clk(clk),
    .rst_n(rst_n),
    
    // Task Interface from Dispatcher
    .task_valid(task_valid_i),
    .task_ready(proc_ready),
    .task_row_id(task_row_id_i),
    .task_prefix_id(task_prefix_id_i),
    .task_pattern(task_pattern_i),
    
    // Weight Memory Interface - use internal DMA-loaded buffer
    .weight_addr(weight_rd_addr),
    .weight_data(weight_rd_data),
    .weight_rd_en(),
    
    // Output Buffer Interface
    .output_rd_addr(output_rd_addr_i),
    .output_wr_addr(output_wr_addr_i),
    .output_rd_data({PE_COUNT*ACC_WIDTH{1'b0}}),
    .output_wr_data(output_wr_data_i),
    .output_wr_en(output_wr_en_i),

    // LIF Neuron Configuration - from CSR
    .cfg_threshold(cfg_lif_threshold),
    .cfg_leak(cfg_lif_leak),
    .cfg_reset_potential(cfg_lif_reset),
    .cfg_refractory(cfg_lif_refractory),

    // LIF Control - from CSR
    .lif_enable(cfg_lif_enable),
    .timestep_end(timestep_end_internal),

    // Spike Output
    .spike_out(proc_spike_out),
    .spike_valid(proc_spike_valid),

    // Debug: Membrane readback
    .vmem_rd_idx(7'd0),
    .vmem_rd_data(),
    
    // Status
    .proc_busy(proc_busy),
    .proc_done(proc_done)
  );

  // ===================================================================
  // Spike Collector Instance
  // ===================================================================
  spike_collector #(
    .ROWS(ROWS),
    .PE_COUNT(PE_COUNT),
    .TIMESTEP_WIDTH(TIMESTEP_WIDTH),
    .MAX_TIMESTEPS(MAX_TIMESTEPS)
  ) u_spike_collector (
    .clk(clk),
    .rst_n(rst_n),
    
    // Spike input interface (from processor)
    .spike_in(proc_spike_out),
    .spike_valid(proc_spike_valid),
    .spike_row_id(output_wr_addr_i),
    .timestep_idx(timestep_idx_internal),
    
    // Control
    .collect_enable(1'b1),
    .clear_buffer(ctrl_sw_reset),
    
    // Host read interface - from AXI bridge
    .host_rd_en(spike_collect_rd_en),
    .host_rd_addr(spike_collect_rd_addr),
    .host_rd_data(collect_rd_data),
    
    // Statistics
    .spike_count(collect_spike_count)
  );
  
  // Export spike collector outputs
  assign spike_collect_rd_data = collect_rd_data;
  
  // tile_done from dispatcher
  assign tile_done = dsp_tile_done;

  // ===================================================================
  // Helper Functions
  // ===================================================================
  
  // Count number of set bits in a 16-bit vector
  function [NO_WIDTH-1:0] popcnt16;
    input [15:0] vec;
    integer i;
    begin
      popcnt16 = 0;
      for (i = 0; i < 16; i = i + 1) begin
        popcnt16 = popcnt16 + vec[i];
      end
    end
  endfunction

endmodule
