#include "TrackletCalculator.hh"

// This function calls TC_L1L2, defined in TC_L1L2.cpp and applies cuts to the
// results.
template<> bool
TC_barrelSeeding<L1L2>(const AllStub &innerStub, const AllStub &outerStub, TC_rinv * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t, TC_phiL phiL[4], TC_zL zL[4], TC_der_phiL * const der_phiL, TC_der_zL * const der_zL, TC_flag valid_proj[4], TC_phiD phiD[4], TC_rD rD[4], TC_der_phiD * const der_phiD, TC_der_rD * const der_rD, TC_flag valid_proj_disk[4])
{
  TC_rmean rproj[4] = {RMEAN[L3], RMEAN[L4], RMEAN[L5], RMEAN[L6]};
  TC_zmean zproj[4] = {ZMEAN[D1], ZMEAN[D2], ZMEAN[D3], ZMEAN[D4]};

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
  for (ap_uint<3> i = 0; i < 4; i++) {
    valid_proj[i] = true;
    if (zL[i] < -(1 << (TrackletProjection<INNER>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (zL[i] >= (1 << (TrackletProjection<INNER>::kTProjRZSize - 1)))
      valid_proj[i] = false;
    if (phiL[i] >= ((1 << TrackletProjection<OUTER>::kTProjPhiSize) - 1)) {
      phiL[i] = ((1 << TrackletProjection<OUTER>::kTProjPhiSize) - 2);
      valid_proj[i] = false;
    }
    if (rproj[i] < 2048) {
      phiL[i] >>= (TrackletProjection<OUTER>::kTProjPhiSize - TrackletProjection<INNER>::kTProjPhiSize);
      if (phiL[i] >= (1 << TrackletProjection<INNER>::kTProjPhiSize) - 1)
        phiL[i] = (1 << TrackletProjection<INNER>::kTProjPhiSize) - 2;
    }
    else
      zL[i] >>= (TrackletProjection<INNER>::kTProjRZSize - TrackletProjection<OUTER>::kTProjRZSize);
    if (phiL[i] <= 0) {
      phiL[i] = 1;
      valid_proj[i] = false;
    }
  }

// Determine which disk projections are valid.
  for (ap_uint<3> i = 0; i < 4; i++) {
    valid_proj_disk[i] = true;
    if (abs(*t) < 512)
      valid_proj_disk[i] = false;
    if (phiD[i] < 0) {
      phiD[i] = 0;
      valid_proj_disk[i] = false;
    }
    if (phiD[i] >= (1 << TrackletProjection<INNER>::kTProjPhiSize)) {
      phiD[i] = (1 << TrackletProjection<INNER>::kTProjPhiSize) - 1;
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

template<seed Seed> const TrackletProjection<INNER>::TProjTCID
TC_ID(const TC_iTC iTC)
{
  return ((TrackletProjection<INNER>::TProjTCID(Seed) << 4) + iTC);
}

template<tProjType TProjType> bool
addProj(const TrackletProjection<TProjType> &proj, const BXType bx, TrackletProjectionMemory<TProjType> * const projout_PHIA, TrackletProjectionMemory<TProjType> * const projout_PHIB, TrackletProjectionMemory<TProjType> * const projout_PHIC, TrackletProjectionMemory<TProjType> * const projout_PHID)
{
  bool success = true;

// Reject projections with extreme r/z values.
  if ((proj.getRZ() == (-(1 << (TrackletProjection<TProjType>::kTProjRZSize - 1))) || (proj.getRZ() == ((1 << (TrackletProjection<TProjType>::kTProjRZSize - 1)) - 1))))
    success = false;
  if (abs(proj.getRZ()) > 2048)
    success = false;

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  TC_phiL phi = proj.getPhi() >> (TrackletProjection<TProjType>::kTProjPhiSize - 5);
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

template<> bool
addProj<DISK>(const TrackletProjection<DISK> &proj, const BXType bx, TrackletProjectionMemory<DISK> * const projout_PHIA, TrackletProjectionMemory<DISK> * const projout_PHIB, TrackletProjectionMemory<DISK> * const projout_PHIC, TrackletProjectionMemory<DISK> * const projout_PHID)
{
  bool success = true;

// Reject projections with extreme r/z values.
  if (proj.getRZ() < 205 || proj.getRZ() > 1911)
    success = false;

// Fill correct TrackletProjectionMemory according to phi bin of projection.
  TC_phiL phi = proj.getPhi() >> (TrackletProjection<DISK>::kTProjPhiSize - 5);
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

// This is the primary interface for the TrackletCalculator.
template<> void
TrackletCalculator<L1L2>(
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

  StubPair::SPInnerIndex innerIndex;
  StubPair::SPOuterIndex outerIndex;
  TC_rinv rinv;
  TrackletParameters::PHI0PAR phi0;
  TrackletParameters::Z0PAR z0;
  TrackletParameters::TPAR t;
  TC_phiL phiL[4];
  TC_zL zL[4];
  TC_der_phiL der_phiL;
  TC_der_zL der_zL;
  TC_flag valid_proj[4];
  TC_phiD phiD[4];
  TC_rD rD[4];
  TC_der_phiD der_phiD;
  TC_der_rD der_rD;
  TC_flag valid_proj_disk[4];
  bool success;
  TrackletProjection<INNER>::TProjTrackletIndex trackletIndex = 0;

// Loop over stub pairs that use the inner stubs memory at index 0 and the
// outer stubs memory at index 0.
  for (ap_uint<5> i = 0; i < kNStubPairMems; i++) {
    for (ap_uint<kNBits_MemAddr+1> j = 0; j < stubPairs00[i].getDepth(); j++) {
      if (j >= stubPairs00[i].getEntries(bx))
        continue;

// Retrieve the inner and outer stubs for this stub pair.
      innerIndex = stubPairs00[i].read_mem(bx, j).getInnerIndex();
      outerIndex = stubPairs00[i].read_mem(bx, j).getOuterIndex();
      const AllStub &innerStub = innerStubs[0].read_mem(bx, innerIndex);
      const AllStub &outerStub = outerStubs[0].read_mem(bx, outerIndex);

// Calculate the tracklet parameters and projections.
      success = TC_barrelSeeding<L1L2>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);

// Write the tracklet parameters and projections to the output memories.
      if (success) {
        TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
        trackletParameters->write_mem(bx, tpar);

        bool addL3 = false, addL4 = false, addL5 = false, addL6 = false;

        if (valid_proj[0]) {
          TrackletProjection<INNER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
          addL3 = addProj<INNER>(tproj, bx, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID);
        }
        if (valid_proj[1]) {
          TrackletProjection<OUTER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
          addL4 = addProj<OUTER>(tproj, bx, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID);
        }
        if (valid_proj[2]) {
          TrackletProjection<OUTER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
          addL5 = addProj<OUTER>(tproj, bx, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID);
        }
        if (valid_proj[3]) {
          TrackletProjection<OUTER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[3], zL[3], der_phiL, der_zL);
          addL6 = addProj<OUTER>(tproj, bx, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID);
        }

        if (valid_proj_disk[0] && !addL6) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID);
        }
        if (valid_proj_disk[1] && !addL5) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID);
        }
        if (valid_proj_disk[2] && !addL4) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[2], rD[2], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID);
        }
        if (valid_proj_disk[3] && !addL3) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[3], rD[3], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);
        }

        trackletIndex++;
      }
    }
  }

// Loop over stub pairs that use the inner stubs memory at index 1 and the
// outer stubs memory at index 0.
  for (ap_uint<5> i = 0; i < kNStubPairMems; i++) {
    for (ap_uint<kNBits_MemAddr+1> j = 0; j < stubPairs10[i].getDepth(); j++) {
      if (j >= stubPairs10[i].getEntries(bx))
        continue;

// Retrieve the inner and outer stubs for this stub pair.
      innerIndex = stubPairs10[i].read_mem(bx, j).getInnerIndex();
      outerIndex = stubPairs10[i].read_mem(bx, j).getOuterIndex();
      const AllStub &innerStub = innerStubs[1].read_mem(bx, innerIndex);
      const AllStub &outerStub = outerStubs[0].read_mem(bx, outerIndex);

// Calculate the tracklet parameters and projections.
      success = TC_barrelSeeding<L1L2>(innerStub, outerStub, &rinv, &phi0, &z0, &t, phiL, zL, &der_phiL, &der_zL, valid_proj, phiD, rD, &der_phiD, &der_rD, valid_proj_disk);

// Write the tracklet parameters and projections to the output memories.
      if (success) {
        TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
        trackletParameters->write_mem(bx, tpar);

        bool addL3 = false, addL4 = false, addL5 = false, addL6 = false;

        if (valid_proj[0]) {
          TrackletProjection<INNER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[0], zL[0], der_phiL, der_zL);
          addL3 = addProj<INNER>(tproj, bx, projout_L3PHIA, projout_L3PHIB, projout_L3PHIC, projout_L3PHID);
        }
        if (valid_proj[1]) {
          TrackletProjection<OUTER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[1], zL[1], der_phiL, der_zL);
          addL4 = addProj<OUTER>(tproj, bx, projout_L4PHIA, projout_L4PHIB, projout_L4PHIC, projout_L4PHID);
        }
        if (valid_proj[2]) {
          TrackletProjection<OUTER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[2], zL[2], der_phiL, der_zL);
          addL5 = addProj<OUTER>(tproj, bx, projout_L5PHIA, projout_L5PHIB, projout_L5PHIC, projout_L5PHID);
        }
        if (valid_proj[3]) {
          TrackletProjection<OUTER> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiL[3], zL[3], der_phiL, der_zL);
          addL6 = addProj<OUTER>(tproj, bx, projout_L6PHIA, projout_L6PHIB, projout_L6PHIC, projout_L6PHID);
        }

        if (valid_proj_disk[0] && !addL6) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[0], rD[0], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D1PHIA, projout_D1PHIB, projout_D1PHIC, projout_D1PHID);
        }
        if (valid_proj_disk[1] && !addL5) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[1], rD[1], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D2PHIA, projout_D2PHIB, projout_D2PHIC, projout_D2PHID);
        }
        if (valid_proj_disk[2] && !addL4) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[2], rD[2], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D3PHIA, projout_D3PHIB, projout_D3PHIC, projout_D3PHID);
        }
        if (valid_proj_disk[3] && !addL3) {
          TrackletProjection<DISK> tproj(TC_ID<L1L2>(iTC), trackletIndex, phiD[3], rD[3], der_phiD, der_rD);
          addProj<DISK>(tproj, bx, projout_D4PHIA, projout_D4PHIB, projout_D4PHIC, projout_D4PHID);
        }

        trackletIndex++;
      }
    }
  }
}

// Wrapper function for TrackletCalculator<L1L2>, since Vivado HLS apparently
// does not like template parameters in the top function.
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
) {
  TrackletCalculator<L1L2>(
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
