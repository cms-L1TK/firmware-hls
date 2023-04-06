# Script to generate project for MP
#   vivado_hls -f script_MP.tcl
#   vivado_hls -p match_processor
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
    {MP_L1PHIC}
    {MP_L2PHIC}
    {MP_L3PHIC}
    {MP_L4PHIC}
    {MP_L5PHIC}
    {MP_L6PHIC}
}
# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export MP_L3PHIC

# create new project (deleting any existing one of same name)
set project_name "match_processor"
append project_name $VitisOrVivado
open_project -reset $project_name

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions/CombinedConfig}
add_files ../TopFunctions/CombinedConfig/MatchProcessorTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchProcessor_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/MP/

foreach i $modules_to_test {
  set layerDisk [string range $i 3 4]
  set iMP [string range $i 8 9]
  set top_func [join [list "MatchProcessor_" $layerDisk "PHI" $iMP] ""]
  puts [join [list "======== TESTING " $i " ========"] ""]
  puts [join [list "layerDisk = " $layerDisk] ""]
  puts [join [list "iMP = " $iMP] ""]
  puts [join [list "top function = " $top_func] ""]

   # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"MODULE_=" $i "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

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
