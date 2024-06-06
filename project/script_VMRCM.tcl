# Script to generate project for VMR
#   vivado_hls -f script_VMRCM.tcl
#   vivado_hls -p vmrouterCM
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# list of modules to test in C-simulation
set modules_to_test {
  {VMRCM_L2PHIA}
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
  csim_design -mflags "-j1"

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
