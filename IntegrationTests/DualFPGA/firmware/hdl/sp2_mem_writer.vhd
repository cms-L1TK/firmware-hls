--===========================================================================
--! @file sp2_mem_writer.vhd
--! @brief Simple module to coordinate writing to FPGA2 SP input memories
--! @author Michael Oshiro <mco62@cornell.edu>
--! @date 2024-04-16
--! @version v.1.0
--===========================================================================
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;

entity sp2_mem_writer is
  port (
    clk                       : in std_logic;
    reset                     : in std_logic;
    bx_link_data              : in std_logic_vector(2 downto 0);
    AS_36_link_data           : in t_arr_AS_36_37b;
    MPAR_73_link_data         : in t_arr_MTPAR_73_76b;
    link_data_valid           : in std_logic;
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

  type t_arr_AS_36_7b is array(enum_AS_36_f1) of std_logic_vector(6 downto 0);
  type t_arr4_7b is array(0 to 3) of std_logic_vector(6 downto 0);
  type t_arr_MTPAR_73_arr4_7b is array(enum_MTPAR_73) of t_arr4_7b;
  type t_arr_MTPAR_73_2b is array(enum_MTPAR_73) of std_logic_vector(1 downto 0);

  signal AS_36_adr       : t_arr_AS_36_7b               := (others => "0000000");
  signal MPAR_73_adr     : t_arr_MTPAR_73_arr4_7b       := (others => (others => "0000000"));
  signal MPAR_73_pge     : t_arr_MTPAR_73_2b            := (others => "00");
  signal bx_prev         : std_logic_vector(2 downto 0) := "000";
  signal bx_change       : std_logic_vector(2 downto 0) := "000";
  signal AS_36_wea_int   : t_arr_AS_36_1b               := (others => '0');
  signal MPAR_73_wea_int : t_arr_MTPAR_73_1b            := (others => '0');
  signal AS_36_din_int   : t_arr_AS_36_DATA             := (others => (others => '0'));
  signal MPAR_73_din_int : t_arr_MTPAR_73_DATA          := (others => (others => '0'));
  signal PC_start_int    : std_logic                    := '0';

  signal AS_36_wea_pipeline         : t_arr_AS_36_1b               := (others => '0');
  signal AS_36_writeaddr_pipeline   : t_arr_AS_36_ADDR             := (others => (others => '0'));
  signal AS_36_din_pipeline         : t_arr_AS_36_DATA             := (others => (others => '0'));
  signal MPAR_73_wea_pipeline       : t_arr_MTPAR_73_1b            := (others => '0');
  signal MPAR_73_writeaddr_pipeline : t_arr_MTPAR_73_ADDR          := (others => (others => '0'));
  signal MPAR_73_din_pipeline       : t_arr_MTPAR_73_DATA          := (others => (others => '0'));
  signal PC_bx_in_pipeline          : std_logic_vector(2 downto 0) := "000";
  signal PC_start_pipeline          : std_logic                    := '0';

begin -- architecture rtl
  
  p_writemem : process (clk) is

  begin -- process p_writemem
    if rising_edge(clk) then -- rising clock edge

      --Convert streamed AllStubs data into memory inputs for SectorProcessor
      --write enable and data in are set directly from link data
      --address is updated on next clock after each write and set to 0 after BX change
      for i in AS_36_link_data'range loop 
        if (link_data_valid = '1' and AS_36_link_data(i)(36) = '1') then
          AS_36_wea_int(i) <= '1';
          AS_36_din_int(i) <= AS_36_link_data(i)(35 downto 0);
        else
          AS_36_wea_int(i) <= '0';
        end if;

        if (bx_change /= "000") then
          AS_36_adr(i) <= "0000000";
        elsif (AS_36_wea_int(i) = '1') then
          AS_36_adr(i) <= std_logic_vector(unsigned(AS_36_adr(i))+1);
        end if;
      end loop; --AS_36 loop

      --Convert streamed MergedParameters data into memory inputs for SectorProcessor
      --write enable, data, and top two address non-bx bits in are set directly from link data
      --addresses for each of the four "pages" are managed by separate counters, which are
      --updated after each write and reset on BX change
      for i in MPAR_73_link_data'range loop 
        if (link_data_valid = '1' and MPAR_73_link_data(i)(75) = '1') then
          MPAR_73_wea_int(i) <= '1';
          MPAR_73_din_int(i) <= MPAR_73_link_data(i)(72 downto 0);
          MPAR_73_pge(i) <= MPAR_73_link_data(i)(74 downto 73);
          --TODO check order of valid and page bits in first FPGA project
        else
          MPAR_73_wea_int(i) <= '0';
        end if;

        if (bx_change /= "000") then
          MPAR_73_adr(i)(0) <= "0000000";
          MPAR_73_adr(i)(1) <= "0000000";
          MPAR_73_adr(i)(2) <= "0000000";
          MPAR_73_adr(i)(3) <= "0000000";
        elsif (MPAR_73_wea_int(i) = '1') then
          MPAR_73_adr(i)(to_integer(unsigned(MPAR_73_pge(i)))) 
              <= std_logic_vector(unsigned(MPAR_73_adr(i)(to_integer(unsigned(MPAR_73_pge(i)))))+1);
        end if;
      end loop; --MPAR_73 loop

      if (bx_change /= "000") then
        PC_start_int <= '1';
      --else
      --  PC_start <= '0';
      end if;

      bx_prev <= bx_link_data;

    end if; --rising clock edge
  end process p_writemem;

  --build full memory addresses based on word, page, and BX
  g_as_address : for i in AS_36_writeaddr'range generate
    AS_36_writeaddr_pipeline(i) <= bx_prev & AS_36_adr(i);
  end generate g_as_address;

  g_mpar_address : for i in MPAR_73_writeaddr'range generate
    MPAR_73_writeaddr_pipeline(i) <= bx_prev & MPAR_73_pge(i) & MPAR_73_adr(i)(to_integer(unsigned(MPAR_73_pge(i))));
  end generate g_mpar_address;
  
  bx_change <= bx_prev xor bx_link_data;
  AS_36_wea_pipeline <= AS_36_wea_int;
  MPAR_73_wea_pipeline <= MPAR_73_wea_int;
  AS_36_din_pipeline <= AS_36_din_int;
  MPAR_73_din_pipeline <= MPAR_73_din_int;
  PC_bx_in_pipeline <= std_logic_vector(unsigned(bx_prev)-1);
  PC_start_pipeline <= PC_start_int;
  --PC_bx_in <= bx_prev;

  p_pipeline : process (clk) is
  begin -- process p_pipeline
    if rising_edge(clk) then -- rising clock edge
      AS_36_wea         <= AS_36_wea_pipeline;
      AS_36_writeaddr   <= AS_36_writeaddr_pipeline;
      AS_36_din         <= AS_36_din_pipeline;
      MPAR_73_wea       <= MPAR_73_wea_pipeline;
      MPAR_73_writeaddr <= MPAR_73_writeaddr_pipeline;
      MPAR_73_din       <= MPAR_73_din_pipeline;
      PC_bx_in          <= PC_bx_in_pipeline;
      PC_start          <= PC_start_pipeline;
    end if;
  end process;

end architecture rtl;
