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

use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;

entity sp2_mem_writer is
  generic (
    MAX_ENTRIES : natural := MAX_ENTRIES
  );
  port (
    clk                       : in std_logic;
    rst                       : in std_logic;
    AS_36_link_data           : in t_arr_AS_36_37b;
    MPAR_73_link_data         : in t_arr_MTPAR_73_76b;
    bx_link_data              : in std_logic_vector(2 downto 0);
    AS_36_link_valid          : in t_arr_AS_36_1b;
    MPAR_73_link_valid        : in t_arr_MTPAR_73_1b;
    bx_link_valid             : in std_logic;
    AS_36_wea                 : out t_arr_AS_36_1b;
    AS_36_writeaddr           : out t_arr_AS_36_ADDR;
    AS_36_din                 : out t_arr_AS_36_DATA;
    MPAR_73_wea               : out t_arr_MTPAR_73_1b;
    MPAR_73_writeaddr         : out t_arr_MTPAR_73_ADDR;
    MPAR_73_din               : out t_arr_MTPAR_73_DATA;
    PC_start                  : out std_logic;
    PC_bx_in                  : out std_logic_vector(2 downto 0);
    HLS_reset                 : out std_logic
    );
end entity sp2_mem_writer;

architecture rtl of sp2_mem_writer is

  type t_arr_t_arr_AS_36_1b is array(1 downto 0) of t_arr_AS_36_1b;
  type t_arr_t_arr_AS_36_DATA is array(1 downto 0) of t_arr_AS_36_DATA;
  type t_arr_t_arr_MTPAR_73_1b is array(1 downto 0) of t_arr_MTPAR_73_1b;
  type t_arr_t_arr_MTPAR_73_DATA is array(1 downto 0) of t_arr_MTPAR_73_DATA;
  type t_arr_t_arr_MTPAR_73_ADDR is array(1 downto 0) of t_arr_MTPAR_73_ADDR;
  type enum_RESET_STATE is (S_IDLE, S_ACTIVE, S_RESET);

  signal AS_36_link_valid_prev   : t_arr_AS_36_1b    := (others => '0');
  signal MPAR_73_link_valid_prev : t_arr_MTPAR_73_1b := (others => '0');
  signal bx_link_valid_prev      : std_logic         := '0';

  signal sectorprocessor_ctrl    : enum_RESET_STATE  := S_IDLE;
  signal sync_counter            : unsigned(7 downto 0) := (others => '0');

  signal bx_prev         : std_logic_vector(2 downto 0) := "000";
  signal AS_36_wea_pipe   : t_arr_t_arr_AS_36_1b               := (others => (others => '0'));
  signal AS_36_din_pipe   : t_arr_t_arr_AS_36_DATA             := (others => (others => (others => '0')));
  signal MPAR_73_wea_pipe : t_arr_t_arr_MTPAR_73_1b            := (others => (others => '0'));
  signal MPAR_73_din_pipe : t_arr_t_arr_MTPAR_73_DATA          := (others => (others => (others => '0')));
  signal MPAR_73_writeaddr_pipe : t_arr_t_arr_MTPAR_73_ADDR          := (others => (others => (others => '0')));
  signal PC_start_int    : std_logic                    := '0';
  signal HLS_reset_int    : std_logic                    := '0';

  attribute shreg_extract : string;
  attribute shreg_extract of AS_36_wea_pipe : signal is "no";
  attribute shreg_extract of AS_36_din_pipe : signal is "no";
  attribute shreg_extract of MPAR_73_wea_pipe : signal is "no";
  attribute shreg_extract of MPAR_73_din_pipe : signal is "no";
  attribute shreg_extract of MPAR_73_writeaddr_pipe : signal is "no";

  attribute max_fanout : integer;
  attribute max_fanout of HLS_reset_int : signal is 100;

begin -- architecture rtl
  
  p_writemem : process (clk) is

  begin -- process p_writemem
    if rising_edge(clk) then -- rising clock edge

      --Convert streamed AllStubs data into memory inputs for SectorProcessor
      --write enable and data in are set directly from link data address is 
      --updated on next clock after each write and set to 0 at beginning of evt
      for i in AS_36_link_data'range loop 
        AS_36_link_valid_prev(i) <= AS_36_link_valid(i);
        if (AS_36_link_valid(i) = '1' and AS_36_link_data(i)(36) = '1') then
          AS_36_wea_pipe(0)(i) <= '1';
          AS_36_din_pipe(0)(i) <= AS_36_link_data(i)(35 downto 0);
        else
          AS_36_wea_pipe(0)(i) <= '0';
        end if;
      end loop; --AS_36 loop

      --Convert streamed MergedParameters data into memory inputs for 
      --SectorProcessor write enable, data, and top two address non-bx bits in 
      --are set directly from link data addresses for each of the four "pages" 
      --are managed by separate counters, which are updated after each write 
      --and reset at the beginning of events
      for i in MPAR_73_link_data'range loop 
        MPAR_73_link_valid_prev(i) <= MPAR_73_link_valid(i);
        if (MPAR_73_link_valid(i) = '1' and MPAR_73_link_data(i)(75) = '1') then
          MPAR_73_wea_pipe(0)(i) <= '1';
          MPAR_73_din_pipe(0)(i) <= MPAR_73_link_data(i)(72 downto 0);
          MPAR_73_writeaddr_pipe(0)(i) <= "0000000000" & MPAR_73_link_data(i)(74 downto 73);
        else
          MPAR_73_wea_pipe(0)(i) <= '0';
        end if;

      end loop; --MPAR_73 loop

      AS_36_wea_pipe(AS_36_wea_pipe'high downto 1) <= AS_36_wea_pipe(AS_36_wea_pipe'high-1 downto 0);
      AS_36_din_pipe(AS_36_din_pipe'high downto 1) <= AS_36_din_pipe(AS_36_din_pipe'high-1 downto 0);
      MPAR_73_wea_pipe(MPAR_73_wea_pipe'high downto 1) <= MPAR_73_wea_pipe(MPAR_73_wea_pipe'high-1 downto 0);
      MPAR_73_din_pipe(MPAR_73_din_pipe'high downto 1) <= MPAR_73_din_pipe(MPAR_73_din_pipe'high-1 downto 0);
      MPAR_73_writeaddr_pipe(MPAR_73_writeaddr_pipe'high downto 1) <= MPAR_73_writeaddr_pipe(MPAR_73_writeaddr_pipe'high-1 downto 0);

      AS_36_wea         <= AS_36_wea_pipe(AS_36_wea_pipe'high);
      AS_36_din         <= AS_36_din_pipe(AS_36_din_pipe'high);
      MPAR_73_wea       <= MPAR_73_wea_pipe(MPAR_73_wea_pipe'high);
      MPAR_73_din       <= MPAR_73_din_pipe(MPAR_73_din_pipe'high);
      MPAR_73_writeaddr       <= MPAR_73_writeaddr_pipe(MPAR_73_writeaddr_pipe'high);

      --latch BX when input not valid
      --generate PC_start at beginning of first packet (?)
      bx_link_valid_prev <= bx_link_valid;
      if (bx_link_valid='1') then
        bx_prev <= bx_link_data;
      end if;

      --FSM to control start/reset signals to SectorProcessor
      case sectorprocessor_ctrl is
        when S_IDLE =>
          --generate start when BX rolls from 0 to 1
          if (bx_link_valid='1' and bx_link_data="001" and bx_prev="000") then
            sync_counter <= (others => '0');
            PC_start_int <= '1';
            sectorprocessor_ctrl <= S_ACTIVE;
          end if;

        when S_ACTIVE =>
          --generate reset if BX change is not sync'd w/ counter
          if (to_integer(sync_counter) = MAX_ENTRIES-1) then 
            sync_counter <= (others => '0');
          else
            sync_counter <= sync_counter+1;
          end if;
          if ((bx_link_valid='1' and bx_link_data /= bx_prev
              and to_integer(sync_counter) /= MAX_ENTRIES-1) or rst = '1') then 
            sync_counter <= (others => '0');
            PC_start_int <= '0';
            HLS_reset <= '1';
            sectorprocessor_ctrl <= S_RESET;
          end if;

        when S_RESET =>
          --return to idle after reset has been asserted for 2 BXs
          if (to_integer(sync_counter) = 2*MAX_ENTRIES-1) then 
            sync_counter <= (others => '0');
            HLS_reset <= '0';
            sectorprocessor_ctrl <= S_IDLE;
          else
            sync_counter <= sync_counter+1;
          end if;

      end case;

      PC_bx_in          <= std_logic_vector(unsigned(bx_prev)-1);
      PC_start          <= PC_start_int;

    end if; --rising clock edge
  end process p_writemem;

  AS_36_writeaddr <= (others => (others => '0'));
  HLS_reset <= HLS_reset_int;

end architecture rtl;
