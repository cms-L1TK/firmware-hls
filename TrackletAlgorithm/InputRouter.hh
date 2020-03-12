#ifndef INPUTROUTER_HH
#define INPUTROUTER_HH

#include "Constants.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"
#include "InputStubMemory.hh"

void WriteMap(int address, ap_uint<kLINKMAPwidth>  encodedMap , DTCMapMemory *Map );
void ReadMap(int address, DTCMapMemory Map, DTCMap&  encodedMap);

// DTC (and therefore input link) is either PS or 2S .. 
// so a templated input router might make sense? 
template<int ISTypeBarrel, int ISTypeDisk>
void InputRouter(const LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink,
				  InputStubMemory<ISTypeBarrel> *hMemory_L1 ,InputStubMemory<ISTypeBarrel> *hMemory_L2, InputStubMemory<ISTypeBarrel> *hMemory_L3,
				  InputStubMemory<ISTypeDisk> *hMemory_D1, InputStubMemory<ISTypeDisk> *hMemory_D2, InputStubMemory<ISTypeDisk> *hMemory_D3 )
{
  ap_uint<kNBits_DTC> hInputStub;
  ap_uint<kLINKMAPwidth> hDTCMapEncoded = Map.read_mem(1, linkId).raw();

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
    // can do this once I know what the phi segmentation is here ..   
    ap_uint<4> cPhiRegion; 
    if( cIsBarrel )
    {
    	cBarrelStub =  InputStub<ISTypeBarrel>(hInputStub.range(kBRAMwidth-1,0)); 
    	cPhiRegion = ( cBarrelStub.getPhi() & (0xF << (cBarrelStub.kISPhiSize-4+1)) ) >> (cBarrelStub.kISPhiSize-4+1);
    }
    else
    {
    	cDiskStub =  InputStub<ISTypeDisk>(hInputStub.range(kBRAMwidth-1,0)); 
    	cPhiRegion = ( cDiskStub.getPhi() & (0xF << (cDiskStub.kISPhiSize-4+1)) ) >> (cDiskStub.kISPhiSize-4+1);
    }
    //std::cout << " \t\t\t... layer " << +cLayerOrDisk << " stub has a phi coordinate of " << cBarrel2Sstub.getPhi() << " phi region is " << +cPhiRegion << "\n";
    if( cIsBarrel == 1 && !cIs2S )
    {
      #ifndef __SYNTHESIS__
        std::cout << "PS Stub from layer " << +cLayerOrDiskId << "  of barrel.\n";
      #endif

      if( cLayerOrDiskId == 1 ) 
        hMemory_L1->write_mem(bx, hStub, hMemory_L1->getEntries(bx) );
      else if( cLayerOrDiskId == 2 ) 
        hMemory_L2->write_mem(bx, hStub, hMemory_L2->getEntries(bx) );
      else if( cLayerOrDiskId == 2 ) 
        hMemory_L3->write_mem(bx, hStub, hMemory_L3->getEntries(bx) );
    }
    else if( cIsBarrel == 1 && cIs2S )
    {
      #ifndef __SYNTHESIS__
        std::cout << "2S Stub from layer " << +cLayerOrDiskId << "  of barrel.\n";
      #endif
      
      if( cLayerOrDiskId == 4 ) 
        hMemory_L1->write_mem(bx, hStub, hMemory_L1->getEntries(bx) );
      else if( cLayerOrDiskId == 5 ) 
        hMemory_L2->write_mem(bx, hStub, hMemory_L2->getEntries(bx) );
      else if( cLayerOrDiskId == 6 ) 
        hMemory_L3->write_mem(bx, hStub, hMemory_L3->getEntries(bx) );
    }
    else if( cIsBarrel == 0 && !cIs2S )
    {
      #ifndef __SYNTHESIS__
    	if( !!cIs2S )
    		std::cout << "PS Stub from disk " << +cLayerOrDiskId << "  of end-cap.\n";
      	else 
       		std::cout << "2S Stub from disk " << +cLayerOrDiskId << "  of end-cap.\n";
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
  // if (hIputLink.read_nb(hInputStream))
  // {
  //   std::cout << "Reading stub from input link...\n";
  // }
  // else
  // {
  //   std::cout << "Reached end of the stream...\n";
  // }
  // ap_uint<kNBits_DTC> din;
  // InputStub<BARRELPS> dout;
  // ap_uint<kNBits_LayerId> cLayerId;
  // //ap_uint<2> region; // layer or 
  // //ap_uint<2> phiDivision;
  // for (int i=0; i<kMaxStubsFromLink; ++i)
  // {
  //   #pragma HLS PIPELINE II=1
  //   //blocking read 
  //   //IL.read(din);

  //   // the non-blocking version of the read 
  //   if (IL.read_nb(din)) // if data is available the function will update the reference in the argument with the values and return “true” 
  //   {
  //     cLayerId = din.range(38,36);
  //     // region = din.range(37,36);
  //     // if (fromL1 && region==0) 
  //     // {
  //     //   phiDivision = din.range(15,14);
  //     // } 
  //     // else 
  //     // {
  //     //   phiDivision = din.range(15,15);
  //     // }
  //     // dout = InputStub<BARRELPS>(din.range(35,0));
  //     // if (region == 0) {
  //     //   if (phiDivision == 0) {
  //     //     R0PhiA->write_mem(bx,dout);
  //     //   } else if (phiDivision == 1) {
  //     //     R0PhiB->write_mem(bx,dout);
  //     //   } else if (phiDivision == 2) {
  //     //     R0PhiC->write_mem(bx,dout);
  //     //   } else if (phiDivision == 3) {
  //     //     R0PhiD->write_mem(bx,dout);
  //     //   }
  //     // } else if (region == 1) {
  //     //   if (phiDivision == 0) {
  //     //     R1PhiA->write_mem(bx,dout);
  //     //   } else if (phiDivision == 1) {
  //     //     R1PhiB->write_mem(bx,dout);
  //     //   }
  //     // } else if (region == 2) {
  //     //   if (phiDivision == 0) {
  //     //     R2PhiA->write_mem(bx,dout);
  //     //   } else if (phiDivision == 1) {
  //     //     R2PhiB->write_mem(bx,dout);
  //     //   }
  //     // } else if (region == 3) {
  //     //   if (phiDivision == 0) {
  //     //     R3PhiA->write_mem(bx,dout);
  //     //   } else if (phiDivision == 1) {
  //     //     R3PhiB->write_mem(bx,dout);
  //     //   } // inner switch
  //     // } // outer switch
  //   } // read if
  // } // stub loop
}// input router function

#endif
