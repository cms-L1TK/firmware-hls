# script to generate ip core <module-name> at <hls-project-name>/<solution>/impl/ip/<module-name>
# excecute after script_<...>.tcl
# excecute in firmware-hls/project
# excecute with vivado -mode batch -source script_ip.tcl

source fpga.tcl

create_project -in_memory -part $FPGA -force

set_property target_language VHDL [current_project]
set_property ip_repo_paths "./" [current_project]
update_ip_catalog -rebuild

create_ip -name <hls-set-top-name> -module_name <module-name> -vendor xilinx.com -library hls -version 1.0 -dir "./<hls-project-name>/<solution>/impl/ip/"

cd "<hls-project-name>/<solution>/impl/ip/"
exec unzip xilinx_com_hls_<hls-set-top-name>_1_0.zip -d <module-name>
