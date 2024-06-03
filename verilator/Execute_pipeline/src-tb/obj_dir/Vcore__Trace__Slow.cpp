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
        tracep->declBit(c+113,"clk", false,-1);
        tracep->declBit(c+114,"rst", false,-1);
        tracep->declBus(c+115,"instruction", false,-1, 31,0);
        tracep->declBus(c+120,"core INSTRUCTION", false,-1, 31,0);
        tracep->declBit(c+113,"core clk", false,-1);
        tracep->declBit(c+114,"core rst", false,-1);
        tracep->declBus(c+115,"core instruction", false,-1, 31,0);
        tracep->declBus(c+82,"core pc_address", false,-1, 31,0);
        tracep->declBus(c+46,"core instruction_o", false,-1, 31,0);
        tracep->declBus(c+47,"core DM_alu_res_out", false,-1, 31,0);
        tracep->declBus(c+1,"core DM_load_data_in", false,-1, 31,0);
        tracep->declBus(c+48,"core DM_store_data_out", false,-1, 31,0);
        tracep->declBit(c+121,"core instruction_mem_we_re", false,-1);
        tracep->declBit(c+93,"core instruction_mem_request", false,-1);
        tracep->declBit(c+13,"core valid", false,-1);
        tracep->declBit(c+83,"core data_mem_valid", false,-1);
        tracep->declBit(c+94,"core data_mem_request", false,-1);
        tracep->declBit(c+95,"core data_mem_we_re", false,-1);
        tracep->declBit(c+88,"core DM_Load", false,-1);
        tracep->declBus(c+122,"core instruction_mem_mask", false,-1, 3,0);
        tracep->declBus(c+49,"core data_mem_mask", false,-1, 3,0);
        tracep->declBus(c+123,"core u_instruc_mem_top0 INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+113,"core u_instruc_mem_top0 clk", false,-1);
        tracep->declBit(c+114,"core u_instruc_mem_top0 rst", false,-1);
        tracep->declBit(c+121,"core u_instruc_mem_top0 we_re", false,-1);
        tracep->declBit(c+93,"core u_instruc_mem_top0 request", false,-1);
        tracep->declBus(c+122,"core u_instruc_mem_top0 mask", false,-1, 3,0);
        tracep->declBus(c+84,"core u_instruc_mem_top0 address", false,-1, 7,0);
        tracep->declBus(c+115,"core u_instruc_mem_top0 data_in", false,-1, 31,0);
        tracep->declBit(c+13,"core u_instruc_mem_top0 valid", false,-1);
        tracep->declBus(c+46,"core u_instruc_mem_top0 data_out", false,-1, 31,0);
        tracep->declBus(c+123,"core u_instruc_mem_top0 u_memory INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+113,"core u_instruc_mem_top0 u_memory clk", false,-1);
        tracep->declBit(c+121,"core u_instruc_mem_top0 u_memory we_re", false,-1);
        tracep->declBit(c+93,"core u_instruc_mem_top0 u_memory request", false,-1);
        tracep->declBus(c+84,"core u_instruc_mem_top0 u_memory address", false,-1, 7,0);
        tracep->declBus(c+115,"core u_instruc_mem_top0 u_memory data_in", false,-1, 31,0);
        tracep->declBus(c+122,"core u_instruc_mem_top0 u_memory mask", false,-1, 3,0);
        tracep->declBus(c+46,"core u_instruc_mem_top0 u_memory data_out", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 ADDRESS", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+124,"core u_Core10 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 clk", false,-1);
        tracep->declBit(c+114,"core u_Core10 rst", false,-1);
        tracep->declBus(c+46,"core u_Core10 instruction", false,-1, 31,0);
        tracep->declBit(c+13,"core u_Core10 instruction_mem_valid", false,-1);
        tracep->declBus(c+1,"core u_Core10 DM_load_data_in", false,-1, 31,0);
        tracep->declBit(c+83,"core u_Core10 DM_valid", false,-1);
        tracep->declBus(c+82,"core u_Core10 address_out", false,-1, 31,0);
        tracep->declBit(c+88,"core u_Core10 DM_Load", false,-1);
        tracep->declBit(c+93,"core u_Core10 instruction_mem_request", false,-1);
        tracep->declBit(c+121,"core u_Core10 instruction_mem_we_re", false,-1);
        tracep->declBus(c+122,"core u_Core10 instruction_mem_mask", false,-1, 3,0);
        tracep->declBit(c+94,"core u_Core10 data_mem_request", false,-1);
        tracep->declBit(c+95,"core u_Core10 data_mem_we_re", false,-1);
        tracep->declBus(c+49,"core u_Core10 data_mem_mask", false,-1, 3,0);
        tracep->declBus(c+48,"core u_Core10 DM_store_data_out", false,-1, 31,0);
        tracep->declBus(c+47,"core u_Core10 DM_alu_res_out", false,-1, 31,0);
        tracep->declBus(c+89,"core u_Core10 alu_in_b", false,-1, 31,0);
        tracep->declBus(c+90,"core u_Core10 alu_in_a", false,-1, 31,0);
        tracep->declBus(c+47,"core u_Core10 alu_res_out_execute_pp", false,-1, 31,0);
        tracep->declBus(c+50,"core u_Core10 instruction_out_execute_pp", false,-1, 31,0);
        tracep->declBus(c+2,"core u_Core10 pre_address_out_execute_pp", false,-1, 31,0);
        tracep->declBus(c+51,"core u_Core10 next_sel_address_execute_pp", false,-1, 31,0);
        tracep->declBus(c+3,"core u_Core10 op_b_execute_pp", false,-1, 31,0);
        tracep->declBus(c+4,"core u_Core10 opb_mux_out_decode_pp", false,-1, 31,0);
        tracep->declBus(c+5,"core u_Core10 opa_mux_out_decode_pp", false,-1, 31,0);
        tracep->declBus(c+52,"core u_Core10 pc_decode_pp", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 next_sel_address", false,-1, 31,0);
        tracep->declBus(c+116,"core u_Core10 opb_mux_out", false,-1, 31,0);
        tracep->declBus(c+117,"core u_Core10 opa_mux_out", false,-1, 31,0);
        tracep->declBus(c+118,"core u_Core10 rd_wb_data", false,-1, 31,0);
        tracep->declBus(c+54,"core u_Core10 instruction_decode_pp", false,-1, 31,0);
        tracep->declBus(c+55,"core u_Core10 instruction_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+56,"core u_Core10 pre_pc_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+85,"core u_Core10 pre_pc", false,-1, 31,0);
        tracep->declBus(c+46,"core u_Core10 instruction_out", false,-1, 31,0);
        tracep->declBus(c+96,"core u_Core10 wrap_load_out", false,-1, 31,0);
        tracep->declBus(c+91,"core u_Core10 alu_res_out", false,-1, 31,0);
        tracep->declBus(c+6,"core u_Core10 alu_control_decode_pp", false,-1, 3,0);
        tracep->declBus(c+97,"core u_Core10 alu_control", false,-1, 3,0);
        tracep->declBit(c+57,"core u_Core10 flush", false,-1);
        tracep->declBit(c+7,"core u_Core10 mem_en_execute_pp", false,-1);
        tracep->declBit(c+8,"core u_Core10 store_out_execute_pp", false,-1);
        tracep->declBit(c+88,"core u_Core10 load_out_execute_pp", false,-1);
        tracep->declBit(c+58,"core u_Core10 reg_write_execute_pp", false,-1);
        tracep->declBit(c+59,"core u_Core10 decode_reg_write_pp", false,-1);
        tracep->declBit(c+119,"core u_Core10 reg_write", false,-1);
        tracep->declBit(c+60,"core u_Core10 Branch_decode_pp", false,-1);
        tracep->declBit(c+61,"core u_Core10 next_sel_decode_pp", false,-1);
        tracep->declBit(c+62,"core u_Core10 Jalr_decode_pp", false,-1);
        tracep->declBit(c+63,"core u_Core10 branch_result_decode_pp", false,-1);
        tracep->declBit(c+9,"core u_Core10 mem_en_decode_pp", false,-1);
        tracep->declBit(c+10,"core u_Core10 Store_decode_pp", false,-1);
        tracep->declBit(c+92,"core u_Core10 Load_decode_pp", false,-1);
        tracep->declBit(c+98,"core u_Core10 Jalr", false,-1);
        tracep->declBit(c+99,"core u_Core10 next_sel", false,-1);
        tracep->declBit(c+100,"core u_Core10 Load", false,-1);
        tracep->declBit(c+101,"core u_Core10 Store", false,-1);
        tracep->declBit(c+101,"core u_Core10 mem_en", false,-1);
        tracep->declBit(c+102,"core u_Core10 Branch", false,-1);
        tracep->declBit(c+103,"core u_Core10 branch_result", false,-1);
        tracep->declBus(c+64,"core u_Core10 mem_reg_out_execute_pp", false,-1, 1,0);
        tracep->declBus(c+104,"core u_Core10 mem_to_reg", false,-1, 1,0);
        tracep->declBus(c+65,"core u_Core10 mem_to_reg_decode_pp", false,-1, 1,0);
        tracep->declBus(c+11,"core u_Core10 rs1_decode_pp", false,-1, 4,0);
        tracep->declBus(c+12,"core u_Core10 rs2_decode_pp", false,-1, 4,0);
        tracep->declBus(c+66,"core u_Core10 rs1_decode", false,-1, 4,0);
        tracep->declBus(c+67,"core u_Core10 rs2_decode", false,-1, 4,0);
        tracep->declBus(c+68,"core u_Core10 rd_execute", false,-1, 4,0);
        tracep->declBus(c+120,"core u_Core10 u_Fetch_stage0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Fetch_stage0 ADDRESS", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Fetch_stage0 clk", false,-1);
        tracep->declBit(c+114,"core u_Core10 u_Fetch_stage0 rst", false,-1);
        tracep->declBit(c+100,"core u_Core10 u_Fetch_stage0 load", false,-1);
        tracep->declBit(c+83,"core u_Core10 u_Fetch_stage0 DM_valid", false,-1);
        tracep->declBus(c+125,"core u_Core10 u_Fetch_stage0 address_in", false,-1, 31,0);
        tracep->declBus(c+91,"core u_Core10 u_Fetch_stage0 next_address", false,-1, 31,0);
        tracep->declBus(c+46,"core u_Core10 u_Fetch_stage0 instruction_fetch", false,-1, 31,0);
        tracep->declBit(c+60,"core u_Core10 u_Fetch_stage0 branch", false,-1);
        tracep->declBit(c+61,"core u_Core10 u_Fetch_stage0 next_sel", false,-1);
        tracep->declBit(c+62,"core u_Core10 u_Fetch_stage0 Jalr", false,-1);
        tracep->declBit(c+63,"core u_Core10 u_Fetch_stage0 branch_result", false,-1);
        tracep->declBit(c+93,"core u_Core10 u_Fetch_stage0 request", false,-1);
        tracep->declBit(c+121,"core u_Core10 u_Fetch_stage0 we_re", false,-1);
        tracep->declBus(c+122,"core u_Core10 u_Fetch_stage0 mask", false,-1, 3,0);
        tracep->declBus(c+46,"core u_Core10 u_Fetch_stage0 instruction", false,-1, 31,0);
        tracep->declBus(c+85,"core u_Core10 u_Fetch_stage0 pre_pc", false,-1, 31,0);
        tracep->declBus(c+82,"core u_Core10 u_Fetch_stage0 pc_addr_out", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Fetch_stage0 u_pc0 ADDRESS", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Fetch_stage0 u_pc0 clk", false,-1);
        tracep->declBit(c+114,"core u_Core10 u_Fetch_stage0 u_pc0 rst", false,-1);
        tracep->declBus(c+125,"core u_Core10 u_Fetch_stage0 u_pc0 address_in", false,-1, 31,0);
        tracep->declBus(c+91,"core u_Core10 u_Fetch_stage0 u_pc0 next_address", false,-1, 31,0);
        tracep->declBit(c+100,"core u_Core10 u_Fetch_stage0 u_pc0 load", false,-1);
        tracep->declBit(c+83,"core u_Core10 u_Fetch_stage0 u_pc0 DM_valid", false,-1);
        tracep->declBit(c+60,"core u_Core10 u_Fetch_stage0 u_pc0 branch", false,-1);
        tracep->declBit(c+61,"core u_Core10 u_Fetch_stage0 u_pc0 next_sel", false,-1);
        tracep->declBit(c+62,"core u_Core10 u_Fetch_stage0 u_pc0 Jalr", false,-1);
        tracep->declBit(c+63,"core u_Core10 u_Fetch_stage0 u_pc0 branch_result", false,-1);
        tracep->declBus(c+82,"core u_Core10 u_Fetch_stage0 u_pc0 address_out", false,-1, 31,0);
        tracep->declBus(c+85,"core u_Core10 u_Fetch_stage0 u_pc0 pre_pc", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Fetch_pipe0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Fetch_pipe0 ADDRESS", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Fetch_pipe0 clk", false,-1);
        tracep->declBus(c+85,"core u_Core10 u_Fetch_pipe0 pre_address_fetch", false,-1, 31,0);
        tracep->declBus(c+46,"core u_Core10 u_Fetch_pipe0 instruction_fetch", false,-1, 31,0);
        tracep->declBit(c+99,"core u_Core10 u_Fetch_pipe0 next_select", false,-1);
        tracep->declBit(c+102,"core u_Core10 u_Fetch_pipe0 branch_result", false,-1);
        tracep->declBit(c+100,"core u_Core10 u_Fetch_pipe0 load", false,-1);
        tracep->declBit(c+98,"core u_Core10 u_Fetch_pipe0 Jalr", false,-1);
        tracep->declBus(c+56,"core u_Core10 u_Fetch_pipe0 pre_pc_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+55,"core u_Core10 u_Fetch_pipe0 instruction_fetch_pp", false,-1, 31,0);
        tracep->declBus(c+56,"core u_Core10 u_Fetch_pipe0 pre_address", false,-1, 31,0);
        tracep->declBus(c+55,"core u_Core10 u_Fetch_pipe0 instruc", false,-1, 31,0);
        tracep->declBit(c+69,"core u_Core10 u_Fetch_pipe0 flush_pipeline", false,-1);
        tracep->declBit(c+70,"core u_Core10 u_Fetch_pipe0 flush_pipeline2", false,-1);
        tracep->declBus(c+120,"core u_Core10 u_Decode_stage0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Decode_stage0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+124,"core u_Core10 u_Decode_stage0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Decode_stage0 clk", false,-1);
        tracep->declBit(c+114,"core u_Core10 u_Decode_stage0 rst", false,-1);
        tracep->declBit(c+83,"core u_Core10 u_Decode_stage0 DM_valid", false,-1);
        tracep->declBit(c+92,"core u_Core10 u_Decode_stage0 decode_ppload", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Decode_stage0 decode_reg_write_pp", false,-1);
        tracep->declBus(c+55,"core u_Core10 u_Decode_stage0 instruction", false,-1, 31,0);
        tracep->declBus(c+118,"core u_Core10 u_Decode_stage0 rwd_data_out", false,-1, 31,0);
        tracep->declBus(c+56,"core u_Core10 u_Decode_stage0 pc", false,-1, 31,0);
        tracep->declBus(c+50,"core u_Core10 u_Decode_stage0 instruction_rd", false,-1, 31,0);
        tracep->declBus(c+97,"core u_Core10 u_Decode_stage0 alu_control", false,-1, 3,0);
        tracep->declBus(c+116,"core u_Core10 u_Decode_stage0 opb_mux_out", false,-1, 31,0);
        tracep->declBus(c+117,"core u_Core10 u_Decode_stage0 opa_mux_out", false,-1, 31,0);
        tracep->declBus(c+66,"core u_Core10 u_Decode_stage0 rs1", false,-1, 4,0);
        tracep->declBus(c+67,"core u_Core10 u_Decode_stage0 rs2", false,-1, 4,0);
        tracep->declBit(c+119,"core u_Core10 u_Decode_stage0 reg_write", false,-1);
        tracep->declBit(c+100,"core u_Core10 u_Decode_stage0 Load", false,-1);
        tracep->declBit(c+101,"core u_Core10 u_Decode_stage0 Store", false,-1);
        tracep->declBit(c+102,"core u_Core10 u_Decode_stage0 Branch", false,-1);
        tracep->declBit(c+99,"core u_Core10 u_Decode_stage0 next_sel", false,-1);
        tracep->declBit(c+98,"core u_Core10 u_Decode_stage0 Jalr", false,-1);
        tracep->declBit(c+103,"core u_Core10 u_Decode_stage0 branch_result", false,-1);
        tracep->declBus(c+104,"core u_Core10 u_Decode_stage0 mem_to_reg", false,-1, 1,0);
        tracep->declBit(c+101,"core u_Core10 u_Decode_stage0 mem_en", false,-1);
        tracep->declBus(c+71,"core u_Core10 u_Decode_stage0 i_imme", false,-1, 31,0);
        tracep->declBus(c+72,"core u_Core10 u_Decode_stage0 s_imme", false,-1, 31,0);
        tracep->declBus(c+73,"core u_Core10 u_Decode_stage0 sb_imme", false,-1, 31,0);
        tracep->declBus(c+74,"core u_Core10 u_Decode_stage0 uj_imme", false,-1, 31,0);
        tracep->declBus(c+75,"core u_Core10 u_Decode_stage0 u_imme", false,-1, 31,0);
        tracep->declBit(c+105,"core u_Core10 u_Decode_stage0 operand_a", false,-1);
        tracep->declBit(c+106,"core u_Core10 u_Decode_stage0 operand_b", false,-1);
        tracep->declBit(c+102,"core u_Core10 u_Decode_stage0 branch", false,-1);
        tracep->declBus(c+86,"core u_Core10 u_Decode_stage0 op_a", false,-1, 31,0);
        tracep->declBus(c+87,"core u_Core10 u_Decode_stage0 op_b", false,-1, 31,0);
        tracep->declBus(c+107,"core u_Core10 u_Decode_stage0 imm_sel", false,-1, 2,0);
        tracep->declBus(c+108,"core u_Core10 u_Decode_stage0 imm_mux_out", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Decode_stage0 u_immediate_gene0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+55,"core u_Core10 u_Decode_stage0 u_immediate_gene0 instruction", false,-1, 31,0);
        tracep->declBus(c+71,"core u_Core10 u_Decode_stage0 u_immediate_gene0 i_imme", false,-1, 31,0);
        tracep->declBus(c+72,"core u_Core10 u_Decode_stage0 u_immediate_gene0 s_imme", false,-1, 31,0);
        tracep->declBus(c+73,"core u_Core10 u_Decode_stage0 u_immediate_gene0 sb_imme", false,-1, 31,0);
        tracep->declBus(c+74,"core u_Core10 u_Decode_stage0 u_immediate_gene0 uj_imme", false,-1, 31,0);
        tracep->declBus(c+75,"core u_Core10 u_Decode_stage0 u_immediate_gene0 u_imme", false,-1, 31,0);
        tracep->declBus(c+126,"core u_Core10 u_Decode_stage0 u_cu0 FUNCTION3", false,-1, 31,0);
        tracep->declBus(c+127,"core u_Core10 u_Decode_stage0 u_cu0 OPCODE", false,-1, 31,0);
        tracep->declBus(c+124,"core u_Core10 u_Decode_stage0 u_cu0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+76,"core u_Core10 u_Decode_stage0 u_cu0 fun7", false,-1);
        tracep->declBit(c+83,"core u_Core10 u_Decode_stage0 u_cu0 DM_valid", false,-1);
        tracep->declBit(c+92,"core u_Core10 u_Decode_stage0 u_cu0 decode_ppload", false,-1);
        tracep->declBus(c+77,"core u_Core10 u_Decode_stage0 u_cu0 fun3", false,-1, 2,0);
        tracep->declBus(c+78,"core u_Core10 u_Decode_stage0 u_cu0 opcode_i", false,-1, 6,0);
        tracep->declBit(c+101,"core u_Core10 u_Decode_stage0 u_cu0 mem_en", false,-1);
        tracep->declBit(c+100,"core u_Core10 u_Decode_stage0 u_cu0 Load", false,-1);
        tracep->declBit(c+101,"core u_Core10 u_Decode_stage0 u_cu0 Store", false,-1);
        tracep->declBit(c+102,"core u_Core10 u_Decode_stage0 u_cu0 Branch", false,-1);
        tracep->declBit(c+99,"core u_Core10 u_Decode_stage0 u_cu0 next_sel", false,-1);
        tracep->declBit(c+98,"core u_Core10 u_Decode_stage0 u_cu0 Jalr", false,-1);
        tracep->declBit(c+119,"core u_Core10 u_Decode_stage0 u_cu0 reg_write_o", false,-1);
        tracep->declBit(c+105,"core u_Core10 u_Decode_stage0 u_cu0 operand_a_o", false,-1);
        tracep->declBit(c+106,"core u_Core10 u_Decode_stage0 u_cu0 operand_b_o", false,-1);
        tracep->declBus(c+107,"core u_Core10 u_Decode_stage0 u_cu0 imm_sel", false,-1, 2,0);
        tracep->declBus(c+104,"core u_Core10 u_Decode_stage0 u_cu0 mem_to_reg", false,-1, 1,0);
        tracep->declBus(c+97,"core u_Core10 u_Decode_stage0 u_cu0 alu_control", false,-1, 3,0);
        tracep->declBit(c+109,"core u_Core10 u_Decode_stage0 u_cu0 r_type", false,-1);
        tracep->declBit(c+110,"core u_Core10 u_Decode_stage0 u_cu0 i_type", false,-1);
        tracep->declBit(c+101,"core u_Core10 u_Decode_stage0 u_cu0 store", false,-1);
        tracep->declBit(c+100,"core u_Core10 u_Decode_stage0 u_cu0 load", false,-1);
        tracep->declBit(c+102,"core u_Core10 u_Decode_stage0 u_cu0 branch", false,-1);
        tracep->declBit(c+99,"core u_Core10 u_Decode_stage0 u_cu0 jal", false,-1);
        tracep->declBit(c+98,"core u_Core10 u_Decode_stage0 u_cu0 jalr", false,-1);
        tracep->declBit(c+111,"core u_Core10 u_Decode_stage0 u_cu0 lui", false,-1);
        tracep->declBit(c+112,"core u_Core10 u_Decode_stage0 u_cu0 auipc", false,-1);
        tracep->declBus(c+120,"core u_Core10 u_Decode_stage0 u_registerfile0 Data_Width", false,-1, 31,0);
        tracep->declBus(c+128,"core u_Core10 u_Decode_stage0 u_registerfile0 AddrRegWidth", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Decode_stage0 u_registerfile0 clk", false,-1);
        tracep->declBit(c+114,"core u_Core10 u_Decode_stage0 u_registerfile0 rst", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Decode_stage0 u_registerfile0 en", false,-1);
        tracep->declBus(c+66,"core u_Core10 u_Decode_stage0 u_registerfile0 rs1", false,-1, 4,0);
        tracep->declBus(c+67,"core u_Core10 u_Decode_stage0 u_registerfile0 rs2", false,-1, 4,0);
        tracep->declBus(c+68,"core u_Core10 u_Decode_stage0 u_registerfile0 rd", false,-1, 4,0);
        tracep->declBus(c+118,"core u_Core10 u_Decode_stage0 u_registerfile0 data", false,-1, 31,0);
        tracep->declBus(c+86,"core u_Core10 u_Decode_stage0 u_registerfile0 op_a", false,-1, 31,0);
        tracep->declBus(c+87,"core u_Core10 u_Decode_stage0 u_registerfile0 op_b", false,-1, 31,0);
        {int i; for (i=0; i<31; i++) {
                tracep->declBus(c+14+i*1,"core u_Core10 u_Decode_stage0 u_registerfile0 register", true,(i+1), 31,0);}}
        tracep->declBus(c+45,"core u_Core10 u_Decode_stage0 u_registerfile0 i", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Decode_stage0 u_branch0 DataWidth", false,-1, 31,0);
        tracep->declBit(c+102,"core u_Core10 u_Decode_stage0 u_branch0 en", false,-1);
        tracep->declBus(c+77,"core u_Core10 u_Decode_stage0 u_branch0 fun3", false,-1, 2,0);
        tracep->declBus(c+86,"core u_Core10 u_Decode_stage0 u_branch0 operand_a", false,-1, 31,0);
        tracep->declBus(c+87,"core u_Core10 u_Decode_stage0 u_branch0 operand_b", false,-1, 31,0);
        tracep->declBit(c+103,"core u_Core10 u_Decode_stage0 u_branch0 result", false,-1);
        tracep->declBus(c+120,"core u_Core10 u_Decode_pipe0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Decode_pipe0 INSTRUCTION", false,-1, 31,0);
        tracep->declBus(c+124,"core u_Core10 u_Decode_pipe0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Decode_pipe0 clk", false,-1);
        tracep->declBus(c+55,"core u_Core10 u_Decode_pipe0 instruction", false,-1, 31,0);
        tracep->declBus(c+56,"core u_Core10 u_Decode_pipe0 pc", false,-1, 31,0);
        tracep->declBus(c+97,"core u_Core10 u_Decode_pipe0 alu_control", false,-1, 3,0);
        tracep->declBus(c+116,"core u_Core10 u_Decode_pipe0 opb_mux_out", false,-1, 31,0);
        tracep->declBus(c+117,"core u_Core10 u_Decode_pipe0 opa_mux_out", false,-1, 31,0);
        tracep->declBus(c+66,"core u_Core10 u_Decode_pipe0 rs1", false,-1, 4,0);
        tracep->declBus(c+67,"core u_Core10 u_Decode_pipe0 rs2", false,-1, 4,0);
        tracep->declBit(c+100,"core u_Core10 u_Decode_pipe0 Load", false,-1);
        tracep->declBit(c+101,"core u_Core10 u_Decode_pipe0 Store", false,-1);
        tracep->declBit(c+102,"core u_Core10 u_Decode_pipe0 Branch", false,-1);
        tracep->declBit(c+99,"core u_Core10 u_Decode_pipe0 next_sel", false,-1);
        tracep->declBit(c+98,"core u_Core10 u_Decode_pipe0 Jalr", false,-1);
        tracep->declBit(c+103,"core u_Core10 u_Decode_pipe0 branch_result", false,-1);
        tracep->declBus(c+104,"core u_Core10 u_Decode_pipe0 mem_to_reg", false,-1, 1,0);
        tracep->declBit(c+101,"core u_Core10 u_Decode_pipe0 mem_en", false,-1);
        tracep->declBit(c+119,"core u_Core10 u_Decode_pipe0 reg_write", false,-1);
        tracep->declBus(c+54,"core u_Core10 u_Decode_pipe0 instruction_decode_pp", false,-1, 31,0);
        tracep->declBus(c+52,"core u_Core10 u_Decode_pipe0 pc_decode_pp", false,-1, 31,0);
        tracep->declBus(c+6,"core u_Core10 u_Decode_pipe0 alu_control_decode_pp", false,-1, 3,0);
        tracep->declBus(c+4,"core u_Core10 u_Decode_pipe0 opb_mux_out_decode_pp", false,-1, 31,0);
        tracep->declBus(c+5,"core u_Core10 u_Decode_pipe0 opa_mux_out_decode_pp", false,-1, 31,0);
        tracep->declBus(c+11,"core u_Core10 u_Decode_pipe0 rs1_decode_pp", false,-1, 4,0);
        tracep->declBus(c+12,"core u_Core10 u_Decode_pipe0 rs2_decode_pp", false,-1, 4,0);
        tracep->declBit(c+92,"core u_Core10 u_Decode_pipe0 Load_decode_pp", false,-1);
        tracep->declBit(c+59,"core u_Core10 u_Decode_pipe0 decode_reg_write_pp", false,-1);
        tracep->declBit(c+10,"core u_Core10 u_Decode_pipe0 Store_decode_pp", false,-1);
        tracep->declBit(c+60,"core u_Core10 u_Decode_pipe0 Branch_decode_pp", false,-1);
        tracep->declBit(c+61,"core u_Core10 u_Decode_pipe0 next_sel_decode_pp", false,-1);
        tracep->declBit(c+62,"core u_Core10 u_Decode_pipe0 Jalr_decode_pp", false,-1);
        tracep->declBit(c+63,"core u_Core10 u_Decode_pipe0 branch_result_decode_pp", false,-1);
        tracep->declBus(c+65,"core u_Core10 u_Decode_pipe0 mem_to_reg_decode_pp", false,-1, 1,0);
        tracep->declBit(c+9,"core u_Core10 u_Decode_pipe0 mem_en_decode_pp", false,-1);
        tracep->declBus(c+11,"core u_Core10 u_Decode_pipe0 r1", false,-1, 4,0);
        tracep->declBus(c+12,"core u_Core10 u_Decode_pipe0 r2", false,-1, 4,0);
        tracep->declBit(c+59,"core u_Core10 u_Decode_pipe0 rg", false,-1);
        tracep->declBit(c+92,"core u_Core10 u_Decode_pipe0 l", false,-1);
        tracep->declBit(c+10,"core u_Core10 u_Decode_pipe0 s", false,-1);
        tracep->declBit(c+61,"core u_Core10 u_Decode_pipe0 nextsel", false,-1);
        tracep->declBit(c+63,"core u_Core10 u_Decode_pipe0 branch_res", false,-1);
        tracep->declBit(c+62,"core u_Core10 u_Decode_pipe0 jalr", false,-1);
        tracep->declBit(c+9,"core u_Core10 u_Decode_pipe0 men", false,-1);
        tracep->declBit(c+60,"core u_Core10 u_Decode_pipe0 branch_", false,-1);
        tracep->declBus(c+65,"core u_Core10 u_Decode_pipe0 mem_reg", false,-1, 1,0);
        tracep->declBus(c+6,"core u_Core10 u_Decode_pipe0 alu_con", false,-1, 3,0);
        tracep->declBus(c+5,"core u_Core10 u_Decode_pipe0 opa_mux", false,-1, 31,0);
        tracep->declBus(c+4,"core u_Core10 u_Decode_pipe0 opb_mux", false,-1, 31,0);
        tracep->declBus(c+52,"core u_Core10 u_Decode_pipe0 pre_address", false,-1, 31,0);
        tracep->declBus(c+54,"core u_Core10 u_Decode_pipe0 instruct", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Execute_stage0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+124,"core u_Core10 u_Execute_stage0 ALU_CONTROL", false,-1, 31,0);
        tracep->declBus(c+90,"core u_Core10 u_Execute_stage0 a_i", false,-1, 31,0);
        tracep->declBus(c+89,"core u_Core10 u_Execute_stage0 b_i", false,-1, 31,0);
        tracep->declBus(c+52,"core u_Core10 u_Execute_stage0 pc_address", false,-1, 31,0);
        tracep->declBus(c+6,"core u_Core10 u_Execute_stage0 alu_control", false,-1, 3,0);
        tracep->declBus(c+91,"core u_Core10 u_Execute_stage0 alu_res_out", false,-1, 31,0);
        tracep->declBus(c+53,"core u_Core10 u_Execute_stage0 next_sel_address", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Execute_stage0 u_alu0 DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+90,"core u_Core10 u_Execute_stage0 u_alu0 a_i", false,-1, 31,0);
        tracep->declBus(c+89,"core u_Core10 u_Execute_stage0 u_alu0 b_i", false,-1, 31,0);
        tracep->declBus(c+6,"core u_Core10 u_Execute_stage0 u_alu0 op_i", false,-1, 3,0);
        tracep->declBus(c+91,"core u_Core10 u_Execute_stage0 u_alu0 res_o", false,-1, 31,0);
        tracep->declBit(c+113,"core u_Core10 u_Execute_pipe0 clk", false,-1);
        tracep->declBit(c+92,"core u_Core10 u_Execute_pipe0 load_in", false,-1);
        tracep->declBit(c+10,"core u_Core10 u_Execute_pipe0 store_in", false,-1);
        tracep->declBit(c+59,"core u_Core10 u_Execute_pipe0 reg_write_in", false,-1);
        tracep->declBit(c+9,"core u_Core10 u_Execute_pipe0 mem_en", false,-1);
        tracep->declBus(c+4,"core u_Core10 u_Execute_pipe0 op_b_execute", false,-1, 31,0);
        tracep->declBus(c+91,"core u_Core10 u_Execute_pipe0 alu_res", false,-1, 31,0);
        tracep->declBus(c+65,"core u_Core10 u_Execute_pipe0 mem_reg_in", false,-1, 1,0);
        tracep->declBus(c+53,"core u_Core10 u_Execute_pipe0 next_sel_addr", false,-1, 31,0);
        tracep->declBus(c+52,"core u_Core10 u_Execute_pipe0 pre_address_in", false,-1, 31,0);
        tracep->declBus(c+54,"core u_Core10 u_Execute_pipe0 instruction_in", false,-1, 31,0);
        tracep->declBit(c+7,"core u_Core10 u_Execute_pipe0 mem_en_execute_pp", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Execute_pipe0 reg_write_execute_pp", false,-1);
        tracep->declBit(c+88,"core u_Core10 u_Execute_pipe0 load_out_execute_pp", false,-1);
        tracep->declBit(c+8,"core u_Core10 u_Execute_pipe0 store_out_execute_pp", false,-1);
        tracep->declBus(c+3,"core u_Core10 u_Execute_pipe0 op_b_execute_pp", false,-1, 31,0);
        tracep->declBus(c+47,"core u_Core10 u_Execute_pipe0 alu_res_out_execute_pp", false,-1, 31,0);
        tracep->declBus(c+64,"core u_Core10 u_Execute_pipe0 mem_reg_out_execute_pp", false,-1, 1,0);
        tracep->declBus(c+51,"core u_Core10 u_Execute_pipe0 next_sel_address_execute_pp", false,-1, 31,0);
        tracep->declBus(c+2,"core u_Core10 u_Execute_pipe0 pre_address_out_execute_pp", false,-1, 31,0);
        tracep->declBus(c+50,"core u_Core10 u_Execute_pipe0 instruction_out_execute_pp", false,-1, 31,0);
        tracep->declBit(c+88,"core u_Core10 u_Execute_pipe0 load", false,-1);
        tracep->declBit(c+8,"core u_Core10 u_Execute_pipe0 store", false,-1);
        tracep->declBit(c+58,"core u_Core10 u_Execute_pipe0 reg_write", false,-1);
        tracep->declBit(c+7,"core u_Core10 u_Execute_pipe0 me", false,-1);
        tracep->declBus(c+64,"core u_Core10 u_Execute_pipe0 mem_reg", false,-1, 1,0);
        tracep->declBus(c+47,"core u_Core10 u_Execute_pipe0 alu_result", false,-1, 31,0);
        tracep->declBus(c+51,"core u_Core10 u_Execute_pipe0 nextsel_addr", false,-1, 31,0);
        tracep->declBus(c+2,"core u_Core10 u_Execute_pipe0 pre_address", false,-1, 31,0);
        tracep->declBus(c+50,"core u_Core10 u_Execute_pipe0 instruction", false,-1, 31,0);
        tracep->declBus(c+3,"core u_Core10 u_Execute_pipe0 opb_data", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_memorystage0 DataWidth", false,-1, 31,0);
        tracep->declBit(c+88,"core u_Core10 u_memorystage0 load", false,-1);
        tracep->declBit(c+8,"core u_Core10 u_memorystage0 store", false,-1);
        tracep->declBit(c+7,"core u_Core10 u_memorystage0 mem_en", false,-1);
        tracep->declBit(c+13,"core u_Core10 u_memorystage0 valid", false,-1);
        tracep->declBit(c+83,"core u_Core10 u_memorystage0 data_valid", false,-1);
        tracep->declBus(c+3,"core u_Core10 u_memorystage0 operand_b", false,-1, 31,0);
        tracep->declBus(c+50,"core u_Core10 u_memorystage0 instruction", false,-1, 31,0);
        tracep->declBus(c+1,"core u_Core10 u_memorystage0 wrap_load_in", false,-1, 31,0);
        tracep->declBus(c+47,"core u_Core10 u_memorystage0 alu_out_address", false,-1, 31,0);
        tracep->declBit(c+95,"core u_Core10 u_memorystage0 we_re", false,-1);
        tracep->declBit(c+94,"core u_Core10 u_memorystage0 request", false,-1);
        tracep->declBus(c+49,"core u_Core10 u_memorystage0 mask", false,-1, 3,0);
        tracep->declBus(c+48,"core u_Core10 u_memorystage0 store_data_out", false,-1, 31,0);
        tracep->declBus(c+96,"core u_Core10 u_memorystage0 wrap_load_out", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_memorystage0 u_wrapper_memory0 DataWidth", false,-1, 31,0);
        tracep->declBit(c+88,"core u_Core10 u_memorystage0 u_wrapper_memory0 Load", false,-1);
        tracep->declBit(c+7,"core u_Core10 u_memorystage0 u_wrapper_memory0 mem_en", false,-1);
        tracep->declBit(c+83,"core u_Core10 u_memorystage0 u_wrapper_memory0 data_valid", false,-1);
        tracep->declBus(c+79,"core u_Core10 u_memorystage0 u_wrapper_memory0 fun3", false,-1, 2,0);
        tracep->declBus(c+80,"core u_Core10 u_memorystage0 u_wrapper_memory0 byteadd", false,-1, 1,0);
        tracep->declBus(c+3,"core u_Core10 u_memorystage0 u_wrapper_memory0 data_i", false,-1, 31,0);
        tracep->declBus(c+1,"core u_Core10 u_memorystage0 u_wrapper_memory0 wrap_load_in", false,-1, 31,0);
        tracep->declBus(c+49,"core u_Core10 u_memorystage0 u_wrapper_memory0 masking", false,-1, 3,0);
        tracep->declBus(c+48,"core u_Core10 u_memorystage0 u_wrapper_memory0 data_o", false,-1, 31,0);
        tracep->declBus(c+96,"core u_Core10 u_memorystage0 u_wrapper_memory0 wrap_load_out", false,-1, 31,0);
        tracep->declBus(c+120,"core u_Core10 u_Writeback_stage0 DataWidth", false,-1, 31,0);
        tracep->declBus(c+64,"core u_Core10 u_Writeback_stage0 mem_to_reg", false,-1, 1,0);
        tracep->declBus(c+47,"core u_Core10 u_Writeback_stage0 alu_out", false,-1, 31,0);
        tracep->declBus(c+96,"core u_Core10 u_Writeback_stage0 data_mem_out", false,-1, 31,0);
        tracep->declBus(c+51,"core u_Core10 u_Writeback_stage0 next_sel_address", false,-1, 31,0);
        tracep->declBus(c+118,"core u_Core10 u_Writeback_stage0 rd_mux_out", false,-1, 31,0);
        tracep->declBus(c+125,"core u_data_memory0 INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+113,"core u_data_memory0 clk", false,-1);
        tracep->declBit(c+114,"core u_data_memory0 rst", false,-1);
        tracep->declBit(c+95,"core u_data_memory0 we_re", false,-1);
        tracep->declBit(c+94,"core u_data_memory0 request", false,-1);
        tracep->declBit(c+88,"core u_data_memory0 load", false,-1);
        tracep->declBus(c+49,"core u_data_memory0 mask", false,-1, 3,0);
        tracep->declBus(c+81,"core u_data_memory0 address", false,-1, 7,0);
        tracep->declBus(c+48,"core u_data_memory0 data_in", false,-1, 31,0);
        tracep->declBit(c+83,"core u_data_memory0 valid", false,-1);
        tracep->declBus(c+1,"core u_data_memory0 data_out", false,-1, 31,0);
        tracep->declBus(c+125,"core u_data_memory0 u_memory INIT_MEM", false,-1, 31,0);
        tracep->declBit(c+113,"core u_data_memory0 u_memory clk", false,-1);
        tracep->declBit(c+95,"core u_data_memory0 u_memory we_re", false,-1);
        tracep->declBit(c+94,"core u_data_memory0 u_memory request", false,-1);
        tracep->declBus(c+81,"core u_data_memory0 u_memory address", false,-1, 7,0);
        tracep->declBus(c+48,"core u_data_memory0 u_memory data_in", false,-1, 31,0);
        tracep->declBus(c+49,"core u_data_memory0 u_memory mask", false,-1, 3,0);
        tracep->declBus(c+1,"core u_data_memory0 u_memory data_out", false,-1, 31,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->core__DOT__DM_load_data_in),32);
        tracep->fullIData(oldp+2,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__pre_address),32);
        tracep->fullIData(oldp+3,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__opb_data),32);
        tracep->fullIData(oldp+4,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__opb_mux),32);
        tracep->fullIData(oldp+5,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__opa_mux),32);
        tracep->fullCData(oldp+6,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__alu_con),4);
        tracep->fullBit(oldp+7,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__me));
        tracep->fullBit(oldp+8,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__store));
        tracep->fullBit(oldp+9,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__men));
        tracep->fullBit(oldp+10,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__s));
        tracep->fullCData(oldp+11,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__r1),5);
        tracep->fullCData(oldp+12,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__r2),5);
        tracep->fullBit(oldp+13,(vlTOPp->core__DOT__valid));
        tracep->fullIData(oldp+14,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[0]),32);
        tracep->fullIData(oldp+15,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[1]),32);
        tracep->fullIData(oldp+16,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[2]),32);
        tracep->fullIData(oldp+17,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[3]),32);
        tracep->fullIData(oldp+18,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[4]),32);
        tracep->fullIData(oldp+19,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[5]),32);
        tracep->fullIData(oldp+20,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[6]),32);
        tracep->fullIData(oldp+21,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[7]),32);
        tracep->fullIData(oldp+22,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[8]),32);
        tracep->fullIData(oldp+23,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[9]),32);
        tracep->fullIData(oldp+24,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[10]),32);
        tracep->fullIData(oldp+25,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[11]),32);
        tracep->fullIData(oldp+26,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[12]),32);
        tracep->fullIData(oldp+27,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[13]),32);
        tracep->fullIData(oldp+28,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[14]),32);
        tracep->fullIData(oldp+29,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[15]),32);
        tracep->fullIData(oldp+30,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[16]),32);
        tracep->fullIData(oldp+31,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[17]),32);
        tracep->fullIData(oldp+32,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[18]),32);
        tracep->fullIData(oldp+33,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[19]),32);
        tracep->fullIData(oldp+34,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[20]),32);
        tracep->fullIData(oldp+35,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[21]),32);
        tracep->fullIData(oldp+36,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[22]),32);
        tracep->fullIData(oldp+37,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[23]),32);
        tracep->fullIData(oldp+38,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[24]),32);
        tracep->fullIData(oldp+39,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[25]),32);
        tracep->fullIData(oldp+40,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[26]),32);
        tracep->fullIData(oldp+41,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[27]),32);
        tracep->fullIData(oldp+42,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[28]),32);
        tracep->fullIData(oldp+43,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[29]),32);
        tracep->fullIData(oldp+44,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__register[30]),32);
        tracep->fullIData(oldp+45,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_registerfile0__DOT__i),32);
        tracep->fullIData(oldp+46,(vlTOPp->core__DOT__instruction_o),32);
        tracep->fullIData(oldp+47,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result),32);
        tracep->fullIData(oldp+48,(vlTOPp->core__DOT__DM_store_data_out),32);
        tracep->fullCData(oldp+49,(vlTOPp->core__DOT__data_mem_mask),4);
        tracep->fullIData(oldp+50,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction),32);
        tracep->fullIData(oldp+51,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__nextsel_addr),32);
        tracep->fullIData(oldp+52,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__pre_address),32);
        tracep->fullIData(oldp+53,(((IData)(4U) + vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__pre_address)),32);
        tracep->fullIData(oldp+54,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__instruct),32);
        tracep->fullIData(oldp+55,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc),32);
        tracep->fullIData(oldp+56,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address),32);
        tracep->fullBit(oldp+57,(((0U == vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction)
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+58,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__reg_write));
        tracep->fullBit(oldp+59,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__rg));
        tracep->fullBit(oldp+60,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__branch_));
        tracep->fullBit(oldp+61,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__nextsel));
        tracep->fullBit(oldp+62,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__jalr));
        tracep->fullBit(oldp+63,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__branch_res));
        tracep->fullCData(oldp+64,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg),2);
        tracep->fullCData(oldp+65,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__mem_reg),2);
        tracep->fullCData(oldp+66,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+67,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+68,((0x1fU & (vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction 
                                             >> 7U))),5);
        tracep->fullBit(oldp+69,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline));
        tracep->fullBit(oldp+70,(vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__flush_pipeline2));
        tracep->fullIData(oldp+71,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (0xfffU 
                                                   & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                                      >> 0x14U)))),32);
        tracep->fullIData(oldp+72,(((0xfffff000U & 
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
        tracep->fullIData(oldp+73,(((0xffffe000U & 
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
        tracep->fullIData(oldp+74,(((0xffe00000U & 
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
        tracep->fullIData(oldp+75,((0xfffff000U & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)),32);
        tracep->fullBit(oldp+76,((1U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                        >> 0x1eU))));
        tracep->fullCData(oldp+77,((7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+78,((0x7fU & vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__instruc)),7);
        tracep->fullCData(oldp+79,((7U & (vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__instruction 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+80,((3U & vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result)),2);
        tracep->fullCData(oldp+81,((0xffU & (vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result 
                                             >> 2U))),8);
        tracep->fullIData(oldp+82,(vlTOPp->core__DOT__pc_address),32);
        tracep->fullBit(oldp+83,(vlTOPp->core__DOT__data_mem_valid));
        tracep->fullCData(oldp+84,((0xffU & (vlTOPp->core__DOT__pc_address 
                                             >> 2U))),8);
        tracep->fullIData(oldp+85,(vlTOPp->core__DOT__u_Core10__DOT__pre_pc),32);
        tracep->fullIData(oldp+86,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a),32);
        tracep->fullIData(oldp+87,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b),32);
        tracep->fullBit(oldp+88,(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__load));
        tracep->fullIData(oldp+89,(vlTOPp->core__DOT__u_Core10__DOT__alu_in_b),32);
        tracep->fullIData(oldp+90,(vlTOPp->core__DOT__u_Core10__DOT__alu_in_a),32);
        tracep->fullIData(oldp+91,(vlTOPp->core__DOT__u_Core10__DOT__alu_res_out),32);
        tracep->fullBit(oldp+92,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_pipe0__DOT__l));
        tracep->fullBit(oldp+93,(vlTOPp->core__DOT__instruction_mem_request));
        tracep->fullBit(oldp+94,(vlTOPp->core__DOT__data_mem_request));
        tracep->fullBit(oldp+95,(vlTOPp->core__DOT__data_mem_we_re));
        tracep->fullIData(oldp+96,(vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out),32);
        tracep->fullCData(oldp+97,(vlTOPp->core__DOT__u_Core10__DOT__alu_control),4);
        tracep->fullBit(oldp+98,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr));
        tracep->fullBit(oldp+99,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal));
        tracep->fullBit(oldp+100,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load));
        tracep->fullBit(oldp+101,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store));
        tracep->fullBit(oldp+102,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch));
        tracep->fullBit(oldp+103,(vlTOPp->core__DOT__u_Core10__DOT__branch_result));
        tracep->fullCData(oldp+104,(vlTOPp->core__DOT__u_Core10__DOT__mem_to_reg),2);
        tracep->fullBit(oldp+105,(((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                    ? 1U : 0U)));
        tracep->fullBit(oldp+106,((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                                          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                    ? 1U : 0U)));
        tracep->fullCData(oldp+107,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_sel),3);
        tracep->fullIData(oldp+108,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out),32);
        tracep->fullBit(oldp+109,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type));
        tracep->fullBit(oldp+110,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type));
        tracep->fullBit(oldp+111,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui));
        tracep->fullBit(oldp+112,(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc));
        tracep->fullBit(oldp+113,(vlTOPp->clk));
        tracep->fullBit(oldp+114,(vlTOPp->rst));
        tracep->fullIData(oldp+115,(vlTOPp->instruction),32);
        tracep->fullIData(oldp+116,(((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type) 
                                             | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                            | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__store)) 
                                           | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch)) 
                                          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                       ? 1U : 0U) ? vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__imm_mux_out
                                      : vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_b)),32);
        tracep->fullIData(oldp+117,((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__branch) 
                                        | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                       ? 1U : 0U) ? vlTOPp->core__DOT__u_Core10__DOT__u_Fetch_pipe0__DOT__pre_address
                                      : vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__op_a)),32);
        tracep->fullIData(oldp+118,(((0U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg))
                                      ? vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__alu_result
                                      : ((1U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg))
                                          ? vlTOPp->core__DOT__u_Core10__DOT__wrap_load_out
                                          : ((2U == (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__mem_reg))
                                              ? vlTOPp->core__DOT__u_Core10__DOT__u_Execute_pipe0__DOT__nextsel_addr
                                              : 0U)))),32);
        tracep->fullBit(oldp+119,((((((((((IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__r_type) 
                                          | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__i_type)) 
                                         | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__load)) 
                                        | (IData)(vlTOPp->core__DOT__data_mem_valid)) 
                                       | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jal)) 
                                      | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__jalr)) 
                                     | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__lui)) 
                                    | (IData)(vlTOPp->core__DOT__u_Core10__DOT__u_Decode_stage0__DOT__u_cu0__DOT__auipc))
                                    ? 1U : 0U)));
        tracep->fullIData(oldp+120,(0x20U),32);
        tracep->fullBit(oldp+121,(0U));
        tracep->fullCData(oldp+122,(0xfU),4);
        tracep->fullIData(oldp+123,(1U),32);
        tracep->fullIData(oldp+124,(4U),32);
        tracep->fullIData(oldp+125,(0U),32);
        tracep->fullIData(oldp+126,(3U),32);
        tracep->fullIData(oldp+127,(7U),32);
        tracep->fullIData(oldp+128,(5U),32);
    }
}
