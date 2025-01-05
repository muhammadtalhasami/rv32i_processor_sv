// `timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2024 06:15:50 AM
// Design Name: 
// Module Name: control_unit
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


module control_unit# 
(
parameter FUNCTION3 =3,
parameter OPCODE=7,
parameter ALU_CONTROL=4
)
(
    input logic fun7,
    input logic DM_valid,
    input logic [FUNCTION3-1 : 0] fun3,
    input logic [OPCODE-1 : 0] opcode_i,

    output logic mem_en,
    output logic Load,
    output logic Store,
    output logic Branch,
    output logic next_sel,
    output logic Jalr,
    output logic reg_write_o,
    output logic operand_a_o,
    output logic operand_b_o,
    output logic [2 : 0] imm_sel,
    output logic [1 : 0] mem_to_reg,
    output logic [ALU_CONTROL-1 : 0] alu_control
);
    logic r_type;
    logic i_type;
    logic store;
    logic load;
    logic branch;
    logic jal;
    logic jalr; 
    logic lui;
    logic auipc;   
    /////////////////////////////////////////////////////////////////////////////////
    //--------------------------------TYPE DECODER-----------------------------------
    /////////////////////////////////////////////////////////////////////////////////
    always_comb begin
      r_type    = (opcode_i == 7'b0110011) ? 1 : 0;
      i_type    = (opcode_i == 7'b0010011) ? 1 : 0;      
      store     = (opcode_i == 7'b0100011) ? 1 : 0; 
      load      = (opcode_i == 7'b0000011) ? 1 : 0;
      branch    = (opcode_i == 7'b1100011) ? 1 : 0;
      jal       = (opcode_i == 7'b1101111) ? 1 : 0;
      jalr      = (opcode_i == 7'b1100111) ? 1 : 0;
      lui       = (opcode_i == 7'b0110111) ? 1 : 0;
      auipc     = (opcode_i == 7'b0010111) ? 1 : 0;
      if(opcode_i==7'b0000011)begin
           if (DM_valid) begin 
                load = 1'b0;
            end
            else begin
                load = 1'b1;
            end
        end
    end
    /////////////////////////////////////////////////////////////////////////////////
    //------------------------------CONTROL DECODER----------------------------------
    /////////////////////////////////////////////////////////////////////////////////
    always_comb begin
        if(r_type)begin //rtype
            alu_control = (fun3==3'b000 & fun7==0) ? 4'b0000 : 
                          (fun3==3'b000 & fun7==1) ? 4'b0001 : 
                          (fun3==3'b001 & fun7==0) ? 4'b0010 : 
                          (fun3==3'b010 & fun7==0) ? 4'b0011 : 
                          (fun3==3'b011 & fun7==0) ? 4'b0100 : 
                          (fun3==3'b100 & fun7==0) ? 4'b0101 : 
                          (fun3==3'b101 & fun7==0) ? 4'b0110 : 
                          (fun3==3'b101 & fun7==1) ? 4'b0111 : 
                          (fun3==3'b110 & fun7==0) ? 4'b1000 : 
                          (fun3==3'b111 & fun7==0) ? 4'b1001 : 0;
        end
        else if (i_type)begin //itype
            alu_control = (fun3==3'b000 & fun7==0) ? 4'b0000 : 
                          (fun3==3'b001 & fun7==0) ? 4'b0010 : 
                          (fun3==3'b010 & fun7==0) ? 4'b0011 : 
                          (fun3==3'b011 & fun7==0) ? 4'b0100 : 
                          (fun3==3'b100 & fun7==0) ? 4'b0101 : 
                          (fun3==3'b101 & fun7==0) ? 4'b0110 : 
                          (fun3==3'b101 & fun7==1) ? 4'b0111 : 
                          (fun3==3'b110 & fun7==0) ? 4'b1000 : 
                          (fun3==3'b111 & fun7==0) ? 4'b1001 : 0 ;
        end
        else if (store) begin //store
            alu_control = (fun3==3'b000) ? 4'b0000 : 
                          (fun3==3'b001) ? 4'b0000 : 
                          (fun3==3'b010) ? 4'b0000 : 0;
        end
          else if (load) begin
            alu_control = (fun3==3'b000) ? 4'b0000 : 
                          (fun3==3'b001) ? 4'b0000 : 
                          (fun3==3'b010) ? 4'b0000 : 
                          (fun3==3'b100) ? 4'b0000 : 
                          (fun3==3'b101) ? 4'b0000 : 
                          (fun3==3'b110) ? 4'b0000 : 0;
        end
        else begin
            alu_control = (branch | jal |jalr |auipc)   ? 4'b0000 : 
                          (lui)                         ? 4'b1111 : 0;
        end
    end

    assign reg_write_o  = (r_type | i_type | load |DM_valid | jal | jalr | lui  | auipc) ? 1 :0;  //reg write signal for register file
    assign operand_a_o  = (branch | jal  |auipc) ? 1 : 0;         //operand a select for first input of alu
    assign operand_b_o  = (i_type | load | store |branch | jal | jalr | lui | auipc) ? 1 : 0 ;        //operand b signal for second input of alu
    assign Load         = load;          //load
    assign Store        = store;         //store
    assign mem_en       = store;
    assign Branch       =  branch;
    assign next_sel     =  jal;             //selection for next address if any jump instrucion run
    assign Jalr         = jalr;

    assign mem_to_reg   = (r_type | i_type |store |branch |jalr| lui|auipc)     ? 2'b00 :
                          (load)                                                ? 2'b01 :
                          (jal)                                                 ? 2'b10 : 0;
    //immediate selection logic
    assign imm_sel      =(i_type | load |jalr)          ?  3'b000  :
                         (store)                        ?  3'b001  :
                         (branch)                       ?  3'b010  :
                         (jal)                          ?  3'b011  :  
                         (lui|auipc)                    ?  3'b100  : 0 ; 


endmodule