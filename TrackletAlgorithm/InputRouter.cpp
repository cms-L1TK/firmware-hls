#include "InputRouter.hh"
#include "hls_math.h"
#include "ap_int.h"
#include "hls_stream.h"

//constexpr unsigned int kInputLinkSize = 38;
//typedef ap_uint<kInputLinkSize> InputLinkData;
// template this .. for now its just PS barrel 
void InputRouter(const LINK linkId, DTCMapMemory Map, const BXType bx, hls::stream<ap_uint<kNBits_DTC> >& hIputLink)
{
  ap_uint<kNBits_DTC> hInputStub;
  ap_uint<kLINKMAPwidth> hDTCMapEncoded = Map.read_mem(1, linkId).raw();

  InputStub<BARRELPS> cBarrelPSstub;
  InputStub<BARREL2S> cBarrel2Sstub;
  InputStub<DISKPS> cDiskPSstub;
  InputStub<DISK2S>  cDisk2Sstub;
  //std::cout << std::hex << (hDTCMapEncoded&0xFFFF) << std::dec << "\n";
  for (int cStubCounter=0; cStubCounter<kMaxStubsFromLink; cStubCounter++)
  {

    //#pragma HLS PIPELINE II=1
    //the non-blocking version of the read 
    if (hIputLink.read_nb(hInputStub)) // if data is available the function will update the reference in the argument with the values and return “true” 
    {
      ap_uint<kNBits_Debug> cDebugWord = hInputStub.range(kNBits_DTC-1,kNBits_DTC-kNBits_Debug);
      ap_uint<kNBits_LayerId> cLayerId  = cDebugWord.range(kNBits_Debug-kNBits_Valid-1,kNBits_Debug-kNBits_Valid-kNBits_LayerId);
      
      ap_uint<5> cLayerEncoding = ( (hDTCMapEncoded & (0x1F << cLayerId*5)) >> cLayerId*5 ); 
      ap_uint<1> cIsBarrel = ( cLayerEncoding & 0x01)  ; 
      ap_uint<1> cIs2S = ( cLayerEncoding & 0x02) >> 1; 
      ap_uint<3> cLayerOrDisk = ( cLayerEncoding & 0x1C) >> 2;
      //std::cout << "Debug word for stub " << +cStubCounter << " is " << std::hex << cDebugWord << std::dec << " layer id is " << +cLayerId << " which means layer " << +cLayer << " and barrel bit is " << +cIsBarrel << "\n";
      ap_uint<kBRAMwidth> hStub = hInputStub.range(kBRAMwidth-1,0);
      ap_uint<4> cPhiRegion; 
      if( cIsBarrel == 1 && cIs2S )
      {
        cBarrel2Sstub =  InputStub<BARREL2S>(hInputStub.range(kBRAMwidth-1,0)); 
        cPhiRegion = ( cBarrel2Sstub.getPhi() & (0xF << (cBarrel2Sstub.kISPhiSize-4+1)) ) >> (cBarrel2Sstub.kISPhiSize-4+1);
        //std::cout << " \t\t\t... layer " << +cLayerOrDisk << " stub has a phi coordinate of " << cBarrel2Sstub.getPhi() << " phi region is " << +cPhiRegion << "\n";
      }
      else if( cIsBarrel == 1 && !cIs2S )
      {
        cBarrelPSstub =  InputStub<BARRELPS>(hInputStub.range(kBRAMwidth-1,0)); 
        cPhiRegion = ( cBarrelPSstub.getPhi() & (0xF << (cBarrelPSstub.kISPhiSize-4+1)) ) >> (cBarrelPSstub.kISPhiSize-4+1);
        std::cout << " \t\t\t... layer " << +cLayerOrDisk << " stub has a phi coordinate of " << cBarrelPSstub.getPhi() << " phi region is " << +cPhiRegion << "\n";
      }
      else if( cIsBarrel == 0 && cIs2S )
      {
        cDisk2Sstub = InputStub<DISK2S>(hInputStub.range(kBRAMwidth-1,0)); 
        cPhiRegion = ( cDisk2Sstub.getPhi() & (0xF << (cDisk2Sstub.kISPhiSize-4+1)) ) >> (cDisk2Sstub.kISPhiSize-4+1);
        //std::cout << " \t\t\t... disk " << +cLayerOrDisk << " stub has a phi coordinate of " << cDisk2Sstub.getPhi() << " phi region is " << +cPhiRegion << "\n";
      }
      else
      {
        cDiskPSstub = InputStub<DISKPS>(hInputStub.range(kBRAMwidth-1,0)); 
        cPhiRegion = ( cDiskPSstub.getPhi() & (0xF << (cDiskPSstub.kISPhiSize-4+1)) ) >> (cDiskPSstub.kISPhiSize-4+1);
        //std::cout << " \t\t\t... disk " << +cLayerOrDisk << " stub has a phi coordinate of " << cDiskPSstub.getPhi() << " phi region is " << +cPhiRegion << "\n";
      }
      // just want to take the number of bits that fit in a standard BRAM 
      // have to figure out if this is a PS or a 2S module 
      //hMemory.write_mem(bx, hStub, cStubCounter);
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
} // input router function
 

//
void WriteMap(int address, ap_uint<kLINKMAPwidth>  encodedMap , DTCMapMemory *Map)
{
  Map->write_mem(1, encodedMap, address);
} // link map function 

//
void ReadMap(int address, DTCMapMemory Map, DTCMap&  encodedMap)
{
  encodedMap = Map.read_mem(1, address);
} 
