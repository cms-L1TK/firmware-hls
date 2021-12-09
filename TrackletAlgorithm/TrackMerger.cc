#include "TrackMerger.h"
#include "ap_int.h"
#include <bitset>
using namespace std;


void TrackMerger(const BXType bx,
  const TrackFit<kMaxBrlStbs,kMaxDskStbs>::TrackWord trackWord [kMaxProc],
  const TrackFit<kMaxBrlStbs,kMaxDskStbs>::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit<kMaxBrlStbs,kMaxDskStbs>::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o,
  TrackFit<kMaxBrlStbs,kMaxDskStbs>::TrackWord trackWord_o [kMaxProc],
  TrackFit<kMaxBrlStbs,kMaxDskStbs>::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit<kMaxBrlStbs,kMaxDskStbs>::DiskStubWord diskStubWords_o[4][kMaxProc]){ 

    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS stream variable=trackWord depth=1 dim=1
    #pragma HLS stream variable=barrelStubWords depth=1 dim=2
    #pragma HLS stream variable=diskStubWords depth=1 dim=2

    // reading in tracks
    
    for (unsigned int i = 0; i < kMaxProc; i++){
        TrackFit<kMaxBrlStbs,kMaxDskStbs> trkFit;
        trkFit.setTrackWord(trackWord[i]);
        TrackFit<kMaxBrlStbs,kMaxDskStbs>::TrackWord trackWord_o = trkFit.getTrackWord();

        //ap_uint<TrackFitBase::kTFHitMapSize> trackStubMap = trkFit.getHitMap();   
        TrackFit<kMaxBrlStbs,kMaxDskStbs>::BarrelStubWord barrelStubWord;   
        for (unsigned int j = 0; j < kMaxBrlStbs; j++){ 
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
            for( unsigned int k = 0 ; k < kMaxBrlStbs ; k++){ 
              barrelStubWords_o[k][i] = barrelStubWords[k][i]; 
            }
        }  
        TrackFit<kMaxBrlStbs,kMaxDskStbs>::DiskStubWord diskStubWord;    
        for (unsigned int k = kMaxBrlStbs; k < TrackFit<kMaxBrlStbs,kMaxDskStbs>::kNStubs; k++){
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
            for( unsigned int k = 0 ; k < kMaxDskStbs ; k++){ 
              diskStubWords_o[k][i] = diskStubWords[k][i]; 
            }
        }

        // getting stub index
        ap_uint<TrackFitBase<kMaxBrlStbs,kMaxDskStbs>::kTFStubIndexSize> stubIndex;
        for (unsigned int l = 0; l < TrackFit<kMaxBrlStbs,kMaxDskStbs>::kNStubs; l++){
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