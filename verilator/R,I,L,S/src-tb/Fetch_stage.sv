// `timescale 1ns / 1ps
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
   input                           load, 
   input                           DM_valid, 
/* verilator lint_off UNUSED */
   input  [ADDRESS-1:0] address_in,
   input  [INSTRUCTION-1:0] instruction_fetch,

   output logic request,
   output logic we_re,
   output logic [3:0]mask,
   output logic [INSTRUCTION-1:0] instruction,
   output logic [ADDRESS-1:0] pre_pc,
   output logic [ADDRESS-1:0] pc_addr_out
   );
        // PROGRAM COUNTER
pc u_pc0 
(
    .clk(clk),
    .rst(rst),
    .load(load), 
    .DM_valid(DM_valid), 
/* verilator lint_off UNUSED */
    .address_in(0),
    .pre_pc(pre_pc),
    .address_out(pc_addr_out)
);



    always_comb begin
        instruction = instruction_fetch ;
        if ((load && !DM_valid)) begin
            mask = 4'b1111; 
            we_re = 1'b0;
            request = 1'b0;
        end
        else begin
            mask = 4'b1111; 
            we_re = 1'b0;
            request = 1'b1;
        end
    end

endmodule
