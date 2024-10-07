
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

  -- Readdjust if latency changes for FPGA1 algorithm
  constant PAYLOAD_LATENCY : integer := 140;

  -- F1 transmits to F2 on inter-fpga links
  constant REGION_CONF : region_conf_array_t := (
     0   => kDummyRegion,                     -- service c2c
     1   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     2   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     3   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     4   => kDummyRegion,                     -- not routed
     5   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     6   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     7   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     8   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
     9   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
    10   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
    11   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
    12   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
    13   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
    14   => (no_mgt, no_buf, no_fmt, buf, gty25), -- fpga-fpga
    15   => kDummyRegion,                     -- not routed
------cross
----- all MGTs instantiated bidirectionally for now
    16  => kDummyRegion,                      -- not routed
    17  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    18  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    19  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    20  => kDummyRegion,                      -- not routed                  
    21  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    22  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    23  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    24  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    25  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    26  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    27  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    28  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    29  => (gty25, buf, no_fmt, buf, gty25),  -- firefly
    30  => (gty25, buf, no_fmt, buf, gty25),  -- firefly     
    31  => kDummyRegion,                      -- service tcds

    others => kDummyRegion
    );

  -- Specify the slink quad using the corresponding region conf ID
  -- Specify slink channels to enable using the channel mask
  constant SLINK_CONF : slink_conf_array_t := (
    others => kNoSlink
    );


end emp_project_decl;
