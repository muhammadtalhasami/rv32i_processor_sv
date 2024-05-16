module Core1#(
parameter DATA_WIDTH =32,
parameter ADDRESS=32,
parameter INSTRUCTION=32,
parameter ALU_CONTROL=4
)
(
input                                   clk,
input                                   rst, 
input           [INSTRUCTION-1:0]       instruction,
output logic    [ADDRESS-1:0]           address_out,
output logic                            instruction_mem_request,
output logic                            instruction_mem_we_re,
output logic    [3:0]                   instruction_mem_mask

);
logic [DATA_WIDTH-1:0] alu_res_out,opb_mux_out,opa_mux_out;
logic [INSTRUCTION-1:0]instruction_out;
logic [ALU_CONTROL-1:0] alu_control;

Fetch_stage u_Fetch_stage0
(
.clk(clk),
.rst(rst),
.address_in(0),   
.pc_addr_out(address_out),
.instruction_fetch(instruction),
.instruction(instruction_out),
.request(instruction_mem_request),
.we_re(instruction_mem_we_re),
.mask(instruction_mem_mask)
);

Decode_stage u_Decode_stage0
(
.clk(clk),
.rst(rst),
.instruction(instruction_out),
.rwd_data_out(alu_res_out),
.alu_control(alu_control),
.opb_mux_out(opb_mux_out),
.opa_mux_out(opa_mux_out)
);

Execute_stage u_Execute_stage0 
(
.a_i(opa_mux_out),
.b_i(opb_mux_out),
.alu_control(alu_control),
.alu_res_out(alu_res_out)
);

endmodule
