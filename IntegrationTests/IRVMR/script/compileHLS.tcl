# Common settings
source ../../../project/env_hls.tcl
file link -symbolic common ../../common
source common/script/build_ip.tcl
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions}
set cwd [pwd]

# Build IR_DTC_PS10G_3_A
open_project -reset inputrouter
add_files ../../../TopFunctions/InputRouterTop.cc -cflags "$CFLAGS"
build_ip InputRouterTop_IR_DTC_PS10G_3_A ../../../../project

# Build VMR_L2PHIA
open_project -reset vmrouter
add_files ../../../TopFunctions/VMRouterTop_L2PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L2PHIA ../../../../project

exit
