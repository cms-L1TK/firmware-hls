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
use work.memUtil_aux_pkg.all;
use work.tf_interface_pkg.all;

use work.hybrid_data_types.all;
use work.hybrid_data_formats.all;
use work.hybrid_tools.all;

entity tf_to_kf is
  port (
    clk_i          : in  std_logic;
    TW_104_data_i  : in  t_arr_TW_104_data;
    TW_104_valid_i : in  t_arr_TW_104_1b;
    BW_46_data_i   : in  t_arr_BW_46_DATA;
    BW_46_valid_i  : in  t_arr_BW_46_1b;
    kf_reset_i     : in  std_logic;
    tftokf_o       : out t_channlesTB(numTW_104 - 1 downto 0)
    );
end entity tf_to_kf;

architecture rtl of tf_to_kf is

  constant widthTrackletLmap : natural := 24;
  constant widthTBInOutIndex : natural := 20;

begin  -- architecture rtl

  p_tf_to_kf : process (clk_i) is
  begin  -- process p_tf_to_kf
    if rising_edge(clk_i) then          -- rising clock edge
      --this style of loop not recommended for synthesis, but seems to be used elsewhere
      for i in TW_104_data_i'range loop 
        tftokf_o(enum_TW_104'pos(i))             <= nulll;
        tftokf_o(enum_TW_104'pos(i)).track.reset <= kf_reset_i;
        if TW_104_valid_i(i) = '1' then
          tftokf_o(enum_TW_104'pos(i)).track.valid    <= TW_104_data_i(i)(1 + widthTBseedType + WidthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1);
          tftokf_o(enum_TW_104'pos(i)).track.seedtype <= TW_104_data_i(i)(widthTBseedType + widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.inv2R    <= TW_104_data_i(i)(widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.phi0     <= TW_104_data_i(i)(widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBz0 + widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.z0       <= TW_104_data_i(i)(widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBcot + widthTrackletLmap);
          tftokf_o(enum_TW_104'pos(i)).track.cot      <= TW_104_data_i(i)(widthTBcot + widthTrackletLmap - 1 downto widthTrackletLmap);
        end if;
        --currently give all stubs to all tracks, maybe do something smart by matching trackId later?
        for j in BW_46_data_i'range loop
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).reset   <= kf_reset_i;
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).valid   <= BW_46_data_i(j)(1 + widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1);
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).trackId <= BW_46_data_i(j)(widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).stubId  <= BW_46_data_i(j)(widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).r       <= resize(BW_46_data_i(j)(widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBphi(0) + widthsTBz(0)), widthTBr);
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).phi     <= resize(BW_46_data_i(j)(widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBz(0)), widthTBphi);
          tftokf_o(enum_TW_104'pos(i)).stubs(enum_BW_46'pos(j)).z       <= resize(BW_46_data_i(j)(widthsTBz(0) - 1 downto 0), widthTBz);
        end loop;  -- j
      end loop; -- i
    end if;
  end process p_tf_to_kf;
  --p_tf_to_kf : process (clk_i) is
  --begin  -- process p_tf_to_kf
  --  if rising_edge(clk_i) then          -- rising clock edge
  --    tftokf_o(0)             <= nulll;
  --    tftokf_o(0).track.reset <= kf_reset_i;
  --    for i in BW_46_data_i'range loop
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).reset <= kf_reset_i;
  --    end loop;  -- i
  --    if TW_104_valid_i(L1L2) = '1' then
  --      tftokf_o(0).track.valid    <= TW_104_data_i(L1L2)(1 + widthTBseedType + WidthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1);
  --      tftokf_o(0).track.seedtype <= TW_104_data_i(L1L2)(widthTBseedType + widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBInOutIndex + widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
  --      tftokf_o(0).track.inv2R    <= TW_104_data_i(L1L2)(widthTBinv2R + widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap);
  --      tftokf_o(0).track.phi0     <= TW_104_data_i(L1L2)(widthTBphi0 + widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBz0 + widthTBcot + widthTrackletLmap);
  --      tftokf_o(0).track.z0       <= TW_104_data_i(L1L2)(widthTBz0 + widthTBcot + widthTrackletLmap - 1 downto widthTBcot + widthTrackletLmap);
  --      tftokf_o(0).track.cot      <= TW_104_data_i(L1L2)(widthTBcot + widthTrackletLmap - 1 downto widthTrackletLmap);
  --    end if;
  --    for i in BW_46_data_i'range loop
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).valid   <= BW_46_data_i(i)(1 + widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1);
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).trackId <= BW_46_data_i(i)(widthTBtrackId + widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).stubId  <= BW_46_data_i(i)(widthTBstubId + widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBr(0) + widthsTBphi(0) + widthsTBz(0));
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).r       <= resize(BW_46_data_i(i)(widthsTBr(0) + widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBphi(0) + widthsTBz(0)), widthTBr);
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).phi     <= resize(BW_46_data_i(i)(widthsTBphi(0) + widthsTBz(0) - 1 downto widthsTBz(0)), widthTBphi);
  --      tftokf_o(0).stubs(enum_BW_46'pos(i)).z       <= resize(BW_46_data_i(i)(widthsTBz(0) - 1 downto 0), widthTBz);
  --    end loop;  -- i
  --  end if;
  --end process p_tf_to_kf;

end architecture rtl;
