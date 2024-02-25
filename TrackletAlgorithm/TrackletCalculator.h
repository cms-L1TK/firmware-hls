#ifndef TrackletAlgorithm_TrackletCalculator_h
#define TrackletAlgorithm_TrackletCalculator_h

#include <cmath>
//#include <cstring>

#include "Constants.h"
#include "AllStubMemory.h"
#include "TrackletParameterMemory.h"
#include "TrackletProjectionMemory.h"

template<TF::seed Seed> constexpr regionType InnerRegion() {
  return (
    (Seed == TF::L1L2 || Seed == TF::L2L3 || Seed == TF::L3L4 || Seed == TF::L1D1 || Seed == TF::L2D1) ? BARRELPS : (
      (Seed == TF::L5L6) ? BARREL2S : DISK
    )
  );
}
template<TF::seed Seed> constexpr regionType OuterRegion() {
  return (
    (Seed == TF::L1L2 || Seed == TF::L2L3) ? BARRELPS : (
      (Seed == TF::L3L4 || Seed == TF::L5L6) ? BARREL2S : DISK
    )
  );
}

namespace TC {
////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////

  static const uint8_t nproj_L1 = L1PHIH - L1PHIA + 1;
  static const uint8_t nproj_L2 = L2PHID - L2PHIA + 1;
  static const uint8_t nproj_L3 = L3PHID - L3PHIA + 1;
  static const uint8_t nproj_L4 = L4PHID - L4PHIA + 1;
  static const uint8_t nproj_L5 = L5PHID - L5PHIA + 1;
  static const uint8_t nproj_L6 = L6PHID - L6PHIA + 1;
  static const uint8_t nproj_D1 = D1PHID - D1PHIA + 1;
  static const uint8_t nproj_D2 = D2PHID - D2PHIA + 1;
  static const uint8_t nproj_D3 = D3PHID - D3PHIA + 1;
  static const uint8_t nproj_D4 = D4PHID - D4PHIA + 1;

  static const uint8_t shift_L1 = 0;
  static const uint8_t shift_L2 = shift_L1 + nproj_L1;
  static const uint8_t shift_L3 = shift_L2 + nproj_L2;
  static const uint8_t shift_L4 = shift_L3 + nproj_L3;
  static const uint8_t shift_L5 = shift_L4 + nproj_L4;
  static const uint8_t shift_L6 = shift_L5 + nproj_L5;

  static const uint8_t shift_D1 = 0;
  static const uint8_t shift_D2 = shift_D1 + nproj_D1;
  static const uint8_t shift_D3 = shift_D2 + nproj_D2;
  static const uint8_t shift_D4 = shift_D3 + nproj_D3;

  static const uint32_t mask_L1 = 0xFF << shift_L1;
  static const uint32_t mask_L2 = 0xF << shift_L2;
  static const uint32_t mask_L3 = 0xF << shift_L3;
  static const uint32_t mask_L4 = 0xF << shift_L4;
  static const uint32_t mask_L5 = 0xF << shift_L5;
  static const uint32_t mask_L6 = 0xF << shift_L6;
  static const uint32_t mask_D1 = 0xF << shift_D1;
  static const uint32_t mask_D2 = 0xF << shift_D2;
  static const uint32_t mask_D3 = 0xF << shift_D3;
  static const uint32_t mask_D4 = 0xF << shift_D4;

// number of bits per SP memory in ASInnerMask and ASOuterMask
  static const uint8_t kNBitsPerSPMem = 2;
  // mask used to select specific SP memory in ASInnerMask and ASOuterMask
  static const uint8_t kSPMemMask = (1 << kNBitsPerSPMem) - 1;

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Functions that are defined in TrackletCalculator_calculate_LXLY.h,
// TrackletCalculator.cc, and the bottom of this file.
////////////////////////////////////////////////////////////////////////////////
  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
  void calculate_LXLY (
    const typename AllStub<InnerRegion>::ASR r1_input,
    const typename AllStub<InnerRegion>::ASPHI phi1_input,
    const typename AllStub<InnerRegion>::ASZ z1_input,
    const typename AllStub<OuterRegion>::ASR r2_input,
    const typename AllStub<OuterRegion>::ASPHI phi2_input,
    const typename AllStub<OuterRegion>::ASZ z2_input,
    const Types::rmean r1mean_input,
    const Types::rmean r2mean_input,
    const Types::rmean rproj0_input,
    const Types::rmean rproj1_input,
    const Types::rmean rproj2_input,
    const Types::rmean rproj3_input,
    const Types::zmean zproj0_input,
    const Types::zmean zproj1_input,
    const Types::zmean zproj2_input,
    const Types::zmean zproj3_input,

    Types::rinv * const rinv_output,
    TrackletParameters::PHI0PAR * const phi0_output,
    TrackletParameters::TPAR * const t_output,
    Types::z0 * const z0_output,
    Types::phiL * const phiL_0_output,
    Types::phiL * const phiL_1_output,
    Types::phiL * const phiL_2_output,
    Types::phiL * const phiL_3_output,
    Types::zL * const zL_0_output,
    Types::zL * const zL_1_output,
    Types::zL * const zL_2_output,
    Types::zL * const zL_3_output,
    Types::der_phiL * const der_phiL_output,
    Types::der_zL * const der_zL_output,
    Types::phiD * const phiD_0_output,
    Types::phiD * const phiD_1_output,
    Types::phiD * const phiD_2_output,
    Types::phiD * const phiD_3_output,
    Types::rD * const rD_0_output,
    Types::rD * const rD_1_output,
    Types::rD * const rD_2_output,
    Types::rD * const rD_3_output,
    Types::der_phiD * const der_phiD_output,
    Types::der_rD * const der_rD_output
  );

  template<TF::seed Seed> bool barrelSeeding(const AllStub<InnerRegion<Seed>()> &innerStub, const AllStub<OuterRegion<Seed>()> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, Types::z0 * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);

  template<TF::seed Seed, TF::phiRegion iTC> const TrackletProjection<BARRELPS>::TProjTCID ID();

  template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], ap_uint<kNBits_MemAddr> nproj[NProjOut], const bool success);

  template<uint8_t NSPMem> void
  getIndices(
      const BXType bx,
      TC::Types::nSP nentries[NSPMem],
      TC::Types::nSPMem &iSPMem,
      TC::Types::nSP &iSP,
      bool &done
  );

}

template<TF::seed Seed, TF::phiRegion iTC> constexpr uint64_t ASInnerMask();
template<TF::seed Seed, TF::phiRegion iTC> constexpr uint64_t ASOuterMask();
template<TF::seed Seed, TF::phiRegion iTC> constexpr uint32_t TPROJMaskBarrel();
template<TF::seed Seed, TF::phiRegion iTC> constexpr uint32_t TPROJMaskDisk();

////////////////////////////////////////////////////////////////////////////////

// Writes a tracklet projection to the appropriate tracklet projection memory.
template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool
TC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], ap_uint<kNBits_MemAddr> nproj[NProjOut], const bool success)
{
  bool proj_success = true;

// Reject projections with extreme r/z values.
  if (TProjType != DISK) {
    if ((proj.getZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1))))
      proj_success = false;
    if (abs(proj.getZ()) > floatToInt(zlength, kz))
      proj_success = false;
  }
  else {
    if (proj.getR() < floatToInt(rmindiskvm, krprojdisk) || proj.getR() >= floatToInt(rmaxdisk, krprojdisk))
      proj_success = false;
  }

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  TC::Types::phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);
  if (TProjType == BARRELPS && NProjOut == nproj_L1) // layer 1
    phi >>= (nbits_maxvm - nbitsallstubs[0]);
  else // all other layers and disks
    phi >>= (nbits_maxvm - nbitsallstubs[1]);

  if (NProjOut > 0 && TPROJMask & (0x1 << 0) && success && proj_success && phi == 0)
    projout[0].write_mem(bx, proj, nproj[0]++);
  if (NProjOut > 1 && TPROJMask & (0x1 << 1) && success && proj_success && phi == 1)
    projout[1].write_mem(bx, proj, nproj[1]++);
  if (NProjOut > 2 && TPROJMask & (0x1 << 2) && success && proj_success && phi == 2)
    projout[2].write_mem(bx, proj, nproj[2]++);
  if (NProjOut > 3 && TPROJMask & (0x1 << 3) && success && proj_success && phi == 3)
    projout[3].write_mem(bx, proj, nproj[3]++);
  if (NProjOut > 4 && TPROJMask & (0x1 << 4) && success && proj_success && phi == 4)
    projout[4].write_mem(bx, proj, nproj[4]++);
  if (NProjOut > 5 && TPROJMask & (0x1 << 5) && success && proj_success && phi == 5)
    projout[5].write_mem(bx, proj, nproj[5]++);
  if (NProjOut > 6 && TPROJMask & (0x1 << 6) && success && proj_success && phi == 6)
    projout[6].write_mem(bx, proj, nproj[6]++);
  if (NProjOut > 7 && TPROJMask & (0x1 << 7) && success && proj_success && phi == 7)
    projout[7].write_mem(bx, proj, nproj[7]++);

  return (success && proj_success);
}


#endif
