# Script to generate project for TE
#   vivado_hls -f script_TE.tcl
#   vivado_hls -p trackletengine
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset trackletengine

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top TrackletEngineTop
add_files ../TrackletAlgorithm/TrackletEngineTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletEngine_test.cpp -cflags "$CFLAGS"

if { ([string first "vitis" $exe] > -1) && ($year > 2019) } {
    open_solution "solution1" -flow_target vivado
} else {
    open_solution "solution1"
}

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/TE/

switch -glob -- $exe {
    *vitis* {
        csim_design -mflags "-j8"
    }
    default {
        csim_design -compiler gcc -mflags "-j8"
    }
}
csynth_design
cosim_design 
export_design -format ip_catalog
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
