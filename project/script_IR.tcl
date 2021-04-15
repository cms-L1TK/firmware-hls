# Script to generate project for IR
#   vivado_hls -f script_IR.tcl
#   vivado_hls -p inputrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset inputrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top InputRouterTop
add_files ../TrackletAlgorithm/InputRouterTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "$CFLAGS"

if { ([string first "vitis" $exe] > -1) && ($year > 2019) } {
    open_solution "solution1" -flow_target vivado
} else {
    open_solution "solution1"
}

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/

create_clock -period 240MHz -name slow_clock 
create_clock -period 360MHz -name fast_clock

set nProc [exec nproc]
switch -glob -- $exe {
    *vitis* {
        csim_design -mflags "-j$nProc"
    }
    default {
        csim_design -compiler gcc -mflags "-j$nProc"
    }
}
csynth_design 
# possible options -trace_level all -rtl verilog -verbose 
cosim_design 
# possible options  -flow syn, -flow impl
#export_design -format ip_catalog 
exit
