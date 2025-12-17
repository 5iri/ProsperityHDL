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
    parameter WEIGHT_WIDTH = 8,       // Weight precision
    parameter ACC_WIDTH    = 16,      // Accumulator width
    // LIF Neuron Parameters
    parameter VMEM_WIDTH    = 16,     // Membrane potential width
    parameter THRESH_WIDTH  = 16,     // Threshold width
    parameter LEAK_WIDTH    = 8,      // Leak value width
    parameter REFRAC_WIDTH  = 4       // Refractory counter width
) (
    // Clock and Reset
    input  wire clk,
    input  wire rst_n,

    // Configuration and Control
    input  wire              cfg_enable,       // Enable PPU operation
    input  wire              cfg_auto_repeat,  // Auto-repeat tile processing
    output wire              ppu_ready,        // PPU ready for new configuration
    output wire              ppu_busy,         // PPU is processing
    
    // Tile Control
    input  wire              tile_start,       // Start processing tile
    output wire              tile_done,        // Tile processing complete
    
    // Memory Interface - Tile Data
    input  wire [$clog2(ROWS)-1:0] tile_mem_addr,
    input  wire [SPIKES-1:0]       tile_mem_data_in,
    output reg [SPIKES-1:0]       tile_mem_data_out,
    input  wire                    tile_mem_wr_en,
    
    // Memory Interface - Popcounts
    input  wire [$clog2(ROWS)-1:0] pc_mem_addr,
    input  wire [NO_WIDTH-1:0]     pc_mem_data_in,
    output reg [NO_WIDTH-1:0]     pc_mem_data_out,
    input  wire                    pc_mem_wr_en,
    
    // Task Interface to Compute Core (internal connection to processor)
    output wire                    task_valid,    // Valid task data
    output wire [$clog2(ROWS)-1:0] task_row_id,   // Current row ID
    output wire [$clog2(ROWS)-1:0] task_prefix_id, // Prefix row ID
    output wire [SPIKES-1:0]       task_pattern,   // Spike pattern
    
    // Weight Memory Interface (for 128 PEs)
    output wire [$clog2(SPIKES*PE_COUNT)-1:0] weight_addr,
    input  wire [WEIGHT_WIDTH-1:0] weight_data,
    output wire                      weight_rd_en,
    
    // Output Buffer Interface
    output wire [$clog2(ROWS)-1:0]   output_rd_addr,
    output wire [$clog2(ROWS)-1:0]   output_wr_addr,
    input  wire [PE_COUNT*ACC_WIDTH-1:0] output_rd_data,
    output wire [PE_COUNT*ACC_WIDTH-1:0] output_wr_data,
    output wire                       output_wr_en,

    // ─────────────────── LIF Neuron Configuration ───────────────────
    input  wire [THRESH_WIDTH-1:0]  cfg_lif_threshold,     // Firing threshold
    input  wire [LEAK_WIDTH-1:0]    cfg_lif_leak,          // Leak per timestep
    input  wire [VMEM_WIDTH-1:0]    cfg_lif_reset,         // Reset potential after spike
    input  wire [REFRAC_WIDTH-1:0]  cfg_lif_refractory,    // Refractory period
    input  wire                     cfg_lif_enable,        // Enable LIF neuron updates
    input  wire                     timestep_end,          // Signal end of timestep

    // ─────────────────── Spike Output Interface ─────────────────────
    output wire [PE_COUNT-1:0]      spike_out,             // Output spike vector from processor
    output wire                     spike_valid,           // Spike output valid
    output wire [$clog2(ROWS)-1:0]  spike_row_id,          // Row ID for current spikes

    // Spike Buffer Interface
    input  wire [$clog2(ROWS)-1:0]  spike_buf_rd_addr,     // Read address for spike buffer
    output wire [PE_COUNT-1:0]      spike_buf_rd_data,     // Spike data at read address

    // Debug: Membrane potential readback
    input  wire [$clog2(PE_COUNT)-1:0] vmem_rd_idx,
    output wire [VMEM_WIDTH-1:0]       vmem_rd_data,
    
    // Debug Signals
    output wire [3:0]              dbg_state,      // Debug: FSM state
    output wire                    dbg_det_ready,  // Debug: Detector ready
    output wire                    dbg_prn_ready,  // Debug: Pruner ready
    output wire                    dbg_dsp_ready,  // Debug: Dispatcher ready
  output wire                    dbg_proc_busy,  // Debug: Processor busy
  output wire                    core_ready      // Core ready signal for testbench
);

  // ===================================================================
  // Internal Signals and Registers
  // ===================================================================
  
  // Tile memory (dual-port)
  reg [SPIKES-1:0] tile_ram [0:ROWS-1];
  reg [NO_WIDTH-1:0] popcount_ram [0:ROWS-1];
  
  // Control FSM states
  localparam ST_IDLE      = 3'd0;
  localparam ST_LOAD      = 3'd1;
  localparam ST_INIT      = 3'd2;
  localparam ST_PROCESS   = 3'd3;
  localparam ST_DONE      = 3'd4;
  
  reg [2:0] state, next_state;
  reg [$clog2(ROWS)-1:0] row_counter;
  reg processing_done;
  
  // ===================================================================
  // Memory Interface
  // ===================================================================
  
  // Tile memory read/write
  always @(posedge clk) begin
    if (tile_mem_wr_en) begin
      tile_ram[tile_mem_addr] <= tile_mem_data_in;
      // Automatically calculate and store popcount
      popcount_ram[tile_mem_addr] <= $countones(tile_mem_data_in);
    end
    tile_mem_data_out <= tile_ram[tile_mem_addr];
    
    if (pc_mem_wr_en) begin
      popcount_ram[pc_mem_addr] <= pc_mem_data_in;
    end
    pc_mem_data_out <= popcount_ram[pc_mem_addr];
  end
  
  // ===================================================================
  // Control FSM
  // ===================================================================
  
  always @(posedge clk) begin
    if (!rst_n) begin
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
        if (tile_start && ppu_ready) begin
          next_state = ST_LOAD;
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
  
  // Debug outputs
  assign dbg_state = state;
  assign dbg_det_ready = det_q_ready;
  assign dbg_prn_ready = prn_ready;
  assign dbg_dsp_ready = dsp_ready;
  

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
    
    // Memory interface
    .tile_mem_addr(tile_mem_addr),
    .tile_mem_data_in(tile_mem_data_in),
    .tile_mem_wr_en(tile_mem_wr_en),
    .popcount_mem_addr(tile_mem_wr_en ? tile_mem_addr : pc_mem_addr),
    .popcount_mem_data_in(tile_mem_wr_en ? $countones(tile_mem_data_in) : pc_mem_data_in),
    .popcount_mem_wr_en(tile_mem_wr_en | pc_mem_wr_en)
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
    .NO_WIDTH(NO_WIDTH),
    .NULL_ID(8'd255)  // Use 255 as NULL prefix ID for roots
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
    
    // Memory interface – multiplex spike vs NO writes
    .mem_addr(pc_mem_wr_en ? pc_mem_addr : tile_mem_addr),
    .mem_NO_in(pc_mem_wr_en ? pc_mem_data_in : $countones(tile_mem_data_in)),
    .mem_spike_in(tile_mem_data_in),
    .mem_wr_en(tile_mem_wr_en | pc_mem_wr_en),
    .mem_sel(tile_mem_wr_en ? 1'b1 : 1'b0)  // Use 1 only while writing spikes
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
    .proc_ready(core_ready),
    .task_valid(task_valid),
    .task_row_id(task_row_id),
    .task_prefix_id(task_prefix_id),
    .task_pattern(task_pattern),
    // Control
    .prev_compute_busy(1'b0),
    .pruner_done(prune_done),
    .tile_done(dsp_tile_done)
  );
  // Only one dispatcher instance above. Any other instance below this comment will be removed.
  
  // ===================================================================
  // Processor Interface (128 PEs with Integrated LIF Neurons)
  // ===================================================================
  wire proc_ready;
  wire proc_busy;
  wire proc_done;
  wire [PE_COUNT-1:0] proc_spike_out;
  wire proc_spike_valid;
  
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
    .task_valid(task_valid),
    .task_ready(proc_ready),
    .task_row_id(task_row_id),
    .task_prefix_id(task_prefix_id),
    .task_pattern(task_pattern),
    
    // Weight Memory Interface
    .weight_addr(weight_addr),
    .weight_data(weight_data),
    .weight_rd_en(weight_rd_en),
    
    // Output Buffer Interface
    .output_rd_addr(output_rd_addr),
    .output_wr_addr(output_wr_addr),
    .output_rd_data(output_rd_data),
    .output_wr_data(output_wr_data),
    .output_wr_en(output_wr_en),

    // LIF Neuron Configuration
    .cfg_threshold(cfg_lif_threshold),
    .cfg_leak(cfg_lif_leak),
    .cfg_reset_potential(cfg_lif_reset),
    .cfg_refractory(cfg_lif_refractory),

    // LIF Control
    .lif_enable(cfg_lif_enable),
    .timestep_end(timestep_end),

    // Spike Output
    .spike_out(proc_spike_out),
    .spike_valid(proc_spike_valid),

    // Debug: Membrane readback
    .vmem_rd_idx(vmem_rd_idx),
    .vmem_rd_data(vmem_rd_data),
    
    // Status
    .proc_busy(proc_busy),
    .proc_done(proc_done)
  );
  
  // Connect processor ready signal to dispatcher
  assign core_ready = proc_ready;

  // ===================================================================
  // Spike Buffer - Store spikes per row for next layer / host readback
  // ===================================================================
  reg [PE_COUNT-1:0] spike_buffer [0:ROWS-1];
  reg [$clog2(ROWS)-1:0] spike_row_id_r;

  // Write spikes to buffer when processor outputs valid spikes
  always @(posedge clk) begin
    if (!rst_n) begin
      spike_row_id_r <= 0;
    end else if (proc_spike_valid && output_wr_en) begin
      spike_buffer[output_wr_addr] <= proc_spike_out;
      spike_row_id_r <= output_wr_addr;
    end
  end

  // Spike output signals
  assign spike_out = proc_spike_out;
  assign spike_valid = proc_spike_valid;
  assign spike_row_id = spike_row_id_r;
  assign spike_buf_rd_data = spike_buffer[spike_buf_rd_addr];
  
  // Status outputs
  assign tile_done = dsp_tile_done;
  assign ppu_ready = (state == ST_IDLE) || (state == ST_DONE);

  // Debug outputs
  assign dbg_state = state;
  assign dbg_det_ready = det_q_ready;
  assign dbg_prn_ready = prn_ready;
  assign dbg_dsp_ready = dsp_ready;
  assign dbg_proc_busy = proc_busy;

  // ─────────────────── Single-port RAM interface for tile_data ---------
  always @(posedge clk) begin
    if (tile_mem_wr_en) begin
      tile_ram[tile_mem_addr] <= tile_mem_data_in;
    end
  end
  
  // Popcount memory
  always @(posedge clk) begin
    if (pc_mem_wr_en) begin
      popcount_ram[pc_mem_addr] <= pc_mem_data_in;
    end
  end

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
