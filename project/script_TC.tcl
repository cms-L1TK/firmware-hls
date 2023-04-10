# Script to generate project for TC
#   vivado_hls -f script_TC.tcl
#   vivado_hls -p trackletCalculator
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
  {TC_L1L2A}
  {TC_L1L2B}
  {TC_L1L2C}
  {TC_L1L2D}
  {TC_L1L2E}
  {TC_L1L2F}
  {TC_L1L2G}
  {TC_L1L2H}
  {TC_L1L2I}
  {TC_L1L2J}
  {TC_L1L2K}
  {TC_L1L2L}
  {TC_L2L3A}
  {TC_L2L3B}
  {TC_L2L3C}
  {TC_L2L3D}
  {TC_L3L4A}
  {TC_L3L4B}
  {TC_L3L4C}
  {TC_L3L4D}
  {TC_L5L6A}
  {TC_L5L6B}
  {TC_L5L6C}
  {TC_L5L6D}
}
# delete me
set modules_to_test {
  {TC_L1L2E}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export TC_L1L2E

# create new project (deleting any existing one of same name)
set project_name "trackletCalculator"
append project_name $VitisOrVivado
open_project -reset $project_name

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
add_files ../TopFunctions/TrackletCalculatorTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletCalculator_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/TC/tables/
add_files -tb ../emData/TC/

foreach i $modules_to_test {
  puts [join [list "======== TESTING " $i " ========"] ""]
  set seed [string range $i 3 6]
  set iTC [string range $i 7 7]
  set top_func [join [list "TrackletCalculator_" $seed $iTC] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"SEED_=" $seed "_\" -D \"MODULE_=" $i "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $seed $iTC] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl
  csim_design -mflags "-j8" -profile

  # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
  if { $i == $module_to_export } {
    csynth_design
    #cosim_design
    #export_design -format ip_catalog
    # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
    #export_design -format ip_catalog -flow impl
  }
}

exit
