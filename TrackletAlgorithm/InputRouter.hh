#ifndef INPUTROUTER_HH
#define INPUTROUTER_HH

#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"

//typedef ap_uint<kInputLinkSize> InputLinkData;

template<int ISType>
void InputRouter(LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& IL, InputStubMemory<ISType>* hMemory );

void WriteMap(int address, ap_uint<kLINKMAPwidth>  encodedMap , DTCMapMemory *Map );

void ReadMap(int address, DTCMapMemory Map, DTCMap&  encodedMap);
#endif
