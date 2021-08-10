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

# data files
add_files -tb ../emData/VMR/

open_solution "solution_L1PHID"
source settings_hls.tcl
set_top VMRouterTop_L1PHID
csynth_design
export_design -format ip_catalog

open_solution "solution_L2PHIB"
source settings_hls.tcl
set_top VMRouterTop_L2PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L3PHIB"
source settings_hls.tcl
set_top VMRouterTop_L3PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L4PHIB"
source settings_hls.tcl
set_top VMRouterTop_L4PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L5PHIB"
source settings_hls.tcl
set_top VMRouterTop_L5PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L6PHIB"
source settings_hls.tcl
set_top VMRouterTop_L6PHIB
csynth_design
export_design -format ip_catalog

exit
