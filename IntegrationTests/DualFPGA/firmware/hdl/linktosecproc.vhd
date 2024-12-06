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
use work.memUtil_aux_pkg_f1.all;

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

  constant IR_LATENCY : natural := 4;

  type t_arr_ldata is array(IR_LATENCY-1 downto 0) of ldata(119 downto 68); 

  -- signal s_tracklet_reset : t_resets(numPPquads - 1 downto 0);
  -- signal s_tracklet_isol  : t_stubsDTC;
  -- signal s_tracklet_data  : t_datas(numInputsIR - 1 downto 0);
  signal s_ir_start      : std_logic;
  signal s_ir_start_srff : std_logic;
  signal s_din_d         : t_arr_ldata := (others => (others => LWORD_NULL));

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

  GEN_DELAYED_DATA: for i in 68 to 119 generate
    p_delay_data: process (clk_i) is
    begin  -- process p_delay_data
      if rising_edge(clk_i) then     -- rising clock edge
        s_din_d(0)(i).data <= din_i(i).data;
      end if;
    end process p_delay_data;
    GEN_DIN_PIPE : for j in 1 to IR_LATENCY-1 generate
      p_delay_data_pipe: process (clk_i) is
      begin  
        if rising_edge(clk_i) then     -- rising clock edge
          s_din_d(j)(i).data <= s_din_d(j-1)(i).data;
        end if;
      end process p_delay_data_pipe;
    end generate GEN_DIN_PIPE;
  end generate GEN_DELAYED_DATA;

  -----------------------------------------------------------------------------
  -- Connect input link data to IR in Sector Processor
  -----------------------------------------------------------------------------
  DL_39_link_AV_DOUT(PS10G_1_A)    <= s_din_d(IR_LATENCY-1)(68).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_1_B)    <= s_din_d(IR_LATENCY-1)(69).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_2_A)    <= s_din_d(IR_LATENCY-1)(70).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_2_B)    <= s_din_d(IR_LATENCY-1)(71).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_3_A)    <= s_din_d(IR_LATENCY-1)(72).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_3_B)    <= s_din_d(IR_LATENCY-1)(73).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_4_A)    <= s_din_d(IR_LATENCY-1)(74).data(38 downto 0);
  DL_39_link_AV_DOUT(PS10G_4_B)    <= s_din_d(IR_LATENCY-1)(75).data(38 downto 0);
  DL_39_link_AV_DOUT(PS_1_A)       <= s_din_d(IR_LATENCY-1)(76).data(38 downto 0);
  DL_39_link_AV_DOUT(PS_1_B)       <= s_din_d(IR_LATENCY-1)(77).data(38 downto 0);
  DL_39_link_AV_DOUT(PS_2_A)       <= s_din_d(IR_LATENCY-1)(78).data(38 downto 0);
  DL_39_link_AV_DOUT(PS_2_B)       <= s_din_d(IR_LATENCY-1)(79).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_1_A) <= s_din_d(IR_LATENCY-1)(84).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_1_B) <= s_din_d(IR_LATENCY-1)(85).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_2_A) <= s_din_d(IR_LATENCY-1)(86).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_2_B) <= s_din_d(IR_LATENCY-1)(87).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_3_A) <= s_din_d(IR_LATENCY-1)(88).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_3_B) <= s_din_d(IR_LATENCY-1)(89).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_4_A) <= s_din_d(IR_LATENCY-1)(90).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS10G_4_B) <= s_din_d(IR_LATENCY-1)(91).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS_1_A)    <= s_din_d(IR_LATENCY-1)(92).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS_1_B)    <= s_din_d(IR_LATENCY-1)(93).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS_2_A)    <= s_din_d(IR_LATENCY-1)(94).data(38 downto 0);
  DL_39_link_AV_DOUT(negPS_2_B)    <= s_din_d(IR_LATENCY-1)(95).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_1_A)     <= s_din_d(IR_LATENCY-1)(96).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_1_B)     <= s_din_d(IR_LATENCY-1)(97).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_2_A)     <= s_din_d(IR_LATENCY-1)(98).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_2_B)     <= s_din_d(IR_LATENCY-1)(99).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_3_A)     <= s_din_d(IR_LATENCY-1)(100).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_3_B)     <= s_din_d(IR_LATENCY-1)(101).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_4_A)     <= s_din_d(IR_LATENCY-1)(102).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_4_B)     <= s_din_d(IR_LATENCY-1)(103).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_5_A)     <= s_din_d(IR_LATENCY-1)(104).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_5_B)     <= s_din_d(IR_LATENCY-1)(105).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_6_A)     <= s_din_d(IR_LATENCY-1)(106).data(38 downto 0);
  DL_39_link_AV_DOUT(twoS_6_B)     <= s_din_d(IR_LATENCY-1)(107).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_1_A)    <= s_din_d(IR_LATENCY-1)(108).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_1_B)    <= s_din_d(IR_LATENCY-1)(109).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_2_A)    <= s_din_d(IR_LATENCY-1)(110).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_2_B)    <= s_din_d(IR_LATENCY-1)(111).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_3_A)    <= s_din_d(IR_LATENCY-1)(112).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_3_B)    <= s_din_d(IR_LATENCY-1)(113).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_4_A)    <= s_din_d(IR_LATENCY-1)(114).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_4_B)    <= s_din_d(IR_LATENCY-1)(115).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_5_A)    <= s_din_d(IR_LATENCY-1)(116).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_5_B)    <= s_din_d(IR_LATENCY-1)(117).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_6_A)    <= s_din_d(IR_LATENCY-1)(118).data(38 downto 0);
  DL_39_link_AV_DOUT(neg2S_6_B)    <= s_din_d(IR_LATENCY-1)(119).data(38 downto 0);

  -----------------------------------------------------------------------------
  -- Generate start signal
  -----------------------------------------------------------------------------
  set_reset_ffd_1 : entity work.set_reset_ffd
    port map (
      clk_i   => clk_i,
      set_i   => din_i(68).valid,
      reset_i => rst_i,
      q_o     => s_ir_start_srff
      );

  --With current IR setup latency, IR_Start needs to come up 4 clock cycles
  --before first data
  s_ir_start <= din_i(68).valid or s_ir_start_srff;
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
