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
parameter FUNCTION7=7,
parameter ALU_CONTROL=5
)
(
    /* verilator lint_off WIDTH */
    input logic [FUNCTION7-1:0]fun7,
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
            alu_control = (fun3==3'b000 & fun7==0000000) ? 5'b00000 : 
                          (fun3==3'b000 & fun7==0100000) ? 5'b00001 : 
                          (fun3==3'b001 & fun7==0000000) ? 5'b00010 : 
                          (fun3==3'b010 & fun7==0000000) ? 5'b00011 : 
                          (fun3==3'b011 & fun7==0000000) ? 5'b00100 : 
                          (fun3==3'b100 & fun7==0000000) ? 5'b00101 : 
                          (fun3==3'b101 & fun7==0000000) ? 5'b00110 : 
                          (fun3==3'b101 & fun7==0100000) ? 5'b00111 : 
                          (fun3==3'b110 & fun7==0000000) ? 5'b01000 : 
                          (fun3==3'b111 & fun7==0000000) ? 5'b01001 : 
                          //Multiply_Extension
                          (fun3==3'b000 & fun7==0000001) ? 5'b10000 : 
                          (fun3==3'b001 & fun7==0000001) ? 5'b10001 : 
                          (fun3==3'b010 & fun7==0000001) ? 5'b10010 : 
                          (fun3==3'b011 & fun7==0000001) ? 5'b10011 : 
                          (fun3==3'b100 & fun7==0000001) ? 5'b10100 : 
                          (fun3==3'b101 & fun7==0000001) ? 5'b10101 : 
                          (fun3==3'b110 & fun7==0000001) ? 5'b10110 : 
                          (fun3==3'b111 & fun7==0000001) ? 5'b10111 : 0;

                           
        end
        else if (i_type)begin //itype
            alu_control = (fun3==3'b000 & fun7==0000000) ? 5'b00000 : 
                          (fun3==3'b001 & fun7==0000000) ? 5'b00010 : 
                          (fun3==3'b010 & fun7==0000000) ? 5'b00011 : 
                          (fun3==3'b011 & fun7==0000000) ? 5'b00100 : 
                          (fun3==3'b100 & fun7==0000000) ? 5'b00101 : 
                          (fun3==3'b101 & fun7==0000000) ? 5'b00110 : 
                          (fun3==3'b101 & fun7==0100000) ? 5'b00111 : 
                          (fun3==3'b110 & fun7==0000000) ? 5'b01000 : 
                          (fun3==3'b111 & fun7==0000000) ? 5'b01001 : 0 ;
        end
        else if (store) begin //store
            alu_control = (fun3==3'b000) ? 5'b00000 : 
                          (fun3==3'b001) ? 5'b00000 : 
                          (fun3==3'b010) ? 5'b00000 : 0;
        end
          else if (load) begin
            alu_control = (fun3==3'b000) ? 5'b00000 : 
                          (fun3==3'b001) ? 5'b00000 : 
                          (fun3==3'b010) ? 5'b00000 : 
                          (fun3==3'b100) ? 5'b00000 : 
                          (fun3==3'b101) ? 5'b00000 : 
                          (fun3==3'b110) ? 5'b00000 : 0;
        end
        else begin
            alu_control = (branch | jal |jalr |auipc)   ? 5'b00000 : 
                          (lui)                         ? 5'b01111 : 0;
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
                          (load | DM_valid)                                                ? 2'b01 :
                          (jal)                                                 ? 2'b10 : 0;
    //immediate selection logic
    assign imm_sel      =(i_type | load |jalr)          ?  3'b000  :
                         (store)                        ?  3'b001  :
                         (branch)                       ?  3'b010  :
                         (jal)                          ?  3'b011  :  
                         (lui|auipc)                    ?  3'b100  : 0 ; 


endmodule