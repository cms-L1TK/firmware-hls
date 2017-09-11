############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project vmrouter_2
set_top VMRouterDispatcher
add_files ../TrackletAlgorithm/VMRouterDispatcher.cpp
add_files ../TrackletAlgorithm/VMRouter.cpp
add_files ../TrackletAlgorithm/HLSConstants.hh
add_files ../TrackletAlgorithm/HLSFullStubLayerPS.hh
add_files ../TrackletAlgorithm/HLSReducedStubLayer.hh
add_files ../TrackletAlgorithm/VMRouter.hh
add_files ../TrackletAlgorithm/VMRouterDispatcher.hh
add_files -tb ../TestBenches/VMRouter_test.cpp
add_files -tb emData
open_solution "solution3-noinline"
set_part {xc7vx690tffg1927-2}
create_clock -period 4 -name default
source "./vmrouter_2/solution3-noinline/directives.tcl"
csim_design -O -compiler gcc
csynth_design
cosim_design
export_design -format ip_catalog
