#ifndef INPUTROUTERTOP_HH
#define INPUTROUTERTOP_HH


#include "InputRouter.hh"
#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"

void InputRouterTop(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC>* hIputLink,
				  InputStubMemory<BARRELPS> &hMemory_L1 ,InputStubMemory<BARRELPS> &hMemory_L2, InputStubMemory<BARRELPS> &hMemory_L3,
				  InputStubMemory<DISKPS> &hMemory_D1, InputStubMemory<DISKPS> &hMemory_D2, InputStubMemory<DISKPS> &hMemory_D3 , InputStubMemory<DISKPS> &hMemory_D4, InputStubMemory<DISKPS> &hMemory_D5 );


void InputRouterTop(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC>* hIputLink,
				  InputStubMemory<BARREL2S> &hMemory_L1 ,InputStubMemory<BARREL2S> &hMemory_L2, InputStubMemory<BARREL2S> &hMemory_L3,
				  InputStubMemory<DISK2S> &hMemory_D1, InputStubMemory<DISK2S> &hMemory_D2, InputStubMemory<DISK2S> &hMemory_D3, InputStubMemory<DISK2S> &hMemory_D4, InputStubMemory<DISK2S> &hMemory_D5 );


#endif
