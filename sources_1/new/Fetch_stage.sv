`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 07:04:23 AM
// Design Name: 
// Module Name: Fetch_stage
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


module Fetch_stage
#
(
parameter INSTRUCTION =32,
parameter ADDRESS=32
)
(
   input  clk,
   input  rst,
   input  [ADDRESS-1:0] address_in,
   input  [INSTRUCTION-1:0] instruction_fetch,
   
   output logic [INSTRUCTION-1:0] instruction,
   output logic [ADDRESS-1:0] pc_addr_out
   );
        // PROGRAM COUNTER
pc u_pc0 
(
    .clk(clk),
    .rst(rst),
    .address_in(0),
    .address_out(pc_addr_out)
);

    always_comb begin
        instruction = instruction_fetch ;
    end

endmodule
