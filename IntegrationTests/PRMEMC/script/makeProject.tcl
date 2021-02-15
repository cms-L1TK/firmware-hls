# Create Vivado project, with user HDL files & IP.
# Run this in IntegrationTests/xyz/script/ 

# Create project
set projName "Work"
set FPGA "xcvu7p-flvb2104-1-e"
create_project -force ${projName} ./${projName} -part $FPGA
set_property target_language VHDL [current_project]

# Rebuild user HLS IP repos index before adding any source files
set_property ip_repo_paths "../../../project/"  [get_filesets sources_1]
update_ip_catalog -rebuild

# Create .xci files for user HLS IP
# FIX: HLS project scripts should produce IP with name like MC_L3PHIC
create_ip -name MatchCalculatorTop -module_name MC_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name MatchEngineTop -module_name ME_L3PHIC -vendor xilinx.com -library hls -version 1.0
create_ip -name ProjectionRouterTop -module_name PR_L3PHIC -vendor xilinx.com -library hls -version 1.0

# Add HDL for algo
add_files -fileset sources_1 [glob ../../common/hdl/*.vhd]
add_files -fileset sources_1 [glob ../hdl/*.vhd]

# Add HDL for TB
add_files -fileset sim_1 [glob ../tb/*.vhd]

# Set 'sim_1' fileset properties
set_property file_type {VHDL 2008} [get_files -filter {FILE_TYPE == VHDL}]
set_property top -value "SectorProcessor" -objects [get_filesets sources_1]
set_property top -value "tb_tf_top" -objects [get_filesets sim_1]
set_property xsim.simulate.runtime -value "50us" -objects  [get_filesets sim_1]

update_compile_order -fileset sources_1 

puts "INFO: Project created: ${projName}"

exit
