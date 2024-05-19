// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 06:11:56 AM
// Design Name: 
// Module Name: alu
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


module alu #(parameter DATA_WIDTH = 32) 
    (
    input               [DATA_WIDTH-1:0]    a_i,
    input               [DATA_WIDTH-1:0]    b_i,
    input               [DATA_WIDTH-29:0]   op_i,

    output  logic       [DATA_WIDTH-1:0]    res_o
    );
    always_comb begin
        res_o = (op_i==4'b0000)?a_i + b_i : // add
                (op_i==4'b0001) ? a_i - b_i  :// sub
                (op_i==4'b0010) ? a_i << b_i : // shift left logical 
        (op_i==4'b0011 & ($signed(a_i) < $signed(b_i))) ? 1 : // set less then signed
                (op_i==4'b0100 & (a_i < b_i)) ? 1 :  //set less then unsigned 4        
                (op_i==4'b0101) ? a_i ^ b_i  : //xor
                (op_i==4'b0110) ? a_i >> b_i : //shift right logical
                (op_i==4'b0111) ? a_i >>> b_i: //shift right arithematic
                (op_i==4'b1000) ? a_i | b_i  : //or
                (op_i==4'b1001) ? a_i & b_i  : 0; //and          
            end
endmodule
