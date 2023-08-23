# Open project
set projName "Work"
open_project $projName/$projName.xpr

reset_simulation sim_1

# Create directory for output .txt file
file delete -force dataOut/
file mkdir dataOut/

# Run pre.tcl if it exists
set_property -name {xsim.compile.tcl.pre} -value [get_files pre.tcl -of [get_fileset utils_1]] -objects [get_filesets sim_1]

# Launch Simulation
launch_simulation

# Set default wave viewer cfg
open_wave_config {../tb/start_bx.wcfg}

restart
# Need 4us + 0.45us per event (50us for 100 events, but 10us for quick test).
run 50 us
