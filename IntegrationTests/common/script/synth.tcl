######################
# Synthesize project #
######################

# Set the reference directory for source file relative paths (by default the value is script directory path)
set origin_dir "."

set _xil_proj_name_ Work

# Open project
open_project ./${_xil_proj_name_}/${_xil_proj_name_}.xpr

reset_run synth_1

# Best strategy to meet timing at high frequency (but slows compilation).
set_property "strategy" "Flow_PerfOptimized_high" [get_runs synth_1]
#set_property STEPS.SYNTH_DESIGN.ARGS.KEEP_EQUIVALENT_REGISTERS true [get_runs synth_1]
#set_property STEPS.SYNTH_DESIGN.ARGS.NO_LC false [get_runs synth_1]
#set_property STEPS.SYNTH_DESIGN.ARGS.SHREG_MIN_SIZE 3 [get_runs synth_1]

# Needed if design doesn't connect to I/O pins of FPGA.
set_property -name {STEPS.SYNTH_DESIGN.ARGS.MORE OPTIONS} -value {-mode out_of_context} -objects [get_runs synth_1]

# Run pre.tcl if it exists
set_property -name {STEPS.SYNTH_DESIGN.TCL.PRE} -value [get_files pre.tcl -of [get_fileset utils_1]] -objects [get_runs synth_1]

# Synthesis
update_compile_order -fileset sources_1
launch_runs synth_1 -jobs 21
wait_on_run synth_1

# Make reports
open_run synth_1
report_timing_summary -file timing_synth.rpt
report_utilization -hierarchical -file utilization_synth.rpt

exit
