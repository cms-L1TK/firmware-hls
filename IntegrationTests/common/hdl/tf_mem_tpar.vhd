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

entity tf_mem_tpar is
  generic (
    PAGE_LENGTH     : natural := PAGE_LENGTH;      --! Page length
    RAM_WIDTH       : natural := 18;               --! Specify RAM data width
    NUM_PAGES       : natural := 2;                --! Specify no. Pages in RAM memory
    NUM_TPAGES      : natural := 1;                --! TPAR pages
    RAM_DEPTH       : natural := NUM_PAGES*NUM_TPAGES*PAGE_LENGTH; --! Leave at default. RAM depth (no. of entries)
    INIT_FILE       : string := "";                --! Specify name/location of RAM initialization file if using one (leave blank if not)
    INIT_HEX        : boolean := true;             --! Read init file in hex (default) or bin
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE";--! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
    NAME            : string := "MEMNAME";          --! Name of mem for printout
    DEBUG           : boolean := false             --! If true prints debug info
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
    nent_o    : out t_arr_7b(0 to NUM_PAGES*NUM_TPAGES-1) := (others => (others => '0')); --! entries per page
    mask_o    : out t_arr_4b(0 to NUM_PAGES-1) := (others => (others => '0')) --! entries per page
    );
end tf_mem_tpar;

architecture rtl of tf_mem_tpar is

-- ########################### Types ###########################
type t_arr_1d_slv_mem is array(0 to RAM_DEPTH-1) of std_logic_vector(RAM_WIDTH-1 downto 0); --! 1D array of slv

-- ########################### Function ##########################
--! @brief TextIO function to read memory data to initialize tf_mem. Needed here because of variable slv width!
impure function read_tf_mem_tpar_data (
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
end read_tf_mem_tpar_data;

-- ########################### Signals ###########################
signal sa_RAM_data : t_arr_1d_slv_mem := read_tf_mem_tpar_data(INIT_FILE, INIT_HEX);         --! RAM data content
signal sv_RAM_row  : std_logic_vector(RAM_WIDTH-1 downto 0) := (others =>'0');          --! RAM data row
signal enb_reg : std_logic;

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_RAM_data : signal is "ultra";

begin

-- Check user didn't change values of derived generics.
assert (RAM_DEPTH  = NUM_TPAGES*NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;
assert (PAGE_LENGTH = 128) report "PAGE_LENGTH in tf_mem_tpar has to be 128" severity FAILURE;


process(clka)
  variable sync_nent_prev : std_logic := '0';
  variable slv_clk_cnt   : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others => '0'); -- Clock counter
  variable slv_page_cnt_save  :  std_logic_vector(clogb2(NUM_PAGES)-1 downto 0) := (others => '0');  -- Page counter save
  variable slv_page_cnt  : std_logic_vector(clogb2(NUM_PAGES)-1 downto 0) := (others => '0'); 
  variable tpage        : std_logic_vector(clogb2(NUM_TPAGES)-1 downto 0)  := (others => '0');
  variable nentaddress  : std_logic_vector(clogb2(NUM_TPAGES*NUM_PAGES)-1 downto 0) := (others => '0');
  variable address      : std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0);

begin
  if rising_edge(clka) then -- ######################################### Start counter initially
    --if DEBUG then
    --if (NUM_PAGES = 2) then
    --  report "tf_mem_tpar "&NAME&" nent(0) nent(1) "&to_bstring(nent_o(0))&" "&to_bstring(nent_o(1));
    --end if;
    --if (NUM_PAGES = 8 and NUM_TPAGES = 4) then
    --  report "tf_mem_tpar "&time'image(now)&" "&NAME&" nent_0 "
    --    &to_bstring(nent_o(0))&" "
    --    &to_bstring(nent_o(1))&" "
    --    &to_bstring(nent_o(2))&" "
    --    &to_bstring(nent_o(3))&" "
    --    &to_bstring(nent_o(4))&" "
    --    &to_bstring(nent_o(5))&" "
    --    &to_bstring(nent_o(6))&" "
    --    &to_bstring(nent_o(7));
    --end if;
    --end if;
    --end if;

    slv_page_cnt_save := slv_page_cnt;
    if (sync_nent = '1' and to_integer(unsigned(slv_clk_cnt)) < MAX_ENTRIES-1) then
      slv_clk_cnt := std_logic_vector(unsigned(slv_clk_cnt)+1);     
    elsif (to_integer(unsigned(slv_clk_cnt)) >= MAX_ENTRIES-1) then 
      slv_clk_cnt := (others => '0');
      if (to_integer(unsigned(slv_page_cnt)) < NUM_PAGES-1) then
        slv_page_cnt := std_logic_vector(unsigned(slv_page_cnt)+1);
      else
         slv_page_cnt := (others => '0');
      end if;
      mask_o(to_integer(unsigned(slv_page_cnt))) <= (others => '0');
      -- Note that we don't zero the nent_o counters here. When adding entry we
      -- reset the nent_o counter if the mask is zero
    end if;
    --use sync_nent transition to synchronize at BX (page) 1
    if (sync_nent='1') and (sync_nent_prev='0') then
      --report time'image(now)&" tf_mem_tpar "&NAME&" sync_nent";
      slv_clk_cnt := (others => '0');
      slv_page_cnt := (0 => '1', others => '0');
    end if;
    sync_nent_prev := sync_nent;

    if (wea='1') then
      tpage := addra(clogb2(NUM_TPAGES)-1 downto 0);
      nentaddress := slv_page_cnt_save&tpage;
      if (mask_o(to_integer(unsigned(slv_page_cnt_save)))(to_integer(unsigned(tpage)))='1') then
        address := nentaddress&nent_o(to_integer(unsigned(nentaddress)));
        nent_o(to_integer(unsigned(nentaddress))) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o(to_integer(unsigned(nentaddress))))) + 1, nent_o(to_integer(unsigned(nentaddress)))'length)); -- + 1 (slv)
      else
        address := nentaddress&std_logic_vector(to_unsigned(0, nent_o(to_integer(unsigned(nentaddress)))'length));
        nent_o(to_integer(unsigned(nentaddress))) <= std_logic_vector(to_unsigned(1, nent_o(to_integer(unsigned(nentaddress)))'length));
      end if;
      --report time'image(now)&" tf_mem_tpar "&NAME&" tpage:"&to_bstring(tpage)&" writeaddr "&to_bstring(slv_page_cnt_save)&" "&to_bstring(address)&" nentaddress nent:"&to_bstring(nentaddress)&" "&to_bstring(nent_o(to_integer(unsigned(nentaddress))))&" "&to_bstring(dina);
      sa_RAM_data(to_integer(unsigned(address))) <= dina; -- Write data
      mask_o(to_integer(unsigned(slv_page_cnt_save)))(to_integer(unsigned(tpage))) <= '1';
    end if;
  end if;
end process;

process(clkb)
begin
  if rising_edge(clkb) then
    if (enb='1') then
      if DEBUG then
      report "tf_mem_tpar "&time'image(now)&" "&NAME&" readaddr "&to_bstring(addrb)
          &" "&to_bstring(sa_RAM_data(to_integer(unsigned(addrb))));
      end if;
      sv_RAM_row <= sa_RAM_data(to_integer(unsigned(addrb)));
    end if;
  end if;
end process;

process(clkb)
begin
  if rising_edge(clkb) then
    enb_reg <= enb;
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
      else
        if (enb_reg='1') then
          doutb <= sv_RAM_row;
        end if;
      end if;
    end if;
  end process;
end generate MODE;

end rtl;
