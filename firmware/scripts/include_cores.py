from glob import iglob
import glob
import os

# List of things to substitute to get the cores nickname
sub_froms = ["solution_", "InputRouterTop_IR_DTC", "VMRouterTop", "TrackletEngine_PS_PS", "TrackletCalculator", "ProjectionRouterTop", "MatchEngineTop", "MatchCalculator", "TrackBuilder"]
sub_tos = ["", "IR", "VMR", "TE_L1L2", "TC", "PR", "ME", "MC", "FT"]

#create file and write first line
core_file = 'scripts/xciMaker'
part = 'xcvu7p-flvb2104-2-e'
dir_path = 'cgn'
f = open(core_file, "w")

# Get paths to the cores "component.xml" files
core_dir = iglob('../IntegrationTests/ReducedConfig/IRtoTB/script/*')
core_dirs_lup = []
for x in (x for x in core_dir if os.path.isdir(x) and not os.path.islink(x)):
    core_dir_lup = iglob(x + '/*')
    core_dirs_lup = core_dirs_lup + [x for x in core_dir_lup if os.path.isdir(x)]
core_suffix = '/impl/ip/component.xml'
core_suffix_folder = '/impl/ip'
#core_prefix = ''

# Create symbolic links to the core folders in cgn

# Get proper paths and nicknames and write them to tcl script
core_names = []
for core_folder in core_dirs_lup:
    core_dir_complete = core_folder + core_suffix
    core_dir_folder = core_folder + core_suffix_folder
    core_name = os.path.basename(core_folder)
    for sub_from, sub_to in zip(sub_froms, sub_tos):
        core_name = core_name.replace(sub_from, sub_to)
    if (core_name.find('ME') != -1):
        core_name = core_name + "PHIB"
    #f.write("tool_add_core -level 0 -inst " + core_name + " " + core_dir_complete + "\n")
    os.symlink('../' + core_dir_folder, dir_path + '/' + core_name)
    core_names.append(core_name)
    f.write(core_name + ":\n")
    f.write("\tvivado -nolog -nojou -mode batch -source scripts/ip_tools.tcl -tclargs " + core_name + " " + core_dir_folder + " " + part + " " + core_dir_complete + "\n")

f.write("all: ")
for core in core_names:
    f.write(core + " ")

f.close()
