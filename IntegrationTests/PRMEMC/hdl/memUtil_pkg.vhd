--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;

package memUtil_pkg is

  -- ########################### Types ###########################

  type enum_TPROJ_60 is (L1L2F_L3PHIC,L1L2G_L3PHIC,L1L2H_L3PHIC,L1L2I_L3PHIC,L1L2J_L3PHIC,L5L6B_L3PHIC,L5L6C_L3PHIC,L5L6D_L3PHIC);

  type enum_VMSME_16 is (L3PHIC17n1,L3PHIC18n1,L3PHIC19n1,L3PHIC20n1,L3PHIC21n1,L3PHIC22n1,L3PHIC23n1,L3PHIC24n1);

  type enum_VMPROJ_24 is (L3PHIC17,L3PHIC18,L3PHIC19,L3PHIC20,L3PHIC21,L3PHIC22,L3PHIC23,L3PHIC24);

  type enum_CM_14 is (L3PHIC17,L3PHIC18,L3PHIC19,L3PHIC20,L3PHIC21,L3PHIC22,L3PHIC23,L3PHIC24);

  type enum_AP_60 is (L3PHIC);

  type enum_AS_36 is (L3PHICn6);

  type enum_FM_52 is (L1L2_L3PHIC,L5L6_L3PHIC);

  type t_arr_TPROJ_60_1b is array(enum_TPROJ_60) of std_logic;
  type t_arr_TPROJ_60_ADDR is array(enum_TPROJ_60) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_60_DATA is array(enum_TPROJ_60) of std_logic_vector(59 downto 0);
  type t_arr_TPROJ_60_NENT is array(enum_TPROJ_60) of t_arr2_7b;
  type t_arr_VMSME_16_1b is array(enum_VMSME_16) of std_logic;
  type t_arr_VMSME_16_ADDR is array(enum_VMSME_16) of std_logic_vector(9 downto 0);
  type t_arr_VMSME_16_DATA is array(enum_VMSME_16) of std_logic_vector(15 downto 0);
  type t_arr_VMSME_16_NENT is array(enum_VMSME_16) of t_arr8_8_5b;
  type t_arr_VMPROJ_24_1b is array(enum_VMPROJ_24) of std_logic;
  type t_arr_VMPROJ_24_ADDR is array(enum_VMPROJ_24) of std_logic_vector(7 downto 0);
  type t_arr_VMPROJ_24_DATA is array(enum_VMPROJ_24) of std_logic_vector(23 downto 0);
  type t_arr_VMPROJ_24_NENT is array(enum_VMPROJ_24) of t_arr2_7b;
  type t_arr_CM_14_1b is array(enum_CM_14) of std_logic;
  type t_arr_CM_14_ADDR is array(enum_CM_14) of std_logic_vector(7 downto 0);
  type t_arr_CM_14_DATA is array(enum_CM_14) of std_logic_vector(13 downto 0);
  type t_arr_CM_14_NENT is array(enum_CM_14) of t_arr2_7b;
  type t_arr_AP_60_1b is array(enum_AP_60) of std_logic;
  type t_arr_AP_60_ADDR is array(enum_AP_60) of std_logic_vector(9 downto 0);
  type t_arr_AP_60_DATA is array(enum_AP_60) of std_logic_vector(59 downto 0);
  type t_arr_AP_60_NENT is array(enum_AP_60) of t_arr8_7b;
  type t_arr_AS_36_1b is array(enum_AS_36) of std_logic;
  type t_arr_AS_36_ADDR is array(enum_AS_36) of std_logic_vector(9 downto 0);
  type t_arr_AS_36_DATA is array(enum_AS_36) of std_logic_vector(35 downto 0);
  type t_arr_AS_36_NENT is array(enum_AS_36) of t_arr8_7b;
  type t_arr_FM_52_1b is array(enum_FM_52) of std_logic;
  type t_arr_FM_52_ADDR is array(enum_FM_52) of std_logic_vector(7 downto 0);
  type t_arr_FM_52_DATA is array(enum_FM_52) of std_logic_vector(51 downto 0);
  type t_arr_FM_52_NENT is array(enum_FM_52) of t_arr2_7b;

  -- ########################### Functions ###########################

  -- Following functions are needed because VHDL is not case sensitive when converting an enum to a string
  function memory_enum_to_string(val: enum_TPROJ_60) return string;
  function memory_enum_to_string(val: enum_VMSME_16) return string;
  function memory_enum_to_string(val: enum_VMPROJ_24) return string;
  function memory_enum_to_string(val: enum_CM_14) return string;
  function memory_enum_to_string(val: enum_AP_60) return string;
  function memory_enum_to_string(val: enum_AS_36) return string;
  function memory_enum_to_string(val: enum_FM_52) return string;

end package memUtil_pkg;

package body memUtil_pkg is

  -- ########################### Functions ###########################

  function memory_enum_to_string(val: enum_TPROJ_60) return string is
  begin
    case val is
       when L1L2F_L3PHIC => return "L1L2F_L3PHIC";
       when L1L2G_L3PHIC => return "L1L2G_L3PHIC";
       when L1L2H_L3PHIC => return "L1L2H_L3PHIC";
       when L1L2I_L3PHIC => return "L1L2I_L3PHIC";
       when L1L2J_L3PHIC => return "L1L2J_L3PHIC";
       when L5L6B_L3PHIC => return "L5L6B_L3PHIC";
       when L5L6C_L3PHIC => return "L5L6C_L3PHIC";
       when L5L6D_L3PHIC => return "L5L6D_L3PHIC";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMSME_16) return string is
  begin
    case val is
       when L3PHIC17n1 => return "L3PHIC17n1";
       when L3PHIC18n1 => return "L3PHIC18n1";
       when L3PHIC19n1 => return "L3PHIC19n1";
       when L3PHIC20n1 => return "L3PHIC20n1";
       when L3PHIC21n1 => return "L3PHIC21n1";
       when L3PHIC22n1 => return "L3PHIC22n1";
       when L3PHIC23n1 => return "L3PHIC23n1";
       when L3PHIC24n1 => return "L3PHIC24n1";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMPROJ_24) return string is
  begin
    case val is
       when L3PHIC17 => return "L3PHIC17";
       when L3PHIC18 => return "L3PHIC18";
       when L3PHIC19 => return "L3PHIC19";
       when L3PHIC20 => return "L3PHIC20";
       when L3PHIC21 => return "L3PHIC21";
       when L3PHIC22 => return "L3PHIC22";
       when L3PHIC23 => return "L3PHIC23";
       when L3PHIC24 => return "L3PHIC24";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_CM_14) return string is
  begin
    case val is
       when L3PHIC17 => return "L3PHIC17";
       when L3PHIC18 => return "L3PHIC18";
       when L3PHIC19 => return "L3PHIC19";
       when L3PHIC20 => return "L3PHIC20";
       when L3PHIC21 => return "L3PHIC21";
       when L3PHIC22 => return "L3PHIC22";
       when L3PHIC23 => return "L3PHIC23";
       when L3PHIC24 => return "L3PHIC24";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_AP_60) return string is
  begin
    case val is
       when L3PHIC => return "L3PHIC";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_AS_36) return string is
  begin
    case val is
       when L3PHICn6 => return "L3PHICn6";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_FM_52) return string is
  begin
    case val is
       when L1L2_L3PHIC => return "L1L2_L3PHIC";
       when L5L6_L3PHIC => return "L5L6_L3PHIC";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

end package body memUtil_pkg;
