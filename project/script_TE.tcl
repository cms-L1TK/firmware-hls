# WARNING: this will wipe out the original project by the same name

# set clock 250 MHz
set clockperiod 4

# delete old project
delete_project trackletengine

# make new project
open_project -reset trackletengine
set_top TrackletEngineTop
add_files ../TrackletAlgorithm/TrackletEngineTop.cpp -cflags "-std=c++11"

add_files -tb ../TestBenches/TrackletEngine_test.cpp -cflags "-I../TrackletAlgorithm -std=c++11"
add_files -tb ../emData/TE
open_solution -reset "solution1"
source set_fpga.tcl
create_clock -period $clockperiod -name default
csim_design -compiler gcc
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
#exit
