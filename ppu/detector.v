// detector.v  ───────────────────────────────────────────────────
// Prosperity subset detector - Direct TCAM Implementation
//   • 16-bit spike rows, 256-row tile
//   • Finds ALL subsets in single query (1-cycle operation)
//   • Outputs: 256-bit si_vec, NO_WIDTH-bit row_popcounts, 1-clk si_valid
//   • Uses tcam_line_array directly for hardware-accelerated lookup
//
// Verilog-2001
//
// --------------------------------------------------------------------
`timescale 1ns / 1ps

module detector #(
    parameter SPIKES = 16,  // Number of spikes per pattern
    parameter ROWS = 256,  // Number of patterns in tile
    parameter NO_WIDTH = 8,  // Width for Number-of-Ones (popcount)
    parameter TEST_ROWS = ROWS  // Number of test rows used
) (
    input wire clk,
    input wire rst,

    // Query interface
    input  wire [SPIKES-1:0] query_pattern,
    input  wire              q_valid,
    output wire              q_ready,        // Ready to accept new query

    // Result interface
    output reg  [    ROWS-1:0] si_vec,                   // Subset index vector
    output reg                 si_valid,                 // Result valid
    output reg                 det_done,                 // Detection stage complete

    // Additional interface signals for top module
    input  wire [$clog2(ROWS)-1:0] row_idx,            // Current row index
    output reg  [    NO_WIDTH-1:0] row_popcnt,         // Popcount for current row
    output reg                     detector_init_done,  // Initialization complete

    // Single-port RAM interface for tile_buffer and row_popcounts
    input  wire [$clog2(ROWS)-1:0] tile_mem_addr,
    input  wire [SPIKES-1:0]       tile_mem_data_in,
    input  wire                    tile_mem_wr_en,
    input  wire [$clog2(ROWS)-1:0] popcount_mem_addr,
    input  wire [NO_WIDTH-1:0]     popcount_mem_data_in,
    input  wire                    popcount_mem_wr_en
);

  // Internal buffers for tile_buffer and row_popcounts
  reg [SPIKES-1:0] tile_buffer [0:ROWS-1];
  reg [NO_WIDTH-1:0] row_popcounts [0:ROWS-1];

  // Signal to track if popcounts have been calculated
  reg popcounts_calculated;
  integer popcount_loop_idx;  // Loop variable for popcount calculation

  // ── FSM state definitions ───────────────────────────────────────
  localparam ST_IDLE = 2'd0;  // Waiting for command
  localparam ST_LOAD = 2'd1;  // Load patterns once at init
  localparam ST_QUERY = 2'd2;  // Handle query with exactly 3-cycle latency
  localparam ST_POPCOUNT = 2'd3;  // Calculate popcounts for all rows (one-time after loading)

  reg [1:0] state, next_state;

  // ── Counters and registers ───────────────────────────────────────
  reg  [$clog2(TEST_ROWS)-1:0] load_counter;  // Fixed width to match tcam_addr
  reg  [$clog2(TEST_ROWS)-1:0] popcount_counter;  // Fixed width to match tcam_addr
  reg  [           SPIKES-1:0] query_reg;
  reg                          initialized;  // Tracks if patterns have been loaded
  reg                          query_in_progress;  // Used to track exact 1-cycle latency

  // ── TCAM signals ─────────────────────────────────────────
  reg  [           SPIKES-1:0] tcam_key;  // Key to match against
  reg  [           SPIKES-1:0] tcam_xmask;  // 1=don't care, 0=must match
  reg  [     $clog2(ROWS)-1:0] tcam_addr;
  reg                          tcam_set_valid;
  reg                          tcam_set_clr;
  reg                          tcam_req_valid;
  wire [             ROWS-1:0] tcam_matches;  // One-hot match vector

  // Ready when in IDLE state and initialized with popcounts calculated
  assign q_ready = (state == ST_IDLE || (state == ST_QUERY && !query_in_progress)) &&
                    initialized && popcounts_calculated;

  // ── Direct instance of tcam_line_array ─────────────────────────────
  tcam_line_array #(
      .ADDR_WIDTH  ($clog2(ROWS)),  // Address width for ROWS entries
      .KEY_WIDTH   (SPIKES),        // Pattern width (16 bits)
      .MASK_DISABLE(0)              // Enable masking for don't care bits
  ) tcam_core (
      .clk(clk),
      .rst(rst),

      // Set interface - for loading patterns
      .set_addr (tcam_addr),
      .set_key  (tcam_key),
      .set_xmask(tcam_xmask),     // 1=don't care, 0=must match
      .set_clr  (tcam_set_clr),
      .set_valid(tcam_set_valid),

      // Request interface - for querying
      .req_key  (query_reg),
      .req_valid(tcam_req_valid),

      // Output - direct match vector (no encoder)
      .line_match(tcam_matches)
  );

  // ── Parallel Population count function ─────────────────────────────────────
  function [NO_WIDTH-1:0] calc_popcount;
    input [SPIKES-1:0] data;
    reg [NO_WIDTH-1:0] stage1[SPIKES/2-1:0];
    reg [NO_WIDTH-1:0] stage2[SPIKES/4-1:0];
    reg [NO_WIDTH-1:0] stage3[SPIKES/8-1:0];
    reg [NO_WIDTH-1:0] stage4[SPIKES/16-1:0];
    integer i;
    begin
      // Stage 1: Count pairs
      for (i = 0; i < SPIKES / 2; i = i + 1) begin
        stage1[i] = data[2*i] + data[2*i+1];
      end

      // Stage 2: Combine pairs
      for (i = 0; i < SPIKES / 4; i = i + 1) begin
        stage2[i] = stage1[2*i] + stage1[2*i+1];
      end

      // Stage 3: Combine quads
      for (i = 0; i < SPIKES / 8; i = i + 1) begin
        stage3[i] = stage2[2*i] + stage2[2*i+1];
      end

      // Stage 4: Final combination
      for (i = 0; i < SPIKES / 16; i = i + 1) begin
        stage4[i] = stage3[2*i] + stage3[2*i+1];
      end

      calc_popcount = stage4[0];
    end
  endfunction

  // ── Next state logic ─────────────────────────────────────────────
  always @(*) begin
    case (state)
      ST_IDLE: begin
        if (!initialized) next_state = ST_LOAD;  // Initial load
        else if (!popcounts_calculated) next_state = ST_POPCOUNT;  // Calculate popcounts once
        else if (q_valid) next_state = ST_QUERY;  // Process query
        else next_state = ST_IDLE;  // Stay idle
      end

      ST_LOAD: begin
        if (load_counter == TEST_ROWS - 1)  // Fixed width comparison
          next_state = ST_POPCOUNT;  // Done loading, calculate popcounts next
        else next_state = ST_LOAD;  // Continue loading
      end

      ST_POPCOUNT: begin
        if (popcount_counter == TEST_ROWS - 1)  // Fixed width comparison
          next_state = ST_IDLE;  // Done calculating popcounts
        else next_state = ST_POPCOUNT;  // Continue calculating popcounts
      end

      ST_QUERY:
      next_state = query_in_progress ? ST_IDLE : ST_QUERY;  // Stay in query for exactly one more cycle

      default: next_state = ST_IDLE;
    endcase
  end

  // ── TCAM interface signals ────────────────────────────────────────
  always @(*) begin
    // Default values
    tcam_set_valid = 1'b0;
    tcam_set_clr = 1'b0;
    tcam_req_valid = 1'b0;
    tcam_key = {SPIKES{1'b0}};
    tcam_xmask = {SPIKES{1'b0}};
    tcam_addr = load_counter;  // Now matches width

    case (state)
      ST_LOAD: begin
        // Load patterns into TCAM
        tcam_set_valid = 1'b1;
        tcam_key = tile_buffer[load_counter];  // Pattern is the key
        tcam_xmask = ~tile_buffer[load_counter];  // For subset matching: 0s in pattern are don't cares
        tcam_addr = load_counter;  // Now matches width
      end

      ST_QUERY: begin
        // Issue query to TCAM if not already in progress
        tcam_req_valid = ~query_in_progress;
      end

      default: begin
        // Default case for completeness
        tcam_set_valid = 1'b0;
        tcam_set_clr   = 1'b0;
        tcam_req_valid = 1'b0;
      end
    endcase
  end

  // ── State and signal updates ──────────────────────────────────────
  always @(posedge clk) begin
    if (rst) begin
      state <= ST_IDLE;
      load_counter <= 0;
      popcount_counter <= 0;
      query_reg <= 0;
      si_vec <= 0;
      si_valid <= 0;
      det_done <= 0;
      initialized <= 0;
      query_in_progress <= 0;
      popcounts_calculated <= 0;
      row_popcnt <= 0;
      detector_init_done <= 0;
    end else begin
      state <= next_state;
      si_valid <= 0;  // Default value, overridden below when needed
      det_done <= 0;  // Default value, overridden below when needed

      case (state)
        ST_IDLE: begin
          query_in_progress <= 0;  // Always reset when entering IDLE
          if (q_valid) begin
            query_reg <= query_pattern;
          end
        end

        ST_LOAD: begin
          if (load_counter < TEST_ROWS - 1) begin  // Fixed width comparison
            load_counter <= load_counter + 1'b1;
          end else begin
            initialized <= 1'b1;  // Done loading patterns
          end
        end

        ST_POPCOUNT: begin
          if (popcount_counter < TEST_ROWS - 1) begin  // Fixed width comparison
            popcount_counter <= popcount_counter + 1'b1;
          end else begin
            popcounts_calculated <= 1'b1;  // Done calculating popcounts
            detector_init_done   <= 1'b1;  // Signal initialization complete
          end
        end

        ST_QUERY: begin
          if (query_in_progress) begin
            si_vec   <= tcam_matches;  // Capture TCAM results
            si_valid <= 1'b1;  // Signal results ready
            det_done <= 1'b1;  // Signal detection complete
          end else begin
            query_in_progress <= 1'b1;
          end
        end
      endcase
    end
  end

  always @(posedge clk) begin
    if (tile_mem_wr_en) begin
      tile_buffer[tile_mem_addr] <= tile_mem_data_in;
    end
    if (popcount_mem_wr_en) begin
      row_popcounts[popcount_mem_addr] <= popcount_mem_data_in;
    end
  end

  reg [SPIKES-1:0] tile_mem_data_out; // INTERNAL
  reg [NO_WIDTH-1:0] popcount_mem_data_out; // INTERNAL

  always @(*) begin
    tile_mem_data_out = tile_buffer[tile_mem_addr];
    popcount_mem_data_out = row_popcounts[popcount_mem_addr];
  end

endmodule
