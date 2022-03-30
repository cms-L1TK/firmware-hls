#ifndef TrackletAlgorithm_CandidateMatchMemory_h
#define TrackletAlgorithm_CandidateMatchMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// Data object definition
class CandidateMatch
{
public:

  enum BitWidths {
    // Bit size for full CandidateMatchMemory
    kCandidateMatchSize = 2*kNBits_MemAddr + 1
  };
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the CandidateMatchMemory word for different fields
    kCMStubIndexLSB = 0,
    kCMStubIndexMSB = kCMStubIndexLSB + kNBits_MemAddr - 1,
    kCMIsPSStubLSB = kCMStubIndexMSB + 1,
    kCMProjIndexLSB = kCMIsPSStubLSB + 1,
    kCMProjIndexMSB = kCMProjIndexLSB + kNBits_MemAddr - 1
  };
  
  // Define bit widths for CM parameters
  typedef ap_uint<kNBits_MemAddr> CMProjIndex; // projection (tracklet) index
  typedef ap_uint<kNBits_MemAddr> CMStubIndex; // stub index

  // Raw candidate match data
  typedef ap_uint<kCandidateMatchSize> CandidateMatchData;

  // Constructors
  CandidateMatch(const CandidateMatchData& newdata):
    data_(newdata)
  {}

  CandidateMatch(const CMProjIndex projindex, const CMStubIndex stubindex):
    data_( ((projindex,1),stubindex) )
  {}

  CandidateMatch(const CMProjIndex projindex, bool isPSStub, const CMStubIndex stubindex):
    data_( ((projindex,isPSStub),stubindex) )
  {}
  
  CandidateMatch()
  {}

  #ifndef __SYNTHESIS__
  CandidateMatch(const char* datastr, int base=16)
  {
    CandidateMatchData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return kCandidateMatchSize;}
  
  CandidateMatchData raw() const {return data_;}
  
  CMProjIndex getProjIndex() const {
    return data_.range(kCMProjIndexMSB,kCMProjIndexLSB);
  }

  bool getIsPSStub() const {
    return data_.range(kCMIsPSStubLSB,kCMIsPSStubLSB);
  }

  CMStubIndex getStubIndex() const {
    return data_.range(kCMStubIndexMSB,kCMStubIndexLSB);
  }

  // Setter
  void setProjIndex(const CMProjIndex id) {
    data_.range(kCMProjIndexMSB,kCMProjIndexLSB) = id;
  }

  void setIsPSStub(const bool isPSStub) {
    data_.range(kCMIsPSStubLSB,kCMIsPSStubLSB) = isPSStub;;
  }

  void setStubIndex(const CMStubIndex id) {
    data_.range(kCMStubIndexMSB,kCMStubIndexLSB) = id;
  }

private:
  
  CandidateMatchData data_;
  
};

// Memory definition
typedef MemoryTemplate<CandidateMatch, 1, kNBits_MemAddr> CandidateMatchMemory;

#endif
