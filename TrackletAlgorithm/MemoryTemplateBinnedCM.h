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

#ifdef CMSSW_GIT_HASH
template<class DataType, unsigned int DUMMY, unsigned int NBIT_ADDR, unsigned int NBIT_BIN, unsigned int kNBitsphibinCM, unsigned int NCOPY>
#else
template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR, unsigned int NBIT_BIN, unsigned int kNBitsphibinCM, unsigned int NCOPY>
#endif

// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BIN): number of BXs the memory is keeping track of
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
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR-NBIT_BIN> NEntryT;

 protected:
  enum BitWidths {
    kNBxBins = 1<<NBIT_BX,
    kNSlots = 1<<NBIT_BIN,
    kNMemDepth = 1<<NBIT_ADDR,
    kNBitsRZBinCM = NBIT_BIN-kNBitsphibinCM,
    kNBinsRZ = (1<<kNBitsRZBinCM),
    slots = (1<<(NBIT_BX+NBIT_BIN-kNBitsphibinCM)),
    entries8 = 32
  };

  DataType dataarray_[NCP][kNBxBins][kNMemDepth];  // data array

  ap_uint<8> binmask8_[kNBxBins][1<<kNBitsRZBinCM];
  ap_uint<32> nentries8_[kNBxBins][1<<kNBitsRZBinCM];
  ap_uint<64> nentries_[slots];

public:

  unsigned int getDepth() const {return kNMemDepth;}
  unsigned int getNBX() const {return kNBxBins;}
  unsigned int getNBins() const {return kNSlots;}
  unsigned int getNEntryPerBin() const {return (1<<(NBIT_ADDR-NBIT_BIN));}
  unsigned int getNCopy() const {return NCOPY;}

  NEntryT getEntries(BunchXingT bx, ap_uint<NBIT_BIN> slot) const {
    ap_uint<kNBitsRZBinCM> ibin;
    ap_uint<kNBitsphibinCM> ireg;
    (ireg,ibin)=slot;
    return nentries8_[bx][ibin].range(ireg*4+3,ireg*4);
  }





  ap_uint<32> getEntries8(BunchXingT bx, ap_uint<kNBitsRZBinCM> ibin) const {
    #pragma HLS ARRAY_PARTITION variable=nentries8_ complete dim=0
    return nentries8_[bx][ibin];
  }

  ap_uint<64> getEntries(BunchXingT bx, ap_uint<kNBitsRZBinCM> ibin) const {
    return nentries_[bx*8+ibin];
  }

  ap_uint<8> getBinMask8(BunchXingT bx, ap_uint<kNBitsRZBinCM> ibin) const {
    #pragma HLS ARRAY_PARTITION variable=binmask8_ complete dim=0
    return binmask8_[bx][ibin];
  }

  NEntryT getEntries(BunchXingT bx) const {
    NEntryT val = 0;
    for ( auto i = 0; i < getDepth(); ++i ) {
      val += getEntries(bx, i);
    }
    return val;
  } 

  const DataType (&getMem(unsigned int icopy) const)[1<<NBIT_BX][1<<NBIT_ADDR] {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    if (isCMSSW) icopy = 0;
    return dataarray_[icopy];
  }


#ifndef CMSSW_GIT_HASH
  const DataType (&get_mem() const)[NCOPY][1<<NBIT_BX][1<<NBIT_ADDR] {
    return dataarray_;
  }
#endif

  DataType read_mem(unsigned int icopy, BunchXingT ibx, ap_uint<NBIT_ADDR> index) const {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    // TODO: check if valid
    if (isCMSSW) {ibx = 0; icopy = 0;}
    return dataarray_[icopy][ibx][index];
  }
  DataType read_mem(unsigned int icopy, BunchXingT ibx, ap_uint<NBIT_BIN> slot,
		    ap_uint<NBIT_ADDR> index) const {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
    // TODO: check if valid
    if (isCMSSW) {ibx = 0; icopy = 0;}
    return dataarray_[icopy][ibx][getNEntryPerBin()*slot+index];
  }
  bool write_mem(BunchXingT ibx, ap_uint<NBIT_BIN> slot, DataType data, unsigned int nentry_ibx) {
#pragma HLS ARRAY_PARTITION variable=dataarray_ dim=1
#pragma HLS ARRAY_PARTITION variable=binmask8_ complete dim=0
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS ARRAY_PARTITION variable=nentries8_ complete dim=0
#pragma HLS inline
    if (isCMSSW && !NBIT_BX) {ibx = 0;}
    if (nentry_ibx < getNEntryPerBin()-1) { // Max 15 stubs in each memory due to 4 bit nentries
      // write address for slot: getNEntryPerBin() * slot + nentry_ibx

      ap_uint<kNBitsRZBinCM> ibin;
      ap_uint<kNBitsphibinCM> ireg;
      (ireg,ibin)=slot;
      unsigned int nentry = nentries_[ibx*kNBinsRZ+ibin].range(ireg*4+3,ireg*4);
      nentries_[ibx*kNBinsRZ+ibin].range(ireg*4+3,ireg*4)=nentry+1;
      if (ibin!=0) {
      	nentries_[ibx*kNBinsRZ+ibin-1].range((ireg+8)*4+3,(ireg+8)*4)=nentry+1;
      }
      nentries8_[ibx][ibin].range(ireg*4+3,ireg*4)=nentry+1;
      binmask8_[ibx][ibin].set_bit(ireg,true);

      //icopy comparison must be signed int or future SW fails
      writememloop:for (signed int icopy=0;icopy< (signed) NCP;icopy++) {
#pragma HLS unroll
	//#if defined __SYNTHESIS__ && !defined CSYNTH
        //dataarray_[icopy][ibx][getNEntryPerBin()*slot] = data;
	//#else
	//FIXME ugly hack...
	dataarray_[icopy][ibx][getNEntryPerBin()*slot+nentry] = data;
	//#endif      
      }
#ifdef CMSSW_GIT_HASH
      ap_uint<kNBitsRZBinCM> ibin;
      ap_uint<kNBitsphibinCM> ireg;
      (ireg,ibin)=slot;
      nentries_[ibx*kNBinsRZ+ibin].range(ireg*4+3,ireg*4)=nentry_ibx+1;
      if (ibin!=0) {
      	nentries_[ibx*kNBinsRZ+ibin-1].range((ireg+8)*4+3,(ireg+8)*4)=nentry_ibx+1;
      }
      nentries8_[ibx][ibin].range(ireg*4+3,ireg*4)=nentry_ibx+1;
      binmask8_[ibx][ibin].set_bit(ireg,true);
#endif

      return true;
    }
    else {
#ifndef __SYNTHESIS__
      if (data.raw() != 0) { // To avoid lots of prints when we're clearing the memories
	edm::LogVerbatim("L1trackHLS") << "Warning out of range. nentry_ibx = "<<nentry_ibx<<" NBIT_ADDR-NBIT_BIN = "<<NBIT_ADDR-NBIT_BIN << std::endl;
      }
#endif
      return false;
    }
  }

  // Methods for C simulation only
#ifndef __SYNTHESIS__

  MemoryTemplateBinnedCM() {
    clear();
  }

  ~MemoryTemplateBinnedCM() {}

  void clear() {

    DataType data("0",16);
    for (size_t ibx=0; ibx<(kNBxBins); ++ibx) {
      // Clear data
      for (unsigned int i = 0; i < getNBins(); ++i ) {
        for (unsigned int j = 0; j < getNEntryPerBin(); ++j) {
          write_mem(ibx, i, data, j);
        }
      }
      // Clear nentries8 and binmask8
      for (unsigned int ibin = 0; ibin < getNBins()/8; ++ibin) {
	nentries_[ibx*kNBinsRZ+ibin] = 0;
        nentries8_[ibx][ibin] = 0;
        binmask8_[ibx][ibin] = 0;
      }
    }
  }


  ///////////////////////////////////
  std::vector<std::string> split(const std::string& s, char delimiter)
  {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream sstream(s);
    while (getline(sstream, token, delimiter))
      {
	tokens.push_back(token);
      }
    return tokens;
  }

  // write memory from text file
  bool write_mem(BunchXingT ibx, const std::string& line, int base=16)
  {

    if (isCMSSW) {ibx = 0;}

    std::string datastr = split(line, ' ').back();

    int slot = (int)strtol(split(line, ' ').front().c_str(), nullptr, base); // Convert string (in hexadecimal) to int

    DataType data(datastr.c_str(), base);

    bool success = write_mem(ibx, slot, data, 0);
    return success;
  }


  // print memory contents
  void print_data(const DataType data) const
  {
    edm::LogVerbatim("L1trackHLS") << std::hex << data.raw() << std::endl;
	// TODO: overload '<<' in data class
  }

  void print_entry(BunchXingT bx, ap_uint<NBIT_ADDR> index) const
  {
	print_data(dataarray_[bx][index]);
  }

  void print_mem(BunchXingT bx) const
  {
    for(unsigned int slot=0;slot<8;slot++) {
      for (unsigned int i = 0; i < nentries8_[bx][slot]; ++i) {
	edm::LogVerbatim("L1trackHLS") << bx << " " << i << " ";
	print_entry(bx, i + slot*getNEntryPerBin() );
      }
    }
  }

  void print_mem() const
  {
    for (unsigned int ibx = 0; ibx < kNBxBins; ++ibx) {
      for (unsigned int i = 0; i < 8; ++i) {
	edm::LogVerbatim("L1trackHLS") << ibx << " " << i << " ";
	print_entry(ibx,i);
      }
    }
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
