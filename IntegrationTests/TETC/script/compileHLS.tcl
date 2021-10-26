# Common settings
source ../../../project/env_hls.tcl
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions}
set cwd [pwd]

# Build TE_L1L2
open_project -reset trackletengine
add_files ../../../TopFunctions/TrackletEngineTop.cc -cflags "$CFLAGS"
set_top TrackletEngineTop
open_solution solution_L1L2
cd ../../../project
source settings_hls.tcl
cd $cwd
csynth_design
export_design -format ip_catalog

# Build TC_L1L2E
open_project -reset trackletCalculator
add_files ../../../TopFunctions/TrackletCalculatorTop.cc -cflags "$CFLAGS"
set_top TrackletCalculator_L1L2E
open_solution solution_L1L2E
cd ../../../project
source settings_hls.tcl
cd $cwd
csynth_design
export_design -format ip_catalog

exit
