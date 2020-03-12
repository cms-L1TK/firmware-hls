#include "InputRouter.hh"
#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"

// implementation of input router 
//#include "InputRouter.tpp"

void LayerEncoding(ap_uint<kNBits_LayerId> cLayerId, ap_uint<kLINKMAPwidth>  encodedMap, ap_uint<5>& cEncoding)
{
	if( cLayerId == 0 )
		cEncoding = encodedMap.range(4,0);
	else if( cLayerId == 1 )
		cEncoding = encodedMap.range(9,5);
	else if( cLayerId == 2 )
		cEncoding = encodedMap.range(14,10);
	else 
		cEncoding = encodedMap.range(19,15);
}

template<int ISTypeBarrel, int ISTypeDisk>
void RouteStub(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<ISTypeBarrel>& hMemory_L1 ,InputStubMemory<ISTypeBarrel> &hMemory_L2, InputStubMemory<ISTypeBarrel> &hMemory_L3,
				  InputStubMemory<ISTypeDisk>& hMemory_D1, InputStubMemory<ISTypeDisk> &hMemory_D2, InputStubMemory<ISTypeDisk> &hMemory_D3 , InputStubMemory<ISTypeDisk> &hMemory_D4, InputStubMemory<ISTypeDisk> &hMemory_D5 )
{
  ap_uint<kNBits_DTC> hInputStub;
  
  // input stubs per region/type of module 
  InputStub<ISTypeBarrel> cBarrelStub;
  InputStub<ISTypeDisk> cDiskStub;
  
  #pragma HLS pipeline II=1
  //the non-blocking version of the read 
  if (hIputLink.read_nb(hInputStub)) // if data is available the function will update the reference in the argument with the values and return “true” 
  {
	//std::cout << " \t\t\t... Stub " << std::hex << hInputStub << std::dec << "\n";
	ap_uint<kNBits_Debug> cDebugWord = hInputStub.range(kNBits_DTC-1,kNBits_DTC-kNBits_Debug);
	ap_uint<kNBits_LayerId> cLayerId  = cDebugWord.range(kNBits_Debug-kNBits_Valid-1,kNBits_Debug-kNBits_Valid-kNBits_LayerId);

	ap_uint<5> cLayerEncoding; LayerEncoding(cLayerId, hDTCMapEncoded, cLayerEncoding);
	ap_uint<1> cIsBarrel = cLayerEncoding.range(0,0) ; 
	ap_uint<1> cIs2S =  cLayerEncoding.range(1,1) ;
	ap_uint<3> cLayerOrDiskId = cLayerEncoding.range(4,2);
	#ifndef __SYNTHESIS__
	  std::cout << "\t.. layer index " << +cLayerId << " ... which is layer " << +cLayerOrDiskId << " 2S bit is " << +cIs2S << " barrel bit is " << +cIsBarrel << "\n";
    #endif
	
	// for now assuming one memory per layer .. no phi segmentation here 
	// can do this once I know what the phi segmentation is here ..   
	ap_uint<4> cPhiRegion; 
	if( cIsBarrel == 1  )
	{
		cBarrelStub =  InputStub<ISTypeBarrel>(hInputStub.range(kBRAMwidth-1,0));
		
		if( cLayerOrDiskId == 1 || cLayerOrDiskId == 4 ) 
			hMemory_L1.write_mem(bx, cBarrelStub, hMemory_L1.getEntries(bx) );
		else if( cLayerOrDiskId == 2 || cLayerOrDiskId == 5 ) 
			hMemory_L2.write_mem(bx, cBarrelStub, hMemory_L2.getEntries(bx) );
		else if( cLayerOrDiskId == 3 || cLayerOrDiskId == 6 ) 
			hMemory_L3.write_mem(bx, cBarrelStub, hMemory_L3.getEntries(bx) );

		#ifndef __SYNTHESIS__
			//cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
		#endif
	}
	else if( cIsBarrel == 0  )
	{
		cDiskStub =  InputStub<ISTypeDisk>(hInputStub.range(kBRAMwidth-1,0)); 
		#ifndef __SYNTHESIS__
			//cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
		#endif

		if( cLayerOrDiskId == 1 ) 
			hMemory_D1.write_mem(bx, cDiskStub,  hMemory_D1.getEntries(bx) );
		else if( cLayerOrDiskId == 2 ) 
			hMemory_D2.write_mem(bx, cDiskStub,  hMemory_D2.getEntries(bx) );
		else if( cLayerOrDiskId == 3 )
			hMemory_D3.write_mem(bx, cDiskStub,  hMemory_D3.getEntries(bx) );
		else if( cLayerOrDiskId == 4 )
			hMemory_D4.write_mem(bx, cDiskStub,  hMemory_D4.getEntries(bx) );
		else if( cLayerOrDiskId == 5 )
			hMemory_D5.write_mem(bx, cDiskStub,  hMemory_D5.getEntries(bx) );

		#ifndef __SYNTHESIS__
			std::cout << ".... " << +hMemory_D1.getEntries(bx) << " in D1\n";
			std::cout << ".... " << +hMemory_D2.getEntries(bx) << " in D2\n";
			std::cout << ".... " << +hMemory_D3.getEntries(bx) << " in D3\n";
			std::cout << ".... " << +hMemory_D4.getEntries(bx) << " in D4\n";
			std::cout << ".... " << +hMemory_D5.getEntries(bx) << " in D5\n";
		#endif
	}
	else 
	{
	  #ifndef __SYNTHESIS__
	    std::cout << "Something has gone wrong.. stub is from an invalid layer/disk/region\n";
	  #endif
	}
  }
}// input router 

void WriteMap(int address, ap_uint<kLINKMAPwidth>  encodedMap , DTCMapMemory *Map )
{
  Map->write_mem(1, encodedMap, address);
} // link map function 

void ReadMap(int address, DTCMapMemory Map, DTCMap&  encodedMap)
{
  encodedMap = Map.read_mem(1, address);
} // read map function 

// barrel 2S input router 
void InputRouter(const LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<BARRELPS>& hMemory_L1 ,InputStubMemory<BARRELPS>& hMemory_L2, InputStubMemory<BARRELPS>& hMemory_L3,
				  InputStubMemory<DISKPS>& hMemory_D1, InputStubMemory<DISKPS>& hMemory_D2, InputStubMemory<DISKPS>& hMemory_D3 , InputStubMemory<DISKPS>& hMemory_D4, InputStubMemory<DISKPS>& hMemory_D5 )
{
	ap_uint<kLINKMAPwidth> hDTCMapEncoded = Map.read_mem(1, linkId).raw();
	RouteStub<BARRELPS,DISKPS>(hDTCMapEncoded, bx, hIputLink,hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
}

// disk 2S input router 
void InputRouter(const LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<BARREL2S>& hMemory_L1 ,InputStubMemory<BARREL2S>& hMemory_L2, InputStubMemory<BARREL2S>& hMemory_L3,
				  InputStubMemory<DISK2S>& hMemory_D1, InputStubMemory<DISK2S>& hMemory_D2, InputStubMemory<DISK2S>& hMemory_D3 , InputStubMemory<DISK2S>& hMemory_D4, InputStubMemory<DISK2S>& hMemory_D5 )
{
	ap_uint<kLINKMAPwidth> hDTCMapEncoded = Map.read_mem(1, linkId).raw();
	RouteStub<BARREL2S,DISK2S>(hDTCMapEncoded, bx, hIputLink, hMemory_L1, hMemory_L2, hMemory_L3, hMemory_D1, hMemory_D2, hMemory_D3, hMemory_D4, hMemory_D5);
}