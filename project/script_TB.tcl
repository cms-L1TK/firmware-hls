# Script to generate project for TB
#   vivado_hls -f script_TB.tcl
#   vivado_hls -p trackBuilder
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# FIXME: FT_D1D2 is excluded for now because it currently produces extra
# entries compared to the emulation
set modules_to_test {
  {TB_AAAA}
  {TB_BBBB}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export FT_L1L2

# create new project (deleting any existing one of same name)
open_project -reset trackBuilder

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TrackletAlgorithm/TestBench -I../TopFunctions/CombinedConfig_FPGA2}
add_files ../TopFunctions/CombinedConfig_FPGA2/TrackBuilderTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackBuilder_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/TB/

foreach i $modules_to_test {
  puts [join [list "======== TESTING " $i " ========"] ""]
  set seed [string range $i 3 6]
  set top_func [join [list "TrackBuilder_" $seed] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list $::env(CCFLAG_CMSSW) " -D \"SEED_=" $seed "_\" -D \"MODULE_=" $i "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $seed] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl
  csim_design -mflags "-j8"

  # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
  if { $i == $module_to_export } {
    csynth_design
    cosim_design
    export_design -format ip_catalog
    # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
    #export_design -format ip_catalog -flow impl
  }
}

exit
