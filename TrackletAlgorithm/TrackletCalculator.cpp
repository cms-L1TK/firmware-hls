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
    double dPhi0 = phi0->to_long() * 1.56566e-05,
           dRinv = rinv->to_long() * 1.04377e-06;
    double phicrit=dPhi0-asin(0.5*55.0*dRinv);
    bool keep=(phicrit>0.15897)&&(phicrit<0.867102);
    success = success && keep;

    return success;
  }
}

template<TC::seed Seed, TC::itc iTC> const TrackletProjection<BARRELPS>::TProjTCID
TC::ID()
{
  return ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << 4) + iTC);
}

template<regionType TProjType> bool
TC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID, const bool success)
{
#pragma HLS inline
  bool proj_success = true;

// Reject projections with extreme r/z values.
  if ((proj.getRZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getRZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1))))
    proj_success = false;
  if (abs(proj.getRZ()) > 2048)
    proj_success = false;

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  TC::Types::phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);
  phi >>= 3;

  projout_PHIA->write_mem(bx, proj, success && proj_success && phi == 0);
  projout_PHIB->write_mem(bx, proj, success && proj_success && phi == 1);
  projout_PHIC->write_mem(bx, proj, success && proj_success && phi == 2);
  projout_PHID->write_mem(bx, proj, success && proj_success && phi == 3);

  return (success && proj_success);
}

namespace TC {
  template<> bool
  addProj<DISK>(const TrackletProjection<DISK> &proj, const BXType bx, TrackletProjectionMemory<DISK> * const projout_PHIA, TrackletProjectionMemory<DISK> * const projout_PHIB, TrackletProjectionMemory<DISK> * const projout_PHIC, TrackletProjectionMemory<DISK> * const projout_PHID, const bool success)
  {
#pragma HLS inline
    bool proj_success = true;

  // Reject projections with extreme r/z values.
    if (proj.getRZ() < 205 || proj.getRZ() > 1911)
      proj_success = false;

  // Fill correct TrackletProjectionMemory according to phi bin of projection.
    Types::phiL phi = proj.getPhi() >> (TrackletProjection<DISK>::kTProjPhiSize - 5);
    phi >>= 3;

    projout_PHIA->write_mem(bx, proj, success && proj_success && phi == 0);
    projout_PHIB->write_mem(bx, proj, success && proj_success && phi == 1);
    projout_PHIC->write_mem(bx, proj, success && proj_success && phi == 2);
    projout_PHID->write_mem(bx, proj, success && proj_success && phi == 3);

    return (success && proj_success);
  }
}

template<uint8_t NSPMem00, uint8_t NSPMem01, uint8_t NSPMem10, uint8_t NSPMem11> void
TC::getIndices(
    const BXType bx,
    const StubPairMemory stubPairs[NSPMem00 + NSPMem01 + NSPMem10 + NSPMem11],
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
  index: for (TC::Types::nSPMem j = 0; j < NSPMem00 + NSPMem01 + NSPMem10 + NSPMem11; j++) {
    if (!set && iSP >= stubPairs[j].getEntries(bx))
      iSP -= stubPairs[j].getEntries(bx), iSPMem++;
    else
      set = true;
  }

  done = !set || iSPMem >= NSPMem00 + NSPMem01 + NSPMem10 + NSPMem11;
}

namespace TC {
  template<> void
  processStubPair<L1L2>(
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
      TrackletProjectionMemory<DISK> * const projout_D4PHID
  )
  {
    Types::rinv rinv;
    TrackletParameters::PHI0PAR phi0;
    TrackletParameters::Z0PAR z0;
    TrackletParameters::TPAR t;
    Types::phiL phiL[4];
    Types::zL zL[4];
    Types::der_phiL der_phiL;
    Types::der_zL der_zL;
    Types::flag valid_proj[4];
    Types::phiD phiD[4];
    Types::rD rD[4];
    Types::der_phiD der_phiD;
    Types::der_rD der_rD;
    Types::flag valid_proj_disk[4];
    bool success;

  // Calculate the tracklet parameters and projections.
    success = barrelSeeding<L1L2>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);

  // Write the tracklet parameters and projections to the output memories.
    if (success) {
      TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
      trackletParameters->write_mem(bx, tpar);
      const TrackletProjection<BARRELPS>::TProjTrackletIndex trackletIndex = trackletParameters->getEntries(bx) - 1;

      bool addL3 = false, addL4 = false, addL5 = false, addL6 = false;

      if (valid_proj[0]) {
        TrackletProjection<BARRELPS> tproj(TCID, trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
        addL3 = addProj<BARRELPS>(tproj, bx, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID);
      }
      if (valid_proj[1]) {
        TrackletProjection<BARREL2S> tproj(TCID, trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
        addL4 = addProj<BARREL2S>(tproj, bx, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID);
      }
      if (valid_proj[2]) {
        TrackletProjection<BARREL2S> tproj(TCID, trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
        addL5 = addProj<BARREL2S>(tproj, bx, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID);
      }
      if (valid_proj[3]) {
        TrackletProjection<BARREL2S> tproj(TCID, trackletIndex, phiL[3], zL[3], der_phiL, der_zL);
        addL6 = addProj<BARREL2S>(tproj, bx, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID);
      }

      if (valid_proj_disk[0] && !addL6) {
        TrackletProjection<DISK> tproj(TCID, trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
        addProj<DISK>(tproj, bx, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID);
      }
      if (valid_proj_disk[1] && !addL5) {
        TrackletProjection<DISK> tproj(TCID, trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
        addProj<DISK>(tproj, bx, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID);
      }
      if (valid_proj_disk[2] && !addL4) {
        TrackletProjection<DISK> tproj(TCID, trackletIndex, phiD[2], rD[2], der_phiD, der_rD);
        addProj<DISK>(tproj, bx, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID);
      }
      if (valid_proj_disk[3] && !addL3) {
        TrackletProjection<DISK> tproj(TCID, trackletIndex, phiD[3], rD[3], der_phiD, der_rD);
        addProj<DISK>(tproj, bx, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);
      }
    }
  }
}

template<class T> void
TC::clearMemories(const BXType bx, T mem)
{
  mem->clear(bx);
}

template<class T, class... Args> void
TC::clearMemories(const BXType bx, T mem, Args... args)
{
  mem->clear(bx);
  clearMemories(bx, args...);
}

// This is the primary interface for the TrackletCalculator.
template<TC::itc iTC, uint8_t NASMemInner, uint8_t NASMemOuter, uint8_t NSPMem00, uint8_t NSPMem01, uint8_t NSPMem10, uint8_t NSPMem11, uint16_t N> void
TrackletCalculator_L1L2(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[NASMemInner],
    const AllStubMemory<BARRELPS> outerStubs[NASMemOuter],
    const StubPairMemory stubPairs[NSPMem00 + NSPMem01 + NSPMem10 + NSPMem11],
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
)
{
// Clear all output memories before starting.
  TC::clearMemories(bx, trackletParameters, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);

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
    TC::getIndices<NSPMem00, NSPMem01, NSPMem10, NSPMem11>(bx, stubPairs, iSPMem, iSP, done);

    if (!done) {
// Retrieve the inner and outer stubs for this stub pair, determining which
// all-stubs memory to use based on iSPMem:
//   [0, NSPMem00):        inner stub from innerStubs[0], outer stub from outerStubs[0]
//   [NSPMem00, NSPMem01): inner stub from innerStubs[1], outer stub from outerStubs[0]
//   [NSPMem01, NSPMem10): inner stub from innerStubs[0], outer stub from outerStubs[1]
//   [NSPMem10, NSPMem11): inner stub from innerStubs[1], outer stub from outerStubs[1]
      innerIndex = stubPairs[iSPMem].read_mem(bx, iSP).getInnerIndex();
      outerIndex = stubPairs[iSPMem].read_mem(bx, iSP).getOuterIndex();
      const AllStub<BARRELPS> &innerStub = (iSPMem < NSPMem00 + NSPMem01 ? innerStubs[0].read_mem(bx, innerIndex) : innerStubs[1].read_mem(bx, innerIndex));
      const AllStub<BARRELPS> &outerStub = (iSPMem < NSPMem00 || (iSPMem >= NSPMem00 + NSPMem01 && iSPMem < NSPMem00 + NSPMem01 + NSPMem10) ? outerStubs[0].read_mem(bx, outerIndex) : outerStubs[1].read_mem(bx, outerIndex));

      TC::processStubPair<TC::L1L2>(bx, innerIndex, innerStub, outerIndex, outerStub, TCID, trackletIndex, trackletParameters, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);
    }
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
  TC_L1L2E: TrackletCalculator_L1L2<TC::E, 2, 1, 5, 0, 8, 0, kMaxProc>(
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

// Explicitly instantiate this for the C-simulation so that the user can test
// the version of TC_L1L2E without truncation.
template void
TrackletCalculator_L1L2<TC::E, 2, 1, 5, 0, 8, 0, (5 + 8) * (1 << kNBits_MemAddr)>(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<BARRELPS> outerStubs[1],
    const StubPairMemory stubPairs[13],
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
