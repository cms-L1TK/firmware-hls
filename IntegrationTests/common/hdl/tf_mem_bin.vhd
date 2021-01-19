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
    nent_o0   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 0; No 2D array to avoid partially associated port
    nent_o1   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 1; No 2D array to avoid partially associated port
    nent_o2   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 2; No 2D array to avoid partially associated port
    nent_o3   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 3; No 2D array to avoid partially associated port
    nent_o4   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 4; No 2D array to avoid partially associated port
    nent_o5   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 5; No 2D array to avoid partially associated port
    nent_o6   : out t_arr8_5b := (others => (others => '0'));       --! Num entries (bin) for page 6; No 2D array to avoid partially associated port
    nent_o7   : out t_arr8_5b := (others => (others => '0'))        --! Num entries (bin) for page 7; No 2D array to avoid partially associated port
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
signal sv_addra_d1 : std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0) := (others => '1'); --! Write address bus delayed

-- ########################### Attributes ###########################
attribute ram_style : string;
attribute ram_style of sa_RAM_data : signal is "block";

begin

process(clka)
  variable vi_clk_cnt  : integer := -1; -- Clock counter
  variable vi_page_cnt : integer := 0;  -- Page counter
  variable vi_nent_idx : integer := 0;  -- Bin index of nent
  --variable v_line_out  : line;          -- Line for debug
begin
  if rising_edge(clka) then
    if (sync_nent='1') and vi_clk_cnt=-1 then
      vi_clk_cnt := 0;
    end if;
    if (vi_clk_cnt >=0) and (vi_clk_cnt < MAX_ENTRIES-1) then -- ####### Counter nent
      vi_clk_cnt := vi_clk_cnt+1;
    elsif (vi_clk_cnt >= MAX_ENTRIES-1) then -- -1 not included
      vi_clk_cnt := 0;
      case (vi_page_cnt) is -- Reset nent counter values
        when 0 =>
          nent_o0 <= (others => (others => '0'));
        when 1 =>
          nent_o1 <= (others => (others => '0'));
        when 2 =>
          nent_o2 <= (others => (others => '0'));
        when 3 =>
          nent_o3 <= (others => (others => '0'));
        when 4 =>
          nent_o4 <= (others => (others => '0'));
        when 5 =>
          nent_o5 <= (others => (others => '0'));
        when 6 =>
          nent_o6 <= (others => (others => '0'));
        when 7 =>
          nent_o7 <= (others => (others => '0'));
        when others =>
          assert (false) report "vi_page_cnt out of range" severity error;
      end case;
      if (vi_page_cnt < RAM_DEPTH/PAGE_OFFSET-1) then -- Assuming linear continuous page access
        vi_page_cnt := vi_page_cnt +1;
      else
        vi_page_cnt := 0;
      end if;
    end if;
    if (wea='1') then
      sa_RAM_data(to_integer(unsigned(addra))) <= dina; -- Write data
      if ((addra = (addra'range => '0')) or (addra /= sv_addra_d1)) and (dina /= (dina'range => '0')) then -- ##### Count n_entries;
        vi_nent_idx := to_integer(shift_right(unsigned(addra), clogb2(N_ENTRIES_PER_MEM_BINS))) mod N_MEM_BINS; -- Calculate bin index
        --if DEBUG=true then write(v_line_out, string'("vi_nent_idx: ")); write(v_line_out, vi_nent_idx); writeline(output, v_line_out); end if;
        case (to_integer(unsigned(addra))) is
          when 0*PAGE_OFFSET to 1*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(0*PAGE_OFFSET, addra'length))) then
              nent_o0(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o0(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o0(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o0(vi_nent_idx))) + 1, nent_o0(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 1*PAGE_OFFSET to 2*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(1*PAGE_OFFSET, addra'length))) then
              nent_o1(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o1(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o1(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o1(vi_nent_idx))) + 1, nent_o1(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 2*PAGE_OFFSET to 3*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(2*PAGE_OFFSET, addra'length))) then
              nent_o2(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o2(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o2(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o2(vi_nent_idx))) + 1, nent_o2(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 3*PAGE_OFFSET to 4*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(3*PAGE_OFFSET, addra'length))) then
              nent_o3(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o3(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o3(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o3(vi_nent_idx))) + 1, nent_o3(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 4*PAGE_OFFSET to 5*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(4*PAGE_OFFSET, addra'length))) then
              nent_o4(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o4(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o4(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o4(vi_nent_idx))) + 1, nent_o4(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 5*PAGE_OFFSET to 6*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(5*PAGE_OFFSET, addra'length))) then
              nent_o5(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o5(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o5(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o5(vi_nent_idx))) + 1, nent_o5(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 6*PAGE_OFFSET to 7*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(6*PAGE_OFFSET, addra'length))) then
              nent_o6(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o6(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o6(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o6(vi_nent_idx))) + 1, nent_o6(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when 7*PAGE_OFFSET to 8*PAGE_OFFSET-1 =>
            if (addra = std_logic_vector(to_unsigned(7*PAGE_OFFSET, addra'length))) then
              nent_o7(vi_nent_idx) <= std_logic_vector(to_unsigned(1, nent_o7(vi_nent_idx)'length)); -- <= 1 (slv)
            else
              nent_o7(vi_nent_idx) <= std_logic_vector(to_unsigned(to_integer(unsigned(nent_o7(vi_nent_idx))) + 1, nent_o7(vi_nent_idx)'length)); -- + 1 (slv)
            end if;
          when others =>
            assert (false) report "addra out of range" severity error;
        end case;
      end if;
      sv_addra_d1 <= addra;
    end if; -- (wea='1')
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