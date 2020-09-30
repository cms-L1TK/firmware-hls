#ifndef TrackletAlgorithm_InputRouterTop_h
#define TrackletAlgorithm_InputRouterTop_h

#include "InputRouter.h"
#include "DTCStubMemory.h"

void InputRouterTop( const BXType hBx
	, const ap_uint<6> hLinkId 
	, const ap_uint<kLINKMAPwidth> hLinkTable[kSizeLinkTable]
	, const int kPhiCorrtable_L1[kSizePhiCorrTablePS]
	, const int kPhiCorrtable_L2[kSizePhiCorrTablePS]
	, const int kPhiCorrtable_L3[kSizePhiCorrTablePS]
	, const int kPhiCorrtable_L4[kSizePhiCorrTable2S]
	, const int kPhiCorrtable_L5[kSizePhiCorrTable2S]
	, const int kPhiCorrtable_L6[kSizePhiCorrTable2S]
	, ap_uint<kNBits_DTC> hStubs[kMaxStubsFromLink]
	, DTCStubMemory hMemories[kNIRMemories]);

#endif


