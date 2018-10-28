// 
// StubPairs class
// 
// Contains stub pair definition
//
// 
#ifndef STUBPAIRS_HH
#define STUBPAIRS_HH
#include "ap_int.h"
#include "Constants.hh"

//const int MAX_nCM     = 5; // max number of CMs an individual module can handle (truncate)


const int nBITS_SP    = 14; // total number of bits for CM
const int nBITS_INDEX = 7;  // number of bits used for indexing

// Raw candidate match data
typedef ap_uint<nBITS_SP> StubPair;

// Define bit widths for SP parameters
typedef ap_uint<nBITS_INDEX>   SP_stub_index; // stub index


class StubPairs: public MemoryBase<StubPair, 2, kMemDepth>
{
public:

  static SP_stub_index getStubIndexInner(const StubPair data) { return data.range(13,7);}
  static SP_stub_index getStubIndexOuter(const StubPair data) { return data.range(6,0);}

}; // end class
#endif
