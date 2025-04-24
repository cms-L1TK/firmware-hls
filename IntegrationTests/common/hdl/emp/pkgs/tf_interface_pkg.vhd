-------------------------------------------------------------------------------
-- Title      : tf interface pkg
-- Project    : 
-------------------------------------------------------------------------------
-- File       : tf_interface_pkg.vhd
-- Author     : Filippo Marini  <filippo.marini@cern.ch>
-- Company    : University of Colorado Boulder
-- Created    : 2022-11-02
-- Last update: 2023-02-21
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

use work.memUtil_pkg.all;
use work.emp_data_types.all;

use work.hybrid_config.all;
use work.hybrid_data_types.all;

package tf_interface_pkg is

  --numTW_104 should reflect number of seed types (no longer length of 
  --TW_113 since now only 2 TBs). TODO fix this hack
  constant numTW_104 : natural := 8;
  constant numBW_46 : natural := enum_BW_46'pos(enum_BW_46'high) + 1;

  function conv (l : ldata)
    return t_packets;

  function conv_f2 (l : ldata)
    return t_packets;

end package tf_interface_pkg;

package body tf_interface_pkg is

  function conv(l : ldata) return t_packets is
    variable s : t_packets(numLinksTFP - 1 downto 0);
  begin
    for k in s'range loop
      s(k).valid          := l(k+68).valid;
      s(k).start_of_orbit := l(k+68).start_of_orbit;
      s(k).start          := l(k+68).start;
      s(k).last           := l(k+68).last;
    end loop;
    return s;
  end;

  function conv_f2(l : ldata) return t_packets is
    variable s : t_packets(numLinksTFP - 1 downto 0);
  begin
    for k in s'range loop
      s(k).valid          := l(k+10).valid;
      s(k).start_of_orbit := l(k+10).start_of_orbit;
      s(k).start          := l(k+10).start;
      s(k).last           := l(k+10).last;
    end loop;
    return s;
  end;

end package body tf_interface_pkg;




