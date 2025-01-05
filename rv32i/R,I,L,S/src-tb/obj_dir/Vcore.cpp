// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore.h for the primary calling header

#include "Vcore.h"
#include "Vcore__Syms.h"

//==========

void Vcore::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcore::eval\n"); );
    Vcore__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("core.sv", 23, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcore::_eval_initial_loop(Vcore__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("core.sv", 23, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcore::_sequent__TOP__1(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__1\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0;
    CData/*0:0*/ __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0;
    CData/*0:0*/ __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v1;
    IData/*31:0*/ __Vdlyvval__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0;
    // Body
    vlTOPp->__Vdly__core__DOT__pc_address = vlTOPp->core__DOT__pc_address;
    if ((1U & (~ (IData)(vlTOPp->rst)))) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__i = 0x20U;
    }
    __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 = 0U;
    __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v1 = 0U;
    vlTOPp->core__DOT__valid = ((IData)(vlTOPp->rst) 
                                & (IData)(vlTOPp->core__DOT__instruction_mem_request));
    if (vlTOPp->rst) {
        if (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
             & (~ (IData)(vlTOPp->core__DOT__data_mem_valid)))) {
            vlTOPp->__Vdly__core__DOT__pc_address = vlTOPp->core__DOT__pc_address;
            vlTOPp->core__DOT__u_Core10__DOT__pre_pc 
                = vlTOPp->core__DOT__u_Core10__DOT__pre_pc;
        } else {
            vlTOPp->__Vdly__core__DOT__pc_address = 
                ((IData)(4U) + vlTOPp->core__DOT__pc_address);
            vlTOPp->core__DOT__u_Core10__DOT__pre_pc 
                = vlTOPp->core__DOT__pc_address;
        }
    } else {
        vlTOPp->__Vdly__core__DOT__pc_address = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__pre_pc = vlTOPp->core__DOT__pc_address;
    }
    if (vlTOPp->rst) {
        if ((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type) 
                | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)) 
               | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
              | (IData)(vlTOPp->core__DOT__data_mem_valid))
              ? 1U : 0U)) {
            vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT____Vlvbound1 
                = ((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                    ? vlTOPp->core__DOT__u_Core10__DOT__alu_res_out
                    : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                        ? vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out
                        : 0U));
            if ((0x1eU >= (0x1fU & ((vlTOPp->core__DOT__instruction_o 
                                     >> 7U) - (IData)(1U))))) {
                __Vdlyvval__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 
                    = vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT____Vlvbound1;
                __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 = 1U;
                __Vdlyvdim0__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 
                    = (0x1fU & ((vlTOPp->core__DOT__instruction_o 
                                 >> 7U) - (IData)(1U)));
            }
        }
    } else {
        __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v1 = 1U;
    }
    if (__Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[__Vdlyvdim0__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0] 
            = __Vdlyvval__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0;
    }
    if (__Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v1) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[1U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[2U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[3U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[4U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[5U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[6U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[7U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[8U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[9U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0xaU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0xbU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0xcU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0xdU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0xeU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0xfU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x10U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x11U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x12U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x13U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x14U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x15U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x16U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x17U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x18U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x19U] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x1aU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x1bU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x1cU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x1dU] = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0x1eU] = 0U;
    }
    vlTOPp->core__DOT__data_mem_valid = ((IData)(vlTOPp->rst) 
                                         & (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load));
}

VL_INLINE_OPT void Vcore::_sequent__TOP__2(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__2\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1;
    CData/*4:0*/ __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2;
    CData/*4:0*/ __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3;
    CData/*4:0*/ __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3;
    // Body
    __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0 = 0U;
    __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1 = 0U;
    __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2 = 0U;
    __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3 = 0U;
    if ((1U & (~ ((IData)(vlTOPp->core__DOT__data_mem_request) 
                  & (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store))))) {
        if (((IData)(vlTOPp->core__DOT__data_mem_request) 
             & (~ (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)))) {
            vlTOPp->core__DOT__DM_load_data_in = vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem
                [(0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                           >> 2U))];
        }
    }
    if (vlTOPp->core__DOT__instruction_mem_request) {
        vlTOPp->core__DOT__instruction_o = vlTOPp->core__DOT__u_instruc_mem_top0__DOT__u_memory__DOT__mem
            [(0xffU & (vlTOPp->core__DOT__pc_address 
                       >> 2U))];
    }
    if (((IData)(vlTOPp->core__DOT__data_mem_request) 
         & (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store))) {
        if ((1U & (IData)(vlTOPp->core__DOT__data_mem_mask))) {
            __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0 
                = (0xffU & vlTOPp->core__DOT__DM_store_data_out);
            __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0 = 1U;
            __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0 = 0U;
            __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0 
                = (0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                            >> 2U));
        }
        if ((2U & (IData)(vlTOPp->core__DOT__data_mem_mask))) {
            __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1 
                = (0xffU & (vlTOPp->core__DOT__DM_store_data_out 
                            >> 8U));
            __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1 = 1U;
            __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1 = 8U;
            __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1 
                = (0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                            >> 2U));
        }
        if ((4U & (IData)(vlTOPp->core__DOT__data_mem_mask))) {
            __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2 
                = (0xffU & (vlTOPp->core__DOT__DM_store_data_out 
                            >> 0x10U));
            __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2 = 1U;
            __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2 
                = (0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                            >> 2U));
        }
        if ((8U & (IData)(vlTOPp->core__DOT__data_mem_mask))) {
            __Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3 
                = (0xffU & (vlTOPp->core__DOT__DM_store_data_out 
                            >> 0x18U));
            __Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3 = 1U;
            __Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3 
                = (0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                            >> 2U));
        }
    }
    if (__Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0) {
        vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem[__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0))) 
                & vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem
                [__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0]) 
               | ((IData)(__Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0) 
                  << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v0)));
    }
    if (__Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1) {
        vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem[__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1))) 
                & vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem
                [__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1]) 
               | ((IData)(__Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1) 
                  << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v1)));
    }
    if (__Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2) {
        vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem[__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2))) 
                & vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem
                [__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2]) 
               | ((IData)(__Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2) 
                  << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v2)));
    }
    if (__Vdlyvset__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3) {
        vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem[__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3))) 
                & vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem
                [__Vdlyvdim0__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3]) 
               | ((IData)(__Vdlyvval__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3) 
                  << (IData)(__Vdlyvlsb__core__DOT__u_data_memory0__DOT__u_memory__DOT__mem__v3)));
    }
}

VL_INLINE_OPT void Vcore::_sequent__TOP__5(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__5\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->core__DOT__pc_address = vlTOPp->__Vdly__core__DOT__pc_address;
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->core__DOT__data_mem_valid) 
                             << 7U) | (0x7fU & vlTOPp->core__DOT__instruction_o));
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store
        [vlTOPp->__Vtableidx1];
    if ((8U & vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1])) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load 
            = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load
            [vlTOPp->__Vtableidx1];
    }
    vlTOPp->core__DOT__instruction_mem_request = (1U 
                                                  & (~ 
                                                     ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
                                                      & (~ (IData)(vlTOPp->core__DOT__data_mem_valid)))));
    vlTOPp->core__DOT__data_mem_request = ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
                                           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store));
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
                             << 7U) | (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store) 
                                        << 6U) | (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                                                   << 5U) 
                                                  | ((0x10U 
                                                      & (vlTOPp->core__DOT__instruction_o 
                                                         >> 0x1aU)) 
                                                     | ((0xeU 
                                                         & (vlTOPp->core__DOT__instruction_o 
                                                            >> 0xbU)) 
                                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type))))));
    if ((1U & vlTOPp->__Vtablechg2[vlTOPp->__Vtableidx2])) {
        vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg 
            = vlTOPp->__Vtable2_core__DOT__u_Core10__DOT__mem_to_reg
            [vlTOPp->__Vtableidx2];
    }
    if ((2U & vlTOPp->__Vtablechg2[vlTOPp->__Vtableidx2])) {
        vlTOPp->core__DOT__u_Core10__DOT__alu_control 
            = vlTOPp->__Vtable2_core__DOT__u_Core10__DOT__alu_control
            [vlTOPp->__Vtableidx2];
    }
    if ((4U & vlTOPp->__Vtablechg2[vlTOPp->__Vtableidx2])) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel 
            = vlTOPp->__Vtable2_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel
            [vlTOPp->__Vtableidx2];
    }
    vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out = 
        (((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store))
           ? 1U : 0U) ? ((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
                          ? ((0xfffff000U & ((- (IData)(
                                                        (1U 
                                                         & (vlTOPp->core__DOT__instruction_o 
                                                            >> 0x1fU)))) 
                                             << 0xcU)) 
                             | (0xfffU & (vlTOPp->core__DOT__instruction_o 
                                          >> 0x14U)))
                          : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
                              ? ((0xfffff000U & ((- (IData)(
                                                            (1U 
                                                             & (vlTOPp->core__DOT__instruction_o 
                                                                >> 0x1fU)))) 
                                                 << 0xcU)) 
                                 | ((0xfe0U & (vlTOPp->core__DOT__instruction_o 
                                               >> 0x14U)) 
                                    | (0x1fU & (vlTOPp->core__DOT__instruction_o 
                                                >> 7U))))
                              : 0U)) : ((0U != (0x1fU 
                                                & (vlTOPp->core__DOT__instruction_o 
                                                   >> 0x14U)))
                                         ? ((0x1eU 
                                             >= (0x1fU 
                                                 & ((vlTOPp->core__DOT__instruction_o 
                                                     >> 0x14U) 
                                                    - (IData)(1U))))
                                             ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                            [(0x1fU 
                                              & ((vlTOPp->core__DOT__instruction_o 
                                                  >> 0x14U) 
                                                 - (IData)(1U)))]
                                             : 0U) : 0U));
    vlTOPp->core__DOT__u_Core10__DOT__alu_res_out = 
        ((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
          ? (((0U != (0x1fU & (vlTOPp->core__DOT__instruction_o 
                               >> 0xfU))) ? ((0x1eU 
                                              >= (0x1fU 
                                                  & ((vlTOPp->core__DOT__instruction_o 
                                                      >> 0xfU) 
                                                     - (IData)(1U))))
                                              ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                             [(0x1fU 
                                               & ((vlTOPp->core__DOT__instruction_o 
                                                   >> 0xfU) 
                                                  - (IData)(1U)))]
                                              : 0U)
               : 0U) + vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
          : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
              ? (((0U != (0x1fU & (vlTOPp->core__DOT__instruction_o 
                                   >> 0xfU))) ? ((0x1eU 
                                                  >= 
                                                  (0x1fU 
                                                   & ((vlTOPp->core__DOT__instruction_o 
                                                       >> 0xfU) 
                                                      - (IData)(1U))))
                                                  ? 
                                                 vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                 [(0x1fU 
                                                   & ((vlTOPp->core__DOT__instruction_o 
                                                       >> 0xfU) 
                                                      - (IData)(1U)))]
                                                  : 0U)
                   : 0U) - vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
              : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                  ? ((0x1fU >= vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                      ? (((0U != (0x1fU & (vlTOPp->core__DOT__instruction_o 
                                           >> 0xfU)))
                           ? ((0x1eU >= (0x1fU & ((vlTOPp->core__DOT__instruction_o 
                                                   >> 0xfU) 
                                                  - (IData)(1U))))
                               ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                              [(0x1fU & ((vlTOPp->core__DOT__instruction_o 
                                          >> 0xfU) 
                                         - (IData)(1U)))]
                               : 0U) : 0U) << vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                      : 0U) : (((3U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control)) 
                                & VL_LTS_III(1,32,32, 
                                             ((0U != 
                                               (0x1fU 
                                                & (vlTOPp->core__DOT__instruction_o 
                                                   >> 0xfU)))
                                               ? ((0x1eU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((vlTOPp->core__DOT__instruction_o 
                                                        >> 0xfU) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                  [
                                                  (0x1fU 
                                                   & ((vlTOPp->core__DOT__instruction_o 
                                                       >> 0xfU) 
                                                      - (IData)(1U)))]
                                                   : 0U)
                                               : 0U), vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out))
                                ? 1U : (((4U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control)) 
                                         & (((0U != 
                                              (0x1fU 
                                               & (vlTOPp->core__DOT__instruction_o 
                                                  >> 0xfU)))
                                              ? ((0x1eU 
                                                  >= 
                                                  (0x1fU 
                                                   & ((vlTOPp->core__DOT__instruction_o 
                                                       >> 0xfU) 
                                                      - (IData)(1U))))
                                                  ? 
                                                 vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                 [(0x1fU 
                                                   & ((vlTOPp->core__DOT__instruction_o 
                                                       >> 0xfU) 
                                                      - (IData)(1U)))]
                                                  : 0U)
                                              : 0U) 
                                            < vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out))
                                         ? 1U : ((5U 
                                                  == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                  ? 
                                                 (((0U 
                                                    != 
                                                    (0x1fU 
                                                     & (vlTOPp->core__DOT__instruction_o 
                                                        >> 0xfU)))
                                                    ? 
                                                   ((0x1eU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((vlTOPp->core__DOT__instruction_o 
                                                          >> 0xfU) 
                                                         - (IData)(1U))))
                                                     ? 
                                                    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                    [
                                                    (0x1fU 
                                                     & ((vlTOPp->core__DOT__instruction_o 
                                                         >> 0xfU) 
                                                        - (IData)(1U)))]
                                                     : 0U)
                                                    : 0U) 
                                                  ^ vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                   ? 
                                                  ((0x1fU 
                                                    >= vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                    ? 
                                                   (((0U 
                                                      != 
                                                      (0x1fU 
                                                       & (vlTOPp->core__DOT__instruction_o 
                                                          >> 0xfU)))
                                                      ? 
                                                     ((0x1eU 
                                                       >= 
                                                       (0x1fU 
                                                        & ((vlTOPp->core__DOT__instruction_o 
                                                            >> 0xfU) 
                                                           - (IData)(1U))))
                                                       ? 
                                                      vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                      [
                                                      (0x1fU 
                                                       & ((vlTOPp->core__DOT__instruction_o 
                                                           >> 0xfU) 
                                                          - (IData)(1U)))]
                                                       : 0U)
                                                      : 0U) 
                                                    >> vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                    : 0U)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                     ? 
                                                    (((0U 
                                                       != 
                                                       (0x1fU 
                                                        & (vlTOPp->core__DOT__instruction_o 
                                                           >> 0xfU)))
                                                       ? 
                                                      ((0x1eU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((vlTOPp->core__DOT__instruction_o 
                                                             >> 0xfU) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                       [
                                                       (0x1fU 
                                                        & ((vlTOPp->core__DOT__instruction_o 
                                                            >> 0xfU) 
                                                           - (IData)(1U)))]
                                                        : 0U)
                                                       : 0U) 
                                                     >> vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                     : 0U)
                                                    : 
                                                   ((8U 
                                                     == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                     ? 
                                                    (((0U 
                                                       != 
                                                       (0x1fU 
                                                        & (vlTOPp->core__DOT__instruction_o 
                                                           >> 0xfU)))
                                                       ? 
                                                      ((0x1eU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((vlTOPp->core__DOT__instruction_o 
                                                             >> 0xfU) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                       [
                                                       (0x1fU 
                                                        & ((vlTOPp->core__DOT__instruction_o 
                                                            >> 0xfU) 
                                                           - (IData)(1U)))]
                                                        : 0U)
                                                       : 0U) 
                                                     | vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                      ? 
                                                     (((0U 
                                                        != 
                                                        (0x1fU 
                                                         & (vlTOPp->core__DOT__instruction_o 
                                                            >> 0xfU)))
                                                        ? 
                                                       ((0x1eU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((vlTOPp->core__DOT__instruction_o 
                                                              >> 0xfU) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                                        [
                                                        (0x1fU 
                                                         & ((vlTOPp->core__DOT__instruction_o 
                                                             >> 0xfU) 
                                                            - (IData)(1U)))]
                                                         : 0U)
                                                        : 0U) 
                                                      & vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                      : 0U))))))))));
    if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store) {
        vlTOPp->core__DOT__data_mem_mask = 0U;
        if ((0U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__data_mem_mask = 1U;
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__data_mem_mask = 2U;
                }
            }
        }
        if ((1U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__data_mem_mask = 3U;
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__data_mem_mask = 6U;
                }
            }
        }
        if ((2U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__data_mem_mask = 0xfU;
        }
    }
    if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store) {
        if ((0U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__DM_store_data_out 
                    = vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out;
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__DM_store_data_out 
                        = ((0xffff0000U & vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out) 
                           | ((0xff00U & (vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out 
                                          << 8U)) | 
                              (0xffU & vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)));
                }
            }
        }
        if ((1U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__DM_store_data_out 
                    = vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out;
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__DM_store_data_out 
                        = ((0xff000000U & vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out) 
                           | ((0xffff00U & (vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out 
                                            << 8U)) 
                              | (0xffU & vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)));
                }
            }
        }
        if ((2U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__DM_store_data_out = vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out;
        }
    }
    if (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
         | (IData)(vlTOPp->core__DOT__data_mem_valid))) {
        if ((0U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                    = ((0xffffff00U & ((- (IData)((1U 
                                                   & (vlTOPp->core__DOT__DM_load_data_in 
                                                      >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->core__DOT__DM_load_data_in));
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                        = ((0xffffff00U & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__DM_load_data_in 
                                                          >> 0xfU)))) 
                                           << 8U)) 
                           | (0xffU & (vlTOPp->core__DOT__DM_load_data_in 
                                       >> 8U)));
                }
            }
        }
        if ((1U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                    = ((0xffff0000U & ((- (IData)((1U 
                                                   & (vlTOPp->core__DOT__DM_load_data_in 
                                                      >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->core__DOT__DM_load_data_in));
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                        = ((0xffff0000U & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__DM_load_data_in 
                                                          >> 0x17U)))) 
                                           << 0x10U)) 
                           | (0xffffU & (vlTOPp->core__DOT__DM_load_data_in 
                                         >> 8U)));
                }
            }
        }
        if ((2U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                = vlTOPp->core__DOT__DM_load_data_in;
        }
        if ((4U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                    = (0xffU & vlTOPp->core__DOT__DM_load_data_in);
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                        = (0xffU & (vlTOPp->core__DOT__DM_load_data_in 
                                    >> 8U));
                }
            }
        }
        if ((5U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                    = (0xffffU & vlTOPp->core__DOT__DM_load_data_in);
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                        = (0xffffU & (vlTOPp->core__DOT__DM_load_data_in 
                                      >> 8U));
                }
            }
        }
        if ((6U == (7U & (vlTOPp->core__DOT__instruction_o 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                = vlTOPp->core__DOT__DM_load_data_in;
        }
    }
}

void Vcore::_eval(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst)) & (IData)(vlTOPp->__Vclklast__TOP__rst)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst)) & (IData)(vlTOPp->__Vclklast__TOP__rst)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

VL_INLINE_OPT QData Vcore::_change_request(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_change_request\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vcore::_change_request_1(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_change_request_1\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcore::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
