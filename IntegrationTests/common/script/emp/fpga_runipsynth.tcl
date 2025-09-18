#minimal script to run synthesis

set origin_dir "."
set proj_name "tf_1"

open_project $origin_dir/$proj_name.xpr
update_compile_order -fileset sources_1

# Create and launch all OOC runs for all IPs
launch_runs synth_1 -scripts_only
reset_runs [get_runs *_synth_1]
launch_runs -jobs 24 [get_runs *_synth_1]
wait_on_runs [get_runs *_synth_1]

exit
