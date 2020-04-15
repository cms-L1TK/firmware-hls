# Script to generate project for ME
#   vivado_hls -f script_ME.tcl
#   vivado_hls -p matchengine
# WARNING: this will wipe out the original project by the same name

# create new project (deleting any existing one of same name)
open_project -reset matchengine

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top MatchEngineTopL3
add_files ../TrackletAlgorithm/MatchEngineTopL3.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchEngineL3_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/ME/

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

csim_design -compiler gcc -mflags "-j8"
csynth_design
cosim_design 
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
