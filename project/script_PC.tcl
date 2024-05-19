# Script to generate project for PC
#   vivado_hls -f script_PC.tcl
#   vivado_hls -p trackletCalculator
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
  {PC_L1L2ABC}
  {PC_L1L2DE}
  {PC_L1L2F}
  {PC_L1L2G}
  {PC_L1L2HI}
  {PC_L1L2JKL}
  {PC_L2L3ABCD}
}

# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export PC_L1L2ABC

# create new project (deleting any existing one of same name)
open_project -reset projectionCalculator

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TrackletAlgorithm/TestBench -I../TopFunctions/CombinedConfig_FPGA2/}
add_files ../TopFunctions/CombinedConfig_FPGA2/ProjectionCalculatorTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/ProjectionCalculator_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/PC/tables/
add_files -tb ../emData/PC/

foreach i $modules_to_test {
  puts [join [list "======== TESTING " $i " ========"] ""]
  set seed [string range $i 3 6]
  set iTC [string range $i 7 9]
  set top_func [join [list "ProjectionCalculator_" $seed $iTC] ""]
  set module [join [list "PC_" $seed $iTC] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list $::env(CCFLAG_CMSSW) " -D \"SEED_=" $seed "_\" -D \"ITC_=" $iTC "_\" -D \"MODULE_=" $module "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $seed $iTC] ""]

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
