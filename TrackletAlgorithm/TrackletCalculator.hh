#pragma once

#include "StubPairMemory.hh"
#include "AllStubMemory.hh"
#include "TrackletParameterMemory.hh"
#include "TrackletProjectionMemory.hh"

namespace TC {
////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////
  namespace Types {
    typedef ap_uint<4> iTC;
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
  enum layer {L1 = 0, L2 = 1, L3 = 2, L4 = 3, L5 = 4, L6 = 5};
  enum disk {D1 = 0, D2 = 1, D3 = 2, D4 = 3, D5 = 4};

  static const uint8_t kNInnerStubMems = 2;
  static const uint8_t kNOuterStubMems = 1;

  static const ap_uint<13> rinvcut = 5718;
  static const ap_uint<9> z0cut = 256;

  static const Types::rmean RMEAN[6] = {858, 1279, 1795, 2347, 2937, 3783};
  static const Types::zmean ZMEAN[5] = {2239, 2645, 3163, 3782, 4523};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Functions that are defined in TC_L1L2.cpp and TrackletCalculator.cpp.
////////////////////////////////////////////////////////////////////////////////
  void
  TC_L1L2(
    const AllStub::ASR r1_input,
    const AllStub::ASPHI phi1_input,
    const AllStub::ASZ z1_input,
    const AllStub::ASR r2_input,
    const AllStub::ASPHI phi2_input,
    const AllStub::ASZ z2_input,
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

  template<seed Seed> bool barrelSeeding(const AllStub &innerStub, const AllStub &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);

  template<seed Seed> const TrackletProjection<INNER>::TProjTCID ID(const Types::iTC iTC);

  template<tProjType TProjType> bool addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID);

  template<uint8_t NSPMem00, uint8_t NSPMem10> void
  getIndices(
      const BXType bx,
      const StubPairMemory stubPairs00[NSPMem00],
      const StubPairMemory stubPairs10[NSPMem10],
      Types::nASMem &iASMemInner,
      Types::nASMem &iASMemOuter,
      Types::nSPMem &iSPMem,
      Types::nSP &iSP,
      bool &done
  );

  template<seed Seed> void
  processStubPair(
      const BXType bx,
      const StubPair::SPInnerIndex innerIndex,
      const AllStub &innerStub,
      const StubPair::SPOuterIndex outerIndex,
      const AllStub &outerStub,
      const TrackletProjection<INNER>::TProjTCID TCID,
      TrackletParameterMemory * const trackletParameters,
      TrackletProjectionMemory<INNER> * const projout_L3PHIA,
      TrackletProjectionMemory<INNER> * const projout_L3PHIB,
      TrackletProjectionMemory<INNER> * const projout_L3PHIC,
      TrackletProjectionMemory<INNER> * const projout_L3PHID,
      TrackletProjectionMemory<OUTER> * const projout_L4PHIA,
      TrackletProjectionMemory<OUTER> * const projout_L4PHIB,
      TrackletProjectionMemory<OUTER> * const projout_L4PHIC,
      TrackletProjectionMemory<OUTER> * const projout_L4PHID,
      TrackletProjectionMemory<OUTER> * const projout_L5PHIA,
      TrackletProjectionMemory<OUTER> * const projout_L5PHIB,
      TrackletProjectionMemory<OUTER> * const projout_L5PHIC,
      TrackletProjectionMemory<OUTER> * const projout_L5PHID,
      TrackletProjectionMemory<OUTER> * const projout_L6PHIA,
      TrackletProjectionMemory<OUTER> * const projout_L6PHIB,
      TrackletProjectionMemory<OUTER> * const projout_L6PHIC,
      TrackletProjectionMemory<OUTER> * const projout_L6PHID,
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
  ) {}
}

template<uint8_t NSPMem00, uint8_t NSPMem10> void
TrackletCalculator_L1L2(
    const BXType bx,
    const TC::Types::iTC iTC,
    const AllStubMemory innerStubs[TC::kNInnerStubMems],
    const AllStubMemory outerStubs[TC::kNOuterStubMems],
    const StubPairMemory stubPairs00[NSPMem00],
    const StubPairMemory stubPairs10[NSPMem10],
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<INNER> * const projout_L3PHIA,
    TrackletProjectionMemory<INNER> * const projout_L3PHIB,
    TrackletProjectionMemory<INNER> * const projout_L3PHIC,
    TrackletProjectionMemory<INNER> * const projout_L3PHID,
    TrackletProjectionMemory<OUTER> * const projout_L4PHIA,
    TrackletProjectionMemory<OUTER> * const projout_L4PHIB,
    TrackletProjectionMemory<OUTER> * const projout_L4PHIC,
    TrackletProjectionMemory<OUTER> * const projout_L4PHID,
    TrackletProjectionMemory<OUTER> * const projout_L5PHIA,
    TrackletProjectionMemory<OUTER> * const projout_L5PHIB,
    TrackletProjectionMemory<OUTER> * const projout_L5PHIC,
    TrackletProjectionMemory<OUTER> * const projout_L5PHID,
    TrackletProjectionMemory<OUTER> * const projout_L6PHIA,
    TrackletProjectionMemory<OUTER> * const projout_L6PHIB,
    TrackletProjectionMemory<OUTER> * const projout_L6PHIC,
    TrackletProjectionMemory<OUTER> * const projout_L6PHID,
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

void TrackletCalculator_L1L2_5_8(
    const BXType bx,
    const TC::Types::iTC iTC,
    const AllStubMemory innerStubs[TC::kNInnerStubMems],
    const AllStubMemory outerStubs[TC::kNOuterStubMems],
    const StubPairMemory stubPairs00[5],
    const StubPairMemory stubPairs10[8],
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory<INNER> * const projout_L3PHIA,
    TrackletProjectionMemory<INNER> * const projout_L3PHIB,
    TrackletProjectionMemory<INNER> * const projout_L3PHIC,
    TrackletProjectionMemory<INNER> * const projout_L3PHID,
    TrackletProjectionMemory<OUTER> * const projout_L4PHIA,
    TrackletProjectionMemory<OUTER> * const projout_L4PHIB,
    TrackletProjectionMemory<OUTER> * const projout_L4PHIC,
    TrackletProjectionMemory<OUTER> * const projout_L4PHID,
    TrackletProjectionMemory<OUTER> * const projout_L5PHIA,
    TrackletProjectionMemory<OUTER> * const projout_L5PHIB,
    TrackletProjectionMemory<OUTER> * const projout_L5PHIC,
    TrackletProjectionMemory<OUTER> * const projout_L5PHID,
    TrackletProjectionMemory<OUTER> * const projout_L6PHIA,
    TrackletProjectionMemory<OUTER> * const projout_L6PHIB,
    TrackletProjectionMemory<OUTER> * const projout_L6PHIC,
    TrackletProjectionMemory<OUTER> * const projout_L6PHID,
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
////////////////////////////////////////////////////////////////////////////////
