# Create Vivado project, with user HDL files & IP.
# Run this in IntegrationTests/xyz/script/ 

# Create project
set projName "Work"
set FPGA "xcvu13p-flga2577-2-e"
create_project -force ${projName} ./${projName} -part $FPGA
set_property target_language VHDL [current_project]

# Rebuild user HLS IP repos index before adding any source files
set_property ip_repo_paths "./"  [get_filesets sources_1]
update_ip_catalog -rebuild

create_ip -name InputRouterTop_IR_DTC_PS10G_1_A  -module_name IR_PS10G_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_1_B  -module_name IR_PS10G_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_2_A  -module_name IR_PS10G_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_2_B  -module_name IR_PS10G_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_3_A  -module_name IR_PS10G_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_3_B  -module_name IR_PS10G_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_4_A  -module_name IR_PS10G_4_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS10G_4_B  -module_name IR_PS10G_4_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_1_A  -module_name IR_PS_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_1_B  -module_name IR_PS_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_2_A  -module_name IR_PS_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_PS_2_B  -module_name IR_PS_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_1_A  -module_name IR_negPS10G_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_1_B  -module_name IR_negPS10G_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_2_A  -module_name IR_negPS10G_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_2_B  -module_name IR_negPS10G_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_3_A  -module_name IR_negPS10G_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_3_B  -module_name IR_negPS10G_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_4_A  -module_name IR_negPS10G_4_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS10G_4_B  -module_name IR_negPS10G_4_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_1_A  -module_name IR_negPS_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_1_B  -module_name IR_negPS_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_2_A  -module_name IR_negPS_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_negPS_2_B  -module_name IR_negPS_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_1_A  -module_name IR_2S_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_1_B  -module_name IR_2S_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_2_A  -module_name IR_2S_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_2_B  -module_name IR_2S_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_3_A  -module_name IR_2S_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_3_B  -module_name IR_2S_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_4_A  -module_name IR_2S_4_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_4_B  -module_name IR_2S_4_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_5_A  -module_name IR_2S_5_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_5_B  -module_name IR_2S_5_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_6_A  -module_name IR_2S_6_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_2S_6_B  -module_name IR_2S_6_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_1_A  -module_name IR_neg2S_1_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_1_B  -module_name IR_neg2S_1_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_2_A  -module_name IR_neg2S_2_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_2_B  -module_name IR_neg2S_2_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_3_A  -module_name IR_neg2S_3_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_3_B  -module_name IR_neg2S_3_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_4_A  -module_name IR_neg2S_4_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_4_B  -module_name IR_neg2S_4_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_5_A  -module_name IR_neg2S_5_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_5_B  -module_name IR_neg2S_5_B -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_6_A  -module_name IR_neg2S_6_A -vendor xilinx.com -library hls -version 1.0
create_ip -name InputRouterTop_IR_DTC_neg2S_6_B  -module_name IR_neg2S_6_B -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIA  -module_name VMR_L1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIB  -module_name VMR_L1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIC  -module_name VMR_L1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHID  -module_name VMR_L1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIE  -module_name VMR_L1PHIE -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIF  -module_name VMR_L1PHIF -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIG  -module_name VMR_L1PHIG -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L1PHIH  -module_name VMR_L1PHIH -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L2PHIA  -module_name VMR_L2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L2PHIB  -module_name VMR_L2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L2PHIC  -module_name VMR_L2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L2PHID  -module_name VMR_L2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L3PHIA  -module_name VMR_L3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L3PHIB  -module_name VMR_L3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L3PHIC  -module_name VMR_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L3PHID  -module_name VMR_L3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L4PHIA  -module_name VMR_L4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L4PHIB  -module_name VMR_L4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L4PHIC  -module_name VMR_L4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L4PHID  -module_name VMR_L4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L5PHIA  -module_name VMR_L5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L5PHIB  -module_name VMR_L5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L5PHIC  -module_name VMR_L5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L5PHID  -module_name VMR_L5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L6PHIA  -module_name VMR_L6PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L6PHIB  -module_name VMR_L6PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L6PHIC  -module_name VMR_L6PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_L6PHID  -module_name VMR_L6PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D1PHIA  -module_name VMR_D1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D1PHIB  -module_name VMR_D1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D1PHIC  -module_name VMR_D1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D1PHID  -module_name VMR_D1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D2PHIA  -module_name VMR_D2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D2PHIB  -module_name VMR_D2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D2PHIC  -module_name VMR_D2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D2PHID  -module_name VMR_D2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D3PHIA  -module_name VMR_D3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D3PHIB  -module_name VMR_D3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D3PHIC  -module_name VMR_D3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D3PHID  -module_name VMR_D3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D4PHIA  -module_name VMR_D4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D4PHIB  -module_name VMR_D4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D4PHIC  -module_name VMR_D4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D4PHID  -module_name VMR_D4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D5PHIA  -module_name VMR_D5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D5PHIB  -module_name VMR_D5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D5PHIC  -module_name VMR_D5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMRouterCMTop_D5PHID  -module_name VMR_D5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2A  -module_name TP_L1L2A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2B  -module_name TP_L1L2B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2C  -module_name TP_L1L2C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2D  -module_name TP_L1L2D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2E  -module_name TP_L1L2E -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2F  -module_name TP_L1L2F -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2G  -module_name TP_L1L2G -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2H  -module_name TP_L1L2H -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2I  -module_name TP_L1L2I -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2J  -module_name TP_L1L2J -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2K  -module_name TP_L1L2K -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1L2L  -module_name TP_L1L2L -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2L3A  -module_name TP_L2L3A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2L3B  -module_name TP_L2L3B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2L3C  -module_name TP_L2L3C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2L3D  -module_name TP_L2L3D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L3L4A  -module_name TP_L3L4A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L3L4B  -module_name TP_L3L4B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L3L4C  -module_name TP_L3L4C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L3L4D  -module_name TP_L3L4D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L5L6A  -module_name TP_L5L6A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L5L6B  -module_name TP_L5L6B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L5L6C  -module_name TP_L5L6C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L5L6D  -module_name TP_L5L6D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D1D2A  -module_name TP_D1D2A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D1D2B  -module_name TP_D1D2B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D1D2C  -module_name TP_D1D2C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D1D2D  -module_name TP_D1D2D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D3D4A  -module_name TP_D3D4A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D3D4B  -module_name TP_D3D4B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D3D4C  -module_name TP_D3D4C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_D3D4D  -module_name TP_D3D4D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1A  -module_name TP_L1D1A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1B  -module_name TP_L1D1B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1C  -module_name TP_L1D1C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1D  -module_name TP_L1D1D -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1E  -module_name TP_L1D1E -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1F  -module_name TP_L1D1F -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1G  -module_name TP_L1D1G -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L1D1H  -module_name TP_L1D1H -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2D1A  -module_name TP_L2D1A -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2D1B  -module_name TP_L2D1B -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2D1C  -module_name TP_L2D1C -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackletProcessor_L2D1D  -module_name TP_L2D1D -vendor xilinx.com -library hls -version 1.0


# Provide name of top-level HDL (without .vhd extension).
#set topLevelHDL "SectorProcessor"
set topLevelHDL "SectorProcessorFull"

# Add HDL for algo
add_files -fileset sources_1 [glob ../hdl/SectorProcessor.vhd]
add_files -fileset sources_1 [glob ../hdl/SectorProcessorFull.vhd]
add_files -fileset sources_1 [glob ../hdl/memUtil_pkg.vhd]
add_files -fileset sources_1 [glob common/hdl/FileReaderFIFO.vhd]
add_files -fileset sources_1 [glob common/hdl/FileWriterFIFO.vhd]
add_files -fileset sources_1 [glob common/hdl/pipelining.vhd]
add_files -fileset sources_1 [glob common/hdl/tf_mem_bin.vhd]
add_files -fileset sources_1 [glob common/hdl/tf_mem.vhd]
add_files -fileset sources_1 [glob common/hdl/tf_mem_format.vhd]
add_files -fileset sources_1 [glob common/hdl/tf_merge_streamer.vhd]
add_files -fileset sources_1 [glob common/hdl/tf_pkg.vhd]

# Add post-synthesis script
add_files -fileset utils_1 [glob common/script/post.tcl]

# Add HDL for TB
add_files -fileset sim_1 [glob ../tb/tb_tf_top.vhd]

# Add constraints (clock etc.)
add_files -fileset constrs_1 [glob common/hdl/constraints.xdc]
add_files -fileset constrs_1 [glob soft_floorplan.xdc]

# Set 'sim_1' fileset properties
set_property file_type {VHDL 2008} [get_files -filter {FILE_TYPE == VHDL}]
set_property top -value ${topLevelHDL} -objects [get_filesets sim_1]
set_property top -value "tb_tf_top" -objects [get_filesets sim_1]
set_property used_in_synthesis false [get_files FileReaderFIFO.vhd]
set_property used_in_synthesis false [get_files FileWriterFIFO.vhd]
set_property xsim.simulate.runtime -value "0us" -objects  [get_filesets sim_1]

# Set 'synth_1` fileset properties
set_property STEPS.SYNTH_DESIGN.TCL.POST [get_files post.tcl -of [get_fileset utils_1] ] [get_runs synth_1]

update_compile_order -fileset sources_1 

puts "INFO: Project created: ${projName}"

exit

