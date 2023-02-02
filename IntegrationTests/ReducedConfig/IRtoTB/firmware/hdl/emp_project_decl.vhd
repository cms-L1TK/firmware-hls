library ieee;
use ieee.std_logic_1164.all;

use work.emp_framework_decl.all;
use work.emp_device_types.all;
use work.emp_slink_types.all;


package emp_project_decl is


  constant PAYLOAD_REV : std_logic_vector(31 downto 0) := X"12345678";

  constant SLINK_CONF : slink_conf_array_t := (others => kNoSlink);

  constant LB_ADDR_WIDTH : integer := 10;

-- Dividers of CLOCK_COMMON_RATIO * 40 MHz
  constant CLOCK_AUX_DIV      : clock_divisor_array_t := (18, 9, 4);
  constant CLOCK_COMMON_RATIO : integer               := 36;
  constant CLOCK_RATIO        : integer               := 6;

  constant PAYLOAD_LATENCY : integer := 1132;  --1143 with thomas converter

-- constant REGION_CONF : region_conf_array_t := (
--   0 to 1 => ( no_mgt, buf, no_fmt, buf,    no_mgt ),
--   2 to 4 => ( no_mgt, buf, no_fmt, no_buf, no_mgt ),
--   others => kDummyRegion
-- );

  constant REGION_CONF : region_conf_array_t := (
    0      => (no_mgt, buf, no_fmt, buf, no_mgt),  --kDummyRegion, -- not used in apollo  -224 A, reserved: util-0 / c2c
    1      => (no_mgt, buf, no_fmt, buf, no_mgt),   --225 B, clk from 225 B
    2      => (no_mgt, buf, no_fmt, no_buf, no_mgt),  --226 C, clk from 227 D
    3      => (no_mgt, buf, no_fmt, no_buf, no_mgt),  --227 D, clk from 227 D
    4      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --  --228 E, reserved: tcds2
    5      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --229 F, clk from 230 G
    6      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --230 G, clk from 230 G
    7      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --231 H, clk from 230 G
    8      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --232 I, clk from 232 I
    9      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --233 J, clk from 232 I    
    ------cross
    10     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --133 S, clk from 132 R
    11     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --132 R, clk from 132 R
    12     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --131 Q, clk from 132 R
    13     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --130 P, clk from 130 P
    14     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --kDummyRegion -- not used in apollo  --129 O,
    15     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --128 N, clk from 128 N
    16     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --127 M, clk from 128 N
    17     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),  --126 L, clk from 126 L
    --18 => (no_mgt, buf, no_fmt, buf, no_mgt), --kDummyRegion -- service             --125 K, reserved: util-1
    others => kDummyRegion
    );


end;
