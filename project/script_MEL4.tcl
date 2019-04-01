############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset matchenginel4
set_top MatchEngineTopL4
add_files ../TrackletAlgorithm/MatchEngineTopL4.cpp -cflags "-std=c++11"
add_files -tb ../TestBenches/MatchEngineL4_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/ME
open_solution -reset "solution1"
source set_fpga.tcl
create_clock -period 4 -name default
#source "./projrouter/solution1/directives.tcl"
#csim_design -compiler gcc
#csynth_design
#cosim_design
#export_design -rtl verilog -format ip_catalog

#exit
