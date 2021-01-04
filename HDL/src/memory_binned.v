`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 01/17/2020
// Module Name: MemoryBinned
// Project Name: L1 Tracking
// Target Devices: xcvu7p-flvb2104-1-e 
// Description: Binned Memory modules which store data between the algorithm steps in the Hybrid L1 Tracking algorithm
// Revision:
// 0.01 - File imported from Tracklet 1.0, n_ent ports added.
// 0.02 - Add 8 page support.
// 0.03 - Add parameter for counting n_ent (n_ent input ports are ignored if true).
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module myMemoryBinned #(
  parameter RAM_WIDTH = 14,                       // Specify RAM data width, VM Stub: 14 for Barral LPS, 15 for Barral L2S/DISK
  parameter RAM_DEPTH = 1024,                     // Specify RAM depth (number of entries) 1024 is for 8 pages
  parameter INIT_FILE = "",                       // Specify name/location of RAM initialization file if using one (leave blank if not)
  parameter INIT_HEX = 1,                         // Read init file in hex (default) or bin
  parameter RAM_PERFORMANCE = "HIGH_PERFORMANCE", // Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
  parameter COUNT_NENT = 0                        // Count number of entries internally. Ignores input ports nent_ix and nent_wex.
) (
  input [clogb2(RAM_DEPTH)-1:0] addra, // Write address bus, width determined from RAM_DEPTH
  input [clogb2(RAM_DEPTH)-1:0] addrb, // Read address bus, width determined from RAM_DEPTH
  input [RAM_WIDTH-1:0] 	dina, // RAM input data
  input 			clka, // Write clock
  input 			clkb, // Read clock
  input 			wea, // Write enable
  input 			enb, // Read Enable, for additional power savings, disable when not in use
  input 			rstb, // Output reset (does not affect memory contents)
  input 			regceb, // Output register enable
  input [3:0] 			nent_0_i0, // Num entries received
  input 			nent_0_we0, // Write enable
  output [3:0] 			nent_0_o0, // Num entries for page 0 [4 bits each]
  input [3:0] 			nent_0_i1, // Num entries received
  input 			nent_0_we1, // Write enable
  output [3:0] 			nent_0_o1, // Num entries for page 0 [4 bits each]
  input [3:0] 			nent_0_i2, // Num entries received
  input 			nent_0_we2, // Write enable
  output [3:0] 			nent_0_o2, // Num entries for page 0 [4 bits each]
  input [3:0] 			nent_0_i3, // Num entries received
  input 			nent_0_we3, // Write enable
  output [3:0] 			nent_0_o3, // Num entries for page 0 [4 bits each]      
  input [3:0] 			nent_0_i4, // Num entries received
  input 			nent_0_we4, // Write enable
  output [3:0] 			nent_0_o4, // Num entries for page 0 [4 bits each]      
  input [3:0] 			nent_0_i5, // Num entries received
  input 			nent_0_we5, // Write enable
  output [3:0] 			nent_0_o5, // Num entries for page 0 [4 bits each]      
  input [3:0] 			nent_0_i6, // Num entries received
  input 			nent_0_we6, // Write enable
  output [3:0] 			nent_0_o6, // Num entries for page 0 [4 bits each]      
  input [3:0] 			nent_0_i7, // Num entries received
  input 			nent_0_we7, // Write enable
  output [3:0] 			nent_0_o7, // Num entries for page 0 [4 bits each]      
  input [3:0] 			nent_1_i0, // Num entries received
  input 			nent_1_we0, // Write enable
  output [3:0] 			nent_1_o0, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i1, // Num entries received
  input 			nent_1_we1, // Write enable
  output [3:0] 			nent_1_o1, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i2, // Num entries received
  input 			nent_1_we2, // Write enable
  output [3:0] 			nent_1_o2, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i3, // Num entries received
  input 			nent_1_we3, // Write enable
  output [3:0] 			nent_1_o3, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i4, // Num entries received
  input 			nent_1_we4, // Write enable
  output [3:0] 			nent_1_o4, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i5, // Num entries received
  input 			nent_1_we5, // Write enable
  output [3:0] 			nent_1_o5, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i6, // Num entries received
  input 			nent_1_we6, // Write enable
  output [3:0] 			nent_1_o6, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_1_i7, // Num entries received
  input 			nent_1_we7, // Write enable
  output [3:0] 			nent_1_o7, // Num entries for page 1 [4 bits each]
  input [3:0] 			nent_2_i0, // Num entries received
  input 			nent_2_we0, // Write enable
  output [3:0] 			nent_2_o0, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i1, // Num entries received
  input 			nent_2_we1, // Write enable
  output [3:0] 			nent_2_o1, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i2, // Num entries received
  input 			nent_2_we2, // Write enable
  output [3:0] 			nent_2_o2, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i3, // Num entries received
  input 			nent_2_we3, // Write enable
  output [3:0] 			nent_2_o3, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i4, // Num entries received
  input 			nent_2_we4, // Write enable
  output [3:0] 			nent_2_o4, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i5, // Num entries received
  input 			nent_2_we5, // Write enable
  output [3:0] 			nent_2_o5, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i6, // Num entries received
  input 			nent_2_we6, // Write enable
  output [3:0] 			nent_2_o6, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_2_i7, // Num entries received
  input 			nent_2_we7, // Write enable
  output [3:0] 			nent_2_o7, // Num entries for page 2 [4 bits each]
  input [3:0] 			nent_3_i0, // Num entries received
  input 			nent_3_we0, // Write enable
  output [3:0] 			nent_3_o0, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i1, // Num entries received
  input 			nent_3_we1, // Write enable
  output [3:0] 			nent_3_o1, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i2, // Num entries received
  input 			nent_3_we2, // Write enable
  output [3:0] 			nent_3_o2, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i3, // Num entries received
  input 			nent_3_we3, // Write enable
  output [3:0] 			nent_3_o3, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i4, // Num entries received
  input 			nent_3_we4, // Write enable
  output [3:0] 			nent_3_o4, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i5, // Num entries received
  input 			nent_3_we5, // Write enable
  output [3:0] 			nent_3_o5, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i6, // Num entries received
  input 			nent_3_we6, // Write enable
  output [3:0] 			nent_3_o6, // Num entries for page 3 [4 bits each]
  input [3:0] 			nent_3_i7, // Num entries received
  input 			nent_3_we7, // Write enable
  output [3:0] 			nent_3_o7, // Num entries for page 3 [4 bits each]
  input [3:0]       nent_4_i0, // Num entries received
  input       nent_4_we0, // Write enable
  output [3:0]      nent_4_o0, // Num entries for page 4 [4 bits each]
  input [3:0]       nent_4_i1, // Num entries received
  input       nent_4_we1, // Write enable
  output [3:0]      nent_4_o1, // Num entries for page 4 [4 bits each]
  input [3:0]       nent_4_i2, // Num entries received
  input       nent_4_we2, // Write enable
  output [3:0]      nent_4_o2, // Num entries for page 4 [4 bits each]
  input [3:0]       nent_4_i3, // Num entries received
  input       nent_4_we3, // Write enable
  output [3:0]      nent_4_o3, // Num entries for page 4 [4 bits each]      
  input [3:0]       nent_4_i4, // Num entries received
  input       nent_4_we4, // Write enable
  output [3:0]      nent_4_o4, // Num entries for page 4 [4 bits each]      
  input [3:0]       nent_4_i5, // Num entries received
  input       nent_4_we5, // Write enable
  output [3:0]      nent_4_o5, // Num entries for page 4 [4 bits each]      
  input [3:0]       nent_4_i6, // Num entries received
  input       nent_4_we6, // Write enable
  output [3:0]      nent_4_o6, // Num entries for page 4 [4 bits each]      
  input [3:0]       nent_4_i7, // Num entries received
  input       nent_4_we7, // Write enable
  output [3:0]      nent_4_o7, // Num entries for page 4 [4 bits each]      
  input [3:0]       nent_5_i0, // Num entries received
  input       nent_5_we0, // Write enable
  output [3:0]      nent_5_o0, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i1, // Num entries received
  input       nent_5_we1, // Write enable
  output [3:0]      nent_5_o1, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i2, // Num entries received
  input       nent_5_we2, // Write enable
  output [3:0]      nent_5_o2, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i3, // Num entries received
  input       nent_5_we3, // Write enable
  output [3:0]      nent_5_o3, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i4, // Num entries received
  input       nent_5_we4, // Write enable
  output [3:0]      nent_5_o4, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i5, // Num entries received
  input       nent_5_we5, // Write enable
  output [3:0]      nent_5_o5, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i6, // Num entries received
  input       nent_5_we6, // Write enable
  output [3:0]      nent_5_o6, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_5_i7, // Num entries received
  input       nent_5_we7, // Write enable
  output [3:0]      nent_5_o7, // Num entries for page 5 [4 bits each]
  input [3:0]       nent_6_i0, // Num entries received
  input       nent_6_we0, // Write enable
  output [3:0]      nent_6_o0, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i1, // Num entries received
  input       nent_6_we1, // Write enable
  output [3:0]      nent_6_o1, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i2, // Num entries received
  input       nent_6_we2, // Write enable
  output [3:0]      nent_6_o2, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i3, // Num entries received
  input       nent_6_we3, // Write enable
  output [3:0]      nent_6_o3, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i4, // Num entries received
  input       nent_6_we4, // Write enable
  output [3:0]      nent_6_o4, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i5, // Num entries received
  input       nent_6_we5, // Write enable
  output [3:0]      nent_6_o5, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i6, // Num entries received
  input       nent_6_we6, // Write enable
  output [3:0]      nent_6_o6, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_6_i7, // Num entries received
  input       nent_6_we7, // Write enable
  output [3:0]      nent_6_o7, // Num entries for page 6 [4 bits each]
  input [3:0]       nent_7_i0, // Num entries received
  input       nent_7_we0, // Write enable
  output [3:0]      nent_7_o0, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i1, // Num entries received
  input       nent_7_we1, // Write enable
  output [3:0]      nent_7_o1, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i2, // Num entries received
  input       nent_7_we2, // Write enable
  output [3:0]      nent_7_o2, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i3, // Num entries received
  input       nent_7_we3, // Write enable
  output [3:0]      nent_7_o3, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i4, // Num entries received
  input       nent_7_we4, // Write enable
  output [3:0]      nent_7_o4, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i5, // Num entries received
  input       nent_7_we5, // Write enable
  output [3:0]      nent_7_o5, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i6, // Num entries received
  input       nent_7_we6, // Write enable
  output [3:0]      nent_7_o6, // Num entries for page 7 [4 bits each]
  input [3:0]       nent_7_i7, // Num entries received
  input       nent_7_we7, // Write enable
  output [3:0]      nent_7_o7, // Num entries for page 7 [4 bits each] 
  output [RAM_WIDTH-1:0] 	doutb         // RAM output data
);

  (* ram_style = "block" *) reg [RAM_WIDTH-1:0] BRAM [RAM_DEPTH-1:0];
  reg [RAM_WIDTH-1:0] ram_data = {RAM_WIDTH{1'b0}};
  reg [7:0] nent_0[7:0];
  reg [7:0] nent_1[7:0];
  reg [7:0] nent_2[7:0];
  reg [7:0] nent_3[7:0];
  reg [7:0] nent_4[7:0];
  reg [7:0] nent_5[7:0];
  reg [7:0] nent_6[7:0];
  reg [7:0] nent_7[7:0];
   

  // The following code either initializes the memory values to a specified file or to all zeros to match hardware
  generate
    if (INIT_FILE != "") begin: use_init_file
      initial
        if (INIT_HEX)
            $readmemh(INIT_FILE, BRAM, 0, RAM_DEPTH-1);
        else
            $readmemb(INIT_FILE, BRAM, 0, RAM_DEPTH-1);
    end else begin: init_bram_to_zero
      integer ram_index;
      initial
        for (ram_index = 0; ram_index < RAM_DEPTH; ram_index = ram_index + 1)
          BRAM[ram_index] = {RAM_WIDTH{1'b0}};
    end
  endgenerate

  always @(posedge clka) begin
     if (wea)
       begin
	  BRAM[addra] <= dina;
       end
     if (nent_0_we0)
       nent_0[0] <= nent_0_i0;
     if (nent_0_we1)
       nent_0[1] <= nent_0_i1;
     if (nent_0_we2)
       nent_0[2] <= nent_0_i2;
     if (nent_0_we3)
       nent_0[3] <= nent_0_i3;
     if (nent_0_we4)
       nent_0[4] <= nent_0_i4;
     if (nent_0_we5)
       nent_0[5] <= nent_0_i5;
     if (nent_0_we6)
       nent_0[6] <= nent_0_i6;
     if (nent_0_we7)
       nent_0[7] <= nent_0_i7;
     
     if (nent_1_we0)
       nent_1[0] <= nent_1_i0;
     if (nent_1_we1)
       nent_1[1] <= nent_1_i1;
     if (nent_1_we2)
       nent_1[2] <= nent_1_i2;
     if (nent_1_we3)
       nent_1[3] <= nent_1_i3;
     if (nent_1_we4)
       nent_1[4] <= nent_1_i4;
     if (nent_1_we5)
       nent_1[5] <= nent_1_i5;
     if (nent_1_we6)
       nent_1[6] <= nent_1_i6;
     if (nent_1_we7)
       nent_1[7] <= nent_1_i7;

     if (nent_2_we0)
       nent_2[0] <= nent_2_i0;
    if (nent_2_we1)
      nent_2[1] <= nent_2_i1;
    if (nent_2_we2)
      nent_2[2] <= nent_2_i2;
    if (nent_2_we3)
      nent_2[3] <= nent_2_i3;
    if (nent_2_we4)
      nent_2[4] <= nent_2_i4;
    if (nent_2_we5)
      nent_2[5] <= nent_2_i5;
    if (nent_2_we6)
      nent_2[6] <= nent_2_i6;
    if (nent_2_we7)
      nent_2[7] <= nent_2_i7;

     if (nent_3_we0)
       nent_3[0] <= nent_3_i0;
    if (nent_3_we1)
      nent_3[1] <= nent_3_i1;
    if (nent_3_we2)
      nent_3[2] <= nent_3_i2;
    if (nent_3_we3)
      nent_3[3] <= nent_3_i3;
    if (nent_3_we4)
      nent_3[4] <= nent_3_i4;
    if (nent_3_we5)
      nent_3[5] <= nent_3_i5;
    if (nent_3_we6)
      nent_3[6] <= nent_3_i6;
    if (nent_3_we7)
      nent_3[7] <= nent_3_i7;

    if (nent_4_we0)
       nent_4[0] <= nent_4_i0;
     if (nent_4_we1)
       nent_4[1] <= nent_4_i1;
     if (nent_4_we2)
       nent_4[2] <= nent_4_i2;
     if (nent_4_we3)
       nent_4[3] <= nent_4_i3;
     if (nent_4_we4)
       nent_4[4] <= nent_4_i4;
     if (nent_4_we5)
       nent_4[5] <= nent_4_i5;
     if (nent_4_we6)
       nent_4[6] <= nent_4_i6;
     if (nent_4_we7)
       nent_4[7] <= nent_4_i7;
     
     if (nent_5_we0)
       nent_5[0] <= nent_5_i0;
     if (nent_5_we1)
       nent_5[1] <= nent_5_i1;
     if (nent_5_we2)
       nent_5[2] <= nent_5_i2;
     if (nent_5_we3)
       nent_5[3] <= nent_5_i3;
     if (nent_5_we4)
       nent_5[4] <= nent_5_i4;
     if (nent_5_we5)
       nent_5[5] <= nent_5_i5;
     if (nent_5_we6)
       nent_5[6] <= nent_5_i6;
     if (nent_5_we7)
       nent_5[7] <= nent_5_i7;

     if (nent_6_we0)
       nent_6[0] <= nent_6_i0;
    if (nent_6_we1)
      nent_6[1] <= nent_6_i1;
    if (nent_6_we2)
      nent_6[2] <= nent_6_i2;
    if (nent_6_we3)
      nent_6[3] <= nent_6_i3;
    if (nent_6_we4)
      nent_6[4] <= nent_6_i4;
    if (nent_6_we5)
      nent_6[5] <= nent_6_i5;
    if (nent_6_we6)
      nent_6[6] <= nent_6_i6;
    if (nent_6_we7)
      nent_6[7] <= nent_6_i7;

     if (nent_7_we0)
       nent_7[0] <= nent_7_i0;
    if (nent_7_we1)
      nent_7[1] <= nent_7_i1;
    if (nent_7_we2)
      nent_7[2] <= nent_7_i2;
    if (nent_7_we3)
      nent_7[3] <= nent_7_i3;
    if (nent_7_we4)
      nent_7[4] <= nent_7_i4;
    if (nent_7_we5)
      nent_7[5] <= nent_7_i5;
    if (nent_7_we6)
      nent_7[6] <= nent_7_i6;
    if (nent_7_we7)
      nent_7[7] <= nent_7_i7;
     
  end

   always @(posedge clkb)
     if (enb)
       begin
	  ram_data <= BRAM[addrb];
       end

   assign nent_0_o0 = nent_0[0];
   assign nent_0_o1 = nent_0[1];
   assign nent_0_o2 = nent_0[2];
   assign nent_0_o3 = nent_0[3];
   assign nent_0_o4 = nent_0[4];
   assign nent_0_o5 = nent_0[5];
   assign nent_0_o6 = nent_0[6];
   assign nent_0_o7 = nent_0[7];

   assign nent_1_o0 = nent_1[0];
   assign nent_1_o1 = nent_1[1];
   assign nent_1_o2 = nent_1[2];
   assign nent_1_o3 = nent_1[3];
   assign nent_1_o4 = nent_1[4];
   assign nent_1_o5 = nent_1[5];
   assign nent_1_o6 = nent_1[6];
   assign nent_1_o7 = nent_1[7];

   assign nent_2_o0 = nent_2[0];
   assign nent_2_o1 = nent_2[1];
   assign nent_2_o2 = nent_2[2];
   assign nent_2_o3 = nent_2[3];
   assign nent_2_o4 = nent_2[4];
   assign nent_2_o5 = nent_2[5];
   assign nent_2_o6 = nent_2[6];
   assign nent_2_o7 = nent_2[7];

   assign nent_3_o0 = nent_3[0];
   assign nent_3_o1 = nent_3[1];
   assign nent_3_o2 = nent_3[2];
   assign nent_3_o3 = nent_3[3];
   assign nent_3_o4 = nent_3[4];
   assign nent_3_o5 = nent_3[5];
   assign nent_3_o6 = nent_3[6];
   assign nent_3_o7 = nent_3[7];

   assign nent_4_o0 = nent_4[0];
   assign nent_4_o1 = nent_4[1];
   assign nent_4_o2 = nent_4[2];
   assign nent_4_o3 = nent_4[3];
   assign nent_4_o4 = nent_4[4];
   assign nent_4_o5 = nent_4[5];
   assign nent_4_o6 = nent_4[6];
   assign nent_4_o7 = nent_4[7];

   assign nent_5_o0 = nent_5[0];
   assign nent_5_o1 = nent_5[1];
   assign nent_5_o2 = nent_5[2];
   assign nent_5_o3 = nent_5[3];
   assign nent_5_o4 = nent_5[4];
   assign nent_5_o5 = nent_5[5];
   assign nent_5_o6 = nent_5[6];
   assign nent_5_o7 = nent_5[7];

   assign nent_6_o0 = nent_6[0];
   assign nent_6_o1 = nent_6[1];
   assign nent_6_o2 = nent_6[2];
   assign nent_6_o3 = nent_6[3];
   assign nent_6_o4 = nent_6[4];
   assign nent_6_o5 = nent_6[5];
   assign nent_6_o6 = nent_6[6];
   assign nent_6_o7 = nent_6[7];

   assign nent_7_o0 = nent_7[0];
   assign nent_7_o1 = nent_7[1];
   assign nent_7_o2 = nent_7[2];
   assign nent_7_o3 = nent_7[3];
   assign nent_7_o4 = nent_7[4];
   assign nent_7_o5 = nent_7[5];
   assign nent_7_o6 = nent_7[6];
   assign nent_7_o7 = nent_7[7];

   
  //  The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
  generate
    if (RAM_PERFORMANCE == "LOW_LATENCY") begin: no_output_register

      // The following is a 1 clock cycle read latency at the cost of a longer clock-to-out timing
       assign doutb = ram_data;

    end else begin: output_register

      // The following is a 2 clock cycle read latency with improve clock-to-out timing

      reg [RAM_WIDTH-1:0] doutb_reg = {RAM_WIDTH{1'b0}};

      always @(posedge clkb)
        if (rstb)
          doutb_reg <= {RAM_WIDTH{1'b0}};
        else if (regceb)
          doutb_reg <= ram_data;

      assign doutb = doutb_reg;

    end
  endgenerate

  //  The following function calculates the address width based on specified RAM depth
  function integer clogb2;
    input integer depth;
      for (clogb2=0; depth>1; clogb2=clogb2+1)
        depth = depth >> 1;
  endfunction

endmodule
