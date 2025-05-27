-------------------------------------------------------------------------------
-- Title      : tf to kf
-- Project    : 
-------------------------------------------------------------------------------
-- File       : tf_to_kf.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-11-02
-- Last update: 2022-11-03
-- Platform   : 
-- Standard   : VHDL'93/02
-------------------------------------------------------------------------------
-- Description: Module to convert between TB output format and KF input format.
--              One day, Duplicate Removal may replace this
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

use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_tools.all;
use work.hybrid_config.all;

entity tf_to_kf is
  port (
    clk_i          : in  std_logic;
    TW_113_data_i  : in  t_arr_TW_113_data;
    TW_113_valid_i : in  t_arr_TW_113_1b;
    DW_49_data_i   : in  t_arr_DW_49_DATA;
    DW_49_valid_i  : in  t_arr_DW_49_1b;
    BW_46_data_i   : in  t_arr_BW_46_DATA;
    BW_46_valid_i  : in  t_arr_BW_46_1b;
    kf_reset_i     : in  std_logic;
    tftokf_o       : out t_channlesTB(numTW_104 - 1 downto 0)
    );
end entity tf_to_kf;

architecture rtl of tf_to_kf is

  constant widthTrackletLmap : natural := 33;
  constant widthTBInOutIndex : natural := 20;
  constant nMaxTypeStubs : natural := 4;

  constant TW_valid_pos    : natural := widthTBseedType + WidthTBInOutIndex
                                        + widthTBinv2R + widthTBphi0 
                                        + widthTBz0 + widthTBcot 
                                        + widthTrackletLmap;
  constant TW_seedtype_pos : natural := widthTBInOutIndex + widthTBinv2R 
                                        + widthTBphi0 + widthTBz0 + widthTBcot 
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

  type t_arr_stub_DW is array(0 to maxNumProjectionLayers-1) of enum_DW_49;
  type t_arr_stub_BW is array(0 to maxNumProjectionLayers-1) of enum_BW_46;
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

  p_tf_to_kf : process (clk_i) is

    variable TW_idx : natural range 0 to 7;
    variable proj_idx : natural range 0 to 15;
    variable iBW_enum : enum_BW_46;
    variable iDW_enum : enum_DW_49;

  begin  -- process p_tf_to_kf
    if rising_edge(clk_i) then          -- rising clock edge

      --pipeline input
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

      for iseed in 0 to (numTW_104-1) loop
        tftokf_o(iseed)             <= nulll;
        tftokf_o(iseed).track.reset <= kf_reset_i;
      end loop;

      --this style of loop not recommended for synthesis, but seems to be used 
      --elsewhere
      for i in TW_113_data_pipe_2'range loop 
        TW_idx := to_integer(unsigned(TW_113_data_pipe_2(i)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos)));

        if (TW_113_valid_pipe_2(i) = '1') and (TW_113_data_pipe_2(i)(TW_valid_pos) = '1') then
          
          tftokf_o(TW_idx).track.valid    <= TW_113_data_pipe_2(i)(TW_valid_pos);
          tftokf_o(TW_idx).track.seedtype <= TW_113_data_pipe_2(i)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos);
          tftokf_o(TW_idx).track.inv2R    <= TW_113_data_pipe_2(i)(widthTBinv2R - 1 + TW_inv2r_pos downto TW_inv2r_pos);
          tftokf_o(TW_idx).track.phi0     <= TW_113_data_pipe_2(i)(widthTBphi0 - 1 + TW_phi0_pos downto TW_phi0_pos);
          tftokf_o(TW_idx).track.z0       <= TW_113_data_pipe_2(i)(widthTBz0 - 1 + TW_z0_pos downto TW_z0_pos);
          tftokf_o(TW_idx).track.cot      <= TW_113_data_pipe_2(i)(widthTBcot - 1 + TW_cot_pos downto TW_cot_pos);

          --assign stubs
          for j in 0 to maxNumProjectionLayers-1 loop
            proj_idx := seedTypesProjectionLayers(TW_idx)(j);

            --L2L3_L6 projection doesn't exist
            --hacky fix for now, eventually modify either KF or tracklet
            if TW_idx = 1 and proj_idx = 6 then
              tftokf_o(TW_idx).stubs(j).reset   <= kf_reset_i;
              tftokf_o(TW_idx).stubs(j).valid   <= '0';

            --barrel
            elsif proj_idx >= 1 and proj_idx <= 6 then
              iBW_enum := barrel_stub_lut(TW_idx)(j);

              tftokf_o(TW_idx).stubs(j).reset   <= kf_reset_i;
              tftokf_o(TW_idx).stubs(j).valid   <= BW_46_data_pipe_2(iBW_enum)(BW_valid_pos);
              tftokf_o(TW_idx).stubs(j).trackId <= BW_46_data_pipe_2(iBW_enum)(widthTBtrackId + BW_trackid_pos - 1 downto BW_trackid_pos);
              tftokf_o(TW_idx).stubs(j).stubId  <= BW_46_data_pipe_2(iBW_enum)(widthTBstubId + BW_stubid_pos - 1 downto BW_stubid_pos);
              tftokf_o(TW_idx).stubs(j).r       <= resize(BW_46_data_pipe_2(iBW_enum)(widthsTBr(0) + BW_r_pos - 1 downto BW_r_pos), widthTBr);
              tftokf_o(TW_idx).stubs(j).phi     <= resize(BW_46_data_pipe_2(iBW_enum)(widthsTBphi(0) + BW_phi_pos - 1 downto BW_phi_pos), widthTBphi);
              tftokf_o(TW_idx).stubs(j).z       <= resize(BW_46_data_pipe_2(iBW_enum)(widthsTBz(0) - 1 + BW_z_pos downto BW_z_pos), widthTBz);

            --disk
            elsif proj_idx >= 11 then
              iDW_enum := disk_stub_lut(TW_idx)(j);

              tftokf_o(TW_idx).stubs(j).reset   <= kf_reset_i;
              tftokf_o(TW_idx).stubs(j).valid   <= DW_49_data_pipe_2(iDW_enum)(DW_valid_pos);
              tftokf_o(TW_idx).stubs(j).trackId <= DW_49_data_pipe_2(iDW_enum)(widthTBtrackId - 1 + DW_trackid_pos downto DW_trackid_pos);
              tftokf_o(TW_idx).stubs(j).stubId  <= DW_49_data_pipe_2(iDW_enum)(widthTBstubId - 1 + DW_stubid_pos downto DW_stubid_pos);
              tftokf_o(TW_idx).stubs(j).r       <= resize(DW_49_data_pipe_2(iDW_enum)(widthsTBr(2) - 1 + DW_r_pos downto DW_r_pos), widthTBr);
              tftokf_o(TW_idx).stubs(j).phi     <= resize(DW_49_data_pipe_2(iDW_enum)(widthsTBphi(2) - 1 + DW_phi_pos downto DW_phi_pos), widthTBphi);
              tftokf_o(TW_idx).stubs(j).z       <= resize(DW_49_data_pipe_2(iDW_enum)(widthsTBz(2) - 1 + DW_z_pos downto DW_z_pos), widthTBz);

            else --empty slot
              tftokf_o(TW_idx).stubs(j).reset   <= kf_reset_i;
              tftokf_o(TW_idx).stubs(j).valid   <= '0';

            end if;
          end loop; --stubs (j)
        end if; --track is valid
      end loop; -- track types (i)
    end if; --rising clock edge
  end process p_tf_to_kf;

end architecture rtl;
