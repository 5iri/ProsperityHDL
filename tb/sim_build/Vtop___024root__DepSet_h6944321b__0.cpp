// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__cfg_enable = vlSelfRef.cfg_enable;
    vlSelfRef.top__DOT__cfg_auto_repeat = vlSelfRef.cfg_auto_repeat;
    vlSelfRef.top__DOT__tile_start = vlSelfRef.tile_start;
    vlSelfRef.top__DOT__u_detector__DOT__row_idx = vlSelfRef.top__DOT__row_counter;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__req_key 
        = vlSelfRef.top__DOT__u_detector__DOT__query_reg;
    vlSelfRef.top__DOT__u_pruner__DOT__row_index = vlSelfRef.top__DOT__row_counter;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_last 
        = (0xffU == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_id_out));
    vlSelfRef.dbg_prn_ready = vlSelfRef.top__DOT__u_pruner__DOT__pruner_ready;
    vlSelfRef.top__DOT__dbg_prn_ready = vlSelfRef.top__DOT__u_pruner__DOT__pruner_ready;
    vlSelfRef.top__DOT__prn_ready = vlSelfRef.top__DOT__u_pruner__DOT__pruner_ready;
    vlSelfRef.tile_done = vlSelfRef.top__DOT__u_dispatcher__DOT__tile_done;
    vlSelfRef.top__DOT__tile_done = vlSelfRef.top__DOT__u_dispatcher__DOT__tile_done;
    vlSelfRef.top__DOT__dsp_tile_done = vlSelfRef.top__DOT__u_dispatcher__DOT__tile_done;
    vlSelfRef.tile_mem_data_out = vlSelfRef.top__DOT__tile_mem_data_out;
    vlSelfRef.pc_mem_data_out = vlSelfRef.top__DOT__pc_mem_data_out;
    vlSelfRef.task_valid = vlSelfRef.top__DOT__u_dispatcher__DOT__task_valid;
    vlSelfRef.task_row_id = vlSelfRef.top__DOT__u_dispatcher__DOT__task_row_id;
    vlSelfRef.task_prefix_id = vlSelfRef.top__DOT__u_dispatcher__DOT__task_prefix_id;
    vlSelfRef.task_pattern = vlSelfRef.top__DOT__u_dispatcher__DOT__task_pattern;
    vlSelfRef.output_rd_addr = vlSelfRef.top__DOT__u_processor__DOT__current_prefix_id;
    vlSelfRef.top__DOT__output_rd_addr = vlSelfRef.top__DOT__u_processor__DOT__current_prefix_id;
    vlSelfRef.top__DOT__u_processor__DOT__output_rd_addr 
        = vlSelfRef.top__DOT__u_processor__DOT__current_prefix_id;
    vlSelfRef.output_wr_addr = vlSelfRef.top__DOT__u_processor__DOT__current_row_id;
    vlSelfRef.top__DOT__output_wr_addr = vlSelfRef.top__DOT__u_processor__DOT__current_row_id;
    vlSelfRef.top__DOT__u_processor__DOT__output_wr_addr 
        = vlSelfRef.top__DOT__u_processor__DOT__current_row_id;
    vlSelfRef.output_wr_en = vlSelfRef.top__DOT__u_processor__DOT__writeback_en;
    vlSelfRef.top__DOT__output_wr_en = vlSelfRef.top__DOT__u_processor__DOT__writeback_en;
    vlSelfRef.top__DOT__u_processor__DOT__output_wr_en 
        = vlSelfRef.top__DOT__u_processor__DOT__writeback_en;
    vlSelfRef.top__DOT__det_done_flag = vlSelfRef.top__DOT__u_detector__DOT__det_done;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[0U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[1U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[2U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[3U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[4U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[5U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[6U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_matches[7U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[0U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[1U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[2U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[3U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[4U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[5U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[6U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__line_match[7U] 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__match[7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__0__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__1__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__2__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__3__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__4__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__5__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__6__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__7__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__8__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__9__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__10__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__11__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__12__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xcU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__13__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xdU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__14__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xeU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__15__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xfU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__16__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x10U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__17__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x11U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__18__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x12U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__19__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x13U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__20__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x14U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__21__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x15U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__22__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x16U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__23__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x17U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__24__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x18U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__25__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x19U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__26__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x1aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__27__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x1bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__28__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x1cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__29__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x1dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__30__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x1eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__31__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x1fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__32__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x20U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__33__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x21U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__34__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x22U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__35__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x23U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__36__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x24U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__37__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x25U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__38__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x26U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__39__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x27U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__40__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x28U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__41__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x29U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__42__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x2aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__43__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x2bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__44__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x2cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__45__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x2dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__46__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x2eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__47__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x2fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__48__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x30U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__49__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x31U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__50__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x32U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__51__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x33U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__52__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x34U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__53__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x35U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__54__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x36U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__55__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x37U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__56__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x38U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__57__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x39U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__58__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x3aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__59__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x3bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__60__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x3cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__61__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x3dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__62__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x3eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__63__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x3fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__64__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x40U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__65__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x41U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__66__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x42U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__67__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x43U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__68__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x44U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__69__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x45U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__70__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x46U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__71__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x47U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__72__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x48U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__73__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x49U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__74__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x4aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__75__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x4bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__76__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x4cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__77__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x4dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__78__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x4eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__79__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x4fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__80__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x50U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__81__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x51U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__82__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x52U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__83__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x53U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__84__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x54U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__85__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x55U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__86__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x56U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__87__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x57U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__88__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x58U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__89__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x59U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__90__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x5aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__91__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x5bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__92__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x5cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__93__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x5dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__94__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x5eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__95__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x5fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__96__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x60U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__97__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x61U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__98__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x62U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__99__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x63U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__100__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x64U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__101__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x65U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__102__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x66U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__103__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x67U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__104__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x68U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__105__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x69U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__106__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x6aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__107__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x6bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__108__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x6cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__109__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x6dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__110__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x6eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__111__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x6fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__112__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x70U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__113__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x71U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__114__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x72U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__115__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x73U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__116__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x74U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__117__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x75U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__118__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x76U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__119__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x77U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__120__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x78U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__121__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x79U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__122__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x7aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__123__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x7bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__124__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x7cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__125__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x7dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__126__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x7eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__127__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x7fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__128__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x80U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__129__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x81U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__130__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x82U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__131__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x83U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__132__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x84U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__133__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x85U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__134__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x86U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__135__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x87U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__136__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x88U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__137__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x89U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__138__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x8aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__139__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x8bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__140__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x8cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__141__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x8dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__142__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x8eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__143__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x8fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__144__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x90U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__145__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x91U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__146__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x92U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__147__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x93U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__148__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x94U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__149__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x95U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__150__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x96U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__151__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x97U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__152__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x98U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__153__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x99U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__154__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x9aU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__155__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x9bU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__156__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x9cU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__157__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x9dU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__158__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x9eU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__159__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0x9fU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__160__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__161__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__162__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__163__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__164__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__165__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__166__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__167__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__168__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__169__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xa9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__170__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xaaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__171__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xabU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__172__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xacU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__173__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xadU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__174__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xaeU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__175__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xafU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__176__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__177__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__178__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__179__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__180__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__181__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__182__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__183__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__184__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__185__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xb9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__186__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__187__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbbU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__188__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbcU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__189__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbdU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__190__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbeU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__191__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xbfU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__192__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__193__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__194__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__195__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__196__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__197__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__198__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__199__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__200__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__201__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xc9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__202__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xcaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__203__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xcbU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__204__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xccU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__205__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xcdU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__206__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xceU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__207__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xcfU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__208__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__209__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__210__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__211__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__212__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__213__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__214__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__215__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__216__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__217__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xd9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__218__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xdaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__219__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xdbU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__220__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xdcU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__221__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xddU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__222__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xdeU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__223__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xdfU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__224__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__225__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__226__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__227__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__228__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__229__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__230__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__231__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__232__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__233__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xe9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__234__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xeaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__235__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xebU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__236__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xecU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__237__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xedU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__238__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xeeU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__239__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xefU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__240__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf0U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__241__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf1U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__242__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf2U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__243__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf3U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__244__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf4U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__245__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf5U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__246__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf6U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__247__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf7U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__248__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf8U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__249__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xf9U];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__250__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xfaU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__251__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xfbU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__252__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xfcU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__253__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xfdU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__254__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xfeU];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__255__KET____DOT__mem_tmp 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
        [0xffU];
    vlSelfRef.top__DOT__row_done = ((IData)(vlSelfRef.top__DOT__u_detector__DOT__si_valid) 
                                    & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__pruner_ready));
    vlSelfRef.top__DOT__u_detector__DOT__tile_mem_data_out 
        = vlSelfRef.top__DOT__u_detector__DOT__tile_buffer
        [vlSelfRef.tile_mem_addr];
    vlSelfRef.top__DOT__u_detector__DOT__popcount_mem_data_out 
        = vlSelfRef.top__DOT__u_detector__DOT__row_popcounts
        [vlSelfRef.pc_mem_addr];
    vlSelfRef.top__DOT__tile_mem_addr = vlSelfRef.tile_mem_addr;
    vlSelfRef.top__DOT__pc_mem_addr = vlSelfRef.pc_mem_addr;
    vlSelfRef.top__DOT__pc_mem_data_in = vlSelfRef.pc_mem_data_in;
    vlSelfRef.top__DOT__pc_mem_wr_en = vlSelfRef.pc_mem_wr_en;
    vlSelfRef.top__DOT__weight_data[0U] = vlSelfRef.weight_data[0U];
    vlSelfRef.top__DOT__weight_data[1U] = vlSelfRef.weight_data[1U];
    vlSelfRef.top__DOT__weight_data[2U] = vlSelfRef.weight_data[2U];
    vlSelfRef.top__DOT__weight_data[3U] = vlSelfRef.weight_data[3U];
    vlSelfRef.top__DOT__weight_data[4U] = vlSelfRef.weight_data[4U];
    vlSelfRef.top__DOT__weight_data[5U] = vlSelfRef.weight_data[5U];
    vlSelfRef.top__DOT__weight_data[6U] = vlSelfRef.weight_data[6U];
    vlSelfRef.top__DOT__weight_data[7U] = vlSelfRef.weight_data[7U];
    vlSelfRef.top__DOT__weight_data[8U] = vlSelfRef.weight_data[8U];
    vlSelfRef.top__DOT__weight_data[9U] = vlSelfRef.weight_data[9U];
    vlSelfRef.top__DOT__weight_data[0xaU] = vlSelfRef.weight_data[0xaU];
    vlSelfRef.top__DOT__weight_data[0xbU] = vlSelfRef.weight_data[0xbU];
    vlSelfRef.top__DOT__weight_data[0xcU] = vlSelfRef.weight_data[0xcU];
    vlSelfRef.top__DOT__weight_data[0xdU] = vlSelfRef.weight_data[0xdU];
    vlSelfRef.top__DOT__weight_data[0xeU] = vlSelfRef.weight_data[0xeU];
    vlSelfRef.top__DOT__weight_data[0xfU] = vlSelfRef.weight_data[0xfU];
    vlSelfRef.top__DOT__weight_data[0x10U] = vlSelfRef.weight_data[0x10U];
    vlSelfRef.top__DOT__weight_data[0x11U] = vlSelfRef.weight_data[0x11U];
    vlSelfRef.top__DOT__weight_data[0x12U] = vlSelfRef.weight_data[0x12U];
    vlSelfRef.top__DOT__weight_data[0x13U] = vlSelfRef.weight_data[0x13U];
    vlSelfRef.top__DOT__weight_data[0x14U] = vlSelfRef.weight_data[0x14U];
    vlSelfRef.top__DOT__weight_data[0x15U] = vlSelfRef.weight_data[0x15U];
    vlSelfRef.top__DOT__weight_data[0x16U] = vlSelfRef.weight_data[0x16U];
    vlSelfRef.top__DOT__weight_data[0x17U] = vlSelfRef.weight_data[0x17U];
    vlSelfRef.top__DOT__weight_data[0x18U] = vlSelfRef.weight_data[0x18U];
    vlSelfRef.top__DOT__weight_data[0x19U] = vlSelfRef.weight_data[0x19U];
    vlSelfRef.top__DOT__weight_data[0x1aU] = vlSelfRef.weight_data[0x1aU];
    vlSelfRef.top__DOT__weight_data[0x1bU] = vlSelfRef.weight_data[0x1bU];
    vlSelfRef.top__DOT__weight_data[0x1cU] = vlSelfRef.weight_data[0x1cU];
    vlSelfRef.top__DOT__weight_data[0x1dU] = vlSelfRef.weight_data[0x1dU];
    vlSelfRef.top__DOT__weight_data[0x1eU] = vlSelfRef.weight_data[0x1eU];
    vlSelfRef.top__DOT__weight_data[0x1fU] = vlSelfRef.weight_data[0x1fU];
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.top__DOT__output_rd_data[__Vilp1] 
            = vlSelfRef.output_rd_data[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.top__DOT__u_detector__DOT__rst = (1U 
                                                & (~ (IData)(vlSelfRef.rst_n)));
    vlSelfRef.top__DOT__u_detector__DOT__tcam_set_valid = 0U;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_set_clr = 0U;
    vlSelfRef.ppu_busy = ((0U != (IData)(vlSelfRef.top__DOT__state)) 
                          & (4U != (IData)(vlSelfRef.top__DOT__state)));
    vlSelfRef.dbg_state = vlSelfRef.top__DOT__state;
    vlSelfRef.top__DOT__det_si_valid = vlSelfRef.top__DOT__u_detector__DOT__si_valid;
    vlSelfRef.top__DOT__task_row_id = vlSelfRef.top__DOT__u_dispatcher__DOT__task_row_id;
    vlSelfRef.top__DOT__task_prefix_id = vlSelfRef.top__DOT__u_dispatcher__DOT__task_prefix_id;
    vlSelfRef.top__DOT__task_pattern = vlSelfRef.top__DOT__u_dispatcher__DOT__task_pattern;
    vlSelfRef.top__DOT__proc_done = (4U == (IData)(vlSelfRef.top__DOT__u_processor__DOT__state));
    vlSelfRef.top__DOT__det_row_pc = vlSelfRef.top__DOT__u_detector__DOT__row_popcnt;
    vlSelfRef.top__DOT__prn_row_id = vlSelfRef.top__DOT__u_pruner__DOT__row_id_out;
    vlSelfRef.top__DOT__prn_prefix_id = vlSelfRef.top__DOT__u_pruner__DOT__prefix_id;
    vlSelfRef.top__DOT__prn_pattern = vlSelfRef.top__DOT__u_pruner__DOT__pattern;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_req_valid = 0U;
    if ((1U != (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))) {
            vlSelfRef.top__DOT__u_detector__DOT__tcam_set_clr = 0U;
        }
        vlSelfRef.top__DOT__u_detector__DOT__tcam_req_valid 
            = ((2U == (IData)(vlSelfRef.top__DOT__u_detector__DOT__state)) 
               && (1U & (~ (IData)(vlSelfRef.top__DOT__u_detector__DOT__query_in_progress))));
    }
    vlSelfRef.top__DOT__u_detector__DOT__tcam_addr 
        = vlSelfRef.top__DOT__u_detector__DOT__load_counter;
    vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_wr_en 
        = ((IData)(vlSelfRef.pc_mem_wr_en) | (IData)(vlSelfRef.tile_mem_wr_en));
    vlSelfRef.top__DOT____Vcellinp__u_detector__query_pattern 
        = vlSelfRef.top__DOT__tile_ram[vlSelfRef.top__DOT__row_counter];
    vlSelfRef.top__DOT__u_detector__DOT__tcam_key = 0U;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_xmask = 0U;
    if ((1U == (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))) {
        vlSelfRef.top__DOT__u_detector__DOT__tcam_set_valid = 1U;
        vlSelfRef.top__DOT__u_detector__DOT__tcam_addr 
            = vlSelfRef.top__DOT__u_detector__DOT__load_counter;
        vlSelfRef.top__DOT__u_detector__DOT__tcam_key 
            = vlSelfRef.top__DOT__u_detector__DOT__tile_buffer
            [vlSelfRef.top__DOT__u_detector__DOT__load_counter];
        vlSelfRef.top__DOT__u_detector__DOT__tcam_xmask 
            = (0xffffU & (~ vlSelfRef.top__DOT__u_detector__DOT__tile_buffer
                          [vlSelfRef.top__DOT__u_detector__DOT__load_counter]));
    } else if ((2U != (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))) {
        vlSelfRef.top__DOT__u_detector__DOT__tcam_set_valid = 0U;
    }
    vlSelfRef.top__DOT__tile_mem_data_in = vlSelfRef.tile_mem_data_in;
    vlSelfRef.top__DOT__tile_mem_wr_en = vlSelfRef.tile_mem_wr_en;
    if (vlSelfRef.pc_mem_wr_en) {
        vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_NO_in 
            = vlSelfRef.pc_mem_data_in;
        vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_addr 
            = vlSelfRef.pc_mem_addr;
    } else {
        vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_NO_in 
            = vlSelfRef.top__DOT__popcount_ram[vlSelfRef.tile_mem_addr];
        vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_addr 
            = vlSelfRef.tile_mem_addr;
    }
    vlSelfRef.output_wr_data[0U] = (IData)((((QData)((IData)(
                                                             ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [3U] 
                                                               << 0x10U) 
                                                              | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                              [2U]))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [1U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0U])))));
    vlSelfRef.output_wr_data[1U] = (IData)(((((QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [3U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [2U]))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [1U] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0U])))) 
                                            >> 0x20U));
    vlSelfRef.output_wr_data[2U] = (IData)((((QData)((IData)(
                                                             ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [7U] 
                                                               << 0x10U) 
                                                              | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                              [6U]))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [5U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [4U])))));
    vlSelfRef.output_wr_data[3U] = (IData)(((((QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [7U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [6U]))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [5U] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [4U])))) 
                                            >> 0x20U));
    vlSelfRef.output_wr_data[4U] = (IData)((((QData)((IData)(
                                                             ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0xbU] 
                                                               << 0x10U) 
                                                              | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                              [0xaU]))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [9U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [8U])))));
    vlSelfRef.output_wr_data[5U] = (IData)(((((QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0xbU] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0xaU]))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [9U] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [8U])))) 
                                            >> 0x20U));
    vlSelfRef.output_wr_data[6U] = (IData)((((QData)((IData)(
                                                             ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0xfU] 
                                                               << 0x10U) 
                                                              | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                              [0xeU]))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0xdU] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0xcU])))));
    vlSelfRef.output_wr_data[7U] = (IData)(((((QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0xfU] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0xeU]))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0xdU] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0xcU])))) 
                                            >> 0x20U));
    vlSelfRef.output_wr_data[8U] = (IData)((((QData)((IData)(
                                                             ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0x13U] 
                                                               << 0x10U) 
                                                              | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                              [0x12U]))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0x11U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0x10U])))));
    vlSelfRef.output_wr_data[9U] = (IData)(((((QData)((IData)(
                                                              ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0x13U] 
                                                                << 0x10U) 
                                                               | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                               [0x12U]))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x11U] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0x10U])))) 
                                            >> 0x20U));
    vlSelfRef.output_wr_data[0xaU] = (IData)((((QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x17U] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0x16U]))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x15U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x14U])))));
    vlSelfRef.output_wr_data[0xbU] = (IData)(((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x17U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x16U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x15U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x14U])))) 
                                              >> 0x20U));
    vlSelfRef.output_wr_data[0xcU] = (IData)((((QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x1bU] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0x1aU]))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x19U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x18U])))));
    vlSelfRef.output_wr_data[0xdU] = (IData)(((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x1bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x1aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x19U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x18U])))) 
                                              >> 0x20U));
    vlSelfRef.output_wr_data[0xeU] = (IData)((((QData)((IData)(
                                                               ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x1fU] 
                                                                 << 0x10U) 
                                                                | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                [0x1eU]))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x1dU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x1cU])))));
    vlSelfRef.output_wr_data[0xfU] = (IData)(((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x1fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x1eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x1dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x1cU])))) 
                                              >> 0x20U));
    vlSelfRef.output_wr_data[0x10U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x23U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x22U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x21U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x20U])))));
    vlSelfRef.output_wr_data[0x11U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x23U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x22U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x21U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x20U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x12U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x27U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x26U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x25U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x24U])))));
    vlSelfRef.output_wr_data[0x13U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x27U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x26U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x25U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x24U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x14U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x2bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x2aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x29U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x28U])))));
    vlSelfRef.output_wr_data[0x15U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x2bU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x2aU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x29U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x28U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x16U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x2fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x2eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x2dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x2cU])))));
    vlSelfRef.output_wr_data[0x17U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x2fU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x2eU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x2dU] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x2cU])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x18U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x33U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x32U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x31U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x30U])))));
    vlSelfRef.output_wr_data[0x19U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x33U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x32U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x31U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x30U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x1aU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x37U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x36U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x35U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x34U])))));
    vlSelfRef.output_wr_data[0x1bU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x37U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x36U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x35U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x34U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x1cU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x3bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x3aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x39U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x38U])))));
    vlSelfRef.output_wr_data[0x1dU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x3bU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x3aU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x39U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x38U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x1eU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x3fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x3eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x3dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x3cU])))));
    vlSelfRef.output_wr_data[0x1fU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x3fU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x3eU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x3dU] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x3cU])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x20U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x43U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x42U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x41U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x40U])))));
    vlSelfRef.output_wr_data[0x21U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x43U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x42U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x41U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x40U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x22U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x47U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x46U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x45U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x44U])))));
    vlSelfRef.output_wr_data[0x23U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x47U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x46U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x45U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x44U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x24U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x4bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x4aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x49U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x48U])))));
    vlSelfRef.output_wr_data[0x25U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x4bU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x4aU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x49U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x48U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x26U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x4fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x4eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x4dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x4cU])))));
    vlSelfRef.output_wr_data[0x27U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x4fU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x4eU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x4dU] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x4cU])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x28U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x53U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x52U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x51U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x50U])))));
    vlSelfRef.output_wr_data[0x29U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x53U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x52U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x51U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x50U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x2aU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x57U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x56U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x55U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x54U])))));
    vlSelfRef.output_wr_data[0x2bU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x57U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x56U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x55U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x54U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x2cU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x5bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x5aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x59U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x58U])))));
    vlSelfRef.output_wr_data[0x2dU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x5bU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x5aU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x59U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x58U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x2eU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x5fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x5eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x5dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x5cU])))));
    vlSelfRef.output_wr_data[0x2fU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x5fU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x5eU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x5dU] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x5cU])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x30U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x63U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x62U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x61U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x60U])))));
    vlSelfRef.output_wr_data[0x31U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x63U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x62U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x61U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x60U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x32U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x67U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x66U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x65U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x64U])))));
    vlSelfRef.output_wr_data[0x33U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x67U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x66U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x65U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x64U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x34U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x6bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x6aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x69U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x68U])))));
    vlSelfRef.output_wr_data[0x35U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x6bU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x6aU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x69U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x68U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x36U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x6fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x6eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x6dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x6cU])))));
    vlSelfRef.output_wr_data[0x37U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x6fU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x6eU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x6dU] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x6cU])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x38U] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x73U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x72U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x71U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x70U])))));
    vlSelfRef.output_wr_data[0x39U] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x73U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x72U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x71U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x70U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x3aU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x77U] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x76U]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x75U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x74U])))));
    vlSelfRef.output_wr_data[0x3bU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x77U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x76U]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x75U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x74U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x3cU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x7bU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x7aU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x79U] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x78U])))));
    vlSelfRef.output_wr_data[0x3dU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x7bU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x7aU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x79U] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x78U])))) 
                                               >> 0x20U));
    vlSelfRef.output_wr_data[0x3eU] = (IData)((((QData)((IData)(
                                                                ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x7fU] 
                                                                  << 0x10U) 
                                                                 | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                 [0x7eU]))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x7dU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x7cU])))));
    vlSelfRef.output_wr_data[0x3fU] = (IData)(((((QData)((IData)(
                                                                 ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x7fU] 
                                                                   << 0x10U) 
                                                                  | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                  [0x7eU]))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                    [0x7dU] 
                                                                    << 0x10U) 
                                                                   | vlSelfRef.top__DOT__u_processor__DOT__pe_partial_sum
                                                                   [0x7cU])))) 
                                               >> 0x20U));
    vlSelfRef.top__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.dbg_proc_busy = (0U != (IData)(vlSelfRef.top__DOT__u_processor__DOT__state));
    vlSelfRef.top__DOT__detector_init_done = vlSelfRef.top__DOT__u_detector__DOT__detector_init_done;
    vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0[vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Pre_he920b6b0_0_0] = 0U;
    vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0[vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r] = 1U;
    vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Pre_he920b6b0_0_0 
        = vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r;
    vlSelfRef.top__DOT__u_processor__DOT__pattern_empty 
        = (0U == (IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working));
    vlSelfRef.top__DOT__u_pruner__DOT__best_idx_comb 
        = vlSelfRef.top__DOT__u_pruner__DOT__st0_row_idx;
    vlSelfRef.top__DOT__u_pruner__DOT__best_no_comb = 0U;
    vlSelfRef.top__DOT__u_pruner__DOT__best_spikes_comb 
        = vlSelfRef.top__DOT__u_pruner__DOT__st0_row_spikes;
    vlSelfRef.top__DOT__u_pruner__DOT__j = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelfRef.top__DOT__u_pruner__DOT__j)) {
        if (((((IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_valid) 
               & (vlSelfRef.top__DOT__u_pruner__DOT__st0_si_vec[
                  (7U & (vlSelfRef.top__DOT__u_pruner__DOT__j 
                         >> 5U))] >> (0x1fU & vlSelfRef.top__DOT__u_pruner__DOT__j))) 
              & (vlSelfRef.top__DOT__u_pruner__DOT__j 
                 != (IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_row_idx))) 
             & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                  [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)] 
                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_row_NO)) 
                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                     [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)] 
                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_row_spikes)) 
                    == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                    [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)])) 
                | (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                     [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)] 
                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_row_NO)) 
                    & (vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                       [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)] 
                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_row_spikes))) 
                   & (vlSelfRef.top__DOT__u_pruner__DOT__j 
                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__st0_row_idx)))))) {
            if (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                  [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)] 
                  > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_no_comb)) 
                 | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                     [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)] 
                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_no_comb)) 
                    & (vlSelfRef.top__DOT__u_pruner__DOT__j 
                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_comb))))) {
                vlSelfRef.top__DOT__u_pruner__DOT__best_idx_comb 
                    = (0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j);
                vlSelfRef.top__DOT__u_pruner__DOT__best_no_comb 
                    = vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                    [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)];
                vlSelfRef.top__DOT__u_pruner__DOT__best_spikes_comb 
                    = vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                    [(0xffU & vlSelfRef.top__DOT__u_pruner__DOT__j)];
            }
        }
        vlSelfRef.top__DOT__u_pruner__DOT__j = ((IData)(1U) 
                                                + vlSelfRef.top__DOT__u_pruner__DOT__j);
    }
    vlSelfRef.ppu_ready = ((0U == (IData)(vlSelfRef.top__DOT__state)) 
                           | (4U == (IData)(vlSelfRef.top__DOT__state)));
    vlSelfRef.core_ready = (0U == (IData)(vlSelfRef.top__DOT__u_processor__DOT__state));
    vlSelfRef.dbg_dsp_ready = ((0U == (IData)(vlSelfRef.top__DOT__u_dispatcher__DOT__state)) 
                               | (1U == (IData)(vlSelfRef.top__DOT__u_dispatcher__DOT__state)));
    vlSelfRef.top__DOT__task_valid = vlSelfRef.top__DOT__u_dispatcher__DOT__task_valid;
    vlSelfRef.top__DOT__prn_valid = vlSelfRef.top__DOT__u_pruner__DOT__prune_valid;
    vlSelfRef.top__DOT__prune_done = vlSelfRef.top__DOT__u_pruner__DOT__prune_done;
    vlSelfRef.top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0U;
    while (VL_GTS_III(32, 0x80U, vlSelfRef.top__DOT__u_pruner__DOT__i)) {
        if ((0U == ((2U & ((vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[
                            (7U & (((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)) 
                                   >> 5U))] >> (0x1fU 
                                                & ((IData)(1U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))) 
                           << 1U)) | (1U & (vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[
                                            (7U & (
                                                   VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i) 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))))))) {
            vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0[(0x7fU 
                                                              & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r;
            vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0[(0x7fU 
                                                             & vlSelfRef.top__DOT__u_pruner__DOT__i)] = 0U;
        } else if ((1U == ((2U & ((vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[
                                   (7U & (((IData)(1U) 
                                           + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)) 
                                          >> 5U))] 
                                   >> (0x1fU & ((IData)(1U) 
                                                + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))) 
                                  << 1U)) | (1U & (
                                                   vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[
                                                   (7U 
                                                    & (VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))))))) {
            vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0[(0x7fU 
                                                              & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = (0xffU & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i));
            vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0[(0x7fU 
                                                             & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                [(0xffU & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))];
        } else if ((2U == ((2U & ((vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[
                                   (7U & (((IData)(1U) 
                                           + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)) 
                                          >> 5U))] 
                                   >> (0x1fU & ((IData)(1U) 
                                                + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))) 
                                  << 1U)) | (1U & (
                                                   vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[
                                                   (7U 
                                                    & (VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))))))) {
            vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0[(0x7fU 
                                                              & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = (0xffU & ((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)));
            vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0[(0x7fU 
                                                             & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                [(0xffU & ((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))];
        } else if (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                     [(0xffU & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))] 
                     > vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                     [(0xffU & ((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))]) 
                    | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                        [(0xffU & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))] 
                        == vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                        [(0xffU & ((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))]) 
                       & VL_LTS_III(32, VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i), 
                                    ((IData)(1U) + 
                                     VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))))) {
            vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0[(0x7fU 
                                                              & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = (0xffU & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i));
            vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0[(0x7fU 
                                                             & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                [(0xffU & VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i))];
        } else {
            vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0[(0x7fU 
                                                              & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = (0xffU & ((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)));
            vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0[(0x7fU 
                                                             & vlSelfRef.top__DOT__u_pruner__DOT__i)] 
                = vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                [(0xffU & ((IData)(1U) + VL_MULS_III(32, (IData)(2U), vlSelfRef.top__DOT__u_pruner__DOT__i)))];
        }
        vlSelfRef.top__DOT__u_pruner__DOT__i = ((IData)(1U) 
                                                + vlSelfRef.top__DOT__u_pruner__DOT__i);
    }
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [1U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [0U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [1U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [0U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [1U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [1U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [1U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 1U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [2U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [3U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [2U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [3U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [2U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [3U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [2U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [2U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [3U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [3U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 2U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [4U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [5U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [4U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [5U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [4U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [5U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [4U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [4U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [5U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [5U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 3U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [6U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [7U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [6U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [7U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [6U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [7U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [6U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [6U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [7U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [7U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 4U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [8U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [9U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [8U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                    [9U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [8U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                             [9U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [8U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [8U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [9U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [9U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 5U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0xaU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0xbU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                      [0xaU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                      [0xbU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                 [0xaU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                 [0xbU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0xaU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0xaU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0xbU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0xbU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 6U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0xcU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0xdU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                      [0xcU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                      [0xdU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                 [0xcU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                 [0xdU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0xcU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0xcU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0xdU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0xdU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 7U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0xeU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0xfU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                      [0xeU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                      [0xfU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                 [0xeU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                 [0xfU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0xeU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0xeU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0xfU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0xfU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 8U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x10U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x11U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x10U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x11U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x10U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x11U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x10U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x10U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x11U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x11U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 9U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x12U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x13U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x12U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x13U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x12U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x13U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x12U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x12U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x13U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x13U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xaU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x14U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x15U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x14U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x15U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x14U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x15U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x14U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x14U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x15U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x15U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xbU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x16U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x17U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x16U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x17U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x16U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x17U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x16U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x16U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x17U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x17U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xcU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x18U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x19U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x18U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x19U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x18U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x19U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x18U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x18U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x19U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x19U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xdU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x1aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x1bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x1aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x1bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x1aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x1bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x1aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x1aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x1bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x1bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xeU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x1cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x1dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x1cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x1dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x1cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x1dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x1cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x1cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x1dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x1dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xfU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x1eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x1fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x1eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x1fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x1eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x1fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x1eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x1eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x1fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x1fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x10U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x20U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x21U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x20U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x21U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x20U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x21U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x20U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x20U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x21U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x21U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x11U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x22U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x23U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x22U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x23U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x22U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x23U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x22U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x22U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x23U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x23U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x12U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x24U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x25U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x24U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x25U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x24U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x25U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x24U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x24U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x25U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x25U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x13U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x26U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x27U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x26U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x27U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x26U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x27U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x26U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x26U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x27U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x27U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x14U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x28U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x29U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x28U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x29U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x28U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x29U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x28U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x28U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x29U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x29U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x15U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x2aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x2bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x2aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x2bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x2aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x2bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x2aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x2aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x2bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x2bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x16U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x2cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x2dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x2cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x2dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x2cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x2dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x2cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x2cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x2dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x2dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x17U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x2eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x2fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x2eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x2fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x2eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x2fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x2eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x2eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x2fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x2fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x18U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x30U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x31U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x30U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x31U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x30U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x31U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x30U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x30U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x31U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x31U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x19U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x32U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x33U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x32U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x33U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x32U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x33U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x32U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x32U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x33U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x33U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1aU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x34U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x35U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x34U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x35U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x34U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x35U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x34U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x34U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x35U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x35U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1bU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x36U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x37U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x36U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x37U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x36U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x37U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x36U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x36U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x37U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x37U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1cU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x38U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x39U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x38U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x39U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x38U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x39U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x38U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x38U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x39U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x39U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1dU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x3aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x3bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x3aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x3bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x3aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x3bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x3aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x3aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x3bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x3bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1eU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x3cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x3dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x3cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x3dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x3cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x3dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x3cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x3cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x3dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x3dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1fU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x3eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x3fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x3eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x3fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x3eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x3fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x3eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x3eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x3fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x3fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x20U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x40U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x41U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x40U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x41U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x40U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x41U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x20U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x40U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x20U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x40U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x20U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x41U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x20U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x41U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x21U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x42U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x43U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x42U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x43U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x42U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x43U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x21U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x42U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x21U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x42U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x21U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x43U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x21U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x43U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x22U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x44U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x45U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x44U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x45U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x44U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x45U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x22U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x44U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x22U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x44U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x22U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x45U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x22U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x45U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x23U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x46U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x47U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x46U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x47U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x46U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x47U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x23U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x46U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x23U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x46U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x23U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x47U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x23U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x47U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x24U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x48U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x49U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x48U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x49U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x48U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x49U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x24U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x48U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x24U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x48U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x24U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x49U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x24U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x49U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x25U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x4aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x4bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x4aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x4bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x4aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x4bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x25U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x4aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x25U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x4aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x25U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x4bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x25U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x4bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x26U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x4cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x4dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x4cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x4dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x4cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x4dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x26U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x4cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x26U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x4cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x26U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x4dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x26U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x4dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x27U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x4eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x4fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x4eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x4fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x4eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x4fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x27U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x4eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x27U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x4eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x27U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x4fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x27U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x4fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x28U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x50U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x51U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x50U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x51U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x50U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x51U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x28U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x50U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x28U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x50U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x28U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x51U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x28U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x51U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x29U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x52U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x53U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x52U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x53U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x52U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x53U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x29U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x52U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x29U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x52U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x29U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x53U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x29U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x53U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x2aU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x54U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x55U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x54U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x55U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x54U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x55U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x54U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x54U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x55U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x55U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x2bU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x56U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x57U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x56U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x57U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x56U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x57U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x56U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x56U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x57U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x57U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x2cU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x58U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x59U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x58U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x59U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x58U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x59U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x58U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x58U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x59U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x59U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x2dU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x5aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x5bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x5aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x5bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x5aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x5bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x5aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x5aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x5bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x5bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x2eU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x5cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x5dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x5cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x5dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x5cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x5dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x5cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x5cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x5dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x5dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x2fU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x5eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x5fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x5eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x5fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x5eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x5fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x5eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x5eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x2fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x5fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x2fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x5fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x30U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x60U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x61U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x60U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x61U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x60U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x61U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x30U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x60U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x30U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x60U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x30U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x61U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x30U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x61U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x31U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x62U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x63U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x62U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x63U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x62U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x63U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x31U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x62U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x31U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x62U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x31U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x63U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x31U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x63U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x32U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x64U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x65U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x64U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x65U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x64U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x65U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x32U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x64U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x32U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x64U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x32U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x65U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x32U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x65U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x33U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x66U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x67U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x66U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x67U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x66U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x67U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x33U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x66U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x33U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x66U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x33U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x67U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x33U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x67U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x34U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x68U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x69U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x68U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x69U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x68U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x69U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x34U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x68U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x34U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x68U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x34U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x69U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x34U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x69U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x35U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x6aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x6bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x6aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x6bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x6aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x6bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x35U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x6aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x35U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x6aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x35U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x6bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x35U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x6bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x36U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x6cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x6dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x6cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x6dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x6cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x6dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x36U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x6cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x36U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x6cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x36U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x6dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x36U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x6dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x37U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x6eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x6fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x6eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x6fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x6eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x6fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x37U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x6eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x37U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x6eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x37U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x6fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x37U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x6fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x38U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x70U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x71U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x70U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x71U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x70U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x71U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x38U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x70U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x38U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x70U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x38U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x71U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x38U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x71U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x39U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x72U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x73U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x72U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x73U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x72U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x73U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x39U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x72U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x39U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x72U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x39U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x73U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x39U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x73U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x3aU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x74U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x75U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x74U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x75U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x74U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x75U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x74U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x74U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x75U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x75U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x3bU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x76U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x77U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x76U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x77U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x76U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x77U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x76U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x76U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x77U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x77U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x3cU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x78U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x79U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x78U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x79U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x78U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x79U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x78U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x78U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x79U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x79U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x3dU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x7aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x7bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x7aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x7bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x7aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x7bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x7aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x7aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x7bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x7bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x3eU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x7cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x7dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x7cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x7dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x7cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x7dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x7cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x7cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x7dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x7dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x3fU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x7eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
          [0x7fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x7eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
                       [0x7fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x7eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
                                   [0x7fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x7eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x7eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1[0x3fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl0
            [0x7fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1[0x3fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl0
            [0x7fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x40U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [1U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [0U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [1U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [0U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [1U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [1U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [1U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 1U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [2U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [3U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [2U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [3U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [2U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [3U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [2U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [2U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [3U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[1U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [3U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 2U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [4U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [5U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [4U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [5U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [4U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [5U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [4U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [4U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [5U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[2U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [5U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 3U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [6U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [7U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [6U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [7U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [6U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [7U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [6U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [6U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [7U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[3U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [7U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 4U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [8U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [9U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [8U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                    [9U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [8U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                             [9U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [8U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [8U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [9U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[4U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [9U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 5U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0xaU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0xbU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                      [0xaU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                      [0xbU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                 [0xaU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                 [0xbU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0xaU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0xaU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0xbU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[5U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0xbU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 6U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0xcU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0xdU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                      [0xcU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                      [0xdU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                 [0xcU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                 [0xdU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0xcU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0xcU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0xdU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[6U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0xdU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 7U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0xeU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0xfU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                      [0xeU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                      [0xfU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                 [0xeU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                 [0xfU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0xeU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0xeU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0xfU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[7U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0xfU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 8U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x10U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x11U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x10U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x11U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x10U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x11U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x10U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x10U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x11U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[8U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x11U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 9U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x12U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x13U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x12U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x13U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x12U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x13U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x12U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x12U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x13U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[9U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x13U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xaU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x14U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x15U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x14U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x15U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x14U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x15U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x14U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x14U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x15U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xaU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x15U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xbU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x16U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x17U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x16U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x17U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x16U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x17U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x16U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x16U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x17U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xbU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x17U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xcU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x18U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x19U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x18U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x19U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x18U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x19U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x18U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x18U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x19U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xcU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x19U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xdU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x1aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x1bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x1aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x1bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x1aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x1bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x1aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x1aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x1bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xdU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x1bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xeU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x1cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x1dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x1cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x1dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x1cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x1dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x1cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x1cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x1dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xeU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x1dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xfU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x1eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x1fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x1eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x1fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x1eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x1fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x1eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x1eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x1fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0xfU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x1fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x10U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x20U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x21U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x20U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x21U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x20U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x21U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x20U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x20U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x21U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x10U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x21U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x11U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x22U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x23U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x22U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x23U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x22U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x23U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x22U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x22U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x23U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x11U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x23U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x12U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x24U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x25U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x24U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x25U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x24U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x25U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x24U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x24U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x25U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x12U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x25U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x13U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x26U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x27U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x26U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x27U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x26U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x27U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x26U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x26U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x27U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x13U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x27U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x14U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x28U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x29U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x28U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x29U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x28U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x29U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x28U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x28U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x29U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x14U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x29U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x15U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x2aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x2bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x2aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x2bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x2aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x2bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x2aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x2aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x2bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x15U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x2bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x16U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x2cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x2dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x2cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x2dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x2cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x2dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x2cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x2cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x2dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x16U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x2dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x17U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x2eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x2fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x2eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x2fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x2eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x2fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x2eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x2eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x2fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x17U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x2fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x18U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x30U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x31U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x30U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x31U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x30U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x31U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x30U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x30U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x31U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x18U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x31U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x19U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x32U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x33U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x32U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x33U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x32U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x33U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x32U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x32U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x33U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x19U] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x33U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1aU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x34U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x35U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x34U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x35U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x34U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x35U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x34U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x34U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x35U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1aU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x35U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1bU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x36U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x37U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x36U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x37U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x36U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x37U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x36U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x36U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x37U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1bU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x37U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1cU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x38U] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x39U]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x38U] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x39U]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x38U] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x39U])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x38U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x38U];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x39U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1cU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x39U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1dU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x3aU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x3bU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x3aU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x3bU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x3aU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x3bU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x3aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x3aU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x3bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1dU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x3bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1eU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x3cU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x3dU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x3cU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x3dU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x3cU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x3dU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x3cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x3cU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x3dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1eU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x3dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1fU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x3eU] > vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
          [0x3fU]) | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x3eU] == vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
                       [0x3fU]) & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x3eU] < vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
                                   [0x3fU])))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x3eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x3eU];
    } else {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl1
            [0x3fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2[0x1fU] 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl1
            [0x3fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x20U;
    vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r = 
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
        [0U];
    vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r = 
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
        [0U];
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [1U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [1U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [1U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [1U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [1U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 2U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [2U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [2U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [2U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [2U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [2U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 3U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [3U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [3U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [3U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [3U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [3U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 4U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [4U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [4U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [4U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [4U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [4U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 5U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [5U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [5U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [5U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [5U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [5U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 6U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [6U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [6U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [6U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [6U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [6U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 7U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [7U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [7U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [7U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [7U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [7U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 8U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [8U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [8U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [8U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [8U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [8U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 9U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [9U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [9U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [9U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [9U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xaU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0xaU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0xaU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0xaU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0xaU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0xaU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xbU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0xbU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0xbU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0xbU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0xbU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0xbU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xcU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0xcU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0xcU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0xcU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0xcU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0xcU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xdU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0xdU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0xdU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0xdU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0xdU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0xdU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xeU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0xeU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0xeU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0xeU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0xeU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0xeU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0xfU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0xfU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0xfU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0xfU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0xfU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0xfU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x10U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x10U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x10U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x10U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x10U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x10U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x11U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x11U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x11U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x11U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x11U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x11U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x12U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x12U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x12U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x12U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x12U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x12U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x13U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x13U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x13U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x13U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x13U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x13U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x14U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x14U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x14U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x14U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x14U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x14U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x15U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x15U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x15U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x15U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x15U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x15U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x16U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x16U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x16U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x16U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x16U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x16U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x17U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x17U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x17U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x17U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x17U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x17U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x18U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x18U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x18U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x18U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x18U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x18U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x19U;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x19U] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x19U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x19U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x19U];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x19U];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1aU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x1aU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x1aU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x1aU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x1aU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x1aU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1bU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x1bU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x1bU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x1bU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x1bU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x1bU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1cU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x1cU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x1cU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x1cU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x1cU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x1cU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1dU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x1dU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x1dU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x1dU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x1dU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x1dU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1eU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x1eU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x1eU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x1eU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x1eU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x1eU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x1fU;
    if (((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
          [0x1fU] > (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
         | ((vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
             [0x1fU] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r)) 
            & (vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
               [0x1fU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r))))) {
        vlSelfRef.top__DOT__u_pruner__DOT__best_idx_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_idx_lvl2
            [0x1fU];
        vlSelfRef.top__DOT__u_pruner__DOT__best_NO_r 
            = vlSelfRef.top__DOT__u_pruner__DOT__best_NO_lvl2
            [0x1fU];
    }
    vlSelfRef.top__DOT__u_pruner__DOT__i = 0x20U;
    vlSelfRef.top__DOT__det_si_vec[0U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[0U];
    vlSelfRef.top__DOT__det_si_vec[1U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[1U];
    vlSelfRef.top__DOT__det_si_vec[2U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[2U];
    vlSelfRef.top__DOT__det_si_vec[3U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[3U];
    vlSelfRef.top__DOT__det_si_vec[4U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[4U];
    vlSelfRef.top__DOT__det_si_vec[5U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[5U];
    vlSelfRef.top__DOT__det_si_vec[6U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[6U];
    vlSelfRef.top__DOT__det_si_vec[7U] = vlSelfRef.top__DOT__u_detector__DOT__si_vec[7U];
    vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0U;
    vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 0U;
    if ((1U & ((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
               & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 1U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 1U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 2U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 2U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 3U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 3U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 4U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 4U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 5U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 5U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 6U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 6U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 7U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 7U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 8U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 8U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 9U) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 9U;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 0xaU) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0xaU;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 0xbU) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0xbU;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 0xcU) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0xcU;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 0xdU) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0xdU;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((1U & (((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                >> 0xeU) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0xeU;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    if ((IData)((((IData)(vlSelfRef.top__DOT__u_processor__DOT__pattern_working) 
                  >> 0xfU) & (~ (IData)(vlSelfRef.top__DOT__u_processor__DOT__spike_valid))))) {
        vlSelfRef.top__DOT__u_processor__DOT__current_spike_idx = 0xfU;
        vlSelfRef.top__DOT__u_processor__DOT__spike_valid = 1U;
    }
    vlSelfRef.dbg_det_ready = (((0U == (IData)(vlSelfRef.top__DOT__u_detector__DOT__state)) 
                                | ((~ (IData)(vlSelfRef.top__DOT__u_detector__DOT__query_in_progress)) 
                                   & (2U == (IData)(vlSelfRef.top__DOT__u_detector__DOT__state)))) 
                               & ((IData)(vlSelfRef.top__DOT__u_detector__DOT__initialized) 
                                  & (IData)(vlSelfRef.top__DOT__u_detector__DOT__popcounts_calculated)));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0U] 
        = (0xffU & vlSelfRef.weight_data[0U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[1U] 
        = (0xffU & (vlSelfRef.weight_data[0U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[2U] 
        = (0xffU & (vlSelfRef.weight_data[0U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[3U] 
        = (vlSelfRef.weight_data[0U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[4U] 
        = (0xffU & vlSelfRef.weight_data[1U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[5U] 
        = (0xffU & (vlSelfRef.weight_data[1U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[6U] 
        = (0xffU & (vlSelfRef.weight_data[1U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[7U] 
        = (vlSelfRef.weight_data[1U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[8U] 
        = (0xffU & vlSelfRef.weight_data[2U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[9U] 
        = (0xffU & (vlSelfRef.weight_data[2U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0xaU] 
        = (0xffU & (vlSelfRef.weight_data[2U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0xbU] 
        = (vlSelfRef.weight_data[2U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0xcU] 
        = (0xffU & vlSelfRef.weight_data[3U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0xdU] 
        = (0xffU & (vlSelfRef.weight_data[3U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0xeU] 
        = (0xffU & (vlSelfRef.weight_data[3U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0xfU] 
        = (vlSelfRef.weight_data[3U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x10U] 
        = (0xffU & vlSelfRef.weight_data[4U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x11U] 
        = (0xffU & (vlSelfRef.weight_data[4U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x12U] 
        = (0xffU & (vlSelfRef.weight_data[4U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x13U] 
        = (vlSelfRef.weight_data[4U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x14U] 
        = (0xffU & vlSelfRef.weight_data[5U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x15U] 
        = (0xffU & (vlSelfRef.weight_data[5U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x16U] 
        = (0xffU & (vlSelfRef.weight_data[5U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x17U] 
        = (vlSelfRef.weight_data[5U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x18U] 
        = (0xffU & vlSelfRef.weight_data[6U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x19U] 
        = (0xffU & (vlSelfRef.weight_data[6U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x1aU] 
        = (0xffU & (vlSelfRef.weight_data[6U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x1bU] 
        = (vlSelfRef.weight_data[6U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x1cU] 
        = (0xffU & vlSelfRef.weight_data[7U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x1dU] 
        = (0xffU & (vlSelfRef.weight_data[7U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x1eU] 
        = (0xffU & (vlSelfRef.weight_data[7U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x1fU] 
        = (vlSelfRef.weight_data[7U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x20U] 
        = (0xffU & vlSelfRef.weight_data[8U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x21U] 
        = (0xffU & (vlSelfRef.weight_data[8U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x22U] 
        = (0xffU & (vlSelfRef.weight_data[8U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x23U] 
        = (vlSelfRef.weight_data[8U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x24U] 
        = (0xffU & vlSelfRef.weight_data[9U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x25U] 
        = (0xffU & (vlSelfRef.weight_data[9U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x26U] 
        = (0xffU & (vlSelfRef.weight_data[9U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x27U] 
        = (vlSelfRef.weight_data[9U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x28U] 
        = (0xffU & vlSelfRef.weight_data[0xaU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x29U] 
        = (0xffU & (vlSelfRef.weight_data[0xaU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x2aU] 
        = (0xffU & (vlSelfRef.weight_data[0xaU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x2bU] 
        = (vlSelfRef.weight_data[0xaU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x2cU] 
        = (0xffU & vlSelfRef.weight_data[0xbU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x2dU] 
        = (0xffU & (vlSelfRef.weight_data[0xbU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x2eU] 
        = (0xffU & (vlSelfRef.weight_data[0xbU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x2fU] 
        = (vlSelfRef.weight_data[0xbU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x30U] 
        = (0xffU & vlSelfRef.weight_data[0xcU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x31U] 
        = (0xffU & (vlSelfRef.weight_data[0xcU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x32U] 
        = (0xffU & (vlSelfRef.weight_data[0xcU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x33U] 
        = (vlSelfRef.weight_data[0xcU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x34U] 
        = (0xffU & vlSelfRef.weight_data[0xdU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x35U] 
        = (0xffU & (vlSelfRef.weight_data[0xdU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x36U] 
        = (0xffU & (vlSelfRef.weight_data[0xdU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x37U] 
        = (vlSelfRef.weight_data[0xdU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x38U] 
        = (0xffU & vlSelfRef.weight_data[0xeU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x39U] 
        = (0xffU & (vlSelfRef.weight_data[0xeU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x3aU] 
        = (0xffU & (vlSelfRef.weight_data[0xeU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x3bU] 
        = (vlSelfRef.weight_data[0xeU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x3cU] 
        = (0xffU & vlSelfRef.weight_data[0xfU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x3dU] 
        = (0xffU & (vlSelfRef.weight_data[0xfU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x3eU] 
        = (0xffU & (vlSelfRef.weight_data[0xfU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x3fU] 
        = (vlSelfRef.weight_data[0xfU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x40U] 
        = (0xffU & vlSelfRef.weight_data[0x10U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x41U] 
        = (0xffU & (vlSelfRef.weight_data[0x10U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x42U] 
        = (0xffU & (vlSelfRef.weight_data[0x10U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x43U] 
        = (vlSelfRef.weight_data[0x10U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x44U] 
        = (0xffU & vlSelfRef.weight_data[0x11U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x45U] 
        = (0xffU & (vlSelfRef.weight_data[0x11U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x46U] 
        = (0xffU & (vlSelfRef.weight_data[0x11U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x47U] 
        = (vlSelfRef.weight_data[0x11U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x48U] 
        = (0xffU & vlSelfRef.weight_data[0x12U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x49U] 
        = (0xffU & (vlSelfRef.weight_data[0x12U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x4aU] 
        = (0xffU & (vlSelfRef.weight_data[0x12U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x4bU] 
        = (vlSelfRef.weight_data[0x12U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x4cU] 
        = (0xffU & vlSelfRef.weight_data[0x13U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x4dU] 
        = (0xffU & (vlSelfRef.weight_data[0x13U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x4eU] 
        = (0xffU & (vlSelfRef.weight_data[0x13U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x4fU] 
        = (vlSelfRef.weight_data[0x13U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x50U] 
        = (0xffU & vlSelfRef.weight_data[0x14U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x51U] 
        = (0xffU & (vlSelfRef.weight_data[0x14U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x52U] 
        = (0xffU & (vlSelfRef.weight_data[0x14U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x53U] 
        = (vlSelfRef.weight_data[0x14U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x54U] 
        = (0xffU & vlSelfRef.weight_data[0x15U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x55U] 
        = (0xffU & (vlSelfRef.weight_data[0x15U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x56U] 
        = (0xffU & (vlSelfRef.weight_data[0x15U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x57U] 
        = (vlSelfRef.weight_data[0x15U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x58U] 
        = (0xffU & vlSelfRef.weight_data[0x16U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x59U] 
        = (0xffU & (vlSelfRef.weight_data[0x16U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x5aU] 
        = (0xffU & (vlSelfRef.weight_data[0x16U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x5bU] 
        = (vlSelfRef.weight_data[0x16U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x5cU] 
        = (0xffU & vlSelfRef.weight_data[0x17U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x5dU] 
        = (0xffU & (vlSelfRef.weight_data[0x17U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x5eU] 
        = (0xffU & (vlSelfRef.weight_data[0x17U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x5fU] 
        = (vlSelfRef.weight_data[0x17U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x60U] 
        = (0xffU & vlSelfRef.weight_data[0x18U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x61U] 
        = (0xffU & (vlSelfRef.weight_data[0x18U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x62U] 
        = (0xffU & (vlSelfRef.weight_data[0x18U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x63U] 
        = (vlSelfRef.weight_data[0x18U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x64U] 
        = (0xffU & vlSelfRef.weight_data[0x19U]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x65U] 
        = (0xffU & (vlSelfRef.weight_data[0x19U] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x66U] 
        = (0xffU & (vlSelfRef.weight_data[0x19U] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x67U] 
        = (vlSelfRef.weight_data[0x19U] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x68U] 
        = (0xffU & vlSelfRef.weight_data[0x1aU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x69U] 
        = (0xffU & (vlSelfRef.weight_data[0x1aU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x6aU] 
        = (0xffU & (vlSelfRef.weight_data[0x1aU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x6bU] 
        = (vlSelfRef.weight_data[0x1aU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x6cU] 
        = (0xffU & vlSelfRef.weight_data[0x1bU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x6dU] 
        = (0xffU & (vlSelfRef.weight_data[0x1bU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x6eU] 
        = (0xffU & (vlSelfRef.weight_data[0x1bU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x6fU] 
        = (vlSelfRef.weight_data[0x1bU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x70U] 
        = (0xffU & vlSelfRef.weight_data[0x1cU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x71U] 
        = (0xffU & (vlSelfRef.weight_data[0x1cU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x72U] 
        = (0xffU & (vlSelfRef.weight_data[0x1cU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x73U] 
        = (vlSelfRef.weight_data[0x1cU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x74U] 
        = (0xffU & vlSelfRef.weight_data[0x1dU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x75U] 
        = (0xffU & (vlSelfRef.weight_data[0x1dU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x76U] 
        = (0xffU & (vlSelfRef.weight_data[0x1dU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x77U] 
        = (vlSelfRef.weight_data[0x1dU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x78U] 
        = (0xffU & vlSelfRef.weight_data[0x1eU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x79U] 
        = (0xffU & (vlSelfRef.weight_data[0x1eU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x7aU] 
        = (0xffU & (vlSelfRef.weight_data[0x1eU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x7bU] 
        = (vlSelfRef.weight_data[0x1eU] >> 0x18U);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x7cU] 
        = (0xffU & vlSelfRef.weight_data[0x1fU]);
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x7dU] 
        = (0xffU & (vlSelfRef.weight_data[0x1fU] >> 8U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x7eU] 
        = (0xffU & (vlSelfRef.weight_data[0x1fU] >> 0x10U));
    vlSelfRef.top__DOT__u_processor__DOT__pe_weight[0x7fU] 
        = (vlSelfRef.weight_data[0x1fU] >> 0x18U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xcU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xdU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xeU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xeU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xfU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x10U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x10U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x11U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x11U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x12U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x12U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x13U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x13U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x14U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x14U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x15U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x15U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x16U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x16U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x17U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x17U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x18U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x18U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x19U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x19U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x1aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x1bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x1cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x1dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x1eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x1fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x20U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x20U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x21U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x21U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x22U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x22U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x23U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x23U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x24U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x24U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x25U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x25U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x26U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x26U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x27U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x27U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x28U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x28U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x29U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x29U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x2aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x2bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x2cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x2dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x2eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x2fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x30U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x30U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x31U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x31U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x32U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x32U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x33U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x33U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x34U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x34U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x35U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x35U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x36U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x36U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x37U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x37U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x38U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x38U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x39U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x39U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x3aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x3bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x3cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x3dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x3eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x3fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x40U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x40U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x41U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x41U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x42U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x42U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x43U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x43U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x44U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x44U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x45U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x45U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x46U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x46U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x47U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x47U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x48U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x48U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x49U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x49U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x4aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x4bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x4cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x4dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x4eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x4fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x50U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x50U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x51U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x51U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x52U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x52U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x53U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x53U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x54U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x54U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x55U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x55U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x56U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x56U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x57U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x57U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x58U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x58U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x59U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x59U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x5aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x5bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x5cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x5dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x5eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x5fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x60U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x60U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x61U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x61U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x62U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x62U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x63U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x63U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x64U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x64U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x65U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x65U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x66U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x66U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x67U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x67U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x68U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x68U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x69U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x69U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x6aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x6bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x6cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x6dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x6eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x6fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x70U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x70U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x71U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x71U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x72U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x72U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x73U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x73U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x74U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x74U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x75U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x75U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x76U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x76U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x77U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x77U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x78U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x78U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x79U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x79U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x7aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x7bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x7cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x7dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x7eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x7fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x80U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x80U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x81U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x81U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x82U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x82U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x83U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x83U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x84U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x84U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x85U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x85U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x86U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x86U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x87U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x87U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x88U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x88U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x89U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x89U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x8aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x8bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x8cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x8dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x8eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x8fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x90U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x90U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x91U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x91U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x92U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x92U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x93U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x93U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x94U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x94U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x95U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x95U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x96U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x96U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x97U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x97U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x98U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x98U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x99U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x99U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x9aU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9aU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x9bU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9bU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x9cU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9cU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x9dU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9dU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x9eU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9eU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0x9fU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9fU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xa9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xaaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xaaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xabU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xabU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xacU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xacU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xadU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xadU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xaeU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xaeU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xafU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xafU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xb9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbbU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbbU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbcU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbcU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbdU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbdU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbeU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbeU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xbfU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbfU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xc9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xcaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xcbU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcbU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xccU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xccU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xcdU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcdU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xceU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xceU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xcfU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcfU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xd9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xdaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xdbU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdbU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xdcU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdcU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xddU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xddU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xdeU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdeU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xdfU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdfU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xe9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xeaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xeaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xebU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xebU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xecU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xecU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xedU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xedU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xeeU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xeeU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xefU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xefU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf0U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf0U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf1U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf1U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf2U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf2U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf3U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf3U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf4U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf4U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf5U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf5U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf6U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf6U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf7U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf7U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf8U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf8U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xf9U] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf9U]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xfaU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfaU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xfbU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfbU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xfcU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfcU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xfdU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfdU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xfeU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfeU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__key[0xffU] 
        = (0xffffU & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xffU]);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xcU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xdU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xeU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xeU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xfU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x10U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x10U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x11U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x11U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x12U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x12U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x13U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x13U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x14U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x14U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x15U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x15U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x16U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x16U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x17U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x17U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x18U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x18U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x19U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x19U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x1aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x1bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x1cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x1dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x1eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x1fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x1fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x20U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x20U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x21U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x21U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x22U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x22U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x23U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x23U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x24U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x24U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x25U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x25U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x26U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x26U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x27U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x27U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x28U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x28U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x29U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x29U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x2aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x2bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x2cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x2dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x2eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x2fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x2fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x30U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x30U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x31U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x31U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x32U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x32U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x33U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x33U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x34U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x34U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x35U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x35U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x36U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x36U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x37U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x37U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x38U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x38U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x39U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x39U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x3aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x3bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x3cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x3dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x3eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x3fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x3fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x40U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x40U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x41U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x41U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x42U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x42U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x43U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x43U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x44U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x44U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x45U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x45U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x46U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x46U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x47U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x47U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x48U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x48U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x49U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x49U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x4aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x4bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x4cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x4dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x4eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x4fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x4fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x50U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x50U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x51U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x51U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x52U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x52U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x53U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x53U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x54U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x54U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x55U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x55U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x56U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x56U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x57U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x57U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x58U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x58U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x59U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x59U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x5aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x5bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x5cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x5dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x5eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x5fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x5fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x60U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x60U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x61U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x61U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x62U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x62U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x63U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x63U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x64U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x64U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x65U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x65U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x66U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x66U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x67U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x67U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x68U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x68U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x69U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x69U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x6aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x6bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x6cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x6dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x6eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x6fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x6fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x70U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x70U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x71U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x71U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x72U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x72U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x73U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x73U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x74U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x74U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x75U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x75U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x76U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x76U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x77U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x77U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x78U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x78U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x79U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x79U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x7aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x7bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x7cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x7dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x7eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x7fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x7fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x80U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x80U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x81U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x81U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x82U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x82U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x83U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x83U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x84U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x84U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x85U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x85U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x86U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x86U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x87U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x87U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x88U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x88U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x89U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x89U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x8aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x8bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x8cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x8dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x8eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x8fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x8fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x90U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x90U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x91U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x91U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x92U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x92U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x93U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x93U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x94U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x94U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x95U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x95U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x96U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x96U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x97U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x97U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x98U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x98U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x99U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x99U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x9aU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9aU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x9bU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9bU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x9cU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9cU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x9dU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9dU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x9eU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9eU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0x9fU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0x9fU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xa9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xa9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xaaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xaaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xabU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xabU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xacU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xacU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xadU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xadU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xaeU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xaeU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xafU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xafU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xb9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xb9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbbU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbbU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbcU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbcU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbdU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbdU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbeU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbeU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xbfU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xbfU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xc9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xc9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xcaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xcbU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcbU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xccU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xccU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xcdU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcdU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xceU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xceU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xcfU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xcfU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xd9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xd9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xdaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xdbU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdbU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xdcU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdcU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xddU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xddU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xdeU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdeU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xdfU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xdfU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xe9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xe9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xeaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xeaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xebU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xebU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xecU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xecU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xedU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xedU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xeeU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xeeU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xefU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xefU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf0U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf0U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf1U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf1U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf2U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf2U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf3U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf3U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf4U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf4U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf5U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf5U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf6U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf6U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf7U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf7U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf8U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf8U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xf9U] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xf9U] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xfaU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfaU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xfbU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfbU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xfcU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfcU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xfdU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfdU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xfeU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xfeU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__xmask[0xffU] 
        = (vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem
           [0xffU] >> 0x10U);
    vlSelfRef.top__DOT__u_detector__DOT__tile_mem_addr 
        = vlSelfRef.top__DOT__tile_mem_addr;
    vlSelfRef.top__DOT__u_detector__DOT__popcount_mem_addr 
        = vlSelfRef.top__DOT__pc_mem_addr;
    vlSelfRef.top__DOT__u_detector__DOT__popcount_mem_data_in 
        = vlSelfRef.top__DOT__pc_mem_data_in;
    vlSelfRef.top__DOT__u_detector__DOT__popcount_mem_wr_en 
        = vlSelfRef.top__DOT__pc_mem_wr_en;
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0U] 
        = vlSelfRef.top__DOT__weight_data[0U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[1U] 
        = vlSelfRef.top__DOT__weight_data[1U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[2U] 
        = vlSelfRef.top__DOT__weight_data[2U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[3U] 
        = vlSelfRef.top__DOT__weight_data[3U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[4U] 
        = vlSelfRef.top__DOT__weight_data[4U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[5U] 
        = vlSelfRef.top__DOT__weight_data[5U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[6U] 
        = vlSelfRef.top__DOT__weight_data[6U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[7U] 
        = vlSelfRef.top__DOT__weight_data[7U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[8U] 
        = vlSelfRef.top__DOT__weight_data[8U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[9U] 
        = vlSelfRef.top__DOT__weight_data[9U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0xaU] 
        = vlSelfRef.top__DOT__weight_data[0xaU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0xbU] 
        = vlSelfRef.top__DOT__weight_data[0xbU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0xcU] 
        = vlSelfRef.top__DOT__weight_data[0xcU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0xdU] 
        = vlSelfRef.top__DOT__weight_data[0xdU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0xeU] 
        = vlSelfRef.top__DOT__weight_data[0xeU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0xfU] 
        = vlSelfRef.top__DOT__weight_data[0xfU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x10U] 
        = vlSelfRef.top__DOT__weight_data[0x10U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x11U] 
        = vlSelfRef.top__DOT__weight_data[0x11U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x12U] 
        = vlSelfRef.top__DOT__weight_data[0x12U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x13U] 
        = vlSelfRef.top__DOT__weight_data[0x13U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x14U] 
        = vlSelfRef.top__DOT__weight_data[0x14U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x15U] 
        = vlSelfRef.top__DOT__weight_data[0x15U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x16U] 
        = vlSelfRef.top__DOT__weight_data[0x16U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x17U] 
        = vlSelfRef.top__DOT__weight_data[0x17U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x18U] 
        = vlSelfRef.top__DOT__weight_data[0x18U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x19U] 
        = vlSelfRef.top__DOT__weight_data[0x19U];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x1aU] 
        = vlSelfRef.top__DOT__weight_data[0x1aU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x1bU] 
        = vlSelfRef.top__DOT__weight_data[0x1bU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x1cU] 
        = vlSelfRef.top__DOT__weight_data[0x1cU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x1dU] 
        = vlSelfRef.top__DOT__weight_data[0x1dU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x1eU] 
        = vlSelfRef.top__DOT__weight_data[0x1eU];
    vlSelfRef.top__DOT__u_processor__DOT__weight_data[0x1fU] 
        = vlSelfRef.top__DOT__weight_data[0x1fU];
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        vlSelfRef.top__DOT__u_processor__DOT__output_rd_data[__Vilp2] 
            = vlSelfRef.top__DOT__output_rd_data[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__rst 
        = vlSelfRef.top__DOT__u_detector__DOT__rst;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__set_valid 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_set_valid;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__set_clr 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_set_clr;
    vlSelfRef.top__DOT__ppu_busy = vlSelfRef.ppu_busy;
    vlSelfRef.top__DOT__dbg_state = vlSelfRef.dbg_state;
    vlSelfRef.top__DOT__u_pruner__DOT__si_valid = vlSelfRef.top__DOT__det_si_valid;
    vlSelfRef.top__DOT__u_processor__DOT__task_row_id 
        = vlSelfRef.top__DOT__task_row_id;
    vlSelfRef.top__DOT__u_processor__DOT__task_prefix_id 
        = vlSelfRef.top__DOT__task_prefix_id;
    vlSelfRef.top__DOT__u_processor__DOT__task_pattern 
        = vlSelfRef.top__DOT__task_pattern;
    vlSelfRef.top__DOT__u_processor__DOT__proc_done 
        = vlSelfRef.top__DOT__proc_done;
    vlSelfRef.top__DOT__u_pruner__DOT__row_NO = vlSelfRef.top__DOT__det_row_pc;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_idx 
        = vlSelfRef.top__DOT__prn_row_id;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_prefix_id 
        = vlSelfRef.top__DOT__prn_prefix_id;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_pattern 
        = vlSelfRef.top__DOT__prn_pattern;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__req_valid 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_req_valid;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__set_addr 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_addr;
    vlSelfRef.top__DOT__u_pruner__DOT__mem_wr_en = vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_wr_en;
    vlSelfRef.top__DOT__u_detector__DOT__query_pattern 
        = vlSelfRef.top__DOT____Vcellinp__u_detector__query_pattern;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__set_key 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_key;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__set_xmask 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_xmask;
    vlSelfRef.top__DOT__u_detector__DOT__tile_mem_data_in 
        = vlSelfRef.top__DOT__tile_mem_data_in;
    vlSelfRef.top__DOT__u_pruner__DOT__mem_spike_in 
        = vlSelfRef.top__DOT__tile_mem_data_in;
    vlSelfRef.top__DOT__u_detector__DOT__tile_mem_wr_en 
        = vlSelfRef.top__DOT__tile_mem_wr_en;
    vlSelfRef.top__DOT__u_pruner__DOT__mem_sel = vlSelfRef.top__DOT__tile_mem_wr_en;
    vlSelfRef.top__DOT__u_pruner__DOT__mem_NO_in = vlSelfRef.top__DOT____Vcellinp__u_pruner__mem_NO_in;
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        vlSelfRef.top__DOT__output_wr_data[__Vilp3] 
            = vlSelfRef.output_wr_data[__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x3fU)) {
        vlSelfRef.top__DOT__u_processor__DOT__output_wr_data[__Vilp4] 
            = vlSelfRef.output_wr_data[__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    vlSelfRef.top__DOT__u_pruner__DOT__rst_n = vlSelfRef.top__DOT__rst_n;
    vlSelfRef.top__DOT__u_dispatcher__DOT__rst_n = vlSelfRef.top__DOT__rst_n;
    vlSelfRef.top__DOT__u_processor__DOT__rst_n = vlSelfRef.top__DOT__rst_n;
    vlSelfRef.top__DOT__dbg_proc_busy = vlSelfRef.dbg_proc_busy;
    vlSelfRef.top__DOT__proc_busy = vlSelfRef.dbg_proc_busy;
    vlSelfRef.top__DOT__u_processor__DOT__proc_busy 
        = vlSelfRef.dbg_proc_busy;
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[0U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0x1fU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x1fU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x1fU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0x1fU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x1fU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x1fU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0x1fU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0x1eU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0x1eU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x1eU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0x1eU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x1eU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x1eU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0x1eU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x1dU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x1dU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x1dU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x1dU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x1dU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x1dU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x1dU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x1cU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x1cU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x1cU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x1cU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x1cU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x1cU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x1cU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x1bU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x1bU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x1bU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x1bU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x1bU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x1bU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x1bU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x1aU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x1aU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x1aU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x1aU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x1aU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x1aU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x1aU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x19U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x19U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x19U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x19U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x19U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x19U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x19U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x18U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x18U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x18U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x18U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x18U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x18U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x18U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x17U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x17U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x17U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x17U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x17U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x17U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x17U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x16U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x16U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x16U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x16U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x16U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x16U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x16U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x15U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x15U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x15U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x15U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x15U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x15U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x15U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x14U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x14U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x14U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x14U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x14U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x14U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x14U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x13U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x13U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x13U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x13U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x13U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x13U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x13U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x12U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x12U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x12U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x12U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x12U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x12U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x12U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x11U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x11U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x11U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x11U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x11U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x11U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x11U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0x10U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x10U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x10U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0x10U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x10U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x10U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0x10U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xfU]) & (((
                                                   vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                   [0xfU] 
                                                   < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                  & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xfU] 
                                                      & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                     == 
                                                     vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0xfU])) 
                                                 | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [0xfU] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [0xfU] 
                                                        == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       & (0xfU 
                                                          < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xeU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xeU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xeU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xeU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xeU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xeU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xeU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xdU]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [0xdU] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [0xdU] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xdU])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [0xdU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [0xdU] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (0xdU 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xcU]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [0xcU] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [0xcU] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xcU])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [0xcU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [0xcU] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (0xcU 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xbU]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [0xbU] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [0xbU] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xbU])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [0xbU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [0xbU] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (0xbU 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xaU]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [0xaU] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [0xaU] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xaU])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [0xaU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [0xaU] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (0xaU 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [9U]) & (((
                                                   vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                   [9U] 
                                                   < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                  & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [9U] 
                                                      & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                     == 
                                                     vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [9U])) 
                                                 | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [9U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [9U] 
                                                        == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       & (9U 
                                                          < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [8U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [8U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [8U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [8U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [8U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [8U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (8U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [7U]) & (((
                                                   vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                   [7U] 
                                                   < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                  & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [7U] 
                                                      & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                     == 
                                                     vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [7U])) 
                                                 | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [7U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [7U] 
                                                        == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       & (7U 
                                                          < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [6U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [6U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [6U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [6U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [6U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [6U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (6U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [5U]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [5U] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [5U] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [5U])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [5U] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [5U] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (5U 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [4U]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [4U] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [4U] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [4U])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [4U] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [4U] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (4U 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [3U]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [3U] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [3U] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [3U])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [3U] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [3U] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (3U 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [2U]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [2U] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [2U] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [2U])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [2U] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [2U] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (2U 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [1U]) & (
                                                   ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                     [1U] 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                        [1U] 
                                                        & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                       == 
                                                       vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [1U])) 
                                                   | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                       [1U] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                      & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                          [1U] 
                                                          == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                         & (1U 
                                                            < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[0U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                     [0U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                    & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                        [0U] & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                       == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                       [0U])) | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[1U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0x3fU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x3fU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x3fU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0x3fU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x3fU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x3fU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0x3fU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0x3eU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0x3eU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x3eU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0x3eU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x3eU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x3eU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0x3eU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x3dU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x3dU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x3dU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x3dU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x3dU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x3dU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x3dU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x3cU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x3cU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x3cU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x3cU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x3cU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x3cU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x3cU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x3bU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x3bU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x3bU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x3bU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x3bU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x3bU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x3bU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x3aU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x3aU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x3aU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x3aU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x3aU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x3aU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x3aU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x39U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x39U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x39U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x39U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x39U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x39U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x39U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x38U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x38U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x38U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x38U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x38U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x38U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x38U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x37U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x37U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x37U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x37U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x37U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x37U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x37U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x36U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x36U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x36U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x36U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x36U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x36U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x36U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x35U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x35U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x35U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x35U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x35U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x35U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x35U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x34U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x34U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x34U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x34U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x34U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x34U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x34U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x33U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x33U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x33U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x33U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x33U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x33U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x33U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x32U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x32U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x32U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x32U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x32U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x32U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x32U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x31U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x31U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x31U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x31U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x31U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x31U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x31U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0x30U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x30U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x30U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0x30U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x30U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x30U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0x30U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x2fU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x2fU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x2fU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x2fU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x2fU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x2fU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x2fU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x2eU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x2eU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x2eU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x2eU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x2eU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x2eU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x2eU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x2dU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x2dU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x2dU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x2dU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x2dU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x2dU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x2dU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x2cU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x2cU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x2cU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x2cU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x2cU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x2cU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x2cU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x2bU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x2bU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x2bU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x2bU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x2bU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x2bU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x2bU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x2aU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x2aU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x2aU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x2aU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x2aU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x2aU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x2aU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x29U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x29U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x29U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x29U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x29U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x29U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x29U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x28U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x28U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x28U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x28U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x28U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x28U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x28U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x27U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x27U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x27U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x27U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x27U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x27U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x27U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x26U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x26U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x26U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x26U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x26U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x26U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x26U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x25U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x25U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x25U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x25U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x25U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x25U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x25U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x24U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x24U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x24U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x24U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x24U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x24U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x24U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x23U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x23U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x23U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x23U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x23U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x23U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x23U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x22U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x22U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x22U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x22U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x22U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x22U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x22U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x21U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x21U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x21U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x21U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x21U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x21U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x21U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[1U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0x20U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0x20U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0x20U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0x20U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x20U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x20U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0x20U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[2U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0x5fU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x5fU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x5fU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0x5fU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x5fU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x5fU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0x5fU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0x5eU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0x5eU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x5eU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0x5eU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x5eU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x5eU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0x5eU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x5dU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x5dU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x5dU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x5dU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x5dU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x5dU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x5dU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x5cU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x5cU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x5cU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x5cU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x5cU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x5cU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x5cU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x5bU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x5bU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x5bU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x5bU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x5bU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x5bU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x5bU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x5aU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x5aU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x5aU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x5aU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x5aU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x5aU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x5aU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x59U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x59U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x59U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x59U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x59U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x59U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x59U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x58U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x58U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x58U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x58U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x58U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x58U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x58U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x57U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x57U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x57U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x57U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x57U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x57U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x57U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x56U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x56U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x56U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x56U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x56U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x56U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x56U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x55U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x55U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x55U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x55U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x55U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x55U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x55U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x54U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x54U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x54U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x54U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x54U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x54U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x54U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x53U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x53U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x53U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x53U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x53U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x53U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x53U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x52U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x52U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x52U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x52U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x52U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x52U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x52U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x51U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x51U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x51U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x51U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x51U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x51U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x51U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0x50U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x50U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x50U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0x50U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x50U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x50U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0x50U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x4fU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x4fU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x4fU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x4fU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x4fU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x4fU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x4fU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x4eU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x4eU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x4eU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x4eU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x4eU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x4eU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x4eU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x4dU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x4dU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x4dU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x4dU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x4dU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x4dU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x4dU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x4cU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x4cU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x4cU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x4cU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x4cU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x4cU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x4cU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x4bU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x4bU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x4bU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x4bU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x4bU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x4bU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x4bU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x4aU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x4aU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x4aU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x4aU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x4aU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x4aU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x4aU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x49U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x49U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x49U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x49U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x49U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x49U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x49U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x48U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x48U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x48U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x48U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x48U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x48U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x48U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x47U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x47U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x47U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x47U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x47U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x47U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x47U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x46U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x46U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x46U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x46U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x46U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x46U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x46U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x45U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x45U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x45U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x45U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x45U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x45U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x45U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x44U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x44U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x44U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x44U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x44U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x44U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x44U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x43U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x43U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x43U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x43U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x43U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x43U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x43U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x42U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x42U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x42U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x42U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x42U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x42U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x42U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x41U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x41U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x41U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x41U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x41U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x41U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x41U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[2U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0x40U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0x40U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0x40U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0x40U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x40U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x40U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0x40U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[3U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0x7fU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x7fU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x7fU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0x7fU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x7fU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x7fU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0x7fU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0x7eU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0x7eU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x7eU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0x7eU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x7eU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x7eU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0x7eU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x7dU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x7dU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x7dU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x7dU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x7dU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x7dU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x7dU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x7cU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x7cU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x7cU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x7cU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x7cU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x7cU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x7cU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x7bU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x7bU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x7bU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x7bU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x7bU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x7bU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x7bU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x7aU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x7aU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x7aU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x7aU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x7aU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x7aU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x7aU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x79U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x79U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x79U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x79U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x79U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x79U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x79U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x78U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x78U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x78U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x78U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x78U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x78U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x78U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x77U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x77U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x77U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x77U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x77U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x77U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x77U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x76U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x76U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x76U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x76U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x76U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x76U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x76U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x75U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x75U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x75U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x75U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x75U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x75U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x75U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x74U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x74U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x74U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x74U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x74U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x74U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x74U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x73U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x73U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x73U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x73U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x73U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x73U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x73U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x72U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x72U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x72U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x72U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x72U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x72U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x72U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x71U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x71U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x71U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x71U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x71U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x71U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x71U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0x70U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x70U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x70U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0x70U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x70U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x70U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0x70U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x6fU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x6fU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x6fU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x6fU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x6fU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x6fU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x6fU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x6eU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x6eU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x6eU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x6eU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x6eU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x6eU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x6eU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x6dU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x6dU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x6dU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x6dU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x6dU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x6dU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x6dU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x6cU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x6cU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x6cU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x6cU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x6cU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x6cU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x6cU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x6bU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x6bU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x6bU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x6bU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x6bU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x6bU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x6bU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x6aU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x6aU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x6aU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x6aU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x6aU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x6aU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x6aU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x69U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x69U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x69U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x69U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x69U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x69U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x69U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x68U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x68U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x68U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x68U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x68U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x68U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x68U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x67U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x67U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x67U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x67U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x67U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x67U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x67U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x66U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x66U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x66U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x66U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x66U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x66U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x66U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x65U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x65U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x65U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x65U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x65U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x65U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x65U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x64U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x64U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x64U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x64U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x64U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x64U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x64U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x63U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x63U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x63U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x63U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x63U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x63U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x63U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x62U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x62U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x62U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x62U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x62U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x62U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x62U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x61U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x61U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x61U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x61U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x61U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x61U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x61U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[3U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0x60U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0x60U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0x60U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0x60U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x60U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x60U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0x60U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[4U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0x9fU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x9fU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x9fU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0x9fU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x9fU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x9fU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0x9fU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0x9eU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0x9eU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x9eU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0x9eU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x9eU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x9eU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0x9eU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x9dU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x9dU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x9dU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x9dU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x9dU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x9dU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x9dU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x9cU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x9cU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x9cU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x9cU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x9cU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x9cU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x9cU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x9bU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x9bU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x9bU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x9bU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x9bU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x9bU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x9bU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x9aU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x9aU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x9aU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x9aU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x9aU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x9aU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x9aU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x99U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x99U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x99U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x99U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x99U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x99U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x99U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x98U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x98U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x98U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x98U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x98U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x98U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x98U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x97U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x97U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x97U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x97U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x97U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x97U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x97U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0x96U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0x96U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0x96U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x96U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0x96U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0x96U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0x96U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x95U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x95U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x95U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x95U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x95U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x95U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x95U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x94U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x94U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x94U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x94U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x94U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x94U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x94U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x93U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x93U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x93U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x93U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x93U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x93U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x93U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x92U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x92U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x92U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x92U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x92U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x92U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x92U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x91U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x91U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x91U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x91U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x91U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x91U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x91U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0x90U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x90U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x90U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0x90U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0x90U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0x90U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0x90U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0x8fU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0x8fU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0x8fU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0x8fU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0x8fU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0x8fU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0x8fU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x8eU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x8eU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x8eU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x8eU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x8eU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x8eU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x8eU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x8dU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x8dU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x8dU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x8dU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x8dU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x8dU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x8dU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x8cU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x8cU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x8cU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x8cU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x8cU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x8cU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x8cU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x8bU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x8bU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x8bU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x8bU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x8bU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x8bU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x8bU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x8aU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x8aU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x8aU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x8aU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x8aU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x8aU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x8aU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x89U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x89U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x89U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x89U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x89U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x89U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x89U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x88U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x88U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x88U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x88U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x88U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x88U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x88U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0x87U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x87U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x87U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0x87U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0x87U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0x87U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0x87U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0x86U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0x86U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0x86U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0x86U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0x86U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0x86U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0x86U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x85U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x85U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x85U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x85U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x85U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x85U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x85U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x84U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x84U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x84U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x84U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x84U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x84U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x84U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x83U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x83U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x83U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x83U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x83U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x83U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x83U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x82U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x82U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x82U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x82U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x82U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x82U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x82U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0x81U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0x81U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0x81U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0x81U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0x81U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0x81U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0x81U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[4U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0x80U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0x80U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0x80U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0x80U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0x80U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0x80U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0x80U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[5U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0xbfU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0xbfU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0xbfU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0xbfU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xbfU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xbfU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0xbfU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0xbeU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0xbeU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xbeU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0xbeU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xbeU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xbeU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0xbeU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xbdU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xbdU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xbdU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xbdU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xbdU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xbdU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xbdU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xbcU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xbcU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xbcU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xbcU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xbcU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xbcU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xbcU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xbbU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xbbU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xbbU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xbbU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xbbU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xbbU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xbbU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xbaU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xbaU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xbaU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xbaU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xbaU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xbaU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xbaU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xb9U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xb9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xb9U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xb9U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xb9U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xb9U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xb9U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xb8U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xb8U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xb8U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xb8U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xb8U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xb8U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xb8U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xb7U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xb7U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xb7U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xb7U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xb7U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xb7U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xb7U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xb6U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xb6U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xb6U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xb6U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xb6U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xb6U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xb6U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xb5U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xb5U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xb5U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xb5U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xb5U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xb5U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xb5U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xb4U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xb4U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xb4U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xb4U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xb4U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xb4U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xb4U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xb3U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xb3U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xb3U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xb3U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xb3U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xb3U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xb3U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xb2U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xb2U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xb2U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xb2U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xb2U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xb2U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xb2U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xb1U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xb1U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xb1U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xb1U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xb1U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xb1U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xb1U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0xb0U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xb0U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xb0U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0xb0U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0xb0U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0xb0U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0xb0U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xafU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xafU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xafU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xafU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xafU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xafU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xafU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xaeU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xaeU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xaeU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xaeU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xaeU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xaeU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xaeU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xadU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xadU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xadU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xadU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xadU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xadU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xadU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xacU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xacU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xacU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xacU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xacU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xacU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xacU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xabU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xabU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xabU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xabU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xabU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xabU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xabU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xaaU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xaaU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xaaU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xaaU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xaaU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xaaU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xaaU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xa9U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xa9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xa9U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xa9U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xa9U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xa9U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xa9U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xa8U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xa8U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xa8U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xa8U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xa8U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xa8U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xa8U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xa7U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xa7U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xa7U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xa7U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xa7U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xa7U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xa7U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xa6U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xa6U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xa6U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xa6U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xa6U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xa6U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xa6U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xa5U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xa5U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xa5U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xa5U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xa5U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xa5U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xa5U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xa4U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xa4U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xa4U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xa4U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xa4U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xa4U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xa4U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xa3U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xa3U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xa3U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xa3U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xa3U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xa3U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xa3U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xa2U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xa2U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xa2U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xa2U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xa2U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xa2U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xa2U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xa1U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xa1U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xa1U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xa1U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xa1U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xa1U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xa1U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[5U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0xa0U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0xa0U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0xa0U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0xa0U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xa0U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xa0U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0xa0U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[6U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0xdfU]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0xdfU] 
                                                  < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0xdfU] 
                                                     & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    == 
                                                    vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0xdfU])) 
                                                | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xdfU] 
                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xdfU] 
                                                       == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      & (0xdfU 
                                                         < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0xdeU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0xdeU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xdeU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0xdeU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xdeU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xdeU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0xdeU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xddU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xddU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xddU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xddU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xddU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xddU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xddU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xdcU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xdcU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xdcU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xdcU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xdcU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xdcU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xdcU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xdbU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xdbU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xdbU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xdbU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xdbU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xdbU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xdbU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xdaU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xdaU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xdaU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xdaU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xdaU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xdaU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xdaU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xd9U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xd9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xd9U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xd9U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xd9U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xd9U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xd9U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xd8U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xd8U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xd8U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xd8U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xd8U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xd8U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xd8U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xd7U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xd7U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xd7U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xd7U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xd7U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xd7U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xd7U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xd6U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xd6U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xd6U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xd6U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xd6U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xd6U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xd6U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xd5U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xd5U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xd5U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xd5U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xd5U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xd5U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xd5U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xd4U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xd4U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xd4U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xd4U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xd4U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xd4U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xd4U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xd3U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xd3U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xd3U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xd3U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xd3U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xd3U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xd3U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xd2U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xd2U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xd2U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xd2U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xd2U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xd2U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xd2U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xd1U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xd1U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xd1U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xd1U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xd1U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xd1U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xd1U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0xd0U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xd0U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xd0U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0xd0U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0xd0U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0xd0U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0xd0U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xcfU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xcfU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xcfU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xcfU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xcfU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xcfU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xcfU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xceU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xceU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xceU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xceU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xceU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xceU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xceU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xcdU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xcdU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xcdU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xcdU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xcdU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xcdU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xcdU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xccU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xccU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xccU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xccU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xccU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xccU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xccU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xcbU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xcbU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xcbU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xcbU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xcbU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xcbU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xcbU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xcaU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xcaU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xcaU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xcaU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xcaU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xcaU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xcaU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xc9U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xc9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xc9U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xc9U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xc9U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xc9U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xc9U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xc8U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xc8U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xc8U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xc8U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xc8U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xc8U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xc8U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xc7U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xc7U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xc7U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xc7U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xc7U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xc7U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xc7U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xc6U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xc6U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xc6U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xc6U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xc6U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xc6U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xc6U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xc5U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xc5U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xc5U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xc5U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xc5U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xc5U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xc5U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xc4U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xc4U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xc4U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xc4U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xc4U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xc4U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xc4U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xc3U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xc3U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xc3U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xc3U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xc3U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xc3U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xc3U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xc2U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xc2U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xc2U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xc2U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xc2U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xc2U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xc2U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xc1U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xc1U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xc1U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xc1U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xc1U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xc1U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xc1U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[6U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0xc0U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0xc0U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0xc0U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0xc0U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xc0U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xc0U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0xc0U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.top__DOT__u_pruner__DOT__valid_mask[7U] 
        = ((((((0x80000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                               & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                    [0xffU]) & ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                 [0xffU] 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                    [0xffU] 
                                                    & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                   == 
                                                   vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xffU]))) 
                                  << 0x1fU))) | (0xc0000000U 
                                                 & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                    & (((~ 
                                                         vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                         [0xfeU]) 
                                                        & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                             [0xfeU] 
                                                             < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xfeU] 
                                                                & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                               [0xfeU])) 
                                                           | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xfeU] 
                                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xfeU] 
                                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 & (0xfeU 
                                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                       << 0x1eU)))) 
              | ((0xe0000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xfdU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xfdU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xfdU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xfdU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xfdU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xfdU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xfdU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1dU))) | (0xf0000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xfcU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xfcU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xfcU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xfcU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xfcU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xfcU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xfcU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1cU))))) 
             | (((0xf8000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xfbU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xfbU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xfbU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xfbU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xfbU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xfbU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xfbU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x1bU))) | (0xfc000000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xfaU]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xfaU] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xfaU] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xfaU])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xfaU] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xfaU] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xfaU 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x1aU)))) 
                | ((0xfe000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xf9U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xf9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xf9U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xf9U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xf9U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xf9U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xf9U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x19U))) | 
                   (0xff000000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xf8U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xf8U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xf8U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xf8U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xf8U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xf8U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xf8U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x18U)))))) 
            | ((((0xff800000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xf7U]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xf7U] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xf7U] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xf7U])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xf7U] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xf7U] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xf7U 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0x17U))) | (0xffc00000U 
                                                   & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                      & (((~ 
                                                           vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                           [0xf6U]) 
                                                          & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                               [0xf6U] 
                                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                              & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                  [0xf6U] 
                                                                  & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                 == 
                                                                 vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xf6U])) 
                                                             | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                 [0xf6U] 
                                                                 == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                                & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                    [0xf6U] 
                                                                    == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                   & (0xf6U 
                                                                      < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                         << 0x16U)))) 
                | ((0xffe00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xf5U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xf5U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xf5U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xf5U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xf5U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xf5U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xf5U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x15U))) | 
                   (0xfff00000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xf4U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xf4U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xf4U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xf4U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xf4U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xf4U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xf4U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x14U))))) 
               | (((0xfff80000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xf3U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xf3U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xf3U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xf3U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xf3U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xf3U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xf3U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x13U))) | 
                   (0xfffc0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xf2U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xf2U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xf2U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xf2U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xf2U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xf2U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xf2U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0x12U)))) 
                  | ((0xfffe0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xf1U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xf1U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xf1U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xf1U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xf1U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xf1U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xf1U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 0x11U))) 
                     | (0xffff0000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                       & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                            [0xf0U]) 
                                           & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xf0U] 
                                                < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xf0U] 
                                                   & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  == 
                                                  vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                  [0xf0U])) 
                                              | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                  [0xf0U] 
                                                  == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                 & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                     [0xf0U] 
                                                     == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                    & (0xf0U 
                                                       < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                          << 0x10U))))))) 
           | (((((0xffff8000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                 & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                      [0xefU]) & ((
                                                   (vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                    [0xefU] 
                                                    < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                   & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                       [0xefU] 
                                                       & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                      == 
                                                      vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                      [0xefU])) 
                                                  | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                      [0xefU] 
                                                      == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                     & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                         [0xefU] 
                                                         == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                        & (0xefU 
                                                           < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                    << 0xfU))) | (0xffffc000U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xeeU]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xeeU] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xeeU] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xeeU])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xeeU] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xeeU] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xeeU 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 0xeU)))) 
                | ((0xffffe000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xedU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xedU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xedU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xedU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xedU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xedU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xedU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xdU))) | 
                   (0xfffff000U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xecU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xecU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xecU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xecU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xecU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xecU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xecU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xcU))))) 
               | (((0xfffff800U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xebU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xebU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xebU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xebU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xebU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xebU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xebU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xbU))) | 
                   (0xfffffc00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xeaU]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xeaU] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xeaU] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xeaU])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xeaU] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xeaU] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xeaU 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 0xaU)))) | 
                  ((0xfffffe00U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xe9U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xe9U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xe9U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xe9U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xe9U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xe9U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xe9U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 9U))) | (0xffffff00U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xe8U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xe8U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xe8U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xe8U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xe8U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xe8U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xe8U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 8U)))))) 
              | ((((0xffffff80U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                   & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                        [0xe7U]) & 
                                       (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xe7U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xe7U] 
                                             & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                            [0xe7U])) 
                                        | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                            [0xe7U] 
                                            == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                           & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                               [0xe7U] 
                                               == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                              & (0xe7U 
                                                 < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                      << 7U))) | (0xffffffc0U 
                                                  & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                                     & (((~ 
                                                          vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                                          [0xe6U]) 
                                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                              [0xe6U] 
                                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                 [0xe6U] 
                                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                [0xe6U])) 
                                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                                [0xe6U] 
                                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                                   [0xe6U] 
                                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                                  & (0xe6U 
                                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                                        << 6U)))) 
                  | ((0xffffffe0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xe5U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xe5U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xe5U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xe5U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xe5U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xe5U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xe5U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 5U))) | 
                     (0xfffffff0U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xe4U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xe4U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xe4U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xe4U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xe4U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xe4U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xe4U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 4U))))) 
                 | (((0xfffffff8U & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xe3U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xe3U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xe3U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xe3U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xe3U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xe3U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xe3U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 3U))) | 
                     (0xfffffffcU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xe2U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xe2U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xe2U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xe2U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xe2U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xe2U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xe2U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 2U)))) | 
                    ((0xfffffffeU & (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                                     & (((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                                          [0xe1U]) 
                                         & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                              [0xe1U] 
                                              < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                             & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                 [0xe1U] 
                                                 & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                == 
                                                vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                [0xe1U])) 
                                            | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                                [0xe1U] 
                                                == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                               & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                                   [0xe1U] 
                                                   == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                                  & (0xe1U 
                                                     < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r)))))) 
                                        << 1U))) | 
                     (vlSelfRef.top__DOT__u_pruner__DOT__si_vec_r[7U] 
                      & ((~ vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0
                          [0xe0U]) & (((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                        [0xe0U] < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                       & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                           [0xe0U] 
                                           & (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                          == vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                          [0xe0U])) 
                                      | ((vlSelfRef.top__DOT__u_pruner__DOT__NO_table
                                          [0xe0U] == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_NO_r)) 
                                         & ((vlSelfRef.top__DOT__u_pruner__DOT__spike_matrix
                                             [0xe0U] 
                                             == (IData)(vlSelfRef.top__DOT__u_pruner__DOT__cur_spikes_r)) 
                                            & (0xe0U 
                                               < (IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_idx_r))))))))))));
}
