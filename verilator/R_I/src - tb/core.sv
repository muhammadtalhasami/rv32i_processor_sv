// `timescale 1ns / 1ps
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
input [INSTRUCTION-1:0] instruction
);
/* verilator lint_off UNUSED */
logic [INSTRUCTION-1:0] pc_address,instruction_o;  
logic instruction_mem_we_re,instruction_mem_request,valid;
logic [3:0]instruction_mem_mask;
         // INSTRUCTION MEMORY
instruc_mem_top #(
    .INIT_MEM(1)
) u_instruc_mem_top0 (
    .clk(clk),
    .rst (rst),
    .we_re(instruction_mem_we_re),
    .request(instruction_mem_request),
    .valid(valid),
    .mask(instruction_mem_mask),
/* verilator lint_off UNUSED */
    .address(pc_address[9:2]),
    .data_in(instruction),
    .data_out(instruction_o) 
);

Core1 u_Core10(
.clk(clk),
.rst(rst), 
.instruction(instruction_o),
.address_out(pc_address),
.instruction_mem_request(instruction_mem_request),
.instruction_mem_we_re(instruction_mem_we_re),
.instruction_mem_mask(instruction_mem_mask)
);
endmodule
