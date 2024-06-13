--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.memUtil_Pkg.all;

package memUtil_aux_pkg_f1 is

  -- ########################### Types ###########################

  type t_arr_DL_39_1b is array(enum_DL_39) of std_logic;
  type t_arr_DL_39_DATA is array(enum_DL_39) of std_logic_vector(38 downto 0);

end package memUtil_aux_pkg_f1;

