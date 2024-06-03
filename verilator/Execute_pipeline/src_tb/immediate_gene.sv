// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 06:29:35 AM
// Design Name: 
// Module Name: immediate_gene
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


module immediate_gene #
(parameter INSTRUCTION=32
)
(
/* verilator lint_off UNUSED */
    input        [INSTRUCTION-1:0]   instruction,
    output logic [INSTRUCTION-1:0]   i_imme,
    output logic [INSTRUCTION-1:0]   s_imme,
    output logic [INSTRUCTION-1:0]   sb_imme,
    output logic [INSTRUCTION-1:0]   uj_imme,
    output logic [INSTRUCTION-1:0]   u_imme
);

    always_comb begin
/* verilator lint_off UNUSED */

        i_imme  = {{20{instruction[31]}}, instruction[31:20]};
        s_imme  = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
        sb_imme = {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8],1'b0};
        uj_imme = {{11{instruction[31]}}, instruction[31], instruction[19:12],instruction[20], instruction[30:21],1'b0};
        u_imme  = {{instruction[31:12]},12'b0};       
    end
endmodule
