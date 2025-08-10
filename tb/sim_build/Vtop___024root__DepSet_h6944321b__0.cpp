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
    vlSelfRef.dispatcher__DOT__clk = vlSelfRef.clk;
    vlSelfRef.dispatcher__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.dispatcher__DOT__row_info_valid = vlSelfRef.row_info_valid;
    vlSelfRef.dispatcher__DOT__row_idx = vlSelfRef.row_idx;
    vlSelfRef.dispatcher__DOT__row_prefix_id = vlSelfRef.row_prefix_id;
    vlSelfRef.dispatcher__DOT__row_pattern = vlSelfRef.row_pattern;
    vlSelfRef.dispatcher__DOT__row_popcnt = vlSelfRef.row_popcnt;
    vlSelfRef.dispatcher__DOT__row_last = vlSelfRef.row_last;
    vlSelfRef.dispatcher__DOT__proc_ready = vlSelfRef.proc_ready;
    vlSelfRef.dispatcher__DOT__prev_compute_busy = vlSelfRef.prev_compute_busy;
    vlSelfRef.dispatcher__DOT__pruner_done = vlSelfRef.pruner_done;
    vlSelfRef.task_valid = vlSelfRef.dispatcher__DOT__task_valid;
    vlSelfRef.task_row_id = vlSelfRef.dispatcher__DOT__task_row_id;
    vlSelfRef.task_prefix_id = vlSelfRef.dispatcher__DOT__task_prefix_id;
    vlSelfRef.task_pattern = vlSelfRef.dispatcher__DOT__task_pattern;
    vlSelfRef.tile_done = vlSelfRef.dispatcher__DOT__tile_done;
    vlSelfRef.dispatcher__DOT__row_info_ready = ((0U 
                                                  == (IData)(vlSelfRef.dispatcher__DOT__state)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.dispatcher__DOT__state)));
    vlSelfRef.dispatcher__DOT__next_state = vlSelfRef.dispatcher__DOT__state;
    if ((4U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
        vlSelfRef.dispatcher__DOT__next_state = 0U;
    } else if ((2U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
            if (((IData)(vlSelfRef.dispatcher__DOT__dispatch_count) 
                 >= (IData)(vlSelfRef.dispatcher__DOT__collect_count))) {
                vlSelfRef.dispatcher__DOT__next_state = 4U;
            }
        } else if (((IData)(vlSelfRef.dispatcher__DOT__sort_count) 
                    >= (IData)(vlSelfRef.dispatcher__DOT__collect_count))) {
            vlSelfRef.dispatcher__DOT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
        if (((((0x100U == (IData)(vlSelfRef.dispatcher__DOT__collect_count)) 
               | (IData)(vlSelfRef.pruner_done)) | (IData)(vlSelfRef.dispatcher__DOT__collect_timeout)) 
             | (IData)(vlSelfRef.dispatcher__DOT__last_row_seen))) {
            vlSelfRef.dispatcher__DOT__next_state = 2U;
        }
    } else if (vlSelfRef.row_info_valid) {
        vlSelfRef.dispatcher__DOT__next_state = 1U;
    }
    vlSelfRef.row_info_ready = vlSelfRef.dispatcher__DOT__row_info_ready;
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
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__dispatcher__DOT__state;
    __Vdly__dispatcher__DOT__state = 0;
    SData/*8:0*/ __Vdly__dispatcher__DOT__dispatch_count;
    __Vdly__dispatcher__DOT__dispatch_count = 0;
    CData/*1:0*/ __Vdly__dispatcher__DOT__sort_stage;
    __Vdly__dispatcher__DOT__sort_stage = 0;
    CData/*7:0*/ __Vdly__dispatcher__DOT__sort_temp_pc;
    __Vdly__dispatcher__DOT__sort_temp_pc = 0;
    CData/*7:0*/ __Vdly__dispatcher__DOT__sort_temp_row;
    __Vdly__dispatcher__DOT__sort_temp_row = 0;
    CData/*7:0*/ __Vdly__dispatcher__DOT__temp_pc;
    __Vdly__dispatcher__DOT__temp_pc = 0;
    SData/*8:0*/ __Vdly__dispatcher__DOT__sort_count;
    __Vdly__dispatcher__DOT__sort_count = 0;
    SData/*15:0*/ __Vdly__dispatcher__DOT__timeout_counter;
    __Vdly__dispatcher__DOT__timeout_counter = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_popcnt__v0;
    __VdlyVal__dispatcher__DOT__sort_popcnt__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_popcnt__v0;
    __VdlyDim0__dispatcher__DOT__sort_popcnt__v0 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_row_id__v0;
    __VdlyVal__dispatcher__DOT__sort_row_id__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_row_id__v0;
    __VdlyDim0__dispatcher__DOT__sort_row_id__v0 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_popcnt__v1;
    __VdlyVal__dispatcher__DOT__sort_popcnt__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_popcnt__v1;
    __VdlyDim0__dispatcher__DOT__sort_popcnt__v1 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_row_id__v1;
    __VdlyVal__dispatcher__DOT__sort_row_id__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_row_id__v1;
    __VdlyDim0__dispatcher__DOT__sort_row_id__v1 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__pst_prefix_id__v0;
    __VdlyVal__dispatcher__DOT__pst_prefix_id__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_prefix_id__v0;
    __VdlyDim0__dispatcher__DOT__pst_prefix_id__v0 = 0;
    CData/*0:0*/ __VdlySet__dispatcher__DOT__pst_prefix_id__v0;
    __VdlySet__dispatcher__DOT__pst_prefix_id__v0 = 0;
    SData/*15:0*/ __VdlyVal__dispatcher__DOT__pst_pattern__v0;
    __VdlyVal__dispatcher__DOT__pst_pattern__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_pattern__v0;
    __VdlyDim0__dispatcher__DOT__pst_pattern__v0 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__pst_popcnt__v0;
    __VdlyVal__dispatcher__DOT__pst_popcnt__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_popcnt__v0;
    __VdlyDim0__dispatcher__DOT__pst_popcnt__v0 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__pst_row_id__v0;
    __VdlyVal__dispatcher__DOT__pst_row_id__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_row_id__v0;
    __VdlyDim0__dispatcher__DOT__pst_row_id__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_valid__v0;
    __VdlyDim0__dispatcher__DOT__pst_valid__v0 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__collected_rows__v0;
    __VdlyVal__dispatcher__DOT__collected_rows__v0 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__collected_rows__v0;
    __VdlyDim0__dispatcher__DOT__collected_rows__v0 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_row_id__v2;
    __VdlyVal__dispatcher__DOT__sort_row_id__v2 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_row_id__v2;
    __VdlyDim0__dispatcher__DOT__sort_row_id__v2 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_popcnt__v2;
    __VdlyVal__dispatcher__DOT__sort_popcnt__v2 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_popcnt__v2;
    __VdlyDim0__dispatcher__DOT__sort_popcnt__v2 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_valid__v1;
    __VdlyDim0__dispatcher__DOT__pst_valid__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_row_id__v3;
    __VdlyDim0__dispatcher__DOT__sort_row_id__v3 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_popcnt__v3;
    __VdlyDim0__dispatcher__DOT__sort_popcnt__v3 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__collected_rows__v1;
    __VdlyDim0__dispatcher__DOT__collected_rows__v1 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_row_id__v4;
    __VdlyVal__dispatcher__DOT__sort_row_id__v4 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_popcnt__v4;
    __VdlyVal__dispatcher__DOT__sort_popcnt__v4 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__pst_prefix_id__v1;
    __VdlyVal__dispatcher__DOT__pst_prefix_id__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_prefix_id__v1;
    __VdlyDim0__dispatcher__DOT__pst_prefix_id__v1 = 0;
    CData/*0:0*/ __VdlySet__dispatcher__DOT__pst_prefix_id__v1;
    __VdlySet__dispatcher__DOT__pst_prefix_id__v1 = 0;
    SData/*15:0*/ __VdlyVal__dispatcher__DOT__pst_pattern__v1;
    __VdlyVal__dispatcher__DOT__pst_pattern__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_pattern__v1;
    __VdlyDim0__dispatcher__DOT__pst_pattern__v1 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__pst_popcnt__v1;
    __VdlyVal__dispatcher__DOT__pst_popcnt__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_popcnt__v1;
    __VdlyDim0__dispatcher__DOT__pst_popcnt__v1 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__pst_row_id__v1;
    __VdlyVal__dispatcher__DOT__pst_row_id__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_row_id__v1;
    __VdlyDim0__dispatcher__DOT__pst_row_id__v1 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_valid__v2;
    __VdlyDim0__dispatcher__DOT__pst_valid__v2 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__collected_rows__v2;
    __VdlyVal__dispatcher__DOT__collected_rows__v2 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__pst_valid__v3;
    __VdlyDim0__dispatcher__DOT__pst_valid__v3 = 0;
    CData/*7:0*/ __VdlyVal__dispatcher__DOT__sort_row_id__v5;
    __VdlyVal__dispatcher__DOT__sort_row_id__v5 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_row_id__v5;
    __VdlyDim0__dispatcher__DOT__sort_row_id__v5 = 0;
    CData/*7:0*/ __VdlyDim0__dispatcher__DOT__sort_popcnt__v5;
    __VdlyDim0__dispatcher__DOT__sort_popcnt__v5 = 0;
    // Body
    __Vdly__dispatcher__DOT__sort_stage = vlSelfRef.dispatcher__DOT__sort_stage;
    __Vdly__dispatcher__DOT__sort_temp_pc = vlSelfRef.dispatcher__DOT__sort_temp_pc;
    __Vdly__dispatcher__DOT__sort_temp_row = vlSelfRef.dispatcher__DOT__sort_temp_row;
    __Vdly__dispatcher__DOT__temp_pc = vlSelfRef.dispatcher__DOT__temp_pc;
    __Vdly__dispatcher__DOT__timeout_counter = vlSelfRef.dispatcher__DOT__timeout_counter;
    __Vdly__dispatcher__DOT__dispatch_count = vlSelfRef.dispatcher__DOT__dispatch_count;
    __Vdly__dispatcher__DOT__sort_count = vlSelfRef.dispatcher__DOT__sort_count;
    __Vdly__dispatcher__DOT__state = vlSelfRef.dispatcher__DOT__state;
    __VdlySet__dispatcher__DOT__pst_prefix_id__v0 = 0U;
    __VdlySet__dispatcher__DOT__pst_prefix_id__v1 = 0U;
    if (vlSelfRef.rst_n) {
        __Vdly__dispatcher__DOT__state = vlSelfRef.dispatcher__DOT__next_state;
        vlSelfRef.dispatcher__DOT__task_valid = 0U;
        vlSelfRef.dispatcher__DOT__tile_done = 0U;
        if ((4U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
                __Vdly__dispatcher__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
                __Vdly__dispatcher__DOT__state = 0U;
            } else {
                vlSelfRef.dispatcher__DOT__tile_done = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
                if (((IData)(vlSelfRef.proc_ready) 
                     & ((IData)(vlSelfRef.dispatcher__DOT__dispatch_count) 
                        < (IData)(vlSelfRef.dispatcher__DOT__collect_count)))) {
                    vlSelfRef.dispatcher__DOT__current_row 
                        = vlSelfRef.dispatcher__DOT__sort_row_id
                        [(0xffU & (IData)(vlSelfRef.dispatcher__DOT__dispatch_count))];
                    if (vlSelfRef.dispatcher__DOT__pst_valid
                        [vlSelfRef.dispatcher__DOT__current_row]) {
                        __Vdly__dispatcher__DOT__dispatch_count 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.dispatcher__DOT__dispatch_count)));
                        vlSelfRef.dispatcher__DOT__task_valid = 1U;
                        vlSelfRef.dispatcher__DOT__task_row_id 
                            = vlSelfRef.dispatcher__DOT__current_row;
                        vlSelfRef.dispatcher__DOT__task_prefix_id 
                            = vlSelfRef.dispatcher__DOT__pst_prefix_id
                            [vlSelfRef.dispatcher__DOT__current_row];
                        vlSelfRef.dispatcher__DOT__task_pattern 
                            = vlSelfRef.dispatcher__DOT__pst_pattern
                            [vlSelfRef.dispatcher__DOT__current_row];
                    } else {
                        __Vdly__dispatcher__DOT__dispatch_count 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.dispatcher__DOT__dispatch_count)));
                    }
                }
            } else if (((IData)(vlSelfRef.dispatcher__DOT__sort_count) 
                        < (IData)(vlSelfRef.dispatcher__DOT__collect_count))) {
                if ((0U == (IData)(vlSelfRef.dispatcher__DOT__sort_stage))) {
                    vlSelfRef.dispatcher__DOT__min_idx_found 
                        = vlSelfRef.dispatcher__DOT__sort_count;
                    vlSelfRef.dispatcher__DOT__min_pc_found 
                        = vlSelfRef.dispatcher__DOT__sort_popcnt
                        [(0xffU & (IData)(vlSelfRef.dispatcher__DOT__sort_count))];
                    vlSelfRef.dispatcher__DOT__min_row_found 
                        = vlSelfRef.dispatcher__DOT__sort_row_id
                        [(0xffU & (IData)(vlSelfRef.dispatcher__DOT__sort_count))];
                    vlSelfRef.dispatcher__DOT__i = 0U;
                    while ((0x100U > vlSelfRef.dispatcher__DOT__i)) {
                        if (((vlSelfRef.dispatcher__DOT__i 
                              >= ((IData)(1U) + (IData)(vlSelfRef.dispatcher__DOT__sort_count))) 
                             & (vlSelfRef.dispatcher__DOT__i 
                                < (IData)(vlSelfRef.dispatcher__DOT__collect_count)))) {
                            if (((vlSelfRef.dispatcher__DOT__sort_popcnt
                                  [(0xffU & vlSelfRef.dispatcher__DOT__i)] 
                                  < vlSelfRef.dispatcher__DOT__min_pc_found) 
                                 | ((vlSelfRef.dispatcher__DOT__sort_popcnt
                                     [(0xffU & vlSelfRef.dispatcher__DOT__i)] 
                                     == vlSelfRef.dispatcher__DOT__min_pc_found) 
                                    & (vlSelfRef.dispatcher__DOT__sort_row_id
                                       [(0xffU & vlSelfRef.dispatcher__DOT__i)] 
                                       < vlSelfRef.dispatcher__DOT__min_row_found)))) {
                                vlSelfRef.dispatcher__DOT__min_idx_found 
                                    = vlSelfRef.dispatcher__DOT__i;
                                vlSelfRef.dispatcher__DOT__min_pc_found 
                                    = vlSelfRef.dispatcher__DOT__sort_popcnt
                                    [(0xffU & vlSelfRef.dispatcher__DOT__i)];
                                vlSelfRef.dispatcher__DOT__min_row_found 
                                    = vlSelfRef.dispatcher__DOT__sort_row_id
                                    [(0xffU & vlSelfRef.dispatcher__DOT__i)];
                            }
                        }
                        vlSelfRef.dispatcher__DOT__i 
                            = ((IData)(1U) + vlSelfRef.dispatcher__DOT__i);
                    }
                    if ((vlSelfRef.dispatcher__DOT__min_idx_found 
                         != (IData)(vlSelfRef.dispatcher__DOT__sort_count))) {
                        __Vdly__dispatcher__DOT__sort_stage = 1U;
                        __Vdly__dispatcher__DOT__sort_temp_pc 
                            = (0xffU & vlSelfRef.dispatcher__DOT__min_pc_found);
                        __Vdly__dispatcher__DOT__sort_temp_row 
                            = (0xffU & vlSelfRef.dispatcher__DOT__min_row_found);
                        __Vdly__dispatcher__DOT__temp_pc 
                            = (0xffU & vlSelfRef.dispatcher__DOT__min_idx_found);
                    } else {
                        __Vdly__dispatcher__DOT__sort_count 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.dispatcher__DOT__sort_count)));
                        __Vdly__dispatcher__DOT__sort_stage = 0U;
                    }
                } else if ((1U == (IData)(vlSelfRef.dispatcher__DOT__sort_stage))) {
                    __Vdly__dispatcher__DOT__sort_stage = 2U;
                } else if ((2U == (IData)(vlSelfRef.dispatcher__DOT__sort_stage))) {
                    __VdlyVal__dispatcher__DOT__sort_popcnt__v0 
                        = vlSelfRef.dispatcher__DOT__sort_temp_pc;
                    __VdlyDim0__dispatcher__DOT__sort_popcnt__v0 
                        = (0xffU & (IData)(vlSelfRef.dispatcher__DOT__sort_count));
                    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.enqueue(__VdlyVal__dispatcher__DOT__sort_popcnt__v0, (IData)(__VdlyDim0__dispatcher__DOT__sort_popcnt__v0));
                    __VdlyVal__dispatcher__DOT__sort_row_id__v0 
                        = vlSelfRef.dispatcher__DOT__sort_temp_row;
                    __VdlyDim0__dispatcher__DOT__sort_row_id__v0 
                        = (0xffU & (IData)(vlSelfRef.dispatcher__DOT__sort_count));
                    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.enqueue(__VdlyVal__dispatcher__DOT__sort_row_id__v0, (IData)(__VdlyDim0__dispatcher__DOT__sort_row_id__v0));
                    __Vdly__dispatcher__DOT__sort_stage = 0U;
                    __VdlyVal__dispatcher__DOT__sort_popcnt__v1 
                        = vlSelfRef.dispatcher__DOT__sort_popcnt
                        [(0xffU & (IData)(vlSelfRef.dispatcher__DOT__sort_count))];
                    __VdlyDim0__dispatcher__DOT__sort_popcnt__v1 
                        = vlSelfRef.dispatcher__DOT__temp_pc;
                    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.enqueue(__VdlyVal__dispatcher__DOT__sort_popcnt__v1, (IData)(__VdlyDim0__dispatcher__DOT__sort_popcnt__v1));
                    __VdlyVal__dispatcher__DOT__sort_row_id__v1 
                        = vlSelfRef.dispatcher__DOT__sort_row_id
                        [(0xffU & (IData)(vlSelfRef.dispatcher__DOT__sort_count))];
                    __VdlyDim0__dispatcher__DOT__sort_row_id__v1 
                        = vlSelfRef.dispatcher__DOT__temp_pc;
                    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.enqueue(__VdlyVal__dispatcher__DOT__sort_row_id__v1, (IData)(__VdlyDim0__dispatcher__DOT__sort_row_id__v1));
                    __Vdly__dispatcher__DOT__sort_count 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.dispatcher__DOT__sort_count)));
                } else {
                    __Vdly__dispatcher__DOT__sort_stage = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
            if (((IData)(vlSelfRef.row_info_valid) 
                 & (IData)(vlSelfRef.dispatcher__DOT__row_info_ready))) {
                __VdlyVal__dispatcher__DOT__pst_prefix_id__v0 
                    = vlSelfRef.row_prefix_id;
                __VdlyDim0__dispatcher__DOT__pst_prefix_id__v0 
                    = vlSelfRef.row_idx;
                __VdlySet__dispatcher__DOT__pst_prefix_id__v0 = 1U;
                __VdlyVal__dispatcher__DOT__pst_pattern__v0 
                    = vlSelfRef.row_pattern;
                __VdlyDim0__dispatcher__DOT__pst_pattern__v0 
                    = vlSelfRef.row_idx;
                __VdlyVal__dispatcher__DOT__pst_popcnt__v0 
                    = vlSelfRef.row_popcnt;
                __VdlyDim0__dispatcher__DOT__pst_popcnt__v0 
                    = vlSelfRef.row_idx;
                __VdlyVal__dispatcher__DOT__pst_row_id__v0 
                    = vlSelfRef.row_idx;
                __VdlyDim0__dispatcher__DOT__pst_row_id__v0 
                    = vlSelfRef.row_idx;
                __VdlyDim0__dispatcher__DOT__pst_valid__v0 
                    = vlSelfRef.row_idx;
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__pst_valid.enqueue(1U, (IData)(__VdlyDim0__dispatcher__DOT__pst_valid__v0));
                __VdlyVal__dispatcher__DOT__collected_rows__v0 
                    = vlSelfRef.row_idx;
                __VdlyDim0__dispatcher__DOT__collected_rows__v0 
                    = (0xffU & (IData)(vlSelfRef.dispatcher__DOT__collect_count));
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__collected_rows.enqueue(__VdlyVal__dispatcher__DOT__collected_rows__v0, (IData)(__VdlyDim0__dispatcher__DOT__collected_rows__v0));
                __Vdly__dispatcher__DOT__timeout_counter = 0U;
                if (vlSelfRef.row_last) {
                    vlSelfRef.dispatcher__DOT__last_row_seen = 1U;
                }
                __VdlyVal__dispatcher__DOT__sort_row_id__v2 
                    = vlSelfRef.row_idx;
                __VdlyDim0__dispatcher__DOT__sort_row_id__v2 
                    = (0xffU & (IData)(vlSelfRef.dispatcher__DOT__collect_count));
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.enqueue(__VdlyVal__dispatcher__DOT__sort_row_id__v2, (IData)(__VdlyDim0__dispatcher__DOT__sort_row_id__v2));
                __VdlyVal__dispatcher__DOT__sort_popcnt__v2 
                    = vlSelfRef.row_popcnt;
                __VdlyDim0__dispatcher__DOT__sort_popcnt__v2 
                    = (0xffU & (IData)(vlSelfRef.dispatcher__DOT__collect_count));
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.enqueue(__VdlyVal__dispatcher__DOT__sort_popcnt__v2, (IData)(__VdlyDim0__dispatcher__DOT__sort_popcnt__v2));
                vlSelfRef.dispatcher__DOT__collect_count 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.dispatcher__DOT__collect_count)));
            } else {
                __Vdly__dispatcher__DOT__timeout_counter 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.dispatcher__DOT__timeout_counter)));
                if ((0x1388U < (IData)(vlSelfRef.dispatcher__DOT__timeout_counter))) {
                    vlSelfRef.dispatcher__DOT__collect_timeout = 1U;
                }
            }
        } else {
            vlSelfRef.dispatcher__DOT__collect_count = 0U;
            __Vdly__dispatcher__DOT__dispatch_count = 0U;
            __Vdly__dispatcher__DOT__sort_count = 0U;
            vlSelfRef.dispatcher__DOT__last_row_seen = 0U;
            __Vdly__dispatcher__DOT__timeout_counter = 0U;
            vlSelfRef.dispatcher__DOT__collect_timeout = 0U;
            __Vdly__dispatcher__DOT__sort_stage = 0U;
            __Vdly__dispatcher__DOT__sort_temp_pc = 0U;
            __Vdly__dispatcher__DOT__sort_temp_row = 0U;
            vlSelfRef.dispatcher__DOT__i = 0U;
            while ((0x100U > vlSelfRef.dispatcher__DOT__i)) {
                __VdlyDim0__dispatcher__DOT__pst_valid__v1 
                    = (0xffU & vlSelfRef.dispatcher__DOT__i);
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__pst_valid.enqueue(0U, (IData)(__VdlyDim0__dispatcher__DOT__pst_valid__v1));
                __VdlyDim0__dispatcher__DOT__sort_row_id__v3 
                    = (0xffU & vlSelfRef.dispatcher__DOT__i);
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.enqueue(0U, (IData)(__VdlyDim0__dispatcher__DOT__sort_row_id__v3));
                __VdlyDim0__dispatcher__DOT__sort_popcnt__v3 
                    = (0xffU & vlSelfRef.dispatcher__DOT__i);
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.enqueue(0U, (IData)(__VdlyDim0__dispatcher__DOT__sort_popcnt__v3));
                __VdlyDim0__dispatcher__DOT__collected_rows__v1 
                    = (0xffU & vlSelfRef.dispatcher__DOT__i);
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__collected_rows.enqueue(0U, (IData)(__VdlyDim0__dispatcher__DOT__collected_rows__v1));
                vlSelfRef.dispatcher__DOT__i = ((IData)(1U) 
                                                + vlSelfRef.dispatcher__DOT__i);
            }
            if (((IData)(vlSelfRef.row_info_valid) 
                 & (IData)(vlSelfRef.dispatcher__DOT__row_info_ready))) {
                __VdlyVal__dispatcher__DOT__sort_row_id__v4 
                    = vlSelfRef.row_idx;
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.enqueue(__VdlyVal__dispatcher__DOT__sort_row_id__v4, 0U);
                __VdlyVal__dispatcher__DOT__sort_popcnt__v4 
                    = vlSelfRef.row_popcnt;
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.enqueue(__VdlyVal__dispatcher__DOT__sort_popcnt__v4, 0U);
                vlSelfRef.dispatcher__DOT__collect_count = 1U;
                __VdlyVal__dispatcher__DOT__pst_prefix_id__v1 
                    = vlSelfRef.row_prefix_id;
                __VdlyDim0__dispatcher__DOT__pst_prefix_id__v1 
                    = vlSelfRef.row_idx;
                __VdlySet__dispatcher__DOT__pst_prefix_id__v1 = 1U;
                __VdlyVal__dispatcher__DOT__pst_pattern__v1 
                    = vlSelfRef.row_pattern;
                __VdlyDim0__dispatcher__DOT__pst_pattern__v1 
                    = vlSelfRef.row_idx;
                __VdlyVal__dispatcher__DOT__pst_popcnt__v1 
                    = vlSelfRef.row_popcnt;
                __VdlyDim0__dispatcher__DOT__pst_popcnt__v1 
                    = vlSelfRef.row_idx;
                __VdlyVal__dispatcher__DOT__pst_row_id__v1 
                    = vlSelfRef.row_idx;
                __VdlyDim0__dispatcher__DOT__pst_row_id__v1 
                    = vlSelfRef.row_idx;
                __VdlyDim0__dispatcher__DOT__pst_valid__v2 
                    = vlSelfRef.row_idx;
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__pst_valid.enqueue(1U, (IData)(__VdlyDim0__dispatcher__DOT__pst_valid__v2));
                __VdlyVal__dispatcher__DOT__collected_rows__v2 
                    = vlSelfRef.row_idx;
                vlSelfRef.__VdlyCommitQueuedispatcher__DOT__collected_rows.enqueue(__VdlyVal__dispatcher__DOT__collected_rows__v2, 0U);
                if (vlSelfRef.row_last) {
                    vlSelfRef.dispatcher__DOT__last_row_seen = 1U;
                }
            }
        }
    } else {
        __Vdly__dispatcher__DOT__state = 0U;
        vlSelfRef.dispatcher__DOT__collect_count = 0U;
        __Vdly__dispatcher__DOT__dispatch_count = 0U;
        __Vdly__dispatcher__DOT__sort_count = 0U;
        vlSelfRef.dispatcher__DOT__i = 0U;
        vlSelfRef.dispatcher__DOT__last_row_seen = 0U;
        vlSelfRef.dispatcher__DOT__task_valid = 0U;
        vlSelfRef.dispatcher__DOT__tile_done = 0U;
        __Vdly__dispatcher__DOT__timeout_counter = 0U;
        vlSelfRef.dispatcher__DOT__collect_timeout = 0U;
        __Vdly__dispatcher__DOT__sort_stage = 0U;
        __Vdly__dispatcher__DOT__sort_temp_pc = 0U;
        __Vdly__dispatcher__DOT__sort_temp_row = 0U;
        while ((0x100U > vlSelfRef.dispatcher__DOT__i)) {
            __VdlyDim0__dispatcher__DOT__pst_valid__v3 
                = (0xffU & vlSelfRef.dispatcher__DOT__i);
            vlSelfRef.__VdlyCommitQueuedispatcher__DOT__pst_valid.enqueue(0U, (IData)(__VdlyDim0__dispatcher__DOT__pst_valid__v3));
            __VdlyVal__dispatcher__DOT__sort_row_id__v5 
                = (0xffU & vlSelfRef.dispatcher__DOT__i);
            __VdlyDim0__dispatcher__DOT__sort_row_id__v5 
                = (0xffU & vlSelfRef.dispatcher__DOT__i);
            vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.enqueue(__VdlyVal__dispatcher__DOT__sort_row_id__v5, (IData)(__VdlyDim0__dispatcher__DOT__sort_row_id__v5));
            __VdlyDim0__dispatcher__DOT__sort_popcnt__v5 
                = (0xffU & vlSelfRef.dispatcher__DOT__i);
            vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.enqueue(0U, (IData)(__VdlyDim0__dispatcher__DOT__sort_popcnt__v5));
            vlSelfRef.dispatcher__DOT__i = ((IData)(1U) 
                                            + vlSelfRef.dispatcher__DOT__i);
        }
    }
    vlSelfRef.dispatcher__DOT__sort_stage = __Vdly__dispatcher__DOT__sort_stage;
    vlSelfRef.dispatcher__DOT__sort_temp_pc = __Vdly__dispatcher__DOT__sort_temp_pc;
    vlSelfRef.dispatcher__DOT__sort_temp_row = __Vdly__dispatcher__DOT__sort_temp_row;
    vlSelfRef.dispatcher__DOT__temp_pc = __Vdly__dispatcher__DOT__temp_pc;
    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_popcnt.commit(vlSelfRef.dispatcher__DOT__sort_popcnt);
    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__sort_row_id.commit(vlSelfRef.dispatcher__DOT__sort_row_id);
    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__pst_valid.commit(vlSelfRef.dispatcher__DOT__pst_valid);
    vlSelfRef.__VdlyCommitQueuedispatcher__DOT__collected_rows.commit(vlSelfRef.dispatcher__DOT__collected_rows);
    vlSelfRef.dispatcher__DOT__timeout_counter = __Vdly__dispatcher__DOT__timeout_counter;
    vlSelfRef.dispatcher__DOT__dispatch_count = __Vdly__dispatcher__DOT__dispatch_count;
    vlSelfRef.dispatcher__DOT__sort_count = __Vdly__dispatcher__DOT__sort_count;
    vlSelfRef.dispatcher__DOT__state = __Vdly__dispatcher__DOT__state;
    if (__VdlySet__dispatcher__DOT__pst_prefix_id__v0) {
        vlSelfRef.dispatcher__DOT__pst_prefix_id[__VdlyDim0__dispatcher__DOT__pst_prefix_id__v0] 
            = __VdlyVal__dispatcher__DOT__pst_prefix_id__v0;
        vlSelfRef.dispatcher__DOT__pst_pattern[__VdlyDim0__dispatcher__DOT__pst_pattern__v0] 
            = __VdlyVal__dispatcher__DOT__pst_pattern__v0;
        vlSelfRef.dispatcher__DOT__pst_popcnt[__VdlyDim0__dispatcher__DOT__pst_popcnt__v0] 
            = __VdlyVal__dispatcher__DOT__pst_popcnt__v0;
        vlSelfRef.dispatcher__DOT__pst_row_id[__VdlyDim0__dispatcher__DOT__pst_row_id__v0] 
            = __VdlyVal__dispatcher__DOT__pst_row_id__v0;
    }
    if (__VdlySet__dispatcher__DOT__pst_prefix_id__v1) {
        vlSelfRef.dispatcher__DOT__pst_prefix_id[__VdlyDim0__dispatcher__DOT__pst_prefix_id__v1] 
            = __VdlyVal__dispatcher__DOT__pst_prefix_id__v1;
        vlSelfRef.dispatcher__DOT__pst_pattern[__VdlyDim0__dispatcher__DOT__pst_pattern__v1] 
            = __VdlyVal__dispatcher__DOT__pst_pattern__v1;
        vlSelfRef.dispatcher__DOT__pst_popcnt[__VdlyDim0__dispatcher__DOT__pst_popcnt__v1] 
            = __VdlyVal__dispatcher__DOT__pst_popcnt__v1;
        vlSelfRef.dispatcher__DOT__pst_row_id[__VdlyDim0__dispatcher__DOT__pst_row_id__v1] 
            = __VdlyVal__dispatcher__DOT__pst_row_id__v1;
    }
    vlSelfRef.task_valid = vlSelfRef.dispatcher__DOT__task_valid;
    vlSelfRef.tile_done = vlSelfRef.dispatcher__DOT__tile_done;
    vlSelfRef.task_row_id = vlSelfRef.dispatcher__DOT__task_row_id;
    vlSelfRef.task_prefix_id = vlSelfRef.dispatcher__DOT__task_prefix_id;
    vlSelfRef.task_pattern = vlSelfRef.dispatcher__DOT__task_pattern;
    vlSelfRef.dispatcher__DOT__row_info_ready = ((0U 
                                                  == (IData)(vlSelfRef.dispatcher__DOT__state)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.dispatcher__DOT__state)));
    vlSelfRef.dispatcher__DOT__next_state = vlSelfRef.dispatcher__DOT__state;
    if ((4U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
        vlSelfRef.dispatcher__DOT__next_state = 0U;
    } else if ((2U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
            if (((IData)(vlSelfRef.dispatcher__DOT__dispatch_count) 
                 >= (IData)(vlSelfRef.dispatcher__DOT__collect_count))) {
                vlSelfRef.dispatcher__DOT__next_state = 4U;
            }
        } else if (((IData)(vlSelfRef.dispatcher__DOT__sort_count) 
                    >= (IData)(vlSelfRef.dispatcher__DOT__collect_count))) {
            vlSelfRef.dispatcher__DOT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.dispatcher__DOT__state))) {
        if (((((0x100U == (IData)(vlSelfRef.dispatcher__DOT__collect_count)) 
               | (IData)(vlSelfRef.pruner_done)) | (IData)(vlSelfRef.dispatcher__DOT__collect_timeout)) 
             | (IData)(vlSelfRef.dispatcher__DOT__last_row_seen))) {
            vlSelfRef.dispatcher__DOT__next_state = 2U;
        }
    } else if (vlSelfRef.row_info_valid) {
        vlSelfRef.dispatcher__DOT__next_state = 1U;
    }
    vlSelfRef.row_info_ready = vlSelfRef.dispatcher__DOT__row_info_ready;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

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
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/dispatcher.v", 12, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/dispatcher.v", 12, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/Users/lazybanana/github/snn_prosperity/ppu/dispatcher.v", 12, "", "Active region did not converge.");
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
    if (VL_UNLIKELY(((vlSelfRef.row_info_valid & 0xfeU)))) {
        Verilated::overWidthError("row_info_valid");}
    if (VL_UNLIKELY(((vlSelfRef.row_last & 0xfeU)))) {
        Verilated::overWidthError("row_last");}
    if (VL_UNLIKELY(((vlSelfRef.proc_ready & 0xfeU)))) {
        Verilated::overWidthError("proc_ready");}
    if (VL_UNLIKELY(((vlSelfRef.prev_compute_busy & 0xfeU)))) {
        Verilated::overWidthError("prev_compute_busy");}
    if (VL_UNLIKELY(((vlSelfRef.pruner_done & 0xfeU)))) {
        Verilated::overWidthError("pruner_done");}
}
#endif  // VL_DEBUG
