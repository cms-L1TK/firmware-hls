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

# Create .xci files for user HLS IP

create_ip -name ProjectionCalculator_L5L6ABCD -module_name PC_L5L6ABCD -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIA -module_name VMSMER_L1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIB -module_name VMSMER_L1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIC -module_name VMSMER_L1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHID -module_name VMSMER_L1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIE -module_name VMSMER_L1PHIE -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIF -module_name VMSMER_L1PHIF -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIG -module_name VMSMER_L1PHIG -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L1PHIH -module_name VMSMER_L1PHIH -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L2PHIA -module_name VMSMER_L2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L2PHIB -module_name VMSMER_L2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L2PHIC -module_name VMSMER_L2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L2PHID -module_name VMSMER_L2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L3PHIA -module_name VMSMER_L3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L3PHIB -module_name VMSMER_L3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L3PHIC -module_name VMSMER_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L3PHID -module_name VMSMER_L3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L4PHIA -module_name VMSMER_L4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L4PHIB -module_name VMSMER_L4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L4PHIC -module_name VMSMER_L4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L4PHID -module_name VMSMER_L4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIA -module_name MP_L1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIB -module_name MP_L1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIC -module_name MP_L1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHID -module_name MP_L1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIE -module_name MP_L1PHIE -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIF -module_name MP_L1PHIF -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIG -module_name MP_L1PHIG -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L1PHIH -module_name MP_L1PHIH -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L2PHIA -module_name MP_L2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L2PHIB -module_name MP_L2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L2PHIC -module_name MP_L2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L2PHID -module_name MP_L2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L3PHIA -module_name MP_L3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L3PHIB -module_name MP_L3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L3PHIC -module_name MP_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L3PHID -module_name MP_L3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L4PHIA -module_name MP_L4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L4PHIB -module_name MP_L4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L4PHIC -module_name MP_L4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L4PHID -module_name MP_L4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_AAAA -module_name TB_AAAA -vendor xilinx.com -library hls -version 1.0

# Provide name of top-level HDL (without .vhd extension).
#set topLevelHDL "SectorProcessor"
set topLevelHDL "SectorProcessorFull"

# Add HDL for algo
add_files -fileset sources_1 [glob ../hdl/SectorProcessor.vhd]
add_files -fileset sources_1 [glob ../hdl/SectorProcessorFull.vhd]
add_files -fileset sources_1 [glob ../hdl/memUtil_pkg.vhd]
add_files -fileset sources_1 [glob common/hdl/*.vhd]
remove_files -fileset sources_1 [glob common/hdl/latency_monitor.vhd]
remove_files -fileset sources_1 [glob common/hdl/tf_mem_new.vhd]


# Add HDL for TB
add_files -fileset sim_1 [glob ../tb/tb_tf_top.vhd]

# Add constraints (clock etc.)
add_files -fileset constrs_1 [glob common/hdl/constraints.xdc]
add_files -fileset constrs_1 [glob floorplan.xdc]

# Set 'sim_1' fileset properties
set_property file_type {VHDL 2008} [get_files -filter {FILE_TYPE == VHDL}]
set_property top -value ${topLevelHDL} -objects [get_filesets sim_1]
set_property top -value "tb_tf_top" -objects [get_filesets sim_1]
set_property xsim.simulate.runtime -value "0us" -objects  [get_filesets sim_1]

update_compile_order -fileset sources_1 

# Create all the out-of-context runs for HLS modules
launch_runs impl_1 -scripts_only

puts "INFO: Project created: ${projName}"

exit
