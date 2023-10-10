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
-- Description: 
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
use work.tf_interface_pkg.all;

use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_tools.all;

entity tf_to_kf is
  port (
    clk_i         : in  std_logic;
    TW_98_data_i  : in  t_arr_TW_98_data;
    TW_98_valid_i : in  t_arr_TW_98_1b;
    BW_46_data_i  : in  t_arr_BW_46_DATA;
    BW_46_valid_i : in  t_arr_BW_46_1b;
    kf_reset_i    : in  std_logic;
    tftokf_o      : out t_channlesTB(numTW_98 - 1 downto 0)
    );
end entity tf_to_kf;

architecture rtl of tf_to_kf is

  constant widthTrackletLmap : natural := 24;
  constant widthTBInOutIndex : natural := 14;

begin  -- architecture rtl

  p_tf_to_kf : process (clk_i) is
  begin  -- process p_tf_to_kf
    if rising_edge(clk_i) then          -- rising clock edge
      --this style of loop not recommended for synthesis, but seems to be used elsewhere
      for i in TW_98_data_i'range loop 
        tftokf_o(enum_TW_98'pos(i))             <= nulll;
        tftokf_o(enum_TW_98'pos(i)).track.reset <= kf_reset_i;
        if TW_98_valid_i(i) = '1' then
          tftokf_o(enum_TW_98'pos(i)).track.valid    <= TW_98_data_i(i)(1 + widthTBseedType + WidthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1);
          tftokf_o(enum_TW_98'pos(i)).track.seedtype <= TW_98_data_i(i)(widthTBseedType + widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_98'pos(i)).track.inv2R    <= TW_98_data_i(i)(widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_98'pos(i)).track.phi0     <= TW_98_data_i(i)(widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_98'pos(i)).track.z0       <= TW_98_data_i(i)(widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_98'pos(i)).track.cot      <= TW_98_data_i(i)(widthTBcot + widthTrackletLmap - 1 downto widthTrackletLmap);
        end if;
        --currently give all stubs to all tracks, maybe do something smart by matching trackId later?
        for j in BW_46_data_i'range loop
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).reset   <= kf_reset_i;
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).valid   <= BW_46_data_i(j)(1 + widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1);
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).trackId <= BW_46_data_i(j)(widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).stubId  <= BW_46_data_i(j)(widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).r       <= resize(BW_46_data_i(j)(widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBphi(0) + widthsTBz(0)), widthTBr);
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).phi     <= resize(BW_46_data_i(j)(widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBz(0)), widthTBphi);
          tftokf_o(enum_TW_98'pos(i)).stubs(enum_BW_46'pos(j)).z       <= resize(BW_46_data_i(j)(widthsTBz(0) - 1 downto 0), widthTBz);
        end loop;  -- j
      end loop; -- i
    end if;
  end process p_tf_to_kf;

end architecture rtl;
