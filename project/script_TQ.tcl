# Script to generate project for TQ
#   vivado_hls -f script_TQ.tcl
#   vivado_hls -p trackquality
# WARNING: this will wipe out the original project by the same name

# Check parameters exists, cannot run without it
if { [file exists ../TrackQuality/parameters.h ] == 1} {     
        set parameters_age [file mtime ../TrackQuality/parameters.h]
        puts "parameters.h created at [clock format [file mtime ../TrackQuality/parameters.h]] \n"
        set model_age  [file mtime ../TrackQuality/xgboost_model.pkl] 
        puts "xgboost_model.pkl created at [clock format [file mtime ../TrackQuality/xgboost_model.pkl]] \n"
        set diff [expr $parameters_age - $model_age]   

        # If parameters was created after the model file exit as this parameters.h is outdated
        if { $diff < 0 } {
           puts "parameters.h is outdated rerun conversion" 
           exit
        } 
        
        
    } else {

    puts "parameters.h not present, follow track quality instructions in README"
    exit

    }

# create new project (deleting any existing one of same name)
set project_name "trackquality"
append project_name $VitisOrVivado
open_project -reset $project_name

# source files
set CFLAGS {-std=c++11 -I../TrackQuality}
set_top TrackQualityTop
add_files ../TrackQuality/TrackQualityTop.cc -cflags "$CFLAGS"
add_files -tb ../TestBenches/TrackQuality_test.cpp -cflags "$CFLAGS"

open_solution "solution1"

# Define FPGA, clock frequency & common HLS settings.
source settings_hls.tcl

# data files
add_files -tb ../TrackQuality/TQ/


csim_design -compiler gcc -mflags "-j8"
#csynth_design
#cosim_design 
#export_design -format ip_catalog 
# Adding "-flow impl" runs full Vivado implementation, providing accurate resource use numbers (very slow).
#export_design -format ip_catalog -flow impl

exit
