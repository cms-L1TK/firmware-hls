# script to generate half ip core DuplicateRemoval
# excecute in firmware-hls/project
# excecute with vitis_hls -f script_DR.tcl

source env_hls.tcl

open_project -reset duplicateRemoval

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm/}
add_files ../TopFunctions/DuplicateRemovalTop.cc -cflags "$CFLAGS"
add_files ../TrackletAlgorithm/DuplicateRemoval.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/DuplicateRemoval_test.cpp -cflags "$CFLAGS"
set_top DuplicateRemovalTop

open_solution "solution1"
source settings_hls.tcl

config_array_partition -complete_threshold 128
config_rtl -reset all

csynth_design
csim_design
cosim_design
export_design -format ip_catalog

exit
