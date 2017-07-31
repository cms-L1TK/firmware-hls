############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project vmrouter_1
set_top VMRouterDispatcher
add_files ../TrackletAlgorithm/HLSConstants.hh
add_files ../TrackletAlgorithm/HLSFullStubLayerPS.hh
add_files ../TrackletAlgorithm/HLSReducedStubLayer.hh
add_files ../TrackletAlgorithm/VMRouter.cpp
add_files ../TrackletAlgorithm/VMRouter.hh
add_files ../TrackletAlgorithm/VMRouterDispatcher.cpp
add_files ../TrackletAlgorithm/VMRouterDispatcher.hh
add_files -tb ../TestBenches/VMRouter_test.cpp
open_solution "solution1"
set_part {xc7vx690tffg1927-2}
create_clock -period 4 -name default
source "./vmrouter_1/solution1/directives.tcl"
csim_design -O
csynth_design
cosim_design
export_design -format ip_catalog
