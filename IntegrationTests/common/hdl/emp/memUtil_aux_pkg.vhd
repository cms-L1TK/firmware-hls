--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.memUtil_Pkg.all;

package memUtil_aux_pkg is

  -- ########################### Types ###########################

  type t_arr_DL_39_1b is array(enum_DL_39) of std_logic;
  type t_arr_DL_39_DATA is array(enum_DL_39) of std_logic_vector(38 downto 0);
  type t_arr_TW_104_1b is array(enum_TW_104) of std_logic;
  type t_arr_TW_104_DATA is array(enum_TW_104) of std_logic_vector(103 downto 0);
  type t_arr_BW_46_1b is array(enum_BW_46) of std_logic;
  type t_arr_BW_46_DATA is array(enum_BW_46) of std_logic_vector(45 downto 0);

end package memUtil_aux_pkg;

