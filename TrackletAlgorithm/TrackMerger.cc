#include "TrackMerger.h"
#include <bitset>

void ModuleBuffer::insertTrack(const TrackHandler track){
  #pragma HLS inline
  assert(writeIndex < kNBufferSize);
  trackArray[writeIndex] = track;
  writeIndex++;
}

TrackHandler ModuleBuffer::readTrack(){
  #pragma HLS inline
  assert(readIndex <= writeIndex);
  if (readIndex < writeIndex){
    TrackHandler track = trackArray[readIndex];
    readIndex++;
    return track;
  } // else return a null track
  else{ 
     return TrackHandler();
  }
}

void ModuleBuffer::clearBuffer(){
  #pragma HLS inline
  TrackHandler track;
  readIndex = 0;
  writeIndex = 0;

}

void ComparisonModule::process(hls::stream<TrackHandler> &inputBuffer, hls::stream<TrackHandler> &outputBuffer){
  #pragma HLS inline
  #pragma HLS pipeline
  TrackHandler track;
  if (inputBuffer.read_nb(track)) {
    assert(track.getTrackWord()!=0 && "Null track in CM");
    outputBuffer.write(track);
    tracksProcessed++;
  }
}

void ComparisonModule::process(hls::stream<TrackFit::TrackWord> &inputBuffer, hls::stream<TrackFit::TrackWord> &outputBuffer){
  #pragma HLS inline
  #pragma HLS pipeline
  TrackFit::TrackWord track;
  if (inputBuffer.read_nb(track)) {
    assert(track !=0 && "Null track in CM");
    outputBuffer.write(track);
    tracksProcessed++;
  }
}

void ComparisonModule::process(ModuleBuffer &inputBuffer, ModuleBuffer &outputBuffer){
  #pragma HLS inline
  #pragma HLS pipeline
  TrackHandler track = inputBuffer.readTrack();

  if (track.getTrackWord() != 0){    
    outputBuffer.insertTrack(track);
    tracksProcessed++;
  }
}

ModuleBuffer::ModuleBuffer() : trackArray() {}

ModuleBuffer::~ModuleBuffer(){}

// overall module only reads in a track and pass it to the comparison module
void TrackMerger(const BXType bx,
  hls::stream<TrackFit::TrackWord> &trackWord,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2,
  // const hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_0,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_1,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_2,
  // const hls::stream<TrackFit::DiskStubWord> &diskStubWords_3,
  BXType bx_o,
  hls::stream<TrackFit::TrackWord> &trackWord_o
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_0_o, 
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_1_o, 
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_2_o, 
  // hls::stream<TrackFit::BarrelStubWord> &barrelStubWords_3_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_0_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_1_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_2_o, 
  // hls::stream<TrackFit::DiskStubWord> &diskStubWords_3_o 
  )
{
    #pragma HLS inline

    ComparisonModule comparisonModule[kNComparisonModules];
    #pragma HLS array_partition variable=comparisonModule complete dim=0

    // ModuleBuffer buffer[kNBuffers];
    // #pragma HLS array_partition variable=buffer complete dim=0
    hls::stream<TrackFit::TrackWord> buffer[kNBuffers];
    #pragma HLS STREAM variable=buffer depth=3

    unsigned int nIn = 0;
    unsigned int nOut = 0;

    // assert(buffer[0].empty());
    // assert(buffer[1].empty());

    LOOP_PROCESS:
    for (int i = 0; i < kMaxProc; i++){ 
      #pragma HLS pipeline II=1 REWIND
      TrackFit::TrackWord inTrackWord;
      TrackFit::BarrelStubWord barrelStubWordsArray[4];
      TrackFit::DiskStubWord diskStubWordsArray[4];
      if (trackWord.read_nb(inTrackWord)) {
        // assert(barrelStubWords_0.read_nb(barrelStubWordsArray[0]));
        // assert(barrelStubWords_1.read_nb(barrelStubWordsArray[1]));
        // assert(barrelStubWords_2.read_nb(barrelStubWordsArray[2]));
        // assert(barrelStubWords_3.read_nb(barrelStubWordsArray[3]));
        // assert(diskStubWords_0.read_nb(diskStubWordsArray[0]));
        // assert(diskStubWords_1.read_nb(diskStubWordsArray[1]));
        // assert(diskStubWords_2.read_nb(diskStubWordsArray[2]));
        // assert(diskStubWords_3.read_nb(diskStubWordsArray[3]));
        //TrackHandler track(inTrackWord, barrelStubWordsArray, diskStubWordsArray);
        //buffer[0].insertTrack(track);
        buffer[0].write(inTrackWord);
        ++nIn;
      }

      LOOP_ProcTracks:
      for(unsigned int j = 0; j < kNComparisonModules; j++){
        #pragma HLS unroll
        comparisonModule[j].process(buffer[j], buffer[j+1]);
      } 

      TrackFit::TrackWord track_o; 
      if (!buffer[kNBuffers-1].empty()) {
        if (buffer[kNBuffers-1].read_nb(track_o) ) {
          assert(track_o != 0 && "Null track in FIFO"); // Check it is not a null track
          trackWord_o.write(track_o);
          // barrelStubWords_0_o.write(track_o.getBarrelStubArray(0,0));
          // barrelStubWords_1_o.write(track_o.getBarrelStubArray(1,0));
          // barrelStubWords_2_o.write(track_o.getBarrelStubArray(2,0));
          // barrelStubWords_3_o.write(track_o.getBarrelStubArray(3,0));
          // diskStubWords_0_o.write(track_o.getDiskStubArray(0,0));
          // diskStubWords_1_o.write(track_o.getDiskStubArray(1,0));
          // diskStubWords_2_o.write(track_o.getDiskStubArray(2,0));
          // diskStubWords_3_o.write(track_o.getDiskStubArray(3,0));
          ++nOut;
        }
      } 
    }
    bx_o = bx;
  std::cout << "Finishing TrackMerger with " << nIn << " tracks read and " << nOut << " out" <<std::endl;
}