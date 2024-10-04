set_property SOURCE_SET sources_1 [get_filesets sim_1]
add_files -fileset sim_1 -norecurse ../../src/firmware-hls/IntegrationTests/DualFPGA/firmware/mem/in_fpga2.txt
set lut_script [file dirname [file normalize ../../src/firmware-hls/IntegrationTests/DualFPGA/firmware/scripts/pre_msim.tcl ]]
append lut_script "/pre_msim.tcl"
add_files -fileset utils_1 -norecurse $lut_script
#set_property STEPS.SYNTH_DESIGN.TCL.PRE $lut_script [get_runs sim_1]
#add_files -fileset sim_1 -norecurse ../../src/firmware-hls/firmware/mem/out.txt
set pre_path "set_property -name {xsim.compile.tcl.pre} -value {$lut_script} -objects \[\get_filesets \sim_1\]"
eval ${pre_path}

# Disabling source management mode.  This is to allow the top design properties to be set without GUI intervention.
set_property source_mgmt_mode None [current_project]
set_property top top [get_filesets sim_1]
set_property top_lib xil_defaultlib [get_filesets sim_1]
set_property target_language VHDL [current_project]
set_property simulator_language VHDL [current_project]
# Re-enabling previously disabled source management mode.
set_property source_mgmt_mode All [current_project]
