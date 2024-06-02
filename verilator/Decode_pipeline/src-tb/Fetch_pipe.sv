module Fetch_pipe
#
(
parameter INSTRUCTION =32,
parameter ADDRESS=32
)
(
  input  clk,
  input  [ADDRESS-1:0] pre_address_fetch,
  input  [INSTRUCTION-1:0] instruction_fetch,
  input  next_select,
  input  branch_result,
  input  load,
  input  Jalr,

  output logic [ADDRESS-1:0] pre_pc_fetch_pp,
  output logic [INSTRUCTION-1:0] instruction_fetch_pp
);

  logic [ADDRESS-1:0] pre_address;
  logic [INSTRUCTION-1:0] instruc;
  logic flush_pipeline,flush_pipeline2;

  always_ff @ (posedge clk) begin
    if (next_select | branch_result |Jalr) begin
      // If jal, jalr, or branch result is high, flush the pipeline for one cycle
      pre_address <= 32'b0;
      instruc <= 32'b0;
      flush_pipeline <= 1; // Set flag to flush for one cycle
    end 
    else if (flush_pipeline) begin
        // Stall the pipeline for one additional cycle after flushing
        pre_address <= 32'b0;
        instruc <= 32'b0;
        flush_pipeline <= 0; // Reset flag after one cycle stall
        flush_pipeline2 <= 1; // Set flag to flush for one cycle
      end
      else if (flush_pipeline2) begin
        // Stall the pipeline for one additional cycle after flushing
        pre_address <= 32'b0;
        instruc <= 32'b0;
        flush_pipeline2 <= 0; // Reset flag after one cycle stall
          end
      else if (load) begin
        //stall pipeline
        pre_address <= pre_pc_fetch_pp;
        instruc <= instruction_fetch_pp;
      end
      else begin
        // For other instructions, proceed normally
        pre_address <= pre_address_fetch;
        instruc <= instruction_fetch;
      end
    end

  assign pre_pc_fetch_pp = pre_address;
  assign instruction_fetch_pp = instruc;
endmodule