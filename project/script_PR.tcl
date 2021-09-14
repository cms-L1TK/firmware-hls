# Script to generate project for PR
#   vivado_hls -f script_PR.tcl
#   vivado_hls -p projrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
  {PR_L1PHIB}
  {PR_L2PHIB}
  {PR_L3PHIB}
  {PR_L4PHIB}
  {PR_L5PHIB}
  {PR_L6PHIB}
  {PR_L1PHIC}
  {PR_L2PHIC}
  {PR_L3PHIC}
  {PR_L4PHIC}
  {PR_L5PHIC}
  {PR_L6PHIC}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export PR_L3PHIC

# create new project (deleting any existing one of same name)
open_project -reset projrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
add_files ../TrackletAlgorithm/ProjectionRouterTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/ProjectionRouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/PR/


foreach i $modules_to_test {
  puts [join [list "======== TESTING " $i " ========"] ""]
  set module $i
  set top_func [join [list "ProjectionRouterTop_" [string range $i 3 8]] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"MODULE_=" $module "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $module] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl
  csim_design -mflags "-j8"
  csynth_design
  export_design -format ip_catalog

  # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
  if { $i == $module_to_export } {
    cosim_design
    # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
    #export_design -format ip_catalog -flow impl
  }
}

exit
