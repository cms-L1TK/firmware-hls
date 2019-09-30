open_project -reset trackletCalculator

set_top TrackletCalculator_L1L2E
add_files ../TrackletAlgorithm/TrackletCalculator.cpp -cflags "-std=c++11"
add_files ../TrackletAlgorithm/TC_L1L2.cpp            -cflags "-std=c++11"
add_files -tb ../TestBenches/TrackletCalculator_L1L2E_test.cpp -cflags "-I../TrackletAlgorithm -I../emData -std=c++11"
add_files -tb ../emData/TC/tables
add_files -tb ../emData/TC/TC_L1L2E

open_solution -reset "solution_250MHz"
source set_fpga.tcl
create_clock -period 4

csim_design -compiler gcc
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog

exit
