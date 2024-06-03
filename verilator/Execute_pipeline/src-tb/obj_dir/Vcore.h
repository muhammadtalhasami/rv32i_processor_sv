// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCORE_H_
#define _VCORE_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcore__Syms;
class Vcore_VerilatedVcd;


//----------

VL_MODULE(Vcore) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN(instruction,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ core__DOT__instruction_mem_request;
        CData/*0:0*/ core__DOT__valid;
        CData/*0:0*/ core__DOT__data_mem_valid;
        CData/*0:0*/ core__DOT__data_mem_request;
        CData/*0:0*/ core__DOT__data_mem_we_re;
        CData/*3:0*/ core__DOT__data_mem_mask;
        CData/*3:0*/ core__DOT__u_Core10__DOT__alu_control;
        CData/*0:0*/ core__DOT__u_Core10__DOT__branch_result;
        CData/*1:0*/ core__DOT__u_Core10__DOT__mem_to_reg;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline2;
        CData/*2:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc;
        CData/*4:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__r1;
        CData/*4:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__r2;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__rg;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__l;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__s;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__nextsel;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__branch_res;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__jalr;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__men;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__branch_;
        CData/*1:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__mem_reg;
        CData/*3:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__alu_con;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__load;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__store;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__reg_write;
        CData/*0:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__me;
        CData/*1:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg;
        IData/*31:0*/ core__DOT__pc_address;
        IData/*31:0*/ core__DOT__instruction_o;
        IData/*31:0*/ core__DOT__DM_load_data_in;
        IData/*31:0*/ core__DOT__DM_store_data_out;
        IData/*31:0*/ core__DOT__u_Core10__DOT__alu_in_b;
        IData/*31:0*/ core__DOT__u_Core10__DOT__alu_in_a;
        IData/*31:0*/ core__DOT__u_Core10__DOT__instruction_fetch_pp;
        IData/*31:0*/ core__DOT__u_Core10__DOT__pre_pc_fetch_pp;
        IData/*31:0*/ core__DOT__u_Core10__DOT__pre_pc;
        IData/*31:0*/ core__DOT__u_Core10__DOT__wrap_load_out;
        IData/*31:0*/ core__DOT__u_Core10__DOT__alu_res_out;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__i;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__opa_mux;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__opb_mux;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__pre_address;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__instruct;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__nextsel_addr;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__pre_address;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction;
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__opb_data;
    };
    struct {
        IData/*31:0*/ core__DOT__u_instruc_mem_top0__DOT__u_memory__DOT__mem[256];
        IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[31];
        IData/*31:0*/ core__DOT__u_data_memory0__DOT__u_memory__DOT__mem[256];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline;
    CData/*0:0*/ __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline2;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    SData/*8:0*/ __Vtableidx1;
    IData/*31:0*/ core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT____Vlvbound1;
    IData/*31:0*/ __Vdly__core__DOT__pc_address;
    IData/*31:0*/ __Vdly__core__DOT__u_Core10__DOT__pre_pc;
    CData/*0:0*/ __Vm_traceActivity[7];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui[512];
    static CData/*0:0*/ __Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc[512];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcore__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcore);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcore(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcore();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcore__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcore__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcore__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vcore__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcore__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__4(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vcore__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
