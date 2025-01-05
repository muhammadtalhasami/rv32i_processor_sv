// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 06:33:45 AM
// Design Name: 
// Module Name: register_file
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


module register_file #
(
    parameter Data_Width =   32,
    parameter AddrRegWidth = 5
)
(
    input                                  clk,
    input                                  rst,
    input                                  en,
    input        [AddrRegWidth-1:0]        rs1,
    input        [AddrRegWidth-1:0]        rs2,
    input        [AddrRegWidth-1:0]        rd,
    input        [Data_Width-1:0]          data,

    output logic [Data_Width-1:0]           op_a,
    output logic [Data_Width-1:0]           op_b
);

reg [Data_Width-1:0] register[Data_Width-1:1];
integer i;

always @(posedge clk or negedge rst) begin
    if(!rst)begin
        for (i=0; i<32; i++) begin
            register[i] <= 32'b0;
        end
    end
    else if(en)begin
        register[rd] <= data;
    end
end

assign op_a = (rs1 != 0)? register[rs1] : 0;
assign op_b = (rs2 != 0)? register[rs2] : 0;

endmodule
