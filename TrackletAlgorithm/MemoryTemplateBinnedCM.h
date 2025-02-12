// Class template for binned memory module
#ifndef TrackletAlgorithm_MemoryTemplateBinnedCM_h
#define TrackletAlgorithm_MemoryTemplateBinnedCM_h

#ifndef __SYNTHESIS__
#include <iostream>
#include <sstream>
#include <vector>
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

//This is a bit of a hack, but until we find a cleaner
//way to implement this we will use this...
#include "SynthesisOptions.h"

#ifdef CMSSW_GIT_HASH
template<class DataType, unsigned int DUMMY, unsigned int NBIT_ADDR, unsigned int NBIT_BIN, unsigned int kNBitsphibinCM, unsigned int NCOPY>
#else
template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR, unsigned int NBIT_BIN, unsigned int kNBitsphibinCM, unsigned int NCOPY>
#endif

// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BX): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX
// (1<<NBIT_ADDR): depth of the memory for each BX
// NBIT_BIN: number of bits used for binning; (1<<NBIT_BIN): number of bins
// NCOPY: is the number of memory copies - same as number of TE used

// N.B. The CMSSW version of this pretends to have NCOPY copies to anyone 
// using this class, but doesn't actually instantiate them, to save memory.

class MemoryTemplateBinnedCM{

private:
#ifdef CMSSW_GIT_HASH
  static constexpr bool isCMSSW = true;
  static constexpr unsigned int NBIT_BX = 0;
  static constexpr unsigned int NCP = 1;
#else
  static constexpr bool isCMSSW = false;
  static constexpr unsigned int NCP = NCOPY;
#endif

public:
  static constexpr unsigned int DEPTH_BX = 1<<NBIT_BX;
  static constexpr unsigned int DEPTH_ADDR = 1<<NBIT_ADDR;
  static constexpr unsigned int DEPTH_BIN = 1<<NBIT_BIN;
 
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR-NBIT_BIN> NEntryT;

protected:
  enum BitWidths {
    kNBxBins = DEPTH_BX,
    kNSlots = DEPTH_BIN,
    kNMemDepth = DEPTH_ADDR,
    kNBitsRZBinCM = NBIT_BIN-kNBitsphibinCM,
    kNBinsRZ = (1<<kNBitsRZBinCM),  //FIXME is this wrong?
    slots = (1<<(NBIT_BX+NBIT_BIN-kNBitsphibinCM))
  };

  DataType dataarray_[NCP][kNBxBins][kNMemDepth];  // data array

  ap_uint<8> binmask8_[kNBxBins][1<<kNBitsRZBinCM];
  ap_uint<64> nentries_[slots];

  ap_uint<8> binmaskA_[slots];
  ap_uint<8> binmaskB_[slots]; 
 
  
#if !(defined __SYNTHESIS__  && !defined SYNTHESIS_TEST_BENCH)
  ap_uint<4> nentriestmp_[1<<NBIT_BIN];
  BunchXingT write_bx_;                //BX for writing
#endif

public:

  unsigned int getDepth() const {return kNMemDepth;}
  unsigned int getNBX() const {return kNBxBins;}
  unsigned int getNBins() const {return kNSlots;}
  unsigned int getNEntryPerBin() const {return (1<<(NBIT_ADDR-NBIT_BIN));}
  unsigned int getNCopy() const {return NCOPY;}

  ap_uint<8> getBinMaskA(const ap_uint<NBIT_BX+NBIT_BIN-kNBitsphibinCM>& addrbinmaskA) const {
    // std::cout << "getBinMaskA:" << addrbinmaskA << std::endl;
    return binmaskA_[addrbinmaskA];
  }
  
  ap_uint<8> getBinMaskB(const ap_uint<NBIT_BX+NBIT_BIN-kNBitsphibinCM>& addrbinmaskB) const {
    return binmaskB_[addrbinmaskB];
  }
  
#if !(defined __SYNTHESIS__  && !defined SYNTHESIS_TEST_BENCH)
  void setWriteBX(const BunchXingT& ibx) {
    write_bx_ = ibx;
  }
#endif
  
  NEntryT getEntries(const BunchXingT& bx, ap_uint<NBIT_BIN> slot) const {
    ap_uint<kNBitsRZBinCM> ibin;
    ap_uint<kNBitsphibinCM> ireg;
    (ireg,ibin)=slot;
    return nentries_[bx][ibin].range(ireg*4+3,ireg*4);
  }

  ap_uint<64> getEntries(const BunchXingT& bx, ap_uint<kNBitsRZBinCM> ibin) const {
    return nentries_[bx*(1<<kNBitsRZBinCM)+ibin];
  }

  ap_uint<8> getBinMask8(const BunchXingT& bx, ap_uint<kNBitsRZBinCM> ibin) const {
#pragma HLS ARRAY_PARTITION variable=binmask8_ complete dim=0
    return binmask8_[bx][ibin];
  }

  NEntryT getEntries(const BunchXingT& bx) const {
    NEntryT val = 0;
    for ( auto i = 0; i < getDepth(); ++i ) {
      val += getEntries(bx, i);
    }
    return val;
  }

  const DataType (&getMem(unsigned int icopy) const)[DEPTH_BX][DEPTH_ADDR] {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    if (isCMSSW) icopy = 0;
    return dataarray_[icopy];
  }

#ifndef CMSSW_GIT_HASH
  const DataType (&get_mem() const)[NCOPY][DEPTH_BX][DEPTH_ADDR] {
    return dataarray_;
  }
#endif

  DataType read_mem(unsigned int icopy, const BunchXingT& ibx, ap_uint<NBIT_ADDR> index) const {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    // TODO: check if valid
    if (isCMSSW) {assert(ibx == 0 && icopy == 0);}
    return dataarray_[icopy][ibx][index];
  }
  
  DataType read_mem(unsigned int icopy, const BunchXingT& ibx,
		    ap_uint<NBIT_BIN> slot, ap_uint<NBIT_ADDR> index) const {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    // TODO: check if valid
    if (isCMSSW) {assert(ibx == 0 && icopy == 0);}
    return dataarray_[icopy][ibx][getNEntryPerBin()*slot+index];
  }

  bool write_mem(ap_uint<NBIT_BIN> slot, const DataType& data) {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
#pragma HLS ARRAY_PARTITION variable=binmask8_ complete dim=0
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS inline


#if defined __SYNTHESIS__  && !defined SYNTHESIS_TEST_BENCH
    //The vhdl implementation will write to the correct address
    dataarray_[0][0][getNEntryPerBin()*slot] = data;
    return true;

#else

#pragma HLS ARRAY_PARTITION variable=nentriestmp_ complete dim=0

    if (isCMSSW && !NBIT_BX) {write_bx_ = 0;}

    ap_uint<kNBitsRZBinCM> ibin;
    ap_uint<kNBitsphibinCM> ireg;
    (ibin,ireg)=slot;

    unsigned int nentry = nentriestmp_[slot];

    if (nentry == ((1 << (NBIT_ADDR-NBIT_BIN)) - 1)) return false;

    nentries_[write_bx_*kNBinsRZ+ibin].range(ireg*4+3,ireg*4)=nentry+1;
    //The next ifdef is a real hack. In order to meet II=1 for test benches
    //where we write to a VM memory we don't properly fill the nentries_
    //array. This works because the test benches does not check the nentries_
    //However, in a testbench when we read in a VM memory we need the
    //nentries_ to be properly set for use in the TP or MP modules

#if !defined __SYNTHESIS__
    if (ibin!=0) {
      nentries_[write_bx_*kNBinsRZ+ibin-1].range((ireg+8)*4+3,(ireg+8)*4)=nentry+1;
    }
    binmaskA_[write_bx_*kNBinsRZ+ibin].set_bit(ireg,true);
    binmaskB_[write_bx_*kNBinsRZ+ibin].set_bit(ireg,true);
#else
    binmaskA_[write_bx_*kNBinsRZ+ibin] = 0;
    binmaskB_[write_bx_*kNBinsRZ+ibin] = 0;
#endif

    nentriestmp_[slot] = nentry+1;

    binmask8_[write_bx_][ibin].set_bit(ireg,true);

    //std::cout << "write_bx_:" << write_bx_ << std::endl;
    
    //icopy comparison must be signed int or future SW fails
  writememloop:for (signed int icopy=0;icopy< (signed) NCP;icopy++) {
#pragma HLS unroll
      dataarray_[icopy][write_bx_][getNEntryPerBin()*slot+nentry] = data;
    }
    return true;
#endif      
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__

  MemoryTemplateBinnedCM() {
    clear();
  }

  ~MemoryTemplateBinnedCM() {}

  void clear() {

    DataType data("0",16);
    //std::cout << "Clear: " << kNBxBins << "  " << (1<<kNBitsRZBinCM) << std::endl;
    for (size_t ibx=0; ibx<(kNBxBins); ++ibx) {
      for (size_t ibin=0; ibin < (1<<kNBitsRZBinCM); ibin++) {
	      binmask8_[ibx][ibin] = 0;
	      binmaskA_[ibx*kNBinsRZ+ibin] = 0;
	      binmaskB_[ibx*kNBinsRZ+ibin] = 0;
      }
      for (size_t ibin=0; ibin < kNMemDepth; ibin++) {
	for (size_t icopy=0; icopy < NCP; icopy++) {
          dataarray_[icopy][ibx][ibin] = data;
        }
      }
    }

    for (size_t ibin=0; ibin < (1<<NBIT_BIN); ibin++) {
      nentriestmp_[ibin] = 0;
    }

    for (size_t ibin=0; ibin < slots; ibin++) {
      nentries_[ibin] = 0;
    }
    
  }

  // write memory from text file
  bool write_mem(const std::vector<std::string>& split_line, int base=16) {

    assert(split_line.size()==4);

    if (isCMSSW) {write_bx_ = 0;}

    std::string datastr = split_line.back();

    int slot = (int)strtol(split_line.front().c_str(), nullptr, base); // Convert string (in hexadecimal) to int

    DataType data(datastr.c_str(), base);

    bool success = write_mem(slot, data);
    
    return success;
  }

  
  // print memory contents
  void print_data(const DataType& data) const
  {
    edm::LogVerbatim("L1trackHLS") << std::hex << data.raw() << std::endl;
    // TODO: overload '<<' in data class
  }

  void print_entry(const BunchXingT& bx, ap_uint<NBIT_ADDR> index) const
  {
    print_data(dataarray_[bx][index]);
  }

  static constexpr int getWidth() {return DataType::getWidth();}

#endif

#ifdef CMSSW_GIT_HASH
  std::string name_;
  void setName(std::string name) { name_ = name;}
  std::string const& getName() const { return name_;}

  unsigned int iSector_;
  void setSector(unsigned int iS) { iSector_ = iS;}
  unsigned int getSector() const { return iSector_;}
#endif
};

#endif
