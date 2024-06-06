# Script to generate project for VMR
#   vivado_hls -f script_VMRCM.tcl
#   vivado_hls -p vmrouterCM
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# list of modules to test in C-simulation
set modules_to_test {
  {VMRCM_L1PHIA}
  {VMRCM_L1PHIB}
  {VMRCM_L1PHIC}
  {VMRCM_L1PHID}
  {VMRCM_L1PHIE}
  {VMRCM_L1PHIF}
  {VMRCM_L1PHIG}
  {VMRCM_L1PHIH}
  {VMRCM_L2PHIA}
  {VMRCM_L2PHIB}
  {VMRCM_L2PHIC}
  {VMRCM_L2PHID}
  {VMRCM_L3PHIA}
  {VMRCM_L3PHIB}
  {VMRCM_L3PHIC}
  {VMRCM_L3PHID}
  {VMRCM_L4PHIA}
  {VMRCM_L4PHIB}
  {VMRCM_L4PHIC}
  {VMRCM_L4PHID}
  {VMRCM_L5PHIA}
  {VMRCM_L5PHIB}
  {VMRCM_L5PHIC}
  {VMRCM_L5PHID}
  {VMRCM_L6PHIA}
  {VMRCM_L6PHIB}
  {VMRCM_L6PHIC}
  {VMRCM_L6PHID}
  {VMRCM_D1PHIA}
  {VMRCM_D1PHIB}
  {VMRCM_D1PHIC}
  {VMRCM_D1PHID}
  {VMRCM_D2PHIA}
  {VMRCM_D2PHIB}
  {VMRCM_D2PHIC}
  {VMRCM_D2PHID}
  {VMRCM_D3PHIA}
  {VMRCM_D3PHIB}
  {VMRCM_D3PHIC}
  {VMRCM_D3PHID}
  {VMRCM_D4PHIA}
  {VMRCM_D4PHIB}
  {VMRCM_D4PHIC}
  {VMRCM_D4PHID}
  {VMRCM_D5PHIA}
  {VMRCM_D5PHIB}
  {VMRCM_D5PHIC}
  {VMRCM_D5PHID}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export VMRCM_L2PHIA

set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TrackletAlgorithm/TestBench -I../TopFunctions/CombinedConfig_FPGA2}

foreach i $modules_to_test {

  puts [join [list "======== TESTING " $i " ========"] ""]

  set region [string range $i 6 12]
  set top_func [join [list "VMRouterCMTop_" $region] ""]
  set header_file [join [list "\\\"" $top_func ".h\\\""] ""]

  # set macros for this module in CCFLAG environment variable

  set ::env(CCFLAG) [join [list $::env(CCFLAG_CMSSW) " -D \"TOP_FUNC_=" $top_func "\" -D \"HEADER_FILE_=" $header_file "\""] ""]

  # create new project (deleting any existing one of same name)
  open_project -reset vmrouterCM_$region

  # source files
  add_files -tb ../TestBenches/VMRouterCM_test.cpp -cflags "$CFLAGS"

  # data files
  add_files -tb ../emData/VMRCM/

  # run C-simulation for each module in modules_to_test
  add_files ../TopFunctions/CombinedConfig_FPGA2/$top_func.cc -cflags "$CFLAGS"
  set_top $top_func
  open_solution [join [list "solution_" $top_func] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl

  puts [join [list $::env(CCFLAG) ] ""]  

  # run C-simulation
  csim_design -mflags "-j8"

  # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
  if { $i == $module_to_export } {
    csynth_design
    puts [join [list "======== Done with csynth ========"] ""]
    cosim_design
    export_design -format ip_catalog
    # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
    #export_design -format ip_catalog -flow impl
  }
}

exit
