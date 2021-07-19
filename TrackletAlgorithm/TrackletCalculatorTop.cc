#include "TrackletCalculatorTop.h"

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

void TrackletCalculator_L1L2A(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[1],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2A: TrackletCalculator<
  TF::L1L2,
  TC::A,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2B(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[1],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2B: TrackletCalculator<
  TF::L1L2,
  TC::B,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2C(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[2],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2C: TrackletCalculator<
  TF::L1L2,
  TC::C,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2D(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[2],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2D: TrackletCalculator<
  TF::L1L2,
  TC::D,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2E(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[1],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2E: TrackletCalculator<
  TF::L1L2,
  TC::E,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2F(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[2],
    const StubPairMemory stubPairs[12],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2F: TrackletCalculator<
  TF::L1L2,
  TC::F,
  12
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2G(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[2],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2G: TrackletCalculator<
  TF::L1L2,
  TC::G,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2H(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[1],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2H: TrackletCalculator<
  TF::L1L2,
  TC::H,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2I(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[2],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2I: TrackletCalculator<
  TF::L1L2,
  TC::I,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2J(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[2],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2J: TrackletCalculator<
  TF::L1L2,
  TC::J,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2K(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[1],
    const StubPairMemory stubPairs[13],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2K: TrackletCalculator<
  TF::L1L2,
  TC::K,
  13
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L1L2L(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[1],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[1],
    const StubPairMemory stubPairs[12],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L1L2L: TrackletCalculator<
  TF::L1L2,
  TC::L,
  12
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L3L4A(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[2],
    const StubPairMemory stubPairs[23],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS resource variable=stubPairs[13].get_mem() latency=2
#pragma HLS resource variable=stubPairs[14].get_mem() latency=2
#pragma HLS resource variable=stubPairs[15].get_mem() latency=2
#pragma HLS resource variable=stubPairs[16].get_mem() latency=2
#pragma HLS resource variable=stubPairs[17].get_mem() latency=2
#pragma HLS resource variable=stubPairs[18].get_mem() latency=2
#pragma HLS resource variable=stubPairs[19].get_mem() latency=2
#pragma HLS resource variable=stubPairs[20].get_mem() latency=2
#pragma HLS resource variable=stubPairs[21].get_mem() latency=2
#pragma HLS resource variable=stubPairs[22].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4A: TrackletCalculator<
  TF::L3L4,
  TC::A,
  23
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L3L4D(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[2],
    const StubPairMemory stubPairs[23],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS resource variable=stubPairs[13].get_mem() latency=2
#pragma HLS resource variable=stubPairs[14].get_mem() latency=2
#pragma HLS resource variable=stubPairs[15].get_mem() latency=2
#pragma HLS resource variable=stubPairs[16].get_mem() latency=2
#pragma HLS resource variable=stubPairs[17].get_mem() latency=2
#pragma HLS resource variable=stubPairs[18].get_mem() latency=2
#pragma HLS resource variable=stubPairs[19].get_mem() latency=2
#pragma HLS resource variable=stubPairs[20].get_mem() latency=2
#pragma HLS resource variable=stubPairs[21].get_mem() latency=2
#pragma HLS resource variable=stubPairs[22].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4D: TrackletCalculator<
  TF::L3L4,
  TC::D,
  23
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L5L6A(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L5L6>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L5L6>()> outerStubs[2],
    const StubPairMemory stubPairs[30],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS resource variable=stubPairs[13].get_mem() latency=2
#pragma HLS resource variable=stubPairs[14].get_mem() latency=2
#pragma HLS resource variable=stubPairs[15].get_mem() latency=2
#pragma HLS resource variable=stubPairs[16].get_mem() latency=2
#pragma HLS resource variable=stubPairs[17].get_mem() latency=2
#pragma HLS resource variable=stubPairs[18].get_mem() latency=2
#pragma HLS resource variable=stubPairs[19].get_mem() latency=2
#pragma HLS resource variable=stubPairs[20].get_mem() latency=2
#pragma HLS resource variable=stubPairs[21].get_mem() latency=2
#pragma HLS resource variable=stubPairs[22].get_mem() latency=2
#pragma HLS resource variable=stubPairs[23].get_mem() latency=2
#pragma HLS resource variable=stubPairs[24].get_mem() latency=2
#pragma HLS resource variable=stubPairs[25].get_mem() latency=2
#pragma HLS resource variable=stubPairs[26].get_mem() latency=2
#pragma HLS resource variable=stubPairs[27].get_mem() latency=2
#pragma HLS resource variable=stubPairs[28].get_mem() latency=2
#pragma HLS resource variable=stubPairs[29].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L5L6A: TrackletCalculator<
  TF::L5L6,
  TC::A,
  30
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

void TrackletCalculator_L5L6D(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L5L6>()> innerStubs[2],
    const AllStubMemory<OuterRegion<TF::L5L6>()> outerStubs[2],
    const StubPairMemory stubPairs[30],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],
    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=innerStubs complete dim=1
#pragma HLS array_partition variable=outerStubs complete dim=1
#pragma HLS array_partition variable=stubPairs complete dim=1
#pragma HLS resource variable=innerStubs[0].get_mem() latency=2
#pragma HLS resource variable=innerStubs[1].get_mem() latency=2
#pragma HLS resource variable=outerStubs[0].get_mem() latency=2
#pragma HLS resource variable=outerStubs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[0].get_mem() latency=2
#pragma HLS resource variable=stubPairs[1].get_mem() latency=2
#pragma HLS resource variable=stubPairs[2].get_mem() latency=2
#pragma HLS resource variable=stubPairs[3].get_mem() latency=2
#pragma HLS resource variable=stubPairs[4].get_mem() latency=2
#pragma HLS resource variable=stubPairs[5].get_mem() latency=2
#pragma HLS resource variable=stubPairs[6].get_mem() latency=2
#pragma HLS resource variable=stubPairs[7].get_mem() latency=2
#pragma HLS resource variable=stubPairs[8].get_mem() latency=2
#pragma HLS resource variable=stubPairs[9].get_mem() latency=2
#pragma HLS resource variable=stubPairs[10].get_mem() latency=2
#pragma HLS resource variable=stubPairs[11].get_mem() latency=2
#pragma HLS resource variable=stubPairs[12].get_mem() latency=2
#pragma HLS resource variable=stubPairs[13].get_mem() latency=2
#pragma HLS resource variable=stubPairs[14].get_mem() latency=2
#pragma HLS resource variable=stubPairs[15].get_mem() latency=2
#pragma HLS resource variable=stubPairs[16].get_mem() latency=2
#pragma HLS resource variable=stubPairs[17].get_mem() latency=2
#pragma HLS resource variable=stubPairs[18].get_mem() latency=2
#pragma HLS resource variable=stubPairs[19].get_mem() latency=2
#pragma HLS resource variable=stubPairs[20].get_mem() latency=2
#pragma HLS resource variable=stubPairs[21].get_mem() latency=2
#pragma HLS resource variable=stubPairs[22].get_mem() latency=2
#pragma HLS resource variable=stubPairs[23].get_mem() latency=2
#pragma HLS resource variable=stubPairs[24].get_mem() latency=2
#pragma HLS resource variable=stubPairs[25].get_mem() latency=2
#pragma HLS resource variable=stubPairs[26].get_mem() latency=2
#pragma HLS resource variable=stubPairs[27].get_mem() latency=2
#pragma HLS resource variable=stubPairs[28].get_mem() latency=2
#pragma HLS resource variable=stubPairs[29].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L5L6D: TrackletCalculator<
  TF::L5L6,
  TC::D,
  30
 >(
    bx,
    innerStubs,
    outerStubs,
    stubPairs,
    bx_o,
    trackletParameters,
    projout_barrel_ps,
    projout_barrel_2s,
    projout_disk
  );
}

////////////////////////////////////////////////////////////////////////////////
