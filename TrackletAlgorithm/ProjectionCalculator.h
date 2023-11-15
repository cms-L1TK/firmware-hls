#ifndef TrackletAlgorithm_ProjectionCalculator_h
#define TrackletAlgorithm_ProjectionCalculator_h

#include "TrackletParameterMemory.h"
#include "TrackletProjectionMemory.h"

#include "TrackletProcessor.h"

namespace PC {
template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool
addProj(const TrackletProjection<TProjType> &, const BXType, TrackletProjectionMemory<TProjType>[], int[], const bool);
}

// Writes a tracklet projection to the appropriate tracklet projection memory.
template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool

PC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], int nproj[NProjOut], const bool success)
{
  bool proj_success = true;

// Reject projections with extreme r/z values.
  if (TProjType != DISK) {
    if ((proj.getZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1)))) {
      proj_success = false;
    }
    if (abs(proj.getZ()) > TC::izmaxcut) {
      proj_success = false;
    }
  }
  else {
    if (proj.getR() < TC::irprojmincut || proj.getR() >= TC::irprojmaxcut)
      proj_success = false;
  }
  TC::Types::phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  if (TProjType == BARRELPS && NProjOut == TC::nproj_L1)
    phi >>= 2;
  else
    phi >>= 3;

  if (NProjOut > 0 && TPROJMask & (0x1 << 0) && success && proj_success && phi == 0)
    projout[0].write_mem(bx, proj);
  if (NProjOut > 1 && TPROJMask & (0x1 << 1) && success && proj_success && phi == 1)
    projout[1].write_mem(bx, proj);
  if (NProjOut > 2 && TPROJMask & (0x1 << 2) && success && proj_success && phi == 2)
    projout[2].write_mem(bx, proj);
  if (NProjOut > 3 && TPROJMask & (0x1 << 3) && success && proj_success && phi == 3)
    projout[3].write_mem(bx, proj);
  if (NProjOut > 4 && TPROJMask & (0x1 << 4) && success && proj_success && phi == 4)
    projout[4].write_mem(bx, proj);
  if (NProjOut > 5 && TPROJMask & (0x1 << 5) && success && proj_success && phi == 5)
    projout[5].write_mem(bx, proj);
  if (NProjOut > 6 && TPROJMask & (0x1 << 6) && success && proj_success && phi == 6)
    projout[6].write_mem(bx, proj);
  if (NProjOut > 7 && TPROJMask & (0x1 << 7) && success && proj_success && phi == 7)
    projout[7].write_mem(bx, proj);

  return (success && proj_success);
}
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

  // Overlap seeds
  else if (Seed >= TF::L1D1){
    const TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, iphi_D2, ir_D2, ider_phiD, ider_rD);
    const TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, iphi_D3, ir_D3, ider_phiD, ider_rD);
    const TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, iphi_D4, ir_D4, ider_phiD, ider_rD);

    PC::addProj<DISK, TC::nproj_D2, ((MaskDisk & TC::mask_D2) >> TC::shift_D2)> (tproj_D2, bx, &projout_disk[TC::D2PHIA], &nproj_disk[TC::D2PHIA], valid_D2);
    PC::addProj<DISK, TC::nproj_D3, ((MaskDisk & TC::mask_D3) >> TC::shift_D3)> (tproj_D3, bx, &projout_disk[TC::D3PHIA], &nproj_disk[TC::D3PHIA], valid_D3);
    PC::addProj<DISK, TC::nproj_D4, ((MaskDisk & TC::mask_D4) >> TC::shift_D4)> (tproj_D4, bx, &projout_disk[TC::D4PHIA], &nproj_disk[TC::D4PHIA], valid_D4);

    if (Seed == TF::L1D1){
      const TrackletProjection<DISK> tproj_D5(TCID, trackletIndex, iphi_D5, ir_D5, ider_phiD, ider_rD);
      PC::addProj<DISK, TC::nproj_D5, ((MaskDisk & TC::mask_D5) >> TC::shift_D5)> (tproj_D5, bx, &projout_disk[TC::D5PHIA], &nproj_disk[TC::D5PHIA], valid_D5);
    }
    else if (Seed == TF::L2D1){
      const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, iphi_L1, iz_L1, ider_phiL, ider_zL);
      PC::addProj<BARRELPS, TC::nproj_L1, ((MaskBarrel & TC::mask_L1) >> TC::shift_L1)> (tproj_L1, bx, &projout_barrel_ps[TC::L1PHIA], &nproj_barrel_ps[TC::L1PHIA], valid_L1);
    }
  }

  // Barrel-only seeds
  else if (Seed <= TF::L5L6){
    switch (Seed) {
      case TF::L1L2:
        {
          const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, iphi_L3, iz_L3, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, iphi_L4, iz_L4, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, iphi_L5, iz_L5, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, iphi_L6, iz_L6, ider_phiL, ider_zL);

          addL3 = PC::addProj<BARRELPS, TC::nproj_L3, ((MaskBarrel & TC::mask_L3) >> TC::shift_L3)> (tproj_L3, bx, &projout_barrel_ps[TC::L3PHIA], &nproj_barrel_ps[TC::L3PHIA], valid_L3);
          addL4 = PC::addProj<BARREL2S, TC::nproj_L4, ((MaskBarrel & TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], &nproj_barrel_2s[TC::L4PHIA], valid_L4);
          addL5 = PC::addProj<BARREL2S, TC::nproj_L5, ((MaskBarrel & TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], &nproj_barrel_2s[TC::L5PHIA], valid_L5);
          addL6 = PC::addProj<BARREL2S, TC::nproj_L6, ((MaskBarrel & TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], &nproj_barrel_2s[TC::L6PHIA], valid_L6);
        }
        break;
      case TF::L2L3:
        {
          const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, iphi_L1, iz_L1, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, iphi_L4, iz_L4, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, iphi_L5, iz_L5, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, iphi_L6, iz_L6, ider_phiL, ider_zL);

          PC::addProj<BARRELPS, TC::nproj_L1, ((MaskBarrel & TC::mask_L1) >> TC::shift_L1)> (tproj_L1, bx, &projout_barrel_ps[TC::L1PHIA], &nproj_barrel_ps[TC::L1PHIA], valid_L1);
          addL4 = PC::addProj<BARREL2S, TC::nproj_L4, ((MaskBarrel & TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], &nproj_barrel_2s[TC::L4PHIA], valid_L4);
          addL5 = PC::addProj<BARREL2S, TC::nproj_L5, ((MaskBarrel & TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], &nproj_barrel_2s[TC::L5PHIA], valid_L5);
          addL6 = PC::addProj<BARREL2S, TC::nproj_L6, ((MaskBarrel & TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], &nproj_barrel_2s[TC::L6PHIA], valid_L6);
        }
        break;
      case TF::L3L4:
        {
          const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, iphi_L1, iz_L1, ider_phiL, ider_zL);
          const TrackletProjection<BARRELPS> tproj_L2(TCID, trackletIndex, iphi_L2, iz_L2, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, iphi_L5, iz_L5, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, iphi_L6, iz_L6, ider_phiL, ider_zL);

          PC::addProj<BARRELPS, TC::nproj_L1, ((MaskBarrel & TC::mask_L1) >> TC::shift_L1)> (tproj_L1, bx, &projout_barrel_ps[TC::L1PHIA], &nproj_barrel_ps[TC::L1PHIA], valid_L1);
          PC::addProj<BARRELPS, TC::nproj_L2, ((MaskBarrel & TC::mask_L2) >> TC::shift_L2)> (tproj_L2, bx, &projout_barrel_ps[TC::L2PHIA], &nproj_barrel_ps[TC::L2PHIA], valid_L2);
          addL3 = addL4 = true;
          addL5 = PC::addProj<BARREL2S, TC::nproj_L5, ((MaskBarrel & TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], &nproj_barrel_2s[TC::L5PHIA], valid_L5);
          addL6 = PC::addProj<BARREL2S, TC::nproj_L6, ((MaskBarrel & TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], &nproj_barrel_2s[TC::L6PHIA], valid_L6);
        }
        break;
      case TF::L5L6:
        {
          const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, iphi_L1, iz_L1, ider_phiL, ider_zL);
          const TrackletProjection<BARRELPS> tproj_L2(TCID, trackletIndex, iphi_L2, iz_L2, ider_phiL, ider_zL);
          const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, iphi_L3, iz_L3, ider_phiL, ider_zL);
          const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, iphi_L4, iz_L4, ider_phiL, ider_zL);

          PC::addProj<BARRELPS, TC::nproj_L1, ((MaskBarrel & TC::mask_L1) >> TC::shift_L1)> (tproj_L1, bx, &projout_barrel_ps[TC::L1PHIA], &nproj_barrel_ps[TC::L1PHIA], valid_L1);
          PC::addProj<BARRELPS, TC::nproj_L2, ((MaskBarrel & TC::mask_L2) >> TC::shift_L2)> (tproj_L2, bx, &projout_barrel_ps[TC::L2PHIA], &nproj_barrel_ps[TC::L2PHIA], valid_L2);
          addL3 = PC::addProj<BARRELPS, TC::nproj_L3, ((MaskBarrel & TC::mask_L3) >> TC::shift_L3)> (tproj_L3, bx, &projout_barrel_ps[TC::L3PHIA], &nproj_barrel_ps[TC::L3PHIA], valid_L3);
          addL4 = PC::addProj<BARREL2S, TC::nproj_L4, ((MaskBarrel & TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], &nproj_barrel_2s[TC::L4PHIA], valid_L4);
          addL5 = addL6 = true;
        }
        break;
      default:
        break;
    }

    const TrackletProjection<DISK> tproj_D1(TCID, trackletIndex, iphi_D1, ir_D1, ider_phiD, ider_rD);
    const TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, iphi_D2, ir_D2, ider_phiD, ider_rD);
    const TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, iphi_D3, ir_D3, ider_phiD, ider_rD);
    const TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, iphi_D4, ir_D4, ider_phiD, ider_rD);

    PC::addProj<DISK, TC::nproj_D1, ((MaskDisk & TC::mask_D1) >> TC::shift_D1)> (tproj_D1, bx, &projout_disk[TC::D1PHIA], &nproj_disk[TC::D1PHIA], valid_D1 && !addL6);
    PC::addProj<DISK, TC::nproj_D2, ((MaskDisk & TC::mask_D2) >> TC::shift_D2)> (tproj_D2, bx, &projout_disk[TC::D2PHIA], &nproj_disk[TC::D2PHIA], valid_D2 && !addL5);
    PC::addProj<DISK, TC::nproj_D3, ((MaskDisk & TC::mask_D3) >> TC::shift_D3)> (tproj_D3, bx, &projout_disk[TC::D3PHIA], &nproj_disk[TC::D3PHIA], valid_D3 && !addL4);
    PC::addProj<DISK, TC::nproj_D4, ((MaskDisk & TC::mask_D4) >> TC::shift_D4)> (tproj_D4, bx, &projout_disk[TC::D4PHIA], &nproj_disk[TC::D4PHIA], valid_D4 && !addL3);
  }
  //============================================================================

  bx_o = bx; //Makes sure that bxs are aligned to make different "page" per bx in the system
}

#endif
