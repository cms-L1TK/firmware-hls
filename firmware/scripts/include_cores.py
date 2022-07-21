from glob import iglob
import glob
import os

# List of things to substitute to get the cores nickname
sub_froms = ["solution_", "InputRouterTop_IR_DTC", "VMRouterTop", "TrackletEngine", "TrackletCalculator", "ProjectionRouterTop", "MatchEngineTop", "MatchCalculator", "TrackBuilder"]
sub_tos = ["", "IR", "VMR", "TE", "TC", "PR", "ME", "MC", "FT"]

#create file and write first line
core_file = 'cfg/include_cores.tcl'
f = open(core_file, "w")
f.write("source ../../src/firmware-hls/firmware/cfg/ip_tools.tcl\n")

# Get paths to the cores "component.xml" files
core_dir = iglob('cgn/*/*')
core_suffix = '/impl/ip/component.xml'
core_prefix = '../../src/firmware-hls/firmware/'
core_dirs = [x for x in core_dir if os.path.isdir(x)]

# Get proper paths and nicknames and write them to tcl script
for core_folder in core_dirs:
    core_dir_complete = core_prefix + core_folder + core_suffix
    core_name = os.path.basename(core_folder)
    for sub_from, sub_to in zip(sub_froms, sub_tos):
        core_name = core_name.replace(sub_from, sub_to)
    f.write("tool_add_core -level 0 -inst " + core_name + " " + core_dir_complete + "\n")

f.close()
