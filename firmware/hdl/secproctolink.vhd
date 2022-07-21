-------------------------------------------------------------------------------
-- Title      : sector processor to link
-- Project    : 
-------------------------------------------------------------------------------
-- File       : secproctolink.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-07-13
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
-- 2022-07-13  1.0      fmarini Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_misc.all;
use work.emp_data_types.all;
use work.emp_device_decl.all;
use work.emp_ttc_decl.all;
use work.tf_pkg.all;
use work.memUtil_pkg.all;
library surf;
use surf.StdRtlPkg.all;
use surf.ArbiterPkg.all;
use surf.AxiStreamPkg.all;

entity secproctolink is
  port (
    clk_i                   : in  std_logic;
    TW_84_stream_data_i     : in  t_arr_TW_84_DATA;
    TW_84_stream_write_i    : in  t_arr_TW_84_1b;
    TW_84_stream_full_neg_o : out t_arr_TW_84_1b;
    BW_46_stream_data_i     : in  t_arr_BW_46_DATA;
    BW_46_stream_write_i    : in  t_arr_BW_46_1b;
    BW_46_stream_full_neg_i : out t_arr_BW_46_1b;
    dout_o                  : out ldata(4 * N_REGION - 1 downto 0)
    );
end entity secproctolink;

architecture rtl of secproctolink is

  constant SMALL_BIT_CONFIG_G : AxiStreamConfigType := (
    TSTRB_EN_C    => false,
    TDATA_BYTES_C => 8,
    TDEST_BITS_C  => 2,
    TID_BITS_C    => 0,
    TKEEP_MODE_C  => TKEEP_COMP_C,
    TUSER_BITS_C  => 2,
    TUSER_MODE_C  => TUSER_FIRST_LAST_C
    );
  constant BIG_BIT_CONFIG_G : AxiStreamConfigType := (
    TSTRB_EN_C    => false,
    TDATA_BYTES_C => 40,
    TDEST_BITS_C  => 2,
    TID_BITS_C    => 0,
    TKEEP_MODE_C  => TKEEP_COMP_C,
    TUSER_BITS_C  => 2,
    TUSER_MODE_C  => TUSER_FIRST_LAST_C
    );

  signal s_fifo_valid     : std_logic;
  signal s_fifo_valid_vec : std_logic_vector(4 downto 0);
  signal s_fifo_ready     : std_logic;
  signal s_fifo_data      : std_logic_vector(319 downto 0);
  signal s_sAxisMaster_sp : AxiStreamMasterType;
  signal s_sAxisSlave_sp  : AxiStreamSlaveType;
  signal s_mAxisMaster_l  : AxiStreamMasterType;
  signal s_mAxisSlave_l   : AxiStreamSlaveType;

begin  -- architecture rtl

  -----------------------------------------------------------------------------
  -- FIFO input array
  -----------------------------------------------------------------------------
  s_fifo_valid_vec                 <= TW_84_stream_write_i(L1L2) & BW_46_stream_write_i(L1L2_L3) & BW_46_stream_write_i(L1L2_L4) & BW_46_stream_write_i(L1L2_L5) & BW_46_stream_write_i(L1L2_L6);
  s_fifo_valid                     <= or_reduce(s_fifo_valid_vec);
  TW_84_stream_full_neg_o(L1L2)    <= s_fifo_ready;
  BW_46_stream_full_neg_i(L1L2_L3) <= s_fifo_ready;
  BW_46_stream_full_neg_i(L1L2_L4) <= s_fifo_ready;
  BW_46_stream_full_neg_i(L1L2_L5) <= s_fifo_ready;
  BW_46_stream_full_neg_i(L1L2_L6) <= s_fifo_ready;
  s_fifo_data                      <= x"805A0123456" &
                 TW_84_stream_data_i(L1L2) &
                 "00" & BW_46_stream_data_i(L1L2_L3) &
                 "00" & BW_46_stream_data_i(L1L2_L4) &
                 "00" & BW_46_stream_data_i(L1L2_L5) &
                 "00" & BW_46_stream_data_i(L1L2_L6);

  -----------------------------------------------------------------------------
  -- FIFO
  -----------------------------------------------------------------------------
  s_sAxisMaster_sp.tData(319 downto 0)                                 <= s_fifo_data;
  s_sAxisMaster_sp.tData(s_sAxisMaster_sp.tData'length - 1 downto 320) <= (others => '0');
  s_sAxisMaster_sp.tValid                                              <= s_fifo_valid;
  s_sAxisMaster_sp.tKeep                                               <= x"000000FFFFFFFFFF";
  s_fifo_ready                                                         <= s_sAxisSlave_sp.tReady;
  dout_o(0).data                                                       <= s_mAxisMaster_l.tData(63 downto 0);
  dout_o(0).valid                                                      <= s_mAxisMaster_l.tValid;
  dout_o(0).strobe                                                     <= '1';
  s_mAxisSlave_l.tReady                                                <= '1';

  AxiStreamFifoV2_1 : entity surf.AxiStreamFifoV2
    generic map (
      LITTLE_ENDIAN_G     => false,
      GEN_SYNC_FIFO_G     => true,
      FIFO_ADDR_WIDTH_G   => 4,
      -- SYNTH_MODE_G           => SYNTH_MODE_G,
      -- MEMORY_TYPE_G          => MEMORY_TYPE_G,
      SLAVE_AXI_CONFIG_G  => BIG_BIT_CONFIG_G,
      MASTER_AXI_CONFIG_G => SMALL_BIT_CONFIG_G
      )
    port map (
      sAxisClk    => clk_i,
      sAxisRst    => '0',
      sAxisMaster => s_sAxisMaster_sp,
      sAxisSlave  => s_sAxisSlave_sp,
      sAxisCtrl   => open,
      -- fifoPauseThresh => fifoPauseThresh,
      -- fifoWrCnt       => fifoWrCnt,
      -- fifoFull        => fifoFull,
      mAxisClk    => clk_i,
      mAxisRst    => '0',
      mAxisMaster => s_mAxisMaster_l,
      mAxisSlave  => s_mAxisSlave_l,
      mTLastTUser => open
      );



end architecture rtl;
