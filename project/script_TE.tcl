# Script to generate project for TE
#   vivado_hls -f script_TE.tcl
#   vivado_hls -p trackletEngine
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

#set modules_to_test {
#  {TE_L1PHIC11_L2PHIB11} //done vitis, vivado
#  {TE_L1PHID16_L2PHIB16} //done vitis, vivado
#  {TE_L1PHIE19_L2PHIC19} //done vitis, vivado
#  {TE_L1PHIG27_L2PHID26} //done vitis, vivado 
#  {TE_L1PHIG27_L2PHID27} //done vitis, vivado
#  {TE_L2PHIJ5_L3PHIJ5} //done vitis, vivado
#  {TE_L2PHIJ6_L3PHIJ6} //done vitis, vivado
#  {TE_L2PHIJ8_L3PHIJ8} //done vitis, vivado
#  {TE_L2PHIK10_L3PHIK10} //done vitis, vivado
#  {TE_L2PHIL13_L3PHIL13} //done vitis, vivado
#  {TE_L3PHIA4_L4PHIA7} //done vitis, vivado
#  {TE_L3PHIA4_L4PHIA8} //done vitis, vivado
#  {TE_L3PHIC10_L4PHIC19} //done vitis, vivado
#  {TE_L3PHIC11_L4PHIC21} //done vitis, vivado
#  {TE_L3PHID13_L4PHID25} //done vitis, vivado 
#  {TE_L5PHIB7_L6PHIB14} //done vitis, vivado
#  {TE_L5PHIC10_L6PHIC21} //done vitis, vivado
#  {TE_L5PHIC12_L6PHIC22} //done vitis, vivado
#  {TE_L5PHID13_L6PHID26} //done vitis, vivado 
#  {TE_L5PHID14_L6PHID28} //done vitis, vivado
#}

#setting a single module to test
set modules_to_test TE_L5PHID14_L6PHID28

# module_to_export must correspond to the default macros set at the top of the
# test bench; otherwise, the C/RTL cosimulation will fail
set module_to_export $modules_to_test

# create new project (deleting any existing one of same name)
set project_name "trackletengine"
append project_name $VitisOrVivado
append project_name "_"
append project_name $module_to_export
open_project -reset $project_name


# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm -I../TopFunctions}
add_files ../TopFunctions/TrackletEngineTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackletEngine_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/TE/tables/
add_files -tb ../emData/TE/

foreach i $modules_to_test {
  puts [join [list "======== TESTING " $i " ========"] ""]
  set innerLayer [string range $i 3 4]
  set outerLayerIndex [string first "_" $i 5]
  set outerLayer [string range $i [expr $outerLayerIndex + 1] [expr $outerLayerIndex + 2]]
  set seed [join [list $innerLayer $outerLayer] ""]
  set innerTable [join [list "../emData/TE/tables/" $i "_stubptinnercut.tab"] ""]
  set outerTable [join [list "../emData/TE/tables/" $i "_stubptoutercut.tab"] ""]

  if { $seed == "L1L2" } {
    set top_func "TrackletEngine_PS_PS"
  } elseif { $seed == "L2L3" } {
    set top_func "TrackletEngine_PS_PS"
  } elseif { $seed == "L3L4" } {
    set top_func "TrackletEngine_PS_2S"
  } elseif { $seed == "L5L6" } {
    set top_func "TrackletEngine_2S_2S"
  }

  # set macros for this module in CCFLAG environment variable
  set ::env(CCFLAG) [join [list "-D \"SEED_=" $seed "_\" -D \"MODULE_=" $i "_\" -D \"TOP_FUNC_=" $top_func "\" -D \"INNER_TABLE_=\\\"" $innerTable "\\\"\" -D \"OUTER_TABLE_=\\\"" $outerTable "\\\"\""] ""]

  # run C-simulation for each module in modules_to_test
  set_top $top_func
  open_solution [join [list "solution_" $i] ""]

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
