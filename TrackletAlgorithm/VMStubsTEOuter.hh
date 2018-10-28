#ifndef VMSTUBSMEOUTER_HH
#define VMSTUBSMEOUTER_HH

#include "Constants.hh"
#include "MemoryBaseBinned.hh"

typedef ap_uint<7> VMSTEOID;
typedef ap_uint<4> VMSTEOFINEZ;
typedef ap_uint<3> VMSTEOFINEPHI;
typedef ap_uint<3> VMSTEOBEND;
typedef ap_uint<7+4+3+3> VMStubTEOuter;


//template<unsigned int bx=2, unsigned int memdepth=kMemDepth>
class VMStubsTEOuter: public MemoryBaseBinned<VMStubTEOuter, 2, kMemDepth>
{
public:

  static VMSTEOID get_index(const VMStubTEOuter data) {return data.range(15,9);}
  static VMSTEOBEND get_bend(const VMStubTEOuter data) {return data.range(8,6);}
  static VMSTEOFINEPHI get_finephi(const VMStubTEOuter data) {return data.range(5,3);}
  static VMSTEOFINEZ get_finez(const VMStubTEOuter data) {return data.range(2,0);}

#ifndef __SYNTHESIS__
#include <iostream>

#endif

};

#endif
