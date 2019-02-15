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
  // FPGA-friendly. However, it does not actually reject anything with the
  // current test-bench files, so we comment it out for now.
    /*double dPhi0 = phi0->to_long() * 1.56566e-05,
           dRinv = rinv->to_long() * 1.04377e-06;
    double phicrit=dPhi0-asin(0.5*55.0*dRinv);
    bool keep=(phicrit>0.15897)&&(phicrit<0.867102);
    success = success && keep;*/

    return success;
  }
}

template<TC::seed Seed> const TrackletProjection<BARRELPS>::TProjTCID
TC::ID(const TC::Types::iTC iTC)
{
  return ((TrackletProjection<BARRELPS>::TProjTCID(Seed) << 4) + iTC);
}

template<regionType TProjType> bool
TC::addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID)
{
  bool success = true;

// Reject projections with extreme r/z values.
  if ((proj.getRZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getRZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1))))
    success = false;
  if (abs(proj.getRZ()) > 2048)
    success = false;

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  TC::Types::phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);
  phi >>= 3;
  if (success) {
    switch (phi) {
      case 0:
        projout_PHIA->write_mem(bx, proj);
        break;
      case 1:
        projout_PHIB->write_mem(bx, proj);
        break;
      case 2:
        projout_PHIC->write_mem(bx, proj);
        break;
      case 3:
        projout_PHID->write_mem(bx, proj);
        break;
    }
  }

  return success;
}

namespace TC {
  template<> bool
  addProj<DISK>(const TrackletProjection<DISK> &proj, const BXType bx, TrackletProjectionMemory<DISK> * const projout_PHIA, TrackletProjectionMemory<DISK> * const projout_PHIB, TrackletProjectionMemory<DISK> * const projout_PHIC, TrackletProjectionMemory<DISK> * const projout_PHID)
  {
    bool success = true;

  // Reject projections with extreme r/z values.
    if (proj.getRZ() < 205 || proj.getRZ() > 1911)
      success = false;

  // Fill correct TrackletProjectionMemory according to phi bin of projection.
    Types::phiL phi = proj.getPhi() >> (TrackletProjection<DISK>::kTProjPhiSize - 5);
    phi >>= 3;
    if (success) {
      switch (phi) {
        case 0:
          projout_PHIA->write_mem(bx, proj);
          break;
        case 1:
          projout_PHIB->write_mem(bx, proj);
          break;
        case 2:
          projout_PHIC->write_mem(bx, proj);
          break;
        case 3:
          projout_PHID->write_mem(bx, proj);
          break;
      }
    }

    return success;
  }
}

template<uint8_t NSPMem00, uint8_t NSPMem10> void
TC::getIndices(
    const BXType bx,
    const StubPairMemory stubPairs00[NSPMem00],
    const StubPairMemory stubPairs10[NSPMem10],
    TC::Types::nASMem &iASMemInner,
    TC::Types::nASMem &iASMemOuter,
    TC::Types::nSPMem &iSPMem,
    TC::Types::nSP &iSP,
    bool &done
)
{
  bool set = false;

  iASMemInner = 0;
  iASMemOuter = 0;
  iSPMem = 0;
  done = false;

// Determine the correct stub-pair memory and stub-pair indices for stub pairs
// where the inner index corresponds to all-stubs memory 0.
  index_00: for (TC::Types::nSPMem j = 0; j < NSPMem00; j++) {
    if (!set && iSP >= stubPairs00[j].getEntries(bx))
      iSP -= stubPairs00[j].getEntries(bx), iSPMem++;
    else
      set = true;
  }

// Determine the correct stub-pair memory and stub-pair indices for stub pairs
// where the inner index corresponds to all-stubs memory 1.
  if (iSPMem == NSPMem00) {
    iSPMem = 0, iASMemInner = 1;
    index_10: for (TC::Types::nSPMem j = 0; j < NSPMem10; j++) {
      if (!set && iSP >= stubPairs10[j].getEntries(bx))
        iSP -= stubPairs10[j].getEntries(bx), iSPMem++;
      else
        set = true;
    }
    if (iSPMem == NSPMem10)
      done = true;
  }
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

// This is the primary interface for the TrackletCalculator.
template<uint8_t NSPMem00, uint8_t NSPMem10> void
TrackletCalculator_L1L2(
    const BXType bx,
    const TC::Types::iTC iTC,
    const AllStubMemory<BARRELPS> innerStubs[TC::kNInnerStubMems],
    const AllStubMemory<BARRELPS> outerStubs[TC::kNOuterStubMems],
    const StubPairMemory stubPairs00[NSPMem00],
    const StubPairMemory stubPairs10[NSPMem10],
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
  trackletParameters->clear(bx);
  projout_L3PHIA->clear(bx);
  projout_L3PHIB->clear(bx);
  projout_L3PHIC->clear(bx);
  projout_L3PHID->clear(bx);
  projout_L4PHIA->clear(bx);
  projout_L4PHIB->clear(bx);
  projout_L4PHIC->clear(bx);
  projout_L4PHID->clear(bx);
  projout_L5PHIA->clear(bx);
  projout_L5PHIB->clear(bx);
  projout_L5PHIC->clear(bx);
  projout_L5PHID->clear(bx);
  projout_L6PHIA->clear(bx);
  projout_L6PHIB->clear(bx);
  projout_L6PHIC->clear(bx);
  projout_L6PHID->clear(bx);
  projout_D1PHIA->clear(bx);
  projout_D1PHIB->clear(bx);
  projout_D1PHIC->clear(bx);
  projout_D1PHID->clear(bx);
  projout_D2PHIA->clear(bx);
  projout_D2PHIB->clear(bx);
  projout_D2PHIC->clear(bx);
  projout_D2PHID->clear(bx);
  projout_D3PHIA->clear(bx);
  projout_D3PHIB->clear(bx);
  projout_D3PHIC->clear(bx);
  projout_D3PHID->clear(bx);
  projout_D4PHIA->clear(bx);
  projout_D4PHIB->clear(bx);
  projout_D4PHIC->clear(bx);
  projout_D4PHID->clear(bx);

  const TC::Types::nSP N = (NSPMem00 + NSPMem10) * (1 << kNBits_MemAddr);

  TC::Types::nASMem iASMemInner;
  TC::Types::nASMem iASMemOuter;
  TC::Types::nSPMem iSPMem;
  TC::Types::nSP iSP;
  bool done;

  StubPair::SPInnerIndex innerIndex;
  StubPair::SPOuterIndex outerIndex;
  const TrackletProjection<BARRELPS>::TProjTCID TCID = TC::ID<TC::L1L2>(iTC);

// Loop over all stub pairs.
  stub_pairs: for (TC::Types::nSP i = 0; i < N; i++) {
#pragma HLS pipeline II=1

    iSP = i;
    TC::getIndices<NSPMem00, NSPMem10>(bx, stubPairs00, stubPairs10, iASMemInner, iASMemOuter, iSPMem, iSP, done);

    if (!done) {
// Retrieve the inner and outer stubs for this stub pair.
      innerIndex = (iASMemInner == 0 ? stubPairs00[iSPMem].read_mem(bx, iSP).getInnerIndex() : stubPairs10[iSPMem].read_mem(bx, iSP).getInnerIndex());
      outerIndex = (iASMemInner == 0 ? stubPairs00[iSPMem].read_mem(bx, iSP).getOuterIndex() : stubPairs10[iSPMem].read_mem(bx, iSP).getOuterIndex());
      const AllStub<BARRELPS> &innerStub = innerStubs[iASMemInner].read_mem(bx, innerIndex);
      const AllStub<BARRELPS> &outerStub = outerStubs[iASMemOuter].read_mem(bx, outerIndex);

      TC::processStubPair<TC::L1L2>(bx, innerIndex, innerStub, outerIndex, outerStub, TCID, trackletParameters, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);
    }
  }
}

// Wrapper function for TrackletCalculator_L1L25, 8>, since Vivado HLS
// apparently does not like template parameters in the top function.
void TrackletCalculator_L1L2_5_8(
    const BXType bx,
    const TC::Types::iTC iTC,
    const AllStubMemory<BARRELPS> innerStubs[TC::kNInnerStubMems],
    const AllStubMemory<BARRELPS> outerStubs[TC::kNOuterStubMems],
    const StubPairMemory stubPairs00[5],
    const StubPairMemory stubPairs10[8],
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
) {
  TrackletCalculator_L1L2<5, 8>(
    bx,
    iTC,
    innerStubs,
    outerStubs,
    stubPairs00,
    stubPairs10,
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
