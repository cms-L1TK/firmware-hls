#ifndef INPUTROUTERTOP_HH
#define INPUTROUTERTOP_HH


#include "InputRouter.hh"
#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"

// void InputRouterTopPS(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
// 				  InputStubMemory<BARRELPS> &hMemory_L1 ,InputStubMemory<BARRELPS> &hMemory_L2, InputStubMemory<BARRELPS> &hMemory_L3,
// 				  InputStubMemory<DISKPS> &hMemory_D1, InputStubMemory<DISKPS> &hMemory_D2, InputStubMemory<DISKPS> &hMemory_D3 , InputStubMemory<DISKPS> &hMemory_D4, InputStubMemory<DISKPS> &hMemory_D5 );


// void InputRouterTop2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
// 				  InputStubMemory<BARREL2S> &hMemory_L1 ,InputStubMemory<BARREL2S> &hMemory_L2, InputStubMemory<BARREL2S> &hMemory_L3,
				  // InputStubMemory<DISK2S> &hMemory_D1, InputStubMemory<DISK2S> &hMemory_D2, InputStubMemory<DISK2S> &hMemory_D3, InputStubMemory<DISK2S> &hMemory_D4, InputStubMemory<DISK2S> &hMemory_D5 );


void is2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIs2S);
void isFirst(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIsFirst);


void InputRouterGeneric(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
				  TFStubMemory &hMemory_L1 ,TFStubMemory &hMemory_L2, TFStubMemory &hMemory_L3,
				  TFStubMemory &hMemory_D1, TFStubMemory &hMemory_D2, TFStubMemory &hMemory_D3, TFStubMemory &hMemory_D4, TFStubMemory &hMemory_D5 );


void InputRouterTop(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink],
				  TFStubMemory &hMemory_L1 ,TFStubMemory &hMemory_L2, TFStubMemory &hMemory_L3,
				  TFStubMemory &hMemory_D1, TFStubMemory &hMemory_D2, TFStubMemory &hMemory_D3, TFStubMemory &hMemory_D4, TFStubMemory &hMemory_D5 );


#endif
