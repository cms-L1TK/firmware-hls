#ifndef INPUTROUTER_HH
#define INPUTROUTER_HH

#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"
#include <bitset> 
#include <cassert>


// //template<int...Ts> void WriteMemories(Ts... hMemory);
// template<typename ...Links, typename ...Memories> void ProcessLink(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, Links..., Memories...) 
// {
// 	#pragma HLS ARRAY_PARTITION variable=in_local complete dim=2
// }


void ProcessLink(const BXType bx, ap_uint<kNBits_DTC>* cStub , int cNstubs);

// to-do .. template array size to improve efficiency here 
template<int ISTypeBarrel, int ISTypeDisk>
void InputRouter(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC> hStubs[kMaxStubsFromLink],
				  TFStubMemory& hMemory_L1 ,TFStubMemory& hMemory_L2, TFStubMemory& hMemory_L3,
				  TFStubMemory& hMemory_D1, TFStubMemory& hMemory_D2, TFStubMemory& hMemory_D3 , TFStubMemory& hMemory_D4, TFStubMemory& hMemory_D5 )
{
	// input port as a fifo 
	#pragma HLS interface ap_none port=hDTCMapEncoded
	//#pragma HLS INTERFACE ap_fifo port=hStubs 
	//memories as BRAMS
	// #pragma HLS INTERFACE bram port=hMemory_L1
	// #pragma HLS INTERFACE bram port=hMemory_L2
	// #pragma HLS INTERFACE bram port=hMemory_L3
	// //
	// #pragma HLS INTERFACE bram port=hMemory_D1
	// #pragma HLS INTERFACE bram port=hMemory_D2
	// #pragma HLS INTERFACE bram port=hMemory_D3
	// #pragma HLS INTERFACE bram port=hMemory_D4
	// #pragma HLS INTERFACE bram port=hMemory_D5

	ap_uint<kNBits_DTC> hInputStub;
	// clear barrel memories for this bunch crossing 
	hMemory_L1.clear(bx);
	hMemory_L2.clear(bx);
	hMemory_L3.clear(bx);
	// clear end-cap memories for this bunch crossing 
	hMemory_D1.clear(bx);
	hMemory_D2.clear(bx);
	hMemory_D3.clear(bx);
	hMemory_D4.clear(bx);
	hMemory_D5.clear(bx);

	for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
	{
		#pragma HLS pipeline II=1
			hInputStub = hStubs[cStubCounter];
			//std::cout << " \t\t\t... Stub " << std::hex << hInputStub << std::dec << "\n";
			ap_uint<kNBits_Debug> cDebugWord = hInputStub.range(kNBits_DTC-1,kNBits_DTC-kNBits_Debug);
			ap_uint<kNBits_LayerId> cLayerId  = cDebugWord.range(kNBits_Debug-kNBits_Valid-1,kNBits_Debug-kNBits_Valid-kNBits_LayerId);

			// encoded layer id 
			ap_uint<5> cLayerEncoding; 
			if( cLayerId == 0 )
				cLayerEncoding = hDTCMapEncoded.range(3,0);
			else if( cLayerId == 1 )
				cLayerEncoding = hDTCMapEncoded.range(8,4);
			else if( cLayerId == 2 )
				cLayerEncoding = hDTCMapEncoded.range(13,9);
			else 
				cLayerEncoding = hDTCMapEncoded.range(17,14);

			ap_uint<1> cIsBarrel = cLayerEncoding.range(0,0) ;
			ap_uint<3> cLayerOrDiskId = cLayerEncoding.range(3,1);
			// for now assuming one memory per layer .. no phi segmentation here 
			// can do this once I know what the phi segmentation is here ..   
			ap_uint<3> cPhiRegion; 
			TFStub hStub(hInputStub.range(kBRAMwidth-1,0));
			if( cIsBarrel == 1  )
			{
				hStub.setBitLocations<ISTypeBarrel>();
				auto cPhiNibble = hStub.getPhi<ISTypeBarrel>();
				cPhiRegion = hStub.getCoarsePhiRegion<ISTypeBarrel>((cLayerOrDiskId==1) ? 3 : 2); // number of bits that can be used to encode phi region : 2 --> 0,1,2,3 3 --> 0,1,2,3,4,5,6,7 as possible values
				#ifndef __SYNTHESIS__
					std::cout << "\t.. layer " << +cLayerOrDiskId << " ... phi nibble is " << cPhiNibble << " -- " << std::bitset<InputStubBase<ISTypeDisk>::kISPhiSize>(cPhiNibble) << " phi region is " << (cPhiRegion) << " stub is " << std::bitset<kBRAMwidth>(hStub.raw()) << "\n";
				#endif

				assert( (cLayerOrDiskId >= 1) || (cLayerOrDiskId<=6)  );
				if( cLayerOrDiskId == 1 || cLayerOrDiskId == 4 ) 
				{
					hMemory_L1.write_mem(bx, hStub.raw(), hMemory_L1.getEntries(bx) );
				}
				else if( cLayerOrDiskId == 2 || cLayerOrDiskId == 5 ) 
				{
					hMemory_L2.write_mem(bx, hStub.raw(), hMemory_L2.getEntries(bx) );
				}
				else if( cLayerOrDiskId == 3 || cLayerOrDiskId == 6 )
				{ 
					hMemory_L3.write_mem(bx, hStub.raw(), hMemory_L3.getEntries(bx) );
				}
				#ifndef __SYNTHESIS__
					//cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
				#endif
			}
			else if( cIsBarrel == 0  )
			{
				hStub.setBitLocations<ISTypeDisk>();
  				auto cPhiNibble = hStub.getPhi<ISTypeDisk>();
				cPhiRegion = hStub.getCoarsePhiRegion<ISTypeDisk>();
				#ifndef __SYNTHESIS__
					std::cout << "\t.. layer " << +cLayerOrDiskId << " ... phi nibble is " << cPhiNibble << " -- " << std::bitset<InputStubBase<ISTypeDisk>::kISPhiSize>(cPhiNibble) << " phi region is " << (cPhiRegion) << " stub is " << std::bitset<kBRAMwidth>(hStub.raw()) << "\n";
				#endif
				
				assert( (cLayerOrDiskId >= 1) || (cLayerOrDiskId<=5)  );
				if( cLayerOrDiskId == 1 ) 
				{
					hMemory_D1.write_mem(bx, hStub.raw(), hMemory_D1.getEntries(bx) );
				}
				else if( cLayerOrDiskId == 2 ) 
				{
					hMemory_D2.write_mem(bx, hStub.raw(),  hMemory_D2.getEntries(bx) );
				}
				else if( cLayerOrDiskId == 3 )
				{
					hMemory_D3.write_mem(bx, hStub.raw(),  hMemory_D3.getEntries(bx) );
				}
				else if( cLayerOrDiskId == 4 )
				{
					hMemory_D4.write_mem(bx, hStub.raw(),  hMemory_D4.getEntries(bx) );
				}
				else if( cLayerOrDiskId == 5 )
				{
					hMemory_D5.write_mem(bx, hStub.raw(),  hMemory_D5.getEntries(bx) );
				}
			}
	}
}// input router 
#endif
