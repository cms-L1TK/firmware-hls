--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Writing to and from files
use IEEE.STD_LOGIC_TEXTIO.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! Writing to and from files
use STD.TEXTIO.all;

--! User packages
use work.tf_pkg.all;

-- ==================================================================
--  Writes a .txt file with the ADDR & DATA of all valid entries in
--  the final memories in the chain.
--
--  N.B. This version assumes the memories are unbinned.
-- ==================================================================

entity FileWriterFromRAMBinned is
  generic (
    FILE_NAME  : string;   --! Name of .txt file to be written
    RAM_WIDTH  : natural := 18;    --! RAM data width
    NUM_PAGES  : natural := 2;     --! Number of pages in RAM memory
    NUM_MEM_BINS    : natural := 8;                --! Specify number of memory bins
    -- Leave following parameters at their default values.
    RAM_DEPTH  : natural := NUM_PAGES*PAGE_LENGTH; --! RAM depth (no. of entries)
    ADDR_WIDTH : natural := clogb2(RAM_DEPTH);      --! RAM address
    NUM_ENTRIES_PER_MEM_BINS : natural := PAGE_LENGTH/NUM_MEM_BINS --! Number of entries per memory bin
  );
  port (
    CLK      : in  std_logic;
    DONE     : in std_logic;   --! Done signal of final proc. module.
    NENT_ARR : in t_arr_8_5b(0 to NUM_PAGES-1);
    DATA     : in std_logic_vector(RAM_WIDTH-1 downto 0);    --! dout
    ADDR     : out std_logic_vector(ADDR_WIDTH-1 downto 0);  --! read_addr
    READ_EN  : out std_logic
  );
end FileWriterFromRAMBinned;


architecture behavior of FileWriterFromRAMBinned is
  -- Latches to allow for read latency of memory.
  type t_arr_en_lat is array(0 to MEM_READ_LATENCY) of std_logic;
  type t_arr_rd_lat is array(0 to MEM_READ_LATENCY) of std_logic_vector(ADDR_WIDTH-1 downto 0);
  type t_arr_bx_lat is array(0 to MEM_READ_LATENCY) of integer;
  signal READ_EN_LATCH : t_arr_en_lat := (others => '0');
  signal ADDR_LATCH    : t_arr_rd_lat := (others => (others => '0'));
  signal BX_CNT_LATCH  : t_arr_bx_lat := (others => 0);
  -- nentries arrays and shit
  type t_arr_nent is array(0 to NUM_MEM_BINS) of natural; -- use natural or logic vector of size NUM_ENTRIES_PER_MEM_BINS?
begin

procFile : process(CLK)
  variable INIT        : boolean := false; --! File not yet open
  variable FILE_STATUS : file_open_status;
  file     FILE_OUT    : text;   
  variable LINE_OUT    : line;                              
  variable BX_CNT      : integer := -1;  --! Event counter
  variable PAGE        : natural := 0;
  variable NENT        : t_arr_nent := (others => 0); -- nentries within bins or something
  variable DATA_CNT    : t_arr_nent := (others => 0);   --! Counter of data within page and bin
  variable v_REN       : std_logic := '0';
  variable v_ADDR      : std_logic_vector(ADDR_WIDTH-1 downto 0) := (others => '0');
  constant zeroADDR    : std_logic_vector(ADDR_WIDTH-1 downto 0) := (others => '0');
  constant TXT_WIDTH   : natural := 11;  --! Column width in output .txt file
  --variable BIN         : std_logic_vector
  function to_hexstring ( VAR : std_logic_vector) return string is
  -- Convert to string, with "0x" prefix.
  begin    
    return "0x"&to_hstring(unsigned(var));
  end;

begin

  -- Check user didn't change values of derived generics.
  assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;
  assert (ADDR_WIDTH = clogb2(RAM_DEPTH)) report "User changed ADDR_WIDTH" severity FAILURE;
  assert (NUM_ENTRIES_PER_MEM_BINS = PAGE_LENGTH/NUM_MEM_BINS) report "User changed NUM_ENTRIES_PER_MEM_BINS" severity FAILURE;

  if rising_edge(CLK) then

    -- Open and initialize file

    if (not INIT) then
      INIT := true;
      file_open(FILE_STATUS, FILE_OUT, FILE_NAME, write_mode); 
      assert (FILE_STATUS = open_ok) report "Failed to open file "&FILE_NAME severity FAILURE;
      -- Write column headings
      write(LINE_OUT, string'("TIME (ns)"), right, TXT_WIDTH);
      write(LINE_OUT, string'("BX")       , right, TXT_WIDTH);
      write(LINE_OUT, string'("ADDR")     , right, TXT_WIDTH);
      write(LINE_OUT, string'("BIN")      , right, TXT_WIDTH);
      write(LINE_OUT, string'("DATA")     , right, 2*TXT_WIDTH);
      writeline(FILE_OUT, LINE_OUT);      
    end if;

    -- Check if new event available in memory

    if (DONE = '1') then   --! Signal present in single clk cycle when event first ready.
      BX_CNT := BX_CNT + 1;
      PAGE := BX_CNT mod NUM_PAGES;
      bin_nent_loop : for i in 0 to NUM_MEM_BINS-1 loop -- if this works, then we don't need a separate file for the binned?
        NENT(i) := to_integer(unsigned(NENT_ARR(PAGE)(i)));
        DATA_CNT(i) := 0;
      end loop bin_nent_loop;
      if (BX_CNT = MAX_EVENTS) then
        -- All events processed, so close file.
        file_close(FILE_OUT);
      end if;
    end if;

    -- Launch memory read, if data remains to be read from current event.

    -- Loop over the bins and find the first unread data
    bin_read_loop : for i in 0 to NUM_MEM_BINS-1 loop
      if (BX_CNT >= 0 and BX_CNT < MAX_EVENTS and DATA_CNT(i) < NENT(i)) then
        -- Data to read
        v_REN  := '1';
        v_ADDR := std_logic_vector(to_unsigned(DATA_CNT(i) + i*NUM_ENTRIES_PER_MEM_BINS + PAGE_LENGTH*PAGE, ADDR_WIDTH));
        DATA_CNT(i) := DATA_CNT(i) + 1;
        exit;
      else
        -- No data to read.
        v_REN  := '0';
        v_ADDR := (others => '0');
      end if;
    end loop bin_read_loop;

    READ_EN <= v_REN;
    ADDR    <= v_ADDR;
    -- As memory read takes 1-2 clks, store address and read-enable flags.
    READ_EN_LATCH <= READ_EN_LATCH(1 to MEM_READ_LATENCY) & v_REN;
    ADDR_LATCH    <= ADDR_LATCH   (1 to MEM_READ_LATENCY) & v_ADDR;
    BX_CNT_LATCH  <= BX_CNT_LATCH (1 to MEM_READ_LATENCY) & BX_CNT;

    -- Write to .txt file results of read from memory (if read took place).
    -- (Delayed due to read latency of memory).
    if (READ_EN_LATCH(0) = '1') then
      -- Valid data, so write it to file.
      write(LINE_OUT, NOW   , right, TXT_WIDTH); 
      write(LINE_OUT, BX_CNT_LATCH(0), right, TXT_WIDTH);
      write(LINE_OUT, to_hexstring(ADDR_LATCH(0)), right, TXT_WIDTH);
      write(LINE_OUT, to_integer(unsigned(ADDR_LATCH(0)(clogb2(NUM_MEM_BINS)+clogb2(NUM_ENTRIES_PER_MEM_BINS)-1 downto clogb2(NUM_ENTRIES_PER_MEM_BINS)))), right, TXT_WIDTH);
      write(LINE_OUT, to_hexstring(DATA), right, 2*TXT_WIDTH);
      writeline(FILE_OUT, LINE_OUT);
    end if;

  end if;

end process procFile;

end behavior;
