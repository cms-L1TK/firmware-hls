#####################
# Implement project #
#####################

# Set the reference directory for source file relative paths (by default the value is script directory path)
set origin_dir "."

set _xil_proj_name_ Work

# Open project
open_project ./${_xil_proj_name_}/${_xil_proj_name_}.xpr

reset_run impl_1

# Best strategy to meet timing at high frequency (but slows compilation).
#set_property "strategy" "Performance_ExtraTimingOpt" [get_runs impl_1]
#set_property STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE AggressiveFanoutOpt [get_runs impl_1]
#set_property STEPS.POST_ROUTE_PHYS_OPT_DESIGN.IS_ENABLED true [get_runs impl_1]
#set_property STEPS.POST_ROUTE_PHYS_OPT_DESIGN.ARGS.DIRECTIVE Explore [get_runs impl_1]

# Implementation
update_compile_order -fileset sources_1
launch_runs impl_1 -jobs 32
wait_on_run impl_1

# Make reports
open_run impl_1
report_timing_summary -file timing_impl.rpt
report_utilization -hierarchical -file utilization_impl.rpt

exit
