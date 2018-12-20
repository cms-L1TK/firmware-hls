#pragma once

#include "StubPairMemory.hh"
#include "AllStubMemory.hh"
#include "TrackletParameterMemory.hh"
#include "TrackletProjectionMemory.hh"

////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////
typedef ap_uint<4> TC_iTC;
typedef ap_int<13> TC_rmean;
typedef ap_int<14> TC_zmean;
typedef ap_int<15> TC_rinv;
typedef ap_uint<20> TC_phiL;
typedef ap_int<15> TC_zL;
typedef ap_int<11> TC_der_phiL;
typedef ap_int<10> TC_der_zL;
typedef ap_uint<16> TC_phiD;
typedef ap_int<14> TC_rD;
typedef ap_int<10> TC_der_phiD;
typedef ap_int<10> TC_der_rD;
typedef ap_uint<1> TC_flag;

enum seed {UNDEF_SEED, L1L2 = 0, L3L4 = 1, L5L6 = 2, D1D2 = 3, D3D4 = 4, L1D1 = 5, L2D1 = 6};
enum layer {L1 = 0, L2 = 1, L3 = 2, L4 = 3, L5 = 4, L6 = 5};
enum disk {D1 = 0, D2 = 1, D3 = 2, D4 = 3, D5 = 4};

static const unsigned kNInnerStubMems = 2;
static const unsigned kNOuterStubMems = 1;
static const unsigned kNStubPairMems = 16;

static const ap_uint<13> rinvcut = 5718;
static const ap_uint<9> z0cut = 256;

static const TC_rmean RMEAN[6] = {858, 1279, 1795, 2347, 2937, 3783};
static const TC_zmean ZMEAN[5] = {2239, 2645, 3163, 3782, 4523};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Functions that are defined in TC_L1L2.cpp and TrackletCalculator.cpp.
////////////////////////////////////////////////////////////////////////////////
void
TC_L1L2(
  const AllStub::ASR r1_wire,
  const AllStub::ASPHI phi1_wire,
  const AllStub::ASZ z1_wire,
  const AllStub::ASR r2_wire,
  const AllStub::ASPHI phi2_wire,
  const AllStub::ASZ z2_wire,
  const TC_rmean rproj0_wire,
  const TC_rmean rproj1_wire,
  const TC_rmean rproj2_wire,
  const TC_rmean rproj3_wire,
  const TC_zmean zproj0_wire,
  const TC_zmean zproj1_wire,
  const TC_zmean zproj2_wire,
  const TC_zmean zproj3_wire,

  TC_rinv * const rinv_final_wire,
  TrackletParameters::PHI0PAR * const phi0_final_wire,
  TrackletParameters::TPAR * const t_final_wire,
  TrackletParameters::Z0PAR * const z0_final_wire,
  TC_phiL * const phiL_0_final_wire,
  TC_phiL * const phiL_1_final_wire,
  TC_phiL * const phiL_2_final_wire,
  TC_phiL * const phiL_3_final_wire,
  TC_zL * const zL_0_final_wire,
  TC_zL * const zL_1_final_wire,
  TC_zL * const zL_2_final_wire,
  TC_zL * const zL_3_final_wire,
  TC_der_phiL * const der_phiL_final_wire,
  TC_der_zL * const der_zL_final_wire,
  TC_phiD * const phiD_0_final_wire,
  TC_phiD * const phiD_1_final_wire,
  TC_phiD * const phiD_2_final_wire,
  TC_phiD * const phiD_3_final_wire,
  TC_rD * const rD_0_final_wire,
  TC_rD * const rD_1_final_wire,
  TC_rD * const rD_2_final_wire,
  TC_rD * const rD_3_final_wire,
  TC_der_phiD * const der_phiD_final_wire,
  TC_der_rD * const der_rD_final_wire
);

template<seed Seed> bool TC_barrelSeeding(const AllStub &innerStub, const AllStub &outerStub, TC_rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t, TC_phiL phiL[4], TC_zL zL[4], TC_der_phiL * const der_phiL, TC_der_zL * const der_zL, TC_flag valid_proj[4], TC_phiD phiD[4], TC_rD rD[4], TC_der_phiD * const der_phiD, TC_der_rD * const der_rD, TC_flag valid_proj_disk[4]);

template<seed Seed> const TrackletProjection<INNER>::TProjTCID TC_ID(const TC_iTC iTC);

template<tProjType TProjType> bool addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID);

template<seed Seed> void
TrackletCalculator(
    const BXType bx,
    const TC_iTC iTC,
    const AllStubMemory innerStubs[kNInnerStubMems],
    const AllStubMemory outerStubs[kNOuterStubMems],
    const StubPairMemory stubPairs00[kNStubPairMems],
    const StubPairMemory stubPairs10[kNStubPairMems],
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

void TrackletCalculator_L1L2(
    const BXType bx,
    const TC_iTC iTC,
    const AllStubMemory innerStubs[kNInnerStubMems],
    const AllStubMemory outerStubs[kNOuterStubMems],
    const StubPairMemory stubPairs00[kNStubPairMems],
    const StubPairMemory stubPairs10[kNStubPairMems],
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
