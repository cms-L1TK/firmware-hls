#include "TrackFitMemory.h"

const unsigned int kFullBarrelStubSize = TrackFit::kBarrelStubSize * 4;
const unsigned int kFullDiskStubSize = TrackFit::kDiskStubSize * 4;
const unsigned int kFullTrackWordSize = TrackFit::kTrackWordSize;

class TrackHandler{
  public:
    TrackHandler(){};
    TrackHandler(const TrackFit::TrackWord trackWord,
      const TrackFit::BarrelStubWord barrelStubWords[4],
      const TrackFit::DiskStubWord diskStubWords[4])
    {
      //prepare the TrackHandler members
      //assign the bits to trackWord, barrelStubsWord, diskStubsWord
      // set the barrel and disk stub words in constructor using loop
      //all the information from the track and stub words;
      trkWord = trackWord;
      for (unsigned int j = 0; j < TrackFit::kNBarrelStubs; j++){ 
        barrelStubArray[j][0] = barrelStubWords[j];
      }

    for (unsigned int k = 0; k < TrackFit::kNDiskStubs; k++){
        diskStubArray[k][0] = diskStubWords[k];
    }
    
    }
  
    ~TrackHandler(){};
    TrackFit::TrackWord trkWord;
    TrackFit::BarrelStubWord barrelStubArray[4][10]; //adding extra dimension to array of size 10
    TrackFit::DiskStubWord diskStubArray[4][10];
    
    //masterTrack;
    //track;

    //Buffer 1D array of TH objects, each containing the 2d array of stubs
    


    //TrackFit::TFSTUBINDEX getStubIndex(int Hit) const {
    //  assert(Hit >= 0 && Hit <= kNStubs - 1);
    //  return track.range(TrackFitBits::kTFStubIndexMSB(Hit),TrackFitBits::kTFStubIndexLSB(Hit));
    //}
    // TFSTUBPHIRESID getStubPhiResid(int Hit) const {
    //   assert(Hit >= 0 && Hit <= kNStubs - 1);
    //   return track.range(TrackFitBits::kTFStubPhiResidMSB(Hit),TrackFitBits::kTFStubPhiResidLSB(Hit));
    // }
    // BarrelStubWord getBarrelStubWord(int Hit) const {
    //   assert(Hit >= 0 && Hit <= kNBarrelStubs - 1);
    //   return track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
    // }
    // DiskStubWord getDiskStubWord(int Hit) const {
    //   assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1);
    //   return track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
    // }
    // void setBarrelStubWord(const BarrelStubWord &word, int Hit) {
    //   assert(Hit >= 0 && Hit <= kNBarrelStubs - 1);
    //   track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = word;
    // }
    // void setDiskStubWord(const DiskStubWord &word, int Hit) {
    //   assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1);
    //   track.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = word;
    // }



  private:
};