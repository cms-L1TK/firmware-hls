# Script to generate project for VMR
#   vivado_hls -f script_VMRSW.tcl
#   vivado_hls -p vmstubwriter
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# list of modules to test in C-simulation
set modules_to_test {
  {VMSR_L1PHIA}
  {VMSR_L1PHIB}
  {VMSR_L1PHIC}
  {VMSR_L1PHID}
  {VMSR_L1PHIE}
  {VMSR_L1PHIF}
  {VMSR_L1PHIG}
  {VMSR_L1PHIH}
  {VMSR_L2PHIA}
  {VMSR_L2PHIB}
  {VMSR_L2PHIC}
  {VMSR_L2PHID}
  {VMSR_L3PHIA}
  {VMSR_L3PHIB}
  {VMSR_L3PHIC}
  {VMSR_L3PHID}
  {VMSR_L4PHIA}
  {VMSR_L4PHIB}
  {VMSR_L4PHIC}
  {VMSR_L4PHID}
  {VMSR_L5PHIA}
  {VMSR_L5PHIB}
  {VMSR_L5PHIC}
  {VMSR_L5PHID}
  {VMSR_L6PHIA}
  {VMSR_L6PHIB}
  {VMSR_L6PHIC}
  {VMSR_L6PHID}
  {VMSR_D1PHIA}
  {VMSR_D1PHIB}
  {VMSR_D1PHIC}
  {VMSR_D1PHID}
  {VMSR_D2PHIA}
  {VMSR_D2PHIB}
  {VMSR_D2PHIC}
  {VMSR_D2PHID}
  {VMSR_D3PHIA}
  {VMSR_D3PHIB}
  {VMSR_D3PHIC}
  {VMSR_D3PHID}
  {VMSR_D4PHIA}
  {VMSR_D4PHIB}
  {VMSR_D4PHIC}
  {VMSR_D4PHID}
  {VMSR_D5PHIA}
  {VMSR_D5PHIB}
  {VMSR_D5PHIC}
  {VMSR_D5PHID}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export VMSR_L2PHIA

# create new project (deleting any existing one of same name)
open_project -reset vmrouterCM

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions/CombinedConfig}
add_files -tb ../TestBenches/VMRouterCM_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/VMSR/

foreach i $modules_to_test {

  puts [join [list "======== TESTING " $i " ========"] ""]

  set region [string range $i 6 12]
  set top_func [join [list "VMRouterCMTop_" $region] ""]
  set header_file [join [list "\\\"" $top_func ".h\\\""] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list $::env(CCFLAG) " -D \"TOP_FUNC_=" $top_func "\" -D \"HEADER_FILE_=" $header_file "\""] ""]

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
