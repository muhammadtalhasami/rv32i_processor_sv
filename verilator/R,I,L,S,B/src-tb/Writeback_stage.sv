module Writeback_stage #(
    parameter DataWidth = 32
    )(
        input logic [1 : 0]  mem_to_reg,
        input logic [DataWidth-1 : 0] alu_out,
        input logic [DataWidth-1 : 0] data_mem_out,

        output logic [DataWidth-1 : 0] rd_mux_out
    );

    //Selection for Destination Register RD
    assign rd_mux_out =
                    (mem_to_reg == 2'b00) ? alu_out          :
                    (mem_to_reg == 2'b01) ? data_mem_out   :  0;
endmodule