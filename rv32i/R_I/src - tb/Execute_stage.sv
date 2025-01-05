// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 07:04:58 AM
// Design Name: 
// Module Name: Execute_stage
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


module Execute_stage#
(
parameter DATA_WIDTH =32,
parameter ALU_CONTROL=4
)
(
    input  [DATA_WIDTH-1:0] a_i,
    input  [DATA_WIDTH-1:0] b_i,
    input  [ALU_CONTROL-1:0]  alu_control,
    
    output logic [DATA_WIDTH-1:0] alu_res_out
);
    // ALU
    alu u_alu0 
    (
        .a_i(a_i),
        .b_i(b_i),
        .op_i(alu_control),
        .res_o(alu_res_out)
    );
endmodule
