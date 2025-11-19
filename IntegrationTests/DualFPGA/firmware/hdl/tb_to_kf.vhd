-------------------------------------------------------------------------------
-- Title      : tb to kf
-- Project    : 
-------------------------------------------------------------------------------
-- File       : tb_to_kf.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-11-02
-- Last update: 2022-11-03
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: Module to convert between TB output format and KF input format.
-------------------------------------------------------------------------------
-- Copyright (c) 2022 University of Colorado Boulder
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2022-11-02  1.0      fmarini Created
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;
use work.tf_interface_pkg.all;

use work.tf_data_types.all;
use work.tf_data_formats.all;
use work.tf_tools.all;
use work.tf_config.all;

entity tb_to_kf is
  port (
    clk240         : in  std_logic;
    clk360         : in  std_logic;
    rst            : in  std_logic;
    TW_113_data_i  : in  t_arr_TW_113_data;
    TW_113_valid_i : in  t_arr_TW_113_1b;
    DW_49_data_i   : in  t_arr_DW_49_DATA;
    DW_49_valid_i  : in  t_arr_DW_49_1b;
    BW_46_data_i   : in  t_arr_BW_46_DATA;
    BW_46_valid_i  : in  t_arr_BW_46_1b;
    kf_reset_i     : in  std_logic;
    packet_valid   : in  std_logic;
    tmpacket_o     : out t_packets(0 to tbNumSeedTypes - 1);
    tbtokf_o       : out t_tracksTB(0 to tbNumSeedTypes - 1)
    );
end entity tb_to_kf;

architecture rtl of tb_to_kf is

  constant widthTrackletLmap : natural := 33;
  constant widthTBInPhiRegion : natural := 3;
  constant widthTBOutPhiRegion : natural := 3;
  constant widthTBInIndex : natural := 7;
  constant widthTBOutIndex : natural := 7;
  constant nMaxTypeStubs : natural := 4;

  constant TW_valid_pos : natural := widthTBseedType + widthTBInPhiRegion
                                     + widthTBOutPhiRegion + widthTBInIndex 
                                     + widthTBOutIndex + widthTBinv2R 
                                     + widthTBphi0 + widthTBz0 + widthTBcot 
                                     + widthTrackletLmap;
  constant TW_seedtype_pos : natural := widthTBInPhiRegion
                                     + widthTBOutPhiRegion + widthTBInIndex 
                                     + widthTBOutIndex + widthTBinv2R 
                                     + widthTBphi0 + widthTBz0 + widthTBcot 
                                     + widthTrackletLmap;
  constant TW_inPhiRegion_pos : natural := widthTBOutPhiRegion + widthTBInIndex 
                                        + widthTBOutIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_outPhiRegion_pos : natural := widthTBInIndex 
                                        + widthTBOutIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_inIndex_pos : natural := widthTBOutIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_outIndex_pos : natural := widthTBinv2R + widthTBphi0 
                                        + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_inv2r_pos    : natural := widthTBphi0 + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_phi0_pos     : natural := widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_z0_pos       : natural := widthTBcot + widthTrackletLmap;
  constant TW_cot_pos      : natural := widthTrackletLmap;

  constant BW_valid_pos   : natural := widthTBtrackId + widthTBstubId 
                                       + widthsTBr(0) + widthsTBphi(0) 
                                       + widthsTBz(0);
  constant BW_trackid_pos : natural := widthTBstubId 
                                       + widthsTBr(0) + widthsTBphi(0) 
                                       + widthsTBz(0);
  constant BW_stubid_pos  : natural := widthsTBr(0) + widthsTBphi(0) 
                                       + widthsTBz(0);
  constant BW_r_pos       : natural := widthsTBphi(0) + widthsTBz(0);
  constant BW_phi_pos     : natural := widthsTBz(0);
  constant BW_z_pos       : natural := 0;

  constant DW_valid_pos   : natural := widthTBtrackId + widthTBstubId 
                                       + widthsTBr(2) + widthsTBphi(2) 
                                       + widthsTBz(2);
  constant DW_trackid_pos : natural := widthTBstubId 
                                       + widthsTBr(2) + widthsTBphi(2) 
                                       + widthsTBz(2);
  constant DW_stubid_pos  : natural := widthsTBr(2) + widthsTBphi(2) 
                                       + widthsTBz(2);
  constant DW_r_pos       : natural := widthsTBphi(2) + widthsTBz(2);
  constant DW_phi_pos     : natural := widthsTBz(2);
  constant DW_z_pos       : natural := 0;
  constant tb_latency     : natural := 570;
  constant tb_latency240  : natural := 378; --378?

  signal TW_113_data_pipe_2 : t_arr_TW_113_data;
  signal TW_113_valid_pipe_2 : t_arr_TW_113_1b;
  signal DW_49_data_pipe_2 : t_arr_DW_49_data;
  signal DW_49_valid_pipe_2 : t_arr_DW_49_1b;
  signal BW_46_data_pipe_2 : t_arr_BW_46_data;
  signal BW_46_valid_pipe_2 : t_arr_BW_46_1b;

  signal TW_113_data_pipe_1 : t_arr_TW_113_data;
  signal TW_113_valid_pipe_1 : t_arr_TW_113_1b;
  signal DW_49_data_pipe_1 : t_arr_DW_49_data;
  signal DW_49_valid_pipe_1 : t_arr_DW_49_1b;
  signal BW_46_data_pipe_1 : t_arr_BW_46_data;
  signal BW_46_valid_pipe_1 : t_arr_BW_46_1b;

  signal sr_packet : std_logic_vector(0 to tb_latency-1) := (others => '0');
  signal sr_reset  : std_logic_vector(0 to tb_latency240-1) := (others => '0');
  signal reset_start : std_logic := '0';
  signal reset_counter : integer range 0 to 107 := 0;
  signal start_evt : std_logic := '0';
  signal packet_start : std_logic := '0';
  signal packet_valid_prev : std_logic := '0';
  signal packet_valid_prev240 : std_logic := '0';
  signal evt_counter : integer range 0 to 161 := 0;
  signal bx_counter  : integer range 0 to 3564 := 0; --temp until input @360
  signal packet_int  : t_packets(0 to tbNumSeedTypes - 1) := (others => nulll);

  type t_arr_stub_DW is array(0 to tbMaxNumProjectionLayers - 1) of enum_DW_49;
  type t_arr_stub_BW is array(0 to tbMaxNumProjectionLayers - 1) of enum_BW_46;
  type t_arr_seed_arr_stub_DW is array(integer range 0 to 7) of t_arr_stub_DW;
  type t_arr_seed_arr_stub_BW is array(integer range 0 to 7) of t_arr_stub_BW;

  --constants used to look up which barrel/disk stubs should be assigned to which seed type
  constant disk_stub_lut : t_arr_seed_arr_stub_DW := (
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4), --L1L2
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4), --L2L3
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,BBBB_D1,BBBB_D2,AAAA_D1,AAAA_D1), --L3L4
      (AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1), --L5L6
      (AAAA_D1,AAAA_D1,BBBB_D3,BBBB_D4,BBBB_D5,AAAA_D1,AAAA_D1,AAAA_D1), --D1D2
      (AAAA_D1,BBBB_D1,BBBB_D2,BBBB_D5,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1), --D3D4
      (BBBB_D2,BBBB_D3,BBBB_D4,BBBB_D5,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1), --L1D1
      (AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4,AAAA_D1,AAAA_D1,AAAA_D1,AAAA_D1)  --L2D1
      );

  constant barrel_stub_lut : t_arr_seed_arr_stub_BW := (
      (AAAA_L3,AAAA_L4,AAAA_L5,AAAA_L6,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L1L2
      (AAAA_L1,AAAA_L4,AAAA_L5,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L2L3
      (BBBB_L1,BBBB_L2,BBBB_L5,BBBB_L6,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L3L4
      (AAAA_L1,AAAA_L2,AAAA_L3,AAAA_L4,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L5L6
      (BBBB_L1,BBBB_L2,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --D1D2
      (BBBB_L1,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --D3D4
      (AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3), --L1D1
      (AAAA_L1,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3,AAAA_L3)  --L2D1
      );

begin  -- architecture rtl

  --process that propagates packet signals; currently acts as CDC from 240 to
  --360, but will be entirely in 360 once input is updated to 360 MHz
  --in EMP simulation with frame 6 convention (first 6 frames empty), the
  --240 MHz edge with start of orbit is aligned with an edge of 360 MHz, so
  --we can sample on this edge and the next one, but we should skip the third
  --This probably is not the case in hardware (depends on FPGA1 latency, we
  --can adjust pipeline stages once we measure when start_of_orbit arrives)
  p_packet : process (clk360) is
  begin
    if rising_edge(clk360) then
      --in sim, valid only changes on common edge, so always safe to sample
      packet_valid_prev <= packet_valid; 
      sr_packet <= '0' & sr_packet(sr_packet'low to sr_packet'high - 1);
      if packet_valid = '1' and packet_valid_prev = '0' then
        sr_packet(0) <= '1';
      end if;

      --TODO need false path constraint or similar for reset to cross domain
      if rst = '1' then
        packet_start <= '0';
        evt_counter <= 0;
        bx_counter <= 0;
      elsif packet_start = '0' and sr_packet(sr_packet'high - 1) = '1' then
        evt_counter <= 0;
        packet_start <= '1';
      elsif packet_start = '1' and evt_counter = 161 then
        evt_counter <= 0;
        if bx_counter = 3563 then
          bx_counter <= 0;
        else
          bx_counter <= bx_counter + 1;
        end if;
      elsif packet_start = '1' then
        evt_counter <= evt_counter + 1;
      end if;

      for i in 0 to (tbNumSeedTypes-1) loop
        if packet_start = '1' then

          if evt_counter = 0 and bx_counter = 0 then
            packet_int(i).start_of_orbit <= '1';
          else
            packet_int(i).start_of_orbit <= '0';
          end if;

          if evt_counter < 156 then
            packet_int(i).valid <= '1';
          else 
            packet_int(i).valid <= '0';
          end if;

        end if;
      end loop;
    end if;
  end process p_packet;
  tmpacket_o <= packet_int;

  --process that formats TB data for TM
  p_tf_to_kf : process (clk240) is

    variable TW_idx : natural range 0 to 7;
    variable proj_idx : natural range 0 to 15;
    variable iBW_enum : enum_BW_46;
    variable iDW_enum : enum_DW_49;

  begin -- process p_tf_to_kf
    if rising_edge(clk240) then          -- rising clock edge

      -- test logic for reset
      packet_valid_prev240 <= packet_valid; 
      sr_reset <= '0' & sr_reset(sr_reset'low to sr_reset'high - 1);
      if packet_valid = '1' and packet_valid_prev240 = '0' then
        sr_reset(0) <= '1';
      end if;
      if rst = '1' then
        reset_counter <= 0;
        reset_start <= '0';
        start_evt <= '0';
      elsif reset_start = '0' and sr_reset(sr_reset'high -1) = '1' then
        reset_start <= '1';
        start_evt <= '1';
      elsif reset_start = '1' and reset_counter = 107 then
        reset_counter <= 0;
        start_evt <= '1';
      elsif reset_start = '1' then
        reset_counter <= reset_counter + 1;
        start_evt <= '0';
      end if;

      -- pipeline input
      TW_113_data_pipe_2 <= TW_113_data_pipe_1;
      TW_113_data_pipe_1 <= TW_113_data_i;
      TW_113_valid_pipe_2 <= TW_113_valid_pipe_1;
      TW_113_valid_pipe_1 <= TW_113_valid_i;
      DW_49_data_pipe_2 <= DW_49_data_pipe_1;
      DW_49_data_pipe_1 <= DW_49_data_i;
      DW_49_valid_pipe_2 <= DW_49_valid_pipe_1;
      DW_49_valid_pipe_1 <= DW_49_valid_i;
      BW_46_data_pipe_2 <= BW_46_data_pipe_1;
      BW_46_data_pipe_1 <= BW_46_data_i;
      BW_46_valid_pipe_2 <= BW_46_valid_pipe_1;
      BW_46_valid_pipe_1 <= BW_46_valid_i;

      --initialize all links to null values by default
      for i in 0 to (tbNumSeedTypes-1) loop
        tbtokf_o(i)            <= nulll;
        --tbtokf_o(i).meta.reset <= kf_reset_i;
        tbtokf_o(i).meta.reset <= start_evt;
      end loop;

      --set relevant links to non-null values if valid output from TB
      --NB this style of loop not recommended for synthesis, but used elsewhere
      for i in TW_113_data_pipe_2'range loop 
        TW_idx := to_integer(unsigned(TW_113_data_pipe_2(i)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos)));

        if (TW_113_valid_pipe_2(i) = '1') and (TW_113_data_pipe_2(i)(TW_valid_pos) = '1') then
          
          tbtokf_o(TW_idx).meta.valid     <= TW_113_data_pipe_2(i)(TW_valid_pos);
          tbtokf_o(TW_idx).track.seedtype <= TW_113_data_pipe_2(i)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos);
          tbtokf_o(TW_idx).track.inv2R    <= TW_113_data_pipe_2(i)(widthTBinv2R - 1 + TW_inv2r_pos downto TW_inv2r_pos);
          tbtokf_o(TW_idx).track.phi0     <= TW_113_data_pipe_2(i)(widthTBphi0 - 1 + TW_phi0_pos downto TW_phi0_pos);
          tbtokf_o(TW_idx).track.z0       <= TW_113_data_pipe_2(i)(widthTBz0 - 1 + TW_z0_pos downto TW_z0_pos);
          tbtokf_o(TW_idx).track.cot      <= TW_113_data_pipe_2(i)(widthTBcot - 1 + TW_cot_pos downto TW_cot_pos);

          tbtokf_o(TW_idx).seeds(0)       <= TW_113_data_pipe_2(i)(widthTBInPhiRegion - 1 + TW_inPhiRegion_pos downto TW_inPhiRegion_pos) & TW_113_data_pipe_2(i)(widthTBInIndex - 1 + TW_inIndex_pos downto TW_inIndex_pos);
          tbtokf_o(TW_idx).seeds(1)       <= TW_113_data_pipe_2(i)(widthTBOutPhiRegion - 1 + TW_outPhiRegion_pos downto TW_outPhiRegion_pos) & TW_113_data_pipe_2(i)(widthTBOutIndex - 1 + TW_outIndex_pos downto TW_outIndex_pos);
          tbtokf_o(TW_idx).meta.hits(0) <= '1';
          tbtokf_o(TW_idx).meta.hits(1) <= '1';

          --assign stubs
          for j in 0 to tbMaxNumProjectionLayers-1 loop
            proj_idx := seedTypesProjectionLayers(TW_idx)(j);

            --L2L3_L6 projection doesn't exist
            --hacky fix for now, eventually modify either KF or tracklet
            if TW_idx = 1 and proj_idx = 6 then
              tbtokf_o(TW_idx).stubs(j) <= nulll;

            --barrel
            elsif proj_idx >= 1 and proj_idx <= 6 then
              iBW_enum := barrel_stub_lut(TW_idx)(j);

              tbtokf_o(TW_idx).stubs(j).stubId  <= BW_46_data_pipe_2(iBW_enum)(widthTBstubId + BW_stubid_pos - 1 downto BW_stubid_pos);
              tbtokf_o(TW_idx).stubs(j).r       <= resize(BW_46_data_pipe_2(iBW_enum)(widthsTBr(0) + BW_r_pos - 1 downto BW_r_pos), widthTBr);
              tbtokf_o(TW_idx).stubs(j).phi     <= resize(BW_46_data_pipe_2(iBW_enum)(widthsTBphi(0) + BW_phi_pos - 1 downto BW_phi_pos), widthTBphi);
              tbtokf_o(TW_idx).stubs(j).z       <= resize(BW_46_data_pipe_2(iBW_enum)(widthsTBz(0) - 1 + BW_z_pos downto BW_z_pos), widthTBz);
              tbtokf_o(TW_idx).meta.hits(2+j)   <= BW_46_data_pipe_2(iBW_enum)(BW_valid_pos);

            --disk
            elsif proj_idx >= 11 then
              iDW_enum := disk_stub_lut(TW_idx)(j);

              tbtokf_o(TW_idx).stubs(j).stubId  <= DW_49_data_pipe_2(iDW_enum)(widthTBstubId - 1 + DW_stubid_pos downto DW_stubid_pos);
              tbtokf_o(TW_idx).stubs(j).r       <= resize(DW_49_data_pipe_2(iDW_enum)(widthsTBr(2) - 1 + DW_r_pos downto DW_r_pos), widthTBr);
              tbtokf_o(TW_idx).stubs(j).phi     <= resize(DW_49_data_pipe_2(iDW_enum)(widthsTBphi(2) - 1 + DW_phi_pos downto DW_phi_pos), widthTBphi);
              tbtokf_o(TW_idx).stubs(j).z       <= resize(DW_49_data_pipe_2(iDW_enum)(widthsTBz(2) - 1 + DW_z_pos downto DW_z_pos), widthTBz);
              tbtokf_o(TW_idx).meta.hits(2+j)   <= DW_49_data_pipe_2(iDW_enum)(DW_valid_pos);
            --else --empty slot

            end if;
          end loop; --stubs (j)
        end if; --track is valid
      end loop; -- track types (i)
    end if; --rising clock edge
  end process p_tf_to_kf;

end architecture rtl;
