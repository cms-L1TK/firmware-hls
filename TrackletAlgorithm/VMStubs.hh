#ifndef VMSTUBS_HH
#define VMSTUBS_HH

#include "Constants.hh"
#include "MemoryBaseBinned.hh"



//template<unsigned int bx=2, unsigned int memdepth=kMemDepth>
class VMStubs {
public:

  typedef ap_uint<7> VMSID;
  typedef ap_uint<3> VMSBEND;
  typedef ap_uint<4> VMSFINEZ;
  typedef ap_uint<7+3+4> VMStub;


  static VMSID get_index(const VMStub data) {return data.range(13,7);}
  static VMSBEND get_bend(const VMStub data) {return data.range(6,4);}
  static VMSFINEZ get_finez(const VMStub data) {return data.range(3,0);}

  MemoryBaseBinned<VMStub, 2, kMemDepth> _mem;

  void clear(int ievt) {_mem.clear(ievt);}
  void write_mem_line(int ievt, std::string line ) {_mem.write_mem_line(ievt,line);}
  ap_uint<4> getEntries(ap_uint<3> bx, ap_uint<3> zbin) const {return _mem.getEntries(bx,zbin);}
  VMStub read_mem(ap_uint<3> bx, unsigned int index) const {return _mem.read_mem(bx,index);}

};

#endif
