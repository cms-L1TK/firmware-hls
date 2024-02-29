-------------------------------------------------------------------------------
-- Title      : link to sector processor
-- Project    : 
-------------------------------------------------------------------------------
-- File       : linktosecproc.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-06-27
-- Last update: 2023-04-06
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2022 University of Colorado Boulder
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-06-27  1.0      fmarini Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.emp_data_types.all;
use work.emp_device_decl.all;
use work.emp_ttc_decl.all;
-- emp thomas
-- use work.hybrid_tools.all;
-- use work.hybrid_config.all;
-- use work.hybrid_data_types.all;
-- use work.tracklet_config.all;
-- use work.tracklet_data_types.all;
-- emp US
use work.tf_pkg.all;
use work.memUtil_pkg.all;

entity linktosecproc is
  port (
    clk_i                : in  std_logic;
    rst_i                : in  std_logic;
    ttc_i                : in  ttc_stuff_array(N_REGION - 1 downto 0);
    din_i                : in  ldata(4 * N_REGION - 1 downto 0);
    ir_start_o           : out std_logic;
    bx_o                 : out std_logic_vector(2 downto 0);
    DL_39_link_AV_dout   : out t_arr_DL_39_DATA;
    DL_39_link_empty_neg : out t_arr_DL_39_1b;
    DL_39_link_read      : in  t_arr_DL_39_1b
    );
end entity linktosecproc;

architecture rtl of linktosecproc is

  -- signal s_tracklet_reset : t_resets(numPPquads - 1 downto 0);
  -- signal s_tracklet_isol  : t_stubsDTC;
  -- signal s_tracklet_data  : t_datas(numInputsIR - 1 downto 0);
  signal s_ir_start      : std_logic;
  signal s_ir_start_srff : std_logic;
  signal s_din_d         : ldata(4 * N_REGION - 1 downto 0);

begin  -- architecture rtl

  -- tracklet_isolation_in_1 : entity work.tracklet_isolation_in
  --   port map (
  --     clk      => clk_i,
  --     in_ttc   => ttc_i,
  --     in_din   => din_i,
  --     in_reset => s_tracklet_reset,
  --     in_dout  => s_tracklet_isol
  --     );

  -- tracklet_format_in_1 : entity work.tracklet_format_in
  --   port map (
  --     clk      => clk_i,
  --     in_reset => s_tracklet_reset,
  --     in_din   => s_tracklet_isol,
  --     in_dout  => s_tracklet_data
  --     );

  GEN_DELAYED_DATA: for i in 0 to 14 generate
    p_delay_data: process (clk_i) is
    begin  -- process p_delay_data
      if rising_edge(clk_i) then     -- rising clock edge
        s_din_d(i).data <= din_i(i).data;
      end if;
    end process p_delay_data;
  end generate GEN_DELAYED_DATA;

  -----------------------------------------------------------------------------
  -- Connect input link data to IR in Sector Processor
  -----------------------------------------------------------------------------
  DL_39_link_AV_DOUT(PS10G_1_A) <= s_din_d(0).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_2_A) <= s_din_d(1).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_3_A) <= s_din_d(2).data(38 downto 0);
  DL_39_link_AV_DOUT(PS_1_A)    <= s_din_d(3).data(38 downto 0);
  DL_39_link_AV_DOUT(PS_2_A)    <= s_din_d(4).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_1_A)  <= s_din_d(5).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_2_A)  <= s_din_d(6).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_3_A)  <= s_din_d(7).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_4_A)  <= s_din_d(8).data(38 downto 0);

  -----------------------------------------------------------------------------
  -- Generate start signal
  -----------------------------------------------------------------------------
  set_reset_ffd_1 : entity work.set_reset_ffd
    port map (
      clk_i   => clk_i,
      set_i   => din_i(0).valid,
      reset_i => rst_i,
      q_o     => s_ir_start_srff
      );


  s_ir_start <= din_i(0).valid or s_ir_start_srff;
  ir_start_o <= s_ir_start;

  p_bx_count : process (clk_i) is
    variable v_bx         : natural;
    variable v_word_count : natural := 1;
  begin  -- process p_bx_count
    if rising_edge(clk_i) then          -- rising clock edge
      if s_ir_start = '1' then
        if v_word_count < MAX_ENTRIES then
          v_word_count := v_word_count + 1;
        else
          v_word_count := 1;
          v_bx         := v_bx + 1;
        end if;
      end if;
      bx_o <= std_logic_vector(to_unsigned(v_bx, bx_o'length));
    end if;
  end process p_bx_count;

end architecture rtl;
