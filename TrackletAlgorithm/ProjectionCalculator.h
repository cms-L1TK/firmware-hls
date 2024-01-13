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
    TrackletParameters const &tpar, int trackletIndex,
    bool valid,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS], 
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S], 
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK])
  {

    if (!valid) {
      return;
    }

  int TCID = ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << 4) + iTC); // TODO: unsure if this is okay
  const uint32_t MaskBarrel = TPROJMaskBarrel<Seed, iTC>();
  const uint32_t MaskDisk = TPROJMaskDisk<Seed, iTC>(); 


    bool addL3 = false, addL4 = false, addL5 = false, addL6 = false; // whether a projection has been added successfully

 
    // Load the initial track parameters (phi0, z0, t, rinv) 
    TrackletParameters::PHI0PAR phi0 = tpar.getPhi0();
    TrackletParameters::Z0PAR z0 = tpar.getZ0();
    TrackletParameters::TPAR t = tpar.getT();
    TrackletParameters::RINVPAR rinv = tpar.getRinv();

    TC::Types::zL iz_L3, iz_L4, iz_L5, iz_L6;
    TC::Types::phiL iphi_L3, iphi_L4, iphi_L5, iphi_L6;


    int ir = rmean[2];
    int irtilde = ir*phiHG_/sqrtsix + 0.5;
    projToLayer(ir, irtilde, rinv, phi0, t, z0, iz_L3, iphi_L3);
    bool valid_zmin=iz_L3 >= -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    bool valid_zmax=iz_L3 < (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    bool valid_phimax=iphi_L3 < ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1);
    bool valid_phimin=iphi_L3 > 0;
    bool valid_L3 = valid_zmin & valid_zmax & valid_phimax & valid_phimin;

    iphi_L3 = iphi_L3 >> 3;

    ir = rmean[3];
    irtilde = ir*phiHG_/sqrtsix + 0.5;
    projToLayer(ir, irtilde, rinv, phi0, t, z0, iz_L4, iphi_L4);
    valid_zmin=iz_L4 >= -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    valid_zmax=iz_L4 < (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    valid_phimax=iphi_L4 < ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1);
    valid_phimin=iphi_L4 > 0;
    bool valid_L4 = valid_zmin & valid_zmax & valid_phimax & valid_phimin;

    iz_L4 = iz_L4 >> 4;

    ir = rmean[4];
    irtilde = ir*phiHG_/sqrtsix + 0.5;
    projToLayer(ir, irtilde, rinv, phi0, t, z0, iz_L5, iphi_L5);
    valid_zmin=iz_L5 >= -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    valid_zmax=iz_L5 < (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    valid_phimax=iphi_L5 < ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1);
    valid_phimin=iphi_L5 > 0;
    bool valid_L5 = valid_zmin & valid_zmax & valid_phimax & valid_phimin;

    iz_L5 = iz_L5 >> 4;

    ir = rmean[5];
    irtilde = ir*phiHG_/sqrtsix + 0.5;
    projToLayer(ir, irtilde, rinv, phi0, t, z0, iz_L6, iphi_L6);
    valid_zmin=iz_L6 >= -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    valid_zmax=iz_L6 < (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    valid_phimax=iphi_L6 < ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1);
    valid_phimin=iphi_L6 > 0;
    bool valid_L6 = valid_zmin & valid_zmax & valid_phimax & valid_phimin;

    iz_L6 = iz_L6 >> 4;


    TC::Types::der_phiL ider_phiL = -(rinv >> (1+3));
    TC::Types::der_zL ider_zL = t >> 3;


      // Create projections with corrections 
      const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, iphi_L3, iz_L3, ider_phiL, ider_zL);
      const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, iphi_L4, iz_L4, ider_phiL, ider_zL);
      const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, iphi_L5, iz_L5, ider_phiL, ider_zL);
      const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, iphi_L6, iz_L6, ider_phiL, ider_zL);

      int nproj_dummy[8]; //FIXME current addproj requires this argument, but is not used... 

    // Write the projections 
      // addProj checks if the projection is valid in the phi region
      addL3 = TC::addProj<BARRELPS, TC::nproj_L3, ((MaskBarrel & TC::mask_L3) >> TC::shift_L3)> (tproj_L3, bx, &projout_barrel_ps[TC::L3PHIA], nproj_dummy, valid_L3);

      addL4 = TC::addProj<BARREL2S, TC::nproj_L4, ((MaskBarrel & TC::mask_L4) >> TC::shift_L4)> (tproj_L4, bx, &projout_barrel_2s[TC::L4PHIA], nproj_dummy, valid_L4);

      addL5 = TC::addProj<BARREL2S, TC::nproj_L5, ((MaskBarrel & TC::mask_L5) >> TC::shift_L5)> (tproj_L5, bx, &projout_barrel_2s[TC::L5PHIA], nproj_dummy, valid_L5);

      addL6 = TC::addProj<BARREL2S, TC::nproj_L6, ((MaskBarrel & TC::mask_L6) >> TC::shift_L6)> (tproj_L6, bx, &projout_barrel_2s[TC::L6PHIA], nproj_dummy, valid_L6);
      std::cout << addL4 <<addL5 << addL6 << std::endl;


      TC::Types::rD ir_D1, ir_D2, ir_D3, ir_D4;
      TC::Types::phiD iphi_D1, iphi_D2, iphi_D3, iphi_D4;

      //constexpr int izproj0 = zmean[projectionDisks[Seed][0]];
      //constexpr int izproj1 = zmean[projectionDisks[Seed][1]];
      //constexpr int izproj2 = zmean[projectionDisks[Seed][2]];
      //constexpr int izproj3 = zmean[projectionDisks[Seed][3]];

      constexpr int izproj0 = zmean[6];
      constexpr int izproj1 = zmean[7];
      constexpr int izproj2 = zmean[8];
      constexpr int izproj3 = zmean[9];

      const ap_int<14> zproj0 = izproj0;
      const ap_int<14> zproj1 = izproj1;
      const ap_int<14> zproj2 = izproj2;
      const ap_int<14> zproj3 = izproj3;

      static const InvtLUT lut_itinv;
      ap_uint<20> itinv = lut_itinv.lookup(abs(t)&4095);

      TC::Types::der_phiD ider_phiD = (-rinv*itinv) >> 17;
      TC::Types::der_rD ider_rD = itinv >> 5;
      
      projToDisk(zproj0, itinv, rinv, phi0, t, z0, ir_D1, iphi_D1);
      projToDisk(zproj1, itinv, rinv, phi0, t, z0, ir_D2, iphi_D2);
      projToDisk(zproj2, itinv, rinv, phi0, t, z0, ir_D3, iphi_D3);
      projToDisk(zproj3, itinv, rinv, phi0, t, z0, ir_D4, iphi_D4);

      constexpr int itcut = 1.0/kt;

      const TrackletProjection<DISK> tproj_D1(TCID, trackletIndex, iphi_D1, ir_D1, ider_phiD, ider_rD);
      bool validD1 = true;

      const TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, iphi_D2, ir_D2, ider_phiD, ider_rD);
      bool validD2 = true;

      const TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, iphi_D3, ir_D3, ider_phiD, ider_rD);
      bool validD3 = ir_D3 >= irmindisk && ir_D3 < irmaxdisk && ((t > itcut) || (t<-itcut)) && !addL4;

      const TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, iphi_D4, ir_D4, ider_phiD, ider_rD);
      bool validD4 = ir_D4 >= irmindisk && ir_D4 < irmaxdisk && ((t > itcut) || (t<-itcut)) && !addL3;

      bool addD1 = TC::addProj<DISK, TC::nproj_D1, ((MaskDisk & TC::mask_D1) >> TC::shift_D1)> (tproj_D1, bx, &projout_disk[TC::D1PHIA], nproj_dummy, validD1);

      bool addD2 = TC::addProj<DISK, TC::nproj_D2, ((MaskDisk & TC::mask_D2) >> TC::shift_D2)> (tproj_D2, bx, &projout_disk[TC::D2PHIA], nproj_dummy, validD2);

      bool addD3 = TC::addProj<DISK, TC::nproj_D3, ((MaskDisk & TC::mask_D3) >> TC::shift_D3)> (tproj_D3, bx, &projout_disk[TC::D3PHIA], nproj_dummy, validD3);

      bool addD4 = TC::addProj<DISK, TC::nproj_D4, ((MaskDisk & TC::mask_D4) >> TC::shift_D4)> (tproj_D4, bx, &projout_disk[TC::D4PHIA], nproj_dummy, validD4);

  bx_o = bx; //Makes sure that bxs are aligned to make different "page" per bx in the system 
}

#endif
