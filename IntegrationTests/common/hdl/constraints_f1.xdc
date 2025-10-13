# Clocks generated in emp_ttc_clocks.vhd

# 360 MHz clock from CLKOUT3 (on CLKIN1 path)
create_generated_clock -name clk_360 \
  -source [get_pins ttc/clocks/mmcm/CLKIN1] \
  -multiply_by 9 \
  [get_pins ttc/clocks/mmcm/CLKOUT3]

# 240 MHz clock from CLKOUT4 (on CLKIN1 path)
create_generated_clock -name clk_240 \
  -source [get_pins ttc/clocks/mmcm/CLKIN1] \
  -multiply_by 6 \
  [get_pins ttc/clocks/mmcm/CLKOUT4]

# Multicycle constraints from 360 to 240 MHz
set_multicycle_path 2 -setup -start -from [get_clocks clk_360] -to [get_clocks clk_240]
set_multicycle_path 1 -hold -from [get_clocks clk_360] -to [get_clocks clk_240]

# Constraints from 240 to 360 MHz
set_max_delay 2.778 -from [get_clocks clk_240] -to [get_clocks clk_360]
set_min_delay 0.000 -from [get_clocks clk_240] -to [get_clocks clk_360]
