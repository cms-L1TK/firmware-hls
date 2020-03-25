#include "InputRouterTop.h"
#include "InputRouter.cc"

// 	#pragma HLS unroll factor=4 // clear two phi regions at a time ..
// #pragma HLS ARRAY_PARTITION variable=nEntriesL1 complete dim=1
				

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

	#pragma HLS ARRAY_PARTITION variable=nEntriesL1 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesL2 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesL3 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD1 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD2 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD3 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD4 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD5 cyclic factor=4 dim=1

	LOOP_ClearInputStubsPS : for( int cPhiRegion=0; cPhiRegion<kNRegionsLayer1; cPhiRegion++)
	{
		#pragma HLS pipeline II=1
		#pragma HLS unroll factor=4 // clear four phi regions at a time ..
			if( cPhiRegion < kNRegions )
			{
				(&hMemory_L2[cPhiRegion])->clear(bx);
				(&hMemory_L3[cPhiRegion])->clear(bx);
				(&hMemory_D1[cPhiRegion])->clear(bx);
				(&hMemory_D2[cPhiRegion])->clear(bx);
				(&hMemory_D3[cPhiRegion])->clear(bx);
				(&hMemory_D4[cPhiRegion])->clear(bx);
				(&hMemory_D5[cPhiRegion])->clear(bx);
			}		
			(&hMemory_L1[cPhiRegion])->clear(bx);
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
					InputStub<BARRELPS> hStub(hInputStub.range(kBRAMwidth-1,0));
	
					if( cLayerOrDiskId == 1 ) 
					{
						ap_uint<3> cPhiRegion;
						GetCoarsePhiRegion<InputStub<BARRELPS>,3>(hInputStub, cPhiRegion );
						(&hMemory_L1[cPhiRegion])->write_mem(bx, hStub, nEntriesL1[cPhiRegion] );
						nEntriesL1[cPhiRegion]++;
					}
					else
					{
						ap_uint<2> cPhiRegion;
						GetCoarsePhiRegion<InputStub<BARRELPS>,2>(hInputStub, cPhiRegion );
						if( cLayerOrDiskId == 2 ) 
						{
							(&hMemory_L2[cPhiRegion])->write_mem(bx, hStub, nEntriesL2[cPhiRegion] );
							nEntriesL2[cPhiRegion]++;
						}
						else if( cLayerOrDiskId == 3 )
						{
							(&hMemory_L3[cPhiRegion])->write_mem(bx, hStub, nEntriesL2[cPhiRegion] );
							nEntriesL3[cPhiRegion]++;
						}
					}
				}
				else
				{
					assert( cLayerOrDiskId >=1 && cLayerOrDiskId <= 5 ); // only three layers in the barrel
					InputStub<DISKPS> hStub(hInputStub.range(kBRAMwidth-1,0));
					ap_uint<2> cPhiRegion;
					GetCoarsePhiRegion<InputStub<DISKPS>,2>(hInputStub, cPhiRegion );
					
					if( cLayerOrDiskId == 1 ) 
					{
						(&hMemory_D1[cPhiRegion])->write_mem(bx, hStub, nEntriesD1[cPhiRegion] );
						nEntriesD1[cPhiRegion]++;
					}
					else if( cLayerOrDiskId == 2 ) 
					{
						(&hMemory_D2[cPhiRegion])->write_mem(bx, hStub, nEntriesD2[cPhiRegion] );
						nEntriesD2[cPhiRegion]++;
					}
					else if( cLayerOrDiskId == 3 ) 
					{
						(&hMemory_D3[cPhiRegion])->write_mem(bx, hStub, nEntriesD3[cPhiRegion] );
						nEntriesD3[cPhiRegion]++;
					}
					else if( cLayerOrDiskId == 4 ) 
					{
						(&hMemory_D4[cPhiRegion])->write_mem(bx, hStub, nEntriesD4[cPhiRegion] );
						nEntriesD4[cPhiRegion]++;
					}
					else 
					{
						(&hMemory_D5[cPhiRegion])->write_mem(bx, hStub, nEntriesD5[cPhiRegion] );
						nEntriesD5[cPhiRegion]++;
					}
				}
			}
	}
}



// route stubs for 2S memories only 
void InputRouter2S(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
				  InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L1[kNRegions], InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L2[kNRegions], 
				  InputRouterMemory<InputStub<BARREL2S>,kNBits_BX,kNBits_MemAddr> hMemory_L3[kNRegions],
				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D1[kNRegions], InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D2[kNRegions], 
				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D3[kNRegions], InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D4[kNRegions], 
				  InputRouterMemory<InputStub<DISK2S>,kNBits_BX,kNBits_MemAddr> hMemory_D5[kNRegions])
{
	#pragma HLS interface ap_none port=hDTCMapEncoded
	#pragma HLS interface ap_fifo port=hIputLink

	// clear memories for this bunch crossing 
	ap_uint<8> nEntriesL1[kNRegions]; 
	ap_uint<8> nEntriesL2[kNRegions]; 
	ap_uint<8> nEntriesL3[kNRegions];
	ap_uint<8> nEntriesD1[kNRegions]; 
	ap_uint<8> nEntriesD2[kNRegions];
	ap_uint<8> nEntriesD3[kNRegions]; 
	ap_uint<8> nEntriesD4[kNRegions];
	ap_uint<8> nEntriesD5[kNRegions];

	#pragma HLS ARRAY_PARTITION variable=nEntriesL1 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesL2 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesL3 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD1 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD2 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD3 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD4 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=nEntriesD5 cyclic factor=4 dim=1

	LOOP_ClearInputStubs2S : for( int cPhiRegion=0; cPhiRegion<kNRegions; cPhiRegion++)
	{
		#pragma HLS pipeline II=1
		#pragma HLS unroll factor=4 // clear four phi regions at a time ..
			(&hMemory_L1[cPhiRegion])->clear(bx);
			(&hMemory_L2[cPhiRegion])->clear(bx);
			(&hMemory_L3[cPhiRegion])->clear(bx);
			(&hMemory_D1[cPhiRegion])->clear(bx);
			(&hMemory_D2[cPhiRegion])->clear(bx);
			(&hMemory_D3[cPhiRegion])->clear(bx);
			(&hMemory_D4[cPhiRegion])->clear(bx);
			(&hMemory_D5[cPhiRegion])->clear(bx);
	}
	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	ap_uint<3> cLayerOrDiskId;
	ap_uint<1> cIsBarrel;
	ap_uint<kNBits_DTC> hInputStub;
	LOOP_InputStubs2S : for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
	{
		#pragma HLS pipeline II=1
		if (hIputLink.read_nb(hInputStub))
		{
			DecodeMap( hInputStub, hDTCMapEncoded , cLayerOrDiskId, cIsBarrel);
			assert( cIs2S == 1 ); // this should only be for 2S modules 

			if( cIsBarrel == 1 ) // stub is from a barrel module 
			{
				assert( cLayerOrDiskId >=1 && cLayerOrDiskId <= 3 ); // only three layers in the barrel
				InputStub<BARREL2S> hStub(hInputStub.range(kBRAMwidth-1,0));
				ap_uint<2> cPhiRegion;
				GetCoarsePhiRegion<InputStub<BARREL2S>,2>(hInputStub, cPhiRegion );
					
				if( cLayerOrDiskId == 1 ) 
				{
					(&hMemory_L1[cPhiRegion])->write_mem(bx, hStub, nEntriesL1[cPhiRegion] );
					nEntriesL1[cPhiRegion]++;
				}
				else if( cLayerOrDiskId == 2 ) 
				{
					(&hMemory_L2[cPhiRegion])->write_mem(bx, hStub, nEntriesL2[cPhiRegion] );
					nEntriesL2[cPhiRegion]++;
				}
				else 
				{
					(&hMemory_L[cPhiRegion])->write_mem(bx, hStub, nEntriesL3[cPhiRegion] );
					nEntriesL3[cPhiRegion]++;
				}
			}
			else
			{
				assert( cLayerOrDiskId >=1 && cLayerOrDiskId <= 5 ); // only three layers in the barrel
				InputStub<DISK2S> hStub(hInputStub.range(kBRAMwidth-1,0));
				ap_uint<2> cPhiRegion;
				GetCoarsePhiRegion<InputStub<DISK2S>,2>(hInputStub, cPhiRegion );
				
				if( cLayerOrDiskId == 1 ) 
				{
					(&hMemory_D1[cPhiRegion])->write_mem(bx, hStub, nEntriesD1[cPhiRegion] );
					nEntriesD1[cPhiRegion]++;
				}
				else if( cLayerOrDiskId == 2 ) 
				{
					(&hMemory_D2[cPhiRegion])->write_mem(bx, hStub, nEntriesD2[cPhiRegion] );
					nEntriesD2[cPhiRegion]++;
				}
				else if( cLayerOrDiskId == 3 ) 
				{
					(&hMemory_D3[cPhiRegion])->write_mem(bx, hStub, nEntriesD3[cPhiRegion] );
					nEntriesD3[cPhiRegion]++;
				}
				else if( cLayerOrDiskId == 4 ) 
				{
					(&hMemory_D4[cPhiRegion])->write_mem(bx, hStub, nEntriesD4[cPhiRegion] );
					nEntriesD4[cPhiRegion]++;
				}
				else 
				{
					(&hMemory_D5[cPhiRegion])->write_mem(bx, hStub, nEntriesD5[cPhiRegion] );
					nEntriesD5[cPhiRegion]++;
				}
			}
		}
	}
	
}


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