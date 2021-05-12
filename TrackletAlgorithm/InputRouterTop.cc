#include "InputRouterTop.h"


void InputRouterTop( const BXType bx
  , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
  , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
  , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink] // input stubs 
  , BXType & bx_o // output bx 
  , DTCStubMemory hOutputStubs[cNMemories]) {

  #pragma HLS clock domain = slow_clock
  #pragma HLS stream variable = hInputStubs depth = 1
  
  InputRouter<cNMemories>( bx
      , hLinkWord
      , hPhBnWord
      , hInputStubs
      , bx_o
      , hOutputStubs);
}