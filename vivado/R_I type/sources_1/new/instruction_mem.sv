`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 07:00:57 AM
// Design Name: 
// Module Name: instruction_mem
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


module instruction_mem #
(parameter DataWidth = 32,
parameter  Addr =8,
parameter  Depth=256)
(
    input clk,
    input enable,
    input [Addr-1:0]address,
    input [DataWidth-1:0]data_in,

    output logic [DataWidth-1:0] data_out
);

    logic [DataWidth-1:0] mem [0:Depth-1];

    initial begin
        $readmemh("D:\Users\hp\single_cycle\instr",mem);
   end

   always_ff@(posedge clk) begin
        if(enable)begin
            mem[address]<=data_in;
        end
   end

   always_comb begin
        data_out = mem[address];
   end

endmodule
