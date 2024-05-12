`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 06:35:18 AM
// Design Name: 
// Module Name: pc
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


module pc #
(
parameter ADDRESS = 32 
)
(
    input                           clk,
    input                           rst,  
    input        [ADDRESS-1:0]    address_in,

    output logic [ADDRESS-1:0]    address_out
);

always_ff@(posedge clk or negedge rst) begin
    if(!rst)begin
        address_out <= 0;
    end
        else begin
        address_out <= address_out + 32'd4;
    end
end
endmodule
