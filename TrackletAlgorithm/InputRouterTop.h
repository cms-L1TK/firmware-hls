#ifndef INPUTROUTERTOP_HH
#define INPUTROUTERTOP_HH


// input router constants 

constexpr int kNRegionsLayer1 = 8;
constexpr int kNRegions = 4;  

#include "InputRouter.hh"
#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"



void is2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIs2S);
void isFirst(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIsFirst);

void InputRouterPS(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
				  InputRouterMemory<InputStub<BARRELPS>,kNBits_BX,kNBits_MemAddr> hMemory_L1[kNRegionsLayer1], InputRouterMemory<InputStub<BARRELPS>,kNBits_BX,kNBits_MemAddr> hMemory_L2[kNRegions], 
				  InputRouterMemory<InputStub<BARRELPS>,kNBits_BX,kNBits_MemAddr> hMemory_L3[kNRegions],
				  InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D1[kNRegions], InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D2[kNRegions], 
				  InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D3[kNRegions], InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D4[kNRegions], 
				  InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D5[kNRegions]);

void InputRouter2S(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
				  InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L1[kNRegions], InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L2[kNRegions], 
				  InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L3[kNRegions],
				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D1[kNRegions], InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D2[kNRegions], 
				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D3[kNRegions], InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D4[kNRegions], 
				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D5[kNRegions]) ;	

void InputRouterGeneric(const BXType bx, const int nStubs, const ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink], const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
				  MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemoriesPS[kTotalPSmemories], MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemories2S[kTotal2Smemories]);	

#endif
