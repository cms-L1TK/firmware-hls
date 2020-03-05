# Script to generate project for TE
#   vivado_hls -f script_TE.tcl
#   vivado_hls -p trackletengine
# WARNING: this will wipe out the original project by the same name

# create new project (deleting any existing one of same name)
open_project -reset trackletengine

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top TrackletEngineTop
add_files ../TrackletAlgorithm/TrackletEngineTop.cpp -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletEngine_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/TE/

# solutions
open_solution "solution1"
source settings_hls.tcl
source set_fpga.tcl
create_clock -period 250MHz -name default

csim_design -compiler gcc -mflags "-j8"
csynth_design
cosim_design 
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
