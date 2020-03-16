#ifndef INPUTROUTER_HH
#define INPUTROUTER_HH

#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"
#include <bitset> 

// //template<int...Ts> void WriteMemories(Ts... hMemory);
// template<typename ...Links, typename ...Memories> void ProcessLink(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, Links..., Memories...) 
// {
// 	#pragma HLS ARRAY_PARTITION variable=in_local complete dim=2
// }


void ProcessLink(const BXType bx, ap_uint<kNBits_DTC>* cStub , int cNstubs);

template<int ISTypeBarrel, int ISTypeDisk>
void InputRouter(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, ap_uint<kNBits_DTC>* hStubs,
				  InputStubMemory<ISTypeBarrel>& hMemory_L1 ,InputStubMemory<ISTypeBarrel> &hMemory_L2, InputStubMemory<ISTypeBarrel> &hMemory_L3,
				  InputStubMemory<ISTypeDisk>& hMemory_D1, InputStubMemory<ISTypeDisk> &hMemory_D2, InputStubMemory<ISTypeDisk> &hMemory_D3 , InputStubMemory<ISTypeDisk> &hMemory_D4, InputStubMemory<ISTypeDisk> &hMemory_D5 )
{
	// input port as a fifo 
	#pragma HLS interface ap_none port=hDTCMapEncoded
	#pragma HLS INTERFACE ap_fifo port=hStubs 
	// memories as BRAMS
	#pragma HLS INTERFACE bram port=hMemory_L1
	#pragma HLS INTERFACE bram port=hMemory_L2
	#pragma HLS INTERFACE bram port=hMemory_L3
	//
	#pragma HLS INTERFACE bram port=hMemory_D1
	#pragma HLS INTERFACE bram port=hMemory_D2
	#pragma HLS INTERFACE bram port=hMemory_D3
	#pragma HLS INTERFACE bram port=hMemory_D4
	#pragma HLS INTERFACE bram port=hMemory_D5

	ap_uint<kNBits_DTC> hInputStub;

	int nStubs_L1=0;
	int nStubs_L2=0;
	int nStubs_L3=0;
	int nStubs_D1=0;
	int nStubs_D2=0;
	int nStubs_D3=0;
	int nStubs_D4=0;
	int nStubs_D5=0;
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
				cLayerEncoding = hDTCMapEncoded.range(4,0);
			else if( cLayerId == 1 )
				cLayerEncoding = hDTCMapEncoded.range(9,5);
			else if( cLayerId == 2 )
				cLayerEncoding = hDTCMapEncoded.range(14,10);
			else 
				cLayerEncoding = hDTCMapEncoded.range(19,15);

			ap_uint<1> cIsBarrel = cLayerEncoding.range(0,0) ; 
			ap_uint<1> cIs2S =  cLayerEncoding.range(1,1) ;
			ap_uint<3> cLayerOrDiskId = cLayerEncoding.range(4,2);
			#ifndef __SYNTHESIS__
			  std::cout << "\t.. layer index " << +cLayerId << " ... which is layer " << +cLayerOrDiskId << " 2S bit is " << +cIs2S << " barrel bit is " << +cIsBarrel << "\n";
			#endif

			// for now assuming one memory per layer .. no phi segmentation here 
			// can do this once I know what the phi segmentation is here ..   
			ap_uint<3> cPhiRegion; 
			if( cIsBarrel == 1  )
			{
				// input stubs per region/type of module 
				InputStub<ISTypeBarrel> hBarrelStub;
				hBarrelStub =  InputStub<ISTypeBarrel>(hInputStub.range(kBRAMwidth-1,0));
				//cPhiRegion = ( hBarrelStub.getPhi().range( hBarrelStub.kISPhiMSB,  hBarrelStub.kISPhiMSB-(4-1) ) );
				ap_uint<hBarrelStub.kISPhiSize> cPhiNibble = hBarrelStub.getPhi();
				cPhiRegion = cPhiNibble.range(hBarrelStub.kISPhiSize-1, hBarrelStub.kISPhiSize-3);
				//.range( (hBarrelStub.kISPhiSize - 1,  hBarrelStub.kISPhiSize-1-3+1 ) );  
				#ifndef __SYNTHESIS__
					std::cout << "\t.. layer " << +cLayerOrDiskId << " ... phi nibble is " << +cPhiNibble << " phi region is " << std::bitset<3>(cPhiRegion) << "\n";
				#endif

				if( cLayerOrDiskId == 1 || cLayerOrDiskId == 4 ) 
				{	
					//auto const nEntries = hMemory_L1.getEntries(bx);
					hMemory_L1.write_mem(bx, hBarrelStub, nStubs_L1 );
					nStubs_L1++;
				}
				else if( cLayerOrDiskId == 2 || cLayerOrDiskId == 5 ) 
				{
					//auto const nEntries = hMemory_L2.getEntries(bx);
					hMemory_L2.write_mem(bx, hBarrelStub, nStubs_L2 );
					nStubs_L2++;
				}
				else if( cLayerOrDiskId == 3 || cLayerOrDiskId == 6 )
				{ 
					//auto const nEntries = hMemory_L3.getEntries(bx);
					hMemory_L3.write_mem(bx, hBarrelStub, nStubs_L3 );
					nStubs_L3++;
				}
				#ifndef __SYNTHESIS__
					//cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
				#endif
			}
			else if( cIsBarrel == 0  )
			{
				InputStub<ISTypeDisk> hDiskStub;
				hDiskStub =  InputStub<ISTypeDisk>(hInputStub.range(kBRAMwidth-1,0)); 
				ap_uint<hDiskStub.kISPhiSize> cPhiNibble = hDiskStub.getPhi();
				cPhiRegion = cPhiNibble.range(hDiskStub.kISPhiSize-1, hDiskStub.kISPhiSize-3);
				
				#ifndef __SYNTHESIS__
					std::cout << "\t.. disk " << +cLayerOrDiskId << " ... phi nibble is " << +cPhiNibble << " phi region is " << std::bitset<3>(cPhiRegion) << "\n";
				#endif

				if( cLayerOrDiskId == 1 ) 
				{
					hMemory_D1.write_mem(bx, hDiskStub, nStubs_D1 );
					nStubs_D1++;
				}
				else if( cLayerOrDiskId == 2 ) 
				{
					//auto const nEntries = hMemory_D2.getEntries(bx);
					hMemory_D2.write_mem(bx, hDiskStub,  nStubs_D2 );
					nStubs_D2++;
				}
				else if( cLayerOrDiskId == 3 )
				{
					//auto const nEntries = hMemory_D3.getEntries(bx);
					hMemory_D3.write_mem(bx, hDiskStub,  nStubs_D3 );
					nStubs_D3++;
				}
				else if( cLayerOrDiskId == 4 )
				{
					//auto const nEntries = hMemory_D4.getEntries(bx);
					hMemory_D4.write_mem(bx, hDiskStub,  nStubs_D4 );
					nStubs_D4++;
				}
				else if( cLayerOrDiskId == 5 )
				{
					//auto const nEntries = hMemory_D5.getEntries(bx);
					hMemory_D5.write_mem(bx, hDiskStub,  nStubs_D5 );
					nStubs_D5++;
				}
			}
	}
}// input router 

// template<int ISTypeBarrel, int ISTypeDisk>
// void InputRouter(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
// 				  InputStubMemory<ISTypeBarrel>& hMemory_L1 ,InputStubMemory<ISTypeBarrel> &hMemory_L2, InputStubMemory<ISTypeBarrel> &hMemory_L3,
// 				  InputStubMemory<ISTypeDisk>& hMemory_D1, InputStubMemory<ISTypeDisk> &hMemory_D2, InputStubMemory<ISTypeDisk> &hMemory_D3 , InputStubMemory<ISTypeDisk> &hMemory_D4, InputStubMemory<ISTypeDisk> &hMemory_D5 )
// {

//   #pragma HLS stream variable=hIputLink depth=kMaxStubsFromLink
//   //#pragma HLS stream variable=hIputLink depth=kMaxStubsFromLink
//   ap_uint<kNBits_DTC> hInputStub;
  
//   int nStubs_L1=0;
//   int nStubs_L2=0;
//   int nStubs_L3=0;
//   int nStubs_D1=0;
//   int nStubs_D2=0;
//   int nStubs_D3=0;
//   int nStubs_D4=0;
//   int nStubs_D5=0;
//   // clear barrel memories for this bunch crossing 
//   hMemory_L1.clear(bx);
//   hMemory_L2.clear(bx);
//   hMemory_L3.clear(bx);
//   // clear end-cap memories for this bunch crossing 
//   hMemory_D1.clear(bx);
//   hMemory_D2.clear(bx);
//   hMemory_D3.clear(bx);
//   hMemory_D4.clear(bx);
//   hMemory_D5.clear(bx);

				
//   for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
//   {
//   	//#pragma HLS pipeline II=1
//   	//the non-blocking version of the read 
//   	if (hIputLink.read_nb(hInputStub)) // if data is available the function will update the reference in the argument with the values and return “true” 
// 	{
// 		//std::cout << " \t\t\t... Stub " << std::hex << hInputStub << std::dec << "\n";
// 		ap_uint<kNBits_Debug> cDebugWord = hInputStub.range(kNBits_DTC-1,kNBits_DTC-kNBits_Debug);
// 		ap_uint<kNBits_LayerId> cLayerId  = cDebugWord.range(kNBits_Debug-kNBits_Valid-1,kNBits_Debug-kNBits_Valid-kNBits_LayerId);

// 		// encoded layer id 
// 		ap_uint<5> cLayerEncoding; 
// 		if( cLayerId == 0 )
// 			cLayerEncoding = hDTCMapEncoded.range(4,0);
// 		else if( cLayerId == 1 )
// 			cLayerEncoding = hDTCMapEncoded.range(9,5);
// 		else if( cLayerId == 2 )
// 			cLayerEncoding = hDTCMapEncoded.range(14,10);
// 		else 
// 			cLayerEncoding = hDTCMapEncoded.range(19,15);

// 		ap_uint<1> cIsBarrel = cLayerEncoding.range(0,0) ; 
// 		ap_uint<1> cIs2S =  cLayerEncoding.range(1,1) ;
// 		ap_uint<3> cLayerOrDiskId = cLayerEncoding.range(4,2);
// 		#ifndef __SYNTHESIS__
// 		  std::cout << "\t.. layer index " << +cLayerId << " ... which is layer " << +cLayerOrDiskId << " 2S bit is " << +cIs2S << " barrel bit is " << +cIsBarrel << "\n";
// 	    #endif
		
// 		// for now assuming one memory per layer .. no phi segmentation here 
// 		// can do this once I know what the phi segmentation is here ..   
// 		ap_uint<3> cPhiRegion; 
// 		if( cIsBarrel == 1  )
// 		{
// 			// input stubs per region/type of module 
// 			InputStub<ISTypeBarrel> hBarrelStub;
// 			hBarrelStub =  InputStub<ISTypeBarrel>(hInputStub.range(kBRAMwidth-1,0));
// 			//cPhiRegion = ( hBarrelStub.getPhi().range( hBarrelStub.kISPhiMSB,  hBarrelStub.kISPhiMSB-(4-1) ) );
// 			ap_uint<hBarrelStub.kISPhiSize> cPhiNibble = hBarrelStub.getPhi();
// 			cPhiRegion = cPhiNibble.range(hBarrelStub.kISPhiSize-1, hBarrelStub.kISPhiSize-3);
// 			//.range( (hBarrelStub.kISPhiSize - 1,  hBarrelStub.kISPhiSize-1-3+1 ) );  
// 			#ifndef __SYNTHESIS__
// 				std::cout << "\t.. layer " << +cLayerOrDiskId << " ... phi nibble is " << +cPhiNibble << " phi region is " << std::bitset<3>(cPhiRegion) << "\n";
// 			#endif

// 			if( cLayerOrDiskId == 1 || cLayerOrDiskId == 4 ) 
// 			{	
// 				//auto const nEntries = hMemory_L1.getEntries(bx);
// 				hMemory_L1.write_mem(bx, hBarrelStub, nStubs_L1 );
// 				nStubs_L1++;
// 			}
// 			else if( cLayerOrDiskId == 2 || cLayerOrDiskId == 5 ) 
// 			{
// 				//auto const nEntries = hMemory_L2.getEntries(bx);
// 				hMemory_L2.write_mem(bx, hBarrelStub, nStubs_L2 );
// 				nStubs_L2++;
// 			}
// 			else if( cLayerOrDiskId == 3 || cLayerOrDiskId == 6 )
// 			{ 
// 				//auto const nEntries = hMemory_L3.getEntries(bx);
// 				hMemory_L3.write_mem(bx, hBarrelStub, nStubs_L3 );
// 				nStubs_L3++;
// 			}
// 			#ifndef __SYNTHESIS__
// 				//cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
// 			#endif
// 		}
// 		else if( cIsBarrel == 0  )
// 		{
// 			InputStub<ISTypeDisk> hDiskStub;
// 			hDiskStub =  InputStub<ISTypeDisk>(hInputStub.range(kBRAMwidth-1,0)); 
// 			ap_uint<hDiskStub.kISPhiSize> cPhiNibble = hDiskStub.getPhi();
// 			cPhiRegion = cPhiNibble.range(hDiskStub.kISPhiSize-1, hDiskStub.kISPhiSize-3);
			
// 			#ifndef __SYNTHESIS__
// 				std::cout << "\t.. disk " << +cLayerOrDiskId << " ... phi nibble is " << +cPhiNibble << " phi region is " << std::bitset<3>(cPhiRegion) << "\n";
// 			#endif

// 			if( cLayerOrDiskId == 1 ) 
// 			{
// 				hMemory_D1.write_mem(bx, hDiskStub, nStubs_D1 );
// 				nStubs_D1++;
// 			}
// 			else if( cLayerOrDiskId == 2 ) 
// 			{
// 				//auto const nEntries = hMemory_D2.getEntries(bx);
// 				hMemory_D2.write_mem(bx, hDiskStub,  nStubs_D2 );
// 				nStubs_D2++;
// 			}
// 			else if( cLayerOrDiskId == 3 )
// 			{
// 				//auto const nEntries = hMemory_D3.getEntries(bx);
// 				hMemory_D3.write_mem(bx, hDiskStub,  nStubs_D3 );
// 				nStubs_D3++;
// 			}
// 			else if( cLayerOrDiskId == 4 )
// 			{
// 				//auto const nEntries = hMemory_D4.getEntries(bx);
// 				hMemory_D4.write_mem(bx, hDiskStub,  nStubs_D4 );
// 				nStubs_D4++;
// 			}
// 			else if( cLayerOrDiskId == 5 )
// 			{
// 				//auto const nEntries = hMemory_D5.getEntries(bx);
// 				hMemory_D5.write_mem(bx, hDiskStub,  nStubs_D5 );
// 				nStubs_D5++;
// 			}
// 		}
// 	 }
//   }
// }// input router 

#endif
