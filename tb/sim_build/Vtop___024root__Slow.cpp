// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr CData/*2:0*/ Vtop___024root::top__DOT__ST_IDLE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__ST_LOAD;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__ST_INIT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__ST_PROCESS;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__ST_DONE;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__u_detector__DOT__ST_IDLE;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__u_detector__DOT__ST_LOAD;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__u_detector__DOT__ST_QUERY;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__u_detector__DOT__ST_POPCOUNT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_pruner__DOT__S_IDLE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_pruner__DOT__S_FILT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_pruner__DOT__S_SEL;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_pruner__DOT__S_XOR;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_pruner__DOT__S_OUT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_pruner__DOT__S_NEXT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__S_IDLE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__S_COLLECT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__S_SORT;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__S_DISPATCH;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__S_DONE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_processor__DOT__ST_IDLE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_processor__DOT__ST_LOAD_PFX;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_processor__DOT__ST_DECODE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_processor__DOT__ST_ACCUMULATE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__u_processor__DOT__ST_WRITEBACK;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__ROWS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__SPIKES;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__NO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__PE_COUNT;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__WEIGHT_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__ACC_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__SPIKES;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__ROWS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__NO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__TEST_ROWS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__tcam_core__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__tcam_core__DOT__KEY_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__tcam_core__DOT__MASK_DISABLE;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_detector__DOT__tcam_core__DOT__MEM_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_pruner__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_pruner__DOT__M;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_pruner__DOT__NO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__ROWS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__SPIKES;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__PATTERN_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__NO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_dispatcher__DOT__IDX_W;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_processor__DOT__ROWS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_processor__DOT__SPIKES;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_processor__DOT__PE_COUNT;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_processor__DOT__WEIGHT_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_processor__DOT__ACC_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__u_processor__DOT__NO_WIDTH;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
