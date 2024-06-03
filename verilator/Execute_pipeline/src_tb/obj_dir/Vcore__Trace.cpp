// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcore__Syms.h"


void Vcore::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vcore::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->core__DOT__DM_load_data_in),32);
            tracep->chgBit(oldp+1,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__store));
            tracep->chgIData(oldp+2,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__pre_address),32);
            tracep->chgIData(oldp+3,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__opb_data),32);
            tracep->chgIData(oldp+4,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__opb_mux),32);
            tracep->chgIData(oldp+5,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__opa_mux),32);
            tracep->chgCData(oldp+6,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__alu_con),4);
            tracep->chgBit(oldp+7,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__me));
            tracep->chgBit(oldp+8,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__men));
            tracep->chgBit(oldp+9,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__s));
            tracep->chgCData(oldp+10,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__r1),5);
            tracep->chgCData(oldp+11,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__r2),5);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+12,(vlTOPp->core__DOT__valid));
            tracep->chgIData(oldp+13,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0]),32);
            tracep->chgIData(oldp+14,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[1]),32);
            tracep->chgIData(oldp+15,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[2]),32);
            tracep->chgIData(oldp+16,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[3]),32);
            tracep->chgIData(oldp+17,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[4]),32);
            tracep->chgIData(oldp+18,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[5]),32);
            tracep->chgIData(oldp+19,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[6]),32);
            tracep->chgIData(oldp+20,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[7]),32);
            tracep->chgIData(oldp+21,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[8]),32);
            tracep->chgIData(oldp+22,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[9]),32);
            tracep->chgIData(oldp+23,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[10]),32);
            tracep->chgIData(oldp+24,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[11]),32);
            tracep->chgIData(oldp+25,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[12]),32);
            tracep->chgIData(oldp+26,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[13]),32);
            tracep->chgIData(oldp+27,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[14]),32);
            tracep->chgIData(oldp+28,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[15]),32);
            tracep->chgIData(oldp+29,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[16]),32);
            tracep->chgIData(oldp+30,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[17]),32);
            tracep->chgIData(oldp+31,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[18]),32);
            tracep->chgIData(oldp+32,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[19]),32);
            tracep->chgIData(oldp+33,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[20]),32);
            tracep->chgIData(oldp+34,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[21]),32);
            tracep->chgIData(oldp+35,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[22]),32);
            tracep->chgIData(oldp+36,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[23]),32);
            tracep->chgIData(oldp+37,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[24]),32);
            tracep->chgIData(oldp+38,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[25]),32);
            tracep->chgIData(oldp+39,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[26]),32);
            tracep->chgIData(oldp+40,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[27]),32);
            tracep->chgIData(oldp+41,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[28]),32);
            tracep->chgIData(oldp+42,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[29]),32);
            tracep->chgIData(oldp+43,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[30]),32);
            tracep->chgIData(oldp+44,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgIData(oldp+45,(vlTOPp->core__DOT__instruction_o),32);
            tracep->chgIData(oldp+46,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result),32);
            tracep->chgIData(oldp+47,(vlTOPp->core__DOT__DM_store_data_out),32);
            tracep->chgCData(oldp+48,(vlTOPp->core__DOT__data_mem_mask),4);
            tracep->chgIData(oldp+49,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction),32);
            tracep->chgIData(oldp+50,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__nextsel_addr),32);
            tracep->chgIData(oldp+51,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__pre_address),32);
            tracep->chgIData(oldp+52,(((IData)(4U) 
                                       + vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__pre_address)),32);
            tracep->chgIData(oldp+53,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__instruct),32);
            tracep->chgIData(oldp+54,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc),32);
            tracep->chgIData(oldp+55,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address),32);
            tracep->chgBit(oldp+56,(((0U == vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction)
                                      ? 1U : 0U)));
            tracep->chgBit(oldp+57,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__reg_write));
            tracep->chgBit(oldp+58,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__rg));
            tracep->chgBit(oldp+59,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__branch_));
            tracep->chgBit(oldp+60,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__nextsel));
            tracep->chgBit(oldp+61,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__jalr));
            tracep->chgBit(oldp+62,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__branch_res));
            tracep->chgCData(oldp+63,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg),2);
            tracep->chgCData(oldp+64,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__mem_reg),2);
            tracep->chgCData(oldp+65,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+66,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+67,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction 
                                                >> 7U))),5);
            tracep->chgBit(oldp+68,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline));
            tracep->chgBit(oldp+69,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline2));
            tracep->chgIData(oldp+70,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | (0xfffU & 
                                          (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                           >> 0x14U)))),32);
            tracep->chgIData(oldp+71,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                >> 7U))))),32);
            tracep->chgIData(oldp+72,(((0xffffe000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x1fU)))) 
                                           << 0xdU)) 
                                       | ((0x1000U 
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
                                                      >> 7U))))))),32);
            tracep->chgIData(oldp+73,(((0xffe00000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                          >> 0x1fU)))) 
                                           << 0x15U)) 
                                       | ((0x100000U 
                                           & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                              >> 0xbU)) 
                                          | ((0xff000U 
                                              & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc) 
                                             | ((0x800U 
                                                 & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0x14U))))))),32);
            tracep->chgIData(oldp+74,((0xfffff000U 
                                       & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)),32);
            tracep->chgBit(oldp+75,((1U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                           >> 0x1eU))));
            tracep->chgCData(oldp+76,((7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+77,((0x7fU & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)),7);
            tracep->chgCData(oldp+78,((7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+79,((3U & vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result)),2);
            tracep->chgCData(oldp+80,((0xffU & (vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result 
                                                >> 2U))),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgIData(oldp+81,(vlTOPp->core__DOT__pc_address),32);
            tracep->chgBit(oldp+82,(vlTOPp->core__DOT__data_mem_valid));
            tracep->chgCData(oldp+83,((0xffU & (vlTOPp->core__DOT__pc_address 
                                                >> 2U))),8);
            tracep->chgIData(oldp+84,(vlTOPp->core__DOT__u_Core10__DOT__pre_pc),32);
            tracep->chgIData(oldp+85,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a),32);
            tracep->chgIData(oldp+86,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgBit(oldp+87,(vlTOPp->core__DOT__data_mem_request));
            tracep->chgBit(oldp+88,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__load));
            tracep->chgIData(oldp+89,(vlTOPp->core__DOT__u_Core10__DOT__alu_in_b),32);
            tracep->chgIData(oldp+90,(vlTOPp->core__DOT__u_Core10__DOT__alu_in_a),32);
            tracep->chgIData(oldp+91,(vlTOPp->core__DOT__u_Core10__DOT__alu_res_out),32);
            tracep->chgBit(oldp+92,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__l));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgBit(oldp+93,(vlTOPp->core__DOT__instruction_mem_request));
            tracep->chgIData(oldp+94,(vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out),32);
            tracep->chgCData(oldp+95,(vlTOPp->core__DOT__u_Core10__DOT__alu_control),4);
            tracep->chgBit(oldp+96,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr));
            tracep->chgBit(oldp+97,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal));
            tracep->chgBit(oldp+98,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load));
            tracep->chgBit(oldp+99,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store));
            tracep->chgBit(oldp+100,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch));
            tracep->chgBit(oldp+101,(vlTOPp->core__DOT__u_Core10__DOT__branch_result));
            tracep->chgCData(oldp+102,(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg),2);
            tracep->chgBit(oldp+103,(((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                       ? 1U : 0U)));
            tracep->chgBit(oldp+104,((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                                             | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
                                           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
                                          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                       ? 1U : 0U)));
            tracep->chgCData(oldp+105,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel),3);
            tracep->chgIData(oldp+106,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out),32);
            tracep->chgBit(oldp+107,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type));
            tracep->chgBit(oldp+108,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type));
            tracep->chgBit(oldp+109,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui));
            tracep->chgBit(oldp+110,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc));
        }
        tracep->chgBit(oldp+111,(vlTOPp->clk));
        tracep->chgBit(oldp+112,(vlTOPp->rst));
        tracep->chgIData(oldp+113,(vlTOPp->instruction),32);
        tracep->chgIData(oldp+114,(((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                                            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
                                          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                      ? 1U : 0U) ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out
                                     : vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)),32);
        tracep->chgIData(oldp+115,((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                      ? 1U : 0U) ? vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address
                                     : vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a)),32);
        tracep->chgIData(oldp+116,(((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg))
                                     ? vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result
                                     : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg))
                                         ? vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out
                                         : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg))
                                             ? vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__nextsel_addr
                                             : 0U)))),32);
        tracep->chgBit(oldp+117,((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                       | (IData)(vlTOPp->core__DOT__data_mem_valid)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                   | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                   ? 1U : 0U)));
    }
}

void Vcore::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
        vlTOPp->__Vm_traceActivity[6U] = 0U;
    }
}
