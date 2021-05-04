#include "TrackMerger.h"

void TrackMerger(const BXType bx, TrackFit::TrackWord trackWord [kMaxProc], TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc], 
TrackFit::DiskStubWord diskStubWords[4][kMaxProc]){

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
        unsigned int stubCounter = 0;
        //every 3 bits is a new layer/disk - getting number of stubs in each layer
        for (int layer = 0; layer < trackStubMap.length()/kTFHitCountSize; layer++){
            int stubNumber = trackStubMap.range(trackStubMap.length() - kTFHitCountSize*layer, trackStubMap.length() - kTFHitCountSize*(layer + 1))
             
             for (unsigned int j = 0; j < kNBarrelStubs - 1; j++;){
                trkFit.setBarrelStubWord<j>(barrelStubWords[j][i]);
                //barrelStubWord = trkFit.getBarrelStubWord<2>();
                //trkFit.getStubIndex()
                //getStubPhiResid() for phi res of stub
                //set phi res to smallest value using setStubPhiResid()
             }
            
            for (unsigned int k = kNBarrelStubs; k < kNStubs - 1; k++;){
                trkFit.setDiskStubWord<k>(DiskStubWords[k][i]);
                //use trkFit.getDiskStubWord()
                //trkFit.getStubIndex()
                //getStubPhiResid() for phi res of stub
                //set phi res to smallest value using setStubPhiResid()
            }
            //stubCounter++;
        }
            
      
    // if there are > 3 stubs in common, merge tracks into single track
    //if (stubCounter > 3){
        // assign track helix params according to best seed type between the two tracks
        // use trkFit.getTrackWord() then trkFit.getSeedType() 
        // merge using trkFit.setTrackWord()
        // create the TrackStub
        //}

    }
}