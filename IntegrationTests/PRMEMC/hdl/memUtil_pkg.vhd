--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;

package memUtil_pkg is

  type enum_TPROJ_60 is (L1L2F_L3PHIC,L1L2G_L3PHIC,L1L2H_L3PHIC,L1L2I_L3PHIC,L1L2J_L3PHIC,L5L6B_L3PHIC,L5L6C_L3PHIC,L5L6D_L3PHIC);

  type enum_VMSME_13 is (L3PHIC17n1,L3PHIC18n1,L3PHIC19n1,L3PHIC20n1,L3PHIC21n1,L3PHIC22n1,L3PHIC23n1,L3PHIC24n1);

  type enum_VMPROJ_21 is (L3PHIC17,L3PHIC18,L3PHIC19,L3PHIC20,L3PHIC21,L3PHIC22,L3PHIC23,L3PHIC24);

  type enum_CM_14 is (L3PHIC17,L3PHIC18,L3PHIC19,L3PHIC20,L3PHIC21,L3PHIC22,L3PHIC23,L3PHIC24);

  type enum_AP_60 is (L3PHIC);

  type enum_AS_36 is (L3PHICn6);

  type enum_FM_45 is (L1L2_L3PHIC,L5L6_L3PHIC);

  type t_arr_TPROJ_60_1b is array(enum_TPROJ_60) of std_logic;
  type t_arr_TPROJ_60_ADDR is array(enum_TPROJ_60) of std_logic_vector(7 downto 0);
  type t_arr_TPROJ_60_DATA is array(enum_TPROJ_60) of std_logic_vector(59 downto 0);
  type t_arr_TPROJ_60_NENT is array(enum_TPROJ_60) of t_arr2_7b;
  type t_arr_VMSME_13_1b is array(enum_VMSME_13) of std_logic;
  type t_arr_VMSME_13_ADDR is array(enum_VMSME_13) of std_logic_vector(9 downto 0);
  type t_arr_VMSME_13_DATA is array(enum_VMSME_13) of std_logic_vector(12 downto 0);
  type t_arr_VMSME_13_NENT is array(enum_VMSME_13) of t_arr8_8_5b;
  type t_arr_VMPROJ_21_1b is array(enum_VMPROJ_21) of std_logic;
  type t_arr_VMPROJ_21_ADDR is array(enum_VMPROJ_21) of std_logic_vector(7 downto 0);
  type t_arr_VMPROJ_21_DATA is array(enum_VMPROJ_21) of std_logic_vector(20 downto 0);
  type t_arr_VMPROJ_21_NENT is array(enum_VMPROJ_21) of t_arr2_7b;
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
  type t_arr_FM_45_1b is array(enum_FM_45) of std_logic;
  type t_arr_FM_45_ADDR is array(enum_FM_45) of std_logic_vector(7 downto 0);
  type t_arr_FM_45_DATA is array(enum_FM_45) of std_logic_vector(44 downto 0);
  type t_arr_FM_45_NENT is array(enum_FM_45) of t_arr2_7b;
end package memUtil_pkg;
