# Script to generate project for MC
#   vivado_hls -f script_MC.tcl
#   vivado_hls -p match_calc
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset match_calc

# source files
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
add_files ../TrackletAlgorithm/MatchCalculatorTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchCalculator_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/MC/

open_solution "solution_L3PHIB"
source settings_hls.tcl
set_top MatchCalculator_L3PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L4PHIB"
source settings_hls.tcl
set_top MatchCalculator_L4PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L5PHIB"
source settings_hls.tcl
set_top MatchCalculator_L5PHIB
csynth_design
export_design -format ip_catalog

open_solution "solution_L6PHIB"
source settings_hls.tcl
set_top MatchCalculator_L6PHIB
csynth_design
export_design -format ip_catalog

exit
