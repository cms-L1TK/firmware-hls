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
#set_max_delay 2.778 -from [get_clocks clk_240] -to [get_clocks clk_360] #-datapath_only
#set_min_delay 0.000 -from [get_clocks clk_240] -to [get_clocks clk_360]
set_multicycle_path 2 -setup -from [get_clocks clk_240] -to [get_clocks clk_360]
set_multicycle_path 1 -hold -end -from [get_clocks clk_240] -to [get_clocks clk_360]

# Set resets in SectorProcessor as false paths
set_false_path -from [get_pin payload/linktosecproc_1/sp_reset*/C] -to [all_registers]

set_property EQUIVALENT_DRIVER_OPT KEEP [get_cells payload/tf1_wrapper_1/SectorProcessor_1/*/PIPELINE_SLR_XING[*].AUTO_PIPELINE_OFF.USE_SRL_OFF.PIPELINE_*/*pipe*]
set_property EQUIVALENT_DRIVER_OPT KEEP [get_cells payload/tf1_wrapper_1/SectorProcessor_1/*/PIPELINE_SLR_XING[*].AUTO_PIPELINE_OFF.USE_SRL_OFF.PIPELINE_*]
set_property EQUIVALENT_DRIVER_OPT KEEP [get_cells payload/tf1_wrapper_1/SectorProcessor_1/LATCH_*]
set_property EQUIVALENT_DRIVER_OPT KEEP [get_cells payload/tf1_wrapper_1/SectorProcessor_1/*_DELAY]
