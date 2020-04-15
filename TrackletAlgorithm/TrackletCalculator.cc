#include "TrackletCalculator.h"

////////////////////////////////////////////////////////////////////////////////
// Top functions for various TrackletCalculators (TC). For each iteration of
// the main processing loop, a TC retrieves a pair of stub indices from one of
// the stub-pair memories, and in turn, these indices are used to retrieve one
// stub each from an inner and an outer all-stub memory. This pair of stubs is
// used to calculate a rough set of helix parameters, which are written to the
// tracklet-parameter memory if the tracklet passes cuts on rinv and z0. Rough
// projections to additional layers and disks are also calculated and are
// written to the appropriate tracklet-projection memories.
////////////////////////////////////////////////////////////////////////////////
void TrackletCalculator_L1L2E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[2],
    const AllStubMemory<BARRELPS> outerStubs[1],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
#pragma HLS resource variable=stubPairs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete
#pragma HLS array_partition variable=projout_barrel_2s complete
#pragma HLS array_partition variable=projout_disk complete

  TC_L1L2E: TrackletCalculator<TC::L1L2, TC::E, BARRELPS, BARRELPS, 2, 1, 13, 0x1FE0, 0x0000, 0x7772000, 0x7777, kMaxProc>(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2G(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<BARRELPS> outerStubs[2],
    const StubPairMemory stubPairs[13],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
#pragma HLS resource variable=stubPairs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete
#pragma HLS array_partition variable=projout_barrel_2s complete
#pragma HLS array_partition variable=projout_disk complete

  TC_L1L2G: TrackletCalculator<TC::L1L2, TC::G, BARRELPS, BARRELPS, 1, 2, 13, 0x0000, 0x1FEE, 0xEEE6000, 0xEEEE, kMaxProc>(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L3L4E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[1],
    const AllStubMemory<BARREL2S> outerStubs[2],
    const StubPairMemory stubPairs[11],
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
#pragma HLS resource variable=stubPairs.get_mem() latency=2
#pragma HLS array_partition variable=projout_barrel_ps complete
#pragma HLS array_partition variable=projout_barrel_2s complete
#pragma HLS array_partition variable=projout_disk complete

  TC_L3L4E: TrackletCalculator<TC::L3L4, TC::E, BARRELPS, BARREL2S, 1, 2, 11, 0x0000, 0x7FE, 0xE600478, 0xEE, kMaxProc>(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}
////////////////////////////////////////////////////////////////////////////////
