# Common settings
source ../../../project/env_hls.tcl
source ../../common/script/tools.tcl
source ../../common/script/build_ip.tcl
linkCreate ../../common common
linkCreate ../../../emData/MemPrintsReducedCM2 MemPrints
linkCreate ../../../emData/LUTsCM2 LUTs
set CFLAGS {-std=c++11 -I../../../TrackletAlgorithm -I../../../TopFunctions/ReducedCombinedConfig2}
set cwd [pwd]

# Build IRs
open_project -reset inputrouter
add_files ../../../TopFunctions/ReducedCombinedConfig2/InputRouterTop.cc -cflags "$CFLAGS"
build_ip InputRouterTop_IR_DTC_PS10G_1_A ../../../project
build_ip InputRouterTop_IR_DTC_PS10G_1_B ../../../project
build_ip InputRouterTop_IR_DTC_PS10G_2_A ../../../project
build_ip InputRouterTop_IR_DTC_PS10G_2_B ../../../project
build_ip InputRouterTop_IR_DTC_PS10G_3_A ../../../project
build_ip InputRouterTop_IR_DTC_PS10G_3_B ../../../project
build_ip InputRouterTop_IR_DTC_PS_1_A ../../../project
build_ip InputRouterTop_IR_DTC_PS_1_B ../../../project
build_ip InputRouterTop_IR_DTC_PS_2_A ../../../project
build_ip InputRouterTop_IR_DTC_PS_2_B ../../../project
build_ip InputRouterTop_IR_DTC_2S_1_A ../../../project
build_ip InputRouterTop_IR_DTC_2S_1_B ../../../project
build_ip InputRouterTop_IR_DTC_2S_2_A ../../../project
build_ip InputRouterTop_IR_DTC_2S_2_B ../../../project
build_ip InputRouterTop_IR_DTC_2S_3_A ../../../project
build_ip InputRouterTop_IR_DTC_2S_3_B ../../../project
build_ip InputRouterTop_IR_DTC_2S_4_A ../../../project
build_ip InputRouterTop_IR_DTC_2S_4_B ../../../project

# Build VMRCM_L1PHIA
open_project -reset vmrouter_L1PHIA
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIA ../../../project

# Build VMRCM_L1PHIB
open_project -reset vmrouter_L1PHIB
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIB ../../../project

# Build VMRCM_L1PHIC
open_project -reset vmrouter_L1PHIC
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIC ../../../project

# Build VMRCM_L1PHID
open_project -reset vmrouter_L1PHID
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHID.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHID ../../../project

# Build VMRCM_L1PHIE
open_project -reset vmrouter_L1PHIE
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIE.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIE ../../../project

# Build VMRCM_L1PHIF
open_project -reset vmrouter_L1PHIF
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIF.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIF ../../../project

# Build VMRCM_L1PHIG
open_project -reset vmrouter_L1PHIG
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIG.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIG ../../../project

# Build VMRCM_L1PHIH
open_project -reset vmrouter_L1PHIH
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L1PHIH.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L1PHIH ../../../project

# Build VMRCM_L2PHIA
open_project -reset vmrouter_L2PHIA
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L2PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L2PHIA ../../../project

# Build VMRCM_L2PHIB
open_project -reset vmrouter_L2PHIB
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L2PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L2PHIB ../../../project

# Build VMRCM_L2PHIC
open_project -reset vmrouter_L2PHIC
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L2PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L2PHIC ../../../project

# Build VMRCM_L2PHID
open_project -reset vmrouter_L2PHID
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L2PHID.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L2PHID ../../../project

# Build VMRCM_L3PHIA
open_project -reset vmrouter_L3PHIA
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L3PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L3PHIA ../../../project

# Build VMRCM_L3PHIB
open_project -reset vmrouter_L3PHIB
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L3PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L3PHIB ../../../project

# Build VMRCM_L3PHIC
open_project -reset vmrouter_L3PHIC
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L3PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L3PHIC ../../../project

# Build VMRCM_L3PHID
open_project -reset vmrouter_L3PHID
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L3PHID.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L3PHID ../../../project

# Build VMRCM_L4PHIA
open_project -reset vmrouter_L4PHIA
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L4PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L4PHIA ../../../project

# Build VMRCM_L4PHIB
open_project -reset vmrouter_L4PHIB
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L4PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L4PHIB ../../../project

# Build VMRCM_L4PHIC
open_project -reset vmrouter_L4PHIC
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L4PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L4PHIC ../../../project

# Build VMRCM_L4PHID
open_project -reset vmrouter_L4PHID
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L4PHID.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L4PHID ../../../project

# Build VMRCM_L5PHIA
open_project -reset vmrouter_L5PHIA
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L5PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L5PHIA ../../../project

# Build VMRCM_L5PHIB
open_project -reset vmrouter_L5PHIB
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L5PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L5PHIB ../../../project

# Build VMRCM_L5PHIC
open_project -reset vmrouter_L5PHIC
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L5PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L5PHIC ../../../project

# Build VMRCM_L5PHID
open_project -reset vmrouter_L5PHID
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L5PHID.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L5PHID ../../../project

# Build VMRCM_L6PHIA
open_project -reset vmrouter_L6PHIA
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L6PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L6PHIA ../../../project

# Build VMRCM_L6PHIB
open_project -reset vmrouter_L6PHIB
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L6PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L6PHIB ../../../project

# Build VMRCM_L6PHIC
open_project -reset vmrouter_L6PHIC
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L6PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L6PHIC ../../../project

# Build VMRCM_L6PHID
open_project -reset vmrouter_L6PHID
add_files ../../../TopFunctions/ReducedCombinedConfig2/VMRouterCMTop_L6PHID.cc -cflags "$CFLAGS"
build_ip VMRouterCMTop_L6PHID ../../../project



# Build TP
open_project -reset trackletprocessor
add_files ../../../TopFunctions/ReducedCombinedConfig2/TrackletProcessorTop.cc -cflags "$CFLAGS"
build_ip TrackletProcessor_L1L2A ../../../project
build_ip TrackletProcessor_L1L2B ../../../project
build_ip TrackletProcessor_L1L2C ../../../project
build_ip TrackletProcessor_L1L2D ../../../project
build_ip TrackletProcessor_L1L2E ../../../project
build_ip TrackletProcessor_L1L2F ../../../project
build_ip TrackletProcessor_L1L2G ../../../project
build_ip TrackletProcessor_L1L2H ../../../project
build_ip TrackletProcessor_L1L2I ../../../project
build_ip TrackletProcessor_L1L2J ../../../project
build_ip TrackletProcessor_L1L2K ../../../project
build_ip TrackletProcessor_L1L2L ../../../project

# Build MPs
open_project -reset matchprocessor
add_files ../../../TopFunctions/ReducedCombinedConfig2/MatchProcessorTop.cc -cflags "$CFLAGS"
build_ip MatchProcessor_L3PHIA ../../../project
build_ip MatchProcessor_L3PHIB ../../../project
build_ip MatchProcessor_L3PHIC ../../../project
build_ip MatchProcessor_L3PHID ../../../project
build_ip MatchProcessor_L4PHIA ../../../project
build_ip MatchProcessor_L4PHIB ../../../project
build_ip MatchProcessor_L4PHIC ../../../project
build_ip MatchProcessor_L4PHID ../../../project
build_ip MatchProcessor_L5PHIA ../../../project
build_ip MatchProcessor_L5PHIB ../../../project
build_ip MatchProcessor_L5PHIC ../../../project
build_ip MatchProcessor_L5PHID ../../../project
build_ip MatchProcessor_L6PHIA ../../../project
build_ip MatchProcessor_L6PHIB ../../../project
build_ip MatchProcessor_L6PHIC ../../../project
build_ip MatchProcessor_L6PHID ../../../project

# Build TB
open_project -reset trackBuilder
add_files ../../../TopFunctions/ReducedCombinedConfig2/TrackBuilderTop.cc -cflags "$CFLAGS"
build_ip TrackBuilder_L1L2 ../../../project

exit
