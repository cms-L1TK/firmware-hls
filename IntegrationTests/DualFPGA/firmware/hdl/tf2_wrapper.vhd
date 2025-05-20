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
use work.memUtil_aux_pkg_f2.all;

entity tf2_wrapper is
  port (
    clk                       : in  std_logic;
    reset                     : in  std_logic;
    PC_start                  : in  std_logic;
    PC_bx_in                  : in  std_logic_vector(2 downto 0);
    PC_bx_out                 : out std_logic_vector(2 downto 0);
    PC_bx_out_vld             : out std_logic;
    PC_done                   : out std_logic;
    TB_bx_out                 : out std_logic_vector(2 downto 0); 
    TB_bx_out_vld             : out std_logic;
    TB_done                   : out std_logic;
    TB_last_track             : out std_logic;
    TB_last_track_vld         : out std_logic;
    AS_36_wea                 : in t_arr_AS_36_1b;
    AS_36_writeaddr           : in t_arr_AS_36_ADDR;
    AS_36_din                 : in t_arr_AS_36_DATA;
    MPAR_73_wea               : in t_arr_MTPAR_73_1b;
    MPAR_73_writeaddr         : in t_arr_MTPAR_73_ADDR;
    MPAR_73_din               : in t_arr_MTPAR_73_DATA;
    TW_113_stream_AV_din      : out t_arr_TW_113_DATA;
    TW_113_stream_A_full_neg  : in t_arr_TW_113_1b;
    TW_113_stream_A_write     : out t_arr_TW_113_1b;
    DW_49_stream_AV_din       : out t_arr_DW_49_DATA;
    DW_49_stream_A_full_neg   : in t_arr_DW_49_1b;
    DW_49_stream_A_write      : out t_arr_DW_49_1b;
    BW_46_stream_AV_din       : out t_arr_BW_46_DATA;
    BW_46_stream_A_full_neg   : in t_arr_BW_46_1b;
    BW_46_stream_A_write      : out t_arr_BW_46_1b
    );
end entity tf2_wrapper;

architecture rtl of tf2_wrapper is

  signal f2_in : t_f2_in := c_f2_in_init;
  signal f2_out : t_f2_out := c_f2_out_init;

begin  -- architecture rtl

  f2_in_1 : entity work.tf_pipeline_slr_xing
    generic map (
      NUM_SLR => 4,
      EMP_WRAPPER => true
      )
    port map (
      clk => clk,

      f2_input_in.PC_start => PC_start,
      f2_input_in.PC_bx_in => PC_bx_in,
      f2_input_in.AS_36_wea => AS_36_wea,
      f2_input_in.AS_36_writeaddr => AS_36_writeaddr,
      f2_input_in.AS_36_din => AS_36_din,
      f2_input_in.MPAR_73_wea => MPAR_73_wea,
      f2_input_in.MPAR_73_writeaddr => MPAR_73_writeaddr,
      f2_input_in.MPAR_73_din => MPAR_73_din,

      f2_input_out => f2_in
      );

  SectorProcessor_1 : entity work.SectorProcessor
    port map (
      clk                     => clk,
      reset                   => reset,
      PC_start                => f2_in.PC_start,
      PC_bx_in                => f2_in.PC_bx_in,
      PC_bx_out               => f2_out.PC_bx_out,
      PC_bx_out_vld           => f2_out.PC_bx_out_vld,
      PC_done                 => f2_out.PC_done,
      TB_bx_out               => f2_out.TB_bx_out,
      TB_bx_out_vld           => f2_out.TB_bx_out_vld,
      TB_done                 => f2_out.TB_done,
      TB_AAAA_last_track      => f2_out.TB_last_track,
      TB_AAAA_last_track_vld  => f2_out.TB_last_track_vld,
      TB_BBBB_last_track      => open,
      TB_BBBB_last_track_vld  => open,
      AS_L1PHIAin_wea       => f2_in.AS_36_wea(L1PHIAn1),
      AS_L1PHIAin_writeaddr => f2_in.AS_36_writeaddr(L1PHIAn1),
      AS_L1PHIAin_din       => f2_in.AS_36_din(L1PHIAn1),
      AS_L1PHIBin_wea       => f2_in.AS_36_wea(L1PHIBn1),
      AS_L1PHIBin_writeaddr => f2_in.AS_36_writeaddr(L1PHIBn1),
      AS_L1PHIBin_din       => f2_in.AS_36_din(L1PHIBn1),
      AS_L1PHICin_wea       => f2_in.AS_36_wea(L1PHICn1),
      AS_L1PHICin_writeaddr => f2_in.AS_36_writeaddr(L1PHICn1),
      AS_L1PHICin_din       => f2_in.AS_36_din(L1PHICn1),
      AS_L1PHIDin_wea       => f2_in.AS_36_wea(L1PHIDn1),
      AS_L1PHIDin_writeaddr => f2_in.AS_36_writeaddr(L1PHIDn1),
      AS_L1PHIDin_din       => f2_in.AS_36_din(L1PHIDn1),
      AS_L1PHIEin_wea       => f2_in.AS_36_wea(L1PHIEn1),
      AS_L1PHIEin_writeaddr => f2_in.AS_36_writeaddr(L1PHIEn1),
      AS_L1PHIEin_din       => f2_in.AS_36_din(L1PHIEn1),
      AS_L1PHIFin_wea       => f2_in.AS_36_wea(L1PHIFn1),
      AS_L1PHIFin_writeaddr => f2_in.AS_36_writeaddr(L1PHIFn1),
      AS_L1PHIFin_din       => f2_in.AS_36_din(L1PHIFn1),
      AS_L1PHIGin_wea       => f2_in.AS_36_wea(L1PHIGn1),
      AS_L1PHIGin_writeaddr => f2_in.AS_36_writeaddr(L1PHIGn1),
      AS_L1PHIGin_din       => f2_in.AS_36_din(L1PHIGn1),
      AS_L1PHIHin_wea       => f2_in.AS_36_wea(L1PHIHn1),
      AS_L1PHIHin_writeaddr => f2_in.AS_36_writeaddr(L1PHIHn1),
      AS_L1PHIHin_din       => f2_in.AS_36_din(L1PHIHn1),
      AS_L2PHIAin_wea       => f2_in.AS_36_wea(L2PHIAn1),
      AS_L2PHIAin_writeaddr => f2_in.AS_36_writeaddr(L2PHIAn1),
      AS_L2PHIAin_din       => f2_in.AS_36_din(L2PHIAn1),
      AS_L2PHIBin_wea       => f2_in.AS_36_wea(L2PHIBn1),
      AS_L2PHIBin_writeaddr => f2_in.AS_36_writeaddr(L2PHIBn1),
      AS_L2PHIBin_din       => f2_in.AS_36_din(L2PHIBn1),
      AS_L2PHICin_wea       => f2_in.AS_36_wea(L2PHICn1),
      AS_L2PHICin_writeaddr => f2_in.AS_36_writeaddr(L2PHICn1),
      AS_L2PHICin_din       => f2_in.AS_36_din(L2PHICn1),
      AS_L2PHIDin_wea       => f2_in.AS_36_wea(L2PHIDn1),
      AS_L2PHIDin_writeaddr => f2_in.AS_36_writeaddr(L2PHIDn1),
      AS_L2PHIDin_din       => f2_in.AS_36_din(L2PHIDn1),
      AS_L3PHIAin_wea       => f2_in.AS_36_wea(L3PHIAn1),
      AS_L3PHIAin_writeaddr => f2_in.AS_36_writeaddr(L3PHIAn1),
      AS_L3PHIAin_din       => f2_in.AS_36_din(L3PHIAn1),
      AS_L3PHIBin_wea       => f2_in.AS_36_wea(L3PHIBn1),
      AS_L3PHIBin_writeaddr => f2_in.AS_36_writeaddr(L3PHIBn1),
      AS_L3PHIBin_din       => f2_in.AS_36_din(L3PHIBn1),
      AS_L3PHICin_wea       => f2_in.AS_36_wea(L3PHICn1),
      AS_L3PHICin_writeaddr => f2_in.AS_36_writeaddr(L3PHICn1),
      AS_L3PHICin_din       => f2_in.AS_36_din(L3PHICn1),
      AS_L3PHIDin_wea       => f2_in.AS_36_wea(L3PHIDn1),
      AS_L3PHIDin_writeaddr => f2_in.AS_36_writeaddr(L3PHIDn1),
      AS_L3PHIDin_din       => f2_in.AS_36_din(L3PHIDn1),
      AS_L4PHIAin_wea       => f2_in.AS_36_wea(L4PHIAn1),
      AS_L4PHIAin_writeaddr => f2_in.AS_36_writeaddr(L4PHIAn1),
      AS_L4PHIAin_din       => f2_in.AS_36_din(L4PHIAn1),
      AS_L4PHIBin_wea       => f2_in.AS_36_wea(L4PHIBn1),
      AS_L4PHIBin_writeaddr => f2_in.AS_36_writeaddr(L4PHIBn1),
      AS_L4PHIBin_din       => f2_in.AS_36_din(L4PHIBn1),
      AS_L4PHICin_wea       => f2_in.AS_36_wea(L4PHICn1),
      AS_L4PHICin_writeaddr => f2_in.AS_36_writeaddr(L4PHICn1),
      AS_L4PHICin_din       => f2_in.AS_36_din(L4PHICn1),
      AS_L4PHIDin_wea       => f2_in.AS_36_wea(L4PHIDn1),
      AS_L4PHIDin_writeaddr => f2_in.AS_36_writeaddr(L4PHIDn1),
      AS_L4PHIDin_din       => f2_in.AS_36_din(L4PHIDn1),
      AS_L5PHIAin_wea       => f2_in.AS_36_wea(L5PHIAn1),
      AS_L5PHIAin_writeaddr => f2_in.AS_36_writeaddr(L5PHIAn1),
      AS_L5PHIAin_din       => f2_in.AS_36_din(L5PHIAn1),
      AS_L5PHIBin_wea       => f2_in.AS_36_wea(L5PHIBn1),
      AS_L5PHIBin_writeaddr => f2_in.AS_36_writeaddr(L5PHIBn1),
      AS_L5PHIBin_din       => f2_in.AS_36_din(L5PHIBn1),
      AS_L5PHICin_wea       => f2_in.AS_36_wea(L5PHICn1),
      AS_L5PHICin_writeaddr => f2_in.AS_36_writeaddr(L5PHICn1),
      AS_L5PHICin_din       => f2_in.AS_36_din(L5PHICn1),
      AS_L5PHIDin_wea       => f2_in.AS_36_wea(L5PHIDn1),
      AS_L5PHIDin_writeaddr => f2_in.AS_36_writeaddr(L5PHIDn1),
      AS_L5PHIDin_din       => f2_in.AS_36_din(L5PHIDn1),
      AS_L6PHIAin_wea       => f2_in.AS_36_wea(L6PHIAn1),
      AS_L6PHIAin_writeaddr => f2_in.AS_36_writeaddr(L6PHIAn1),
      AS_L6PHIAin_din       => f2_in.AS_36_din(L6PHIAn1),
      AS_L6PHIBin_wea       => f2_in.AS_36_wea(L6PHIBn1),
      AS_L6PHIBin_writeaddr => f2_in.AS_36_writeaddr(L6PHIBn1),
      AS_L6PHIBin_din       => f2_in.AS_36_din(L6PHIBn1),
      AS_L6PHICin_wea       => f2_in.AS_36_wea(L6PHICn1),
      AS_L6PHICin_writeaddr => f2_in.AS_36_writeaddr(L6PHICn1),
      AS_L6PHICin_din       => f2_in.AS_36_din(L6PHICn1),
      AS_L6PHIDin_wea       => f2_in.AS_36_wea(L6PHIDn1),
      AS_L6PHIDin_writeaddr => f2_in.AS_36_writeaddr(L6PHIDn1),
      AS_L6PHIDin_din       => f2_in.AS_36_din(L6PHIDn1),
      AS_D1PHIAin_wea       => f2_in.AS_36_wea(D1PHIAn1),
      AS_D1PHIAin_writeaddr => f2_in.AS_36_writeaddr(D1PHIAn1),
      AS_D1PHIAin_din       => f2_in.AS_36_din(D1PHIAn1),
      AS_D1PHIBin_wea       => f2_in.AS_36_wea(D1PHIBn1),
      AS_D1PHIBin_writeaddr => f2_in.AS_36_writeaddr(D1PHIBn1),
      AS_D1PHIBin_din       => f2_in.AS_36_din(D1PHIBn1),
      AS_D1PHICin_wea       => f2_in.AS_36_wea(D1PHICn1),
      AS_D1PHICin_writeaddr => f2_in.AS_36_writeaddr(D1PHICn1),
      AS_D1PHICin_din       => f2_in.AS_36_din(D1PHICn1),
      AS_D1PHIDin_wea       => f2_in.AS_36_wea(D1PHIDn1),
      AS_D1PHIDin_writeaddr => f2_in.AS_36_writeaddr(D1PHIDn1),
      AS_D1PHIDin_din       => f2_in.AS_36_din(D1PHIDn1),
      AS_D2PHIAin_wea       => f2_in.AS_36_wea(D2PHIAn1),
      AS_D2PHIAin_writeaddr => f2_in.AS_36_writeaddr(D2PHIAn1),
      AS_D2PHIAin_din       => f2_in.AS_36_din(D2PHIAn1),
      AS_D2PHIBin_wea       => f2_in.AS_36_wea(D2PHIBn1),
      AS_D2PHIBin_writeaddr => f2_in.AS_36_writeaddr(D2PHIBn1),
      AS_D2PHIBin_din       => f2_in.AS_36_din(D2PHIBn1),
      AS_D2PHICin_wea       => f2_in.AS_36_wea(D2PHICn1),
      AS_D2PHICin_writeaddr => f2_in.AS_36_writeaddr(D2PHICn1),
      AS_D2PHICin_din       => f2_in.AS_36_din(D2PHICn1),
      AS_D2PHIDin_wea       => f2_in.AS_36_wea(D2PHIDn1),
      AS_D2PHIDin_writeaddr => f2_in.AS_36_writeaddr(D2PHIDn1),
      AS_D2PHIDin_din       => f2_in.AS_36_din(D2PHIDn1),
      AS_D3PHIAin_wea       => f2_in.AS_36_wea(D3PHIAn1),
      AS_D3PHIAin_writeaddr => f2_in.AS_36_writeaddr(D3PHIAn1),
      AS_D3PHIAin_din       => f2_in.AS_36_din(D3PHIAn1),
      AS_D3PHIBin_wea       => f2_in.AS_36_wea(D3PHIBn1),
      AS_D3PHIBin_writeaddr => f2_in.AS_36_writeaddr(D3PHIBn1),
      AS_D3PHIBin_din       => f2_in.AS_36_din(D3PHIBn1),
      AS_D3PHICin_wea       => f2_in.AS_36_wea(D3PHICn1),
      AS_D3PHICin_writeaddr => f2_in.AS_36_writeaddr(D3PHICn1),
      AS_D3PHICin_din       => f2_in.AS_36_din(D3PHICn1),
      AS_D3PHIDin_wea       => f2_in.AS_36_wea(D3PHIDn1),
      AS_D3PHIDin_writeaddr => f2_in.AS_36_writeaddr(D3PHIDn1),
      AS_D3PHIDin_din       => f2_in.AS_36_din(D3PHIDn1),
      AS_D4PHIAin_wea       => f2_in.AS_36_wea(D4PHIAn1),
      AS_D4PHIAin_writeaddr => f2_in.AS_36_writeaddr(D4PHIAn1),
      AS_D4PHIAin_din       => f2_in.AS_36_din(D4PHIAn1),
      AS_D4PHIBin_wea       => f2_in.AS_36_wea(D4PHIBn1),
      AS_D4PHIBin_writeaddr => f2_in.AS_36_writeaddr(D4PHIBn1),
      AS_D4PHIBin_din       => f2_in.AS_36_din(D4PHIBn1),
      AS_D4PHICin_wea       => f2_in.AS_36_wea(D4PHICn1),
      AS_D4PHICin_writeaddr => f2_in.AS_36_writeaddr(D4PHICn1),
      AS_D4PHICin_din       => f2_in.AS_36_din(D4PHICn1),
      AS_D4PHIDin_wea       => f2_in.AS_36_wea(D4PHIDn1),
      AS_D4PHIDin_writeaddr => f2_in.AS_36_writeaddr(D4PHIDn1),
      AS_D4PHIDin_din       => f2_in.AS_36_din(D4PHIDn1),
      AS_D5PHIAin_wea       => f2_in.AS_36_wea(D5PHIAn1),
      AS_D5PHIAin_writeaddr => f2_in.AS_36_writeaddr(D5PHIAn1),
      AS_D5PHIAin_din       => f2_in.AS_36_din(D5PHIAn1),
      AS_D5PHIBin_wea       => f2_in.AS_36_wea(D5PHIBn1),
      AS_D5PHIBin_writeaddr => f2_in.AS_36_writeaddr(D5PHIBn1),
      AS_D5PHIBin_din       => f2_in.AS_36_din(D5PHIBn1),
      AS_D5PHICin_wea       => f2_in.AS_36_wea(D5PHICn1),
      AS_D5PHICin_writeaddr => f2_in.AS_36_writeaddr(D5PHICn1),
      AS_D5PHICin_din       => f2_in.AS_36_din(D5PHICn1),
      AS_D5PHIDin_wea       => f2_in.AS_36_wea(D5PHIDn1),
      AS_D5PHIDin_writeaddr => f2_in.AS_36_writeaddr(D5PHIDn1),
      AS_D5PHIDin_din       => f2_in.AS_36_din(D5PHIDn1),
      MPAR_L1L2ABCin_wea        => f2_in.MPAR_73_wea(L1L2ABC),
      MPAR_L1L2ABCin_writeaddr  => f2_in.MPAR_73_writeaddr(L1L2ABC),
      MPAR_L1L2ABCin_din        => f2_in.MPAR_73_din(L1L2ABC),
      MPAR_L1L2DEin_wea         => f2_in.MPAR_73_wea(L1L2DE),
      MPAR_L1L2DEin_writeaddr   => f2_in.MPAR_73_writeaddr(L1L2DE),
      MPAR_L1L2DEin_din         => f2_in.MPAR_73_din(L1L2DE),
      MPAR_L1L2Fin_wea          => f2_in.MPAR_73_wea(L1L2F),
      MPAR_L1L2Fin_writeaddr    => f2_in.MPAR_73_writeaddr(L1L2F),
      MPAR_L1L2Fin_din          => f2_in.MPAR_73_din(L1L2F),
      MPAR_L1L2Gin_wea          => f2_in.MPAR_73_wea(L1L2G),
      MPAR_L1L2Gin_writeaddr    => f2_in.MPAR_73_writeaddr(L1L2G),
      MPAR_L1L2Gin_din          => f2_in.MPAR_73_din(L1L2G),
      MPAR_L1L2HIin_wea         => f2_in.MPAR_73_wea(L1L2HI),
      MPAR_L1L2HIin_writeaddr   => f2_in.MPAR_73_writeaddr(L1L2HI),
      MPAR_L1L2HIin_din         => f2_in.MPAR_73_din(L1L2HI),
      MPAR_L1L2JKLin_wea        => f2_in.MPAR_73_wea(L1L2JKL),
      MPAR_L1L2JKLin_writeaddr  => f2_in.MPAR_73_writeaddr(L1L2JKL),
      MPAR_L1L2JKLin_din        => f2_in.MPAR_73_din(L1L2JKL),
      MPAR_L2L3ABCDin_wea       => f2_in.MPAR_73_wea(L2L3ABCD),
      MPAR_L2L3ABCDin_writeaddr => f2_in.MPAR_73_writeaddr(L2L3ABCD),
      MPAR_L2L3ABCDin_din       => f2_in.MPAR_73_din(L2L3ABCD),
      MPAR_L3L4ABin_wea         => f2_in.MPAR_73_wea(L3L4AB),
      MPAR_L3L4ABin_writeaddr   => f2_in.MPAR_73_writeaddr(L3L4AB),
      MPAR_L3L4ABin_din         => f2_in.MPAR_73_din(L3L4AB),
      MPAR_L3L4CDin_wea         => f2_in.MPAR_73_wea(L3L4CD),
      MPAR_L3L4CDin_writeaddr   => f2_in.MPAR_73_writeaddr(L3L4CD),
      MPAR_L3L4CDin_din         => f2_in.MPAR_73_din(L3L4CD),
      MPAR_L5L6ABCDin_wea       => f2_in.MPAR_73_wea(L5L6ABCD),
      MPAR_L5L6ABCDin_writeaddr => f2_in.MPAR_73_writeaddr(L5L6ABCD),
      MPAR_L5L6ABCDin_din       => f2_in.MPAR_73_din(L5L6ABCD),
      MPAR_D1D2ABCDin_wea       => f2_in.MPAR_73_wea(D1D2ABCD),
      MPAR_D1D2ABCDin_writeaddr => f2_in.MPAR_73_writeaddr(D1D2ABCD),
      MPAR_D1D2ABCDin_din       => f2_in.MPAR_73_din(D1D2ABCD),
      MPAR_D3D4ABCDin_wea       => f2_in.MPAR_73_wea(D3D4ABCD),
      MPAR_D3D4ABCDin_writeaddr => f2_in.MPAR_73_writeaddr(D3D4ABCD),
      MPAR_D3D4ABCDin_din       => f2_in.MPAR_73_din(D3D4ABCD),
      MPAR_L1D1ABCDin_wea       => f2_in.MPAR_73_wea(L1D1ABCD),
      MPAR_L1D1ABCDin_writeaddr => f2_in.MPAR_73_writeaddr(L1D1ABCD),
      MPAR_L1D1ABCDin_din       => f2_in.MPAR_73_din(L1D1ABCD),
      MPAR_L1D1EFGHin_wea       => f2_in.MPAR_73_wea(L1D1EFGH),
      MPAR_L1D1EFGHin_writeaddr => f2_in.MPAR_73_writeaddr(L1D1EFGH),
      MPAR_L1D1EFGHin_din       => f2_in.MPAR_73_din(L1D1EFGH),
      MPAR_L2D1ABCDin_wea       => f2_in.MPAR_73_wea(L2D1ABCD),
      MPAR_L2D1ABCDin_writeaddr => f2_in.MPAR_73_writeaddr(L2D1ABCD),
      MPAR_L2D1ABCDin_din       => f2_in.MPAR_73_din(L2D1ABCD),
      TW_AAAA_stream_AV_din     => f2_out.TW_113_stream_AV_din(AAAA),
      TW_AAAA_stream_A_full_neg => TW_113_stream_A_full_neg(AAAA),
      TW_AAAA_stream_A_write    => f2_out.TW_113_stream_A_write(AAAA),
      TW_BBBB_stream_AV_din     => f2_out.TW_113_stream_AV_din(BBBB),
      TW_BBBB_stream_A_full_neg => TW_113_stream_A_full_neg(BBBB),
      TW_BBBB_stream_A_write    => f2_out.TW_113_stream_A_write(BBBB),
      DW_AAAA_D1_stream_AV_din     => f2_out.DW_49_stream_AV_din(AAAA_D1),
      DW_AAAA_D1_stream_A_full_neg => DW_49_stream_A_full_neg(AAAA_D1),
      DW_AAAA_D1_stream_A_write    => f2_out.DW_49_stream_A_write(AAAA_D1),
      DW_AAAA_D2_stream_AV_din     => f2_out.DW_49_stream_AV_din(AAAA_D2),
      DW_AAAA_D2_stream_A_full_neg => DW_49_stream_A_full_neg(AAAA_D2),
      DW_AAAA_D2_stream_A_write    => f2_out.DW_49_stream_A_write(AAAA_D2),
      DW_AAAA_D3_stream_AV_din     => f2_out.DW_49_stream_AV_din(AAAA_D3),
      DW_AAAA_D3_stream_A_full_neg => DW_49_stream_A_full_neg(AAAA_D3),
      DW_AAAA_D3_stream_A_write    => f2_out.DW_49_stream_A_write(AAAA_D3),
      DW_AAAA_D4_stream_AV_din     => f2_out.DW_49_stream_AV_din(AAAA_D4),
      DW_AAAA_D4_stream_A_full_neg => DW_49_stream_A_full_neg(AAAA_D4),
      DW_AAAA_D4_stream_A_write    => f2_out.DW_49_stream_A_write(AAAA_D4),
      DW_AAAA_D5_stream_AV_din     => f2_out.DW_49_stream_AV_din(AAAA_D5),
      DW_AAAA_D5_stream_A_full_neg => DW_49_stream_A_full_neg(AAAA_D5),
      DW_AAAA_D5_stream_A_write    => f2_out.DW_49_stream_A_write(AAAA_D5),
      DW_BBBB_D1_stream_AV_din     => f2_out.DW_49_stream_AV_din(BBBB_D1),
      DW_BBBB_D1_stream_A_full_neg => DW_49_stream_A_full_neg(BBBB_D1),
      DW_BBBB_D1_stream_A_write    => f2_out.DW_49_stream_A_write(BBBB_D1),
      DW_BBBB_D2_stream_AV_din     => f2_out.DW_49_stream_AV_din(BBBB_D2),
      DW_BBBB_D2_stream_A_full_neg => DW_49_stream_A_full_neg(BBBB_D2),
      DW_BBBB_D2_stream_A_write    => f2_out.DW_49_stream_A_write(BBBB_D2),
      DW_BBBB_D3_stream_AV_din     => f2_out.DW_49_stream_AV_din(BBBB_D3),
      DW_BBBB_D3_stream_A_full_neg => DW_49_stream_A_full_neg(BBBB_D3),
      DW_BBBB_D3_stream_A_write    => f2_out.DW_49_stream_A_write(BBBB_D3),
      DW_BBBB_D4_stream_AV_din     => f2_out.DW_49_stream_AV_din(BBBB_D4),
      DW_BBBB_D4_stream_A_full_neg => DW_49_stream_A_full_neg(BBBB_D4),
      DW_BBBB_D4_stream_A_write    => f2_out.DW_49_stream_A_write(BBBB_D4),
      DW_BBBB_D5_stream_AV_din     => f2_out.DW_49_stream_AV_din(BBBB_D5),
      DW_BBBB_D5_stream_A_full_neg => DW_49_stream_A_full_neg(BBBB_D5),
      DW_BBBB_D5_stream_A_write    => f2_out.DW_49_stream_A_write(BBBB_D5),
      BW_AAAA_L1_stream_AV_din     => f2_out.BW_46_stream_AV_din(AAAA_L1),
      BW_AAAA_L1_stream_A_full_neg => BW_46_stream_A_full_neg(AAAA_L1),
      BW_AAAA_L1_stream_A_write    => f2_out.BW_46_stream_A_write(AAAA_L1),
      BW_AAAA_L2_stream_AV_din     => f2_out.BW_46_stream_AV_din(AAAA_L2),
      BW_AAAA_L2_stream_A_full_neg => BW_46_stream_A_full_neg(AAAA_L2),
      BW_AAAA_L2_stream_A_write    => f2_out.BW_46_stream_A_write(AAAA_L2),
      BW_AAAA_L3_stream_AV_din     => f2_out.BW_46_stream_AV_din(AAAA_L3),
      BW_AAAA_L3_stream_A_full_neg => BW_46_stream_A_full_neg(AAAA_L3),
      BW_AAAA_L3_stream_A_write    => f2_out.BW_46_stream_A_write(AAAA_L3),
      BW_AAAA_L4_stream_AV_din     => f2_out.BW_46_stream_AV_din(AAAA_L4),
      BW_AAAA_L4_stream_A_full_neg => BW_46_stream_A_full_neg(AAAA_L4),
      BW_AAAA_L4_stream_A_write    => f2_out.BW_46_stream_A_write(AAAA_L4),
      BW_AAAA_L5_stream_AV_din     => f2_out.BW_46_stream_AV_din(AAAA_L5),
      BW_AAAA_L5_stream_A_full_neg => BW_46_stream_A_full_neg(AAAA_L5),
      BW_AAAA_L5_stream_A_write    => f2_out.BW_46_stream_A_write(AAAA_L5),
      BW_AAAA_L6_stream_AV_din     => f2_out.BW_46_stream_AV_din(AAAA_L6),
      BW_AAAA_L6_stream_A_full_neg => BW_46_stream_A_full_neg(AAAA_L6),
      BW_AAAA_L6_stream_A_write    => f2_out.BW_46_stream_A_write(AAAA_L6),
      BW_BBBB_L1_stream_AV_din     => f2_out.BW_46_stream_AV_din(BBBB_L1),
      BW_BBBB_L1_stream_A_full_neg => BW_46_stream_A_full_neg(BBBB_L1),
      BW_BBBB_L1_stream_A_write    => f2_out.BW_46_stream_A_write(BBBB_L1),
      BW_BBBB_L2_stream_AV_din     => f2_out.BW_46_stream_AV_din(BBBB_L2),
      BW_BBBB_L2_stream_A_full_neg => BW_46_stream_A_full_neg(BBBB_L2),
      BW_BBBB_L2_stream_A_write    => f2_out.BW_46_stream_A_write(BBBB_L2),
      BW_BBBB_L3_stream_AV_din     => f2_out.BW_46_stream_AV_din(BBBB_L3),
      BW_BBBB_L3_stream_A_full_neg => BW_46_stream_A_full_neg(BBBB_L3),
      BW_BBBB_L3_stream_A_write    => f2_out.BW_46_stream_A_write(BBBB_L3),
      BW_BBBB_L4_stream_AV_din     => f2_out.BW_46_stream_AV_din(BBBB_L4),
      BW_BBBB_L4_stream_A_full_neg => BW_46_stream_A_full_neg(BBBB_L4),
      BW_BBBB_L4_stream_A_write    => f2_out.BW_46_stream_A_write(BBBB_L4),
      BW_BBBB_L5_stream_AV_din     => f2_out.BW_46_stream_AV_din(BBBB_L5),
      BW_BBBB_L5_stream_A_full_neg => BW_46_stream_A_full_neg(BBBB_L5),
      BW_BBBB_L5_stream_A_write    => f2_out.BW_46_stream_A_write(BBBB_L5),
      BW_BBBB_L6_stream_AV_din     => f2_out.BW_46_stream_AV_din(BBBB_L6),
      BW_BBBB_L6_stream_A_full_neg => BW_46_stream_A_full_neg(BBBB_L6),
      BW_BBBB_L6_stream_A_write    => f2_out.BW_46_stream_A_write(BBBB_L6)
      );

  f2_out_1 : entity work.tf_pipeline_slr_xing
    generic map (
      NUM_SLR => 2,
      EMP_WRAPPER => true
      )
    port map (
      clk => clk,

      f2_output_in => f2_out,

      f2_output_out.PC_bx_out => PC_bx_out,
      f2_output_out.PC_bx_out_vld => PC_bx_out_vld,
      f2_output_out.PC_done => PC_done,
      f2_output_out.TB_bx_out => TB_bx_out,
      f2_output_out.TB_bx_out_vld => TB_bx_out_vld,
      f2_output_out.TB_done => TB_done,
      f2_output_out.TB_last_track => TB_last_track,
      f2_output_out.TB_last_track_vld => TB_last_track_vld,
      f2_output_out.TW_113_stream_AV_din => TW_113_stream_AV_din,
      f2_output_out.TW_113_stream_A_write => TW_113_stream_A_write,
      f2_output_out.DW_49_stream_AV_din => DW_49_stream_AV_din,
      f2_output_out.DW_49_stream_A_write => DW_49_stream_A_write,
      f2_output_out.BW_46_stream_AV_din => BW_46_stream_AV_din,
      f2_output_out.BW_46_stream_A_write => BW_46_stream_A_write
      );

end architecture rtl;
