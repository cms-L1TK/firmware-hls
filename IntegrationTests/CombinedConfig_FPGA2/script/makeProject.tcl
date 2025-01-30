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

create_ip -name ProjectionCalculator_L1L2ABC -module_name PC_L1L2ABC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1L2DE -module_name PC_L1L2DE -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1L2F -module_name PC_L1L2F -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1L2G -module_name PC_L1L2G -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1L2HI -module_name PC_L1L2HI -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1L2JKL -module_name PC_L1L2JKL -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L2L3ABCD -module_name PC_L2L3ABCD -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L3L4AB -module_name PC_L3L4AB -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L3L4CD -module_name PC_L3L4CD -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L5L6ABCD -module_name PC_L5L6ABCD -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_D1D2ABCD -module_name PC_D1D2ABCD -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_D3D4ABCD -module_name PC_D3D4ABCD -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1D1ABCD -module_name PC_L1D1ABCD -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L1D1EFGH -module_name PC_L1D1EFGH -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionCalculator_L2D1ABCD -module_name PC_L2D1ABCD -vendor xilinx.com -library hls -version 1.0
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
create_ip -name VMStubMERouterTop_L5PHIA -module_name VMSMER_L5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L5PHIB -module_name VMSMER_L5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L5PHIC -module_name VMSMER_L5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L5PHID -module_name VMSMER_L5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L6PHIA -module_name VMSMER_L6PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L6PHIB -module_name VMSMER_L6PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L6PHIC -module_name VMSMER_L6PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_L6PHID -module_name VMSMER_L6PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D1PHIA -module_name VMSMER_D1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D1PHIB -module_name VMSMER_D1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D1PHIC -module_name VMSMER_D1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D1PHID -module_name VMSMER_D1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D2PHIA -module_name VMSMER_D2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D2PHIB -module_name VMSMER_D2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D2PHIC -module_name VMSMER_D2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D2PHID -module_name VMSMER_D2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D3PHIA -module_name VMSMER_D3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D3PHIB -module_name VMSMER_D3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D3PHIC -module_name VMSMER_D3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D3PHID -module_name VMSMER_D3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D4PHIA -module_name VMSMER_D4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D4PHIB -module_name VMSMER_D4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D4PHIC -module_name VMSMER_D4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D4PHID -module_name VMSMER_D4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D5PHIA -module_name VMSMER_D5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D5PHIB -module_name VMSMER_D5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D5PHIC -module_name VMSMER_D5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name VMStubMERouterTop_D5PHID -module_name VMSMER_D5PHID -vendor xilinx.com -library hls -version 1.0
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
create_ip -name MatchProcessor_L5PHIA -module_name MP_L5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L5PHIB -module_name MP_L5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L5PHIC -module_name MP_L5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L5PHID -module_name MP_L5PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L6PHIA -module_name MP_L6PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L6PHIB -module_name MP_L6PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L6PHIC -module_name MP_L6PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_L6PHID -module_name MP_L6PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D1PHIA -module_name MP_D1PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D1PHIB -module_name MP_D1PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D1PHIC -module_name MP_D1PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D1PHID -module_name MP_D1PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D2PHIA -module_name MP_D2PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D2PHIB -module_name MP_D2PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D2PHIC -module_name MP_D2PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D2PHID -module_name MP_D2PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D3PHIA -module_name MP_D3PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D3PHIB -module_name MP_D3PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D3PHIC -module_name MP_D3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D3PHID -module_name MP_D3PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D4PHIA -module_name MP_D4PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D4PHIB -module_name MP_D4PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D4PHIC -module_name MP_D4PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D4PHID -module_name MP_D4PHID -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D5PHIA -module_name MP_D5PHIA -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D5PHIB -module_name MP_D5PHIB -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D5PHIC -module_name MP_D5PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchProcessor_D5PHID -module_name MP_D5PHID -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L3PHIB_E -module_name MP_L3PHIB_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L3PHIC_E -module_name MP_L3PHIC_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L4PHIB_E -module_name MP_L4PHIB_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L4PHIC_E -module_name MP_L4PHIC_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L5PHIB_E -module_name MP_L5PHIB_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L5PHIC_E -module_name MP_L5PHIC_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L6PHIB_E -module_name MP_L6PHIB_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_L6PHIC_E -module_name MP_L6PHIC_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_D3PHIB_E -module_name MP_D3PHIB_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_D3PHIC_E -module_name MP_D3PHIC_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_D4PHIB_E -module_name MP_D4PHIB_E -vendor xilinx.com -library hls -version 1.0
#create_ip -name MatchProcessor_D4PHIC_E -module_name MP_D4PHIC_E -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_AAAA -module_name TB_AAAA -vendor xilinx.com -library hls -version 1.0
create_ip -name TrackBuilder_BBBB -module_name TB_BBBB -vendor xilinx.com -library hls -version 1.0

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

puts "INFO: Project created: ${projName}"

exit
