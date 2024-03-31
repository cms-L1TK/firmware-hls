#ifndef TrackletAlgorithm_TrackletProcessor_h
#define TrackletAlgorithm_TrackletProcessor_h

#include <cmath>

#include "Constants.h"
#include "AllStubMemory.h"
#include "AllStubInnerMemory.h"
#include "TrackletParameterMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubTEOuterMemoryCM.h"
#include "TEBuffer.h"
#include "TrackletEngineUnit.h"
#include "TrackletProcessor_parameters.h"
#include "TrackletLUTs.h"

namespace TC {
////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////
  namespace Types {
    typedef ap_uint<2> nASMem;

    typedef ap_int<13> rmean;
    typedef ap_int<14> zmean;
    typedef ap_int<15> rinv;
    typedef ap_int<12> z0;
    typedef ap_uint<20> phiL;
    typedef ap_int<15> zL;
    typedef ap_int<11> der_phiL;
    typedef ap_int<10> der_zL;
    typedef ap_uint<16> phiD;
    typedef ap_uint<14> rD;
    typedef ap_int<10> der_phiD;
    typedef ap_int<10> der_rD;
    typedef ap_uint<1> flag;
  }

  enum projout_index_barrel_ps {L1PHIA = 0, L1PHIB = 1, L1PHIC = 2, L1PHID = 3, L1PHIE = 4, L1PHIF = 5, L1PHIG = 6, L1PHIH = 7, L2PHIA = 8, L2PHIB = 9, L2PHIC = 10, L2PHID = 11, L3PHIA = 12, L3PHIB = 13, L3PHIC = 14, L3PHID = 15, N_PROJOUT_BARRELPS = 16};
  enum projout_index_barrel_2s {L4PHIA = 0, L4PHIB = 1, L4PHIC = 2, L4PHID = 3, L5PHIA = 4, L5PHIB = 5, L5PHIC = 6, L5PHID = 7, L6PHIA = 8, L6PHIB = 9, L6PHIC = 10, L6PHID = 11, N_PROJOUT_BARREL2S = 12};
  enum projout_index_disk      {D1PHIA = 0, D1PHIB = 1, D1PHIC = 2, D1PHID = 3, D2PHIA = 4, D2PHIB = 5, D2PHIC = 6, D2PHID = 7, D3PHIA = 8, D3PHIB = 9, D3PHIC = 10, D3PHID = 11, D4PHIA = 12, D4PHIB = 13, D4PHIC = 14, D4PHID = 15, D5PHIA = 16, D5PHIB = 17, D5PHIC = 18, D5PHID = 19, N_PROJOUT_DISK = 20};

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
  static const uint8_t nproj_D5 = D5PHID - D5PHIA + 1;

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
  static const uint8_t shift_D5 = shift_D4 + nproj_D4;

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
  static const uint32_t mask_D5 = 0xF << shift_D5;

  constexpr int itcut = floatToInt(1.0, kt);
  constexpr int irinvcut = floatToInt(rinvcut, krinv);
  constexpr int iz0cut = floatToInt(z0cut, kz0);
  constexpr int izmaxcut = floatToInt(zlength, kz); 
  constexpr int irprojmincut = floatToInt(rmindisk, krprojdisk); 
  constexpr int irprojmaxcut = floatToInt(rmaxdisk, krprojdisk); 



////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Functions that are defined in TrackletCalculator_calculate_LXLY.h,
// TrackletProcessor.cc, and the bottom of this file.
////////////////////////////////////////////////////////////////////////////////
  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
  void calculate_LXLY (
    const typename AllStub<InnerRegion>::ASR r1_input,
    const typename AllStub<InnerRegion>::ASPHI phi1_input,
    const typename AllStub<InnerRegion>::ASZ z1_input,
    const typename AllStub<OuterRegion>::ASR r2_input,
    const typename AllStub<OuterRegion>::ASPHI phi2_input,
    const typename AllStub<OuterRegion>::ASZ z2_input,

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
  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
  void calculate_LXD1 (
    const typename AllStub<InnerRegion>::ASR r1_input,
    const typename AllStub<InnerRegion>::ASPHI phi1_input,
    const typename AllStub<InnerRegion>::ASZ z1_input,
    const typename AllStub<OuterRegion>::ASR r2_input,
    const typename AllStub<OuterRegion>::ASPHI phi2_input,
    const typename AllStub<OuterRegion>::ASZ z2_input,

    bool * const valid_radii,
    Types::rinv * const rinv_output,
    TrackletParameters::PHI0PAR * const phi0_output,
    TrackletParameters::TPAR * const t_output,
    Types::z0 * const z0_output,
    Types::phiL * const phiL_0_output,
    Types::phiL * const phiL_1_output,
    Types::phiL * const phiL_2_output,
    Types::zL * const zL_0_output,
    Types::zL * const zL_1_output,
    Types::zL * const zL_2_output,
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
  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion>
  void calculate_DXDY (
    const typename AllStub<InnerRegion>::ASR r1_input,
    const typename AllStub<InnerRegion>::ASPHI phi1_input,
    const typename AllStub<InnerRegion>::ASZ z1_input,
    const typename AllStub<OuterRegion>::ASR r2_input,
    const typename AllStub<OuterRegion>::ASPHI phi2_input,
    const typename AllStub<OuterRegion>::ASZ z2_input,
    const bool negDisk,

    Types::rinv * const rinv_output,
    TrackletParameters::PHI0PAR * const phi0_output,
    TrackletParameters::TPAR * const t_output,
    Types::z0 * const z0_output,
    Types::phiL * const phiL_0_output,
    Types::phiL * const phiL_1_output,
    Types::phiL * const phiL_2_output,
    Types::zL * const zL_0_output,
    Types::zL * const zL_1_output,
    Types::zL * const zL_2_output,
    Types::der_phiL * const der_phiL_output,
    Types::der_zL * const der_zL_output,
    Types::phiD * const phiD_0_output,
    Types::phiD * const phiD_1_output,
    Types::phiD * const phiD_2_output,
    Types::rD * const rD_0_output,
    Types::rD * const rD_1_output,
    Types::rD * const rD_2_output,
    Types::der_phiD * const der_phiD_output,
    Types::der_rD * const der_rD_output
  );
  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion> bool barrelSeeding(const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, Types::z0 * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);
  template<TF::seed Seed,regionType InnerRegion, regionType OuterRegion> bool overlapSeeding(const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, Types::z0 * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);
  template<TF::seed Seed,regionType InnerRegion, regionType OuterRegion> bool diskSeeding(const bool negDisk, const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, Types::z0 * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4]);

  template<TF::seed Seed, itc iTC> const TrackletProjection<BARRELPS>::TProjTCID ID();

  template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], int nproj[NProjOut], const bool success);

  template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion, uint32_t TPROJMaskBarrel, uint32_t TPROJMaskDisk> void
    processStubPair(
		    const BXType bx,
		    const ap_uint<TrackletParameters::kTParPhiRegionSize> phiRegion,
		    const ap_uint<kNBits_MemAddr> innerIndex,
		    const AllStub<InnerRegion> &innerStub,
		    const ap_uint<kNBits_MemAddr>  outerIndex,
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
		    int nproj_disk[N_PROJOUT_DISK],
        bool negDisk = false
		    );


}

#include "TrackletCalculator_calculate.h"

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
template<TF::seed Seed> constexpr TF::layerDisk OuterLayerDisk() {
  return (
    (Seed == TF::L1L2 ? TF::L2 : (Seed == TF::L2L3 ? TF::L3 : (Seed == TF::L3L4 ? TF::L4 : (Seed == TF::L5L6 ? TF::L6 :
    (Seed == TF::D1D2 ? TF::D2 : (Seed == TF::D3D4 ? TF::D4 : TF::D1))))))
  );
}
// Constants used in TE functions assigned to constants here for readability, do not depend on template parameters
const int kNBufferDepthBits = TEBuffer<TF::L1L2,C,BARRELPS,BARRELPS>::kNBufferDepthBits;
const int kNBitsBuffer = TrackletEngineUnit<TF::L1L2,C,BARRELPS,BARRELPS>::kNBitsBuffer;
// TE functions that used to live in top file
inline ap_uint<1> nearFullTEBuff(const ap_uint<kNBufferDepthBits>& writeptr,
        const ap_uint<kNBufferDepthBits>& readptr) {
  ap_uint<3> writeptr1=writeptr+1;
  ap_uint<3> writeptr2=writeptr+2;
  ap_uint<3> writeptr3=writeptr+3;
  ap_uint<1> result=writeptr1==readptr||writeptr2==readptr||writeptr3==readptr;
  return result;
}
inline ap_uint<(1<<(2*kNBitsBuffer))> nearFullTEUnitInit() {
  ap_uint<(1<<(2*kNBitsBuffer))> lut(0);
  int i;
  for(i=0;i<(1<<(2*kNBitsBuffer));i++) {
    ap_uint<kNBitsBuffer> wptr,rptr;
    ap_uint<2*kNBitsBuffer> address(i);
    (rptr,wptr)=address;
    ap_uint<kNBitsBuffer> wptr1=wptr+1;
    ap_uint<kNBitsBuffer> wptr2=wptr+2;
    ap_uint<kNBitsBuffer> wptr3=wptr+3;
    ap_uint<1> result=wptr1==rptr||wptr2==rptr||wptr3==rptr;
    lut[i]=result;
  }
  return lut;
 }

////////////////////////////////////////////////////////////////////////////////

// This function calls calculate_LXLY, defined in
// TrackletCalculator_calculate_LXLY.h, and applies cuts to the results.
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion> bool
TC::barrelSeeding(const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, TC::Types
::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TC::Types::z0 * const z0, TrackletParameters::TPAR * const t, TC::Types::phiL phiL[4], TC::Types::zL zL[4], TC::Types::der_phiL * const der_phiL, TC::Types::der_zL * const der_zL, TC::Types::flag valid_proj[4], TC::Types::phiD phiD[4], TC::Types::rD rD[4], TC::Types::der_phiD * const der_phiD, TC::Types::der_rD * const der_rD, TC::Types::flag valid_proj_disk[4])
{
  calculate_LXLY<Seed, InnerRegion, OuterRegion>(
      innerStub.getR(),
      innerStub.getPhi(),
      innerStub.getZ(),
      outerStub.getR(),
      outerStub.getPhi(),
      outerStub.getZ(),

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
#pragma HLS unroll

    bool valid_zmin=zL[i] >= -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    bool valid_zmax=zL[i] < (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    bool valid_phimax=phiL[i] < ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1);
    bool valid_phimin=phiL[i] > 0;

    valid_proj[i] = valid_zmin && valid_zmax && valid_phimax && valid_phimin;

    if (projectionLayers[Seed][i]<=TF::L3) {
      phiL[i] >>= (TrackletProjection<BARREL2S>::kTProjPhiSize - TrackletProjection<BARRELPS>::kTProjPhiSize);
      if (phiL[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1)
        phiL[i] = (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 2;
    }
    else
      zL[i] >>= (TrackletProjection<BARRELPS>::kTProjRZSize - TrackletProjection<BARREL2S>::kTProjRZSize);
  }

// Determine which disk projections are valid.
  valid_proj_disk: for (ap_uint<3> i = 0; i < 4; i++) {
#pragma HLS unroll
    bool valid_t=abs(*t)>itcut;
    bool valid_phimin=phiD[i]>0;
    bool valid_phimax=phiD[i]<(1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1;
    bool valid_r=rD[i] >= irprojmincut && rD[i] < irprojmaxcut;
    valid_proj_disk[i] = valid_t && valid_phimin && valid_phimax && valid_r;

  }
// Reject tracklets with too high a curvature or with too large a longitudinal
// impact parameter.

  bool valid_rinv=abs(*rinv) < floatToInt(rinvcut, krinv);
  bool valid_z0=abs(*z0) < ((Seed == TF::L1L2) ? floatToInt(z0cut, kz0) : floatToInt(1.5*z0cut,kz0));

  const ap_int<TrackletParameters::kTParPhi0Size + 2> phicrit = *phi0 - (*rinv>>8)*ifactor;
  const bool keep = (phicrit > phicritmincut) && (phicrit < phicritmaxcut);

  return valid_rinv && valid_z0 && keep;
}


template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion> bool
TC::diskSeeding(const bool negDisk, const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, TC::Types
::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TC::Types::z0 * const z0, TrackletParameters::TPAR * const t, TC::Types::phiL phiL[4], TC::Types::zL zL[4], TC::Types::der_phiL * const der_phiL, TC::Types::der_zL * const der_zL, TC::Types::flag valid_proj[4], TC::Types::phiD phiD[4], TC::Types::rD rD[4], TC::Types::der_phiD * const der_phiD, TC::Types::der_rD * const der_rD, TC::Types::flag valid_proj_disk[4])
{
  calculate_DXDY<Seed, InnerRegion, OuterRegion>(
      innerStub.getR(),
      innerStub.getPhi(),
      innerStub.getZ(),
      outerStub.getR(),
      outerStub.getPhi(),
      outerStub.getZ(),
      negDisk,

      rinv,
      phi0,
      t,
      z0,
      &phiL[0],
      &phiL[1],
      &phiL[2],
      &zL[0],
      &zL[1],
      &zL[2],
      der_phiL,
      der_zL,
      &phiD[0],
      &phiD[1],
      &phiD[2],
      &rD[0],
      &rD[1],
      &rD[2],
      der_phiD,
      der_rD
  );
// Determine which layer projections are valid.
  valid_proj: for (ap_uint<3> i = 0; i < trklet::N_LAYER - 2; i++) {
    valid_proj[i] = true;
    if (zL[i] < -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (zL[i] >= (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (phiL[i] >= ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1))
      valid_proj[i] = false;
    if (phiL[i] <= 0)
      valid_proj[i] = false;
    phiL[i] >>= (TrackletProjection<BARREL2S>::kTProjPhiSize - TrackletProjection<BARRELPS>::kTProjPhiSize);
    if (phiL[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1)
      phiL[i] = (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 2;
  }


// Determine which disk projections are valid.
  valid_proj_disk: for (ap_uint<3> i = 0; i < 4; i++) {
#pragma HLS unroll
    bool valid_t=abs(*t)>itcut;
    bool valid_phimin=phiD[i]>0;
    bool valid_phimax=phiD[i]<(1 << TrackletProjection<DISK>::kTProjPhiSize) - 1;
    bool valid_r=rD[i] >= irprojmincut && rD[i] < irprojmaxcut;
    valid_proj_disk[i] = valid_t && valid_phimin && valid_phimax && valid_r;
  }
// Reject tracklets with too high a curvature or with too large a longitudinal
// impact parameter.
  bool valid_rinv=abs(*rinv) < floatToInt(rinvcut, krinv);
  bool valid_z0= abs(*z0) < floatToInt(z0cut, kz0);

  const ap_int<TrackletParameters::kTParPhi0Size + 2> phicrit = *phi0 - (*rinv>>8)*ifactor;
  const bool keep = (phicrit > phicritmincut) && (phicrit < phicritmaxcut);

  return valid_rinv && valid_z0 && keep;
}

// This function calls calculate_LXD1, defined in
// TrackletCalculator_calculate_LXD1.h, and applies cuts to the results.
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion> bool
TC::overlapSeeding(const AllStub<InnerRegion> &innerStub, const AllStub<OuterRegion> &outerStub, TC::Types
::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TC::Types::z0 * const z0, TrackletParameters::TPAR * const t, TC::Types::phiL phiL[4], TC::Types::zL zL[4], TC::Types::der_phiL * const der_phiL, TC::Types::der_zL * const der_zL, TC::Types::flag valid_proj[4], TC::Types::phiD phiD[4], TC::Types::rD rD[4], TC::Types::der_phiD * const der_phiD, TC::Types::der_rD * const der_rD, TC::Types::flag valid_proj_disk[4])
{
  bool valid_radii;
  calculate_LXD1<Seed, InnerRegion, DISKPS>(
      innerStub.getR(),
      innerStub.getPhi(),
      innerStub.getZ(),
      outerStub.getR(),
      outerStub.getPhi(),
      outerStub.getZ(),

      &valid_radii,
      rinv,
      phi0,
      t,
      z0,
      &phiL[0],
      &phiL[1],
      &phiL[2],
      &zL[0],
      &zL[1],
      &zL[2],
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
// Determine which layer projections are valid
  valid_proj: for (ap_uint<3> i = 0; i < 4; i++) {
#pragma HLS unroll

    bool valid_zmin=zL[i] >= -(1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    bool valid_zmax=zL[i] < (1 << (TrackletProjection<BARRELPS>::kTProjRZSize - 1));
    bool valid_phimax=phiL[i] < ((1 << TrackletProjection<BARREL2S>::kTProjPhiSize) - 1);
    bool valid_phimin=phiL[i] > 0;

    valid_proj[i] = valid_zmin && valid_zmax && valid_phimax && valid_phimin;

    phiL[i] >>= (TrackletProjection<BARREL2S>::kTProjPhiSize - TrackletProjection<BARRELPS>::kTProjPhiSize);
    if (phiL[i] >= (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 1)
      phiL[i] = (1 << TrackletProjection<BARRELPS>::kTProjPhiSize) - 2;
  }

// Determine which disk projections are valid.
 valid_proj_disk: for (ap_uint<3> i = 0; i < 4; i++) {
#pragma HLS unroll
    bool valid_t=abs(*t) > itcut;
    bool valid_phimin=phiD[i]>0;
    bool valid_phimax=phiD[i]<(1 << TrackletProjection<DISK>::kTProjPhiSize) - 1;
    bool valid_r=rD[i] >= irprojmincut && rD[i] < irprojmaxcut;
    valid_proj_disk[i] = valid_t && valid_phimin && valid_phimax && valid_r;
  }
// Reject tracklets with too high a curvature or with too large a longitudinal
// impact parameter.

  bool valid_rinv=abs(*rinv) < irinvcut;
  bool valid_z0=abs(*z0) < iz0cut;

  const ap_int<TrackletParameters::kTParPhi0Size + 2> phicrit = *phi0 - (*rinv>>8)*ifactor;
  const bool keep = (phicrit > phicritmincut) && (phicrit < phicritmaxcut);

  return valid_rinv && valid_z0 && keep && valid_radii;
}


// Returns a unique identifier assigned to each TC.
template<TF::seed Seed, itc iTC> const TrackletProjection<BARRELPS>::TProjTCID
ID()
{
  return ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << 4) + iTC);
}

// Writes a tracklet projection to the appropriate tracklet projection memory.
template<regionType TProjType, uint8_t NProjOut, uint32_t TPROJMask> bool
TC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> projout[NProjOut], int nproj[NProjOut], const bool success)
{
  bool proj_success = true;

// Reject projections with extreme r/z values.
  if (TProjType != DISK) {
    if ((proj.getZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1)))) {
      proj_success = false;
    }
    if (abs(proj.getZ()) > izmaxcut) {
      proj_success = false;
    }
  }
  else {
    if (proj.getR() < irprojmincut || proj.getR() >= irprojmaxcut)
      proj_success = false;
  }
  TC::Types::phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  if (TProjType == BARRELPS && NProjOut == nproj_L1)
    phi >>= 2;
  else
    phi >>= 3;

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

// Processes a given stub pair and writes the calculated tracklet parameters
// and tracklet projections to the appropriate memories.
template<TF::seed Seed, regionType InnerRegion, regionType OuterRegion, uint32_t TPROJMaskBarrel, uint32_t TPROJMaskDisk> void
TC::processStubPair(
    const BXType bx,
    const ap_uint<TrackletParameters::kTParPhiRegionSize> phiRegion,
    const ap_uint<kNBits_MemAddr> innerIndex,
    const AllStub<InnerRegion> &innerStub,
    const ap_uint<kNBits_MemAddr>  outerIndex,
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
    int nproj_disk[N_PROJOUT_DISK],
    bool negDisk
)
{
  TC::Types::rinv rinv;
  TrackletParameters::PHI0PAR phi0;
  TC::Types::z0 z0;
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
#pragma HLS array_partition variable=rD complete

  //std::cout << "barrelSeeding: innerStub phi z r : "<<innerStub.getPhi()<<" "<<innerStub.getZ()<<" "<<innerStub.getR()<<std::endl;
  //std::cout << "barrelSeeding: outerStub phi z r : "<<outerStub.getPhi()<<" "<<outerStub.getZ()<<" "<<outerStub.getR()<<std::endl;

// Calculate the tracklet parameters and projections.
  auto stubIndex1 = innerIndex;
  auto stubIndex2 =  outerIndex;

  if (Seed == TF::L1L2 || Seed == TF::L2L3 || Seed == TF::L3L4 || Seed == TF::L5L6)
    success = TC::barrelSeeding<Seed, InnerRegion, OuterRegion>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);
  else if (Seed == TF::L1D1 || Seed==TF::L2D1 ){
    success = TC::overlapSeeding<Seed, InnerRegion, OuterRegion>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);
    //stub indices are reversed on overlap seeds for some reason.
    stubIndex1 = outerIndex;
    stubIndex2 = innerIndex;
  }
  else //disk seeds
    success = TC::diskSeeding<Seed, InnerRegion, OuterRegion>(negDisk, innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);
  // Write the tracklet parameters and projections to the output memories.
  const TrackletParameters tpar(phiRegion, stubIndex1, stubIndex2, rinv, phi0, z0, t);
  if (success) trackletParameters->write_mem(bx, tpar, npar++);

bool addL3 = false, addL4 = false, addL5 = false, addL6 = false;
//Disk Seeds
  if (Seed == TF::D1D2){
    const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
    const TrackletProjection<BARRELPS> tproj_L2(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
    const TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
    const TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
    const TrackletProjection<DISK> tproj_D5(TCID, trackletIndex, phiD[2], rD[2], der_phiD, der_rD);

    TC::addProj<BARRELPS, nproj_L1, ((TPROJMaskBarrel & mask_L1) >> shift_L1)> (tproj_L1, bx, &projout_barrel_ps[L1PHIA], &nproj_barrel_ps[L1PHIA], success && valid_proj[0]);
    TC::addProj<BARRELPS, nproj_L2, ((TPROJMaskBarrel & mask_L2) >> shift_L2)> (tproj_L2, bx, &projout_barrel_ps[L2PHIA], &nproj_barrel_ps[L2PHIA], success && valid_proj[1]);
    TC::addProj<DISK, nproj_D3, ((TPROJMaskDisk & mask_D3) >> shift_D3)> (tproj_D3, bx, &projout_disk[D3PHIA], &nproj_disk[D3PHIA], success && valid_proj_disk[0]);
    TC::addProj<DISK, nproj_D4, ((TPROJMaskDisk & mask_D4) >> shift_D4)> (tproj_D4, bx, &projout_disk[D4PHIA], &nproj_disk[D4PHIA], success && valid_proj_disk[1]);
    TC::addProj<DISK, nproj_D5, ((TPROJMaskDisk & mask_D5) >> shift_D5)> (tproj_D5, bx, &projout_disk[D5PHIA], &nproj_disk[D5PHIA], success && valid_proj_disk[2]);
  }
  else if (Seed == TF::D3D4){
    const TrackletProjection<DISK> tproj_D1(TCID, trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
    const TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
    const TrackletProjection<DISK> tproj_D5(TCID, trackletIndex, phiD[2], rD[2], der_phiD, der_rD);
    const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
    TC::addProj<BARRELPS, nproj_L1, ((TPROJMaskBarrel & mask_L1) >> shift_L1)> (tproj_L1, bx, &projout_barrel_ps[L1PHIA], &nproj_barrel_ps[L1PHIA], success && valid_proj[0]);
    TC::addProj<DISK, nproj_D1, ((TPROJMaskDisk & mask_D1) >> shift_D1)> (tproj_D1, bx, &projout_disk[D1PHIA], &nproj_disk[D1PHIA], success && valid_proj_disk[0]);
    TC::addProj<DISK, nproj_D2, ((TPROJMaskDisk & mask_D2) >> shift_D2)> (tproj_D2, bx, &projout_disk[D2PHIA], &nproj_disk[D2PHIA], success && valid_proj_disk[0]);
    TC::addProj<DISK, nproj_D5, ((TPROJMaskDisk & mask_D5) >> shift_D5)> (tproj_D5, bx, &projout_disk[D5PHIA], &nproj_disk[D5PHIA], success && valid_proj_disk[1]);
  }
//Overlap Seeds
  else if (Seed >= TF::L1D1){
    const TrackletProjection<DISK> tproj_D2(TCID, trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
    const TrackletProjection<DISK> tproj_D3(TCID, trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
    const TrackletProjection<DISK> tproj_D4(TCID, trackletIndex, phiD[2], rD[2], der_phiD, der_rD);

    TC::addProj<DISK, nproj_D2, ((TPROJMaskDisk & mask_D2) >> shift_D2)> (tproj_D2, bx, &projout_disk[D2PHIA], &nproj_disk[D2PHIA], success && valid_proj_disk[0]);
    TC::addProj<DISK, nproj_D3, ((TPROJMaskDisk & mask_D3) >> shift_D3)> (tproj_D3, bx, &projout_disk[D3PHIA], &nproj_disk[D3PHIA], success && valid_proj_disk[1]);
    TC::addProj<DISK, nproj_D4, ((TPROJMaskDisk & mask_D4) >> shift_D4)> (tproj_D4, bx, &projout_disk[D4PHIA], &nproj_disk[D4PHIA], success && valid_proj_disk[2]);

    if (Seed == TF::L1D1){
      const TrackletProjection<DISK> tproj_D5(TCID, trackletIndex, phiD[3], rD[3], der_phiD, der_rD);
      TC::addProj<DISK, nproj_D5, ((TPROJMaskDisk & mask_D5) >> shift_D5)> (tproj_D5, bx, &projout_disk[D5PHIA], &nproj_disk[D5PHIA], success && valid_proj_disk[3]);
    }
    else if (Seed == TF::L2D1){
      const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
      TC::addProj<BARRELPS, nproj_L1, ((TPROJMaskBarrel & mask_L1) >> shift_L1)> (tproj_L1, bx, &projout_barrel_ps[L1PHIA], &nproj_barrel_ps[L1PHIA], success && valid_proj[0]);
    }
  }
//Barrel Seeds:
  else if (Seed <= TF::L5L6){
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
      case TF::L2L3:
        {
        const TrackletProjection<BARRELPS> tproj_L1(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L4(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L5(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
        const TrackletProjection<BARREL2S> tproj_L6(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);

        TC::addProj<BARRELPS, nproj_L1, ((TPROJMaskBarrel & mask_L1) >> shift_L1)> (tproj_L1, bx, &projout_barrel_ps[L1PHIA], &nproj_barrel_ps[L1PHIA], success && valid_proj[0]);
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
      default:
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
  }
  if (success) trackletIndex++;
}


#define LUTTYPE ap_uint<1+2*TrackletEngineUnit<Seed,iTC,InnerRegion<Seed>(), OuterRegion<Seed>()>::kNBitsRZFine+TrackletEngineUnit<Seed,iTC,InnerRegion<Seed>(),OuterRegion<Seed>()>::kNBitsRZBin>
#define lutsize  (1<<(kNbitszfinebintable+kNbitsrfinebintable))


// This is the primary interface for the TrackletProcessor.
template<
TF::seed Seed, // seed layer combination (TC::L1L2, TC::L3L4, etc.)
  itc iTC, // letter at the end of the TC name (TC_L1L2A and TC_L5L6A have the same iTC); generally indicates the region of the phi sector being processed
  uint8_t NVMSTECopy, // Number of VMSTE copies
  uint8_t NASMemInner, // Number of inner all-stub memories
  uint16_t N // maximum number of steps
> void
  TrackletProcessor(
		    const BXType bx,  BXType& bx_o, const LUTTYPE lut[lutsize], const AllStubInnerMemory<InnerRegion<Seed>()> innerStubs[NASMemInner], const AllStubMemory<OuterRegion<Seed>()>* outerStubs, const VMStubTEOuterMemoryCM<OuterRegion<Seed>(),kNbitsrzbin,kNbitsphibin,NVMSTECopy>* outerVMStubs, TrackletParameterMemory * const trackletParameters, TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS], TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S], TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
  )
{
  constexpr bool diskSeed = (Seed == TF::D1D2 || Seed == TF::D3D4);
  constexpr bool overlapSeed = (Seed == TF::L1D1 || Seed == TF::L2D1);
  constexpr bool L1InnerSeed = (Seed == TF::L1L2 || Seed == TF::L1D1) ;
  //AS Memories are cast from DISK into DISKPS types in overlap and disk seeds
  constexpr regionType innerASType = diskSeed ? DISKPS : InnerRegion<Seed>();
  constexpr regionType outerASType = (diskSeed || overlapSeed) ? DISKPS : OuterRegion<Seed>();
  int npar = 0;
  int nproj_barrel_ps[TC::N_PROJOUT_BARRELPS];
  int nproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
  int nproj_disk[TC::N_PROJOUT_DISK];
#pragma HLS array_partition variable=nproj_barrel_ps complete
#pragma HLS array_partition variable=nproj_barrel_2s complete
#pragma HLS array_partition variable=nproj_disk complete
#pragma HLS array_partition variable=innerStubs complete dim=1
  
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

  constexpr unsigned int NBitsPhiRegion = 2;
  constexpr int numTPs = (Seed == TF::L1L2) ? 12 : (Seed == TF::L1D1 ? 8 : 4 );
  constexpr int iAllstub = (iTC / (numTPs / 4) );

  
  const ap_uint<1>* stubptinnertmp = getPTInnerLUT<Seed,iTC>();
  static const TPRegionLUT<Seed> regionLUT(stubptinnertmp, iAllstub);

  constexpr unsigned int NfinephiBits=NBitsPhiRegion+TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::kNBitsPhiBins+VMStubTEOuterBase<OuterRegion<Seed>()>::kVMSTEOFinePhiSize;

  static TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()> tebuffer;
  static_assert(nASMemInner<Seed, iTC>() <= 3, "Only handling up to three inner AS memories");
  tebuffer.setMemBegin(0);
  tebuffer.setMemEnd(nASMemInner<Seed, iTC>());
  tebuffer.setIStub(0); 

  tebuffer.reset();


  TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()> teunits[kNTEUnits[Seed]];
#pragma HLS array_partition variable=teunits complete dim=1

 reset_teunits: for (unsigned i = 0; i < kNTEUnits[Seed]; i++) {
#pragma HLS unroll
    teunits[i].reset(i);
  }

  TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex = 0;

  //pipeline variables
  bool goodstub___;
  ap_uint<kNBits_MemAddr> istub__, istub___;
  AllStubInner<innerASType> stub__, stub___;
  ap_uint<1+2*TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::kNBitsRZFine+TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::kNBitsRZBin> lutval___;
  ap_uint<(1<<TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::kNBitsPhiBins)> useregion___;

  bool goodstub__ = false;
  goodstub___ = false;


  static const ap_uint<(1<<(2*TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::kNBitsBuffer))> TENearFullUINT=nearFullTEUnitInit();

  constexpr int NRZBINS = (1<<TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::kNBitsRZBin);

  typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMMASK vmstubsmask[NRZBINS];
#pragma HLS array_partition variable=vmstubsmask complete dim=1
 entriesloop:for(unsigned int i=0;i<NRZBINS-1;i++) {
#pragma HLS unroll
  vmstubsmask[i]=(outerVMStubs->getBinMask8(bx,i+1),outerVMStubs->getBinMask8(bx,i));
}
  vmstubsmask[NRZBINS-1]=(ap_uint<8>(0),outerVMStubs->getBinMask8(bx,NRZBINS-1));

  constexpr int NTEUBits=3; //ceil(log2(kNTEUnits[Seed]));

  ap_uint<NTEUBits> iTEfirstidle = 0;
  ap_uint<NTEUBits> iTE = 0;
  ap_uint<1> HaveTEData = false; 
  ap_uint<1> idlete = true;

  typename AllStub<innerASType>::AllStubData innerStubData = 0;
  ap_uint<TrackletParameters::kTParPhiRegionSize> phiRegion = 0;
  bool negDisk_ = false;
  typename TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS innerIndex = 0;
  typename TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS outerIndex = 0;

  ap_uint<kNTEUnits[Seed]> teunearfull = 0;
  ap_uint<kNTEUnits[Seed]> teuidle = 0;
  teuidle = ~teuidle;

  typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::INDEX teuwriteindex[kNTEUnits[Seed]];
#pragma HLS array_partition variable=teuwriteindex complete dim=1

  typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::INDEX teureadindex[kNTEUnits[Seed]];
#pragma HLS array_partition variable=teureadindex complete dim=1

  for (unsigned k = 0; k < kNTEUnits[Seed]; k++){
#pragma HLS unroll
    teuwriteindex[k] = 0;
    teureadindex[k] = 0;
  }
  //quantities looked up in LUT
  typename VMStubTEOuter<OuterRegion<Seed>()>::VMSTEOFINEZ rzfinebinfirst,rzdiffmax;
  typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::RZBIN start;
  ap_uint<1> usenext;
 istep_loop: for(unsigned istep=0;istep<N;istep++) {
#pragma HLS pipeline II=1 rewind

    /*
    std::cout << "istep="<<istep<<" TEBuffer: "<<tebuffer.getIStub()<<" "<<tebuffer.getMem()<<" "
              << tebuffer.readptr()<<" "<<tebuffer.writeptr()<<std::endl;

    for (unsigned k = 0; k < kNTEUnits[Seed]; k++){
      std::cout<<" ["<<k<<" "<<teunits[k].readindex_<<" "<<teunits[k].writeindex_<<" "<<teunits[k].idle_<<"]";
    }
    std::cout << std::endl;
    */


    //
    // Step 0 -  zeroth step is to cache some of data
    //

    typename TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()>::TEBUFFERINDEX writeptr = tebuffer.writeptr_;
    typename TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()>::TEBUFFERINDEX readptr = tebuffer.readptr_;
    typename TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()>::TEBUFFERINDEX readptrnext = readptr+1;
    typename TEBuffer<Seed,iTC,innerASType,OuterRegion<Seed>()>::TEBUFFERINDEX writeptrnext = writeptr+1;
    bool tebufferfull = nearFullTEBuff(writeptr,readptr);
    ap_uint<1> TEBufferData = (writeptr!=readptr);

    /*
    
    ap_uint<kNTEUnits[Seed]> teunotempty;

  prefetchteudata: for (unsigned k = 0; k < kNTEUnits[Seed]; k++){
#pragma HLS unroll
      teuwriteindex[k]=teunits[k].writeindex_;
      teureadindex[k]=teunits[k].readindex_;
      teunearfull[k]=TENearFullUINT[ (teureadindex[k], teuwriteindex[k]) ];
      teunotempty[k]=teuwriteindex[k]!=teureadindex[k];
      teuidle[k]=
teunits[k].idle_;
    }

    iTEfirstidle = __builtin_ctz(teuidle);
    iTE = (((1<<NTEUBits)-1)&__builtin_clz(teunotempty));
    iTE=~iTE;
    HaveTEData = teunotempty.or_reduce();    
    idlete = teuidle.or_reduce();

    (outerIndex, innerStub, innerIndex)=teunits[iTE].stubids_[teureadindex[iTE]];

    */

    tebuffer.readptr_ = (idlete&&TEBufferData)?readptrnext:readptr;


    
    // Step 1 - In this first step we check if there are stubs to be sent to the TC
    // we loop over the TE units and see if they have data.
    
    
    // Check if TE unit has data - find the first instance with data
      
    teunits[iTE].readindex_=teureadindex[iTE]+HaveTEData;
    const TrackletProjection<BARRELPS>::TProjTCID TCId(iTC+(Seed << TrackletProjection<BARRELPS>::kTProjITCSize));

    const auto &outerStub = AllStub<outerASType>(outerStubs->read_mem(bx, outerIndex).raw());
    const auto innerStub = AllStub<innerASType>(innerStubData);

    if (HaveTEData) {
      if (diskSeed) //pass in negdisk if disk seed
        TC::processStubPair<Seed, innerASType, outerASType, TPROJMaskBarrel<Seed, iTC>(), TPROJMaskDisk<Seed, iTC>()>(bx, phiRegion, innerIndex, innerStub, outerIndex, outerStub, TCId, trackletIndex, trackletParameters, projout_barrel_ps, projout_barrel_2s, projout_disk, npar, nproj_barrel_ps, nproj_barrel_2s, nproj_disk, negDisk_);
      else
        TC::processStubPair<Seed, innerASType, outerASType, TPROJMaskBarrel<Seed, iTC>(), TPROJMaskDisk<Seed, iTC>()>(bx, phiRegion, innerIndex, innerStub, outerIndex, outerStub, TCId, trackletIndex, trackletParameters, projout_barrel_ps, projout_barrel_2s, projout_disk, npar, nproj_barrel_ps, nproj_barrel_2s, nproj_disk);
    }
    

    //
    // Step 2 - Run the TE unit step method. If there is idle TE unit and we have stubs to process we will read from TE Buffer 
    // and initialize a TE unit
    // 

    //Now loop over the TE units and execute the step method. The first TE unit that is idle is 
    //initialized if there is data in TE Buffer from above
  step_teunits: for (unsigned int k = 0 ; k < kNTEUnits[Seed]; k++){
#pragma HLS unroll
      ap_uint<1> init=teuidle[k]&&TEBufferData&&(k==iTEfirstidle);
      //second step

      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::INDEX writeindexnext=teuwriteindex[k]+1;

      const typename VMStubTEOuter<OuterRegion<Seed>()>::VMSTEOFINEPHI& finephi = teunits[k].outervmstub___.getFinePhi();
      const ap_uint<1+VMStubTEOuterBase<OuterRegion<Seed>()>::kVMSTEOFineZSize>& rzbin = (teunits[k].next___, teunits[k].outervmstub___.getFineZ()); 


      ap_uint<NfinephiBits> outerfinephi = (iAllstub, teunits[k].ireg___, finephi);
      
      constexpr unsigned int NdphiBits = (Seed==TF::L5L6 || overlapSeed) ? 6 : 5;
      ap_uint<NdphiBits> idphi,idphitmp;
      ap_uint<NdphiBits+1> outerfinephitmp = outerfinephi&((1<<(NdphiBits+1))-1);
      ap_uint<NdphiBits+1> innerfinephitmp = AllStubInner<innerASType>(teunits[k].innerstub___).getFinePhi()&((1<<(NdphiBits+1))-1);
      idphitmp = outerfinephitmp-innerfinephitmp;
      ap_uint<NfinephiBits-NdphiBits> overflow;
      (overflow,idphi) =  outerfinephi - AllStubInner<innerASType>(teunits[k].innerstub___).getFinePhi();
      
      ap_uint<1> inrange1 = overflow==0;
      ap_uint<1> inrange2 = overflow==~ap_uint<NfinephiBits-NdphiBits>(0);
      ap_uint<1> inrange = inrange1||inrange2;

      ap_uint<1> rzcut1=rzbin >= teunits[k].rzbinfirst___;
      ap_uint<1> rzcut2=rzbin <= teunits[k].rzbinfirst___+teunits[k].rzbindiffmax___;
      ap_uint<1> rzcut= rzcut1 && rzcut2;
      
      const auto& outerbend = teunits[k].outervmstub___.getBend();
      const auto& innerbend = AllStubInner<innerASType>(teunits[k].innerstub___).getBend();
      ap_uint<1> lutinner, lutouter;
      if (diskSeed||overlapSeed){ //Overlap and Disk Seeds
        ap_uint<3> ibin = teunits[k].ibin___;
        int ibinMask = 3;
        ap_uint<3> ir = ((ibin & ibinMask) << 1) + ((rzbin&4) >> (kNbitsrzbin-1));

        ap_uint<2> ptinnerindexfirst, ptouterindexfirst;
        ap_uint<10> ptinnerindexlast, ptouterindexlast;

        (ptinnerindexfirst,ptinnerindexlast) = (idphitmp,ir,innerbend);
        (ptouterindexfirst,ptouterindexlast) = (idphitmp,ir,outerbend);

        if (diskSeed){ //for disk/overlap seeds, pt luts are split into 2/4 parts, due to vivado_hls limit on array sizes
          lutinner = (ptinnerindexfirst == 0) ? teunits[k].stubptinnerlutnew1_[ptinnerindexlast] :
                     teunits[k].stubptinnerlutnew2_[ptinnerindexlast];
          lutouter = (ptouterindexfirst == 0) ? teunits[k].stubptouterlutnew1_[ptouterindexlast] :
                     teunits[k].stubptouterlutnew2_[ptouterindexlast];
        }
        else{
          lutinner = (ptinnerindexfirst == 0) ? teunits[k].stubptinnerlutnew1_[ptinnerindexlast] :
                     (ptinnerindexfirst == 1) ? teunits[k].stubptinnerlutnew2_[ptinnerindexlast] :
                     (ptinnerindexfirst == 2) ? teunits[k].stubptinnerlutnew3_[ptinnerindexlast] :
                     teunits[k].stubptinnerlutnew4_[ptinnerindexlast];
          lutouter = (ptouterindexfirst == 0) ? teunits[k].stubptouterlutnew1_[ptouterindexlast] :
                     (ptouterindexfirst == 1) ? teunits[k].stubptouterlutnew2_[ptouterindexlast] :
                     (ptouterindexfirst == 2) ? teunits[k].stubptouterlutnew3_[ptouterindexlast] :
                     teunits[k].stubptouterlutnew4_[ptouterindexlast];
        }
      }
      else{ //Barrel Seeds
        auto ptinnerindex = (idphitmp, innerbend);
        auto ptouterindex = (idphitmp, outerbend);
        lutinner = teunits[k].stubptinnerlutnew_[ptinnerindex];
        lutouter = teunits[k].stubptouterlutnew_[ptouterindex];
      }
      ap_uint<1> savestub = teunits[k].good___ && inrange && lutinner && lutouter && rzcut;
      ap_uint<TrackletParameters::kTParPhiRegionSize> phiregion = teunits[k].innerstub___.getFinePhi().range(7, L1InnerSeed?5:6);
      teunits[k].stubids_[teuwriteindex[k]] = (teunits[k].outervmstub___.getIndex(),
					       teunits[k].innerstub___.getAllStub(),
					       phiregion, 
					       teunits[k].innerstub___.getIndex());
      if (diskSeed)
        teunits[k].negDisk_[teuwriteindex[k]] = teunits[k].innerstub___.getNegDisk();

      teunits[k].writeindex_=savestub?writeindexnext:teuwriteindex[k];
      
      //first and half step. Tried to remove this pipelining stage but failed timing.

      teunits[k].next___=teunits[k].next__;
      teunits[k].ireg___=teunits[k].ireg__;
      teunits[k].outervmstub___=teunits[k].outervmstub__;
      teunits[k].rzbinfirst___=teunits[k].rzbinfirst__;
      teunits[k].rzbindiffmax___=teunits[k].rzbindiffmax__;
      teunits[k].innerstub___=teunits[k].innerstub__;
      teunits[k].good___=teunits[k].good__;
      teunits[k].ibin___=teunits[k].ibin__;

      //first step
      TEData<Seed,iTC,innerASType,OuterRegion<Seed>()> tedatatmp = tebuffer.buffer_[readptr];

      teunits[k].innerstub__ = init?tedatatmp.getAllStub():teunits[k].innerstub__;
      teunits[k].rzbinfirst__=init?tedatatmp.getrzbinfirst():teunits[k].rzbinfirst__;
      teunits[k].rzbindiffmax__=init?tedatatmp.getrzdiffmax():teunits[k].rzbindiffmax__;

      //Do init path here
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMMASK memmask_init = tedatatmp.getStubMask();
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMINDEX memindex_init = __builtin_ctz(tedatatmp.getStubMask());
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMINDEX memindexlast_init = __builtin_clz(tedatatmp.getStubMask());
      memindexlast_init = ~memindexlast_init;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMSTUBS memstubs_init = outerVMStubs->getEntries(bx,tedatatmp.getStart());
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS nstubs_init(teunits[k].calcNStubs(memstubs_init,memmask_init));
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::PHIBIN rzbin_init=tedatatmp.getStart();
      ap_uint<1> next_init;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::PHIBIN ireg_init;
      (next_init, ireg_init) = memindex_init;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::RZBIN ibin_init(rzbin_init+next_init);
      ap_uint<1> good_init = !teunearfull[k];
      ap_uint<1> notallstubs_init = nstubs_init!=1;
      memmask_init[memindex_init] = good_init ? notallstubs_init : ap_uint<1>(1);
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS istub_init(good_init&&notallstubs_init); 
      ap_uint<1> idle_init = good_init && (!notallstubs_init) && (memindex_init==memindexlast_init);
      //Do 'regular' processing here
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMMASK memmask_reg = teunits[k].memmask_;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMINDEX memindex_reg = __builtin_ctz(teunits[k].memmask_);
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMINDEX memindexlast_reg = teunits[k].lastmemindex;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMSTUBS memstubs_reg = teunits[k].nstub16();
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS nstubs_reg(teunits[k].calcNStubs(memstubs_reg,memmask_reg));
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS istub_tmp_reg = teunits[k].istub_;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS istubnext_reg = teunits[k].istub_+1;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::PHIBIN rzbin_reg=teunits[k].rzbin_;
      ap_uint<1> next_reg;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::PHIBIN ireg_reg;
      (next_reg, ireg_reg) = memindex_reg;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::RZBIN ibin_reg(rzbin_reg+next_reg);
      ap_uint<1> good_reg = !(teunearfull[k]||teuidle[k]);
      ap_uint<1> notallstubs_reg = nstubs_reg!=istubnext_reg;
      typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS istub_reg = 
	good_reg?(notallstubs_reg?istubnext_reg:typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS(0)):istub_tmp_reg;
      memmask_reg[memindex_reg] = good_reg ? notallstubs_reg : ap_uint<1>(1);
      ap_uint<1> idle_reg = teuidle[k] || (good_reg && (!notallstubs_reg) && (memindex_reg==memindexlast_reg));
      

      //Fill the result

      teunits[k].outervmstub__ = outerVMStubs->read_mem(k, bx, init?
						       (ireg_init, ibin_init,typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::NSTUBS(0)):
						       (ireg_reg, ibin_reg, istub_tmp_reg));
      teunits[k].next__ = init?next_init:next_reg;
      teunits[k].ireg__ = init?ireg_init:ireg_reg;
      teunits[k].good__ = init?good_init:good_reg;
      teunits[k].ibin__ = init?ibin_init:ibin_reg;

      teunits[k].memmask_ = init?memmask_init:memmask_reg;
      teunits[k].lastmemindex = init?memindexlast_init:memindexlast_reg;
      teunits[k].setnstub16(init?memstubs_init:memstubs_reg);

      teunits[k].istub_ = init?istub_init:istub_reg;
      teunits[k].rzbin_ = init?rzbin_init:rzbin_reg;
      teunits[k].idle_ = init?idle_init:idle_reg;

    }

    //
    // Third step - fill inner layer stubs in the TE buffer 
    // Check if inner stub has matching stubs in next layer/disk if
    // so put them in TE buffere to be picked up by a TE unit
    //

    //Implement as a manual pipeline ugh...

    
    //
    // Get stubmask and save in TE Buffer
    //
    
    //LUT returns all 1's if not valid. (should change to returning zero.
    bool valid=!lutval___.and_reduce();
    
    //Get the mask of bins that has non-zero number of hits
    typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMMASK stubmask16 = vmstubsmask[start];
    
    //Calculate the stub mask for which bins have hits _and_ are consistent with the inner stub
    typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMMASK mask = ( (useregion___*usenext,useregion___) );
    typename TrackletEngineUnit<Seed,iTC,innerASType,OuterRegion<Seed>()>::MEMMASK stubmask = stubmask16&mask;

    //Find if there are _any_ bins with hits that needs to be tried. If so will store stub in buffer
    bool havestubs=stubmask.or_reduce();
    
    //addtedata is the criteria for saving stub to TE buffer:
    //valid means that r/z project is in valid range
    //havestubs means that at least one memory bin has stubs
    //goodstub means that we had a valid inner stub
    ap_uint<1> addtedata=valid&&havestubs&&goodstub___;

    //Create TEData and save in buffer - but only increment point if data good
    TEData<Seed,iTC,innerASType,OuterRegion<Seed>()> tedatatmp(stubmask, rzfinebinfirst,start, rzdiffmax,stub___.raw());
    tebuffer.buffer_[tebuffer.writeptr_] = tedatatmp.raw();
    tebuffer.writeptr_ = addtedata?writeptrnext:tebuffer.writeptr_;
    
    //
    // Read LUTs and find valid regions in r/z and phi
    //
    
    //Get z-position and top bits for LUT
    auto z = stub__.getZ();

    //Get r-position and top bits for LUT
    auto r = stub__.getR();
    //
    bool negDisk;
    if (diskSeed){
      auto indexz = z.range(z.length()-1,z.length()-kNbitszfinebintableDisk);
      auto indexr = r.range(r.length()-1,r.length()-kNbitsrfinebintableDisk);
      negDisk = stub__.getNegDisk();
      indexz = negDisk ? ap_int<kNbitszfinebintable>(((1 << kNbitszfinebintableDisk) - 1) - indexz) : indexz;
      lutval___ = lut[(indexz,indexr)];
    }
    else{
      auto indexz = z.range(z.length()-1,z.length()-kNbitszfinebintable);
      auto indexr = r.range(r.length()-1,r.length()-kNbitsrfinebintable);
      lutval___ = lut[(indexz,indexr)];
    }

    //Get bend and fine phi for LUT
    ap_uint<AllStubInnerBase<innerASType>::kASBendSize> bend = stub__.getBend();
    ap_uint<AllStubInnerBase<innerASType>::kASFinePhiSize> innerfinephi = stub__.getFinePhi();
    
    //This LUT tells us which range in r/z to look for stubs in the other layer/disk
    if (diskSeed){//disk seeds only read 2 bits of start from lut, last bit is from negative disk
      ap_uint<2> starttmp;
      (rzdiffmax , starttmp, usenext, rzfinebinfirst) = lutval___;
      start = negDisk ? ap_uint<3>(starttmp + (1 << (kNbitsrzbin-1))) : ap_uint<3>(starttmp);
    }
    else
      (rzdiffmax, start, usenext, rzfinebinfirst) = lutval___; 

    auto useregindex = (innerfinephi,bend);
    ap_uint<3> ir;
    
    if (diskSeed || overlapSeed) {
      //If the lookupbits were rationally organized this would be much simpler
      ap_uint<2> nrbits = 3;
      ir = ((start & ((1 << (nrbits - 1)) - 1)) << 1) + (rzfinebinfirst >> (kNbitsrzbin - 1));
      useregion___ = regionLUT.lookup((useregindex,ir));
    }
    else{
      useregion___ = regionLUT.lookup(useregindex);
    }

    //This lut tells us which range in phi to loof for stubs the other layer/disk
   
    goodstub___ = goodstub__;
    stub___ = stub__;
    istub___ = istub__;
    

    //
    // Read stub
    //

    
    //Extract the memory and range this TE buffer is processing
    auto imem=tebuffer.getMem();
    bool validmem=imem<tebuffer.getMemEnd();
    
    //compute the next memory
    typename TEData<Seed,iTC,innerASType,OuterRegion<Seed>()>::IMEM imemnext = imem+1;
    
    //Extract the current stub - check if valid. Calculate next stub. Check if valid
    istub__ = tebuffer.getIStub();
    bool validstub = istub__ < innerStubs[imem].getEntries(bx);
    
    ap_uint<kNBits_MemAddr> istubnext = istub__+1;
    bool validstubnext=istubnext<innerStubs[imem].getEntries(bx);
    
    //Calculate good stub - true if:
    //validmem is true - meaning thart we have not exhausted all stub memories
    //tebuffer not full - can not process stub if buffere is full and we can not store 
    //validstub - should be redundant with validmem - FIXME
    goodstub__ = validmem&&(!tebufferfull)&&validstub;
    //Update istub if goodstub
    tebuffer.getIStub()=goodstub__?(validstubnext?istubnext:ap_uint<kNBits_MemAddr>(0)):istub__; 
    //Update imem if the next stub is not valid
    tebuffer.getMem()=((goodstub__&&(!validstubnext))||(innerStubs[imem].getEntries(bx) == 0&&validmem))?imemnext:imem;
    
    //Read stub from memory - BRAM with latency of one or two clks
    stub__ = AllStubInner<innerASType>(innerStubs[imem].read_mem(bx,istub__).raw());


    //Update TEUnit data for next loop

    ap_uint<kNTEUnits[Seed]> teunotempty;

  prefetchteudata: for (unsigned k = 0; k < kNTEUnits[Seed]; k++){
#pragma HLS unroll
      teuwriteindex[k]=teunits[k].writeindex_;
      teureadindex[k]=teunits[k].readindex_;
      teunearfull[k]=TENearFullUINT[ (teureadindex[k], teuwriteindex[k]) ];
      teunotempty[k]=teuwriteindex[k]!=teureadindex[k];
      teuidle[k]=teunits[k].idle_;
    }

    iTEfirstidle = __builtin_ctz(teuidle);
    iTE = (((1<<NTEUBits)-1)&__builtin_clz(teunotempty));
    iTE=~iTE;
    HaveTEData = teunotempty.or_reduce();
    idlete = teuidle.or_reduce();
    (outerIndex, innerStubData, phiRegion, innerIndex)=teunits[iTE].stubids_[teureadindex[iTE]];
    if (diskSeed)
      negDisk_ = teunits[iTE].negDisk_[teureadindex[iTE]];
  } //end of istep

  bx_o = bx;

}

#endif

