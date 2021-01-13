--===========================================================================
--! @file
--! @brief 2-page (RAM_DEPTH=256) or 8-page (RAM_DEPTH=1024) binned memory module 
--!        which stores data between the algorithm steps in the Hybrid L1 
--!        Tracking algorithm. Based on the MemoryBinned.v module. 
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
--! Standard functions
library std;
--! Standard TextIO functions
use std.textio.all;

--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;

--! User packages
use work.tf_pkg.all;

entity tf_mem_bin is
  generic (
    RAM_WIDTH       : natural := 14;               --! Specify RAM data width
    RAM_DEPTH       : natural := 1024;             --! Specify RAM depth (number of entries)
    INIT_FILE       : string := "";                --! Specify name/location of RAM initialization file if using one (leave blank if not)
    INIT_HEX        : boolean := true;             --! Read init file in hex (default) or bin
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE" --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
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
    nent_o  : out t_arr8_8_5b                                     --! Num entries (page)(bin)
    );
end tf_mem_bin;

architecture rtl of tf_mem_bin is

-- ########################### Types ###########################
type t_arr_1d_slv_mem is array(0 to RAM_DEPTH-1) of std_logic_vector(RAM_WIDTH-1 downto 0); --! 1D array of slv

-- ########################### Function ##########################
--! @brief TextIO function to read memory data to initialize tf_mem_bin. Needed here because of variable slv width!
impure function read_tf_mem_data (
file_path : string;      --! File path as string
hex_val   : boolean)     --! Read file vales as hex or bin
return t_arr_1d_slv_mem is --! Dataarray with read values
  file     file_in  : text ;                                           -- Text - a file of character strings
  variable line_in  : line;                                            -- Line - one string from a text file
  variable char     : character;                                       -- Character
  variable i_bx_row : natural;                                         -- Read row index
  variable data_arr : t_arr_1d_slv_mem := (others => (others => '0')); -- Output RAM array
begin
  if (file_path /= "") then
    i_bx_row := 0; -- Init
    file_open(file_in, file_path, READ_MODE);
    l_rd_row : while not endfile(file_in) loop -- Read until EoF
      readline (file_in, line_in);
      if (hex_val=true) then
        if (line_in'length > 1) then
          read(line_in, char); read(line_in, char); -- Read '0' and 'x' chars
          hread(line_in, data_arr(i_bx_row)(RAM_WIDTH-1 downto 0)); -- Read value as hex slv (line_in'length in hex)
        else
          data_arr(i_bx_row) := (others => '0');
        end if;
      else
        read(line_in, data_arr(i_bx_row)(RAM_WIDTH-1 downto 0)); -- Read value as bin slv
      end if;
      i_bx_row := i_bx_row +1;
    end loop l_rd_row;
    file_close(file_in);
  else
    data_arr := (others => (others => '0'));
  end if;
  return data_arr;
end read_tf_mem_data;

-- ########################### Signals ###########################
signal sa_RAM_data : t_arr_1d_slv_mem := read_tf_mem_data(INIT_FILE, INIT_HEX);         --! RAM data content
signal sv_RAM_row  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');          --! RAM data row
signal sv_addra_d1 : std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0) := (others => '0'); --! Write address bus delayed

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_RAM_data : signal is "block";

begin



process(clkb)
begin
  if rising_edge(clkb) then
    if (enb='1') then
      sv_RAM_row <= sa_RAM_data(to_integer(unsigned(addrb)));
    end if;
  end if;
end process;

-- The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
MODE : if (RAM_PERFORMANCE = "LOW_LATENCY") generate -- no_output_register; 1 clock cycle read latency at the cost of a longer clock-to-out timing
  doutb <= sv_RAM_row;
else generate -- output_register; 2 clock cycle read latency with improve clock-to-out timing
  process(clkb)
  begin
    if rising_edge(clkb) then
      if (rstb='1') then
        doutb <= (others => '0');
      elsif (regceb='1') then
        doutb <= sv_RAM_row;
      end if;
    end if;
  end process;
end generate MODE;

end rtl;