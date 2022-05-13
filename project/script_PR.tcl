# Script to generate project for PR
#   vivado_hls -f script_PR.tcl
#   vivado_hls -p projrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
  {PR_L1PHIA}
  {PR_L1PHIB}
  {PR_L1PHIC}
  {PR_L1PHID}
  {PR_L1PHIE}
  {PR_L1PHIF}
  {PR_L1PHIG}
  {PR_L1PHIH}
  {PR_L2PHIA}
  {PR_L2PHIB}
  {PR_L2PHIC}
  {PR_L2PHID}
  {PR_L3PHIA}
  {PR_L3PHIB}
  {PR_L3PHIC}
  {PR_L3PHID}
  {PR_L4PHIA}
  {PR_L4PHIB}
  {PR_L4PHIC}
  {PR_L4PHID}
  {PR_L5PHIA}
  {PR_L5PHIB}
  {PR_L5PHIC}
  {PR_L5PHID}
  {PR_L6PHIA}
  {PR_L6PHIB}
  {PR_L6PHIC}
  {PR_L6PHID}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export PR_L3PHIC

# create new project (deleting any existing one of same name)
if { $tool == "Vivado" } {
        open_project -reset projrouter_vivado
} elseif { $tool == "Vitis" } {
        open_project -reset projrouter_vitis
} else {
        puts "Neither vivado nor vitis is being used."
}


# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
add_files ../TopFunctions/ProjectionRouterTop.cc -cflags "$CFLAGS"
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
