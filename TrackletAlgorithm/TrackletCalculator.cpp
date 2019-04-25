#include "TrackletCalculator.hh"

// This function calls TC_L1L2, defined in TC_L1L2.cpp, and applies cuts to the
// results.
namespace TC {
  template<> bool
  barrelSeeding<L1L2>(const AllStub<BARRELPS> &innerStub, const AllStub<BARRELPS> &outerStub, Types::rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t, Types::phiL phiL[4], Types::zL zL[4], Types::der_phiL * const der_phiL, Types::der_zL * const der_zL, Types::flag valid_proj[4], Types::phiD phiD[4], Types::rD rD[4], Types::der_phiD * const der_phiD, Types::der_rD * const der_rD, Types::flag valid_proj_disk[4])
  {
    Types::rmean rproj[4] = {RMEAN[L3], RMEAN[L4], RMEAN[L5], RMEAN[L6]};
    Types::zmean zproj[4] = {ZMEAN[D1], ZMEAN[D2], ZMEAN[D3], ZMEAN[D4]};

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

  // This is copied from the emulation for now, but should probably be made more
  // FPGA-friendly.
    /*double dPhi0 = phi0->to_long() * 1.56566e-05,
           dRinv = rinv->to_long() * 1.04377e-06;
    double phicrit=dPhi0-asin(0.5*55.0*dRinv);
    bool keep=(phicrit>0.15897)&&(phicrit<0.867102);
    success = success && keep;*/

    return success;
  }
}

// Wrapper function for TC_L1L2E, since Vivado HLS apparently does not like
// template parameters in the top function.
void TrackletCalculator_L1L2E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<BARRELPS> outerStubs[1],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHIA,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHIB,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHIC,
    TrackletProjectionMemory<BARRELPS> * projout_L3PHID,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIA,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L4PHID,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIA,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L5PHID,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIA,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIB,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHIC,
    TrackletProjectionMemory<BARREL2S> * projout_L6PHID,
    TrackletProjectionMemory<DISK> * projout_D1PHIA,
    TrackletProjectionMemory<DISK> * projout_D1PHIB,
    TrackletProjectionMemory<DISK> * projout_D1PHIC,
    TrackletProjectionMemory<DISK> * projout_D1PHID,
    TrackletProjectionMemory<DISK> * projout_D2PHIA,
    TrackletProjectionMemory<DISK> * projout_D2PHIB,
    TrackletProjectionMemory<DISK> * projout_D2PHIC,
    TrackletProjectionMemory<DISK> * projout_D2PHID,
    TrackletProjectionMemory<DISK> * projout_D3PHIA,
    TrackletProjectionMemory<DISK> * projout_D3PHIB,
    TrackletProjectionMemory<DISK> * projout_D3PHIC,
    TrackletProjectionMemory<DISK> * projout_D3PHID,
    TrackletProjectionMemory<DISK> * projout_D4PHIA,
    TrackletProjectionMemory<DISK> * projout_D4PHIB,
    TrackletProjectionMemory<DISK> * projout_D4PHIC,
    TrackletProjectionMemory<DISK> * projout_D4PHID
) {
  TC_L1L2E: TrackletCalculator_L1L2<TC::E, 2, 1, 5, 0, 8, 0, 0x77777772, kMaxProc>(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    trackletParameters,
    projout_L3PHIA,
    projout_L3PHIB,
    projout_L3PHIC,
    projout_L3PHID,
    projout_L4PHIA,
    projout_L4PHIB,
    projout_L4PHIC,
    projout_L4PHID,
    projout_L5PHIA,
    projout_L5PHIB,
    projout_L5PHIC,
    projout_L5PHID,
    projout_L6PHIA,
    projout_L6PHIB,
    projout_L6PHIC,
    projout_L6PHID,
    projout_D1PHIA,
    projout_D1PHIB,
    projout_D1PHIC,
    projout_D1PHID,
    projout_D2PHIA,
    projout_D2PHIB,
    projout_D2PHIC,
    projout_D2PHID,
    projout_D3PHIA,
    projout_D3PHIB,
    projout_D3PHIC,
    projout_D3PHID,
    projout_D4PHIA,
    projout_D4PHIB,
    projout_D4PHIC,
    projout_D4PHID
  );
}
