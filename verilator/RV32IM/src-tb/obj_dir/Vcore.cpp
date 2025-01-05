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
    vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
        = vlTOPp->core__DOT__u_Core10__DOT__pre_pc;
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
            vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
                = vlTOPp->core__DOT__u_Core10__DOT__pre_pc;
        } else {
            if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal) {
                vlTOPp->__Vdly__core__DOT__pc_address 
                    = vlTOPp->core__DOT__u_Core10__DOT__alu_res_out;
                vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
                    = vlTOPp->core__DOT__pc_address;
            } else {
                if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) {
                    if (vlTOPp->core__DOT__u_Core10__DOT__branch_result) {
                        vlTOPp->__Vdly__core__DOT__pc_address 
                            = vlTOPp->core__DOT__u_Core10__DOT__alu_res_out;
                        vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
                            = vlTOPp->core__DOT__pc_address;
                    }
                } else {
                    if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr) {
                        vlTOPp->__Vdly__core__DOT__pc_address 
                            = vlTOPp->core__DOT__u_Core10__DOT__alu_res_out;
                        vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
                            = vlTOPp->core__DOT__pc_address;
                    } else {
                        vlTOPp->__Vdly__core__DOT__pc_address 
                            = ((IData)(4U) + vlTOPp->core__DOT__pc_address);
                        vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
                            = vlTOPp->core__DOT__pc_address;
                    }
                }
            }
        }
    } else {
        vlTOPp->__Vdly__core__DOT__pc_address = 0U;
        vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc 
            = vlTOPp->core__DOT__pc_address;
    }
    if (vlTOPp->rst) {
        if ((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type) 
                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)) 
                   | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                  | (IData)(vlTOPp->core__DOT__data_mem_valid)) 
                 | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
               | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
              | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
              ? 1U : 0U)) {
            vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT____Vlvbound1 
                = ((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                    ? vlTOPp->core__DOT__u_Core10__DOT__alu_res_out
                    : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                        ? vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out
                        : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                            ? ((IData)(4U) + vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address)
                            : 0U)));
            if ((0x1eU >= (0x1fU & ((vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                     >> 7U) - (IData)(1U))))) {
                __Vdlyvval__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 
                    = vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT____Vlvbound1;
                __Vdlyvset__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 = 1U;
                __Vdlyvdim0__core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register__v0 
                    = (0x1fU & ((vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
    CData/*0:0*/ __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline;
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
    __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline 
        = vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline;
    if ((1U & (~ ((IData)(vlTOPp->core__DOT__data_mem_request) 
                  & (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store))))) {
        if (((IData)(vlTOPp->core__DOT__data_mem_request) 
             & (~ (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)))) {
            vlTOPp->core__DOT__DM_load_data_in = vlTOPp->core__DOT__u_data_memory0__DOT__u_memory__DOT__mem
                [(0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                           >> 2U))];
        }
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
    if ((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal) 
          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__branch_result)) 
         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr))) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address = 0U;
        vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc = 0U;
        __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline = 1U;
    } else {
        if (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline) {
            vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address = 0U;
            vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc = 0U;
            __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline = 0U;
        } else {
            if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) {
                vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address 
                    = vlTOPp->core__DOT__u_Core10__DOT__pre_pc_fetch_pp;
                vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                    = vlTOPp->core__DOT__u_Core10__DOT__instruction_fetch_pp;
            } else {
                vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address 
                    = vlTOPp->core__DOT__u_Core10__DOT__pre_pc;
                vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                    = vlTOPp->core__DOT__instruction_o;
            }
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
    vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline 
        = __Vdly__core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline;
    if (vlTOPp->core__DOT__instruction_mem_request) {
        vlTOPp->core__DOT__instruction_o = vlTOPp->core__DOT__u_instruc_mem_top0__DOT__u_memory__DOT__mem
            [(0xffU & (vlTOPp->core__DOT__pc_address 
                       >> 2U))];
    }
    vlTOPp->core__DOT__u_Core10__DOT__pre_pc_fetch_pp 
        = vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address;
    vlTOPp->core__DOT__u_Core10__DOT__instruction_fetch_pp 
        = vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc;
}

VL_INLINE_OPT void Vcore::_sequent__TOP__5(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__5\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->core__DOT__u_Core10__DOT__pre_pc = vlTOPp->__Vdly__core__DOT__u_Core10__DOT__pre_pc;
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a 
        = ((0U != (0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                            >> 0xfU))) ? ((0x1eU >= 
                                           (0x1fU & 
                                            ((vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                              >> 0xfU) 
                                             - (IData)(1U))))
                                           ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                          [(0x1fU & 
                                            ((vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                              >> 0xfU) 
                                             - (IData)(1U)))]
                                           : 0U) : 0U);
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b 
        = ((0U != (0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                            >> 0x14U))) ? ((0x1eU >= 
                                            (0x1fU 
                                             & ((vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                 >> 0x14U) 
                                                - (IData)(1U))))
                                            ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register
                                           [(0x1fU 
                                             & ((vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                 >> 0x14U) 
                                                - (IData)(1U)))]
                                            : 0U) : 0U);
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->core__DOT__data_mem_valid) 
                             << 7U) | (0x7fU & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc));
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc 
        = vlTOPp->__Vtable1_core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc
        [vlTOPp->__Vtableidx1];
    vlTOPp->core__DOT__pc_address = vlTOPp->__Vdly__core__DOT__pc_address;
    vlTOPp->core__DOT__instruction_mem_request = (1U 
                                                  & (~ 
                                                     ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
                                                      & (~ (IData)(vlTOPp->core__DOT__data_mem_valid)))));
    vlTOPp->core__DOT__data_mem_request = ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
                                           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store));
    if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) {
        if ((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__u_Core10__DOT__branch_result 
                = ((vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a 
                    == vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)
                    ? 1U : 0U);
        } else {
            if ((1U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                              >> 0xcU)))) {
                vlTOPp->core__DOT__u_Core10__DOT__branch_result 
                    = ((vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a 
                        != vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)
                        ? 1U : 0U);
            } else {
                if ((4U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                  >> 0xcU)))) {
                    vlTOPp->core__DOT__u_Core10__DOT__branch_result 
                        = (VL_LTS_III(1,32,32, vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a, vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)
                            ? 1U : 0U);
                } else {
                    if ((5U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                      >> 0xcU)))) {
                        vlTOPp->core__DOT__u_Core10__DOT__branch_result 
                            = (VL_GTES_III(1,32,32, vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a, vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)
                                ? 1U : 0U);
                    } else {
                        if ((6U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                          >> 0xcU)))) {
                            vlTOPp->core__DOT__u_Core10__DOT__branch_result 
                                = ((vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a 
                                    < vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)
                                    ? 1U : 0U);
                        } else {
                            if ((7U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                              >> 0xcU)))) {
                                vlTOPp->core__DOT__u_Core10__DOT__branch_result 
                                    = ((vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a 
                                        >= vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)
                                        ? 1U : 0U);
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->core__DOT__u_Core10__DOT__branch_result = 0U;
    }
    vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg = 
        ((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type) 
               | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)) 
              | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
             | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
          ? 0U : (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
                   | (IData)(vlTOPp->core__DOT__data_mem_valid))
                   ? 1U : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)
                            ? 2U : 0U)));
    vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out = 
        (((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
           ? 1U : 0U) ? vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address
          : vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a);
    vlTOPp->core__DOT__u_Core10__DOT__alu_control = 
        (0x1fU & ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type)
                   ? (((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                     >> 0xcU))) & (0U 
                                                   == 
                                                   (0x7fU 
                                                    & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                       >> 0x19U))))
                       ? 0U : (((1U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                              >> 0xcU))) 
                                & (0U == (0x7fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                   >> 0x19U))))
                                ? 2U : (((2U == (7U 
                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                    >> 0xcU))) 
                                         & (0U == (0x7fU 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0x19U))))
                                         ? 3U : (((3U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                       >> 0xcU))) 
                                                  & (0U 
                                                     == 
                                                     (0x7fU 
                                                      & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                         >> 0x19U))))
                                                  ? 4U
                                                  : 
                                                 (((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                        >> 0xcU))) 
                                                   & (0U 
                                                      == 
                                                      (0x7fU 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x19U))))
                                                   ? 5U
                                                   : 
                                                  (((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                         >> 0xcU))) 
                                                    & (0U 
                                                       == 
                                                       (0x7fU 
                                                        & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                           >> 0x19U))))
                                                    ? 6U
                                                    : 
                                                   (((6U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0xcU))) 
                                                     & (0U 
                                                        == 
                                                        (0x7fU 
                                                         & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                            >> 0x19U))))
                                                     ? 8U
                                                     : 
                                                    (((7U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                           >> 0xcU))) 
                                                      & (0U 
                                                         == 
                                                         (0x7fU 
                                                          & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                             >> 0x19U))))
                                                      ? 9U
                                                      : 
                                                     (((0U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                            >> 0xcU))) 
                                                       & (1U 
                                                          == 
                                                          (0x7fU 
                                                           & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                              >> 0x19U))))
                                                       ? 0x10U
                                                       : 
                                                      (((1U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                             >> 0xcU))) 
                                                        & (1U 
                                                           == 
                                                           (0x7fU 
                                                            & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                               >> 0x19U))))
                                                        ? 0x11U
                                                        : 
                                                       (((2U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                              >> 0xcU))) 
                                                         & (1U 
                                                            == 
                                                            (0x7fU 
                                                             & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                >> 0x19U))))
                                                         ? 0x12U
                                                         : 
                                                        (((3U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                               >> 0xcU))) 
                                                          & (1U 
                                                             == 
                                                             (0x7fU 
                                                              & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                 >> 0x19U))))
                                                          ? 0x13U
                                                          : 
                                                         (((4U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                >> 0xcU))) 
                                                           & (1U 
                                                              == 
                                                              (0x7fU 
                                                               & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                  >> 0x19U))))
                                                           ? 0x14U
                                                           : 
                                                          (((5U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                 >> 0xcU))) 
                                                            & (1U 
                                                               == 
                                                               (0x7fU 
                                                                & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                   >> 0x19U))))
                                                            ? 0x15U
                                                            : 
                                                           (((6U 
                                                              == 
                                                              (7U 
                                                               & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                  >> 0xcU))) 
                                                             & (1U 
                                                                == 
                                                                (0x7fU 
                                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                    >> 0x19U))))
                                                             ? 0x16U
                                                             : 
                                                            (((7U 
                                                               == 
                                                               (7U 
                                                                & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                   >> 0xcU))) 
                                                              & (1U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                                     >> 0x19U))))
                                                              ? 0x17U
                                                              : 0U))))))))))))))))
                   : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)
                       ? (((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                         >> 0xcU))) 
                           & (0U == (0x7fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                              >> 0x19U))))
                           ? 0U : (((1U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                  >> 0xcU))) 
                                    & (0U == (0x7fU 
                                              & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                 >> 0x19U))))
                                    ? 2U : (((2U == 
                                              (7U & 
                                               (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0xcU))) 
                                             & (0U 
                                                == 
                                                (0x7fU 
                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                    >> 0x19U))))
                                             ? 3U : 
                                            (((3U == 
                                               (7U 
                                                & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                   >> 0xcU))) 
                                              & (0U 
                                                 == 
                                                 (0x7fU 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0x19U))))
                                              ? 4U : 
                                             (((4U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                    >> 0xcU))) 
                                               & (0U 
                                                  == 
                                                  (0x7fU 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0x19U))))
                                               ? 5U
                                               : ((
                                                   (5U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                        >> 0xcU))) 
                                                   & (0U 
                                                      == 
                                                      (0x7fU 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x19U))))
                                                   ? 6U
                                                   : 
                                                  (((6U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                         >> 0xcU))) 
                                                    & (0U 
                                                       == 
                                                       (0x7fU 
                                                        & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                           >> 0x19U))))
                                                    ? 8U
                                                    : 
                                                   (((7U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0xcU))) 
                                                     & (0U 
                                                        == 
                                                        (0x7fU 
                                                         & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                            >> 0x19U))))
                                                     ? 9U
                                                     : 0U))))))))
                       : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)
                           ? ((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                            >> 0xcU)))
                               ? 0U : ((1U == (7U & 
                                               (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0xcU)))
                                        ? 0U : ((2U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0xcU)))
                                                 ? 0U
                                                 : 0U)))
                           : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)
                               ? ((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0xcU)))
                                   ? 0U : ((1U == (7U 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0xcU)))
                                            ? 0U : 
                                           ((2U == 
                                             (7U & 
                                              (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                               >> 0xcU)))
                                             ? 0U : 
                                            ((4U == 
                                              (7U & 
                                               (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0xcU)))
                                              ? 0U : 
                                             ((5U == 
                                               (7U 
                                                & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                   >> 0xcU)))
                                               ? 0U
                                               : ((6U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                       >> 0xcU)))
                                                   ? 0U
                                                   : 0U))))))
                               : (((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                   | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                   ? 0U : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)
                                            ? 0xfU : 0U)))))));
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel 
        = ((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
             | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr))
            ? 0U : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)
                     ? 1U : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)
                              ? 2U : ((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)
                                       ? 3U : (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui) 
                                                | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                                ? 4U
                                                : 0U)))));
    vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out 
        = ((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
            ? ((0xfffff000U & ((- (IData)((1U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                 >> 0x1fU)))) 
                               << 0xcU)) | (0xfffU 
                                            & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                               >> 0x14U)))
            : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
                ? ((0xffffe000U & ((- (IData)((1U & 
                                               (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0x1fU)))) 
                                   << 0xdU)) | ((0x1000U 
                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                    >> 0x13U)) 
                                                | ((0x800U 
                                                    & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                            >> 7U))))))
                : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                    >> 7U))))
                    : ((3U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
                        ? ((0xffe00000U & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x1fU)))) 
                                           << 0x15U)) 
                           | ((0x100000U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                            >> 0xbU)) 
                              | ((0xff000U & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc) 
                                 | ((0x800U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                               >> 9U)) 
                                    | (0x7feU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                 >> 0x14U))))))
                        : ((4U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel))
                            ? (0xfffff000U & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)
                            : 0U)))));
    vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out = 
        ((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                 | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
               | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
              | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
             | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
           ? 1U : 0U) ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out
          : vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b);
    vlTOPp->core__DOT__u_Core10__DOT__alu_res_out = 
        ((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
          ? (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
             + vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
          : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
              ? (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                 - vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
              : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                  ? ((0x1fU >= vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                      ? (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                         << vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                      : 0U) : (((3U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control)) 
                                & VL_LTS_III(1,32,32, vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out, vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out))
                                ? 1U : (((4U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control)) 
                                         & (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                                            < vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out))
                                         ? 1U : ((5U 
                                                  == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                  ? 
                                                 (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                                                  ^ vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                   ? 
                                                  ((0x1fU 
                                                    >= vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                    ? 
                                                   (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                                                    >> vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                    : 0U)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                     ? 
                                                    (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                                                     >> vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                     : 0U)
                                                    : 
                                                   ((8U 
                                                     == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                     ? 
                                                    (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                                                     | vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                      ? 
                                                     (vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out 
                                                      & vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                      : 
                                                     ((0xfU 
                                                       == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                       ? vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out
                                                       : 
                                                      ((0x14U 
                                                        == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                        ? 
                                                       VL_DIV_III(32, vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out, vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                        : 
                                                       ((0x15U 
                                                         == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                         ? 
                                                        VL_DIV_III(32, vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out, vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                         : 
                                                        ((0x16U 
                                                          == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                          ? 
                                                         VL_MODDIV_III(32, vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out, vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                          : 
                                                         ((0x17U 
                                                           == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))
                                                           ? 
                                                          VL_MODDIV_III(32, vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out, vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)
                                                           : 0U)))))))))))))));
    if ((0x10U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))) {
        vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
            = ((QData)((IData)(vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out)) 
               * (QData)((IData)(vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)));
        vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
            = (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res);
    } else {
        if ((0x11U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))) {
            vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
                = VL_MULS_QQQ(64,64,64, VL_EXTENDS_QI(64,32, vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out), 
                              VL_EXTENDS_QI(64,32, vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out));
            vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                = (IData)((vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
                           >> 0x20U));
        } else {
            if ((0x12U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))) {
                vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
                    = ((QData)((IData)(vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out)) 
                       * (QData)((IData)(vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)));
                vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                    = (IData)((vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
                               >> 0x20U));
            } else {
                if ((0x13U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__alu_control))) {
                    vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
                        = ((QData)((IData)(vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out)) 
                           * (QData)((IData)(vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out)));
                    vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                        = (IData)((vlTOPp->core__DOT__u_Core10__DOT__u_Execute_stage0__DOT__u_alu0__DOT__mult_res 
                                   >> 0x20U));
                }
            }
        }
    }
    if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store) {
        vlTOPp->core__DOT__data_mem_mask = 0U;
        if ((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__data_mem_mask = 1U;
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__data_mem_mask = 2U;
                }
            }
        }
        if ((1U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                          >> 0xcU)))) {
            if ((0U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                vlTOPp->core__DOT__data_mem_mask = 3U;
            } else {
                if ((1U == (3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out))) {
                    vlTOPp->core__DOT__data_mem_mask = 6U;
                }
            }
        }
        if ((2U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__data_mem_mask = 0xfU;
        }
    }
    if (vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store) {
        if ((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
        if ((1U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
        if ((2U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__DM_store_data_out = vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out;
        }
    }
    if (((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load) 
         | (IData)(vlTOPp->core__DOT__data_mem_valid))) {
        if ((0U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
        if ((1U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
        if ((2U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                          >> 0xcU)))) {
            vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out 
                = vlTOPp->core__DOT__DM_load_data_in;
        }
        if ((4U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
        if ((5U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
        if ((6U == (7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
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
