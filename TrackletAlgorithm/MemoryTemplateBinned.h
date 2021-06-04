// Class template for binned memory module
#ifndef TrackletAlgorithm_MemoryTemplateBinned_h
#define TrackletAlgorithm_MemoryTemplateBinned_h

#ifndef __SYNTHESIS__
#include <iostream>
#include <sstream>
#include <vector>
#endif


template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR,
		 unsigned int NBIT_BIN>
// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BX): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX
// (1<<NBIT_ADDR): depth of the memory for each BX
// NBIT_BIN: number of bits used for binning; (1<<NBIT_BIN): number of bins
class MemoryTemplateBinned{
public:
  static constexpr unsigned int kNBitDataAddr = NBIT_ADDR-NBIT_BIN;
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<kNBitDataAddr+1> NEntryT;
  
protected:
  enum BitWidths {
    kNBxBins = 1<<NBIT_BX,
    kNSlots = 1<<NBIT_BIN,
    kNMemDepth = 1<<NBIT_ADDR
  };

  DataType dataarray_[kNBxBins][kNMemDepth];  // data array
  NEntryT nentries_[kNBxBins][kNSlots];     // number of entries
  
public:

  unsigned int getDepth() const {return kNMemDepth;}
  unsigned int getNBX() const {return kNBxBins;}
  unsigned int getNBins() const {return kNSlots;}
  unsigned int getNEntryPerBin() const {return (1<<(kNBitDataAddr));}

  NEntryT getEntries(BunchXingT bx, ap_uint<NBIT_BIN> ibin) const {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	return nentries_[bx][ibin];
  }

  const DataType (&get_mem() const)[1<<NBIT_BX][1<<NBIT_ADDR] {return dataarray_;}

  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_ADDR> index) const
  {
    // TODO: check if valid
    return dataarray_[ibx][index];
  }
  
  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_BIN> slot,
		    ap_uint<NBIT_ADDR> index) const
  {
    // TODO: check if valid
    return dataarray_[ibx][(1<<(kNBitDataAddr))*slot+index];
  }

  bool write_mem(BunchXingT ibx, ap_uint<NBIT_BIN> slot, DataType data, int nentry_ibx)
  {
#pragma HLS inline
	if (nentry_ibx < (1<<(kNBitDataAddr))) {
	  // write address for slot: 1<<(kNBitDataAddr) * slot + nentry_ibx
	  dataarray_[ibx][(1<<(kNBitDataAddr))*slot+nentry_ibx] = data;
    #ifdef CMSSW_GIT_HASH
    nentries_[ibx][slot]++;
    #endif
	  return true;
	}
	else {
#ifndef __SYNTHESIS__
	  std::cout << "Warning out of range" << std::endl;
#endif
	  return false;
	}
  }


  // Methods for C simulation only
#ifndef __SYNTHESIS__
  
  MemoryTemplateBinned()
  {
        clear();
  }

  ~MemoryTemplateBinned(){}

  void clear()
  {
    DataType data("0",16);
    for (size_t ibx=0; ibx<kNBxBins; ++ibx) {
      for (size_t ibin=0; ibin<kNSlots; ++ibin) {
        nentries_[ibx][ibin] = 0;
        for (size_t addr=0; addr<(1<<(kNBitDataAddr)); ++addr) {
          write_mem(ibx,ibin,data,addr);
        }
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
  bool write_mem(BunchXingT bx, const std::string& line, int base=16)
  {

    std::string datastr = split(line, ' ').back();

    int slot = (int)strtol(split(line, ' ').front().c_str(), nullptr, base); // Convert string (in hexadecimal) to int
    // Originally: atoi(split(line, ' ').front().c_str()); but that didn't work for disks with 16 bins

    DataType data(datastr.c_str(), base);
    int nent = nentries_[bx][slot];
    bool success = write_mem(bx, slot, data, nent);
    #ifndef CMSSW_GIT_HASH
    if (success) nentries_[bx][slot] ++;
    #endif
    return success;
  }


  // print memory contents
  void print_data(const DataType data) const
  {
	std::cout << std::hex << data.raw() << std::endl;
	// TODO: overload '<<' in data class
  }

  void print_entry(BunchXingT bx, ap_uint<NBIT_ADDR> index) const
  {
	print_data(dataarray_[bx][index]);
  }

  void print_mem(BunchXingT bx) const
  {
	for(int slot=0;slot<(kNSlots);slot++) {
	  for (int i = 0; i < nentries_[bx][slot]; ++i) {
		std::cout << bx << " " << i << " ";
		print_entry(bx, i + slot*(1<<(kNBitDataAddr)) );
 	  }
	}
  }

  void print_mem() const
  {
	for (int ibx = 0; ibx < (kNBxBins); ++ibx) {
	  for (int i = 0; i < nentries_[ibx]; ++i) {
		std::cout << ibx << " " << i << " ";
		print_entry(ibx,i);
	  }
	}
  }

  static constexpr int getWidth() {return DataType::getWidth();}
  
#endif
  
};

#endif
