#ifndef PROJECTIONROUTER_HH
#define PROJECTIONROUTER_HH

// Projection Router
#include "Constants.hh"
#include "TrackletProjectionMemory.hh"
#include "AllProjectionMemory.hh"
#include "VMProjectionMemory.hh"

//#include <assert.h>

//////////////////////////////
// Input memory reading logic
template<int nbits_nMEM, int nbits_MemAddr>
bool get_mem_read_addr(ap_uint<nbits_nMEM>& imem, ap_uint<nbits_MemAddr>& addr,
					   ap_uint<(1<<nbits_nMEM)>& mem_hasdata, ap_uint<nbits_MemAddr>* numbersin)
{
  if (mem_hasdata == 0) return false;
  
  // priority encoder
  imem = __builtin_ctz(mem_hasdata);
  ++addr;
	  
  if (addr >= *(numbersin+imem)) {
    // All entries have been read out in memory[imem]
	// Prepare to read the next non-empty memory
	addr = 0;  // reset read address
	mem_hasdata -= (1<<imem);  // flip the lowest 1 bit to 0
  }
  
  return true;
}

//////////////////////////////
// ProjectionRouter
template<unsigned int nINMEM>
void ProjectionRouter(ap_uint<3> bx, // FIXME
                      TrackletProjectionMemory *const tproj1,
                      TrackletProjectionMemory *const tproj2,
                      TrackletProjectionMemory *const tproj3,
                      TrackletProjectionMemory *const tproj4,
                      TrackletProjectionMemory *const tproj5,
                      TrackletProjectionMemory *const tproj6,
                      TrackletProjectionMemory *const tproj7,
                      TrackletProjectionMemory *const tproj8,
                      ap_uint<3>& bx_o, // FIXME
                      AllProjectionMemory* allproj,
                      VMProjectionMemory* vmproj1,
                      VMProjectionMemory* vmproj2,
                      VMProjectionMemory* vmproj3,
                      VMProjectionMemory* vmproj4    
){
#pragma HLS inline off

  //assert(nINMEM <= 8); // maximum number of input ports is 8
  
  // reset
  allproj->clear();
  vmproj1->clear();
  vmproj2->clear();
  vmproj3->clear();
  vmproj4->clear();

  // logic for reading inputs
  // check the number of entries in the input memories
  ap_uint<8> mem_hasdata = 0;
  ap_uint<kNBits_MemAddr> numbersin[8] = {0,0,0,0,0,0,0,0};
#pragma HLS ARRAY_PARTITION variable=numbersin complete dim=0

  if (nINMEM > 0) {
    ap_uint<kNBits_MemAddr> num1 = tproj1->getEntries(bx);
    numbersin[0] = num1;
    if (num1 > 0) mem_hasdata += (1<<0);
  }
  if (nINMEM > 1) {
    ap_uint<kNBits_MemAddr> num2 = tproj2->getEntries(bx);
    numbersin[1] = num2;
    if (num2 > 0) mem_hasdata += (1<<1);
  }
  if (nINMEM > 2) {
    ap_uint<kNBits_MemAddr> num3 = tproj3->getEntries(bx);
    numbersin[2] = num3;
    if (num3 > 0) mem_hasdata += (1<<2);
  }
  if (nINMEM > 3) {
    ap_uint<kNBits_MemAddr> num4 = tproj4->getEntries(bx);
    numbersin[3] = num4;
    if (num4 > 0) mem_hasdata += (1<<3);
  }
  if (nINMEM > 4) {
    ap_uint<kNBits_MemAddr> num5 = tproj5->getEntries(bx);
    numbersin[4] = num5;
    if (num5 > 0) mem_hasdata += (1<<4);
  }
  if (nINMEM > 5) {
    ap_uint<kNBits_MemAddr> num6 = tproj6->getEntries(bx);
    numbersin[5] = num6;
    if (num6 > 0) mem_hasdata += (1<<5);
  }
  if (nINMEM > 6) {
    ap_uint<kNBits_MemAddr> num7 = tproj7->getEntries(bx);
    numbersin[6] = num7;
    if (num7 > 0) mem_hasdata += (1<<6);
  }
  if (nINMEM > 7) {
    ap_uint<kNBits_MemAddr> num8 = tproj8->getEntries(bx);
    numbersin[7] = num8;
    if (num8 > 0) mem_hasdata += (1<<7);
  }

  // TODO: package the prio encoder reading logic better
  
  // Input memory index
  // The number of bits for imem depends on the max number of input ports.
  // 3 here for 8 input tprojs
  ap_uint<3> imem = 0;
  ap_uint<kNBits_MemAddr> addr_next = 0;
  
 PROC_LOOP: for (int i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1
    // read inputs3
    ap_uint<kNBits_MemAddr> addr = addr_next;
    bool validin = get_mem_read_addr<3, kNBits_MemAddr>(imem, addr_next, mem_hasdata, numbersin);
    
    if (not validin) continue;

    TrackletProjection tproj;
    // read input memories
    switch (imem)
      {
      case 0:
        tproj = tproj1->read_mem(bx, addr);
        break;
      case 1:
        tproj = tproj2->read_mem(bx, addr);
        break;
      case 2:
        tproj = tproj3->read_mem(bx, addr);
        break;
      case 3:
        tproj = tproj4->read_mem(bx, addr);
        break;
      case 4:
        tproj = tproj5->read_mem(bx, addr);
        break;
      case 5:
        tproj = tproj6->read_mem(bx, addr);
        break;
      case 6:
        tproj = tproj7->read_mem(bx, addr);
        break;
      case 7:
        tproj = tproj8->read_mem(bx, addr);
        break;
      }
    
    TrackletProjection::TProjPHI iphiproj = tproj.GetPhi();
    TrackletProjection::TProjZ izproj = tproj.GetZ();
    TrackletProjection::TProjPHIDER iphider = tproj.GetPhiDer();

    // routing
    auto iphi5 = iphiproj>>(iphiproj.length()-5);  // top 5 bits of phi

    // FIXME
    // inner barrel non-hourglass for now
    //assert(iphi5>=4 and iphi5<=27);
    ap_uint<2> iphi = ((iphi5-4)>>1)&3;
    //assert(iphi>=0 and iphi<=3);

    // vmproj index
    VMProjection::VMPID index = i;

    // vmproj z
    // Separate the vm projections into zbins
    // The central bin e.g.: zbin=4+(zproj.value()>>(zproj.nbits()-3));
    // (assume 8 bins; take top 3 bits of zproj and shift it to make it positive)
    // But we need some range (particularly for L5L6 seed projecting to L1-L3):
    // Lower bound
    ap_uint<MEBinsBits> zbin1 = (1<<(MEBinsBits-1))+(((izproj>>(izproj.length()-MEBinsBits-2))-2)>>2);
    // Upper bound
    ap_uint<MEBinsBits> zbin2 = (1<<(MEBinsBits-1))+(((izproj>>(izproj.length()-MEBinsBits-2))+2)>>2);
    if (zbin1 >= (1<<MEBinsBits)) zbin1 = 0;
    if (zbin2 >= (1<<MEBinsBits)) zbin2 = (1<<MEBinsBits)-1;

    if (zbin1>=(1<<MEBinsBits)) zbin1=0; //note that zbin1 is unsigned
    if (zbin2>=(1<<MEBinsBits)) zbin2=(1<<MEBinsBits)-1;
    //assert(zbin1<=zbin2);
    //assert(zbin2-zbin1<=1);
	  
    VMProjection::VMPZBIN zbin = (zbin1, zbin2!=zbin1);
    //fine vm z bits. Use 4 bits for fine position. starting at zbin 1
    // need to be careful about left shift of ap_(u)int
    VMProjection::VMPFINEZ finez = ((1<<(MEBinsBits+2))+(izproj>>(izproj.length()-(MEBinsBits+3))))-(zbin1,ap_uint<3>(0));

    // vmproj irinv
    VMProjection::VMPRINV rinv = 16 + (iphider>>(iphider.length()-5));
    //assert(rinv >=0 and rinv < 32);
    // PS seed
    bool psseed = false;  // FIXME

    // VM Projection
    VMProjection vmproj(index, zbin, finez, rinv, psseed);

    // All Projection
    AllProjection aproj(tproj.raw());

    // write outputs
    //assert(iphi>=0 and iphi<4);
    switch(iphi) {
    case 0:
      vmproj1->write_mem(bx, vmproj);
      break;
    case 1:
      vmproj2->write_mem(bx, vmproj);
      break;
    case 2:
      vmproj3->write_mem(bx, vmproj);
      break;
    case 3:
      vmproj4->write_mem(bx, vmproj);
      break;
    }

    allproj->write_mem(bx, aproj);

    bx_o = bx;
    
  } // end of PROC_LOOP
  
} // ProjectionRouter

#endif
