#ifndef VMSTUBS_HH
#define VMSTUBS_HH

#include "Constants.hh"
#include "MemoryBaseBinned.hh"

typedef ap_uint<7> VMPID;
typedef ap_uint<4> VMPFINEZ;
typedef ap_uint<3> VMBEND;
typedef ap_uint<7+4+3> VMStub;


//template<unsigned int bx=2, unsigned int memdepth=kMemDepth>
class VMStubs: public MemoryBaseBinned<VMStub, 2, kMemDepth>
{
public:

  static VMPID get_index(const VMStub data) {return data.range(13,7);}
  static VMPFINEZ get_finez(const VMProj data) {return data.range(3,0);}
  static VMPBEND get_bend(const VMProj data) {return data.range(6,4);}

#ifndef __SYNTHESIS__
#include <iostream>

#endif

};

#endif
