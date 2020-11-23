#include "InputRouterTop.h"

void InputRouterTop( const BXType hBx
  , const ap_uint<6> hInputLinkId // link id 
  , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
  , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
  , const ap_uint<kNMEMwidth> hNmemories // number of memories filled by each IR module
  , const int kPhiCorrtable_L1[kSizePhiCorrTable2S] // corrections frst brl lyr  
  , const int kPhiCorrtable_L2[kSizePhiCorrTable2S] // corrections scnd brl lyr   
  , const int kPhiCorrtable_L3[kSizePhiCorrTable2S] // corrections thrd brl lyr  
  , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]
  , DTCStubMemory hOutputStubs[cNMemories]) {

  #pragma HLS stream variable = hInputStubs depth = 1
 
  #ifndef __SYNTHESIS__
    std::cout << "IR module reading out link " << +hInputLinkId
      << " is going to fill "
      <<  hNmemories
      << " memories\n";
  #endif

  // only for PS10G_1_A for now 
  // other cases to be added 
  // when I have final link map
  if( hInputLinkId%12 == 6 ) 
    InputRouter<16,kSizePhiCorrTablePS>( hBx
        , hLinkWord
        , hPhBnWord
        , kPhiCorrtable_L1
        , kPhiCorrtable_L2
        , kPhiCorrtable_L3
        , hInputStubs
        , hOutputStubs);
}
