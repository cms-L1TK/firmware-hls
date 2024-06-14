# Common settings
set top_level [exec git rev-parse --show-toplevel]
source $top_level/project/env_hls.tcl
source $top_level/IntegrationTests/common/script/build_ip.tcl

# Process arguments
set top_path [lindex $argv 2]
set top_function [lindex $argv 3]
set top_dir [string range $top_path 0 [expr [string last "/" $top_path] - 1]]

# Build IP
set CFLAGS "-std=c++11 -I$top_level/TrackletAlgorithm  -I$top_level/TrackletAlgorithm/Project -I$top_dir"
open_project -reset $top_function
add_files $top_path -cflags "$CFLAGS"
build_ip $top_function

exit
