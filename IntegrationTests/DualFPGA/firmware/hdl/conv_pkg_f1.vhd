library ieee;
use ieee.std_logic_1164.all;

use work.emp_data_types.all;
use work.hybrid_data_types.all;

package conv_pkg_f1 is

  function conv_single (l : ldata)
    return t_packet;

end package conv_pkg_f1;

package body conv_pkg_f1 is

  function conv_single(l : ldata) return t_packet is
    variable s : t_packet;
  begin
    s.valid          := l(68).valid;
    s.start_of_orbit := l(68).start_of_orbit;
    s.start          := l(68).start;
    s.last           := l(68).last;
    return s;
  end;

end package body conv_pkg_f1;




