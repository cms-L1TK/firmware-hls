#### Put the entire SectorProcessor in SLR0 and SLR1 ####
create_pblock SectorProcessor
resize_pblock [get_pblocks SectorProcessor] -add {SLR0:SLR1}
add_cells_to_pblock [get_pblocks SectorProcessor] [get_cells payload/tf2_wrapper_1/SectorProcessor_1]
