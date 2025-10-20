# The directory where the input files to run are found
set input_dir "../mem"

# The directory to save the simulation output to
set output_dir "./dataOut"

# The path to the simulation project
set project_path "../../../../../../proj/vsim_f1/vsim_f1/vsim_f1.xpr"

# The length of the simulation to run (6us is enough to get through 9 events)
set sim_time 6us

# The list of input files to run over
set mem_files {
     "in_fpga1_0.txt"
     "in_fpga1_1.txt"
     "in_fpga1_2.txt"
     "in_fpga1_3.txt"
     "in_fpga1_4.txt"
     "in_fpga1_5.txt"
     "in_fpga1_6.txt"
     "in_fpga1_7.txt"
     "in_fpga1_8.txt"
     "in_fpga1_9.txt"
     "in_fpga1_10.txt"
     "in_fpga1_11.txt"
}

if {[catch {current_project}]} {
    if {![file exists $project_path]} {
        puts "ERROR: Simulation project file not found. Be sure to create a vsim_f1 project."
        exit 1
    }

    puts "Opening project file $project_path"
    open_project $project_path
    reset_simulation sim_1
    launch_simulation
} else {
    puts "Using currently open project."
}

set proj_name [get_property NAME [current_project]]
set proj_dir [get_property DIRECTORY [current_project]]
set sim_name [get_property NAME [current_fileset -simset]]
set sim_dir [file join $proj_dir "$proj_name.sim" $sim_name "behav" "xsim"]
set temp_backup [file join $sim_dir "temp_input.txt"]

if {[catch {set input_filename [get_value "/top/sourcefile"]} errMsg]} {
    puts "ERROR: Could not infer source input filename."
    exit 1
} else {
    set input_filename [string trim $input_filename "\""]
    puts "Using source input filename $input_filename"
}

if {[catch {set output_filename [get_value "/top/sinkfile"]} errMsg]} {
    puts "ERROR: Could not infer source output filename."
    exit 1
} else {
    set output_filename [string trim $output_filename "\""]
    puts "Using source output filename $output_filename"
}

file delete -force $output_dir
file mkdir $output_dir

set target_input_path [file join $sim_dir $input_filename]
set source_output_path [file join $sim_dir $output_filename]

# Save the existing input file since we will be overwriting it
puts "Saving copy of original input file $target_input_path"
file copy -force $target_input_path [file join $sim_dir $temp_backup]

# try..catch..finally not implemented until tcl 8.6, so we must
# catch any errors to ensure we restore the existing input file
set return_status [catch {
    set idx 0
    foreach mem_file $mem_files {
        set source_input_path [file join $input_dir $mem_file]
        if {![file exists $source_input_path]} {
            puts "WARNING: Input file '$mem_file' does not exist. Skipping..."
            continue
        }

        puts "Copying $source_input_path -> $target_input_path"
        file copy -force $source_input_path $target_input_path

        puts "Running simulation for $mem_file"
        restart
        run $sim_time
        puts "Simulation finished for $mem_file"

        if {[file exists $source_output_path]} {
            set target_output_path [file join $output_dir "out${idx}.txt"]
            file copy -force $source_output_path $target_output_path
            puts "Saved output -> $target_output_path"
        } else {
            puts "WARNING: Output file '$source_output_path' not found after simulation."
        }

        incr idx
    }
} result options]

# Restore the existing input file since we overwrote it
puts "Restoring original input file $target_input_path"
file copy -force [file join $sim_dir $temp_backup] $target_input_path
file delete -force [file join $sim_dir $temp_backup]

# If our code threw an error, we want to report that to the user
if {$return_status != 0} {
    return -code $return_status -options $options $result
}
