# Run OOC synthesis for clock wizard
# (happens automatically when launching simulation from GUI, but not from CLI)
if {[get_filesets -quiet clk_wiz_240_360] eq ""} {
  generate_target all [get_files clk_wiz_240_360.xci]
  export_ip_user_files -of_objects [get_files clk_wiz_240_360.xci] -no_script -sync -force -quiet
  export_simulation -of_objects [get_files clk_wiz_240_360.xci] -directory $projName/$projName.ip_user_files/sim_scripts -ip_user_files_dir $projName/$projName.ip_user_files -ipstatic_source_dir $projName/$projName.ip_user_files/ipstatic -lib_map_path [list {modelsim=$projName/$projName.cache/compile_simlib/modelsim} {questa=$projName/$projName.cache/compile_simlib/questa} {ies=$projName/$projName.cache/compile_simlib/ies} {xcelium=$projName/$projName.cache/compile_simlib/xcelium} {vcs=$projName/$projName.cache/compile_simlib/vcs} {riviera=$projName/$projName.cache/compile_simlib/riviera}] -use_ip_compiled_libs -force -quiet
  create_fileset -blockset clk_wiz_240_360
  set_property top clk_wiz_240_360 [get_fileset clk_wiz_240_360]
  move_files -fileset [get_fileset clk_wiz_240_360] [get_files -of_objects [get_fileset sources_1] clk_wiz_240_360.xci]
  launch_run clk_wiz_240_360_synth_1
  wait_on_run clk_wiz_240_360_synth_1
}
