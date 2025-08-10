// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_dispatcher);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(141);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_dispatcher.configure(this, name(), "dispatcher", "dispatcher", "dispatcher", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_dispatcher);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"prev_compute_busy", &(TOP.prev_compute_busy), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"proc_ready", &(TOP.proc_ready), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"pruner_done", &(TOP.pruner_done), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_idx", &(TOP.row_idx), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_info_ready", &(TOP.row_info_ready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_info_valid", &(TOP.row_info_valid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_last", &(TOP.row_last), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_pattern", &(TOP.row_pattern), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_popcnt", &(TOP.row_popcnt), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"row_prefix_id", &(TOP.row_prefix_id), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_n", &(TOP.rst_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"task_pattern", &(TOP.task_pattern), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"task_prefix_id", &(TOP.task_prefix_id), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"task_row_id", &(TOP.task_row_id), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"task_valid", &(TOP.task_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"tile_done", &(TOP.tile_done), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"IDX_W", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__IDX_W))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"NO_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__NO_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"PATTERN_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__PATTERN_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"ROWS", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__ROWS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"SPIKES", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__SPIKES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"S_COLLECT", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__S_COLLECT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"S_DISPATCH", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__S_DISPATCH))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"S_DONE", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__S_DONE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"S_IDLE", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__S_IDLE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"S_SORT", const_cast<void*>(static_cast<const void*>(&(TOP.dispatcher__DOT__S_SORT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"clk", &(TOP.dispatcher__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"collect_count", &(TOP.dispatcher__DOT__collect_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"collect_timeout", &(TOP.dispatcher__DOT__collect_timeout), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"collected_rows", &(TOP.dispatcher__DOT__collected_rows), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"current_row", &(TOP.dispatcher__DOT__current_row), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"dispatch_count", &(TOP.dispatcher__DOT__dispatch_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"i", &(TOP.dispatcher__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"j", &(TOP.dispatcher__DOT__j), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"last_row_seen", &(TOP.dispatcher__DOT__last_row_seen), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"min_idx_found", &(TOP.dispatcher__DOT__min_idx_found), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"min_pc_found", &(TOP.dispatcher__DOT__min_pc_found), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"min_row_found", &(TOP.dispatcher__DOT__min_row_found), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"next_state", &(TOP.dispatcher__DOT__next_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"prev_compute_busy", &(TOP.dispatcher__DOT__prev_compute_busy), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"proc_ready", &(TOP.dispatcher__DOT__proc_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"pruner_done", &(TOP.dispatcher__DOT__pruner_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"pst_pattern", &(TOP.dispatcher__DOT__pst_pattern), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,15,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"pst_popcnt", &(TOP.dispatcher__DOT__pst_popcnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"pst_prefix_id", &(TOP.dispatcher__DOT__pst_prefix_id), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"pst_row_id", &(TOP.dispatcher__DOT__pst_row_id), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"pst_valid", &(TOP.dispatcher__DOT__pst_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,0 ,0,255);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_idx", &(TOP.dispatcher__DOT__row_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_info_ready", &(TOP.dispatcher__DOT__row_info_ready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_info_valid", &(TOP.dispatcher__DOT__row_info_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_last", &(TOP.dispatcher__DOT__row_last), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_pattern", &(TOP.dispatcher__DOT__row_pattern), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_popcnt", &(TOP.dispatcher__DOT__row_popcnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"row_prefix_id", &(TOP.dispatcher__DOT__row_prefix_id), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"rst_n", &(TOP.dispatcher__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"sort_count", &(TOP.dispatcher__DOT__sort_count), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"sort_popcnt", &(TOP.dispatcher__DOT__sort_popcnt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"sort_row_id", &(TOP.dispatcher__DOT__sort_row_id), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"sort_stage", &(TOP.dispatcher__DOT__sort_stage), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"sort_temp_pc", &(TOP.dispatcher__DOT__sort_temp_pc), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"sort_temp_row", &(TOP.dispatcher__DOT__sort_temp_row), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"state", &(TOP.dispatcher__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"task_pattern", &(TOP.dispatcher__DOT__task_pattern), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"task_prefix_id", &(TOP.dispatcher__DOT__task_prefix_id), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"task_row_id", &(TOP.dispatcher__DOT__task_row_id), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"task_valid", &(TOP.dispatcher__DOT__task_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"temp_pc", &(TOP.dispatcher__DOT__temp_pc), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"temp_row", &(TOP.dispatcher__DOT__temp_row), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"tile_done", &(TOP.dispatcher__DOT__tile_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dispatcher.varInsert(__Vfinal,"timeout_counter", &(TOP.dispatcher__DOT__timeout_counter), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
    }
}
