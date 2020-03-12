#######################################################################################
# Define functions to do Vivado synthesis & implementation
# with options to optimize for high frequency operation.
#
#    RUN_SETTINGS  (set Vivado compilation options)
#    RUN_SYNTHESIS (do Vivado synthesis & make timing/utilisation reports)
#    RUN_IMPLEMENTATION (do Vivado implementation & make timing/utilisation reports)
######################################################################################

proc RUN_SETTINGS {} {
  # Best strategy to meet timing at high frequency.
  set_property "strategy" "Flow_AlternateRoutability" [get_runs synth_1]
  set_property "strategy" "Performance_ExtraTimingOpt" [get_runs impl_1]

  set_property STEPS.SYNTH_DESIGN.ARGS.KEEP_EQUIVALENT_REGISTERS true [get_runs synth_1]
  set_property STEPS.SYNTH_DESIGN.ARGS.NO_LC false [get_runs synth_1]
  set_property STEPS.SYNTH_DESIGN.ARGS.SHREG_MIN_SIZE 3 [get_runs synth_1]

  set_property STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE AggressiveFanoutOpt [get_runs impl_1]
  set_property STEPS.POST_ROUTE_PHYS_OPT_DESIGN.IS_ENABLED true [get_runs impl_1]
  set_property STEPS.POST_ROUTE_PHYS_OPT_DESIGN.ARGS.DIRECTIVE Explore [get_runs impl_1]
 
  # Needed if design doesn't connect to I/O pins of FPGA.
  #set_property -name {STEPS.SYNTH_DESIGN.ARGS.MORE OPTIONS} -value {-mode out_of_context} -objects [get_runs synth_1]
}

proc RUN_SYNTHESIS {} {
  puts "=== LAUNCHING SYNTHESIS"
  launch_runs synth_1 -jobs 4
  wait_on synth_1

  # Check if synthesis ran successfully
  set STAT [get_property STATUS [get_runs synth_1] ]
  puts "=== SYNTHESIS DONE : status = $STAT "

  # Get synthesis results
  open_run synth_1 -name synth_1
  report_timing_summary -file timing_synth_1.rpt
  report_utilization -file util_synth_1.rpt
  puts "=== Timing & utilization reports in ./*synth_1.rpt"
}

proc RUN_IMPLEMENTATION {} {
  puts "=== LAUNCHING IMPLEMENTATION"
  launch_runs impl_1 -jobs 4
  wait_on impl_1

  # Check if implementation ran successfully
  set STAT [get_property STATUS [get_runs impl_1] ]
  puts "=== IMPLEMENTATION DONE : status = $STAT"

  # Get implementation results
  open_run impl_1 -name impl_1
  report_timing_summary -file timing_impl_1.rpt
  report_utilization -file util_impl_1.rpt
  puts "=== Timing & utilization reports in ./*impl_1.rpt"
}
