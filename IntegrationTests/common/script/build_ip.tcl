###################
# Build an HLS IP #
###################

proc build_ip {top_function project_location} {
    global exe
    set cwd [pwd]

    set_top $top_function
    open_solution "solution_$top_function"
    cd $project_location
    source settings_hls.tcl
    cd $cwd
    csynth_design
    export_design -format ip_catalog
}
