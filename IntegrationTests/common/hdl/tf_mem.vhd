--===========================================================================
--! @file
--! @brief 2-page (RAM_DEPTH=256) or 8-page (RAM_DEPTH=1024) memory module 
--!        which stores data between the algorithm steps in the Hybrid L1 
--!        Tracking algorithm. Based on the Memory.v module. 
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

entity tf_mem is
  generic (
    RAM_WIDTH       : natural := 18;               --! Specify RAM data width
    NUM_PAGES       : natural := 2;                --! Specify no. Pages in RAM memory
    RAM_DEPTH       : natural := NUM_PAGES*PAGE_LENGTH; --! Leave at default. RAM depth (no. of entries)
    INIT_FILE       : string := "";                --! Specify name/location of RAM initialization file if using one (leave blank if not)
    INIT_HEX        : boolean := true;             --! Read init file in hex (default) or bin
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE" --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
    );
  port (
    clka      : in  std_logic;                                      --! Write clock
    clkb      : in  std_logic;                                      --! Read clock
    wea       : in  std_logic;                                      --! Write enable
    enb       : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    rstb      : in  std_logic;                                      --! Output reset (does not affect memory contents)
    regceb    : in  std_logic;                                      --! Output register enable
    addra     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Write address bus, width determined from RAM_DEPTH
    dina      : in  std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM input data
    addrb     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    doutb     : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    sync_nent : in  std_logic;                                      --! Synchronize nent counter; Connect to start of reading module
    --nent_o    : out t_arr_meb(0 to NUM_PAGES-1) := (others => (others => '0'))
    nent_o    : out t_arr_7b(0 to NUM_PAGES-1) := (others => (others => '0')) --! entries per page
    );
end tf_mem;

architecture rtl of tf_mem is

-- ########################### Types ###########################
type t_arr_1d_slv_mem is array(0 to RAM_DEPTH-1) of std_logic_vector(RAM_WIDTH-1 downto 0); --! 1D array of slv

-- ########################### Function ##########################
--! @brief TextIO function to read memory data to initialize tf_mem. Needed here because of variable slv width!
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

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_RAM_data : signal is "block";

begin

-- Check user didn't change values of derived generics.
assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;

process(clka)
  variable vi_clk_cnt   : integer := -1; -- Clock counter
  variable vi_page_cnt  : integer := 0;  -- Page counter
  variable page         : integer := 0;
  variable addr_in_page : integer := 0;
begin
  if rising_edge(clka) then -- ######################################### Start counter initially
    if (sync_nent='1') and vi_clk_cnt=-1 then
      vi_clk_cnt := 0;
    end if;
    if (vi_clk_cnt >=0) and (vi_clk_cnt < MAX_ENTRIES-1) then -- ####### Counter nent
      vi_clk_cnt := vi_clk_cnt+1;
    elsif (vi_clk_cnt >= MAX_ENTRIES-1) then -- -1 not included
      vi_clk_cnt := 0;
      nent_o(vi_page_cnt) <= (others => '0');
      assert (vi_page_cnt < NUM_PAGES) report "vi_page_cnt out of range" severity error;
      if (vi_page_cnt < NUM_PAGES-1) then -- Assuming linear continuous page access
        vi_page_cnt := vi_page_cnt +1;
      else
        vi_page_cnt := 0;
      end if;
    end if;
    if (wea='1') then
      sa_RAM_data(to_integer(unsigned(addra))) <= dina; -- Write data
      -- Count entries
      page := to_integer(unsigned(addra(clogb2(RAM_DEPTH)-1 downto clogb2(PAGE_LENGTH))));
      addr_in_page := to_integer(unsigned(addra(clogb2(PAGE_LENGTH)-1 downto 0)));
      assert (page < NUM_PAGES) report "page out of range" severity error;
      if (addr_in_page = 0) then
        nent_o(page) <= std_logic_vector(to_unsigned(1, nent_o(page)'length)); -- <= 1 (slv)
      else
        nent_o(page) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o(page))) + 1, nent_o(page)'length)); -- + 1 (slv)
      end if;	
    end if;
  end if;
end process;

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