#ifndef CANDIDATEMATCHMEMORY_HH
#define CANDIDATEMATCHMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"

// Data object definition
class CandidateMatch
{
public:
  
  static const int nBITS_INDEX = 7;  // number of bits used for indexing
  static const int nBITS_CM    = 2*nBITS_INDEX; // total number of bits for CM

  // Raw candidate match data
  typedef ap_uint<nBITS_CM> CandidateMatchData;

  // Define bit widths for CM parameters
  typedef ap_uint<nBITS_INDEX>   CMProjIndex; // projection (tracklet) index
  typedef ap_uint<nBITS_INDEX>   CMStubIndex; // stub index

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
  
  CandidateMatch(const char* datastr, int base=16)
  {
    CandidateMatchData newdata(datastr, base);
    data_ = newdata;
  }


  // Getter
  CandidateMatchData raw() const {return data_;}
  
  CMProjIndex GetProjIndex() const {return data_.range(13,7);}
  CMStubIndex GetStubIndex() const {return data_.range(6,0);}
  
private:
  
  CandidateMatchData data_;
  
};

// Memory definition
typedef MemoryTemplate<CandidateMatch, 1, kNBits_MemAddr> CandidateMatchMemory;

#endif
