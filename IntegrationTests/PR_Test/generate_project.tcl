# Set the reference directory for source file relative paths (by default the value is script directory path)
set origin_dir "."

# Set the project name
set _xil_proj_name_ "PR_Test"

# Create project
create_project ${_xil_proj_name_} ./${_xil_proj_name_} -part xcvu7p-flvb2104-1-e

# Set the directory path for the new project
set proj_dir [get_property directory [current_project]]

# Create 'sources_1' fileset (if not found)
if {[string equal [get_filesets -quiet sources_1] ""]} {
  create_fileset -srcset sources_1
}

# Set IP repository paths
set obj [get_filesets sources_1]
set_property "ip_repo_paths" "[file normalize "$origin_dir/../../project/projrouter/solution1/impl/ip"]" $obj

# Rebuild user ip_repo's index before adding any source files
update_ip_catalog -rebuild

# Set 'sources_1' fileset object
set obj [get_filesets sources_1]
set files [list \
 [file normalize "${origin_dir}/../../TrackletAlgorithm/Memory.v"] \
 [file normalize "${origin_dir}/sourceFiles/uut.v"] \
]
add_files -norecurse -fileset $obj $files

# Create 'sim_1' fileset (if not found)
if {[string equal [get_filesets -quiet sim_1] ""]} {
  create_fileset -simset sim_1
}

# Set 'sim_1' fileset object
set obj [get_filesets sim_1]
set files [list \
 [file normalize "${origin_dir}/Waveforms/CurrentWaveform.wcfg"] \
 [file normalize "${origin_dir}/emData/TPROJ_L5L6XXB_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L5L6XXC_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L1L2XXG_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L1L2XXF_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L1L2XXH_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L1L2XXJ_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L1L2XXI_L3PHIC.dat"] \
 [file normalize "${origin_dir}/emData/TPROJ_L5L6XXD_L3PHIC.dat"] \
 [file normalize "${origin_dir}/sourceFiles/testfixture.v"] \
]
add_files -norecurse -fileset $obj $files

# Create .xci file
create_ip -name ProjectionRouterTop -vendor xilinx.com -library hls -version 1.0 -module_name ProjectionRouter_BARRELPS_BARREL_8_3_0

# Set 'sim_1' fileset properties
set obj [get_filesets sim_1]
set_property -name "top" -value "testfixture" -objects $obj
set_property -name "xsim.simulate.runtime" -value "3000ns" -objects $obj

puts "INFO: Project created:${_xil_proj_name_}"
