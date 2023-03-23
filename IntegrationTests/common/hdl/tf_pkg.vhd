--==========================================================================
--! @file
--! @brief Package for the track finding top and test bench using TextIO.
--! @author rglein@CUBoulder
--! @date 2020-05-28
--! @version v.1.0
--=============================================================================

--! Standard library
library ieee;
--! Standard package
use ieee.std_logic_1164.all;
--! Signed/unsigned calculations
use ieee.numeric_std.all;
--! Math real
use ieee.math_real.all;
--! TextIO
use ieee.std_logic_textio.all;
--! Standard functions
library std;
--! Standard TextIO functions
use std.textio.all;

--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;


--! @brief Package.
package tf_pkg is

  -- ########################### Constants #######################
  constant DEBUG                  : boolean := true; --! Debug off/on
  constant MAX_EVENTS             : natural := 100;  --! Max. number of BX events
  constant MAX_ENTRIES            : natural := 108;  --! Max. number of entries: 108 = BX period with 240 MHz
  constant EMDATA_WIDTH           : natural := 72;   --! Max. bit width of emData
  constant N_MEM_BINS             : natural := 8;    --! Number of memory bins
  constant N_ENTRIES_PER_MEM_BINS : natural := 16;   --! Number of entries per memory bin
  constant N_MEM_BINS_ME_DISK     : natural := 16;   --! Number of memory bins for ME disk
  constant N_ENTRIES_PER_MEM_BINS_ME_DISK : natural := 8;   --! Number of entries per memory bin for ME disk
  constant PAGE_LENGTH            : natural := 128;  --! Page length of all memories
  constant PAGE_LENGTH_CM         : natural := 1024; --! Page length of all CM
                                                     -- binned memories
  constant MEM_READ_LATENCY       : natural := 2;    --! Memory read latency.
  -- Memory width constants
  constant RAM_WIDTH_AS    : natural := 36; --! Width for memories
  constant RAM_WIDTH_TPROJ : natural := 60; --! Width for memories
  constant RAM_WIDTH_AP    : natural := 60; --! Width for memories

  -- Boolean indicating if this is Vivado simulation.
  constant IS_SIMULATION : boolean := FALSE
-- pragma synthesis_off
    or TRUE    -- this line is only executed if Vivado simulation.
-- pragma synthesis_on
  ;
  
  -- ########################### Types ###########################

  -- 2D
  type t_arr2_1b  is array(0 to 1) of std_logic;
  type t_arr2_8b  is array(0 to 1) of std_logic_vector(7 downto 0);
  type t_arr4_12b  is array(0 to 3) of std_logic_vector(11 downto 0);
  type t_arr4_16b  is array(0 to 3) of std_logic_vector(15 downto 0);
  type t_arr4_17b  is array(0 to 3) of std_logic_vector(16 downto 0);
  type t_arr5_11b  is array(0 to 4) of std_logic_vector(10 downto 0);
  type t_arr5_16b  is array(0 to 4) of std_logic_vector(15 downto 0);
  type t_arr8_1b  is array(0 to 7) of std_logic;
  type t_arr8_2b  is array(0 to 7) of std_logic_vector(1 downto 0);
  type t_arr8_3b  is array(0 to 7) of std_logic_vector(2 downto 0);
  type t_arr8_4b  is array(0 to 7) of std_logic_vector(3 downto 0);
  type t_arr64_4b  is array(0 to 63) of std_logic_vector(3 downto 0);
  type t_arr64_1b  is array(0 to 63) of std_logic;
  type t_arr8_5b  is array(0 to 7) of std_logic_vector(4 downto 0);
  type t_arr8_8b  is array(0 to 7) of std_logic_vector(7 downto 0);
  type t_arr8_9b  is array(0 to 7) of std_logic_vector(8 downto 0);
  type t_arr8_10b is array(0 to 7) of std_logic_vector(9 downto 0);
  type t_arr8_16b is array(0 to 7) of std_logic_vector(15 downto 0);
  type t_arr8_14b is array(0 to 7) of std_logic_vector(13 downto 0);
  type t_arr8_24b is array(0 to 7) of std_logic_vector(23 downto 0);
  type t_arr8_60b is array(0 to 7) of std_logic_vector(59 downto 0);
  -- 3D
  type t_arr2_8_1b is array(0 to 1) of t_arr8_1b;
  type t_arr2_8_8b is array(0 to 1) of t_arr8_8b;
  type t_arr8_8_1b is array(0 to 7) of t_arr8_1b;
  type t_arr8_8_4b is array(0 to 7) of t_arr8_4b;
  -- 4D
  type t_arr8_8_8_1b is array(0 to 7) of t_arr8_8_1b;
  type t_arr8_8_8_4b is array(0 to 7) of t_arr8_8_4b;
  -- Others
  type t_arr_1d_int is array(natural range <>) of integer;                  --! 1D array of int
  type t_arr_2d_int is array(natural range <>,natural range <>) of integer; --! 2D array of int
  type t_arr_2d_slv is array(natural range <>, natural range <>) of std_logic_vector(EMDATA_WIDTH-1 downto 0); --! 2D array of slv

  -- Used for memories
  type t_arr_7b  is array(integer range<>) of std_logic_vector(6 downto 0);
  subtype t_arr2_7b is t_arr_7b(0 to 1);
  subtype t_arr8_7b is t_arr_7b(0 to 7);
  type t_arr8_2_7b is array(0 to 7) of t_arr2_7b;

  type t_arr_8_5b  is array(integer range<>) of t_arr8_5b;
  subtype t_arr2_8_5b is t_arr_8_5b(0 to 1);
  subtype t_arr8_8_5b is t_arr_8_5b(0 to 7);
  type t_arr8_8_8_5b is array(0 to 7) of t_arr8_8_5b;

  type t_arr_64_4b  is array(integer range<>) of t_arr64_4b;
  subtype t_arr2_64_4b is t_arr_64_4b(0 to 1);
  subtype t_arr4_64_4b is t_arr_64_4b(0 to 3);

  type t_arr_64_1b  is array(integer range<>) of t_arr64_1b;
  subtype t_arr2_64_1b is t_arr_64_1b(0 to 1);
  subtype t_arr4_64_1b is t_arr_64_1b(0 to 3);
  
  -- Could be used in place of t_arr_7b. 
  -- type t_arr_meb is array(integer range<>) of std_logic_vector(clogb2(MAX_ENTRIES)-1 downto 0);

  -- ########################### Functions ################################################################
  function clogb2     (bit_depth : integer) return integer;

  function to_bstring(sl : std_logic) return string;

  function to_bstring(slv : std_logic_vector) return string;

  function to_bstring(slv : t_arr64_1b) return string;

  function to_bstring(slv : t_arr64_4b) return string;

  -- -- ########################### Procedures #######################
  procedure char2int (
    char : in  character;            --! Input charater 0...9, a...f, and A...F
    int  : out integer range 0 to 15 --! Output integer 0...15
  );
  procedure read_emData (
    file_path     : in    string;  --! File path as string
    data_arr      : out   t_arr_2d_slv(0 to MAX_EVENTS-1,0 to PAGE_LENGTH-1); --! Dataarray with read values
    n_entries_arr : inout t_arr_1d_int(0 to MAX_EVENTS-1)                       --! Number of entries per event
  );
  procedure read_emData_bin (
    file_path     : in    string;  --! File path as string
    data_arr      : out   t_arr_2d_slv(0 to MAX_EVENTS-1,0 to PAGE_LENGTH-1); --! Dataarray with read values
    n_entries_arr : inout t_arr_2d_int(0 to MAX_EVENTS-1,0 to N_MEM_BINS-1)     --! Number of entries per event
  );
  procedure write_header_line (
    file_path       : in string;  --! File path as string
    signal_name     : in string;  --! Signal name that will be printed in output file
    N_PAGES         : in natural  --! Number of pages
  );
  procedure write_emData_line_2p (
    reset           : in std_logic;        --! HDL (global) reset
    bx_cnt          : in integer;          --! HDL (global) counter
    done            : in std_logic;        --! HLS module done
    bx_out          : in std_logic_vector; --! HLS module BX counter
    bx_out_vld      : in std_logic;        --! HLS module BX counter valid
    file_path       : in string;           --! File path as string
    signal_name     : in string;           --! Signal name that will be printed in output file
    mem_data        : in std_logic_vector; --! Data write values
    mem_wea         : in std_logic;        --! Write enable of data
    mem_addr        : in std_logic_vector; --! Memory address
    n_entries_p2    : in t_arr2_8b;    --! Number of entries per page
    n_entries_p2_we : in t_arr2_1b     --! Number of entries per page write enable
  );
  procedure write_emData_line_8p (
    reset           : in std_logic;        --! HDL (global) reset
    bx_cnt          : in integer;          --! HDL (global) counter
    done            : in std_logic;        --! HLS module done
    bx_out          : in std_logic_vector; --! HLS module BX counter
    bx_out_vld      : in std_logic;        --! HLS module BX counter valid
    file_path       : in string;           --! File path as string
    signal_name     : in string;           --! Signal name that will be printed in output file
    mem_data        : in std_logic_vector; --! Data write values
    mem_wea         : in std_logic;        --! Write enable of data
    mem_addr        : in std_logic_vector; --! Memory address
    n_entries_p2    : in t_arr8_8b;    --! Number of entries per page
    n_entries_p2_we : in t_arr8_1b     --! Number of entries per page write enable
  );

end package tf_pkg;


package body tf_pkg is

  -- ########################### Functions ################################################################

  --! @brief Gets #bits needed to form any value from 0 to bit_depth-1.
  --! Identical result to clogb2_old() if arg. is exact power of 2.
  --! Result 1 larger than clogb2_old() otherwise.
  --! Exception if arg. = 2, when it is 1 larger than clogb2_old().
  function clogb2 (bit_depth : integer) return integer is
  begin
    return integer( ceil( log2( real( bit_depth ) ) ) );
  end;

  function to_bstring(sl : std_logic) return string is
  variable sl_str_v : string(1 to 3);  -- std_logic image with quotes around
  begin
    sl_str_v := std_logic'image(sl);
    return "" & sl_str_v(2);  -- "" & character to get strings
  end function;

  function to_bstring(slv : std_logic_vector) return string is
  alias    slv_norm : std_logic_vector(1 to slv'length) is slv;
  variable sl_str_v : string(1 to 1);  -- String of std_logic
  variable res_v    : string(1 to slv'length);
  begin
    for idx in slv_norm'range loop
      sl_str_v := to_bstring(slv_norm(idx));
      res_v(idx) := sl_str_v(1);
    end loop;
    return res_v;
  end function;

  function to_bstring(slv : t_arr64_1b) return string is
  variable sl_str_v : string(1 to 1);  -- String of std_logic
  variable res_v    : string(0 to 63);
  begin
    for idx in 63 downto 0 loop
      sl_str_v := to_bstring(slv(idx));
      res_v(idx) := sl_str_v(1);
    end loop;
    return res_v;
  end function;

  function to_bstring(slv : t_arr64_4b) return string is
  variable sl_str_v : string(1 to 4);  -- String of std_logic
  variable res_v    : string(0 to 319);
  begin
    for idx in 63 downto 0 loop
      sl_str_v := to_bstring(slv(idx));
      res_v(idx*5) := sl_str_v(1);
      res_v(idx*5+1) := sl_str_v(2);
      res_v(idx*5+2) := sl_str_v(3);
      res_v(idx*5+3) := sl_str_v(4);
      res_v(idx*5+4) := '-';
    end loop;
    return res_v;
  end function;



  -- ########################### Procedures ################################################################
  --! @brief Convert character to integer
  --! Procedure to limit the output by using range
  procedure char2int (
    char : in  character;            --! Input charater 0...9, a...f, and A...F
    int  : out integer range 0 to 15 --! Output integer 0...15
  ) is
  begin
    if    (char = 'a') or (char = 'A') then
      int := 10;
    elsif (char = 'b') or (char = 'B') then
      int := 11;
    elsif (char = 'c') or (char = 'C') then
      int := 12;
    elsif (char = 'd') or (char = 'D') then
      int := 13;
    elsif (char = 'e') or (char = 'E') then
      int := 14;
    elsif (char = 'f') or (char = 'F') then
      int := 15;
    else
      int := character'pos(char)-48;
    end if;
  end char2int;

  --! @brief TextIO procedure to read emData for non-binned memories all at once
  --! Assuming normal memory format with the first column as entries counter per BX
  --! N_PAGES=2/8: BX = 000 (even) Event : 1 is page 0/0 and BX = 001 (odd) Event : 2 is page 1/1 ...
  --!          ... BX = 010 (even) Event : 3 is page 0/2 ... BX = 111 (odd) Event : 8 is page 1/7
  procedure read_emData (
    file_path     : in    string;  --! File path as string
    data_arr      : out   t_arr_2d_slv(0 to MAX_EVENTS-1,0 to PAGE_LENGTH-1); --! Dataarray with read values
    n_entries_arr : inout t_arr_1d_int(0 to MAX_EVENTS-1)                       --! Number of entries per event
  ) is
  constant N_X_CHAR        : integer :=2;                        --! Count of 'x' characters before actual value to read
  file     file_in         : text open READ_MODE is file_path;   -- Text - a file of character strings
  variable line_in         : line;                               -- Line - one string from a text file
  variable bx_cnt          : integer;                            -- BX counter
  variable i_bx_row        : integer;                            -- Read row index
  variable i_rd_col        : integer;                            -- Read column index
  variable cnt_x_char      : integer;                            -- Count of 'x' characters
  variable char            : character;                          -- Character
  begin
    data_arr      := (others => (others => (others => '0'))); -- Init
    n_entries_arr := (others => 0);                           -- Init
    bx_cnt        := -1;                                      -- Init
    l_rd_row : while not endfile(file_in) loop -- Read until EoF
    --l_rd_row : for i in 0 to 5 loop -- Debug
      readline (file_in, line_in);
      if (line_in.all(1 to 2) = "BX" or line_in.all = "") then -- Identify event header line or empty line
        i_bx_row := 0;       -- Init
        bx_cnt   := bx_cnt +1;
        --if DEBUG=true then writeline(output, line_in); end if;
      elsif (bx_cnt >= 0) then
        i_rd_col := 0;   -- Init
        cnt_x_char := 0; -- Init
        l_rd_col : while line_in'length>0 loop -- Loop over the columns
          read(line_in, char);                 -- Read chars ...
          if (char='x') then                   -- ... until the next x
            if (cnt_x_char >= N_X_CHAR-1) then -- Number of 'x' chars reached
              hread(line_in, data_arr(bx_cnt,i_bx_row)(line_in'length*4-1 downto 0)); -- Read value as hex slv (line_in'length in hex)
            end if;
            cnt_x_char := cnt_x_char +1;
          end if;
        i_rd_col := i_rd_col +1;
        end loop l_rd_col;
        n_entries_arr(bx_cnt) := n_entries_arr(bx_cnt) +1;
        i_bx_row := i_bx_row +1;
      else
        assert false report "No BX header before data in txt file" severity FAILURE;
      end if;
    end loop l_rd_row;
    file_close(file_in);
  end read_emData;

  --! @brief TextIO procedure to read emData for binned memories all at once
  --! Assuming binned memory format with the first column as bin address (0...7, address_offset=16) ...
  --! ...and the second column as bin entry address (0...F)
  --! N_PAGES=2/8: BX = 000 (even) Event : 1 is page 0/0 and BX = 001 (odd) Event : 2 is page 1/1 ...
  --!          ... BX = 010 (even) Event : 3 is page 0/2 ... BX = 111 (odd) Event : 8 is page 1/7
  --BX = 000 Event : 1      // page 0/0   (emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC17n1_04.dat)
  --1 0 0111111|011|101 0x0FDD // addr 16
  --2 0 1000001|011|001 0x1059 // addr 32
  --3 0 0101101|100|010 0x0B62 // addr 48
  --3 1 0101110|110|010 0x0BB2 // addr 49
  --...
  --BX = 001 Event : 2      // page 1/1
  --0 0 1001011|000|011 0x12C3 // addr 128
  --...
  --BX = 010 Event : 3      // page 0/2
  --1 0 0110000|010|001 0x0C11 // addr 128*2+16
  --...
  --BX = 111 Event : 8      // page 1/7
  --3 0 0101000|011|000 0x0A18 // addr 128*7+48
  --3 1 0101001|110|100 0x0A74 // addr 128*7+49
  --...
  --BX = 000 Event : 9      // page 0/0
  --1 0 0101101|001|001 0x0B49 // addr 16
  --1 1 0101110|101|001 0x0BA9 // addr 17
  --...
  procedure read_emData_bin (
    file_path     : in    string;  --! File path as string
    data_arr      : out   t_arr_2d_slv(0 to MAX_EVENTS-1,0 to PAGE_LENGTH-1); --! Dataarray with read values
    n_entries_arr : inout t_arr_2d_int(0 to MAX_EVENTS-1,0 to N_MEM_BINS-1)     --! Number of entries per event per bin
  ) is
  constant N_X_CHAR        : integer :=1;                        --! Count of 'x' characters before actual value to read
  file     file_in         : text open READ_MODE is file_path;   -- Text - a file of character strings
  variable line_in         : line;                               -- Line - one string from a text file
  variable bx_cnt          : integer;                            -- BX counter
  variable i_bx_row        : integer;                            -- Read row index
  variable i_rd_col        : integer;                            -- Read column index
  variable cnt_x_char      : integer;                            -- Count of 'x' characters
  variable char            : character;                          -- Character
  variable mem_bin         : integer;                            -- Bin number of memory
  variable n_entry_mem_bin : integer;                            -- Entry number of memory bin
  begin
    data_arr      := (others => (others => (others => '0'))); -- Init
    n_entries_arr := (others => (others => 0));               -- Init
    bx_cnt        := -1;                                      -- Init
    l_rd_row : while not endfile(file_in) loop -- Read until EoF
    --l_rd_row : for i in 0 to 5 loop -- Debug
      readline (file_in, line_in);
      if (line_in.all(1 to 2) = "BX" or line_in.all = "") then -- Identify event header line or empty line
        i_bx_row := 0;       -- Init
        bx_cnt   := bx_cnt +1;
        --if DEBUG=true then writeline(output, line_in); end if;
      elsif (bx_cnt >= 0) then
        i_rd_col := 0;   -- Init
        cnt_x_char := 0; -- Init
        l_rd_col : while line_in'length>0 loop  -- Loop over the columns
          read(line_in, char);                  -- Read chars ...
            if (i_rd_col=0) then
              char2int(char, mem_bin);
            end if;
            if (i_rd_col=2) then
              char2int(char, n_entry_mem_bin);
            end if;
            if (char='x') then                   -- ... until the next x
              cnt_x_char := cnt_x_char +1;
              if (cnt_x_char >= N_X_CHAR) then -- Number of 'x' chars reached
                hread(line_in, data_arr(bx_cnt,mem_bin*N_ENTRIES_PER_MEM_BINS+n_entry_mem_bin)(line_in'length*4-1 downto 0)); -- Read value as hex slv (line_in'length in hex)
              end if;
              n_entries_arr(bx_cnt,mem_bin) := n_entries_arr(bx_cnt,mem_bin) +1;
            end if;
        i_rd_col := i_rd_col +1;
        end loop l_rd_col;
        i_bx_row := i_bx_row +1;
      else
        assert false report "No BX header before data in txt file" severity FAILURE;
      end if;
    end loop l_rd_row;
    file_close(file_in);
  end read_emData_bin;

  --! @brief TextIO procedure to write emData for non-binned memories one line per clock cycle
  procedure write_header_line (
    file_path       : in string;  --! File path as string
    signal_name     : in string;  --! Signal name that will be printed in output file
    N_PAGES         : in natural  --! Number of pages
  ) is
  file     file_out : text is file_path; -- Text - a file of character strings
  variable line_out : line;              -- Line - one string from a text file
  begin
    file_open(file_out, file_path, WRITE_MODE);
    write(line_out, string'("time"), right, 20); write(line_out, string'("BX#"), right, 4);
    write(line_out, string'("reset"), right, 6);
    l_pages : for i in 0 to N_PAGES-1 loop
      write(line_out, string'("we_p"),    right, 5); write(line_out, i, right, 1);
      write(line_out, string'("n_ent_p"), right, 8); write(line_out, i, right, 1);
    end loop l_pages;
    write(line_out, string'("wea"), right, 4); write(line_out, string'("mem_addr"), right, 9);
    write(line_out, signal_name, right, signal_name'length+1);
    write(line_out, string'("done"), right, 5);  write(line_out, string'("bx_out_vld"), right, 11); write(line_out, string'("bx_out"), right, 7);
    writeline (file_out, line_out); -- Write line
    file_close(file_out);
  end write_header_line;
  --! @brief TextIO procedure to write emData for non-binned memories one line per clock cycle
  procedure write_emData_line_2p (
    reset           : in std_logic;        --! HDL (global) reset
    bx_cnt          : in integer;          --! HDL (global) counter
    done            : in std_logic;        --! HLS module done
    bx_out          : in std_logic_vector; --! HLS module BX counter
    bx_out_vld      : in std_logic;        --! HLS module BX counter valid
    file_path       : in string;           --! File path as string
    signal_name     : in string;           --! Signal name that will be printed in output file
    mem_data        : in std_logic_vector; --! Data write values
    mem_wea         : in std_logic;        --! Write enable of data
    mem_addr        : in std_logic_vector; --! Memory address
    n_entries_p2    : in t_arr2_8b;    --! Number of entries per page
    n_entries_p2_we : in t_arr2_1b     --! Number of entries per page write enable
  ) is
  constant N_PAGES  : integer := 2;      --! Number of pages
  file     file_out : text is file_path; -- Text - a file of character strings
  variable line_out : line;              -- Line - one string from a text file
  variable v_zero   : std_logic_vector(mem_data'length-1 downto 0) := (others => '0');  -- Zero vector
  begin
    file_open(file_out, file_path, APPEND_MODE);
    write(line_out, NOW, right, 20); write(line_out, bx_cnt, right, 4);
    write(line_out, string'("0b"), right, 5);   write(line_out, reset, right, 1);
    l_pages : for i in 0 to N_PAGES-1 loop
      write(line_out, string'("0b"), right, 5);   write(line_out, n_entries_p2_we(i), right, 1);
      write(line_out, string'("0x"), right, 7);  hwrite(line_out, n_entries_p2(i),    right, 2);
    end loop l_pages;
    write(line_out, string'("0b"), right, 3);   write(line_out, mem_wea, right, 1);
    write(line_out, string'("0x"), right, 7);  hwrite(line_out, std_logic_vector(unsigned(mem_addr)), right, 2);
    if (mem_wea='1') then -- Only write if enable
      write(line_out, string'("0x"), right, signal_name'length+1-(mem_data'length+3)/4); hwrite(line_out, mem_data, right, (mem_data'length+3)/4);
    else
      write(line_out, string'("0x"), right, signal_name'length+1-(mem_data'length+3)/4); hwrite(line_out, v_zero,   right, (mem_data'length+3)/4);
    end if;
    write(line_out, string'("0b"), right, 4);   write(line_out, done,       right, 1);
    write(line_out, string'("0b"), right, 10);  write(line_out, bx_out_vld, right, 1);
    write(line_out, string'("0x"), right, 6);  hwrite(line_out, bx_out,     right, (bx_out'length+3)/4);
    writeline (file_out, line_out); -- Write line
    file_close(file_out);
  end write_emData_line_2p;
  --! @brief TextIO procedure to write emData for non-binned memories one line per clock cycle
  procedure write_emData_line_8p (
    reset           : in std_logic;        --! HDL (global) reset
    bx_cnt          : in integer;          --! HDL (global) counter
    done            : in std_logic;        --! HLS module done
    bx_out          : in std_logic_vector; --! HLS module BX counter
    bx_out_vld      : in std_logic;        --! HLS module BX counter valid
    file_path       : in string;           --! File path as string
    signal_name     : in string;           --! Signal name that will be printed in output file
    mem_data        : in std_logic_vector; --! Data write values
    mem_wea         : in std_logic;        --! Write enable of data
    mem_addr        : in std_logic_vector; --! Memory address
    n_entries_p2    : in t_arr8_8b;    --! Number of entries per page
    n_entries_p2_we : in t_arr8_1b     --! Number of entries per page write enable
  ) is
  constant N_PAGES  : integer := 8;      --! Number of pages
  file     file_out : text is file_path; -- Text - a file of character strings
  variable line_out : line;              -- Line - one string from a text file
  variable v_zero   : std_logic_vector(mem_data'length-1 downto 0) := (others => '0');  -- Zero vector
  begin
    file_open(file_out, file_path, APPEND_MODE);
    write(line_out, NOW, right, 20); write(line_out, bx_cnt, right, 4);
    write(line_out, string'("0b"), right, 5);   write(line_out, reset, right, 1);
    l_pages : for i in 0 to N_PAGES-1 loop
      write(line_out, string'("0b"), right, 5);   write(line_out, n_entries_p2_we(i), right, 1);
      write(line_out, string'("0x"), right, 7);  hwrite(line_out, n_entries_p2(i),    right, 2);
    end loop l_pages;
    write(line_out, string'("0b"), right, 3);   write(line_out, mem_wea, right, 1);
    write(line_out, string'("0x"), right, 6);  hwrite(line_out, std_logic_vector(unsigned(mem_addr)), right, 2);
    if (mem_wea='1') then -- Only write if enable
      write(line_out, string'("0x"), right, signal_name'length+1-(mem_data'length+3)/4); hwrite(line_out, mem_data, right, (mem_data'length+3)/4);
    else
      write(line_out, string'("0x"), right, signal_name'length+1-(mem_data'length+3)/4); hwrite(line_out, v_zero,   right, (mem_data'length+3)/4);
    end if;
    write(line_out, string'("0b"), right, 4);   write(line_out, done,       right, 1);
    write(line_out, string'("0b"), right, 10);  write(line_out, bx_out_vld, right, 1);
    write(line_out, string'("0x"), right, 6);  hwrite(line_out, bx_out,     right, (bx_out'length+3)/4);
    writeline (file_out, line_out); -- Write line
    file_close(file_out);
  end write_emData_line_8p;

end package body tf_pkg;
