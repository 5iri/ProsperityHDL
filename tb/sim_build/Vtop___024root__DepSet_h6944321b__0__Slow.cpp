// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9e67c271_0;

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[0U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[0U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[1U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[1U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[2U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[2U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[3U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[3U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[4U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[4U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[5U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[5U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[6U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[6U];
    vlSelfRef.top__DOT__u_pruner__DOT__cand_mask_r[7U] 
        = Vtop__ConstPool__CONST_h9e67c271_0[7U];
    vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Pre_he920b6b0_0_0 = 0U;
    vlSelfRef.top__DOT__u_pruner__DOT____VdfgBinToOneHot_Tab_he920b6b0_0_0.fill(0U);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 1U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 2U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 3U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 4U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 5U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 6U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 7U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 8U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 9U;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0xaU;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0xbU;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0xcU;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0xdU;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0xeU;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0xfU;
    vlSelfRef.top__DOT__popcnt16__Vstatic__i = 0x10U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 1U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 2U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 3U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 4U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 5U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 6U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 7U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 8U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 9U;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0xaU;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0xbU;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0xcU;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0xdU;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0xeU;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0xfU;
    vlSelfRef.top__DOT__u_processor__DOT__bit_idx = 0x10U;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__i)) {
        vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__mem[(0xffU 
                                                                  & vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__i)] = 0U;
        vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__i 
            = ((IData)(1U) + vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__i);
    }
    vlSelfRef.top__DOT__u_pruner__DOT__pruner_ready = 1U;
    vlSelfRef.top__DOT__u_dispatcher__DOT__prev_compute_busy = 0U;
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
            VL_FATAL_MT("/Users/lazybanana/github/prosperityHDL/ppu/top.v", 17, "", "Settle region did not converge.");
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
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
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
    vlSelf->cfg_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 148062765657242380ull);
    vlSelf->cfg_auto_repeat = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12017401018904262475ull);
    vlSelf->ppu_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8097355461653234154ull);
    vlSelf->ppu_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5644987291669626289ull);
    vlSelf->tile_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7204520046371388062ull);
    vlSelf->tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3324423728752466192ull);
    vlSelf->tile_mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18205962807971333319ull);
    vlSelf->tile_mem_data_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7058112006336908108ull);
    vlSelf->tile_mem_data_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13230436107644583472ull);
    vlSelf->tile_mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17614249050036567320ull);
    vlSelf->pc_mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10938140994526337491ull);
    vlSelf->pc_mem_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3429356539820076712ull);
    vlSelf->pc_mem_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6206686932208667382ull);
    vlSelf->pc_mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14668227930730900096ull);
    vlSelf->task_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2208319092310542942ull);
    vlSelf->task_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 255000589688752538ull);
    vlSelf->task_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16649161983487453779ull);
    vlSelf->task_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15519119981607992596ull);
    vlSelf->weight_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13673491808103937249ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->weight_data, __VscopeHash, 9000556573228251116ull);
    vlSelf->weight_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12349073959211784391ull);
    vlSelf->output_rd_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4881850030703572814ull);
    vlSelf->output_wr_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7272088556423801458ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->output_rd_data, __VscopeHash, 14108308959468663166ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->output_wr_data, __VscopeHash, 6621866479666801866ull);
    vlSelf->output_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7051146528772670882ull);
    vlSelf->dbg_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9035414299298431771ull);
    vlSelf->dbg_det_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14689603760226652558ull);
    vlSelf->dbg_prn_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10482013356223574951ull);
    vlSelf->dbg_dsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9033351823536069225ull);
    vlSelf->dbg_proc_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8765441647238004686ull);
    vlSelf->core_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4856537120919570224ull);
    vlSelf->top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17741742976451700217ull);
    vlSelf->top__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14231290532059103644ull);
    vlSelf->top__DOT__cfg_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7129726729197851650ull);
    vlSelf->top__DOT__cfg_auto_repeat = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1649407649553146611ull);
    vlSelf->top__DOT__ppu_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13700415170808263517ull);
    vlSelf->top__DOT__ppu_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17988772980223413072ull);
    vlSelf->top__DOT__tile_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 673206990800336814ull);
    vlSelf->top__DOT__tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18057417605776787213ull);
    vlSelf->top__DOT__tile_mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7118301711647022852ull);
    vlSelf->top__DOT__tile_mem_data_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10730823750161644640ull);
    vlSelf->top__DOT__tile_mem_data_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5330024854951899497ull);
    vlSelf->top__DOT__tile_mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5706638233360326779ull);
    vlSelf->top__DOT__pc_mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2810136558809360711ull);
    vlSelf->top__DOT__pc_mem_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13676526754456029183ull);
    vlSelf->top__DOT__pc_mem_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11798336515962083146ull);
    vlSelf->top__DOT__pc_mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13818750485680339293ull);
    vlSelf->top__DOT__task_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18263442066129435953ull);
    vlSelf->top__DOT__task_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4404281976860317705ull);
    vlSelf->top__DOT__task_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11680556403792816298ull);
    vlSelf->top__DOT__task_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4262109190183687567ull);
    vlSelf->top__DOT__weight_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1288522063135163495ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->top__DOT__weight_data, __VscopeHash, 9850274881271020948ull);
    vlSelf->top__DOT__weight_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17716662597358687835ull);
    vlSelf->top__DOT__output_rd_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13037907041531188167ull);
    vlSelf->top__DOT__output_wr_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18266034535371841613ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->top__DOT__output_rd_data, __VscopeHash, 4280449930818074617ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->top__DOT__output_wr_data, __VscopeHash, 1005465847370168155ull);
    vlSelf->top__DOT__output_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2650422311458944753ull);
    vlSelf->top__DOT__dbg_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4170806107267260862ull);
    vlSelf->top__DOT__dbg_det_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4535139227568523925ull);
    vlSelf->top__DOT__dbg_prn_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8972987861767345480ull);
    vlSelf->top__DOT__dbg_dsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8399338500799229910ull);
    vlSelf->top__DOT__dbg_proc_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3337628990630122335ull);
    vlSelf->top__DOT__core_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8791880273067806298ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__tile_ram[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16495954974713187935ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__popcount_ram[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4197369095247930343ull);
    }
    vlSelf->top__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9904540416334528851ull);
    vlSelf->top__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14234869201619147039ull);
    vlSelf->top__DOT__row_counter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4411574384168678932ull);
    vlSelf->top__DOT__processing_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 54423894756891144ull);
    vlSelf->top__DOT__det_q_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12438556161939930685ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__det_si_vec, __VscopeHash, 5055911911523508312ull);
    vlSelf->top__DOT__det_si_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6917349905481289344ull);
    vlSelf->top__DOT__det_done_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7636098719848807062ull);
    vlSelf->top__DOT__det_row_pc = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11947316087453992430ull);
    vlSelf->top__DOT__detector_init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6768646891061409585ull);
    vlSelf->top__DOT____Vcellinp__u_detector__q_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17543029507019874420ull);
    vlSelf->top__DOT____Vcellinp__u_detector__query_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8892609247630679871ull);
    vlSelf->top__DOT__prn_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1625591246460497212ull);
    vlSelf->top__DOT__prn_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5214090689872261744ull);
    vlSelf->top__DOT__prn_popcnt = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15372428206201467715ull);
    vlSelf->top__DOT__row_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5054226101120968789ull);
    vlSelf->top__DOT__ready_for_new_row = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6040108121654954228ull);
    vlSelf->top__DOT__prune_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17994930612852785961ull);
    vlSelf->top__DOT__prn_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8053459429054389726ull);
    vlSelf->top__DOT__prn_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10260701243959990648ull);
    vlSelf->top__DOT__prn_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13718731351601903612ull);
    vlSelf->top__DOT____Vcellinp__u_pruner__mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7761579325432784995ull);
    vlSelf->top__DOT____Vcellinp__u_pruner__mem_NO_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14459988826926333013ull);
    vlSelf->top__DOT____Vcellinp__u_pruner__mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8744336306345608921ull);
    vlSelf->top__DOT__dsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5541536709548981517ull);
    vlSelf->top__DOT__dsp_tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 210005579913768204ull);
    vlSelf->top__DOT__pattern_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10918543762504184766ull);
    vlSelf->top__DOT__row_idx_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 484732059727601385ull);
    vlSelf->top__DOT__prefix_id_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7247196203413743327ull);
    vlSelf->top__DOT__row_popcnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1676145922149991498ull);
    vlSelf->top__DOT__prn_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10552063884230077831ull);
    vlSelf->top__DOT__best_prefix = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10797587199116868119ull);
    vlSelf->top__DOT__best_prefix_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4063110026877814872ull);
    vlSelf->top__DOT__output_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15758508325490006112ull);
    vlSelf->top__DOT__output_popcount = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17961038536481921027ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__valid_mask, __VscopeHash, 13805854516856943022ull);
    vlSelf->top__DOT__k = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13868248131636257204ull);
    vlSelf->top__DOT__proc_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6900188941622560853ull);
    vlSelf->top__DOT__proc_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17747974711381230625ull);
    vlSelf->top__DOT__proc_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3723940268009662628ull);
    vlSelf->top__DOT__popcnt16__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14454973770188890217ull);
    vlSelf->top__DOT__u_detector__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7535789608001530229ull);
    vlSelf->top__DOT__u_detector__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5729795523647101704ull);
    vlSelf->top__DOT__u_detector__DOT__query_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17104680977139854059ull);
    vlSelf->top__DOT__u_detector__DOT__q_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5673076739462296923ull);
    vlSelf->top__DOT__u_detector__DOT__q_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13392010609299098783ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_detector__DOT__si_vec, __VscopeHash, 12118997578512320590ull);
    vlSelf->top__DOT__u_detector__DOT__si_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11433688318489115123ull);
    vlSelf->top__DOT__u_detector__DOT__det_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4103880916694596073ull);
    vlSelf->top__DOT__u_detector__DOT__row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10560395504174649039ull);
    vlSelf->top__DOT__u_detector__DOT__row_popcnt = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7568923789683851032ull);
    vlSelf->top__DOT__u_detector__DOT__detector_init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8556401061535223636ull);
    vlSelf->top__DOT__u_detector__DOT__tile_mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16223784718148082498ull);
    vlSelf->top__DOT__u_detector__DOT__tile_mem_data_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12131818267702801605ull);
    vlSelf->top__DOT__u_detector__DOT__tile_mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 950698339913495130ull);
    vlSelf->top__DOT__u_detector__DOT__popcount_mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11433873711503390397ull);
    vlSelf->top__DOT__u_detector__DOT__popcount_mem_data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1684081911094931129ull);
    vlSelf->top__DOT__u_detector__DOT__popcount_mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11896996521684444021ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_detector__DOT__tile_buffer[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1670929765802398912ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_detector__DOT__row_popcounts[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17550336039458146254ull);
    }
    vlSelf->top__DOT__u_detector__DOT__popcounts_calculated = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3709709932833592627ull);
    vlSelf->top__DOT__u_detector__DOT__popcount_loop_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8776239097254416794ull);
    vlSelf->top__DOT__u_detector__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18244124976704599806ull);
    vlSelf->top__DOT__u_detector__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5097409708778111159ull);
    vlSelf->top__DOT__u_detector__DOT__load_counter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11331011728574268655ull);
    vlSelf->top__DOT__u_detector__DOT__popcount_counter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12269811160866122088ull);
    vlSelf->top__DOT__u_detector__DOT__query_reg = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2752918667702880267ull);
    vlSelf->top__DOT__u_detector__DOT__initialized = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5496162025287031068ull);
    vlSelf->top__DOT__u_detector__DOT__query_in_progress = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7043461988693350079ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_key = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 381711524981892163ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_xmask = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5171275812019927673ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2272285341431293072ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_set_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8745997039975968848ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_set_clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17296864426290395098ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11712474777840831241ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_detector__DOT__tcam_matches, __VscopeHash, 16204012936781130170ull);
    vlSelf->top__DOT__u_detector__DOT__tile_mem_data_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4818101699158263148ull);
    vlSelf->top__DOT__u_detector__DOT__popcount_mem_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12711683460118203844ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5622705849234057729ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5878002604695445469ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__set_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4357280766081913129ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__set_key = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7088458265220036310ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__set_xmask = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2631802957480989130ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__set_clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17479251890614328691ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__set_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5081952216207667418ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__req_key = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10053908881730107653ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16865099896171812445ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__line_match, __VscopeHash, 7321110410878841027ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10201111474181551209ull);
    }
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__active, __VscopeHash, 2916770145444206976ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__match, __VscopeHash, 2156046056679851539ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__key[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14260651100752630760ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__xmask[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13164842950406582550ull);
    }
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11967010467993650071ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__0__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2736223072899119672ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__1__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1319349567933497662ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__2__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11834495812541072669ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__3__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10758082051345912930ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__4__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7027525677696386049ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__5__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9685071514342859787ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__6__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13281837084645895383ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__7__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11583199824055881494ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__8__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7808061110658837861ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__9__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3356167926321738058ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__10__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9437903177697834804ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__11__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15208561196508671543ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__12__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4314609512642660464ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__13__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16196484999390957167ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__14__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3231978177061033449ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__15__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11499525538949774675ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__16__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16834508526372060542ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__17__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5123519693958808717ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__18__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3231717752426352294ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__19__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12022082092966233096ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__20__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18288345727429305778ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__21__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9823472586686395407ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__22__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4830810883311379054ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__23__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 568607333900390856ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__24__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3292064672925012603ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__25__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1434410348368737762ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__26__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15155980322721632366ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__27__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15657160986417315750ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__28__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12118680724590272929ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__29__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14922684007994071434ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__30__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2274433107343220127ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__31__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18044071781930705643ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__32__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15791913811306829794ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__33__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9127542374063735007ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__34__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15118732564939190958ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__35__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7054605185825953205ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__36__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8560453112114873902ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__37__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1616076962718087597ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__38__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6444857680750378220ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__39__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7438101181933489438ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__40__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11727811368214167046ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__41__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7804184997891702354ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__42__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9656386916400304893ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__43__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3609745323187673741ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__44__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16906309500433624249ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__45__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3264281070191418308ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__46__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2549635233477556852ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__47__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3955686616361540077ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__48__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13435631642863547919ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__49__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18098799584556528326ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__50__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5583982310290883863ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__51__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9273274424124052218ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__52__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10795491334612127223ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__53__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1162085359928110709ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__54__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11976194066042074747ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__55__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10264038593870181396ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__56__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3383931804734601384ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__57__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4539672713131659357ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__58__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9792845163966533157ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__59__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7639714424866922472ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__60__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1697944633210040346ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__61__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2077426752753686858ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__62__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10693388182978572079ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__63__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3286612478531374535ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__64__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12323543511191703458ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__65__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1539339760199720817ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__66__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11365643963072903661ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__67__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 242440092744419731ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__68__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7796944898954573181ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__69__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12179836986138451065ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__70__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10619765095243546914ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__71__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 481043467359089302ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__72__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14029955006236353011ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__73__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17426572041155812768ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__74__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 572725362637757218ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__75__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12036034686476502983ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__76__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10818755355075252589ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__77__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12843042893026965497ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__78__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5837965052905906046ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__79__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12072752162051707436ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__80__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12332865561335494055ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__81__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12119127872238169679ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__82__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15963078683389546710ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__83__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5909738287050798518ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__84__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 586318377123064985ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__85__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15555142063629803246ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__86__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4609336771751618868ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__87__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15973222886402750849ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__88__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1706937088212337733ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__89__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8893794052930237525ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__90__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12108884425758854013ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__91__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5271676679665399274ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__92__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1189186255943437627ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__93__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13009987451713076626ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__94__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8225523697195468412ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__95__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10181411041176995005ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__96__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16271814854236912445ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__97__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12821076507219654404ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__98__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12413963239140151261ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__99__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3354173894502097137ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__100__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14755992989535918097ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__101__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8713341403294409793ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__102__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14970459722656692281ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__103__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2375974794073197367ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__104__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13325968726170575119ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__105__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1839360123734370602ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__106__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 25924572247197219ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__107__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2653206388030121840ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__108__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5304893990454728163ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__109__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9459402137693143034ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__110__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12053167118021565191ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__111__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5004550947575846400ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__112__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12335918821050590445ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__113__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 888760097626787672ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__114__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12703846450811583231ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__115__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11311823258763571394ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__116__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14937997678083356114ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__117__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13181054616382041830ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__118__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7995125180166903386ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__119__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1565025591948342193ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__120__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16818643139251717606ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__121__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16386476600199573830ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__122__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3079294736572958034ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__123__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9390846010641182382ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__124__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11058247553006828576ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__125__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3624740627156090980ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__126__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5824391538604950519ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__127__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3305699656738793967ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__128__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18414554549082605487ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__129__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4118168867846382915ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__130__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3610809990067585236ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__131__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14170940776519503316ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__132__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17837858065817444383ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__133__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16974494412729383661ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__134__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5603636602477378551ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__135__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6977941245123477647ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__136__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4499845707591848624ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__137__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1046980732945549279ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__138__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16009474595439903534ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__139__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1214704776882330478ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__140__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7612879901232199406ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__141__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2668277940934175832ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__142__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7322401129505891427ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__143__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11577164178059176590ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__144__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14565292652027322688ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__145__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1365098967888386133ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__146__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8439829285084695997ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__147__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17883218039505504028ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__148__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17197561367697491313ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__149__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10637673928810188085ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__150__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2224214551768619019ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__151__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13373353763921785099ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__152__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7078994194836469854ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__153__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10785054078893988115ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__154__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4388667971856398310ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__155__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1590982344404835343ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__156__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7445464723802440579ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__157__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7937440831420724722ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__158__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3994843938213367822ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__159__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7625742020845085041ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__160__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11303755910526169511ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__161__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14200340953794832476ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__162__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7702955408564077403ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__163__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8893464824431557228ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__164__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17443575241052862756ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__165__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12564607873629200930ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__166__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1854240889293306149ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__167__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8224928902999912676ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__168__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7856614005639272104ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__169__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15753275448654565424ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__170__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12911175577439823672ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__171__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 965654143311679336ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__172__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7968596753201126850ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__173__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17456077346193488279ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__174__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11882312855688335903ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__175__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12575744794850496419ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__176__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13110149047469238571ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__177__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1325328662663777163ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__178__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 991382357476980636ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__179__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 688177382995063680ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__180__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5976291719701750081ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__181__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3496479326188580235ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__182__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8874339595000982977ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__183__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16783505175566173480ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__184__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7536928055243731028ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__185__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7670090058760139931ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__186__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4043710793205362991ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__187__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11130319190587653192ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__188__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3630316085739878676ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__189__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5212058978176899077ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__190__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12232872015261654410ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__191__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7728964702406855117ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__192__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1392912234972312737ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__193__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16828707851839094208ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__194__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5478073716078815286ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__195__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7378909778314444368ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__196__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 22679184997158491ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__197__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5276272219732420424ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__198__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17988039366058214177ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__199__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10326570445625775229ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__200__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2165542199936123635ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__201__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8363787110968330598ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__202__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5272854249123341048ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__203__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9028124509545713032ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__204__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10110701203441327352ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__205__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16838981695536084342ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__206__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14420178801135727466ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__207__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7565196554491309083ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__208__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4265802235655257186ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__209__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7415073648919508334ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__210__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15045134841634662511ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__211__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8374174577453728808ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__212__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7254827539426131636ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__213__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16032095170465930492ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__214__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16652417045113631786ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__215__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15292813197089065503ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__216__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1032224680197646577ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__217__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14959695028855019789ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__218__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9018842866874996761ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__219__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17777391729820792271ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__220__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16470979504073411321ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__221__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1728990107230468204ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__222__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17031114433558743405ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__223__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15580192620378899479ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__224__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15709197061555214294ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__225__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12802513240118463432ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__226__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17921331847383493578ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__227__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11116153415459134994ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__228__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14357362487050718634ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__229__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14065673954096934906ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__230__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5678226021871409823ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__231__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17010404353773969445ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__232__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11631362774022835115ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__233__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13040563932315225570ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__234__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6182997477163887387ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__235__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8372019952189181609ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__236__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8483915643165554273ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__237__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16418416698007120881ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__238__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10366280594434766398ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__239__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2545362827008180418ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__240__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15516733864249140605ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__241__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17385281538811662481ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__242__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2868949356864827102ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__243__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12493674766601314169ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__244__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11054721961760557516ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__245__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10674435403838723047ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__246__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14130659519671956450ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__247__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3490938065174591963ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__248__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4714009326139512362ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__249__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6327777747975939747ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__250__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1727141216147820904ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__251__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9226203363740001866ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__252__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12448862370379634428ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__253__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5503820862955348142ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__254__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7902511750211275641ull);
    vlSelf->top__DOT__u_detector__DOT__tcam_core__DOT__genblk1__BRA__255__KET____DOT__mem_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11497228611430530920ull);
    vlSelf->top__DOT__u_pruner__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2413592699425578922ull);
    vlSelf->top__DOT__u_pruner__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17056732215258736742ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_pruner__DOT__si_vector, __VscopeHash, 7847888425092313461ull);
    vlSelf->top__DOT__u_pruner__DOT__row_index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1920367388024200887ull);
    vlSelf->top__DOT__u_pruner__DOT__row_NO = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16648355865689127335ull);
    vlSelf->top__DOT__u_pruner__DOT__si_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17117597838706586546ull);
    vlSelf->top__DOT__u_pruner__DOT__pruner_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2230591110988774763ull);
    vlSelf->top__DOT__u_pruner__DOT__prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6859002961191271548ull);
    vlSelf->top__DOT__u_pruner__DOT__row_id_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12461711995086304900ull);
    vlSelf->top__DOT__u_pruner__DOT__pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2420819031492529615ull);
    vlSelf->top__DOT__u_pruner__DOT__prune_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6229346483479308721ull);
    vlSelf->top__DOT__u_pruner__DOT__prune_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10727134307663795350ull);
    vlSelf->top__DOT__u_pruner__DOT__dispatch_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1036573215928467072ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11441536872613589364ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_NO_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12996596784540336682ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_spike_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11850615712399889181ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_NO_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12525964909364615731ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_spike_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10561917020595301719ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2977523571012627941ull);
    vlSelf->top__DOT__u_pruner__DOT__mem_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8782156640647384862ull);
    vlSelf->top__DOT__u_pruner__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8025193808443855105ull);
    vlSelf->top__DOT__u_pruner__DOT__row_counter = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1293745228286787008ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_pruner__DOT__si_vec_r, __VscopeHash, 13777060836186763179ull);
    vlSelf->top__DOT__u_pruner__DOT__row_idx_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3141840783354989242ull);
    vlSelf->top__DOT__u_pruner__DOT__row_NO_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13321432924517257083ull);
    vlSelf->top__DOT__u_pruner__DOT__cur_spikes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12953695609925224441ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__NO_table[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5337437799249557131ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__spike_matrix[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6513088834400189989ull);
    }
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_pruner__DOT__valid_mask, __VscopeHash, 6024508108437373840ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_pruner__DOT__cand_mask_r, __VscopeHash, 12264538805676829662ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__best_idx_lvl0[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15479575850482036303ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__best_NO_lvl0[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13164456632985676216ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__best_idx_lvl1[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1265423597304318106ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__best_NO_lvl1[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15740534551442609042ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__best_idx_lvl2[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12089334112371008107ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__u_pruner__DOT__best_NO_lvl2[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 601785591018881827ull);
    }
    vlSelf->top__DOT__u_pruner__DOT__best_idx_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13630546494694418075ull);
    vlSelf->top__DOT__u_pruner__DOT__best_NO_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6219825462677181910ull);
    vlSelf->top__DOT__u_pruner__DOT__pre_spikes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3539049951859038979ull);
    vlSelf->top__DOT__u_pruner__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15466620471721594021ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->top__DOT__u_pruner__DOT__st0_si_vec, __VscopeHash, 18378165093236948276ull);
    vlSelf->top__DOT__u_pruner__DOT__st0_row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10322662704322596894ull);
    vlSelf->top__DOT__u_pruner__DOT__st1_row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8013716024415267205ull);
    vlSelf->top__DOT__u_pruner__DOT__st2_row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 432620101683699879ull);
    vlSelf->top__DOT__u_pruner__DOT__st0_row_NO = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4545648779247151070ull);
    vlSelf->top__DOT__u_pruner__DOT__st0_row_spikes = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7990822145026683406ull);
    vlSelf->top__DOT__u_pruner__DOT__st1_row_spikes = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1339126549846344190ull);
    vlSelf->top__DOT__u_pruner__DOT__st1_pre_spikes = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6392446805757071142ull);
    vlSelf->top__DOT__u_pruner__DOT__st2_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2925419410054865872ull);
    vlSelf->top__DOT__u_pruner__DOT__st1_prefix_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16887802824681658327ull);
    vlSelf->top__DOT__u_pruner__DOT__st2_prefix_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7040693976434132995ull);
    vlSelf->top__DOT__u_pruner__DOT__st0_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10955668954347706843ull);
    vlSelf->top__DOT__u_pruner__DOT__st1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5071627434356370423ull);
    vlSelf->top__DOT__u_pruner__DOT__st2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 115156601513533606ull);
    vlSelf->top__DOT__u_pruner__DOT__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5260223504568802016ull);
    vlSelf->top__DOT__u_pruner__DOT__best_idx_comb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1715840399075594903ull);
    vlSelf->top__DOT__u_pruner__DOT__best_no_comb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16608896395856490116ull);
    vlSelf->top__DOT__u_pruner__DOT__best_spikes_comb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5502901361076410088ull);
    vlSelf->top__DOT__u_pruner__DOT__out_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4703645131180498546ull);
    vlSelf->top__DOT__u_dispatcher__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1816027091247585750ull);
    vlSelf->top__DOT__u_dispatcher__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4481767917828888639ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_info_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12175685109797838155ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_info_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15151795699096770393ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_idx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17647845427881077878ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4273570890643235611ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1039289282807408053ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_popcnt = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6590164363688239978ull);
    vlSelf->top__DOT__u_dispatcher__DOT__row_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10216777339857420912ull);
    vlSelf->top__DOT__u_dispatcher__DOT__proc_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3131232209853437039ull);
    vlSelf->top__DOT__u_dispatcher__DOT__task_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7799082896414757837ull);
    vlSelf->top__DOT__u_dispatcher__DOT__task_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5094045751860471568ull);
    vlSelf->top__DOT__u_dispatcher__DOT__task_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16304694241882661536ull);
    vlSelf->top__DOT__u_dispatcher__DOT__task_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9738360809860673194ull);
    vlSelf->top__DOT__u_dispatcher__DOT__prev_compute_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8840256740955919089ull);
    vlSelf->top__DOT__u_dispatcher__DOT__pruner_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15809833524662196099ull);
    vlSelf->top__DOT__u_dispatcher__DOT__tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13543765305087383866ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__pst_prefix_id[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 497077304252425493ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__pst_pattern[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6600841224102656330ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__pst_popcnt[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5123051793332582028ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__pst_row_id[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14755876732264817921ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__pst_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6362552334240327449ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__sort_row_id[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9647934610916233355ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__sort_popcnt[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4471228620725346349ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__u_dispatcher__DOT__collected_rows[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11006568001879013824ull);
    }
    vlSelf->top__DOT__u_dispatcher__DOT__temp_pc = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3071118030492697702ull);
    vlSelf->top__DOT__u_dispatcher__DOT__temp_row = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5579356454450130140ull);
    vlSelf->top__DOT__u_dispatcher__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2432934572078827464ull);
    vlSelf->top__DOT__u_dispatcher__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18165198974450653471ull);
    vlSelf->top__DOT__u_dispatcher__DOT__collect_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15815105641713533448ull);
    vlSelf->top__DOT__u_dispatcher__DOT__dispatch_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 18069827344635987583ull);
    vlSelf->top__DOT__u_dispatcher__DOT__sort_count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13803924126114936114ull);
    vlSelf->top__DOT__u_dispatcher__DOT__last_row_seen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9244077829205285162ull);
    vlSelf->top__DOT__u_dispatcher__DOT__timeout_counter = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1468708195523689592ull);
    vlSelf->top__DOT__u_dispatcher__DOT__collect_timeout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14266553164792984581ull);
    vlSelf->top__DOT__u_dispatcher__DOT__sort_stage = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14051306693324959262ull);
    vlSelf->top__DOT__u_dispatcher__DOT__sort_temp_pc = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9461060909796331199ull);
    vlSelf->top__DOT__u_dispatcher__DOT__sort_temp_row = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9425136750763906546ull);
    vlSelf->top__DOT__u_dispatcher__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17607958959888626445ull);
    vlSelf->top__DOT__u_dispatcher__DOT__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7435780209427211180ull);
    vlSelf->top__DOT__u_dispatcher__DOT__current_row = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8192245800664621882ull);
    vlSelf->top__DOT__u_dispatcher__DOT__min_idx_found = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3115498898270693951ull);
    vlSelf->top__DOT__u_dispatcher__DOT__min_pc_found = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17617096094490284706ull);
    vlSelf->top__DOT__u_dispatcher__DOT__min_row_found = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7440360136450756202ull);
    vlSelf->top__DOT__u_processor__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16099194919483855997ull);
    vlSelf->top__DOT__u_processor__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2626748236692175758ull);
    vlSelf->top__DOT__u_processor__DOT__task_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6916287275054381415ull);
    vlSelf->top__DOT__u_processor__DOT__task_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6985975324948252580ull);
    vlSelf->top__DOT__u_processor__DOT__task_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10642882939421190744ull);
    vlSelf->top__DOT__u_processor__DOT__task_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5899134456838818982ull);
    vlSelf->top__DOT__u_processor__DOT__task_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6431800395331216131ull);
    vlSelf->top__DOT__u_processor__DOT__weight_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3797655004733569338ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->top__DOT__u_processor__DOT__weight_data, __VscopeHash, 13449181353484790446ull);
    vlSelf->top__DOT__u_processor__DOT__weight_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13780232212614160845ull);
    vlSelf->top__DOT__u_processor__DOT__output_rd_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6382194449015871189ull);
    vlSelf->top__DOT__u_processor__DOT__output_wr_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5516607720483826854ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->top__DOT__u_processor__DOT__output_rd_data, __VscopeHash, 17568442084441757184ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->top__DOT__u_processor__DOT__output_wr_data, __VscopeHash, 3522280150198985561ull);
    vlSelf->top__DOT__u_processor__DOT__output_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6639018026032170852ull);
    vlSelf->top__DOT__u_processor__DOT__proc_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3299152924262442343ull);
    vlSelf->top__DOT__u_processor__DOT__proc_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6884424186379613865ull);
    vlSelf->top__DOT__u_processor__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15277589513411886309ull);
    vlSelf->top__DOT__u_processor__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8596803439188855459ull);
    vlSelf->top__DOT__u_processor__DOT__current_row_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11386530174366837807ull);
    vlSelf->top__DOT__u_processor__DOT__current_prefix_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1246449657487810218ull);
    vlSelf->top__DOT__u_processor__DOT__current_pattern = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18323899131569300256ull);
    vlSelf->top__DOT__u_processor__DOT__pattern_working = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10904886883379145198ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->top__DOT__u_processor__DOT__pe_partial_sum[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1223284648289174597ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->top__DOT__u_processor__DOT__pe_weight[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1882164347914720021ull);
    }
    vlSelf->top__DOT__u_processor__DOT__pe_accumulate_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12553307912374068199ull);
    vlSelf->top__DOT__u_processor__DOT__current_spike_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 255535215756277839ull);
    vlSelf->top__DOT__u_processor__DOT__spike_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16357498204210373392ull);
    vlSelf->top__DOT__u_processor__DOT__pattern_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 48926362392931117ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->top__DOT__u_processor__DOT__prefix_result, __VscopeHash, 594314237081191363ull);
    vlSelf->top__DOT__u_processor__DOT__prefix_loaded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5408146334408354142ull);
    vlSelf->top__DOT__u_processor__DOT__writeback_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17085285649104796344ull);
    vlSelf->top__DOT__u_processor__DOT__bit_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8499892725410589103ull);
    vlSelf->__VdlyVal__top__DOT__u_pruner__DOT__spike_matrix__v0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 990018650981351724ull);
    vlSelf->__VdlyDim0__top__DOT__u_pruner__DOT__spike_matrix__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 349236346995546170ull);
    vlSelf->__VdlySet__top__DOT__u_pruner__DOT__spike_matrix__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14803524876191471008ull);
}
