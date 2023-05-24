create_pblock pblock_MPS
add_cells_to_pblock [get_pblocks pblock_MPS] [get_cells -quiet [list \
          {TPROJ_58_loop[*].TPROJ_58}\
          {TPROJ_60_loop[*].TPROJ_60} \    
          {TPROJ_58_delay_loop[*].TPROJ_58}\
          {TPROJ_60_delay_loop[*].TPROJ_60} \              
          {VMSME_16_loop[*].VMSME_16} \
          {VMSME_17_loop[*].VMSME_17 \
          {VMSME_16_delay_loop[*].VMSME_16} \
         {VMSME_17_delay_loop[*].VMSME_17}}]]
resize_pblock [get_pblocks pblock_MPS] -add {CLOCKREGION_X7Y7:CLOCKREGION_X0Y4}

create_pblock pblock_MPL3L4L5L6
add_cells_to_pblock [get_pblocks pblock_MPL3L4L5L6] [get_cells -quiet [list \
          MP_L3PHIA \
          MP_L3PHIB \
          MP_L3PHIC \
          MP_L3PHID \
          MP_L4PHIA \
          MP_L4PHIB \
          MP_L4PHIC \
          MP_L4PHID \
          MP_L5PHIA \
          MP_L5PHIB \
          MP_L5PHIC \
          MP_L5PHID \
          MP_L6PHIA \
          MP_L6PHIB \        
          MP_L6PHID \
          MP_L6PHIC]]
resize_pblock [get_pblocks pblock_MPL3L4L5L6] -add {CLOCKREGION_X0Y8:CLOCKREGION_X7Y9}
create_pblock pblock_MPL1L2
add_cells_to_pblock [get_pblocks pblock_MPL1L2] [get_cells -quiet [list \
          MP_L1PHIA \
          MP_L1PHIB \
          MP_L1PHIC \
          MP_L1PHID \
          MP_L1PHIE \
          MP_L1PHIF \
          MP_L1PHIG \
          MP_L1PHIH \
          MP_L2PHIA \
          MP_L2PHIB \
          MP_L2PHIC \
          MP_L2PHID]]
resize_pblock [get_pblocks pblock_MPL1L2] -add {CLOCKREGION_X0Y4:CLOCKREGION_X7Y5}

create_pblock pblock_TPs
add_cells_to_pblock [get_pblocks pblock_TPs] [get_cells -quiet [list \
          {AS_51_loop[*].AS_51} \
          {VMSTE_16_loop[*].VMSTE_16} \
         {VMSTE_17_loop[*].VMSTE_17}]]
resize_pblock [get_pblocks pblock_TPs] -add {CLOCKREGION_X7Y11:CLOCKREGION_X0Y8}

create_pblock pblock_TPL1L2
add_cells_to_pblock [get_pblocks pblock_TPL1L2] [get_cells -quiet [list \
          TP_L1L2A \
          TP_L1L2A_lut \
          TP_L1L2A_regionlut \
          TP_L1L2B \
          TP_L1L2B_lut \
          TP_L1L2B_regionlut \
          TP_L1L2C \
          TP_L1L2C_lut \
          TP_L1L2C_regionlut \
          TP_L1L2D \
          TP_L1L2D_lut \
          TP_L1L2D_regionlut \
          TP_L1L2E \
          TP_L1L2E_lut \
          TP_L1L2E_regionlut \
          TP_L1L2F \
          TP_L1L2F_lut \
          TP_L1L2F_regionlut \
          TP_L1L2G \
          TP_L1L2G_lut \
          TP_L1L2G_regionlut \
          TP_L1L2H \
          TP_L1L2H_lut \
          TP_L1L2H_regionlut \
          TP_L1L2I \
          TP_L1L2I_lut \
          TP_L1L2I_regionlut \
          TP_L1L2J \
          TP_L1L2J_lut \
          TP_L1L2J_regionlut \
          TP_L1L2K \
          TP_L1L2K_lut \
          TP_L1L2K_regionlut \
          TP_L1L2L \
          TP_L1L2L_lut \
          TP_L1L2L_regionlut]]
resize_pblock [get_pblocks pblock_TPL1L2] -add {CLOCKREGION_X0Y11:CLOCKREGION_X7Y10}

create_pblock pblock_TPL3L4
add_cells_to_pblock [get_pblocks pblock_TPL3L4] [get_cells -quiet [list \
          TP_L2L3A \
          TP_L2L3A_lut \
          TP_L2L3A_regionlut \
          TP_L2L3B \
          TP_L2L3B_lut \
          TP_L2L3B_regionlut \
          TP_L2L3C \
          TP_L2L3C_lut \
          TP_L2L3C_regionlut \
          TP_L2L3D \
          TP_L2L3D_lut \
          TP_L2L3D_regionlut \
          TP_L3L4A \
          TP_L3L4A_lut \
          TP_L3L4A_regionlut \
          TP_L3L4B \
          TP_L3L4B_lut \
          TP_L3L4B_regionlut \
          TP_L3L4C \
          TP_L3L4C_lut \
          TP_L3L4C_regionlut \
          TP_L3L4D \
          TP_L3L4D_lut \
          TP_L3L4D_regionlut \
          TP_L5L6A \
          TP_L5L6A_lut \
          TP_L5L6A_regionlut \
          TP_L5L6B \
          TP_L5L6B_lut \
          TP_L5L6B_regionlut \
          TP_L5L6C \
          TP_L5L6C_lut \
          TP_L5L6C_regionlut \
          TP_L5L6D \
          TP_L5L6D_lut \
          TP_L5L6D_regionlut]]
resize_pblock [get_pblocks pblock_TPL3L4] -add {CLOCKREGION_X0Y6:CLOCKREGION_X7Y7}

create_pblock pblock_FTs
add_cells_to_pblock [get_pblocks pblock_FTs] [get_cells -quiet [list \
          {FM_52_loop[*].FM_52} \
          {FM_52_delay_loop[*].FM_52} \
          FT_L1L2 \
          FT_L2L3 \
          FT_L3L4 \
          FT_L5L6 \
          {TPAR_70_loop[*].TPAR_70}]]
resize_pblock [get_pblocks pblock_FTs] -add {CLOCKREGION_X1Y0:CLOCKREGION_X6Y3}
create_pblock pblock_IRsVMRs
add_cells_to_pblock [get_pblocks pblock_IRsVMRs] [get_cells -quiet [list \
          {IL_36_loop[*].IL_36}\
          IR_2S_1_A \
          IR_2S_1_B \
          IR_2S_2_A \
          IR_2S_2_B \
          IR_2S_3_A \
          IR_2S_3_B \
          IR_2S_4_A \
          IR_2S_4_B \
          IR_PS10G_1_A \
          IR_PS10G_1_B \
          IR_PS10G_2_A \
          IR_PS10G_2_B \
          IR_PS10G_3_A \
          IR_PS10G_3_B \
          IR_PS_1_A \
          IR_PS_1_B \
          IR_PS_2_A \
          IR_PS_2_B \
          IR_neg2S_1_A \
          IR_neg2S_1_B \
          IR_neg2S_2_A \
          IR_neg2S_2_B \
          IR_neg2S_3_A \
          IR_neg2S_3_B \
          IR_neg2S_4_A \
          IR_neg2S_4_B \
          IR_negPS10G_1_A \
          IR_negPS10G_1_B \
          IR_negPS10G_2_A \
          IR_negPS10G_2_B \
          IR_negPS10G_3_A \
          IR_negPS10G_3_B \
          IR_negPS_1_A \
          IR_negPS_1_B \
          IR_negPS_2_A \
          IR_negPS_2_B]]
resize_pblock [get_pblocks pblock_IRsVMRs] -add {CLOCKREGION_X1Y12:CLOCKREGION_X6Y15}

create_pblock pblock_1
resize_pblock [get_pblocks pblock_1] -add {CLOCKREGION_X0Y12:CLOCKREGION_X0Y15}
set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_1]
create_pblock pblock_2
resize_pblock [get_pblocks pblock_2] -add {CLOCKREGION_X7Y12:CLOCKREGION_X7Y15}
set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_2]

create_pblock pblock_3
resize_pblock [get_pblocks pblock_3] -add {CLOCKREGION_X0Y0:CLOCKREGION_X0Y3}
set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_3]
create_pblock pblock_4
resize_pblock [get_pblocks pblock_4] -add {CLOCKREGION_X7Y0:CLOCKREGION_X7Y3}
set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_4]

set_property USER_CLUSTER group_TP_L1L2A [get_cells [list TP_L1L2A TP_L1L2A_lut TP_L1L2A_regionlut]]
set_property USER_CLUSTER group_TP_L1L2B [get_cells [list TP_L1L2B TP_L1L2B_lut TP_L1L2B_regionlut]]
set_property USER_CLUSTER group_TP_L1L2C [get_cells [list TP_L1L2C TP_L1L2C_lut TP_L1L2C_regionlut]]
set_property USER_CLUSTER group_TP_L1L2D [get_cells [list TP_L1L2D TP_L1L2D_lut TP_L1L2D_regionlut]]
set_property USER_CLUSTER group_TP_L1L2E [get_cells [list TP_L1L2E TP_L1L2E_lut TP_L1L2E_regionlut]]
set_property USER_CLUSTER group_TP_L1L2F [get_cells [list TP_L1L2F TP_L1L2F_lut TP_L1L2F_regionlut]]
set_property USER_CLUSTER group_TP_L1L2G [get_cells [list TP_L1L2G TP_L1L2G_lut TP_L1L2G_regionlut]]
set_property USER_CLUSTER group_TP_L1L2H [get_cells [list TP_L1L2H TP_L1L2H_lut TP_L1L2H_regionlut]]
set_property USER_CLUSTER group_TP_L1L2I [get_cells [list TP_L1L2I TP_L1L2I_lut TP_L1L2I_regionlut]]
set_property USER_CLUSTER group_TP_L1L2J [get_cells [list TP_L1L2J TP_L1L2J_lut TP_L1L2J_regionlut]]
set_property USER_CLUSTER group_TP_L1L2K [get_cells [list TP_L1L2K TP_L1L2K_lut TP_L1L2K_regionlut]]
set_property USER_CLUSTER group_TP_L1L2L [get_cells [list TP_L1L2L TP_L1L2L_lut TP_L1L2L_regionlut]]
set_property USER_CLUSTER group_TP_L2L3A [get_cells [list TP_L2L3A TP_L2L3A_lut TP_L2L3A_regionlut]]
set_property USER_CLUSTER group_TP_L2L3B [get_cells [list TP_L2L3B TP_L2L3B_lut TP_L2L3B_regionlut]]
set_property USER_CLUSTER group_TP_L2L3C [get_cells [list TP_L2L3C TP_L2L3C_lut TP_L2L3C_regionlut]]
set_property USER_CLUSTER group_TP_L2L3D [get_cells [list TP_L2L3D TP_L2L3D_lut TP_L2L3D_regionlut]]
set_property USER_CLUSTER group_TP_L3L4A [get_cells [list TP_L3L4A TP_L3L4A_lut TP_L3L4A_regionlut]]
set_property USER_CLUSTER group_TP_L3L4B [get_cells [list TP_L3L4B TP_L3L4B_lut TP_L3L4B_regionlut]]
set_property USER_CLUSTER group_TP_L3L4C [get_cells [list TP_L3L4C TP_L3L4C_lut TP_L3L4C_regionlut]]
set_property USER_CLUSTER group_TP_L3L4D [get_cells [list TP_L3L4D TP_L3L4D_lut TP_L3L4D_regionlut]]
set_property USER_CLUSTER group_TP_L5L6A [get_cells [list TP_L5L6A TP_L5L6A_lut TP_L5L6A_regionlut]]
set_property USER_CLUSTER group_TP_L5L6B [get_cells [list TP_L5L6B TP_L5L6B_lut TP_L5L6B_regionlut]]
set_property USER_CLUSTER group_TP_L5L6C [get_cells [list TP_L5L6C TP_L5L6C_lut TP_L5L6C_regionlut]]
set_property USER_CLUSTER group_TP_L5L6D [get_cells [list TP_L5L6D TP_L5L6D_lut TP_L5L6D_regionlut]]
set_property USER_CLUSTER group_MP_L1PHIA [get_cells MP_L1PHIA]
set_property USER_CLUSTER group_MP_L1PHIB [get_cells MP_L1PHIB]
set_property USER_CLUSTER group_MP_L1PHIC [get_cells MP_L1PHIC]
set_property USER_CLUSTER group_MP_L1PHID [get_cells MP_L1PHID]
set_property USER_CLUSTER group_MP_L1PHIE [get_cells MP_L1PHIE]
set_property USER_CLUSTER group_MP_L1PHIF [get_cells MP_L1PHIF]
set_property USER_CLUSTER group_MP_L1PHIG [get_cells MP_L1PHIG]
set_property USER_CLUSTER group_MP_L1PHIH [get_cells MP_L1PHIH]
set_property USER_CLUSTER group_MP_L2PHIA [get_cells MP_L2PHIA]
set_property USER_CLUSTER group_MP_L2PHIB [get_cells MP_L2PHIB]
set_property USER_CLUSTER group_MP_L2PHIC [get_cells MP_L2PHIC]
set_property USER_CLUSTER group_MP_L2PHID [get_cells MP_L2PHID]
set_property USER_CLUSTER group_MP_L3PHIA [get_cells MP_L3PHIA]
set_property USER_CLUSTER group_MP_L3PHIB [get_cells MP_L3PHIB]
set_property USER_CLUSTER group_MP_L3PHIC [get_cells MP_L3PHIC]
set_property USER_CLUSTER group_MP_L3PHID [get_cells MP_L3PHID]
set_property USER_CLUSTER group_MP_L4PHIA [get_cells MP_L4PHIA]
set_property USER_CLUSTER group_MP_L4PHIB [get_cells MP_L4PHIB]
set_property USER_CLUSTER group_MP_L4PHIC [get_cells MP_L4PHIC]
set_property USER_CLUSTER group_MP_L4PHID [get_cells MP_L4PHID]
set_property USER_CLUSTER group_MP_L5PHIA [get_cells MP_L5PHIA]
set_property USER_CLUSTER group_MP_L5PHIB [get_cells MP_L5PHIB]
set_property USER_CLUSTER group_MP_L5PHIC [get_cells MP_L5PHIC]
set_property USER_CLUSTER group_MP_L5PHID [get_cells MP_L5PHID]
set_property USER_CLUSTER group_MP_L6PHIA [get_cells MP_L6PHIA]
set_property USER_CLUSTER group_MP_L6PHIB [get_cells MP_L6PHIB]
set_property USER_CLUSTER group_MP_L6PHIC [get_cells MP_L6PHIC]
set_property USER_CLUSTER group_MP_L6PHID [get_cells MP_L6PHID]



