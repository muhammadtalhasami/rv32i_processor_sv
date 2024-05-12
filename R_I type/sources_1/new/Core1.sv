`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 11:15:53 AM
// Design Name: 
// Module Name: Core1
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


module Core1#(
parameter DATA_WIDTH =32,
parameter ADDRESS=32,
parameter INSTRUCTION=32,
parameter ALU_CONTROL=4
)
(
input                                   clk,
input                                   rst, 
input           [INSTRUCTION-1:0]       instruction,
output logic    [ADDRESS-1:0]           address_out

);
logic [DATA_WIDTH-1:0] alu_res_out,opb_mux_out,opa_mux_out;
logic [INSTRUCTION-1:0]instruction_out;
logic [ALU_CONTROL-1:0] alu_control;

Fetch_stage u_Fetch_stage0
(
.clk(clk),
.rst(rst),
.address_in(0),   
.pc_addr_out(address_out),
.instruction_fetch(instruction_out),
.instruction(instruction)
);

Decode_stage u_Decode_stage0
(
.clk(clk),
.rst(rst),
.instruction(instruction_out),
.rwd_data_out(alu_res_out),
.alu_control(alu_control),
.opb_mux_out(opb_mux_out),
.opa_mux_out(opa_mux_out)
);

Execute_stage u_Execute_stage0 
(
.a_i(opa_mux_out),
.b_i(opb_mux_out),
.alu_control(alu_control),
.alu_res_out(alu_res_out)
);

endmodule
