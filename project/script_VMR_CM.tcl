# Script to generate project for VMR
#   vivado_hls -f script_VMR_CM.tcl
#   vivado_hls -p vmrouterCM
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset vmrouterCM

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top VMRouterTopCM
add_files ../TrackletAlgorithm/VMRouterTopCM.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/VMRouterCM_test.cpp -cflags "$CFLAGS"

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/VMRCM/tables/
add_files -tb ../emData/VMRCM/

csim_design -compiler gcc -mflags "-j8"
csynth_design
cosim_design
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
