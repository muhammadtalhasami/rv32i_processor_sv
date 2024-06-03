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
input                                   instruction_mem_valid,
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
/* verilator lint_off UNUSED */
logic [DATA_WIDTH-1:0] alu_in_b,alu_in_a,alu_res_out_execute_pp,instruction_out_execute_pp,pre_address_out_execute_pp,next_sel_address_execute_pp,op_b_execute_pp,opb_mux_out_decode_pp,opa_mux_out_decode_pp,pc_decode_pp,next_sel_address,opb_mux_out,opa_mux_out,rd_wb_data;
/* verilator lint_off UNUSED */
logic [INSTRUCTION-1:0]instruction_decode_pp,instruction_fetch_pp,pre_pc_fetch_pp,pre_pc,instruction_out,wrap_load_out,alu_res_out;
logic [ALU_CONTROL-1:0] alu_control_decode_pp,alu_control;
logic flush,mem_en_execute_pp,store_out_execute_pp,load_out_execute_pp,reg_write_execute_pp,decode_reg_write_pp,reg_write,Branch_decode_pp,next_sel_decode_pp,Jalr_decode_pp,branch_result_decode_pp,mem_en_decode_pp,Store_decode_pp,Load_decode_pp,Jalr,next_sel,Load,Store,mem_en,Branch,branch_result;
logic [1:0]mem_reg_out_execute_pp,mem_to_reg,mem_to_reg_decode_pp;
logic [4:0]rs1_decode_pp,rs2_decode_pp,rs1_decode,rs2_decode;
logic [4:0]rd_execute;


Fetch_stage u_Fetch_stage0
(
.clk(clk),
.rst(rst),
.address_in(0),   
.DM_valid(DM_valid),
.pc_addr_out(address_out),
.load(Load),
.branch(Branch_decode_pp),
.branch_result(branch_result_decode_pp),
.next_address(alu_res_out),
.next_sel(next_sel_decode_pp),
.Jalr(Jalr_decode_pp),
/* verilator lint_off UNUSED */
.pre_pc(pre_pc),
.instruction_fetch(instruction),
.instruction(instruction_out),
.request(instruction_mem_request),
.we_re(instruction_mem_we_re),
.mask(instruction_mem_mask)
);

//FETCH STAGE PIPELINE
Fetch_pipe u_Fetch_pipe0(
    .clk(clk),
    .Jalr(Jalr),
    .load(Load),
    .next_select(next_sel),
    .branch_result(Branch),
    .pre_address_fetch(pre_pc),
    .instruction_fetch(instruction_out),
    .pre_pc_fetch_pp(pre_pc_fetch_pp),
    .instruction_fetch_pp(instruction_fetch_pp)
);

Decode_stage u_Decode_stage0
(
.clk(clk),
.rst(rst),
.DM_valid(DM_valid),
.instruction(instruction_fetch_pp),
.pc(pre_pc_fetch_pp),
.rwd_data_out(rd_wb_data),
.Load(Load),
.decode_reg_write_pp(reg_write_execute_pp),
.reg_write(reg_write),
.decode_ppload(Load_decode_pp),
.Store(Store),
.Branch(Branch),
.branch_result(branch_result),
.next_sel(next_sel),
.Jalr(Jalr),
.rs1(rs1_decode),
.rs2(rs2_decode),
.alu_control(alu_control),
.opb_mux_out(opb_mux_out),
.mem_to_reg(mem_to_reg),
.mem_en(mem_en),
.instruction_rd(instruction_out_execute_pp),
.opa_mux_out(opa_mux_out)
);

//decode_pipeline
Decode_pipe u_Decode_pipe0
(
.clk(clk),
// .rst(rst),
.instruction(instruction_fetch_pp),
.pc(pre_pc_fetch_pp),
.alu_control(alu_control),
.opa_mux_out(opa_mux_out),
.opb_mux_out(opb_mux_out),
.Load(Load),
.reg_write(reg_write),
.decode_reg_write_pp(decode_reg_write_pp),
.Store(Store),
.rs1(rs1_decode),
.rs2(rs2_decode),
.Branch(Branch),
.next_sel(next_sel),
.Jalr(Jalr),
.branch_result(branch_result),
.mem_to_reg(mem_to_reg),
.mem_en(mem_en),
.instruction_decode_pp(instruction_decode_pp),
.pc_decode_pp(pc_decode_pp),
.alu_control_decode_pp(alu_control_decode_pp),
.opa_mux_out_decode_pp(opa_mux_out_decode_pp),
.opb_mux_out_decode_pp(opb_mux_out_decode_pp),
.rs1_decode_pp(rs1_decode_pp),
.rs2_decode_pp(rs2_decode_pp),
.Load_decode_pp(Load_decode_pp),
.Store_decode_pp(Store_decode_pp),
.Branch_decode_pp(Branch_decode_pp),
.next_sel_decode_pp(next_sel_decode_pp),
.Jalr_decode_pp(Jalr_decode_pp),
.branch_result_decode_pp(branch_result_decode_pp),
.mem_to_reg_decode_pp(mem_to_reg_decode_pp),
.mem_en_decode_pp(mem_en_decode_pp)
);

assign rd_execute = instruction_out_execute_pp[11:7];

always_comb begin
    if(Load_decode_pp | flush)begin
        alu_in_a = opa_mux_out_decode_pp;
        alu_in_b = opb_mux_out_decode_pp;
    end
    else begin
        alu_in_a =(rs1_decode_pp == rd_execute)?  alu_res_out_execute_pp : opa_mux_out_decode_pp;
        alu_in_b = (rs2_decode_pp == rd_execute)?alu_res_out_execute_pp : opb_mux_out_decode_pp;
    end
end    

Execute_stage u_Execute_stage0 
(
.a_i(alu_in_a),
.b_i(alu_in_b),
.pc_address(pc_decode_pp),
.alu_control(alu_control_decode_pp),
.next_sel_address(next_sel_address),
.alu_res_out(alu_res_out)
);

    //EXECUTE STAGE PIPELINE
Execute_pipe u_Execute_pipe0(
        .clk(clk),
        .load_in(Load_decode_pp),
        .store_in(Store_decode_pp),
        .op_b_execute(opb_mux_out_decode_pp),
        .alu_res(alu_res_out),
        .mem_reg_in(mem_to_reg_decode_pp),
        .next_sel_addr(next_sel_address),
        .pre_address_in(pc_decode_pp),
        .mem_en(mem_en_decode_pp),
        .instruction_in(instruction_decode_pp),
        .reg_write_in(decode_reg_write_pp),
        .reg_write_execute_pp(reg_write_execute_pp),
        .load_out_execute_pp(load_out_execute_pp),
        .store_out_execute_pp(store_out_execute_pp),
        .alu_res_out_execute_pp(alu_res_out_execute_pp),
        .mem_reg_out_execute_pp(mem_reg_out_execute_pp),
        .mem_en_execute_pp(mem_en_execute_pp),
        .op_b_execute_pp(op_b_execute_pp),
        .next_sel_address_execute_pp(next_sel_address_execute_pp),
        .pre_address_out_execute_pp(pre_address_out_execute_pp),
        .instruction_out_execute_pp(instruction_out_execute_pp)
    );

    assign flush = (instruction_out_execute_pp == 32'b0) ? 1 : 0;

//MEMORY STAGE
Memory_stage u_memorystage0
(
        .load(load_out_execute_pp),
        .store(store_out_execute_pp),
        .mem_en(mem_en_execute_pp),
        .operand_b(op_b_execute_pp),
        .instruction(instruction_out_execute_pp),
        .alu_out_address(alu_res_out_execute_pp),
        .wrap_load_in(DM_load_data_in),
        .mask(data_mem_mask),
        .data_valid(DM_valid),
        .valid(instruction_mem_valid),
        .we_re(data_mem_we_re),
        .request(data_mem_request),
        .store_data_out(DM_store_data_out),
        .wrap_load_out(wrap_load_out)
);

Writeback_stage u_Writeback_stage0
    (
        .mem_to_reg(mem_reg_out_execute_pp),
        .alu_out(alu_res_out_execute_pp),
        .data_mem_out(wrap_load_out),
        .next_sel_address(next_sel_address_execute_pp),
        .rd_mux_out(rd_wb_data)
    );

assign DM_alu_res_out = alu_res_out_execute_pp;
assign DM_Load        = load_out_execute_pp;
endmodule
