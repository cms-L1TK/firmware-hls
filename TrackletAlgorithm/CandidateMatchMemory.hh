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
  CandidateMatch(CandidateMatchData newdata):
    data_(newdata)
  {}
  
  CandidateMatch(CMProjIndex projindex, CMStubIndex stubindex):
    data_( (projindex,stubindex) )
  {}
  
  CandidateMatch():
    data_(0)
  {}
  
  // copy constructor
  CandidateMatch(const CandidateMatch& rhs):
    data_(rhs.raw())
  {}
  
  CandidateMatch(const char* datastr, int base=16):
    data_(datastr, base)
  {}

  // Getter
  CandidateMatchData raw() const {return data_;}
  
  CMProjIndex GetProjIndex() const {
    return data_.range(kProjIndexLSB+kNBits_MemAddr-1,kProjIndexLSB);
  }

  CMStubIndex GetStubIndex() const {
    return data_.range(kStubIndexLSB+kNBits_MemAddr-1,kStubIndexLSB);
  }

private:
  
  CandidateMatchData data_;
  
};

// Memory definition
typedef MemoryTemplate<CandidateMatch, 1, kNBits_MemAddr> CandidateMatchMemory;

#endif
