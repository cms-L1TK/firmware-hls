// 
// CandidateMatches class
// 
// Contains candidate match definition
//
// 
#ifndef CANDIDATEMATCHES_HH
#define CANDIDATEMATCHES_HH
#include "ap_int.h"
#include "Constants.hh"

//const int MAX_nCM     = 5; // max number of CMs an individual module can handle (truncate)


const int nBITS_CM    = 14; // total number of bits for CM
const int nBITS_INDEX = 7;  // number of bits used for indexing

// Raw candidate match data
typedef ap_uint<nBITS_CM> CandidateMatch;

// Define bit widths for CM parameters
typedef ap_uint<nBITS_INDEX>   CM_proj_index; // projection (tracklet) index
typedef ap_uint<nBITS_INDEX>   CM_stub_index; // stub index


class CandidateMatches: public MemoryBase<CandidateMatch, 2, kMemDepth>
{
public:

  static CM_proj_index getProjIndex(const CandidateMatch data) { return data.range(13,7);}
  static CM_stub_index getStubIndex(const CandidateMatch data) { return data.range(6,0);}

}; // end class
#endif
