module Memory_pipe(
  input clk,
  input reg_write_in,
  input [1:0]  mem_reg_in,
  input [31:0] wrap_load_in,
  input [31:0] alu_res,
  input [31:0] next_sel_addr,
  input [31:0] instruction_in,
  input [31:0] pre_address_in,

  output logic reg_write_mem_pp,
  output logic [31:0] alu_res_mem_pp,
  output logic [1:0]  mem_reg_mem_pp,
  output logic [31:0] next_sel_address_mem_pp,
  output logic [31:0] wrap_load_mem_pp,
  output logic [31:0] instruction_mem_pp,
  output logic [31:0] pre_address_mem_pp
  );

  logic reg_write;
  logic [1:0]  mem_reg;
  logic [31:0] pre_address_pc;
  logic [31:0] alu_result , nextsel_addr , wrap_load , instruction;

  always_ff@ (posedge clk) begin
    mem_reg        <= mem_reg_in;
    alu_result     <= alu_res;
    nextsel_addr   <= next_sel_addr;
    wrap_load      <= wrap_load_in;
    instruction    <= instruction_in;
    reg_write      <= reg_write_in;
    pre_address_pc <= pre_address_in;
  end

  assign reg_write_mem_pp    = reg_write;
  assign mem_reg_mem_pp      = mem_reg;
  assign alu_res_mem_pp      = alu_result;
  assign next_sel_address_mem_pp = nextsel_addr;
  assign wrap_load_mem_pp    = wrap_load;
  assign instruction_mem_pp  = instruction;
  assign pre_address_mem_pp  = pre_address_pc;
endmodule