-------------------------------------------------------------------------------
-- Title      : payload
-- Project    : 
-------------------------------------------------------------------------------
-- File       : payload.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-06-21
-- Last update: 2023-06-02
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
use work.emp_slink_types.all;
-- tf
use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.tf_interface_pkg.all;
use work.hybrid_data_types.all;
use work.hybrid_config.all;
use work.hybrid_data_formats.all;

entity emp_payload is
  port (
    clk          : in  std_logic; --unused
    rst          : in  std_logic;
    ipb_in       : in  ipb_wbus;  --unused
    clk40        : in  std_logic; --unused
    clk_payload  : in  std_logic_vector(2 downto 0);
    rst_payload  : in  std_logic_vector(2 downto 0); --unused
    clk_p        : in  std_logic;
    rst_loc      : in  std_logic_vector(N_REGION - 1 downto 0); --unused
    clken_loc    : in  std_logic_vector(N_REGION - 1 downto 0); --unused
    ctrs         : in  ttc_stuff_array(N_REGION - 1 downto 0);  --in linktosecproc, but unused
    d            : in  ldata(4 * N_REGION - 1 downto 0);
    ipb_out      : out ipb_rbus;  --unused
    bc0          : out std_logic; --unused
    q            : out ldata(4 * N_REGION - 1 downto 0); 
    gpio         : out std_logic_vector(29 downto 0);    --unused
    gpio_en      : out std_logic_vector(29 downto 0);    --unused
    slink_q      : out slink_input_data_quad_array(SLINK_MAX_QUADS - 1 downto 0); --unused
    backpressure : in  std_logic_vector(SLINK_MAX_QUADS - 1 downto 0) --unused
    );
end;

architecture rtl of emp_payload is

  signal s_IR_data            : t_arr_DL_39_DATA;
  signal s_ir_start           : std_logic;
  signal s_bx                 : std_logic_vector(2 downto 0);
  signal s_TW_98_stream_data  : t_arr_TW_98_DATA;
  signal s_TW_98_stream_valid : t_arr_TW_98_1b;
  signal s_BW_46_stream_data  : t_arr_BW_46_DATA;
  signal s_BW_46_stream_valid : t_arr_BW_46_1b;
  signal s_FT_bx_out_vld      : std_logic;
  signal rst_p                : std_logic;
  signal s_tftokf             : t_channlesTB(numTW_98 - 1 downto 0);
  signal s_kfout              : t_frames(numLinksTFP - 1 downto 0);
  signal s_tfout              : ldata(numLinksTFP - 1 downto 0);
  signal s_tfin               : ldata(4 * N_REGION - 1 downto 0);
  signal s_tfoutout           : ldata(4 * N_REGION - 1 downto 0);

begin  -- architecture rtl

  -----------------------------------------------------------------------------
  -- EMP ports
  -----------------------------------------------------------------------------
  slink_q <= (others => SLINK_INPUT_DATA_ARRAY_NULL);
  gpio    <= (others => '0');
  gpio_en <= (others => '0');
  ipb_out <= IPB_RBUS_NULL;
  bc0     <= '0';

  emp_cdc_1 : entity work.emp_cdc
    generic map (
      channel_first => 68,
      channel_last  => 107
      )
    port map (
      clk_i => clk_p,
      clk_o => clk_payload(1),
      rst_i => rst,
      din_i => d,
      din_o => s_tfin,
      rst_o => rst_p
      );

  -----------------------------------------------------------------------------
  -- Link to Sector Processor formatter
  -----------------------------------------------------------------------------
   linktosecproc_1 : entity work.linktosecproc
     port map (
       clk_i                => clk_payload(1),
       --clk_i                => clk_p,
       rst_i                => rst_p,
       --rst_i                => rst,
       ttc_i                => ctrs,
       din_i                => s_tfin,
       ir_start_o           => s_ir_start,
       bx_o                 => s_bx,
       DL_39_link_AV_dout   => s_IR_data,
       DL_39_link_empty_neg => open,
       DL_39_link_read      => (others => '0')
       );

  -----------------------------------------------------------------------------
  -- Sector Processor
  -----------------------------------------------------------------------------
   SectorProcessor_1 : entity work.SectorProcessor
     port map (
       clk                     => clk_payload(1),
       --clk                     => clk_p,
       reset                   => rst_p,
       --reset                   => rst,
       IR_start                => s_ir_start,
       IR_bx_in                => s_bx,
       FT_bx_out               => open,
       FT_bx_out_vld           => s_FT_bx_out_vld,
       FT_done                 => open,
       DL_39_link_AV_dout      => s_IR_data,
       DL_39_link_empty_neg    => (others => '1'),
       DL_39_link_read         => open,
       TW_98_stream_AV_din     => s_TW_98_stream_data,
       TW_98_stream_A_full_neg => (others => '1'),
       TW_98_stream_A_write    => s_TW_98_stream_valid,
       BW_46_stream_AV_din     => s_BW_46_stream_data,
       BW_46_stream_A_full_neg => (others => '1'),
       BW_46_stream_A_write    => s_BW_46_stream_valid
       );

  -----------------------------------------------------------------------------
  -- Sector Processor to Link formatter
  -----------------------------------------------------------------------------
  -- secproctolink_1 : entity work.secproctolink
  --   port map (
  --     clk_i                   => clk_p,
  --     TW_98_stream_data_i     => s_TW_98_stream_data,
  --     TW_98_stream_write_i    => s_TW_98_stream_valid,
  --     TW_98_stream_full_neg_o => open,
  --     BW_46_stream_data_i     => s_BW_46_stream_data,
  --     BW_46_stream_write_i    => s_BW_46_stream_valid,
  --     BW_46_stream_full_neg_i => open,
  --     dout_o                  => q
  --     );

  -----------------------------------------------------------------------------
  -- Sector Processor to KF formatter
  -----------------------------------------------------------------------------
   tf_to_kf_1 : entity work.tf_to_kf
     port map (
       clk_i         => clk_payload(1),
       --clk_i         => clk_p,
       TW_98_data_i  => s_TW_98_stream_data,
       TW_98_valid_i => s_TW_98_stream_valid,
       BW_46_data_i  => s_BW_46_stream_data,
       BW_46_valid_i => s_BW_46_stream_valid,
       kf_reset_i    => s_FT_bx_out_vld,
       tftokf_o      => s_tftokf
       );

  -----------------------------------------------------------------------------
  -- KF
  -----------------------------------------------------------------------------
   kf_wrapper_1 : entity work.kf_wrapper
     port map (
       clk_i   => clk_payload(1),
       --clk_i   => clk_p,
       kfin_i  => s_tftokf,
       kfout_o => s_kfout
       );

  -----------------------------------------------------------------------------
  -- Output step
  -----------------------------------------------------------------------------
   kfout_isolation_out_1 : entity work.kfout_isolation_out
     port map (
       clk        => clk_payload(1),
       --clk        => clk_p,
       out_packet => conv(s_tfin),
       out_din    => s_kfout,
       out_dout   => s_tfout
       );

  s_tfoutout(120)        <= s_tfout(0);
  s_tfoutout(121)        <= s_tfout(1);
  --q(120).strobe <= '1';
  --q(121).strobe <= '1';

  emp_cdc_2 : entity work.emp_cdc
    generic map (
      channel_first => 120,
      channel_last  => 121
      )
    port map (
      clk_i => clk_payload(1),
      clk_o => clk_p,
      rst_i => rst_p,
      din_i => s_tfoutout,
      din_o => q,
      rst_o => open
      );

end architecture rtl;
