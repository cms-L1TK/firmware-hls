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
--  Outputs on each clk cycle one RAM data word & address,
--  with write-enable flag indicating if valid word.
--  The data are read from a .txt file, but if this has less than
--  108 entries per event, it outputs invalid signals for the
--  remaining clks in that event.
--
--  The start of the first event can be delayed by specified amount.
-- ==================================================================

entity FileReader is
  generic (
    FILE_NAME  : string;   --! Name of .txt file corresponding to memory content
    DELAY      : natural := 0;     --! Delay output signals by this many clocks.
    RAM_WIDTH  : natural := 18;    --! RAM data width
    NUM_PAGES  : natural := 2;     --! Number of pages in RAM memory
    NUM_BINS   : natural := 1;     --! Number of bins in RAM memory (1 if unbinned)
    DEBUG      : boolean := false; --! Debug printout
    FILE_NAME_DEBUG : string  := "";  --! Name of .txt file for debug printout.
    -- Leave following parameters at their default values.
    RAM_DEPTH  : natural := NUM_PAGES*PAGE_LENGTH; --! RAM depth (no. of entries)
    ADDR_WIDTH : natural := clogb2(RAM_DEPTH);     --! RAM address
    BIN_SIZE   : natural := PAGE_LENGTH/NUM_BINS   --! Max. entries per RAM bin
  );
  port (
    CLK      : in  std_logic;
    ADDR     : out std_logic_vector(ADDR_WIDTH-1 downto 0);
    DATA     : out std_logic_vector(RAM_WIDTH-1 downto 0);
    START    : out std_logic;
    WRITE_EN : out std_logic
  );
end FileReader;


architecture behavior of FileReader is
  signal EVENT_CNT : integer := -1;   --! Used for debug printout
  signal WAITING   : boolean := true; --! Used to delay start of first event.
begin

procFile : process(CLK)
  variable INIT        : boolean := false; --! File not yet open
  variable DONE        : boolean := false; --! File read and closed.        
  variable FILE_STATUS : file_open_status;
  file     FILE_IN     : text;   
  variable LINE_IN     : line;                              
  variable BX_CNT      : integer := -1; --! Event counter
  variable DATA_CNT    : natural := MAX_ENTRIES;  --! Current count of data from within current page.
  variable PAGE        : natural := 0;  --! Current page in memory 
  variable MEM_BIN     : natural := 0;  --! Current bin in memory
  variable POS_IN_MEM_BIN : natural :=0; --! Current location in mem bin.
  constant NUM_X_CHAR_UNBINNED  : natural := 2;  --! Count of 'x' characters in line, before value to read
  constant NUM_X_CHAR_BINNED    : natural := 1;  --! Count of 'x' characters in line, before value to read
  variable CNT_X_CHAR  : natural := 0;  --! Current count of 'x' characters
  variable CHAR        : character;     --! Character
  variable FOUND_WORD  : boolean := false;
  variable emDATA      : std_logic_vector(EMDATA_WIDTH-1 downto 0) := (others => '0');
  variable LOOPING     : boolean := true; --! Need another loop to make output.
  variable CREATE_DUMMY_DATA  : boolean := false; --! Inventing null data. 

begin

  -- Check user didn't change values of derived generics.
  assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;
  assert (ADDR_WIDTH = clogb2(RAM_DEPTH)) report "User changed ADDR_WIDTH" severity FAILURE;
  assert (BIN_SIZE = PAGE_LENGTH/NUM_BINS) report "User changed BIN_SIZE" severity FAILURE;

  if rising_edge(CLK) then
  
    -- Open file
    if (not INIT) then
      INIT := true;
      file_open(FILE_STATUS, FILE_IN, FILE_NAME, read_mode); 
      assert (FILE_STATUS = open_ok) report "Failed to open file "&FILE_NAME severity FAILURE;
    end if;

    if (not DONE and endFile(FILE_IN)) then
      file_close(FILE_IN);
      DONE := true;
    end if;

    if (WAITING or DONE) then

      -- No data, either because we're waiting to start reading it
      -- or because we already finished reading it.
      WRITE_EN <= '0';
      ADDR     <= (others => '0');
      DATA     <= (others => '0');
 
    else 

      LOOPING := true;

      -- Read next data word from file.

      findNextDataLine : while LOOPING loop

        if (not CREATE_DUMMY_DATA) then
          -- Read next line in file.
          readline (FILE_IN, LINE_IN);
        end if;

        if (LINE_IN.all(1 to 2) = "BX") then 

          -- New event header

          if (DATA_CNT < MAX_ENTRIES) then

            -- Last event didn't have full number of entries in file,
            -- so invent dummy data to represent the remainder.
            WRITE_EN <= '0';
            ADDR     <= (others => '0');
            DATA     <= (others => '0');
            DATA_CNT := DATA_CNT + 1;
            -- We sent output signals, so stop looping
            LOOPING := false;
            -- Note that we're creating dummy data.
            CREATE_DUMMY_DATA := true;

          else

            -- We've finished processing last event, so get on with new one.
            BX_CNT := BX_CNT + 1;
            PAGE := BX_CNT mod NUM_PAGES;
            DATA_CNT := 0;
            -- Note that we are now reading data from file again.
            CREATE_DUMMY_DATA := false;

          end if;

        elsif (LINE_IN.all = "") then

          -- Skip blank lines

        elsif (BX_CNT >= 0) then

          CNT_X_CHAR := 0;
          FOUND_WORD := false;

          -- Line containing data. Extract data word.

          if (NUM_BINS > 1) then
            -- Get memory bin 
            read(LINE_IN, CHAR);        
            char2int(CHAR, MEM_BIN);
            read(LINE_IN, CHAR);        
            read(LINE_IN, CHAR);        
            char2int(CHAR, POS_IN_MEM_BIN);
          end if;

          rd_col : while (LINE_IN'length > 0) loop -- Loop over the columns
            read(LINE_IN, CHAR);                 -- Read chars ...
            if (CHAR = 'x') then                   -- ... until the next x
              CNT_X_CHAR := CNT_X_CHAR + 1;
              if ((NUM_BINS > 1 and CNT_X_CHAR = NUM_X_CHAR_BINNED) or
                  (NUM_BINS = 1 and CNT_X_CHAR = 1 and RAM_WIDTH = 36) or -- Bodge for IL as they are unbinned but only contains one 'x'
                  (NUM_BINS = 1 and CNT_X_CHAR = NUM_X_CHAR_UNBINNED)) then -- No. of 'x' chars reached
                -- Found data word.
                FOUND_WORD := true;
                hread(line_in, emDATA(LINE_IN'length*4-1 downto 0)); -- Read remainer of line as hex. 
              end if;
            end if;
          end loop rd_col;

          assert FOUND_WORD report "Unexpected data line format in "&FILE_NAME&" "&integer'image(CNT_X_CHAR) severity FAILURE;   

          -- Truncate data word to desired width.
          DATA <= emDATA(RAM_WIDTH-1 downto 0);
          if (NUM_BINS > 1) then
            -- Binned memory
            ADDR <= std_logic_vector(to_unsigned(POS_IN_MEM_BIN + BIN_SIZE*MEM_BIN + PAGE_LENGTH*PAGE, ADDR_WIDTH));
          else
            -- Unbinned memory
            ADDR <= std_logic_vector(to_unsigned(DATA_CNT + PAGE_LENGTH*PAGE, ADDR_WIDTH));
          end if;
          WRITE_EN <= '1';
          DATA_CNT := DATA_CNT + 1;
          -- We sent output signals, so stop looping
          LOOPING := false;

        else
          assert false report "No BX header before data in "&FILE_NAME severity FAILURE;
        end if;
      end loop findNextDataLine;
    end if;

    -- Note when event processing starts
    if (BX_CNT >= 0) then
      START <= '1';
    else
      START <= '0';
    end if;
    -- Used for debug printout
    EVENT_CNT <= BX_CNT;  

  end if;
end process procFile;


procDelay : process(CLK)
  -- Process to delay start of first event output by required amount.   
  variable COUNT : natural := 0;
begin

  if rising_edge(CLK) then
    if (COUNT < DELAY) then
      COUNT := COUNT + 1;
      WAITING <= true;
    else
      WAITING <= false;
    end if;
  end if;

end process procDelay;


procDebugPrint : process(CLK)
  -- Debug printout of output signals.

  file     FILE_OUT  : text;  --! File for debug output   
  variable FILE_STATUS : file_open_status;
  variable LINE_OUT  : line;  --! Line for debug output
  variable INIT        : boolean := false; --! Debug file not yet open
begin

  if DEBUG then
    if rising_edge(CLK) then

      -- Open debug printout file
      if (DEBUG and not INIT) then
        INIT := true;
        file_open(FILE_STATUS, FILE_OUT, FILE_NAME_DEBUG, write_mode); 
        assert (FILE_STATUS = open_ok) report "Failed to open file "&FILE_NAME_DEBUG severity FAILURE;
      end if;

      if (DEBUG and WRITE_EN = '1') then 
        write(LINE_OUT, string'("BX=")); write(LINE_OUT, EVENT_CNT);
        write(LINE_OUT, string'(" ADDR=")); hwrite(LINE_OUT, ADDR);
        write(LINE_OUT, string'(" DATA=")); hwrite(LINE_OUT, DATA);
        write(LINE_OUT, string'(" at SIM time ")); write(LINE_OUT, NOW); 
        writeline(FILE_OUT, LINE_OUT);      
      end if;
    end if;
  end if;
end process procDebugPrint;


end behavior;
