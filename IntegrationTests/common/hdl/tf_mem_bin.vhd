--===========================================================================
--! @file
--! @brief Configurable memory that can specify:
--!        RAM_WIDTH - width of memory
--!        NUM_PAGES - Number of pages
--!        NUM_PHI_BINS - Number of phi bins
--!        NUM_RZ_BINS - Number of RZ bins
--!        ADDR_WIDTH - number of bits for address
--!        NUM_COPY - number of memory copies
--!
--!        Derived quantities
--!        NUM_BIN = NUM_PHI_BINS * NUM_RZ_BINS
--!        BIN_DEPTH = 2**ADDRWIDTH depth of each memory bin
--!        PAGE_LENGTH =  BIN_DEPTH * NBIN total memory depth
--!
--!        This memory inplements the binned, VMStubs, memories
--!        
--! @author anders.ryd@cornell.edu (based on code from robert.glein@colorado.edu)
--! @date 2023-02-02 (Groundhog day!)
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
    RAM_WIDTH       : natural := 14;     --! Specify RAM data width
    NUM_PAGES       : natural := 2;      --! Specify no. Pages in RAM memory
    ADDR_WIDTH      : natural := 4;      --! Bits for address, e.g. 4 for
                                         --  binned memories
    NUM_PHI_BINS    : natural := 8;      --! Number of phi bins
    NUM_RZ_BINS     : natural := 8;      --! Number r/z bins (16 for disks VM)
    NUM_COPY        : natural := 4;      --! Number of memory copies

    --! Derived quantities
    NUM_BINS        : natural := NUM_PHI_BINS * NUM_RZ_BINS;
    BIN_DEPTH       : natural := 2**ADDR_WIDTH;
    PAGE_LENGTH     : natural := BIN_DEPTH * NUM_BINS;
    RAM_DEPTH       : natural := NUM_PAGES * PAGE_LENGTH;
    RAM_DEPTH_BITS  : natural := clogb2(RAM_DEPTH);
    NUM_PAGES_BITS  : natural := clogb2(NUM_PAGES);
    PAGE_LENGTH_BITS  : natural := clogb2(PAGE_LENGTH);

    NUM_PHI_BITS    : natural := clogb2(NUM_PHI_BINS);      --! Number of phi bits
    NUM_RZ_BITS     : natural := clogb2(NUM_RZ_BINS);      --! Number r/z bits (4 for disks VM)
    MEM_TYPE        : string := "ultra";       --! "block" or "ultra" 

    --! Specify name/location of RAM initialization file if using one
    --! (leave blank if not)
    INIT_FILE       : string := "";

    --! Read init file in hex (default) or bin
    INIT_HEX        : boolean := true;

    --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY"
    --! (1 clk latency)
    RAM_PERFORMANCE : string := "HIGH_PERFORMANCE"; 

    --! Memory name - used for debugging
    NAME            : string := "MEMNAME"
    );  
  port (

    --! Write clock
    clka      : in  std_logic;
    --! Write enable
    wea       : in  std_logic;
    --! Write Address (contains page, bin, and bin address)
    addra     : in  std_logic_vector(RAM_DEPTH_BITS-1 downto 0);
    --! RAM input data
    dina      : in  std_logic_vector(RAM_WIDTH-1 downto 0);

    
    --! Read clock
    clkb      : in  std_logic;                                      
    --! Read Enable, for additional power savings, disable when not in use
    enb       : in  std_logic_vector(NUM_COPY-1 downto 0);          

    --! Output reset (does not affect memory contents)
    rstb      : in  std_logic;

    --! Output register enable
    regceb    : in  std_logic;

    --! Read address bus, width determined from RAM_DEPTH and NCOPY   
    addrb      : in std_logic_vector(NUM_COPY*RAM_DEPTH_BITS-1 downto 0);

    --! RAM output data
    doutb      : out std_logic_vector(NUM_COPY*RAM_WIDTH-1 downto 0);
    
    --! Synchronize nent counter; Connect to start of reading module
    sync_nent : in  std_logic;

    --! Read Enable for number of entries, for additional power savings,
    --disable when not in use
    enb_nent  : in  std_logic;

    --! Address for nentries as fcn of r/z bin and page
    addr_nent : in std_logic_vector(NUM_RZ_BITS+NUM_PAGES_BITS-1 downto 0); 

    dout_nent  : out std_logic_vector(2*NUM_PHI_BINS*ADDR_WIDTH-1 downto 0);

    --! mask(page)(bin)
    mask_o      : out std_logic_vector(NUM_BINS * NUM_PAGES-1 downto 0) := (others => '0') 
    );
end tf_mem_bin;

architecture rtl of tf_mem_bin is

-- ########################### Types ###########################

--! Array of data type for memory
  type t_data_array is array(0 to NUM_COPY-1) of std_logic_vector(RAM_WIDTH-1 downto 0);
--! Memory 1d
  type t_mem_1d_array is array(0 to RAM_DEPTH-1) of std_logic_vector(RAM_WIDTH-1 downto 0);
--! Memory 2d for NUM_COPY instances
  type t_mem_2d_array is array(0 to NUM_COPY-1) of t_mem_1d_array;

  type t_arr_1d_mem_nent_tmp is array(NUM_BINS -1 downto 0) of std_logic_vector(ADDR_WIDTH-1 downto 0);

  type t_arr_1d_slv_mem_nent is array(0 to NUM_RZ_BINS*NUM_PAGES-1) of std_logic_vector(ADDR_WIDTH-1 downto 0);

  type t_arr_2d_slv_mem_nent is array(0 to 2*NUM_PHI_BINS-1) of t_arr_1d_slv_mem_nent; --! 2D array of slv

-- ########################### Function ##########################
--! @brief TextIO function to read memory data to initialize tf_mem_bin. Needed here because of variable slv width!
impure function read_tf_mem_data (
file_path : string;      --! File path as string
hex_val   : boolean)     --! Read file vales as hex or bin
return t_mem_1d_array is --! Dataarray with read values
  file     file_in  : text ;                                           -- Text - a file of character strings
  variable line_in  : line;                                            -- Line - one string from a text file
  variable char     : character;                                       -- Character
  variable i_bx_row : natural;                                         -- Read row index
  variable data_arr : t_mem_1d_array := (others => (others => '0')); -- Output RAM array
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

impure function read_tf_mem_data_2d (
file_path : string;      --! File path as string
hex_val   : boolean)     --! Read file vales as hex or bin
return t_mem_2d_array is --! Dataarray with read values
  variable data_arr : t_mem_2d_array := (others => (others => (others => '0'))); -- Output RAM array
begin
  for i in 0 to NUM_COPY-1 loop
    data_arr(i) := read_tf_mem_data(file_path, hex_val);
  end loop;
  return data_arr;
end read_tf_mem_data_2d;

-- ########################### Signals ###########################

--! RAM data content for stub data
signal sa_RAM_data : t_mem_2d_array := read_tf_mem_data_2d(INIT_FILE, INIT_HEX);          

--! Pipeline for return data
signal sv_RAM_row  : t_data_array := (others => (others =>'0'));

--! RAM for the number of entries
signal sa_RAM_nent :  t_arr_2d_slv_mem_nent := (others => (others => (others => '0')));

signal nentry_tmp : t_arr_1d_mem_nent_tmp := (others => (others =>'0'));
signal nentry_mask_tmp : std_logic_vector(NUM_BINS-1 downto 0) := (others => '0');

-- ########################### Attributes ###########################
attribute ram_style : string;

attribute ram_style of sa_RAM_data : signal is MEM_TYPE;
attribute ram_style of sa_RAM_nent : signal is "distributed";

attribute ram_style of nentry_tmp : signal is "distributed";

begin

-- Check user didn't change values of derived generics.
assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;

process(clka)
  variable init   : std_logic := '1'; -- Clock counter
  --FIXME hardcoded number
  variable slv_clk_cnt   : std_logic_vector(6 downto 0) := (others => '0'); -- Clock counter
  variable slv_page_cnt  : std_logic_vector(NUM_PAGES_BITS-1 downto 0) := (others => '0');  -- Page counter
  variable slv_page_cnt_save  : std_logic_vector(NUM_PAGES_BITS-1 downto 0) := (others => '0');  -- Page counter

  --! Extract phi and rz bin address
  alias vi_nent_idx  : std_logic_vector(NUM_PHI_BITS+NUM_RZ_BITS-1 downto 0) is addra(ADDR_WIDTH + NUM_PHI_BITS + NUM_RZ_BITS - 1 downto ADDR_WIDTH);

  --! Extract phi bin from bin address
  alias phibits: std_logic_vector(NUM_PHI_BITS-1 downto 0) is vi_nent_idx(NUM_PHI_BITS + NUM_RZ_BITS - 1 downto NUM_RZ_BITS);
  
  --! Extract rz bin from binaddress
  alias rzbits: std_logic_vector(NUM_RZ_BITS-1 downto 0) is vi_nent_idx(NUM_RZ_BITS-1 downto 0); --rz position

  variable binaddr   : unsigned(ADDR_WIDTH-1 downto 0) := (others => '0');
  variable nentry   : unsigned(ADDR_WIDTH-1 downto 0) := (others => '0');

  variable writeaddr : std_logic_vector(RAM_DEPTH_BITS-1 downto 0);
  
begin
  if rising_edge(clka) then
    slv_page_cnt_save := slv_page_cnt;
    if (sync_nent='1') and init='1' then
      init := '0';
      slv_clk_cnt := (others => '0');
      slv_page_cnt := (0 => '1', others => '0');
      nentry_mask_tmp <= (others => '0'); -- Do we need this??? FIXME
      --report "tf_mem_bin "&time'image(now)&" "&NAME&" setting nentry_mask_tmp to zero";
    end if;
    if (init = '0' and to_integer(unsigned(slv_clk_cnt)) < MAX_ENTRIES-1) then -- ####### Counter nent
      slv_clk_cnt := std_logic_vector(unsigned(slv_clk_cnt)+1);
    elsif (to_integer(unsigned(slv_clk_cnt)) >= MAX_ENTRIES-1) then -- -1 not included
      slv_clk_cnt := (others => '0');
      nentry_mask_tmp <= (others => '0'); -- Why do we need this??? FIXME
      --report "tf_mem_bin "&time'image(now)&" "&NAME&" setting nentry_mask_tmp to zero";
      if (to_integer(unsigned(slv_page_cnt)) < NUM_PAGES-1) then 
        slv_page_cnt := std_logic_vector(unsigned(slv_page_cnt)+1);
      else
        slv_page_cnt := (others => '0');
      end if;
      mask_o(NUM_BINS*(to_integer(unsigned(slv_page_cnt))+1)-1 downto NUM_BINS*to_integer(unsigned(slv_page_cnt))) <= (others => '0');
    end if;

    if (wea='1') then
      -- FIXME - this code is not yet protected from "wrapping" if there are
      -- more than 16 (or 15) entries.      
      -- Write data to all copies

      --report "tf_mem_bin vi_nent_idx vi_nent_idx_new: " & to_bstring(vi_nent_idx) & " " & to_bstring(vi_nent_idx_new) & " " & to_bstring(rzbits) & " " & to_bstring(phibits);
  
      binaddr := unsigned(nentry_tmp(to_integer(unsigned(vi_nent_idx))));
      nentry := binaddr+1;

      if (nentry_mask_tmp(to_integer(unsigned(vi_nent_idx)))='0') then
        nentry := "0001";
        binaddr := "0000";
      end if; 

      nentry_tmp(to_integer(unsigned(vi_nent_idx))) <= std_logic_vector(nentry);
      nentry_mask_tmp(to_integer(unsigned(vi_nent_idx))) <= '1';
      
      writeaddr := slv_page_cnt_save & vi_nent_idx & std_logic_vector(binaddr);
      --report "tf_mem_bin addra: " & NAME & " " & to_bstring(std_logic_vector(addra));
      for icopy in 0 to NUM_COPY-1 loop
        sa_RAM_data(icopy)(to_integer(unsigned(writeaddr))) <= dina; 
      end loop;
      
      --assert (page < NUM_PAGES) report "page out of range" severity error;
      mask_o(to_integer(unsigned(slv_page_cnt_save))*NUM_BINS+to_integer(unsigned(vi_nent_idx))) <= '1'; -- <= 1 (slv)

      --report "tf_mem_bin write nent :"&time'image(now)&" "&NAME&" phi:"&to_bstring(phibits)&" rz:"&to_bstring(rzbits)&" "&to_bstring(nentry)&" "&to_bstring(writeaddr);

      sa_RAM_nent(to_integer(unsigned(phibits)))(to_integer(unsigned(slv_page_cnt_save))*NUM_RZ_BINS+to_integer(unsigned(rzbits))) <= std_logic_vector(nentry); -- <= address
      if (unsigned(rzbits) /= 0) then
        --report "tf_mem_bin write nent :"&time'image(now)&" "&NAME&" phi:"&to_bstring(phibits)&" rz:"&to_bstring(rzbits)
        --  &" "&to_bstring(nentry_in_bin)&" "&to_bstring(addra);
        sa_RAM_nent(to_integer(unsigned(phibits))+NUM_PHI_BINS)(to_integer(unsigned(slv_page_cnt_save))*NUM_RZ_BINS+(to_integer(unsigned(rzbits))-1)) <= std_logic_vector(nentry); -- <= address
      end if;
    end if;
  end if;
end process;

process(clkb)
begin

    
  if rising_edge(clkb) then
    --Reading DRAM so should not be on clock edge ?
    if (enb_nent='1') then
      --for i in 0 to NUM_PHI_BINS-1 loop
      --  report "tf_mem_bin read_nent "&NAME&" "&time'image(now)&" "&integer'image(i)&"  : "
      --  &to_bstring(sa_RAM_nent(i)(8))&" "
      --  &to_bstring(sa_RAM_nent(i)(9))&" "
      --  &to_bstring(sa_RAM_nent(i)(10))&" "
      --  &to_bstring(sa_RAM_nent(i)(11))&" "
      --  &to_bstring(sa_RAM_nent(i)(12))&" "
      --  &to_bstring(sa_RAM_nent(i)(13))&" "
      --  &to_bstring(sa_RAM_nent(i)(14))&" "
      --  &to_bstring(sa_RAM_nent(i)(15));
      --end loop;
      for i in 0 to 2*NUM_PHI_BINS-1 loop
        --report "tf_mem_bin read nent " & NAME & " " &to_bstring(addr_nent) & " " & to_bstring(sa_RAM_nent(i)(to_integer(unsigned(addr_nent))));
        dout_nent(ADDR_WIDTH*(i+1)-1 downto ADDR_WIDTH*i) <= sa_RAM_nent(i)(to_integer(unsigned(addr_nent)));
      end loop;
    end if; 

    for i in 0 to NUM_COPY-1 loop
      if (enb(i)='1') then
        --report "tf_mem_bin read addrb"&integer'image(i)&" "&time'image(now)&" "& NAME & " " & to_bstring(addrb((i+1)*RAM_DEPTH_BITS-1 downto i*RAM_DEPTH_BITS))
        --  &" "&to_bstring(sa_RAM_data(i)(to_integer(unsigned(addrb((i+1)*RAM_DEPTH_BITS-1 downto i*RAM_DEPTH_BITS)))));
        sv_RAM_row(i) <= sa_RAM_data(i)(to_integer(unsigned(addrb((i+1)*RAM_DEPTH_BITS-1 downto i*RAM_DEPTH_BITS))));
      end if;
    end loop;  
  end if;
  
end process;

-- The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
MODE : if (RAM_PERFORMANCE = "LOW_LATENCY") generate -- no_output_register; 1 clock cycle read latency at the cost of a longer clock-to-out timing
  process(clkb)
  begin
    for i in 0 to NUM_COPY-1 loop
      doutb((i+1)*RAM_WIDTH-1 downto i*RAM_WIDTH) <= sv_RAM_row(i);
    end loop;
  end process;
else generate -- output_register; 2 clock cycle read latency with improve clock-to-out timing
  process(clkb)
  begin
    if rising_edge(clkb) then
      if (rstb='1') then
        doutb <= (others => '0');
      elsif (regceb='1') then
        for i in 0 to NUM_COPY-1 loop
          doutb((i+1)*RAM_WIDTH-1 downto i*RAM_WIDTH) <= sv_RAM_row(i);
        end loop;
      end if;
    end if;
  end process;
end generate MODE;

end rtl;
