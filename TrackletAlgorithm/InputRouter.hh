#ifndef INPUTROUTER_HH
#define INPUTROUTER_HH

#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"

void WriteMap(int address, ap_uint<kLINKMAPwidth>  encodedMap , DTCMapMemory *Map );

void ReadMap(int address, DTCMapMemory Map, DTCMap&  encodedMap);

// DTC (and therefore input link) is either PS or 2S .. 
// so a templated input router might make sense? 
template<int ISTypeBarrel, int ISTypeDisk>
void RouteStub(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<ISTypeBarrel> *hMemory_L1 ,InputStubMemory<ISTypeBarrel> *hMemory_L2, InputStubMemory<ISTypeBarrel> *hMemory_L3,
				  InputStubMemory<ISTypeDisk> *hMemory_D1, InputStubMemory<ISTypeDisk> *hMemory_D2, InputStubMemory<ISTypeDisk> *hMemory_D3 );
// implementation of input router 
// #include "InputRouter.tpp"


void InputRouter(const LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<BARRELPS> *hMemory_L1 ,InputStubMemory<BARRELPS> *hMemory_L2, InputStubMemory<BARRELPS> *hMemory_L3,
				  InputStubMemory<DISKPS> *hMemory_D1, InputStubMemory<DISKPS> *hMemory_D2, InputStubMemory<DISKPS> *hMemory_D3 );


void InputRouter(const LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<BARREL2S> *hMemory_L1 ,InputStubMemory<BARREL2S> *hMemory_L2, InputStubMemory<BARREL2S> *hMemory_L3,
				  InputStubMemory<DISK2S> *hMemory_D1, InputStubMemory<DISK2S> *hMemory_D2, InputStubMemory<DISK2S> *hMemory_D3 );


#endif
