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

use work.hybrid_config.all;
use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_tools.all;

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

  constant widthTrackletLmap    : natural := 33;
  constant widthTBInOutIndex    : natural := 20;
  constant nBarrelStubs         : natural := 6;
  constant nDiskStubs           : natural := 5;

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

  type t_arr_stub_BW is array(0 to nBarrelStubs-1) of enum_BW_46;
  type t_arr_seed_arr_stub_BW is array(enum_TW_113) of t_arr_stub_BW;
  type t_arr_stub_DW is array(0 to nDiskStubs-1) of enum_DW_49;
  type t_arr_seed_arr_stub_DW is array(enum_TW_113) of t_arr_stub_DW;

  constant barrel_stub_lut : t_arr_seed_arr_stub_BW := (
      (AAAA_L1,AAAA_L2,AAAA_L3,AAAA_L4,AAAA_L5,AAAA_L6),
      (BBBB_L1,BBBB_L2,BBBB_L3,BBBB_L4,BBBB_L5,BBBB_L6));

  constant disk_stub_lut : t_arr_seed_arr_stub_DW := (
      (AAAA_D1,AAAA_D2,AAAA_D3,AAAA_D4,AAAA_D5),
      (BBBB_D1,BBBB_D2,BBBB_D3,BBBB_D4,BBBB_D5));

  type t_arr_index_BW is array(0 to nBarrelStubs-1) of natural range 0 to 8;
  type t_arr_index_DW is array(0 to nDiskStubs-1) of natural range 0 to 8;
  type t_arr_seed_arr_index_BW is array(t_seedTypes) of t_arr_index_BW;
  type t_arr_seed_arr_index_DW is array(t_seedTypes) of t_arr_index_DW;

  --8 indicates invalid
  constant barrel_stub_index_lut : t_arr_seed_arr_index_BW := (
      (8, 8, 0, 1, 2, 3),  --L1L2
      (0, 8, 8, 1, 2, 3),  --L2L3
      (0, 1, 8, 8, 2, 3),  --L3L4
      (0, 1, 2, 3, 8, 8),  --L5L6
      (0, 1, 8, 8, 8, 8),  --D1D2
      (0, 8, 8, 8, 8, 8),  --D3D4
      (8, 8, 8, 8, 8, 8),  --L1D1
      (0, 8, 8, 8, 8, 8)); --L2D1

  constant disk_stub_index_lut : t_arr_seed_arr_index_DW := (
      (4, 5, 6, 7, 8),  --L1L2
      (4, 5, 6, 7, 8),  --L2L3
      (4, 5, 8, 8, 8),  --L3L4
      (8, 8, 8, 8, 8),  --L5L6
      (8, 8, 2, 3, 4),  --D1D2
      (1, 2, 8, 8, 3),  --D3D4
      (8, 0, 1, 2, 3),  --L1D1
      (8, 1, 2, 3, 8)); --L2D1

begin  -- architecture rtl

  p_tf_to_kf : process (clk_i) is

    variable seed_type : t_seedTypes;
    variable barrel_index : natural range 0 to 8;
    variable disk_index : natural range 0 to 8;

  begin  -- process p_tf_to_kf
    if rising_edge(clk_i) then          -- rising clock edge
      --this style of loop not recommended for synthesis, but seems to be used elsewhere
      for i in TW_113_data_i'range loop 
        tftokf_o(enum_TW_113'pos(i))             <= nulll;
        tftokf_o(enum_TW_113'pos(i)).track.reset <= kf_reset_i;

        if TW_113_valid_i(i) = '1' then
          seed_type := t_seedTypes'val(to_integer(unsigned(TW_113_data_i(i)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos))));
          tftokf_o(enum_TW_113'pos(i)).track.valid    <= TW_113_data_i(i)(TW_valid_pos);
          tftokf_o(enum_TW_113'pos(i)).track.seedtype <= TW_113_data_i(i)(widthTBseedType - 1 + TW_seedtype_pos downto TW_seedtype_pos);
          tftokf_o(enum_TW_113'pos(i)).track.inv2R    <= TW_113_data_i(i)(widthTBinv2R - 1 + TW_inv2r_pos downto TW_inv2r_pos);
          tftokf_o(enum_TW_113'pos(i)).track.phi0     <= TW_113_data_i(i)(widthTBphi0 - 1 + TW_phi0_pos downto TW_phi0_pos);
          tftokf_o(enum_TW_113'pos(i)).track.z0       <= TW_113_data_i(i)(widthTBz0 - 1 + TW_z0_pos downto TW_z0_pos);
          tftokf_o(enum_TW_113'pos(i)).track.cot      <= TW_113_data_i(i)(widthTBcot - 1 + TW_cot_pos downto TW_cot_pos);
          --barrel stubs
          for j in 0 to nBarrelStubs-1 loop 
            barrel_index := barrel_stub_index_lut(seed_type)(j);
            if (barrel_index /= 8) then

              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).reset   <= kf_reset_i;
              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).valid   <= BW_46_data_i(barrel_stub_lut(i)(j))(BW_valid_pos);
              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).trackId <= BW_46_data_i(barrel_stub_lut(i)(j))(widthTBtrackId + BW_trackid_pos - 1 downto BW_trackid_pos);
              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).stubId  <= BW_46_data_i(barrel_stub_lut(i)(j))(widthTBstubId + BW_stubid_pos - 1 downto BW_stubid_pos);
              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).r       <= resize(BW_46_data_i(barrel_stub_lut(i)(j))(widthsTBr(0) + BW_r_pos - 1 downto BW_r_pos), widthTBr);
              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).phi     <= resize(BW_46_data_i(barrel_stub_lut(i)(j))(widthsTBphi(0) + BW_phi_pos - 1 downto BW_phi_pos), widthTBphi);
              tftokf_o(enum_TW_113'pos(i)).stubs(barrel_index).z       <= resize(BW_46_data_i(barrel_stub_lut(i)(j))(widthsTBz(0) - 1 + BW_z_pos downto BW_z_pos), widthTBz);
            end if;
          end loop;
          --disk stubs
          for j in 0 to nDiskStubs-1 loop
            disk_index := disk_stub_index_lut(seed_type)(j);
            if (disk_index /= 8) then

              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).reset   <= kf_reset_i;
              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).valid   <= DW_49_data_i(disk_stub_lut(i)(j))(DW_valid_pos);
              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).trackId <= DW_49_data_i(disk_stub_lut(i)(j))(widthTBtrackId - 1 + DW_trackid_pos downto DW_trackid_pos);
              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).stubId  <= DW_49_data_i(disk_stub_lut(i)(j))(widthTBstubId - 1 + DW_stubid_pos downto DW_stubid_pos);
              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).r       <= resize(DW_49_data_i(disk_stub_lut(i)(j))(widthsTBr(2) - 1 + DW_r_pos downto DW_r_pos), widthTBr);
              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).phi     <= resize(DW_49_data_i(disk_stub_lut(i)(j))(widthsTBphi(2) - 1 + DW_phi_pos downto DW_phi_pos), widthTBphi);
              tftokf_o(enum_TW_113'pos(i)).stubs(disk_index).z       <= resize(DW_49_data_i(disk_stub_lut(i)(j))(widthsTBz(2) - 1 + DW_z_pos downto DW_z_pos), widthTBz);
            end if;
          end loop; -- loop over disk stubs
        end if; -- track is valid
      end loop; -- loop over tracks
    end if; -- clock edge
  end process p_tf_to_kf;

end architecture rtl;
