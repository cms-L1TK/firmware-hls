#this XDC contains physical constraints for the second FPGA project

#temporary delete_pblocks for pblocks in previous versions of this script to avoid left-over shenanigans that will confuse vivado

#normal delete_pblocks
delete_pblocks -quiet pblock_payload_MPL1A pblock_payload_MPL1B pblock_payload_MPL1C pblock_payload_MPL1D pblock_payload_MPL1E pblock_payload_MPL1F pblock_payload_MPL1G pblock_payload_MPL1H pblock_payload_MPL2A pblock_payload_MPL2B pblock_payload_MPL2C pblock_payload_MPL2D pblock_payload_MPL3A pblock_payload_MPL3B pblock_payload_MPL3C pblock_payload_MPL3D pblock_payload_MPL4A pblock_payload_MPL4B pblock_payload_MPL4C pblock_payload_MPL4D pblock_payload_MPL5A pblock_payload_MPL5B pblock_payload_MPL5C pblock_payload_MPL5D pblock_payload_MPL6A pblock_payload_MPL6B pblock_payload_MPL6C pblock_payload_MPL6D pblock_payload_MPD1A pblock_payload_MPD1B pblock_payload_MPD1C pblock_payload_MPD1D pblock_payload_MPD2A pblock_payload_MPD2B pblock_payload_MPD2C pblock_payload_MPD2D pblock_payload_MPD3A pblock_payload_MPD3B pblock_payload_MPD3C pblock_payload_MPD3D pblock_payload_MPD4A pblock_payload_MPD4B pblock_payload_MPD4C pblock_payload_MPD4D pblock_payload_MPD5A pblock_payload_MPD5B pblock_payload_MPD5C pblock_payload_MPD5D 
delete_pblocks -quiet pblock_payload_FTL1L2 pblock_payload_FTL2L3 pblock_payload_FTL3L4 pblock_payload_FTL5L6 pblock_payload_FTD1D2 pblock_payload_FTD3D4 pblock_payload_FTL1D1 pblock_payload_FTL2D1 pblock_payload_KF pblock_payload_KFout
delete_pblocks -quiet pblock_payload_PCVMSMERs
delete_pblocks -quiet pblock_payload_MPL1to6 pblock_payload_MPD1to5 pblock_payload_FTset1 pblock_payload_FTset2 pblock_payload_FTMPset1 pblock_payload_FTMPset2

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

proc add_uram_rects_to_pblock {aPBlock aRects} {

    set lSitePatterns [list URAM*]

    set lToAdd [list]
    foreach lType $lSitePatterns {
        dict for {lId lRange} [dict filter $aRects key $lType] {
            lappend lToAdd $lRange
        }
    }

    puts "Adding to $aPBlock URAM rectangles $lToAdd"
    resize_pblock $aPBlock -add $lToAdd
}

proc add_bram_rects_to_pblock {aPBlock aRects} {

    set lSitePatterns [list RAM*]

    set lToAdd [list]
    foreach lType $lSitePatterns {
        dict for {lId lRange} [dict filter $aRects key $lType] {
            lappend lToAdd $lRange
        }
    }

    puts "Adding to $aPBlock URAM rectangles $lToAdd"
    resize_pblock $aPBlock -add $lToAdd
}

proc add_nonram_rects_to_pblock {aPBlock aRects} {

    set lSitePatterns [list SLICE DSP*]

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

set lpblock_payload_MPL1to6 [create_pblock pblock_payload_MPL1to6]
set lpblock_payload_MPD1to5 [create_pblock pblock_payload_MPD1to5]
set lpblock_payload_FTset1 [create_pblock pblock_payload_FTset1]
set lpblock_payload_FTset2 [create_pblock pblock_payload_FTset2]
set lpblock_payload_FTMPset1 [create_pblock pblock_payload_FTMPset1]
set lpblock_payload_FTMPset2 [create_pblock pblock_payload_FTMPset2]

#PC/VMSMER pblock

set lpblock_payload_PCMVSMERS [create_pblock pblock_payload_PCVMSMERs]
add_cells_to_pblock [get_pblocks pblock_payload_PCVMSMERs] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2ABC \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2DE \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2F \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2G \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2HI \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2JKL \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L2L3ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L3L4AB \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L3L4CD \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L5L6ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_D1D2ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_D3D4ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1D1EFGH \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L2D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L6PHIB \        
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSMER_D5PHID \
          ]]

#MP pblocks

set lpblock_payload_MPL1A [create_pblock pblock_payload_MPL1A]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIA \
          ]]

set lpblock_payload_MPL1B [create_pblock pblock_payload_MPL1B]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIB \
          ]]

set lpblock_payload_MPL1C [create_pblock pblock_payload_MPL1C]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIC \
          ]]

set lpblock_payload_MPL1D [create_pblock pblock_payload_MPL1D]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHID \
          ]]

set lpblock_payload_MPL1E [create_pblock pblock_payload_MPL1E]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1E] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIEn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIEn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIE \
          ]]

set lpblock_payload_MPL1F [create_pblock pblock_payload_MPL1F]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1F] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIFn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIFn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIF \
          ]]

set lpblock_payload_MPL1G [create_pblock pblock_payload_MPL1G]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1G] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIGn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIGn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIG \
          ]]

set lpblock_payload_MPL1H [create_pblock pblock_payload_MPL1H]
add_cells_to_pblock [get_pblocks pblock_payload_MPL1H] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L1PHIHn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L1PHIHn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIH \
          ]]

set lpblock_payload_MPL2A [create_pblock pblock_payload_MPL2A]
add_cells_to_pblock [get_pblocks pblock_payload_MPL2A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L2PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L2PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIA \
          ]]
          
set lpblock_payload_MPL2B [create_pblock pblock_payload_MPL2B]
add_cells_to_pblock [get_pblocks pblock_payload_MPL2B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L2PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L2PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIB \
          ]]
          
set lpblock_payload_MPL2C [create_pblock pblock_payload_MPL2C]
add_cells_to_pblock [get_pblocks pblock_payload_MPL2C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L2PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L2PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIC \
          ]]
          
set lpblock_payload_MPL2D [create_pblock pblock_payload_MPL2D]
add_cells_to_pblock [get_pblocks pblock_payload_MPL2D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L2PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L2PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHID \
          ]]

set lpblock_payload_MPL3A [create_pblock pblock_payload_MPL3A]
add_cells_to_pblock [get_pblocks pblock_payload_MPL3A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L3PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L3PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIA \
          ]]
          
set lpblock_payload_MPL3B [create_pblock pblock_payload_MPL3B]
add_cells_to_pblock [get_pblocks pblock_payload_MPL3B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L3PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L3PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIB \
          ]]
          
set lpblock_payload_MPL3C [create_pblock pblock_payload_MPL3C]
add_cells_to_pblock [get_pblocks pblock_payload_MPL3C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L3PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L3PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIC \
          ]]
          
set lpblock_payload_MPL3D [create_pblock pblock_payload_MPL3D]
add_cells_to_pblock [get_pblocks pblock_payload_MPL3D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L3PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L3PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHID \
          ]]

set lpblock_payload_MPL4A [create_pblock pblock_payload_MPL4A]
add_cells_to_pblock [get_pblocks pblock_payload_MPL4A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L4PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L4PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIA \
          ]]
          
set lpblock_payload_MPL4B [create_pblock pblock_payload_MPL4B]
add_cells_to_pblock [get_pblocks pblock_payload_MPL4B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L4PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L4PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIB \
          ]]
          
set lpblock_payload_MPL4C [create_pblock pblock_payload_MPL4C]
add_cells_to_pblock [get_pblocks pblock_payload_MPL4C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L4PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L4PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIC \
          ]]
          
set lpblock_payload_MPL4D [create_pblock pblock_payload_MPL4D]
add_cells_to_pblock [get_pblocks pblock_payload_MPL4D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L4PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L4PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHID \
          ]]

set lpblock_payload_MPL5A [create_pblock pblock_payload_MPL5A]
add_cells_to_pblock [get_pblocks pblock_payload_MPL5A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L5PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L5PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIA \
          ]]
          
set lpblock_payload_MPL5B [create_pblock pblock_payload_MPL5B]
add_cells_to_pblock [get_pblocks pblock_payload_MPL5B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L5PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L5PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHIB \
          ]]
          
set lpblock_payload_MPL5C [create_pblock pblock_payload_MPL5C]
add_cells_to_pblock [get_pblocks pblock_payload_MPL5C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L5PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L5PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHIC \
          ]]
          
set lpblock_payload_MPL5D [create_pblock pblock_payload_MPL5D]
add_cells_to_pblock [get_pblocks pblock_payload_MPL5D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L5PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L5PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHID \
          ]]

set lpblock_payload_MPL6A [create_pblock pblock_payload_MPL6A]
add_cells_to_pblock [get_pblocks pblock_payload_MPL6A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L6PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L6PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIA \
          ]]
          
set lpblock_payload_MPL6B [create_pblock pblock_payload_MPL6B]
add_cells_to_pblock [get_pblocks pblock_payload_MPL6B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L6PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L6PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHIB \
          ]]
          
set lpblock_payload_MPL6C [create_pblock pblock_payload_MPL6C]
add_cells_to_pblock [get_pblocks pblock_payload_MPL6C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L6PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L6PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHIC \
          ]]
          
set lpblock_payload_MPL6D [create_pblock pblock_payload_MPL6D]
add_cells_to_pblock [get_pblocks pblock_payload_MPL6D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_L6PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_L6PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHID \
          ]]

set lpblock_payload_MPD1A [create_pblock pblock_payload_MPD1A]
add_cells_to_pblock [get_pblocks pblock_payload_MPD1A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D1PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D1PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIA \
          ]]
          
set lpblock_payload_MPD1B [create_pblock pblock_payload_MPD1B]
add_cells_to_pblock [get_pblocks pblock_payload_MPD1B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D1PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D1PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIB \
          ]]
          
set lpblock_payload_MPD1C [create_pblock pblock_payload_MPD1C]
add_cells_to_pblock [get_pblocks pblock_payload_MPD1C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D1PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D1PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIC \
          ]]
          
set lpblock_payload_MPD1D [create_pblock pblock_payload_MPD1D]
add_cells_to_pblock [get_pblocks pblock_payload_MPD1D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D1PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D1PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHID \
          ]]
          
set lpblock_payload_MPD2A [create_pblock pblock_payload_MPD2A]
add_cells_to_pblock [get_pblocks pblock_payload_MPD2A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D2PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D2PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIA \
          ]]
          
set lpblock_payload_MPD2B [create_pblock pblock_payload_MPD2B]
add_cells_to_pblock [get_pblocks pblock_payload_MPD2B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D2PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D2PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIB \
          ]]
          
set lpblock_payload_MPD2C [create_pblock pblock_payload_MPD2C]
add_cells_to_pblock [get_pblocks pblock_payload_MPD2C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D2PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D2PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIC \
          ]]
          
set lpblock_payload_MPD2D [create_pblock pblock_payload_MPD2D]
add_cells_to_pblock [get_pblocks pblock_payload_MPD2D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D2PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D2PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHID \
          ]]
          
set lpblock_payload_MPD3A [create_pblock pblock_payload_MPD3A]
add_cells_to_pblock [get_pblocks pblock_payload_MPD3A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D3PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D3PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIA \
          ]]
          
set lpblock_payload_MPD3B [create_pblock pblock_payload_MPD3B]
add_cells_to_pblock [get_pblocks pblock_payload_MPD3B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D3PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D3PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIB \
          ]]
          
set lpblock_payload_MPD3C [create_pblock pblock_payload_MPD3C]
add_cells_to_pblock [get_pblocks pblock_payload_MPD3C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D3PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D3PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIC \
          ]]
          
set lpblock_payload_MPD3D [create_pblock pblock_payload_MPD3D]
add_cells_to_pblock [get_pblocks pblock_payload_MPD3D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D3PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D3PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHID \
          ]]
          
set lpblock_payload_MPD4A [create_pblock pblock_payload_MPD4A]
add_cells_to_pblock [get_pblocks pblock_payload_MPD4A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D4PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D4PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIA \
          ]]
          
set lpblock_payload_MPD4B [create_pblock pblock_payload_MPD4B]
add_cells_to_pblock [get_pblocks pblock_payload_MPD4B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D4PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D4PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIB \
          ]]
          
set lpblock_payload_MPD4C [create_pblock pblock_payload_MPD4C]
add_cells_to_pblock [get_pblocks pblock_payload_MPD4C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D4PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D4PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIC \
          ]]
          
set lpblock_payload_MPD4D [create_pblock pblock_payload_MPD4D]
add_cells_to_pblock [get_pblocks pblock_payload_MPD4D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D4PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D4PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHID \
          ]]
          
set lpblock_payload_MPD5A [create_pblock pblock_payload_MPD5A]
add_cells_to_pblock [get_pblocks pblock_payload_MPD5A] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D5PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D5PHIAn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIA \
          ]]
          
set lpblock_payload_MPD5B [create_pblock pblock_payload_MPD5B]
add_cells_to_pblock [get_pblocks pblock_payload_MPD5B] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D5PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D5PHIBn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHIB \
          ]]
          
set lpblock_payload_MPD5C [create_pblock pblock_payload_MPD5C]
add_cells_to_pblock [get_pblocks pblock_payload_MPD5C] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D5PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D5PHICn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHIC \
          ]]
          
set lpblock_payload_MPD5D [create_pblock pblock_payload_MPD5D]
add_cells_to_pblock [get_pblocks pblock_payload_MPD5D] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/AS_D5PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/VMSME_D5PHIDn2 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHID \
          ]]

#FT pblocks

set lpblock_payload_FTL1L2 [create_pblock pblock_payload_FTL1L2]
add_cells_to_pblock [get_pblocks pblock_payload_FTL1L2] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_L1L2 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2ABC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2DE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2F \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2G \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2HI \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2JKL \
          ]]

set lpblock_payload_FTL2L3 [create_pblock pblock_payload_FTL2L3]
add_cells_to_pblock [get_pblocks pblock_payload_FTL2L3] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_L2L3 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L2L3ABCD \
          ]]

set lpblock_payload_FTL3L4 [create_pblock pblock_payload_FTL3L4]
add_cells_to_pblock [get_pblocks pblock_payload_FTL3L4] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_L3L4 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L3L4AB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L3L4CD \
          ]]

set lpblock_payload_FTL5L6 [create_pblock pblock_payload_FTL5L6]
add_cells_to_pblock [get_pblocks pblock_payload_FTL5L6] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_L5L6 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L5L6ABCD \
          ]]

set lpblock_payload_FTD1D2 [create_pblock pblock_payload_FTD1D2]
add_cells_to_pblock [get_pblocks pblock_payload_FTD1D2] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_D1D2 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_D1D2ABCD \
          ]]

set lpblock_payload_FTD3D4 [create_pblock pblock_payload_FTD3D4]
add_cells_to_pblock [get_pblocks pblock_payload_FTD3D4] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_D3D4 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_D3D4ABCD \
          ]]

set lpblock_payload_FTL1D1 [create_pblock pblock_payload_FTL1D1]
add_cells_to_pblock [get_pblocks pblock_payload_FTL1D1] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_L1D1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1D1EFGH \
          ]]
          
set lpblock_payload_FTL2D1 [create_pblock pblock_payload_FTL2D1]
add_cells_to_pblock [get_pblocks pblock_payload_FTL2D1] [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/FT_L2D1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L2D1ABCD \
          ]]

#KF pblocks

set lpblock_payload_KF [create_pblock pblock_payload_KF]
add_cells_to_pblock [get_pblocks pblock_payload_KF] [get_cells -quiet [list \
          payload/kf_wrapper_1 \
          ]]

#set lpblock_payload_KFout [create_pblock pblock_payload_KFout]
#add_cells_to_pblock [get_pblocks pblock_payload_KFout] [get_cells -quiet [list \
#          payload/kf_wrapper_1/kfout_top_1 \
#          ]]

#set parents

set_property PARENT pblock_payload_MPL1to6 [get_pblocks [list \
          pblock_payload_MPL1A \
          pblock_payload_MPL1B \
          pblock_payload_MPL1C \
          pblock_payload_MPL1D \
          pblock_payload_MPL1E \
          pblock_payload_MPL1F \
          pblock_payload_MPL1G \
          pblock_payload_MPL1H \
          pblock_payload_MPL2A \
          pblock_payload_MPL2B \
          pblock_payload_MPL2C \
          pblock_payload_MPL2D \
          pblock_payload_MPL3A \
          pblock_payload_MPL3B \
          pblock_payload_MPL3C \
          pblock_payload_MPL3D \
          pblock_payload_MPL4A \
          pblock_payload_MPL4B \
          pblock_payload_MPL4C \
          pblock_payload_MPL4D \
          pblock_payload_MPL5A \
          pblock_payload_MPL5B \
          pblock_payload_MPL5C \
          pblock_payload_MPL5D \
          pblock_payload_MPL6A \
          pblock_payload_MPL6B \
          pblock_payload_MPL6C \
          pblock_payload_MPL6D \
          ]]

set_property PARENT pblock_payload_MPD1to5 [get_pblocks [list \
          pblock_payload_MPD1A \
          pblock_payload_MPD1B \
          pblock_payload_MPD1C \
          pblock_payload_MPD1D \
          pblock_payload_MPD2A \
          pblock_payload_MPD2B \
          pblock_payload_MPD2C \
          pblock_payload_MPD2D \
          pblock_payload_MPD3A \
          pblock_payload_MPD3B \
          pblock_payload_MPD3C \
          pblock_payload_MPD3D \
          pblock_payload_MPD4A \
          pblock_payload_MPD4B \
          pblock_payload_MPD4C \
          pblock_payload_MPD4D \
          pblock_payload_MPD5A \
          pblock_payload_MPD5B \
          pblock_payload_MPD5C \
          pblock_payload_MPD5D \
          ]]
          
set_property PARENT pblock_payload_FTset1 [get_pblocks [list \
          pblock_payload_FTL2L3 \
          pblock_payload_FTL3L4 \
          pblock_payload_FTL5L6 \
          pblock_payload_FTL1D1 \
          ]]

set_property PARENT pblock_payload_FTset2 [get_pblocks [list \
          pblock_payload_FTL1L2 \
          pblock_payload_FTD1D2 \
          pblock_payload_FTD3D4 \
          pblock_payload_FTL2D1 \
          ]]

set_property PARENT pblock_payload_FTMPset1 [get_pblocks [list \
          pblock_payload_MPL1to6 \
          pblock_payload_FTset1 \
          ]]

set_property PARENT pblock_payload_FTMPset2 [get_pblocks [list \
          pblock_payload_MPD1to5 \
          pblock_payload_FTset2 \
          ]]

#
#set constraints

#set pblock_payload_PCVMSMERsrect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=0 && ROW_INDEX<=7 && COLUMN_INDEX==6}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
#add_rects_to_pblock_mod $lpblock_payload_PCVMSMERs $pblock_payload_PCVMSMERsrect

#set pblock_payload_MPL1to6rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=0 && ROW_INDEX<=3 && COLUMN_INDEX>=2 && COLUMN_INDEX<=6}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
#add_rects_to_pblock_mod $lpblock_payload_MPL1to6 $pblock_payload_MPL1to6rect
#
#set pblock_payload_MPD1to5rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=4 && ROW_INDEX<=7 && COLUMN_INDEX>=2 && COLUMN_INDEX<=6}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
#add_rects_to_pblock_mod $lpblock_payload_MPD1to5 $pblock_payload_MPD1to5rect

set pblock_payload_FTMPset1rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=0 && ROW_INDEX<=3 && COLUMN_INDEX>=1 && COLUMN_INDEX<=6}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_FTMPset1 $pblock_payload_FTMPset1rect

set pblock_payload_FTMPset2rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=4 && ROW_INDEX<=7 && COLUMN_INDEX>=1 && COLUMN_INDEX<=6}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_FTMPset2 $pblock_payload_FTMPset2rect

set pblock_payload_FTset1rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=0 && ROW_INDEX<=3 && COLUMN_INDEX>=1 && COLUMN_INDEX<=2}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_FTset1 $pblock_payload_FTset1rect

set pblock_payload_FTset2rect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=4 && ROW_INDEX<=7 && COLUMN_INDEX>=1 && COLUMN_INDEX<=2}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_FTset2 $pblock_payload_FTset2rect

set pblock_payload_KFrect [find_rects [get_sites -of [get_clock_regions -f {ROW_INDEX>=8}] -f "RPM_X >= $lLeftBoundary && RPM_X <= $lRightBoundary"]]
add_rects_to_pblock_mod $lpblock_payload_KF $pblock_payload_KFrect

#change only payload pblocks to be hard constraints
set_property IS_SOFT FALSE [get_pblocks pblock_payload_*]

#set SLRs for clusters

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1L2ABC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2ABC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2ABC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D4PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1L2DE [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2DE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2DE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1L2F [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2F \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2F_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1L2G [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2G \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2G_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1L2HI [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2HI \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2HI_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1L2JKL [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2JKL \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2JKL_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL2L3ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L2L3ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L2L3ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL3L4AB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L3L4AB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L3L4AB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL3L4CD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L3L4CD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L3L4CD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL5L6ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L5L6ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L5L6ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCD1D2ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_D1D2ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_D1D2ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCD3D4ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_D3D4ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_D3D4ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1D1ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1D1ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL1D1EFGH [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1D1EFGH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1D1EFGH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_PCL2D1ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L2D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L2D1ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIA_DELAY0/di_pipe_reg[1]* \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIE [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIE_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIF [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIF_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIG [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIG_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL1PHIH [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIH_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL2PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL2PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL2PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL2PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL3PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL3PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL3PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL3PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL4PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL4PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL4PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL4PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL5PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL5PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL5PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL5PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL6PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL6PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL6PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPL6PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD1PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD1PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD1PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD1PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD2PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD2PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD2PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD2PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD3PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD3PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD3PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD3PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD4PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD4PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD4PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD4PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD5PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD5PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD5PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_SLR_ASSIGNMENT slrcluster_payload_MPD5PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

#set clusters within SLRs

set_property USER_CLUSTER cluster_payload_PCL1L2ABC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2ABC \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2ABC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2ABC_D4PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1L2DE [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2DE \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2DE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2DE_D4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1L2F [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2F \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2F_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2F_D4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1L2G [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2G \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2G_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2G_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1L2HI [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2HI \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2HI_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2HI_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1L2JKL [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1L2JKL \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1L2JKL_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1L2JKL_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL2L3ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L2L3ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L2L3ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2L3ABCD_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL3L4AB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L3L4AB \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L3L4AB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4AB_D2PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL3L4CD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L3L4CD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L3L4CD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L3L4CD_D2PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL5L6ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L5L6ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L5L6ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L5L6ABCD_L4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCD1D2ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_D1D2ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_D1D2ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D1D2ABCD_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCD3D4ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_D3D4ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_D3D4ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_D3D4ABCD_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1D1ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1D1ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1ABCD_D5PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL1D1EFGH [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L1D1EFGH \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L1D1EFGH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L1D1EFGH_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_PCL2D1ABCD [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/PC_L2D1ABCD \
          payload/tf2_wrapper_1/SectorProcessor_1/MPAR_L2D1ABCD_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/MPROJ_L2D1ABCD_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIA_DELAY0/di_pipe_reg[1]* \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIE [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIE \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIE_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIE_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIF [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIF \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIF_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIF_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIG [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIG \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIG_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIG_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL1PHIH [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L1PHIH \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_L1PHIH_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_L1PHIH_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL2PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL2PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL2PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL2PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_L2PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL3PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL3PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL3PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL3PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L3PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL4PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL4PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL4PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL4PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L5L6_L4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL5PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL5PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL5PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL5PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_L5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL6PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL6PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL6PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPL6PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_L6PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_L6PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_L6PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD1PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD1PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD1PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD1PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D1PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D1PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D1PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD2PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD2PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD2PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD2PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D2PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L3L4_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D2PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D2PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD3PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD3PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD3PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD3PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D3PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D3PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D3PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD4PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD4PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD4PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD4PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D4PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1L2_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2L3_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D4PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L2D1_D4PHID_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD5PHIA [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIA \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIA_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIA_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD5PHIB [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIB \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIB_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIB_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD5PHIC [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHIC \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHIC_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHIC_DELAY0/tf_pipe_delay_1 \
          ]]

set_property USER_CLUSTER cluster_payload_MPD5PHID [get_cells -quiet [list \
          payload/tf2_wrapper_1/SectorProcessor_1/MP_D5PHID \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D1D2_D5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_D3D4_D5PHID_DELAY0/tf_pipe_delay_1 \
          payload/tf2_wrapper_1/SectorProcessor_1/FM_L1D1_D5PHID_DELAY0/tf_pipe_delay_1 \
          ]]

#set_property MAX_FANOUT 10000 [get_nets payload/kf_wrapper_1/kfout_top_1/OutObjectsToPacketsInstance/g1[0].RAMreset*]
#set_property MAX_FANOUT 10000 [get_nets payload/kf_wrapper_1/kfout_top_1/OutObjectsToPacketsInstance/g1[1].RAMreset*]
