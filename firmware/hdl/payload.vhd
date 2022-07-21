-------------------------------------------------------------------------------
-- Title      : payload
-- Project    : 
-------------------------------------------------------------------------------
-- File       : payload.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-06-21
-- Last update: 2022-07-14
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2022 University of Colorado Boulder
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-06-21  1.0      fmarini Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use work.ipbus.all;
use work.emp_data_types.all;
use work.emp_device_decl.all;
use work.emp_ttc_decl.all;
-- emp US
use work.tf_pkg.all;
use work.memUtil_pkg.all;

entity emp_payload is
  port (
    clk         : in  std_logic;
    rst         : in  std_logic;
    ipb_in      : in  ipb_wbus;
    clk40       : in  std_logic;
    clk_payload : in  std_logic_vector(2 downto 0);
    rst_payload : in  std_logic_vector(2 downto 0);
    clk_p       : in  std_logic;
    rst_loc     : in  std_logic_vector(N_REGION - 1 downto 0);
    clken_loc   : in  std_logic_vector(N_REGION - 1 downto 0);
    ctrs        : in  ttc_stuff_array(N_REGION - 1 downto 0);
    d           : in  ldata(4 * N_REGION - 1 downto 0);
    ipb_out     : out ipb_rbus;
    bc0         : out std_logic;
    q           : out ldata(4 * N_REGION - 1 downto 0);
    gpio        : out std_logic_vector(29 downto 0);
    gpio_en     : out std_logic_vector(29 downto 0)
    );
end;

architecture rtl of emp_payload is

  signal s_IR_data            : t_arr_DL_39_DATA;
  signal s_ir_start           : std_logic;
  signal s_bx                 : std_logic_vector(2 downto 0);
  signal s_TW_84_stream_data  : t_arr_TW_84_DATA;
  signal s_TW_84_stream_valid : t_arr_TW_84_1b;
  signal s_BW_46_stream_data  : t_arr_BW_46_DATA;
  signal s_BW_46_stream_valid : t_arr_BW_46_1b;

begin  -- architecture rtl

  linktosecproc_1 : entity work.linktosecproc
    port map (
      clk_i                => clk_p,
      ttc_i                => ctrs,
      din_i                => d,
      ir_start_o           => s_ir_start,
      bx_o                 => s_bx,
      DL_39_link_AV_dout   => s_IR_data,
      DL_39_link_empty_neg => open,
      DL_39_link_read      => (others => '0')
      );

  SectorProcessor_1 : entity work.SectorProcessor
    port map (
      clk                     => clk_p,
      reset                   => rst,
      IR_start                => s_ir_start,
      IR_bx_in                => s_bx,
      FT_bx_out               => open,
      FT_bx_out_vld           => open,
      FT_done                 => open,
      DL_39_link_AV_dout      => s_IR_data,
      DL_39_link_empty_neg    => (others => '1'),
      DL_39_link_read         => open,
      TW_84_stream_AV_din     => s_TW_84_stream_data,
      TW_84_stream_A_full_neg => (others => '1'),
      TW_84_stream_A_write    => s_TW_84_stream_valid,
      BW_46_stream_AV_din     => s_BW_46_stream_data,
      BW_46_stream_A_full_neg => (others => '1'),
      BW_46_stream_A_write    => s_BW_46_stream_valid
      );

  secproctolink_1 : entity work.secproctolink
    port map (
      clk_i                   => clk_p,
      TW_84_stream_data_i     => s_TW_84_stream_data,
      TW_84_stream_write_i    => s_TW_84_stream_valid,
      TW_84_stream_full_neg_o => open,
      BW_46_stream_data_i     => s_BW_46_stream_data,
      BW_46_stream_write_i    => s_BW_46_stream_valid,
      BW_46_stream_full_neg_i => open,
      dout_o                  => q
      );

end architecture rtl;
