# Common settings
source ../../../env_hls.tcl
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions}

# Build PR_L3PHIC
open_project -reset projrouter
add_files ../../../TopFunctions/ProjectionRouterTop.cc -cflags "$CFLAGS"
set_top ProjectionRouterTop_L3PHIC
open_solution solution_L3PHIC
source settings_hls.tcl
csynth_design
export_design -format ip_catalog

# Build ME_L3*
open_project -reset matchengine
add_files ../TopFunctions/MatchEngineTop.cc -cflags "$CFLAGS"
set_top MatchEngineTop_L3
open_solution solution_L3
source settings_hls.tcl
csynth_design
export_design -format ip_catalog

# Build MC_L3PHIC
open_project -reset match_calc
add_files ../TopFunctions/MatchCalculatorTop.cc -cflags "$CFLAGS"
set_top MatchCalculator_L3PHIC
open_solution solution_L3PHIC
source settings_hls.tcl
csynth_design
export_design -format ip_catalog

exit
