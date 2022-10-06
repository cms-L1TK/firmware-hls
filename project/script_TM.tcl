source env_hls.tcl

open_project -reset trackMerger

# source files
# Optional Flags: -DDEBUG
set CFLAGS {-std=c++11 -I../TrackletAlgorithm}
set_top TrackMergerTop
add_files ../TrackletAlgorithm/TrackMergerTop.cc -cflags "$CFLAGS"
add_files ../TrackletAlgorithm/TrackMerger.cc -cflags "$CFLAGS"
add_files ../TrackletAlgorithm/TrackHandler.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackMerger_test.cpp -cflags "$CFLAGS"

open_solution "soln_df1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../emData/PD/
config_dataflow -scalar_fifo_depth 50
csim_design -compiler gcc -mflags "-j8"
#csynth_design
#cosim_design 
#-trace_level all -rtl verilog -verbose
#export_design -format ip_catalog
#export_design -flow impl -rtl vhdl

exit