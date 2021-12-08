#include "TrackMerger.h"
<<<<<<< HEAD
#include "ap_int.h"
#include <bitset>
using namespace std;


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

    // reading in tracks
    
    for (unsigned int i = 0; i < kMaxProc; i++){
        TrackFit trkFit;
        trkFit.setTrackWord(trackWord[i]);
        TrackFit::TrackWord trackWord_o = trkFit.getTrackWord();

        //ap_uint<TrackFitBase::kTFHitMapSize> trackStubMap = trkFit.getHitMap();   
        TrackFit::BarrelStubWord barrelStubWord;   
        for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
            switch (j){
              case 0:
                trkFit.setBarrelStubWord<0>(barrelStubWords[0][i]);
                barrelStubWord = trkFit.getBarrelStubWord<0>();
                break;
              case 1:
                trkFit.setBarrelStubWord<1>(barrelStubWords[1][i]);
                barrelStubWord = trkFit.getBarrelStubWord<1>();
                break;
              case 2:
                trkFit.setBarrelStubWord<2>(barrelStubWords[2][i]);
                barrelStubWord = trkFit.getBarrelStubWord<2>();
                break;
              case 3:
                trkFit.setBarrelStubWord<3>(barrelStubWords[3][i]);
                barrelStubWord = trkFit.getBarrelStubWord<3>();
                break;

            }
            TrackFit::BarrelStubWord barrelStubWords_o[4][i] = {barrelStubWords[0][i], barrelStubWords[1][i], barrelStubWords[2][i], barrelStubWords[3][i]};
        }  
        TrackFit::DiskStubWord diskStubWord;    
        for (unsigned int k = TrackFit::kNDiskStubs; k < TrackFit::kNStubs; k++){
            switch (k){
              case 4:
                trkFit.setDiskStubWord<4>(diskStubWords[0][i]);
                diskStubWord = trkFit.getDiskStubWord<4>();
                break;
              case 5:
                trkFit.setDiskStubWord<5>(diskStubWords[1][i]);
                diskStubWord = trkFit.getDiskStubWord<5>();
                break;
              case 6:
                trkFit.setDiskStubWord<6>(diskStubWords[2][i]);
                diskStubWord = trkFit.getDiskStubWord<6>();
                break;
              case 7:
                trkFit.setDiskStubWord<7>(diskStubWords[3][i]);
                diskStubWord = trkFit.getDiskStubWord<7>();
                break;
            }
            TrackFit::DiskStubWord diskStubWords_o[4][i] = {diskStubWords[0][i], diskStubWords[1][i], diskStubWords[2][i], diskStubWords[3][i]};
        }

        // getting stub index
        ap_uint<TrackFitBase::kTFStubIndexSize> stubIndex;
        for (unsigned int l = 0; l < TrackFit::kNStubs; l++){
          switch (l) {
            case 0:
              stubIndex = trkFit.getStubIndex<0>();
              break;
            case 1:
              stubIndex = trkFit.getStubIndex<1>();
              break;
            case 2:
              stubIndex = trkFit.getStubIndex<2>();
              break;
            case 3: 
              stubIndex = trkFit.getStubIndex<3>();
              break;
            case 4:
              stubIndex = trkFit.getStubIndex<4>();
              break;
            case 5:
              stubIndex = trkFit.getStubIndex<5>();
              break;
            case 6:
              stubIndex = trkFit.getStubIndex<6>();
              break;
            case 7:
              stubIndex = trkFit.getStubIndex<7>();
              break;
          }
        }

    }
  
    bx_o = bx;
  
  }
=======

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
>>>>>>> Pseudo-code/unfinished code for comparison module
