module  Decode_pipe
#(
parameter DATA_WIDTH =32,
parameter INSTRUCTION=32,
parameter ALU_CONTROL=4
)
(
    input  clk,
    // input  rst,
    input [INSTRUCTION-1:0] instruction,
    input [DATA_WIDTH-1:0] pc,
    input [ALU_CONTROL-1:0] alu_control,
    input [DATA_WIDTH-1:0] opb_mux_out,
    input [DATA_WIDTH-1:0] opa_mux_out,
    input Load,
    input Store,
    input Branch,
    input next_sel,
    input Jalr,
    input branch_result,
    input [1:0]mem_to_reg,
    input mem_en,
    input reg_write,

    output logic [INSTRUCTION-1:0] instruction_decode_pp,
    output logic [DATA_WIDTH-1:0] pc_decode_pp,  
    output logic [ALU_CONTROL-1:0] alu_control_decode_pp,
    output logic [DATA_WIDTH-1:0] opb_mux_out_decode_pp,
    output logic [DATA_WIDTH-1:0] opa_mux_out_decode_pp,
    output logic Load_decode_pp,
    output logic decode_reg_write_pp,
    output logic Store_decode_pp,
    output logic Branch_decode_pp,
    output logic next_sel_decode_pp,
    output logic Jalr_decode_pp,
    output logic branch_result_decode_pp,
    output logic [1:0]mem_to_reg_decode_pp,
    output logic mem_en_decode_pp
 );

  logic rg,l,s,nextsel,branch_res,jalr,men,branch_;
  logic [1:0] mem_reg;
  logic [3:0] alu_con;
  logic [31:0] opa_mux,opb_mux,pre_address,instruct;

  always_ff@ (posedge clk) begin
    rg<=reg_write;
    l <= Load;
    s <= Store;
    jalr <= Jalr;
    nextsel <= next_sel;
    men<=mem_en;
    branch_<=Branch;
    branch_res <= branch_result;
    mem_reg <= mem_to_reg;
    alu_con <= alu_control;
    opa_mux <= opa_mux_out;
    opb_mux <= opb_mux_out;
    pre_address <= pc;
    instruct <= instruction;
  end

  assign decode_reg_write_pp = rg;
  assign Load_decode_pp = l;
  assign mem_en_decode_pp = men;
  assign Store_decode_pp = s;
  assign Branch_decode_pp = branch_;
  assign Jalr_decode_pp = jalr;
  assign next_sel_decode_pp = nextsel;
  assign branch_result_decode_pp = branch_res;
  assign mem_to_reg_decode_pp = mem_reg;
  assign alu_control_decode_pp = alu_con;
  assign opa_mux_out_decode_pp = opa_mux;
  assign opb_mux_out_decode_pp = opb_mux;
  assign instruction_decode_pp = instruct;
  assign pc_decode_pp = pre_address;
endmodule