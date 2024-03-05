proc tool_add_xact {file_component_xml} {
    puts "\n=> add_xact: $file_component_xml"

    global current_xml_name
    global current_xml_vlnv


    if {! [file exists $file_component_xml]} {
        puts "ERROR: file doesn't exist: $file_component_xml"
        exit 1;
    }

    if {! [regexp {component\.xml$} $file_component_xml tmp]} {
        puts "ERROR: wrong file name ($file). This proc only reads component.xml files created by IP Packager."
        exit 1;
    }

    set xml_dir  [file dirname $file_component_xml]
    set cfs      [current_fileset]
    set old_path [get_property ip_repo_paths $cfs]
    set new_path [concat $old_path $xml_dir]

    puts "    xml_dir: ($xml_dir)"
    puts "    add_repo:($new_path)"
    set_property ip_repo_paths $new_path $cfs

    puts "    update_ip_catalog"
    update_ip_catalog

    puts "    open_core"
    set core [ipx::open_core -set_current false $file_component_xml]

    set vlnv    [get_property vlnv $core]
    set tidbits [split $vlnv ":"]
    puts "    vlnv: $vlnv"

    puts "    close_core"
    ipx::unload_core $core

    set current_xml_name  [lindex $tidbits 2]
    set current_xml_vlnv  $vlnv
}

# Instantiate XACT IP
proc tool_add_core {args} {
    puts "\n=> add_core: $args"

    global current_xml_name
    global current_xml_vlnv

    #flag defaults
    set level 1
    set inst  ""
    set dir "."
    set part ""

    # Parse Flags
    while {[llength $args]} {
        set flag [lindex $args 0]
        #puts "flag: ($flag)"
        #puts "args: ($args)"

        switch -glob $flag {
            -level  {
                # Instantion Generation Level
                set level [lindex $args 1]
                set args  [lrange $args 2 end]
                puts "level:($level) args($args)"

            } -inst {
                # Override default instantation name
                set autoname 0
                set inst  [lindex $args 1]
                set args  [lrange $args 2 end]
                puts "inst:($inst) args($args)"

            } -dir {
                # Override default instantation name
                set autoname 0
                set dir  [lindex $args 1]
                set args  [lrange $args 2 end]
                puts "dir:($dir) args($args)"

            } -part {
                # Override default instantation name
                set autoname 0
                set part  [lindex $args 1]
                set args  [lrange $args 2 end]
                puts "part:($part) args($args)"

            } -h* {
                #help
                puts "USAGE:"
                puts "    tool_add_core \[flags\] <component.xml>"
                puts ""
                puts "FLAGS:"
                puts "    -level 0           //Instantiate only"
                puts "    -level 1           //Instantiate + Generate Instantiation templates"
                puts "    -level 2           //Instantiate + Generate all"
                puts "    -level 3           //Instantiate + Synthesize"
                puts "    -inst <name>       //set name of instance, default: \${corename}_1"
                puts "    -dir <path>        //set path for .xci file"
                puts "    -part <fpga part>  //set part to open project in_memory"
                exit 1

            } -* {
                # unknown option
                error "unknown option [lindex $args 0]"

            } default break
        }
    }
    #puts "args: ($args)"

    # remaining argument is component.xml flag
    set file_component_xml "$args"
    puts "component_xml: $args"

    if {$part == ""} {
    } else {
        create_project -in_memory -part $part
    }

    # Add Packaged IP core, aka. "component.xml", to "IP Integator Library"
    tool_add_xact $file_component_xml

    if {$inst == ""} {
       set module_ip "${current_xml_name}_1"
    } else {
       set module_ip "${inst}"
    }

    puts "-> level: $level"
    puts "-> inst:  $module_ip"

    # Create XCI by instantiating component just added to "IP Integrator Library"
    puts "-> create_ip -verbose -module_name $module_ip -vlnv $current_xml_vlnv -dir $dir"
    create_ip \
        -verbose \
        -module_name $module_ip \
        -vlnv $current_xml_vlnv \
        -dir $dir

    set ip_obj [get_ips "${module_ip}"]

    # Instantate only
    if {$level == 0} {
        return
    }

    # Instantiate + Generate Instantiation template only
    if {$level == 1} {
        puts "\n-> generate_target {instantiation_template}"
        #generate_target {instantiation_template} [get_files "${module_ip}.xci"]
        generate_target {instantiation_template} $ip_obj
        return
    }

    # Instantiate + Generate all
    if {$level == 2} {
        puts "\n-> generate_target {all}"
        generate_target {all} $ip_obj
        return
    }

    # Instantiate + Generate all + Synthesize Core
    if {$level == 3} {
        puts "\n-> generate_target {all}"
        generate_target {all} $ip_obj

        set run_name "${module_ip}_synth_1"
        set run_jobs 8

        puts "\n-> synth_ip    name:${run_name}    jobs:${run_jobs}"

        create_ip_run $ip_obj
        launch_run -jobs $run_jobs $run_name
        wait_on_run $run_name

        return
    }

    error "unknown -level $level"
}

tool_add_core -level 0 -inst [lindex ${argv} 0] -dir [lindex ${argv} 1] -part [lindex ${argv} 2] [lindex ${argv} 3]
