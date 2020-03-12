############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################

# set clock 250 MHz
set clockperiod 4

# delete old project
delete_project inputrouter

# make new project
open_project -reset inputrouter
set_top InputRouterTop
add_files ../TrackletAlgorithm/InputRouterTop.cpp -cflags "-std=c++11"

add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/IL
open_solution -reset "solution1"
source set_fpga.tcl
#source "./projrouter/solution1/directives.tcl"
create_clock -period $clockperiod -name default
# simulate 
# csim_design -compiler gcc
# synthesize 
csynth_design
#cosim_design
#export_design -rtl verilog -format ip_catalog -evaluate verilog
exit
