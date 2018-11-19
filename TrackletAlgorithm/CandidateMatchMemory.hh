#ifndef CANDIDATEMATCHMEMORY_HH
#define CANDIDATEMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

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

  // copy constructor
  CandidateMatch(const CandidateMatch& rhs):
    data_(rhs.raw())
  {}
  
  // Getter
  CandidateMatchData raw() const {return data_;}
  
  CMProjIndex GetProjIndex() const {
    return data_.range(kCMProjIndexLSB+kNBits_MemAddr-1,kCMProjIndexLSB);
  }

  CMStubIndex GetStubIndex() const {
    return data_.range(kCMStubIndexLSB+kNBits_MemAddr-1,kCMStubIndexLSB);
  }

  // Setter
  void SetProjIndex(const CMProjIndex id) {
    data_.range(kCMProjIndexLSB+kNBits_MemAddr-1,kCMProjIndexLSB) = id;
  }

  void SetStubIndex(const CMStubIndex id) {
    data_.range(kCMStubIndexLSB+kNBits_MemAddr-1,kCMStubIndexLSB) = id;
  }

private:
  
  CandidateMatchData data_;
  
};

// Memory definition
typedef MemoryTemplate<CandidateMatch, 1, kNBits_MemAddr> CandidateMatchMemory;

#endif
