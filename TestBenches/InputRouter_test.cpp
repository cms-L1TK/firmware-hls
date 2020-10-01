// InputRouter Test
#include "InputStubs.h"

using namespace std;

int main()
{
 
  DTCStubMemory hMemories[kNIRMemories];
  
  bool cTruncated = false;
  int cDTCsplit=1;
  int cNonant=4;
  std::string cInputFile_LinkMap = "emData/dtclinklayerdisk.dat";
 
  //
  int cFirstBx = 0 ;
  int cLastBx = 10;
  // 
  int pLinkId = 6; 
  int cTotalErrorCount = simInputRouter( hMemories
    , cTruncated 
    , pLinkId 
    , cInputFile_LinkMap
    , cFirstBx
    , cLastBx
    , cDTCsplit
    , cNonant); 
  return cTotalErrorCount;
}
