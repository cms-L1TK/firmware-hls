#include "TrackMerger.h"
#include "TrackHandler.h"
#include <bitset>

TrackStruct& ComparisonModule::getMasterTrackStruct(){
  return masterTrack;
}

void ComparisonModule::process(TrackStruct &inTrack, TrackStruct &outTrack){
  // assert(inTrack._trackWord !=0);
  // assert (tracksProcessed <= kMaxTrack);
  trackHandler = TrackHandler();
  if (inTrack._trackWord != 0 && tracksProcessed <= kMaxTrack){
    if (masterTrack._trackWord == 0){
      masterTrack = inTrack;
    } else {
      // assert(masterTrack._trackWord != inTrack._trackWord);
      if(masterTrack._trackWord != inTrack._trackWord){
        trackHandler.compareTrack(inTrack, masterTrack, matchFound, mergeCondition);
        if (matchFound){
          trackHandler.mergeTrack(inTrack, masterTrack);
        } else {
          outTrack = inTrack;
        }
      }
    }
  }

  tracksProcessed++;
  return;
}

void fillUnmerged(TrackStruct& inTrack,TrackStruct* outTrack, unsigned int i){
  outTrack[i] = inTrack;}


void loadTrack(
  stream<TrackFitType::TrackWord> &trackWord,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_0,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_1,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_2,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_3,
  stream<TrackFitType::DiskStubWord> &diskStubWords_0,
  stream<TrackFitType::DiskStubWord> &diskStubWords_1,
  stream<TrackFitType::DiskStubWord> &diskStubWords_2,
  stream<TrackFitType::DiskStubWord> &diskStubWords_3,
  TrackStruct& aTrack
) {
  trackWord.read(aTrack._trackWord);
  barrelStubWords_0.read(aTrack._barrelStubArray[0][0]);
  barrelStubWords_1.read(aTrack._barrelStubArray[1][0]);
  barrelStubWords_2.read(aTrack._barrelStubArray[2][0]);
  barrelStubWords_3.read(aTrack._barrelStubArray[3][0]);
  diskStubWords_0.read(aTrack._diskStubArray[0][0]);        
  diskStubWords_1.read(aTrack._diskStubArray[1][0]);        
  diskStubWords_2.read(aTrack._diskStubArray[2][0]);        
  diskStubWords_3.read(aTrack._diskStubArray[3][0]);  

  return;      
}  


void unloadTrack(
  TrackStruct& aTrack,
  stream<TrackFitType::TrackWord> &trackWord_o,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_0_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_1_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_2_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_3_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_0_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_1_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_2_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_3_o 
) {
  trackWord_o.write(aTrack._trackWord);
  barrelStubWords_0_o.write(aTrack._barrelStubArray[0][0]);
  barrelStubWords_1_o.write(aTrack._barrelStubArray[1][0]);
  barrelStubWords_2_o.write(aTrack._barrelStubArray[2][0]);
  barrelStubWords_3_o.write(aTrack._barrelStubArray[3][0]);
  diskStubWords_0_o.write(aTrack._diskStubArray[0][0]);
  diskStubWords_1_o.write(aTrack._diskStubArray[1][0]);
  diskStubWords_2_o.write(aTrack._diskStubArray[2][0]);
  diskStubWords_3_o.write(aTrack._diskStubArray[3][0]);

  return;
}

void TrackMerger(const BXType bx,
  stream<TrackFitType::TrackWord> &trackWord,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_0,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_1,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_2,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_3,
  stream<TrackFitType::DiskStubWord> &diskStubWords_0,
  stream<TrackFitType::DiskStubWord> &diskStubWords_1,
  stream<TrackFitType::DiskStubWord> &diskStubWords_2,
  stream<TrackFitType::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  stream<TrackFitType::TrackWord> &trackWord_o,
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_0_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_1_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_2_o, 
  stream<TrackFitType::BarrelStubWord> &barrelStubWords_3_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_0_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_1_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_2_o, 
  stream<TrackFitType::DiskStubWord> &diskStubWords_3_o 
  )
{
  static ComparisonModule comparisonModule[kNComparisonModules];
  #pragma HLS array_partition variable=comparisonModule complete dim=0

  // TrackStruct unmergedTracks[kMaxTrack];
  // #pragma HLS array_partition variable=unmergedTracks complete dim=0
  LOOP_Input:
  for (unsigned int i = 0; i < kMaxTrack; i++){ 
    #pragma HLS pipeline II=1 REWIND
    TrackStruct tracks[kNBuffers]; 
    #pragma HLS array_partition variable=tracks complete dim=0
    loadTrack(trackWord,
              barrelStubWords_0,
              barrelStubWords_1,
              barrelStubWords_2,
              barrelStubWords_3,
              diskStubWords_0,
              diskStubWords_1,
              diskStubWords_2,
              diskStubWords_3,
              tracks[0]);
    LOOP_ProcTracks:
    for (unsigned int j = 0; j < kNComparisonModules; j++){
      #pragma HLS unroll
      comparisonModule[j].process(tracks[j],tracks[j+1]);

    }
    //putting straight into fifo in dataflow region
    // fillUnmerged(tracks[kNComparisonModules],unmergedTracks, i);

    // send unmerged tracks sent to output
    unloadTrack(tracks[kNComparisonModules],
                trackWord_o,
                barrelStubWords_0_o,
                barrelStubWords_1_o,
                barrelStubWords_2_o,
                barrelStubWords_3_o,
                diskStubWords_0_o,
                diskStubWords_1_o,
                diskStubWords_2_o,
                diskStubWords_3_o);

  }

  LOOP_OutputCM:
  for (unsigned int nModule = 0; nModule < kNComparisonModules; nModule++){
    #pragma HLS unroll
    TrackStruct& masterTk = comparisonModule[nModule].getMasterTrackStruct();
    unloadTrack(masterTk,
                trackWord_o,
                barrelStubWords_0_o,
                barrelStubWords_1_o,
                barrelStubWords_2_o,
                barrelStubWords_3_o,
                diskStubWords_0_o,
                diskStubWords_1_o,
                diskStubWords_2_o,
                diskStubWords_3_o);

  }

    
  bx_o = bx;
}