--===========================================================================
--! @file
--! @brief this module continously reads memories. Used as interfaces to the
--  VMSMER and PC modules of the AS and TPAR
--! @author Anders.Ryd@cornell.edu
--! @date 2024-02-25
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

entity mem_reader is
  generic (
    RAM_WIDTH       : natural := 36;               --! Specify RAM data width
    NUM_PAGES       : natural := 8;                --! Specify no. Pages in RAM
                                                   --memory --FIXME should be 2
    NUM_TPAGES      : natural := 1;                 --! subpages
    RAM_DEPTH       : natural := NUM_PAGES*PAGE_LENGTH; --! memory depth 
    DEBUG           : boolean := false;             --! If true prints debug info
    NAME            : string  := ""                     --! Name for debug 
    );
  port (
    clk       : in  std_logic;                                      --! Clock
    start     : in  std_logic;                                      --! stare
    enb       : out  std_logic;                                      --! Read Enable
    bx        : in  std_logic_vector(clogb2(NUM_PAGES)-1 downto 0); --! BX
    addra     : out  std_logic_vector(clogb2(RAM_DEPTH)-1 downto 0); --! read address
    din       : in  std_logic_vector(RAM_WIDTH-1 downto 0);         --! RAM input data
    dout      : out  std_logic_vector(RAM_WIDTH-1 downto 0);        --! output data
    valid     : out  std_logic;                                     --! data valid
    index     : out  std_logic_vector(6 downto 0);                         --!index
    nent      : in t_arr_7b(0 to NUM_PAGES*NUM_TPAGES-1)
    );
end mem_reader;

architecture rtl of mem_reader is

-- ########################### Types ###########################

signal current_BX  : std_logic_vector(clogb2(NUM_PAGES)-1 downto 0) := (others =>'0');          --! RAM data row
signal addr_counter  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          --! RAM data row
signal addr_counter1  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          --! RAM data row
signal addr_counter2  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          --! RAM data row
signal valid1 : std_logic := '0';
signal valid2 : std_logic := '0';
signal valid3 : std_logic := '0';
signal addrP1  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          
signal addrP2  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          
signal addrP3  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          
signal addrP4  : std_logic_vector(clogb2(PAGE_LENGTH)-1 downto 0) := (others =>'0');          

-- ########################### Attributes ###########################

begin

-- Check user didn't change values of derived generics.
assert (RAM_DEPTH  = NUM_PAGES*PAGE_LENGTH) report "User changed RAM_DEPTH" severity FAILURE;

process(clk)
  variable vi_page_cnt_slv  : std_logic_vector(clogb2(NUM_PAGES)-1 downto 0) := (others => '0');
begin
  if rising_edge(clk) then -- ######################################### Start counter initially


    if (start='1') then
      --report "mem_reader:"&NAME&" start  bx="&to_bstring(bx)&" nent="
      --  &to_bstring(nent(to_integer(unsigned(bx))*NUM_TPAGES))&" "
      --  &to_bstring(nent(to_integer(unsigned(bx))*NUM_TPAGES+1))&" "
      --  &to_bstring(nent(to_integer(unsigned(bx))*NUM_TPAGES+2))&" "
      --  &to_bstring(nent(to_integer(unsigned(bx))*NUM_TPAGES+3))
      --  ;

      if (bx /= vi_page_cnt_slv) then
        vi_page_cnt_slv := bx;
        addrP1 <= (others => '0');
        addrP2 <= (others => '0');
        addrP3 <= (others => '0');
        addrP4 <= (others => '0');
        addr_counter <= (others => '0');
      end if;

      addr_counter2 <= addr_counter1;

      addr_counter1 <= addr_counter;
      
      valid <= valid3;

      valid3 <= valid2;
      
      valid2 <= valid1;
      
      if (addrP1 < nent(to_integer(unsigned(bx))*NUM_TPAGES)) then
        addr_counter <= std_logic_vector(to_unsigned(0,2))&addrP1(4 downto 0);
        addra <= bx&std_logic_vector(to_unsigned(0,2))&addrP1(4 downto 0);
        addrP1 <= std_logic_vector(to_unsigned(to_integer(unsigned(addrP1)) + 1, addrP1'length));
        valid1 <= '1'; 
      elsif ((addrP2 < nent(to_integer(unsigned(bx))*NUM_TPAGES+1)) and (NUM_TPAGES > 1)) then
        addr_counter <= std_logic_vector(to_unsigned(1,2))&addrP2(4 downto 0);
        addra <= bx&std_logic_vector(to_unsigned(1,2))&addrP2(4 downto 0);
        addrP2 <= std_logic_vector(to_unsigned(to_integer(unsigned(addrP2)) + 1, addrP2'length));
        valid1 <= '1'; 
      elsif ((addrP3 < nent(to_integer(unsigned(bx))*NUM_TPAGES+2)) and (NUM_TPAGES > 2)) then
        addr_counter <= std_logic_vector(to_unsigned(2,2))&addrP3(4 downto 0);
        addra <= bx&std_logic_vector(to_unsigned(2,2))&addrP3(4 downto 0);
        addrP3 <= std_logic_vector(to_unsigned(to_integer(unsigned(addrP3)) + 1, addrP3'length));
        valid1 <= '1';       
      elsif ((addrP4 < nent(to_integer(unsigned(bx))*NUM_TPAGES+3)) and (NUM_TPAGES > 3)) then
        addr_counter <= std_logic_vector(to_unsigned(3,2))&addrP4(4 downto 0);
        addra <= bx&std_logic_vector(to_unsigned(3,2))&addrP4(4 downto 0);
        addrP4 <= std_logic_vector(to_unsigned(to_integer(unsigned(addrP4)) + 1, addrP4'length));
        valid1 <= '1'; 
      else
        valid1 <= '0';
      end if;
        
      enb <= '1';       

      index <= addr_counter2;
    
      dout <= din;

      --if (valid3='1') then
      --  report "mem_reader:"&NAME&" addr="&to_bstring(addr_counter2)&"  din="&to_bstring(din)&" valid="&to_bstring(valid3);
      --end if;
        
    end if;    


      
  end if;
end process;

end rtl;
