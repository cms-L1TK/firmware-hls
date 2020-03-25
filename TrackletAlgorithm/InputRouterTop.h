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

// structs to keep track of passing things around 
// not templated because I want them here for now .. 
// PS barrel memories 
// sizes to use in this top level function 
typedef struct
{
    ap_uint<8> n1[kNRegionsLayer1]; 
	ap_uint<8> n2[kNRegions]; 
	ap_uint<8> n3[kNRegions];
} EntriesBarrelPS;
// memories 
typedef struct
{
	InputStubMemory<BARRELPS> m1[kNRegionsLayer1];
	InputStubMemory<BARRELPS> m2[kNRegions];
	InputStubMemory<BARRELPS> m3[kNRegions];
} StubsBarrelPS;
// 2S barrel memories 
// sizes 
typedef struct
{
    ap_uint<8> n1[kNRegions]; 
	ap_uint<8> n2[kNRegions]; 
	ap_uint<8> n3[kNRegions];
} EntriesBarrel2S;
// memories 
typedef struct
{
	InputStubMemory<BARREL2S> m1[kNRegionsLayer1];
	InputStubMemory<BARREL2S> m2[kNRegions];
	InputStubMemory<BARREL2S> m3[kNRegions];
} StubsBarrel2S;

// PS endcap memories 
// sizes
typedef struct
{
    ap_uint<8> n1[kNRegions]; 
	ap_uint<8> n2[kNRegions]; 
	ap_uint<8> n3[kNRegions];
	ap_uint<8> n4[kNRegions];
	ap_uint<8> n5[kNRegions];
} EntriesDiskPS;
// memories 
typedef struct
{
	InputStubMemory<DISKPS> m1[kNRegions];
	InputStubMemory<DISKPS> m2[kNRegions];
	InputStubMemory<DISKPS> m3[kNRegions];
	InputStubMemory<DISKPS> m4[kNRegions];
	InputStubMemory<DISKPS> m5[kNRegions];
} StubsDiskPS;

// 2S endcap memories 
// sizes 
typedef struct
{
    ap_uint<8> n1[kNRegions]; 
	ap_uint<8> n2[kNRegions]; 
	ap_uint<8> n3[kNRegions];
	ap_uint<8> n4[kNRegions];
	ap_uint<8> n5[kNRegions];
} EntriesDisk2S;
// memories 
typedef struct
{
	InputStubMemory<DISK2S> m1[kNRegions];
	InputStubMemory<DISK2S> m2[kNRegions];
	InputStubMemory<DISK2S> m3[kNRegions];
	InputStubMemory<DISK2S> m4[kNRegions];
	InputStubMemory<DISK2S> m5[kNRegions];
} StubsDisk2S;



void is2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIs2S);
void isFirst(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIsFirst);

void InputRouterPS(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	StubsBarrelPS hBarrelMemories, StubsDiskPS hDiskMemories);


void InputRouter2S(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	StubsBarrel2S hBarrelMemories, StubsDisk2S hDiskMemories);

void InputRouterGeneric(const BXType bx, const int nStubs, 
	const ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink], 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	IRMemory hMemoriesPS[kTotalPSmemories], 
	IRMemory hMemories2S[kTotal2Smemories]);	

#endif
