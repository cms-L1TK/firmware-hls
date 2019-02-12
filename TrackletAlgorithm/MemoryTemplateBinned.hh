// Class template for binned memory module
#ifndef MEMORYTEMPLATEBINNED_HH
#define MEMORYTEMPLATEBINNED_HH

#ifndef __SYNTHESIS__
#include <iostream>
#include <sstream>
#include <vector>
#endif


template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR,
		 unsigned int NBIT_BIN>
// DataType: type of data object stored in the array
// NBIT_BX: number of bits for BX;
// (1<<NBIT_BIN): number of BXs the memory is keeping track of
// NBIT_ADDR: number of bits for memory address space per BX
// (1<<NBIT_ADDR): depth of the memory for each BX
// NBIT_BIN: number of bits used for binning; (1<<NBIT_BIN): number of bins
class MemoryTemplateBinned{
  typedef ap_uint<NBIT_BX> BunchXingT;
  typedef ap_uint<NBIT_ADDR-NBIT_BIN+1> NEntryT;
  
protected:
  enum BitWidths {
    kNBxBins = 1<<NBIT_BX,
    kNSlots = 1<<NBIT_BIN,
    kNMemDepth = 1<<NBIT_ADDR
  };

  DataType dataarray_[kNBxBins][kNMemDepth];  // data array
  NEntryT nentries_[kNBxBins][kNSlots];     // number of entries
  
public:

  MemoryTemplateBinned()
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	clear();
  }
  
  ~MemoryTemplateBinned(){}
  
  void clear()
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	
	for (size_t ibx=0; ibx<(kNBxBins); ++ibx) {
#pragma HLS UNROLL
	  clear(ibx);
	}
  }

  void clear(BunchXingT bx)
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	
	for (unsigned int ibin = 0; ibin < (kNSlots); ++ibin) {
#pragma HLS UNROLL
	  nentries_[bx][ibin] = 0;
	}
  }

  unsigned int getDepth() const {return kNMemDepth;}
  unsigned int getNBX() const {return kNBxBins;}
  unsigned int getNBins() const {return kNSlots;}

  NEntryT getEntries(BunchXingT bx, ap_uint<NBIT_BIN> ibin) const {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	return nentries_[bx][ibin];
  }

  NEntryT getEntries(BunchXingT bx) const {
    NEntryT val = 0;
    for ( auto i = 0; i < getDepth(); ++i ) {
      val += getEntries(bx, i);
    }
    return val;
  }


  DataType* get_mem(BunchXingT ibx) {return dataarray_[ibx];}

  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_ADDR> index) const
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
	// TODO: check if valid
	return dataarray_[ibx][index];
  }
  
  DataType read_mem(BunchXingT ibx, ap_uint<NBIT_BIN> slot,
		    ap_uint<NBIT_ADDR> index) const
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
    // TODO: check if valid
    return dataarray_[ibx][(1<<(NBIT_ADDR-NBIT_BIN))*slot+index];
  }

  bool write_mem(BunchXingT ibx, ap_uint<NBIT_BIN> slot, DataType data)
  {
#pragma HLS ARRAY_PARTITION variable=nentries_ complete dim=0
#pragma HLS dependence variable=nentries_ intra WAR true

	NEntryT nentry_ibx = nentries_[ibx][slot];

	if (nentry_ibx <= (kNMemDepth)) {
	  // write address for slot: 1<<(NBIT_ADDR-NBIT_BIN) * slot + nentry_ibx
	  dataarray_[ibx][(1<<(NBIT_ADDR-NBIT_BIN))*slot+nentry_ibx] = data;
	  nentries_[ibx][slot] = nentry_ibx + 1;
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

    int slot=atoi(split(line, ' ').front().c_str());

    DataType data(datastr.c_str(), base);
    //std::cout << "write_mem slot data : " << slot<<" "<<data << std::endl;
    return write_mem(bx, slot, data);
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
      //std::cout << "slot "<<slot<<" entries "
      //		<<nentries_[bx%NBX].range((slot+1)*4-1,slot*4)<<endl;
      for (int i = 0; i < nentries_[bx][slot]; ++i) {
		std::cout << bx << " " << i << " ";
		print_entry(bx, i + slot*(1<<(NBIT_ADDR-NBIT_BIN)) );
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
  
#endif
  
};

#endif
