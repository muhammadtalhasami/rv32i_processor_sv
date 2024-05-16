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
    input logic [FUNCTION3-1 : 0] fun3,
    input logic [OPCODE-1 : 0] opcode_i,

    output logic reg_write_o,
    output logic operand_b_o,
    output logic [ALU_CONTROL-1 : 0] alu_control
);
    logic r_type;
    logic i_type; 
    /////////////////////////////////////////////////////////////////////////////////
    //--------------------------------TYPE DECODER-----------------------------------
    /////////////////////////////////////////////////////////////////////////////////
    always_comb begin
      r_type    = (opcode_i == 7'b0110011) ? 1 : 0;
      i_type    = (opcode_i == 7'b0010011) ? 1 : 0;      

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
    end

    assign reg_write_o = (r_type | i_type) ? 1 :0;  //reg write signal for register file
    assign operand_b_o = (i_type) ? 1 : 0 ;        //operand b signal for second input of alu
endmodule