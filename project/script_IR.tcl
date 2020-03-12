############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset inputrouter
set_top InputRouter
add_files ../TrackletAlgorithm/InputRouter.cpp -cflags "-std=c++11"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/IL
open_solution -reset "solution1"
source set_fpga.tcl
create_clock -period 4 -name default
source "./projrouter/solution1/directives.tcl"
csim_design -compiler gcc
#csynth_design
#cosim_design
#export_design -rtl verilog -format ip_catalog -evaluate verilog

#exit
