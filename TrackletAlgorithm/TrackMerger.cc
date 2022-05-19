#include "TrackMerger.h"
#include "TrackHandler.cc"
#include <bitset>

void ModuleBuffer::insertTrack(const TrackHandler track){
  // #pragma HLS inline
  assert(writeIndex < kNBufferSize);
  trackArray[writeIndex] = track;
  #ifndef _SYNTHESIS_ 
  std::cout << "inserting track..." << std::endl;
  std::cout << "writeIndex: " << writeIndex << " trackArray[writeIndex]: " << trackArray[writeIndex].getTrackWord() << std::endl;
  #endif
  writeIndex++;
  #ifndef _SYNTHESIS_
  std::cout << "writeIndex: " << writeIndex << std::endl;
  #endif

}

TrackHandler ModuleBuffer::readTrack(){
  // #pragma HLS inline
  #ifndef _SYNTHESIS_
  std::cout << "reading track..." << std::endl;
  #endif
  assert(readIndex <= writeIndex);
  if (readIndex < writeIndex){
    TrackHandler track = trackArray[readIndex];
    #ifndef _SYNTHESIS_
    std::cout << "trackArray[readIndex]: " << trackArray[readIndex].getTrackWord() << " writeIndex: " << writeIndex << " readIndex: " << readIndex << std::endl;
    #endif
    readIndex++;
      #ifndef _SYNTHESIS_
      std::cout << "readIndex: " << readIndex << std::endl;
      #endif
    return track;
  } // else return a null track
  else if (readIndex == writeIndex){ 
     return TrackHandler();
  }
  else {
    #ifndef _SYNTHESIS_
     std::cout << "writeIndex: " << writeIndex << " readIndex: " << readIndex << std::endl;
    #endif
  }
}

void ModuleBuffer::clearBuffer(){
  #pragma HLS inline
  TrackHandler track;
  readIndex = 0;
  writeIndex = 0;

}


void ComparisonModule::process(){
  // #pragma HLS inline
  // #pragma HLS pipeline
  TrackHandler track = inputBuffer->readTrack();

  #ifndef _SYNTHESIS_
  // std::cout << "inputBufferTrack: " << track.getTrackWord() << std::endl;
  #endif
  // if masterTrack is not set and track is not null, set as master
  // else then if null, do nothing
  // if track is not null and also have a master set then do compare, merge

  // if (masterTrack.getTrackWord() == NULL && track.getTrackWord() != NULL){
  //   track = masterTrack;
  // }
  // if (masterTrack.getTrackWord() != NULL && track.getTrackWord() != NULL){
  //   if (masterTrack.getTrackWord() != track.getTrackWord()){
  //     masterTrack.CompareTrack(track);
  //     masterTrack.MergeTrack(track, matchFound, mergeCondition);
  //   }
  //   if (masterTrack.MergeTrack(track, matchFound, mergeCondition) ==  false){
  //     outputBuffer.insertTrack(track);

  //     #ifndef _SYNTHESIS_
  //     std::cout << "outputBufferTrack: " << outputBuffer.readTrack().getTrackWord() << std::endl;
  //     #endif
  //   }
  // }

  outputBuffer->insertTrack(track);

  #ifndef _SYNTHESIS_
  // std::cout << "outputBufferTrack: " << outputBuffer->readTrack().getTrackWord() << std::endl;
  #endif
  tracksProcessed++;
}

void ComparisonModule::setInputBuffer(ModuleBuffer* buffer){
  // #pragma HLS inline
  inputBuffer = buffer;
}

void ComparisonModule::setOutputBuffer(ModuleBuffer* buffer){
  // #pragma HLS inline
  outputBuffer = buffer;
}

ModuleBuffer* ComparisonModule::getInputBuffer(){
  // #pragma HLS inline
  return inputBuffer;
}

ModuleBuffer* ComparisonModule::getOutputBuffer(){
  // #pragma HLS inline
  return outputBuffer;
}

ModuleBuffer::ModuleBuffer() : trackArray() {}

ModuleBuffer::~ModuleBuffer(){}

// overall module only reads in a track and pass it to the comparison module
void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxProc],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxProc],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxProc],
  BXType &bx_o, 
  TrackFit::TrackWord trackWord_o[kMaxProc],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxProc],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  ){
    // #pragma HLS inline
    // #pragma HLS array_partition variable=barrelStubWords complete dim=1
    // #pragma HLS array_partition variable=diskStubWords complete dim=1
    // #pragma HLS array_partition variable=barrelStubWords_o complete dim=1
    // #pragma HLS array_partition variable=diskStubWords_o complete dim=1
    // #pragma HLS array_partition variable=trackWord_o complete dim=0

    ComparisonModule comparisonModule[kNComparisonModules];
    // #pragma HLS array_partition variable=comparisonModule complete dim=0

    ModuleBuffer buffer[kNBuffers];

    unsigned int outputIndex{0};
    unsigned int moduleCounter{1};

    // loop over the CMs to set the input/output buffer variables for each CM
    LOOP_SetBuffers:
    for (unsigned int i = 0; i < kNComparisonModules; i++){
      // #pragma HLS unroll
      comparisonModule[i].setInputBuffer(&(buffer[i]));
      comparisonModule[i].setOutputBuffer(&(buffer[i+1]));
    }

    LOOP_InputProc:
    for (int i = 0; i < kMaxProc; i++){ 
      #ifndef _SYNTHESIS_
      std::cout << "track no. : " << i << std::endl;
      #endif

      // #pragma HLS pipeline II=1 REWIND
      TrackFit::BarrelStubWord barrelStubWordsArray[4];
      TrackFit::DiskStubWord diskStubWordsArray[4];
      LOOP_SetArrays:
      for(unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
        // #pragma HLS unroll
        barrelStubWordsArray[layerIndex] = barrelStubWords[layerIndex][i];
        diskStubWordsArray[layerIndex] = diskStubWords[layerIndex][i];
      }

      TrackHandler track(trackWord[i], barrelStubWordsArray, diskStubWordsArray);

      // put track into input buffer 0 for CM zero
      // first track in input buffer is master, then comapre against the rest
      comparisonModule[0].getInputBuffer()->insertTrack(track); // pragmas to write in parallel?
  

      LOOP_ProcTracks:
      for(unsigned int j = 0; j < moduleCounter; j++){
        #ifndef _SYNTHESIS_
        std::cout << "comparisonModule no. : " << j << std::endl;
        #endif
        // #pragma HLS unroll
        comparisonModule[j].process();
      }
      if (moduleCounter != kNComparisonModules){moduleCounter++;}


        // create a last buffer (so 17 in total) the last buffer is for the output
       // then in main proc loop handle the output buffer - could read it out at the end of the event or in real time
       // needs to be a way of signalling when they have processed the track word (end of input) - 
       // passed from CM to CM, if nothing in buffer and see signal, read out track (also pass on signal to next CM)
       // create a fn to read out master

      #ifndef _SYNTHESIS_
      std::cout << "finished loop" << std::endl;
      #endif

    }
    bx_o = bx;

}