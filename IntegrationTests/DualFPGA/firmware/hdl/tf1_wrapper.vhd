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
use work.memUtil_aux_pkg_f1.all;

entity tf1_wrapper is
  port (
    clk                      : in  std_logic;
    reset                    : in  std_logic;
    IR_start                 : in  std_logic;
    IR_bx_in                 : in  std_logic_vector(2 downto 0);
    TP_bx_out_0              : out std_logic_vector(2 downto 0); 
    TP_bx_out_vld            : out std_logic;
    TP_done                  : out std_logic;
    DL_39_link_AV_dout       : in  t_arr_DL_39_DATA;
    DL_39_link_empty_neg     : in  t_arr_DL_39_1b;
    DL_39_link_read          : out t_arr_DL_39_1b;
    AS_37_stream_V_dout        : out t_arr_AS_37_DATA;
    MPAR_76_stream_V_dout     : out t_arr_MPAR_76_DATA
    );
end entity tf1_wrapper;

architecture rtl of tf1_wrapper is

begin  -- architecture rtl

  SectorProcessor_1 : entity work.SectorProcessor
    port map (
      clk                            => clk,
      reset                          => reset,
      IR_start                       => IR_start,
      IR_bx_in                       => IR_bx_in,
      TP_bx_out                      => TP_bx_out_0,
      TP_bx_out_vld                  => TP_bx_out_vld,
      TP_done                        => TP_done,
      DL_PS10G_1_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_1_A),
      DL_PS10G_1_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_1_A),
      DL_PS10G_1_A_link_read         => DL_39_link_read(PS10G_1_A),
      DL_PS10G_1_B_link_AV_dout      => DL_39_link_AV_dout(PS10G_1_B),
      DL_PS10G_1_B_link_empty_neg    => DL_39_link_empty_neg(PS10G_1_B),
      DL_PS10G_1_B_link_read         => DL_39_link_read(PS10G_1_B),
      DL_PS10G_2_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_2_A),
      DL_PS10G_2_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_2_A),
      DL_PS10G_2_A_link_read         => DL_39_link_read(PS10G_2_A),
      DL_PS10G_2_B_link_AV_dout      => DL_39_link_AV_dout(PS10G_2_B),
      DL_PS10G_2_B_link_empty_neg    => DL_39_link_empty_neg(PS10G_2_B),
      DL_PS10G_2_B_link_read         => DL_39_link_read(PS10G_2_B),
      DL_PS10G_3_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_3_A),
      DL_PS10G_3_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_3_A),
      DL_PS10G_3_A_link_read         => DL_39_link_read(PS10G_3_A),
      DL_PS10G_3_B_link_AV_dout      => DL_39_link_AV_dout(PS10G_3_B),
      DL_PS10G_3_B_link_empty_neg    => DL_39_link_empty_neg(PS10G_3_B),
      DL_PS10G_3_B_link_read         => DL_39_link_read(PS10G_3_B),
      DL_PS10G_4_A_link_AV_dout      => DL_39_link_AV_dout(PS10G_4_A),
      DL_PS10G_4_A_link_empty_neg    => DL_39_link_empty_neg(PS10G_4_A),
      DL_PS10G_4_A_link_read         => DL_39_link_read(PS10G_4_A),
      DL_PS10G_4_B_link_AV_dout      => DL_39_link_AV_dout(PS10G_4_B),
      DL_PS10G_4_B_link_empty_neg    => DL_39_link_empty_neg(PS10G_4_B),
      DL_PS10G_4_B_link_read         => DL_39_link_read(PS10G_4_B),
      DL_PS_1_A_link_AV_dout         => DL_39_link_AV_dout(PS_1_A),
      DL_PS_1_A_link_empty_neg       => DL_39_link_empty_neg(PS_1_A),
      DL_PS_1_A_link_read            => DL_39_link_read(PS_1_A),
      DL_PS_1_B_link_AV_dout         => DL_39_link_AV_dout(PS_1_B),
      DL_PS_1_B_link_empty_neg       => DL_39_link_empty_neg(PS_1_B),
      DL_PS_1_B_link_read            => DL_39_link_read(PS_1_B),
      DL_PS_2_A_link_AV_dout         => DL_39_link_AV_dout(PS_2_A),
      DL_PS_2_A_link_empty_neg       => DL_39_link_empty_neg(PS_2_A),
      DL_PS_2_A_link_read            => DL_39_link_read(PS_2_A),
      DL_PS_2_B_link_AV_dout         => DL_39_link_AV_dout(PS_2_B),
      DL_PS_2_B_link_empty_neg       => DL_39_link_empty_neg(PS_2_B),
      DL_PS_2_B_link_read            => DL_39_link_read(PS_2_B),
      DL_negPS10G_1_A_link_AV_dout   => DL_39_link_AV_dout(negPS10G_1_A),
      DL_negPS10G_1_A_link_empty_neg => DL_39_link_empty_neg(negPS10G_1_A),
      DL_negPS10G_1_A_link_read      => DL_39_link_read(negPS10G_1_A),
      DL_negPS10G_1_B_link_AV_dout   => DL_39_link_AV_dout(negPS10G_1_B),
      DL_negPS10G_1_B_link_empty_neg => DL_39_link_empty_neg(negPS10G_1_B),
      DL_negPS10G_1_B_link_read      => DL_39_link_read(negPS10G_1_B),
      DL_negPS10G_2_A_link_AV_dout   => DL_39_link_AV_dout(negPS10G_2_A),
      DL_negPS10G_2_A_link_empty_neg => DL_39_link_empty_neg(negPS10G_2_A),
      DL_negPS10G_2_A_link_read      => DL_39_link_read(negPS10G_2_A),
      DL_negPS10G_2_B_link_AV_dout   => DL_39_link_AV_dout(negPS10G_2_B),
      DL_negPS10G_2_B_link_empty_neg => DL_39_link_empty_neg(negPS10G_2_B),
      DL_negPS10G_2_B_link_read      => DL_39_link_read(negPS10G_2_B),
      DL_negPS10G_3_A_link_AV_dout   => DL_39_link_AV_dout(negPS10G_3_A),
      DL_negPS10G_3_A_link_empty_neg => DL_39_link_empty_neg(negPS10G_3_A),
      DL_negPS10G_3_A_link_read      => DL_39_link_read(negPS10G_3_A),
      DL_negPS10G_3_B_link_AV_dout   => DL_39_link_AV_dout(negPS10G_3_B),
      DL_negPS10G_3_B_link_empty_neg => DL_39_link_empty_neg(negPS10G_3_B),
      DL_negPS10G_3_B_link_read      => DL_39_link_read(negPS10G_3_B),
      DL_negPS10G_4_A_link_AV_dout   => DL_39_link_AV_dout(negPS10G_4_A),
      DL_negPS10G_4_A_link_empty_neg => DL_39_link_empty_neg(negPS10G_4_A),
      DL_negPS10G_4_A_link_read      => DL_39_link_read(negPS10G_4_A),
      DL_negPS10G_4_B_link_AV_dout   => DL_39_link_AV_dout(negPS10G_4_B),
      DL_negPS10G_4_B_link_empty_neg => DL_39_link_empty_neg(negPS10G_4_B),
      DL_negPS10G_4_B_link_read      => DL_39_link_read(negPS10G_4_B),
      DL_negPS_1_A_link_AV_dout      => DL_39_link_AV_dout(negPS_1_A),
      DL_negPS_1_A_link_empty_neg    => DL_39_link_empty_neg(negPS_1_A),
      DL_negPS_1_A_link_read         => DL_39_link_read(negPS_1_A),
      DL_negPS_1_B_link_AV_dout      => DL_39_link_AV_dout(negPS_1_B),
      DL_negPS_1_B_link_empty_neg    => DL_39_link_empty_neg(negPS_1_B),
      DL_negPS_1_B_link_read         => DL_39_link_read(negPS_1_B),
      DL_negPS_2_A_link_AV_dout      => DL_39_link_AV_dout(negPS_2_A),
      DL_negPS_2_A_link_empty_neg    => DL_39_link_empty_neg(negPS_2_A),
      DL_negPS_2_A_link_read         => DL_39_link_read(negPS_2_A),
      DL_negPS_2_B_link_AV_dout      => DL_39_link_AV_dout(negPS_2_B),
      DL_negPS_2_B_link_empty_neg    => DL_39_link_empty_neg(negPS_2_B),
      DL_negPS_2_B_link_read         => DL_39_link_read(negPS_2_B),
      DL_twoS_1_A_link_AV_dout       => DL_39_link_AV_dout(twoS_1_A),
      DL_twoS_1_A_link_empty_neg     => DL_39_link_empty_neg(twoS_1_A),
      DL_twoS_1_A_link_read          => DL_39_link_read(twoS_1_A),
      DL_twoS_1_B_link_AV_dout       => DL_39_link_AV_dout(twoS_1_B),
      DL_twoS_1_B_link_empty_neg     => DL_39_link_empty_neg(twoS_1_B),
      DL_twoS_1_B_link_read          => DL_39_link_read(twoS_1_B),
      DL_twoS_2_A_link_AV_dout       => DL_39_link_AV_dout(twoS_2_A),
      DL_twoS_2_A_link_empty_neg     => DL_39_link_empty_neg(twoS_2_A),
      DL_twoS_2_A_link_read          => DL_39_link_read(twoS_2_A),
      DL_twoS_2_B_link_AV_dout       => DL_39_link_AV_dout(twoS_2_B),
      DL_twoS_2_B_link_empty_neg     => DL_39_link_empty_neg(twoS_2_B),
      DL_twoS_2_B_link_read          => DL_39_link_read(twoS_2_B),
      DL_twoS_3_A_link_AV_dout       => DL_39_link_AV_dout(twoS_3_A),
      DL_twoS_3_A_link_empty_neg     => DL_39_link_empty_neg(twoS_3_A),
      DL_twoS_3_A_link_read          => DL_39_link_read(twoS_3_A),
      DL_twoS_3_B_link_AV_dout       => DL_39_link_AV_dout(twoS_3_B),
      DL_twoS_3_B_link_empty_neg     => DL_39_link_empty_neg(twoS_3_B),
      DL_twoS_3_B_link_read          => DL_39_link_read(twoS_3_B),
      DL_twoS_4_A_link_AV_dout       => DL_39_link_AV_dout(twoS_4_A),
      DL_twoS_4_A_link_empty_neg     => DL_39_link_empty_neg(twoS_4_A),
      DL_twoS_4_A_link_read          => DL_39_link_read(twoS_4_A),
      DL_twoS_4_B_link_AV_dout       => DL_39_link_AV_dout(twoS_4_B),
      DL_twoS_4_B_link_empty_neg     => DL_39_link_empty_neg(twoS_4_B),
      DL_twoS_4_B_link_read          => DL_39_link_read(twoS_4_B),
      DL_twoS_5_A_link_AV_dout       => DL_39_link_AV_dout(twoS_5_A),
      DL_twoS_5_A_link_empty_neg     => DL_39_link_empty_neg(twoS_5_A),
      DL_twoS_5_A_link_read          => DL_39_link_read(twoS_5_A),
      DL_twoS_5_B_link_AV_dout       => DL_39_link_AV_dout(twoS_5_B),
      DL_twoS_5_B_link_empty_neg     => DL_39_link_empty_neg(twoS_5_B),
      DL_twoS_5_B_link_read          => DL_39_link_read(twoS_5_B),
      DL_twoS_6_A_link_AV_dout       => DL_39_link_AV_dout(twoS_6_A),
      DL_twoS_6_A_link_empty_neg     => DL_39_link_empty_neg(twoS_6_A),
      DL_twoS_6_A_link_read          => DL_39_link_read(twoS_6_A),
      DL_twoS_6_B_link_AV_dout       => DL_39_link_AV_dout(twoS_6_B),
      DL_twoS_6_B_link_empty_neg     => DL_39_link_empty_neg(twoS_6_B),
      DL_twoS_6_B_link_read          => DL_39_link_read(twoS_6_B),
      DL_neg2S_1_A_link_AV_dout      => DL_39_link_AV_dout(neg2S_1_A),
      DL_neg2S_1_A_link_empty_neg    => DL_39_link_empty_neg(neg2S_1_A),
      DL_neg2S_1_A_link_read         => DL_39_link_read(neg2S_1_A),
      DL_neg2S_1_B_link_AV_dout      => DL_39_link_AV_dout(neg2S_1_B),
      DL_neg2S_1_B_link_empty_neg    => DL_39_link_empty_neg(neg2S_1_B),
      DL_neg2S_1_B_link_read         => DL_39_link_read(neg2S_1_B),
      DL_neg2S_2_A_link_AV_dout      => DL_39_link_AV_dout(neg2S_2_A),
      DL_neg2S_2_A_link_empty_neg    => DL_39_link_empty_neg(neg2S_2_A),
      DL_neg2S_2_A_link_read         => DL_39_link_read(neg2S_2_A),
      DL_neg2S_2_B_link_AV_dout      => DL_39_link_AV_dout(neg2S_2_B),
      DL_neg2S_2_B_link_empty_neg    => DL_39_link_empty_neg(neg2S_2_B),
      DL_neg2S_2_B_link_read         => DL_39_link_read(neg2S_2_B),
      DL_neg2S_3_A_link_AV_dout      => DL_39_link_AV_dout(neg2S_3_A),
      DL_neg2S_3_A_link_empty_neg    => DL_39_link_empty_neg(neg2S_3_A),
      DL_neg2S_3_A_link_read         => DL_39_link_read(neg2S_3_A),
      DL_neg2S_3_B_link_AV_dout      => DL_39_link_AV_dout(neg2S_3_B),
      DL_neg2S_3_B_link_empty_neg    => DL_39_link_empty_neg(neg2S_3_B),
      DL_neg2S_3_B_link_read         => DL_39_link_read(neg2S_3_B),
      DL_neg2S_4_A_link_AV_dout      => DL_39_link_AV_dout(neg2S_4_A),
      DL_neg2S_4_A_link_empty_neg    => DL_39_link_empty_neg(neg2S_4_A),
      DL_neg2S_4_A_link_read         => DL_39_link_read(neg2S_4_A),
      DL_neg2S_4_B_link_AV_dout      => DL_39_link_AV_dout(neg2S_4_B),
      DL_neg2S_4_B_link_empty_neg    => DL_39_link_empty_neg(neg2S_4_B),
      DL_neg2S_4_B_link_read         => DL_39_link_read(neg2S_4_B),
      DL_neg2S_5_A_link_AV_dout      => DL_39_link_AV_dout(neg2S_5_A),
      DL_neg2S_5_A_link_empty_neg    => DL_39_link_empty_neg(neg2S_5_A),
      DL_neg2S_5_A_link_read         => DL_39_link_read(neg2S_5_A),
      DL_neg2S_5_B_link_AV_dout      => DL_39_link_AV_dout(neg2S_5_B),
      DL_neg2S_5_B_link_empty_neg    => DL_39_link_empty_neg(neg2S_5_B),
      DL_neg2S_5_B_link_read         => DL_39_link_read(neg2S_5_B),
      DL_neg2S_6_A_link_AV_dout      => DL_39_link_AV_dout(neg2S_6_A),
      DL_neg2S_6_A_link_empty_neg    => DL_39_link_empty_neg(neg2S_6_A),
      DL_neg2S_6_A_link_read         => DL_39_link_read(neg2S_6_A),
      DL_neg2S_6_B_link_AV_dout      => DL_39_link_AV_dout(neg2S_6_B),
      DL_neg2S_6_B_link_empty_neg    => DL_39_link_empty_neg(neg2S_6_B),
      DL_neg2S_6_B_link_read         => DL_39_link_read(neg2S_6_B),
      AS_L1PHIAn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIAn1),
      AS_L1PHIBn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIBn1),
      AS_L1PHICn1_stream_V_dout      => AS_37_stream_V_dout(L1PHICn1),
      AS_L1PHIDn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIDn1),
      AS_L1PHIEn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIEn1),
      AS_L1PHIFn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIFn1),
      AS_L1PHIGn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIGn1),
      AS_L1PHIHn1_stream_V_dout      => AS_37_stream_V_dout(L1PHIHn1),
      AS_L2PHIAn1_stream_V_dout      => AS_37_stream_V_dout(L2PHIAn1),
      AS_L2PHIBn1_stream_V_dout      => AS_37_stream_V_dout(L2PHIBn1),
      AS_L2PHICn1_stream_V_dout      => AS_37_stream_V_dout(L2PHICn1),
      AS_L2PHIDn1_stream_V_dout      => AS_37_stream_V_dout(L2PHIDn1),
      AS_L3PHIAn1_stream_V_dout      => AS_37_stream_V_dout(L3PHIAn1),
      AS_L3PHIBn1_stream_V_dout      => AS_37_stream_V_dout(L3PHIBn1),
      AS_L3PHICn1_stream_V_dout      => AS_37_stream_V_dout(L3PHICn1),
      AS_L3PHIDn1_stream_V_dout      => AS_37_stream_V_dout(L3PHIDn1),
      AS_L4PHIAn1_stream_V_dout      => AS_37_stream_V_dout(L4PHIAn1),
      AS_L4PHIBn1_stream_V_dout      => AS_37_stream_V_dout(L4PHIBn1),
      AS_L4PHICn1_stream_V_dout      => AS_37_stream_V_dout(L4PHICn1),
      AS_L4PHIDn1_stream_V_dout      => AS_37_stream_V_dout(L4PHIDn1),
      AS_L5PHIAn1_stream_V_dout      => AS_37_stream_V_dout(L5PHIAn1),
      AS_L5PHIBn1_stream_V_dout      => AS_37_stream_V_dout(L5PHIBn1),
      AS_L5PHICn1_stream_V_dout      => AS_37_stream_V_dout(L5PHICn1),
      AS_L5PHIDn1_stream_V_dout      => AS_37_stream_V_dout(L5PHIDn1),
      AS_L6PHIAn1_stream_V_dout      => AS_37_stream_V_dout(L6PHIAn1),
      AS_L6PHIBn1_stream_V_dout      => AS_37_stream_V_dout(L6PHIBn1),
      AS_L6PHICn1_stream_V_dout      => AS_37_stream_V_dout(L6PHICn1),
      AS_L6PHIDn1_stream_V_dout      => AS_37_stream_V_dout(L6PHIDn1),
      AS_D1PHIAn1_stream_V_dout      => AS_37_stream_V_dout(D1PHIAn1),
      AS_D1PHIBn1_stream_V_dout      => AS_37_stream_V_dout(D1PHIBn1),
      AS_D1PHICn1_stream_V_dout      => AS_37_stream_V_dout(D1PHICn1),
      AS_D1PHIDn1_stream_V_dout      => AS_37_stream_V_dout(D1PHIDn1),
      AS_D2PHIAn1_stream_V_dout      => AS_37_stream_V_dout(D2PHIAn1),
      AS_D2PHIBn1_stream_V_dout      => AS_37_stream_V_dout(D2PHIBn1),
      AS_D2PHICn1_stream_V_dout      => AS_37_stream_V_dout(D2PHICn1),
      AS_D2PHIDn1_stream_V_dout      => AS_37_stream_V_dout(D2PHIDn1),
      AS_D3PHIAn1_stream_V_dout      => AS_37_stream_V_dout(D3PHIAn1),
      AS_D3PHIBn1_stream_V_dout      => AS_37_stream_V_dout(D3PHIBn1),
      AS_D3PHICn1_stream_V_dout      => AS_37_stream_V_dout(D3PHICn1),
      AS_D3PHIDn1_stream_V_dout      => AS_37_stream_V_dout(D3PHIDn1),
      AS_D4PHIAn1_stream_V_dout      => AS_37_stream_V_dout(D4PHIAn1),
      AS_D4PHIBn1_stream_V_dout      => AS_37_stream_V_dout(D4PHIBn1),
      AS_D4PHICn1_stream_V_dout      => AS_37_stream_V_dout(D4PHICn1),
      AS_D4PHIDn1_stream_V_dout      => AS_37_stream_V_dout(D4PHIDn1),
      AS_D5PHIAn1_stream_V_dout      => AS_37_stream_V_dout(D5PHIAn1),
      AS_D5PHIBn1_stream_V_dout      => AS_37_stream_V_dout(D5PHIBn1),
      AS_D5PHICn1_stream_V_dout      => AS_37_stream_V_dout(D5PHICn1),
      AS_D5PHIDn1_stream_V_dout      => AS_37_stream_V_dout(D5PHIDn1),
      MPAR_L1L2ABC_stream_V_dout    => MPAR_76_stream_V_dout(L1L2ABC),
      MPAR_L1L2DE_stream_V_dout     => MPAR_76_stream_V_dout(L1L2DE),
      MPAR_L1L2F_stream_V_dout      => MPAR_76_stream_V_dout(L1L2F),
      MPAR_L1L2G_stream_V_dout      => MPAR_76_stream_V_dout(L1L2G),
      MPAR_L1L2HI_stream_V_dout     => MPAR_76_stream_V_dout(L1L2HI),
      MPAR_L1L2JKL_stream_V_dout    => MPAR_76_stream_V_dout(L1L2JKL),
      MPAR_L2L3ABCD_stream_V_dout   => MPAR_76_stream_V_dout(L2L3ABCD),
      MPAR_L3L4AB_stream_V_dout     => MPAR_76_stream_V_dout(L3L4AB),
      MPAR_L3L4CD_stream_V_dout     => MPAR_76_stream_V_dout(L3L4CD),
      MPAR_L5L6ABCD_stream_V_dout   => MPAR_76_stream_V_dout(L5L6ABCD),
      MPAR_D1D2ABCD_stream_V_dout   => MPAR_76_stream_V_dout(D1D2ABCD),
      MPAR_D3D4ABCD_stream_V_dout   => MPAR_76_stream_V_dout(D3D4ABCD),
      MPAR_L1D1ABCD_stream_V_dout   => MPAR_76_stream_V_dout(L1D1ABCD),
      MPAR_L1D1EFGH_stream_V_dout   => MPAR_76_stream_V_dout(L1D1EFGH),
      MPAR_L2D1ABCD_stream_V_dout   => MPAR_76_stream_V_dout(L2D1ABCD)
      );

end architecture rtl;
