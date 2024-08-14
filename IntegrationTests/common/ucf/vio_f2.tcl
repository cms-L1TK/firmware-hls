set proj_dir [get_property DIRECTORY [current_project]]

create_ip -name vio -vendor xilinx.com -library ip -version 3.0 -module_name vio_0
set_property -dict [list CONFIG.C_PROBE_OUT15_WIDTH {76} CONFIG.C_PROBE_OUT14_WIDTH {76} CONFIG.C_PROBE_OUT13_WIDTH {76} CONFIG.C_PROBE_OUT12_WIDTH {76} CONFIG.C_PROBE_OUT11_WIDTH {76} CONFIG.C_PROBE_OUT10_WIDTH {76} CONFIG.C_PROBE_OUT9_WIDTH {37} CONFIG.C_PROBE_OUT8_WIDTH {37} CONFIG.C_PROBE_OUT7_WIDTH {37} CONFIG.C_PROBE_OUT6_WIDTH {37} CONFIG.C_PROBE_OUT5_WIDTH {37} CONFIG.C_PROBE_OUT4_WIDTH {37} CONFIG.C_PROBE_OUT3_WIDTH {37} CONFIG.C_PROBE_OUT2_WIDTH {37} CONFIG.C_PROBE_OUT1_WIDTH {37} CONFIG.C_PROBE_OUT0_WIDTH {37} CONFIG.C_NUM_PROBE_OUT {16} CONFIG.C_EN_PROBE_IN_ACTIVITY {0} CONFIG.C_NUM_PROBE_IN {0}] [get_ips vio_0]
generate_target {instantiation_template} [get_files $proj_dir/tf_f2/tf_f2.srcs/sources_1/ip/vio_0/vio_0.xci]

generate_target all [get_files $proj_dir/tf_f2/tf_f2.srcs/sources_1/ip/vio_0/vio_0.xci]

catch { config_ip_cache -export [get_ips -all vio_0] }
export_ip_user_files -of_objects [get_files $proj_dir/tf_f2/tf_f2.srcs/sources_1/ip/vio_0/vio_0.xci] -no_script -sync -force -quiet
create_ip_run [get_files -of_objects [get_fileset sources_1] $proj_dir/tf_f2/tf_f2.srcs/sources_1/ip/vio_0/vio_0.xci]
launch_runs vio_0_synth_1 -jobs 63

export_simulation -of_objects [get_files $proj_dir/tf_f2/tf_f2.srcs/sources_1/ip/vio_0/vio_0.xci] -directory $proj_dir/tf_f2/tf_f2.ip_user_files/sim_scripts -ip_user_files_dir $proj_dir/tf_f2/tf_f2.ip_user_files -ipstatic_source_dir $proj_dir/tf_f2/tf_f2.ip_user_files/ipstatic -lib_map_path [list {modelsim=$proj_dir/tf_f2/tf_f2.cache/compile_simlib/modelsim} {questa=$proj_dir/tf_f2/tf_f2.cache/compile_simlib/questa} {ies=$proj_dir/tf_f2/tf_f2.cache/compile_simlib/ies} {xcelium=$proj_dir/tf_f2/tf_f2.cache/compile_simlib/xcelium} {vcs=$proj_dir/tf_f2/tf_f2.cache/compile_simlib/vcs} {riviera=$proj_dir/tf_f2/tf_f2.cache/compile_simlib/riviera}] -use_ip_compiled_libs -force -quiet
