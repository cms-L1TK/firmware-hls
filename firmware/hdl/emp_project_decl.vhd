library ieee;
use ieee.std_logic_1164.ALL;

use work.emp_framework_decl.all;
use work.emp_device_types.all;


package emp_project_decl is


constant PAYLOAD_REV: std_logic_vector(31 downto 0) := X"12345678";

constant LB_ADDR_WIDTH  : integer := 10;

-- Dividers of CLOCK_COMMON_RATIO * 40 MHz
constant CLOCK_AUX_DIV     : clock_divisor_array_t := (18, 9, 4);
constant CLOCK_COMMON_RATIO: integer               := 36;
constant CLOCK_RATIO       : integer               :=  6;

constant PAYLOAD_LATENCY: integer := 816;

constant REGION_CONF : region_conf_array_t := (
  0  => kDummyRegion, -- service
  1  => (gty25, buf, no_fmt, buf, gty25),
  2  => (gty25, buf, no_fmt, buf, gty25),
  3  => (gty25, buf, no_fmt, buf, gty25),
  4  => kDummyRegion, -- tcds
  5  => (gty25, buf, no_fmt, buf, gty25),
  6  => (gty25, buf, no_fmt, buf, gty25),
  others => kDummyRegion
);


end;
