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

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/

create_clock -period 240MHz -name slow_clock 
create_clock -period 360MHz -name fast_clock

set nProc [exec nproc]
csim_design -mflags "-j$nProc" -argv "--link,3 --tkNonant,4"
csynth_design 
#possible options -trace_level all -rtl verilog -verbose 
cosim_design  -argv "--link,3 --tkNonant,4"
#possible options  -flow syn, -flow impl
export_design -format ip_catalog 
exit
