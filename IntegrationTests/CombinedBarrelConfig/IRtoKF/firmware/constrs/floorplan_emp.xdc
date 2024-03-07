#this XDC contains physical constraints for the out-of-context combined barrel chain
create_pblock pblock_MPL3L4L5L6
add_cells_to_pblock [get_pblocks pblock_MPL3L4L5L6] [get_cells -quiet [list \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHIA \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHIB \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHIC \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHID \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHIA \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHIB \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHIC \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHID \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHIA \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHIB \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHIC \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHID \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHIA \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHIB \        
          payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHID \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHIC]]
resize_pblock [get_pblocks pblock_MPL3L4L5L6] -add {CLOCKREGION_X0Y8:CLOCKREGION_X7Y9}
create_pblock pblock_MPL1L2
add_cells_to_pblock [get_pblocks pblock_MPL1L2] [get_cells -quiet [list \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIA \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIB \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIC \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHID \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIE \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIF \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIG \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIH \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHIA \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHIB \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHIC \
          payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHID]]
resize_pblock [get_pblocks pblock_MPL1L2] -add {CLOCKREGION_X0Y4:CLOCKREGION_X7Y5}
create_pblock pblock_TPL1L2
add_cells_to_pblock [get_pblocks pblock_TPL1L2] [get_cells -quiet [list \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2A \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2A_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2A_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2B \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2B_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2B_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2C \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2C_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2C_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2D \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2D_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2D_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2E \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2E_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2E_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2F \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2F_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2F_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2G \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2G_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2G_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2H \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2H_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2H_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2I \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2I_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2I_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2J \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2J_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2J_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2K \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2K_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2K_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2L \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2L_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2L_regionlut]]
resize_pblock [get_pblocks pblock_TPL1L2] -add {CLOCKREGION_X0Y11:CLOCKREGION_X7Y10}

create_pblock pblock_TPL3L4
add_cells_to_pblock [get_pblocks pblock_TPL3L4] [get_cells -quiet [list \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3A \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3A_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3A_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3B \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3B_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3B_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3C \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3C_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3C_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3D \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3D_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3D_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4A \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4A_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4A_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4B \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4B_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4B_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4C \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4C_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4C_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4D \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4D_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4D_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6A \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6A_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6A_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6B \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6B_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6B_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6C \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6C_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6C_regionlut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6D \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6D_lut \
          payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6D_regionlut]]
resize_pblock [get_pblocks pblock_TPL3L4] -add {CLOCKREGION_X0Y6:CLOCKREGION_X7Y7}

create_pblock pblock_FTs
add_cells_to_pblock [get_pblocks pblock_FTs] [get_cells -quiet [list \
          {payload/tf_wrapper_1/SectorProcessor_1/FM_52_loop[*].FM_52} \
          {payload/tf_wrapper_1/SectorProcessor_1/FM_52_delay_loop[*].FM_52} \
          payload/tf_wrapper_1/SectorProcessor_1/FT_L1L2 \
          payload/tf_wrapper_1/SectorProcessor_1/FT_L2L3 \
          payload/tf_wrapper_1/SectorProcessor_1/FT_L3L4 \
          payload/tf_wrapper_1/SectorProcessor_1/FT_L5L6 \
          {payload/tf_wrapper_1/SectorProcessor_1/TPAR_70_loop[*].TPAR_70}]]
resize_pblock [get_pblocks pblock_FTs] -add {CLOCKREGION_X1Y0:CLOCKREGION_X6Y3}
create_pblock pblock_IRsVMRs
add_cells_to_pblock [get_pblocks pblock_IRsVMRs] [get_cells -quiet [list \
          {payload/tf_wrapper_1/SectorProcessor_1/IL_36_loop[*].IL_36}\
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_1_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_1_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_2_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_2_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_3_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_3_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_4_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_2S_4_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS10G_1_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS10G_1_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS10G_2_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS10G_2_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS10G_3_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS10G_3_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS_1_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS_1_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS_2_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_PS_2_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_1_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_1_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_2_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_2_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_3_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_3_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_4_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_neg2S_4_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS10G_1_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS10G_1_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS10G_2_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS10G_2_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS10G_3_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS10G_3_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS_1_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS_1_B \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS_2_A \
          payload/tf_wrapper_1/SectorProcessor_1/IR_negPS_2_B]]
resize_pblock [get_pblocks pblock_IRsVMRs] -add {CLOCKREGION_X1Y12:CLOCKREGION_X6Y15}

create_pblock pblock_KF
add_cells_to_pblock [get_pblocks pblock_KF] [get_cells -quiet [list \
          payload/kf_wrapper_1]]
resize_pblock [get_pblocks pblock_KF] -add {CLOCKREGION_X0Y0:CLOCKREGION_X7Y3}

create_pblock pblock_1
resize_pblock [get_pblocks pblock_1] -add {CLOCKREGION_X0Y12:CLOCKREGION_X0Y15}
#set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_1]
create_pblock pblock_2
resize_pblock [get_pblocks pblock_2] -add {CLOCKREGION_X7Y12:CLOCKREGION_X7Y15}
#set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_2]

create_pblock pblock_3
resize_pblock [get_pblocks pblock_3] -add {CLOCKREGION_X0Y0:CLOCKREGION_X0Y3}
#set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_3]
create_pblock pblock_4
resize_pblock [get_pblocks pblock_4] -add {CLOCKREGION_X7Y0:CLOCKREGION_X7Y3}
#set_property EXCLUDE_PLACEMENT 1 [get_pblocks pblock_4]

set_property USER_CLUSTER group_TP_L1L2A [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2A payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2A_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2A_regionlut]]
set_property USER_CLUSTER group_TP_L1L2B [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2B payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2B_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2B_regionlut]]
set_property USER_CLUSTER group_TP_L1L2C [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2C payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2C_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2C_regionlut]]
set_property USER_CLUSTER group_TP_L1L2D [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2D payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2D_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2D_regionlut]]
set_property USER_CLUSTER group_TP_L1L2E [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2E payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2E_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2E_regionlut]]
set_property USER_CLUSTER group_TP_L1L2F [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2F payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2F_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2F_regionlut]]
set_property USER_CLUSTER group_TP_L1L2G [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2G payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2G_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2G_regionlut]]
set_property USER_CLUSTER group_TP_L1L2H [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2H payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2H_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2H_regionlut]]
set_property USER_CLUSTER group_TP_L1L2I [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2I payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2I_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2I_regionlut]]
set_property USER_CLUSTER group_TP_L1L2J [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2J payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2J_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2J_regionlut]]
set_property USER_CLUSTER group_TP_L1L2K [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2K payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2K_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2K_regionlut]]
set_property USER_CLUSTER group_TP_L1L2L [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2L payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2L_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L1L2L_regionlut]]
set_property USER_CLUSTER group_TP_L2L3A [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3A payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3A_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3A_regionlut]]
set_property USER_CLUSTER group_TP_L2L3B [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3B payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3B_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3B_regionlut]]
set_property USER_CLUSTER group_TP_L2L3C [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3C payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3C_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3C_regionlut]]
set_property USER_CLUSTER group_TP_L2L3D [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3D payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3D_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L2L3D_regionlut]]
set_property USER_CLUSTER group_TP_L3L4A [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4A payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4A_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4A_regionlut]]
set_property USER_CLUSTER group_TP_L3L4B [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4B payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4B_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4B_regionlut]]
set_property USER_CLUSTER group_TP_L3L4C [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4C payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4C_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4C_regionlut]]
set_property USER_CLUSTER group_TP_L3L4D [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4D payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4D_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L3L4D_regionlut]]
set_property USER_CLUSTER group_TP_L5L6A [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6A payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6A_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6A_regionlut]]
set_property USER_CLUSTER group_TP_L5L6B [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6B payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6B_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6B_regionlut]]
set_property USER_CLUSTER group_TP_L5L6C [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6C payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6C_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6C_regionlut]]
set_property USER_CLUSTER group_TP_L5L6D [get_cells [list payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6D payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6D_lut payload/tf_wrapper_1/SectorProcessor_1/TP_L5L6D_regionlut]]
set_property USER_CLUSTER group_MP_L1PHIA [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIA]
set_property USER_CLUSTER group_MP_L1PHIB [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIB]
set_property USER_CLUSTER group_MP_L1PHIC [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIC]
set_property USER_CLUSTER group_MP_L1PHID [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHID]
set_property USER_CLUSTER group_MP_L1PHIE [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIE]
set_property USER_CLUSTER group_MP_L1PHIF [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIF]
set_property USER_CLUSTER group_MP_L1PHIG [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIG]
set_property USER_CLUSTER group_MP_L1PHIH [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L1PHIH]
set_property USER_CLUSTER group_MP_L2PHIA [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHIA]
set_property USER_CLUSTER group_MP_L2PHIB [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHIB]
set_property USER_CLUSTER group_MP_L2PHIC [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHIC]
set_property USER_CLUSTER group_MP_L2PHID [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L2PHID]
set_property USER_CLUSTER group_MP_L3PHIA [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHIA]
set_property USER_CLUSTER group_MP_L3PHIB [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHIB]
set_property USER_CLUSTER group_MP_L3PHIC [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHIC]
set_property USER_CLUSTER group_MP_L3PHID [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L3PHID]
set_property USER_CLUSTER group_MP_L4PHIA [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHIA]
set_property USER_CLUSTER group_MP_L4PHIB [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHIB]
set_property USER_CLUSTER group_MP_L4PHIC [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHIC]
set_property USER_CLUSTER group_MP_L4PHID [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L4PHID]
set_property USER_CLUSTER group_MP_L5PHIA [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHIA]
set_property USER_CLUSTER group_MP_L5PHIB [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHIB]
set_property USER_CLUSTER group_MP_L5PHIC [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHIC]
set_property USER_CLUSTER group_MP_L5PHID [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L5PHID]
set_property USER_CLUSTER group_MP_L6PHIA [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHIA]
set_property USER_CLUSTER group_MP_L6PHIB [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHIB]
set_property USER_CLUSTER group_MP_L6PHIC [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHIC]
set_property USER_CLUSTER group_MP_L6PHID [get_cells payload/tf_wrapper_1/SectorProcessor_1/MP_L6PHID]



