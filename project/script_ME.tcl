# Script to generate project for ME
#   vivado_hls -f script_ME.tcl
#   vivado_hls -p matchengine
# WARNING: this will wipe out the original project by the same name

# get some information about the executable and environment
source env_hls.tcl

# create new project (deleting any existing one of same name)
open_project -reset matchengine

# source files
# Optional Flags: -DDEBUG
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
add_files ../TrackletAlgorithm/MatchEngineTop_L3.cc -cflags "$CFLAGS"
add_files ../TrackletAlgorithm/MatchEngineTop_L4.cc -cflags "$CFLAGS"
add_files ../TrackletAlgorithm/MatchEngineTop_L5.cc -cflags "$CFLAGS"
add_files ../TrackletAlgorithm/MatchEngineTop_L6.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/MatchEngine_test.cpp -cflags "$CFLAGS"

# data files
add_files -tb ../emData/ME/

open_solution "solution_L3"
source settings_hls.tcl
set_top MatchEngineTop_L3
csynth_design
export_design -format ip_catalog

open_solution "solution_L4"
source settings_hls.tcl
set_top MatchEngineTop_L4
csynth_design
export_design -format ip_catalog

open_solution "solution_L5"
source settings_hls.tcl
set_top MatchEngineTop_L5
csynth_design
export_design -format ip_catalog

open_solution "solution_L6"
source settings_hls.tcl
set_top MatchEngineTop_L6
csynth_design
export_design -format ip_catalog

exit
