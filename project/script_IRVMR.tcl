# Script to generate project for VMR
#   vivado_hls -f script_VMRCM.tcl
#   vivado_hls -p vmrouterCM
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TrackletAlgorithm/TestBench -I../TopFunctions/test}

# create new project (deleting any existing one of same name)
open_project -reset combined

# data files
add_files -tb ../emData/VMRCM/

# run C-simulation for each module in modules_to_test
add_files ../TopFunctions/test/InputRouterTop.cc -cflags "$CFLAGS"
add_files ../TopFunctions/test/VMRouterCMTop_L1PHIA.cc -cflags "$CFLAGS"
add_files ../TopFunctions/test/VMRouterCMTop_L1PHIB.cc -cflags "$CFLAGS"
add_files ../TopFunctions/test/combined.cc -cflags "$CFLAGS"
set_top combined
open_solution solution

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

csynth_design
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
