#ifndef VMPROJECTIONS_HH
#define VMPROJECTIONS_HH

#include "Constants.hh"
#include "MemoryBase.hh"

typedef ap_uint<7> VMPID;
typedef ap_uint<MEBinsBits+1> VMPZBIN;
typedef ap_uint<4> VMPFINEZ;
typedef ap_uint<5> VMPBEND;
typedef ap_uint<7+MEBinsBits+1+4+5+1> VMProj;

/*
struct VMProjData {
  VMPID   index;
  VMPZBIN zbin;
  VMPFINEZ finez;
  VMPRINV rinv;
  bool PSseed;
};
*/

//template<unsigned int bx=2, unsigned int memdepth=kMemDepth>
class VMProjections: public MemoryBase<VMProj, 2, kMemDepth>
{
public:

  static VMPID get_index(const VMProj data) {return data.range(20,14);}
  static VMPZBIN get_zbin(const VMProj data) {return data.range(13,10);}
  static VMPFINEZ get_finez(const VMProj data) {return data.range(9,6);}
  static VMPBEND get_bend(const VMProj data) {return data.range(5,1);}
  static bool get_PSseed(const VMProj data) {return data.range(0,0);}


  /*
  // overload base class add_mem()
  using MemoryBase<VMProjData, MemDepth>::add_mem;
  // add memory from data string
  bool add_mem(const char* datastr, int base = 16)
  {
	  VMProj data(datastr, base);
	  // convert to struct
	  VMProjData vmproj = {
			  data.range(20,14), // index
			  data.range(13,10), // zbin
			  data.range(9,6),   // finez
			  data.range(5,1),   // rinv
			  data.range(0,0)    // PSseed
	  };

	  return add_mem(vmproj);
  }

  */

#ifndef __SYNTHESIS__
#include <iostream>
  /*
  // print memory contents
  void print_data(const VMProjData& vmprojdata) const
  {
	  VMProj vmproj =
			  (vmprojdata.index,
					  (vmprojdata.zbin,
							  (vmprojdata.finez,
									  (vmprojdata.rinv,vmprojdata.PSseed)
			)));

	  std::cout << std::hex << vmproj << std::endl;
  }
*/

#endif

};

#endif
