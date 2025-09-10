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
--  Writes a .txt file with DATA of the intermediate memories
--  in the chain, whenever WRITE_EN is high.
-- ==================================================================

entity FileWriterFIFO is
  generic (
    FILE_NAME  : string;   --! Name of .txt file to be written
    FIFO_WIDTH  : natural;    --! Data width
    BX_CNT_INIT : integer := 0; --! allows to set offset to allign with BX
    DONE_DELAY  : natural := 0    --! Delay for DONE signal to update BX_CNT
  );
  port (
    CLK      : in  std_logic;
    DONE     : in std_logic;  --! Done signal of previous proc. module.
    WRITE_EN : in std_logic;
    FULL_NEG : out std_logic;
    DATA     : in std_logic_vector(FIFO_WIDTH-1 downto 0)  --! din
  );
end FileWriterFIFO;


architecture behavior of FileWriterFIFO is
begin

procFile : process(CLK)
  variable INIT        : boolean := false; --! File not yet open
  variable FILE_STATUS : file_open_status;
  file     FILE_OUT    : text;   
  variable LINE_OUT    : line;                              
  variable BX_CNT      : integer := 0;  --! Event counter
  variable ADDR        : std_logic_vector(7 downto 0) := (others => '0');  --! Entry counter
  constant TXT_WIDTH   : natural := 11; --! Column width in output .txt file
  variable delay       : std_logic_vector(DONE_DELAY downto 0) := (others => '0');

  function to_hexstring ( VAR : std_logic_vector) return string is
  -- Convert to string, with "0x" prefix.
  begin    
    return "0x"&to_hstring(unsigned(var));
  end;

begin

  if rising_edge(CLK) then

    -- Open and initialize file

    if (not INIT) then
      INIT := true;
      FULL_NEG <= '1'; -- FIFO not full at the start
      file_open(FILE_STATUS, FILE_OUT, FILE_NAME, write_mode); 
      assert (FILE_STATUS = open_ok) report "Failed to open file "&FILE_NAME severity FAILURE;
      -- Write column headings
      write(LINE_OUT, string'("TIME (ns)"), right, TXT_WIDTH);
      write(LINE_OUT, string'("BX")       , right, TXT_WIDTH);
      write(LINE_OUT, string'("ADDR")     , right, TXT_WIDTH);
      write(LINE_OUT, string'("DATA")     , right, TXT_WIDTH);
      writeline(FILE_OUT, LINE_OUT);      
    end if;

    -- Write data from events

    if (WRITE_EN = '1' and (BX_CNT+BX_CNT_INIT) < MAX_EVENTS) then
      -- Valid data, so write it to file.
      write(LINE_OUT, NOW   , right, TXT_WIDTH); 
      write(LINE_OUT, BX_CNT, right, TXT_WIDTH);
      write(LINE_OUT, to_hexstring(ADDR)&" ", right, TXT_WIDTH);
      write(LINE_OUT, to_hexstring(DATA), right, 1+to_hexstring(DATA)'length);
      writeline(FILE_OUT, LINE_OUT);      
      ADDR := std_logic_vector(unsigned(ADDR) + "1");
    end if;

    delay(DONE_DELAY) := DONE;

    if (delay(0) = '1') then
      -- Module has finished event, so increment event counter.
      BX_CNT := BX_CNT + 1;
      ADDR := (others => '0');

      if ((BX_CNT+BX_CNT_INIT) = MAX_EVENTS) then
        -- All events processed, so close file.
        file_close(FILE_OUT);
      end if;
    end if;
    for i in 0 to DONE_DELAY-1 loop
      delay(i) := delay(i+1);
    end loop;

  end if;

end process procFile;

end behavior;
