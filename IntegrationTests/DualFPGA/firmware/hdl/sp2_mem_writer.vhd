-------------------------------------------------------------------------------
-- Title      : sp2 mem writer
-- Project    : 
-------------------------------------------------------------------------------
-- File       : sp2_mem_writer.vhd
-- Author     : Michael Oshiro  <mco62@cornell.edu>
-- Company    : Cornell University
-- Created    : 2024-04-16
-- Last update: 2024-04-16
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: Simple module to coordinate writing to FPGA2 SP input memories
-------------------------------------------------------------------------------
-- Copyright (c) 2024 Cornell University
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-01-19  1.0      oshiro  Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f1.all;

entity sp2_mem_writer is
  port (
    clk                       : in std_logic;
    reset                     : in std_logic;
    bx_link_data              : in std_logic_vector(2 downto 0);
    AS_36_link_data           : in t_arr_AS_36_37b;
    MPAR_73_link_data         : in t_arr_MTPAR_73_76b;
    AS_36_wea                 : out t_arr_AS_36_1b;
    AS_36_writeaddr           : out t_arr_AS_36_ADDR;
    AS_36_din                 : out t_arr_AS_36_DATA;
    MPAR_73_wea               : out t_arr_MTPAR_73_1b;
    MPAR_73_writeaddr         : out t_arr_MTPAR_73_ADDR;
    MPAR_73_din               : out t_arr_MTPAR_73_DATA;
    PC_start                  : out std_logic;
    PC_bx_in                  : out std_logic_vector(2 downto 0)
    );
end entity sp2_mem_writer;

architecture rtl of sp2_mem_writer is

  type t_arr_AS_36_7b is array(enum_AS_36) of std_logic_vector(6 downto 0);
  type t_arr_MPAR_73_arr4_5b is array(enum_MTPAR_73) of array(0 to 3) of std_logic_vector(4 downto 0);
  type t_arr_MPAR_73_2b is array(enum_MTPAR_73) of std_logic_vector(1 downto 0);

  signal AS_36_adr   : t_arr_AS_36_7b        := (others => "0000000");
  signal MPAR_73_adr : t_arr_MTPAR_73_arr4_5b := (others => (others => "00000"));
  signal MPAR_73_pge : t_arr_MTPAR_73_2b      := (others => "00");
  signal bx_prev     : std_logic_vector(2 downto 0);

begin -- architecture rtl
  
  p_writemem : process (clk) is

  begin -- process p_writemem
    if rising_edge(clk_i) then -- rising clock edge

      --Convert streamed AllStubs data into memory inputs for SectorProcessor
      --write enable and data in are set directly from link data
      --address is updated on next clock after each write and set to 0 after BX change
      for i in AS_36_link_data'range loop 
	if (AS_36_link_data(enum_AS_36'pos(i))(36) = '1') then
	  AS_36_wea(enum_AS_36'pos(i)) <= '1';
	  AS_36_din(enum_AS_36'pos(i)) <= AS_36_link_data(enum_AS_36'pos(i))(35 downto 0);
	else
	  AS_36_wea(enum_AS_36'pos(i)) <= '0';
        end if;

	if ((bx_prev xor bx_link_data) /= "00") then
	  AS_36_adr(enum_AS_36'pos(i)) <= "0000000";
	elsif (AS_36_wea(enum_AS_36'pos(i))(36) = '1') then
	  AS_36_adr(enum_AS_36'pos(i)) <= std_logic_vector(unsigned(AS_36_adr(enum_AS_36'pos(i)))+1);
        end if;
      end loop; --AS_36 loop

      --Convert streamed MergedParameters data into memory inputs for SectorProcessor
      --write enable, data, and top two address non-bx bits in are set directly from link data
      --addresses for each of the four "pages" are managed by separate counters, which are
      --updated after each write and reset on BX change
      for i in MPAR_73_link_data'range loop 
	if (MPAR_73_link_data(enum_MPAR_73'pos(i))(75) = '1') then
	  MPAR_73_wea(enum_MPAR_73'pos(i)) <= '1';
	  MPAR_73_din(enum_MPAR_73'pos(i)) <= MPAR_73_link_data(enum_MPAR_73'pos(i))(72 downto 0);
	  MPAR_73_pge(enum_MPAR_73'pos(i)) <= MPAR_73_link_data(enum_MPAR_73'pos(i))(74 downto 73);
	  --TODO check order of valid and page bits in first FPGA project
	else
	  MPAR_73_wea(enum_MPAR_73'pos(i)) <= '0';
        end if;

	if ((bx_prev xor bx_link_data) /= "00") then
	  MPAR_73_adr(enum_MPAR_73'pos(i))(0) <= "00000";
	  MPAR_73_adr(enum_MPAR_73'pos(i))(1) <= "00000";
	  MPAR_73_adr(enum_MPAR_73'pos(i))(2) <= "00000";
	  MPAR_73_adr(enum_MPAR_73'pos(i))(3) <= "00000";
	elsif (MPAR_73_wea(enum_MPAR_73'pos(i))(36) = '1') then
	  MPAR_73_adr(enum_MPAR_73'pos(i))(to_integer(unsigned(MPAR_73_pge(enum_MPAR_73'pos(i))))) 
	      <= std_logic_vector(unsigned(MPAR_73_adr(enum_MPAR_73'pos(i))(to_integer(unsigned(MPAR_73_pge(enum_MPAR_73'pos(i))))))+1);
        end if;
      end loop; --MPAR_73 loop

      if ((bx_prev xor bx_link_data) /= "00") then
	PC_start <= '1';
      else
	PC_start <= '0';
      end if;
      bx_prev <= bx_link_data;

    end if;
  end process p_writemem;

  --build full memory addresses based on word, page, and BX
  g_as_address : for i in AS_36_writeaddr'range generate
    AS_36_writeaddr(enum_AS_36'pos(i)) <= bx_prev & AS_36_adr(enum_AS_36'pos(i));
  end generate g_as_address;

  g_mpar_address : for i in MPAR_73_writeaddr'range generate
    MPAR_73_writeaddr(enum_MPAR_73'pos(i)) <= bx_prev & MPAR_73_pge(enum_MPAR_73'pos(i)) 
					      & MPAR_73_adr(enum_MPAR_73'pos(i));
  end generate g_mpar_address;
  
  PC_bx_in <= std_logic_vector(unsigned(bx_prev)-1);

end architecture rtl;
