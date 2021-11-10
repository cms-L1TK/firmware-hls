# Common settings
source ../../../../project/env_hls.tcl
file link -symbolic common ../../../common
file link -symbolic MemPrints ../../../../emData/MemPrintsReduced
source common/script/build_ip.tcl
set CFLAGS {-std=c++11 -I../../../../TrackletAlgorithm -I../../../../TopFunctions/ReducedConfig}
set cwd [pwd]

# Build MCs
open_project -reset match_calc
add_files ../../../../TopFunctions/ReducedConfig/MatchCalculatorTop.cc -cflags "$CFLAGS"
build_ip MatchCalculator_L3PHIB ../../../../project
build_ip MatchCalculator_L4PHIB ../../../../project
build_ip MatchCalculator_L5PHIB ../../../../project
build_ip MatchCalculator_L6PHIB ../../../../project

# Build TB
open_project -reset trackBuilder
add_files ../../../../TopFunctions/ReducedConfig/TrackBuilderTop.cc -cflags "$CFLAGS"
build_ip TrackBuilder_L1L2 ../../../../project

exit
