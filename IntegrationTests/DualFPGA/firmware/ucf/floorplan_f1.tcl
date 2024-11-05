#this XDC contains physical constraints for the second FPGA project

#temporary delete_pblocks for pblocks in previous versions of this script to avoid left-over shenanigans that will confuse vivado

#normal delete_pblocks
delete_pblocks -quiet pblock_payload_TPL1L2_1 pblock_payload_TPL1L2_2 pblock_payload_TPL1L2_3 pblock_payload_TPL2L3 pblock_payload_TPL3L4 pblock_payload_TPL5L6 pblock_payload_TPD1D2 pblock_payload_TPD3D4 pblock_payload_TPL1D1_1 pblock_payload_TPL1D1_2 pblock_payload_TPL2D1 pblock_payload_TPAR pblock_payload_SLR2

# -----------------------------------------------------------------------------
# add_rects_to_pblock --
#
# Adds a set of rectangular ranges of sites to a pblock.
# The ranges are passed in a dictionary. Only the ranges matching the user-defined patterns are added
# This is modified from the EMP central version to include URAMs
#
# Arguments:
#   aPBlock The pblock
#   aRects Dictionary of rectangular areas
# Results:
#   The result is that of the command being redone. Also repla
proc add_rects_to_pblock_mod {aPBlock aRects} {

    set lSitePatterns [list SLICE DSP* URAM* RAM* GT*CHANNEL*]

    set lToAdd [list]
    foreach lType $lSitePatterns {
        dict for {lId lRange} [dict filter $aRects key $lType] {
            lappend lToAdd $lRange
        }
    }

    puts "Adding to $aPBlock rectangles $lToAdd"
    resize_pblock $aPBlock -add $lToAdd
}

#these are from region_constraints_toolbox (called in ex. area_constraints.tcl)
#maybe one day actually make some method that emulates the logic in 
#create_quad_pblocks that automates the calculation in case something changes, 
#but certainly don't want to re-call create_quad_pblocks
set lLeftBoundary 851
set lRightBoundary 4278

#define parents

set lpblock_payload_SLR2 [create_pblock pblock_payload_SLR2]

#Define pblocks

#set lpblock_payload_IRs [create_pblock pblock_payload_IRs]
#add_cells_to_pblock [get_pblocks pblock_payload_IRs] [get_cells -quiet [list \
#          payload/tf1_wrapper_1/SectorProcessor_1/IR_* \
#          ]]

set lpblock_payload_TPL1L2_1 [create_pblock pblock_payload_TPL1L2_1]
add_cells_to_pblock [get_pblocks pblock_payload_TPL1L2_1] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2A \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIA_BF \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_B_L1A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIAn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2B \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIA_BE \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIB_BD \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_B_L1B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIAn2 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2C \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIB_BC \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIC_BB \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_B_L1C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIAn3 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2D \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIB_BA \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIC_BF \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_B_L1D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIBn1 \
          ]]

set lpblock_payload_TPL1L2_2 [create_pblock pblock_payload_TPL1L2_2]
add_cells_to_pblock [get_pblocks pblock_payload_TPL1L2_2] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2E \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIC_BE \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHID_BD \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_B_L1E \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIBn2 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2F \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHID_BC \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIE_BB \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_B_L1F \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIBn3 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2G \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHID_BA \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIE_BF \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_B_L1G \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHICn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2H \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIE_BE \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIF_BD \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_B_L1H \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHICn2 \
          ]]

set lpblock_payload_TPL1L2_3 [create_pblock pblock_payload_TPL1L2_3]
add_cells_to_pblock [get_pblocks pblock_payload_TPL1L2_3] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2I \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIF_BC \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIG_BB \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_B_L1I \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHICn3 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2J \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIF_BA \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIG_BF \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_B_L1J \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIDn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2K \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIG_BE \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIH_BD \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_B_L1K \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIDn2 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1L2L \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIH_BC \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_B_L1L \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L2PHIDn3 \
          ]]

set lpblock_payload_TPL2L3 [create_pblock pblock_payload_TPL2L3]
add_cells_to_pblock [get_pblocks pblock_payload_TPL2L3] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L2L3* \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIA_B_L2A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L3PHIIn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIB_B_L2B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L3PHIJn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIC_B_L2C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L3PHIKn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHID_B_L2D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L3PHILn1 \
          ]]

set lpblock_payload_TPL3L4 [create_pblock pblock_payload_TPL3L4]
add_cells_to_pblock [get_pblocks pblock_payload_TPL3L4] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L3L4* \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIA_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIB_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L4PHIA_B_L3A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L4PHIAn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIA_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIB_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIC_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L4PHIB_B_L3B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L4PHIBn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIB_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIC_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHID_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L4PHIC_B_L3C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L4PHICn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHIC_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L3PHID_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L4PHID_B_L3D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L4PHIDn1 \
          ]]

set lpblock_payload_TPL5L6 [create_pblock pblock_payload_TPL5L6]
add_cells_to_pblock [get_pblocks pblock_payload_TPL5L6] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L5L6* \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIA_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIB_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L6PHIA_B_L5A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L6PHIAn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIA_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIB_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIC_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L6PHIB_B_L5B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L6PHIBn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIB_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIC_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHID_BL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L6PHIC_B_L5C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L6PHICn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHIC_BR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L5PHID_BM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L6PHID_B_L5D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_L6PHIDn1 \
          ]]

set lpblock_payload_TPD1D2 [create_pblock pblock_payload_TPD1D2]
add_cells_to_pblock [get_pblocks pblock_payload_TPD1D2] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_D1D2* \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIA_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIB_DL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D2PHIA_D_D1A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D2PHIAn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIA_DR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIB_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIC_DL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D2PHIB_D_D1B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D2PHIBn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIB_DR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIC_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHID_DL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D2PHIC_D_D1C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D2PHICn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIC_DR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHID_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D2PHID_D_D1D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D2PHIDn1 \
          ]]

set lpblock_payload_TPD3D4 [create_pblock pblock_payload_TPD3D4]
add_cells_to_pblock [get_pblocks pblock_payload_TPD3D4] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_D3D4* \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIA_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIB_DL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D4PHIA_D_D3A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D4PHIAn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIA_DR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIB_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIC_DL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D4PHIB_D_D3B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D4PHIBn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIB_DR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIC_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHID_DL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D4PHIC_D_D3C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D4PHICn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHIC_DR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D3PHID_DM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D4PHID_D_D3D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D4PHIDn1 \
          ]]

set lpblock_payload_TPL1D1_1 [create_pblock pblock_payload_TPL1D1_1]
add_cells_to_pblock [get_pblocks pblock_payload_TPL1D1_1] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1A \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIA_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIB_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIA_O_L1A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIXn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1B \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIA_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIB_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIC_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIA_O_L1B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIXn2 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1C \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIB_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIC_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHID_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIB_O_L1C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIYn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1D \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIC_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHID_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIE_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIB_O_L1D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIYn2 \
          ]]

set lpblock_payload_TPL1D1_2 [create_pblock pblock_payload_TPL1D1_2]
add_cells_to_pblock [get_pblocks pblock_payload_TPL1D1_2] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1E \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHID_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIE_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIF_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIC_O_L1E \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIZn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1F \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIE_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIF_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIG_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIC_O_L1F \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIZn2 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1G \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIF_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIG_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIH_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHID_O_L1G \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIWn1 \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L1D1H \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIG_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L1PHIH_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHID_O_L1H \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIWn2 \
          ]]

set lpblock_payload_TPL2D1 [create_pblock pblock_payload_TPL2D1]
add_cells_to_pblock [get_pblocks pblock_payload_TPL2D1] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TP_L2D1* \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIA_O_L2A \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIXn3 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIA_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIB_O_L2B \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIYn3 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIB_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_OL \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHIC_O_L2C \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIZn3 \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHIC_OR \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_L2PHID_OM \
          payload/tf1_wrapper_1/SectorProcessor_1/AS_D1PHID_O_L2D \
          payload/tf1_wrapper_1/SectorProcessor_1/VMSTE_D1PHIWn3 \
          ]]

#don't accidentally wildcard delay modules
set lpblock_payload_TPAR [create_pblock pblock_payload_TPAR]
add_cells_to_pblock [get_pblocks pblock_payload_TPAR] [get_cells -quiet [list \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2E \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2F \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2G \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2H \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2I \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2J \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2K \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1L2L \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2L3A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2L3B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2L3C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2L3D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L3L4A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L3L4B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L3L4C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L3L4D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L5L6A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L5L6B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L5L6C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L5L6D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D1D2A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D1D2B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D1D2C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D1D2D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D3D4A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D3D4B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D3D4C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_D3D4D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1D \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1E \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1F \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1G \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L1D1H \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2D1A \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2D1B \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2D1C \
          payload/tf1_wrapper_1/SectorProcessor_1/TPAR_L2D1D \
          ]]

#set constraints

set_property PARENT pblock_payload_SLR2 [get_pblocks [list \
          pblock_payload_TPL1L2_1 \
          pblock_payload_TPL1L2_2 \
          pblock_payload_TPL1L2_3 \
          pblock_payload_TPL2D1 \
          pblock_payload_TPAR \
          ]]

#SLR 3

set pblock_payload_TPL5L6rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=14}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL5L6 $pblock_payload_TPL5L6rect

set pblock_payload_TPL3L4rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==13}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL3L4 $pblock_payload_TPL3L4rect

set pblock_payload_TPL2L3rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==12}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL2L3 $pblock_payload_TPL2L3rect

#SLR2

set pblock_payload_SLR2rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=8 && ROW_INDEX<=11}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_SLR2 $pblock_payload_SLR2rect

set pblock_payload_TPL1L2_1rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==11 && COLUMN_INDEX<=4}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL1L2_1 $pblock_payload_TPL1L2_1rect

set pblock_payload_TPL1L2_2rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==10 && COLUMN_INDEX<=4}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL1L2_2 $pblock_payload_TPL1L2_2rect

set pblock_payload_TPL1L2_3rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==9 && COLUMN_INDEX<=4}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL1L2_3 $pblock_payload_TPL1L2_3rect

set pblock_payload_TPL2D1rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==8 && COLUMN_INDEX<=4}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL2D1 $pblock_payload_TPL2D1rect

#set pblock_payload_TPARrect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=6 && ROW_INDEX<=13 && COLUMN_INDEX>=5}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
#add_rects_to_pblock_mod $lpblock_payload_TPAR $pblock_payload_TPARrect

#SLR1

set pblock_payload_TPL1D1_1rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==7}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL1D1_1 $pblock_payload_TPL1D1_1rect

set pblock_payload_TPL1D1_2rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==6}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPL1D1_2 $pblock_payload_TPL1D1_2rect

set pblock_payload_TPD1D2rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==5}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPD1D2 $pblock_payload_TPD1D2rect

set pblock_payload_TPD3D4rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX==4}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_TPD3D4 $pblock_payload_TPD3D4rect

#change only payload pblocks to be hard constraints
set_property IS_SOFT FALSE [get_pblocks pblock_payload_*]

