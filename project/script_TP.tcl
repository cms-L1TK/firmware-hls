# Script to generate project for TP
#   vivado_hls -f script_TP.tcl
#   vivado_hls -p trackletProcessor
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset trackletProcessor

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top TrackletProcessor_L3L4C
add_files ../TrackletAlgorithm/TrackletProcessor.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletProcessor_L3L4C_test.cpp -cflags "$CFLAGS"

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl
#set_clock_uncertainty .05

# data files
add_files -tb ../emData/TP/tables/
add_files -tb ../emData/TP/TP_L3L4C/

csim_design -mflags "-j8"
csynth_design
cosim_design 
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
