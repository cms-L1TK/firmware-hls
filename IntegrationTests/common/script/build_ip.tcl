###################
# Build an HLS IP #
###################

proc build_ip {top_function} {
    global exe
    set cwd [pwd]
    set top_level [exec git rev-parse --show-toplevel]

    set_top $top_function
    open_solution -reset "solution"
    cd $top_level/project
    source settings_hls.tcl
    cd $cwd
    csynth_design
    export_design -format ip_catalog
}
