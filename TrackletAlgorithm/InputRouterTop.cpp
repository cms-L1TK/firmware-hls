#include "InputRouterTop.h"
#include "InputRouter.cc"



// route stubs for PS memories only 
void InputRouterPS(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
				  InputRouterMemory<InputStub<BARRELPS>,kNBits_BX,kNBits_MemAddr> hMemory_L1[kNRegionsLayer1], InputRouterMemory<InputStub<BARRELPS>,kNBits_BX,kNBits_MemAddr> hMemory_L2[kNRegions], 
				  InputRouterMemory<InputStub<BARRELPS>,kNBits_BX,kNBits_MemAddr> hMemory_L3[kNRegions],
				  InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D1[kNRegions], InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D2[kNRegions], 
				  InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D3[kNRegions], InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D4[kNRegions], 
				  InputRouterMemory<InputStub<DISKPS>,kNBits_BX,kNBits_MemAddr> hMemory_D5[kNRegions])
{
	#pragma HLS interface ap_none port=hDTCMapEncoded
	#pragma HLS interface ap_fifo port=hIputLink

	// clear memories for this bunch crossing 
	ap_uint<8> nEntriesL1[kNRegionsLayer1]; 
	ap_uint<8> nEntriesL2[kNRegions]; 
	ap_uint<8> nEntriesL3[kNRegions];
	ap_uint<8> nEntriesD1[kNRegions]; 
	ap_uint<8> nEntriesD2[kNRegions];
	ap_uint<8> nEntriesD3[kNRegions]; 
	ap_uint<8> nEntriesD4[kNRegions];
	ap_uint<8> nEntriesD5[kNRegions];

	#pragma HLS ARRAY_PARTITION variable=nEntriesL1 complete dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesL2 complete dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesL3 complete dim=1

	#pragma HLS ARRAY_PARTITION variable=nEntriesD1 complete dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD2 complete dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD3 complete dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD4 complete dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD5 complete dim=1

	// #pragma HLS ARRAY_PARTITION variable=nEntriesL1 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesL2 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesL3 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesD1 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesD2 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesD3 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesD4 cyclic factor=4 dim=1
	// #pragma HLS ARRAY_PARTITION variable=nEntriesD5 cyclic factor=4 dim=1

	LOOP_ClearInputStubsPS : for( int cPhiRegion=0; cPhiRegion<kNRegionsLayer1; cPhiRegion++)
	{
		if( cPhiRegion < kNRegions )
		{
			(&hMemory_L2[cPhiRegion])->clear(bx);
			(&hMemory_L3[cPhiRegion])->clear(bx);
			(&hMemory_D1[cPhiRegion])->clear(bx);
			(&hMemory_D2[cPhiRegion])->clear(bx);
			(&hMemory_D3[cPhiRegion])->clear(bx);
			(&hMemory_D4[cPhiRegion])->clear(bx);
			(&hMemory_D5[cPhiRegion])->clear(bx);
			nEntriesL2[cPhiRegion]=0;
			nEntriesL3[cPhiRegion]=0;
			nEntriesD1[cPhiRegion]=0;
			nEntriesD2[cPhiRegion]=0;
			nEntriesD3[cPhiRegion]=0;
			nEntriesD4[cPhiRegion]=0;
			nEntriesD5[cPhiRegion]=0;
		}		
		(&hMemory_L1[cPhiRegion])->clear(bx);
		nEntriesL1[cPhiRegion]=0;
	}

	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	ap_uint<3> cLayerOrDiskId;
	ap_uint<1> cIsBarrel;
	ap_uint<kNBits_DTC> hInputStub;
	LOOP_InputStubsPS : for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
	{
		#pragma HLS pipeline II=1
			if (hIputLink.read_nb(hInputStub))
			{
				DecodeMap( hInputStub, hDTCMapEncoded , cLayerOrDiskId, cIsBarrel);
				assert( cIs2S == 0 ); // this should only be for PS modules 
					
				if( cIsBarrel == 1 ) // stub is from a barrel module 
				{
					assert( cLayerOrDiskId >=1 && cLayerOrDiskId <= 3 ); // only three layers in the barrel
					#ifndef __SYNTHESIS__
						//std::cout << "\t.. Routing stub from PS barrel. Tracker layer " << +cLayerOrDiskId << "\n";
					#endif
					
					if( cLayerOrDiskId == 1 ) 
						WriteMemories<InputStub<BARRELPS>,3,kNRegionsLayer1>(bx, hInputStub, nEntriesL1, hMemory_L1);
					else if( cLayerOrDiskId == 2 )
						WriteMemories<InputStub<BARRELPS>,2,kNRegions>(bx, hInputStub, nEntriesL2, hMemory_L2);
					else
						WriteMemories<InputStub<BARRELPS>,2,kNRegions>(bx, hInputStub, nEntriesL3, hMemory_L3);
				}
				else
				{
					assert( cLayerOrDiskId >=1 && cLayerOrDiskId <= 5 ); // only five disks in the endcap
					#ifndef __SYNTHESIS__
						//std::cout << "\t.. Routing stub from PS endcap. Endcap disk " << +cLayerOrDiskId << "\n";
					#endif

					if( cLayerOrDiskId == 1 ) 
						WriteMemories<InputStub<DISKPS>,2,kNRegions>(bx, hInputStub, nEntriesD1, hMemory_D1);
					else if( cLayerOrDiskId == 2 )
						WriteMemories<InputStub<DISKPS>,2,kNRegions>(bx, hInputStub, nEntriesD2, hMemory_D2);
					else if( cLayerOrDiskId == 3 )
						WriteMemories<InputStub<DISKPS>,2,kNRegions>(bx, hInputStub, nEntriesD3, hMemory_D3);
					else if( cLayerOrDiskId == 4 )
						WriteMemories<InputStub<DISKPS>,2,kNRegions>(bx, hInputStub, nEntriesD4, hMemory_D4);
					else if( cLayerOrDiskId == 5 )
						WriteMemories<InputStub<DISKPS>,2,kNRegions>(bx, hInputStub, nEntriesD5, hMemory_D5);
				}
			}
			LOOP_UpdateMemorySizesPS : for( int cPhiRegion=0; cPhiRegion<kNRegionsLayer1; cPhiRegion++)
			{
				if( cPhiRegion < kNRegions )
				{
					nEntriesL2[cPhiRegion]=(&hMemory_L2[cPhiRegion])->getEntries(bx);
					nEntriesL3[cPhiRegion]=(&hMemory_L3[cPhiRegion])->getEntries(bx);
					nEntriesD1[cPhiRegion]=(&hMemory_D1[cPhiRegion])->getEntries(bx);
					nEntriesD2[cPhiRegion]=(&hMemory_D2[cPhiRegion])->getEntries(bx);
					nEntriesD3[cPhiRegion]=(&hMemory_D3[cPhiRegion])->getEntries(bx);
					nEntriesD4[cPhiRegion]=(&hMemory_D4[cPhiRegion])->getEntries(bx);
					nEntriesD5[cPhiRegion]=(&hMemory_D5[cPhiRegion])->getEntries(bx);
				}		
				nEntriesL1[cPhiRegion]=(&hMemory_L1[cPhiRegion])->getEntries(bx);
			}
	}
}


// // route stubs for 2S memories only 
// void InputRouter2S(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
// 				  InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L1[kNRegions], InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L2[kNRegions], 
// 				  InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L3[kNRegions],
// 				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D1[kNRegions], InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D2[kNRegions], 
// 				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D3[kNRegions], InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D4[kNRegions], 
// 				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D5[kNRegions])
// {
// 	#pragma HLS interface ap_none port=hDTCMapEncoded
// 	// clear memories for this bunch crossing 
// 	LOOP_ClearInputStubs2S : for( int cPhiRegion=0; cPhiRegion<kNRegions; cPhiRegion++)
// 	{
// 		(&hMemory_L1[cPhiRegion])->clear(bx);
// 		(&hMemory_L2[cPhiRegion])->clear(bx);
// 		(&hMemory_L3[cPhiRegion])->clear(bx);
// 		(&hMemory_D1[cPhiRegion])->clear(bx);
// 		(&hMemory_D2[cPhiRegion])->clear(bx);
// 		(&hMemory_D3[cPhiRegion])->clear(bx);
// 		(&hMemory_D4[cPhiRegion])->clear(bx);
// 		(&hMemory_D5[cPhiRegion])->clear(bx);
// 	}

// 	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
// 	ap_uint<3> cLayerOrDiskId;
// 	ap_uint<1> cIsBarrel;
// 	ap_uint<kNBits_DTC> hInputStub;
// 	LOOP_InputStubs2S : for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
// 	{
// 		#pragma HLS pipeline II=1
// 		if (hIputLink.read_nb(hInputStub))
// 		//if( cStubCounter < nStubs ) // loop has finite size .. but not going past the end of the array 
// 		{
// 			DecodeMap( hInputStub, hDTCMapEncoded , cLayerOrDiskId, cIsBarrel);
// 			assert( cIs2S == 1 ); // this should only be for 2S modules 
// 			if( cIsBarrel == 1 ) // stub is from a barrel module 
// 			{

// 				assert( cLayerOrDiskId >=4 && cLayerOrDiskId <= 6 ); // only three layers in the barrel
// 				#ifndef __SYNTHESIS__
// 					//std::cout << "\t.. Routing stub from 2S barrel. Tracker layer " << +cLayerOrDiskId << "\n";
// 				#endif

// 				if( cLayerOrDiskId == 3 ) 
// 					WriteMemories<InputStub<BARREL2S>,3,kNRegionsLayer1>(bx, hInputStub, hMemory_L1);
// 				else if( cLayerOrDiskId == 4 )
// 					WriteMemories<InputStub<BARREL2S>,2,kNRegionsLayer1>(bx, hInputStub, hMemory_L2);
// 				else
// 					WriteMemories<InputStub<BARREL2S>,2,kNRegionsLayer1>(bx, hInputStub, hMemory_L3);
// 			}
// 			else
// 			{
// 				assert( cLayerOrDiskId >=1 && cLayerOrDiskId <= 5 ); // only five disks in the endcap
// 				#ifndef __SYNTHESIS__
// 					//std::cout << "\t.. Routing stub from 2S endcap. Endcap disk " << +cLayerOrDiskId << "\n";
// 				#endif

// 				if( cLayerOrDiskId == 1 ) 
// 					WriteMemories<InputStub<DISK2S>,2,kNRegions>(bx, hInputStub, hMemory_D1);
// 				else if( cLayerOrDiskId == 2 )
// 					WriteMemories<InputStub<DISK2S>,2,kNRegions>(bx, hInputStub, hMemory_D2);
// 				else if( cLayerOrDiskId == 3 )
// 					WriteMemories<InputStub<DISK2S>,2,kNRegions>(bx, hInputStub, hMemory_D3);
// 				else if( cLayerOrDiskId == 4 )
// 					WriteMemories<InputStub<DISK2S>,2,kNRegions>(bx, hInputStub, hMemory_D4);
// 				else 
// 					WriteMemories<InputStub<DISK2S>,2,kNRegions>(bx, hInputStub, hMemory_D5);
// 			}
// 		}
// 	}
	
// }


// route stubs to any memory 
void InputRouterGeneric(const BXType bx, const int nStubs, const ap_uint<kNBits_DTC> hIputLink[kMaxStubsFromLink], const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
				  MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemoriesPS[kTotalPSmemories], MemoryTemplate<ap_uint<kBRAMwidth>,kNBits_BX,kNBits_MemAddr> hMemories2S[kTotal2Smemories])
{
	#pragma HLS interface ap_none port=hDTCMapEncoded
	// clear memories for this bunch crossing 
	for( int cMemoryIndex=0; cMemoryIndex<kTotalPSmemories; cMemoryIndex++)
	{
		(&hMemoriesPS[cMemoryIndex])->clear(bx);
		if( cMemoryIndex < kTotal2Smemories )
			(&hMemories2S[cMemoryIndex])->clear(bx);
	}
	
	for (int cStubCounter=0; cStubCounter<nStubs; cStubCounter++)
	{
		#pragma HLS pipeline II=1
			RouteStub(bx, hIputLink[cStubCounter], hDTCMapEncoded, hMemoriesPS, hMemories2S );

	}

}