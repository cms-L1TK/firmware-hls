# Script to generate project for VMR
#   vivado_hls -f script_VMR.tcl
#   vivado_hls -p vmrouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# list of modules to test in C-simulation
set modules_to_test {
  {VMR_L1PHIA}
  {VMR_L1PHIB}
  {VMR_L1PHIC}
  {VMR_L1PHID}
  {VMR_L1PHIE}
  {VMR_L1PHIF}
  {VMR_L1PHIG}
  {VMR_L1PHIH}
  {VMR_L2PHIA}
  {VMR_L2PHIB}
  {VMR_L2PHIC}
  {VMR_L2PHID}
  {VMR_L3PHIA}
  {VMR_L3PHIB}
  {VMR_L3PHIC}
  {VMR_L3PHID}
  {VMR_L4PHIA}
  {VMR_L4PHIB}
  {VMR_L4PHIC}
  {VMR_L4PHID}
  {VMR_L5PHIA}
  {VMR_L5PHIB}
  {VMR_L5PHIC}
  {VMR_L5PHID}
  {VMR_L6PHIA}
  {VMR_L6PHIB}
  {VMR_L6PHIC}
  {VMR_L6PHID}
  {VMR_D1PHIA}
  {VMR_D1PHIB}
  {VMR_D1PHIC}
  {VMR_D1PHID}
  {VMR_D2PHIA}
  {VMR_D2PHIB}
  {VMR_D2PHIC}
  {VMR_D2PHID}
  {VMR_D3PHIA}
  {VMR_D3PHIB}
  {VMR_D3PHIC}
  {VMR_D3PHID}
  {VMR_D4PHIA}
  {VMR_D4PHIB}
  {VMR_D4PHIC}
  {VMR_D4PHID}
  {VMR_D5PHIA}
  {VMR_D5PHIB}
  {VMR_D5PHIC}
  {VMR_D5PHID}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export VMR_L2PHIA

# create new project (deleting any existing one of same name)
open_project -reset vmrouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
add_files -tb ../TestBenches/VMRouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/VMR/

foreach i $modules_to_test {

  puts [join [list "======== TESTING " $i " ========"] ""]

  set region [string range $i 4 10]
  set top_func [join [list "VMRouterTop_" $region] ""]
  set header_file [join [list "\\\"" $top_func ".h\\\""] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"TOP_FUNC_=" $top_func "\" -D \"HEADER_FILE_=" $header_file "\""] ""]

  # run C-simulation for each module in modules_to_test
  add_files ../TopFunctions/$top_func.cc -cflags "$CFLAGS"
  set_top $top_func
  open_solution [join [list "solution_" $top_func] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl

  # run C-simulation
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
