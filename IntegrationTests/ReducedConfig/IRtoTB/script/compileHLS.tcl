# Common settings
source ../../../../project/env_hls.tcl
source ../../../common/script/tools.tcl
source ../../../common/script/build_ip.tcl
linkCreate ../../../common common
linkCreate ../../../../emData/MemPrintsReduced MemPrints
linkCreate ../../../../emData/LUTsReduced LUTs
set CFLAGS {-std=c++11 -I../../../../TrackletAlgorithm -I../../../../TopFunctions/ReducedConfig}
set cwd [pwd]

# Build IRs
open_project -reset inputrouter
add_files ../../../../TopFunctions/ReducedConfig/InputRouterTop.cc -cflags "$CFLAGS"
build_ip InputRouterTop_IR_DTC_PS10G_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_3_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_3_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_3_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_3_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_4_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_4_B ../../../../project

# Build VMR_L1PHID
open_project -reset vmrouter_L1PHID
add_files ../../../../TopFunctions/ReducedConfig/VMRouterTop_L1PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHID ../../../../project

# Build VMR_L2PHIB
open_project -reset vmrouter_L2PHIB
add_files ../../../../TopFunctions/ReducedConfig/VMRouterTop_L2PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L2PHIB ../../../../project

# Build VMR_L3PHIB
open_project -reset vmrouter_L3PHIB
add_files ../../../../TopFunctions/ReducedConfig/VMRouterTop_L3PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L3PHIB ../../../../project

# Build VMR_L4PHIB
open_project -reset vmrouter_L4PHIB
add_files ../../../../TopFunctions/ReducedConfig/VMRouterTop_L4PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L4PHIB ../../../../project

# Build VMR_L5PHIB
open_project -reset vmrouter_L5PHIB
add_files ../../../../TopFunctions/ReducedConfig/VMRouterTop_L5PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L5PHIB ../../../../project

# Build VMR_L6PHIB
open_project -reset vmrouter_L6PHIB
add_files ../../../../TopFunctions/ReducedConfig/VMRouterTop_L6PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L6PHIB ../../../../project

# Build TE
open_project -reset trackletengine
add_files ../../../../TopFunctions/ReducedConfig/TrackletEngineTop.cc -cflags "$CFLAGS"
build_ip TrackletEngine_PS_PS ../../../../project

# Build TC
open_project -reset trackletCalculator
add_files ../../../../TopFunctions/ReducedConfig/TrackletCalculatorTop.cc -cflags "$CFLAGS"
build_ip TrackletCalculator_L1L2F ../../../../project

# Build PRs
open_project -reset projrouter
add_files ../../../../TopFunctions/ReducedConfig/ProjectionRouterTop.cc -cflags "$CFLAGS"
build_ip ProjectionRouterTop_L3PHIB ../../../../project
build_ip ProjectionRouterTop_L4PHIB ../../../../project
build_ip ProjectionRouterTop_L5PHIB ../../../../project
build_ip ProjectionRouterTop_L6PHIB ../../../../project

# Build MEs
open_project -reset matchengine
add_files ../../../../TopFunctions/ReducedConfig/MatchEngineTop.cc -cflags "$CFLAGS"
build_ip MatchEngineTop_L3 ../../../../project
build_ip MatchEngineTop_L4 ../../../../project
build_ip MatchEngineTop_L5 ../../../../project
build_ip MatchEngineTop_L6 ../../../../project

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
