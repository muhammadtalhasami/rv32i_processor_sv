// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 07:02:29 AM
// Design Name: 
// Module Name: Decode_stage
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Decode_stage
#(
parameter DATA_WIDTH =32,
parameter INSTRUCTION=32,
parameter ALU_CONTROL=4
)
(
    input  clk,
    input  rst,
    input  [INSTRUCTION-1:0] instruction,
    input  [DATA_WIDTH-1:0] rwd_data_out,
    
    output logic [ALU_CONTROL-1:0] alu_control,
    output logic [DATA_WIDTH-1:0] opb_mux_out,
    output logic [DATA_WIDTH-1:0] opa_mux_out,
    output logic Load,
    output logic Store,
    output logic [1:0]mem_to_reg,
    output logic mem_en
);
    
logic [INSTRUCTION-1:0] i_imme,s_imme;
logic        reg_write,operand_b;
logic [DATA_WIDTH-1:0] op_a,op_b;
logic [2 : 0] imm_sel;
logic [INSTRUCTION-1:0]imm_mux_out;
           // IMMEDIATE GENERATOR
immediate_gene u_immediate_gene0 
(
.instruction(instruction),
.i_imme(i_imme),
.s_imme(s_imme)
);

assign imm_mux_out =
                    (imm_sel==3'b000) ? i_imme :
                    (imm_sel==3'b001) ? s_imme : 32'd0;
    // CONTROL UNIT
control_unit u_cu0 
(
.opcode_i(instruction[6:0]),
.fun3(instruction[14:12]),
.fun7(instruction[30]),
.reg_write_o(reg_write),
.operand_b_o(operand_b),
.mem_en(mem_en),
.imm_sel(imm_sel),
.mem_to_reg(mem_to_reg),
.Load(Load),
.Store(Store),
.alu_control(alu_control)
);

        // REGISTER FILE
register_file u_registerfile0 
(
    .clk(clk),
    .rst(rst),
    .en(reg_write),
    .rs1(instruction[19:15]),
    .rs2(instruction[24:20]),
    .rd(instruction[11:7]),
    .data(rwd_data_out),
    .op_a(op_a),
    .op_b(op_b)
);

assign opa_mux_out = op_a;
        // OPERAND B OR IMMEDIATE     
    assign opb_mux_out =
            (operand_b) ? imm_mux_out : op_b;
endmodule
