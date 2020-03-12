template<int ISTypeBarrel, int ISTypeDisk>
void RouteStub(ap_uint<kLINKMAPwidth> hDTCMapEncoded, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<ISTypeBarrel> *hMemory_L1 ,InputStubMemory<ISTypeBarrel> *hMemory_L2, InputStubMemory<ISTypeBarrel> *hMemory_L3,
				  InputStubMemory<ISTypeDisk> *hMemory_D1, InputStubMemory<ISTypeDisk> *hMemory_D2, InputStubMemory<ISTypeDisk> *hMemory_D3 )
{
  ap_uint<kNBits_DTC> hInputStub;
  
  // input stubs per region/type of module 
  InputStub<ISTypeBarrel> cBarrelStub;
  InputStub<ISTypeDisk> cDiskStub;
  
  #pragma HLS PIPELINE II=1
  //the non-blocking version of the read 
  if (hIputLink.read_nb(hInputStub)) // if data is available the function will update the reference in the argument with the values and return “true” 
  {
	//std::cout << " \t\t\t... Stub " << std::hex << hInputStub << std::dec << "\n";
	ap_uint<kNBits_Debug> cDebugWord = hInputStub.range(kNBits_DTC-1,kNBits_DTC-kNBits_Debug);
	ap_uint<kNBits_LayerId> cLayerId  = cDebugWord.range(kNBits_Debug-kNBits_Valid-1,kNBits_Debug-kNBits_Valid-kNBits_LayerId);

	ap_uint<5> cLayerEncoding = ( (hDTCMapEncoded & (0x1F << cLayerId*5)) >> cLayerId*5 ); 
	ap_uint<1> cIsBarrel = ( cLayerEncoding & 0x01)  ; 
	ap_uint<1> cIs2S = ( cLayerEncoding & 0x02) >> 1; 
	ap_uint<3> cLayerOrDiskId = ( cLayerEncoding & 0x1C) >> 2;
	// discard bits so that the stub fits into the standard BRAM width 
	ap_uint<kBRAMwidth> hStub = hInputStub.range(kBRAMwidth-1,0);

	// for now assume one memory per layer .. no phi segmentation here 
	//std::cout << " \t\t\t... layer " << +cLayerOrDisk << " stub has a phi coordinate of " << cBarrel2Sstub.getPhi() << " phi region is " << +cPhiRegion << "\n";
	// can do this once I know what the phi segmentation is here ..   
	ap_uint<4> cPhiRegion; 
	if( cIsBarrel == 1  )
	{
		// phi region
		cBarrelStub =  InputStub<ISTypeBarrel>(hStub); 
		cPhiRegion = ( cBarrelStub.getPhi() & (0xF << (cBarrelStub.kISPhiSize-4+1)) ) >> (cBarrelStub.kISPhiSize-4+1);
		// 3 layers for each of barrel and disk - so make sure that the layer we're checking starts from 1 
		ap_uint<3> cLayer;
		if (cIs2S) 
			cLayer = (cLayerOrDiskId-4);
		else 
			cLayer = cLayerOrDiskId;
		#ifndef __SYNTHESIS__
			if( !cIs2S )
				std::cout << "PS Stub from layer " << +cLayerOrDiskId << "  of barrel. Phi region is " << +cPhiRegion << "\n";
			else 
				std::cout << "2S Stub from layer " << +cLayerOrDiskId << "  of barrel. Phi region is " << +cPhiRegion << "\n";
		#endif

		if( cLayer == 1 ) 
			hMemory_L1->write_mem(bx, hStub, hMemory_L1->getEntries(bx) );
		else if( cLayer == 2 ) 
			hMemory_L2->write_mem(bx, hStub, hMemory_L2->getEntries(bx) );
		else if( cLayer == 2 ) 
			hMemory_L3->write_mem(bx, hStub, hMemory_L3->getEntries(bx) );
	}
	else if( cIsBarrel == 0  )
	{
		// phi region
		cDiskStub =  InputStub<ISTypeDisk>(hStub); 
		cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
		#ifndef __SYNTHESIS__
			if( !cIs2S )
				std::cout << "PS Stub from disk " << +cLayerOrDiskId << "  of end-cap. Phi region is " << +cPhiRegion << "\n";
			else 
				std::cout << "2S Stub from disk " << +cLayerOrDiskId << "  of end-cap. Phi region is " << +cPhiRegion << "\n";
		#endif

		if( cLayerOrDiskId == 1 ) 
			hMemory_D1->write_mem(bx, hStub, hMemory_D1->getEntries(bx) );
		else if( cLayerOrDiskId == 2 ) 
			hMemory_D2->write_mem(bx, hStub, hMemory_D2->getEntries(bx) );
		else if( cLayerOrDiskId == 3 )
			hMemory_D3->write_mem(bx, hStub, hMemory_D3->getEntries(bx) );
	}
	else 
	{
	  #ifndef __SYNTHESIS__
	    std::cout << "Something has gone wrong.. stub is from an invalid layer/disk/region\n";
	  #endif
	}
  }
}// input router 