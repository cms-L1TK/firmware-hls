# 240 MHz
create_clock -period 4.166 -name clk240 [get_ports clk240]

# 360 MHz
create_clock -period 2.777 -name clk360 [get_ports clk360]

# Multicycle constraints from 360 to 240 MHz
set_multicycle_path 2 -setup -start -from [get_clocks clk360] -to [get_clocks clk240]
set_multicycle_path 1 -hold -from [get_clocks clk360] -to [get_clocks clk240]
