# generate project script
# vivado_hls -f <filename>
# vivado_hls -p match_calc
# WARNING: this will wipe out the original project by the same name

# set clock 250 MHz
set clockperiod 4         

# delete old project
delete_project match_calc
# make new project
open_project match_calc
set_top MatchCalculatorTop

# source files
add_files ../TrackletAlgorithm/MatchCalculatorTop.cpp -cflags "-std=c++11"
add_files -tb -cflags "-I ../TrackletAlgorithm -std=c++11" ../TestBenches/MatchCalculator_test.cpp

# data files
add_files -tb ../emData/MC/

# solutions
open_solution "solution1"
source set_fpga.tcl
create_clock -period $clockperiod -name default

csim_design
csynth_design
cosim_design 
export_design -format ip_catalog

# exit vivado_hls
quit
