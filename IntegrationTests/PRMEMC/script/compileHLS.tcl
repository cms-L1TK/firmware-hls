# Common settings
source ../../../project/env_hls.tcl
source ../../common/script/build_ip.tcl
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions}
set cwd [pwd]

# Build PR_L3PHIC
open_project -reset projrouter
add_files ../../../TopFunctions/ProjectionRouterTop.cc -cflags "$CFLAGS"
build_ip ProjectionRouterTop_L3PHIC ../../../../project

# Build ME_L3*
open_project -reset matchengine
add_files ../../../TopFunctions/MatchEngineTop.cc -cflags "$CFLAGS"
build_ip MatchEngineTop_L3 ../../../../project

# Build MC_L3PHIC
open_project -reset match_calc
add_files ../../../TopFunctions/MatchCalculatorTop.cc -cflags "$CFLAGS"
build_ip MatchCalculator_L3PHIC ../../../../project

exit
