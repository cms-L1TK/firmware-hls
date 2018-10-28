#ifndef VMSTUBSMEINNER_HH
#define VMSTUBSMEINNER_HH

#include "Constants.hh"
#include "MemoryBase.hh"

typedef ap_uint<7> VMSTEIID;
typedef ap_uint<3> VMSTEIBEND;
typedef ap_uint<2> VMSTEIFINEPHI;
typedef ap_uint<10> VMSTEIZBITS;
typedef ap_uint<7+3+2+10> VMStubTEInner;

class VMStubsTEInner: public MemoryBase<VMStubTEInner, 2, kMemDepth>
{
public:

  static VMSTEIID get_index(const VMStubTEInner data) {return data.range(21,15);}
  static VMSTEIBEND get_bend(const VMStubTEInner data) {return data.range(14,12);}
  static VMSTEIFINEPHI get_finephi(const VMStubTEInner data) {return data.range(11,10);}
  static VMSTEIZBITS get_zbits(const VMStubTEInner data) {return data.range(9,0);}



#ifndef __SYNTHESIS__
#include <iostream>


#endif

};

#endif
