############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################

# delete old project
delete_project inputrouter

# make new project
open_project -reset inputrouter
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top InputRouterTop
add_files ../TrackletAlgorithm/InputRouterTop.cpp -cflags "$CFLAGS"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "$CFLAGS"

add_files -tb ../emData/IL

open_solution -reset "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# simulate 
set nProc [exec nproc]
csim_design -compiler gcc -mflags "-j$nProc"
config_rtl -reset all -reset_async -reset_level low
# synthesize 
# csynth_design
#export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
