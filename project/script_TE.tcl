############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset trackletengine
set_top TrackletEngine
add_files ../TrackletAlgorithm/TrackletEngine.cpp -cflags "-std=c++11"

add_files -tb ../TestBenches/TrackletEngine_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/TE
open_solution -reset "solution1"
set_part {xcku115-flvb2104-2-e} -tool vivado
create_clock -period 4 -name default

#exit
