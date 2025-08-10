// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vdly__pruner__DOT__out_count;
    __Vdly__pruner__DOT__out_count = 0;
    // Body
    __Vdly__pruner__DOT__out_count = vlSelfRef.pruner__DOT__out_count;
    if (vlSelfRef.rst_n) {
        vlSelfRef.pruner__DOT__prune_done = 0U;
        if (((IData)(vlSelfRef.pruner__DOT__st2_valid) 
             & (IData)(vlSelfRef.dispatch_ready))) {
            if ((0xffU == (IData)(vlSelfRef.pruner__DOT__out_count))) {
                vlSelfRef.pruner__DOT__prune_done = 1U;
                __Vdly__pruner__DOT__out_count = 0U;
            } else {
                __Vdly__pruner__DOT__out_count = (0x1ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.pruner__DOT__out_count)));
            }
            vlSelfRef.pruner__DOT__row_id_out = vlSelfRef.pruner__DOT__st2_row_idx;
            vlSelfRef.pruner__DOT__prefix_id = vlSelfRef.pruner__DOT__st2_prefix_idx;
            vlSelfRef.pruner__DOT__pattern = vlSelfRef.pruner__DOT__st2_pattern;
            vlSelfRef.pruner__DOT__prune_valid = 1U;
        } else {
            vlSelfRef.pruner__DOT__prune_valid = 0U;
        }
        if (vlSelfRef.pruner__DOT__st1_valid) {
            vlSelfRef.pruner__DOT__st2_prefix_idx = vlSelfRef.pruner__DOT__st1_prefix_idx;
            vlSelfRef.pruner__DOT__st2_row_idx = vlSelfRef.pruner__DOT__st1_row_idx;
            vlSelfRef.pruner__DOT__st2_pattern = ((IData)(vlSelfRef.pruner__DOT__st1_row_spikes) 
                                                  ^ (IData)(vlSelfRef.pruner__DOT__st1_pre_spikes));
        }
        vlSelfRef.pruner__DOT__st1_prefix_idx = vlSelfRef.pruner__DOT__best_idx_comb;
        vlSelfRef.pruner__DOT__st1_row_idx = vlSelfRef.pruner__DOT__st0_row_idx;
        vlSelfRef.pruner__DOT__st1_pre_spikes = vlSelfRef.pruner__DOT__best_spikes_comb;
        vlSelfRef.pruner__DOT__st1_row_spikes = vlSelfRef.pruner__DOT__st0_row_spikes;
        if (vlSelfRef.si_valid) {
            vlSelfRef.pruner__DOT__st0_si_vec[0U] = 
                vlSelfRef.si_vector[0U];
            vlSelfRef.pruner__DOT__st0_si_vec[1U] = 
                vlSelfRef.si_vector[1U];
            vlSelfRef.pruner__DOT__st0_si_vec[2U] = 
                vlSelfRef.si_vector[2U];
            vlSelfRef.pruner__DOT__st0_si_vec[3U] = 
                vlSelfRef.si_vector[3U];
            vlSelfRef.pruner__DOT__st0_si_vec[4U] = 
                vlSelfRef.si_vector[4U];
            vlSelfRef.pruner__DOT__st0_si_vec[5U] = 
                vlSelfRef.si_vector[5U];
            vlSelfRef.pruner__DOT__st0_si_vec[6U] = 
                vlSelfRef.si_vector[6U];
            vlSelfRef.pruner__DOT__st0_si_vec[7U] = 
                vlSelfRef.si_vector[7U];
            vlSelfRef.pruner__DOT__st0_row_NO = vlSelfRef.row_NO;
            vlSelfRef.pruner__DOT__st0_row_idx = vlSelfRef.row_index;
            vlSelfRef.pruner__DOT__st0_row_spikes = 
                vlSelfRef.pruner__DOT__spike_matrix
                [vlSelfRef.row_index];
        }
    } else {
        __Vdly__pruner__DOT__out_count = 0U;
        vlSelfRef.pruner__DOT__prune_done = 0U;
        vlSelfRef.pruner__DOT__prune_valid = 0U;
        vlSelfRef.pruner__DOT__row_id_out = 0U;
        vlSelfRef.pruner__DOT__prefix_id = 0U;
        vlSelfRef.pruner__DOT__pattern = 0U;
    }
    vlSelfRef.pruner__DOT__out_count = __Vdly__pruner__DOT__out_count;
    vlSelfRef.prune_done = vlSelfRef.pruner__DOT__prune_done;
    vlSelfRef.row_id_out = vlSelfRef.pruner__DOT__row_id_out;
    vlSelfRef.prefix_id = vlSelfRef.pruner__DOT__prefix_id;
    vlSelfRef.pattern = vlSelfRef.pruner__DOT__pattern;
    vlSelfRef.prune_valid = vlSelfRef.pruner__DOT__prune_valid;
    vlSelfRef.pruner__DOT__st2_valid = ((IData)(vlSelfRef.rst_n) 
                                        && (IData)(vlSelfRef.pruner__DOT__st1_valid));
    vlSelfRef.pruner__DOT__st1_valid = ((IData)(vlSelfRef.rst_n) 
                                        && (IData)(vlSelfRef.pruner__DOT__st0_valid));
    vlSelfRef.pruner__DOT__st0_valid = ((IData)(vlSelfRef.rst_n) 
                                        && (IData)(vlSelfRef.si_valid));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__pruner__DOT__spike_matrix__v0) {
        vlSelfRef.pruner__DOT__spike_matrix[vlSelfRef.__VdlyDim0__pruner__DOT__spike_matrix__v0] 
            = vlSelfRef.__VdlyVal__pruner__DOT__spike_matrix__v0;
    }
    vlSelfRef.pruner__DOT__mem_spike_out = ((IData)(vlSelfRef.mem_sel)
                                             ? vlSelfRef.pruner__DOT__spike_matrix
                                            [vlSelfRef.mem_addr]
                                             : 0U);
    vlSelfRef.pruner__DOT__valid_mask[0U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                     & (((0x1fU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0x1fU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0x1fU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0x1fU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0x1fU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x1fU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0x1fU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                       & (((0x1eU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x1eU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x1eU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x1eU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x1eU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x1eU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x1eU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                       & (((0x1dU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x1dU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x1dU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x1dU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x1dU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x1dU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x1dU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0x1cU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x1cU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x1cU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x1cU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x1cU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x1cU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x1cU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                       & (((0x1bU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x1bU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x1bU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x1bU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x1bU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x1bU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x1bU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0x1aU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x1aU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x1aU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x1aU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x1aU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x1aU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x1aU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0x19U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x19U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x19U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x19U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x19U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x19U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x19U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((0x18U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x18U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x18U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x18U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x18U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x18U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x18U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                       & (((0x17U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x17U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x17U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x17U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x17U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x17U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x17U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0x16U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x16U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x16U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x16U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x16U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x16U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x16U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0x15U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x15U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x15U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x15U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x15U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x15U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x15U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((0x14U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x14U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x14U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x14U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x14U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x14U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x14U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0x13U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x13U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x13U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x13U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x13U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x13U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x13U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((0x12U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x12U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x12U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x12U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x12U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x12U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x12U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((0x11U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x11U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x11U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x11U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x11U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x11U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x11U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                             & (((0x10U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x10U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x10U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x10U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x10U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x10U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x10U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                       & (((0xfU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xfU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xfU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xfU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xfU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xfU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xfU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0xeU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xeU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xeU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xeU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xeU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xeU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xeU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0xdU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xdU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xdU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xdU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xdU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xdU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xdU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((0xcU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xcU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xcU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xcU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xcU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xcU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xcU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((0xbU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xbU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xbU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xbU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xbU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xbU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xbU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((0xaU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xaU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xaU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xaU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xaU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xaU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xaU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((9U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [9U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [9U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [9U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [9U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [9U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (9U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                             & (((8U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [8U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [8U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [8U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [8U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [8U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (8U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                         & (((7U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [7U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [7U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [7U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [7U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [7U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (7U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((6U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [6U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [6U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [6U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [6U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [6U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (6U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((5U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [5U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [5U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [5U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [5U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [5U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (5U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                             & (((4U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [4U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [4U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [4U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [4U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [4U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (4U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                           & (((3U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [3U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [3U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [3U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [3U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [3U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (3U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                             & (((2U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [2U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [2U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [2U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [2U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [2U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (2U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                             & (((1U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [1U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [1U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [1U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [1U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [1U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (1U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[0U] 
                                                            & ((0U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[1U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                     & (((0x3fU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0x3fU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0x3fU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0x3fU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0x3fU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x3fU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0x3fU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                       & (((0x3eU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x3eU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x3eU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x3eU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x3eU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x3eU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x3eU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                       & (((0x3dU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x3dU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x3dU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x3dU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x3dU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x3dU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x3dU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x3cU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x3cU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x3cU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x3cU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x3cU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x3cU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x3cU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                       & (((0x3bU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x3bU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x3bU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x3bU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x3bU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x3bU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x3bU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x3aU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x3aU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x3aU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x3aU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x3aU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x3aU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x3aU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x39U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x39U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x39U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x39U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x39U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x39U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x39U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x38U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x38U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x38U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x38U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x38U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x38U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x38U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                       & (((0x37U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x37U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x37U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x37U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x37U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x37U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x37U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x36U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x36U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x36U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x36U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x36U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x36U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x36U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x35U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x35U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x35U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x35U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x35U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x35U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x35U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x34U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x34U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x34U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x34U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x34U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x34U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x34U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x33U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x33U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x33U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x33U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x33U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x33U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x33U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x32U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x32U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x32U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x32U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x32U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x32U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x32U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x31U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x31U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x31U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x31U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x31U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x31U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x31U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                             & (((0x30U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x30U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x30U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x30U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x30U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x30U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x30U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                       & (((0x2fU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x2fU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x2fU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x2fU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x2fU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x2fU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x2fU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x2eU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x2eU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x2eU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x2eU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x2eU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x2eU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x2eU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x2dU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x2dU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x2dU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x2dU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x2dU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x2dU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x2dU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x2cU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x2cU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x2cU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x2cU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x2cU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x2cU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x2cU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x2bU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x2bU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x2bU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x2bU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x2bU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x2bU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x2bU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x2aU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x2aU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x2aU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x2aU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x2aU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x2aU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x2aU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x29U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x29U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x29U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x29U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x29U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x29U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x29U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                             & (((0x28U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x28U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x28U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x28U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x28U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x28U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x28U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                         & (((0x27U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x27U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x27U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x27U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x27U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x27U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x27U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x26U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x26U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x26U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x26U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x26U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x26U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x26U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x25U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x25U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x25U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x25U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x25U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x25U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x25U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                             & (((0x24U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x24U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x24U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x24U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x24U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x24U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x24U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                           & (((0x23U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x23U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x23U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x23U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x23U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x23U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x23U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                             & (((0x22U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x22U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x22U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x22U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x22U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x22U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x22U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                             & (((0x21U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x21U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x21U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x21U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x21U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x21U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x21U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[1U] 
                                                            & ((0x20U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x20U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x20U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x20U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x20U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x20U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x20U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[2U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                     & (((0x5fU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0x5fU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0x5fU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0x5fU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0x5fU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x5fU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0x5fU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                       & (((0x5eU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x5eU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x5eU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x5eU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x5eU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x5eU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x5eU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                       & (((0x5dU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x5dU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x5dU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x5dU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x5dU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x5dU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x5dU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x5cU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x5cU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x5cU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x5cU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x5cU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x5cU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x5cU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                       & (((0x5bU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x5bU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x5bU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x5bU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x5bU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x5bU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x5bU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x5aU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x5aU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x5aU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x5aU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x5aU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x5aU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x5aU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x59U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x59U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x59U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x59U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x59U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x59U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x59U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x58U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x58U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x58U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x58U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x58U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x58U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x58U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                       & (((0x57U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x57U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x57U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x57U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x57U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x57U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x57U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x56U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x56U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x56U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x56U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x56U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x56U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x56U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x55U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x55U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x55U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x55U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x55U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x55U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x55U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x54U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x54U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x54U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x54U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x54U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x54U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x54U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x53U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x53U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x53U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x53U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x53U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x53U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x53U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x52U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x52U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x52U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x52U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x52U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x52U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x52U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x51U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x51U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x51U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x51U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x51U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x51U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x51U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                             & (((0x50U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x50U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x50U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x50U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x50U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x50U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x50U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                       & (((0x4fU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x4fU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x4fU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x4fU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x4fU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x4fU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x4fU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x4eU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x4eU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x4eU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x4eU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x4eU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x4eU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x4eU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x4dU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x4dU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x4dU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x4dU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x4dU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x4dU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x4dU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x4cU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x4cU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x4cU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x4cU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x4cU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x4cU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x4cU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x4bU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x4bU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x4bU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x4bU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x4bU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x4bU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x4bU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x4aU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x4aU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x4aU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x4aU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x4aU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x4aU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x4aU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x49U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x49U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x49U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x49U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x49U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x49U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x49U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                             & (((0x48U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x48U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x48U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x48U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x48U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x48U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x48U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                         & (((0x47U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x47U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x47U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x47U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x47U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x47U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x47U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x46U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x46U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x46U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x46U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x46U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x46U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x46U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x45U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x45U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x45U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x45U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x45U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x45U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x45U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                             & (((0x44U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x44U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x44U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x44U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x44U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x44U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x44U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                           & (((0x43U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x43U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x43U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x43U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x43U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x43U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x43U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                             & (((0x42U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x42U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x42U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x42U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x42U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x42U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x42U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                             & (((0x41U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x41U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x41U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x41U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x41U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x41U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x41U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[2U] 
                                                            & ((0x40U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x40U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x40U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x40U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x40U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x40U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x40U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[3U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                     & (((0x7fU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0x7fU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0x7fU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0x7fU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0x7fU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x7fU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0x7fU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                       & (((0x7eU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x7eU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x7eU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x7eU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x7eU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x7eU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x7eU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                       & (((0x7dU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x7dU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x7dU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x7dU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x7dU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x7dU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x7dU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x7cU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x7cU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x7cU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x7cU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x7cU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x7cU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x7cU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                       & (((0x7bU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x7bU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x7bU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x7bU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x7bU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x7bU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x7bU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x7aU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x7aU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x7aU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x7aU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x7aU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x7aU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x7aU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x79U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x79U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x79U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x79U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x79U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x79U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x79U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x78U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x78U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x78U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x78U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x78U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x78U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x78U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                       & (((0x77U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x77U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x77U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x77U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x77U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x77U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x77U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x76U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x76U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x76U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x76U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x76U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x76U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x76U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x75U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x75U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x75U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x75U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x75U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x75U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x75U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x74U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x74U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x74U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x74U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x74U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x74U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x74U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x73U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x73U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x73U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x73U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x73U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x73U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x73U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x72U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x72U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x72U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x72U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x72U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x72U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x72U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x71U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x71U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x71U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x71U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x71U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x71U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x71U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                             & (((0x70U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x70U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x70U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x70U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x70U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x70U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x70U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                       & (((0x6fU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x6fU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x6fU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x6fU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x6fU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x6fU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x6fU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x6eU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x6eU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x6eU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x6eU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x6eU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x6eU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x6eU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x6dU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x6dU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x6dU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x6dU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x6dU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x6dU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x6dU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x6cU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x6cU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x6cU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x6cU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x6cU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x6cU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x6cU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x6bU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x6bU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x6bU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x6bU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x6bU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x6bU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x6bU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x6aU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x6aU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x6aU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x6aU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x6aU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x6aU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x6aU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x69U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x69U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x69U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x69U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x69U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x69U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x69U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                             & (((0x68U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x68U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x68U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x68U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x68U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x68U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x68U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                         & (((0x67U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x67U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x67U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x67U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x67U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x67U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x67U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x66U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x66U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x66U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x66U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x66U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x66U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x66U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x65U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x65U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x65U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x65U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x65U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x65U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x65U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                             & (((0x64U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x64U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x64U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x64U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x64U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x64U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x64U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                           & (((0x63U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x63U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x63U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x63U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x63U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x63U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x63U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                             & (((0x62U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x62U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x62U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x62U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x62U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x62U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x62U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                             & (((0x61U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x61U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x61U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x61U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x61U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x61U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x61U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[3U] 
                                                            & ((0x60U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x60U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x60U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x60U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x60U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x60U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x60U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[4U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                     & (((0x9fU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0x9fU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0x9fU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0x9fU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0x9fU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x9fU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0x9fU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                       & (((0x9eU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x9eU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x9eU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x9eU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x9eU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x9eU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x9eU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                       & (((0x9dU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x9dU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x9dU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x9dU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x9dU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x9dU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x9dU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x9cU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x9cU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x9cU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x9cU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x9cU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x9cU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x9cU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                       & (((0x9bU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x9bU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x9bU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x9bU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x9bU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x9bU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x9bU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x9aU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x9aU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x9aU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x9aU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x9aU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x9aU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x9aU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x99U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x99U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x99U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x99U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x99U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x99U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x99U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x98U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x98U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x98U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x98U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x98U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x98U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x98U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                       & (((0x97U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x97U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x97U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x97U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x97U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x97U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x97U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x96U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x96U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x96U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x96U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x96U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x96U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x96U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x95U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x95U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x95U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x95U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x95U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x95U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x95U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x94U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x94U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x94U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x94U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x94U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x94U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x94U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x93U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x93U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x93U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x93U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x93U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x93U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x93U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x92U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x92U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x92U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x92U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x92U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x92U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x92U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x91U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x91U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x91U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x91U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x91U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x91U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x91U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                             & (((0x90U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x90U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x90U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x90U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x90U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x90U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x90U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                       & (((0x8fU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0x8fU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0x8fU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0x8fU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x8fU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x8fU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0x8fU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x8eU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x8eU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x8eU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x8eU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x8eU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x8eU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x8eU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x8dU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x8dU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x8dU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x8dU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x8dU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x8dU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x8dU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x8cU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x8cU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x8cU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x8cU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x8cU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x8cU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x8cU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x8bU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x8bU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x8bU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x8bU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x8bU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x8bU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x8bU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x8aU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x8aU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x8aU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x8aU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x8aU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x8aU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x8aU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x89U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x89U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x89U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x89U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x89U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x89U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x89U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                             & (((0x88U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x88U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x88U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x88U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x88U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x88U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x88U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                         & (((0x87U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0x87U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0x87U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0x87U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x87U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x87U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0x87U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x86U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x86U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x86U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x86U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x86U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x86U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x86U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x85U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x85U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x85U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x85U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x85U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x85U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x85U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                             & (((0x84U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x84U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x84U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x84U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x84U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x84U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x84U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                           & (((0x83U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x83U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x83U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x83U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x83U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x83U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x83U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                             & (((0x82U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x82U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x82U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x82U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x82U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x82U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x82U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                             & (((0x81U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x81U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x81U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0x81U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0x81U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0x81U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0x81U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[4U] 
                                                            & ((0x80U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0x80U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0x80U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0x80U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0x80U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0x80U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0x80U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[5U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                     & (((0xbfU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0xbfU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0xbfU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0xbfU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0xbfU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xbfU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0xbfU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                       & (((0xbeU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xbeU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xbeU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xbeU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xbeU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xbeU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xbeU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                       & (((0xbdU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xbdU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xbdU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xbdU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xbdU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xbdU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xbdU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xbcU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xbcU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xbcU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xbcU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xbcU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xbcU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xbcU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                       & (((0xbbU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xbbU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xbbU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xbbU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xbbU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xbbU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xbbU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xbaU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xbaU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xbaU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xbaU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xbaU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xbaU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xbaU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xb9U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xb9U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xb9U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xb9U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb9U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb9U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xb9U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xb8U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb8U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb8U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xb8U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xb8U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xb8U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xb8U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                       & (((0xb7U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xb7U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xb7U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xb7U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xb7U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xb7U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xb7U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xb6U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xb6U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xb6U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xb6U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb6U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb6U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xb6U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xb5U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xb5U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xb5U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xb5U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb5U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb5U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xb5U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xb4U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb4U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb4U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xb4U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xb4U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xb4U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xb4U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xb3U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xb3U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xb3U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xb3U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb3U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb3U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xb3U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xb2U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb2U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb2U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xb2U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xb2U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xb2U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xb2U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xb1U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xb1U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xb1U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xb1U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xb1U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xb1U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xb1U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                             & (((0xb0U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xb0U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xb0U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xb0U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xb0U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xb0U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xb0U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                       & (((0xafU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xafU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xafU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xafU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xafU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xafU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xafU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xaeU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xaeU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xaeU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xaeU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xaeU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xaeU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xaeU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xadU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xadU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xadU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xadU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xadU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xadU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xadU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xacU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xacU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xacU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xacU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xacU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xacU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xacU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xabU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xabU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xabU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xabU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xabU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xabU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xabU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xaaU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xaaU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xaaU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xaaU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xaaU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xaaU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xaaU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xa9U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xa9U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xa9U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xa9U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa9U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa9U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xa9U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                             & (((0xa8U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa8U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa8U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xa8U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xa8U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xa8U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xa8U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                         & (((0xa7U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xa7U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xa7U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xa7U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xa7U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xa7U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xa7U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xa6U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xa6U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xa6U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xa6U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa6U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa6U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xa6U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xa5U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xa5U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xa5U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xa5U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa5U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa5U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xa5U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                             & (((0xa4U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa4U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa4U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xa4U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xa4U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xa4U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xa4U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                           & (((0xa3U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xa3U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xa3U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xa3U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa3U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa3U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xa3U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                             & (((0xa2U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa2U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa2U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xa2U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xa2U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xa2U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xa2U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                             & (((0xa1U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa1U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa1U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xa1U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xa1U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xa1U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xa1U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[5U] 
                                                            & ((0xa0U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xa0U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xa0U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xa0U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xa0U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xa0U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xa0U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[6U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                     & (((0xdfU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & (((vlSelfRef.pruner__DOT__NO_table
                                                              [0xdfU] 
                                                              < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                             & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                 [0xdfU] 
                                                                 & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                == 
                                                                vlSelfRef.pruner__DOT__spike_matrix
                                                                [0xdfU])) 
                                                            | ((vlSelfRef.pruner__DOT__NO_table
                                                                [0xdfU] 
                                                                == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xdfU] 
                                                                   == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  & (0xdfU 
                                                                     < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                       & (((0xdeU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xdeU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xdeU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xdeU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xdeU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xdeU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xdeU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                       & (((0xddU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xddU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xddU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xddU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xddU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xddU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xddU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xdcU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xdcU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xdcU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xdcU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xdcU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xdcU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xdcU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                       & (((0xdbU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xdbU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xdbU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xdbU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xdbU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xdbU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xdbU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xdaU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xdaU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xdaU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xdaU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xdaU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xdaU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xdaU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xd9U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xd9U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xd9U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xd9U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd9U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd9U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xd9U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xd8U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd8U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd8U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xd8U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xd8U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xd8U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xd8U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                       & (((0xd7U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xd7U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xd7U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xd7U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xd7U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xd7U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xd7U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xd6U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xd6U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xd6U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xd6U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd6U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd6U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xd6U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xd5U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xd5U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xd5U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xd5U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd5U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd5U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xd5U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xd4U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd4U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd4U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xd4U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xd4U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xd4U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xd4U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xd3U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xd3U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xd3U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xd3U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd3U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd3U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xd3U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xd2U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd2U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd2U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xd2U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xd2U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xd2U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xd2U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xd1U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xd1U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xd1U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xd1U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xd1U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xd1U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xd1U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                             & (((0xd0U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xd0U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xd0U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xd0U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xd0U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xd0U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xd0U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                       & (((0xcfU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xcfU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xcfU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xcfU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xcfU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xcfU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xcfU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xceU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xceU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xceU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xceU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xceU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xceU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xceU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xcdU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xcdU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xcdU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xcdU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xcdU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xcdU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xcdU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xccU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xccU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xccU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xccU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xccU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xccU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xccU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xcbU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xcbU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xcbU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xcbU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xcbU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xcbU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xcbU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xcaU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xcaU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xcaU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xcaU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xcaU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xcaU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xcaU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xc9U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xc9U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xc9U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xc9U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc9U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc9U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xc9U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                             & (((0xc8U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc8U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc8U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xc8U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xc8U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xc8U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xc8U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                         & (((0xc7U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xc7U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xc7U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xc7U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xc7U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xc7U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xc7U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xc6U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xc6U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xc6U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xc6U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc6U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc6U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xc6U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xc5U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xc5U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xc5U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xc5U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc5U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc5U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xc5U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                             & (((0xc4U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc4U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc4U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xc4U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xc4U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xc4U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xc4U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                           & (((0xc3U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xc3U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xc3U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xc3U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc3U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc3U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xc3U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                             & (((0xc2U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc2U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc2U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xc2U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xc2U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xc2U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xc2U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                             & (((0xc1U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc1U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc1U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xc1U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xc1U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xc1U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xc1U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[6U] 
                                                            & ((0xc0U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xc0U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xc0U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xc0U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xc0U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xc0U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xc0U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.pruner__DOT__valid_mask[7U] = ((((((0x80000000U 
                                                  & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                     & (((0xffU 
                                                          != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                         & ((vlSelfRef.pruner__DOT__NO_table
                                                             [0xffU] 
                                                             < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                            & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                [0xffU] 
                                                                & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                               == 
                                                               vlSelfRef.pruner__DOT__spike_matrix
                                                               [0xffU]))) 
                                                        << 0x1fU))) 
                                                 | (0xc0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                       & (((0xfeU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xfeU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xfeU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xfeU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xfeU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xfeU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xfeU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1eU)))) 
                                                | ((0xe0000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                       & (((0xfdU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xfdU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xfdU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xfdU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xfdU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xfdU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xfdU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1dU))) 
                                                   | (0xf0000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xfcU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xfcU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xfcU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xfcU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xfcU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xfcU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xfcU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1cU))))) 
                                               | (((0xf8000000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                       & (((0xfbU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xfbU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xfbU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xfbU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xfbU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xfbU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xfbU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x1bU))) 
                                                   | (0xfc000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xfaU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xfaU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xfaU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xfaU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xfaU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xfaU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xfaU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x1aU)))) 
                                                  | ((0xfe000000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xf9U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xf9U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xf9U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xf9U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf9U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf9U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xf9U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x19U))) 
                                                     | (0xff000000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xf8U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf8U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf8U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xf8U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xf8U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xf8U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xf8U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x18U)))))) 
                                              | ((((0xff800000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                       & (((0xf7U 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xf7U] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xf7U] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xf7U])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xf7U] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xf7U] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xf7U 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0x17U))) 
                                                   | (0xffc00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xf6U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xf6U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xf6U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xf6U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf6U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf6U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xf6U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x16U)))) 
                                                  | ((0xffe00000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xf5U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xf5U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xf5U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xf5U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf5U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf5U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xf5U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x15U))) 
                                                     | (0xfff00000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xf4U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf4U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf4U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xf4U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xf4U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xf4U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xf4U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x14U))))) 
                                                 | (((0xfff80000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xf3U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xf3U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xf3U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xf3U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf3U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf3U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xf3U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0x13U))) 
                                                     | (0xfffc0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xf2U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf2U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf2U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xf2U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xf2U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xf2U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xf2U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x12U)))) 
                                                    | ((0xfffe0000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xf1U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xf1U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xf1U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xf1U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xf1U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xf1U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xf1U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0x11U))) 
                                                       | (0xffff0000U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                             & (((0xf0U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xf0U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xf0U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xf0U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xf0U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xf0U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xf0U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 0x10U))))))) 
                                             | (((((0xffff8000U 
                                                    & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                       & (((0xefU 
                                                            != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                           & (((vlSelfRef.pruner__DOT__NO_table
                                                                [0xefU] 
                                                                < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                               & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                   [0xefU] 
                                                                   & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                  == 
                                                                  vlSelfRef.pruner__DOT__spike_matrix
                                                                  [0xefU])) 
                                                              | ((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xefU] 
                                                                  == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xefU] 
                                                                     == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    & (0xefU 
                                                                       < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                          << 0xfU))) 
                                                   | (0xffffc000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xeeU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xeeU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xeeU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xeeU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xeeU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xeeU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xeeU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xeU)))) 
                                                  | ((0xffffe000U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xedU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xedU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xedU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xedU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xedU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xedU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xedU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xdU))) 
                                                     | (0xfffff000U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xecU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xecU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xecU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xecU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xecU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xecU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xecU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xcU))))) 
                                                 | (((0xfffff800U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xebU 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xebU] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xebU] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xebU])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xebU] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xebU] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xebU 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 0xbU))) 
                                                     | (0xfffffc00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xeaU 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xeaU] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xeaU] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xeaU])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xeaU] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xeaU] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xeaU 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 0xaU)))) 
                                                    | ((0xfffffe00U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xe9U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xe9U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xe9U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xe9U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe9U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe9U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xe9U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 9U))) 
                                                       | (0xffffff00U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                             & (((0xe8U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe8U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe8U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xe8U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xe8U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xe8U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xe8U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 8U)))))) 
                                                | ((((0xffffff80U 
                                                      & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                         & (((0xe7U 
                                                              != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                             & (((vlSelfRef.pruner__DOT__NO_table
                                                                  [0xe7U] 
                                                                  < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                 & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                     [0xe7U] 
                                                                     & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                    == 
                                                                    vlSelfRef.pruner__DOT__spike_matrix
                                                                    [0xe7U])) 
                                                                | ((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xe7U] 
                                                                    == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xe7U] 
                                                                       == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      & (0xe7U 
                                                                         < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                            << 7U))) 
                                                     | (0xffffffc0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xe6U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xe6U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xe6U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xe6U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe6U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe6U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xe6U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 6U)))) 
                                                    | ((0xffffffe0U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xe5U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xe5U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xe5U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xe5U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe5U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe5U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xe5U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 5U))) 
                                                       | (0xfffffff0U 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                             & (((0xe4U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe4U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe4U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xe4U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xe4U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xe4U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xe4U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 4U))))) 
                                                   | (((0xfffffff8U 
                                                        & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                           & (((0xe3U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xe3U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xe3U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xe3U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe3U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe3U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xe3U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                              << 3U))) 
                                                       | (0xfffffffcU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                             & (((0xe2U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe2U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe2U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xe2U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xe2U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xe2U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xe2U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 2U)))) 
                                                      | ((0xfffffffeU 
                                                          & (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                             & (((0xe1U 
                                                                  != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                                 & (((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe1U] 
                                                                      < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe1U] 
                                                                         & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        == 
                                                                        vlSelfRef.pruner__DOT__spike_matrix
                                                                        [0xe1U])) 
                                                                    | ((vlSelfRef.pruner__DOT__NO_table
                                                                        [0xe1U] 
                                                                        == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                       & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                           [0xe1U] 
                                                                           == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                          & (0xe1U 
                                                                             < (IData)(vlSelfRef.pruner__DOT__row_idx_r)))))) 
                                                                << 1U))) 
                                                         | (vlSelfRef.pruner__DOT__si_vec_r[7U] 
                                                            & ((0xe0U 
                                                                != (IData)(vlSelfRef.pruner__DOT__row_idx_r)) 
                                                               & (((vlSelfRef.pruner__DOT__NO_table
                                                                    [0xe0U] 
                                                                    < (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                   & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                       [0xe0U] 
                                                                       & (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                      == 
                                                                      vlSelfRef.pruner__DOT__spike_matrix
                                                                      [0xe0U])) 
                                                                  | ((vlSelfRef.pruner__DOT__NO_table
                                                                      [0xe0U] 
                                                                      == (IData)(vlSelfRef.pruner__DOT__row_NO_r)) 
                                                                     & ((vlSelfRef.pruner__DOT__spike_matrix
                                                                         [0xe0U] 
                                                                         == (IData)(vlSelfRef.pruner__DOT__cur_spikes_r)) 
                                                                        & (0xe0U 
                                                                           < (IData)(vlSelfRef.pruner__DOT__row_idx_r))))))))))));
    vlSelfRef.mem_spike_out = vlSelfRef.pruner__DOT__mem_spike_out;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pruner__DOT__best_idx_comb = vlSelfRef.pruner__DOT__st0_row_idx;
    vlSelfRef.pruner__DOT__best_no_comb = 0U;
    vlSelfRef.pruner__DOT__best_spikes_comb = vlSelfRef.pruner__DOT__st0_row_spikes;
    vlSelfRef.pruner__DOT__j = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelfRef.pruner__DOT__j)) {
        if (((((IData)(vlSelfRef.pruner__DOT__st0_valid) 
               & (vlSelfRef.pruner__DOT__st0_si_vec[
                  (7U & (vlSelfRef.pruner__DOT__j >> 5U))] 
                  >> (0x1fU & vlSelfRef.pruner__DOT__j))) 
              & (vlSelfRef.pruner__DOT__j != (IData)(vlSelfRef.pruner__DOT__st0_row_idx))) 
             & (((vlSelfRef.pruner__DOT__NO_table[(0xffU 
                                                   & vlSelfRef.pruner__DOT__j)] 
                  < (IData)(vlSelfRef.pruner__DOT__st0_row_NO)) 
                 & ((vlSelfRef.pruner__DOT__spike_matrix
                     [(0xffU & vlSelfRef.pruner__DOT__j)] 
                     & (IData)(vlSelfRef.pruner__DOT__st0_row_spikes)) 
                    == vlSelfRef.pruner__DOT__spike_matrix
                    [(0xffU & vlSelfRef.pruner__DOT__j)])) 
                | (((vlSelfRef.pruner__DOT__NO_table
                     [(0xffU & vlSelfRef.pruner__DOT__j)] 
                     == (IData)(vlSelfRef.pruner__DOT__st0_row_NO)) 
                    & (vlSelfRef.pruner__DOT__spike_matrix
                       [(0xffU & vlSelfRef.pruner__DOT__j)] 
                       == (IData)(vlSelfRef.pruner__DOT__st0_row_spikes))) 
                   & (vlSelfRef.pruner__DOT__j < (IData)(vlSelfRef.pruner__DOT__st0_row_idx)))))) {
            if (((vlSelfRef.pruner__DOT__NO_table[(0xffU 
                                                   & vlSelfRef.pruner__DOT__j)] 
                  > (IData)(vlSelfRef.pruner__DOT__best_no_comb)) 
                 | ((vlSelfRef.pruner__DOT__NO_table
                     [(0xffU & vlSelfRef.pruner__DOT__j)] 
                     == (IData)(vlSelfRef.pruner__DOT__best_no_comb)) 
                    & (vlSelfRef.pruner__DOT__j < (IData)(vlSelfRef.pruner__DOT__best_idx_comb))))) {
                vlSelfRef.pruner__DOT__best_idx_comb 
                    = (0xffU & vlSelfRef.pruner__DOT__j);
                vlSelfRef.pruner__DOT__best_no_comb 
                    = vlSelfRef.pruner__DOT__NO_table
                    [(0xffU & vlSelfRef.pruner__DOT__j)];
                vlSelfRef.pruner__DOT__best_spikes_comb 
                    = vlSelfRef.pruner__DOT__spike_matrix
                    [(0xffU & vlSelfRef.pruner__DOT__j)];
            }
        }
        vlSelfRef.pruner__DOT__j = ((IData)(1U) + vlSelfRef.pruner__DOT__j);
    }
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
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/pruner.v", 6, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/pruner.v", 6, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/pruner.v", 6, "", "Active region did not converge.");
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
    if (VL_UNLIKELY(((vlSelfRef.si_valid & 0xfeU)))) {
        Verilated::overWidthError("si_valid");}
    if (VL_UNLIKELY(((vlSelfRef.dispatch_ready & 0xfeU)))) {
        Verilated::overWidthError("dispatch_ready");}
    if (VL_UNLIKELY(((vlSelfRef.mem_wr_en & 0xfeU)))) {
        Verilated::overWidthError("mem_wr_en");}
    if (VL_UNLIKELY(((vlSelfRef.mem_sel & 0xfeU)))) {
        Verilated::overWidthError("mem_sel");}
}
#endif  // VL_DEBUG
