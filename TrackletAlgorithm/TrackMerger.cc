#include "TrackMerger.h"
#include "TrackHandler.cc"
#include <bitset>


void ModuleBuffer::insertTrack(const TrackHandler track){
  #pragma HLS inline
  assert(writeIndex < bufferSize);
  moduleBuffer[writeIndex] = track;
  writeIndex++;
}

TrackHandler ModuleBuffer::readTrack(){
  #pragma HLS inline
  assert(readIndex < writeIndex);
  if (readIndex < writeIndex){
    TrackHandler track = moduleBuffer[readIndex];
    readIndex++;
    return track;
  } // else return a null track
   else { return TrackHandler();}
}

// bool ModuleBuffer::isEmpty(){
//   if(readTrack().getTrackWord() != 0){
//     return 0;
//   }
// }

void ModuleBuffer::clearBuffer(){
  #pragma HLS inline
  TrackHandler track;
  readIndex = 0;
  writeIndex = 0;

}


// void ComparisonModule::processTrack(){
//   #pragma HLS inline
//   #pragma HLS pipeline
//   if(endOfStream == 0){
//     if (myIndex == 0){
//       masterTrack.setDebugFlag(1);
//     } else {
//       masterTrack.setDebugFlag(0);
//     }
//     if(masterTrack.getTrackWord() != track.getTrackWord()){
//       // masterTrack.CompareTrack(track);
//       // masterTrack.MergeTrack(track, matchFound, mergeCondition);
//     }
//     tracksProcessed++;
//   }
// }

void ComparisonModule::process(){
  #pragma HLS inline
  #pragma HLS pipeline
  TrackHandler track = inputBuffer->readTrack();
  outputBuffer->insertTrack(track);
}

void ComparisonModule::setInputBuffer(ModuleBuffer *buffer){
  #pragma HLS inline
  inputBuffer = buffer;
}

void ComparisonModule::setOutputBuffer(ModuleBuffer *buffer){
  #pragma HLS inline
  outputBuffer = buffer;
}


// overall module only reads in a track and pass it to the comparison module
void TrackMerger::TrackMergerMain(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o, 
  TrackFit::TrackWord trackWord_o[kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  ){
    #pragma HLS inline
    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS array_partition variable=barrelStubWords_o complete dim=1
    #pragma HLS array_partition variable=diskStubWords_o complete dim=1
    #pragma HLS array_partition variable=trackWord_o complete dim=0

    // ComparisonModule comparisonModule[kNComparisonModules];
    // ModuleBuffer buffer[kNBuffers];

    // loop over the CMs to set the input/output buffer variables for each CM - put in constructor?
    // LOOP_SetBuffers:
    // for (unsigned int i = 0; i < kNComparisonModules; i++){
    //   #pragma HLS unroll
    //   comparisonModule[i].setInputBuffer(&bufferPtr[i]);
    //   comparisonModule[i].setOutputBuffer(&bufferPtr[i]);
    // }

    // TrackFit::TrackWord unmergedTracks[kMaxProc];
    // TrackFit::BarrelStubWord unmergedBarrelStubs[4][kMaxProc];
    // TrackFit::DiskStubWord unmergedDiskStubs[4][kMaxProc];
    // #pragma HLS array_partition variable=unmergedBarrelStubs complete dim=1
    // #pragma HLS array_partition variable=unmergedDiskStubs complete dim=1

    LOOP_InputProc:
    for (int i = 0; i < kMaxProc; i++){ 
      #pragma HLS pipeline II=1 REWIND
      TrackFit::BarrelStubWord barrelStubWordsArray[4];
      TrackFit::DiskStubWord diskStubWordsArray[4];
      LOOP_SetArrays:
      for(unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
        #pragma HLS unroll
        barrelStubWordsArray[layerIndex] = barrelStubWords[layerIndex][i];
        diskStubWordsArray[layerIndex] = diskStubWords[layerIndex][i];
      }

      TrackHandler track(trackWord[i], barrelStubWordsArray, diskStubWordsArray);

      // put that track into input buffer 0 for CM zero
      // first track in input buffer is master, then comapre against the rest
      // buffer[0].insertTrack(track);

      for(int j = 0; j < kNComparisonModules; j++){
        #pragma HLS unroll
        // comparisonModule[j].process();

      //   CM takes track from buffer + reads track from input buffer, then outputs to output buffer when the track is unmerged
      //   if there is an unmerged track pass it to the next buffer

      }

        // create a last buffer (so 17 in total) the last buffer is for the output
       // then in main proc loop handle the output buffer - could read it out at the end of the event or in real time
       // needs to be a way of signalling when they have processed the track word (end of input) - 
       // passed from CM to CM, if nothing in buffer and see signal, read out track (also pass on signal to next CM)
       // create a fn to read out master
    }
    bx_o = bx;

}