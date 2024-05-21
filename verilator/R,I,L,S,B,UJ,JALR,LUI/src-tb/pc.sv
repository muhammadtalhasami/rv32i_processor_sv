// `timescale 1ns / 1ps
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
/* verilator lint_off UNUSED */ 
    input        [ADDRESS-1:0]    address_in,
    input        [ADDRESS-1:0]    next_address,
    input                         branch,
    input                         next_sel, 
    input                         Jalr,    
    input                         branch_result,

    output logic [ADDRESS-1:0]    address_out,
    output logic [ADDRESS-1:0]    pre_pc
);



always_ff@(posedge clk or negedge rst) begin
    if(!rst)begin
        address_out         <= 0;
        pre_pc              <= address_out;
    end
    else if (next_sel) begin
        address_out         <= next_address;
        pre_pc              <= address_out;
    end
    else if (branch) begin
        if (branch_result) begin
            address_out     <= next_address;
            pre_pc          <= address_out;
        end
    end
    else if (Jalr) begin
        address_out         <= next_address;
        pre_pc              <= address_out;
    end
    else begin
        address_out         <= address_out + 32'd4;
        pre_pc              <= address_out;
    end
end
endmodule
