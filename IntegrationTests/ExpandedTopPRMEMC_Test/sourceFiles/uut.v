`timescale 1ns / 1ps

module uut(
// Control signals
  input 	clk,
  input 	reset,
  input 	en_proc,
  input [2:0] 	bx_in_ProjectionRouter,

// PR inputs
  input TPROJ_L3PHIC_dataarray_data_V_wea [7:0],
  input [7:0] TPROJ_L3PHIC_dataarray_data_V_writeaddr [7:0],
  input [59:0] TPROJ_L3PHIC_dataarray_data_V_din [7:0],
  input TPROJ_L3PHIC_nentries_0_V_we [7:0],
  input [6:0] TPROJ_L3PHIC_nentries_0_V_din [7:0],
  input TPROJ_L3PHIC_nentries_1_V_we [7:0],
  input [6:0] TPROJ_L3PHIC_nentries_1_V_din [7:0],

// ME inputs
  input VMSME_L3PHIC17to24n1_dataarray_data_V_wea [7:0],
  input [9:0] VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr [7:0],
  input [13:0] VMSME_L3PHIC17to24n1_dataarray_data_V_din [7:0], 
  input VMSME_L3PHIC17to24n1_nentries_0_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_0_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_1_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_1_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_2_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_2_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_3_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_3_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_4_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_4_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_5_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_5_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_6_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_6_V_din [7:0],
  input VMSME_L3PHIC17to24n1_nentries_7_V_we [7:0],
  input [6:0] VMSME_L3PHIC17to24n1_nentries_7_V_din [7:0],

// MC inputs
  input AS_L3PHICn4_dataarray_data_V_wea,
  input [9:0] AS_L3PHICn4_dataarray_data_V_writeaddr,
  input [35:0] AS_L3PHICn4_dataarray_data_V_din,
  input AS_L3PHICn4_dataarray_nentries_0_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_0_V_din,
  input AS_L3PHICn4_dataarray_nentries_1_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_1_V_din,
  input AS_L3PHICn4_dataarray_nentries_2_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_2_V_din,
  input AS_L3PHICn4_dataarray_nentries_3_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_3_V_din,
  input AS_L3PHICn4_dataarray_nentries_4_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_4_V_din,
  input AS_L3PHICn4_dataarray_nentries_5_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_5_V_din,
  input AS_L3PHICn4_dataarray_nentries_6_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_6_V_din,
  input AS_L3PHICn4_dataarray_nentries_7_V_we,
  input [6:0] AS_L3PHICn4_dataarray_nentries_7_V_din,

// MC outputs
  input FM_L1L2XX_L3PHIC_dataarray_data_V_enb,
  input [7:0] FM_L1L2XX_L3PHIC_dataarray_data_V_readaddr,
  output [44:0] FM_L1L2XX_L3PHIC_dataarray_data_V_dout,
  output [6:0] FM_L1L2XX_L3PHIC_nentries_0_V_dout,
  output [6:0] FM_L1L2XX_L3PHIC_nentries_1_V_dout,
  input FM_L5L6XX_L3PHIC_dataarray_data_V_enb,
  input [7:0] FM_L5L6XX_L3PHIC_dataarray_data_V_readaddr,
  output [44:0] FM_L5L6XX_L3PHIC_dataarray_data_V_dout,
  output [6:0] FM_L5L6XX_L3PHIC_nentries_0_V_dout,
  output [6:0] FM_L5L6XX_L3PHIC_nentries_1_V_dout,

// More control signals
  output[2:0] bx_out_MatchCalculator,
  output MatchCalculator_done
);

// PR input
// TrackletProjections
// (0-7) -> L1L2F-L1L2J, L5L6B-L5L6D)

wire TPROJ_L3PHIC_dataarray_data_V_enb [7:0];
wire [7:0] TPROJ_L3PHIC_dataarray_data_V_readaddr [7:0];
wire [59:0] TPROJ_L3PHIC_dataarray_data_V_dout [7:0];
wire [6:0] TPROJ_L3PHIC_nentries_0_V_dout [7:0];
wire [6:0] TPROJ_L3PHIC_nentries_1_V_dout [7:0];

genvar tpidx;
generate
  for (tpidx=0; tpidx<=7; tpidx=tpidx+1) begin : gen_MemoryTProj
    Memory #(
      .RAM_WIDTH(60),
      .RAM_DEPTH(256),
      .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
      .HEX(1),
      .INIT_FILE("")
    ) TPROJ_L3PHIC (
      .clka(clk),
      .clkb(clk),
      .wea(TPROJ_L3PHIC_dataarray_data_V_wea[tpidx]),
      .addra(TPROJ_L3PHIC_dataarray_data_V_writeaddr[tpidx]),
      .dina(TPROJ_L3PHIC_dataarray_data_V_din[tpidx]),
      .nent_we0(TPROJ_L3PHIC_nentries_0_V_we[tpidx]),
      .nent_i0(TPROJ_L3PHIC_nentries_0_V_din[tpidx]),
      .nent_we1(TPROJ_L3PHIC_nentries_1_V_we[tpidx]),
      .nent_i1(TPROJ_L3PHIC_nentries_1_V_din[tpidx]),
      .enb(TPROJ_L3PHIC_dataarray_data_V_enb[tpidx]),
      .addrb(TPROJ_L3PHIC_dataarray_data_V_readaddr[tpidx]),
      .doutb(TPROJ_L3PHIC_dataarray_data_V_dout[tpidx]),
      .nent_o0(TPROJ_L3PHIC_nentries_0_V_dout[tpidx]),
      .nent_o1(TPROJ_L3PHIC_nentries_1_V_dout[tpidx]),
      .regceb(1'b1)
    );
  end
endgenerate

//PR output
   
wire[2:0] bx_out_ProjectionRouter;
wire VMPROJ_L3PHIC17to24_dataarray_data_V_wea [7:0];
wire[7:0] VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr [7:0];
wire[20:0] VMPROJ_L3PHIC17to24_dataarray_data_V_din [7:0];
wire VMPROJ_L3PHIC17to24_nentries_0_V_we [7:0];
wire[6:0] VMPROJ_L3PHIC17to24_nentries_0_V_din [7:0];
wire VMPROJ_L3PHIC17to24_nentries_1_V_we [7:0];
wire[6:0] VMPROJ_L3PHIC17to24_nentries_1_V_din [7:0];
wire ProjectionRouter_done;
wire AP_L3PHIC_dataarray_data_V_wea;
wire[9:0] AP_L3PHIC_dataarray_data_V_writeaddr;
wire[59:0] AP_L3PHIC_dataarray_data_V_din;
wire AP_L3PHIC_nentries_0_V_we;
wire[6:0] AP_L3PHIC_nentries_0_V_din;
wire AP_L3PHIC_nentries_1_V_we;
wire[6:0] AP_L3PHIC_nentries_1_V_din;
wire AP_L3PHIC_nentries_2_V_we;
wire[6:0] AP_L3PHIC_nentries_2_V_din;
wire AP_L3PHIC_nentries_3_V_we;
wire[6:0] AP_L3PHIC_nentries_3_V_din;
wire AP_L3PHIC_nentries_4_V_we;
wire[6:0] AP_L3PHIC_nentries_4_V_din;
wire AP_L3PHIC_nentries_5_V_we;
wire[6:0] AP_L3PHIC_nentries_5_V_din;
wire AP_L3PHIC_nentries_6_V_we;
wire[6:0] AP_L3PHIC_nentries_6_V_din;
wire AP_L3PHIC_nentries_7_V_we;
wire[6:0] AP_L3PHIC_nentries_7_V_din;
   
PR_L3PHIC PR_L3PHIC(
  .ap_clk(clk),
  .ap_rst(reset),
  .ap_start(en_proc),
  .ap_done(ProjectionRouter_done),
  .bx_V(bx_in_ProjectionRouter),
  .proj1in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[0]),
  .proj1in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[0]),
  .proj1in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[0]),
  .proj1in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[0]),
  .proj1in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[0]),
  .proj2in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[1]),
  .proj2in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[1]),
  .proj2in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[1]),
  .proj2in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[1]),
  .proj2in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[1]),
  .proj3in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[2]),
  .proj3in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[2]),
  .proj3in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[2]),
  .proj3in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[2]),
  .proj3in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[2]),
  .proj4in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[3]),
  .proj4in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[3]),
  .proj4in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[3]),
  .proj4in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[3]),
  .proj4in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[3]),
  .proj5in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[4]),
  .proj5in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[4]),
  .proj5in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[4]),
  .proj5in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[4]),
  .proj5in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[4]),
  .proj6in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[5]),
  .proj6in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[5]),
  .proj6in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[5]),
  .proj6in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[5]),
  .proj6in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[5]),
  .proj7in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[6]),
  .proj7in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[6]),
  .proj7in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[6]),
  .proj7in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[6]),
  .proj7in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[6]),
  .proj8in_dataarray_data_V_ce0(TPROJ_L3PHIC_dataarray_data_V_enb[7]),
  .proj8in_dataarray_data_V_address0(TPROJ_L3PHIC_dataarray_data_V_readaddr[7]),
  .proj8in_dataarray_data_V_q0(TPROJ_L3PHIC_dataarray_data_V_dout[7]),
  .proj8in_nentries_0_V(TPROJ_L3PHIC_nentries_0_V_dout[7]),
  .proj8in_nentries_1_V(TPROJ_L3PHIC_nentries_1_V_dout[7]),
  .bx_o_V(bx_out_ProjectionRouter),
  .allprojout_dataarray_data_V_we0(AP_L3PHIC_dataarray_data_V_wea),
  .allprojout_dataarray_data_V_address0(AP_L3PHIC_dataarray_data_V_writeaddr),
  .allprojout_dataarray_data_V_d0(AP_L3PHIC_dataarray_data_V_din),
  .allprojout_nentries_0_V_ap_vld(AP_L3PHIC_nentries_0_V_we),
  .allprojout_nentries_0_V(AP_L3PHIC_nentries_0_V_din),
  .allprojout_nentries_1_V_ap_vld(AP_L3PHIC_nentries_1_V_we),
  .allprojout_nentries_1_V(AP_L3PHIC_nentries_1_V_din),
  .allprojout_nentries_2_V_ap_vld(AP_L3PHIC_nentries_2_V_we),
  .allprojout_nentries_2_V(AP_L3PHIC_nentries_2_V_din),
  .allprojout_nentries_3_V_ap_vld(AP_L3PHIC_nentries_3_V_we),
  .allprojout_nentries_3_V(AP_L3PHIC_nentries_3_V_din),
  .allprojout_nentries_4_V_ap_vld(AP_L3PHIC_nentries_4_V_we),
  .allprojout_nentries_4_V(AP_L3PHIC_nentries_4_V_din),
  .allprojout_nentries_5_V_ap_vld(AP_L3PHIC_nentries_5_V_we),
  .allprojout_nentries_5_V(AP_L3PHIC_nentries_5_V_din),
  .allprojout_nentries_6_V_ap_vld(AP_L3PHIC_nentries_6_V_we),
  .allprojout_nentries_6_V(AP_L3PHIC_nentries_6_V_din),
  .allprojout_nentries_7_V_ap_vld(AP_L3PHIC_nentries_7_V_we),
  .allprojout_nentries_7_V(AP_L3PHIC_nentries_7_V_din),
  .vmprojout1_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[0]),
  .vmprojout1_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[0]),
  .vmprojout1_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[0]),
  .vmprojout1_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[0]),
  .vmprojout1_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[0]),
  .vmprojout1_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[0]),
  .vmprojout1_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[0]),
  .vmprojout2_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[1]),
  .vmprojout2_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[1]),
  .vmprojout2_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[1]),
  .vmprojout2_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[1]),
  .vmprojout2_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[1]),
  .vmprojout2_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[1]),
  .vmprojout2_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[1]),
  .vmprojout3_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[2]),
  .vmprojout3_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[2]),
  .vmprojout3_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[2]),
  .vmprojout3_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[2]),
  .vmprojout3_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[2]),
  .vmprojout3_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[2]),
  .vmprojout3_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[2]),
  .vmprojout4_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[3]),
  .vmprojout4_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[3]),
  .vmprojout4_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[3]),
  .vmprojout4_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[3]),
  .vmprojout4_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[3]),
  .vmprojout4_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[3]),
  .vmprojout4_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[3]),
  .vmprojout5_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[4]),
  .vmprojout5_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[4]),
  .vmprojout5_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[4]),
  .vmprojout5_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[4]),
  .vmprojout5_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[4]),
  .vmprojout5_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[4]),
  .vmprojout5_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[4]),
  .vmprojout6_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[5]),
  .vmprojout6_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[5]),
  .vmprojout6_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[5]),
  .vmprojout6_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[5]),
  .vmprojout6_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[5]),
  .vmprojout6_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[5]),
  .vmprojout6_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[5]),
  .vmprojout7_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[6]),
  .vmprojout7_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[6]),
  .vmprojout7_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[6]),
  .vmprojout7_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[6]),
  .vmprojout7_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[6]),
  .vmprojout7_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[6]),
  .vmprojout7_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[6]),
  .vmprojout8_dataarray_data_V_we0(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[7]),
  .vmprojout8_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[7]),
  .vmprojout8_dataarray_data_V_d0(VMPROJ_L3PHIC17to24_dataarray_data_V_din[7]),
  .vmprojout8_nentries_0_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_0_V_we[7]),
  .vmprojout8_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_din[7]),
  .vmprojout8_nentries_1_V_ap_vld(VMPROJ_L3PHIC17to24_nentries_1_V_we[7]),
  .vmprojout8_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_din[7])
);

reg MatchEngine_start;
initial begin
  MatchEngine_start = 1'b0;
end
always @(ProjectionRouter_done) begin
  if (ProjectionRouter_done) MatchEngine_start = 1'b1;
end

// ME input
// AllStubs
wire AS_L3PHICn4_dataarray_data_V_enb;
wire [9:0] AS_L3PHICn4_dataarray_data_V_readaddr;
wire [35:0] AS_L3PHICn4_dataarray_data_V_dout;
wire [6:0] AS_L3PHICn4_nentries_0_V_dout;
wire [6:0] AS_L3PHICn4_nentries_1_V_dout;
wire [6:0] AS_L3PHICn4_nentries_2_V_dout;
wire [6:0] AS_L3PHICn4_nentries_3_V_dout;
wire [6:0] AS_L3PHICn4_nentries_4_V_dout;
wire [6:0] AS_L3PHICn4_nentries_5_V_dout;
wire [6:0] AS_L3PHICn4_nentries_6_V_dout;
wire [6:0] AS_L3PHICn4_nentries_7_V_dout;

Memory #(
  .RAM_WIDTH(36),
  .RAM_DEPTH(1024),
  .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
  .HEX(0),
  .INIT_FILE("")
) AS_L3PHICn4 (
  .clka(clk),
  .clkb(clk),
  .wea(AS_L3PHICn4_dataarray_data_V_wea),
  .addra(AS_L3PHICn4_dataarray_data_V_writeaddr),
  .dina(AS_L3PHICn4_dataarray_data_V_din),
  .nent_we0(AS_L3PHICn4_nentries_0_V_we),
  .nent_i0(AS_L3PHICn4_nentries_0_V_din),
  .nent_we1(AS_L3PHICn4_nentries_1_V_we),
  .nent_i1(AS_L3PHICn4_nentries_1_V_din),
  .nent_we2(AS_L3PHICn4_nentries_2_V_we),
  .nent_i2(AS_L3PHICn4_nentries_2_V_din),
  .nent_we3(AS_L3PHICn4_nentries_3_V_we),
  .nent_i3(AS_L3PHICn4_nentries_3_V_din),
  .nent_we4(AS_L3PHICn4_nentries_4_V_we),
  .nent_i4(AS_L3PHICn4_nentries_4_V_din),
  .nent_we5(AS_L3PHICn4_nentries_5_V_we),
  .nent_i5(AS_L3PHICn4_nentries_5_V_din),
  .nent_we6(AS_L3PHICn4_nentries_6_V_we),
  .nent_i6(AS_L3PHICn4_nentries_6_V_din),
  .nent_we7(AS_L3PHICn4_nentries_7_V_we),
  .nent_i7(AS_L3PHICn4_nentries_7_V_din),
  .enb(AS_L3PHICn4_dataarray_data_V_enb),
  .addrb(AS_L3PHICn4_dataarray_data_V_readaddr),
  .doutb(AS_L3PHICn4_dataarray_data_V_dout),
  .nent_o0(AS_L3PHICn4_nentries_0_V_dout),
  .nent_o1(AS_L3PHICn4_nentries_1_V_dout),
  .nent_o2(AS_L3PHICn4_nentries_2_V_dout),
  .nent_o3(AS_L3PHICn4_nentries_3_V_dout),
  .nent_o4(AS_L3PHICn4_nentries_4_V_dout),
  .nent_o5(AS_L3PHICn4_nentries_5_V_dout),
  .nent_o6(AS_L3PHICn4_nentries_6_V_dout),
  .nent_o7(AS_L3PHICn4_nentries_7_V_dout),
  .regceb(1'b1)
);

// PR Output ME Input 8 MEs
wire VMPROJ_L3PHIC17to24_dataarray_data_V_enb [7:0];
wire [7:0] VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr [7:0];
wire [20:0] VMPROJ_L3PHIC17to24_dataarray_data_V_dout [7:0];
wire [6:0]  VMPROJ_L3PHIC17to24_nentries_0_V_dout [7:0];
wire [6:0]  VMPROJ_L3PHIC17to24_nentries_1_V_dout [7:0];
   
genvar vmpidx;
generate
  for (vmpidx=0; vmpidx<=7; vmpidx=vmpidx+1) begin : gen_MemoryVMProj
    Memory #(
      .RAM_WIDTH(21),
      .RAM_DEPTH(256),
      .RAM_PERFORMANCE("LOW_LATENCY"),
      .HEX(0),
      .INIT_FILE("")
    ) VMPROJ_L3PHIC17to24 (
      .clka(clk),
      .clkb(clk),
      .wea(VMPROJ_L3PHIC17to24_dataarray_data_V_wea[vmpidx]),
      .addra(VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr[vmpidx]),
      .dina(VMPROJ_L3PHIC17to24_dataarray_data_V_din[vmpidx]),
      .nent_we0(VMPROJ_L3PHIC17to24_nentries_0_V_we[vmpidx]),
      .nent_i0(VMPROJ_L3PHIC17to24_nentries_0_V_din[vmpidx]),
      .nent_we1(VMPROJ_L3PHIC17to24_nentries_1_V_we[vmpidx]),
      .nent_i1(VMPROJ_L3PHIC17to24_nentries_1_V_din[vmpidx]),
      .enb(VMPROJ_L3PHIC17to24_dataarray_data_V_enb[vmpidx]),
      .addrb(VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr[vmpidx]),
      .doutb(VMPROJ_L3PHIC17to24_dataarray_data_V_dout[vmpidx]),
      .nent_o0(VMPROJ_L3PHIC17to24_nentries_0_V_dout[vmpidx]),
      .nent_o1(VMPROJ_L3PHIC17to24_nentries_1_V_dout[vmpidx]),
      .regceb(1'b1)
    );
  end
endgenerate  

// PR Output MC Input
wire AP_L3PHIC_dataarray_data_V_enb;
wire[9:0] AP_L3PHIC_dataarray_data_V_readaddr;
wire[59:0] AP_L3PHIC_dataarray_data_V_dout;
wire[7:0] AP_L3PHIC_nentries_0_V_dout;
wire[7:0] AP_L3PHIC_nentries_1_V_dout;
wire[7:0] AP_L3PHIC_nentries_2_V_dout;
wire[7:0] AP_L3PHIC_nentries_3_V_dout;
wire[7:0] AP_L3PHIC_nentries_4_V_dout;
wire[7:0] AP_L3PHIC_nentries_5_V_dout;
wire[7:0] AP_L3PHIC_nentries_6_V_dout;
wire[7:0] AP_L3PHIC_nentries_7_V_dout;

Memory #(
  .RAM_WIDTH(60),
  .RAM_DEPTH(1024),
  .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
  .HEX(1),
  .INIT_FILE("")
) AP_L3PHIC (
  .clka(clk),
  .clkb(clk),
  .wea(AP_L3PHIC_dataarray_data_V_wea),
  .addra(AP_L3PHIC_dataarray_data_V_writeaddr),
  .dina(AP_L3PHIC_dataarray_data_V_din),
  .nent_we0(AP_L3PHIC_nentries_0_V_we),
  .nent_i0(AP_L3PHIC_nentries_0_V_din),
  .nent_we1(AP_L3PHIC_nentries_1_V_we),
  .nent_i1(AP_L3PHIC_nentries_1_V_din),
  .nent_we2(AP_L3PHIC_nentries_2_V_we),
  .nent_i2(AP_L3PHIC_nentries_2_V_din),
  .nent_we3(AP_L3PHIC_nentries_3_V_we),
  .nent_i3(AP_L3PHIC_nentries_3_V_din),
  .nent_we4(AP_L3PHIC_nentries_4_V_we),
  .nent_i4(AP_L3PHIC_nentries_4_V_din),
  .nent_we5(AP_L3PHIC_nentries_5_V_we),
  .nent_i5(AP_L3PHIC_nentries_5_V_din),
  .nent_we6(AP_L3PHIC_nentries_6_V_we),
  .nent_i6(AP_L3PHIC_nentries_6_V_din),
  .nent_we7(AP_L3PHIC_nentries_7_V_we),
  .nent_i7(AP_L3PHIC_nentries_7_V_din),
  .enb(AP_L3PHIC_dataarray_data_V_enb),
  .addrb(AP_L3PHIC_dataarray_data_V_readaddr),
  .doutb(AP_L3PHIC_dataarray_data_V_dout),
  .nent_o0(AP_L3PHIC_nentries_0_V_dout),
  .nent_o1(AP_L3PHIC_nentries_1_V_dout),
  .nent_o2(AP_L3PHIC_nentries_2_V_dout),
  .nent_o3(AP_L3PHIC_nentries_3_V_dout),
  .nent_o4(AP_L3PHIC_nentries_4_V_dout),
  .nent_o5(AP_L3PHIC_nentries_5_V_dout),
  .nent_o6(AP_L3PHIC_nentries_6_V_dout),
  .nent_o7(AP_L3PHIC_nentries_7_V_dout),
  .regceb(1'b1)
);

// ME output
wire [2:0] bx_out_MatchEngine [7:0];
wire CM_L3PHIC17to24_dataarray_data_V_wea [7:0];
wire[7:0] CM_L3PHIC17to24_dataarray_data_V_writeaddr [7:0];
wire[13:0] CM_L3PHIC17to24_dataarray_data_V_din [7:0];
wire CM_L3PHIC17to24_nentries_0_V_we [7:0];
wire[6:0] CM_L3PHIC17to24_nentries_0_V_din [7:0];
wire CM_L3PHIC17to24_nentries_1_V_we [7:0];
wire[6:0] CM_L3PHIC17to24_nentries_1_V_din [7:0];
wire MatchEngine_done [7:0];

genvar meidx;
generate
  for (meidx=0; meidx<=7; meidx=meidx+1) begin : gen_MatchEngineTopL3  
    MatchEngineTopL3_0 MatchEngineTopL3_0( //L1 & L3 identical, maybe should name BARRELPS
      .ap_clk(clk),
      .ap_rst(reset),
      .ap_start(MatchEngine_start),
      .ap_done(MatchEngine_done[meidx]),
      .bx_V(bx_out_ProjectionRouter),
      .bx_o_V(bx_out_MatchEngine[meidx]),
      .instubdata_dataarray_data_V_ce0(VMSME_L3PHIC17to24n1_dataarray_data_V_enb[meidx]),
      .instubdata_dataarray_data_V_address0(VMSME_L3PHIC17to24n1_dataarray_data_V_readaddr[meidx]),
      .instubdata_dataarray_data_V_q0(VMSME_L3PHIC17to24n1_dataarray_data_V_dout[meidx]),
      .instubdata_nentries_0_V_0(VMSME_L3PHIC17to24n1_nentries_0_0_V_dout[meidx]),
      .instubdata_nentries_0_V_1(VMSME_L3PHIC17to24n1_nentries_0_1_V_dout[meidx]),
      .instubdata_nentries_0_V_2(VMSME_L3PHIC17to24n1_nentries_0_2_V_dout[meidx]),
      .instubdata_nentries_0_V_3(VMSME_L3PHIC17to24n1_nentries_0_3_V_dout[meidx]),
      .instubdata_nentries_0_V_4(VMSME_L3PHIC17to24n1_nentries_0_4_V_dout[meidx]),
      .instubdata_nentries_0_V_5(VMSME_L3PHIC17to24n1_nentries_0_5_V_dout[meidx]),
      .instubdata_nentries_0_V_6(VMSME_L3PHIC17to24n1_nentries_0_6_V_dout[meidx]),
      .instubdata_nentries_0_V_7(VMSME_L3PHIC17to24n1_nentries_0_7_V_dout[meidx]),
      .instubdata_nentries_1_V_0(VMSME_L3PHIC17to24n1_nentries_1_0_V_dout[meidx]),
      .instubdata_nentries_1_V_1(VMSME_L3PHIC17to24n1_nentries_1_1_V_dout[meidx]),
      .instubdata_nentries_1_V_2(VMSME_L3PHIC17to24n1_nentries_1_2_V_dout[meidx]),
      .instubdata_nentries_1_V_3(VMSME_L3PHIC17to24n1_nentries_1_3_V_dout[meidx]),
      .instubdata_nentries_1_V_4(VMSME_L3PHIC17to24n1_nentries_1_4_V_dout[meidx]),
      .instubdata_nentries_1_V_5(VMSME_L3PHIC17to24n1_nentries_1_5_V_dout[meidx]),
      .instubdata_nentries_1_V_6(VMSME_L3PHIC17to24n1_nentries_1_6_V_dout[meidx]),
      .instubdata_nentries_1_V_7(VMSME_L3PHIC17to24n1_nentries_1_7_V_dout[meidx]),
      .instubdata_nentries_2_V_0(VMSME_L3PHIC17to24n1_nentries_2_0_V_dout[meidx]),
      .instubdata_nentries_2_V_1(VMSME_L3PHIC17to24n1_nentries_2_1_V_dout[meidx]),
      .instubdata_nentries_2_V_2(VMSME_L3PHIC17to24n1_nentries_2_2_V_dout[meidx]),
      .instubdata_nentries_2_V_3(VMSME_L3PHIC17to24n1_nentries_2_3_V_dout[meidx]),
      .instubdata_nentries_2_V_4(VMSME_L3PHIC17to24n1_nentries_2_4_V_dout[meidx]),
      .instubdata_nentries_2_V_5(VMSME_L3PHIC17to24n1_nentries_2_5_V_dout[meidx]),
      .instubdata_nentries_2_V_6(VMSME_L3PHIC17to24n1_nentries_2_6_V_dout[meidx]),
      .instubdata_nentries_2_V_7(VMSME_L3PHIC17to24n1_nentries_2_7_V_dout[meidx]),
      .instubdata_nentries_3_V_0(VMSME_L3PHIC17to24n1_nentries_3_0_V_dout[meidx]),
      .instubdata_nentries_3_V_1(VMSME_L3PHIC17to24n1_nentries_3_1_V_dout[meidx]),
      .instubdata_nentries_3_V_2(VMSME_L3PHIC17to24n1_nentries_3_2_V_dout[meidx]),
      .instubdata_nentries_3_V_3(VMSME_L3PHIC17to24n1_nentries_3_3_V_dout[meidx]),
      .instubdata_nentries_3_V_4(VMSME_L3PHIC17to24n1_nentries_3_4_V_dout[meidx]),
      .instubdata_nentries_3_V_5(VMSME_L3PHIC17to24n1_nentries_3_5_V_dout[meidx]),
      .instubdata_nentries_3_V_6(VMSME_L3PHIC17to24n1_nentries_3_6_V_dout[meidx]),
      .instubdata_nentries_3_V_7(VMSME_L3PHIC17to24n1_nentries_3_7_V_dout[meidx]),
      .inprojdata_dataarray_data_V_ce0(VMPROJ_L3PHIC17to24_dataarray_data_V_enb[meidx]),
      .inprojdata_dataarray_data_V_address0(VMPROJ_L3PHIC17to24_dataarray_data_V_readaddr[meidx]),
      .inprojdata_dataarray_data_V_q0(VMPROJ_L3PHIC17to24_dataarray_data_V_dout[meidx]),
      .inprojdata_nentries_0_V(VMPROJ_L3PHIC17to24_nentries_0_V_dout[meidx]),
      .inprojdata_nentries_1_V(VMPROJ_L3PHIC17to24_nentries_1_V_dout[meidx]),
      .outcandmatch_dataarray_data_V_we0(CM_L3PHIC17to24_dataarray_data_V_wea[meidx]),
      .outcandmatch_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_writeaddr[meidx]),
      .outcandmatch_dataarray_data_V_d0(CM_L3PHIC17to24_dataarray_data_V_din[meidx]),
      .outcandmatch_nentries_0_V_ap_vld(CM_L3PHIC17to24_nentries_0_V_we[meidx]),
      .outcandmatch_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_din[meidx]),
      .outcandmatch_nentries_1_V_ap_vld(CM_L3PHIC17to24_nentries_1_V_we[meidx]),
      .outcandmatch_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_din[meidx])
    );
  end
endgenerate

reg MatchCalculator_start;
initial begin
  MatchCalculator_start = 1'b0;
end
always @(MatchEngine_done[0]) begin
  if (MatchEngine_done) MatchCalculator_start = 1'b1;
end

// MC input
wire CM_L3PHIC17to24_dataarray_data_V_enb [7:0];
wire[7:0] CM_L3PHIC17to24_dataarray_data_V_readaddr [7:0];
wire[13:0] CM_L3PHIC17to24_dataarray_data_V_dout [7:0];
wire[6:0] CM_L3PHIC17to24_nentries_0_V_dout [7:0];
wire[6:0] CM_L3PHIC17to24_nentries_1_V_dout [7:0];


genvar cmidx;
generate
  for (cmidx=0; cmidx<=7; cmidx=cmidx+1) begin : gen_MemoryCM   
    Memory #(
      .RAM_WIDTH(14),
      .RAM_DEPTH(256),
      .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
      .HEX(1),
      .INIT_FILE("")
    ) CM_L3PHIC17to24 (
      .clka(clk),
      .clkb(clk),
      .rstb(1'b0),
      .wea(CM_L3PHIC17to24_dataarray_data_V_wea[cmidx]),
      .addra(CM_L3PHIC17to24_dataarray_data_V_writeaddr[cmidx]),
      .dina(CM_L3PHIC17to24_dataarray_data_V_din[cmidx]),
      .nent_we0(CM_L3PHIC17to24_nentries_0_V_we[cmidx]),
      .nent_i0(CM_L3PHIC17to24_nentries_0_V_din[cmidx]),
      .nent_we1(CM_L3PHIC17to24_nentries_1_V_we[cmidx]),
      .nent_i1(CM_L3PHIC17to24_nentries_1_V_din[cmidx]),
      .enb(CM_L3PHIC17to24_dataarray_data_V_enb[cmidx]),
      .addrb(CM_L3PHIC17to24_dataarray_data_V_readaddr[cmidx]),
      .doutb(CM_L3PHIC17to24_dataarray_data_V_dout[cmidx]),
      .nent_o0(CM_L3PHIC17to24_nentries_0_V_dout[cmidx]),
      .nent_o1(CM_L3PHIC17to24_nentries_1_V_dout[cmidx]),
      .regceb(1'b1)
    );
  end
endgenerate

// MC output
wire [2:0] bx_out_MatchCalculator;
wire FM_L1L2XX_L3PHIC_dataarray_data_V_wea;
wire [7:0] FM_L1L2XX_L3PHIC_dataarray_data_V_writeaddr;
wire [44:0] FM_L1L2XX_L3PHIC_dataarray_data_V_din;
wire FM_L1L2XX_L3PHIC_nentries_0_V_we;
wire [6:0] FM_L1L2XX_L3PHIC_nentries_0_V_din;
wire FM_L1L2XX_L3PHIC_nentries_1_V_we;
wire [6:0] FM_L1L2XX_L3PHIC_nentries_1_V_din;
wire FM_L5L6XX_L3PHIC_dataarray_data_V_wea;
wire [7:0] FM_L5L6XX_L3PHIC_dataarray_data_V_writeaddr;
wire [44:0] FM_L5L6XX_L3PHIC_dataarray_data_V_din;
wire FM_L5L6XX_L3PHIC_nentries_0_V_we;
wire [6:0] FM_L5L6XX_L3PHIC_nentries_0_V_din;
wire FM_L5L6XX_L3PHIC_nentries_1_V_we;
wire [6:0] FM_L5L6XX_L3PHIC_nentries_1_V_din;
wire MatchCalculator_done;

MC_L3PHIC MC_L3PHIC(
  .ap_clk(clk),
  .ap_rst(reset),
  .ap_start(MatchCalculator_start),
  .ap_done(MatchCalculator_done),
  .bx_V(bx_out_MatchEngine[0]),
  .match1_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[0]),
  .match1_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[0]),
  .match1_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[0]),
  .match1_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[0]),
  .match1_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[0]),
  .match2_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[1]),
  .match2_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[1]),
  .match2_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[1]),
  .match2_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[1]),
  .match2_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[1]),
  .match3_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[2]),
  .match3_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[2]),
  .match3_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[2]),
  .match3_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[2]),
  .match3_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[2]),
  .match4_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[3]),
  .match4_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[3]),
  .match4_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[3]),
  .match4_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[3]),
  .match4_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[3]),
  .match5_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[4]),
  .match5_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[4]),
  .match5_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[4]),
  .match5_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[4]),
  .match5_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[4]),
  .match6_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[5]),
  .match6_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[5]),
  .match6_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[5]),
  .match6_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[5]),
  .match6_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[5]),
  .match7_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[6]),
  .match7_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[6]),
  .match7_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[6]),
  .match7_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[6]),
  .match7_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[6]),
  .match8_dataarray_data_V_ce0(CM_L3PHIC17to24_dataarray_data_V_enb[7]),
  .match8_dataarray_data_V_address0(CM_L3PHIC17to24_dataarray_data_V_readaddr[7]),
  .match8_dataarray_data_V_q0(CM_L3PHIC17to24_dataarray_data_V_dout[7]),
  .match8_nentries_0_V(CM_L3PHIC17to24_nentries_0_V_dout[7]),
  .match8_nentries_1_V(CM_L3PHIC17to24_nentries_1_V_dout[7]),
  .allstub_dataarray_data_V_ce0(AS_L3PHICn4_dataarray_data_V_enb),
  .allstub_dataarray_data_V_address0(AS_L3PHICn4_dataarray_data_V_readaddr),
  .allstub_dataarray_data_V_q0(AS_L3PHICn4_dataarray_data_V_dout),
  .allstub_nentries_0_V(AS_L3PHICn4_nentries_0_V_dout),
  .allstub_nentries_1_V(AS_L3PHICn4_nentries_1_V_dout),
  .allstub_nentries_2_V(AS_L3PHICn4_nentries_2_V_dout),
  .allstub_nentries_3_V(AS_L3PHICn4_nentries_3_V_dout),
  .allstub_nentries_4_V(AS_L3PHICn4_nentries_4_V_dout),
  .allstub_nentries_5_V(AS_L3PHICn4_nentries_5_V_dout),
  .allstub_nentries_6_V(AS_L3PHICn4_nentries_6_V_dout),
  .allstub_nentries_7_V(AS_L3PHICn4_nentries_7_V_dout),
  .allproj_dataarray_data_V_ce0(AP_L3PHIC_dataarray_data_V_enb),
  .allproj_dataarray_data_V_address0(AP_L3PHIC_dataarray_data_V_readaddr),
  .allproj_dataarray_data_V_q0(AP_L3PHIC_dataarray_data_V_dout),
  .allproj_nentries_0_V(AP_L3PHIC_nentries_0_V_dout),
  .allproj_nentries_1_V(AP_L3PHIC_nentries_1_V_dout),
  .allproj_nentries_2_V(AP_L3PHIC_nentries_2_V_dout),
  .allproj_nentries_3_V(AP_L3PHIC_nentries_3_V_dout),
  .allproj_nentries_4_V(AP_L3PHIC_nentries_4_V_dout),
  .allproj_nentries_5_V(AP_L3PHIC_nentries_5_V_dout),
  .allproj_nentries_6_V(AP_L3PHIC_nentries_6_V_dout),
  .allproj_nentries_7_V(AP_L3PHIC_nentries_7_V_dout),
  .bx_o_V(bx_out_MatchCalculator),
  .fullmatch1_dataarray_data_V_we0(FM_L1L2XX_L3PHIC_dataarray_data_V_wea),
  .fullmatch1_dataarray_data_V_address0(FM_L1L2XX_L3PHIC_dataarray_data_V_writeaddr),
  .fullmatch1_dataarray_data_V_d0(FM_L1L2XX_L3PHIC_dataarray_data_V_din),
  .fullmatch1_nentries_0_V_ap_vld(FM_L1L2XX_L3PHIC_nentries_0_V_we),
  .fullmatch1_nentries_0_V(FM_L1L2XX_L3PHIC_nentries_0_V_din),
  .fullmatch1_nentries_1_V_ap_vld(FM_L1L2XX_L3PHIC_nentries_1_V_we),
  .fullmatch1_nentries_1_V(FM_L1L2XX_L3PHIC_nentries_1_V_din),
  .fullmatch3_dataarray_data_V_we0(FM_L5L6XX_L3PHIC_dataarray_data_V_wea),
  .fullmatch3_dataarray_data_V_address0(FM_L5L6XX_L3PHIC_dataarray_data_V_writeaddr),
  .fullmatch3_dataarray_data_V_d0(FM_L5L6XX_L3PHIC_dataarray_data_V_din),
  .fullmatch3_nentries_0_V_ap_vld(FM_L5L6XX_L3PHIC_nentries_0_V_we),
  .fullmatch3_nentries_0_V(FM_L5L6XX_L3PHIC_nentries_0_V_din),
  .fullmatch3_nentries_1_V_ap_vld(FM_L5L6XX_L3PHIC_nentries_1_V_we),
  .fullmatch3_nentries_1_V(FM_L5L6XX_L3PHIC_nentries_1_V_din)
);

// FM memories
Memory #(
  .RAM_WIDTH(45),
  .RAM_DEPTH(256),
  .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
  .HEX(0),
  .INIT_FILE("")
) FM_L1L2XX_L3PHIC (
  .clka(clk),
  .clkb(clk),
  .wea(FM_L1L2XX_L3PHIC_dataarray_data_V_wea),
  .addra(FM_L1L2XX_L3PHIC_dataarray_data_V_writeaddr),
  .dina(FM_L1L2XX_L3PHIC_dataarray_data_V_din),
  .nent_we0(FM_L1L2XX_L3PHIC_nentries_0_V_we),
  .nent_i0(FM_L1L2XX_L3PHIC_nentries_0_V_din),
  .nent_we1(FM_L1L2XX_L3PHIC_nentries_1_V_we),
  .nent_i1(FM_L1L2XX_L3PHIC_nentries_1_V_din),
  .enb(FM_L1L2XX_L3PHIC_dataarray_data_V_enb),
  .addrb(FM_L1L2XX_L3PHIC_dataarray_data_V_readaddr),
  .doutb(FM_L1L2XX_L3PHIC_dataarray_data_V_dout),
  .nent_o0(FM_L1L2XX_L3PHIC_nentries_0_V_dout),
  .nent_o1(FM_L1L2XX_L3PHIC_nentries_1_V_dout),
  .regceb(1'b1)
);

Memory #(
  .RAM_WIDTH(45),
  .RAM_DEPTH(256),
  .RAM_PERFORMANCE("HIGH_PERFORMANCE"),
  .HEX(0),
  .INIT_FILE("")
) FM_L1L2XX_L3PHIC (
  .clka(clk),
  .clkb(clk),
  .wea(FM_L5L6XX_L3PHIC_dataarray_data_V_wea),
  .addra(FM_L5L6XX_L3PHIC_dataarray_data_V_writeaddr),
  .dina(FM_L5L6XX_L3PHIC_dataarray_data_V_din),
  .nent_we0(FM_L5L6XX_L3PHIC_nentries_0_V_we),
  .nent_i0(FM_L5L6XX_L3PHIC_nentries_0_V_din),
  .nent_we1(FM_L5L6XX_L3PHIC_nentries_1_V_we),
  .nent_i1(FM_L5L6XX_L3PHIC_nentries_1_V_din),
  .enb(FM_L5L6XX_L3PHIC_dataarray_data_V_enb),
  .addrb(FM_L5L6XX_L3PHIC_dataarray_data_V_readaddr),
  .doutb(FM_L5L6XX_L3PHIC_dataarray_data_V_dout),
  .nent_o0(FM_L5L6XX_L3PHIC_nentries_0_V_dout),
  .nent_o1(FM_L5L6XX_L3PHIC_nentries_1_V_dout),
  .regceb(1'b1)
);

endmodule
