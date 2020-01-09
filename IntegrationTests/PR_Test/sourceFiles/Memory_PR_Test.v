`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2014 01:08:52 PM
// Design Name: 
// Module Name: Memory
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Memory #(
  parameter RAM_WIDTH = 18,                       // Specify RAM data width
  parameter RAM_DEPTH = 1024,                     // Specify RAM depth (number of entries)
  parameter INIT_FILE = "",                       // Specify name/location of RAM initialization file if using one (leave blank if not)
  parameter RAM_PERFORMANCE = "HIGH_PERFORMANCE",  // Select "HIGH_PERFORMANCE" or "LOW_LATENCY"
  parameter HEX = 1

) (
  input [clogb2(RAM_DEPTH)-1:0] addra, // Write address bus, width determined from RAM_DEPTH
  input [clogb2(RAM_DEPTH)-1:0] addrb, // Read address bus, width determined from RAM_DEPTH
  input [RAM_WIDTH-1:0] dina,          // RAM input data
  input clka,                          // Write clock
  input clkb,                          // Read clock
  input wea,                           // Write enable
  input enb,                           // Read Enable, for additional power savings, disable when not in use
  input rstb,                          // Output reset (does not affect memory contents)
  input regceb,                        // Output register enable
  input [7:0]nent_i0,                   // Num entries received
  input nent_we0,                       // Write enable
  output [7:0]nent_o0,                  // Num entries per page [4 bits each]
  input [7:0]nent_i1,                   // Num entries received
  input nent_we1,                       // Write enable
  output [7:0]nent_o1,                  // Num entries per page [4 bits each]
  input [7:0]nent_i2,                   // Num entries received
  input nent_we2,                       // Write enable
  output [7:0]nent_o2,                  // Num entries per page [4 bits each]
  input [7:0]nent_i3,                   // Num entries received
  input nent_we3,                       // Write enable
  output [7:0]nent_o3,                  // Num entries per page [4 bits each]      
  input [7:0]nent_i4,                   // Num entries received
  input nent_we4,                       // Write enable
  output [7:0]nent_o4,                  // Num entries per page [4 bits each]      
  input [7:0]nent_i5,                   // Num entries received
  input nent_we5,                       // Write enable
  output [7:0]nent_o5,                  // Num entries per page [4 bits each]      
  input [7:0]nent_i6,                   // Num entries received
  input nent_we6,                       // Write enable
  output [7:0]nent_o6,                  // Num entries per page [4 bits each]      
  input [7:0]nent_i7,                   // Num entries received
  input nent_we7,                       // Write enable
  output [7:0]nent_o7,                  // Num entries per page [4 bits each]      
  output [RAM_WIDTH-1:0] doutb         // RAM output data
);

  (* ram_style = "block" *) reg [RAM_WIDTH-1:0] BRAM [RAM_DEPTH-1:0];
  reg [RAM_WIDTH-1:0] ram_data = {RAM_WIDTH{1'b0}};
  reg [7:0] nent[7:0];

  // The following code either initializes the memory values to a specified file or to all zeros to match hardware
  generate
    if (INIT_FILE != "") begin: use_init_file
      initial
        if (HEX)
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
    if (nent_we0)
      nent[0] <= nent_i0;
    if (nent_we1)
      nent[1] <= nent_i1;
    if (nent_we2)
      nent[2] <= nent_i2;
    if (nent_we3)
      nent[3] <= nent_i3;
    if (nent_we4)
      nent[4] <= nent_i4;
    if (nent_we5)
      nent[5] <= nent_i5;
    if (nent_we6)
      nent[6] <= nent_i6;
    if (nent_we7)
      nent[7] <= nent_i7;
  end

  always @(posedge clkb)
    if (enb)
    begin
      ram_data <= BRAM[addrb];
    end

  assign nent_o0 = nent[0];
  assign nent_o1 = nent[1];
  assign nent_o2 = nent[2];
  assign nent_o3 = nent[3];
  assign nent_o4 = nent[4];
  assign nent_o5 = nent[5];
  assign nent_o6 = nent[6];
  assign nent_o7 = nent[7];

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
