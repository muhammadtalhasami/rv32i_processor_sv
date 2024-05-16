// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/11/2024 02:20:53 AM
// Design Name: 
// Module Name: data_memory_top
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


module data_mem_top #(
    parameter INIT_MEM = 0
)(
    input  clk,
    input  rst,
    input  we_re,
    input  request,
    input  load,
    input  [3:0]  mask,
    input  [7:0]  address,
    input  [31:0] data_in,

    output logic valid,
    output logic [31:0] data_out
    );

    always_ff @(posedge clk or negedge rst ) begin
        if(!rst)begin
            valid <= 0;
        end
        else begin
            valid <= load;
        end
    end

    memory #(
      .INIT_MEM(INIT_MEM)
    )u_memory(
        .clk(clk),
        .we_re(we_re),
        .request(request),
        .mask(mask),
        .address(address),
        .data_in(data_in),
        .data_out(data_out)
    );
endmodule
