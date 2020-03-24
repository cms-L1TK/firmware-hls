#ifndef INPUTROUTER_HH
#define INPUTROUTER_HH

#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"
#include <cassert>


void is2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIs2S);
void isFirst(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIsFirst);

// function to get decoded map 
void ParseMap( const ap_uint<kNBits_DTC> hInputStub, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<5>& hDecodedMap);

// function to decode tracker region [barrel or endcap .. 0 --> barrel, 1 --> endcap ]
void DecodeTrackerRegion( const ap_uint<kNBits_DTC> hInputStub, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hTrackerRegion );

// function to decode layer id 
void DecodeLayer( const ap_uint<kNBits_DTC> hInputStub, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<3>& hLayerOrDiskId );

// function to decode layer id + tracker region 
void DecodeMap( const ap_uint<kNBits_DTC> hInputStub, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<3>& hLayerOrDiskId, ap_uint<1>& hTrackerRegion);


// fucntion to get coarse phi region 
template<class DataType, int NBits>
void GetCoarsePhiRegion(const ap_uint<kNBits_DTC> hInputStub, ap_uint<NBits> &hPhiRegion )
{
	// stub from input stub 
	DataType hStub(hInputStub.range(kBRAMwidth-1,0));
	auto cPhi = hStub.getPhi();
	hPhiRegion = hStub.template getCoarsePhiRegion<NBits>(); 
	// #ifndef __SYNTHESIS__
	// 	std::cout << "\t.. Phi value " << cPhi << " phi region is " << hPhiRegion << " [ phi is divided into " << std::pow(2,NBits) << " regions for this memory" << "\n";
	// #endif
}

// write memory function
template<class DataType, int NBits, int Nmemories>
void WriteMemories(const BXType bx, const ap_uint<kNBits_DTC> hInputStub, InputRouterMemory<DataType,kNBits_BX,kNBits_MemAddr> hMemory[Nmemories])
{
	ap_uint<NBits> cPhiRegion;
	GetCoarsePhiRegion<DataType,NBits>(hInputStub, cPhiRegion );
	assert(cPhiRegion >= 0 && cPhiRegion < Nmemories );
	
	// #ifndef __SYNTHESIS__
	// 	std::cout << "\t.. Writing to memory connected to phi region " << +cPhiRegion << "\n";
	// #endif

	DataType hStub(hInputStub.range(kBRAMwidth-1,0));
	(&hMemory[cPhiRegion])->write_mem(bx, hStub, (&hMemory[cPhiRegion])->getEntries(bx) );
}

// write memory function
template<class DataType, int NBits>
void WriteMemory(const BXType bx, const ap_uint<kNBits_DTC> hInputStub, InputRouterMemory<DataType,kNBits_BX,kNBits_MemAddr>* hMemory)
{
	ap_uint<NBits> cPhiRegion;
	GetCoarsePhiRegion<DataType,NBits>(hInputStub, cPhiRegion );
	if( NBits == 2 ) 
		assert(cPhiRegion >= 0 && cPhiRegion < 4 );
	else
		assert(cPhiRegion >= 0 && cPhiRegion < 8 );

	DataType hStub(hInputStub.range(kBRAMwidth-1,0));
	hMemory->write_mem(bx, hStub, hMemory->getEntries(bx) );
}

// write memory function
template<class DataType, int NBits>
void WriteStubToMemory(const BXType bx, const ap_uint<kNBits_DTC> hInputStub, const ap_uint<8> hIndex, MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemories[8])
{
	ap_uint<NBits> cPhiRegion;
	GetCoarsePhiRegion<DataType,NBits>(hInputStub, cPhiRegion );
	if( NBits == 2 ) 
		assert(cPhiRegion >= 0 && cPhiRegion < 4 );
	else
		assert(cPhiRegion >= 0 && cPhiRegion < 8 );

	DataType hStub(hInputStub.range(kBRAMwidth-1,0));
	(&hMemories[hIndex+cPhiRegion])->write_mem(bx, hStub.raw(), (&hMemories[hIndex+cPhiRegion])->getEntries(bx) );
}


//
void RouteStub(const BXType bx, const ap_uint<kNBits_DTC> hInputStub, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemoriesPS[kTotalPSmemories], MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemories2S[kTotal2Smemories] );

//
//
// // variadic template .. act on each item in the list of objects passed
// // apparently recursive functions don't synthesize in HLS .. so this is never going to work 
// template<class DataType, class ... Memories>
// void WriteMemory(const BXType bx, const ap_uint<kNBits_DTC> hStub, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, Memories&... hMemories)
// {
// 	WriteMemory<DataType>(bx, hStub, hDTCMapEncoded, hMemories...);
// }

#endif
