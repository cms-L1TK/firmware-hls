# Script to generate project for VMR
#   vivado_hls -f script_VMR.tcl
#   vivado_hls -p vmrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset vmrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
set_top VMRouterTop_L2PHIA
add_files ../TopFunctions/VMRouterTop_L2PHIA.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/VMRouter_test.cpp -cflags "$CFLAGS"

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/VMR/

csim_design -mflags "-j8"
csynth_design
cosim_design
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
