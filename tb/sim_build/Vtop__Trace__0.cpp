// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.row_info_valid));
    bufp->chgBit(oldp+3,(vlSelfRef.row_info_ready));
    bufp->chgCData(oldp+4,(vlSelfRef.row_idx),8);
    bufp->chgCData(oldp+5,(vlSelfRef.row_prefix_id),8);
    bufp->chgSData(oldp+6,(vlSelfRef.row_pattern),16);
    bufp->chgCData(oldp+7,(vlSelfRef.row_popcnt),8);
    bufp->chgBit(oldp+8,(vlSelfRef.row_last));
    bufp->chgBit(oldp+9,(vlSelfRef.proc_ready));
    bufp->chgBit(oldp+10,(vlSelfRef.task_valid));
    bufp->chgCData(oldp+11,(vlSelfRef.task_row_id),8);
    bufp->chgCData(oldp+12,(vlSelfRef.task_prefix_id),8);
    bufp->chgSData(oldp+13,(vlSelfRef.task_pattern),16);
    bufp->chgBit(oldp+14,(vlSelfRef.prev_compute_busy));
    bufp->chgBit(oldp+15,(vlSelfRef.pruner_done));
    bufp->chgBit(oldp+16,(vlSelfRef.tile_done));
    bufp->chgBit(oldp+17,(vlSelfRef.dispatcher__DOT__clk));
    bufp->chgBit(oldp+18,(vlSelfRef.dispatcher__DOT__rst_n));
    bufp->chgBit(oldp+19,(vlSelfRef.dispatcher__DOT__row_info_valid));
    bufp->chgBit(oldp+20,(vlSelfRef.dispatcher__DOT__row_info_ready));
    bufp->chgCData(oldp+21,(vlSelfRef.dispatcher__DOT__row_idx),8);
    bufp->chgCData(oldp+22,(vlSelfRef.dispatcher__DOT__row_prefix_id),8);
    bufp->chgSData(oldp+23,(vlSelfRef.dispatcher__DOT__row_pattern),16);
    bufp->chgCData(oldp+24,(vlSelfRef.dispatcher__DOT__row_popcnt),8);
    bufp->chgBit(oldp+25,(vlSelfRef.dispatcher__DOT__row_last));
    bufp->chgBit(oldp+26,(vlSelfRef.dispatcher__DOT__proc_ready));
    bufp->chgBit(oldp+27,(vlSelfRef.dispatcher__DOT__task_valid));
    bufp->chgCData(oldp+28,(vlSelfRef.dispatcher__DOT__task_row_id),8);
    bufp->chgCData(oldp+29,(vlSelfRef.dispatcher__DOT__task_prefix_id),8);
    bufp->chgSData(oldp+30,(vlSelfRef.dispatcher__DOT__task_pattern),16);
    bufp->chgBit(oldp+31,(vlSelfRef.dispatcher__DOT__prev_compute_busy));
    bufp->chgBit(oldp+32,(vlSelfRef.dispatcher__DOT__pruner_done));
    bufp->chgBit(oldp+33,(vlSelfRef.dispatcher__DOT__tile_done));
    bufp->chgCData(oldp+34,(vlSelfRef.dispatcher__DOT__temp_pc),8);
    bufp->chgCData(oldp+35,(vlSelfRef.dispatcher__DOT__temp_row),8);
    bufp->chgCData(oldp+36,(vlSelfRef.dispatcher__DOT__state),3);
    bufp->chgCData(oldp+37,(vlSelfRef.dispatcher__DOT__next_state),3);
    bufp->chgSData(oldp+38,(vlSelfRef.dispatcher__DOT__collect_count),9);
    bufp->chgSData(oldp+39,(vlSelfRef.dispatcher__DOT__dispatch_count),9);
    bufp->chgSData(oldp+40,(vlSelfRef.dispatcher__DOT__sort_count),9);
    bufp->chgBit(oldp+41,(vlSelfRef.dispatcher__DOT__last_row_seen));
    bufp->chgSData(oldp+42,(vlSelfRef.dispatcher__DOT__timeout_counter),16);
    bufp->chgBit(oldp+43,(vlSelfRef.dispatcher__DOT__collect_timeout));
    bufp->chgCData(oldp+44,(vlSelfRef.dispatcher__DOT__sort_stage),2);
    bufp->chgCData(oldp+45,(vlSelfRef.dispatcher__DOT__sort_temp_pc),8);
    bufp->chgCData(oldp+46,(vlSelfRef.dispatcher__DOT__sort_temp_row),8);
    bufp->chgIData(oldp+47,(vlSelfRef.dispatcher__DOT__i),32);
    bufp->chgIData(oldp+48,(vlSelfRef.dispatcher__DOT__j),32);
    bufp->chgCData(oldp+49,(vlSelfRef.dispatcher__DOT__current_row),8);
    bufp->chgIData(oldp+50,(vlSelfRef.dispatcher__DOT__min_idx_found),32);
    bufp->chgIData(oldp+51,(vlSelfRef.dispatcher__DOT__min_pc_found),32);
    bufp->chgIData(oldp+52,(vlSelfRef.dispatcher__DOT__min_row_found),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
