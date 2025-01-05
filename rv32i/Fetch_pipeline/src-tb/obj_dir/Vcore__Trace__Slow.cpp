// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcore__Syms.h"


//======================

void Vcore::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcore::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcore::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcore::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcore::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+83,"clk", false,-1);
        tracep->declBit(c+84,"rst", false,-1);
        tracep->declBus(c+85,"instruction", false,-1, 31,0);
        tracep->declBus(c+88,"core INSTRUCTION", false,-1, 31,0);
        tracep->declBit(c+83,"core clk", false,-1);
        tracep->declBit(c+84,"core rst", false,-1);
        tracep->declBus(c+85,"core instruction", false,-1, 31,0);
        tracep->declBus(c+52,"core pc_address", false,-1, 31,0);
        tracep->declBus(c+35,"core instruction_o", false,-1, 31,0);
        tracep->declBus(c+53,"core DM_alu_res_out", false,-1, 31,0);
        tracep->declBus(c+36,"core DM_load_data_in", false,-1, 31,0);
        tracep->declBus(c+54,"core DM_store_data_out", false,-1, 31,0);
        tracep->declBit(c+89,"core instruction_mem_we_re", false,-1);
        tracep->declBit(c+55,"core instruction_mem_request", false,-1);
        tracep->declBit(c+1,"core valid", false,-1);
        tracep->declBit(c+2,"core data_mem_valid", false,-1);
        tracep->declBit(c+56,"core data_mem_request", false,-1);
        tracep->declBit(c+57,"core data_mem_we_re", false,-1);
        tracep->declBit(c+58,"core DM_Load", false,-1);
        tracep->declBus(c+90,"core instruction_mem_mask", false,-1, 3,0);
        tracep->declBus(c+59,"core data_mem_mask", false,-1, 3,0);
        tracep->declBus(c+91,"core u_instruc_mem_top0 INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+83,"core u_instruc_mem_top0 clk", false,-1);
        tracep->declBit(c+84,"core u_instruc_mem_top0 rst", false,-1);
        tracep->declBit(c+89,"core u_instruc_mem_top0 we_re", false,-1);
        tracep->declBit(c+55,"core u_instruc_mem_top0 request", false,-1);
        tracep->declBus(c+90,"core u_instruc_mem_top0 mask", false,-1, 3,0);
        tracep->declBus(c+60,"core u_instruc_mem_top0 address", false,-1, 7,0);
        tracep->declBus(c+85,"core u_instruc_mem_top0 data_in", false,-1, 31,0);
        tracep->declBit(c+1,"core u_instruc_mem_top0 valid", false,-1);
        tracep->declBus(c+35,"core u_instruc_mem_top0 data_out", false,-1, 31,0);
        tracep->declBus(c+91,"core u_instruc_mem_top0 u_memory INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+83,"core u_instruc_mem_top0 u_memory clk", false,-1);
        tracep->declBit(c+89,"core u_instruc_mem_top0 u_memory we_re", false,-1);
        tracep->declBit(c+55,"core u_instruc_mem_top0 u_memory request", false,-1);
        tracep->declBus(c+60,"core u_instruc_mem_top0 u_memory address", false,-1, 7,0);
        tracep->declBus(c+85,"core u_instruc_mem_top0 u_memory data_in", false,-1, 31,0);
        tracep->declBus(c+90,"core u_instruc_mem_top0 u_memory mask", false,-1, 3,0);
        tracep->declBus(c+35,"core u_instruc_mem_top0 u_memory data_out", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 ADDRESS", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+92,"core u_Core10 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 clk", false,-1);
        tracep->declBit(c+84,"core u_Core10 rst", false,-1);
        tracep->declBus(c+35,"core u_Core10 instruction", false,-1, 31,0);
        tracep->declBus(c+36,"core u_Core10 DM_load_data_in", false,-1, 31,0);
        tracep->declBit(c+2,"core u_Core10 DM_valid", false,-1);
        tracep->declBus(c+52,"core u_Core10 address_out", false,-1, 31,0);
        tracep->declBit(c+58,"core u_Core10 DM_Load", false,-1);
        tracep->declBit(c+55,"core u_Core10 instruction_mem_request", false,-1);
        tracep->declBit(c+89,"core u_Core10 instruction_mem_we_re", false,-1);
        tracep->declBus(c+90,"core u_Core10 instruction_mem_mask", false,-1, 3,0);
        tracep->declBit(c+56,"core u_Core10 data_mem_request", false,-1);
        tracep->declBit(c+57,"core u_Core10 data_mem_we_re", false,-1);
        tracep->declBus(c+59,"core u_Core10 data_mem_mask", false,-1, 3,0);
        tracep->declBus(c+54,"core u_Core10 DM_store_data_out", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 DM_alu_res_out", false,-1, 31,0);
        tracep->declBus(c+37,"core u_Core10 next_sel_address", false,-1, 31,0);
        tracep->declBus(c+61,"core u_Core10 opb_mux_out", false,-1, 31,0);
        tracep->declBus(c+62,"core u_Core10 opa_mux_out", false,-1, 31,0);
        tracep->declBus(c+86,"core u_Core10 rd_wb_data", false,-1, 31,0);
        tracep->declBus(c+38,"core u_Core10 instruction_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+39,"core u_Core10 pre_pc_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+63,"core u_Core10 pre_pc", false,-1, 31,0);
        tracep->declBus(c+35,"core u_Core10 instruction_out", false,-1, 31,0);
        tracep->declBus(c+64,"core u_Core10 wrap_load_out", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 alu_res_out", false,-1, 31,0);
        tracep->declBus(c+65,"core u_Core10 alu_control", false,-1, 3,0);
        tracep->declBit(c+66,"core u_Core10 Jalr", false,-1);
        tracep->declBit(c+67,"core u_Core10 next_sel", false,-1);
        tracep->declBit(c+58,"core u_Core10 Load", false,-1);
        tracep->declBit(c+57,"core u_Core10 Store", false,-1);
        tracep->declBit(c+57,"core u_Core10 mem_en", false,-1);
        tracep->declBit(c+68,"core u_Core10 Branch", false,-1);
        tracep->declBit(c+69,"core u_Core10 branch_result", false,-1);
        tracep->declBus(c+70,"core u_Core10 mem_to_reg", false,-1, 1,0);
        tracep->declBus(c+88,"core u_Core10 u_Fetch_stage0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Fetch_stage0 ADDRESS", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 u_Fetch_stage0 clk", false,-1);
        tracep->declBit(c+84,"core u_Core10 u_Fetch_stage0 rst", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Fetch_stage0 load", false,-1);
        tracep->declBit(c+2,"core u_Core10 u_Fetch_stage0 DM_valid", false,-1);
        tracep->declBus(c+93,"core u_Core10 u_Fetch_stage0 address_in", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 u_Fetch_stage0 next_address", false,-1, 31,0);
        tracep->declBus(c+35,"core u_Core10 u_Fetch_stage0 instruction_fetch", false,-1, 31,0);
        tracep->declBit(c+68,"core u_Core10 u_Fetch_stage0 branch", false,-1);
        tracep->declBit(c+67,"core u_Core10 u_Fetch_stage0 next_sel", false,-1);
        tracep->declBit(c+66,"core u_Core10 u_Fetch_stage0 Jalr", false,-1);
        tracep->declBit(c+69,"core u_Core10 u_Fetch_stage0 branch_result", false,-1);
        tracep->declBit(c+55,"core u_Core10 u_Fetch_stage0 request", false,-1);
        tracep->declBit(c+89,"core u_Core10 u_Fetch_stage0 we_re", false,-1);
        tracep->declBus(c+90,"core u_Core10 u_Fetch_stage0 mask", false,-1, 3,0);
        tracep->declBus(c+35,"core u_Core10 u_Fetch_stage0 instruction", false,-1, 31,0);
        tracep->declBus(c+63,"core u_Core10 u_Fetch_stage0 pre_pc", false,-1, 31,0);
        tracep->declBus(c+52,"core u_Core10 u_Fetch_stage0 pc_addr_out", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Fetch_stage0 u_pc0 ADDRESS", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 u_Fetch_stage0 u_pc0 clk", false,-1);
        tracep->declBit(c+84,"core u_Core10 u_Fetch_stage0 u_pc0 rst", false,-1);
        tracep->declBus(c+93,"core u_Core10 u_Fetch_stage0 u_pc0 address_in", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 u_Fetch_stage0 u_pc0 next_address", false,-1, 31,0);
        tracep->declBit(c+58,"core u_Core10 u_Fetch_stage0 u_pc0 load", false,-1);
        tracep->declBit(c+2,"core u_Core10 u_Fetch_stage0 u_pc0 DM_valid", false,-1);
        tracep->declBit(c+68,"core u_Core10 u_Fetch_stage0 u_pc0 branch", false,-1);
        tracep->declBit(c+67,"core u_Core10 u_Fetch_stage0 u_pc0 next_sel", false,-1);
        tracep->declBit(c+66,"core u_Core10 u_Fetch_stage0 u_pc0 Jalr", false,-1);
        tracep->declBit(c+69,"core u_Core10 u_Fetch_stage0 u_pc0 branch_result", false,-1);
        tracep->declBus(c+52,"core u_Core10 u_Fetch_stage0 u_pc0 address_out", false,-1, 31,0);
        tracep->declBus(c+63,"core u_Core10 u_Fetch_stage0 u_pc0 pre_pc", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Fetch_pipe0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Fetch_pipe0 ADDRESS", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 u_Fetch_pipe0 clk", false,-1);
        tracep->declBus(c+63,"core u_Core10 u_Fetch_pipe0 pre_address_fetch", false,-1, 31,0);
        tracep->declBus(c+35,"core u_Core10 u_Fetch_pipe0 instruction_fetch", false,-1, 31,0);
        tracep->declBit(c+67,"core u_Core10 u_Fetch_pipe0 next_select", false,-1);
        tracep->declBit(c+69,"core u_Core10 u_Fetch_pipe0 branch_result", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Fetch_pipe0 load", false,-1);
        tracep->declBit(c+66,"core u_Core10 u_Fetch_pipe0 Jalr", false,-1);
        tracep->declBus(c+39,"core u_Core10 u_Fetch_pipe0 pre_pc_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+38,"core u_Core10 u_Fetch_pipe0 instruction_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+39,"core u_Core10 u_Fetch_pipe0 pre_address", false,-1, 31,0);
        tracep->declBus(c+38,"core u_Core10 u_Fetch_pipe0 instruc", false,-1, 31,0);
        tracep->declBit(c+40,"core u_Core10 u_Fetch_pipe0 flush_pipeline", false,-1);
        tracep->declBus(c+88,"core u_Core10 u_Decode_stage0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Decode_stage0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+92,"core u_Core10 u_Decode_stage0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 u_Decode_stage0 clk", false,-1);
        tracep->declBit(c+84,"core u_Core10 u_Decode_stage0 rst", false,-1);
        tracep->declBit(c+2,"core u_Core10 u_Decode_stage0 DM_valid", false,-1);
        tracep->declBus(c+38,"core u_Core10 u_Decode_stage0 instruction", false,-1, 31,0);
        tracep->declBus(c+86,"core u_Core10 u_Decode_stage0 rwd_data_out", false,-1, 31,0);
        tracep->declBus(c+39,"core u_Core10 u_Decode_stage0 pc", false,-1, 31,0);
        tracep->declBus(c+65,"core u_Core10 u_Decode_stage0 alu_control", false,-1, 3,0);
        tracep->declBus(c+61,"core u_Core10 u_Decode_stage0 opb_mux_out", false,-1, 31,0);
        tracep->declBus(c+62,"core u_Core10 u_Decode_stage0 opa_mux_out", false,-1, 31,0);
        tracep->declBit(c+58,"core u_Core10 u_Decode_stage0 Load", false,-1);
        tracep->declBit(c+57,"core u_Core10 u_Decode_stage0 Store", false,-1);
        tracep->declBit(c+68,"core u_Core10 u_Decode_stage0 Branch", false,-1);
        tracep->declBit(c+67,"core u_Core10 u_Decode_stage0 next_sel", false,-1);
        tracep->declBit(c+66,"core u_Core10 u_Decode_stage0 Jalr", false,-1);
        tracep->declBit(c+69,"core u_Core10 u_Decode_stage0 branch_result", false,-1);
        tracep->declBus(c+70,"core u_Core10 u_Decode_stage0 mem_to_reg", false,-1, 1,0);
        tracep->declBit(c+57,"core u_Core10 u_Decode_stage0 mem_en", false,-1);
        tracep->declBus(c+41,"core u_Core10 u_Decode_stage0 i_imme", false,-1, 31,0);
        tracep->declBus(c+42,"core u_Core10 u_Decode_stage0 s_imme", false,-1, 31,0);
        tracep->declBus(c+43,"core u_Core10 u_Decode_stage0 sb_imme", false,-1, 31,0);
        tracep->declBus(c+44,"core u_Core10 u_Decode_stage0 uj_imme", false,-1, 31,0);
        tracep->declBus(c+45,"core u_Core10 u_Decode_stage0 u_imme", false,-1, 31,0);
        tracep->declBit(c+71,"core u_Core10 u_Decode_stage0 operand_a", false,-1);
        tracep->declBit(c+87,"core u_Core10 u_Decode_stage0 reg_write", false,-1);
        tracep->declBit(c+72,"core u_Core10 u_Decode_stage0 operand_b", false,-1);
        tracep->declBit(c+68,"core u_Core10 u_Decode_stage0 branch", false,-1);
        tracep->declBus(c+73,"core u_Core10 u_Decode_stage0 op_a", false,-1, 31,0);
        tracep->declBus(c+74,"core u_Core10 u_Decode_stage0 op_b", false,-1, 31,0);
        tracep->declBus(c+75,"core u_Core10 u_Decode_stage0 imm_sel", false,-1, 2,0);
        tracep->declBus(c+76,"core u_Core10 u_Decode_stage0 imm_mux_out", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Decode_stage0 u_immediate_gene0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+38,"core u_Core10 u_Decode_stage0 u_immediate_gene0 instruction", false,-1, 31,0);
        tracep->declBus(c+41,"core u_Core10 u_Decode_stage0 u_immediate_gene0 i_imme", false,-1, 31,0);
        tracep->declBus(c+42,"core u_Core10 u_Decode_stage0 u_immediate_gene0 s_imme", false,-1, 31,0);
        tracep->declBus(c+43,"core u_Core10 u_Decode_stage0 u_immediate_gene0 sb_imme", false,-1, 31,0);
        tracep->declBus(c+44,"core u_Core10 u_Decode_stage0 u_immediate_gene0 uj_imme", false,-1, 31,0);
        tracep->declBus(c+45,"core u_Core10 u_Decode_stage0 u_immediate_gene0 u_imme", false,-1, 31,0);
        tracep->declBus(c+94,"core u_Core10 u_Decode_stage0 u_cu0 FUNCTION3", false,-1, 31,0);
        tracep->declBus(c+95,"core u_Core10 u_Decode_stage0 u_cu0 OPCODE", false,-1, 31,0);
        tracep->declBus(c+92,"core u_Core10 u_Decode_stage0 u_cu0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+46,"core u_Core10 u_Decode_stage0 u_cu0 fun7", false,-1);
        tracep->declBit(c+2,"core u_Core10 u_Decode_stage0 u_cu0 DM_valid", false,-1);
        tracep->declBus(c+47,"core u_Core10 u_Decode_stage0 u_cu0 fun3", false,-1, 2,0);
        tracep->declBus(c+48,"core u_Core10 u_Decode_stage0 u_cu0 opcode_i", false,-1, 6,0);
        tracep->declBit(c+57,"core u_Core10 u_Decode_stage0 u_cu0 mem_en", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Decode_stage0 u_cu0 Load", false,-1);
        tracep->declBit(c+57,"core u_Core10 u_Decode_stage0 u_cu0 Store", false,-1);
        tracep->declBit(c+68,"core u_Core10 u_Decode_stage0 u_cu0 Branch", false,-1);
        tracep->declBit(c+67,"core u_Core10 u_Decode_stage0 u_cu0 next_sel", false,-1);
        tracep->declBit(c+66,"core u_Core10 u_Decode_stage0 u_cu0 Jalr", false,-1);
        tracep->declBit(c+87,"core u_Core10 u_Decode_stage0 u_cu0 reg_write_o", false,-1);
        tracep->declBit(c+71,"core u_Core10 u_Decode_stage0 u_cu0 operand_a_o", false,-1);
        tracep->declBit(c+72,"core u_Core10 u_Decode_stage0 u_cu0 operand_b_o", false,-1);
        tracep->declBus(c+75,"core u_Core10 u_Decode_stage0 u_cu0 imm_sel", false,-1, 2,0);
        tracep->declBus(c+70,"core u_Core10 u_Decode_stage0 u_cu0 mem_to_reg", false,-1, 1,0);
        tracep->declBus(c+65,"core u_Core10 u_Decode_stage0 u_cu0 alu_control", false,-1, 3,0);
        tracep->declBit(c+77,"core u_Core10 u_Decode_stage0 u_cu0 r_type", false,-1);
        tracep->declBit(c+78,"core u_Core10 u_Decode_stage0 u_cu0 i_type", false,-1);
        tracep->declBit(c+57,"core u_Core10 u_Decode_stage0 u_cu0 store", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Decode_stage0 u_cu0 load", false,-1);
        tracep->declBit(c+68,"core u_Core10 u_Decode_stage0 u_cu0 branch", false,-1);
        tracep->declBit(c+67,"core u_Core10 u_Decode_stage0 u_cu0 jal", false,-1);
        tracep->declBit(c+66,"core u_Core10 u_Decode_stage0 u_cu0 jalr", false,-1);
        tracep->declBit(c+79,"core u_Core10 u_Decode_stage0 u_cu0 lui", false,-1);
        tracep->declBit(c+80,"core u_Core10 u_Decode_stage0 u_cu0 auipc", false,-1);
        tracep->declBus(c+88,"core u_Core10 u_Decode_stage0 u_registerfile0 Data_Width", false,-1, 31,0);
        tracep->declBus(c+96,"core u_Core10 u_Decode_stage0 u_registerfile0 AddrRegWidth", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 u_Decode_stage0 u_registerfile0 clk", false,-1);
        tracep->declBit(c+84,"core u_Core10 u_Decode_stage0 u_registerfile0 rst", false,-1);
        tracep->declBit(c+87,"core u_Core10 u_Decode_stage0 u_registerfile0 en", false,-1);
        tracep->declBus(c+49,"core u_Core10 u_Decode_stage0 u_registerfile0 rs1", false,-1, 4,0);
        tracep->declBus(c+50,"core u_Core10 u_Decode_stage0 u_registerfile0 rs2", false,-1, 4,0);
        tracep->declBus(c+51,"core u_Core10 u_Decode_stage0 u_registerfile0 rd", false,-1, 4,0);
        tracep->declBus(c+86,"core u_Core10 u_Decode_stage0 u_registerfile0 data", false,-1, 31,0);
        tracep->declBus(c+73,"core u_Core10 u_Decode_stage0 u_registerfile0 op_a", false,-1, 31,0);
        tracep->declBus(c+74,"core u_Core10 u_Decode_stage0 u_registerfile0 op_b", false,-1, 31,0);
        {int i; for (i=0; i<31; i++) {
                tracep->declBus(c+3+i*1,"core u_Core10 u_Decode_stage0 u_registerfile0 register", true,(i+1), 31,0);}}
        tracep->declBus(c+34,"core u_Core10 u_Decode_stage0 u_registerfile0 i", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Decode_stage0 u_branch0 DataWidth", false,-1, 31,0);
        tracep->declBit(c+68,"core u_Core10 u_Decode_stage0 u_branch0 en", false,-1);
        tracep->declBus(c+47,"core u_Core10 u_Decode_stage0 u_branch0 fun3", false,-1, 2,0);
        tracep->declBus(c+73,"core u_Core10 u_Decode_stage0 u_branch0 operand_a", false,-1, 31,0);
        tracep->declBus(c+74,"core u_Core10 u_Decode_stage0 u_branch0 operand_b", false,-1, 31,0);
        tracep->declBit(c+69,"core u_Core10 u_Decode_stage0 u_branch0 result", false,-1);
        tracep->declBus(c+88,"core u_Core10 u_Execute_stage0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+92,"core u_Core10 u_Execute_stage0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBus(c+62,"core u_Core10 u_Execute_stage0 a_i", false,-1, 31,0);
        tracep->declBus(c+61,"core u_Core10 u_Execute_stage0 b_i", false,-1, 31,0);
        tracep->declBus(c+39,"core u_Core10 u_Execute_stage0 pc_address", false,-1, 31,0);
        tracep->declBus(c+65,"core u_Core10 u_Execute_stage0 alu_control", false,-1, 3,0);
        tracep->declBus(c+53,"core u_Core10 u_Execute_stage0 alu_res_out", false,-1, 31,0);
        tracep->declBus(c+37,"core u_Core10 u_Execute_stage0 next_sel_address", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Execute_stage0 u_alu0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+62,"core u_Core10 u_Execute_stage0 u_alu0 a_i", false,-1, 31,0);
        tracep->declBus(c+61,"core u_Core10 u_Execute_stage0 u_alu0 b_i", false,-1, 31,0);
        tracep->declBus(c+65,"core u_Core10 u_Execute_stage0 u_alu0 op_i", false,-1, 3,0);
        tracep->declBus(c+53,"core u_Core10 u_Execute_stage0 u_alu0 res_o", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_memorystage0 DataWidth", false,-1, 31,0);
        tracep->declBit(c+58,"core u_Core10 u_memorystage0 load", false,-1);
        tracep->declBit(c+57,"core u_Core10 u_memorystage0 store", false,-1);
        tracep->declBit(c+57,"core u_Core10 u_memorystage0 mem_en", false,-1);
        tracep->declBit(c+2,"core u_Core10 u_memorystage0 data_valid", false,-1);
        tracep->declBus(c+61,"core u_Core10 u_memorystage0 operand_b", false,-1, 31,0);
        tracep->declBus(c+38,"core u_Core10 u_memorystage0 instruction", false,-1, 31,0);
        tracep->declBus(c+36,"core u_Core10 u_memorystage0 wrap_load_in", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 u_memorystage0 alu_out_address", false,-1, 31,0);
        tracep->declBit(c+57,"core u_Core10 u_memorystage0 we_re", false,-1);
        tracep->declBit(c+56,"core u_Core10 u_memorystage0 request", false,-1);
        tracep->declBus(c+59,"core u_Core10 u_memorystage0 mask", false,-1, 3,0);
        tracep->declBus(c+54,"core u_Core10 u_memorystage0 store_data_out", false,-1, 31,0);
        tracep->declBus(c+64,"core u_Core10 u_memorystage0 wrap_load_out", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_memorystage0 u_wrapper_memory0 DataWidth", false,-1, 31,0);
        tracep->declBit(c+58,"core u_Core10 u_memorystage0 u_wrapper_memory0 Load", false,-1);
        tracep->declBit(c+57,"core u_Core10 u_memorystage0 u_wrapper_memory0 mem_en", false,-1);
        tracep->declBit(c+2,"core u_Core10 u_memorystage0 u_wrapper_memory0 data_valid", false,-1);
        tracep->declBus(c+47,"core u_Core10 u_memorystage0 u_wrapper_memory0 fun3", false,-1, 2,0);
        tracep->declBus(c+81,"core u_Core10 u_memorystage0 u_wrapper_memory0 byteadd", false,-1, 1,0);
        tracep->declBus(c+61,"core u_Core10 u_memorystage0 u_wrapper_memory0 data_i", false,-1, 31,0);
        tracep->declBus(c+36,"core u_Core10 u_memorystage0 u_wrapper_memory0 wrap_load_in", false,-1, 31,0);
        tracep->declBus(c+59,"core u_Core10 u_memorystage0 u_wrapper_memory0 masking", false,-1, 3,0);
        tracep->declBus(c+54,"core u_Core10 u_memorystage0 u_wrapper_memory0 data_o", false,-1, 31,0);
        tracep->declBus(c+64,"core u_Core10 u_memorystage0 u_wrapper_memory0 wrap_load_out", false,-1, 31,0);
        tracep->declBus(c+88,"core u_Core10 u_Writeback_stage0 DataWidth", false,-1, 31,0);
        tracep->declBus(c+70,"core u_Core10 u_Writeback_stage0 mem_to_reg", false,-1, 1,0);
        tracep->declBus(c+53,"core u_Core10 u_Writeback_stage0 alu_out", false,-1, 31,0);
        tracep->declBus(c+64,"core u_Core10 u_Writeback_stage0 data_mem_out", false,-1, 31,0);
        tracep->declBus(c+37,"core u_Core10 u_Writeback_stage0 next_sel_address", false,-1, 31,0);
        tracep->declBus(c+86,"core u_Core10 u_Writeback_stage0 rd_mux_out", false,-1, 31,0);
        tracep->declBus(c+93,"core u_data_memory0 INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+83,"core u_data_memory0 clk", false,-1);
        tracep->declBit(c+84,"core u_data_memory0 rst", false,-1);
        tracep->declBit(c+57,"core u_data_memory0 we_re", false,-1);
        tracep->declBit(c+56,"core u_data_memory0 request", false,-1);
        tracep->declBit(c+58,"core u_data_memory0 load", false,-1);
        tracep->declBus(c+59,"core u_data_memory0 mask", false,-1, 3,0);
        tracep->declBus(c+82,"core u_data_memory0 address", false,-1, 7,0);
        tracep->declBus(c+54,"core u_data_memory0 data_in", false,-1, 31,0);
        tracep->declBit(c+2,"core u_data_memory0 valid", false,-1);
        tracep->declBus(c+36,"core u_data_memory0 data_out", false,-1, 31,0);
        tracep->declBus(c+93,"core u_data_memory0 u_memory INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+83,"core u_data_memory0 u_memory clk", false,-1);
        tracep->declBit(c+57,"core u_data_memory0 u_memory we_re", false,-1);
        tracep->declBit(c+56,"core u_data_memory0 u_memory request", false,-1);
        tracep->declBus(c+82,"core u_data_memory0 u_memory address", false,-1, 7,0);
        tracep->declBus(c+54,"core u_data_memory0 u_memory data_in", false,-1, 31,0);
        tracep->declBus(c+59,"core u_data_memory0 u_memory mask", false,-1, 3,0);
        tracep->declBus(c+36,"core u_data_memory0 u_memory data_out", false,-1, 31,0);
    }
}

void Vcore::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcore::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcore::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcore__Syms* __restrict vlSymsp = static_cast<Vcore__Syms*>(userp);
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->core__DOT__valid));
        tracep->fullBit(oldp+2,(vlTOPp->core__DOT__data_mem_valid));
        tracep->fullIData(oldp+3,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0]),32);
        tracep->fullIData(oldp+4,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[1]),32);
        tracep->fullIData(oldp+5,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[2]),32);
        tracep->fullIData(oldp+6,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[3]),32);
        tracep->fullIData(oldp+7,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[4]),32);
        tracep->fullIData(oldp+8,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[5]),32);
        tracep->fullIData(oldp+9,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[6]),32);
        tracep->fullIData(oldp+10,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[7]),32);
        tracep->fullIData(oldp+11,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[8]),32);
        tracep->fullIData(oldp+12,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[9]),32);
        tracep->fullIData(oldp+13,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[10]),32);
        tracep->fullIData(oldp+14,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[11]),32);
        tracep->fullIData(oldp+15,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[12]),32);
        tracep->fullIData(oldp+16,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[13]),32);
        tracep->fullIData(oldp+17,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[14]),32);
        tracep->fullIData(oldp+18,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[15]),32);
        tracep->fullIData(oldp+19,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[16]),32);
        tracep->fullIData(oldp+20,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[17]),32);
        tracep->fullIData(oldp+21,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[18]),32);
        tracep->fullIData(oldp+22,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[19]),32);
        tracep->fullIData(oldp+23,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[20]),32);
        tracep->fullIData(oldp+24,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[21]),32);
        tracep->fullIData(oldp+25,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[22]),32);
        tracep->fullIData(oldp+26,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[23]),32);
        tracep->fullIData(oldp+27,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[24]),32);
        tracep->fullIData(oldp+28,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[25]),32);
        tracep->fullIData(oldp+29,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[26]),32);
        tracep->fullIData(oldp+30,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[27]),32);
        tracep->fullIData(oldp+31,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[28]),32);
        tracep->fullIData(oldp+32,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[29]),32);
        tracep->fullIData(oldp+33,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[30]),32);
        tracep->fullIData(oldp+34,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__i),32);
        tracep->fullIData(oldp+35,(vlTOPp->core__DOT__instruction_o),32);
        tracep->fullIData(oldp+36,(vlTOPp->core__DOT__DM_load_data_in),32);
        tracep->fullIData(oldp+37,(((IData)(4U) + vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address)),32);
        tracep->fullIData(oldp+38,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc),32);
        tracep->fullIData(oldp+39,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address),32);
        tracep->fullBit(oldp+40,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline));
        tracep->fullIData(oldp+41,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (0xfffU 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0x14U)))),32);
        tracep->fullIData(oldp+42,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                         >> 7U))))),32);
        tracep->fullIData(oldp+43,(((0xffffe000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0x1fU)))) 
                                      << 0xdU)) | (
                                                   (0x1000U 
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
        tracep->fullIData(oldp+44,(((0xffe00000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0x1fU)))) 
                                      << 0x15U)) | 
                                    ((0x100000U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                   >> 0xbU)) 
                                     | ((0xff000U & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc) 
                                        | ((0x800U 
                                            & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                 >> 0x14U))))))),32);
        tracep->fullIData(oldp+45,((0xfffff000U & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)),32);
        tracep->fullBit(oldp+46,((1U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                        >> 0x1eU))));
        tracep->fullCData(oldp+47,((7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+48,((0x7fU & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)),7);
        tracep->fullCData(oldp+49,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+50,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+51,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                             >> 7U))),5);
        tracep->fullIData(oldp+52,(vlTOPp->core__DOT__pc_address),32);
        tracep->fullIData(oldp+53,(vlTOPp->core__DOT__u_Core10__DOT__alu_res_out),32);
        tracep->fullIData(oldp+54,(vlTOPp->core__DOT__DM_store_data_out),32);
        tracep->fullBit(oldp+55,(vlTOPp->core__DOT__instruction_mem_request));
        tracep->fullBit(oldp+56,(vlTOPp->core__DOT__data_mem_request));
        tracep->fullBit(oldp+57,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store));
        tracep->fullBit(oldp+58,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load));
        tracep->fullCData(oldp+59,(vlTOPp->core__DOT__data_mem_mask),4);
        tracep->fullCData(oldp+60,((0xffU & (vlTOPp->core__DOT__pc_address 
                                             >> 2U))),8);
        tracep->fullIData(oldp+61,(vlTOPp->core__DOT__u_Core10__DOT__opb_mux_out),32);
        tracep->fullIData(oldp+62,(vlTOPp->core__DOT__u_Core10__DOT__opa_mux_out),32);
        tracep->fullIData(oldp+63,(vlTOPp->core__DOT__u_Core10__DOT__pre_pc),32);
        tracep->fullIData(oldp+64,(vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out),32);
        tracep->fullCData(oldp+65,(vlTOPp->core__DOT__u_Core10__DOT__alu_control),4);
        tracep->fullBit(oldp+66,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr));
        tracep->fullBit(oldp+67,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal));
        tracep->fullBit(oldp+68,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch));
        tracep->fullBit(oldp+69,(vlTOPp->core__DOT__u_Core10__DOT__branch_result));
        tracep->fullCData(oldp+70,(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg),2);
        tracep->fullBit(oldp+71,(((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                   | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+72,((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                   | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                   ? 1U : 0U)));
        tracep->fullIData(oldp+73,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a),32);
        tracep->fullIData(oldp+74,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b),32);
        tracep->fullCData(oldp+75,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel),3);
        tracep->fullIData(oldp+76,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out),32);
        tracep->fullBit(oldp+77,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type));
        tracep->fullBit(oldp+78,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type));
        tracep->fullBit(oldp+79,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui));
        tracep->fullBit(oldp+80,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc));
        tracep->fullCData(oldp+81,((3U & vlTOPp->core__DOT__u_Core10__DOT__alu_res_out)),2);
        tracep->fullCData(oldp+82,((0xffU & (vlTOPp->core__DOT__u_Core10__DOT__alu_res_out 
                                             >> 2U))),8);
        tracep->fullBit(oldp+83,(vlTOPp->clk));
        tracep->fullBit(oldp+84,(vlTOPp->rst));
        tracep->fullIData(oldp+85,(vlTOPp->instruction),32);
        tracep->fullIData(oldp+86,(((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                                     ? vlTOPp->core__DOT__u_Core10__DOT__alu_res_out
                                     : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                                         ? vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out
                                         : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg))
                                             ? ((IData)(4U) 
                                                + vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address)
                                             : 0U)))),32);
        tracep->fullBit(oldp+87,((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                       | (IData)(vlTOPp->core__DOT__data_mem_valid)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                   | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                   ? 1U : 0U)));
        tracep->fullIData(oldp+88,(0x20U),32);
        tracep->fullBit(oldp+89,(0U));
        tracep->fullCData(oldp+90,(0xfU),4);
        tracep->fullIData(oldp+91,(1U),32);
        tracep->fullIData(oldp+92,(4U),32);
        tracep->fullIData(oldp+93,(0U),32);
        tracep->fullIData(oldp+94,(3U),32);
        tracep->fullIData(oldp+95,(7U),32);
        tracep->fullIData(oldp+96,(5U),32);
    }
}
