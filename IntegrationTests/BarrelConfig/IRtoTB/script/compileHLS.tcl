# Common settings
source ../../../../project/env_hls.tcl
source ../../../common/script/tools.tcl
source ../../../common/script/build_ip.tcl
linkCreate ../../../common common
linkCreate ../../../../emData/MemPrintsBarrel MemPrints
linkCreate ../../../../emData/LUTs LUTs
set CFLAGS {-std=c++11 -I../../../../TrackletAlgorithm -I../../../../TopFunctions/BarrelConfig}
set cwd [pwd]

# Build IRs
open_project -reset inputrouter
add_files ../../../../TopFunctions/BarrelConfig/InputRouterTop.cc -cflags "$CFLAGS"
build_ip InputRouterTop_IR_DTC_2S_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_3_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_3_B ../../../../project
build_ip InputRouterTop_IR_DTC_2S_4_A ../../../../project
build_ip InputRouterTop_IR_DTC_2S_4_B ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_3_A ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_3_B ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_4_A ../../../../project
build_ip InputRouterTop_IR_DTC_neg2S_4_B ../../../../project
build_ip InputRouterTop_IR_DTC_negPS10G_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_negPS10G_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_negPS10G_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_negPS10G_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_negPS10G_3_A ../../../../project
build_ip InputRouterTop_IR_DTC_negPS10G_3_B ../../../../project
build_ip InputRouterTop_IR_DTC_negPS_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_negPS_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_negPS_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_negPS_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_2_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_3_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS10G_3_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS_1_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS_1_B ../../../../project
build_ip InputRouterTop_IR_DTC_PS_2_A ../../../../project
build_ip InputRouterTop_IR_DTC_PS_2_B ../../../../project

# Build VMR_L1PHIA
open_project -reset vmrouter_L1PHIA
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIA ../../../../project

# Build VMR_L1PHIB
open_project -reset vmrouter_L1PHIB
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIB ../../../../project

# Build VMR_L1PHIC
open_project -reset vmrouter_L1PHIC
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIC ../../../../project

# Build VMR_L1PHID
open_project -reset vmrouter_L1PHID
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHID ../../../../project

# Build VMR_L1PHIE
open_project -reset vmrouter_L1PHIE
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIE.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIE ../../../../project

# Build VMR_L1PHIF
open_project -reset vmrouter_L1PHIF
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIF.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIF ../../../../project

# Build VMR_L1PHIG
open_project -reset vmrouter_L1PHIG
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIG.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIG ../../../../project

# Build VMR_L1PHIH
open_project -reset vmrouter_L1PHIH
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L1PHIH.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L1PHIH ../../../../project

# Build VMR_L2PHIA
open_project -reset vmrouter_L2PHIA
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L2PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L2PHIA ../../../../project

# Build VMR_L2PHIB
open_project -reset vmrouter_L2PHIB
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L2PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L2PHIB ../../../../project

# Build VMR_L2PHIC
open_project -reset vmrouter_L2PHIC
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L2PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L2PHIC ../../../../project

# Build VMR_L2PHID
open_project -reset vmrouter_L2PHID
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L2PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L2PHID ../../../../project

# Build VMR_L3PHIA
open_project -reset vmrouter_L3PHIA
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L3PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L3PHIA ../../../../project

# Build VMR_L3PHIB
open_project -reset vmrouter_L3PHIB
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L3PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L3PHIB ../../../../project

# Build VMR_L3PHIC
open_project -reset vmrouter_L3PHIC
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L3PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L3PHIC ../../../../project

# Build VMR_L3PHID
open_project -reset vmrouter_L3PHID
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L3PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L3PHID ../../../../project

# Build VMR_L4PHIA
open_project -reset vmrouter_L4PHIA
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L4PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L4PHIA ../../../../project

# Build VMR_L4PHIB
open_project -reset vmrouter_L4PHIB
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L4PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L4PHIB ../../../../project

# Build VMR_L4PHIC
open_project -reset vmrouter_L4PHIC
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L4PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L4PHIC ../../../../project

# Build VMR_L4PHID
open_project -reset vmrouter_L4PHID
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L4PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L4PHID ../../../../project

# Build VMR_L5PHIA
open_project -reset vmrouter_L5PHIA
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L5PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L5PHIA ../../../../project

# Build VMR_L5PHIB
open_project -reset vmrouter_L5PHIB
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L5PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L5PHIB ../../../../project

# Build VMR_L5PHIC
open_project -reset vmrouter_L5PHIC
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L5PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L5PHIC ../../../../project

# Build VMR_L5PHID
open_project -reset vmrouter_L5PHID
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L5PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L5PHID ../../../../project

# Build VMR_L6PHIA
open_project -reset vmrouter_L6PHIA
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L6PHIA.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L6PHIA ../../../../project

# Build VMR_L6PHIB
open_project -reset vmrouter_L6PHIB
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L6PHIB.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L6PHIB ../../../../project

# Build VMR_L6PHIC
open_project -reset vmrouter_L6PHIC
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L6PHIC.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L6PHIC ../../../../project

# Build VMR_L6PHID
open_project -reset vmrouter_L6PHID
add_files ../../../../TopFunctions/BarrelConfig/VMRouterTop_L6PHID.cc -cflags "$CFLAGS"
build_ip VMRouterTop_L6PHID ../../../../project

# Build TE
open_project -reset trackletengine
add_files ../../../../TopFunctions/BarrelConfig/TrackletEngineTop.cc -cflags "$CFLAGS"
build_ip TrackletEngine_PS_PS ../../../../project
build_ip TrackletEngine_PS_2S ../../../../project
build_ip TrackletEngine_2S_2S ../../../../project

# Build TC
open_project -reset trackletCalculator
add_files ../../../../TopFunctions/BarrelConfig/TrackletCalculatorTop.cc -cflags "$CFLAGS"
build_ip TrackletCalculator_L1L2A ../../../../project
build_ip TrackletCalculator_L1L2B ../../../../project
build_ip TrackletCalculator_L1L2C ../../../../project
build_ip TrackletCalculator_L1L2D ../../../../project
build_ip TrackletCalculator_L1L2E ../../../../project
build_ip TrackletCalculator_L1L2F ../../../../project
build_ip TrackletCalculator_L1L2G ../../../../project
build_ip TrackletCalculator_L1L2H ../../../../project
build_ip TrackletCalculator_L1L2I ../../../../project
build_ip TrackletCalculator_L1L2J ../../../../project
build_ip TrackletCalculator_L1L2K ../../../../project
build_ip TrackletCalculator_L1L2L ../../../../project
build_ip TrackletCalculator_L2L3A ../../../../project
build_ip TrackletCalculator_L2L3B ../../../../project
build_ip TrackletCalculator_L2L3C ../../../../project
build_ip TrackletCalculator_L2L3D ../../../../project
build_ip TrackletCalculator_L3L4A ../../../../project
build_ip TrackletCalculator_L3L4B ../../../../project
build_ip TrackletCalculator_L3L4C ../../../../project
build_ip TrackletCalculator_L3L4D ../../../../project
build_ip TrackletCalculator_L5L6A ../../../../project
build_ip TrackletCalculator_L5L6B ../../../../project
build_ip TrackletCalculator_L5L6C ../../../../project
build_ip TrackletCalculator_L5L6D ../../../../project

# Build PRs
open_project -reset projrouter
add_files ../../../../TopFunctions/BarrelConfig/ProjectionRouterTop.cc -cflags "$CFLAGS"
build_ip ProjectionRouterTop_L1PHIA ../../../../project
build_ip ProjectionRouterTop_L1PHIB ../../../../project
build_ip ProjectionRouterTop_L1PHIC ../../../../project
build_ip ProjectionRouterTop_L1PHID ../../../../project
build_ip ProjectionRouterTop_L1PHIE ../../../../project
build_ip ProjectionRouterTop_L1PHIF ../../../../project
build_ip ProjectionRouterTop_L1PHIG ../../../../project
build_ip ProjectionRouterTop_L1PHIH ../../../../project
build_ip ProjectionRouterTop_L2PHIA ../../../../project
build_ip ProjectionRouterTop_L2PHIB ../../../../project
build_ip ProjectionRouterTop_L2PHIC ../../../../project
build_ip ProjectionRouterTop_L2PHID ../../../../project
build_ip ProjectionRouterTop_L3PHIA ../../../../project
build_ip ProjectionRouterTop_L3PHIB ../../../../project
build_ip ProjectionRouterTop_L3PHIC ../../../../project
build_ip ProjectionRouterTop_L3PHID ../../../../project
build_ip ProjectionRouterTop_L4PHIA ../../../../project
build_ip ProjectionRouterTop_L4PHIB ../../../../project
build_ip ProjectionRouterTop_L4PHIC ../../../../project
build_ip ProjectionRouterTop_L4PHID ../../../../project
build_ip ProjectionRouterTop_L5PHIA ../../../../project
build_ip ProjectionRouterTop_L5PHIB ../../../../project
build_ip ProjectionRouterTop_L5PHIC ../../../../project
build_ip ProjectionRouterTop_L5PHID ../../../../project
build_ip ProjectionRouterTop_L6PHIA ../../../../project
build_ip ProjectionRouterTop_L6PHIB ../../../../project
build_ip ProjectionRouterTop_L6PHIC ../../../../project
build_ip ProjectionRouterTop_L6PHID ../../../../project

# Build MEs
open_project -reset matchengine
add_files ../../../../TopFunctions/BarrelConfig/MatchEngineTop.cc -cflags "$CFLAGS"
build_ip MatchEngineTop_L1 ../../../../project
build_ip MatchEngineTop_L2 ../../../../project
build_ip MatchEngineTop_L3 ../../../../project
build_ip MatchEngineTop_L4 ../../../../project
build_ip MatchEngineTop_L5 ../../../../project
build_ip MatchEngineTop_L6 ../../../../project

# Build MCs
open_project -reset match_calc
add_files ../../../../TopFunctions/BarrelConfig/MatchCalculatorTop.cc -cflags "$CFLAGS"
build_ip MatchCalculator_L1PHIA ../../../../project
build_ip MatchCalculator_L1PHIB ../../../../project
build_ip MatchCalculator_L1PHIC ../../../../project
build_ip MatchCalculator_L1PHID ../../../../project
build_ip MatchCalculator_L1PHIE ../../../../project
build_ip MatchCalculator_L1PHIF ../../../../project
build_ip MatchCalculator_L1PHIG ../../../../project
build_ip MatchCalculator_L1PHIH ../../../../project
build_ip MatchCalculator_L2PHIA ../../../../project
build_ip MatchCalculator_L2PHIB ../../../../project
build_ip MatchCalculator_L2PHIC ../../../../project
build_ip MatchCalculator_L2PHID ../../../../project
build_ip MatchCalculator_L3PHIA ../../../../project
build_ip MatchCalculator_L3PHIB ../../../../project
build_ip MatchCalculator_L3PHIC ../../../../project
build_ip MatchCalculator_L3PHID ../../../../project
build_ip MatchCalculator_L4PHIA ../../../../project
build_ip MatchCalculator_L4PHIB ../../../../project
build_ip MatchCalculator_L4PHIC ../../../../project
build_ip MatchCalculator_L4PHID ../../../../project
build_ip MatchCalculator_L5PHIA ../../../../project
build_ip MatchCalculator_L5PHIB ../../../../project
build_ip MatchCalculator_L5PHIC ../../../../project
build_ip MatchCalculator_L5PHID ../../../../project
build_ip MatchCalculator_L6PHIA ../../../../project
build_ip MatchCalculator_L6PHIB ../../../../project
build_ip MatchCalculator_L6PHIC ../../../../project
build_ip MatchCalculator_L6PHID ../../../../project

# Build TB
open_project -reset trackBuilder
add_files ../../../../TopFunctions/BarrelConfig/TrackBuilderTop.cc -cflags "$CFLAGS"
build_ip TrackBuilder_L1L2 ../../../../project
build_ip TrackBuilder_L2L3 ../../../../project
build_ip TrackBuilder_L3L4 ../../../../project
build_ip TrackBuilder_L5L6 ../../../../project

exit
