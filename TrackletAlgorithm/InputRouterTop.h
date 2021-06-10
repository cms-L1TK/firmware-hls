#ifndef TrackletAlgorithm_InputRouterTop_h
#define TrackletAlgorithm_InputRouterTop_h

#include "InputRouter.h"


// at the moment I'm changing this for each link 
// is that really the only way to do this? 

// only for PS10G_3_A for now 
// other cases to be added 
// when I have final link map
//constexpr unsigned int cTest = (const)(std::atoi(getenv ("TEST")));
constexpr unsigned int cNMemories = 7;

void InputRouterTop( const BXType bx
	, const ap_uint<kLINKMAPwidth> kInputLink // input link LUT 
  	, const ap_uint<kBINMAPwidth> kNPhiBns  // n phi bins LUT 
	, ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]//input stubs 
	, BXType & bx_o // output bx 
    , DTCStubMemory hOutputStubs[cNMemories]);//output memories 

#endif


