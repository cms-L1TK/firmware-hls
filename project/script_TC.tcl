open_project -reset trackletCalculator

set_top TrackletCalculator_L1L2E
add_files ../TrackletAlgorithm/TrackletCalculator.cpp -cflags "-std=c++11"
add_files ../TrackletAlgorithm/TC_L1L2.cpp            -cflags "-std=c++11"
add_files -tb ../TestBenches/TrackletCalculator_test.cpp -cflags "-I../TrackletAlgorithm -I../emData -std=c++11"
add_files -tb ../emData/TC/tables
add_files -tb ../emData/TC/TC_L1L2E
add_files -tb ../emData/TC/TC_L1L2E_truncated

open_solution -reset "solution_250MHz"
source set_fpga.tcl
create_clock -period 4

# Truncation: ON
#csim_design -compiler gcc -O -mflags "-j9 -k"
# Truncation: OFF
#csim_design -compiler gcc -O -mflags "-j9 -k" -argv "0"
#csynth_design
#cosim_design -O -mflags "-j9 -k"
#export_design -rtl verilog -format ip_catalog

exit
