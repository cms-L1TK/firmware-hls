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
    FIFO_WIDTH  : natural    --! Data width
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
  variable BX_CNT      : natural := 0;  --! Event counter
  variable ADDR        : std_logic_vector(7 downto 0) := (others => '0');  --! Entry counter
  constant TXT_WIDTH   : natural := 11; --! Column width in output .txt file

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
      write(LINE_OUT, string'("DATA")     , right, 11*TXT_WIDTH);
      writeline(FILE_OUT, LINE_OUT);      
    end if;

    -- Write data from events

    if (WRITE_EN = '1' and BX_CNT < MAX_EVENTS) then 
      -- Valid data, so write it to file.
      write(LINE_OUT, NOW   , right, TXT_WIDTH); 
      write(LINE_OUT, BX_CNT, right, TXT_WIDTH);
      write(LINE_OUT, to_hexstring(ADDR), right, TXT_WIDTH);
      write(LINE_OUT, to_hexstring(DATA), right, 11*TXT_WIDTH);
      writeline(FILE_OUT, LINE_OUT);      
      ADDR := std_logic_vector(unsigned(ADDR) + "1");
    end if;

    if (DONE = '1') then
      -- Module has finished event, so increment event counter.
      BX_CNT := BX_CNT + 1;
      ADDR := (others => '0');

      if (BX_CNT = MAX_EVENTS) then
        -- All events processed, so close file.
        file_close(FILE_OUT);
      end if;
    end if;
  end if;

end process procFile;

end behavior;
