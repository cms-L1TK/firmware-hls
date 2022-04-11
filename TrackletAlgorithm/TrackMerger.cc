#include "TrackMerger.h"
#include "TrackHandler.cc"
#include <bitset>


void ModuleBuffer::insertTrack(const TrackHandler track, unsigned int wIndex, unsigned int nBuffer){
  moduleBuffer[wIndex][nBuffer] = track;
  assert(writeIndex < bufferSize);
  writeIndex++;
}

TrackHandler ModuleBuffer::readTrack(unsigned int rIndex, unsigned int nBuffer){
  track = moduleBuffer[rIndex][nBuffer];
  readIndex++;
  return track;
}

bool ModuleBuffer::isEmpty(){
  for(unsigned int i = 0; i < bufferSize; i++){
    for(unsigned int j = 0; j < kNBuffers; j++){
        if(readTrack(i, j).getTrackWord() != 0){
          return 0;
        }
    }
  }
  return 1;
}

void ModuleBuffer::clearBuffer(){
  TrackHandler track;
  for(unsigned int i = 0; i < bufferSize; i++){
    for(unsigned int j = 0; j < kNBuffers; j++){
      insertTrack(track, i, j);
    }
  }
}


void ComparisonModule::processTrack(){
  #pragma HLS inline
  #pragma HLS pipeline
  if(endOfStream == 0){
    if (myIndex == 0){
      masterTrack.setDebugFlag(1);
    } else {
      masterTrack.setDebugFlag(0);
    }
    if(masterTrack.getTrackWord() != track.getTrackWord()){
      // masterTrack.CompareTrack(track);
      // masterTrack.MergeTrack(track, matchFound, mergeCondition);
    }
    tracksProcessed++;
  }
}



// overall module only reads in a track and pass it to the comparison module
void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o, 
  TrackFit::TrackWord trackWord_o[kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc],
  int &outputNumber
  ){
    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS array_partition variable=barrelStubWords_o complete dim=1
    #pragma HLS array_partition variable=diskStubWords_o complete dim=1
    #pragma HLS array_partition variable=trackWord_o complete dim=0

    ComparisonModule comparisonModule[kNComparisonModules];

    TrackFit::TrackWord unmergedTracks[kMaxProc];
    TrackFit::BarrelStubWord unmergedBarrelStubs[4][kMaxProc];
    TrackFit::DiskStubWord unmergedDiskStubs[4][kMaxProc];
    #pragma HLS array_partition variable=unmergedBarrelStubs complete dim=1
    #pragma HLS array_partition variable=unmergedDiskStubs complete dim=1

    LOOP_InputProc:
    for (int i = 0; i < kMaxProc; i++){ 
      // #pragma HLS pipeline II=1 REWIND

      TrackFit::BarrelStubWord barrelStubWordsArray[4];
      TrackFit::DiskStubWord diskStubWordsArray[4];
      LOOP_SetArrays:
      for(unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
        #pragma HLS unroll
        barrelStubWordsArray[layerIndex] = barrelStubWords[layerIndex][i];
        diskStubWordsArray[layerIndex] = diskStubWords[layerIndex][i];
      }

      TrackHandler track(trackWord[i], barrelStubWordsArray, diskStubWordsArray);
      ModuleBuffer buffer;

      // put that track into input buffer 0 for CM zero
      // first track in input buffer is master, then comapre against the rest
      buffer.insertTrack(track, 0, 0);
      buffer.readTrack(0,0);

      for(int j = 0; j < kNComparisonModules; j++){
        #pragma HLS unroll

        // dummy function
        comparisonModule[j].doNothing();
      
        // CM takes track from buffer
        // if there is an unmerged track pass it to the next buffer
        
        // if(comparisonModule[j].getMatchFound() == 0 && comparisonModule[j].getNProcessed() > 1){
        //   moduleBuffer[j+1][kNBuffers].readTrack(track);
        //   }

        
      }

        // create a last buffer (so 17 in total) the last buffer is for the output
       // then in main proc loop handle the output buffer - could read it out at the end of the event or in real time
       // needs to be a way of signalling when they have processed the track word (end of input) - 
       // passed from CM to CM, if nothing in buffer and see signal, read out track (also pass on signal to next CM)
       // create a fn to read out master
      


      

    bx_o = bx;
    }

}