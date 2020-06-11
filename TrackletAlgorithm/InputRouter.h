#ifndef TrackletAlgorithm_InputRouter_h
#define TrackletAlgorithm_InputRouter_h

#include "Constants.h"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.h"

//constexpr unsigned int kInputLinkSize = 38;
//typedef ap_uint<kInputLinkSize> InputLinkData;
void InputRouter(const BXType bx, hls::stream<ap_uint<38> >& IL, InputStubMemory<BARRELPS> *R0PhiA, InputStubMemory<BARRELPS> *R0PhiB,
               InputStubMemory<BARRELPS> *R0PhiC, InputStubMemory<BARRELPS> *R0PhiD, InputStubMemory<BARRELPS> *R1PhiA, InputStubMemory<BARRELPS> *R1PhiB,
               InputStubMemory<BARRELPS> *R2PhiA, InputStubMemory<BARRELPS> *R2PhiB, InputStubMemory<BARRELPS> *R3PhiA, InputStubMemory<BARRELPS> *R3PhiB, bool fromL1);

#endif
