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
// input                                   instruction_mem_valid,
input           [31:0]                  DM_load_data_in,
input                                   DM_valid,

output logic    [ADDRESS-1:0]           address_out,
output logic                            DM_Load,
output logic                            instruction_mem_request,
output logic                            instruction_mem_we_re,
output logic    [3:0]                   instruction_mem_mask,
output logic                            data_mem_request,
output logic                            data_mem_we_re,
output logic    [3:0]                   data_mem_mask,
output logic    [31:0]                  DM_store_data_out,
output logic    [31:0]                  DM_alu_res_out

);
logic [DATA_WIDTH-1:0] next_sel_address,opb_mux_out,opa_mux_out,rd_wb_data;
/* verilator lint_off UNUSED */
logic [INSTRUCTION-1:0]pre_pc,instruction_out,wrap_load_out,alu_res_out;
logic [ALU_CONTROL-1:0] alu_control;
logic Jalr,next_sel,Load,Store,mem_en,Branch,branch_result;
logic [1:0]mem_to_reg;

Fetch_stage u_Fetch_stage0
(
.clk(clk),
.rst(rst),
.address_in(0),   
.DM_valid(DM_valid),
.pc_addr_out(address_out),
.load(Load),
.branch(Branch),
.branch_result(branch_result),
.next_address(alu_res_out),
.next_sel(next_sel),
.Jalr(Jalr),
/* verilator lint_off UNUSED */
.pre_pc(pre_pc),
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
.DM_valid(DM_valid),
.instruction(instruction_out),
.pc(pre_pc),
.rwd_data_out(rd_wb_data),
.Load(Load),
.Store(Store),
.Branch(Branch),
.branch_result(branch_result),
.next_sel(next_sel),
.Jalr(Jalr),
.alu_control(alu_control),
.opb_mux_out(opb_mux_out),
.mem_to_reg(mem_to_reg),
.mem_en(mem_en),
.opa_mux_out(opa_mux_out)
);

Execute_stage u_Execute_stage0 
(
.a_i(opa_mux_out),
.b_i(opb_mux_out),
.pc_address(pre_pc),
.alu_control(alu_control),
.next_sel_address(next_sel_address),
.alu_res_out(alu_res_out)
);

//MEMORY STAGE
Memory_stage u_memorystage0
(
        .load(Load),
        .store(Store),
        .mem_en(mem_en),
        .operand_b(opb_mux_out),
        .instruction(instruction_out),
        .alu_out_address(alu_res_out),
        .wrap_load_in(DM_load_data_in),
        .mask(data_mem_mask),
        .data_valid(DM_valid),
        // .valid(instruction_mem_valid),
        .we_re(data_mem_we_re),
        .request(data_mem_request),
        .store_data_out(DM_store_data_out),
        .wrap_load_out(wrap_load_out)
);

Writeback_stage u_Writeback_stage0
    (
        .mem_to_reg(mem_to_reg),
        .alu_out(alu_res_out),
        .data_mem_out(wrap_load_out),
        .next_sel_address(next_sel_address),
        .rd_mux_out(rd_wb_data)
    );

assign DM_alu_res_out = alu_res_out;
assign DM_Load        = Load;
endmodule
