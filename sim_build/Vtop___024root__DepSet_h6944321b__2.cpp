// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_top__DOT__popcnt16__0__Vfuncout;
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_top__DOT__popcnt16__0__vec;
    __Vfunc_top__DOT__popcnt16__0__vec = 0;
    // Body
    vlSelfRef.top__DOT__fifo_in_data = (((QData)((IData)(vlSelfRef.top__DOT__u_pruner__DOT__mem_NO_out)) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          (((IData)(vlSelfRef.top__DOT__u_pruner__DOT__prefix_id) 
                                                            << 0x18U) 
                                                           | (((IData)(vlSelfRef.top__DOT__u_pruner__DOT__row_id_out) 
                                                               << 0x10U) 
                                                              | (IData)(vlSelfRef.top__DOT__u_pruner__DOT__pattern))))));
    vlSelfRef.top__DOT____Vcellinp__u_detector__q_valid 
        = ((3U == (IData)(vlSelfRef.top__DOT__state)) 
           & ((~ (IData)(vlSelfRef.top__DOT__processing_done)) 
              & (IData)(vlSelfRef.top__DOT__ready_for_new_row)));
    vlSelfRef.top__DOT____Vcellinp__u_detector__query_pattern 
        = vlSelfRef.top__DOT__tile_ram[vlSelfRef.top__DOT__row_counter];
    vlSelfRef.top__DOT__next_state = vlSelfRef.top__DOT__state;
    if ((4U & (IData)(vlSelfRef.top__DOT__state))) {
        vlSelfRef.top__DOT__next_state = 0U;
    } else if ((2U & (IData)(vlSelfRef.top__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__state))) {
            if (vlSelfRef.top__DOT__processing_done) {
                vlSelfRef.top__DOT__next_state = ((IData)(vlSelfRef.cfg_auto_repeat)
                                                   ? 1U
                                                   : 4U);
            }
        } else if (vlSelfRef.top__DOT__detector_init_done) {
            vlSelfRef.top__DOT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__state))) {
        if ((0xffU == (IData)(vlSelfRef.top__DOT__row_counter))) {
            vlSelfRef.top__DOT__next_state = 2U;
        }
    } else if (((IData)(vlSelfRef.tile_start) & (IData)(vlSelfRef.top__DOT__ppu_ready))) {
        vlSelfRef.top__DOT__next_state = 1U;
    }
    vlSelfRef.top__DOT__best_prefix = vlSelfRef.top__DOT__row_counter;
    vlSelfRef.top__DOT__best_prefix_pattern = vlSelfRef.top__DOT__tile_ram
        [vlSelfRef.top__DOT__row_counter];
    vlSelfRef.top__DOT__valid_mask[0U] = vlSelfRef.top__DOT__det_si_vec[0U];
    vlSelfRef.top__DOT__valid_mask[1U] = vlSelfRef.top__DOT__det_si_vec[1U];
    vlSelfRef.top__DOT__valid_mask[2U] = vlSelfRef.top__DOT__det_si_vec[2U];
    vlSelfRef.top__DOT__valid_mask[3U] = vlSelfRef.top__DOT__det_si_vec[3U];
    vlSelfRef.top__DOT__valid_mask[4U] = vlSelfRef.top__DOT__det_si_vec[4U];
    vlSelfRef.top__DOT__valid_mask[5U] = vlSelfRef.top__DOT__det_si_vec[5U];
    vlSelfRef.top__DOT__valid_mask[6U] = vlSelfRef.top__DOT__det_si_vec[6U];
    vlSelfRef.top__DOT__valid_mask[7U] = vlSelfRef.top__DOT__det_si_vec[7U];
    vlSelfRef.top__DOT__k = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelfRef.top__DOT__k)) {
        if (((vlSelfRef.top__DOT__valid_mask[(7U & 
                                              (vlSelfRef.top__DOT__k 
                                               >> 5U))] 
              >> (0x1fU & vlSelfRef.top__DOT__k)) & 
             (vlSelfRef.top__DOT__k != (IData)(vlSelfRef.top__DOT__row_counter)))) {
            if (((((IData)(vlSelfRef.top__DOT__best_prefix) 
                   == (IData)(vlSelfRef.top__DOT__row_counter)) 
                  | (vlSelfRef.top__DOT__popcount_ram
                     [(0xffU & vlSelfRef.top__DOT__k)] 
                     > vlSelfRef.top__DOT__popcount_ram
                     [vlSelfRef.top__DOT__best_prefix])) 
                 | ((vlSelfRef.top__DOT__popcount_ram
                     [(0xffU & vlSelfRef.top__DOT__k)] 
                     == vlSelfRef.top__DOT__popcount_ram
                     [vlSelfRef.top__DOT__best_prefix]) 
                    & (vlSelfRef.top__DOT__k < (IData)(vlSelfRef.top__DOT__best_prefix))))) {
                vlSelfRef.top__DOT__best_prefix = (0xffU 
                                                   & vlSelfRef.top__DOT__k);
                vlSelfRef.top__DOT__best_prefix_pattern 
                    = vlSelfRef.top__DOT__tile_ram[
                    (0xffU & vlSelfRef.top__DOT__k)];
            }
        }
        vlSelfRef.top__DOT__k = ((IData)(1U) + vlSelfRef.top__DOT__k);
    }
    vlSelfRef.top__DOT__output_pattern = (vlSelfRef.top__DOT__tile_ram
                                          [vlSelfRef.top__DOT__row_counter] 
                                          ^ (IData)(vlSelfRef.top__DOT__best_prefix_pattern));
    __Vfunc_top__DOT__popcnt16__0__vec = vlSelfRef.top__DOT__output_pattern;
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (1U & (IData)(__Vfunc_top__DOT__popcnt16__0__vec));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 1U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 2U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 3U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 4U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 5U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 6U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 7U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 8U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 9U))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 0xaU))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 0xbU))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 0xcU))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 0xdU))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 0xeU))));
    __Vfunc_top__DOT__popcnt16__0__Vfuncout = (0xffU 
                                               & ((IData)(__Vfunc_top__DOT__popcnt16__0__Vfuncout) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(__Vfunc_top__DOT__popcnt16__0__vec) 
                                                      >> 0xfU))));
    vlSelfRef.top__DOT__output_popcount = __Vfunc_top__DOT__popcnt16__0__Vfuncout;
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
    vlSelfRef.top__DOT__u_prn_dsp_fifo__DOT__in_data 
        = vlSelfRef.top__DOT__fifo_in_data;
    vlSelfRef.top__DOT__fifo_out_data = ((IData)(vlSelfRef.top__DOT__u_prn_dsp_fifo__DOT__full_r)
                                          ? vlSelfRef.top__DOT__u_prn_dsp_fifo__DOT__buffer_r
                                          : vlSelfRef.top__DOT__fifo_in_data);
    vlSelfRef.top__DOT__u_detector__DOT__q_valid = vlSelfRef.top__DOT____Vcellinp__u_detector__q_valid;
    vlSelfRef.top__DOT__u_detector__DOT__tcam_req_valid = 0U;
    if ((1U != (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))) {
        vlSelfRef.top__DOT__u_detector__DOT__tcam_req_valid 
            = ((2U == (IData)(vlSelfRef.top__DOT__u_detector__DOT__state)) 
               && (IData)(vlSelfRef.top__DOT____Vcellinp__u_detector__q_valid));
    }
    vlSelfRef.top__DOT__u_detector__DOT__next_state 
        = ((2U & (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))
            ? ((1U & (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))
                ? ((0xffU == (IData)(vlSelfRef.top__DOT__u_detector__DOT__popcount_counter))
                    ? 0U : 3U) : ((IData)(vlSelfRef.top__DOT____Vcellinp__u_detector__q_valid)
                                   ? 2U : 0U)) : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__u_detector__DOT__state))
                                                   ? 
                                                  ((0xffU 
                                                    == (IData)(vlSelfRef.top__DOT__u_detector__DOT__load_counter))
                                                    ? 3U
                                                    : 1U)
                                                   : 
                                                  ((IData)(vlSelfRef.top__DOT__u_detector__DOT__initialized)
                                                    ? 
                                                   ((IData)(vlSelfRef.top__DOT__u_detector__DOT__popcounts_calculated)
                                                     ? 
                                                    ((IData)(vlSelfRef.top__DOT____Vcellinp__u_detector__q_valid)
                                                      ? 2U
                                                      : 0U)
                                                     : 3U)
                                                    : 1U)));
    vlSelfRef.top__DOT__u_detector__DOT__query_pattern 
        = vlSelfRef.top__DOT____Vcellinp__u_detector__query_pattern;
    vlSelfRef.top__DOT__u_prn_dsp_fifo__DOT__out_data 
        = vlSelfRef.top__DOT__fifo_out_data;
    vlSelfRef.top__DOT__fifo_pattern = (0xffffU & (IData)(vlSelfRef.top__DOT__fifo_out_data));
    vlSelfRef.top__DOT__fifo_prefix_id = (0xffU & (IData)(
                                                          (vlSelfRef.top__DOT__fifo_out_data 
                                                           >> 0x18U)));
    vlSelfRef.top__DOT__fifo_popcnt = (0xffU & (IData)(
                                                       (vlSelfRef.top__DOT__fifo_out_data 
                                                        >> 0x20U)));
    vlSelfRef.top__DOT__fifo_row_id = (0xffU & (IData)(
                                                       (vlSelfRef.top__DOT__fifo_out_data 
                                                        >> 0x10U)));
    vlSelfRef.top__DOT__u_detector__DOT__tcam_core__DOT__req_valid 
        = vlSelfRef.top__DOT__u_detector__DOT__tcam_req_valid;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_pattern 
        = vlSelfRef.top__DOT__fifo_pattern;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_prefix_id 
        = vlSelfRef.top__DOT__fifo_prefix_id;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_popcnt 
        = vlSelfRef.top__DOT__fifo_popcnt;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_idx 
        = vlSelfRef.top__DOT__fifo_row_id;
    vlSelfRef.top__DOT__u_dispatcher__DOT__row_last 
        = (0xffU == (IData)(vlSelfRef.top__DOT__fifo_row_id));
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
void Vtop___024root___eval_act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

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
bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf);
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
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/top.v", 17, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/top.v", 17, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/top.v", 17, "", "Active region did not converge.");
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
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.cfg_enable & 0xfeU)))) {
        Verilated::overWidthError("cfg_enable");}
    if (VL_UNLIKELY(((vlSelfRef.cfg_auto_repeat & 0xfeU)))) {
        Verilated::overWidthError("cfg_auto_repeat");}
    if (VL_UNLIKELY(((vlSelfRef.tile_start & 0xfeU)))) {
        Verilated::overWidthError("tile_start");}
    if (VL_UNLIKELY(((vlSelfRef.tile_mem_wr_en & 0xfeU)))) {
        Verilated::overWidthError("tile_mem_wr_en");}
    if (VL_UNLIKELY(((vlSelfRef.pc_mem_wr_en & 0xfeU)))) {
        Verilated::overWidthError("pc_mem_wr_en");}
    if (VL_UNLIKELY(((vlSelfRef.core_ready & 0xfeU)))) {
        Verilated::overWidthError("core_ready");}
}
#endif  // VL_DEBUG
