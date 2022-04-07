--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;

package memUtil_pkg is

  -- ########################### Types ###########################

  type enum_DL_39 is (PS10G_1_A,PS10G_2_A,PS10G_3_A,PS_1_A,PS_2_A,twoS_1_A,twoS_2_A,twoS_3_A,twoS_4_A);

  type enum_IL_36 is (L1PHIB_PS10G_1_A,L1PHIB_PS10G_2_A,L2PHIA_PS10G_3_A,L3PHIA_PS_1_A,L3PHIA_PS_2_A,L4PHIA_2S_1_A,L5PHIA_2S_1_A,L5PHIA_2S_2_A,L6PHIA_2S_3_A,L6PHIA_2S_4_A);

  type enum_AS_36 is (L3PHIAn1,L4PHIAn1,L5PHIAn1,L6PHIAn1,L2PHIA_B_L1C);

  type enum_AS_51 is (L1PHIB_BC);

  type enum_VMSME_16 is (L3PHIAn1);

  type enum_VMSME_17 is (L4PHIAn1,L5PHIAn1,L6PHIAn1);

  type enum_VMSTE_16 is (L2PHIAn3);

  type enum_TPROJ_60 is (L1L2C_L3PHIA);

  type enum_TPROJ_58 is (L1L2C_L4PHIA,L1L2C_L5PHIA,L1L2C_L6PHIA);

  type enum_TPAR_70 is (L1L2C);

  type enum_FM_52 is (L1L2_L3PHIA,L1L2_L4PHIA,L1L2_L5PHIA,L1L2_L6PHIA);

  type enum_TW_84 is (L1L2);

  type enum_BW_46 is (L1L2_L3,L1L2_L4,L1L2_L5,L1L2_L6);

  type t_arr_DL_39_1b is array(enum_DL_39) of std_logic;
  type t_arr_DL_39_DATA is array(enum_DL_39) of std_logic_vector(38 downto 0);
  type t_arr_IL_36_1b is array(enum_IL_36) of std_logic;
  type t_arr_IL_36_ADDR is array(enum_IL_36) of std_logic_vector(7 downto 0);
  type t_arr_IL_36_DATA is array(enum_IL_36) of std_logic_vector(35 downto 0);
  type t_arr_IL_36_NENT is array(enum_IL_36) of t_arr2_7b;
  type t_arr_AS_36_1b is array(enum_AS_36) of std_logic;
  type t_arr_AS_36_ADDR is array(enum_AS_36) of std_logic_vector(9 downto 0);
  type t_arr_AS_36_DATA is array(enum_AS_36) of std_logic_vector(35 downto 0);
  type t_arr_AS_36_NENT is array(enum_AS_36) of t_arr8_7b;
  type t_arr_AS_51_1b is array(enum_AS_51) of std_logic;
  type t_arr_AS_51_ADDR is array(enum_AS_51) of std_logic_vector(7 downto 0);
  type t_arr_AS_51_DATA is array(enum_AS_51) of std_logic_vector(50 downto 0);
  type t_arr_AS_51_NENT is array(enum_AS_51) of t_arr2_7b;
  type t_arr_VMSME_16_1b is array(enum_VMSME_16) of std_logic;
  type t_arr_VMSME_16_A1b is array(enum_VMSME_16) of std_logic_vector(3 downto 0);
  type t_arr_VMSME_16_ADDR is array(enum_VMSME_16) of std_logic_vector(11 downto 0);
  type t_arr_VMSME_16_AADDR is array(enum_VMSME_16) of t_arr4_12b;
  -- type t_arr_VMSME_16_AADDR is array(enum_VMSME_16) of std_logic_aoa(3 downto 0)(11 downto 0);
  type t_arr_VMSME_16_DATA is array(enum_VMSME_16) of std_logic_vector(15 downto 0);
  type t_arr_VMSME_16_ADATA is array(enum_VMSME_16) of t_arr4_16b;
  -- type t_arr_VMSME_16_ADATA is array(enum_VMSME_16) of std_logic_aoa(3 downto 0)(15 downto 0);
  type t_arr_VMSME_16_NENT is array(enum_VMSME_16) of t_arr4_64_4b;
  type t_arr_VMSME_16_MASK is array(enum_VMSME_16) of t_arr4_64_1b;
  type t_arr_VMSME_17_1b is array(enum_VMSME_17) of std_logic;
  type t_arr_VMSME_17_A1b is array(enum_VMSME_17) of std_logic_vector(3 downto 0);
  type t_arr_VMSME_17_ADDR is array(enum_VMSME_17) of std_logic_vector(11 downto 0);
  type t_arr_VMSME_17_AADDR is array(enum_VMSME_17) of t_arr4_12b;
  -- type t_arr_VMSME_17_AADDR is array(enum_VMSME_17) of std_logic_aoa(3 downto 0)(11 downto 0);
  type t_arr_VMSME_17_DATA is array(enum_VMSME_17) of std_logic_vector(16 downto 0);
  type t_arr_VMSME_17_ADATA is array(enum_VMSME_17) of t_arr4_17b;
  --type t_arr_VMSME_17_ADATA is array(enum_VMSME_17) of std_logic_aoa(3 downto 0)(16 downto 0);
  type t_arr_VMSME_17_NENT is array(enum_VMSME_17) of t_arr4_64_4b;
  type t_arr_VMSME_17_MASK is array(enum_VMSME_17) of t_arr4_64_1b;
  type t_arr_VMSTE_16_1b is array(enum_VMSTE_16) of std_logic;
  type t_arr_VMSTE_16_A1b is array(enum_VMSTE_16) of std_logic_vector(4 downto 0);
  type t_arr_VMSTE_16_ADDR is array(enum_VMSTE_16) of std_logic_vector(10 downto 0);
  type t_arr_VMSTE_16_AADDR is array(enum_VMSTE_16) of t_arr5_11b;
  -- type t_arr_VMSTE_16_AADDR is array(enum_VMSTE_16) of std_logic_aoa(4 downto 0)(10 downto 0);
  type t_arr_VMSTE_16_DATA is array(enum_VMSTE_16) of std_logic_vector(15 downto 0);
  type t_arr_VMSTE_16_ADATA is array(enum_VMSTE_16) of t_arr5_16b;
  -- type t_arr_VMSTE_16_ADATA is array(enum_VMSTE_16) of std_logic_aoa(4 downto 0)(15 downto 0);
  type t_arr_VMSTE_16_NENT is array(enum_VMSTE_16) of t_arr2_64_4b;
  type t_arr_VMSTE_16_MASK is array(enum_VMSTE_16) of t_arr2_64_1b;
  type t_arr_TPROJ_60_1b is array(enum_TPROJ_60) of std_logic;
  type t_arr_TPROJ_60_ADDR is array(enum_TPROJ_60) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_60_DATA is array(enum_TPROJ_60) of std_logic_vector(59 downto 0);
  type t_arr_TPROJ_60_NENT is array(enum_TPROJ_60) of t_arr2_7b;
  type t_arr_TPROJ_58_1b is array(enum_TPROJ_58) of std_logic;
  type t_arr_TPROJ_58_ADDR is array(enum_TPROJ_58) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_58_DATA is array(enum_TPROJ_58) of std_logic_vector(57 downto 0);
  type t_arr_TPROJ_58_NENT is array(enum_TPROJ_58) of t_arr2_7b;
  type t_arr_TPAR_70_1b is array(enum_TPAR_70) of std_logic;
  type t_arr_TPAR_70_ADDR is array(enum_TPAR_70) of std_logic_vector(9 downto 0);
  type t_arr_TPAR_70_DATA is array(enum_TPAR_70) of std_logic_vector(69 downto 0);
  type t_arr_TPAR_70_NENT is array(enum_TPAR_70) of t_arr8_7b;
  type t_arr_FM_52_1b is array(enum_FM_52) of std_logic;
  type t_arr_FM_52_ADDR is array(enum_FM_52) of std_logic_vector(7 downto 0);
  type t_arr_FM_52_DATA is array(enum_FM_52) of std_logic_vector(51 downto 0);
  type t_arr_FM_52_NENT is array(enum_FM_52) of t_arr2_7b;
  type t_arr_TW_84_1b is array(enum_TW_84) of std_logic;
  type t_arr_TW_84_DATA is array(enum_TW_84) of std_logic_vector(83 downto 0);
  type t_arr_BW_46_1b is array(enum_BW_46) of std_logic;
  type t_arr_BW_46_DATA is array(enum_BW_46) of std_logic_vector(45 downto 0);

  -- ########################### Functions ###########################

  -- Following functions are needed because VHDL doesn't preserve case when converting an enum to a string using image
  function memory_enum_to_string(val: enum_DL_39) return string;
  function memory_enum_to_string(val: enum_IL_36) return string;
  function memory_enum_to_string(val: enum_AS_36) return string;
  function memory_enum_to_string(val: enum_AS_51) return string;
  function memory_enum_to_string(val: enum_VMSME_16) return string;
  function memory_enum_to_string(val: enum_VMSME_17) return string;
  function memory_enum_to_string(val: enum_VMSTE_16) return string;
  function memory_enum_to_string(val: enum_TPROJ_60) return string;
  function memory_enum_to_string(val: enum_TPROJ_58) return string;
  function memory_enum_to_string(val: enum_TPAR_70) return string;
  function memory_enum_to_string(val: enum_FM_52) return string;
  function memory_enum_to_string(val: enum_TW_84) return string;
  function memory_enum_to_string(val: enum_BW_46) return string;

end package memUtil_pkg;

package body memUtil_pkg is

  -- ########################### Functions ###########################

  function memory_enum_to_string(val: enum_DL_39) return string is
  begin
    case val is
       when PS10G_1_A => return "PS10G_1_A";
       when PS10G_2_A => return "PS10G_2_A";
       when PS10G_3_A => return "PS10G_3_A";
       when PS_1_A => return "PS_1_A";
       when PS_2_A => return "PS_2_A";
       when twoS_1_A => return "2S_1_A";
       when twoS_2_A => return "2S_2_A";
       when twoS_3_A => return "2S_3_A";
       when twoS_4_A => return "2S_4_A";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_IL_36) return string is
  begin
    case val is
       when L1PHIB_PS10G_1_A => return "L1PHIB_PS10G_1_A";
       when L1PHIB_PS10G_2_A => return "L1PHIB_PS10G_2_A";
       when L2PHIA_PS10G_3_A => return "L2PHIA_PS10G_3_A";
       when L3PHIA_PS_1_A => return "L3PHIA_PS_1_A";
       when L3PHIA_PS_2_A => return "L3PHIA_PS_2_A";
       when L4PHIA_2S_1_A => return "L4PHIA_2S_1_A";
       when L5PHIA_2S_1_A => return "L5PHIA_2S_1_A";
       when L5PHIA_2S_2_A => return "L5PHIA_2S_2_A";
       when L6PHIA_2S_3_A => return "L6PHIA_2S_3_A";
       when L6PHIA_2S_4_A => return "L6PHIA_2S_4_A";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_AS_36) return string is
  begin
    case val is
       when L3PHIAn1 => return "L3PHIAn1";
       when L4PHIAn1 => return "L4PHIAn1";
       when L5PHIAn1 => return "L5PHIAn1";
       when L6PHIAn1 => return "L6PHIAn1";
       when L2PHIA_B_L1C => return "L2PHIA_B_L1C";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_AS_51) return string is
  begin
    case val is
       when L1PHIB_BC => return "L1PHIB_BC";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMSME_16) return string is
  begin
    case val is
       when L3PHIAn1 => return "L3PHIAn1";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMSME_17) return string is
  begin
    case val is
       when L4PHIAn1 => return "L4PHIAn1";
       when L5PHIAn1 => return "L5PHIAn1";
       when L6PHIAn1 => return "L6PHIAn1";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_VMSTE_16) return string is
  begin
    case val is
       when L2PHIAn3 => return "L2PHIAn3";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPROJ_60) return string is
  begin
    case val is
       when L1L2C_L3PHIA => return "L1L2C_L3PHIA";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPROJ_58) return string is
  begin
    case val is
       when L1L2C_L4PHIA => return "L1L2C_L4PHIA";
       when L1L2C_L5PHIA => return "L1L2C_L5PHIA";
       when L1L2C_L6PHIA => return "L1L2C_L6PHIA";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TPAR_70) return string is
  begin
    case val is
       when L1L2C => return "L1L2C";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_FM_52) return string is
  begin
    case val is
       when L1L2_L3PHIA => return "L1L2_L3PHIA";
       when L1L2_L4PHIA => return "L1L2_L4PHIA";
       when L1L2_L5PHIA => return "L1L2_L5PHIA";
       when L1L2_L6PHIA => return "L1L2_L6PHIA";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_TW_84) return string is
  begin
    case val is
       when L1L2 => return "L1L2";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

  function memory_enum_to_string(val: enum_BW_46) return string is
  begin
    case val is
       when L1L2_L3 => return "L1L2_L3";
       when L1L2_L4 => return "L1L2_L4";
       when L1L2_L5 => return "L1L2_L5";
       when L1L2_L6 => return "L1L2_L6";
    end case;
    return "No conversion found.";
  end memory_enum_to_string;

end package body memUtil_pkg;
