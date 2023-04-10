# Execute download.sh in the emData/ directory.
set settings_cwd [pwd]
cd ../emData/
if { [catch { exec ./download.sh } msg] } {
  puts $msg
}
cd $settings_cwd

# Allow HLS to use longer (easier to understand) names in resource/latency usage profiles.
config_compile -name_max_length 100

# Set clock frequency
create_clock -period 250MHz -name default

# Set FPGA variable with part number
source fpga.tcl

switch -glob -- $exe {
    *vitis* {
        # Set the FPGA part number
        set_part $FPGA
	# these settings restore more like default vivado_hls performance.
	# see the "VITIS HLS MIGRATION GUIDE" in UG1399
        # this used to be 12.5% in Vivado, now it's 27% in vitis.
        # set it back to 12.5 % for now
        set frac 0.125
        set curr_clock_period [ get_clock_period -ns ]
        set unc [ expr {$curr_clock_period * $frac } ]
        set_clock_uncertainty $unc
        puts "manually set clock uncertainty to $unc"
	# change the export settings
	config_export -vivado_optimization_level 2
	config_export -vivado_phys_opt place
	config_compile -pipeline_loops 0 -pragma_strict_mode=true  
#-unsafe_math_optimizations
	config_schedule -enable_dsp_full_reg=false
#        config_op mul -latency 3 
#       config_op mul -latency 3 
#	config_op add -latency 3
	config_csim -profile -O
    }
    default {
        # Set the FPGA part number
        set_part $FPGA -tool vivado

        # Remove variables from IP interface if they are never used by HLS algo.
        config_interface -trim_dangling_port

        # Prevent HLS relaxing pipeline interval to meet timing.
        config_schedule -relax_ii_for_timing=0 -verbose
    }
}

# Encourage HLS to make more effort to find best solution.
# (Worth trying, but increases CPU use, so not enabled by default)
#config_bind -effort high
#config_schedule -effort high -relax_ii_for_timing=0 -verbose
