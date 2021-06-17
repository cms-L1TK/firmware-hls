--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;

package memUtil_pkg is

  -- ########################### Types ###########################

  type enum_DL_39 is (PS10G_3_A,negPS10G_3_A);

  type enum_IL_36 is (L2PHIB_PS10G_3_A,L2PHIC_PS10G_3_A,D2PHIA_PS10G_3_A,D2PHIB_PS10G_3_A,D2PHIC_PS10G_3_A,D2PHID_PS10G_3_A,L2PHIB_negPS10G_3_A,L2PHIC_negPS10G_3_A,D2PHIA_negPS10G_3_A,D2PHIB_negPS10G_3_A,D2PHIC_negPS10G_3_A,D2PHID_negPS10G_3_A,L2PHIA_PS10G_3_A,L2PHIA_negPS10G_3_A);

  type enum_AS_36 is (L2PHIAn1,L2PHIAn2,L2PHIAn3,L2PHIAn4,L2PHIAn5,L2PHIAn6,L2PHIAn7);

  type enum_VMSME_16 is (L2PHIA1n1,L2PHIA2n1,L2PHIA3n1,L2PHIA4n1,L2PHIA5n1,L2PHIA6n1,L2PHIA7n1,L2PHIA8n1);

  type enum_VMSTE_16 is (L2PHIA1n1,L2PHIA1n2,L2PHIA1n3,L2PHIA2n1,L2PHIA2n2,L2PHIA2n3,L2PHIA2n4,L2PHIA3n1,L2PHIA3n2,L2PHIA3n3,L2PHIA3n4,L2PHIA3n5,L2PHIA4n1,L2PHIA4n2,L2PHIA4n3,L2PHIA4n4,L2PHIA4n5,L2PHIA5n1,L2PHIA5n2,L2PHIA5n3,L2PHIA5n4,L2PHIA5n5,L2PHIA6n1,L2PHIA6n2,L2PHIA6n3,L2PHIA6n4,L2PHIA6n5,L2PHIA7n1,L2PHIA7n2,L2PHIA7n3,L2PHIA7n4,L2PHIA7n5,L2PHIA8n1,L2PHIA8n2,L2PHIA8n3,L2PHIA8n4,L2PHIA8n5);

  type enum_VMSTE_22 is (L2PHII1n1,L2PHII1n2,L2PHII2n1,L2PHII2n2,L2PHII2n3,L2PHII3n1,L2PHII3n2,L2PHII3n3,L2PHII4n1,L2PHII4n2,L2PHII4n3,L2PHIX1n5,L2PHIX1n6,L2PHIX1n7,L2PHIX2n5,L2PHIX2n6,L2PHIX2n7,L2PHIX2n8);

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
  type t_arr_VMSME_16_1b is array(enum_VMSME_16) of std_logic;
  type t_arr_VMSME_16_ADDR is array(enum_VMSME_16) of std_logic_vector(9 downto 0);
  type t_arr_VMSME_16_DATA is array(enum_VMSME_16) of std_logic_vector(15 downto 0);
  type t_arr_VMSME_16_NENT is array(enum_VMSME_16) of t_arr8_8_5b;
  type t_arr_VMSTE_16_1b is array(enum_VMSTE_16) of std_logic;
  type t_arr_VMSTE_16_ADDR is array(enum_VMSTE_16) of std_logic_vector(7 downto 0);
  type t_arr_VMSTE_16_DATA is array(enum_VMSTE_16) of std_logic_vector(15 downto 0);
  type t_arr_VMSTE_16_NENT is array(enum_VMSTE_16) of t_arr2_8_5b;
  type t_arr_VMSTE_22_1b is array(enum_VMSTE_22) of std_logic;
  type t_arr_VMSTE_22_ADDR is array(enum_VMSTE_22) of std_logic_vector(7 downto 0);
  type t_arr_VMSTE_22_DATA is array(enum_VMSTE_22) of std_logic_vector(21 downto 0);
  type t_arr_VMSTE_22_NENT is array(enum_VMSTE_22) of t_arr2_7b;
  
  -- ########################### Functions ########################
  
  function get_filename(val: enum_DL_39) return string;
  function get_filename(val: enum_AS_36) return string;

end package memUtil_pkg;


package body memUtil_pkg is
  
  -- ########################### Functions ########################

  function get_filename(val: enum_DL_39) return string is
  begin
    case val is
      when PS10G_3_A => return "Link_DL_PS10G_3_A_04.dat";
      when negPS10G_3_A => return "Link_DL_negPS10G_3_A_04.dat";
    end case;
    return "No filename found.";
  end get_filename;

  function get_filename(val: enum_AS_36) return string is
  begin
    case val is
      when L2PHIAn1 => return "AllStubs_AS_L2PHIAn1_04.dat";
      when L2PHIAn2 => return "AllStubs_AS_L2PHIAn2_04.dat";
      when L2PHIAn3 => return "AllStubs_AS_L2PHIAn3_04.dat";
      when L2PHIAn4 => return "AllStubs_AS_L2PHIAn4_04.dat";
      when L2PHIAn5 => return "AllStubs_AS_L2PHIAn5_04.dat";
      when L2PHIAn6 => return "AllStubs_AS_L2PHIAn6_04.dat"; 
      when L2PHIAn7 => return "AllStubs_AS_L2PHIAn7_04.dat";
    end case;
    return "No filename found.";
  end get_filename;

end package body memUtil_pkg;
      