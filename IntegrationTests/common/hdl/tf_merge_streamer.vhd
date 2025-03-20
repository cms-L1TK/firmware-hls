--===========================================================================
--! @file
--! @brief Module which reads and streams out the contents of the memories
--! at the end of the first half of the TF algo.
--! @author Jason Fan (jf847@cornell.edu)
--! @date 2024-02-29
--! @version v.1.1
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
use work.tf_pkg.all;

entity tf_merge_streamer is
  generic (
    RAM_WIDTH:  natural := 72;
    NUM_PAGES   :   natural := 8;
    RAM_DEPTH   : natural := NUM_PAGES * PAGE_LENGTH;
    NUM_INPUTS     : natural := 4;
    NUM_EXTRA_BITS: natural := 2;
    ADDR_WIDTH : natural := 7
  );
  port (
  bx_in : in std_logic_vector(2 downto 0 );
  bx_in_vld : in std_logic;
  rst: in std_logic;
  clk : in std_logic;
  bx_out : out std_logic_vector(2 downto 0);
  --output merged stream, includes input word, up to 2 bits that encode the
  --original module, and a valid bit (from LSB to MSB)
  merged_dout : out std_logic_vector(RAM_WIDTH+NUM_EXTRA_BITS downto 0);
  --input data,nent and addresses are best suited for unconstrained arrays
  --but this is not supported in vivado 2019
  --module always accepts 4 input memories, but will not use all of them
  din0: in std_logic_vector(RAM_WIDTH-1 downto 0);
  din1: in std_logic_vector(RAM_WIDTH-1 downto 0);
  din2: in std_logic_vector(RAM_WIDTH-1 downto 0);
  din3: in std_logic_vector(RAM_WIDTH-1 downto 0);
  nent0: in t_arr_7b(0 to NUM_PAGES-1);
  nent1: in t_arr_7b(0 to NUM_PAGES-1);
  nent2: in t_arr_7b(0 to NUM_PAGES-1);
  nent3: in t_arr_7b(0 to NUM_PAGES-1);
  addr_arr: out std_logic_vector(NUM_INPUTS*CLOGB2(RAM_DEPTH)-1 downto 0)
) ;
end entity tf_merge_streamer;

architecture RTL of tf_merge_streamer is

  constant MAX_INPUTS : integer := 4;
  constant pipe_stages : integer := 3;
  constant LOG2_RAM_DEPTH : integer := CLOGB2(RAM_DEPTH);

  type mem_count_arr is array(MAX_INPUTS-1 downto 0) of integer;
  type toread_arr is array(pipe_stages-1 downto 0) of integer range 0 to 3;
  type bx_arr is array(pipe_stages downto 0) of std_logic_vector(2 downto 0);
  type addr_arr_arr is array(MAX_INPUTS-1 downto 0) of std_logic_vector(LOG2_RAM_DEPTH-1 downto 0);

  --nent and din are repackaged from odd input type into
  --arrays
  type nent_array is array(MAX_INPUTS-1 downto 0) of t_arr_7b(0 to NUM_PAGES-1);
  type din_array is array(MAX_INPUTS-1 downto 0) of std_logic_vector(RAM_WIDTH-1 downto 0);

  signal valid : std_logic_vector(pipe_stages-1 downto 0) := (others => '0');
  signal bx_pipe : bx_arr := (others => (others => '0'));
  signal addr_arr_int : addr_arr_arr := (others => (others => '0'));
  signal bx_last : std_logic_vector(2 downto 0) := "111";
  signal bx_in_latch : std_logic_vector(2 downto 0) := "111"; --since output triggered by BX change, initializing bx_in_latch to 7 will start write on first valid bx (0)
  signal mem_count : mem_count_arr := (others => 0);
  signal toread : toread_arr := (others => 0);
  signal current_page: natural := 7 mod NUM_PAGES;
  signal readmask : std_logic_vector(MAX_INPUTS-1 downto 0) := (others => '0');

begin
  process(clk)
  variable nent_arr: nent_array;
  variable din_arr: din_array;
  variable bx_change : boolean := false; -- indicates to the module whether or not the bx has changed compared to the previous clock
  variable nextread : integer range 0 to 3 := 0;
  variable mem_count_next : mem_count_arr := (others => 0);

  begin
    if rising_edge(clk) then
      if (bx_in_vld = '1') then
        bx_in_latch <= bx_in;
        current_page <= to_integer(unsigned(bx_in)) mod NUM_PAGES;
      end if;

      nent_arr := (nent3,nent2,nent1,nent0); --repackage nent and din as arrays
      din_arr := (din3, din2, din1, din0);
      bx_change := (bx_last /= bx_in_latch);

      if (bx_change) then --reset with rst signal or a change in bx
        mem_count <= (others => 0);
        toread(0) <= (NUM_INPUTS-1) mod NUM_INPUTS;
        valid(0) <= '0';

        --check if memory read counter is less than nentries
        --this sets readmask to 1 for any inputs that still have words to read
        for i in 0 to NUM_INPUTS-1 loop
          if (0 < to_integer(unsigned(nent_arr(i)(current_page)))) then
            readmask(i) <= '1';
          else
            readmask(i) <= '0';
          end if;
        end loop;
        
      else
        --only check for valid reads on non BX change clocks
        --this gives up a clock cycle, but reduces logic levels downstream

        for i in 0 to NUM_INPUTS-1 loop
          mem_count_next(i) := mem_count(i);
        end loop;

        if (to_integer(unsigned(readmask)) = 0) then
          valid(0) <= '0';
        else
          valid(0) <= '1';
          --loop through starting with the next input in front of the current to-read (round-robin)
          for i in 0 to 3 loop
            if (readmask((toread(0) - i) mod 4) = '1') then
              nextread := (toread(0) - i) mod 4;
            end if;
          end loop;
          addr_arr_int(nextread) <= std_logic_vector(to_unsigned(current_page*page_length + mem_count(nextread), LOG2_RAM_DEPTH));
          mem_count(nextread) <= mem_count(nextread) + 1;
          toread(0) <= nextread;
          mem_count_next(nextread) := mem_count_next(nextread)+1;
        end if;

        --check if memory read counter is less than nentries
        --this sets readmask to 1 for any inputs that still have words to read
        for i in 0 to NUM_INPUTS-1 loop
          if ((mem_count_next(i)) < to_integer(unsigned(nent_arr(i)(current_page)))) then
            readmask(i) <= '1';
          else
            readmask(i) <= '0';
          end if;
        end loop;

      end if ;

      --generate output a few clocks after address is set to account for delay in RAMs
      if valid(pipe_stages-1) ='1' then
        if (NUM_EXTRA_BITS > 0) then
          merged_dout <= '1' & std_logic_vector(to_unsigned(toread(pipe_stages-1),NUM_EXTRA_BITS)) & din_arr(toread(pipe_stages-1));
        else
          merged_dout <= '1' & din_arr(toread(pipe_stages-1));
        end if ;
      else
        merged_dout <= (others => '0');
      end if;

      bx_last <= bx_in_latch;
      bx_pipe(0) <= bx_in_latch;
      bx_out <= bx_pipe(pipe_stages);
      for j in pipe_stages-2 downto 0 loop
        valid(j+1) <= valid(j);
        toread(j+1) <= toread(j);
      end loop;
      for j in pipe_stages-1 downto 0 loop
        bx_pipe(j+1) <= bx_pipe(j);
      end loop;
    end if;
  end process;

  GEN_ADDR: for i in 0 to NUM_INPUTS-1 generate
  begin
    addr_arr(LOG2_RAM_DEPTH*(i+1)-1 downto LOG2_RAM_DEPTH*i) <= addr_arr_int(i);
  end generate;

end RTL;
