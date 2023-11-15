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

  // Loop over all tracklets in event 
  for (TrackletProjection<BARREL2S>::TProjTrackletIndex trackletIndex = 0; trackletIndex < N; trackletIndex++) 
  {
    #pragma HLS unroll

    bool addL3 = false, addL4 = false, addL5 = false, addL6 = false; // whether a projection has been added successfully

    // Read in tracklet parameters from the memory 
    const auto &tpar = trackletParameters->read_mem(bx, trackletIndex);
    //std::cout<<"tpar.getPhi0: " << tpar.getPhi0() << std::endl; 

    if (tpar.getPhi0() != 0) // TODO: better way of checking if is filled? 
    {
      std::cout << "Tracklet # "<< trackletIndex<< " -----------------------------------------------------------------" << std::endl; 

    // Load the initial track parameters (phi0, z0, t, rinv) 
      TrackletParameters::PHI0PAR phi0 = tpar.getPhi0();
      std::cout<<"phi0:         " << phi0 << std::endl;  
      TrackletParameters::Z0PAR z0 = tpar.getZ0();
      TrackletParameters::TPAR t = tpar.getT();
      TrackletParameters::RINVPAR rinv = tpar.getRinv();

      // TODO: Access radius of each layer 

      
      TC::Types::phiL phiL_PS;
      TC::Types::zL zL_PS;
      TC::Types::phiL phiL_2S;
      TC::Types::zL zL_2S;
      // TODO: What should we do for derivatives? 
      TC::Types::der_phiL der_phiL = 0;
      TC::Types::der_zL der_zL = 0;

      TC::Types::phiL phiL_PS_L3;
      TC::Types::phiL phiL_2S_L4;
      TC::Types::phiL phiL_2S_L5;
      TC::Types::phiL phiL_2S_L6;

      // Set up projections for barrel layer 


      // TODO: Deal with over/underflows in phi bit 


     // Transform the N bit trackletParameters into M bit trackletProjections in phi by multiplying by 2^(k_phi0/k_phi)
     // E.g. a bitshift left << of n_phi-n_phi0, 
      // n_phi0 = 18  n_phi = 17 for BARREL2S, n_phi-n_phi0=-1, because this is negative it becomes a bitshift right 
     //std::cout<<"shift by:     " << (TrackletProjection<BARREL2S>::kTProjPhiSize - tpar.kTParPhi0Size) << std::endl;  
     //phiL = phi0 >> (tpar.kTParPhi0Size-TrackletProjection<BARREL2S>::kTProjPhiSize);
     //zL = z0 >> (tpar.kTParZ0Size - TrackletProjection<BARREL2S>::kTProjRZSize); 
     // TODO: Somehow this is the correct amount of shifting for L3 ( >> 1) phi >> 1 and z >> 2


     // Corrected. Apparently the two trackletParameter MSBs are used for under/overflow, they are usually 0 so we ignore them
     // n_phi0 = 16, n_phi = 17, n_phi-n_phi0=1, this is positive, so keep the bitshift left. 
     //int my_shift_L4 = TrackletProjection<BARREL2S>::kTProjPhiSize - (tpar.kTParPhi0Size-2) ;
     //std::cout<<"shift by:     " << my_shift_L4 << std::endl;  
     //phiL = phi0 << my_shift_L4;

     // For PS  (things seems to work well for L3)
     int phi_shift_PS = 2;
     phiL_PS = phi0 >> phi_shift_PS;
     std::cout<<"No correction, phiL_PS: "<<phiL_PS<<std::endl;

     int z_shift_PS = 2;
     zL_PS = z0 >> z_shift_PS; 

      // For 2S (looks like it needs corrections a bit more, ordering gets funny)
     int phi_shift_2S = 1;//TrackletProjection<BARREL2S>::kTProjPhiSize - (tpar.kTParPhi0Size-2) ;
     phiL_2S = phi0 << phi_shift_2S;
     std::cout<<"No correction, phiL_2S: "<<phiL_2S<<std::endl;

     int z_shift_2S = 2;
     zL_2S = z0 << z_shift_2S; 

     // Calculate first order corrections // TODO: tidy up redundancy here
     int corr_phi_PS_L3 = rmean[2]*rinv;
     std::cout<<"rmean[2]: "<< rmean[2]<<std::endl;
     std::cout<<"rinv: "<< rinv<<std::endl;
     std::cout<<"corr_phi_PS_L3: "<< corr_phi_PS_L3 <<std::endl;

     int corr_phi_shift_PS = TrackletProjection<BARRELPS>::kTProjPhiSize - TrackletProjection<BARRELPS>::kTProjRZSize - tpar.kTParRinvSize - 1;
     std::cout<<"corr_phi_shift_PS: "<< corr_phi_shift_PS <<std::endl;

     phiL_PS_L3 =  phiL_PS-(corr_phi_PS_L3 >> 12);
     std::cout<<"phiL_PS_L3: "<<phiL_PS_L3<<std::endl;

     int corr_phi_2S_L4 = rmean[3]*rinv;
     int corr_phi_shift_2S = 9;//TrackletProjection<BARREL2S>::kTProjPhiSize - TrackletProjection<BARREL2S>::kTProjRZSize - tpar.kTParRinvSize - 1;
     std::cout<<"corr_phi_shift_2S: "<< corr_phi_shift_2S <<std::endl;
     phiL_2S_L4 =  phiL_2S-(corr_phi_2S_L4 >> corr_phi_shift_2S);
     std::cout<<"phiL_2S_L4: "<<phiL_2S_L4<<std::endl;

    int corr_phi_2S_L5 = rmean[4]*rinv;
    phiL_2S_L5 =  phiL_2S-(corr_phi_2S_L5 >> corr_phi_shift_2S);
    std::cout<<"phiL_2S_L5: "<<phiL_2S_L5<<std::endl;

    int corr_phi_2S_L6 = rmean[5]*rinv;
    phiL_2S_L6 =  phiL_2S-(corr_phi_2S_L6 >> corr_phi_shift_2S);
    std::cout<<"phiL_2S_L6: "<<phiL_2S_L6<<std::endl;

    // Create projections no corrections
      //const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL_PS, zL_PS, der_phiL, der_zL);
      //const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL_2S, zL_2S, der_phiL, der_zL);
      //const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL_2S, zL_2S, der_phiL, der_zL);
      //const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL_2S, zL_2S, der_phiL, der_zL);
      // std::cout<<"tproj phi:     " << tproj_L4.getPhi() << std::endl;

      // Create projections with corrections 
      const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL_PS_L3, zL_PS, der_phiL, der_zL);
      const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL_2S_L4, zL_2S, der_phiL, der_zL);
      const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL_2S_L5, zL_2S, der_phiL, der_zL);
      const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL_2S_L6, zL_2S, der_phiL, der_zL);

    // Write the projections 
      // addProj checks if the projection is valid in the phi region
      addL3 = TC::addProj<BARRELPS, TC::nproj_L3, ((MaskBarrel & TC::mask_L3) >> TC::shift_L3)> (tproj_L3, bx, &projout_barrel_ps[TC::L3PHIA], &nproj_barrel_2s[TC::L3PHIA], true);
      addL4 = TC::addProj<BARREL2S, TC::nproj_L4, ((MaskBarrel & TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], &nproj_barrel_2s[TC::L4PHIA], true);
      addL5 = TC::addProj<BARREL2S, TC::nproj_L5, ((MaskBarrel & TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], &nproj_barrel_2s[TC::L5PHIA], true);
      addL6 = TC::addProj<BARREL2S, TC::nproj_L6, ((MaskBarrel & TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], &nproj_barrel_2s[TC::L6PHIA], true);
      std::cout << addL4 <<addL5 << addL6 << std::endl;
    } 
  }
  bx_o = bx; //Makes sure that bxs are aligned to make different "page" per bx in the system 
}

#endif

