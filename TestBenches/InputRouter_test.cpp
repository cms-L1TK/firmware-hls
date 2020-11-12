// InputRouter Test
#include "InputStubs.h"

using namespace std;

int main()
{
 
  
  
  bool cTruncated = false;
  int cDTCsplit=0;
  int cNonant=4;
  std::string cInputFile_LinkMap = "emData/dtclinklayerdisk.dat";
 
  //
  int cFirstBx = 0 ;
  int cLastBx = 1;
  // 
  int pLinkId = 6; 
  DTCStubMemory hMemories[cNMemories];
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
