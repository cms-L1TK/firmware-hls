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

    // reading in tracks
    
    for (unsigned int i = 0; i < kMaxProc; i++){
        TrackFit trkFit;
        trkFit.setTrackWord(trackWord[i]);
        ap_uint<TrackFitBase::kTFHitMapSize> trackStubMap = trkFit.getHitMap();
        std::cout << "trackWord: " << trackWord[i] << " " << "Track Stub Map: " << trackStubMap<< std::endl;
        //auto trackHitCount = trkFit.getHitCount();
        //std::cout << "Track Stub Map: " << trackStubMap << std::endl;
        // every 3 bits is a new layer/disk - getting number of stubs in each layer
        //for (int layer = 0; layer < trackStubMap.length()/TrackFit::kTFHitCountSize; layer++){
             
        for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
            switch (j){
              case 0:
                trkFit.setBarrelStubWord<0>(barrelStubWords[0][i]);
                std::cout << "Barrel: " << trkFit.getBarrelStubWord<0>() << std::endl;
                break;
              case 1:
                trkFit.setBarrelStubWord<1>(barrelStubWords[1][i]);
                std::cout << "Barrel: " << trkFit.getBarrelStubWord<1>() << std::endl;
                break;
              case 2:
                trkFit.setBarrelStubWord<2>(barrelStubWords[2][i]);
                std::cout << "Barrel: " << trkFit.getBarrelStubWord<2>() << std::endl;
                break;
              case 3:
                trkFit.setBarrelStubWord<3>(barrelStubWords[3][i]);
                std::cout << "Barrel: " << trkFit.getBarrelStubWord<3>() << std::endl;
                break;

            }
        }  
            
        for (unsigned int k = TrackFit::kNDiskStubs; k < TrackFit::kNStubs; k++){
            switch (k){
              case 4:
                trkFit.setDiskStubWord<4>(diskStubWords[0][i]);
                std::cout << "Disk: " << trkFit.getDiskStubWord<4>() << std::endl;
                break;
              case 5:
                trkFit.setDiskStubWord<5>(diskStubWords[1][i]);
                std::cout << "Disk: " << trkFit.getDiskStubWord<5>() << std::endl;
                break;
              case 6:
                trkFit.setDiskStubWord<6>(diskStubWords[2][i]);
                std::cout << "Disk: " << trkFit.getDiskStubWord<6>() << std::endl;
                break;
              case 7:
                trkFit.setDiskStubWord<7>(diskStubWords[3][i]);
                std::cout << "Disk: " << trkFit.getDiskStubWord<7>() << std::endl;
                break;
            }
        }

        // getting stub index and phi residual
        int stubIndex[TrackFit::kNStubs];
        double phiRes[TrackFit::kNStubs];
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
    }


    bx_o = bx;
  
  }