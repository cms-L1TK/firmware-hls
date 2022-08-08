#include "TrackMerger.h"
#include <bitset>

// void ComparisonModule::process(hls::stream<TrackStruct> &inputBuffer, hls::stream<TrackStruct> &outputBuffer){
//   #pragma HLS inline
//   #pragma HLS pipeline
//   TrackStruct track;
//   inputBuffer.read(track);
//   TrackHandler trk = TrackHandler(track);
//   //assert(track._trackWord !=0 && "Null track in CM");
//   if (track._trackWord != 0){
//     if (masterTrack._trackWord == 0){
//       masterTrack = track; 
//      } else {
//     assert(masterTrack._trackWord != track._trackWord);
//     outputBuffer.write(track);
//   }
//   tracksProcessed++;
// }

TrackStruct& ComparisonModule::getMasterTrackStruct(){
  return masterTrack;
}

void ComparisonModule::process(TrackStruct &inTrack, TrackStruct &outTrack){
  TrackHandler trk = TrackHandler(inTrack);
  //assert(track._trackWord !=0 && "Null track in CM");
  if (inTrack._trackWord != 0){
    if (masterTrack._trackWord == 0){
      masterTrack = inTrack; 
    } else {
      TrackHandler masterTrk = TrackHandler(masterTrack);
      #ifndef _SYNTHESIS_
      std::cout << "inTrack: " << trk.getTrackWord() << " masterTrack: " << masterTrk.getTrackWord() << std::endl;
      #endif
      assert(masterTrack._trackWord != inTrack._trackWord);
      // masterTrk.CompareTrack(trk);
      outTrack = inTrack;
    }
  }
  tracksProcessed++;
  return;
}

void fillUnmerged(TrackStruct& inTrack,TrackStruct* outTrack, unsigned int i) {outTrack[i] = inTrack;}

void loadTrack(
  hls::stream<TrackFit::TrackWord> &trackWord,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3,
  TrackStruct& aTrack
) {
  trackWord.read(aTrack._trackWord);
  barrelStubWords_0.read(aTrack._barrelStub_0);
  barrelStubWords_1.read(aTrack._barrelStub_1);
  barrelStubWords_2.read(aTrack._barrelStub_2);
  barrelStubWords_3.read(aTrack._barrelStub_3);
  diskStubWords_0.read(aTrack._diskStub_0);        
  diskStubWords_1.read(aTrack._diskStub_1);        
  diskStubWords_2.read(aTrack._diskStub_2);        
  diskStubWords_3.read(aTrack._diskStub_3);  

  return;      
}  

void unloadTrack(
  TrackStruct& aTrack,
  hls::stream<TrackFit::TrackWord> &trackWord_o,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o 
) {
  trackWord_o.write(aTrack._trackWord);
  barrelStubWords_0_o.write(aTrack._barrelStub_0);
  barrelStubWords_1_o.write(aTrack._barrelStub_1);
  barrelStubWords_2_o.write(aTrack._barrelStub_2);
  barrelStubWords_3_o.write(aTrack._barrelStub_3);
  diskStubWords_0_o.write(aTrack._diskStub_0);
  diskStubWords_1_o.write(aTrack._diskStub_1);
  diskStubWords_2_o.write(aTrack._diskStub_2);
  diskStubWords_3_o.write(aTrack._diskStub_3);

  return;
}

void TrackMerger(const BXType bx,
  hls::stream<TrackFit::TrackWord> &trackWord,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2,
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  hls::stream<TrackFit::TrackWord> &trackWord_o,
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
  hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
  hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o 
  )
{
  #pragma HLS inline

  ComparisonModule comparisonModule[kNComparisonModules];
  #pragma HLS array_partition variable=comparisonModule complete dim=0
  
  // TrackStruct unmergedTracks[kMaxTrack];
  // #pragma HLS array_partition variable=unmergedTracks complete dim=1

  // TrackStruct masterTracks[kNComparisonModules];
  // #pragma HLS array_partition variable=masterTracks complete dim=1

  
  

  LOOP_Input:
  for (unsigned int i = 0; i < kMaxTrack; i++){ 
    TrackStruct tracks[kNBuffers]; 
    #pragma HLS array_partition variable=tracks complete dim=1
    #pragma HLS dataflow
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
    // masterTracks[nModule] = comparisonModule[nModule].getMasterTrackStruct();
    TrackStruct& masterTk = comparisonModule[nModule].getMasterTrackStruct();
    std::cout << "masterTrack: " << " " << nModule << " " << masterTk._trackWord << std::endl;
    unloadTrack(masterTk,
                trackWord_o,
                barrelStubWords_0_o,
                barrelStubWords_1_o,
                barrelStubWords_2_o,
                barrelStubWords_3_o,
                diskStubWords_0_o,
                diskStubWords_1_o,
                diskStubWords_2_o,
                diskStubWords_3_o); //read out master tracks last
  }

  // LOOP_OutputUnmergedTracks:
  // for (unsigned int bufferIndex = kNComparisonModules; bufferIndex < kMaxTrack; bufferIndex++){
  //   #pragma HLS unroll 
  //   unloadTrack(unmergedTracks[bufferIndex],trackWord_o,barrelStubWords_0_o,barrelStubWords_1_o,barrelStubWords_2_o,barrelStubWords_3_o,
  //   diskStubWords_0_o,diskStubWords_1_o,diskStubWords_2_o,diskStubWords_3_o); 
  // }
    
  bx_o = bx;
}