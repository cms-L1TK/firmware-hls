#ifndef TrackletAlgorithm_InputRouterTop_h
#define TrackletAlgorithm_InputRouterTop_h

#include "InputRouter.h"


// at the moment I'm changing this for each link 
// is that really the only way to do this? 
constexpr unsigned int cNMemories = 16; 

void InputRouterTop( const BXType hBx
	, const ap_uint<6> hInputLinkId // link id 
	, const ap_uint<kLINKMAPwidth> kInputLink // input link LUT 
  	, const ap_uint<kBINMAPwidth> kNPhiBns  // n phi bins LUT 
  	, const ap_uint<kNMEMwidth> kLinkNMemories // number of memories filled by each IR module
  	, const int* kPhiCorrtable_L1 // corrections frst brl lyr  
	, const int* kPhiCorrtable_L2 // corrections scnd brl lyr  
	, const int* kPhiCorrtable_L3 // corrections thrd brl lyr   
	, ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]//input stubs 
	, DTCStubMemory hOutputStubs[cNMemories]);//output memories 


#endif


