#ifndef TrackletAlgorithm_TrackletCalculator_h
#define TrackletAlgorithm_TrackletCalculator_h

#include <cmath>
#include <cstring>

#include "StubPairMemory.h"
#include "AllStubMemory.h"
#include "TrackletParameterMemory.h"
#include "TrackletProjectionMemory.h"

namespace TC {
////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////
  namespace Types {
    typedef ap_uint<2> nASMem;
    typedef ap_uint<4> nSPMem;
    typedef ap_uint<11> nSP; // this should be large enough to index the entire list of stub pairs, across all memories

    typedef ap_int<13> rmean;
    typedef ap_int<14> zmean;
    typedef ap_int<15> rinv;
    typedef ap_int<11> z0;
    typedef ap_uint<20> phiL;
    typedef ap_int<15> zL;
    typedef ap_int<11> der_phiL;
    typedef ap_int<10> der_zL;
    typedef ap_uint<16> phiD;
    typedef ap_int<14> rD;
    typedef ap_int<10> der_phiD;
    typedef ap_int<10> der_rD;
    typedef ap_uint<1> flag;
  }

  enum itc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
  enum projout_index_barrel_ps {L1PHIA = 0, L1PHIB = 1, L1PHIC = 2, L1PHID = 3, L1PHIE = 4, L1PHIF = 5, L1PHIG = 6, L1PHIH = 7, L2PHIA = 8, L2PHIB = 9, L2PHIC = 10, L2PHID = 11, L3PHIA = 12, L3PHIB = 13, L3PHIC = 14, L3PHID = 15, N_PROJOUT_BARRELPS = 16};
  enum projout_index_barrel_2s {L4PHIA = 0, L4PHIB = 1, L4PHIC = 2, L4PHID = 3, L5PHIA = 4, L5PHIB = 5, L5PHIC = 6, L5PHID = 7, L6PHIA = 8, L6PHIB = 9, L6PHIC = 10, L6PHID = 11, N_PROJOUT_BARREL2S = 12};
  enum projout_index_disk      {D1PHIA = 0, D1PHIB = 1, D1PHIC = 2, D1PHID = 3, D2PHIA = 4, D2PHIB = 5, D2PHIC = 6, D2PHID = 7, D3PHIA = 8, D3PHIB = 9, D3PHIC = 10, D3PHID = 11, D4PHIA = 12, D4PHIB = 13, D4PHIC = 14, D4PHID = 15, N_PROJOUT_DISK = 16};

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

  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion> bool barrelSeeding(const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, Types::z0 * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);

  template<TF::seed Seed, TC::itc iTC> const TrackletProjection<BARRELPS>::TProjTCID ID();

  template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], int nproj[NProjOut], const bool success);

  template<uint8_t NSPMem> void
  getIndices(
      const BXType bx,
      const StubPairMemory stubPairs[NSPMem],
      TC::Types::nSPMem &iSPMem,
      TC::Types::nSP &iSP,
      bool &done
  );

  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion, uint32_t TPROJMaskBarrel, uint32_t TPROJMaskDisk> void
  processStubPair(
      const BXType bx,
      const StubPair::SPInnerIndex innerIndex,
      const AllStub<InnerRegion> &innerStub,
      const StubPair::SPOuterIndex outerIndex,
      const AllStub<OuterRegion> &outerStub,
      const TrackletProjection<BARRELPS>::TProjTCID TCID,
      TrackletProjection<BARRELPS>::TProjTrackletIndex &trackletIndex,
      TrackletParameterMemory * const trackletParameters,
      TrackletProjectionMemory<BARRELPS> projout_barrel_ps[N_PROJOUT_BARRELPS],
      TrackletProjectionMemory<BARREL2S> projout_barrel_2s[N_PROJOUT_BARREL2S],
      TrackletProjectionMemory<DISK> projout_barrel_disk[N_PROJOUT_DISK],
      int &npar,
      int nproj_barrel_ps[N_PROJOUT_BARRELPS],
      int nproj_barrel_2s[N_PROJOUT_BARREL2S],
      int nproj_disk[N_PROJOUT_DISK]
  );
}

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
template<TF::seed Seed, TC::itc iTC> constexpr uint8_t NASMemInner();
template<TF::seed Seed, TC::itc iTC> constexpr uint8_t NASMemOuter();
template<TF::seed Seed, TC::itc iTC> constexpr uint8_t NSPMem();
template<TF::seed Seed, TC::itc iTC> constexpr uint16_t ASInnerMask();
template<TF::seed Seed, TC::itc iTC> constexpr uint16_t ASOuterMask();
template<TF::seed Seed, TC::itc iTC> constexpr uint32_t TPROJMaskBarrel();
template<TF::seed Seed, TC::itc iTC> constexpr uint32_t TPROJMaskDisk();

template<TF::seed Seed, TC::itc iTC, regionType InnerRegion, regionType OuterRegion, uint8_t NASMemInner, uint8_t NASMemOuter, uint8_t NSPMem> void
TrackletCalculator(
    const BXType bx,
    const AllStubMemory<InnerRegion> innerStubs[NASMemInner],
    const AllStubMemory<OuterRegion> outerStubs[NASMemOuter],
    const StubPairMemory stubPairs[NSPMem],
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
);

void TrackletCalculator_L1L2E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<BARRELPS> outerStubs[1],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
);

void TrackletCalculator_L1L2G(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<BARRELPS> outerStubs[2],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
);

void TrackletCalculator_L3L4E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<BARREL2S> outerStubs[2],
    const StubPairMemory stubPairs[11],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
);

////////////////////////////////////////////////////////////////////////////////

#include "TrackletCalculator_calculate_LXLY.h"
#include "TrackletCalculator_parameters.h"

// This function calls calculate_LXLY, defined in
// TrackletCalculator_calculate_LXLY.h, and applies cuts to the results.
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion> bool
TC::barrelSeeding(const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, TC::Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TC::Types::z0 * const z0, TrackletParameters::TPAR * const t, TC::Types::phiL phiL[4], TC::Types::zL zL[4], TC::Types::der_phiL * const der_phiL, TC::Types::der_zL * const der_zL, TC::Types::flag valid_proj[4], TC::Types::phiD phiD[4], TC::Types::rD rD[4], TC::Types::der_phiD * const der_phiD, TC::Types::der_rD * const der_rD, TC::Types::flag valid_proj_disk[4])
{
  TC::Types::rmean r1mean, r2mean, rproj[4];
  switch (Seed) {
    case TF::L1L2:
      r1mean   = rmean[TF::L1];
      r2mean   = rmean[TF::L2];
      rproj[0] = rmean[TF::L3];
      rproj[1] = rmean[TF::L4];
      rproj[2] = rmean[TF::L5];
      rproj[3] = rmean[TF::L6];
      break;
    case TF::L3L4:
      rproj[0] = rmean[TF::L1];
      rproj[1] = rmean[TF::L2];
      r1mean   = rmean[TF::L3];
      r2mean   = rmean[TF::L4];
      rproj[2] = rmean[TF::L5];
      rproj[3] = rmean[TF::L6];
      break;
    case TF::L5L6:
      rproj[0] = rmean[TF::L1];
      rproj[1] = rmean[TF::L2];
      rproj[2] = rmean[TF::L3];
      rproj[3] = rmean[TF::L4];
      r1mean   = rmean[TF::L5];
      r2mean   = rmean[TF::L6];
      break;
  }
  TC::Types::zmean zproj[4] = {zmean[TF::D1], zmean[TF::D2], zmean[TF::D3], zmean[TF::D4]};
  calculate_LXLY<Seed, InnerRegion, OuterRegion>(
      innerStub.getR(),
      innerStub.getPhi(),
      innerStub.getZ(),
      outerStub.getR(),
      outerStub.getPhi(),
      outerStub.getZ(),
      r1mean,
      r2mean,
      rproj[0],
      rproj[1],
      rproj[2],
      rproj[3],
      zproj[0],
      zproj[1],
      zproj[2],
      zproj[3],

      rinv,
      phi0,
      t,
      z0,
      &phiL[0],
      &phiL[1],
      &phiL[2],
      &phiL[3],
      &zL[0],
      &zL[1],
      &zL[2],
      &zL[3],
      der_phiL,
      der_zL,
      &phiD[0],
      &phiD[1],
      &phiD[2],
      &phiD[3],
      &rD[0],
      &rD[1],
      &rD[2],
      &rD[3],
      der_phiD,
      der_rD
  );

// Determine which layer projections are valid.
  valid_proj: for (ap_uint<3> i = 0; i < N_LAYER - 2; i++) {
    valid_proj[i] = true;
    if (zL[i] < -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (zL[i] >= (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (phiL[i] >= ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1))
      valid_proj[i] = false;
    if (phiL[i] <= 0)
      valid_proj[i] = false;
    if (rproj[i] < rmean[3]) {
      phiL[i] >>= (TrackletProjection<BARREL2S>::kTProjPhiSize - TrackletProjection<BARRELPS>::kTProjPhiSize);
      if (phiL[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1)
        phiL[i] = (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 2;
    }
    else
      zL[i] >>= (TrackletProjection<BARRELPS>::kTProjRZSize - TrackletProjection<BARREL2S>::kTProjRZSize);
  }

// Determine which disk projections are valid.
  valid_proj_disk: for (ap_uint<3> i = 0; i < N_DISK - 1; i++) {
    valid_proj_disk[i] = true;
    if (abs(*t) < floatToInt(1.0, kt)) // disk projections are invalid if |t| < 1
      valid_proj_disk[i] = false;
    if (phiD[i] <= 0)
      valid_proj_disk[i] = false;
    if (phiD[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1)
      valid_proj_disk[i] = false;
    if (rD[i] <= floatToInt(rmindisk, krprojdisk) || rD[i] > floatToInt(rmaxdisk, krprojdisk))
      valid_proj_disk[i] = false;
  }

// Reject tracklets with too high a curvature or with too large a longitudinal
// impact parameter.
  bool success = true;
  if (abs(*rinv) >= floatToInt(rinvcut, krinv))
    success = false;
  if (abs(*z0) >= ((Seed == TF::L1L2) ? floatToInt(z0cut, kz0) : floatToInt(1.5 * z0cut, kz0)))
    success = false;

  const ap_int<TrackletParameters::kTParPhi0Size + 2> phicrit = *phi0 - (*rinv<<1);
  const bool keep = (phicrit > 9253) && (phicrit < 56269);
  success = success && keep;

  return success;
}

// Returns a unique identifier assigned to each TC.
template<TF::seed Seed, TC::itc iTC> const TrackletProjection<BARRELPS>::TProjTCID
TC::ID()
{
  return ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << TrackletProjection<BARRELPS>::kTProjITCSize) + iTC);
}

// Writes a tracklet projection to the appropriate tracklet projection memory.
template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool
TC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], int nproj[NProjOut], const bool success)
{
  bool proj_success = true;

// Reject projections with extreme r/z values.
  if (TProjType != DISK) {
    if ((proj.getRZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getRZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1))))
      proj_success = false;
    if (abs(proj.getRZ()) > floatToInt(zlength, kz))
      proj_success = false;
  }
  else {
    if (proj.getRZ() < floatToInt(rmindisktc, krprojdisk) || proj.getRZ() > floatToInt(rmaxdisktc, krprojdisk))
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


// Determine the correct stub-pair memory and stub-pair index given the global
// index initially stored in iSP.
template<uint8_t NSPMem> void
TC::getIndices(
    const BXType bx,
    const StubPairMemory stubPairs[NSPMem],
    TC::Types::nSPMem &iSPMem,
    TC::Types::nSP &iSP,
    bool &done
)
{
  bool set = false;

  iSPMem = 0;
  done = false;

  index: for (TC::Types::nSPMem j = 0; j < NSPMem; j++) {
    if (!set && iSP >= stubPairs[j].getEntries(bx))
      iSP -= stubPairs[j].getEntries(bx), iSPMem++;
    else
      set = true;
  }

  done = !set || iSPMem >= NSPMem;
}

// Processes a given stub pair and writes the calculated tracklet parameters
// and tracklet projections to the appropriate memories.
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion, uint32_t TPROJMaskBarrel, uint32_t TPROJMaskDisk> void
TC::processStubPair(
    const BXType bx,
    const StubPair::SPInnerIndex innerIndex,
    const AllStub<InnerRegion> &innerStub,
    const StubPair::SPOuterIndex outerIndex,
    const AllStub<OuterRegion> &outerStub,
    const TrackletProjection<BARRELPS>::TProjTCID TCID,
    TrackletProjection<BARRELPS>::TProjTrackletIndex &trackletIndex,
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[N_PROJOUT_DISK],
    int &npar,
    int nproj_barrel_ps[N_PROJOUT_BARRELPS],
    int nproj_barrel_2s[N_PROJOUT_BARREL2S],
    int nproj_disk[N_PROJOUT_DISK]
)
{
  TC::Types::rinv rinv;
  TrackletParameters::PHI0PAR phi0;
  TC::Types::z0 z0;
  TrackletParameters::TPAR t;
  TC::Types::phiL phiL[N_LAYER - 2];
  TC::Types::zL zL[N_LAYER - 2];
  TC::Types::der_phiL der_phiL;
  TC::Types::der_zL der_zL;
  TC::Types::flag valid_proj[N_LAYER - 2];
  TC::Types::phiD phiD[N_DISK - 1];
  TC::Types::rD rD[N_DISK - 1];
  TC::Types::der_phiD der_phiD;
  TC::Types::der_rD der_rD;
  TC::Types::flag valid_proj_disk[N_DISK - 1];
  bool success;

// Calculate the tracklet parameters and projections.
  success = TC::barrelSeeding<Seed, InnerRegion, OuterRegion>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);

// Write the tracklet parameters and projections to the output memories.
  const TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
  if (success) trackletParameters->write_mem(bx, tpar, npar++);

  bool addL3 = false, addL4 = false, addL5 = false, addL6 = false;

  switch (Seed) {
    case TF::L1L2:
      {
        const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);

        addL3 = TC::addProj<BARRELPS, nproj_L3, ((TPROJMaskBarrel & mask_L3) >> shift_L3)> (tproj_L3, bx, &projout_barrel_ps[L3PHIA], &nproj_barrel_ps[L3PHIA], success && valid_proj[0]);
        addL4 = TC::addProj<BARREL2S, nproj_L4, ((TPROJMaskBarrel & mask_L4) >> shift_L4)> (tproj_L4, bx, &projout_barrel_2s[L4PHIA], &nproj_barrel_2s[L4PHIA], success && valid_proj[1]);
        addL5 = TC::addProj<BARREL2S, nproj_L5, ((TPROJMaskBarrel & mask_L5) >> shift_L5)> (tproj_L5, bx, &projout_barrel_2s[L5PHIA], &nproj_barrel_2s[L5PHIA], success && valid_proj[2]);
        addL6 = TC::addProj<BARREL2S, nproj_L6, ((TPROJMaskBarrel & mask_L6) >> shift_L6)> (tproj_L6, bx, &projout_barrel_2s[L6PHIA], &nproj_barrel_2s[L6PHIA], success && valid_proj[3]);
      }

      break;

    case TF::L3L4:
      {
        const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
        const TrackletProjection<BARRELPS> tproj_L2(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);

        TC::addProj<BARRELPS, nproj_L1, ((TPROJMaskBarrel & mask_L1) >> shift_L1)> (tproj_L1, bx, &projout_barrel_ps[L1PHIA], &nproj_barrel_ps[L1PHIA], success && valid_proj[0]);
        TC::addProj<BARRELPS, nproj_L2, ((TPROJMaskBarrel & mask_L2) >> shift_L2)> (tproj_L2, bx, &projout_barrel_ps[L2PHIA], &nproj_barrel_ps[L2PHIA], success && valid_proj[1]);
        addL3 = addL4 = true;
        addL5 = TC::addProj<BARREL2S, nproj_L5, ((TPROJMaskBarrel & mask_L5) >> shift_L5)> (tproj_L5, bx, &projout_barrel_2s[L5PHIA], &nproj_barrel_2s[L5PHIA], success && valid_proj[2]);
        addL6 = TC::addProj<BARREL2S, nproj_L6, ((TPROJMaskBarrel & mask_L6) >> shift_L6)> (tproj_L6, bx, &projout_barrel_2s[L6PHIA], &nproj_barrel_2s[L6PHIA], success && valid_proj[3]);
      }

      break;

    case TF::L5L6:
      {
        const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
        const TrackletProjection<BARRELPS> tproj_L2(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
        const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);

        TC::addProj<BARRELPS, nproj_L1, ((TPROJMaskBarrel & mask_L1) >> shift_L1)> (tproj_L1, bx, &projout_barrel_ps[L1PHIA], &nproj_barrel_ps[L1PHIA], success && valid_proj[0]);
        TC::addProj<BARRELPS, nproj_L2, ((TPROJMaskBarrel & mask_L2) >> shift_L2)> (tproj_L2, bx, &projout_barrel_ps[L2PHIA], &nproj_barrel_ps[L2PHIA], success && valid_proj[1]);
        addL3 = TC::addProj<BARRELPS, nproj_L3, ((TPROJMaskBarrel & mask_L3) >> shift_L3)> (tproj_L3, bx, &projout_barrel_ps[L3PHIA], &nproj_barrel_ps[L3PHIA], success && valid_proj[2]);
        addL4 = TC::addProj<BARREL2S, nproj_L4, ((TPROJMaskBarrel & mask_L4) >> shift_L4)> (tproj_L4, bx, &projout_barrel_2s[L4PHIA], &nproj_barrel_2s[L4PHIA], success && valid_proj[3]);
        addL5 = addL6 = true;
      }

      break;
  }

  const TrackletProjection<DISK> tproj_D1(TCID, trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
  const TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
  const TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, phiD[2], rD[2], der_phiD, der_rD);
  const TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, phiD[3], rD[3], der_phiD, der_rD);

  TC::addProj<DISK, nproj_D1, ((TPROJMaskDisk & mask_D1) >> shift_D1)> (tproj_D1, bx, &projout_disk[D1PHIA], &nproj_disk[D1PHIA], success && valid_proj_disk[0] && !addL6);
  TC::addProj<DISK, nproj_D2, ((TPROJMaskDisk & mask_D2) >> shift_D2)> (tproj_D2, bx, &projout_disk[D2PHIA], &nproj_disk[D2PHIA], success && valid_proj_disk[1] && !addL5);
  TC::addProj<DISK, nproj_D3, ((TPROJMaskDisk & mask_D3) >> shift_D3)> (tproj_D3, bx, &projout_disk[D3PHIA], &nproj_disk[D3PHIA], success && valid_proj_disk[2] && !addL4);
  TC::addProj<DISK, nproj_D4, ((TPROJMaskDisk & mask_D4) >> shift_D4)> (tproj_D4, bx, &projout_disk[D4PHIA], &nproj_disk[D4PHIA], success && valid_proj_disk[3] && !addL3);

  if (success) trackletIndex++;
}

// This is the primary interface for the TrackletCalculator.
template<
TF::seed Seed, // seed layer combination (TF::L1L2, TF::L3L4, etc.)
TC::itc iTC, // letter at the end of the TC name (TC_L1L2A and TC_L5L6A have
             // the same iTC); generally indicates the region of the phi sector
             // being processed
regionType InnerRegion, // region type of the inner stubs
regionType OuterRegion, // region type of the outer stubs
uint8_t NASMemInner, // number of inner all-stub memories
uint8_t NASMemOuter, // number of outer all-stub memories
uint8_t NSPMem // number of stub-pair memories
> void
TrackletCalculator(
    const BXType bx,
    const AllStubMemory<InnerRegion> innerStubs[NASMemInner],
    const AllStubMemory<OuterRegion> outerStubs[NASMemOuter],
    const StubPairMemory stubPairs[NSPMem],
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
)
{
  static_assert(Seed == TF::L1L2 || Seed == TF::L3L4 || Seed == TF::L5L6, "Only L1L2, L3L4, and L5L6 seeds have been implemented so far.");

  int npar;
  int nproj_barrel_ps[TC::N_PROJOUT_BARRELPS];
  int nproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
  int nproj_disk[TC::N_PROJOUT_DISK];
#pragma HLS array_partition variable=nproj_barrel_ps complete
#pragma HLS array_partition variable=nproj_barrel_2s complete
#pragma HLS array_partition variable=nproj_disk complete

  TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex;

  const TrackletProjection<BARRELPS>::TProjTCID TCID = TC::ID<Seed, iTC>();

// Loop over all stub pairs.
  stub_pairs: for (TC::Types::nSP i = 0; i < kMaxProc - kMaxProcOffset(module::TC); i++) {
#pragma HLS pipeline II=1 rewind

// The first iteration is sacrificed to clearing the output memories and
// zeroing the number of tracklets and projections. Therefore, only
// kMaxProc - 1 iterations are actually used for processing stub pairs.
    if (i == 0) {
      npar = 0;
      memset(nproj_barrel_ps, 0, sizeof(int) * TC::N_PROJOUT_BARRELPS);
      memset(nproj_barrel_2s, 0, sizeof(int) * TC::N_PROJOUT_BARREL2S);
      memset(nproj_disk, 0, sizeof(int) * TC::N_PROJOUT_DISK);

      trackletParameters->clear(bx);
      clear_barrel_ps: for (unsigned j = 0; j < TC::N_PROJOUT_BARRELPS; j++)
        if (TPROJMaskBarrel<Seed, iTC>() & (0x1 << j))
          projout_barrel_ps[j].clear(bx);
      clear_barrel_2s: for (unsigned j = 0; j < TC::N_PROJOUT_BARREL2S; j++)
        if (TPROJMaskBarrel<Seed, iTC>() & (0x1 << (j + TC::N_PROJOUT_BARRELPS)))
          projout_barrel_2s[j].clear(bx);
      clear_disk: for (unsigned j = 0; j < TC::N_PROJOUT_DISK; j++)
        if (TPROJMaskDisk<Seed, iTC>() & (0x1 << j))
          projout_disk[j].clear(bx);

      trackletIndex = 0;
    }
    else {
      TC::Types::nSPMem iSPMem;
      TC::Types::nSP iSP = i - 1;
      bool done;
      TC::getIndices<NSPMem>(bx, stubPairs, iSPMem, iSP, done);

      if (!done) {
// Retrieve the inner and outer stubs for this stub pair, determining which
// all-stubs memory to use based on iSPMem:
        const StubPair::SPInnerIndex innerIndex = stubPairs[iSPMem].read_mem(bx, iSP).getInnerIndex();
        const StubPair::SPOuterIndex outerIndex = stubPairs[iSPMem].read_mem(bx, iSP).getOuterIndex();
        const AllStub<InnerRegion> &innerStub = innerStubs[(ASInnerMask<Seed, iTC>() & (1 << iSPMem)) >> iSPMem].read_mem(bx, innerIndex);
        const AllStub<OuterRegion> &outerStub = outerStubs[(ASOuterMask<Seed, iTC>() & (1 << iSPMem)) >> iSPMem].read_mem(bx, outerIndex);

        TC::processStubPair<Seed, InnerRegion, OuterRegion, TPROJMaskBarrel<Seed, iTC>(), TPROJMaskDisk<Seed, iTC>()>(bx, innerIndex, innerStub, outerIndex, outerStub, TCID, trackletIndex, trackletParameters, projout_barrel_ps, projout_barrel_2s, projout_disk, npar, nproj_barrel_ps, nproj_barrel_2s, nproj_disk);
      }
    }
  }
}

#endif
