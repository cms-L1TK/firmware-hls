set fout [open "top_cells.txt" w]
foreach i [get_cells *] {
  if {[string equal VCC $i]} {
    continue
  }
  if {[string equal GND $i]} {
    continue
  }
  puts $fout $i
}
close $fout

set fout [open "pipeline_cells.txt" w]
foreach i [get_cells */PIPELINE_SLR_XING[*].AUTO_PIPELINE_*.USE_SRL_*.*PIPELINE_*] {
  puts $fout $i
}
close $fout

set fout [open "pipeline_nets.txt" w]
foreach i [get_nets -of [get_pins -filter REF_PIN_NAME==Q -of [get_cells */PIPELINE_SLR_XING[*].AUTO_PIPELINE_ON.AUTO_PIPELINE_*/*]]] {
  puts $fout $i
}
close $fout

exec ../../../common/script/generate_constraints.py top_cells.txt pipeline_cells.txt pipeline_nets.txt
