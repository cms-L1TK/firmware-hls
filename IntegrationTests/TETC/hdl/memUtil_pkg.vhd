--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;

package memUtil_pkg is

  -- ########################### Types ###########################

  type enum_AS_36 is (L1PHICn4,L1PHIDn2,L2PHIBn4);

  type enum_VMSTE_22 is (L1PHIC12n1,L1PHIC12n2,L1PHIC12n3,L1PHIC12n4,L1PHIC12n5,L1PHID13n1,L1PHID13n2,L1PHID13n3,L1PHID13n4,L1PHID13n5,L1PHID14n1,L1PHID14n2,L1PHID14n3);

  type enum_VMSTE_16 is (L2PHIB10n5,L2PHIB11n4,L2PHIB11n5,L2PHIB12n3,L2PHIB12n4,L2PHIB12n5,L2PHIB13n2,L2PHIB13n3,L2PHIB13n4,L2PHIB14n1,L2PHIB14n2,L2PHIB14n3,L2PHIB15n1);

  type enum_SP_14 is (L1PHIC12_L2PHIB10,L1PHIC12_L2PHIB11,L1PHIC12_L2PHIB12,L1PHIC12_L2PHIB13,L1PHIC12_L2PHIB14,L1PHID13_L2PHIB11,L1PHID13_L2PHIB12,L1PHID13_L2PHIB13,L1PHID13_L2PHIB14,L1PHID13_L2PHIB15,L1PHID14_L2PHIB12,L1PHID14_L2PHIB13,L1PHID14_L2PHIB14);

  type enum_TPROJ_60 is (L1L2E_L3PHIB);

  type enum_TPROJ_58 is (L1L2E_L4PHIA,L1L2E_L4PHIB,L1L2E_L4PHIC,L1L2E_L5PHIA,L1L2E_L5PHIB,L1L2E_L5PHIC,L1L2E_L6PHIA,L1L2E_L6PHIB,L1L2E_L6PHIC);

  type enum_TPROJ_59 is (L1L2E_D1PHIA,L1L2E_D1PHIB,L1L2E_D1PHIC,L1L2E_D2PHIA,L1L2E_D2PHIB,L1L2E_D2PHIC,L1L2E_D3PHIA,L1L2E_D3PHIB,L1L2E_D3PHIC,L1L2E_D4PHIA,L1L2E_D4PHIB,L1L2E_D4PHIC);

  type enum_TPAR_70 is (L1L2E);

  type t_arr_AS_36_1b is array(enum_AS_36) of std_logic;
  type t_arr_AS_36_ADDR is array(enum_AS_36) of std_logic_vector(9 downto 0);
  type t_arr_AS_36_DATA is array(enum_AS_36) of std_logic_vector(35 downto 0);
  type t_arr_AS_36_NENT is array(enum_AS_36) of t_arr8_7b;
  type t_arr_VMSTE_22_1b is array(enum_VMSTE_22) of std_logic;
  type t_arr_VMSTE_22_ADDR is array(enum_VMSTE_22) of std_logic_vector(7 downto 0);
  type t_arr_VMSTE_22_DATA is array(enum_VMSTE_22) of std_logic_vector(21 downto 0);
  type t_arr_VMSTE_22_NENT is array(enum_VMSTE_22) of t_arr2_7b;
  type t_arr_VMSTE_16_1b is array(enum_VMSTE_16) of std_logic;
  type t_arr_VMSTE_16_ADDR is array(enum_VMSTE_16) of std_logic_vector(7 downto 0);
  type t_arr_VMSTE_16_DATA is array(enum_VMSTE_16) of std_logic_vector(15 downto 0);
  type t_arr_VMSTE_16_NENT is array(enum_VMSTE_16) of t_arr2_8_5b;
  type t_arr_SP_14_1b is array(enum_SP_14) of std_logic;
  type t_arr_SP_14_ADDR is array(enum_SP_14) of std_logic_vector(7 downto 0);
  type t_arr_SP_14_DATA is array(enum_SP_14) of std_logic_vector(13 downto 0);
  type t_arr_SP_14_NENT is array(enum_SP_14) of t_arr2_7b;
  type t_arr_TPROJ_60_1b is array(enum_TPROJ_60) of std_logic;
  type t_arr_TPROJ_60_ADDR is array(enum_TPROJ_60) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_60_DATA is array(enum_TPROJ_60) of std_logic_vector(59 downto 0);
  type t_arr_TPROJ_60_NENT is array(enum_TPROJ_60) of t_arr2_7b;
  type t_arr_TPROJ_58_1b is array(enum_TPROJ_58) of std_logic;
  type t_arr_TPROJ_58_ADDR is array(enum_TPROJ_58) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_58_DATA is array(enum_TPROJ_58) of std_logic_vector(57 downto 0);
  type t_arr_TPROJ_58_NENT is array(enum_TPROJ_58) of t_arr2_7b;
  type t_arr_TPROJ_59_1b is array(enum_TPROJ_59) of std_logic;
  type t_arr_TPROJ_59_ADDR is array(enum_TPROJ_59) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_59_DATA is array(enum_TPROJ_59) of std_logic_vector(58 downto 0);
  type t_arr_TPROJ_59_NENT is array(enum_TPROJ_59) of t_arr2_7b;
  type t_arr_TPAR_70_1b is array(enum_TPAR_70) of std_logic;
  type t_arr_TPAR_70_ADDR is array(enum_TPAR_70) of std_logic_vector(9 downto 0);
  type t_arr_TPAR_70_DATA is array(enum_TPAR_70) of std_logic_vector(69 downto 0);
  type t_arr_TPAR_70_NENT is array(enum_TPAR_70) of t_arr8_7b;

  -- ########################### Functions ###########################

  -- Following functions are needed because VHDL doesn't preserve case when converting an enum to a string using image
  function memory_enum_to_string(val: enum_AS_36) return string;
  function memory_enum_to_string(val: enum_VMSTE_22) return string;
  function memory_enum_to_string(val: enum_VMSTE_16) return string;
  function memory_enum_to_string(val: enum_SP_14) return string;
  function memory_enum_to_string(val: enum_TPROJ_60) return string;
  function memory_enum_to_string(val: enum_TPROJ_58) return string;
  function memory_enum_to_string(val: enum_TPROJ_59) return string;
  function memory_enum_to_string(val: enum_TPAR_70) return string;

end package memUtil_pkg;

package body memUtil_pkg is

  -- ########################### Functions ###########################

  function memory_enum_to_string(val: enum_AS_36) return string is
  begin
    case val is
       when L1PHICn4 => return "L1PHICn4";
       when L1PHIDn2 => return "L1PHIDn2";
       when L2PHIBn4 => return "L2PHIBn4";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMSTE_22) return string is
  begin
    case val is
       when L1PHIC12n1 => return "L1PHIC12n1";
       when L1PHIC12n2 => return "L1PHIC12n2";
       when L1PHIC12n3 => return "L1PHIC12n3";
       when L1PHIC12n4 => return "L1PHIC12n4";
       when L1PHIC12n5 => return "L1PHIC12n5";
       when L1PHID13n1 => return "L1PHID13n1";
       when L1PHID13n2 => return "L1PHID13n2";
       when L1PHID13n3 => return "L1PHID13n3";
       when L1PHID13n4 => return "L1PHID13n4";
       when L1PHID13n5 => return "L1PHID13n5";
       when L1PHID14n1 => return "L1PHID14n1";
       when L1PHID14n2 => return "L1PHID14n2";
       when L1PHID14n3 => return "L1PHID14n3";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMSTE_16) return string is
  begin
    case val is
       when L2PHIB10n5 => return "L2PHIB10n5";
       when L2PHIB11n4 => return "L2PHIB11n4";
       when L2PHIB11n5 => return "L2PHIB11n5";
       when L2PHIB12n3 => return "L2PHIB12n3";
       when L2PHIB12n4 => return "L2PHIB12n4";
       when L2PHIB12n5 => return "L2PHIB12n5";
       when L2PHIB13n2 => return "L2PHIB13n2";
       when L2PHIB13n3 => return "L2PHIB13n3";
       when L2PHIB13n4 => return "L2PHIB13n4";
       when L2PHIB14n1 => return "L2PHIB14n1";
       when L2PHIB14n2 => return "L2PHIB14n2";
       when L2PHIB14n3 => return "L2PHIB14n3";
       when L2PHIB15n1 => return "L2PHIB15n1";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_SP_14) return string is
  begin
    case val is
       when L1PHIC12_L2PHIB10 => return "L1PHIC12_L2PHIB10";
       when L1PHIC12_L2PHIB11 => return "L1PHIC12_L2PHIB11";
       when L1PHIC12_L2PHIB12 => return "L1PHIC12_L2PHIB12";
       when L1PHIC12_L2PHIB13 => return "L1PHIC12_L2PHIB13";
       when L1PHIC12_L2PHIB14 => return "L1PHIC12_L2PHIB14";
       when L1PHID13_L2PHIB11 => return "L1PHID13_L2PHIB11";
       when L1PHID13_L2PHIB12 => return "L1PHID13_L2PHIB12";
       when L1PHID13_L2PHIB13 => return "L1PHID13_L2PHIB13";
       when L1PHID13_L2PHIB14 => return "L1PHID13_L2PHIB14";
       when L1PHID13_L2PHIB15 => return "L1PHID13_L2PHIB15";
       when L1PHID14_L2PHIB12 => return "L1PHID14_L2PHIB12";
       when L1PHID14_L2PHIB13 => return "L1PHID14_L2PHIB13";
       when L1PHID14_L2PHIB14 => return "L1PHID14_L2PHIB14";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPROJ_60) return string is
  begin
    case val is
       when L1L2E_L3PHIB => return "L1L2E_L3PHIB";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPROJ_58) return string is
  begin
    case val is
       when L1L2E_L4PHIA => return "L1L2E_L4PHIA";
       when L1L2E_L4PHIB => return "L1L2E_L4PHIB";
       when L1L2E_L4PHIC => return "L1L2E_L4PHIC";
       when L1L2E_L5PHIA => return "L1L2E_L5PHIA";
       when L1L2E_L5PHIB => return "L1L2E_L5PHIB";
       when L1L2E_L5PHIC => return "L1L2E_L5PHIC";
       when L1L2E_L6PHIA => return "L1L2E_L6PHIA";
       when L1L2E_L6PHIB => return "L1L2E_L6PHIB";
       when L1L2E_L6PHIC => return "L1L2E_L6PHIC";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPROJ_59) return string is
  begin
    case val is
       when L1L2E_D1PHIA => return "L1L2E_D1PHIA";
       when L1L2E_D1PHIB => return "L1L2E_D1PHIB";
       when L1L2E_D1PHIC => return "L1L2E_D1PHIC";
       when L1L2E_D2PHIA => return "L1L2E_D2PHIA";
       when L1L2E_D2PHIB => return "L1L2E_D2PHIB";
       when L1L2E_D2PHIC => return "L1L2E_D2PHIC";
       when L1L2E_D3PHIA => return "L1L2E_D3PHIA";
       when L1L2E_D3PHIB => return "L1L2E_D3PHIB";
       when L1L2E_D3PHIC => return "L1L2E_D3PHIC";
       when L1L2E_D4PHIA => return "L1L2E_D4PHIA";
       when L1L2E_D4PHIB => return "L1L2E_D4PHIB";
       when L1L2E_D4PHIC => return "L1L2E_D4PHIC";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPAR_70) return string is
  begin
    case val is
       when L1L2E => return "L1L2E";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

end package body memUtil_pkg;
