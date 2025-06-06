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

# Register all scalar ports
config_interface -register_io scalar_all

#enable HLS to use fully registered DSPs
config_schedule -enable_dsp_full_reg

# Encourage HLS to make more effort to find best solution.
# (Worth trying, but increases CPU use, so not enabled by default)
#config_bind -effort high -enable_dsp_full_reg
#config_schedule -effort high -relax_ii_for_timing=0 -enable_dsp_full_reg -verbose
