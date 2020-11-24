#include "InputRouterTop.h"

void InputRouterTop( const BXType hBx
  , const ap_uint<6> hInputLinkId // link id 
  , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
  , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
  , const ap_uint<kNMEMwidth> hNmemories // number of memories filled by each IR module
  , const int kPhiCorrtable_L1[cNEntriesLUT] // corrections frst brl lyr  
  , const int kPhiCorrtable_L2[cNEntriesLUT] // corrections scnd brl lyr   
  , const int kPhiCorrtable_L3[cNEntriesLUT] // corrections thrd brl lyr  
  , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]
  , DTCStubMemory hOutputStubs[cNMemories]) {

  #pragma HLS clock domain = slow_clock
  #pragma HLS stream variable = hInputStubs depth = 1
 
  #ifndef __SYNTHESIS__
    std::cout << "IR module reading out link " << +hInputLinkId
      << " is going to fill "
      <<  hNmemories
      << " memories\n";
  #endif

  InputRouter<cNMemories,cNEntriesLUT>( hBx
      , hLinkWord
      , hPhBnWord
      , kPhiCorrtable_L1
      , kPhiCorrtable_L2
      , kPhiCorrtable_L3
      , hInputStubs
      , hOutputStubs);
}
