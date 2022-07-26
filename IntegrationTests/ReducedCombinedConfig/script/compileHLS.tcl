# Common settings
source ../../../project/env_hls.tcl
source ../../common/script/tools.tcl
source ../../common/script/build_ip.tcl
linkCreate ../../common common
linkCreate ../../../emData/MemPrintsReducedCM MemPrints
linkCreate ../../../emData/LUTsCMReduced LUTs
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions/ReducedCombinedConfig}
set cwd [pwd]

# Build IRs
#open_project -reset inputrouter
#add_files ../../../TopFunctions/ReducedCombinedConfig/InputRouterTop.cc -cflags "$CFLAGS"
#build_ip InputRouterTop_IR_DTC_PS10G_1_A ../../../project
#build_ip InputRouterTop_IR_DTC_PS10G_2_A ../../../project
#build_ip InputRouterTop_IR_DTC_PS10G_3_A ../../../project
#build_ip InputRouterTop_IR_DTC_PS_1_A ../../../project
#build_ip InputRouterTop_IR_DTC_PS_2_A ../../../project
#build_ip InputRouterTop_IR_DTC_2S_1_A ../../../project
#build_ip InputRouterTop_IR_DTC_2S_2_A ../../../project
#build_ip InputRouterTop_IR_DTC_2S_3_A ../../../project
#build_ip InputRouterTop_IR_DTC_2S_4_A ../../../project

# Build VMRCM_L1PHIB
#open_project -reset vmrouter_L1PHIB
#add_files ../../../TopFunctions/ReducedCombinedConfig/VMRouterCMTop_L1PHIB.cc -cflags "$CFLAGS"
#build_ip VMRouterCMTop_L1PHIB ../../../project

# Build VMRCM_L2PHIA
#open_project -reset vmrouter_L2PHIA
#add_files ../../../TopFunctions/ReducedCombinedConfig/VMRouterCMTop_L2PHIA.cc -cflags "$CFLAGS"
#build_ip VMRouterCMTop_L2PHIA ../../../project

# Build VMRCM_L3PHIA
#open_project -reset vmrouter_L3PHIA
#add_files ../../../TopFunctions/ReducedCombinedConfig/VMRouterCMTop_L3PHIA.cc -cflags "$CFLAGS"
#build_ip VMRouterCMTop_L3PHIA ../../../project

# Build VMRCM_L4PHIA
#open_project -reset vmrouter_L4PHIA
#add_files ../../../TopFunctions/ReducedCombinedConfig/VMRouterCMTop_L4PHIA.cc -cflags "$CFLAGS"
#build_ip VMRouterCMTop_L4PHIA ../../../project

# Build VMRCM_L5PHIA
#open_project -reset vmrouter_L5PHIA
#add_files ../../../TopFunctions/ReducedCombinedConfig/VMRouterCMTop_L5PHIA.cc -cflags "$CFLAGS"
#build_ip VMRouterCMTop_L5PHIA ../../../project

# Build VMRCM_L6PHIA
#open_project -reset vmrouter_L6PHIA
#add_files ../../../TopFunctions/ReducedCombinedConfig/VMRouterCMTop_L6PHIA.cc -cflags "$CFLAGS"
#build_ip VMRouterCMTop_L6PHIA ../../../project



# Build TP
#open_project -reset trackletprocessor
#add_files ../../../TopFunctions/ReducedCombinedConfig/TrackletProcessorTop.cc -cflags "$CFLAGS"
#build_ip TrackletProcessor_L1L2C ../../../project

# Build MPs
open_project -reset matchprocessor
add_files ../../../TopFunctions/ReducedCombinedConfig/MatchProcessorTop.cc -cflags "$CFLAGS"
build_ip MatchProcessor_L3PHIA ../../../project
build_ip MatchProcessor_L4PHIA ../../../project
build_ip MatchProcessor_L5PHIA ../../../project
build_ip MatchProcessor_L6PHIA ../../../project

# Build TB
#open_project -reset trackBuilder
#add_files ../../../TopFunctions/ReducedCombinedConfig/TrackBuilderTop.cc -cflags "$CFLAGS"
#build_ip TrackBuilder_L1L2 ../../../project

exit
