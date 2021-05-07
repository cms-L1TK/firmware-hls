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
        std::cout << "Track Stub Map: " << trackStubMap << std::endl;
        //every 3 bits is a new layer/disk - getting number of stubs in each layer
        for (int layer = 0; layer < trackStubMap.length()/TrackFit::kTFHitCountSize; layer++){
            int stubNumber = trackStubMap.range(trackStubMap.length() - TrackFit::kTFHitCountSize*layer, trackStubMap.length() - TrackFit::kTFHitCountSize*(layer + 1));
             
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
                //barrelStubWord = trkFit.getBarrelStubWord<2>();
                //trkFit.getStubIndex()
                //getStubPhiResid() for phi res of stub
                //set phi res to smallest value using setStubPhiResid()
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
                //use trkFit.getDiskStubWord<>()
                //trkFit.getStubIndex()
                //getStubPhiResid() for phi res of stub
                //set phi res to smallest value using setStubPhiResid()
            }
        }
            
      
    // if there are > 3 stubs in common, merge tracks into single track
    //if (stubNumber > 3){
        // assign track helix params according to best seed type between the two tracks
        // use trkFit.getTrackWord() then trkFit.getSeedType() 
        // merge using trkFit.setTrackWord()
        //}

    }
     bx_o = bx;
}