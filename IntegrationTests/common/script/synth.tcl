# Set the reference directory for source file relative paths (by default the value is script directory path)
set origin_dir "."

# Set the project name
set _xil_proj_name_ [lindex $argv 0]

# Open project
open_project ./${_xil_proj_name_}/${_xil_proj_name_}.xpr

# Synthesis
update_compile_order -fileset sources_1
launch_runs synth_1 -jobs 4
wait_on_run synth_1
open_run synth_1
report_utilization -hierarchical -file report_utilization_hierarchical.txt

exit
