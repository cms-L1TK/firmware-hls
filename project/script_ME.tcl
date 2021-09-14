# Script to generate project for ME
#   vivado_hls -f script_ME.tcl
#   vivado_hls -p matchengine
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# the set of modules to test
set modules_to_test {
  {ME_L3PHIC20}
}

# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export ME_L3PHIC20

# create new project (deleting any existing one of same name)
open_project -reset matchengine

# source files
# Optional Flags: -DDEBUG
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top MatchEngineTop
add_files ../TrackletAlgorithm/MatchEngineTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchEngine_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/ME/

foreach i $modules_to_test {
  set layerDisk [string range $i 3 4]
  set iME [string range $i 8 11]
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
  set ::env(CCFLAG) [join [list "-D \"KLAYERDISK=" $kLayerDisk "\" -D \"TOPFUNCTION=" $topfunction "\""] ""]

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
