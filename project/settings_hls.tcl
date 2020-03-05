# Allow HLS to use longer (easier to understand) names in resource/latency usage profiles.
config_compile -name_max_length 100

# Remove variables from IP interface if they are never used by HLS algo.
config_interface -trim_dangling_port

# Prevent HLS relaxing pipeline interval to meet timing.
config_schedule -relax_ii_for_timing=0 -verbose

# Encourage HLS to make more effort to find best solution.
# (Worth trying, but increases CPU use, so not enabled by default)
#config_bind -effort high
#config_schedule -effort high -relax_ii_for_timing=0 -verbose
