// pruner.v  – ProSparsity Pruner (N = 256, PM/EM compliant)
// ------------------------------------------------------------------
`timescale 1ns / 1ps
`default_nettype none

/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off UNUSEDPARAM */

module pruner #(
    parameter N        = 256,
    parameter M        = 16,
    parameter NO_WIDTH = 8,
    parameter NULL_ID  = 8'd255  // NULL prefix ID for roots
) (
    input wire clk,
    input wire rst_n,

    // ----- Detector → Pruner ------------------------------------------
    input  wire [        N-1:0] si_vector,
    input  wire [$clog2(N)-1:0] row_index,
    input  wire [ NO_WIDTH-1:0] row_NO,
    input  wire                 si_valid,
    output wire                 pruner_ready,

    // ----- Pruner → Dispatcher ----------------------------------------
    output reg  [$clog2(N)-1:0] prefix_id,
    output reg  [$clog2(N)-1:0] row_id_out,     // NEW: row index of this task
    output reg  [        M-1:0] pattern,
    output reg                  prune_valid,
    output reg                  prune_done,
    input  wire                 dispatch_ready,

    // ----- Single-port RAM interface for NO_table and spike_matrix ----
    input  wire [$clog2(N)-1:0] mem_addr,
    input  wire [NO_WIDTH-1:0]  mem_NO_in,
    input  wire [M-1:0]         mem_spike_in,
    output reg  [NO_WIDTH-1:0]  mem_NO_out,
    output reg  [M-1:0]         mem_spike_out,
    input  wire                 mem_wr_en,
    input  wire                 mem_sel // 0: NO_table, 1: spike_matrix
);
    // FSM states (Verilog-2005 style)
    localparam S_IDLE = 3'd0,
               S_FILT = 3'd1,
               S_SEL  = 3'd2,
               S_XOR  = 3'd3,
               S_OUT  = 3'd4,
               S_NEXT = 3'd5;

    reg  [2:0] state;
    reg  [  $clog2(N):0] row_counter;  // 0 … N

    // ───────────────────── latched current row ────────────────
    reg  [        N-1:0] si_vec_r;
    reg  [$clog2(N)-1:0] row_idx_r;
    reg  [ NO_WIDTH-1:0] row_NO_r;
    reg  [        M-1:0] cur_spikes_r;
    reg                  has_prefix_r;   // Track if we found a valid prefix

    // ───────────────────── Internal buffers ───────────────────
    reg [NO_WIDTH-1:0] NO_table [0:N-1];
    reg [M-1:0] spike_matrix [0:N-1];

    // ───────────────────── candidate filter ───────────────────
    wire [        N-1:0] valid_mask;
    reg  [        N-1:0] cand_mask_r = 0;  // 1 ⇒ valid prefix candidate

    genvar g;
    generate
        for (g = 0; g < N; g = g + 1) begin : GEN_VALID
            /* verilator lint_off CMPCONST */
            assign valid_mask[g] = (g != row_idx_r) && (  // Match golden model exactly
                // Partial-match: proper subset, smaller popcount
                ( (NO_table[g] <  row_NO_r) &&
                                   ((spike_matrix[g] & cur_spikes_r) == spike_matrix[g]) ) ||
                // Exact-match: identical pattern, earlier index (EM rule)
                ( (NO_table[g] == row_NO_r) &&
                                   (spike_matrix[g] == cur_spikes_r) && (g < row_idx_r) )
                               );
            /* verilator lint_on  CMPCONST */
        end
    endgenerate

    // ───────────────────── parallel arg-max tree ───────────────
    // First three levels (256 → 32) as before … then
    // a *final reduction loop* to pick the global winner.

    reg     [$clog2(N)-1:0] best_idx_lvl0[(N/2)-1:0];
    reg     [ NO_WIDTH-1:0] best_NO_lvl0 [(N/2)-1:0];

    reg     [$clog2(N)-1:0] best_idx_lvl1[(N/4)-1:0];
    reg     [ NO_WIDTH-1:0] best_NO_lvl1 [(N/4)-1:0];

    reg     [$clog2(N)-1:0] best_idx_lvl2[(N/8)-1:0];
    reg     [ NO_WIDTH-1:0] best_NO_lvl2 [(N/8)-1:0];

    reg     [$clog2(N)-1:0] best_idx_r;
    reg     [ NO_WIDTH-1:0] best_NO_r;
    reg     [        M-1:0] pre_spikes_r;

    integer                 i;
    always @* begin
        /* ---------- Level-0 : pairs ---------- */
        for (i = 0; i < N / 2; i = i + 1) begin
            case ({
                cand_mask_r[2*i+1], cand_mask_r[2*i]
            })
                2'b00: begin
                    best_idx_lvl0[i] = row_idx_r;
                    best_NO_lvl0[i]  = 0;
                end
                2'b01: begin
                    best_idx_lvl0[i] = 2 * i;
                    best_NO_lvl0[i]  = NO_table[2*i];
                end
                2'b10: begin
                    best_idx_lvl0[i] = 2 * i + 1;
                    best_NO_lvl0[i]  = NO_table[2*i+1];
                end
                default: begin
                    if (NO_table[2*i] > NO_table[2*i+1] ||
               (NO_table[2*i]==NO_table[2*i+1] && 2*i > 2*i+1)) begin
                        best_idx_lvl0[i] = 2 * i;
                        best_NO_lvl0[i]  = NO_table[2*i];
                    end else begin
                        best_idx_lvl0[i] = 2 * i + 1;
                        best_NO_lvl0[i]  = NO_table[2*i+1];
                    end
                end
            endcase
        end

        /* ---------- Level-1 : quarters ---------- */
        for (i = 0; i < N / 4; i = i + 1) begin
            if (best_NO_lvl0[2*i] > best_NO_lvl0[2*i+1] ||
           (best_NO_lvl0[2*i]==best_NO_lvl0[2*i+1] &&
            best_idx_lvl0[2*i]>best_idx_lvl0[2*i+1])) begin
                best_idx_lvl1[i] = best_idx_lvl0[2*i];
                best_NO_lvl1[i]  = best_NO_lvl0[2*i];
            end else begin
                best_idx_lvl1[i] = best_idx_lvl0[2*i+1];
                best_NO_lvl1[i]  = best_NO_lvl0[2*i+1];
            end
        end

        /* ---------- Level-2 : octets (32 winners) ---------- */
        for (i = 0; i < N / 8; i = i + 1) begin
            if (best_NO_lvl1[2*i] > best_NO_lvl1[2*i+1] ||
           (best_NO_lvl1[2*i]==best_NO_lvl1[2*i+1] &&
            best_idx_lvl1[2*i]>best_idx_lvl1[2*i+1])) begin
                best_idx_lvl2[i] = best_idx_lvl1[2*i];
                best_NO_lvl2[i]  = best_NO_lvl1[2*i];
            end else begin
                best_idx_lvl2[i] = best_idx_lvl1[2*i+1];
                best_NO_lvl2[i]  = best_NO_lvl1[2*i+1];
            end
        end

        /* ---------- Final reduction : 32 → 1 ---------- */
        best_idx_r = best_idx_lvl2[0];
        best_NO_r  = best_NO_lvl2[0];
        for (i = 1; i < N / 8; i = i + 1) begin
            if (best_NO_lvl2[i] > best_NO_r ||
           (best_NO_lvl2[i] == best_NO_r && best_idx_lvl2[i] > best_idx_r)) begin
                best_idx_r = best_idx_lvl2[i];
                best_NO_r  = best_NO_lvl2[i];
            end
        end
    end

`ifdef LEGACY_PRUNER
    // ───────────────────── ready / FSM control ────────────────
    assign pruner_ready = (state == S_IDLE);

    always @(posedge clk) begin
        if (!rst_n) begin
            state <= S_IDLE;
            prune_valid <= 1'b0;
            prune_done <= 1'b0;
            row_counter <= 0;
        end else begin
            case (state)
                /* -------------------------------------------------- */
                S_IDLE: begin
                    prune_valid <= 1'b0;
                    prune_done  <= 1'b0;
                    if (si_valid && pruner_ready) begin
                        si_vec_r     <= si_vector;
                        row_idx_r    <= row_index;
                        row_NO_r     <= row_NO;
                        cur_spikes_r <= spike_matrix[row_index];
                        row_counter  <= row_counter + 1;
                        state        <= S_FILT;
                    end
                end

                /* -------------------------------------------------- */
                S_FILT: begin
                    cand_mask_r <= valid_mask;  // 1 ⇒ valid prefix
                    state       <= S_SEL;
                end

                /* -------------------------------------------------- */
                S_SEL: begin
                    if (|cand_mask_r) begin
                        prefix_id    <= best_idx_r;
                        pre_spikes_r <= spike_matrix[best_idx_r];
                        has_prefix_r <= 1'b1;
                    end else begin
                        prefix_id    <= row_idx_r;   // Use self as prefix for roots (PROS_NULL="row")
                        pre_spikes_r <= cur_spikes_r; // Self pattern 
                        has_prefix_r <= 1'b1;       // Treat as having prefix (self)
                    end
                    state <= S_XOR;
                end

                /* -------------------------------------------------- */
                S_XOR: begin
                    if (has_prefix_r) begin
                        pattern <= cur_spikes_r ^ pre_spikes_r;  // Normal prefix case
                    end else begin
                        pattern <= cur_spikes_r;                 // Root case: residual = row_pattern
                    end
                    row_id_out  <= row_idx_r;  // === new: emit correct row index
                    prune_valid <= 1'b1;
                    state       <= S_OUT;
                end

                /* -------------------------------------------------- */
                S_OUT: begin
                    if (dispatch_ready) begin
                        prune_valid <= 1'b0;
                        row_id_out <= {($clog2(N)) {1'b0}};  // clear when accepted
                        state <= S_NEXT;
                    end
                end
                /* -------------------------------------------------- */
                S_NEXT: begin
                    if (row_counter == N) begin
                        prune_done <= 1'b1;
                    end
                    state <= S_IDLE;
                end

                /* -------------------------------------------------- */
                default: state <= S_IDLE;
            endcase
        end
    end

`endif  // LEGACY_PRUNER

    // ---------------- Pipelined implementation ----------------

    // Always ready – accept a new row every cycle
    assign pruner_ready = 1'b1;

    // --- Pipeline registers ---
    reg [N-1:0]           st0_si_vec;
    reg [$clog2(N)-1:0]   st0_row_idx,  st1_row_idx,  st2_row_idx;
    reg [NO_WIDTH-1:0]    st0_row_NO;
    reg [M-1:0]           st0_row_spikes, st1_row_spikes,
                          st1_pre_spikes, st2_pattern;
    reg [$clog2(N)-1:0]   st1_prefix_idx, st2_prefix_idx;
    reg                   st0_valid, st1_valid, st2_valid;

    // Stage-0 : latch detector result
    always @(posedge clk) begin
        if (!rst_n) begin
            st0_valid <= 1'b0;
        end else begin
            st0_valid <= si_valid;
            if (si_valid) begin
                st0_si_vec     <= si_vector;
                st0_row_idx    <= row_index;
                st0_row_NO     <= row_NO;
                st0_row_spikes <= spike_matrix[row_index];
            end
        end
    end

    // Candidate evaluation – combinational
    integer j;
    reg [$clog2(N)-1:0] best_idx_comb;
    reg [NO_WIDTH-1:0]  best_no_comb;
    reg [M-1:0]         best_spikes_comb;
    reg                 has_prefix_comb;

    always @(*) begin
        // Initialize: no prefix found  
        best_idx_comb    = NULL_ID;      // Use NULL_ID when no prefix found
        best_no_comb     = 0;            
        best_spikes_comb = {M{1'b0}};    // Zero pattern for NULL prefix
        has_prefix_comb  = 1'b0;
        
        // Search for valid prefix candidates - match golden model policy exactly  
        for (j = 0; j < N; j = j + 1) begin            
            if (st0_valid && (j != st0_row_idx) && (
                // PM: proper subset with smaller popcount (any index allowed)
                ((NO_table[j] < st0_row_NO) && ((spike_matrix[j] & st0_row_spikes) == spike_matrix[j])) ||
                // EM: equal popcount, exact match, earlier index only
                ((j < st0_row_idx) && (NO_table[j] == st0_row_NO) && (spike_matrix[j] == st0_row_spikes))
            )) begin
                // Select largest popcount; tie-break by largest index (for EM case)  
                if (!has_prefix_comb || 
                    NO_table[j] > best_no_comb ||
                    (NO_table[j] == best_no_comb && j[$clog2(N)-1:0] > best_idx_comb)) begin
                    
                    
                    best_idx_comb    = j[$clog2(N)-1:0];
                    best_no_comb     = NO_table[j];
                    best_spikes_comb = spike_matrix[j];
                    has_prefix_comb  = 1'b1;
                end
            end
        end
        
        
    end

    // Stage-1 : register selection results
    reg st1_has_prefix;
    always @(posedge clk) begin
        if (!rst_n) begin
            st1_valid <= 1'b0;
            st1_has_prefix <= 1'b0;
        end else begin
            st1_valid        <= st0_valid;
            st1_row_idx      <= st0_row_idx;
            st1_row_spikes   <= st0_row_spikes;
            st1_prefix_idx   <= best_idx_comb;
            st1_pre_spikes   <= best_spikes_comb;
            st1_has_prefix   <= has_prefix_comb;
        end
    end

    // Stage-2 : XOR and handshake to dispatcher
    reg st2_has_prefix;
    always @(posedge clk) begin
        if (!rst_n) begin
            st2_valid <= 1'b0;
            st2_has_prefix <= 1'b0;
            prune_valid <= 1'b0;
            row_id_out  <= 0;
            prefix_id   <= 0;
            pattern     <= 0;
        end else begin
            st2_valid <= st1_valid;
            st2_has_prefix <= st1_has_prefix;
            if (st1_valid) begin
                st2_row_idx    <= st1_row_idx;
                st2_prefix_idx <= st1_prefix_idx;
                // Root vs prefix XOR handling
                if (st1_has_prefix) begin
                    st2_pattern <= st1_row_spikes ^ st1_pre_spikes;  // Normal case
                end else begin
                    st2_pattern <= st1_row_spikes;  // Root: residual = row_pattern
                end
            end

            // Drive outputs when dispatcher ready
            if (st2_valid && dispatch_ready) begin
                row_id_out  <= st2_row_idx;
                prefix_id   <= st2_prefix_idx;
                pattern     <= st2_pattern;
                prune_valid <= 1'b1;
            end else begin
                prune_valid <= 1'b0;
            end
        end
    end

    // Simple done pulse after N tasks
    reg [$clog2(N+1)-1:0] out_count;
    always @(posedge clk) begin
        if (!rst_n) begin
            out_count  <= 0;
            prune_done <= 0;
        end else begin
            prune_done <= 0;
            if (st2_valid && dispatch_ready) begin
                if (out_count == N-1) begin
                    prune_done <= 1'b1;
                    out_count  <= 0;
                end else begin
                    out_count  <= out_count + 1;
                end
            end
        end
    end

    // ───────────────────── Single-port RAM logic ──────────────
    always @(posedge clk) begin
        if (mem_wr_en) begin
            if (!mem_sel) begin
                NO_table[mem_addr] <= mem_NO_in;
            end else begin
                spike_matrix[mem_addr] <= mem_spike_in;
            end
        end
    end
    always @(*) begin
        if (!mem_sel) begin
            mem_NO_out = NO_table[mem_addr];
            mem_spike_out = {M{1'b0}};
        end else begin
            mem_NO_out = {NO_WIDTH{1'b0}};
            mem_spike_out = spike_matrix[mem_addr];
        end
    end
endmodule
`default_nettype wire
