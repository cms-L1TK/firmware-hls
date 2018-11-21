#ifndef CANDIDATEMATCHMEMORY_HH
#define CANDIDATEMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Bit size for full CandidateMatchMemory
constexpr unsigned int kCandidateMatchSize = 2*kNBits_MemAddr;

// The location of the least significant bit (LSB) and most significant bit (MSB) in the CandidateMatchMemory word for different fields
constexpr unsigned int kCMStubIndexLSB = 0;
constexpr unsigned int kCMStubIndexMSB = kCMStubIndexLSB + kNBits_MemAddr - 1;
constexpr unsigned int kCMProjIndexLSB = kCMStubIndexMSB + 1;
constexpr unsigned int kCMProjIndexMSB = kCMProjIndexLSB + kNBits_MemAddr - 1;

// Data object definition
class CandidateMatch
{
public:
  
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
    data_( (projindex,stubindex) )
  {}
  
  CandidateMatch():
    data_(0)
  {}

  CandidateMatch(const char* datastr, int base=16)
  {
    CandidateMatchData newdata(datastr, base);
    data_ = newdata;
  }

  // Getter
  CandidateMatchData raw() const {return data_;}
  
  CMProjIndex GetProjIndex() const {
    return data_.range(kCMProjIndexMSB,kCMProjIndexLSB);
  }

  CMStubIndex GetStubIndex() const {
    return data_.range(kCMStubIndexMSB,kCMStubIndexLSB);
  }

  // Setter
  void SetProjIndex(const CMProjIndex id) {
    data_.range(kCMProjIndexMSB,kCMProjIndexLSB) = id;
  }

  void SetStubIndex(const CMStubIndex id) {
    data_.range(kCMStubIndexMSB,kCMStubIndexLSB) = id;
  }

private:
  
  CandidateMatchData data_;
  
};

// Memory definition
typedef MemoryTemplate<CandidateMatch, 1, kNBits_MemAddr> CandidateMatchMemory;

#endif
