--===========================================================================
--! @file
--! @brief 2-page (RAM_DEPTH=2048) or 4-page (RAM_DEPTH=4096) binned memory module 
--!        which stores data between the algorithm steps in the Hybrid L1 
--!        Tracking algorithm. Based on the MemoryBinned.v module. 
--! @author anders.ryd@cornell.edu (based on code from robert.glein@colorado.edu)
--! @date 2022-03-17
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

entity tf_mem_bin_cm4 is
  generic (
    RAM_WIDTH       : natural := 14;               --! Specify RAM data width
    NUM_PAGES       : natural := 2;                --! Specify no. Pages in RAM memory
    RAM_DEPTH       : natural := NUM_PAGES*PAGE_LENGTH_CM; --! Leave at default. RAM depth (no. of entries)
    NUM_MEM_BINS    : natural := 64;                --! Specify number of memory bins
    NUM_ENTRIES_PER_MEM_BINS : natural := PAGE_LENGTH_CM/NUM_MEM_BINS; --! Leave at default. Number of entries per memory bin
    INIT_FILE       : string := "";                --! Specify name/location of RAM initialization file if using one (leave blank if not)
    INIT_HEX        : boolean := true;             --! Read init file in hex (default) or bin
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE"; --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
    NAME            : string := "MEMNAME"          --! Memory name
    );
  port (
    clka      : in  std_logic;                                      --! Write clock
    clkb      : in  std_logic;                                      --! Read clock
    wea       : in  std_logic;                                      --! Write enable
    enb0       : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    enb1       : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    enb2       : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    enb3       : in  std_logic;                                      --! Read Enable, for additional power savings, disable when not in use
    rstb      : in  std_logic;                                      --! Output reset (does not affect memory contents)
    regceb    : in  std_logic;                                      --! Output register enable
    addra     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Write address bus, width determined from RAM_DEPTH
    dina      : in  std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM input data
    addrb0     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    addrb1     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    addrb2     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    addrb3     : in  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! Read address bus, width determined from RAM_DEPTH
    doutb0     : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    doutb1     : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    doutb2     : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    doutb3     : out std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM output data
    sync_nent : in  std_logic;                                      --! Synchronize nent counter; Connect to start of reading module
    nent_o    : out t_arr_64_4b(0 to NUM_PAGES-1) := (others => (others => (others => '0'))); --! entries(page)(bin)
    mask_o    : out t_arr_64_1b(0 to NUM_PAGES-1) := (others => (others => '0')) --! mask(page)(bin)
    );
end tf_mem_bin_cm4;

architecture rtl of tf_mem_bin_cm4 is

-- ########################### Types ###########################
type t_arr_1d_slv_mem is array(0 to RAM_DEPTH-1) of std_logic_vector(RAM_WIDTH-1 downto 0); --! 1D array of slv

-- ########################### Function ##########################
--! @brief TextIO function to read memory data to initialize tf_mem_bin_cm4. Needed here because of variable slv width!
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
signal sa_RAM_data0 : t_arr_1d_slv_mem := read_tf_mem_data(INIT_FILE, INIT_HEX);         --! RAM data content
signal sa_RAM_data1 : t_arr_1d_slv_mem := read_tf_mem_data(INIT_FILE, INIT_HEX);         --! RAM data content
signal sa_RAM_data2 : t_arr_1d_slv_mem := read_tf_mem_data(INIT_FILE, INIT_HEX);         --! RAM data content
signal sa_RAM_data3 : t_arr_1d_slv_mem := read_tf_mem_data(INIT_FILE, INIT_HEX);         --! RAM data content
signal sv_RAM_row0  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');          --! RAM data row
signal sv_RAM_row1  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');          --! RAM data row
signal sv_RAM_row2  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');          --! RAM data row
signal sv_RAM_row3  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');          --! RAM data row

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_RAM_data0 : signal is "block";
attribute ram_style of sa_RAM_data1 : signal is "block";
attribute ram_style of sa_RAM_data2 : signal is "block";
attribute ram_style of sa_RAM_data3 : signal is "block";

begin

-- Check user didn't change values of derived generics.
assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH_CM) report "User changed RAM_DEPTH" severity FAILURE;
assert (NUM_ENTRIES_PER_MEM_BINS = PAGE_LENGTH_CM/NUM_MEM_BINS) report "tf_mem_bin_cm4: User changed NUM_ENTRIES_PER_MEM_BINS" severity FAILURE;

process(clka)
  variable vi_clk_cnt   : integer := -1; -- Clock counter
  variable vi_page_cnt  : integer := 0;  -- Page counter
  variable vi_nent_idx  : integer := 0;  -- Bin index of nent
  variable page         : integer := 0;
  variable addr_in_page : integer := 0;
  --variable v_line_out   : line;          -- Line for debug
begin
  if rising_edge(clka) then
    if (sync_nent='1') and vi_clk_cnt=-1 then
      vi_clk_cnt := 0;
    end if;
    if (vi_clk_cnt >=0) and (vi_clk_cnt < MAX_ENTRIES-1) then -- ####### Counter nent
      vi_clk_cnt := vi_clk_cnt+1;
    elsif (vi_clk_cnt >= MAX_ENTRIES-1) then -- -1 not included
      vi_clk_cnt := 0;
      nent_o(vi_page_cnt) <= (others => (others => '0'));
      mask_o(vi_page_cnt) <= (others => '0'); 
      assert (vi_page_cnt < NUM_PAGES) report "vi_page_cnt out of range" severity error;
      if (vi_page_cnt < NUM_PAGES-1) then -- Assuming linear continuous page access
        vi_page_cnt := vi_page_cnt +1;
      else
        vi_page_cnt := 0;
      end if;
    end if;
    if (wea='1') then
      sa_RAM_data0(to_integer(unsigned(addra))) <= dina; -- Write data
      sa_RAM_data1(to_integer(unsigned(addra))) <= dina; -- Write data
      sa_RAM_data2(to_integer(unsigned(addra))) <= dina; -- Write data
      sa_RAM_data3(to_integer(unsigned(addra))) <= dina; -- Write data
      -- Count entries
      vi_nent_idx := to_integer(shift_right(unsigned(addra), clogb2(NUM_ENTRIES_PER_MEM_BINS))) mod NUM_MEM_BINS; -- Calculate bin index
      --if DEBUG=true then write(v_line_out, string'("vi_nent_idx: ")); write(v_line_out, vi_nent_idx); writeline(output, v_line_out); end if;

      page := to_integer(unsigned(addra(clogb2(RAM_DEPTH)-1 downto clogb2(PAGE_LENGTH_CM))));
      addr_in_page := to_integer(unsigned(addra(clogb2(PAGE_LENGTH_CM)-1 downto 0)));
      assert (page < NUM_PAGES) report "page out of range" severity error;
      mask_o(page)(vi_nent_idx) <= '1'; -- <= 1 (slv)
      if (addr_in_page = 0) then
        nent_o(page)(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o(page)(vi_nent_idx)'length)); -- <= 1 (slv)
      else
        nent_o(page)(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o(page)(vi_nent_idx))) + 1, nent_o(page)(vi_nent_idx)'length)); -- + 1 (slv)
      end if; 
    end if; -- (wea='1')
  end if;
end process;

process(clkb)
begin
  if rising_edge(clkb) then
    if (enb0='1') then
      sv_RAM_row0 <= sa_RAM_data0(to_integer(unsigned(addrb0)));
    end if;
    if (enb1='1') then
      sv_RAM_row1 <= sa_RAM_data1(to_integer(unsigned(addrb1)));
    end if;
    if (enb2='1') then
      sv_RAM_row2 <= sa_RAM_data2(to_integer(unsigned(addrb2)));
    end if;
    if (enb3='1') then
      sv_RAM_row3 <= sa_RAM_data3(to_integer(unsigned(addrb3)));
    end if;
  end if;
end process;

-- The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
MODE : if (RAM_PERFORMANCE = "LOW_LATENCY") generate -- no_output_register; 1 clock cycle read latency at the cost of a longer clock-to-out timing
  doutb0 <= sv_RAM_row0;
  doutb1 <= sv_RAM_row1;
  doutb2 <= sv_RAM_row2;
  doutb3 <= sv_RAM_row3;
else generate -- output_register; 2 clock cycle read latency with improve clock-to-out timing
  process(clkb)
  begin
    if rising_edge(clkb) then
      if (rstb='1') then
        doutb0 <= (others => '0');
        doutb1 <= (others => '0');
        doutb2 <= (others => '0');
        doutb3 <= (others => '0');
      elsif (regceb='1') then
        doutb0 <= sv_RAM_row0;
        doutb1 <= sv_RAM_row1;
        doutb2 <= sv_RAM_row2;
        doutb3 <= sv_RAM_row3;
      end if;
    end if;
  end process;
end generate MODE;

end rtl;
