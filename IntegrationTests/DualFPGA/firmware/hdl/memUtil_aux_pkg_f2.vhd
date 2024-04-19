--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.memUtil_Pkg.all;

package memUtil_aux_pkg_f2 is

  -- ########################### Types ###########################

  type enum_MTPAR_73 is (L1L2ABC,L1L2DE,L1L2F,L1L2G,L1L2HI,L1L2JKL,L2L3ABCD,L3L4AB,L3L4CD,L5L6ABCD,D1D2ABCD,D3D4ABCD,L1D1ABCD,L1D1EFGH,L2D1ABCD);

  type t_arr_AS_36_1b is array(enum_AS_36) of std_logic;
  type t_arr_AS_36_37b is array(enum_AS_36) of std_logic_vector(36 downto 0);
  type t_arr_AS_36_ADDR is array(enum_AS_36) of std_logic_vector(9 downto 0);
  type t_arr_AS_36_DATA is array(enum_AS_36) of std_logic_vector(35 downto 0);

  type t_arr_MTPAR_73_1b is array(enum_MTPAR_73) of std_logic;
  type t_arr_MTPAR_73_76b is array(enum_MTPAR_73) of std_logic_vector(75 downto 0);
  type t_arr_MTPAR_73_ADDR is array(enum_MTPAR_73) of std_logic_vector(9 downto 0);
  type t_arr_MTPAR_73_DATA is array(enum_MTPAR_73) of std_logic_vector(72 downto 0);

  type t_arr_TW_104_1b is array(enum_TW_104) of std_logic;
  type t_arr_TW_104_DATA is array(enum_TW_104) of std_logic_vector(103 downto 0);

  type t_arr_BW_46_1b is array(enum_BW_46) of std_logic;
  type t_arr_BW_46_DATA is array(enum_BW_46) of std_logic_vector(45 downto 0);

  type t_arr_DW_49_1b is array(enum_DW_49) of std_logic;
  type t_arr_DW_49_DATA is array(enum_DW_49) of std_logic_vector(48 downto 0);

end package memUtil_aux_pkg_f2;

