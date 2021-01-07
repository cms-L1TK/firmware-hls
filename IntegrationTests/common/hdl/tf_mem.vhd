--===========================================================================
--! @file
--! @brief Memory module which stores data between the algorithm steps in the 
--!        Hybrid L1 Tracking algorithm. Based on the Memory.v module.
--! @author robert.glein@colorado.edu
--! @date 2021-01-05
--! @version v.1.0
--===========================================================================

--! Standard library
library ieee;
--! Standard package
use ieee.std_logic_1164.all;
--! Signed/unsigned calculations
use ieee.numeric_std.all;

--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;

--! User packages
use work.tf_pkg.all;

entity tf_mem is
  generic (
    RAM_WIDTH       : integer := 18;                --! Specify RAM data width
    RAM_DEPTH       : integer := 1024;              --! Specify RAM depth (number of entries)
    INIT_FILE       : string := "";                 --! Specify name/location of RAM initialization file if using one (leave blank if not)
    INIT_HEX        : integer := 1;                 --! Read init file in hex (default) or bin
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE"; --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
    COUNT_NENT      : integer := 0                  --! Count number of entries internally. Ignores input ports nent_ix and nent_wex.
    );
  port (
    clka    : in  std_logic;                                      --! Write clock
    clkb    : in  std_logic;                                      --! Read clock
    wea     : in  std_logic;                                      --! Write enable
    enb     : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    rstb    : in  std_logic;                                      --! Output reset (does not affect memory contents)
    regceb  : in  std_logic;                                      --! Output register enable
    addra   : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Write address bus, width determined from RAM_DEPTH
    dina    : in  std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM input data
    addrb   : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    doutb   : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    nent_i  : in  t_arr8_8b;                                      --! Num entries received
    nent_we : in  std_logic_vector(7 downto 0);                   --! Write enable
    nent_o  : out t_arr8_8b                                       --! Num entries per page
    );
end tf_mem;

architecture rtl of tf_mem is

-- ########################### Types ###########################
type t_arr_2D  is array(RAM_DEPTH-1 downto 0) of std_logic_vector(RAM_WIDTH-1 downto 0);

-- ########################### Signals ###########################
signal sa_BRAM     : t_arr_2D;                               --! BRAM content
signal sv_RAM_data : std_logic_vector(RAM_WIDTH-1 downto 0); --! RAM data
signal nent        : t_arr8_8b;                              --! Number of entries

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_BRAM : signal is "block";


begin

doutb <= (others => '0');


--  // The following code either initializes the memory values to a specified file or to all zeros to match hardware
--  generate
--    if (INIT_FILE != "") begin: use_init_file
--      initial
--        if (INIT_HEX)
--            $readmemh(INIT_FILE, BRAM, 0, RAM_DEPTH-1);
--        else
--            $readmemb(INIT_FILE, BRAM, 0, RAM_DEPTH-1);
--    end else begin: init_bram_to_zero
--      integer ram_index;
--      initial
--        for (ram_index = 0; ram_index < RAM_DEPTH; ram_index = ram_index + 1)
--          BRAM[ram_index] = {RAM_WIDTH{1'b0}};
--    end
--  endgenerate


--  always @(posedge clka) begin
--    if (wea) begin
--      BRAM[addra] <= dina;
--    end
--  end


--  generate 
--    if (COUNT_NENT == 0) begin // Use nent input ports
--      always @(posedge clka) begin
--        if (nent_we0)
--          nent[0] <= nent_i0;
--        if (nent_we1)
--          nent[1] <= nent_i1;
--        if (nent_we2)
--          nent[2] <= nent_i2;
--        if (nent_we3)
--          nent[3] <= nent_i3;
--        if (nent_we4)
--          nent[4] <= nent_i4;
--        if (nent_we5)
--          nent[5] <= nent_i5;
--        if (nent_we6)
--          nent[6] <= nent_i6;
--        if (nent_we7)
--          nent[7] <= nent_i7;
--      end
--    end else begin // Count number of entries internally 
--      always @(posedge clka) begin
--        if (wea) begin
--          case (addra) inside
--           [1:0]: reg_out <= data_a;
--           [3:2]: reg_out <= data_b;
--          endcase
--          nent <= nent+1;
--        end
--      end
--    end
--  endgenerate


--  always @(posedge clkb)
--    if (enb)
--    begin
--      ram_data <= BRAM[addrb];
--    end

--  assign nent_o0 = nent[0];
--  assign nent_o1 = nent[1];
--  assign nent_o2 = nent[2];
--  assign nent_o3 = nent[3];
--  assign nent_o4 = nent[4];
--  assign nent_o5 = nent[5];
--  assign nent_o6 = nent[6];
--  assign nent_o7 = nent[7];

--  //  The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
--  generate
--    if (RAM_PERFORMANCE == "LOW_LATENCY") begin: no_output_register

--      // The following is a 1 clock cycle read latency at the cost of a longer clock-to-out timing
--       assign doutb = ram_data;

--    end else begin: output_register

--      // The following is a 2 clock cycle read latency with improve clock-to-out timing

--      reg [RAM_WIDTH-1:0] doutb_reg = {RAM_WIDTH{1'b0}};

--      always @(posedge clkb)
--        if (rstb)
--          doutb_reg <= {RAM_WIDTH{1'b0}};
--        else if (regceb)
--          doutb_reg <= ram_data;

--      assign doutb = doutb_reg;

--    end
--  endgenerate


--endmodule

end rtl;