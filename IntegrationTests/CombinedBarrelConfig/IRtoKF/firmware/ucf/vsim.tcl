set_property SOURCE_SET sources_1 [get_filesets sim_1]
add_files -fileset sim_1 -norecurse ../../src/firmware-hls/IntegrationTests/CombinedBarrelConfig/IRtoKF/firmware/mem/in.txt

# Disabling source management mode.  This is to allow the top design properties to be set without GUI intervention.
set_property source_mgmt_mode None [current_project]
set_property top top [get_filesets sim_1]
set_property top_lib xil_defaultlib [get_filesets sim_1]
set_property target_language VHDL [current_project]
set_property simulator_language VHDL [current_project]
# Re-enabling previously disabled source management mode.
set_property source_mgmt_mode All [current_project]
