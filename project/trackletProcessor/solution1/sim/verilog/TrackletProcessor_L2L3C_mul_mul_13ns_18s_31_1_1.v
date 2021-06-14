
`timescale 1 ns / 1 ps

  module TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1_DSP48_19(a, b, p);
input [13 - 1 : 0] a;
input signed [18 - 1 : 0] b;
output signed [31 - 1 : 0] p;

assign p = $signed ({1'b0, a}) * $signed (b);

endmodule
`timescale 1 ns / 1 ps
module TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1(
    din0,
    din1,
    dout);

parameter ID = 32'd1;
parameter NUM_STAGE = 32'd1;
parameter din0_WIDTH = 32'd1;
parameter din1_WIDTH = 32'd1;
parameter dout_WIDTH = 32'd1;
input[din0_WIDTH - 1:0] din0;
input[din1_WIDTH - 1:0] din1;
output[dout_WIDTH - 1:0] dout;



TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1_DSP48_19 TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1_DSP48_19_U(
    .a( din0 ),
    .b( din1 ),
    .p( dout ));

endmodule

