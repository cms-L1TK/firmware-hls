-------------------------------------------------------------------------------
-- Title      : conv96to64
-- Project    : 
-------------------------------------------------------------------------------
-- File       : conv96to64.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-11-21
-- Last update: 2022-11-23
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2022 University of Colorado Boulder
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-11-21  1.0      fmarini Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work;
use work.hybrid_data_types.all;
use work.kfout_data_formats.all;
use work.kfout_config.all;
use work.DataType.all;
use work.ArrayTypes.all;
use work.emp_data_types.all;

library surf;
use surf.StdRtlPkg.all;
use surf.ArbiterPkg.all;
use surf.AxiStreamPkg.all;

entity conv96to64 is
  port (
    clk_i           : in  std_logic;
    rst_i           : in  std_logic;
    sorted_tracks_i : in  vector;
    packet_data_o   : out t_frames
    );
end entity conv96to64;

architecture rtl of conv96to64 is

begin  -- architecture rtl

  GEN_FOR_TRACKS : for i in 0 to numOutLinks - 1 generate

    signal s_track_in      : std_logic_vector(widthTTTrack - 1 downto 0);
    signal s_track_out     : std_logic_vector(widthTTTrack - 1 downto 0);
    signal s_track_reset   : std_logic;
    signal s_track_wr_en   : std_logic;
    signal s_rd_en         : std_logic;
    signal s_wc            : unsigned(1 downto 0) := "00";
    signal s_track_tmp_32  : std_logic_vector(31 downto 0);
    signal s_track_tmp_64  : std_logic_vector(63 downto 0);
    signal s_track         : std_logic_vector(LWORD_WIDTH - 1 downto 0);
    signal s_write_addr    : integer range 0 to 127;
    signal s_read_addr_tmp : integer range 0 to 127;
    signal s_read_addr     : integer range 0 to 127;

    type mem_extendable is array(0 to 127) of std_logic_vector(widthTTTrack - 1 downto 0);
    signal ram                 : mem_extendable := (others => (others => '0'));
    attribute ram_style        : string;
    attribute ram_style of ram : signal is "block";

  begin

    -----------------------------------------------------------------------------
    -- Save words in FIFO
    -----------------------------------------------------------------------------
    s_track_in    <= ToStdLogicVector(sorted_tracks_i(i))(widthTTTrack - 1 downto 0);
    s_track_reset <= sorted_tracks_i(i).Reset;
    s_track_wr_en <= '1' when sorted_tracks_i(i).DataValid else
                     '0';

    -- FifoSync_1 : entity surf.FifoSync
    --   generic map (
    --     MEMORY_TYPE_G => "block",
    --     FWFT_EN_G     => true,
    --     PIPE_STAGES_G => 0,
    --     DATA_WIDTH_G  => 96,
    --     ADDR_WIDTH_G  => 6
    --     )
    --   port map (
    --     rst          => s_track_reset,
    --     clk          => clk_i,
    --     wr_en        => s_track_wr_en,
    --     rd_en        => s_rd_en,
    --     din          => s_track_in,
    --     dout         => s_track_out,
    --     data_count   => open,
    --     wr_ack       => open,
    --     valid        => open,
    --     overflow     => open,
    --     underflow    => open,
    --     prog_full    => open,
    --     prog_empty   => open,
    --     almost_full  => open,
    --     almost_empty => open,
    --     full         => open,
    --     not_full     => open,
    --     empty        => open
    --     );

    p_ram_write : process (clk_i) is
    begin  -- process p_ram
      if rising_edge(clk_i) then        -- rising clock edge
        if s_track_reset = '1' then
          ram <= (others => (others => '0'));
        else
          if s_track_wr_en = '1' then
            ram(s_write_addr) <= s_track_in;
          end if;
        end if;
      end if;
    end process p_ram_write;

    p_ram_read : process (clk_i) is
    begin  -- process p_ram_read
      if rising_edge(clk_i) then        -- rising clock edge
        s_track_out <= ram(s_read_addr);
      end if;
    end process p_ram_read;

    ---------------------------------------------------------------------------
    -- Counter
    ---------------------------------------------------------------------------
    p_96to64_counter : process (clk_i, s_track_reset) is
    begin  -- process p_96to64_counter
      if s_track_reset = '1' then       -- asynchronous reset (active high)
        s_wc <= "01";
      elsif rising_edge(clk_i) then     -- rising clock edge
        if s_wc >= 2 then
          s_wc <= (others => '0');
        else
          s_wc <= s_wc + 1;
        end if;
      end if;
    end process p_96to64_counter;

    p_write_addr : process (clk_i, s_track_reset) is
    begin  -- process p_write_addr
      if s_track_reset = '1' then       -- asynchronous reset (active high)
        s_write_addr <= 0;
      elsif rising_edge(clk_i) then     -- rising clock edge
        if s_write_addr < 63 - 1 then
          s_write_addr <= s_write_addr + 1;
        end if;
      end if;
    end process p_write_addr;

    p_read_addr : process (clk_i, s_track_reset) is
    begin  -- process p_read_addr
      if s_track_reset = '1' then
        s_read_addr_tmp <= 0;
      elsif rising_edge(clk_i) then     -- rising clock edge
        if s_wc < 2 and s_read_addr < 63 - 1 then
          s_read_addr_tmp <= s_read_addr_tmp + 1;
        end if;
      end if;
    end process p_read_addr;

    p_read_addr_delay : process (clk_i) is
    begin  -- process p_read_addr_delay
      if rising_edge(clk_i) then        -- rising clock edge
        s_read_addr <= s_read_addr_tmp;
      end if;
    end process p_read_addr_delay;

    p_96to64_conv : process (clk_i) is
    begin  -- process p_96to64_conv
      if rising_edge(clk_i) then        -- rising clock edge
        case s_wc is
          when "00" =>
            s_track        <= s_track_out(95 downto 32);
            s_track_tmp_32 <= s_track_out(31 downto 0);
          when "01" =>
            s_track        <= s_track_tmp_32 & s_track_out(95 downto 64);
            s_track_tmp_64 <= s_track_out(63 downto 0);
          when "10" =>
            s_track <= s_track_tmp_64;
          when others => null;
        end case;
      end if;
    end process p_96to64_conv;

    packet_data_o(i) <= s_track;

  end generate GEN_FOR_TRACKS;


end architecture rtl;
