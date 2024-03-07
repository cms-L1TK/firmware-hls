-------------------------------------------------------------------------------
-- Title      : kf wrapper
-- Project    : 
-------------------------------------------------------------------------------
-- File       : kf_top.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-11-04
-- Last update: 2023-02-24
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2022 University of Colorado Boulder
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-11-04  1.0      fmarini Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

use work.hybrid_data_formats.all;
use work.hybrid_config.all;
use work.hybrid_data_types.all;

entity kf_wrapper is
  port (
    clk_i   : in  std_logic;
    kfin_i  : in  t_channlesTB(numSeedTypes - 1 downto 0);
    kfout_o : out t_frames(numLinksTFP - 1 downto 0)
    );
end entity kf_wrapper;

architecture rtl of kf_wrapper is

  signal s_kfin_dout : t_channelsZHT(numSeedTypes - 1 downto 0);
  signal s_kf_dout   : t_channelsKF(numNodesKF - 1 downto 0);

begin  -- architecture rtl

  kfin_top_1 : entity work.kfin_top
    port map (
      clk       => clk_i,
      kfin_din  => kfin_i,
      kfin_dout => s_kfin_dout
      );

  kf_top_1 : entity work.kf_top
    port map (
      clk     => clk_i,
      kf_din  => s_kfin_dout,
      kf_dout => s_kf_dout
      );

  kfout_top_1 : entity work.kfout_top_conv
    port map (
      clk        => clk_i,
      kfout_din  => s_kf_dout,
      kfout_dout => kfout_o
      );

end architecture rtl;
