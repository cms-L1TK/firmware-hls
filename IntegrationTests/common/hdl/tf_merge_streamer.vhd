--===========================================================================
--! @file
--! @brief Module which reads and streams out the contents of the memories
--! at the end of the first half of the TF algo.
--! @author Jason Fan (jf847@cornell.edu)
--! @date 2024-02-29
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
use work.tf_pkg.all;

entity tf_merge_streamer is
	generic (
		RAM_WIDTH	:	natural := 72;
		NUM_PAGES   :   natural := 8;
		RAM_DEPTH 	: natural := NUM_PAGES * PAGE_LENGTH;
		NUM_INPUTS 		: natural := 4;
		NUM_EXTRA_BITS: natural := 2;
		ADDR_WIDTH : natural := 7
	);
	port (
	bx_in : in std_logic_vector(2 downto 0 );
	rst: in std_logic;
	clk : in std_logic;
  --output read enable to tf_mem modules
	enb_arr: out std_logic_vector(NUM_INPUTS-1 downto 0);
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
  constant pipe_stages : integer := 4;

	type mem_count_arr is array(NUM_INPUTS-1 downto 0) of integer;
	type toread_arr is array(pipe_stages-1 downto 0) of integer;

  --nent and din are repackaged from odd input type into
  --arrays
	type nent_array is array(MAX_INPUTS-1 downto 0) of t_arr_7b(0 to NUM_PAGES-1);
	type din_array is array(MAX_INPUTS-1 downto 0) of std_logic_vector(RAM_WIDTH-1 downto 0);

	signal valid : std_logic_vector(pipe_stages-1 downto 0) := (others => '0');
	signal readmask : std_logic_vector(NUM_INPUTS-1 downto 0) := (others => '0');

begin
	process(clk)
	variable nent_arr: nent_array;
	variable din_arr: din_array;
	variable bx_last :integer :=0;
	variable mem_count : mem_count_arr := (others => 0);
	variable current_page: natural := 0;
	variable bx_change : boolean := false; -- indicates to the module whether or not the bx has changed compared to the previous clock

	variable toread : toread_arr := (others => 0);

	begin
    if rising_edge(clk) then
   		  nent_arr := (nent3,nent2,nent1,nent0); --repackage nent and din as arrays
			din_arr := (din3, din2, din1, din0);
			bx_change := (bx_last /= to_integer(unsigned(bx_in)));
			if (bx_change) then --reset with rst signal or a change in bx
			-- check if bx changes and update page to read from
				mem_count := (others => 0);
			end if ;
			current_page := to_integer(unsigned(bx_in)) mod NUM_PAGES;
     --check if memory read counter is less than nentries
			for i in 0 to NUM_INPUTS-1 loop
			  if ((mem_count(i)) < to_integer(unsigned(nent_arr(i)(current_page)))) then
			    readmask(i) <= '1';
			    else
			      readmask(i) <= '0';
			    end if;
		  end loop;
			if (to_integer(unsigned(readmask)) = 0) then
			    valid(0) <= '0';
			else
			    for j in 0 to NUM_INPUTS-1 loop
			        if readmask((j + toread(0) + 1) mod NUM_INPUTS) = '1' then
			            toread(0) := (j + toread(0) + 1 ) mod NUM_INPUTS;
			            exit;
			        end if;
			    end loop;
			    addr_arr(((toread(0)+1)*clogb2(RAM_DEPTH))-1 downto (toread(0))*clogb2(RAM_DEPTH)) <= std_logic_vector(to_unsigned(current_page*page_length + mem_count(toread(0)), clogb2(RAM_DEPTH)));
                valid(0) <= '1';
                mem_count(toread(0)) := mem_count(toread(0)) + 1;
			end if;

			if valid(pipe_stages-1) ='1' then
			     if (NUM_EXTRA_BITS > 0) then
			         merged_dout <= '1' & std_logic_vector(to_unsigned(toread(pipe_stages-1),NUM_EXTRA_BITS)) & din_arr(toread(pipe_stages-1));
			     else
			         merged_dout <= '1' & din_arr(toread(pipe_stages-2));
			     end if ;
			else
			     merged_dout <= (others => '0');
			end if;
			bx_last := to_integer(unsigned(bx_in));
			bx_out <= bx_in;
      for j in 0 to pipe_stages-2 loop
	  		toread(j+1) := toread(j);
  			valid(j+1) <= valid(j);
      end loop;
		end if;
	end process;
end RTL;
