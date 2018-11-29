#pragma once

#include "StubPairMemory.hh"
#include "AllStubMemory.hh"
#include "TrackletParameterMemory.hh"
#include "TrackletProjectionMemory.hh"

////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////
typedef ap_int<13> TC_rmean;
typedef ap_int<14> TC_zmean;
typedef ap_int<20> TC_phiL;
typedef ap_int<15> TC_zL;
typedef ap_int<9> TC_der_phiL;
typedef ap_int<10> TC_der_zL;
typedef ap_int<16> TC_phiD;
typedef ap_int<14> TC_rD;
typedef ap_int<10> TC_der_phiD;
typedef ap_int<8> TC_der_rD;
typedef ap_uint<1> TC_flag;

enum seed {UNDEF_SEED, L1L2, L3L4, L5L6, D1D2, D3D4, D1L1, D1L2, L1D1, L2D1};
enum layer {L1 = 0, L2 = 1, L3 = 2, L4 = 3, L5 = 4, L6 = 5};
enum disk {D1 = 0, D2 = 1, D3 = 2, D4 = 3, D5 = 4};

static const unsigned kNInnerStubMems = 2;
static const unsigned kNOuterStubMems = 1;
static const unsigned kNStubPairMems = 16;

static const ap_uint<13> rinvcut = 5718;
static const ap_uint<9> z0cut = 256;

static const TC_rmean RMEAN[6] = {1795, 2347, 2937, 3783};
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
  const TC_zmean zproj4_wire,

  TrackletParameters::RINVPAR * const rinv_final_wire,
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
  TC_phiD * const phiD_4_final_wire,
  TC_rD * const rD_0_final_wire,
  TC_rD * const rD_1_final_wire,
  TC_rD * const rD_2_final_wire,
  TC_rD * const rD_3_final_wire,
  TC_rD * const rD_4_final_wire,
  TC_der_phiD * const der_phiD_final_wire,
  TC_der_rD * const der_rD_final_wire,
  TC_flag * const valid_trackpar_wire,
  TC_flag * const valid_phiL_0_wire,
  TC_flag * const valid_phiL_1_wire,
  TC_flag * const valid_phiL_2_wire,
  TC_flag * const valid_phiL_3_wire,
  TC_flag * const valid_zL_0_wire,
  TC_flag * const valid_zL_1_wire,
  TC_flag * const valid_zL_2_wire,
  TC_flag * const valid_zL_3_wire,
  TC_flag * const valid_der_phiL_wire,
  TC_flag * const valid_der_zL_wire,
  TC_flag * const valid_phiD_0_wire,
  TC_flag * const valid_phiD_1_wire,
  TC_flag * const valid_phiD_2_wire,
  TC_flag * const valid_phiD_3_wire,
  TC_flag * const valid_phiD_4_wire,
  TC_flag * const valid_rD_0_wire,
  TC_flag * const valid_rD_1_wire,
  TC_flag * const valid_rD_2_wire,
  TC_flag * const valid_rD_3_wire,
  TC_flag * const valid_rD_4_wire,
  TC_flag * const valid_der_phiD_wire,
  TC_flag * const valid_der_rD_wire
);

template<seed Seed> bool
TC_barrelSeeding(const AllStub &innerStub, const AllStub &outerStub, TrackletParameters::RINVPAR * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t) {}

template<seed Seed> void
TrackletCalculator(
    BXType bx,
    const AllStubMemory innerStubs[kNInnerStubMems],
    const AllStubMemory outerStubs[kNOuterStubMems],
    const StubPairMemory stubPairs00[kNStubPairMems],
    const StubPairMemory stubPairs10[kNStubPairMems],
    TrackletParameterMemory * const trackletParameters,
    TrackletProjectionMemory * const projout_L1PHIA,
    TrackletProjectionMemory * const projout_L1PHIB,
    TrackletProjectionMemory * const projout_L1PHIC,
    TrackletProjectionMemory * const projout_L1PHID,
    TrackletProjectionMemory * const projout_L1PHIE,
    TrackletProjectionMemory * const projout_L1PHIF,
    TrackletProjectionMemory * const projout_L1PHIG,
    TrackletProjectionMemory * const projout_L1PHIH,
    TrackletProjectionMemory * const projout_L2PHIA,
    TrackletProjectionMemory * const projout_L2PHIB,
    TrackletProjectionMemory * const projout_L2PHIC,
    TrackletProjectionMemory * const projout_L2PHID,
    TrackletProjectionMemory * const projout_L3PHIA,
    TrackletProjectionMemory * const projout_L3PHIB,
    TrackletProjectionMemory * const projout_L3PHIC,
    TrackletProjectionMemory * const projout_L3PHID,
    TrackletProjectionMemory * const projout_L4PHIA,
    TrackletProjectionMemory * const projout_L4PHIB,
    TrackletProjectionMemory * const projout_L4PHIC,
    TrackletProjectionMemory * const projout_L4PHID,
    TrackletProjectionMemory * const projout_L5PHIA,
    TrackletProjectionMemory * const projout_L5PHIB,
    TrackletProjectionMemory * const projout_L5PHIC,
    TrackletProjectionMemory * const projout_L5PHID,
    TrackletProjectionMemory * const projout_L6PHIA,
    TrackletProjectionMemory * const projout_L6PHIB,
    TrackletProjectionMemory * const projout_L6PHIC,
    TrackletProjectionMemory * const projout_L6PHID,
    TrackletProjectionMemory * const projout_D1PHIA,
    TrackletProjectionMemory * const projout_D1PHIB,
    TrackletProjectionMemory * const projout_D1PHIC,
    TrackletProjectionMemory * const projout_D1PHID,
    TrackletProjectionMemory * const projout_D2PHIA,
    TrackletProjectionMemory * const projout_D2PHIB,
    TrackletProjectionMemory * const projout_D2PHIC,
    TrackletProjectionMemory * const projout_D2PHID,
    TrackletProjectionMemory * const projout_D3PHIA,
    TrackletProjectionMemory * const projout_D3PHIB,
    TrackletProjectionMemory * const projout_D3PHIC,
    TrackletProjectionMemory * const projout_D3PHID,
    TrackletProjectionMemory * const projout_D4PHIA,
    TrackletProjectionMemory * const projout_D4PHIB,
    TrackletProjectionMemory * const projout_D4PHIC,
    TrackletProjectionMemory * const projout_D4PHID,
    TrackletProjectionMemory * const projout_D5PHIA,
    TrackletProjectionMemory * const projout_D5PHIB,
    TrackletProjectionMemory * const projout_D5PHIC,
    TrackletProjectionMemory * const projout_D5PHID
) {}
////////////////////////////////////////////////////////////////////////////////
