#include "TrackletCalculator.hh"

// This function calls TC_L1L2, defined in TC_L1L2.cpp and applies cuts to the
// results.
template<> bool
TC_barrelSeeding<L1L2>(const AllStub &innerStub, const AllStub &outerStub, TrackletParameters::RINVPAR * const rinv, TrackletParameters::PHI0PAR * const phi0, TrackletParameters::Z0PAR * const z0, TrackletParameters::TPAR * const t)
{
  TC_phiL phiL[4];
  TC_zL zL[4];
  TC_der_phiL der_phiL;
  TC_der_zL der_zL;
  TC_phiD phiD[5];
  TC_rD rD[5];
  TC_der_phiD der_phiD;
  TC_der_rD der_rD;
  TC_flag tpar_flag, phiL_flag[4], zL_flag[4], der_phiL_flag, der_zL_flag, phiD_flag[5], rD_flag[5], der_phiD_flag, der_rD_flag;

  TC_L1L2(
      innerStub.getR(),
      innerStub.getPhi(),
      innerStub.getZ(),
      outerStub.getR(),
      outerStub.getPhi(),
      outerStub.getZ(),
      RMEAN[L3],
      RMEAN[L4],
      RMEAN[L5],
      RMEAN[L6],
      ZMEAN[D1],
      ZMEAN[D2],
      ZMEAN[D3],
      ZMEAN[D4],
      ZMEAN[D5],

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
      &der_phiL,
      &der_zL,
      &phiD[0],
      &phiD[1],
      &phiD[2],
      &phiD[3],
      &phiD[4],
      &rD[0],
      &rD[1],
      &rD[2],
      &rD[3],
      &rD[4],
      &der_phiD,
      &der_rD,
      &tpar_flag,
      &phiL_flag[0],
      &phiL_flag[1],
      &phiL_flag[2],
      &phiL_flag[3],
      &zL_flag[0],
      &zL_flag[1],
      &zL_flag[2],
      &zL_flag[3],
      &der_phiL_flag,
      &der_zL_flag,
      &phiD_flag[0],
      &phiD_flag[1],
      &phiD_flag[2],
      &phiD_flag[3],
      &phiD_flag[4],
      &rD_flag[0],
      &rD_flag[1],
      &rD_flag[2],
      &rD_flag[3],
      &rD_flag[4],
      &der_phiD_flag,
      &der_rD_flag
  );

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

// This is the primary interface for the TrackletCalculator.
template<> void
TrackletCalculator<L1L2>(
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
)
{
// Loop over stub pairs that use the inner stubs memory at index 0 and the
// outer stubs memory at index 0.
  for (ap_uint<5> i = 0; i < kNStubPairMems; i++) {
    for (ap_uint<kNBits_MemAddr+1> j = 0; j < stubPairs00[i].getDepth(); j++) {
      if (j >= stubPairs00[i].getEntries(bx))
        continue;
      StubPair::SPInnerIndex innerIndex;
      StubPair::SPOuterIndex outerIndex;

// Retrieve the inner and outer stubs for this stub pair.
      innerIndex = stubPairs00[i].read_mem(bx, j).getInnerIndex();
      outerIndex = stubPairs00[i].read_mem(bx, j).getOuterIndex();
      const AllStub &innerStub = innerStubs[0].read_mem(bx, innerIndex);
      const AllStub &outerStub = outerStubs[0].read_mem(bx, outerIndex);

// Calculate the tracklet parameters and projections.
      TrackletParameters::RINVPAR rinv;
      TrackletParameters::PHI0PAR phi0;
      TrackletParameters::Z0PAR z0;
      TrackletParameters::TPAR t;
      bool success = TC_barrelSeeding<L1L2>(innerStub, outerStub, &rinv, &phi0, &z0, &t);

// Write the tracklet parameters and projections to the output memories.
      if (success) {
        TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
        trackletParameters->write_mem(bx, tpar);
      }
    }
  }

// Loop over stub pairs that use the inner stubs memory at index 1 and the
// outer stubs memory at index 0.
  for (ap_uint<5> i = 0; i < kNStubPairMems; i++) {
    for (ap_uint<kNBits_MemAddr+1> j = 0; j < stubPairs10[i].getDepth(); j++) {
      if (j >= stubPairs10[i].getEntries(bx))
        continue;
      StubPair::SPInnerIndex innerIndex;
      StubPair::SPOuterIndex outerIndex;

// Retrieve the inner and outer stubs for this stub pair.
      innerIndex = stubPairs10[i].read_mem(bx, j).getInnerIndex();
      outerIndex = stubPairs10[i].read_mem(bx, j).getOuterIndex();
      const AllStub &innerStub = innerStubs[1].read_mem(bx, innerIndex);
      const AllStub &outerStub = outerStubs[0].read_mem(bx, outerIndex);

// Calculate the tracklet parameters and projections.
      TrackletParameters::RINVPAR rinv;
      TrackletParameters::PHI0PAR phi0;
      TrackletParameters::Z0PAR z0;
      TrackletParameters::TPAR t;
      bool success = TC_barrelSeeding<L1L2>(innerStub, outerStub, &rinv, &phi0, &z0, &t);

// Write the tracklet parameters and projections to the output memories.
      if (success) {
        TrackletParameters tpar(innerIndex, outerIndex, rinv, phi0, z0, t);
        trackletParameters->write_mem(bx, tpar);
      }
    }
  }
}

// Wrapper function for TrackletCalculator<L1L2>, since Vivado HLS apparently
// does not like template parameters in the top function.
void TrackletCalculator_L1L2(
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
) {
  TrackletCalculator<L1L2>(
    bx,
    innerStubs,
    outerStubs,
    stubPairs00,
    stubPairs10,
    trackletParameters,
    projout_L1PHIA,
    projout_L1PHIB,
    projout_L1PHIC,
    projout_L1PHID,
    projout_L1PHIE,
    projout_L1PHIF,
    projout_L1PHIG,
    projout_L1PHIH,
    projout_L2PHIA,
    projout_L2PHIB,
    projout_L2PHIC,
    projout_L2PHID,
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
    projout_D4PHID,
    projout_D5PHIA,
    projout_D5PHIB,
    projout_D5PHIC,
    projout_D5PHID
  );
}
