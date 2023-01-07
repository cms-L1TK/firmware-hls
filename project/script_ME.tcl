# Script to generate project for ME
#   vivado_hls -f script_ME.tcl
#   vivado_hls -p matchengine
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# the set of modules to test
#set modules_to_test {
#  {ME_L1PHIC12}
#  {ME_L2PHIC20}
#  {ME_L3PHIC20}
#  {ME_L4PHIC20}
#  {ME_L5PHIC20}
#  {ME_L6PHIC20}
#  {ME_D1PHIC20}
#  {ME_D2PHIC12}
#  {ME_D3PHIC12}
#  {ME_D4PHIC12}
#  {ME_D5PHIC12}
#}
#

#setting a single module to test
set modules_to_test ME_D5PHIC12



# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
#set modules_to_export ME_L1PHIC12
set module_to_export $modules_to_test

# create new project (deleting any existing one of same name)
set project_name "matchengine" 
append project_name $VitisOrVivado
append project_name "_"
append project_name $module_to_export
open_project -reset $project_name 



# source files
# Optional Flags: -DDEBUG
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
set_top MatchEngineTop
add_files ../TopFunctions/MatchEngineTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchEngine_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/ME/

foreach i $modules_to_test {
  # Pick out  the layer/disk type and number (i.e. L3)
  set layerDisk [string range $i 3 4]
  # Pick out the phi sector (i.e. C20)
  set iME [string range $i 8 11]
  # Convert from the module name indexing (1-based) to the enum index (0-based)
  if {[string first "L" $layerDisk] != -1} {
    set kLayerDisk [expr {[string range $i 4 4] - 1}]
  } else {
    set kLayerDisk [expr {[string range $i 4 4] + 5}]
  }
  set topfunction [join [list "MatchEngineTop_" $layerDisk] ""]
  puts [join [list "======== TESTING " $i " ========"] ""]
  puts [join [list "layerDisk (enum) = " $layerDisk " (" $kLayerDisk ")"] ""]
  puts [join [list "phi sector = " $iME] ""]
  puts [join [list "top function = " $topfunction] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"KLAYERDISK=" $kLayerDisk "\" -D \"KMODULE=" $i "_\" -D \"TOPFUNCTION=" $topfunction "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $topfunction
  open_solution [join [list "solution_" $layerDisk "PHI" $iME] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl
  csim_design -mflags "-j8"

  # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
  if { $i == $module_to_export } {
    csynth_design
    cosim_design -trace_level all -rtl verilog
    export_design -format ip_catalog
    # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
    #export_design -format ip_catalog -flow impl
  }
}

exit
