// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/dispatcher.v", 12, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->row_info_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1883170573452382083ull);
    vlSelf->row_info_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16528620356944377589ull);
    vlSelf->row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3816350678443656888ull);
    vlSelf->row_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5278901581857571541ull);
    vlSelf->row_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3809075614728449700ull);
    vlSelf->row_popcnt = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10848223048669083132ull);
    vlSelf->row_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1895516489951867507ull);
    vlSelf->proc_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11151984481060947938ull);
    vlSelf->task_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2208319092310542942ull);
    vlSelf->task_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 255000589688752538ull);
    vlSelf->task_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16649161983487453779ull);
    vlSelf->task_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15519119981607992596ull);
    vlSelf->prev_compute_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17563205294455735550ull);
    vlSelf->pruner_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1427038484142858261ull);
    vlSelf->tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3324423728752466192ull);
    vlSelf->dispatcher__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14710886091623516143ull);
    vlSelf->dispatcher__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10840949012919365538ull);
    vlSelf->dispatcher__DOT__row_info_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13041038071384445229ull);
    vlSelf->dispatcher__DOT__row_info_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3878947600084999024ull);
    vlSelf->dispatcher__DOT__row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7586501215804908324ull);
    vlSelf->dispatcher__DOT__row_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 49076240926705185ull);
    vlSelf->dispatcher__DOT__row_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6909231387122244068ull);
    vlSelf->dispatcher__DOT__row_popcnt = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17749450822170822475ull);
    vlSelf->dispatcher__DOT__row_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2581310717237977060ull);
    vlSelf->dispatcher__DOT__proc_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5763793060741290579ull);
    vlSelf->dispatcher__DOT__task_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1775681314342887615ull);
    vlSelf->dispatcher__DOT__task_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16518608922294310628ull);
    vlSelf->dispatcher__DOT__task_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9411929046576782384ull);
    vlSelf->dispatcher__DOT__task_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14822011011820842748ull);
    vlSelf->dispatcher__DOT__prev_compute_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11725324645563970770ull);
    vlSelf->dispatcher__DOT__pruner_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3600489704763925619ull);
    vlSelf->dispatcher__DOT__tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 788238545463626399ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__pst_prefix_id[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17689639311027735715ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__pst_pattern[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10222627853336237613ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__pst_popcnt[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4719750705155224756ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__pst_row_id[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4404731981788410980ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__pst_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10094363087496657122ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__sort_row_id[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13231774359034377144ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__sort_popcnt[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10997024209597320886ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dispatcher__DOT__collected_rows[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13119739917644053227ull);
    }
    vlSelf->dispatcher__DOT__temp_pc = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12213504870709784025ull);
    vlSelf->dispatcher__DOT__temp_row = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 983788621486254155ull);
    vlSelf->dispatcher__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1492769352764140304ull);
    vlSelf->dispatcher__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12556877792116598428ull);
    vlSelf->dispatcher__DOT__collect_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4143148031215690832ull);
    vlSelf->dispatcher__DOT__dispatch_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15847752532055240168ull);
    vlSelf->dispatcher__DOT__sort_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3374227003214234784ull);
    vlSelf->dispatcher__DOT__last_row_seen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3417849619282014475ull);
    vlSelf->dispatcher__DOT__timeout_counter = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15545372776562442499ull);
    vlSelf->dispatcher__DOT__collect_timeout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6967402337926540367ull);
    vlSelf->dispatcher__DOT__sort_stage = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16511947595232275658ull);
    vlSelf->dispatcher__DOT__sort_temp_pc = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3560794539654478721ull);
    vlSelf->dispatcher__DOT__sort_temp_row = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3753772847587984612ull);
    vlSelf->dispatcher__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1149272075272679210ull);
    vlSelf->dispatcher__DOT__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1213784768259107412ull);
    vlSelf->dispatcher__DOT__current_row = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 333776469846113396ull);
    vlSelf->dispatcher__DOT__min_idx_found = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16180794894159027682ull);
    vlSelf->dispatcher__DOT__min_pc_found = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14050837393915891729ull);
    vlSelf->dispatcher__DOT__min_row_found = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7815268638573217451ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14803524876191471008ull);
}
