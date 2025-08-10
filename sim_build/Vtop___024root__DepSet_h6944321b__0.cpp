// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.detector__DOT__query_pattern = vlSelfRef.query_pattern;
    vlSelfRef.detector__DOT__q_valid = vlSelfRef.q_valid;
    vlSelfRef.detector__DOT__row_idx = vlSelfRef.row_idx;
    vlSelfRef.detector__DOT__tile_mem_addr = vlSelfRef.tile_mem_addr;
    vlSelfRef.detector__DOT__tile_mem_data_in = vlSelfRef.tile_mem_data_in;
    vlSelfRef.detector__DOT__tile_mem_wr_en = vlSelfRef.tile_mem_wr_en;
    vlSelfRef.detector__DOT__popcount_mem_addr = vlSelfRef.popcount_mem_addr;
    vlSelfRef.detector__DOT__popcount_mem_data_in = vlSelfRef.popcount_mem_data_in;
    vlSelfRef.detector__DOT__popcount_mem_wr_en = vlSelfRef.popcount_mem_wr_en;
    vlSelfRef.detector__DOT__tcam_core__DOT__req_key 
        = vlSelfRef.detector__DOT__query_reg;
    vlSelfRef.si_vec[0U] = vlSelfRef.detector__DOT__si_vec[0U];
    vlSelfRef.si_vec[1U] = vlSelfRef.detector__DOT__si_vec[1U];
    vlSelfRef.si_vec[2U] = vlSelfRef.detector__DOT__si_vec[2U];
    vlSelfRef.si_vec[3U] = vlSelfRef.detector__DOT__si_vec[3U];
    vlSelfRef.si_vec[4U] = vlSelfRef.detector__DOT__si_vec[4U];
    vlSelfRef.si_vec[5U] = vlSelfRef.detector__DOT__si_vec[5U];
    vlSelfRef.si_vec[6U] = vlSelfRef.detector__DOT__si_vec[6U];
    vlSelfRef.si_vec[7U] = vlSelfRef.detector__DOT__si_vec[7U];
    vlSelfRef.si_valid = vlSelfRef.detector__DOT__si_valid;
    vlSelfRef.det_done = vlSelfRef.detector__DOT__det_done;
    vlSelfRef.row_popcnt = vlSelfRef.detector__DOT__row_popcnt;
    vlSelfRef.detector_init_done = vlSelfRef.detector__DOT__detector_init_done;
    vlSelfRef.detector__DOT__tcam_matches[0U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[0U];
    vlSelfRef.detector__DOT__tcam_matches[1U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[1U];
    vlSelfRef.detector__DOT__tcam_matches[2U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[2U];
    vlSelfRef.detector__DOT__tcam_matches[3U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[3U];
    vlSelfRef.detector__DOT__tcam_matches[4U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[4U];
    vlSelfRef.detector__DOT__tcam_matches[5U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[5U];
    vlSelfRef.detector__DOT__tcam_matches[6U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[6U];
    vlSelfRef.detector__DOT__tcam_matches[7U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[0U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[1U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[2U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[3U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[4U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[5U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[6U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__line_match[7U] 
        = vlSelfRef.detector__DOT__tcam_core__DOT__match[7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__0__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__1__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__2__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__3__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__4__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__5__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__6__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__7__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__8__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__9__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__10__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__11__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__12__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__13__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__14__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__15__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__16__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x10U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__17__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x11U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__18__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x12U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__19__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x13U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__20__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x14U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__21__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x15U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__22__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x16U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__23__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x17U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__24__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x18U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__25__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x19U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__26__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__27__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__28__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__29__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__30__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__31__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__32__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x20U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__33__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x21U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__34__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x22U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__35__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x23U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__36__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x24U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__37__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x25U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__38__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x26U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__39__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x27U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__40__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x28U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__41__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x29U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__42__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__43__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__44__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__45__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__46__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__47__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__48__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x30U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__49__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x31U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__50__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x32U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__51__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x33U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__52__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x34U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__53__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x35U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__54__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x36U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__55__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x37U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__56__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x38U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__57__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x39U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__58__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__59__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__60__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__61__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__62__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__63__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__64__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x40U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__65__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x41U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__66__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x42U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__67__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x43U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__68__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x44U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__69__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x45U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__70__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x46U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__71__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x47U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__72__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x48U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__73__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x49U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__74__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__75__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__76__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__77__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__78__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__79__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__80__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x50U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__81__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x51U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__82__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x52U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__83__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x53U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__84__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x54U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__85__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x55U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__86__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x56U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__87__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x57U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__88__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x58U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__89__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x59U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__90__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__91__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__92__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__93__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__94__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__95__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__96__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x60U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__97__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x61U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__98__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x62U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__99__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x63U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__100__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x64U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__101__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x65U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__102__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x66U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__103__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x67U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__104__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x68U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__105__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x69U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__106__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__107__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__108__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__109__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__110__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__111__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__112__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x70U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__113__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x71U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__114__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x72U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__115__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x73U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__116__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x74U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__117__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x75U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__118__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x76U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__119__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x77U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__120__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x78U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__121__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x79U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__122__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__123__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__124__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__125__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__126__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__127__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__128__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x80U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__129__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x81U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__130__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x82U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__131__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x83U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__132__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x84U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__133__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x85U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__134__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x86U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__135__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x87U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__136__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x88U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__137__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x89U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__138__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__139__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__140__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__141__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__142__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__143__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__144__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x90U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__145__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x91U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__146__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x92U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__147__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x93U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__148__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x94U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__149__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x95U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__150__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x96U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__151__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x97U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__152__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x98U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__153__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x99U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__154__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__155__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__156__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__157__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__158__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__159__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__160__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__161__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__162__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__163__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__164__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__165__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__166__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__167__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__168__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__169__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__170__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xaaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__171__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xabU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__172__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xacU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__173__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xadU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__174__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xaeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__175__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xafU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__176__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__177__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__178__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__179__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__180__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__181__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__182__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__183__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__184__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__185__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__186__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__187__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__188__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__189__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__190__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__191__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__192__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__193__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__194__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__195__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__196__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__197__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__198__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__199__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__200__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__201__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__202__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__203__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__204__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xccU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__205__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__206__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xceU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__207__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__208__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__209__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__210__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__211__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__212__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__213__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__214__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__215__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__216__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__217__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__218__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__219__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__220__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__221__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xddU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__222__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__223__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__224__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__225__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__226__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__227__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__228__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__229__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__230__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__231__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__232__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__233__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__234__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xeaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__235__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xebU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__236__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xecU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__237__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xedU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__238__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xeeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__239__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xefU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__240__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__241__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__242__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__243__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__244__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__245__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__246__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__247__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__248__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__249__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__250__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__251__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__252__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__253__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__254__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__255__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xffU];
    vlSelfRef.detector__DOT__tile_mem_data_out = vlSelfRef.detector__DOT__tile_buffer
        [vlSelfRef.tile_mem_addr];
    vlSelfRef.detector__DOT__popcount_mem_data_out 
        = vlSelfRef.detector__DOT__row_popcounts[vlSelfRef.popcount_mem_addr];
    vlSelfRef.detector__DOT__clk = vlSelfRef.clk;
    vlSelfRef.detector__DOT__rst = vlSelfRef.rst;
    vlSelfRef.detector__DOT__tcam_set_valid = 0U;
    vlSelfRef.detector__DOT__tcam_set_clr = 0U;
    vlSelfRef.detector__DOT__tcam_req_valid = 0U;
    if ((1U != (IData)(vlSelfRef.detector__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.detector__DOT__state))) {
            vlSelfRef.detector__DOT__tcam_set_clr = 0U;
        }
    }
    if (vlSelfRef.q_valid) {
        vlSelfRef.detector__DOT__tcam_req_valid = 1U;
    }
    if ((1U != (IData)(vlSelfRef.detector__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.detector__DOT__state))) {
            vlSelfRef.detector__DOT__tcam_req_valid = 0U;
        }
    }
    vlSelfRef.detector__DOT__tcam_addr = vlSelfRef.detector__DOT__load_counter;
    vlSelfRef.detector__DOT__q_ready = ((IData)(vlSelfRef.detector__DOT__initialized) 
                                        & (IData)(vlSelfRef.detector__DOT__popcounts_calculated));
    vlSelfRef.detector__DOT__next_state = ((2U & (IData)(vlSelfRef.detector__DOT__state))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.detector__DOT__state))
                                                ? (
                                                   (0xffU 
                                                    == (IData)(vlSelfRef.detector__DOT__popcount_counter))
                                                    ? 0U
                                                    : 3U)
                                                : ((IData)(vlSelfRef.q_valid)
                                                    ? 2U
                                                    : 0U))
                                            : ((1U 
                                                & (IData)(vlSelfRef.detector__DOT__state))
                                                ? (
                                                   (0xffU 
                                                    == (IData)(vlSelfRef.detector__DOT__load_counter))
                                                    ? 3U
                                                    : 1U)
                                                : ((IData)(vlSelfRef.detector__DOT__initialized)
                                                    ? 
                                                   ((IData)(vlSelfRef.detector__DOT__popcounts_calculated)
                                                     ? 
                                                    ((IData)(vlSelfRef.q_valid)
                                                      ? 2U
                                                      : 0U)
                                                     : 3U)
                                                    : 1U)));
    vlSelfRef.detector__DOT__tcam_key = 0U;
    if (vlSelfRef.q_valid) {
        vlSelfRef.detector__DOT__tcam_key = vlSelfRef.query_pattern;
        vlSelfRef.detector__DOT__tcam_xmask = 0U;
        vlSelfRef.detector__DOT__tcam_xmask = (0xffffU 
                                               & (~ (IData)(vlSelfRef.query_pattern)));
    } else {
        vlSelfRef.detector__DOT__tcam_xmask = 0U;
    }
    if ((1U == (IData)(vlSelfRef.detector__DOT__state))) {
        vlSelfRef.detector__DOT__tcam_set_valid = 1U;
        vlSelfRef.detector__DOT__tcam_addr = vlSelfRef.detector__DOT__load_counter;
        vlSelfRef.detector__DOT__tcam_key = vlSelfRef.detector__DOT__tile_buffer
            [vlSelfRef.detector__DOT__load_counter];
        vlSelfRef.detector__DOT__tcam_xmask = (0xffffU 
                                               & (~ 
                                                  vlSelfRef.detector__DOT__tile_buffer
                                                  [vlSelfRef.detector__DOT__load_counter]));
    } else if ((2U != (IData)(vlSelfRef.detector__DOT__state))) {
        vlSelfRef.detector__DOT__tcam_set_valid = 0U;
    }
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x10U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x10U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x11U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x11U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x12U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x12U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x13U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x13U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x14U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x14U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x15U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x15U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x16U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x16U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x17U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x17U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x18U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x18U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x19U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x19U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x20U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x20U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x21U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x21U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x22U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x22U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x23U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x23U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x24U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x24U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x25U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x25U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x26U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x26U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x27U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x27U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x28U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x28U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x29U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x29U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x30U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x30U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x31U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x31U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x32U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x32U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x33U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x33U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x34U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x34U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x35U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x35U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x36U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x36U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x37U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x37U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x38U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x38U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x39U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x39U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x40U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x40U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x41U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x41U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x42U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x42U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x43U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x43U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x44U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x44U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x45U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x45U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x46U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x46U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x47U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x47U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x48U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x48U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x49U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x49U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x50U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x50U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x51U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x51U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x52U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x52U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x53U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x53U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x54U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x54U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x55U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x55U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x56U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x56U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x57U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x57U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x58U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x58U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x59U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x59U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x60U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x60U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x61U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x61U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x62U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x62U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x63U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x63U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x64U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x64U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x65U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x65U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x66U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x66U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x67U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x67U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x68U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x68U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x69U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x69U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x70U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x70U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x71U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x71U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x72U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x72U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x73U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x73U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x74U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x74U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x75U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x75U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x76U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x76U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x77U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x77U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x78U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x78U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x79U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x79U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x80U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x80U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x81U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x81U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x82U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x82U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x83U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x83U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x84U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x84U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x85U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x85U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x86U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x86U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x87U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x87U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x88U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x88U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x89U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x89U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x90U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x90U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x91U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x91U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x92U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x92U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x93U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x93U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x94U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x94U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x95U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x95U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x96U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x96U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x97U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x97U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x98U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x98U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x99U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x99U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xaaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xabU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xabU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xacU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xacU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xadU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xadU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xaeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xafU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xafU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xccU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xccU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xceU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xceU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xddU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xddU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xeaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xebU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xebU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xecU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xecU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xedU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xedU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xeeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xefU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xefU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xffU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xffU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x10U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x10U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x11U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x11U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x12U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x12U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x13U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x13U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x14U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x14U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x15U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x15U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x16U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x16U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x17U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x17U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x18U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x18U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x19U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x19U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x20U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x20U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x21U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x21U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x22U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x22U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x23U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x23U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x24U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x24U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x25U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x25U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x26U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x26U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x27U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x27U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x28U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x28U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x29U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x29U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x30U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x30U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x31U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x31U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x32U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x32U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x33U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x33U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x34U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x34U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x35U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x35U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x36U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x36U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x37U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x37U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x38U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x38U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x39U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x39U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x40U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x40U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x41U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x41U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x42U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x42U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x43U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x43U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x44U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x44U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x45U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x45U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x46U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x46U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x47U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x47U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x48U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x48U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x49U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x49U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x50U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x50U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x51U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x51U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x52U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x52U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x53U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x53U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x54U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x54U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x55U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x55U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x56U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x56U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x57U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x57U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x58U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x58U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x59U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x59U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x60U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x60U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x61U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x61U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x62U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x62U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x63U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x63U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x64U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x64U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x65U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x65U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x66U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x66U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x67U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x67U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x68U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x68U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x69U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x69U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x70U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x70U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x71U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x71U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x72U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x72U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x73U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x73U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x74U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x74U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x75U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x75U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x76U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x76U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x77U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x77U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x78U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x78U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x79U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x79U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x80U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x80U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x81U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x81U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x82U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x82U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x83U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x83U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x84U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x84U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x85U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x85U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x86U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x86U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x87U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x87U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x88U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x88U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x89U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x89U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x90U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x90U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x91U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x91U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x92U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x92U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x93U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x93U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x94U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x94U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x95U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x95U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x96U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x96U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x97U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x97U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x98U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x98U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x99U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x99U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xaaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xabU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xabU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xacU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xacU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xadU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xadU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xaeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xafU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xafU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xccU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xccU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xceU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xceU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xddU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xddU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xeaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xebU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xebU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xecU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xecU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xedU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xedU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xeeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xefU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xefU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xffU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xffU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__clk = vlSelfRef.detector__DOT__clk;
    vlSelfRef.detector__DOT__tcam_core__DOT__rst = vlSelfRef.detector__DOT__rst;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_valid 
        = vlSelfRef.detector__DOT__tcam_set_valid;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_clr 
        = vlSelfRef.detector__DOT__tcam_set_clr;
    vlSelfRef.detector__DOT__tcam_core__DOT__req_valid 
        = vlSelfRef.detector__DOT__tcam_req_valid;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_addr 
        = vlSelfRef.detector__DOT__tcam_addr;
    vlSelfRef.q_ready = vlSelfRef.detector__DOT__q_ready;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_key 
        = vlSelfRef.detector__DOT__tcam_key;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_xmask 
        = vlSelfRef.detector__DOT__tcam_xmask;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9e67c271_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__detector__DOT__load_counter;
    __Vdly__detector__DOT__load_counter = 0;
    CData/*7:0*/ __Vdly__detector__DOT__popcount_counter;
    __Vdly__detector__DOT__popcount_counter = 0;
    SData/*15:0*/ __VdlyVal__detector__DOT__tile_buffer__v0;
    __VdlyVal__detector__DOT__tile_buffer__v0 = 0;
    CData/*7:0*/ __VdlyDim0__detector__DOT__tile_buffer__v0;
    __VdlyDim0__detector__DOT__tile_buffer__v0 = 0;
    CData/*0:0*/ __VdlySet__detector__DOT__tile_buffer__v0;
    __VdlySet__detector__DOT__tile_buffer__v0 = 0;
    CData/*7:0*/ __VdlyVal__detector__DOT__row_popcounts__v0;
    __VdlyVal__detector__DOT__row_popcounts__v0 = 0;
    CData/*7:0*/ __VdlyDim0__detector__DOT__row_popcounts__v0;
    __VdlyDim0__detector__DOT__row_popcounts__v0 = 0;
    CData/*0:0*/ __VdlySet__detector__DOT__row_popcounts__v0;
    __VdlySet__detector__DOT__row_popcounts__v0 = 0;
    IData/*31:0*/ __VdlyVal__detector__DOT__tcam_core__DOT__mem__v0;
    __VdlyVal__detector__DOT__tcam_core__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__detector__DOT__tcam_core__DOT__mem__v0;
    __VdlyDim0__detector__DOT__tcam_core__DOT__mem__v0 = 0;
    // Body
    __VdlySet__detector__DOT__row_popcounts__v0 = 0U;
    __VdlySet__detector__DOT__tile_buffer__v0 = 0U;
    __Vdly__detector__DOT__popcount_counter = vlSelfRef.detector__DOT__popcount_counter;
    __Vdly__detector__DOT__load_counter = vlSelfRef.detector__DOT__load_counter;
    if (vlSelfRef.popcount_mem_wr_en) {
        __VdlyVal__detector__DOT__row_popcounts__v0 
            = vlSelfRef.popcount_mem_data_in;
        __VdlyDim0__detector__DOT__row_popcounts__v0 
            = vlSelfRef.popcount_mem_addr;
        __VdlySet__detector__DOT__row_popcounts__v0 = 1U;
    }
    if (vlSelfRef.tile_mem_wr_en) {
        __VdlyVal__detector__DOT__tile_buffer__v0 = vlSelfRef.tile_mem_data_in;
        __VdlyDim0__detector__DOT__tile_buffer__v0 
            = vlSelfRef.tile_mem_addr;
        __VdlySet__detector__DOT__tile_buffer__v0 = 1U;
    }
    if (__VdlySet__detector__DOT__tile_buffer__v0) {
        vlSelfRef.detector__DOT__tile_buffer[__VdlyDim0__detector__DOT__tile_buffer__v0] 
            = __VdlyVal__detector__DOT__tile_buffer__v0;
    }
    vlSelfRef.detector__DOT__tile_mem_data_out = vlSelfRef.detector__DOT__tile_buffer
        [vlSelfRef.tile_mem_addr];
    if (vlSelfRef.rst) {
        vlSelfRef.detector__DOT__row_popcnt = 0U;
        vlSelfRef.row_popcnt = vlSelfRef.detector__DOT__row_popcnt;
        vlSelfRef.detector__DOT__tcam_core__DOT__match[0U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[1U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[2U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[3U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[4U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[5U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[6U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.detector__DOT__tcam_core__DOT__match[7U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[0U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[0U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[1U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[1U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[2U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[2U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[3U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[3U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[4U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[4U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[5U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[5U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[6U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[6U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[7U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[7U];
        vlSelfRef.detector__DOT__row_popcnt_stage2 = 0U;
        __Vdly__detector__DOT__load_counter = 0U;
        __Vdly__detector__DOT__popcount_counter = 0U;
        vlSelfRef.detector__DOT__query_reg = 0U;
        vlSelfRef.detector__DOT__si_vec[0U] = Vtop__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.detector__DOT__si_vec[1U] = Vtop__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.detector__DOT__si_vec[2U] = Vtop__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.detector__DOT__si_vec[3U] = Vtop__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.detector__DOT__si_vec[4U] = Vtop__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.detector__DOT__si_vec[5U] = Vtop__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.detector__DOT__si_vec[6U] = Vtop__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.detector__DOT__si_vec[7U] = Vtop__ConstPool__CONST_h9e67c271_0[7U];
        vlSelfRef.detector__DOT__si_valid = 0U;
        vlSelfRef.detector__DOT__det_done = 0U;
        vlSelfRef.detector__DOT__initialized = 0U;
        vlSelfRef.detector__DOT__popcounts_calculated = 0U;
        vlSelfRef.detector__DOT__detector_init_done = 0U;
    } else {
        vlSelfRef.detector__DOT__row_popcnt = vlSelfRef.detector__DOT__row_popcnt_stage2;
        vlSelfRef.row_popcnt = vlSelfRef.detector__DOT__row_popcnt;
        if (vlSelfRef.detector__DOT__tcam_req_valid) {
            vlSelfRef.detector__DOT__tcam_core__DOT__i = 0U;
            while (VL_GTS_III(32, 0x100U, vlSelfRef.detector__DOT__tcam_core__DOT__i)) {
                vlSelfRef.detector__DOT__tcam_core__DOT__match[(7U 
                                                                & (vlSelfRef.detector__DOT__tcam_core__DOT__i 
                                                                   >> 5U))] 
                    = (((~ ((IData)(1U) << (0x1fU & vlSelfRef.detector__DOT__tcam_core__DOT__i))) 
                        & vlSelfRef.detector__DOT__tcam_core__DOT__match[
                        (7U & (vlSelfRef.detector__DOT__tcam_core__DOT__i 
                               >> 5U))]) | (((0U == 
                                              (vlSelfRef.detector__DOT__tcam_core__DOT__key
                                               [(0xffU 
                                                 & vlSelfRef.detector__DOT__tcam_core__DOT__i)] 
                                               ^ ((IData)(vlSelfRef.detector__DOT__query_reg) 
                                                  & (~ 
                                                     vlSelfRef.detector__DOT__tcam_core__DOT__xmask
                                                     [
                                                     (0xffU 
                                                      & vlSelfRef.detector__DOT__tcam_core__DOT__i)])))) 
                                             & (vlSelfRef.detector__DOT__tcam_core__DOT__active[
                                                (7U 
                                                 & (vlSelfRef.detector__DOT__tcam_core__DOT__i 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & vlSelfRef.detector__DOT__tcam_core__DOT__i))) 
                                            << (0x1fU 
                                                & vlSelfRef.detector__DOT__tcam_core__DOT__i)));
                vlSelfRef.detector__DOT__tcam_core__DOT__i 
                    = ((IData)(1U) + vlSelfRef.detector__DOT__tcam_core__DOT__i);
            }
        }
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[0U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[0U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[1U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[1U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[2U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[2U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[3U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[3U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[4U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[4U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[5U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[5U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[6U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[6U];
        vlSelfRef.detector__DOT__tcam_core__DOT__line_match[7U] 
            = vlSelfRef.detector__DOT__tcam_core__DOT__match[7U];
        vlSelfRef.detector__DOT__row_popcnt_stage2 
            = vlSelfRef.detector__DOT__row_popcnt_stage1;
        vlSelfRef.detector__DOT__si_valid = 0U;
        vlSelfRef.detector__DOT__det_done = 0U;
        if ((2U & (IData)(vlSelfRef.detector__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.detector__DOT__state))) {
                if ((0xffU > (IData)(vlSelfRef.detector__DOT__popcount_counter))) {
                    __Vdly__detector__DOT__popcount_counter 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.detector__DOT__popcount_counter)));
                } else {
                    vlSelfRef.detector__DOT__popcounts_calculated = 1U;
                    vlSelfRef.detector__DOT__detector_init_done = 1U;
                }
            } else {
                vlSelfRef.detector__DOT__si_vec[0U] 
                    = vlSelfRef.detector__DOT__match_d2[0U];
                vlSelfRef.detector__DOT__si_vec[1U] 
                    = vlSelfRef.detector__DOT__match_d2[1U];
                vlSelfRef.detector__DOT__si_vec[2U] 
                    = vlSelfRef.detector__DOT__match_d2[2U];
                vlSelfRef.detector__DOT__si_vec[3U] 
                    = vlSelfRef.detector__DOT__match_d2[3U];
                vlSelfRef.detector__DOT__si_vec[4U] 
                    = vlSelfRef.detector__DOT__match_d2[4U];
                vlSelfRef.detector__DOT__si_vec[5U] 
                    = vlSelfRef.detector__DOT__match_d2[5U];
                vlSelfRef.detector__DOT__si_vec[6U] 
                    = vlSelfRef.detector__DOT__match_d2[6U];
                vlSelfRef.detector__DOT__si_vec[7U] 
                    = vlSelfRef.detector__DOT__match_d2[7U];
                vlSelfRef.detector__DOT__si_valid = vlSelfRef.detector__DOT__q_valid_d2;
                vlSelfRef.detector__DOT__det_done = vlSelfRef.detector__DOT__q_valid_d2;
                vlSelfRef.detector__DOT__q_valid_d2 
                    = vlSelfRef.detector__DOT__q_valid_d1;
                vlSelfRef.detector__DOT__q_valid_d1 
                    = vlSelfRef.q_valid;
            }
        } else if ((1U & (IData)(vlSelfRef.detector__DOT__state))) {
            if ((0xffU > (IData)(vlSelfRef.detector__DOT__load_counter))) {
                __Vdly__detector__DOT__load_counter 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.detector__DOT__load_counter)));
            } else {
                vlSelfRef.detector__DOT__initialized = 1U;
            }
        } else if (vlSelfRef.q_valid) {
            vlSelfRef.detector__DOT__query_reg = vlSelfRef.query_pattern;
            vlSelfRef.detector__DOT__q_valid_d1 = 1U;
        } else {
            vlSelfRef.detector__DOT__q_valid_d1 = 0U;
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.detector__DOT__tcam_core__DOT__active[0U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[0U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[1U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[1U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[2U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[2U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[3U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[3U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[4U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[4U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[5U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[5U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[6U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[6U];
        vlSelfRef.detector__DOT__tcam_core__DOT__active[7U] 
            = Vtop__ConstPool__CONST_h9e67c271_0[7U];
    } else if (vlSelfRef.detector__DOT__tcam_set_valid) {
        vlSelfRef.detector__DOT__tcam_core__DOT__i = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelfRef.detector__DOT__tcam_core__DOT__i)) {
            if (((IData)(vlSelfRef.detector__DOT__tcam_addr) 
                 == vlSelfRef.detector__DOT__tcam_core__DOT__i)) {
                __VdlyVal__detector__DOT__tcam_core__DOT__mem__v0 
                    = (((IData)(vlSelfRef.detector__DOT__tcam_xmask) 
                        << 0x10U) | (IData)(vlSelfRef.detector__DOT__tcam_key));
                __VdlyDim0__detector__DOT__tcam_core__DOT__mem__v0 
                    = (0xffU & vlSelfRef.detector__DOT__tcam_core__DOT__i);
                vlSelfRef.__VdlyCommitQueuedetector__DOT__tcam_core__DOT__mem.enqueue(__VdlyVal__detector__DOT__tcam_core__DOT__mem__v0, (IData)(__VdlyDim0__detector__DOT__tcam_core__DOT__mem__v0));
                vlSelfRef.detector__DOT__tcam_core__DOT__active[(7U 
                                                                 & (vlSelfRef.detector__DOT__tcam_core__DOT__i 
                                                                    >> 5U))] 
                    = (((~ ((IData)(1U) << (0x1fU & vlSelfRef.detector__DOT__tcam_core__DOT__i))) 
                        & vlSelfRef.detector__DOT__tcam_core__DOT__active[
                        (7U & (vlSelfRef.detector__DOT__tcam_core__DOT__i 
                               >> 5U))]) | ((1U & (~ (IData)(vlSelfRef.detector__DOT__tcam_set_clr))) 
                                            << (0x1fU 
                                                & vlSelfRef.detector__DOT__tcam_core__DOT__i)));
            }
            vlSelfRef.detector__DOT__tcam_core__DOT__i 
                = ((IData)(1U) + vlSelfRef.detector__DOT__tcam_core__DOT__i);
        }
    }
    vlSelfRef.detector__DOT__popcount_counter = __Vdly__detector__DOT__popcount_counter;
    vlSelfRef.detector__DOT__load_counter = __Vdly__detector__DOT__load_counter;
    vlSelfRef.__VdlyCommitQueuedetector__DOT__tcam_core__DOT__mem.commit(vlSelfRef.detector__DOT__tcam_core__DOT__mem);
    if (vlSelfRef.rst) {
        vlSelfRef.detector__DOT__row_popcnt_stage1 = 0U;
        vlSelfRef.detector__DOT__state = 0U;
    } else {
        if (vlSelfRef.q_valid) {
            vlSelfRef.detector__DOT__row_popcnt_stage1 
                = vlSelfRef.detector__DOT__row_popcounts
                [vlSelfRef.row_idx];
        }
        vlSelfRef.detector__DOT__state = vlSelfRef.detector__DOT__next_state;
    }
    vlSelfRef.detector__DOT__tcam_core__DOT__req_key 
        = vlSelfRef.detector__DOT__query_reg;
    vlSelfRef.si_vec[0U] = vlSelfRef.detector__DOT__si_vec[0U];
    vlSelfRef.si_vec[1U] = vlSelfRef.detector__DOT__si_vec[1U];
    vlSelfRef.si_vec[2U] = vlSelfRef.detector__DOT__si_vec[2U];
    vlSelfRef.si_vec[3U] = vlSelfRef.detector__DOT__si_vec[3U];
    vlSelfRef.si_vec[4U] = vlSelfRef.detector__DOT__si_vec[4U];
    vlSelfRef.si_vec[5U] = vlSelfRef.detector__DOT__si_vec[5U];
    vlSelfRef.si_vec[6U] = vlSelfRef.detector__DOT__si_vec[6U];
    vlSelfRef.si_vec[7U] = vlSelfRef.detector__DOT__si_vec[7U];
    vlSelfRef.si_valid = vlSelfRef.detector__DOT__si_valid;
    vlSelfRef.det_done = vlSelfRef.detector__DOT__det_done;
    vlSelfRef.detector_init_done = vlSelfRef.detector__DOT__detector_init_done;
    vlSelfRef.detector__DOT__q_ready = ((IData)(vlSelfRef.detector__DOT__initialized) 
                                        & (IData)(vlSelfRef.detector__DOT__popcounts_calculated));
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__0__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__1__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__2__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__3__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__4__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__5__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__6__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__7__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__8__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__9__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__10__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__11__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__12__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__13__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__14__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__15__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__16__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x10U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__17__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x11U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__18__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x12U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__19__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x13U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__20__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x14U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__21__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x15U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__22__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x16U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__23__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x17U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__24__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x18U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__25__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x19U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__26__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__27__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__28__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__29__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__30__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__31__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x1fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__32__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x20U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__33__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x21U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__34__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x22U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__35__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x23U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__36__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x24U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__37__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x25U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__38__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x26U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__39__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x27U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__40__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x28U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__41__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x29U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__42__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__43__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__44__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__45__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__46__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__47__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x2fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__48__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x30U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__49__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x31U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__50__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x32U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__51__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x33U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__52__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x34U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__53__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x35U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__54__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x36U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__55__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x37U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__56__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x38U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__57__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x39U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__58__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__59__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__60__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__61__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__62__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__63__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x3fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__64__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x40U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__65__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x41U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__66__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x42U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__67__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x43U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__68__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x44U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__69__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x45U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__70__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x46U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__71__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x47U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__72__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x48U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__73__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x49U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__74__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__75__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__76__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__77__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__78__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__79__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x4fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__80__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x50U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__81__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x51U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__82__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x52U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__83__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x53U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__84__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x54U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__85__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x55U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__86__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x56U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__87__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x57U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__88__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x58U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__89__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x59U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__90__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__91__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__92__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__93__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__94__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__95__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x5fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__96__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x60U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__97__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x61U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__98__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x62U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__99__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x63U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__100__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x64U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__101__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x65U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__102__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x66U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__103__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x67U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__104__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x68U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__105__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x69U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__106__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__107__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__108__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__109__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__110__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__111__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x6fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__112__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x70U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__113__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x71U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__114__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x72U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__115__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x73U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__116__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x74U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__117__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x75U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__118__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x76U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__119__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x77U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__120__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x78U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__121__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x79U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__122__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__123__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__124__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__125__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__126__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__127__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x7fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__128__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x80U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__129__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x81U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__130__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x82U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__131__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x83U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__132__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x84U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__133__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x85U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__134__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x86U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__135__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x87U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__136__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x88U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__137__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x89U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__138__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__139__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__140__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__141__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__142__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__143__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x8fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__144__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x90U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__145__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x91U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__146__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x92U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__147__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x93U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__148__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x94U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__149__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x95U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__150__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x96U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__151__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x97U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__152__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x98U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__153__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x99U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__154__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9aU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__155__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9bU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__156__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9cU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__157__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9dU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__158__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9eU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__159__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0x9fU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__160__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__161__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__162__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__163__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__164__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__165__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__166__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__167__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__168__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__169__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xa9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__170__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xaaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__171__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xabU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__172__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xacU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__173__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xadU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__174__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xaeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__175__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xafU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__176__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__177__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__178__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__179__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__180__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__181__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__182__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__183__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__184__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__185__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xb9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__186__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__187__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__188__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__189__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__190__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__191__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xbfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__192__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__193__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__194__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__195__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__196__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__197__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__198__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__199__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__200__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__201__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xc9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__202__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__203__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__204__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xccU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__205__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__206__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xceU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__207__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xcfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__208__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__209__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__210__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__211__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__212__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__213__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__214__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__215__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__216__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__217__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xd9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__218__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__219__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__220__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__221__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xddU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__222__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__223__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xdfU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__224__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__225__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__226__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__227__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__228__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__229__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__230__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__231__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__232__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__233__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xe9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__234__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xeaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__235__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xebU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__236__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xecU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__237__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xedU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__238__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xeeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__239__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xefU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__240__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf0U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__241__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf1U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__242__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf2U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__243__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf3U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__244__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf4U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__245__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf5U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__246__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf6U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__247__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__248__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf8U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__249__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xf9U];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__250__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfaU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__251__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfbU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__252__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfcU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__253__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfdU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__254__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xfeU];
    vlSelfRef.detector__DOT__tcam_core__DOT__genblk1__BRA__255__KET____DOT__mem_tmp 
        = vlSelfRef.detector__DOT__tcam_core__DOT__mem
        [0xffU];
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeU]);
    if ((1U & (~ (IData)(vlSelfRef.rst)))) {
        vlSelfRef.detector__DOT__match_d2[0U] = vlSelfRef.detector__DOT__match_d1[0U];
        vlSelfRef.detector__DOT__match_d2[1U] = vlSelfRef.detector__DOT__match_d1[1U];
        vlSelfRef.detector__DOT__match_d2[2U] = vlSelfRef.detector__DOT__match_d1[2U];
        vlSelfRef.detector__DOT__match_d2[3U] = vlSelfRef.detector__DOT__match_d1[3U];
        vlSelfRef.detector__DOT__match_d2[4U] = vlSelfRef.detector__DOT__match_d1[4U];
        vlSelfRef.detector__DOT__match_d2[5U] = vlSelfRef.detector__DOT__match_d1[5U];
        vlSelfRef.detector__DOT__match_d2[6U] = vlSelfRef.detector__DOT__match_d1[6U];
        vlSelfRef.detector__DOT__match_d2[7U] = vlSelfRef.detector__DOT__match_d1[7U];
        vlSelfRef.detector__DOT__match_d1[0U] = vlSelfRef.detector__DOT__tcam_matches[0U];
        vlSelfRef.detector__DOT__match_d1[1U] = vlSelfRef.detector__DOT__tcam_matches[1U];
        vlSelfRef.detector__DOT__match_d1[2U] = vlSelfRef.detector__DOT__tcam_matches[2U];
        vlSelfRef.detector__DOT__match_d1[3U] = vlSelfRef.detector__DOT__tcam_matches[3U];
        vlSelfRef.detector__DOT__match_d1[4U] = vlSelfRef.detector__DOT__tcam_matches[4U];
        vlSelfRef.detector__DOT__match_d1[5U] = vlSelfRef.detector__DOT__tcam_matches[5U];
        vlSelfRef.detector__DOT__match_d1[6U] = vlSelfRef.detector__DOT__tcam_matches[6U];
        vlSelfRef.detector__DOT__match_d1[7U] = vlSelfRef.detector__DOT__tcam_matches[7U];
    }
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x10U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x10U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x11U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x11U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x12U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x12U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x13U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x13U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x14U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x14U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x15U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x15U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x16U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x16U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x17U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x17U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x18U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x18U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x19U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x19U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x1fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x20U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x20U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x21U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x21U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x22U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x22U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x23U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x23U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x24U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x24U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x25U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x25U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x26U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x26U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x27U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x27U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x28U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x28U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x29U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x29U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x2fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x30U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x30U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x31U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x31U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x32U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x32U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x33U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x33U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x34U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x34U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x35U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x35U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x36U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x36U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x37U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x37U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x38U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x38U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x39U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x39U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x3fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x40U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x40U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x41U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x41U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x42U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x42U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x43U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x43U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x44U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x44U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x45U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x45U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x46U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x46U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x47U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x47U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x48U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x48U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x49U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x49U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x4fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x50U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x50U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x51U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x51U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x52U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x52U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x53U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x53U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x54U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x54U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x55U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x55U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x56U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x56U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x57U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x57U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x58U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x58U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x59U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x59U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x5fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x60U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x60U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x61U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x61U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x62U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x62U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x63U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x63U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x64U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x64U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x65U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x65U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x66U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x66U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x67U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x67U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x68U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x68U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x69U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x69U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x6fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x70U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x70U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x71U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x71U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x72U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x72U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x73U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x73U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x74U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x74U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x75U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x75U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x76U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x76U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x77U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x77U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x78U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x78U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x79U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x79U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x7fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x80U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x80U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x81U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x81U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x82U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x82U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x83U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x83U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x84U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x84U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x85U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x85U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x86U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x86U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x87U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x87U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x88U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x88U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x89U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x89U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x8fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x90U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x90U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x91U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x91U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x92U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x92U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x93U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x93U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x94U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x94U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x95U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x95U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x96U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x96U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x97U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x97U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x98U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x98U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x99U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x99U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9aU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9aU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9bU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9bU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9cU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9cU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9dU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9dU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9eU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9eU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0x9fU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9fU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xa9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xaaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xabU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xabU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xacU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xacU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xadU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xadU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xaeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xafU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xafU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xb9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xbfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xc9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xccU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xccU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xceU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xceU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xcfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xd9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xddU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xddU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xdfU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdfU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xe9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xeaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xebU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xebU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xecU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xecU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xedU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xedU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xeeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xefU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xefU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf0U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf0U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf1U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf1U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf2U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf2U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf3U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf3U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf4U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf4U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf5U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf5U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf6U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf6U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf7U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf7U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf8U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf8U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xf9U] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf9U]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfaU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfaU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfbU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfbU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfcU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfcU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfdU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfdU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xfeU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfeU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__key[0xffU] 
        = (0xffffU & vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xffU]);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x10U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x10U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x11U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x11U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x12U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x12U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x13U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x13U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x14U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x14U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x15U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x15U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x16U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x16U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x17U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x17U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x18U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x18U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x19U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x19U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x1fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x1fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x20U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x20U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x21U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x21U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x22U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x22U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x23U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x23U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x24U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x24U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x25U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x25U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x26U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x26U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x27U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x27U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x28U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x28U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x29U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x29U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x2fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x2fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x30U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x30U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x31U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x31U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x32U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x32U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x33U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x33U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x34U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x34U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x35U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x35U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x36U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x36U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x37U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x37U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x38U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x38U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x39U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x39U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x3fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x3fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x40U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x40U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x41U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x41U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x42U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x42U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x43U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x43U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x44U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x44U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x45U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x45U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x46U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x46U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x47U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x47U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x48U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x48U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x49U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x49U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x4fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x4fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x50U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x50U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x51U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x51U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x52U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x52U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x53U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x53U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x54U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x54U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x55U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x55U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x56U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x56U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x57U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x57U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x58U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x58U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x59U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x59U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x5fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x5fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x60U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x60U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x61U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x61U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x62U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x62U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x63U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x63U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x64U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x64U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x65U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x65U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x66U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x66U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x67U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x67U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x68U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x68U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x69U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x69U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x6fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x6fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x70U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x70U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x71U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x71U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x72U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x72U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x73U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x73U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x74U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x74U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x75U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x75U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x76U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x76U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x77U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x77U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x78U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x78U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x79U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x79U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x7fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x7fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x80U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x80U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x81U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x81U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x82U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x82U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x83U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x83U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x84U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x84U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x85U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x85U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x86U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x86U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x87U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x87U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x88U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x88U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x89U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x89U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x8fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x8fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x90U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x90U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x91U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x91U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x92U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x92U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x93U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x93U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x94U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x94U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x95U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x95U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x96U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x96U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x97U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x97U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x98U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x98U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x99U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x99U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9aU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9aU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9bU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9bU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9cU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9cU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9dU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9dU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9eU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9eU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0x9fU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0x9fU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xa9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xa9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xaaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xabU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xabU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xacU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xacU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xadU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xadU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xaeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xaeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xafU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xafU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xb9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xb9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xbfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xbfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xc9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xc9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xccU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xccU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xceU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xceU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xcfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xcfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xd9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xd9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xddU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xddU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xdfU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xdfU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xe9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xe9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xeaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xebU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xebU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xecU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xecU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xedU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xedU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xeeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xeeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xefU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xefU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf0U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf0U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf1U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf1U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf2U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf2U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf3U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf3U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf4U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf4U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf5U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf5U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf6U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf6U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf7U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf7U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf8U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf8U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xf9U] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xf9U] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfaU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfaU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfbU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfbU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfcU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfcU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfdU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfdU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xfeU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xfeU] >> 0x10U);
    vlSelfRef.detector__DOT__tcam_core__DOT__xmask[0xffU] 
        = (vlSelfRef.detector__DOT__tcam_core__DOT__mem
           [0xffU] >> 0x10U);
    if (__VdlySet__detector__DOT__row_popcounts__v0) {
        vlSelfRef.detector__DOT__row_popcounts[__VdlyDim0__detector__DOT__row_popcounts__v0] 
            = __VdlyVal__detector__DOT__row_popcounts__v0;
    }
    vlSelfRef.q_ready = vlSelfRef.detector__DOT__q_ready;
    vlSelfRef.detector__DOT__popcount_mem_data_out 
        = vlSelfRef.detector__DOT__row_popcounts[vlSelfRef.popcount_mem_addr];
    vlSelfRef.detector__DOT__tcam_set_valid = 0U;
    vlSelfRef.detector__DOT__tcam_set_clr = 0U;
    vlSelfRef.detector__DOT__tcam_req_valid = 0U;
    if ((1U != (IData)(vlSelfRef.detector__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.detector__DOT__state))) {
            vlSelfRef.detector__DOT__tcam_set_clr = 0U;
        }
    }
    if (vlSelfRef.q_valid) {
        vlSelfRef.detector__DOT__tcam_req_valid = 1U;
    }
    if ((1U != (IData)(vlSelfRef.detector__DOT__state))) {
        if ((2U != (IData)(vlSelfRef.detector__DOT__state))) {
            vlSelfRef.detector__DOT__tcam_req_valid = 0U;
        }
    }
    vlSelfRef.detector__DOT__tcam_addr = vlSelfRef.detector__DOT__load_counter;
    vlSelfRef.detector__DOT__next_state = ((2U & (IData)(vlSelfRef.detector__DOT__state))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.detector__DOT__state))
                                                ? (
                                                   (0xffU 
                                                    == (IData)(vlSelfRef.detector__DOT__popcount_counter))
                                                    ? 0U
                                                    : 3U)
                                                : ((IData)(vlSelfRef.q_valid)
                                                    ? 2U
                                                    : 0U))
                                            : ((1U 
                                                & (IData)(vlSelfRef.detector__DOT__state))
                                                ? (
                                                   (0xffU 
                                                    == (IData)(vlSelfRef.detector__DOT__load_counter))
                                                    ? 3U
                                                    : 1U)
                                                : ((IData)(vlSelfRef.detector__DOT__initialized)
                                                    ? 
                                                   ((IData)(vlSelfRef.detector__DOT__popcounts_calculated)
                                                     ? 
                                                    ((IData)(vlSelfRef.q_valid)
                                                      ? 2U
                                                      : 0U)
                                                     : 3U)
                                                    : 1U)));
    vlSelfRef.detector__DOT__tcam_key = 0U;
    if (vlSelfRef.q_valid) {
        vlSelfRef.detector__DOT__tcam_key = vlSelfRef.query_pattern;
        vlSelfRef.detector__DOT__tcam_xmask = 0U;
        vlSelfRef.detector__DOT__tcam_xmask = (0xffffU 
                                               & (~ (IData)(vlSelfRef.query_pattern)));
    } else {
        vlSelfRef.detector__DOT__tcam_xmask = 0U;
    }
    if ((1U == (IData)(vlSelfRef.detector__DOT__state))) {
        vlSelfRef.detector__DOT__tcam_set_valid = 1U;
        vlSelfRef.detector__DOT__tcam_addr = vlSelfRef.detector__DOT__load_counter;
        vlSelfRef.detector__DOT__tcam_key = vlSelfRef.detector__DOT__tile_buffer
            [vlSelfRef.detector__DOT__load_counter];
        vlSelfRef.detector__DOT__tcam_xmask = (0xffffU 
                                               & (~ 
                                                  vlSelfRef.detector__DOT__tile_buffer
                                                  [vlSelfRef.detector__DOT__load_counter]));
    } else if ((2U != (IData)(vlSelfRef.detector__DOT__state))) {
        vlSelfRef.detector__DOT__tcam_set_valid = 0U;
    }
    vlSelfRef.detector__DOT__tcam_matches[0U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[0U];
    vlSelfRef.detector__DOT__tcam_matches[1U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[1U];
    vlSelfRef.detector__DOT__tcam_matches[2U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[2U];
    vlSelfRef.detector__DOT__tcam_matches[3U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[3U];
    vlSelfRef.detector__DOT__tcam_matches[4U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[4U];
    vlSelfRef.detector__DOT__tcam_matches[5U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[5U];
    vlSelfRef.detector__DOT__tcam_matches[6U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[6U];
    vlSelfRef.detector__DOT__tcam_matches[7U] = vlSelfRef.detector__DOT__tcam_core__DOT__match[7U];
    vlSelfRef.detector__DOT__tcam_core__DOT__set_valid 
        = vlSelfRef.detector__DOT__tcam_set_valid;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_clr 
        = vlSelfRef.detector__DOT__tcam_set_clr;
    vlSelfRef.detector__DOT__tcam_core__DOT__req_valid 
        = vlSelfRef.detector__DOT__tcam_req_valid;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_addr 
        = vlSelfRef.detector__DOT__tcam_addr;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_key 
        = vlSelfRef.detector__DOT__tcam_key;
    vlSelfRef.detector__DOT__tcam_core__DOT__set_xmask 
        = vlSelfRef.detector__DOT__tcam_xmask;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/detector.v", 13, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/detector.v", 13, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/detector.v", 13, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY(((vlSelfRef.q_valid & 0xfeU)))) {
        Verilated::overWidthError("q_valid");}
    if (VL_UNLIKELY(((vlSelfRef.tile_mem_wr_en & 0xfeU)))) {
        Verilated::overWidthError("tile_mem_wr_en");}
    if (VL_UNLIKELY(((vlSelfRef.popcount_mem_wr_en 
                      & 0xfeU)))) {
        Verilated::overWidthError("popcount_mem_wr_en");}
}
#endif  // VL_DEBUG
