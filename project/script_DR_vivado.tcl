# script to finalize ip core DuplicateRemoval
# excecute in firmware-hls/project
# excecute after vitis_hls -f script_DR_hls.tcl
# excecute with vivado -mode batch -source script_DR_vivado.tcl -nojournal -nolog

source fpga.tcl

create_project -in_memory -part $FPGA -force

set_property target_language VHDL [current_project]
set_property ip_repo_paths "./" [current_project]
update_ip_catalog -rebuild

create_ip -name DuplicateRemovalTop -module_name DuplicateRemoval -vendor xilinx.com -library hls -version 1.0 -dir "./"

exec unzip duplicateRemoval/240VU13P-2/impl/ip/xilinx_com_hls_DuplicateRemovalTop_1_0.zip -d ./DuplicateRemoval
