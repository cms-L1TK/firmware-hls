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

use work.tf_pkg.all;
use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;
use work.tf_interface_pkg.all;

use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_tools.all;

entity tf_to_kf is
  port (
    clk_i          : in  std_logic;
    TW_104_data_i  : in  t_arr_TW_104_data;
    TW_104_valid_i : in  t_arr_TW_104_1b;
    DW_49_data_i   : in  t_arr_DW_49_DATA;
    DW_49_valid_i  : in  t_arr_DW_49_1b;
    BW_46_data_i   : in  t_arr_BW_46_DATA;
    BW_46_valid_i  : in  t_arr_BW_46_1b;
    kf_reset_i     : in  std_logic;
    tftokf_o       : out t_channlesTB(numTW_104 - 1 downto 0)
    );
end entity tf_to_kf;

architecture rtl of tf_to_kf is

  constant widthTrackletLmap : natural := 24;
  constant widthTBInOutIndex : natural := 20;

  type t_arr_stub_1b is array(0 to 3) of std_logic;
  type t_arr_stub_DW is array(0 to 3) of enum_DW_49;
  type t_arr_stub_BW is array(0 to 3) of enum_BW_46;
  type t_arr_seed_arr_stub_1b is array(enum_TW_104) of t_arr_stub_1b;
  type t_arr_seed_arr_stub_DW is array(enum_TW_104) of t_arr_stub_DW;
  type t_arr_seed_arr_stub_BW is array(enum_TW_104) of t_arr_stub_BW;

  --constants used to look up which barrel/disk stubs should be assigned to which seed type
  --10 indicates barrel, 11 disk, 0X invalid        
  constant disk_stub_valid : t_arr_seed_arr_stub_1b := (('1','1','1','1'), --L1L2
                                                        ('1','1','1','1'), --L2L3
                                                        ('1','1','0','0'), --L3L4
                                                        ('0','0','0','0'), --L5L6
                                                        ('1','1','1','0'), --D1D2
                                                        ('1','1','1','0'), --D3D4
                                                        ('1','1','1','1'), --L1D1
                                                        ('1','1','1','0')  --L2D1
                                                       );
        
        
  constant disk_stub_lut : t_arr_seed_arr_stub_DW := ((L1L2_D1,L1L2_D2,L1L2_D3,L1L2_D4), --L1L2
                                                      (L2L3_D1,L2L3_D2,L2L3_D3,L2L3_D4), --L2L3
                                                      (L3L4_D1,L3L4_D2,L1L2_D1,L1L2_D1), --L3L4
                                                      (L1L2_D1,L1L2_D1,L1L2_D1,L1L2_D1), --L5L6
                                                      (D1D2_D3,D1D2_D4,D1D2_D5,L1L2_D1), --D1D2
                                                      (D3D4_D1,D3D4_D2,D3D4_D5,L1L2_D1), --D3D4
                                                      (L1D1_D2,L1D1_D3,L1D1_D4,L1D1_D5), --L1D1
                                                      (L2D1_D2,L2D1_D3,L2D1_D4,L1L2_D1)  --L2D1
                                                     );
  constant barrel_stub_valid : t_arr_seed_arr_stub_1b := (('1','1','1','1'), --L1L2
                                                          ('1','1','1','0'), --L2L3
                                                          ('1','1','1','1'), --L3L4
                                                          ('1','1','1','1'), --L5L6
                                                          ('1','1','0','0'), --D1D2
                                                          ('1','0','0','0'), --D3D4
                                                          ('0','0','0','0'), --L1D1
                                                          ('1','0','0','0')  --L2D1
                                                         );
  constant barrel_stub_lut : t_arr_seed_arr_stub_BW := ((L1L2_L3,L1L2_L4,L1L2_L5,L1L2_L6), --L1L2
                                                        (L2L3_L1,L2L3_L4,L2L3_L5,L1L2_L3), --L2L3
                                                        (L3L4_L1,L3L4_L2,L3L4_L5,L3L4_L6), --L3L4
                                                        (L5L6_L1,L5L6_L2,L5L6_L3,L5L6_L4), --L5L6
                                                        (D1D2_L1,D1D2_L2,L1L2_L3,L1L2_L3), --D1D2
                                                        (D3D4_L1,L1L2_L3,L1L2_L3,L1L2_L3), --D3D4
                                                        (L1L2_L3,L1L2_L3,L1L2_L3,L1L2_L3), --L1D1
                                                        (L2D1_L1,L1L2_L3,L1L2_L3,L1L2_L3)  --L2D1
                                                       );

begin  -- architecture rtl

  p_tf_to_kf : process (clk_i) is


  begin  -- process p_tf_to_kf
    if rising_edge(clk_i) then          -- rising clock edge
      --this style of loop not recommended for synthesis, but seems to be used elsewhere
      for i in TW_104_data_i'range loop 
        tftokf_o(enum_TW_104'pos(i))             <= nulll;
        tftokf_o(enum_TW_104'pos(i)).track.reset <= kf_reset_i;
        if (TW_104_valid_i(i) = '1') and (TW_104_data_i(i)(103) = '1') then
          tftokf_o(enum_TW_104'pos(i)).track.valid    <= TW_104_data_i(i)(1 + widthTBseedType + WidthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1);
          tftokf_o(enum_TW_104'pos(i)).track.seedtype <= TW_104_data_i(i)(widthTBseedType + widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.inv2R    <= TW_104_data_i(i)(widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.phi0     <= TW_104_data_i(i)(widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.z0       <= TW_104_data_i(i)(widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.cot      <= TW_104_data_i(i)(widthTBcot + widthTrackletLmap - 1 downto widthTrackletLmap);
          --barrel
          for j in 0 to 3 loop
            if (barrel_stub_valid(i)(j) = '1') then
              tftokf_o(enum_TW_104'pos(i)).stubs(j).reset   <= kf_reset_i;
              tftokf_o(enum_TW_104'pos(i)).stubs(j).valid   <= BW_46_data_i(barrel_stub_lut(i)(j))(1 + widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1);
              tftokf_o(enum_TW_104'pos(i)).stubs(j).trackId <= BW_46_data_i(barrel_stub_lut(i)(j))(widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
              tftokf_o(enum_TW_104'pos(i)).stubs(j).stubId  <= BW_46_data_i(barrel_stub_lut(i)(j))(widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
              tftokf_o(enum_TW_104'pos(i)).stubs(j).r       <= resize(BW_46_data_i(barrel_stub_lut(i)(j))(widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBphi(0) + widthsTBz(0)), widthTBr);
              tftokf_o(enum_TW_104'pos(i)).stubs(j).phi     <= resize(BW_46_data_i(barrel_stub_lut(i)(j))(widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBz(0)), widthTBphi);
              tftokf_o(enum_TW_104'pos(i)).stubs(j).z       <= resize(BW_46_data_i(barrel_stub_lut(i)(j))(widthsTBz(0) - 1 downto 0), widthTBz);
            else
              tftokf_o(enum_TW_104'pos(i)).stubs(j).reset   <= kf_reset_i;
              tftokf_o(enum_TW_104'pos(i)).stubs(j).valid   <= '0';
            end if;
          end loop;
          --disk
          for j in 0 to 3 loop
            if (disk_stub_valid(i)(j) = '1') then
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).reset   <= kf_reset_i;
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).valid   <= DW_49_data_i(disk_stub_lut(i)(j))(1 + widthTBtrackId + widthTBstubId + widthsTBr(2) + widthsTBphi(2) + widthsTBz(2) - 1);
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).trackId <= DW_49_data_i(disk_stub_lut(i)(j))(widthTBtrackId + widthTBstubId + widthsTBr(2) + widthsTBphi(2) + widthsTBz(2) - 1 downto widthTBstubId + widthsTBr(2) + widthsTBphi(2) + widthsTBz(2));
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).stubId  <= DW_49_data_i(disk_stub_lut(i)(j))(widthTBstubId + widthsTBr(2) + widthsTBphi(2) + widthsTBz(2) - 1 downto widthsTBr(2) + widthsTBphi(2) + widthsTBz(2));
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).r       <= resize(DW_49_data_i(disk_stub_lut(i)(j))(widthsTBr(2) + widthsTBphi(2) + widthsTBz(2) - 1 downto widthsTBphi(2) + widthsTBz(2)), widthTBr);
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).phi     <= resize(DW_49_data_i(disk_stub_lut(i)(j))(widthsTBphi(2) + widthsTBz(2) - 1 downto widthsTBz(2)), widthTBphi);
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).z       <= resize(DW_49_data_i(disk_stub_lut(i)(j))(widthsTBz(2) - 1 downto 0), widthTBz);
            else
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).reset   <= kf_reset_i;
              tftokf_o(enum_TW_104'pos(i)).stubs(j+4).valid   <= '0';
            end if;
          end loop;
        end if;
      end loop; -- i
    end if;
  end process p_tf_to_kf;

end architecture rtl;
