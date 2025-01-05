module Execute_pipe(
  input  clk,
  input  load_in,
  input  store_in,
  input  reg_write_in,
  input  mem_en,
  input  [31:0] op_b_execute,
  input  [31:0] alu_res,
  input  [1:0] mem_reg_in,
  input  [31:0] next_sel_addr,
  input  [31:0] pre_address_in,
  input  [31:0] instruction_in,

  output logic mem_en_execute_pp,
  output logic reg_write_execute_pp,
  output logic load_out_execute_pp,
  output logic store_out_execute_pp,
  output logic [31:0] op_b_execute_pp,
  output logic [31:0] alu_res_out_execute_pp,
  output logic [1:0] mem_reg_out_execute_pp,
  output logic [31:0] next_sel_address_execute_pp,
  output logic [31:0] pre_address_out_execute_pp,
  output logic [31:0] instruction_out_execute_pp
  );

  reg load , store , reg_write,me;
  reg [1:0] mem_reg;
  reg [31:0] alu_result , nextsel_addr;
  reg [31:0] pre_address , instruction , opb_data;

  always_ff@ (posedge clk) begin
    opb_data<=op_b_execute;
    me<=mem_en;
    load <= load_in;
    store <= store_in;
    mem_reg <= mem_reg_in;
    pre_address <= pre_address_in;
    instruction <= instruction_in;
    alu_result <= alu_res;
    nextsel_addr <= next_sel_addr;
    reg_write <= reg_write_in;
  end

  assign op_b_execute_pp = opb_data;
  assign mem_en_execute_pp = me;
  assign reg_write_execute_pp = reg_write;
  assign load_out_execute_pp = load;
  assign store_out_execute_pp = store;
  assign mem_reg_out_execute_pp = mem_reg;
  assign alu_res_out_execute_pp = alu_result;
  assign pre_address_out_execute_pp = pre_address;
  assign instruction_out_execute_pp = instruction;
  assign next_sel_address_execute_pp = nextsel_addr;
endmodule