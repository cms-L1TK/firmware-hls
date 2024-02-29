
library IEEE;
use IEEE.STD_LOGIC_1164.all;

use work.emp_framework_decl.all;
use work.emp_device_types.all;
use work.emp_slink_types.all;

package emp_project_decl is

  constant PAYLOAD_REV : std_logic_vector(31 downto 0) := X"12345678";

  -- Latency buffer size
  constant LB_ADDR_WIDTH : integer := 10;

  -- Clock setup
  constant CLOCK_COMMON_RATIO : integer               := 36;
  constant CLOCK_RATIO        : integer               := 6;
  constant CLOCK_AUX_DIV      : clock_divisor_array_t := (18, 9, 4);  -- Dividers of CLOCK_COMMON_RATIO * 40 MHz

  -- Only used by nullalgo   
  constant PAYLOAD_LATENCY : integer := 1132;

  constant REGION_CONF : region_conf_array_t := (
    0      => (no_mgt, buf, no_fmt, no_buf, no_mgt),  --kDummyRegion, -- service
    1      => (no_mgt, buf, no_fmt, no_buf, no_mgt),
    2      => (no_mgt, buf, no_fmt, no_buf, no_mgt),
    3      => (no_mgt, buf, no_fmt, no_buf, no_mgt),
    4      => kDummyRegion,                        -- tcds
    5      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    6      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    7      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    8      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    9      => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    ------cross
    10     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    11     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    12     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    13     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    14     => kDummyRegion,                        -- not used in apollo
    15     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    16     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    17     => (no_mgt, no_buf, no_fmt, no_buf, no_mgt),
    18     => kDummyRegion,                        -- service
    30     => (no_mgt, no_buf, no_fmt, buf, no_mgt),
    others => kDummyRegion
    );

  -- Specify the slink quad using the corresponding region conf ID
  -- Specify slink channels to enable using the channel mask
  constant SLINK_CONF : slink_conf_array_t := (
    others => kNoSlink
    );


end emp_project_decl;
