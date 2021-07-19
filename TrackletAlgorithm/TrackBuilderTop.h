#ifndef TrackletAlgorithm_TrackBuilderTop_h
#define TrackletAlgorithm_TrackBuilderTop_h

#include "TrackBuilder.h"

void TrackBuilder_D1D2(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<2, 3>::TrackWord trackWord[],
    TrackFit<2, 3>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<2, 3>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_D3D4(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<1, 3>::TrackWord trackWord[],
    TrackFit<1, 3>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<1, 3>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_L1D1(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<0, 4>::TrackWord trackWord[],
    TrackFit<0, 4>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<0, 4>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_L1L2(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<4, 4>::TrackWord trackWord[],
    TrackFit<4, 4>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<4, 4>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_L2D1(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<1, 3>::TrackWord trackWord[],
    TrackFit<1, 3>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<1, 3>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_L2L3(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<3, 4>::TrackWord trackWord[],
    TrackFit<3, 4>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<3, 4>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_L3L4(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<4, 2>::TrackWord trackWord[],
    TrackFit<4, 2>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<4, 2>::DiskStubWord diskStubWords[][kMaxProc]
);

void TrackBuilder_L5L6(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[],
    const FullMatchMemory<BARREL> barrelFullMatches[],
    const FullMatchMemory<DISK> diskFullMatches[],
    BXType &bx_o,
    TrackFit<4, 0>::TrackWord trackWord[],
    TrackFit<4, 0>::BarrelStubWord barrelStubWords[][kMaxProc],
    TrackFit<4, 0>::DiskStubWord diskStubWords[][kMaxProc]
);

#endif
