#include "TrackMerger.h"
#include "TrackHandler.cc"
#include <bitset>

void ModuleBuffer::insertTrack(const TrackHandler track){
  #pragma HLS inline
  assert(writeIndex < kNBufferSize);
  trackArray[writeIndex] = track;
  #ifndef _SYNTHESIS_ 
  std::cout << "inserting track..." << std::endl;
  std::cout << "writeIndex: " << writeIndex << " trackArray[writeIndex]: " << std::hex << trackArray[writeIndex].getTrackWord() << std::endl;
  #endif
  writeIndex++;
  #ifndef _SYNTHESIS_
  std::cout << "writeIndex: " << writeIndex << std::endl;
  #endif

}

TrackHandler ModuleBuffer::readTrack(){
  #pragma HLS inline
  #ifndef _SYNTHESIS_
  std::cout << "reading track..." << std::endl;
  #endif
  assert(readIndex <= writeIndex);
  if (readIndex < writeIndex){
    TrackHandler track = trackArray[readIndex];
    #ifndef _SYNTHESIS_
    std::cout << "trackArray[readIndex]: " << std::hex << trackArray[readIndex].getTrackWord() << " writeIndex: " << writeIndex << " readIndex: " << readIndex << std::endl;
    #endif
    readIndex++;
    #ifndef _SYNTHESIS_
    std::cout << "readIndex: " << readIndex << std::endl;
    #endif
    return track;
  } // else return a null track
  else
  {
    //  else if (readIndex == writeIndex){ 
     return TrackHandler();
  }
/*
  else {
    #ifndef _SYNTHESIS_
     std::cout << "writeIndex: " << writeIndex << " readIndex: " << readIndex << std::endl;
    #endif
  }
*/
}

void ModuleBuffer::clearBuffer(){
  #pragma HLS inline
  TrackHandler track;
  readIndex = 0;
  writeIndex = 0;

}


void ComparisonModule::process(ModuleBuffer &inputBuffer, ModuleBuffer &outputBuffer){
  #pragma HLS inline
  #pragma HLS pipeline
  TrackHandler track = inputBuffer.readTrack();
    #ifndef _SYNTHESIS_
    std::cout << "inputBufferTrack: " << std::hex << track.getTrackWord() << std::endl;
    #endif

  if (track.getTrackWord() != 0){
    #ifndef _SYNTHESIS_
    std::cout << "condition met, inputBufferTrack: " << std::hex << track.getTrackWord() << std::endl;
    #endif
    // if masterTrack is not set and track is not null, set as master
    // else then if null, do nothing
    // if track is not null and also have a master set then do compare, merge

    // #ifndef _SYNTHESIS_
    //   std::cout << "masterTrack: " << std::hex << masterTrack.getTrackWord() << std::endl;
    // #endif

    masterTrack = track;
    

    outputBuffer.insertTrack(track);
    #ifndef _SYNTHESIS_
    // std::cout << "outputBufferTrack: " << outputBuffer.readTrack().getTrackWord() << std::endl;
    #endif
    tracksProcessed++;
  }

}

// void ComparisonModule::setInputBuffer(ModuleBuffer &buffer){
//   #pragma HLS inline
//   inputBuffer = buffer;
// }

// void ComparisonModule::setOutputBuffer(ModuleBuffer &buffer){
//   #pragma HLS inline
//   outputBuffer = buffer;
// }


ModuleBuffer::ModuleBuffer() : trackArray() {}

ModuleBuffer::~ModuleBuffer(){}

// overall module only reads in a track and pass it to the comparison module
void TrackMerger(const BXType bx,
  const TrackFit::TrackWord trackWord [kMaxTracks],
  const TrackFit::BarrelStubWord barrelStubWords[4][kMaxTracks],
  const TrackFit::DiskStubWord diskStubWords[4][kMaxTracks],
  BXType &bx_o, 
  TrackFit::TrackWord trackWord_o[kMaxTracks],
  TrackFit::BarrelStubWord barrelStubWords_o[4][kMaxTracks],
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxTracks],
  int &outputNumber
  ){
    #pragma HLS inline
    #pragma HLS array_partition variable=barrelStubWords complete dim=1
    #pragma HLS array_partition variable=diskStubWords complete dim=1
    #pragma HLS array_partition variable=barrelStubWords_o complete dim=1
    #pragma HLS array_partition variable=diskStubWords_o complete dim=1
    #pragma HLS array_partition variable=trackWord_o complete dim=0

    ComparisonModule comparisonModule[kNComparisonModules];
    #pragma HLS array_partition variable=comparisonModule complete dim=0

    ModuleBuffer buffer[kNBuffers];
    #pragma HLS array_partition variable=buffer complete dim=1

    TrackFit::TrackWord unmergedTracks[kMaxTracks];
    TrackFit::BarrelStubWord unmergedBarrelStubs[4][kMaxTracks];
    TrackFit::DiskStubWord unmergedDiskStubs[4][kMaxTracks];
    #pragma HLS array_partition variable=unmergedTracks complete dim=0
    #pragma HLS array_partition variable=unmergedBarrelStubs complete dim=1
    #pragma HLS array_partition variable=unmergedDiskStubs complete dim=1


    unsigned int outputIndex{0};
    unsigned int unmergedOutputIndex{0};

    // loop over the CMs to set the input/output buffer variables for each CM
    // LOOP_SetBuffers:
    // for (unsigned int i = 0; i < kNComparisonModules; i++){
    //   #pragma HLS unroll
    //   comparisonModule[i].setInputBuffer(buffer[i]);
    //   comparisonModule[i].setOutputBuffer(buffer[i+1]);
    // }

    LOOP_Inputs:
    for (int i = 0; i < kMaxTracks; i++){
      #ifndef _SYNTHESIS_
      std::cout << "track no. : " << i << std::endl;
      #endif

      #pragma HLS pipeline II=1 REWIND
      TrackFit::BarrelStubWord barrelStubWordsArray[4];
      TrackFit::DiskStubWord diskStubWordsArray[4];
      LOOP_SetArrays:
      for (unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
        #pragma HLS unroll
        barrelStubWordsArray[layerIndex] = barrelStubWords[layerIndex][i];
        diskStubWordsArray[layerIndex] = diskStubWords[layerIndex][i];
      }

      TrackHandler track(trackWord[i], barrelStubWordsArray, diskStubWordsArray);

      // put track into input buffer 0 for CM zero
      // first track in input buffer is master, then comapre against the rest
      
      // pragmas to write in parallel?
      buffer[0].insertTrack(track);
    }
  

    LOOP_Clks:
    for (int i = 0; i < kMaxProc; i++){ 
      #pragma HLS pipeline II=1 REWIND
      LOOP_ProcTracks:
      for (unsigned int j = 0; j < kNComparisonModules; j++){
        #pragma HLS unroll
        #ifndef _SYNTHESIS_
        std::cout << "comparisonModule no. : " << j << std::endl;
        #endif
        comparisonModule[j].process(buffer[j], buffer[j+1]);
        trackWord_o[outputIndex] = comparisonModule[j].getMasterTrackWord();
        #ifndef _SYNTHESIS_
        std::cout << "trackWord_o:  " << std::hex << trackWord_o[outputIndex] << std::endl;
        #endif
        LOOP_OutputStubWords:
        for (unsigned int layerIndex = 0; layerIndex < 4; layerIndex++){
          #pragma HLS unroll
          barrelStubWords_o[layerIndex][outputIndex] = comparisonModule[j].getMasterTrackBarrelStubs(0, layerIndex);
          diskStubWords_o[layerIndex][outputIndex] = comparisonModule[j].getMasterTrackDiskStubs(0, layerIndex);
        #ifndef _SYNTHESIS_
        std::cout << "barrel_o:  " << std::hex << barrelStubWords_o[layerIndex][outputIndex] << std::endl;
        std::cout << "disk_o:  " << std::hex << diskStubWords_o[layerIndex][outputIndex] << std::endl;
        #endif
        }
        outputIndex++;

        // if (j == kNComparisonModules){
        //   unmergedTracks[unmergedOutputIndex] = trackWord[i];
        //   LOOP_UnmergedStubs:
        //   for (unsigned int arrayIndex = 0; arrayIndex < 4; arrayIndex++){
        //     #pragma HLS unroll
        //     unmergedBarrelStubs[arrayIndex][unmergedOutputIndex] = barrelStubWords[arrayIndex][i];
        //     unmergedDiskStubs[arrayIndex][unmergedOutputIndex] = diskStubWords[arrayIndex][i];
        //   }
        //   unmergedOutputIndex++;
        // }
      }
    }

      
    // outputNumber = outputIndex + unmergedOutputIndex;
    // LOOP_OutputUnmergedTW:
    // for (unsigned int i = 0; i < kMaxProc; i++){
    //   for (unsigned int j = 0; j < kMaxTracks; j++){
    //     #pragma HLS unroll
    //     if ( j >= unmergedOutputIndex) continue;
    //     trackWord_o[outputIndex+j] = unmergedTracks[j];
    //     LOOP_OutputUnmergedStubs:
    //     for (unsigned int k = 0; k < 4; k++){
    //       #pragma HLS unroll
    //       barrelStubWords_o[k][outputIndex+j] = unmergedBarrelStubs[k][j];
    //       diskStubWords_o[k][outputIndex+j] = unmergedDiskStubs[k][j];
    //     }
    //   }
    // }

    bx_o = bx;


    #ifndef _SYNTHESIS_
      std::cout << "finished loop" << std::endl;
    #endif

}
