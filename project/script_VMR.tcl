############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset vmrouter
set_top VMRouterTop
add_files ../TrackletAlgorithm/VMRouter.cpp -cflags "-std=c++11"
add_files ../TrackletAlgorithm/VMRouterTop.cc -cflags "-std=c++11"

add_files -tb ../TestBenches/VMRouter_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/VMR
open_solution -reset "solution1"
source set_fpga.tcl
create_clock -period 4 -name default

# Compile & create IP Core
csim_design -clean -compiler gcc -mflags "-j8"
csynth_design
cosim_design -trace_level all -rtl vhdl
#export_design -rtl vhdl -format ip_catalog
#export_design -flow impl -rtl vhdl -format ip_catalog
exit
