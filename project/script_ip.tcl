# script to generate ip core TrackMerger at trackMerger/soln_df1/impl/ip/TrackMerger
# excecute after script_<...>.tcl
# excecute in firmware-hls/project
# excecute with vivado -mode batch -source script_ip.tcl

source fpga.tcl

create_project -in_memory -part $FPGA -force

set_property target_language VHDL [current_project]
set_property ip_repo_paths "./" [current_project]
update_ip_catalog -rebuild

create_ip -name TrackMergerTop -module_name TrackMerger -vendor xilinx.com -library hls -version 1.0 -dir "./trackMerger/soln_df1/impl/ip/"

cd "trackMerger/soln_df1/impl/ip/"
exec unzip xilinx_com_hls_TrackMergerTop_1_0.zip -d TrackMerger
 
