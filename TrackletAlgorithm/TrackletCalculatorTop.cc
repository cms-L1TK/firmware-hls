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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::A>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::A>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::A>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::A>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::B>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::B>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::B>()],
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
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::B>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::C>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::C>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::C>()],
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
  NSPMem<TF::L1L2, TC::C>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::D>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::D>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::D>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::D>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::E>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::E>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::E>()],
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
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::E>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::F>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::F>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::F>()],
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

TC_L1L2F: TrackletCalculator<
  TF::L1L2,
  TC::F,
  NSPMem<TF::L1L2, TC::F>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::G>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::G>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::G>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::G>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::H>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::H>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::H>()],
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
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::H>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::I>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::I>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::I>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::I>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::J>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::J>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::J>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::J>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::K>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::K>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::K>()],
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
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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

TC_L1L2K: TrackletCalculator<
  TF::L1L2,
  TC::K,
  NSPMem<TF::L1L2, TC::K>()
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
    const AllStubMemory<InnerRegion<TF::L1L2>()> innerStubs[NASMemInner<TF::L1L2, TC::L>()],
    const AllStubMemory<OuterRegion<TF::L1L2>()> outerStubs[NASMemOuter<TF::L1L2, TC::L>()],
    const StubPairMemory stubPairs[NSPMem<TF::L1L2, TC::L>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
  NSPMem<TF::L1L2, TC::L>()
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
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::A>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::A>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::A>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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

TC_L3L4A: TrackletCalculator<
  TF::L3L4,
  TC::A,
  NSPMem<TF::L3L4, TC::A>()
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

void TrackletCalculator_L3L4B(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::B>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::B>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::B>()],
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
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4B: TrackletCalculator<
  TF::L3L4,
  TC::B,
  NSPMem<TF::L3L4, TC::B>()
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

void TrackletCalculator_L3L4C(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::C>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::C>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::C>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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

TC_L3L4C: TrackletCalculator<
  TF::L3L4,
  TC::C,
  NSPMem<TF::L3L4, TC::C>()
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
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::D>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::D>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::D>()],
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
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4D: TrackletCalculator<
  TF::L3L4,
  TC::D,
  NSPMem<TF::L3L4, TC::D>()
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

void TrackletCalculator_L3L4E(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::E>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::E>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::E>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4E: TrackletCalculator<
  TF::L3L4,
  TC::E,
  NSPMem<TF::L3L4, TC::E>()
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

void TrackletCalculator_L3L4F(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::F>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::F>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::F>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
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
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4F: TrackletCalculator<
  TF::L3L4,
  TC::F,
  NSPMem<TF::L3L4, TC::F>()
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

void TrackletCalculator_L3L4G(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::G>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::G>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::G>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
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
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4G: TrackletCalculator<
  TF::L3L4,
  TC::G,
  NSPMem<TF::L3L4, TC::G>()
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

void TrackletCalculator_L3L4H(
    const BXType bx,
    const AllStubMemory<InnerRegion<TF::L3L4>()> innerStubs[NASMemInner<TF::L3L4, TC::H>()],
    const AllStubMemory<OuterRegion<TF::L3L4>()> outerStubs[NASMemOuter<TF::L3L4, TC::H>()],
    const StubPairMemory stubPairs[NSPMem<TF::L3L4, TC::H>()],
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
#pragma HLS resource variable=innerStubs.get_mem() latency=2
#pragma HLS resource variable=outerStubs.get_mem() latency=2
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
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=projout_barrel_ps complete dim=1
#pragma HLS array_partition variable=projout_barrel_2s complete dim=1
#pragma HLS array_partition variable=projout_disk complete dim=1

TC_L3L4H: TrackletCalculator<
  TF::L3L4,
  TC::H,
  NSPMem<TF::L3L4, TC::H>()
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
    const AllStubMemory<InnerRegion<TF::L5L6>()> innerStubs[NASMemInner<TF::L5L6, TC::A>()],
    const AllStubMemory<OuterRegion<TF::L5L6>()> outerStubs[NASMemOuter<TF::L5L6, TC::A>()],
    const StubPairMemory stubPairs[NSPMem<TF::L5L6, TC::A>()],
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
  NSPMem<TF::L5L6, TC::A>()
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
    const AllStubMemory<InnerRegion<TF::L5L6>()> innerStubs[NASMemInner<TF::L5L6, TC::D>()],
    const AllStubMemory<OuterRegion<TF::L5L6>()> outerStubs[NASMemOuter<TF::L5L6, TC::D>()],
    const StubPairMemory stubPairs[NSPMem<TF::L5L6, TC::D>()],
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
  NSPMem<TF::L5L6, TC::D>()
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
