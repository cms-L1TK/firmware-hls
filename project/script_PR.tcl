# Script to generate project for PR
#   vivado_hls -f script_PR.tcl
#   vivado_hls -p projrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset projrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
add_files ../TrackletAlgorithm/ProjectionRouterTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/ProjectionRouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/PR/

open_solution "solution_L3PHIB"
source settings_hls.tcl
set_top "ProjectionRouterTop_L3PHIB"
csynth_design
export_design -format ip_catalog

open_solution "solution_L4PHIB"
source settings_hls.tcl
set_top "ProjectionRouterTop_L4PHIB"
csynth_design
export_design -format ip_catalog

open_solution "solution_L5PHIB"
source settings_hls.tcl
set_top "ProjectionRouterTop_L5PHIB"
csynth_design
export_design -format ip_catalog

open_solution "solution_L6PHIB"
source settings_hls.tcl
set_top "ProjectionRouterTop_L6PHIB"
csynth_design
export_design -format ip_catalog

exit
