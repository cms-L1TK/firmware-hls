#this XDC contains physical constraints for the out-of-context second FPGA project
create_pblock pblock_PCVMSMERs
add_cells_to_pblock [get_pblocks pblock_PCVMSMERs] [get_cells -quiet [list \
          PC_L1L2ABC \
          PC_L1L2DE \
          PC_L1L2F \
          PC_L1L2G \
          PC_L1L2HI \
          PC_L1L2JKL \
          PC_L2L3ABCD \
          PC_L3L4AB \
          PC_L3L4CD \
          PC_L5L6ABCD \
          PC_D1D2ABCD \
          PC_D3D4ABCD \
          PC_L1D1ABCD \
          PC_L1D1EFGH \
          PC_L2D1ABCD \
          VMSMER_L1PHIA \
          VMSMER_L1PHIB \
          VMSMER_L1PHIC \
          VMSMER_L1PHID \
          VMSMER_L1PHIE \
          VMSMER_L1PHIF \
          VMSMER_L1PHIG \
          VMSMER_L1PHIH \
          VMSMER_L2PHIA \
          VMSMER_L2PHIB \
          VMSMER_L2PHIC \
          VMSMER_L2PHID \
          VMSMER_L3PHIA \
          VMSMER_L3PHIB \
          VMSMER_L3PHIC \
          VMSMER_L3PHID \
          VMSMER_L4PHIA \
          VMSMER_L4PHIB \
          VMSMER_L4PHIC \
          VMSMER_L4PHID \
          VMSMER_L5PHIA \
          VMSMER_L5PHIB \
          VMSMER_L5PHIC \
          VMSMER_L5PHID \
          VMSMER_L6PHIA \
          VMSMER_L6PHIB \        
          VMSMER_L6PHID \
          VMSMER_L6PHIC \
	  VMSMER_D1PHIA \
          VMSMER_D1PHIB \
          VMSMER_D1PHIC \
          VMSMER_D1PHID \
          VMSMER_D2PHIA \
          VMSMER_D2PHIB \
          VMSMER_D2PHIC \
          VMSMER_D2PHID \
          VMSMER_D3PHIA \
          VMSMER_D3PHIB \
          VMSMER_D3PHIC \
          VMSMER_D3PHID \
          VMSMER_D4PHIA \
          VMSMER_D4PHIB \
          VMSMER_D4PHIC \
          VMSMER_D4PHID \
          VMSMER_D5PHIA \
          VMSMER_D5PHIB \
          VMSMER_D5PHIC \
          VMSMER_D5PHID \
	  MPROJ_*_DELAY0 \
	  ]]
resize_pblock [get_pblocks pblock_PCVMSMERs] -add {CLOCKREGION_X0Y4:CLOCKREGION_X7Y7}

create_pblock pblock_MPL1A
add_cells_to_pblock [get_pblocks pblock_MPL1A] [get_cells -quiet [list \
          MP_L1PHIA \
          AS_L1PHIAn2_DELAY \
          AS_L1PHIAn2 \
          VMSME_L1PHIAn2_DELAY \
          VMSME_L1PHIAn2 \
          MPROJ_L2L3ABCD_L1PHIA_DELAY \
          MPROJ_L2L3ABCD_L1PHIA \
          MPROJ_L3L4AB_L1PHIA_DELAY \
          MPROJ_L3L4AB_L1PHIA \
          MPROJ_L5L6ABCD_L1PHIA_DELAY \
          MPROJ_L5L6ABCD_L1PHIA \
          MPROJ_D1D2ABCD_L1PHIA_DELAY \
          MPROJ_D1D2ABCD_L1PHIA \
          MPROJ_D3D4ABCD_L1PHIA_DELAY \
          MPROJ_D3D4ABCD_L1PHIA \
          MPROJ_L2D1ABCD_L1PHIA_DELAY \
          MPROJ_L2D1ABCD_L1PHIA \
	  ]]

create_pblock pblock_MPL1B
add_cells_to_pblock [get_pblocks pblock_MPL1B] [get_cells -quiet [list \
	  MP_L1PHIB \
          AS_L1PHIBn2_DELAY \
          AS_L1PHIBn2 \
          VMSME_L1PHIBn2_DELAY \
          VMSME_L1PHIBn2 \
          MPROJ_L2L3ABCD_L1PHIB_DELAY \
          MPROJ_L2L3ABCD_L1PHIB \
          MPROJ_L3L4AB_L1PHIB_DELAY \
          MPROJ_L3L4AB_L1PHIB \
          MPROJ_L5L6ABCD_L1PHIB_DELAY \
          MPROJ_L5L6ABCD_L1PHIB \
          MPROJ_D1D2ABCD_L1PHIB_DELAY \
          MPROJ_D1D2ABCD_L1PHIB \
          MPROJ_D3D4ABCD_L1PHIB_DELAY \
          MPROJ_D3D4ABCD_L1PHIB \
          MPROJ_L2D1ABCD_L1PHIB_DELAY \
          MPROJ_L2D1ABCD_L1PHIB \
	  ]]

create_pblock pblock_MPL1C
add_cells_to_pblock [get_pblocks pblock_MPL1C] [get_cells -quiet [list \
	  MP_L1PHIC \
          AS_L1PHICn2_DELAY \
          AS_L1PHICn2 \
          VMSME_L1PHICn2_DELAY \
          VMSME_L1PHICn2 \
          MPROJ_L2L3ABCD_L1PHIC_DELAY \
          MPROJ_L2L3ABCD_L1PHIC \
          MPROJ_L3L4AB_L1PHIC_DELAY \
          MPROJ_L3L4AB_L1PHIC \
          MPROJ_L5L6ABCD_L1PHIC_DELAY \
          MPROJ_L5L6ABCD_L1PHIC \
          MPROJ_D1D2ABCD_L1PHIC_DELAY \
          MPROJ_D1D2ABCD_L1PHIC \
          MPROJ_D3D4ABCD_L1PHIC_DELAY \
          MPROJ_D3D4ABCD_L1PHIC \
          MPROJ_L2D1ABCD_L1PHIC_DELAY \
          MPROJ_L2D1ABCD_L1PHIC \
	  ]]

create_pblock pblock_MPL1D
add_cells_to_pblock [get_pblocks pblock_MPL1D] [get_cells -quiet [list \
	  MP_L1PHID \
          AS_L1PHIDn2_DELAY \
          AS_L1PHIDn2 \
          VMSME_L1PHIDn2_DELAY \
          VMSME_L1PHIDn2 \
          MPROJ_L2L3ABCD_L1PHID_DELAY \
          MPROJ_L2L3ABCD_L1PHID \
          MPROJ_L3L4AB_L1PHID_DELAY \
          MPROJ_L3L4AB_L1PHID \
          MPROJ_L3L4CD_L1PHID_DELAY \
          MPROJ_L3L4CD_L1PHID \
          MPROJ_L5L6ABCD_L1PHID_DELAY \
          MPROJ_L5L6ABCD_L1PHID \
          MPROJ_D1D2ABCD_L1PHID_DELAY \
          MPROJ_D1D2ABCD_L1PHID \
          MPROJ_D3D4ABCD_L1PHID_DELAY \
          MPROJ_D3D4ABCD_L1PHID \
          MPROJ_L2D1ABCD_L1PHID_DELAY \
          MPROJ_L2D1ABCD_L1PHID \
	  ]]

create_pblock pblock_MPL1E
add_cells_to_pblock [get_pblocks pblock_MPL1E] [get_cells -quiet [list \
	  MP_L1PHIE \
          AS_L1PHIEn2_DELAY \
          AS_L1PHIEn2 \
          VMSME_L1PHIEn2_DELAY \
          VMSME_L1PHIEn2 \
          MPROJ_L2L3ABCD_L1PHIE_DELAY \
          MPROJ_L2L3ABCD_L1PHIE \
          MPROJ_L3L4AB_L1PHIE_DELAY \
          MPROJ_L3L4AB_L1PHIE \
          MPROJ_L3L4CD_L1PHIE_DELAY \
          MPROJ_L3L4CD_L1PHIE \
          MPROJ_L5L6ABCD_L1PHIE_DELAY \
          MPROJ_L5L6ABCD_L1PHIE \
          MPROJ_D1D2ABCD_L1PHIE_DELAY \
          MPROJ_D1D2ABCD_L1PHIE \
          MPROJ_D3D4ABCD_L1PHIE_DELAY \
          MPROJ_D3D4ABCD_L1PHIE \
          MPROJ_L2D1ABCD_L1PHIE_DELAY \
          MPROJ_L2D1ABCD_L1PHIE \
	  ]]

create_pblock pblock_MPL1F
add_cells_to_pblock [get_pblocks pblock_MPL1F] [get_cells -quiet [list \
	  MP_L1PHIF \
          AS_L1PHIFn2_DELAY \
          AS_L1PHIFn2 \
          VMSME_L1PHIFn2_DELAY \
          VMSME_L1PHIFn2 \
          MPROJ_L2L3ABCD_L1PHIF_DELAY \
          MPROJ_L2L3ABCD_L1PHIF \
          MPROJ_L3L4CD_L1PHIF_DELAY \
          MPROJ_L3L4CD_L1PHIF \
          MPROJ_L5L6ABCD_L1PHIF_DELAY \
          MPROJ_L5L6ABCD_L1PHIF \
          MPROJ_D1D2ABCD_L1PHIF_DELAY \
          MPROJ_D1D2ABCD_L1PHIF \
          MPROJ_D3D4ABCD_L1PHIF_DELAY \
          MPROJ_D3D4ABCD_L1PHIF \
          MPROJ_L2D1ABCD_L1PHIF_DELAY \
          MPROJ_L2D1ABCD_L1PHIF \
	  ]]

create_pblock pblock_MPL1G
add_cells_to_pblock [get_pblocks pblock_MPL1G] [get_cells -quiet [list \
	  MP_L1PHIG \
          AS_L1PHIGn2_DELAY \
          AS_L1PHIGn2 \
          VMSME_L1PHIGn2_DELAY \
          VMSME_L1PHIGn2 \
          MPROJ_L2L3ABCD_L1PHIG_DELAY \
          MPROJ_L2L3ABCD_L1PHIG \
          MPROJ_L3L4CD_L1PHIG_DELAY \
          MPROJ_L3L4CD_L1PHIG \
          MPROJ_L5L6ABCD_L1PHIG_DELAY \
          MPROJ_L5L6ABCD_L1PHIG \
          MPROJ_D1D2ABCD_L1PHIG_DELAY \
          MPROJ_D1D2ABCD_L1PHIG \
          MPROJ_D3D4ABCD_L1PHIG_DELAY \
          MPROJ_D3D4ABCD_L1PHIG \
          MPROJ_L2D1ABCD_L1PHIG_DELAY \
          MPROJ_L2D1ABCD_L1PHIG \
	  ]]

create_pblock pblock_MPL1H
add_cells_to_pblock [get_pblocks pblock_MPL1H] [get_cells -quiet [list \
	  MP_L1PHIH \
          AS_L1PHIHn2_DELAY \
          AS_L1PHIHn2 \
          VMSME_L1PHIHn2_DELAY \
          VMSME_L1PHIHn2 \
          MPROJ_L2L3ABCD_L1PHIH_DELAY \
          MPROJ_L2L3ABCD_L1PHIH \
          MPROJ_L3L4CD_L1PHIH_DELAY \
          MPROJ_L3L4CD_L1PHIH \
          MPROJ_L5L6ABCD_L1PHIH_DELAY \
          MPROJ_L5L6ABCD_L1PHIH \
          MPROJ_D1D2ABCD_L1PHIH_DELAY \
          MPROJ_D1D2ABCD_L1PHIH \
          MPROJ_D3D4ABCD_L1PHIH_DELAY \
          MPROJ_D3D4ABCD_L1PHIH \
          MPROJ_L2D1ABCD_L1PHIH_DELAY \
          MPROJ_L2D1ABCD_L1PHIH \
	  ]]

create_pblock pblock_MPL2A
add_cells_to_pblock [get_pblocks pblock_MPL2A] [get_cells -quiet [list \
          MP_L2PHIA \
          AS_L2PHIAn2_DELAY \
          AS_L2PHIAn2 \
          VMSME_L2PHIAn2_DELAY \
          VMSME_L2PHIAn2 \
          MPROJ_L3L4AB_L2PHIA_DELAY \
          MPROJ_L3L4AB_L2PHIA \
          MPROJ_L5L6ABCD_L2PHIA_DELAY \
          MPROJ_L5L6ABCD_L2PHIA \
          MPROJ_D1D2ABCD_L2PHIA_DELAY \
          MPROJ_D1D2ABCD_L2PHIA \
	  ]]
	  
create_pblock pblock_MPL2B
add_cells_to_pblock [get_pblocks pblock_MPL2B] [get_cells -quiet [list \
          MP_L2PHIB \
          AS_L2PHIBn2_DELAY \
          AS_L2PHIBn2 \
          VMSME_L2PHIBn2_DELAY \
          VMSME_L2PHIBn2 \
          MPROJ_L3L4AB_L2PHIB_DELAY \
          MPROJ_L3L4AB_L2PHIB \
          MPROJ_L3L4CD_L2PHIB_DELAY \
          MPROJ_L3L4CD_L2PHIB \
          MPROJ_L5L6ABCD_L2PHIB_DELAY \
          MPROJ_L5L6ABCD_L2PHIB \
          MPROJ_D1D2ABCD_L2PHIB_DELAY \
          MPROJ_D1D2ABCD_L2PHIB \
	  ]]
	  
create_pblock pblock_MPL2C
add_cells_to_pblock [get_pblocks pblock_MPL2C] [get_cells -quiet [list \
          MP_L2PHIC \
          AS_L2PHICn2_DELAY \
          AS_L2PHICn2 \
          VMSME_L2PHICn2_DELAY \
          VMSME_L2PHICn2 \
          MPROJ_L3L4AB_L2PHIC_DELAY \
          MPROJ_L3L4AB_L2PHIC \
          MPROJ_L3L4CD_L2PHIC_DELAY \
          MPROJ_L3L4CD_L2PHIC \
          MPROJ_L5L6ABCD_L2PHIC_DELAY \
          MPROJ_L5L6ABCD_L2PHIC \
          MPROJ_D1D2ABCD_L2PHIC_DELAY \
          MPROJ_D1D2ABCD_L2PHIC \
	  ]]
	  
create_pblock pblock_MPL2D
add_cells_to_pblock [get_pblocks pblock_MPL2D] [get_cells -quiet [list \
          MP_L2PHID \
          AS_L2PHIDn2_DELAY \
          AS_L2PHIDn2 \
          VMSME_L2PHIDn2_DELAY \
          VMSME_L2PHIDn2 \
          MPROJ_L3L4CD_L2PHID_DELAY \
          MPROJ_L3L4CD_L2PHID \
          MPROJ_L5L6ABCD_L2PHID_DELAY \
          MPROJ_L5L6ABCD_L2PHID \
          MPROJ_D1D2ABCD_L2PHID_DELAY \
          MPROJ_D1D2ABCD_L2PHID \
	  ]]

create_pblock pblock_MPL3A
add_cells_to_pblock [get_pblocks pblock_MPL3A] [get_cells -quiet [list \
          MP_L3PHIA \
          AS_L3PHIAn2_DELAY \
          AS_L3PHIAn2 \
          VMSME_L3PHIAn2_DELAY \
          VMSME_L3PHIAn2 \
          MPROJ_L1L2ABC_L3PHIA_DELAY \
          MPROJ_L1L2ABC_L3PHIA \
          MPROJ_L1L2DE_L3PHIA_DELAY \
          MPROJ_L1L2DE_L3PHIA \
          MPROJ_L5L6ABCD_L3PHIA_DELAY \
          MPROJ_L5L6ABCD_L3PHIA \
	  ]]
	  
create_pblock pblock_MPL3B
add_cells_to_pblock [get_pblocks pblock_MPL3B] [get_cells -quiet [list \
          MP_L3PHIB \
          AS_L3PHIBn2_DELAY \
          AS_L3PHIBn2 \
          VMSME_L3PHIBn2_DELAY \
          VMSME_L3PHIBn2 \
          MPROJ_L1L2ABC_L3PHIB_DELAY \
          MPROJ_L1L2ABC_L3PHIB \
          MPROJ_L1L2DE_L3PHIB_DELAY \
          MPROJ_L1L2DE_L3PHIB \
          MPROJ_L1L2F_L3PHIB_DELAY \
          MPROJ_L1L2F_L3PHIB \
          MPROJ_L1L2G_L3PHIB_DELAY \
          MPROJ_L1L2G_L3PHIB \
          MPROJ_L1L2HI_L3PHIB_DELAY \
          MPROJ_L1L2HI_L3PHIB \
          MPROJ_L5L6ABCD_L3PHIB_DELAY \
          MPROJ_L5L6ABCD_L3PHIB \
	  ]]
	  
create_pblock pblock_MPL3C
add_cells_to_pblock [get_pblocks pblock_MPL3C] [get_cells -quiet [list \
          MP_L3PHIC \
          AS_L3PHICn2_DELAY \
          AS_L3PHICn2 \
          VMSME_L3PHICn2_DELAY \
          VMSME_L3PHICn2 \
          MPROJ_L1L2DE_L3PHIC_DELAY \
          MPROJ_L1L2DE_L3PHIC \
          MPROJ_L1L2F_L3PHIC_DELAY \
          MPROJ_L1L2F_L3PHIC \
          MPROJ_L1L2G_L3PHIC_DELAY \
          MPROJ_L1L2G_L3PHIC \
          MPROJ_L1L2HI_L3PHIC_DELAY \
          MPROJ_L1L2HI_L3PHIC \
          MPROJ_L1L2JKL_L3PHIC_DELAY \
          MPROJ_L1L2JKL_L3PHIC \
          MPROJ_L5L6ABCD_L3PHIC_DELAY \
          MPROJ_L5L6ABCD_L3PHIC \
	  ]]
	  
create_pblock pblock_MPL3D
add_cells_to_pblock [get_pblocks pblock_MPL3D] [get_cells -quiet [list \
          MP_L3PHID \
          AS_L3PHIDn2_DELAY \
          AS_L3PHIDn2 \
          VMSME_L3PHIDn2_DELAY \
          VMSME_L3PHIDn2 \
          MPROJ_L1L2HI_L3PHID_DELAY \
          MPROJ_L1L2HI_L3PHID \
          MPROJ_L1L2JKL_L3PHID_DELAY \
          MPROJ_L1L2JKL_L3PHID \
          MPROJ_L5L6ABCD_L3PHID_DELAY \
          MPROJ_L5L6ABCD_L3PHID \
	  ]]

create_pblock pblock_MPL4A
add_cells_to_pblock [get_pblocks pblock_MPL4A] [get_cells -quiet [list \
          MP_L4PHIA \
          AS_L4PHIAn2_DELAY \
          AS_L4PHIAn2 \
          VMSME_L4PHIAn2_DELAY \
          VMSME_L4PHIAn2 \
          MPROJ_L1L2ABC_L4PHIA_DELAY \
          MPROJ_L1L2ABC_L4PHIA \
          MPROJ_L1L2DE_L4PHIA_DELAY \
          MPROJ_L1L2DE_L4PHIA \
          MPROJ_L2L3ABCD_L4PHIA_DELAY \
          MPROJ_L2L3ABCD_L4PHIA \
          MPROJ_L5L6ABCD_L4PHIA_DELAY \
          MPROJ_L5L6ABCD_L4PHIA \
	  ]]
	  
create_pblock pblock_MPL4B
add_cells_to_pblock [get_pblocks pblock_MPL4B] [get_cells -quiet [list \
          MP_L4PHIB \
          AS_L4PHIBn2_DELAY \
          AS_L4PHIBn2 \
          VMSME_L4PHIBn2_DELAY \
          VMSME_L4PHIBn2 \
          MPROJ_L1L2ABC_L4PHIB_DELAY \
          MPROJ_L1L2ABC_L4PHIB \
          MPROJ_L1L2DE_L4PHIB_DELAY \
          MPROJ_L1L2DE_L4PHIB \
          MPROJ_L1L2F_L4PHIB_DELAY \
          MPROJ_L1L2F_L4PHIB \
          MPROJ_L1L2G_L4PHIB_DELAY \
          MPROJ_L1L2G_L4PHIB \
          MPROJ_L1L2HI_L4PHIB_DELAY \
          MPROJ_L1L2HI_L4PHIB \
          MPROJ_L2L3ABCD_L4PHIB_DELAY \
          MPROJ_L2L3ABCD_L4PHIB \
          MPROJ_L5L6ABCD_L4PHIB_DELAY \
          MPROJ_L5L6ABCD_L4PHIB \
	  ]]
	  
create_pblock pblock_MPL4C
add_cells_to_pblock [get_pblocks pblock_MPL4C] [get_cells -quiet [list \
          MP_L4PHIC \
          AS_L4PHICn2_DELAY \
          AS_L4PHICn2 \
          VMSME_L4PHICn2_DELAY \
          VMSME_L4PHICn2 \
          MPROJ_L1L2DE_L4PHIC_DELAY \
          MPROJ_L1L2DE_L4PHIC \
          MPROJ_L1L2F_L4PHIC_DELAY \
          MPROJ_L1L2F_L4PHIC \
          MPROJ_L1L2G_L4PHIC_DELAY \
          MPROJ_L1L2G_L4PHIC \
          MPROJ_L1L2HI_L4PHIC_DELAY \
          MPROJ_L1L2HI_L4PHIC \
          MPROJ_L1L2JKL_L4PHIC_DELAY \
          MPROJ_L1L2JKL_L4PHIC \
          MPROJ_L2L3ABCD_L4PHIC_DELAY \
          MPROJ_L2L3ABCD_L4PHIC \
          MPROJ_L5L6ABCD_L4PHIC_DELAY \
          MPROJ_L5L6ABCD_L4PHIC \
	  ]]
	  
create_pblock pblock_MPL4D
add_cells_to_pblock [get_pblocks pblock_MPL4D] [get_cells -quiet [list \
          MP_L4PHID \
          AS_L4PHIDn2_DELAY \
          AS_L4PHIDn2 \
          VMSME_L4PHIDn2_DELAY \
          VMSME_L4PHIDn2 \
          MPROJ_L1L2HI_L4PHID_DELAY \
          MPROJ_L1L2HI_L4PHID \
          MPROJ_L1L2JKL_L4PHID_DELAY \
          MPROJ_L1L2JKL_L4PHID \
          MPROJ_L2L3ABCD_L4PHID_DELAY \
          MPROJ_L2L3ABCD_L4PHID \
          MPROJ_L5L6ABCD_L4PHID_DELAY \
          MPROJ_L5L6ABCD_L4PHID \
	  ]]

create_pblock pblock_MPL5A
add_cells_to_pblock [get_pblocks pblock_MPL5A] [get_cells -quiet [list \
          MP_L5PHIA \
          AS_L5PHIAn2_DELAY \
          AS_L5PHIAn2 \
          VMSME_L5PHIAn2_DELAY \
          VMSME_L5PHIAn2 \
          MPROJ_L1L2ABC_L5PHIA_DELAY \
          MPROJ_L1L2ABC_L5PHIA \
          MPROJ_L1L2DE_L5PHIA_DELAY \
          MPROJ_L1L2DE_L5PHIA \
          MPROJ_L1L2F_L5PHIA_DELAY \
          MPROJ_L1L2F_L5PHIA \
          MPROJ_L2L3ABCD_L5PHIA_DELAY \
          MPROJ_L2L3ABCD_L5PHIA \
          MPROJ_L3L4AB_L5PHIA_DELAY \
          MPROJ_L3L4AB_L5PHIA \
	  ]]
	  
create_pblock pblock_MPL5B
add_cells_to_pblock [get_pblocks pblock_MPL5B] [get_cells -quiet [list \
          MP_L5PHIB \
          AS_L5PHIBn2_DELAY \
          AS_L5PHIBn2 \
          VMSME_L5PHIBn2_DELAY \
          VMSME_L5PHIBn2 \
          MPROJ_L1L2ABC_L5PHIB_DELAY \
          MPROJ_L1L2ABC_L5PHIB \
          MPROJ_L1L2DE_L5PHIB_DELAY \
          MPROJ_L1L2DE_L5PHIB \
          MPROJ_L1L2F_L5PHIB_DELAY \
          MPROJ_L1L2F_L5PHIB \
          MPROJ_L1L2G_L5PHIB_DELAY \
          MPROJ_L1L2G_L5PHIB \
          MPROJ_L1L2HI_L5PHIB_DELAY \
          MPROJ_L1L2HI_L5PHIB \
          MPROJ_L2L3ABCD_L5PHIB_DELAY \
          MPROJ_L2L3ABCD_L5PHIB \
          MPROJ_L3L4AB_L5PHIB_DELAY \
          MPROJ_L3L4AB_L5PHIB \
          MPROJ_L3L4CD_L5PHIB_DELAY \
          MPROJ_L3L4CD_L5PHIB \
	  ]]
	  
create_pblock pblock_MPL5C
add_cells_to_pblock [get_pblocks pblock_MPL5C] [get_cells -quiet [list \
          MP_L5PHIC \
          AS_L5PHICn2_DELAY \
          AS_L5PHICn2 \
          VMSME_L5PHICn2_DELAY \
          VMSME_L5PHICn2 \
          MPROJ_L1L2DE_L5PHIC_DELAY \
          MPROJ_L1L2DE_L5PHIC \
          MPROJ_L1L2F_L5PHIC_DELAY \
          MPROJ_L1L2F_L5PHIC \
          MPROJ_L1L2G_L5PHIC_DELAY \
          MPROJ_L1L2G_L5PHIC \
          MPROJ_L1L2HI_L5PHIC_DELAY \
          MPROJ_L1L2HI_L5PHIC \
          MPROJ_L1L2JKL_L5PHIC_DELAY \
          MPROJ_L1L2JKL_L5PHIC \
          MPROJ_L2L3ABCD_L5PHIC_DELAY \
          MPROJ_L2L3ABCD_L5PHIC \
          MPROJ_L3L4AB_L5PHIC_DELAY \
          MPROJ_L3L4AB_L5PHIC \
          MPROJ_L3L4CD_L5PHIC_DELAY \
          MPROJ_L3L4CD_L5PHIC \
	  ]]
	  
create_pblock pblock_MPL5D
add_cells_to_pblock [get_pblocks pblock_MPL5D] [get_cells -quiet [list \
          MP_L5PHID \
          AS_L5PHIDn2_DELAY \
          AS_L5PHIDn2 \
          VMSME_L5PHIDn2_DELAY \
          VMSME_L5PHIDn2 \
          MPROJ_L1L2G_L5PHID_DELAY \
          MPROJ_L1L2G_L5PHID \
          MPROJ_L1L2HI_L5PHID_DELAY \
          MPROJ_L1L2HI_L5PHID \
          MPROJ_L1L2JKL_L5PHID_DELAY \
          MPROJ_L1L2JKL_L5PHID \
          MPROJ_L2L3ABCD_L5PHID_DELAY \
          MPROJ_L2L3ABCD_L5PHID \
          MPROJ_L3L4CD_L5PHID_DELAY \
          MPROJ_L3L4CD_L5PHID \
	  ]]

create_pblock pblock_MPL6A
add_cells_to_pblock [get_pblocks pblock_MPL6A] [get_cells -quiet [list \
          MP_L6PHIA \
          AS_L6PHIAn2_DELAY \
          AS_L6PHIAn2 \
          VMSME_L6PHIAn2_DELAY \
          VMSME_L6PHIAn2 \
          MPROJ_L1L2ABC_L6PHIA_DELAY \
          MPROJ_L1L2ABC_L6PHIA \
          MPROJ_L1L2DE_L6PHIA_DELAY \
          MPROJ_L1L2DE_L6PHIA \
          MPROJ_L1L2F_L6PHIA_DELAY \
          MPROJ_L1L2F_L6PHIA \
          MPROJ_L3L4AB_L6PHIA_DELAY \
          MPROJ_L3L4AB_L6PHIA \
	  ]]
	  
create_pblock pblock_MPL6B
add_cells_to_pblock [get_pblocks pblock_MPL6B] [get_cells -quiet [list \
          MP_L6PHIB \        
          AS_L6PHIBn2_DELAY \
          AS_L6PHIBn2 \
          VMSME_L6PHIBn2_DELAY \
          VMSME_L6PHIBn2 \
          MPROJ_L1L2ABC_L6PHIB_DELAY \
          MPROJ_L1L2ABC_L6PHIB \
          MPROJ_L1L2DE_L6PHIB_DELAY \
          MPROJ_L1L2DE_L6PHIB \
          MPROJ_L1L2F_L6PHIB_DELAY \
          MPROJ_L1L2F_L6PHIB \
          MPROJ_L1L2G_L6PHIB_DELAY \
          MPROJ_L1L2G_L6PHIB \
          MPROJ_L1L2HI_L6PHIB_DELAY \
          MPROJ_L1L2HI_L6PHIB \
          MPROJ_L3L4AB_L6PHIB_DELAY \
          MPROJ_L3L4AB_L6PHIB \
          MPROJ_L3L4CD_L6PHIB_DELAY \
          MPROJ_L3L4CD_L6PHIB \
	  ]]
	  
create_pblock pblock_MPL6C
add_cells_to_pblock [get_pblocks pblock_MPL6C] [get_cells -quiet [list \
          MP_L6PHIC \
          AS_L6PHICn2_DELAY \
          AS_L6PHICn2 \
          VMSME_L6PHICn2_DELAY \
          VMSME_L6PHICn2 \
          MPROJ_L1L2DE_L6PHIC_DELAY \
          MPROJ_L1L2DE_L6PHIC \
          MPROJ_L1L2F_L6PHIC_DELAY \
          MPROJ_L1L2F_L6PHIC \
          MPROJ_L1L2G_L6PHIC_DELAY \
          MPROJ_L1L2G_L6PHIC \
          MPROJ_L1L2HI_L6PHIC_DELAY \
          MPROJ_L1L2HI_L6PHIC \
          MPROJ_L1L2JKL_L6PHIC_DELAY \
          MPROJ_L1L2JKL_L6PHIC \
          MPROJ_L3L4AB_L6PHIC_DELAY \
          MPROJ_L3L4AB_L6PHIC \
          MPROJ_L3L4CD_L6PHIC_DELAY \
          MPROJ_L3L4CD_L6PHIC \
	  ]]
	  
create_pblock pblock_MPL6D
add_cells_to_pblock [get_pblocks pblock_MPL6D] [get_cells -quiet [list \
          MP_L6PHID \
          AS_L6PHIDn2_DELAY \
          AS_L6PHIDn2 \
          VMSME_L6PHIDn2_DELAY \
          VMSME_L6PHIDn2 \
          MPROJ_L1L2G_L6PHID_DELAY \
          MPROJ_L1L2G_L6PHID \
          MPROJ_L1L2HI_L6PHID_DELAY \
          MPROJ_L1L2HI_L6PHID \
          MPROJ_L1L2JKL_L6PHID_DELAY \
          MPROJ_L1L2JKL_L6PHID \
          MPROJ_L3L4CD_L6PHID_DELAY \
          MPROJ_L3L4CD_L6PHID \
	  ]]
	  
resize_pblock [get_pblocks pblock_MPL1A] -add {CLOCKREGION_X0Y0:CLOCKREGION_X0Y0}
resize_pblock [get_pblocks pblock_MPL1B] -add {CLOCKREGION_X0Y1:CLOCKREGION_X0Y1}
resize_pblock [get_pblocks pblock_MPL1C] -add {CLOCKREGION_X0Y2:CLOCKREGION_X0Y2}
resize_pblock [get_pblocks pblock_MPL1D] -add {CLOCKREGION_X0Y3:CLOCKREGION_X0Y3}
resize_pblock [get_pblocks pblock_MPL1E] -add {CLOCKREGION_X1Y0:CLOCKREGION_X1Y0}
resize_pblock [get_pblocks pblock_MPL1F] -add {CLOCKREGION_X1Y1:CLOCKREGION_X1Y1}
resize_pblock [get_pblocks pblock_MPL1G] -add {CLOCKREGION_X1Y2:CLOCKREGION_X1Y2}
resize_pblock [get_pblocks pblock_MPL1H] -add {CLOCKREGION_X1Y3:CLOCKREGION_X1Y3}

resize_pblock [get_pblocks pblock_MPL2A] -add {CLOCKREGION_X2Y0:CLOCKREGION_X2Y0}
resize_pblock [get_pblocks pblock_MPL2B] -add {CLOCKREGION_X2Y1:CLOCKREGION_X2Y1}
resize_pblock [get_pblocks pblock_MPL2C] -add {CLOCKREGION_X2Y2:CLOCKREGION_X2Y2}
resize_pblock [get_pblocks pblock_MPL2D] -add {CLOCKREGION_X2Y3:CLOCKREGION_X2Y3}

resize_pblock [get_pblocks pblock_MPL3A] -add {CLOCKREGION_X3Y0:CLOCKREGION_X3Y0}
resize_pblock [get_pblocks pblock_MPL3B] -add {CLOCKREGION_X3Y1:CLOCKREGION_X3Y1}
resize_pblock [get_pblocks pblock_MPL3C] -add {CLOCKREGION_X3Y2:CLOCKREGION_X3Y2}
resize_pblock [get_pblocks pblock_MPL3D] -add {CLOCKREGION_X3Y3:CLOCKREGION_X3Y3}

resize_pblock [get_pblocks pblock_MPL4A] -add {CLOCKREGION_X4Y0:CLOCKREGION_X4Y0}
resize_pblock [get_pblocks pblock_MPL4B] -add {CLOCKREGION_X4Y1:CLOCKREGION_X4Y1}
resize_pblock [get_pblocks pblock_MPL4C] -add {CLOCKREGION_X4Y2:CLOCKREGION_X4Y2}
resize_pblock [get_pblocks pblock_MPL4D] -add {CLOCKREGION_X4Y3:CLOCKREGION_X4Y3}

resize_pblock [get_pblocks pblock_MPL5A] -add {CLOCKREGION_X6Y0:CLOCKREGION_X6Y0}
resize_pblock [get_pblocks pblock_MPL5B] -add {CLOCKREGION_X5Y1:CLOCKREGION_X6Y1}
resize_pblock [get_pblocks pblock_MPL5C] -add {CLOCKREGION_X5Y2:CLOCKREGION_X6Y2}
resize_pblock [get_pblocks pblock_MPL5D] -add {CLOCKREGION_X6Y3:CLOCKREGION_X6Y3}

resize_pblock [get_pblocks pblock_MPL6A] -add {CLOCKREGION_X7Y0:CLOCKREGION_X7Y0}
resize_pblock [get_pblocks pblock_MPL6B] -add {CLOCKREGION_X7Y1:CLOCKREGION_X7Y1}
resize_pblock [get_pblocks pblock_MPL6C] -add {CLOCKREGION_X7Y2:CLOCKREGION_X7Y2}
resize_pblock [get_pblocks pblock_MPL6D] -add {CLOCKREGION_X7Y3:CLOCKREGION_X7Y3}


create_pblock pblock_MPD1A
add_cells_to_pblock [get_pblocks pblock_MPD1A] [get_cells -quiet [list \
	  MP_D1PHIA \
          AS_D1PHIAn2_DELAY \
          AS_D1PHIAn2 \
          VMSME_D1PHIAn2_DELAY \
          VMSME_D1PHIAn2 \
          MPROJ_L1L2ABC_D1PHIA_DELAY \
          MPROJ_L1L2ABC_D1PHIA \
          MPROJ_L1L2DE_D1PHIA_DELAY \
          MPROJ_L1L2DE_D1PHIA \
          MPROJ_L1L2F_D1PHIA_DELAY \
          MPROJ_L1L2F_D1PHIA \
          MPROJ_L2L3ABCD_D1PHIA_DELAY \
          MPROJ_L2L3ABCD_D1PHIA \
          MPROJ_L3L4AB_D1PHIA_DELAY \
          MPROJ_L3L4AB_D1PHIA \
          MPROJ_D3D4ABCD_D1PHIA_DELAY \
          MPROJ_D3D4ABCD_D1PHIA \
	  ]]
	  
create_pblock pblock_MPD1B
add_cells_to_pblock [get_pblocks pblock_MPD1B] [get_cells -quiet [list \
          MP_D1PHIB \
          AS_D1PHIBn2_DELAY \
          AS_D1PHIBn2 \
          VMSME_D1PHIBn2_DELAY \
          VMSME_D1PHIBn2 \
          MPROJ_L1L2ABC_D1PHIB_DELAY \
          MPROJ_L1L2ABC_D1PHIB \
          MPROJ_L1L2DE_D1PHIB_DELAY \
          MPROJ_L1L2DE_D1PHIB \
          MPROJ_L1L2F_D1PHIB_DELAY \
          MPROJ_L1L2F_D1PHIB \
          MPROJ_L1L2G_D1PHIB_DELAY \
          MPROJ_L1L2G_D1PHIB \
          MPROJ_L1L2HI_D1PHIB_DELAY \
          MPROJ_L1L2HI_D1PHIB \
          MPROJ_L2L3ABCD_D1PHIB_DELAY \
          MPROJ_L2L3ABCD_D1PHIB \
          MPROJ_L3L4AB_D1PHIB_DELAY \
          MPROJ_L3L4AB_D1PHIB \
          MPROJ_L3L4CD_D1PHIB_DELAY \
          MPROJ_L3L4CD_D1PHIB \
          MPROJ_D3D4ABCD_D1PHIB_DELAY \
          MPROJ_D3D4ABCD_D1PHIB \
	  ]]
	  
create_pblock pblock_MPD1C
add_cells_to_pblock [get_pblocks pblock_MPD1C] [get_cells -quiet [list \
          MP_D1PHIC \
          AS_D1PHICn2_DELAY \
          AS_D1PHICn2 \
          VMSME_D1PHICn2_DELAY \
          VMSME_D1PHICn2 \
          MPROJ_L1L2DE_D1PHIC_DELAY \
          MPROJ_L1L2DE_D1PHIC \
          MPROJ_L1L2F_D1PHIC_DELAY \
          MPROJ_L1L2F_D1PHIC \
          MPROJ_L1L2G_D1PHIC_DELAY \
          MPROJ_L1L2G_D1PHIC \
          MPROJ_L1L2HI_D1PHIC_DELAY \
          MPROJ_L1L2HI_D1PHIC \
          MPROJ_L1L2JKL_D1PHIC_DELAY \
          MPROJ_L1L2JKL_D1PHIC \
          MPROJ_L2L3ABCD_D1PHIC_DELAY \
          MPROJ_L2L3ABCD_D1PHIC \
          MPROJ_L3L4AB_D1PHIC_DELAY \
          MPROJ_L3L4AB_D1PHIC \
          MPROJ_L3L4CD_D1PHIC_DELAY \
          MPROJ_L3L4CD_D1PHIC \
          MPROJ_D3D4ABCD_D1PHIC_DELAY \
          MPROJ_D3D4ABCD_D1PHIC \
	  ]]
	  
create_pblock pblock_MPD1D
add_cells_to_pblock [get_pblocks pblock_MPD1D] [get_cells -quiet [list \
          MP_D1PHID \
          AS_D1PHIDn2_DELAY \
          AS_D1PHIDn2 \
          VMSME_D1PHIDn2_DELAY \
          VMSME_D1PHIDn2 \
          MPROJ_L1L2G_D1PHID_DELAY \
          MPROJ_L1L2G_D1PHID \
          MPROJ_L1L2HI_D1PHID_DELAY \
          MPROJ_L1L2HI_D1PHID \
          MPROJ_L1L2JKL_D1PHID_DELAY \
          MPROJ_L1L2JKL_D1PHID \
          MPROJ_L2L3ABCD_D1PHID_DELAY \
          MPROJ_L2L3ABCD_D1PHID \
          MPROJ_L3L4CD_D1PHID_DELAY \
          MPROJ_L3L4CD_D1PHID \
          MPROJ_D3D4ABCD_D1PHID_DELAY \
          MPROJ_D3D4ABCD_D1PHID \
	  ]]
	  
create_pblock pblock_MPD2A
add_cells_to_pblock [get_pblocks pblock_MPD2A] [get_cells -quiet [list \
          MP_D2PHIA \
          AS_D2PHIAn2_DELAY \
          AS_D2PHIAn2 \
          VMSME_D2PHIAn2_DELAY \
          VMSME_D2PHIAn2 \
          MPROJ_L1L2ABC_D2PHIA_DELAY \
          MPROJ_L1L2ABC_D2PHIA \
          MPROJ_L1L2DE_D2PHIA_DELAY \
          MPROJ_L1L2DE_D2PHIA \
          MPROJ_L1L2F_D2PHIA_DELAY \
          MPROJ_L1L2F_D2PHIA \
          MPROJ_L2L3ABCD_D2PHIA_DELAY \
          MPROJ_L2L3ABCD_D2PHIA \
          MPROJ_L3L4AB_D2PHIA_DELAY \
          MPROJ_L3L4AB_D2PHIA \
          MPROJ_D3D4ABCD_D2PHIA_DELAY \
          MPROJ_D3D4ABCD_D2PHIA \
          MPROJ_L1D1ABCD_D2PHIA_DELAY \
          MPROJ_L1D1ABCD_D2PHIA \
          MPROJ_L2D1ABCD_D2PHIA_DELAY \
          MPROJ_L2D1ABCD_D2PHIA \
	  ]]
	  
create_pblock pblock_MPD2B
add_cells_to_pblock [get_pblocks pblock_MPD2B] [get_cells -quiet [list \
          MP_D2PHIB \
          AS_D2PHIBn2_DELAY \
          AS_D2PHIBn2 \
          VMSME_D2PHIBn2_DELAY \
          VMSME_D2PHIBn2 \
          MPROJ_L1L2ABC_D2PHIB_DELAY \
          MPROJ_L1L2ABC_D2PHIB \
          MPROJ_L1L2DE_D2PHIB_DELAY \
          MPROJ_L1L2DE_D2PHIB \
          MPROJ_L1L2F_D2PHIB_DELAY \
          MPROJ_L1L2F_D2PHIB \
          MPROJ_L1L2G_D2PHIB_DELAY \
          MPROJ_L1L2G_D2PHIB \
          MPROJ_L1L2HI_D2PHIB_DELAY \
          MPROJ_L1L2HI_D2PHIB \
          MPROJ_L2L3ABCD_D2PHIB_DELAY \
          MPROJ_L2L3ABCD_D2PHIB \
          MPROJ_L3L4AB_D2PHIB_DELAY \
          MPROJ_L3L4AB_D2PHIB \
          MPROJ_L3L4CD_D2PHIB_DELAY \
          MPROJ_L3L4CD_D2PHIB \
          MPROJ_D3D4ABCD_D2PHIB_DELAY \
          MPROJ_D3D4ABCD_D2PHIB \
          MPROJ_L1D1ABCD_D2PHIB_DELAY \
          MPROJ_L1D1ABCD_D2PHIB \
          MPROJ_L1D1EFGH_D2PHIB_DELAY \
          MPROJ_L1D1EFGH_D2PHIB \
          MPROJ_L2D1ABCD_D2PHIB_DELAY \
          MPROJ_L2D1ABCD_D2PHIB \
	  ]]
	  
create_pblock pblock_MPD2C
add_cells_to_pblock [get_pblocks pblock_MPD2C] [get_cells -quiet [list \
          MP_D2PHIC \
          AS_D2PHICn2_DELAY \
          AS_D2PHICn2 \
          VMSME_D2PHICn2_DELAY \
          VMSME_D2PHICn2 \
          MPROJ_L1L2DE_D2PHIC_DELAY \
          MPROJ_L1L2DE_D2PHIC \
          MPROJ_L1L2F_D2PHIC_DELAY \
          MPROJ_L1L2F_D2PHIC \
          MPROJ_L1L2G_D2PHIC_DELAY \
          MPROJ_L1L2G_D2PHIC \
          MPROJ_L1L2HI_D2PHIC_DELAY \
          MPROJ_L1L2HI_D2PHIC \
          MPROJ_L1L2JKL_D2PHIC_DELAY \
          MPROJ_L1L2JKL_D2PHIC \
          MPROJ_L2L3ABCD_D2PHIC_DELAY \
          MPROJ_L2L3ABCD_D2PHIC \
          MPROJ_L3L4AB_D2PHIC_DELAY \
          MPROJ_L3L4AB_D2PHIC \
          MPROJ_L3L4CD_D2PHIC_DELAY \
          MPROJ_L3L4CD_D2PHIC \
          MPROJ_D3D4ABCD_D2PHIC_DELAY \
          MPROJ_D3D4ABCD_D2PHIC \
          MPROJ_L1D1ABCD_D2PHIC_DELAY \
          MPROJ_L1D1ABCD_D2PHIC \
          MPROJ_L1D1EFGH_D2PHIC_DELAY \
          MPROJ_L1D1EFGH_D2PHIC \
          MPROJ_L2D1ABCD_D2PHIC_DELAY \
          MPROJ_L2D1ABCD_D2PHIC \
	  ]]
	  
create_pblock pblock_MPD2D
add_cells_to_pblock [get_pblocks pblock_MPD2D] [get_cells -quiet [list \
          MP_D2PHID \
          AS_D2PHIDn2_DELAY \
          AS_D2PHIDn2 \
          VMSME_D2PHIDn2_DELAY \
          VMSME_D2PHIDn2 \
          MPROJ_L1L2G_D2PHID_DELAY \
          MPROJ_L1L2G_D2PHID \
          MPROJ_L1L2HI_D2PHID_DELAY \
          MPROJ_L1L2HI_D2PHID \
          MPROJ_L1L2JKL_D2PHID_DELAY \
          MPROJ_L1L2JKL_D2PHID \
          MPROJ_L2L3ABCD_D2PHID_DELAY \
          MPROJ_L2L3ABCD_D2PHID \
          MPROJ_L3L4CD_D2PHID_DELAY \
          MPROJ_L3L4CD_D2PHID \
          MPROJ_D3D4ABCD_D2PHID_DELAY \
          MPROJ_D3D4ABCD_D2PHID \
          MPROJ_L1D1EFGH_D2PHID_DELAY \
          MPROJ_L1D1EFGH_D2PHID \
          MPROJ_L2D1ABCD_D2PHID_DELAY \
          MPROJ_L2D1ABCD_D2PHID \
	  ]]
	  
create_pblock pblock_MPD3A
add_cells_to_pblock [get_pblocks pblock_MPD3A] [get_cells -quiet [list \
          MP_D3PHIA \
          AS_D3PHIAn2_DELAY \
          AS_D3PHIAn2 \
          VMSME_D3PHIAn2_DELAY \
          VMSME_D3PHIAn2 \
          MPROJ_L1L2ABC_D3PHIA_DELAY \
          MPROJ_L1L2ABC_D3PHIA \
          MPROJ_L1L2DE_D3PHIA_DELAY \
          MPROJ_L1L2DE_D3PHIA \
          MPROJ_L1L2F_D3PHIA_DELAY \
          MPROJ_L1L2F_D3PHIA \
          MPROJ_L2L3ABCD_D3PHIA_DELAY \
          MPROJ_L2L3ABCD_D3PHIA \
          MPROJ_D1D2ABCD_D3PHIA_DELAY \
          MPROJ_D1D2ABCD_D3PHIA \
          MPROJ_L1D1ABCD_D3PHIA_DELAY \
          MPROJ_L1D1ABCD_D3PHIA \
          MPROJ_L2D1ABCD_D3PHIA_DELAY \
          MPROJ_L2D1ABCD_D3PHIA \
	  ]]
	  
create_pblock pblock_MPD3B
add_cells_to_pblock [get_pblocks pblock_MPD3B] [get_cells -quiet [list \
          MP_D3PHIB \
          AS_D3PHIBn2_DELAY \
          AS_D3PHIBn2 \
          VMSME_D3PHIBn2_DELAY \
          VMSME_D3PHIBn2 \
          MPROJ_L1L2ABC_D3PHIB_DELAY \
          MPROJ_L1L2ABC_D3PHIB \
          MPROJ_L1L2DE_D3PHIB_DELAY \
          MPROJ_L1L2DE_D3PHIB \
          MPROJ_L1L2F_D3PHIB_DELAY \
          MPROJ_L1L2F_D3PHIB \
          MPROJ_L1L2G_D3PHIB_DELAY \
          MPROJ_L1L2G_D3PHIB \
          MPROJ_L1L2HI_D3PHIB_DELAY \
          MPROJ_L1L2HI_D3PHIB \
          MPROJ_L2L3ABCD_D3PHIB_DELAY \
          MPROJ_L2L3ABCD_D3PHIB \
          MPROJ_D1D2ABCD_D3PHIB_DELAY \
          MPROJ_D1D2ABCD_D3PHIB \
          MPROJ_L1D1ABCD_D3PHIB_DELAY \
          MPROJ_L1D1ABCD_D3PHIB \
          MPROJ_L1D1EFGH_D3PHIB_DELAY \
          MPROJ_L1D1EFGH_D3PHIB \
          MPROJ_L2D1ABCD_D3PHIB_DELAY \
          MPROJ_L2D1ABCD_D3PHIB \
	  ]]
	  
create_pblock pblock_MPD3C
add_cells_to_pblock [get_pblocks pblock_MPD3C] [get_cells -quiet [list \
          MP_D3PHIC \
          AS_D3PHICn2_DELAY \
          AS_D3PHICn2 \
          VMSME_D3PHICn2_DELAY \
          VMSME_D3PHICn2 \
          MPROJ_L1L2DE_D3PHIC_DELAY \
          MPROJ_L1L2DE_D3PHIC \
          MPROJ_L1L2F_D3PHIC_DELAY \
          MPROJ_L1L2F_D3PHIC \
          MPROJ_L1L2G_D3PHIC_DELAY \
          MPROJ_L1L2G_D3PHIC \
          MPROJ_L1L2HI_D3PHIC_DELAY \
          MPROJ_L1L2HI_D3PHIC \
          MPROJ_L1L2JKL_D3PHIC_DELAY \
          MPROJ_L1L2JKL_D3PHIC \
          MPROJ_L2L3ABCD_D3PHIC_DELAY \
          MPROJ_L2L3ABCD_D3PHIC \
          MPROJ_D1D2ABCD_D3PHIC_DELAY \
          MPROJ_D1D2ABCD_D3PHIC \
          MPROJ_L1D1ABCD_D3PHIC_DELAY \
          MPROJ_L1D1ABCD_D3PHIC \
          MPROJ_L1D1EFGH_D3PHIC_DELAY \
          MPROJ_L1D1EFGH_D3PHIC \
          MPROJ_L2D1ABCD_D3PHIC_DELAY \
          MPROJ_L2D1ABCD_D3PHIC \
	  ]]
	  
create_pblock pblock_MPD3D
add_cells_to_pblock [get_pblocks pblock_MPD3D] [get_cells -quiet [list \
          MP_D3PHID \
          AS_D3PHIDn2_DELAY \
          AS_D3PHIDn2 \
          VMSME_D3PHIDn2_DELAY \
          VMSME_D3PHIDn2 \
          MPROJ_L1L2G_D3PHID_DELAY \
          MPROJ_L1L2G_D3PHID \
          MPROJ_L1L2HI_D3PHID_DELAY \
          MPROJ_L1L2HI_D3PHID \
          MPROJ_L1L2JKL_D3PHID_DELAY \
          MPROJ_L1L2JKL_D3PHID \
          MPROJ_L2L3ABCD_D3PHID_DELAY \
          MPROJ_L2L3ABCD_D3PHID \
          MPROJ_D1D2ABCD_D3PHID_DELAY \
          MPROJ_D1D2ABCD_D3PHID \
          MPROJ_L1D1EFGH_D3PHID_DELAY \
          MPROJ_L1D1EFGH_D3PHID \
          MPROJ_L2D1ABCD_D3PHID_DELAY \
          MPROJ_L2D1ABCD_D3PHID \
	  ]]
	  
create_pblock pblock_MPD4A
add_cells_to_pblock [get_pblocks pblock_MPD4A] [get_cells -quiet [list \
          MP_D4PHIA \
          AS_D4PHIAn2_DELAY \
          AS_D4PHIAn2 \
          VMSME_D4PHIAn2_DELAY \
          VMSME_D4PHIAn2 \
          MPROJ_L1L2ABC_D4PHIA_DELAY \
          MPROJ_L1L2ABC_D4PHIA \
          MPROJ_L1L2DE_D4PHIA_DELAY \
          MPROJ_L1L2DE_D4PHIA \
          MPROJ_L1L2F_D4PHIA_DELAY \
          MPROJ_L1L2F_D4PHIA \
          MPROJ_L2L3ABCD_D4PHIA_DELAY \
          MPROJ_L2L3ABCD_D4PHIA \
          MPROJ_D1D2ABCD_D4PHIA_DELAY \
          MPROJ_D1D2ABCD_D4PHIA \
          MPROJ_L1D1ABCD_D4PHIA_DELAY \
          MPROJ_L1D1ABCD_D4PHIA \
          MPROJ_L2D1ABCD_D4PHIA_DELAY \
          MPROJ_L2D1ABCD_D4PHIA \
	  ]]
	  
create_pblock pblock_MPD4B
add_cells_to_pblock [get_pblocks pblock_MPD4B] [get_cells -quiet [list \
          MP_D4PHIB \
          AS_D4PHIBn2_DELAY \
          AS_D4PHIBn2 \
          VMSME_D4PHIBn2_DELAY \
          VMSME_D4PHIBn2 \
          MPROJ_L1L2ABC_D4PHIB_DELAY \
          MPROJ_L1L2ABC_D4PHIB \
          MPROJ_L1L2DE_D4PHIB_DELAY \
          MPROJ_L1L2DE_D4PHIB \
          MPROJ_L1L2F_D4PHIB_DELAY \
          MPROJ_L1L2F_D4PHIB \
          MPROJ_L1L2G_D4PHIB_DELAY \
          MPROJ_L1L2G_D4PHIB \
          MPROJ_L1L2HI_D4PHIB_DELAY \
          MPROJ_L1L2HI_D4PHIB \
          MPROJ_L2L3ABCD_D4PHIB_DELAY \
          MPROJ_L2L3ABCD_D4PHIB \
          MPROJ_D1D2ABCD_D4PHIB_DELAY \
          MPROJ_D1D2ABCD_D4PHIB \
          MPROJ_L1D1ABCD_D4PHIB_DELAY \
          MPROJ_L1D1ABCD_D4PHIB \
          MPROJ_L1D1EFGH_D4PHIB_DELAY \
          MPROJ_L1D1EFGH_D4PHIB \
          MPROJ_L2D1ABCD_D4PHIB_DELAY \
          MPROJ_L2D1ABCD_D4PHIB \
	  ]]
	  
create_pblock pblock_MPD4C
add_cells_to_pblock [get_pblocks pblock_MPD4C] [get_cells -quiet [list \
          MP_D4PHIC \
          AS_D4PHICn2_DELAY \
          AS_D4PHICn2 \
          VMSME_D4PHICn2_DELAY \
          VMSME_D4PHICn2 \
          MPROJ_L1L2DE_D4PHIC_DELAY \
          MPROJ_L1L2DE_D4PHIC \
          MPROJ_L1L2F_D4PHIC_DELAY \
          MPROJ_L1L2F_D4PHIC \
          MPROJ_L1L2G_D4PHIC_DELAY \
          MPROJ_L1L2G_D4PHIC \
          MPROJ_L1L2HI_D4PHIC_DELAY \
          MPROJ_L1L2HI_D4PHIC \
          MPROJ_L1L2JKL_D4PHIC_DELAY \
          MPROJ_L1L2JKL_D4PHIC \
          MPROJ_L2L3ABCD_D4PHIC_DELAY \
          MPROJ_L2L3ABCD_D4PHIC \
          MPROJ_D1D2ABCD_D4PHIC_DELAY \
          MPROJ_D1D2ABCD_D4PHIC \
          MPROJ_L1D1ABCD_D4PHIC_DELAY \
          MPROJ_L1D1ABCD_D4PHIC \
          MPROJ_L1D1EFGH_D4PHIC_DELAY \
          MPROJ_L1D1EFGH_D4PHIC \
          MPROJ_L2D1ABCD_D4PHIC_DELAY \
          MPROJ_L2D1ABCD_D4PHIC \
	  ]]
	  
create_pblock pblock_MPD4D
add_cells_to_pblock [get_pblocks pblock_MPD4D] [get_cells -quiet [list \
          MP_D4PHID \
          AS_D4PHIDn2_DELAY \
          AS_D4PHIDn2 \
          VMSME_D4PHIDn2_DELAY \
          VMSME_D4PHIDn2 \
          MPROJ_L1L2G_D4PHID_DELAY \
          MPROJ_L1L2G_D4PHID \
          MPROJ_L1L2HI_D4PHID_DELAY \
          MPROJ_L1L2HI_D4PHID \
          MPROJ_L1L2JKL_D4PHID_DELAY \
          MPROJ_L1L2JKL_D4PHID \
          MPROJ_L2L3ABCD_D4PHID_DELAY \
          MPROJ_L2L3ABCD_D4PHID \
          MPROJ_D1D2ABCD_D4PHID_DELAY \
          MPROJ_D1D2ABCD_D4PHID \
          MPROJ_L1D1EFGH_D4PHID_DELAY \
          MPROJ_L1D1EFGH_D4PHID \
          MPROJ_L2D1ABCD_D4PHID_DELAY \
          MPROJ_L2D1ABCD_D4PHID \
	  ]]
	  
create_pblock pblock_MPD5A
add_cells_to_pblock [get_pblocks pblock_MPD5A] [get_cells -quiet [list \
          MP_D5PHIA \
          AS_D5PHIAn2_DELAY \
          AS_D5PHIAn2 \
          VMSME_D5PHIAn2_DELAY \
          VMSME_D5PHIAn2 \
          MPROJ_D1D2ABCD_D5PHIA_DELAY \
          MPROJ_D1D2ABCD_D5PHIA \
          MPROJ_D3D4ABCD_D5PHIA_DELAY \
          MPROJ_D3D4ABCD_D5PHIA \
          MPROJ_L1D1ABCD_D5PHIA_DELAY \
          MPROJ_L1D1ABCD_D5PHIA \
	  ]]
	  
create_pblock pblock_MPD5B
add_cells_to_pblock [get_pblocks pblock_MPD5B] [get_cells -quiet [list \
          MP_D5PHIB \
          AS_D5PHIBn2_DELAY \
          AS_D5PHIBn2 \
          VMSME_D5PHIBn2_DELAY \
          VMSME_D5PHIBn2 \
          MPROJ_D1D2ABCD_D5PHIB_DELAY \
          MPROJ_D1D2ABCD_D5PHIB \
          MPROJ_D3D4ABCD_D5PHIB_DELAY \
          MPROJ_D3D4ABCD_D5PHIB \
          MPROJ_L1D1ABCD_D5PHIB_DELAY \
          MPROJ_L1D1ABCD_D5PHIB \
          MPROJ_L1D1EFGH_D5PHIB_DELAY \
          MPROJ_L1D1EFGH_D5PHIB \
	  ]]
	  
create_pblock pblock_MPD5C
add_cells_to_pblock [get_pblocks pblock_MPD5C] [get_cells -quiet [list \
          MP_D5PHIC \
          AS_D5PHICn2_DELAY \
          AS_D5PHICn2 \
          VMSME_D5PHICn2_DELAY \
          VMSME_D5PHICn2 \
          MPROJ_D1D2ABCD_D5PHIC_DELAY \
          MPROJ_D1D2ABCD_D5PHIC \
          MPROJ_D3D4ABCD_D5PHIC_DELAY \
          MPROJ_D3D4ABCD_D5PHIC \
          MPROJ_L1D1ABCD_D5PHIC_DELAY \
          MPROJ_L1D1ABCD_D5PHIC \
          MPROJ_L1D1EFGH_D5PHIC_DELAY \
          MPROJ_L1D1EFGH_D5PHIC \
	  ]]
	  
create_pblock pblock_MPD5D
add_cells_to_pblock [get_pblocks pblock_MPD5D] [get_cells -quiet [list \
          MP_D5PHID \
          AS_D5PHIDn2_DELAY \
          AS_D5PHIDn2 \
          VMSME_D5PHIDn2_DELAY \
          VMSME_D5PHIDn2 \
          MPROJ_D1D2ABCD_D5PHID_DELAY \
          MPROJ_D1D2ABCD_D5PHID \
          MPROJ_D3D4ABCD_D5PHID_DELAY \
          MPROJ_D3D4ABCD_D5PHID \
          MPROJ_L1D1EFGH_D5PHID_DELAY \
          MPROJ_L1D1EFGH_D5PHID \
	  ]]
	  
resize_pblock [get_pblocks pblock_MPD1A] -add {CLOCKREGION_X1Y8:CLOCKREGION_X1Y8}
resize_pblock [get_pblocks pblock_MPD1B] -add {CLOCKREGION_X1Y9:CLOCKREGION_X1Y9}
resize_pblock [get_pblocks pblock_MPD1C] -add {CLOCKREGION_X1Y10:CLOCKREGION_X1Y10}
resize_pblock [get_pblocks pblock_MPD1D] -add {CLOCKREGION_X1Y11:CLOCKREGION_X1Y11}
resize_pblock [get_pblocks pblock_MPD2A] -add {CLOCKREGION_X2Y8:CLOCKREGION_X2Y8}
resize_pblock [get_pblocks pblock_MPD2B] -add {CLOCKREGION_X2Y9:CLOCKREGION_X2Y9}
resize_pblock [get_pblocks pblock_MPD2C] -add {CLOCKREGION_X2Y10:CLOCKREGION_X2Y10}
resize_pblock [get_pblocks pblock_MPD2D] -add {CLOCKREGION_X2Y11:CLOCKREGION_X2Y11}
resize_pblock [get_pblocks pblock_MPD3A] -add {CLOCKREGION_X4Y8:CLOCKREGION_X4Y8}
resize_pblock [get_pblocks pblock_MPD3B] -add {CLOCKREGION_X4Y9:CLOCKREGION_X4Y9}
resize_pblock [get_pblocks pblock_MPD3C] -add {CLOCKREGION_X4Y10:CLOCKREGION_X4Y10}
resize_pblock [get_pblocks pblock_MPD3D] -add {CLOCKREGION_X4Y11:CLOCKREGION_X4Y11}
resize_pblock [get_pblocks pblock_MPD4A] -add {CLOCKREGION_X5Y8:CLOCKREGION_X6Y8}
resize_pblock [get_pblocks pblock_MPD4B] -add {CLOCKREGION_X5Y9:CLOCKREGION_X6Y9}
resize_pblock [get_pblocks pblock_MPD4C] -add {CLOCKREGION_X5Y10:CLOCKREGION_X6Y10}
resize_pblock [get_pblocks pblock_MPD4D] -add {CLOCKREGION_X5Y11:CLOCKREGION_X6Y11}
resize_pblock [get_pblocks pblock_MPD5A] -add {CLOCKREGION_X7Y8:CLOCKREGION_X7Y8}
resize_pblock [get_pblocks pblock_MPD5B] -add {CLOCKREGION_X7Y9:CLOCKREGION_X7Y9}
resize_pblock [get_pblocks pblock_MPD5C] -add {CLOCKREGION_X7Y10:CLOCKREGION_X7Y10}
resize_pblock [get_pblocks pblock_MPD5D] -add {CLOCKREGION_X7Y11:CLOCKREGION_X7Y11}


create_pblock pblock_FTL1L2
add_cells_to_pblock [get_pblocks pblock_FTL1L2] [get_cells -quiet [list \
          FT_L1L2 \
          FM_L1L2_L3PHIA_DELAY \
          FM_L1L2_L3PHIA \
          FM_L1L2_L3PHIB_DELAY \
          FM_L1L2_L3PHIB \
          FM_L1L2_L3PHIC_DELAY \
          FM_L1L2_L3PHIC \
          FM_L1L2_L3PHID_DELAY \
          FM_L1L2_L3PHID \
          FM_L1L2_L4PHIA_DELAY \
          FM_L1L2_L4PHIA \
          FM_L1L2_L4PHIB_DELAY \
          FM_L1L2_L4PHIB \
          FM_L1L2_L4PHIC_DELAY \
          FM_L1L2_L4PHIC \
          FM_L1L2_L4PHID_DELAY \
          FM_L1L2_L4PHID \
          FM_L1L2_L5PHIA_DELAY \
          FM_L1L2_L5PHIA \
          FM_L1L2_L5PHIB_DELAY \
          FM_L1L2_L5PHIB \
          FM_L1L2_L5PHIC_DELAY \
          FM_L1L2_L5PHIC \
          FM_L1L2_L5PHID_DELAY \
          FM_L1L2_L5PHID \
          FM_L1L2_L6PHIA_DELAY \
          FM_L1L2_L6PHIA \
          FM_L1L2_L6PHIB_DELAY \
          FM_L1L2_L6PHIB \
          FM_L1L2_L6PHIC_DELAY \
          FM_L1L2_L6PHIC \
          FM_L1L2_L6PHID_DELAY \
          FM_L1L2_L6PHID \
          FM_L1L2_D1PHIA_DELAY \
          FM_L1L2_D1PHIA \
          FM_L1L2_D1PHIB_DELAY \
          FM_L1L2_D1PHIB \
          FM_L1L2_D1PHIC_DELAY \
          FM_L1L2_D1PHIC \
          FM_L1L2_D1PHID_DELAY \
          FM_L1L2_D1PHID \
          FM_L1L2_D2PHIA_DELAY \
          FM_L1L2_D2PHIA \
          FM_L1L2_D2PHIB_DELAY \
          FM_L1L2_D2PHIB \
          FM_L1L2_D2PHIC_DELAY \
          FM_L1L2_D2PHIC \
          FM_L1L2_D2PHID_DELAY \
          FM_L1L2_D2PHID \
          FM_L1L2_D3PHIA_DELAY \
          FM_L1L2_D3PHIA \
          FM_L1L2_D3PHIB_DELAY \
          FM_L1L2_D3PHIB \
          FM_L1L2_D3PHIC_DELAY \
          FM_L1L2_D3PHIC \
          FM_L1L2_D3PHID_DELAY \
          FM_L1L2_D3PHID \
          FM_L1L2_D4PHIA_DELAY \
          FM_L1L2_D4PHIA \
          FM_L1L2_D4PHIB_DELAY \
          FM_L1L2_D4PHIB \
          FM_L1L2_D4PHIC_DELAY \
          FM_L1L2_D4PHIC \
          FM_L1L2_D4PHID_DELAY \
          FM_L1L2_D4PHID \
          MPAR_L1L2ABC_DELAY \
          MPAR_L1L2ABC \
          MPAR_L1L2DE_DELAY \
          MPAR_L1L2DE \
          MPAR_L1L2F_DELAY \
          MPAR_L1L2F \
          MPAR_L1L2G_DELAY \
          MPAR_L1L2G \
          MPAR_L1L2HI_DELAY \
          MPAR_L1L2HI \
          MPAR_L1L2JKL_DELAY \
          MPAR_L1L2JKL \
	  ]]

create_pblock pblock_FTL2L3
add_cells_to_pblock [get_pblocks pblock_FTL2L3] [get_cells -quiet [list \
	  FT_L2L3 \
          FM_L2L3_L1PHIA_DELAY \
          FM_L2L3_L1PHIA \
          FM_L2L3_L1PHIB_DELAY \
          FM_L2L3_L1PHIB \
          FM_L2L3_L1PHIC_DELAY \
          FM_L2L3_L1PHIC \
          FM_L2L3_L1PHID_DELAY \
          FM_L2L3_L1PHID \
          FM_L2L3_L1PHIE_DELAY \
          FM_L2L3_L1PHIE \
          FM_L2L3_L1PHIF_DELAY \
          FM_L2L3_L1PHIF \
          FM_L2L3_L1PHIG_DELAY \
          FM_L2L3_L1PHIG \
          FM_L2L3_L1PHIH_DELAY \
          FM_L2L3_L1PHIH \
          FM_L2L3_L4PHIA_DELAY \
          FM_L2L3_L4PHIA \
          FM_L2L3_L4PHIB_DELAY \
          FM_L2L3_L4PHIB \
          FM_L2L3_L4PHIC_DELAY \
          FM_L2L3_L4PHIC \
          FM_L2L3_L4PHID_DELAY \
          FM_L2L3_L4PHID \
          FM_L2L3_L5PHIA_DELAY \
          FM_L2L3_L5PHIA \
          FM_L2L3_L5PHIB_DELAY \
          FM_L2L3_L5PHIB \
          FM_L2L3_L5PHIC_DELAY \
          FM_L2L3_L5PHIC \
          FM_L2L3_L5PHID_DELAY \
          FM_L2L3_L5PHID \
          FM_L2L3_D1PHIA_DELAY \
          FM_L2L3_D1PHIA \
          FM_L2L3_D1PHIB_DELAY \
          FM_L2L3_D1PHIB \
          FM_L2L3_D1PHIC_DELAY \
          FM_L2L3_D1PHIC \
          FM_L2L3_D1PHID_DELAY \
          FM_L2L3_D1PHID \
          FM_L2L3_D2PHIA_DELAY \
          FM_L2L3_D2PHIA \
          FM_L2L3_D2PHIB_DELAY \
          FM_L2L3_D2PHIB \
          FM_L2L3_D2PHIC_DELAY \
          FM_L2L3_D2PHIC \
          FM_L2L3_D2PHID_DELAY \
          FM_L2L3_D2PHID \
          FM_L2L3_D3PHIA_DELAY \
          FM_L2L3_D3PHIA \
          FM_L2L3_D3PHIB_DELAY \
          FM_L2L3_D3PHIB \
          FM_L2L3_D3PHIC_DELAY \
          FM_L2L3_D3PHIC \
          FM_L2L3_D3PHID_DELAY \
          FM_L2L3_D3PHID \
          FM_L2L3_D4PHIA_DELAY \
          FM_L2L3_D4PHIA \
          FM_L2L3_D4PHIB_DELAY \
          FM_L2L3_D4PHIB \
          FM_L2L3_D4PHIC_DELAY \
          FM_L2L3_D4PHIC \
          FM_L2L3_D4PHID_DELAY \
          FM_L2L3_D4PHID \
          MPAR_L2L3ABCD_DELAY \
          MPAR_L2L3ABCD \
	  ]]

create_pblock pblock_FTL3L4
add_cells_to_pblock [get_pblocks pblock_FTL3L4] [get_cells -quiet [list \
	  FT_L3L4 \
          FM_L3L4_L1PHIA_DELAY \
          FM_L3L4_L1PHIA \
          FM_L3L4_L1PHIB_DELAY \
          FM_L3L4_L1PHIB \
          FM_L3L4_L1PHIC_DELAY \
          FM_L3L4_L1PHIC \
          FM_L3L4_L1PHID_DELAY \
          FM_L3L4_L1PHID \
          FM_L3L4_L1PHIE_DELAY \
          FM_L3L4_L1PHIE \
          FM_L3L4_L1PHIF_DELAY \
          FM_L3L4_L1PHIF \
          FM_L3L4_L1PHIG_DELAY \
          FM_L3L4_L1PHIG \
          FM_L3L4_L1PHIH_DELAY \
          FM_L3L4_L1PHIH \
          FM_L3L4_L2PHIA_DELAY \
          FM_L3L4_L2PHIA \
          FM_L3L4_L2PHIB_DELAY \
          FM_L3L4_L2PHIB \
          FM_L3L4_L2PHIC_DELAY \
          FM_L3L4_L2PHIC \
          FM_L3L4_L2PHID_DELAY \
          FM_L3L4_L2PHID \
          FM_L3L4_L5PHIA_DELAY \
          FM_L3L4_L5PHIA \
          FM_L3L4_L5PHIB_DELAY \
          FM_L3L4_L5PHIB \
          FM_L3L4_L5PHIC_DELAY \
          FM_L3L4_L5PHIC \
          FM_L3L4_L5PHID_DELAY \
          FM_L3L4_L5PHID \
          FM_L3L4_L6PHIA_DELAY \
          FM_L3L4_L6PHIA \
          FM_L3L4_L6PHIB_DELAY \
          FM_L3L4_L6PHIB \
          FM_L3L4_L6PHIC_DELAY \
          FM_L3L4_L6PHIC \
          FM_L3L4_L6PHID_DELAY \
          FM_L3L4_L6PHID \
          FM_L3L4_D1PHIA_DELAY \
          FM_L3L4_D1PHIA \
          FM_L3L4_D1PHIB_DELAY \
          FM_L3L4_D1PHIB \
          FM_L3L4_D1PHIC_DELAY \
          FM_L3L4_D1PHIC \
          FM_L3L4_D1PHID_DELAY \
          FM_L3L4_D1PHID \
          FM_L3L4_D2PHIA_DELAY \
          FM_L3L4_D2PHIA \
          FM_L3L4_D2PHIB_DELAY \
          FM_L3L4_D2PHIB \
          FM_L3L4_D2PHIC_DELAY \
          FM_L3L4_D2PHIC \
          FM_L3L4_D2PHID_DELAY \
          FM_L3L4_D2PHID \
          MPAR_L3L4AB_DELAY \
          MPAR_L3L4AB \
          MPAR_L3L4CD_DELAY \
          MPAR_L3L4CD \
	  ]]

create_pblock pblock_FTL5L6
add_cells_to_pblock [get_pblocks pblock_FTL5L6] [get_cells -quiet [list \
	  FT_L5L6 \
          FM_L5L6_L1PHIA_DELAY \
          FM_L5L6_L1PHIA \
          FM_L5L6_L1PHIB_DELAY \
          FM_L5L6_L1PHIB \
          FM_L5L6_L1PHIC_DELAY \
          FM_L5L6_L1PHIC \
          FM_L5L6_L1PHID_DELAY \
          FM_L5L6_L1PHID \
          FM_L5L6_L1PHIE_DELAY \
          FM_L5L6_L1PHIE \
          FM_L5L6_L1PHIF_DELAY \
          FM_L5L6_L1PHIF \
          FM_L5L6_L1PHIG_DELAY \
          FM_L5L6_L1PHIG \
          FM_L5L6_L1PHIH_DELAY \
          FM_L5L6_L1PHIH \
          FM_L5L6_L2PHIA_DELAY \
          FM_L5L6_L2PHIA \
          FM_L5L6_L2PHIB_DELAY \
          FM_L5L6_L2PHIB \
          FM_L5L6_L2PHIC_DELAY \
          FM_L5L6_L2PHIC \
          FM_L5L6_L2PHID_DELAY \
          FM_L5L6_L2PHID \
          FM_L5L6_L3PHIA_DELAY \
          FM_L5L6_L3PHIA \
          FM_L5L6_L3PHIB_DELAY \
          FM_L5L6_L3PHIB \
          FM_L5L6_L3PHIC_DELAY \
          FM_L5L6_L3PHIC \
          FM_L5L6_L3PHID_DELAY \
          FM_L5L6_L3PHID \
          FM_L5L6_L4PHIA_DELAY \
          FM_L5L6_L4PHIA \
          FM_L5L6_L4PHIB_DELAY \
          FM_L5L6_L4PHIB \
          FM_L5L6_L4PHIC_DELAY \
          FM_L5L6_L4PHIC \
          FM_L5L6_L4PHID_DELAY \
          FM_L5L6_L4PHID \
          MPAR_L5L6ABCD_DELAY \
          MPAR_L5L6ABCD \
	  ]]

create_pblock pblock_FTD1D2
add_cells_to_pblock [get_pblocks pblock_FTD1D2] [get_cells -quiet [list \
	  FT_D1D2 \
          FM_D1D2_L1PHIA_DELAY \
          FM_D1D2_L1PHIA \
          FM_D1D2_L1PHIB_DELAY \
          FM_D1D2_L1PHIB \
          FM_D1D2_L1PHIC_DELAY \
          FM_D1D2_L1PHIC \
          FM_D1D2_L1PHID_DELAY \
          FM_D1D2_L1PHID \
          FM_D1D2_L1PHIE_DELAY \
          FM_D1D2_L1PHIE \
          FM_D1D2_L1PHIF_DELAY \
          FM_D1D2_L1PHIF \
          FM_D1D2_L1PHIG_DELAY \
          FM_D1D2_L1PHIG \
          FM_D1D2_L1PHIH_DELAY \
          FM_D1D2_L1PHIH \
          FM_D1D2_L2PHIA_DELAY \
          FM_D1D2_L2PHIA \
          FM_D1D2_L2PHIB_DELAY \
          FM_D1D2_L2PHIB \
          FM_D1D2_L2PHIC_DELAY \
          FM_D1D2_L2PHIC \
          FM_D1D2_L2PHID_DELAY \
          FM_D1D2_L2PHID \
          FM_D1D2_D3PHIA_DELAY \
          FM_D1D2_D3PHIA \
          FM_D1D2_D3PHIB_DELAY \
          FM_D1D2_D3PHIB \
          FM_D1D2_D3PHIC_DELAY \
          FM_D1D2_D3PHIC \
          FM_D1D2_D3PHID_DELAY \
          FM_D1D2_D3PHID \
          FM_D1D2_D4PHIA_DELAY \
          FM_D1D2_D4PHIA \
          FM_D1D2_D4PHIB_DELAY \
          FM_D1D2_D4PHIB \
          FM_D1D2_D4PHIC_DELAY \
          FM_D1D2_D4PHIC \
          FM_D1D2_D4PHID_DELAY \
          FM_D1D2_D4PHID \
          FM_D1D2_D5PHIA_DELAY \
          FM_D1D2_D5PHIA \
          FM_D1D2_D5PHIB_DELAY \
          FM_D1D2_D5PHIB \
          FM_D1D2_D5PHIC_DELAY \
          FM_D1D2_D5PHIC \
          FM_D1D2_D5PHID_DELAY \
          FM_D1D2_D5PHID \
          MPAR_D1D2ABCD_DELAY \
          MPAR_D1D2ABCD \
	  ]]

create_pblock pblock_FTD3D4
add_cells_to_pblock [get_pblocks pblock_FTD3D4] [get_cells -quiet [list \
	  FT_D3D4 \
          FM_D3D4_L1PHIA_DELAY \
          FM_D3D4_L1PHIA \
          FM_D3D4_L1PHIB_DELAY \
          FM_D3D4_L1PHIB \
          FM_D3D4_L1PHIC_DELAY \
          FM_D3D4_L1PHIC \
          FM_D3D4_L1PHID_DELAY \
          FM_D3D4_L1PHID \
          FM_D3D4_L1PHIE_DELAY \
          FM_D3D4_L1PHIE \
          FM_D3D4_L1PHIF_DELAY \
          FM_D3D4_L1PHIF \
          FM_D3D4_L1PHIG_DELAY \
          FM_D3D4_L1PHIG \
          FM_D3D4_L1PHIH_DELAY \
          FM_D3D4_L1PHIH \
          FM_D3D4_D1PHIA_DELAY \
          FM_D3D4_D1PHIA \
          FM_D3D4_D1PHIB_DELAY \
          FM_D3D4_D1PHIB \
          FM_D3D4_D1PHIC_DELAY \
          FM_D3D4_D1PHIC \
          FM_D3D4_D1PHID_DELAY \
          FM_D3D4_D1PHID \
          FM_D3D4_D2PHIA_DELAY \
          FM_D3D4_D2PHIA \
          FM_D3D4_D2PHIB_DELAY \
          FM_D3D4_D2PHIB \
          FM_D3D4_D2PHIC_DELAY \
          FM_D3D4_D2PHIC \
          FM_D3D4_D2PHID_DELAY \
          FM_D3D4_D2PHID \
          FM_D3D4_D5PHIA_DELAY \
          FM_D3D4_D5PHIA \
          FM_D3D4_D5PHIB_DELAY \
          FM_D3D4_D5PHIB \
          FM_D3D4_D5PHIC_DELAY \
          FM_D3D4_D5PHIC \
          FM_D3D4_D5PHID_DELAY \
          FM_D3D4_D5PHID \
          MPAR_D3D4ABCD_DELAY \
          MPAR_D3D4ABCD \
	  ]]

create_pblock pblock_FTL1D1
add_cells_to_pblock [get_pblocks pblock_FTL1D1] [get_cells -quiet [list \
	  FT_L1D1 \
          FM_L1D1_D2PHIA_DELAY \
          FM_L1D1_D2PHIA \
          FM_L1D1_D2PHIB_DELAY \
          FM_L1D1_D2PHIB \
          FM_L1D1_D2PHIC_DELAY \
          FM_L1D1_D2PHIC \
          FM_L1D1_D2PHID_DELAY \
          FM_L1D1_D2PHID \
          FM_L1D1_D3PHIA_DELAY \
          FM_L1D1_D3PHIA \
          FM_L1D1_D3PHIB_DELAY \
          FM_L1D1_D3PHIB \
          FM_L1D1_D3PHIC_DELAY \
          FM_L1D1_D3PHIC \
          FM_L1D1_D3PHID_DELAY \
          FM_L1D1_D3PHID \
          FM_L1D1_D4PHIA_DELAY \
          FM_L1D1_D4PHIA \
          FM_L1D1_D4PHIB_DELAY \
          FM_L1D1_D4PHIB \
          FM_L1D1_D4PHIC_DELAY \
          FM_L1D1_D4PHIC \
          FM_L1D1_D4PHID_DELAY \
          FM_L1D1_D4PHID \
          FM_L1D1_D5PHIA_DELAY \
          FM_L1D1_D5PHIA \
          FM_L1D1_D5PHIB_DELAY \
          FM_L1D1_D5PHIB \
          FM_L1D1_D5PHIC_DELAY \
          FM_L1D1_D5PHIC \
          FM_L1D1_D5PHID_DELAY \
          FM_L1D1_D5PHID \
          MPAR_L1D1ABCD_DELAY \
          MPAR_L1D1ABCD \
          MPAR_L1D1EFGH_DELAY \
          MPAR_L1D1EFGH \
	  ]]
	  
create_pblock pblock_FTL2D1
add_cells_to_pblock [get_pblocks pblock_FTL2D1] [get_cells -quiet [list \
	  FT_L2D1 \
          FM_L2D1_L1PHIA_DELAY \
          FM_L2D1_L1PHIA \
          FM_L2D1_L1PHIB_DELAY \
          FM_L2D1_L1PHIB \
          FM_L2D1_L1PHIC_DELAY \
          FM_L2D1_L1PHIC \
          FM_L2D1_L1PHID_DELAY \
          FM_L2D1_L1PHID \
          FM_L2D1_L1PHIE_DELAY \
          FM_L2D1_L1PHIE \
          FM_L2D1_L1PHIF_DELAY \
          FM_L2D1_L1PHIF \
          FM_L2D1_L1PHIG_DELAY \
          FM_L2D1_L1PHIG \
          FM_L2D1_L1PHIH_DELAY \
          FM_L2D1_L1PHIH \
          FM_L2D1_D2PHIA_DELAY \
          FM_L2D1_D2PHIA \
          FM_L2D1_D2PHIB_DELAY \
          FM_L2D1_D2PHIB \
          FM_L2D1_D2PHIC_DELAY \
          FM_L2D1_D2PHIC \
          FM_L2D1_D2PHID_DELAY \
          FM_L2D1_D2PHID \
          FM_L2D1_D3PHIA_DELAY \
          FM_L2D1_D3PHIA \
          FM_L2D1_D3PHIB_DELAY \
          FM_L2D1_D3PHIB \
          FM_L2D1_D3PHIC_DELAY \
          FM_L2D1_D3PHIC \
          FM_L2D1_D3PHID_DELAY \
          FM_L2D1_D3PHID \
          FM_L2D1_D4PHIA_DELAY \
          FM_L2D1_D4PHIA \
          FM_L2D1_D4PHIB_DELAY \
          FM_L2D1_D4PHIB \
          FM_L2D1_D4PHIC_DELAY \
          FM_L2D1_D4PHIC \
          FM_L2D1_D4PHID_DELAY \
          FM_L2D1_D4PHID \
          MPAR_L2D1ABCD_DELAY \
          MPAR_L2D1ABCD \
	  ]]
	  
resize_pblock [get_pblocks pblock_FTL1L2] -add {CLOCKREGION_X6Y4:CLOCKREGION_X6Y7}
resize_pblock [get_pblocks pblock_FTL2L3] -add {CLOCKREGION_X1Y4:CLOCKREGION_X1Y7}
resize_pblock [get_pblocks pblock_FTL3L4] -add {CLOCKREGION_X2Y4:CLOCKREGION_X2Y7}
resize_pblock [get_pblocks pblock_FTL5L6] -add {CLOCKREGION_X3Y4:CLOCKREGION_X3Y7}
resize_pblock [get_pblocks pblock_FTD1D2] -add {CLOCKREGION_X4Y4:CLOCKREGION_X4Y7}
resize_pblock [get_pblocks pblock_FTD3D4] -add {CLOCKREGION_X5Y4:CLOCKREGION_X5Y7}
resize_pblock [get_pblocks pblock_FTL1D1] -add {CLOCKREGION_X0Y4:CLOCKREGION_X0Y7}
resize_pblock [get_pblocks pblock_FTL2D1] -add {CLOCKREGION_X7Y4:CLOCKREGION_X7Y7}

set_property IS_SOFT FALSE [get_pblocks pblock_*]


