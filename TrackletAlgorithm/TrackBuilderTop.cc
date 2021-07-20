#include "TrackBuilderTop.h"

void TrackBuilder_D1D2(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[4],
    const FullMatchMemory<BARREL> barrelFullMatches[12],
    const FullMatchMemory<DISK> diskFullMatches[12],
    BXType &bx_o,
    TrackFit<2, 3>::TrackWord trackWord[kMaxProc],
    TrackFit<2, 3>::BarrelStubWord barrelStubWords[2][kMaxProc],
    TrackFit<2, 3>::DiskStubWord diskStubWords[3][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[11].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_D1D2: TrackBuilder<12, 12, 2, 3>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_D3D4(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[4],
    const FullMatchMemory<BARREL> barrelFullMatches[8],
    const FullMatchMemory<DISK> diskFullMatches[12],
    BXType &bx_o,
    TrackFit<1, 3>::TrackWord trackWord[kMaxProc],
    TrackFit<1, 3>::BarrelStubWord barrelStubWords[1][kMaxProc],
    TrackFit<1, 3>::DiskStubWord diskStubWords[3][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[11].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_D3D4: TrackBuilder<8, 12, 1, 3>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_L1D1(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[8],
    const FullMatchMemory<BARREL> barrelFullMatches[0],
    const FullMatchMemory<DISK> diskFullMatches[16],
    BXType &bx_o,
    TrackFit<0, 4>::TrackWord trackWord[kMaxProc],
    TrackFit<0, 4>::BarrelStubWord barrelStubWords[0][kMaxProc],
    TrackFit<0, 4>::DiskStubWord diskStubWords[4][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[4].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[5].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[6].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[15].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_L1D1: TrackBuilder<0, 16, 0, 4>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_L1L2(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[12],
    const FullMatchMemory<BARREL> barrelFullMatches[16],
    const FullMatchMemory<DISK> diskFullMatches[16],
    BXType &bx_o,
    TrackFit<4, 4>::TrackWord trackWord[kMaxProc],
    TrackFit<4, 4>::BarrelStubWord barrelStubWords[4][kMaxProc],
    TrackFit<4, 4>::DiskStubWord diskStubWords[4][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[4].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[5].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[6].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[7].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[8].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[9].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[10].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[11].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[15].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[15].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_L1L2: TrackBuilder<16, 16, 4, 4>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_L2D1(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[4],
    const FullMatchMemory<BARREL> barrelFullMatches[8],
    const FullMatchMemory<DISK> diskFullMatches[12],
    BXType &bx_o,
    TrackFit<1, 3>::TrackWord trackWord[kMaxProc],
    TrackFit<1, 3>::BarrelStubWord barrelStubWords[1][kMaxProc],
    TrackFit<1, 3>::DiskStubWord diskStubWords[3][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[11].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_L2D1: TrackBuilder<8, 12, 1, 3>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_L2L3(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[4],
    const FullMatchMemory<BARREL> barrelFullMatches[16],
    const FullMatchMemory<DISK> diskFullMatches[16],
    BXType &bx_o,
    TrackFit<3, 4>::TrackWord trackWord[kMaxProc],
    TrackFit<3, 4>::BarrelStubWord barrelStubWords[3][kMaxProc],
    TrackFit<3, 4>::DiskStubWord diskStubWords[4][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[15].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[15].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_L2L3: TrackBuilder<16, 16, 3, 4>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_L3L4(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[4],
    const FullMatchMemory<BARREL> barrelFullMatches[20],
    const FullMatchMemory<DISK> diskFullMatches[8],
    BXType &bx_o,
    TrackFit<4, 2>::TrackWord trackWord[kMaxProc],
    TrackFit<4, 2>::BarrelStubWord barrelStubWords[4][kMaxProc],
    TrackFit<4, 2>::DiskStubWord diskStubWords[2][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[15].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[16].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[17].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[18].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[19].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=diskFullMatches[7].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_L3L4: TrackBuilder<20, 8, 4, 2>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}

void TrackBuilder_L5L6(
    const BXType bx,
    const TrackletParameterMemory trackletParameters[4],
    const FullMatchMemory<BARREL> barrelFullMatches[20],
    const FullMatchMemory<DISK> diskFullMatches[0],
    BXType &bx_o,
    TrackFit<4, 0>::TrackWord trackWord[kMaxProc],
    TrackFit<4, 0>::BarrelStubWord barrelStubWords[4][kMaxProc],
    TrackFit<4, 0>::DiskStubWord diskStubWords[0][kMaxProc]
) {
#pragma HLS inline recursive
#pragma HLS array_partition variable=trackletParameters complete dim=1
#pragma HLS array_partition variable=barrelFullMatches complete dim=1
#pragma HLS array_partition variable=diskFullMatches complete dim=1
#pragma HLS resource variable=trackletParameters[0].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[1].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[2].get_mem() latency=2
#pragma HLS resource variable=trackletParameters[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[0].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[1].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[2].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[3].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[4].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[5].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[6].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[7].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[8].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[9].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[10].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[11].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[12].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[13].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[14].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[15].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[16].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[17].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[18].get_mem() latency=2
#pragma HLS resource variable=barrelFullMatches[19].get_mem() latency=2
#pragma HLS interface register port=bx_o
#pragma HLS array_partition variable=barrelStubWords complete dim=1
#pragma HLS array_partition variable=diskStubWords complete dim=1
#pragma HLS stream variable=trackWord depth=1 dim=1
#pragma HLS stream variable=barrelStubWords depth=1 dim=2
#pragma HLS stream variable=diskStubWords depth=1 dim=2

TB_L5L6: TrackBuilder<20, 0, 4, 0>(
    bx,
    trackletParameters,
    barrelFullMatches,
    diskFullMatches,
    bx_o,
    trackWord,
    barrelStubWords,
    diskStubWords
  );
}
