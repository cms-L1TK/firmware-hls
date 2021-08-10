# Script to generate project for IR
#   vivado_hls -f script_IR.tcl
#   vivado_hls -p inputrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset inputrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
set_top InputRouterTop_IR_DTC_PS10G_3_A
add_files ../TopFunctions/InputRouterTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/

open_solution "solution_PS_1_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock 
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS_1_B
csynth_design 
export_design -format ip_catalog 

open_solution "solution_2S_3_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_3_A
csynth_design
export_design -format ip_catalog

open_solution "solution_PS10G_2_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS10G_2_B
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_3_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_3_B
csynth_design
export_design -format ip_catalog

open_solution "solution_PS10G_1_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS10G_1_A
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_2_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_2_B
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_1_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_1_A
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_2_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_2_A
csynth_design
export_design -format ip_catalog

open_solution "solution_PS_2_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS_2_B
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_4_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_4_B
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_1_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_1_B
csynth_design
export_design -format ip_catalog

open_solution "solution_PS10G_3_B"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS10G_3_B
csynth_design
export_design -format ip_catalog

open_solution "solution_PS_1_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS_1_A
csynth_design
export_design -format ip_catalog

open_solution "solution_PS_2_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS_2_A
csynth_design
export_design -format ip_catalog

open_solution "solution_PS10G_2_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS10G_2_A
csynth_design
export_design -format ip_catalog

open_solution "solution_PS10G_3_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_PS10G_3_A
csynth_design
export_design -format ip_catalog

open_solution "solution_2S_4_A"
source settings_hls.tcl
create_clock -period 240MHz -name slow_clock
create_clock -period 360MHz -name fast_clock
set_top InputRouterTop_IR_DTC_2S_4_A
csynth_design
export_design -format ip_catalog

exit
