`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 11:56:07 AM
// Design Name: 
// Module Name: core_tb
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


module core_tb();
logic clk;
logic [31:0]instruction;
logic rst;
logic en;



    core u_core0
    (
        .clk(clk),
        .instruction(instruction),
        .rst(rst),
        .en(en)
    );

    initial begin
        clk = 0;
        rst = 0;
        #5;
        rst=1;
        en = 0;
        #10;

        rst = 1;
        #40;

        $finish;       
    end

    always begin
        #5 clk= ~clk;
    end
endmodule



