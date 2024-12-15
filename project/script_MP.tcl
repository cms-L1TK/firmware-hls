# Script to generate project for MP
#   vivado_hls -f script_MP.tcl
#   vivado_hls -p match_processor
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
    {MP_L1PHIB}
    {MP_L2PHIB}
    {MP_L3PHIB}
    {MP_L3PHIB_E}
    {MP_L4PHIB}
    {MP_L4PHIB_E}
    {MP_L5PHIB}
    {MP_L5PHIB_E}
    {MP_L6PHIB}
    {MP_L6PHIB_E}
    {MP_D1PHIB}
    {MP_D2PHIB}
    {MP_D3PHIB}
    {MP_D3PHIB_E}
    {MP_D4PHIB}
    {MP_D4PHIB_E}
    {MP_D5PHIB}
    {MP_L1PHIC}
    {MP_L2PHIC}
    {MP_L3PHIC}
    {MP_L3PHIC_E}
    {MP_L4PHIC}
    {MP_L4PHIC_E}
    {MP_L5PHIC}
    {MP_L5PHIC_E}
    {MP_L6PHIC}
    {MP_L6PHIC_E}
    {MP_D1PHIC}
    {MP_D2PHIC}
    {MP_D3PHIC}
    {MP_D3PHIC_E}
    {MP_D4PHIC}
    {MP_D4PHIC_E}
    {MP_D5PHIC}
}

# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export MP_D1PHIC

# create new project (deleting any existing one of same name)
open_project -reset match_processor

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TrackletAlgorithm/TestBench -I../TopFunctions/CombinedConfig_FPGA2}
add_files ../TopFunctions/CombinedConfig_FPGA2/MatchProcessorTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchProcessor_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/MP/

foreach i $modules_to_test {
  set layerDisk [string range $i 3 4]
  set iMP [string range $i 8 8]
  set extra [string range $i 9 10]
  set top_func [join [list "MatchProcessor_" $layerDisk "PHI" $iMP $extra] ""]
  puts [join [list "======== TESTING " $i " ========"] ""]
  puts [join [list "layerDisk = " $layerDisk] ""]
  puts [join [list "iMP = " $iMP] ""]
  puts [join [list "top function = " $top_func] ""]

   # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list $::env(CCFLAG_CMSSW) " -D \"MODULE_=" $i "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $layerDisk $iMP] ""]

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
