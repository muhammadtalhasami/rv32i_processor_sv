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
    input                          clk,
    input                          rst,
    input                          load, 
    input                          DM_valid,
/* verilator lint_off UNUSED */   
    input        [ADDRESS-1:0]     address_in,

    output logic [ADDRESS-1:0]     address_out,
    output logic [ADDRESS-1:0]     pre_pc
);


always_ff @(posedge clk or negedge rst) begin
    if (!rst) begin
        address_out <= 0;
        pre_pc <= address_out;
    end
    else if (load && ~DM_valid) begin 
        address_out <= address_out;
        // No change in address_out, hold_add should remember pre_pc
        pre_pc <= pre_pc;
    end
    else begin
        address_out <= address_out + 32'd4;
        pre_pc <= address_out;
    end
end


endmodule
