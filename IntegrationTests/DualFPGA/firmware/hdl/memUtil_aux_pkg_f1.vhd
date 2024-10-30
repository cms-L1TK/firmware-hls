--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.memUtil_Pkg.all;

package memUtil_aux_pkg_f1 is

  -- ########################### Types ###########################

  type enum_AS_37 is (L1PHIAn1,L1PHIBn1,L1PHICn1,L1PHIDn1,L1PHIEn1,L1PHIFn1,L1PHIGn1,L1PHIHn1,L2PHIAn1,L2PHIBn1,L2PHICn1,L2PHIDn1,L3PHIAn1,L3PHIBn1,L3PHICn1,L3PHIDn1,L4PHIAn1,L4PHIBn1,L4PHICn1,L4PHIDn1,L5PHIAn1,L5PHIBn1,L5PHICn1,L5PHIDn1,L6PHIAn1,L6PHIBn1,L6PHICn1,L6PHIDn1,D1PHIAn1,D1PHIBn1,D1PHICn1,D1PHIDn1,D2PHIAn1,D2PHIBn1,D2PHICn1,D2PHIDn1,D3PHIAn1,D3PHIBn1,D3PHICn1,D3PHIDn1,D4PHIAn1,D4PHIBn1,D4PHICn1,D4PHIDn1,D5PHIAn1,D5PHIBn1,D5PHICn1,D5PHIDn1);

  type enum_MPAR_76 is (L1L2ABC,L1L2DE,L1L2F,L1L2G,L1L2HI,L1L2JKL,L2L3ABCD,L3L4AB,L3L4CD,L5L6ABCD,D1D2ABCD,D3D4ABCD,L1D1ABCD,L1D1EFGH,L2D1ABCD);

  type t_arr_DL_39_1b is array(enum_DL_39) of std_logic;
  type t_arr_DL_39_DATA is array(enum_DL_39) of std_logic_vector(38 downto 0);
  type t_arr_AS_37_DATA is array(enum_AS_37) of std_logic_vector(36 downto 0);
  type t_arr_MPAR_76_DATA is array(enum_MPAR_76) of std_logic_vector(75 downto 0);

end package memUtil_aux_pkg_f1;

