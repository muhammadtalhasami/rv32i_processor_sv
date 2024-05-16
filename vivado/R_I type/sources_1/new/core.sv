`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 06:06:54 AM
// Design Name: 
// Module Name: core
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


module core#
(
parameter INSTRUCTION = 32
)
(
input                   clk,
input                   rst,
input                   en,
input [INSTRUCTION-1:0] instruction
);
 
logic [INSTRUCTION-1:0] pc_address,instruction_o;     
         // INSTRUCTION MEMORY
instruction_mem u_instruction_mem0 (
    .clk(clk),
    .enable(en),
    .address(pc_address[9:2]),
    .data_in(instruction),
    .data_out(instruction_o)
);

Core1 u_Core10(
.clk(clk),
.rst(en), 
.instruction(instruction_o),
.address_out(pc_address)
);
endmodule
