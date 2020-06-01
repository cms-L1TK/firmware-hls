# Script to generate project for TC
#   vivado_hls -f script_TC.tcl
#   vivado_hls -p trackletCalculator
# WARNING: this will wipe out the original project by the same name

# create new project (deleting any existing one of same name)
open_project -reset trackletCalculator

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top TrackletCalculator_L1L2G
add_files ../TrackletAlgorithm/TrackletCalculator.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletCalculator_L1L2G_test.cpp -cflags "$CFLAGS"

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/TC/tables/
add_files -tb ../emData/TC/TC_L1L2G/

csim_design -compiler gcc -mflags "-j8"
csynth_design
cosim_design 
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
