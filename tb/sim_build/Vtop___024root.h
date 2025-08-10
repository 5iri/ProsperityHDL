// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(row_info_valid,0,0);
        VL_OUT8(row_info_ready,0,0);
        VL_IN8(row_idx,7,0);
        VL_IN8(row_prefix_id,7,0);
        VL_IN8(row_popcnt,7,0);
        VL_IN8(row_last,0,0);
        VL_IN8(proc_ready,0,0);
        VL_OUT8(task_valid,0,0);
        VL_OUT8(task_row_id,7,0);
        VL_OUT8(task_prefix_id,7,0);
        VL_IN8(prev_compute_busy,0,0);
        VL_IN8(pruner_done,0,0);
        VL_OUT8(tile_done,0,0);
        CData/*0:0*/ dispatcher__DOT__clk;
        CData/*0:0*/ dispatcher__DOT__rst_n;
        CData/*0:0*/ dispatcher__DOT__row_info_valid;
        CData/*0:0*/ dispatcher__DOT__row_info_ready;
        CData/*7:0*/ dispatcher__DOT__row_idx;
        CData/*7:0*/ dispatcher__DOT__row_prefix_id;
        CData/*7:0*/ dispatcher__DOT__row_popcnt;
        CData/*0:0*/ dispatcher__DOT__row_last;
        CData/*0:0*/ dispatcher__DOT__proc_ready;
        CData/*0:0*/ dispatcher__DOT__task_valid;
        CData/*7:0*/ dispatcher__DOT__task_row_id;
        CData/*7:0*/ dispatcher__DOT__task_prefix_id;
        CData/*0:0*/ dispatcher__DOT__prev_compute_busy;
        CData/*0:0*/ dispatcher__DOT__pruner_done;
        CData/*0:0*/ dispatcher__DOT__tile_done;
        CData/*7:0*/ dispatcher__DOT__temp_pc;
        CData/*7:0*/ dispatcher__DOT__temp_row;
        CData/*2:0*/ dispatcher__DOT__state;
        CData/*2:0*/ dispatcher__DOT__next_state;
        CData/*0:0*/ dispatcher__DOT__last_row_seen;
        CData/*0:0*/ dispatcher__DOT__collect_timeout;
        CData/*1:0*/ dispatcher__DOT__sort_stage;
        CData/*7:0*/ dispatcher__DOT__sort_temp_pc;
        CData/*7:0*/ dispatcher__DOT__sort_temp_row;
        CData/*7:0*/ dispatcher__DOT__current_row;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_IN16(row_pattern,15,0);
        VL_OUT16(task_pattern,15,0);
        SData/*15:0*/ dispatcher__DOT__row_pattern;
        SData/*15:0*/ dispatcher__DOT__task_pattern;
        SData/*8:0*/ dispatcher__DOT__collect_count;
        SData/*8:0*/ dispatcher__DOT__dispatch_count;
        SData/*8:0*/ dispatcher__DOT__sort_count;
        SData/*15:0*/ dispatcher__DOT__timeout_counter;
        IData/*31:0*/ dispatcher__DOT__i;
        IData/*31:0*/ dispatcher__DOT__j;
        IData/*31:0*/ dispatcher__DOT__min_idx_found;
        IData/*31:0*/ dispatcher__DOT__min_pc_found;
        IData/*31:0*/ dispatcher__DOT__min_row_found;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 256> dispatcher__DOT__pst_prefix_id;
        VlUnpacked<SData/*15:0*/, 256> dispatcher__DOT__pst_pattern;
        VlUnpacked<CData/*7:0*/, 256> dispatcher__DOT__pst_popcnt;
        VlUnpacked<CData/*7:0*/, 256> dispatcher__DOT__pst_row_id;
        VlUnpacked<CData/*0:0*/, 256> dispatcher__DOT__pst_valid;
    };
    struct {
        VlUnpacked<CData/*7:0*/, 256> dispatcher__DOT__sort_row_id;
        VlUnpacked<CData/*7:0*/, 256> dispatcher__DOT__sort_popcnt;
        VlUnpacked<CData/*7:0*/, 256> dispatcher__DOT__collected_rows;
    };
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 256>, false, CData/*7:0*/, 1> __VdlyCommitQueuedispatcher__DOT__sort_popcnt;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 256>, false, CData/*7:0*/, 1> __VdlyCommitQueuedispatcher__DOT__sort_row_id;
    VlNBACommitQueue<VlUnpacked<CData/*0:0*/, 256>, false, CData/*0:0*/, 1> __VdlyCommitQueuedispatcher__DOT__pst_valid;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 256>, false, CData/*7:0*/, 1> __VdlyCommitQueuedispatcher__DOT__collected_rows;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*2:0*/ dispatcher__DOT__S_IDLE = 0U;
    static constexpr CData/*2:0*/ dispatcher__DOT__S_COLLECT = 1U;
    static constexpr CData/*2:0*/ dispatcher__DOT__S_SORT = 2U;
    static constexpr CData/*2:0*/ dispatcher__DOT__S_DISPATCH = 3U;
    static constexpr CData/*2:0*/ dispatcher__DOT__S_DONE = 4U;
    static constexpr IData/*31:0*/ dispatcher__DOT__ROWS = 0x00000100U;
    static constexpr IData/*31:0*/ dispatcher__DOT__SPIKES = 0x00000010U;
    static constexpr IData/*31:0*/ dispatcher__DOT__PATTERN_WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ dispatcher__DOT__NO_WIDTH = 8U;
    static constexpr IData/*31:0*/ dispatcher__DOT__IDX_W = 8U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
