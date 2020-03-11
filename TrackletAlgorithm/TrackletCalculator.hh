#pragma once

#include <cmath>

#include "StubPairMemory.hh"
#include "AllStubMemory.hh"
#include "TrackletParameterMemory.hh"
#include "TrackletProjectionMemory.hh"

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

  enum seed {UNDEF_SEED, L1L2 = 0, L3L4 = 1, L5L6 = 2, D1D2 = 3, D3D4 = 4, L1D1 = 5, L2D1 = 6};
  enum itc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
  enum layer {L1 = 0, L2 = 1, L3 = 2, L4 = 3, L5 = 4, L6 = 5};
  enum disk {D1 = 0, D2 = 1, D3 = 2, D4 = 3, D5 = 4};

  static const ap_uint<13> rinvcut = 5718;
  static const ap_uint<9> z0cut = 256;

  static const Types::rmean RMEAN[6] = {858, 1279, 1795, 2347, 2937, 3783};
  static const Types::zmean ZMEAN[5] = {2239, 2645, 3163, 3782, 4523};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Functions that are defined in TC_L1L2.cpp, TrackletCalculator.cpp, and the
// bottom of this file.
////////////////////////////////////////////////////////////////////////////////
  void
  TC_L1L2(
    const AllStub<BARRELPS>::ASR r1_input,
    const AllStub<BARRELPS>::ASPHI phi1_input,
    const AllStub<BARRELPS>::ASZ z1_input,
    const AllStub<BARRELPS>::ASR r2_input,
    const AllStub<BARRELPS>::ASPHI phi2_input,
    const AllStub<BARRELPS>::ASZ z2_input,
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
    TrackletParameters::Z0PAR * const z0_output,
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

  template<seed Seed> bool barrelSeeding(const AllStub<BARRELPS> &innerStub, const AllStub<BARRELPS> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);

  template<seed Seed, itc iTC> const TrackletProjection<BARRELPS>::TProjTCID ID();

  template<regionType TProjType, uint32_t TPROJMask> bool addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID, int &nproj_PHIA, int &nproj_PHIB, int &nproj_PHIC, int &nproj_PHID, const bool success);

  template<uint8_t NSPMem> void
  getIndices(
      const BXType bx,
      const StubPairMemory stubPairs[NSPMem],
      TC::Types::nSPMem &iSPMem,
      TC::Types::nSP &iSP,
      bool &done
  );

  template<seed Seed, uint32_t TPROJMask> void
  processStubPair(
      const BXType bx,
      const StubPair::SPInnerIndex innerIndex,
      const AllStub<BARRELPS> &innerStub,
      const StubPair::SPOuterIndex outerIndex,
      const AllStub<BARRELPS> &outerStub,
      const TrackletProjection<BARRELPS>::TProjTCID TCID,
      TrackletProjection<BARRELPS>::TProjTrackletIndex &trackletIndex,
      TrackletParameterMemory * const trackletParameters,
      TrackletProjectionMemory<BARRELPS> * const projout_L3PHIA,
      TrackletProjectionMemory<BARRELPS> * const projout_L3PHIB,
      TrackletProjectionMemory<BARRELPS> * const projout_L3PHIC,
      TrackletProjectionMemory<BARRELPS> * const projout_L3PHID,
      TrackletProjectionMemory<BARREL2S> * const projout_L4PHIA,
      TrackletProjectionMemory<BARREL2S> * const projout_L4PHIB,
      TrackletProjectionMemory<BARREL2S> * const projout_L4PHIC,
      TrackletProjectionMemory<BARREL2S> * const projout_L4PHID,
      TrackletProjectionMemory<BARREL2S> * const projout_L5PHIA,
      TrackletProjectionMemory<BARREL2S> * const projout_L5PHIB,
      TrackletProjectionMemory<BARREL2S> * const projout_L5PHIC,
      TrackletProjectionMemory<BARREL2S> * const projout_L5PHID,
      TrackletProjectionMemory<BARREL2S> * const projout_L6PHIA,
      TrackletProjectionMemory<BARREL2S> * const projout_L6PHIB,
      TrackletProjectionMemory<BARREL2S> * const projout_L6PHIC,
      TrackletProjectionMemory<BARREL2S> * const projout_L6PHID,
      TrackletProjectionMemory<DISK> * const projout_D1PHIA,
      TrackletProjectionMemory<DISK> * const projout_D1PHIB,
      TrackletProjectionMemory<DISK> * const projout_D1PHIC,
      TrackletProjectionMemory<DISK> * const projout_D1PHID,
      TrackletProjectionMemory<DISK> * const projout_D2PHIA,
      TrackletProjectionMemory<DISK> * const projout_D2PHIB,
      TrackletProjectionMemory<DISK> * const projout_D2PHIC,
      TrackletProjectionMemory<DISK> * const projout_D2PHID,
      TrackletProjectionMemory<DISK> * const projout_D3PHIA,
      TrackletProjectionMemory<DISK> * const projout_D3PHIB,
      TrackletProjectionMemory<DISK> * const projout_D3PHIC,
      TrackletProjectionMemory<DISK> * const projout_D3PHID,
      TrackletProjectionMemory<DISK> * const projout_D4PHIA,
      TrackletProjectionMemory<DISK> * const projout_D4PHIB,
      TrackletProjectionMemory<DISK> * const projout_D4PHIC,
      TrackletProjectionMemory<DISK> * const projout_D4PHID,
      int &npar,
      int &nproj_L3PHIA,
      int &nproj_L3PHIB,
      int &nproj_L3PHIC,
      int &nproj_L3PHID,
      int &nproj_L4PHIA,
      int &nproj_L4PHIB,
      int &nproj_L4PHIC,
      int &nproj_L4PHID,
      int &nproj_L5PHIA,
      int &nproj_L5PHIB,
      int &nproj_L5PHIC,
      int &nproj_L5PHID,
      int &nproj_L6PHIA,
      int &nproj_L6PHIB,
      int &nproj_L6PHIC,
      int &nproj_L6PHID,
      int &nproj_D1PHIA,
      int &nproj_D1PHIB,
      int &nproj_D1PHIC,
      int &nproj_D1PHID,
      int &nproj_D2PHIA,
      int &nproj_D2PHIB,
      int &nproj_D2PHIC,
      int &nproj_D2PHID,
      int &nproj_D3PHIA,
      int &nproj_D3PHIB,
      int &nproj_D3PHIC,
      int &nproj_D3PHID,
      int &nproj_D4PHIA,
      int &nproj_D4PHIB,
      int &nproj_D4PHIC,
      int &nproj_D4PHID
  );

  template<uint32_t TPROJMask, class T> void clearMemories(const BXType bx, T mem);
  template<uint32_t TPROJMask, class T, class... Args> void clearMemories(const BXType bx, T mem, Args... args);
}

template<TC::itc iTC, uint8_t NASMemInner, uint8_t NASMemOuter, uint8_t NSPMem, uint16_t ASInnerMask, uint16_t ASOuterMask, uint32_t TPROJMask, uint16_t N> void
TrackletCalculator_L1L2(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[NASMemInner],
    const AllStubMemory<BARRELPS> outerStubs[NASMemOuter],
    const StubPairMemory stubPairs[NSPMem],
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIA,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIB,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIC,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHID,
    TrackletProjectionMemory<DISK> * const projout_D1PHIA,
    TrackletProjectionMemory<DISK> * const projout_D1PHIB,
    TrackletProjectionMemory<DISK> * const projout_D1PHIC,
    TrackletProjectionMemory<DISK> * const projout_D1PHID,
    TrackletProjectionMemory<DISK> * const projout_D2PHIA,
    TrackletProjectionMemory<DISK> * const projout_D2PHIB,
    TrackletProjectionMemory<DISK> * const projout_D2PHIC,
    TrackletProjectionMemory<DISK> * const projout_D2PHID,
    TrackletProjectionMemory<DISK> * const projout_D3PHIA,
    TrackletProjectionMemory<DISK> * const projout_D3PHIB,
    TrackletProjectionMemory<DISK> * const projout_D3PHIC,
    TrackletProjectionMemory<DISK> * const projout_D3PHID,
    TrackletProjectionMemory<DISK> * const projout_D4PHIA,
    TrackletProjectionMemory<DISK> * const projout_D4PHIB,
    TrackletProjectionMemory<DISK> * const projout_D4PHIC,
    TrackletProjectionMemory<DISK> * const projout_D4PHID
);

void TrackletCalculator_L1L2E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<BARRELPS> outerStubs[1],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIA,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIA,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIA,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIC,
    TrackletProjectionMemory<DISK> * projout_D1PHIA,
    TrackletProjectionMemory<DISK> * projout_D1PHIB,
    TrackletProjectionMemory<DISK> * projout_D1PHIC,
    TrackletProjectionMemory<DISK> * projout_D2PHIA,
    TrackletProjectionMemory<DISK> * projout_D2PHIB,
    TrackletProjectionMemory<DISK> * projout_D2PHIC,
    TrackletProjectionMemory<DISK> * projout_D3PHIA,
    TrackletProjectionMemory<DISK> * projout_D3PHIB,
    TrackletProjectionMemory<DISK> * projout_D3PHIC,
    TrackletProjectionMemory<DISK> * projout_D4PHIA,
    TrackletProjectionMemory<DISK> * projout_D4PHIB,
    TrackletProjectionMemory<DISK> * projout_D4PHIC
);

void TrackletCalculator_L1L2G(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<BARRELPS> outerStubs[2],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHIB,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHID,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHID,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHID,
    TrackletProjectionMemory<DISK> * projout_D1PHIB,
    TrackletProjectionMemory<DISK> * projout_D1PHIC,
    TrackletProjectionMemory<DISK> * projout_D1PHID,
    TrackletProjectionMemory<DISK> * projout_D2PHIB,
    TrackletProjectionMemory<DISK> * projout_D2PHIC,
    TrackletProjectionMemory<DISK> * projout_D2PHID,
    TrackletProjectionMemory<DISK> * projout_D3PHIB,
    TrackletProjectionMemory<DISK> * projout_D3PHIC,
    TrackletProjectionMemory<DISK> * projout_D3PHID,
    TrackletProjectionMemory<DISK> * projout_D4PHIB,
    TrackletProjectionMemory<DISK> * projout_D4PHIC,
    TrackletProjectionMemory<DISK> * projout_D4PHID
);

////////////////////////////////////////////////////////////////////////////////

// This function calls TC_L1L2, defined in TC_L1L2.cpp, and applies cuts to the
// results.
template<TC::seed Seed> bool
TC::barrelSeeding(const AllStub<BARRELPS> &innerStub, const AllStub<BARRELPS> &outerStub, TC::Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t, TC::Types::phiL phiL[4], TC::Types::zL zL[4], TC::Types::der_phiL * const der_phiL, TC::Types::der_zL * const der_zL, TC::Types::flag valid_proj[4], TC::Types::phiD phiD[4], TC::Types::rD rD[4], TC::Types::der_phiD * const der_phiD, TC::Types::der_rD * const der_rD, TC::Types::flag valid_proj_disk[4])
{
  static_assert(Seed == TC::L1L2, "Only L1L2 has been implemented so far.");

  TC::Types::rmean rproj[4] = {RMEAN[L3], RMEAN[L4], RMEAN[L5], RMEAN[L6]};
  TC::Types::zmean zproj[4] = {ZMEAN[D1], ZMEAN[D2], ZMEAN[D3], ZMEAN[D4]};
  TC_L1L2(
      innerStub.getR(),
      innerStub.getPhi(),
      innerStub.getZ(),
      outerStub.getR(),
      outerStub.getPhi(),
      outerStub.getZ(),
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
  valid_proj: for (ap_uint<3> i = 0; i < 4; i++) {
    valid_proj[i] = true;
    if (zL[i] < -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (zL[i] >= (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (phiL[i] >= ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1)) {
      phiL[i] = ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 2);
      valid_proj[i] = false;
    }
    if (rproj[i] < 2048) {
      phiL[i] >>= (TrackletProjection<BARREL2S>::kTProjPhiSize - TrackletProjection<BARRELPS>::kTProjPhiSize);
      if (phiL[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1)
        phiL[i] = (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 2;
    }
    else
      zL[i] >>= (TrackletProjection<BARRELPS>::kTProjRZSize - TrackletProjection<BARREL2S>::kTProjRZSize);
    if (phiL[i] <= 0) {
      phiL[i] = 1;
      valid_proj[i] = false;
    }
  }

// Determine which disk projections are valid.
  valid_proj_disk: for (ap_uint<3> i = 0; i < 4; i++) {
    valid_proj_disk[i] = true;
    if (abs(*t) < 512)
      valid_proj_disk[i] = false;
    if (phiD[i] < 0) {
      phiD[i] = 0;
      valid_proj_disk[i] = false;
    }
    if (phiD[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize)) {
      phiD[i] = (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1;
      valid_proj_disk[i] = false;
    }
    if (rD[i] < 342 || rD[i] > 2048) {
      valid_proj_disk[i] = false;
      phiD[i] = 0;
      rD[i] = 0;
    }
  }

// Reject tracklets with too high a curvature or with too large a longitudinal
// impact parameter.
  bool success = true;
  if (abs(*rinv) > rinvcut)
    success = false;
  if (abs(*z0) > z0cut)
    success = false;

  const ap_int<TrackletParameters::kTParPhi0Size + 2> phicrit = *phi0 - (*rinv<<1);
  const bool keep = (phicrit > 9253) && (phicrit < 56269);
  success = success && keep;

  return success;
}

template<TC::seed Seed, TC::itc iTC> const TrackletProjection<BARRELPS>::TProjTCID
TC::ID()
{
  return ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << 4) + iTC);
}

template<regionType TProjType, uint32_t TPROJMask> bool
TC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID, int &nproj_PHIA, int &nproj_PHIB, int &nproj_PHIC, int &nproj_PHID, const bool success)
{
  bool proj_success = true;

// Reject projections with extreme r/z values.
  if (TProjType != DISK) {
    if ((proj.getRZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getRZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1))))
      proj_success = false;
    if (abs(proj.getRZ()) > 2048)
      proj_success = false;
  }
  else {
    if (proj.getRZ() < 205 || proj.getRZ() > 1911)
      proj_success = false;
  }

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  TC::Types::phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);
  phi >>= 3;

  if (TPROJMask & 0x1 && success && proj_success && phi == 0) projout_PHIA->write_mem(bx, proj, nproj_PHIA++);
  if (TPROJMask & 0x2 && success && proj_success && phi == 1) projout_PHIB->write_mem(bx, proj, nproj_PHIB++);
  if (TPROJMask & 0x4 && success && proj_success && phi == 2) projout_PHIC->write_mem(bx, proj, nproj_PHIC++);
  if (TPROJMask & 0x8 && success && proj_success && phi == 3) projout_PHID->write_mem(bx, proj, nproj_PHID++);

  return (success && proj_success);
}

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

// Determine the correct stub-pair memory and stub-pair index given the global
// index initially stored in iSP.
  index: for (TC::Types::nSPMem j = 0; j < NSPMem; j++) {
    if (!set && iSP >= stubPairs[j].getEntries(bx))
      iSP -= stubPairs[j].getEntries(bx), iSPMem++;
    else
      set = true;
  }

  done = !set || iSPMem >= NSPMem;
}

template<TC::seed Seed, uint32_t TPROJMask> void
TC::processStubPair(
    const BXType bx,
    const StubPair::SPInnerIndex innerIndex,
    const AllStub<BARRELPS> &innerStub,
    const StubPair::SPOuterIndex outerIndex,
    const AllStub<BARRELPS> &outerStub,
    const TrackletProjection<BARRELPS>::TProjTCID TCID,
    TrackletProjection<BARRELPS>::TProjTrackletIndex &trackletIndex,
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIA,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIB,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIC,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHID,
    TrackletProjectionMemory<DISK> * const projout_D1PHIA,
    TrackletProjectionMemory<DISK> * const projout_D1PHIB,
    TrackletProjectionMemory<DISK> * const projout_D1PHIC,
    TrackletProjectionMemory<DISK> * const projout_D1PHID,
    TrackletProjectionMemory<DISK> * const projout_D2PHIA,
    TrackletProjectionMemory<DISK> * const projout_D2PHIB,
    TrackletProjectionMemory<DISK> * const projout_D2PHIC,
    TrackletProjectionMemory<DISK> * const projout_D2PHID,
    TrackletProjectionMemory<DISK> * const projout_D3PHIA,
    TrackletProjectionMemory<DISK> * const projout_D3PHIB,
    TrackletProjectionMemory<DISK> * const projout_D3PHIC,
    TrackletProjectionMemory<DISK> * const projout_D3PHID,
    TrackletProjectionMemory<DISK> * const projout_D4PHIA,
    TrackletProjectionMemory<DISK> * const projout_D4PHIB,
    TrackletProjectionMemory<DISK> * const projout_D4PHIC,
    TrackletProjectionMemory<DISK> * const projout_D4PHID,
    int &npar,
    int &nproj_L3PHIA,
    int &nproj_L3PHIB,
    int &nproj_L3PHIC,
    int &nproj_L3PHID,
    int &nproj_L4PHIA,
    int &nproj_L4PHIB,
    int &nproj_L4PHIC,
    int &nproj_L4PHID,
    int &nproj_L5PHIA,
    int &nproj_L5PHIB,
    int &nproj_L5PHIC,
    int &nproj_L5PHID,
    int &nproj_L6PHIA,
    int &nproj_L6PHIB,
    int &nproj_L6PHIC,
    int &nproj_L6PHID,
    int &nproj_D1PHIA,
    int &nproj_D1PHIB,
    int &nproj_D1PHIC,
    int &nproj_D1PHID,
    int &nproj_D2PHIA,
    int &nproj_D2PHIB,
    int &nproj_D2PHIC,
    int &nproj_D2PHID,
    int &nproj_D3PHIA,
    int &nproj_D3PHIB,
    int &nproj_D3PHIC,
    int &nproj_D3PHID,
    int &nproj_D4PHIA,
    int &nproj_D4PHIB,
    int &nproj_D4PHIC,
    int &nproj_D4PHID
)
{

  static_assert(Seed == TC::L1L2, "Only L1L2 has been implemented so far.");

  TC::Types::rinv rinv;
  TrackletParameters::PHI0PAR phi0;
  TrackletParameters::Z0PAR z0;
  TrackletParameters::TPAR t;
  TC::Types::phiL phiL[4];
  TC::Types::zL zL[4];
  TC::Types::der_phiL der_phiL;
  TC::Types::der_zL der_zL;
  TC::Types::flag valid_proj[4];
  TC::Types::phiD phiD[4];
  TC::Types::rD rD[4];
  TC::Types::der_phiD der_phiD;
  TC::Types::der_rD der_rD;
  TC::Types::flag valid_proj_disk[4];
  bool success;

// Calculate the tracklet parameters and projections.
  success = TC::barrelSeeding<Seed>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);

// Write the tracklet parameters and projections to the output memories.
  const TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
  if (success) trackletParameters->write_mem(bx, tpar, npar++);

  bool addL3 = false, addL4 = false, addL5 = false, addL6 = false;

  const TrackletProjection<BARRELPS> tproj_L3(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
  const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
  const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
  const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);

  addL3 = TC::addProj<BARRELPS, ((TPROJMask & 0x0000000F) >> 0)> (tproj_L3, bx, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID, nproj_L3PHIA, nproj_L3PHIB, nproj_L3PHIC, nproj_L3PHID, success && valid_proj[0]);
  addL4 = TC::addProj<BARREL2S, ((TPROJMask & 0x000000F0) >> 4)> (tproj_L4, bx, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID, nproj_L4PHIA, nproj_L4PHIB, nproj_L4PHIC, nproj_L4PHID, success && valid_proj[1]);
  addL5 = TC::addProj<BARREL2S, ((TPROJMask & 0x00000F00) >> 8)> (tproj_L5, bx, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID, nproj_L5PHIA, nproj_L5PHIB, nproj_L5PHIC, nproj_L5PHID, success && valid_proj[2]);
  addL6 = TC::addProj<BARREL2S, ((TPROJMask & 0x0000F000) >> 12)>(tproj_L6, bx, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID, nproj_L6PHIA, nproj_L6PHIB, nproj_L6PHIC, nproj_L6PHID, success && valid_proj[3]);

  TrackletProjection<DISK> tproj_D1(TCID, trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
  TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
  TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, phiD[2], rD[2], der_phiD, der_rD);
  TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, phiD[3], rD[3], der_phiD, der_rD);

  TC::addProj<DISK, ((TPROJMask & 0x000F0000) >> 16)>(tproj_D1, bx, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID, nproj_D1PHIA, nproj_D1PHIB, nproj_D1PHIC, nproj_D1PHID, success && valid_proj_disk[0] && !addL6);
  TC::addProj<DISK, ((TPROJMask & 0x00F00000) >> 20)>(tproj_D2, bx, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID, nproj_D2PHIA, nproj_D2PHIB, nproj_D2PHIC, nproj_D2PHID, success && valid_proj_disk[1] && !addL5);
  TC::addProj<DISK, ((TPROJMask & 0x0F000000) >> 24)>(tproj_D3, bx, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID, nproj_D3PHIA, nproj_D3PHIB, nproj_D3PHIC, nproj_D3PHID, success && valid_proj_disk[2] && !addL4);
  TC::addProj<DISK, ((TPROJMask & 0xF0000000) >> 28)>(tproj_D4, bx, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID, nproj_D4PHIA, nproj_D4PHIB, nproj_D4PHIC, nproj_D4PHID, success && valid_proj_disk[3] && !addL3);

  if (success) trackletIndex++;
}

template<uint32_t TPROJMask, class T> void
TC::clearMemories(const BXType bx, T mem)
{
  if (TPROJMask & 0x1) mem->clear(bx);
}

template<uint32_t TPROJMask, class T, class... Args> void
TC::clearMemories(const BXType bx, T mem, Args... args)
{
  if (TPROJMask & 0x1) mem->clear(bx);
  clearMemories<(TPROJMask >> 1)>(bx, args...);
}

// This is the primary interface for the TrackletCalculator.
template<TC::itc iTC, uint8_t NASMemInner, uint8_t NASMemOuter, uint8_t NSPMem, uint16_t ASInnerMask, uint16_t ASOuterMask, uint32_t TPROJMask, uint16_t N> void
TrackletCalculator_L1L2(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[NASMemInner],
    const AllStubMemory<BARRELPS> outerStubs[NASMemOuter],
    const StubPairMemory stubPairs[NSPMem],
    TrackletParameterMemory * const trackletParameters,

// The validity of each of the TPROJ memories is determined by TPROJMask. The
// bits of this mask, from least significant to most significant, correspond to
// the memories in the order they are passed to TrackletCalculator_L1L2; i.e.,
// the LSB corresponds to projout_L3PHIA and the MSB corresponds to
// projout_D4PHID.  If a bit is set, the corresponding memory is valid, if it
// is not, the corresponding memory is not valid.
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIA,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIB,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHIC,
    TrackletProjectionMemory<BARRELPS> * const projout_L3PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L4PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L5PHID,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIA,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIB,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHIC,
    TrackletProjectionMemory<BARREL2S> * const projout_L6PHID,
    TrackletProjectionMemory<DISK> * const projout_D1PHIA,
    TrackletProjectionMemory<DISK> * const projout_D1PHIB,
    TrackletProjectionMemory<DISK> * const projout_D1PHIC,
    TrackletProjectionMemory<DISK> * const projout_D1PHID,
    TrackletProjectionMemory<DISK> * const projout_D2PHIA,
    TrackletProjectionMemory<DISK> * const projout_D2PHIB,
    TrackletProjectionMemory<DISK> * const projout_D2PHIC,
    TrackletProjectionMemory<DISK> * const projout_D2PHID,
    TrackletProjectionMemory<DISK> * const projout_D3PHIA,
    TrackletProjectionMemory<DISK> * const projout_D3PHIB,
    TrackletProjectionMemory<DISK> * const projout_D3PHIC,
    TrackletProjectionMemory<DISK> * const projout_D3PHID,
    TrackletProjectionMemory<DISK> * const projout_D4PHIA,
    TrackletProjectionMemory<DISK> * const projout_D4PHIB,
    TrackletProjectionMemory<DISK> * const projout_D4PHIC,
    TrackletProjectionMemory<DISK> * const projout_D4PHID
)
{
  int npar = 0;
  int nproj_L3PHIA = 0;
  int nproj_L3PHIB = 0;
  int nproj_L3PHIC = 0;
  int nproj_L3PHID = 0;
  int nproj_L4PHIA = 0;
  int nproj_L4PHIB = 0;
  int nproj_L4PHIC = 0;
  int nproj_L4PHID = 0;
  int nproj_L5PHIA = 0;
  int nproj_L5PHIB = 0;
  int nproj_L5PHIC = 0;
  int nproj_L5PHID = 0;
  int nproj_L6PHIA = 0;
  int nproj_L6PHIB = 0;
  int nproj_L6PHIC = 0;
  int nproj_L6PHID = 0;
  int nproj_D1PHIA = 0;
  int nproj_D1PHIB = 0;
  int nproj_D1PHIC = 0;
  int nproj_D1PHID = 0;
  int nproj_D2PHIA = 0;
  int nproj_D2PHIB = 0;
  int nproj_D2PHIC = 0;
  int nproj_D2PHID = 0;
  int nproj_D3PHIA = 0;
  int nproj_D3PHIB = 0;
  int nproj_D3PHIC = 0;
  int nproj_D3PHID = 0;
  int nproj_D4PHIA = 0;
  int nproj_D4PHIB = 0;
  int nproj_D4PHIC = 0;
  int nproj_D4PHID = 0;

// Clear all output memories before starting.
  trackletParameters->clear(bx);
  TC::clearMemories<TPROJMask>(bx, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);

  TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex = 0;

  TC::Types::nSPMem iSPMem;
  TC::Types::nSP iSP;
  bool done;

  StubPair::SPInnerIndex innerIndex;
  StubPair::SPOuterIndex outerIndex;
  const TrackletProjection<BARRELPS>::TProjTCID TCID = TC::ID<TC::L1L2, iTC>();

// Loop over all stub pairs.
  stub_pairs: for (TC::Types::nSP i = 0; i < N; i++) {
#pragma HLS pipeline II=1

    iSP = i;
    TC::getIndices<NSPMem>(bx, stubPairs, iSPMem, iSP, done);

    if (!done) {
// Retrieve the inner and outer stubs for this stub pair, determining which
// all-stubs memory to use based on iSPMem:
      innerIndex = stubPairs[iSPMem].read_mem(bx, iSP).getInnerIndex();
      outerIndex = stubPairs[iSPMem].read_mem(bx, iSP).getOuterIndex();
      const AllStub<BARRELPS> &innerStub = innerStubs[(ASInnerMask & (1 << iSPMem)) >> iSPMem].read_mem(bx, innerIndex);
      const AllStub<BARRELPS> &outerStub = outerStubs[(ASOuterMask & (1 << iSPMem)) >> iSPMem].read_mem(bx, outerIndex);

      TC::processStubPair<TC::L1L2, TPROJMask>(bx, innerIndex, innerStub, outerIndex, outerStub, TCID, trackletIndex, trackletParameters, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID, npar, nproj_L3PHIA, nproj_L3PHIB, nproj_L3PHIC, nproj_L3PHID, nproj_L4PHIA, nproj_L4PHIB, nproj_L4PHIC, nproj_L4PHID, nproj_L5PHIA, nproj_L5PHIB, nproj_L5PHIC, nproj_L5PHID, nproj_L6PHIA, nproj_L6PHIB, nproj_L6PHIC, nproj_L6PHID, nproj_D1PHIA, nproj_D1PHIB, nproj_D1PHIC, nproj_D1PHID, nproj_D2PHIA, nproj_D2PHIB, nproj_D2PHIC, nproj_D2PHID, nproj_D3PHIA, nproj_D3PHIB, nproj_D3PHIC, nproj_D3PHID, nproj_D4PHIA, nproj_D4PHIB, nproj_D4PHIC, nproj_D4PHID);
    }
  }
}
