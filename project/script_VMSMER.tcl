# Script to generate project for VMSMER
#   vivado_hls -f script_VMSMER.tcl
#   vivado_hls -p vmsmeRouter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# list of modules to test in C-simulation
set modules_to_test {
  {VMSMER_L1PHIA}
  {VMSMER_L1PHIB}
  {VMSMER_L1PHIC}
  {VMSMER_L1PHID}
  {VMSMER_L1PHIE}
  {VMSMER_L1PHIF}
  {VMSMER_L1PHIG}
  {VMSMER_L1PHIH}
  {VMSMER_L2PHIA}
  {VMSMER_L2PHIB}
  {VMSMER_L2PHIC}
  {VMSMER_L2PHID}
  {VMSMER_L3PHIA}
  {VMSMER_L3PHIB}
  {VMSMER_L3PHIC}
  {VMSMER_L3PHID}
  {VMSMER_L4PHIA}
  {VMSMER_L4PHIB}
  {VMSMER_L4PHIC}
  {VMSMER_L4PHID}
  {VMSMER_L5PHIA}
  {VMSMER_L5PHIB}
  {VMSMER_L5PHIC}
  {VMSMER_L5PHID}
  {VMSMER_L6PHIA}
  {VMSMER_L6PHIB}
  {VMSMER_L6PHIC}
  {VMSMER_L6PHID}
  {VMSMER_D1PHIA}
  {VMSMER_D1PHIB}
  {VMSMER_D1PHIC}
  {VMSMER_D1PHID}
  {VMSMER_D2PHIA}
  {VMSMER_D2PHIB}
  {VMSMER_D2PHIC}
  {VMSMER_D2PHID}
  {VMSMER_D3PHIA}
  {VMSMER_D3PHIB}
  {VMSMER_D3PHIC}
  {VMSMER_D3PHID}
  {VMSMER_D4PHIA}
  {VMSMER_D4PHIB}
  {VMSMER_D4PHIC}
  {VMSMER_D4PHID}
  {VMSMER_D5PHIA}
  {VMSMER_D5PHIB}
  {VMSMER_D5PHIC}
  {VMSMER_D5PHID}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export VMSMER_D1PHIA

# create new project (deleting any existing one of same name)
open_project -reset vmsmeRouter

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions/CombinedConfig}
add_files -tb ../TestBenches/VMStubMERouter_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/VMRCM/

foreach i $modules_to_test {

  puts [join [list "======== TESTING " $i " ========"] ""]

  set region [string range $i 6 12]
  set top_func [join [list "VMStubMERouterTop" $region] ""]
  set header_file [join [list "\\\"" $top_func ".h\\\""] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list $::env(CCFLAG_CMSSW) " -D \"TOP_FUNC_=" $top_func "\" -D \"HEADER_FILE_=" $header_file "\""] ""]

  # run C-simulation for each module in modules_to_test
  add_files ../TopFunctions/CombinedConfig/$top_func.cc -cflags "$CFLAGS"
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
