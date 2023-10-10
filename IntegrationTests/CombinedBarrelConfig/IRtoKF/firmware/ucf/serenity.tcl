#for { set y 0 } { $y < 1 } { incr y }  {
#    delete_pblocks quad_R${y}
#}
#for { set y 0 } { $y < 10 } { incr y }  {
#    delete_pblocks quad_L${y}
#}

#delete_pblocks payload

#create_pblock payload
#resize_pblock payload -add SLICE_X0Y60:SLICE_X148Y599
#set_property gridtypes {URAM288 RAMB36 RAMB18 DSP48E2 SLICE} [get_pblocks payload]

add_cells_to_pblock [get_pblock payload] payload

#delete_pblocks ttc
#create_pblock infra
#resize_pblock infra -add SLICE_X0Y0:SLICE_X168Y59
#set_property gridtypes {URAM288 RAMB36 RAMB18 DSP48E2 SLICE} [get_pblocks infra]

#add_cells_to_pblock [get_pblock infra] ttc
#remove_cells_from_pblock [get_pblock infra] ttc/*osc_clock
#remove_cells_from_pblock [get_pblock infra] ttc/clocks

#add_cells_to_pblock [get_pblock infra] infra
#add_cells_to_pblock [get_pblock infra] ctrl
#add_cells_to_pblock [get_pblock infra] info
