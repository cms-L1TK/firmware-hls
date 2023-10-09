#ifndef TrackletAlgorithm_ProjectionCalculator_h
#define TrackletAlgorithm_ProjectionCalculator_h

#include <cmath>
#include <iostream>

#include "AllStubMemory.h"
#include "AllStubInnerMemory.h"
#include "TrackletParameterMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubTEOuterMemoryCM.h"
#include "TEBuffer.h"
#include "TrackletEngineUnit.h"
#include "TrackletProcessor.h"



// This is the primary interface for the ProjectionCalculator.
template<
  TF::seed Seed, // seed layer combination (TC::L1L2, TC::L3L4, etc.)
  TC::itc iTC, // letter at the end of the TC name (TC_L1L2A and TC_L5L6A have
// the same iTC); generally indicates the region of the phi sector
             // being processed
  //uint8_t OuterPhiRegion, // outer phi region
  //uint8_t RZBins,         // number of RZ bins in outer layer/disk
  //uint8_t PhiBins,        // number of Phi bins in outer layer/dsik
  //uint8_t NASMemInner, // number of inner all-stub memories
  uint16_t N // maximum number of steps
> void
  ProjectionCalculator(
		    const BXType bx,  
        BXType& bx_o,
        TrackletParameterMemory * const trackletParameters, 
        TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS], 
        TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S], 
        TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK])
{


  int TCID = 0; // TODO: unsure if this should be passed in or not 

  //for (int trackletCounter = 0, trackletCounter < 1, trackletCounter++) 
  for (TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex = 0; trackletIndex < 1; trackletIndex++) 
  {
    std::cout << trackletIndex << std::endl;
  
    //TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex = 0; // TODO: Unsure what this should be
    // TODO: Make giant loop here

    bool addL3 = false, addL4 = false, addL5 = false, addL6 = false; // whether a projection has been added successfully

    
    // Read in tracklet parameters from the memory //
    const auto &tpar = trackletParameters->read_mem(bx, trackletIndex);
    //std::cout<< tpar << std::endl; 

    // Calculate the projections (TODO: actually calculate instead of dummies)
    TC::Types::phiL phiL = tpar.getPhi0();
    TC::Types::zL zL = tpar.getZ0();
    TC::Types::der_phiL der_phiL = tpar.getPhi0();
    TC::Types::der_zL der_zL = tpar.getZ0();
    
    // Set up writing the projections 
    int nproj_barrel_ps[TC::N_PROJOUT_BARRELPS];//  Number of projections written to the different parts
    int nproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
    int nproj_disk[TC::N_PROJOUT_DISK];
    for (unsigned int i = 0; i < TC::N_PROJOUT_BARRELPS; i++) {
      #pragma HLS unroll
      nproj_barrel_ps[i] = 0;
    }
    for (unsigned int i = 0; i < TC::N_PROJOUT_BARREL2S; i++) {
      #pragma HLS unroll
      nproj_barrel_2s[i] = 0;
    }
    for (unsigned int i = 0; i < TC::N_PROJOUT_DISK; i++) {
      #pragma HLS unroll
      nproj_disk[i] = 0;
    }

    // Create garbage projections
    const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
    const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
    const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
    const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
    //const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
    //const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
    //const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
    //const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);

    // Write the projections // TODO: TPROJMask copy in logic for generate_PC.py
    addL3 = TC::addProj<BARRELPS, TC::nproj_L3, (( TC::mask_L3) >> TC::shift_L3)> (tproj_L3, bx, &projout_barrel_ps[TC::L3PHIA], &nproj_barrel_ps[TC::L3PHIA], true);
    //addL3 = TC::addProj<BARRELPS, nproj_L3, ((TPROJMaskBarrel & mask_L3) >> shift_L3)> (tproj_L3, bx, &projout_barrel_ps[L3PHIA], &nproj_barrel_ps[L3PHIA], success && valid_proj[0]);
    addL4 = TC::addProj<BARREL2S, TC::nproj_L4, ((TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], &nproj_barrel_2s[TC::L4PHIA], true);
    addL5 = TC::addProj<BARREL2S, TC::nproj_L5, ((TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], &nproj_barrel_2s[TC::L5PHIA], true);
    addL6 = TC::addProj<BARREL2S, TC::nproj_L6, ((TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], &nproj_barrel_2s[TC::L6PHIA], true);
    std::cout << addL3 << std::endl;
    std::cout << "Testing -----------------------------------------------------------------" << std::endl; // Why not producing output? Had to add in generate statement

    bx_o = bx; //Makes sure that bxs are aligned to make different "page" per bx in the system 
    

  }
}

#endif

