# Script to generate project for IR
#   vivado_hls -f script_IR.tcl
#   vivado_hls -p inputrouter
# WARNING: this will wipe out the original project by the same name

# create new project (deleting any existing one of same name)
open_project -reset inputrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top InputRouter
add_files ../TrackletAlgorithm/InputRouter.cpp -cflags "$CFLAGS"
add_files -tb ../TestBenches/InputRouter_test.cpp -cflags "CFLAGS"

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/IL/

csim_design -compiler gcc -mflags "-j8"
csynth_design
cosim_design 
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
