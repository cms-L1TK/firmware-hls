# Script to generate project for TC
#   vivado_hls -f script_TC.tcl
#   vivado_hls -p trackletCalculator
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

set modules_to_test {
  {TP_L1L2A}
  {TP_L1L2B}
  {TP_L1L2C}
  {TP_L1L2D}
  {TP_L1L2E}
  {TP_L1L2F}
  {TP_L1L2G}
  {TP_L1L2H}
  {TP_L1L2I}
  {TP_L1L2J}
  {TP_L1L2K}
  {TP_L1L2L}
  {TP_L2L3A}
  {TP_L2L3B}
  {TP_L2L3C}
  {TP_L2L3D}
  {TP_L3L4A}
  {TP_L3L4B}
  {TP_L3L4C}
  {TP_L3L4D}
  {TP_L5L6A}
  {TP_L5L6B}
  {TP_L5L6C}
  {TP_L5L6D}
  {TP_L1D1A}
  {TP_L1D1B}
  {TP_L1D1C}
  {TP_L1D1D}
  {TP_L1D1E}
  {TP_L1D1F}
  {TP_L1D1G}
  {TP_L1D1H}
  {TP_L2D1A}
  {TP_L2D1B}
  {TP_L2D1C}
  {TP_L2D1D}
  {TP_D1D2A}
  {TP_D1D2B}
  {TP_D1D2C}
  {TP_D1D2D}
  {TP_D3D4A}
  {TP_D3D4B}
  {TP_D3D4C}
  {TP_D3D4D}
}

# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export TP_D1D2A

# create new project (deleting any existing one of same name)
open_project -reset trackletProcessor

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions/CombinedConfig}
add_files ../TopFunctions/CombinedConfig/TrackletProcessorTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletProcessor_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/TP/tables/
add_files -tb ../emData/TP/

foreach i $modules_to_test {
  puts [join [list "======== TESTING " $i " ========"] ""]
  set seed [string range $i 3 6]
  set iTC [string range $i 7 7]
  set top_func [join [list "TrackletProcessor_" $seed $iTC] ""]

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"SEED_=" $seed "_\" -D \"ITC_=" $iTC "_\" -D \"MODULE_=" $i "_\" -D \"TOP_FUNC_=" $top_func "\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $seed $iTC] ""]

  # Define FPGA, clock frequency & common HLS settings.
  source settings_hls.tcl
  csim_design -mflags "-j8"

  # only run C-synthesis, C/RTL cosimulation, and export for module_to_export
  if { $i == $module_to_export } {
    csynth_design
    cosim_design
    #export_design -format ip_catalog
    # Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
    export_design -format ip_catalog -flow impl
  }
}

exit
