// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/11/2024 02:11:34 AM
// Design Name: 
// Module Name: memory
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


module memory#(
    parameter INIT_MEM = 0
)(
    input  clk,
    input  we_re,
    input  request,
    input  [7:0]address,
    input  [31:0]data_in,
    input  [3:0]mask,

    output logic [31:0]data_out
);

    logic [31:0] mem [0:255];

    initial begin
        if (INIT_MEM)
            $readmemh("instru.mem",mem);
    end

    always_ff@(posedge clk) begin
        if (request && we_re) begin
            if(mask[0]) begin
                mem[address][7:0] <= data_in[7:0];
            end
            if(mask[1]) begin
                mem[address][15:8] <= data_in[15:8];
            end
            if(mask[2]) begin
                mem[address][23:16] <= data_in[23:16];
            end
            if(mask[3]) begin
                mem[address][31:24] <= data_in[31:24];
            end
        end

        else if (request && !we_re) begin
            data_out <= mem[address];
        end
    end
endmodule