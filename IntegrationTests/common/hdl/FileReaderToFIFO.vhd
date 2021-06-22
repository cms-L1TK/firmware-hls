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

entity FileReaderToFIFO is
  generic (
    FILE_NAME  : string;   --! Name of .txt file corresponding to memory content
    DELAY      : natural := 0;     --! Delay output signals by this many clocks.
    FIFO_WIDTH  : natural := 39;    --! RAM data width
    DEBUG      : boolean := false; --! Debug printout
    FILE_NAME_DEBUG : string  := ""  --! Name of .txt file for debug printout.
  );
  port (
    CLK       : in  std_logic;
    READ_SHIT : in std_logic;
    EMPTY_NEG : out std_logic;
    DATA      : out std_logic_vector(FIFO_WIDTH-1 downto 0);
    START     : out std_logic
  );
end FileReaderToFIFO;


architecture behavior of FileReaderToFIFO is
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
  variable CHAR        : character;     --! Character
  variable FOUND_WORD  : boolean := false;
  variable emDATA      : std_logic_vector(EMDATA_WIDTH-1 downto 0) := (others => '0');
  variable LOOPING     : boolean := true; --! Need another loop to make output.
  variable CREATE_DUMMY_DATA  : boolean := false; --! Inventing null data. 
  variable v_line : line; -- Line for debug
  variable line_is_read : boolean := true; -- LINE_IN has been read by module
begin

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
      DATA <= (others => '0');
      -- EMPTY_NEG <= '0';
 
    else 

      -- don't read next stub until we have an read signal
      if (line_is_read or READ_SHIT='1') then
        LOOPING := true;
      else 
        LOOPING := false;
      end if;
      --LOOPING := true;

      -- Read next data word from file.

      findNextDataLine : while LOOPING loop
        
        if (not CREATE_DUMMY_DATA) then -- and (line_is_read or READ_SHIT='1')) then

          -- Read next line in file.
          readline (FILE_IN, LINE_IN);

        end if;
        -- write(v_line, string'("LINE ")); write(v_line,LINE_IN.all); write(v_line, string'(" BX_CNT ")); write(v_line, BX_CNT); write(v_line, string'(" DATA_CNT ")); write(v_line, DATA_CNT); writeline(output, v_line);
        if (LINE_IN.all(1 to 2) = "BX") then

          -- New event header

          EMPTY_NEG <= '0'; -- no reads
          line_is_read := true; -- don't have to wait for this line to be read as it doesn't contain data

          if (DATA_CNT < MAX_ENTRIES) then

            -- Last event didn't have full number of entries in file,
            -- so invent dummy data to represent the remainder.
            DATA     <= (others => '0');
            DATA_CNT := DATA_CNT + 1;
            -- We sent output signals, so stop looping
            LOOPING := false;
            -- Note that we're creating dummy data.
            CREATE_DUMMY_DATA := true;

          else

            -- We've finished processing last event, so get on with new one.
            BX_CNT := BX_CNT + 1;
            DATA_CNT := 0;
            -- Note that we are now reading data from file again.
            CREATE_DUMMY_DATA := false;
            
          end if;

        elsif (LINE_IN.all(1 to 2) /= "BX" and DATA_CNT >= MAX_ENTRIES) then
          
          -- skip data until next bx 
          
          if (BX_CNT = 99)  then -- or stop if end of file. FIX ME
            LOOPING := false;
          end if;
          
        elsif (LINE_IN.all = "") then

          -- Skip blank lines
          EMPTY_NEG <= '0'; -- no reads

        elsif (BX_CNT >= 0) then

          -- Line containing data. Extract data word.

          FOUND_WORD := false;
          EMPTY_NEG <= '1';  -- There is stub to be read

          rd_col : while (LINE_IN'length > 0) loop -- Loop over the columns
            read(LINE_IN, CHAR);                 -- Read chars ...
            if (CHAR = 'x') then                   -- ... until the x
              -- Found data word.
              FOUND_WORD := true;
              hread(line_in, emDATA(LINE_IN'length*4-1 downto 0)); -- Read remainer of line as hex. 
            end if;
          end loop rd_col;

          assert FOUND_WORD report "Unexpected data line format in "&FILE_NAME severity FAILURE;   

          -- Truncate data word to desired width.
          DATA <= emDATA(FIFO_WIDTH-1 downto 0);

          DATA_CNT := DATA_CNT + 1;
          -- We sent output signals, so stop looping
          LOOPING := false;

          -- Don't read the next line until it has been read
          if (READ_SHIT='1') then
            line_is_read := true;
          else
            line_is_read := false;
          end if;

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

      if (DEBUG and READ_SHIT = '1') then 
        write(LINE_OUT, string'("BX=")); write(LINE_OUT, EVENT_CNT);
        write(LINE_OUT, string'(" DATA=")); hwrite(LINE_OUT, DATA);
        write(LINE_OUT, string'(" at SIM time ")); write(LINE_OUT, NOW); 
        writeline(FILE_OUT, LINE_OUT);      
      end if;
    end if;
  end if;
end process procDebugPrint;


end behavior;
