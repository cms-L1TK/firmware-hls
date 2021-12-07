#include "TrackMerger.h"
#include "TrackHandler.cc"
#include <bitset>

void ComparisonModule::inputTrack(const TrackHandler track){ 
  // put tracks into buffer

  if(track.getTrackWord() == 0){
    endOfStream = 1;
   //std::cout << "endOfStream: " << endOfStream << std::endl;
  } else {
    endOfStream = 0;
    #ifndef _SYNTHESIS_
    // std::cout << "Module#: " << myIndex << " InputTrack#: " << writeIndex << " " << track.getTrackWord() << "\n";
    #endif
    assert(writeIndex < bufferSize);
    inputBuffer[writeIndex] = track;
    if (masterTrack.getTrackWord() == 0){
      masterTrack = track;
    }
    writeIndex++;
  }

}
void ComparisonModule::processTrack(){
  if(endOfStream == 0){
   if (myIndex == 0){
     masterTrack.setDebugFlag(1);
   } else {
    masterTrack.setDebugFlag(0);
   }
    masterTrack.CompareTrack(track);
    masterTrack.MergeTrack(track, matchFound, mergeCondition);
    tracksProcessed++;
  }
}

void ComparisonModule::getTrack(){
  track = inputBuffer[readIndex];
  readIndex++;
}

void ComparisonModule::endEvent(TrackHandler outputBuffer[16], unsigned int outputWriteIndex){
  if(endOfStream == 1 && tracksProcessed == writeIndex){
    endOfModule = 1;
    #ifndef _SYNTHESIS_
    std::cout << "endOfStream: " << endOfStream << " tracksProcessed: " << tracksProcessed << " writeIndex: " << writeIndex << std::endl;
    #endif
    outputBuffer[outputWriteIndex] = masterTrack;
    writeIndex = 0;
    readIndex = 0;
    TrackFit::TrackWord nullWord(0);
    masterTrack.setTrackWord(nullWord);
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
  TrackFit::DiskStubWord diskStubWords_o[4][kMaxProc]
  ){

    ComparisonModule comparisonModule[kNComparisonModules];
    unsigned int outputIndex{0};
    for(unsigned int nModule = 0; nModule < kNComparisonModules; nModule++)
    {
      comparisonModule[nModule].myIndex=nModule;
    }
    TrackHandler outputBuffer[kNComparisonModules];
    unsigned int nActiveModules = 1;
    unsigned int modulesToRun[kNComparisonModules];
    modulesToRun[0] = 1;
    for (int i = 0; i < kMaxProc; i++){
      #ifndef _SYNTHESIS_
            //std::cout << "Step#: " << i << std::endl;
      #endif
      unsigned int moduleEnd{0};
      for (activeModule = 0; activeModule < kNComparisonModules activeModule++){
        if(comparisonModule[activeModule].getEndOfModule() == 1){
          moduleEnd++;
        }
      } 
      if(moduleEnd == kNComparisonModules){continue;}

      const TrackFit::BarrelStubWord barrelStubWordsArray[4] = {barrelStubWords[0][i], barrelStubWords[1][i], barrelStubWords[2][i], barrelStubWords[3][i]};
      const TrackFit::DiskStubWord diskStubWordsArray[4] = {diskStubWords[0][i], diskStubWords[1][i], diskStubWords[2][i], diskStubWords[3][i]};
      TrackHandler track(trackWord[i], barrelStubWordsArray, diskStubWordsArray);
      // run active modules 
      // local array to keep track of which modules have been activated
      unsigned int activeModules[kNComparisonModules];
      for(unsigned int activeModule = 0; activeModule < kNComparisonModules; activeModule++)
      {
        // if module has yet to be activated, carry on 
        if( modulesToRun[activeModule] == 0 ){ 
          continue;
        }
        activeModules[activeModule] = 1;
        // if it is active,  process this track 
        comparisonModule[activeModule].inputTrack(track);
        comparisonModule[activeModule].getTrack();
        comparisonModule[activeModule].processTrack();
        comparisonModule[activeModule].endEvent(outputBuffer, activeModule);

        // if it's the last Comparison Module 
        // nothing to pass an unmatched track to
        if(activeModule == kNComparisonModules-1) continue;
        // if the next Comparison Module is inactive 
        // and a mismatch has been found 
        // next comparison module also processes this track
        if(modulesToRun[activeModule+1] == 0 && comparisonModule[activeModule].getMatchFound() == 0 && comparisonModule[activeModule].getNProcessed() >1)
        {
          comparisonModule[activeModule+1].inputTrack(track);
          comparisonModule[activeModule+1].getTrack();
          comparisonModule[activeModule+1].processTrack();
          comparisonModule[activeModule+1].endEvent(outputBuffer, activeModule);
          activeModules[activeModule+1] = 1;
        }
      }
      
      // update global array that keeps track of which modules have been activated 
      for(unsigned int activeModule = 0; activeModule < kNComparisonModules; activeModule++)
      {
        modulesToRun[activeModule] = activeModules[activeModule];
      }

      //output the master track from each comparison module as the output array
      //also outputs any unmerged tracks from the last comparison module 
      for(unsigned int activeModule = 0; activeModule < kNComparisonModules; activeModule++){
        if(activeModules[activeModule] == 0){continue;}
        // if am not the last comparison module - when finished processing, output the master track
        if(comparisonModule[activeModule].getEndOfModule() == 1){
          trackWord_o[outputIndex] = comparisonModule[activeModule].getMasterTrackWord();
          for (unsigned int arrayIndex = 0; arrayIndex < 4; arrayIndex++){
            barrelStubWords_o[arrayIndex][outputIndex] = comparisonModule[activeModule].getMasterTrackBarrelStubs(arrayIndex, 0);
            diskStubWords_o[arrayIndex][outputIndex] = comparisonModule[activeModule].getMasterTrackDiskStubs(arrayIndex, 0);
          }  
          outputIndex++;
        }
        
        //if this is the last comparison module 
        //if it has found no duplicates - output this track (to keep track of unmerged tracks)
        //or if the module has finished processing tracks, output the master
        // if(activeModule == kNComparisonModules-1 && comparisonModule[activeModule].getMatchFound() == 0){
        //   //fill the outputs with the trackWord, barrel and disk stubs
        //   // trackWord_o[outputIndex] = trackWord[i];
        //   // for (unsigned int arrayIndex = 0; arrayIndex < 4; arrayIndex++){
        //   //   barrelStubWords_o[arrayIndex][outputIndex] = barrelStubWords[arrayIndex][i];
        //   //   diskStubWords_o[arrayIndex][outputIndex] = diskStubWords[arrayIndex][i];
        //   // }
        // }
        
      }
    }
    #ifndef _SYNTHESIS_
    //  std::cout << "outputBuffer: " << outputBuffer[0].getTrackWord() << " firstTrackWord: " << trackWord[0] << "\n";
    #endif
    for(unsigned int activeModule = 0; activeModule < kNComparisonModules; activeModule++)
    {
      #ifndef _SYNTHESIS_
        // std::cout << "\t\tModule#" << activeModule << " active " << modulesToRun[activeModule] << std::endl;
      #endif
    }
    bx_o = bx;

    #ifndef _SYNTHESIS_
    std::cout << "no. trackWords: " << outputIndex << std::endl;
    // for (unsigned int trackNumber = 0; trackNumber < outputIndex; trackNumber++){
    //   std::cout << "trackWord: " << trackWord[trackNumber] << " trackNumber: " << trackNumber << std::endl;
    // }
    #endif
}