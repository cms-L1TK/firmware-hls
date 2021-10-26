# Common settings
source ../../../project/env_hls.tcl
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions}
set cwd [pwd]

# Build IR_DTC_PS10G_3_A
open_project -reset inputrouter
add_files ../../../TopFunctions/InputRouterTop.cc -cflags "$CFLAGS"
set_top InputRouterTop_IR_DTC_PS10G_3_A
open_solution solution_PS10G_3_A
cd ../../../project
source settings_hls.tcl
cd $cwd
csynth_design
export_design -format ip_catalog

# Build VMR_L2PHIA
open_project -reset vmrouter
add_files ../../../TopFunctions/VMRouterTop_L2PHIA.cc -cflags "$CFLAGS"
set_top VMRouterTop_L2PHIA
open_solution solution_L2PHIA
cd ../../../project
source settings_hls.tcl
cd $cwd
csynth_design
export_design -format ip_catalog

exit
