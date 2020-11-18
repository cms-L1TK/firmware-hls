#include "InputRouterTop.h"

void InputRouterTop( const BXType hBx
  , const ap_uint<6> hInputLinkId // link id 
  , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT 
  , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT 
  , const ap_uint<kNMEMwidth> hNmemories // number of memories filled by each IR module
  , const int kPhiCorrtable_L1[] // corrections frst brl lyr  
  , const int kPhiCorrtable_L2[] // corrections scnd brl lyr   
  , const int kPhiCorrtable_L3[] // corrections thrd brl lyr  
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
    InputRouter<16>( hBx
        , hLinkWord
        , hPhBnWord
        , kPhiCorrtable_L1
        , kPhiCorrtable_L2
        , kPhiCorrtable_L3
        , hInputStubs
        , hOutputStubs);

  // check 
  #ifndef __SYNTHESIS__
    for( size_t cIndx=0; cIndx < cNMemories; cIndx++)
    {
      std::cout << "\t...Found " 
          << +hOutputStubs[cIndx].getEntries(hBx) 
          << " in memory#"
          << +cIndx 
          << " from HLS top level"
          << "\n";
    }
#endif

}
