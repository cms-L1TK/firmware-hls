#include "InputRouter.hh"

#include <bitset> 


void ParseMap( const ap_uint<kNBits_DTC> hInputStub, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<4>& hDecodedMap)
{
	ap_uint<kNBits_Debug> cDebugWord;
	ap_uint<kNBits_LayerId> cLayerId;

	cDebugWord = hInputStub.range(kNBits_DTC-1,
		kNBits_DTC-kNBits_Debug);
	cLayerId  = cDebugWord.range(kNBits_Debug-kNBits_Valid-1,
		kNBits_Debug-kNBits_Valid-kNBits_LayerId);
	if( cLayerId == 0 )
		hDecodedMap = hDTCMapEncoded.range(3,0);
	else if( cLayerId == 1 )
		hDecodedMap = hDTCMapEncoded.range(7,4);
	else if( cLayerId == 2 )
		hDecodedMap = hDTCMapEncoded.range(11,8);
	else 
		hDecodedMap = hDTCMapEncoded.range(15,12);
}
// hTrackerRegion : 0 --> endcap, 1 --> barrel
void DecodeTrackerRegion( const ap_uint<kNBits_DTC> hInputStub, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hTrackerRegion ) 
{
	ap_uint<4> hDecodedMap;
	ParseMap( hInputStub, hDTCMapEncoded, hDecodedMap);
	hTrackerRegion = hDecodedMap.range(0,0) ;
}
void DecodeLayer( const ap_uint<kNBits_DTC> hInputStub, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<3>& hLayerOrDiskId )
{
	ap_uint<4> hDecodedMap;
	ParseMap( hInputStub, hDTCMapEncoded, hDecodedMap);
	hLayerOrDiskId = hDecodedMap.range(3,1);
}
void DecodeMap( const ap_uint<kNBits_DTC> hInputStub, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<3>& hLayerOrDiskId, 
	ap_uint<1>& hTrackerRegion)
{
	ap_uint<4> hDecodedMap;
	ParseMap( hInputStub, hDTCMapEncoded, hDecodedMap);

	hLayerOrDiskId = hDecodedMap.range(3,1);
	hTrackerRegion = hDecodedMap.range(0,0) ;
}

void is2S(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIs2S)
{
	hIs2S  =  hDTCMapEncoded.range(kLINKMAPwidth-2,kLINKMAPwidth-2);
}
void isFirst(ap_uint<kLINKMAPwidth> hDTCMapEncoded, ap_uint<1>& hIsFirst)
{
	hIsFirst  =  hDTCMapEncoded.range(kLINKMAPwidth-1,kLINKMAPwidth-1);
}

void RouteStub(const BXType bx, const ap_uint<kNBits_DTC> hStub, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	IRMemory hPS[kTotalPSmemories], 
	IRMemory h2S[kTotal2Smemories] )
{
	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	ap_uint<1> cFirst; isFirst(hDTCMapEncoded, cFirst);
	ap_uint<3> cLayerOrDiskId;
	ap_uint<1> cIsBarrel;

	DecodeMap( hStub, hDTCMapEncoded , cLayerOrDiskId, cIsBarrel);
	// get the index of the memory to write to 
	ap_uint<8> cMemIndex=0; 
	if( cIs2S )
	{
		// 4 coarse phi regions per 2S barrel layer .. 3 barrel layers 
		cMemIndex = ( cIsBarrel == 1 ) ? 0 : 12; 
		if( cIsBarrel == 1 )
			cMemIndex = (cMemIndex + 4*cLayerOrDiskId);
		else 
			cMemIndex + 4*cLayerOrDiskId;
	}
	else
	{
		// 8 coarse phi regions for L1 
		// 4 coarse phi regions for remaining 3 .. 3 barrel layers 
		cMemIndex = ( cIsBarrel == 1 ) ? 0 : 20; 
		if( cIsBarrel == 1 && cFirst )
			cMemIndex = cMemIndex ; 
		else if ( cIsBarrel == 1 )
			cMemIndex = cMemIndex + 8 + 4*(cLayerOrDiskId-1);
		else 
			cMemIndex = cMemIndex + 4*(cLayerOrDiskId-1);
	}	
	#ifndef __SYNTHESIS__
		std::cout << "\t.. Input stub is " 
				  << std::bitset<kNBits_DTC>(hStub) 
				  << " layer id is " << cLayerOrDiskId 
				  << " 2S bit is set to " << cIs2S 
				  << " barrel bit is set to " 
				  << cIsBarrel << " - memory index is " << cMemIndex << "\n";
	#endif

	if( cIsBarrel && cIs2S)
		WriteStubToMemory<BARREL2S,2>(bx, hStub, cMemIndex, h2S);
	else if( !cIsBarrel && cIs2S )
		WriteStubToMemory<DISK2S,2>(bx, hStub, cMemIndex, h2S);
	else if( cFirst )
		WriteStubToMemory<BARRELPS,3>(bx, hStub, cMemIndex, hPS);
	else if( cIsBarrel )
		WriteStubToMemory<BARRELPS,2>(bx, hStub, cMemIndex, hPS);
	else	
		WriteStubToMemory<BARREL2S,2>(bx, hStub, cMemIndex, hPS);
}