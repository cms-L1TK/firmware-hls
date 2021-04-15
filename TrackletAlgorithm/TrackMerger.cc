#include "TrackMerger.h"

void TrackMerger(const BXType bx, TrackFit::Trackword trackWord [kMaxProc], TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc], 
TrackFit::DiskStubWord diskStubWords[4][kMaxProc]), TrackFit::TrackWord newTrackWord){
    //ap_uint<kNBits_MemAddr> addr;
    //TrackFitMemory inputTracks;
    //TrackFitMemory outputTracks;
    //for(ap_uint<kNBits_MemAddr> addr = 0; addr < inputTracks.getEntries(bx); addr++){
        //auto track = inputTracks.read_mem(bx, addr);
        //outputTracks.write_mem(bx, track, addr);
         
    //}

    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS stream variable=trackWord depth=1 dim=1
    #pragma HLS stream variable=barrelStubWords depth=1 dim=2
    #pragma HLS stream variable=diskStubWords depth=1 dim=2

    // Comparison module
    // count stubs in common, looking at stubs with smallest phi residual in each layer
    for (unsigned int i = 0; i < kMaxProc; i++){
        auto trackStubMap = trackWord.getHitMap();
        std::cout << "Track Stub Map: " << trackStubMap << std::endl;
        //for(each layer){
            //unsigned int stubCounter = 0;
            //for(each hit in layer){
                //if(in barrel){
                    //getBarrelStubWord()
                    //getStubIndex() for hit and getStubPhiResid() for phi res of stub
                    //compare stub index if they are the same
                    //set phi res to smallest value using setStubPhiResid()
                //}
                //if(in disk){
                    //getDiskStubWord()
                    //getStubIndex() for hit and getStubPhiResid() for phi res of stub
                    //compare stub index if they are the same
                    //set phi res to smallest value using setStubPhiResid()
                //}
                
                //stubCounter++;
           //}       
        //}
    // if there are > 3 stubs in common, merge tracks into single track
    //if (stubCounter > 3){
        // assign track helix params according to best seed type between the two tracks
        // use track.getTrackWord() then track.getSeedType() 
        // merge using track.setTrackWord()
        // create the TrackStub
        //}

    }
}