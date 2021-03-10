#ifndef TrackletAlgorithm_TrackletCalculatorTop_h
#define TrackletAlgorithm_TrackletCalculatorTop_h

#include "TrackletCalculator.h"

void TrackletCalculator_L1L2E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[],
    const AllStubMemory<BARRELPS> outerStubs[],
    const StubPairMemory stubPairs[],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletCalculator_L1L2G(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[],
    const AllStubMemory<BARRELPS> outerStubs[],
    const StubPairMemory stubPairs[],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

void TrackletCalculator_L3L4E(
    const BXType bx,
    const AllStubMemory<BARRELPS> innerStubs[],
    const AllStubMemory<BARREL2S> outerStubs[],
    const StubPairMemory stubPairs[],
    BXType& bx_o,
    TrackletParameterMemory * trackletParameters,
    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],
    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],
    TrackletProjectionMemory<DISK> projout_disk[]
);

#endif
