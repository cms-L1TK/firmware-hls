#include "TrackMerger.h"

void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit::TrackWord trackWord_o [kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]){

    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS stream variable=trackWord depth=1 dim=1
    #pragma HLS stream variable=barrelStubWords depth=1 dim=2
    #pragma HLS stream variable=diskStubWords depth=1 dim=2

    // Comparison module
    // count stubs in common, looking at stubs with smallest phi residual in each layer
    for (unsigned int i = 0; i < kMaxProc; i++){
        TrackFit trkFit;
        trkFit.setTrackWord(trackWord[i]);
        auto trackStubMap = trkFit.getHitMap();
        auto trackHitCount = trkFit.getHitCount();
        //std::cout << "Track Stub Map: " << trackStubMap << std::endl;
        // every 3 bits is a new layer/disk - getting number of stubs in each layer
        for (int layer = 0; layer < trackStubMap.length()/TrackFit::kTFHitCountSize; layer++){
            int stubNumber = trackStubMap.range(trackStubMap.length() - TrackFit::kTFHitCountSize*layer - 1 , trackStubMap.length() - TrackFit::kTFHitCountSize*(layer + 1));
             
             for (unsigned int j = 0; j < TrackFit::kNBarrelStubs - 1; j++){
                 switch (j){
                   case 0:
                     trkFit.setBarrelStubWord<0>(barrelStubWords[0][i]);
                     break;
                   case 1:
                     trkFit.setBarrelStubWord<1>(barrelStubWords[1][i]);
                     break;
                   case 2:
                     trkFit.setBarrelStubWord<2>(barrelStubWords[2][i]);
                     break;
                    case 3:
                     trkFit.setBarrelStubWord<3>(barrelStubWords[3][i]);
                     break;

                 }
             }
            
            for (unsigned int k = TrackFit::kNBarrelStubs; k < TrackFit::kNStubs - 1; k++){
                 switch (k){
                   case 0:
                      trkFit.setDiskStubWord<4>(diskStubWords[0][i]);
                      break;
                   case 1:
                      trkFit.setDiskStubWord<5>(diskStubWords[1][i]);
                      break;
                   case 2:
                      trkFit.setDiskStubWord<6>(diskStubWords[2][i]);
                      break;
                    case 3:
                      trkFit.setDiskStubWord<7>(diskStubWords[3][i]);
                      break;

                 }
            }

            // getting stub index and phi residual
            int stubIndex[TrackFit::kNStubs];
            int phiRes[TrackFit::kNStubs];
            for (int l = 0; l < TrackFit::kNStubs; l++){
              switch (l) {
                case 0:
                  stubIndex[0] = trkFit.getStubIndex<0>();
                  phiRes[0] = trkFit.getStubPhiResid<0>();
                  break;
                case 1:
                  stubIndex[1] = trkFit.getStubIndex<1>();
                  phiRes[1] = trkFit.getStubPhiResid<1>();
                  break;
                case 2:
                  stubIndex[2] = trkFit.getStubIndex<2>();
                  phiRes[2] = trkFit.getStubPhiResid<2>();
                  break;
                case 3: 
                  stubIndex[3] = trkFit.getStubIndex<3>();
                  phiRes[3] = trkFit.getStubPhiResid<3>();
                  break;
                case 4:
                  stubIndex[4] = trkFit.getStubIndex<4>();
                  phiRes[4] = trkFit.getStubPhiResid<4>();
                  break;
                case 5:
                  stubIndex[5] = trkFit.getStubIndex<5>();
                  phiRes[5] = trkFit.getStubPhiResid<5>();
                  break;
                case 6:
                  stubIndex[6] = trkFit.getStubIndex<6>();
                  phiRes[6] = trkFit.getStubPhiResid<6>();
                  break;
                case 7:
                  stubIndex[7] = trkFit.getStubIndex<7>();
                  phiRes[7] = trkFit.getStubPhiResid<7>();
                  break;
              }
            }
            
            // considering smallest phi residual in each layer
            for (int m = stubIndex[0]; m < stubIndex[TrackFit::kNStubs]; m++){
              int min_value = 999;
              for(int i = 0; i < TrackFit::kNStubs; i++){
                 if (phiRes[i] < min_value) min_value = phiRes[i];
              }
              trkFit.setStubPhiResid(min_value);
            }
        }

        // if there are > 3 stubs in common, merge tracks into single track
        //if (stubs in common > 3 ){
          // merging tracks
          // assign track helix params according to best seed type between the two tracks - trkFit.getSeedType() 
          // merge using trkFit.setTrackWord() - using parameters of track with best seed type
        //}

    bx_o = bx;
  }
}