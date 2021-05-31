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
--  Writes a .txt file with ADDR & DATA of the intermediate memories
--  in the chain, whenever WRITE_EN is high.
-- ==================================================================

entity FileWriter is
  generic (
    FILE_NAME  : string;   --! Name of .txt file to be written
    RAM_WIDTH  : natural := 18;    --! RAM data width
    NUM_PAGES  : natural := 2;     --! Number of pages in RAM memory
    -- Leave following parameters at their default values.
    RAM_DEPTH  : natural := NUM_PAGES*PAGE_LENGTH; --! RAM depth (no. of entries)
    ADDR_WIDTH : natural := clogb2(RAM_DEPTH)      --! RAM address
  );
  port (
    CLK      : in  std_logic;
    START    : in std_logic;  --! Start signal of previous proc. module.
                              --! (or Done signal of previous, previous proc. module).
    DONE     : in std_logic;  --! Done signal of previous proc. module.
    ADDR     : in std_logic_vector(ADDR_WIDTH-1 downto 0); --! addr_in
    DATA     : in std_logic_vector(RAM_WIDTH-1 downto 0);  --! din
    WRITE_EN : in std_logic
  );
end FileWriter;


architecture behavior of FileWriter is
begin

procFile : process(CLK)
  variable START_LATCH : std_logic := '0';            
  variable INIT        : boolean := false; --! File not yet open
  variable FILE_STATUS : file_open_status;
  file     FILE_OUT    : text;   
  variable LINE_OUT    : line;                              
  variable BX_CNT      : natural := 0;  --! Event counter
  constant TXT_WIDTH   : natural := 11; --! Column width in output .txt file

  function to_hexstring ( VAR : std_logic_vector) return string is
  -- Convert to string, with "0x" prefix.
  begin    
    return "0x"&to_hstring(unsigned(var));
  end;

begin

  -- Check user didn't change values of derived generics.
  assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;
  assert (ADDR_WIDTH = clogb2(RAM_DEPTH)) report "User changed ADDR_WIDTH" severity FAILURE;

  if rising_edge(CLK) then

    if (START = '1') then
      START_LATCH := '1';
    end if;

    -- Open and initialize file

    if (not INIT) then
      INIT := true;
      file_open(FILE_STATUS, FILE_OUT, FILE_NAME, write_mode); 
      assert (FILE_STATUS = open_ok) report "Failed to open file "&FILE_NAME severity FAILURE;
      -- Write column headings
      write(LINE_OUT, string'("TIME (ns)"), right, TXT_WIDTH);
      write(LINE_OUT, string'("BX")       , right, TXT_WIDTH);
      write(LINE_OUT, string'("ADDR")     , right, TXT_WIDTH);
      write(LINE_OUT, string'("DATA")     , right, 2*TXT_WIDTH);
      writeline(FILE_OUT, LINE_OUT);      
    end if;

    -- Write data from events

    if (START_LATCH = '1') then

      if (WRITE_EN = '1') then 
        -- Valid data, so write it to file.
        write(LINE_OUT, NOW   , right, TXT_WIDTH); 
        write(LINE_OUT, BX_CNT, right, TXT_WIDTH);
        write(LINE_OUT, to_hexstring(ADDR), right, TXT_WIDTH);
        write(LINE_OUT, to_hexstring(DATA), right, 2*TXT_WIDTH);
        writeline(FILE_OUT, LINE_OUT);      
      end if;

      if (DONE = '1') then
        -- Module has finished event, so increment event counter.
        BX_CNT := BX_CNT + 1;

        if (BX_CNT = MAX_EVENTS) then
          -- All events processed, so close file.
          file_close(FILE_OUT);
        end if;
      end if;
    end if;
  end if;

end process procFile;

end behavior;
