// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr CData/*1:0*/ Vtop___024root::detector__DOT__ST_IDLE;
constexpr CData/*1:0*/ Vtop___024root::detector__DOT__ST_LOAD;
constexpr CData/*1:0*/ Vtop___024root::detector__DOT__ST_QUERY;
constexpr CData/*1:0*/ Vtop___024root::detector__DOT__ST_POPCOUNT;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__SPIKES;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__ROWS;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__NO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__TEST_ROWS;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__tcam_core__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__tcam_core__DOT__KEY_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__tcam_core__DOT__MASK_DISABLE;
constexpr IData/*31:0*/ Vtop___024root::detector__DOT__tcam_core__DOT__MEM_WIDTH;


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
