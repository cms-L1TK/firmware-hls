#include "InputRouterTop.h"
#include "InputRouter.cc"

// 	#pragma HLS unroll factor=4 // clear two phi regions at a time ..
// #pragma HLS ARRAY_PARTITION variable=nEntriesL1 complete dim=1
				

// route stubs for PS memories only 
void InputRouterPS(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	StubsBarrelPS hBrl, StubsDiskPS hDsk)
{
	// local variables to keep track of how many entries 
	// are in each memory 
	EntriesBarrelPS cBrl;
	EntriesDiskPS cDsk;
	#pragma HLS interface ap_none port=hDTCMapEncoded
	#pragma HLS interface ap_fifo port=hIputLink

	// needed this to allow pipeline of 1 
	#pragma HLS ARRAY_PARTITION variable=cBrl.n1 cyclic factor=4 dim=1
	#pragma HLS ARRAY_PARTITION variable=cBrl.n2 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cBrl.n3 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n1 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n2 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n3 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n4 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n5 cyclic factor=2 dim=1

	// clear memories for this bunch crossing 
	// one memory for each coarse phi bin 
	LOOP_ClearInputStubsPS : 
	for( int cPhiBn=0; cPhiBn<kNRegionsLayer1; cPhiBn++)
	{
		#pragma HLS pipeline II=1
		#pragma HLS unroll factor=4 // clear four phi regions at a time ..
		if( cPhiBn < kNRegions )
		{
			(&hBrl.m2[cPhiBn])->clear(bx);
			(&hBrl.m3[cPhiBn])->clear(bx);
			(&hDsk.m1[cPhiBn])->clear(bx);
			(&hDsk.m2[cPhiBn])->clear(bx);
			(&hDsk.m3[cPhiBn])->clear(bx);
			(&hDsk.m4[cPhiBn])->clear(bx);
			(&hDsk.m5[cPhiBn])->clear(bx);
		}		
		(&hBrl.m1[cPhiBn])->clear(bx);
	}

	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	ap_uint<3> cLyrOrDskId;
	ap_uint<1> cIsBrl;
	ap_uint<kNBits_DTC> hWord;
	LOOP_InputStubsPS : 
	for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
	{
		#pragma HLS pipeline II=1
		if (hIputLink.read_nb(hWord))
		{
			DecodeMap( hWord, hDTCMapEncoded , cLyrOrDskId, cIsBrl);
			assert( cIs2S == 0 ); // this should only be for PS modules 
		
			if( cIsBrl == 1 ) // stub is from a barrel module 
			{
				// only three layers in the barrel
				assert( cLyrOrDskId >=1 && cLyrOrDskId <= 3 ); 
				InputStub<BARRELPS> hStub(hWord.range(kBRAMwidth-1,0));

				if( cLyrOrDskId == 1 ) 
				{
					ap_uint<3> cPhiBn;
					GetCoarsePhiRegion<InputStub<BARRELPS>,3>(hWord, cPhiBn);
					(&hBrl.m1[cPhiBn])->write_mem(bx, hStub, cBrl.n1[cPhiBn]);
					cBrl.n1[cPhiBn]++;
				}
				else
				{
					ap_uint<2> cPhiBn;
					GetCoarsePhiRegion<InputStub<BARRELPS>,2>(hWord, cPhiBn);
					if( cLyrOrDskId == 2 ) 
					{
						(&hBrl.m2[cPhiBn])->write_mem(bx,hStub,cBrl.n2[cPhiBn]);
						cBrl.n2[cPhiBn]++;
					}
					else if( cLyrOrDskId == 3 )
					{
						(&hBrl.m3[cPhiBn])->write_mem(bx,hStub,cBrl.n3[cPhiBn]);
						cBrl.n3[cPhiBn]++;
					}
				}
			}
			else
			{
				// only 5 disks in the endcap
				assert( cLyrOrDskId >=1 && cLyrOrDskId <= 5 ); 
				InputStub<DISKPS> hStub(hWord.range(kBRAMwidth-1,0));
				ap_uint<2> cPhiBn;
				GetCoarsePhiRegion<InputStub<DISKPS>,2>(hWord, cPhiBn);
				
				if( cLyrOrDskId == 1 ) 
				{
					(&hDsk.m1[cPhiBn])->write_mem(bx, hStub, cDsk.n1[cPhiBn]);
					cDsk.n1[cPhiBn]++;
				}
				else if( cLyrOrDskId == 2 ) 
				{
					(&hDsk.m2[cPhiBn])->write_mem(bx, hStub, cDsk.n2[cPhiBn]);
					cDsk.n2[cPhiBn]++;
				}
				else if( cLyrOrDskId == 3 ) 
				{
					(&hDsk.m3[cPhiBn])->write_mem(bx, hStub, cDsk.n3[cPhiBn]);
					cDsk.n3[cPhiBn]++;
				}
				else if( cLyrOrDskId == 4 ) 
				{
					(&hDsk.m4[cPhiBn])->write_mem(bx, hStub, cDsk.n4[cPhiBn]);
					cDsk.n4[cPhiBn]++;
				}
				else 
				{
					(&hDsk.m5[cPhiBn])->write_mem(bx, hStub, cDsk.n5[cPhiBn]);
					cDsk.n5[cPhiBn]++;
				}
			}
		}
	}
}



//route stubs for 2S memories only 
void InputRouter2S(const BXType bx, hls::stream<ap_uint<kNBits_DTC>> &hIputLink, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	StubsBarrel2S hBrl, StubsDisk2S hDsk)
{
	// local variables to keep track of how many entries 
	// are in each memory 
	EntriesBarrel2S cBrl;
	EntriesDisk2S cDsk;
	#pragma HLS interface ap_none port=hDTCMapEncoded
	#pragma HLS interface ap_fifo port=hIputLink

	// needed this to allow pipeline of 1 
	#pragma HLS ARRAY_PARTITION variable=cBrl.n1 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cBrl.n2 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cBrl.n3 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n1 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n2 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n3 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n4 cyclic factor=2 dim=1
	#pragma HLS ARRAY_PARTITION variable=cDsk.n5 cyclic factor=2 dim=1

	// clear memories for this bunch crossing 
	// one memory for each coarse phi bin 
	LOOP_ClearInputStubsPS : 
	for( int cPhiBn=0; cPhiBn<kNRegions; cPhiBn++)
	{
		#pragma HLS pipeline II=1
		#pragma HLS unroll factor=4 // clear four phi regions at a time ..
			(&hBrl.m1[cPhiBn])->clear(bx);
			(&hBrl.m2[cPhiBn])->clear(bx);
			(&hBrl.m3[cPhiBn])->clear(bx);
			(&hDsk.m1[cPhiBn])->clear(bx);
			(&hDsk.m2[cPhiBn])->clear(bx);
			(&hDsk.m3[cPhiBn])->clear(bx);
			(&hDsk.m4[cPhiBn])->clear(bx);
			(&hDsk.m5[cPhiBn])->clear(bx);
	}

	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	ap_uint<3> cLyrOrDskId;
	ap_uint<1> cIsBrl;
	ap_uint<kNBits_DTC> hWord;
	LOOP_InputStubs2S : 
	for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
	{
		#pragma HLS pipeline II=1
		if (hIputLink.read_nb(hWord))
		{
			DecodeMap( hWord, hDTCMapEncoded , cLyrOrDskId, cIsBrl);
			assert( cIs2S == 1 ); // this should only be for 2S modules 
			ap_uint<2> cPhiBn;
			if( cIsBrl == 1 ) // stub is from a barrel module 
			{
				// three layers [4--6]
				assert( cLyrOrDskId >=4 && cLyrOrDskId <= 6 ); 
				InputStub<BARREL2S> hStub(hWord.range(kBRAMwidth-1,0));
				GetCoarsePhiRegion<InputStub<BARRELPS>,2>(hWord, cPhiBn);
					
				if( cLyrOrDskId == 4 ) 
				{
					(&hBrl.m1[cPhiBn])->write_mem(bx, hStub, cBrl.n1[cPhiBn]);
					cBrl.n1[cPhiBn]++;
				}
				else if( cLyrOrDskId == 5 ) 
				{
					(&hBrl.m2[cPhiBn])->write_mem(bx, hStub, cBrl.n2[cPhiBn]);
					cBrl.n2[cPhiBn]++;
				}
				else 
				{
					(&hBrl.m3[cPhiBn])->write_mem(bx, hStub, cBrl.n3[cPhiBn]);
					cBrl.n3[cPhiBn]++;
				}
			}
			else
			{
				// five disks [1--5] in the endcap 
				assert( cLyrOrDskId >=1 && cLyrOrDskId <= 5 ); 
				InputStub<DISK2S> hStub(hWord.range(kBRAMwidth-1,0));
				GetCoarsePhiRegion<InputStub<BARRELPS>,2>(hWord, cPhiBn);
				
				if( cLyrOrDskId == 1 ) 
				{
					(&hDsk.m1[cPhiBn])->write_mem(bx, hStub, cDsk.n1[cPhiBn]);
					cDsk.n1[cPhiBn]++;
				}
				else if( cLyrOrDskId == 2 ) 
				{
					(&hDsk.m2[cPhiBn])->write_mem(bx, hStub, cDsk.n2[cPhiBn]);
					cDsk.n2[cPhiBn]++;
				}
				else if( cLyrOrDskId == 3 ) 
				{
					(&hDsk.m3[cPhiBn])->write_mem(bx, hStub, cDsk.n3[cPhiBn]);
					cDsk.n3[cPhiBn]++;
				}
				else if( cLyrOrDskId == 4 ) 
				{
					(&hDsk.m4[cPhiBn])->write_mem(bx, hStub, cDsk.n4[cPhiBn]);
					cDsk.n4[cPhiBn]++;
				}
				else 
				{
					(&hDsk.m5[cPhiBn])->write_mem(bx, hStub, cDsk.n5[cPhiBn]);
					cDsk.n5[cPhiBn]++;
				}
			}
		}
	}
	
}

// route stubs to any memory 
void InputRouterTop(const BXType bx, 
	hls::stream<ap_uint<kNBits_DTC>> &hIputLink, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	StubsBarrelPS hBrlPS, StubsDiskPS hDskPS, 
	StubsBarrel2S hBrl2S, StubsDisk2S hDsk2S)
{
	ap_uint<1> cIs2S; is2S(hDTCMapEncoded, cIs2S);
	if( cIs2S == 1 )
		InputRouter2S(bx, hIputLink, hDTCMapEncoded, hBrl2S, hDsk2S);
	else
		InputRouterPS(bx, hIputLink, hDTCMapEncoded, hBrlPS, hDskPS);
}


// route stubs to any memory
void InputRouterGeneric(const BXType bx, const int nStubs, 
	hls::stream<ap_uint<kNBits_DTC>> &hIputLink, 
	const ap_uint<kLINKMAPwidth> hDTCMapEncoded, 
	IRMemory hM_PS[kTotalPSmemories], 
	IRMemory hM_2S[kTotal2Smemories])
{
	#pragma HLS interface ap_none port=hDTCMapEncoded
	// clear memories for this bunch crossing 
	for( int cMemoryIndex=0; cMemoryIndex<kTotalPSmemories; cMemoryIndex++)
	{
		(&hM_PS[cMemoryIndex])->clear(bx);
		if( cMemoryIndex < kTotal2Smemories )
			(&hM_2S[cMemoryIndex])->clear(bx);
	}
	
	ap_uint<kNBits_DTC> hWord;
	
	for (int cStubCounter=0; cStubCounter<nStubs; cStubCounter++)
	{
		#pragma HLS pipeline II=1
		if (hIputLink.read_nb(hWord))
			RouteStub(bx, hWord, hDTCMapEncoded, hM_PS, hM_2S);
	}
}