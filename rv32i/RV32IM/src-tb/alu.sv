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
    input               [DATA_WIDTH-28:0]   op_i,

    output  logic       [DATA_WIDTH-1:0]    res_o
    );
/* verilator lint_off UNUSED */
    logic [63:0] mult_res;

    always_comb begin
        res_o = (op_i==5'b00000)?a_i + b_i : // add
                (op_i==5'b00001) ? a_i - b_i  :// sub
                (op_i==5'b00010) ? a_i << b_i : // shift left logical 
                (op_i==5'b00011 & ($signed(a_i) < $signed(b_i))) ? 1 :
                (op_i==5'b00100 & (a_i < b_i)) ? 1 :  //set less then unsigned 4        
                (op_i==5'b00101) ? a_i ^ b_i  : //xor
                (op_i==5'b00110) ? a_i >> b_i : //shift right logical
                (op_i==5'b00111) ? a_i >>> b_i: //shift right arithematic
                (op_i==5'b01000) ? a_i | b_i  : //or
                (op_i==5'b01001) ? a_i & b_i  :  //and
                (op_i==5'b01111) ? b_i  :        //lui   
                //  MUL5IPLY EXTENSION                
                (op_i==5'b10100)?   ($signed(a_i) / $signed(b_i)) :         //DIV
                (op_i==5'b10101)?   a_i / b_i :                             //DIVU
                (op_i==5'b10110)?   ($signed(a_i) % $signed(b_i)) :         //REM
                (op_i==5'b10111)?   a_i % b_i :  0;                         //REMU
                  
            if  (op_i==5'b10000)begin
                mult_res =(a_i * b_i);//MUL
                res_o = mult_res[31:0]; // mul - lower 32 bits
            end
            else if  (op_i==5'b10001)begin
                mult_res = ($signed(a_i) * $signed(b_i));//MULH
                res_o = mult_res[63:32]; // mulh - upper 32 bits
            end
            else if  (op_i==5'b10010)begin
                mult_res = ($signed(a_i) * b_i);//MULSU
                res_o = mult_res[63:32]; // mulh - upper 32 bits
            end  
            else if  (op_i==5'b10011)begin
                mult_res = (a_i * b_i);//MULU
                res_o = mult_res[63:32]; // mulh - upper 32 bits
            end           
            end
endmodule
