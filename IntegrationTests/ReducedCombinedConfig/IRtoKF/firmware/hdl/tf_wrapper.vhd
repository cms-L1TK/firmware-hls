-------------------------------------------------------------------------------
-- Title      : tf wrapper
-- Project    : 
-------------------------------------------------------------------------------
-- File       : tf_wrapper.vhd
-- Author     : Michael Oshiro  <mco62@cornell.edu>
-- Company    : Cornell University
-- Created    : 2024-01-19
-- Last update: 2024-01-19
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: Simple module to pack/unpack SectorProcessor inputs into vectors
-------------------------------------------------------------------------------
-- Copyright (c) 2024 Cornell University
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-01-19  1.0      oshiro  Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

use work.memUtil_pkg.all;
use work.memUtil_aux_pkg.all;

entity tf_wrapper is
  port (
    clk                      : in  std_logic;
    reset                    : in  std_logic;
    IR_start                 : in  std_logic;
    IR_bx_in                 : in  std_logic_vector(2 downto 0);
    FT_bx_out                : out std_logic_vector(2 downto 0); 
    FT_bx_out_vld            : out std_logic;
    FT_done                  : out std_logic;
    DL_39_link_AV_dout       : in  t_arr_DL_39_DATA;
    DL_39_link_empty_neg     : in  t_arr_DL_39_1b;
    DL_39_link_read          : out t_arr_DL_39_1b;
    TW_104_stream_AV_din     : out t_arr_TW_104_DATA;
    TW_104_stream_A_full_neg : in  t_arr_TW_104_1b;
    TW_104_stream_A_write    : out t_arr_TW_104_1b;
    BW_46_stream_AV_din      : out t_arr_BW_46_DATA;
    BW_46_stream_A_full_neg  : in  t_arr_BW_46_1b;
    BW_46_stream_A_write     : out t_arr_BW_46_1b
    );
end entity tf_wrapper;

architecture rtl of tf_wrapper is

begin  -- architecture rtl

  SectorProcessor_1 : entity work.SectorProcessor
    port map (
      clk                            => clk,
      reset                          => reset,
      IR_start                       => IR_start,
      IR_bx_in                       => IR_bx_in,
      FT_bx_out                      => FT_bx_out,
      FT_bx_out_vld                  => FT_bx_out_vld,
      FT_done                        => FT_done,
      DL_PS10G_1_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_1_A),
      DL_PS10G_1_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_1_A),
      DL_PS10G_1_A_link_read         => DL_39_link_read(PS10G_1_A),
      DL_PS10G_2_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_2_A),
      DL_PS10G_2_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_2_A),
      DL_PS10G_2_A_link_read         => DL_39_link_read(PS10G_2_A),
      DL_PS10G_3_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_3_A),
      DL_PS10G_3_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_3_A),
      DL_PS10G_3_A_link_read         => DL_39_link_read(PS10G_3_A),
      DL_PS_1_A_link_AV_dout         => DL_39_link_AV_dout(PS_1_A),
      DL_PS_1_A_link_empty_neg       => DL_39_link_empty_neg(PS_1_A),
      DL_PS_1_A_link_read            => DL_39_link_read(PS_1_A),
      DL_PS_2_A_link_AV_dout         => DL_39_link_AV_dout(PS_2_A),
      DL_PS_2_A_link_empty_neg       => DL_39_link_empty_neg(PS_2_A),
      DL_PS_2_A_link_read            => DL_39_link_read(PS_2_A),
      DL_twoS_1_A_link_AV_dout       => DL_39_link_AV_dout(twoS_1_A),
      DL_twoS_1_A_link_empty_neg     => DL_39_link_empty_neg(twoS_1_A),
      DL_twoS_1_A_link_read          => DL_39_link_read(twoS_1_A),
      DL_twoS_2_A_link_AV_dout       => DL_39_link_AV_dout(twoS_2_A),
      DL_twoS_2_A_link_empty_neg     => DL_39_link_empty_neg(twoS_2_A),
      DL_twoS_2_A_link_read          => DL_39_link_read(twoS_2_A),
      DL_twoS_3_A_link_AV_dout       => DL_39_link_AV_dout(twoS_3_A),
      DL_twoS_3_A_link_empty_neg     => DL_39_link_empty_neg(twoS_3_A),
      DL_twoS_3_A_link_read          => DL_39_link_read(twoS_3_A),
      DL_twoS_4_A_link_AV_dout       => DL_39_link_AV_dout(twoS_4_A),
      DL_twoS_4_A_link_empty_neg     => DL_39_link_empty_neg(twoS_4_A),
      DL_twoS_4_A_link_read          => DL_39_link_read(twoS_4_A),
      TW_L1L2_stream_AV_din          => TW_104_stream_AV_din(L1L2),
      TW_L1L2_stream_A_full_neg      => TW_104_stream_A_full_neg(L1L2),
      TW_L1L2_stream_A_write         => TW_104_stream_A_write(L1L2),
      BW_L1L2_L3_stream_AV_din       => BW_46_stream_AV_din(L1L2_L3),
      BW_L1L2_L3_stream_A_full_neg   => BW_46_stream_A_full_neg(L1L2_L3),
      BW_L1L2_L3_stream_A_write      => BW_46_stream_A_write(L1L2_L3),
      BW_L1L2_L4_stream_AV_din       => BW_46_stream_AV_din(L1L2_L4),
      BW_L1L2_L4_stream_A_full_neg   => BW_46_stream_A_full_neg(L1L2_L4),
      BW_L1L2_L4_stream_A_write      => BW_46_stream_A_write(L1L2_L4),
      BW_L1L2_L5_stream_AV_din       => BW_46_stream_AV_din(L1L2_L5),
      BW_L1L2_L5_stream_A_full_neg   => BW_46_stream_A_full_neg(L1L2_L5),
      BW_L1L2_L5_stream_A_write      => BW_46_stream_A_write(L1L2_L5),
      BW_L1L2_L6_stream_AV_din       => BW_46_stream_AV_din(L1L2_L6),
      BW_L1L2_L6_stream_A_full_neg   => BW_46_stream_A_full_neg(L1L2_L6),
      BW_L1L2_L6_stream_A_write      => BW_46_stream_A_write(L1L2_L6)
      );

end architecture rtl;
