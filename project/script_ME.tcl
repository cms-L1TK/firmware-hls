############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset matchengine
set_top MatchEngine
add_files ../TrackletAlgorithm/MatchEngineTopL1.cpp -cflags "-std=c++11"
add_files -tb ../TestBenches/MatchEngine_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/ME
open_solution -reset "solution1"
set_part {xcku115-flvb2104-2-e} -tool vivado
create_clock -period 4 -name default
#source "./projrouter/solution1/directives.tcl"
#csim_design -compiler gcc
#csynth_design
#cosim_design
#export_design -rtl verilog -format ip_catalog

#exit
