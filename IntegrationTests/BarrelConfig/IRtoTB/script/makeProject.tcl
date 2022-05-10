# Create Vivado project, with user HDL files & IP.
# Run this in IntegrationTests/xyz/script/ 

# Create project
set projName "Work"
source ../../../../project/fpga.tcl
create_project -force ${projName} ./${projName} -part $FPGA
set_property target_language VHDL [current_project]

# Rebuild user HLS IP repos index before adding any source files
set_property ip_repo_paths "./"  [get_filesets sources_1]
update_ip_catalog -rebuild

# Create .xci files for user HLS IP
create_ip -name InputRouterTop_IR_DTC_2S_1_A -module_name IR_2S_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_1_B -module_name IR_2S_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_2_A -module_name IR_2S_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_2_B -module_name IR_2S_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_3_A -module_name IR_2S_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_3_B -module_name IR_2S_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_4_A -module_name IR_2S_4_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_4_B -module_name IR_2S_4_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_1_A -module_name IR_neg2S_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_1_B -module_name IR_neg2S_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_2_A -module_name IR_neg2S_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_2_B -module_name IR_neg2S_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_3_A -module_name IR_neg2S_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_3_B -module_name IR_neg2S_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_4_A -module_name IR_neg2S_4_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_4_B -module_name IR_neg2S_4_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_1_A -module_name IR_negPS10G_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_1_B -module_name IR_negPS10G_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_2_A -module_name IR_negPS10G_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_2_B -module_name IR_negPS10G_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_3_A -module_name IR_negPS10G_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_3_B -module_name IR_negPS10G_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_1_A -module_name IR_negPS_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_1_B -module_name IR_negPS_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_2_A -module_name IR_negPS_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_2_B -module_name IR_negPS_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_1_A -module_name IR_PS10G_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_1_B -module_name IR_PS10G_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_2_A -module_name IR_PS10G_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_2_B -module_name IR_PS10G_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_3_A -module_name IR_PS10G_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_3_B -module_name IR_PS10G_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_1_A -module_name IR_PS_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_1_B -module_name IR_PS_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_2_A -module_name IR_PS_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_2_B -module_name IR_PS_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIA -module_name VMR_L1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIB -module_name VMR_L1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIC -module_name VMR_L1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHID -module_name VMR_L1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIE -module_name VMR_L1PHIE -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIF -module_name VMR_L1PHIF -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIG -module_name VMR_L1PHIG -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L1PHIH -module_name VMR_L1PHIH -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L2PHIA -module_name VMR_L2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L2PHIB -module_name VMR_L2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L2PHIC -module_name VMR_L2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L2PHID -module_name VMR_L2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L3PHIA -module_name VMR_L3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L3PHIB -module_name VMR_L3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L3PHIC -module_name VMR_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L3PHID -module_name VMR_L3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L4PHIA -module_name VMR_L4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L4PHIB -module_name VMR_L4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L4PHIC -module_name VMR_L4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L4PHID -module_name VMR_L4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L5PHIA -module_name VMR_L5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L5PHIB -module_name VMR_L5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L5PHIC -module_name VMR_L5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L5PHID -module_name VMR_L5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L6PHIA -module_name VMR_L6PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L6PHIB -module_name VMR_L6PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L6PHIC -module_name VMR_L6PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterTop_L6PHID -module_name VMR_L6PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletEngine_PS_PS -module_name TE_PS_PS -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletEngine_PS_2S -module_name TE_PS_2S -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletEngine_2S_2S -module_name TE_2S_2S -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2A -module_name TC_L1L2A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2B -module_name TC_L1L2B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2C -module_name TC_L1L2C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2D -module_name TC_L1L2D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2E -module_name TC_L1L2E -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2F -module_name TC_L1L2F -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2G -module_name TC_L1L2G -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2H -module_name TC_L1L2H -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2I -module_name TC_L1L2I -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2J -module_name TC_L1L2J -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2K -module_name TC_L1L2K -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L1L2L -module_name TC_L1L2L -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L2L3A -module_name TC_L2L3A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L2L3B -module_name TC_L2L3B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L2L3C -module_name TC_L2L3C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L2L3D -module_name TC_L2L3D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L3L4A -module_name TC_L3L4A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L3L4B -module_name TC_L3L4B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L3L4C -module_name TC_L3L4C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L3L4D -module_name TC_L3L4D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L5L6A -module_name TC_L5L6A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L5L6B -module_name TC_L5L6B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L5L6C -module_name TC_L5L6C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletCalculator_L5L6D -module_name TC_L5L6D -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIA -module_name PR_L1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIB -module_name PR_L1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIC -module_name PR_L1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHID -module_name PR_L1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIE -module_name PR_L1PHIE -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIF -module_name PR_L1PHIF -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIG -module_name PR_L1PHIG -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L1PHIH -module_name PR_L1PHIH -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L2PHIA -module_name PR_L2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L2PHIB -module_name PR_L2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L2PHIC -module_name PR_L2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L2PHID -module_name PR_L2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L3PHIA -module_name PR_L3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L3PHIB -module_name PR_L3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L3PHIC -module_name PR_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L3PHID -module_name PR_L3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L4PHIA -module_name PR_L4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L4PHIB -module_name PR_L4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L4PHIC -module_name PR_L4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L4PHID -module_name PR_L4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L5PHIA -module_name PR_L5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L5PHIB -module_name PR_L5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L5PHIC -module_name PR_L5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L5PHID -module_name PR_L5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L6PHIA -module_name PR_L6PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L6PHIB -module_name PR_L6PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L6PHIC -module_name PR_L6PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop_L6PHID -module_name PR_L6PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop_L1 -module_name ME_L1 -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop_L2 -module_name ME_L2 -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop_L3 -module_name ME_L3 -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop_L4 -module_name ME_L4 -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop_L5 -module_name ME_L5 -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop_L6 -module_name ME_L6 -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIA -module_name MC_L1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIB -module_name MC_L1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIC -module_name MC_L1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHID -module_name MC_L1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIE -module_name MC_L1PHIE -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIF -module_name MC_L1PHIF -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIG -module_name MC_L1PHIG -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L1PHIH -module_name MC_L1PHIH -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L2PHIA -module_name MC_L2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L2PHIB -module_name MC_L2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L2PHIC -module_name MC_L2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L2PHID -module_name MC_L2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L3PHIA -module_name MC_L3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L3PHIB -module_name MC_L3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L3PHIC -module_name MC_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L3PHID -module_name MC_L3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L4PHIA -module_name MC_L4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L4PHIB -module_name MC_L4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L4PHIC -module_name MC_L4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L4PHID -module_name MC_L4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L5PHIA -module_name MC_L5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L5PHIB -module_name MC_L5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L5PHIC -module_name MC_L5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L5PHID -module_name MC_L5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L6PHIA -module_name MC_L6PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L6PHIB -module_name MC_L6PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L6PHIC -module_name MC_L6PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchCalculator_L6PHID -module_name MC_L6PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_L1L2 -module_name FT_L1L2 -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_L2L3 -module_name FT_L2L3 -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_L3L4 -module_name FT_L3L4 -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_L5L6 -module_name FT_L5L6 -vendor xilinx.com -library hls -version 1.0

# Provide name of top-level HDL (without .vhd extension).
set topLevelHDL "SectorProcessor"
#set topLevelHDL "SectorProcessorFull"

# Add HDL for algo
add_files -fileset sources_1 [glob ../hdl/SectorProcessor*.vhd]
add_files -fileset sources_1 [glob ../hdl/memUtil_pkg.vhd]
add_files -fileset sources_1 [glob common/hdl/*.vhd]
remove_files -fileset sources_1 [glob common/hdl/latency_monitor.vhd]

# Add HDL for TB
add_files -fileset sim_1 [glob ../tb/tb_tf_top.vhd]

# Add utility files
add_files -fileset utils_1 [glob ./pre.tcl]

# Add constraints (clock etc.)
add_files -fileset constrs_1 [glob common/hdl/constraints.xdc]

# Set 'sim_1' fileset properties
set_property file_type {VHDL 2008} [get_files -filter {FILE_TYPE == VHDL}]
set_property top -value ${topLevelHDL} -objects [get_filesets sources_1]
set_property top -value "tb_tf_top" -objects [get_filesets sim_1]
set_property xsim.simulate.runtime -value "0us" -objects  [get_filesets sim_1]

update_compile_order -fileset sources_1 

puts "INFO: Project created: ${projName}"

exit
