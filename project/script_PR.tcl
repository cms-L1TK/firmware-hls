open_project -reset projrouter
set_top ProjectionRouterTop
add_files ../TrackletAlgorithm/ProjectionRouterTop.cpp -cflags "-std=c++11"
add_files -tb ../TestBenches/ProjectionRouter_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/PR/PR_L3PHIC
#add_files -tb ../emData/PR/PR_L3L4_L1PHI3
open_solution -reset "solution1"
source set_fpga.tcl
create_clock -period 4 -name default
#source "./projrouter/solution1/directives.tcl"
csim_design -compiler gcc
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog

exit
