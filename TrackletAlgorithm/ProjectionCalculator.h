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
#include "TrackletProcessor_parameters.h"


// This is the primary interface for the ProjectionCalculator.
template<
  TF::seed Seed, // seed layer combination (TC::L1L2, TC::L3L4, etc.)
  TC::itc iTC, // letter at the end of the TC name (TC_L1L2A and TC_L5L6A have
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

  int TCID = ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << 4) + iTC); // TODO: unsure if this is okay
  const uint32_t MaskBarrel = TPROJMaskBarrel<Seed, iTC>();
  const uint32_t MaskDisk = TPROJMaskDisk<Seed, iTC>(); 

  // Set up writing to the projection memories 
  int nproj_barrel_ps[TC::N_PROJOUT_BARRELPS];//  Number of projections written to the different parts
  int nproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
  int nproj_disk[TC::N_PROJOUT_DISK];
  #pragma HLS array_partition variable=nproj_barrel_ps complete
  #pragma HLS array_partition variable=nproj_barrel_2s complete
  #pragma HLS array_partition variable=nproj_disk complete
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

  // Loop over all tracklets in event // TODO: Max number of tracklets? 
  for (TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex = 0; trackletIndex < 20; trackletIndex++) 
  {
    #pragma HLS unroll
    std::cout << "Testing -----------------------------------------------------------------" << std::endl; // Why not producing output? Had to add in generate statement
    std::cout << trackletIndex << std::endl;

    bool addL3 = false, addL4 = false, addL5 = false, addL6 = false; // whether a projection has been added successfully

    // Read in tracklet parameters from the memory //
    const auto &tpar = trackletParameters->read_mem(bx, trackletIndex);
    std::cout<< tpar.getPhi0() << std::endl; 
    if (tpar.getPhi0() != 0)
    {
    // Calculate the projections TODO: actually calculate instead of dummies
      TC::Types::phiL phiL = tpar.getPhi0();
      TC::Types::zL zL = tpar.getZ0();
      TC::Types::der_phiL der_phiL = tpar.getPhi0();
      TC::Types::der_zL der_zL = tpar.getZ0();

    // Create garbage projections
      const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
      const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
      const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);
      const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL, zL, der_phiL, der_zL);

    // Write the projections 
      addL3 = TC::addProj<BARRELPS, TC::nproj_L3, ((MaskBarrel & TC::mask_L3) >> TC::shift_L3)> (tproj_L3, bx, &projout_barrel_ps[TC::L3PHIA], &nproj_barrel_ps[TC::L3PHIA], true);
      addL4 = TC::addProj<BARREL2S, TC::nproj_L4, ((MaskBarrel & TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], &nproj_barrel_2s[TC::L4PHIA], true);
      addL5 = TC::addProj<BARREL2S, TC::nproj_L5, ((MaskBarrel & TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], &nproj_barrel_2s[TC::L5PHIA], true);
      addL6 = TC::addProj<BARREL2S, TC::nproj_L6, ((MaskBarrel & TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], &nproj_barrel_2s[TC::L6PHIA], true);
      std::cout << addL3 <<addL4 <<addL5 << addL6 << std::endl;
    } 
  }
  bx_o = bx; //Makes sure that bxs are aligned to make different "page" per bx in the system 
}

#endif

