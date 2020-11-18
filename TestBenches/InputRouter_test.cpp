// InputRouter Test
//#include "InputStubs.h"
#include "FileReadUtility.h"
#include "InputRouterTop.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <map>

static const int kMaxLyrsPerDTC = 4; 
static const int kMaxNEvents = 100;  // max number of events to run

// link assignment table 
// TO-BE fixed :  need this added to emData 
// 3 bits for layer/disk id  --> 3 bits 
// 1 bit for barrel/disk --> 4 bits  
// up-to 4 layers/disks per DTC
// 16 bits per link
// then 3 bits 
// 1 bit to assign whether link is PS/2S 
// 3 bits to encode the number of layers readout by this DTC 
// 20 bits in total 
static const ap_uint<kLINKMAPwidth> kLinkAssignmentTable[] =
{
  0x500b9, 0x3000b, 0x3000d, 0x5006d, 
  0x50082, 0x500a4, 0x60843, 0x8a623, 
  0x20005, 0x60a62, 0x40047, 0x40087
};

// number of phi bins read out 
// by each link (kSizeBinWord per layer )
// upto 4 layers per link  
static const ap_uint<kBINMAPwidth> kLinkNPhiBns[] = 
{
  0x01B , 0x003 , 0x003 , 0x01B , 
  0x01B , 0x01B , 0x0DF , 0x6DF , 
  0x003 , 0x0DB , 0x01B , 0x01B 
};

// total number of memoreis 
// readout b each link 
static const ap_uint<kNMEMwidth> kLinkNMemories[] = 
{
   8 ,  4 ,  4 ,  8 , 
   8 ,  8 , 16 , 20 , 
   4 , 12 ,  8 ,  8 
};



// LUT with phi corrections to the nominal radius. Only used by layers.
// Values are determined by the radius and the bend of the stub.
static const int kPhiCorrtable_L1[] =
#include "../emData/LUTs/VMPhiCorrL1.txt"
;
static const int kPhiCorrtable_L2[] =
#include "../emData/LUTs/VMPhiCorrL2.txt"
;
static const int kPhiCorrtable_L3[] =
#include "../emData/LUTs/VMPhiCorrL3.txt"
;
static const int kPhiCorrtable_L4[] =
#include "../emData/LUTs/VMPhiCorrL4.txt"
;
static const int kPhiCorrtable_L5[] =
#include "../emData/LUTs/VMPhiCorrL5.txt"
;
static const int kPhiCorrtable_L6[] =
#include "../emData/LUTs/VMPhiCorrL6.txt"
;

// map of input links  [per DTC ]
using LinkMap = std::map<int, std::pair<std::string ,std::vector<std::uint8_t>>> ; 
//map of input stubs [ per Bx ]
using InputStubs = std::map<int, std::vector<std::string>> ; 
//vector of stubs 
using Stubs = std::vector<std::bitset<kNBits_DTC>>; 
// DTC layer map 
typedef std::map<int, std::vector<int>> TkMap;


using namespace std;

// create link map
// map is 
// link id [key]
// DTC name [from dtclinklayer]
// then a list of encoded layers 
void createLinkMap(std::string pInputCablingMap, int pDTCsplit, LinkMap& pLinkMap ) 
{
  std::string cBaseName  = "Link_";
  //std::cout << "Loading link map into memory .. will be used later" <<std::endl;
  std::ifstream fin_il_map;
  if (not openDataFile(fin_il_map,pInputCablingMap)) 
  {
    std::cout << "Could not find file " 
      << pInputCablingMap << std::endl;
  }
  size_t cLinkCounter=0;
  // parse link map 
  for(std::string cInputLine; getline( fin_il_map, cInputLine ); )
  {
    auto cStream = std::istringstream{cInputLine};
    std::string cToken;
    while (cStream >> cToken) 
    {
      bool cIsAlNum =true;
      for( auto cChar : cToken )
        cIsAlNum = cIsAlNum && std::isalnum(cChar);
      if( !cIsAlNum ) // input link name 
      {
        if( cToken.find("2S") != std::string::npos 
          || cToken.find("PS") != std::string::npos ) 
        {
          pLinkMap[cLinkCounter].first += cBaseName + cToken;
          pLinkMap[cLinkCounter].first += (pDTCsplit==0)?"_A":"_B";
          if( IR_DEBUG)
            std::cout << "Link name : " << pLinkMap[cLinkCounter].first << "\n";
        }
      }
      else
      {
        auto cLayerId = std::stoi( cToken);
        if(cLayerId != -1 )
          pLinkMap[cLinkCounter].second.push_back( cLayerId );
      }
    }
    cLinkCounter++;
  }
}

// return name of link file based on link id 
// link 
std::string getLinkName( int pLinkId
  , int pDTCsplit = 0 
  , std::string pInputFile_LinkMap = "emData/dtclinklayerdisk.dat")
{
  // create link map 
  LinkMap cInputMap;
  createLinkMap(pInputFile_LinkMap, pDTCsplit, cInputMap );
  
  // get link Id 
  std::string cLinkName = cInputMap[pLinkId].first; 
  return cLinkName; 
}

// return name of dtc based on link id 
std::string getDTCName( int pLinkId
  , int pDTCsplit = 0 
  , std::string pInputFile_LinkMap = "emData/dtclinklayerdisk.dat")
{
  
  std::string cBaseName = "Link_"; 
  std::string cLinkName = getLinkName( pLinkId, pDTCsplit, pInputFile_LinkMap);
  std::string cDTCName  = cLinkName.substr(cLinkName.find(cBaseName)+cBaseName.length(), cLinkName.length() - cBaseName.length()) ; 
  return cDTCName;
}

// get name of mem print 
// from emulation 
std::string getMemPrintName(std::string pDTC
  , int pLyrIndx , int pPhiBin , int pNonant
  , ap_uint<kLINKMAPwidth> hLinkWord )
{
  std::string cBaseName  = "emData/MemPrints/InputStubs/InputStubs_IL_";
  if( IR_DEBUG )
    std::cout << "DTC word is " << std::bitset<kLINKMAPwidth>(hLinkWord) << "\n";

  ap_uint<4> cDTCWord = (hLinkWord & (0xF << pLyrIndx*4)) >> (pLyrIndx*4); 
  if( cDTCWord != 0 )
  {
    if( IR_DEBUG )
      std::cout << "Lyr word is " << std::bitset<4>(cDTCWord) << "\n";

    ap_uint<1> cIsBrl = (cDTCWord&0x01); 
    std::string cMemoryPrint = cBaseName;
    cMemoryPrint += (cIsBrl==1) ? "L" : "D";
    uint8_t cLyrId =  (cDTCWord & 0xE) >> 1;
    cMemoryPrint += std::to_string((cLyrId)); 
    std::stringstream ss;
    ss << "PHI" ; 
    ss << static_cast<char>(int('A') + int(pPhiBin));
    ss << "_" << pDTC << "_";
    ss << std::setw(2) << std::setfill('0') << pNonant;
    cMemoryPrint += ss.str() + ".dat";
    ifstream cInputStream;
    if( openDataFile(cInputStream,cMemoryPrint) )
    {
      cInputStream.close();
      if( IR_DEBUG )
      {
        std::cout << "Lyr#" << +pLyrIndx 
          << " Lyr " << +cLyrId
          << " Mem print name " << cMemoryPrint 
          << "\n";
      }
      return cMemoryPrint; 
    }
    else
      return "";
  }     
} 

// prepare file streams 
// containing data from 
// reference memories 
// produced by emulation 
void prepareInputStreams( ifstream * pInputStreams
  , int pLinkId
  , int pDTCsplit = 0 
  , int pNonant = 4 
  , std::string pInputFile_LinkMap = "emData/dtclinklayerdisk.dat" )
{
  std::string cDTCName = getDTCName( pLinkId, pDTCsplit , pInputFile_LinkMap); 
  std::cout << "DTC " << cDTCName << " is link#" <<  pLinkId << std::endl;
  
  ap_uint<kLINKMAPwidth> hLinkWord = kLinkAssignmentTable[pLinkId%12];
  ap_uint<1> hIs2S = hLinkWord.range(kLINKMAPwidth-3,kLINKMAPwidth-4);
  int cMemIndx=0;
  for(int cLyrIndx=0; cLyrIndx< kMaxLyrsPerDTC; cLyrIndx++)
  {
    LnkWrd hWrd = hLinkWord.range(LnkWrd.width*cLyrIndx+LnkWrd.width-1,LnkWrd.width*cLyrIndx);
    if( hWrd == 0) continue;
    BrlBit hIsBrl = hWrd.range(hIsBrl.width, 0);
    TkLyrId hLyrId = hWrd.range(hLyrId.width, hIsBrl.width);
    // then over phi bins
    int cNPhiBns = ( (hIs2S==0) && hLyrId==1 && hIsBrl) ? 8 : 4; 
    for( int cPhiBn=0; cPhiBn<cNPhiBns; cPhiBn++)
    {
      std::string cMemPrint = getMemPrintName(cDTCName ,cLyrIndx, cPhiBn, pNonant, hLinkWord);
      if( !cMemPrint.empty() )
      {
        std::cout << "Loading stubs from .. " << cMemPrint << "\n";
        openDataFile(pInputStreams[cMemIndx],cMemPrint); 
      }
      cMemIndx++;
    }
  }
}

// test bench starts here 
int main()
{
 
  int cDTCsplit=0;
  int cNonant=4;
  std::string cInputFile_LinkMap = "emData/dtclinklayerdisk.dat";
  std::string cBaseName  = "emData/MemPrints/InputStubs/";
  
  //
  int cFirstBx = 0 ;
  int cLastBx = 5;
  // 
  int cLinkId = 6; 
  std::string cLinkName = getLinkName( cLinkId, cDTCsplit , cInputFile_LinkMap); 
  std::string cInputFile_Link = cBaseName + cLinkName + ".dat";
 
  // figure out 
  // how many phi bins 
  // per layer 
  // and how many memories
  // there are in total 
  int cNLyrs=0;
  int cNPhiBnsPerLyr[kMaxLyrsPerDTC];
  int cTotalNMems=0;
  for(int cLyr=0; cLyr < kMaxLyrsPerDTC; cLyr++)
  {
    ap_uint<kBINMAPwidth> hPhBnWord = kLinkNPhiBns[cLinkId%12];
    ap_uint<kSizeBinWord> hBnWrd = hPhBnWord.range(kSizeBinWord * cLyr + (kSizeBinWord-1), kSizeBinWord * cLyr);
    cNLyrs += ( hBnWrd != 0 ) ? 1 : 0 ;
    cNPhiBnsPerLyr[cLyr] =  ( hBnWrd != 0 ) ? int(1 + hBnWrd) : 0 ;
    cTotalNMems +=  ( hBnWrd != 0 ) ? int(1+hBnWrd) : 0;
    std::cout << "Link#"
      << cLinkId
      << " - number of phi bins readout by layer "
      << +cLyr 
      << " is "
      << cNPhiBnsPerLyr[cLyr]
      << " total number of memories will be "
      << cTotalNMems
      << " total number of layers read out is "
      << cNLyrs
      << "\n";
  }
  DTCStubMemory hMemories[cNMemories];
  
  // prepare input streams 
  // those are used to read 
  // reference memory prints 
  // from emulation 
  ifstream cInputStreams[cNMemories];
  prepareInputStreams( cInputStreams
    , cLinkId
    , cDTCsplit
    , cNonant 
    , cInputFile_LinkMap );

  // prepare input stream 
  // used to read stubs arriving 
  // from the DTC on the link 
  // LINK_ file from 
  // emulation 
  std::ifstream cLinkDataStream;
  // check file exists 
  if( !openDataFile(cLinkDataStream,cInputFile_Link ) ) 
    return 1; 

  int cTotalErrCnt=0;
  for( int cEvId=0; cEvId < kMaxNEvents; cEvId++)
  {
    // fill reference output memories 
    // these will be used to compare the 
    // output of the emulation to 
    // the output of the HLS top level 
    // DTCStubMemory hRefMems[cNMemories]; 
    // for( size_t cMemIndx = 0; cMemIndx < cNMemories; cMemIndx++)
    // {
    //   writeMemFromFile<DTCStubMemory>(hRefMems[cMemIndx], cInputStreams[cMemIndx], cEvId);
    // }
    
    
    // only compare the ones I want 
    if( cEvId < cFirstBx || cEvId > cLastBx ) continue;
    
    std::cout << "Event#" << +cEvId << "\n";
    // prepare input stub stream 
    ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink];
    for( size_t cStubIndx=0; cStubIndx < kMaxStubsFromLink; cStubIndx++)
      hInputStubs[cStubIndx]=ap_uint<kNBits_DTC>(0);
    readDataFromFile<ap_uint<kNBits_DTC>>(hInputStubs , cLinkDataStream, cEvId);
    
    // now prepare inputs for IR 
    // top 
    ap_uint<6> hLinkId(cLinkId);
    ap_uint<kLINKMAPwidth> hLinkWord = kLinkAssignmentTable[hLinkId%12];
    ap_uint<kBINMAPwidth> hPhBnWord = kLinkNPhiBns[hLinkId%12];
    ap_uint<kNMEMwidth> hNmemories = kLinkNMemories[hLinkId%12];
    ap_uint<1> hIs2S = hLinkWord.range(kLINKMAPwidth-3,kLINKMAPwidth-4);
    // clear memories 
    for( unsigned int cIndx=0; cIndx < (unsigned int)cTotalNMems ; cIndx++)
    { 
       hMemories[cIndx].clear();
    }
    std::cout << "Link Word is " 
      << std::bitset<kLINKMAPwidth>(hLinkWord)
      << "\t"
      << std::hex
      << hLinkWord 
      << std::dec
      << "\t connected to "
      << hNmemories 
      << " memories."
      << "\n";

    // decode link wrd for this layer
    // figure out which of the LUTs I need 
    const int* cLUT_L1 = (  hIs2S == 1 )  ? kPhiCorrtable_L4 : kPhiCorrtable_L1; 
    const int* cLUT_L2 = (  hIs2S == 1 )  ? kPhiCorrtable_L5 : kPhiCorrtable_L2; 
    const int* cLUT_L3 = (  hIs2S == 1 )  ? kPhiCorrtable_L6 : kPhiCorrtable_L3; 

    BXType hBx = cEvId&0x7;
    InputRouterTop( hBx
      , hLinkId // link id 
      , hLinkWord // input link LUT 
      , hPhBnWord  // n phi bins LUT 
      , hNmemories // number of mems LUT
      , cLUT_L1// corrections frst brl lyr  
      , cLUT_L2 // corrections scnd brl lyr  
      , cLUT_L3 // corrections thrd brl lyr  
      , hInputStubs // input stub stream 
      , hMemories); 

    // compare memories 
    for( size_t cMemIndx = 0; cMemIndx < cTotalNMems; cMemIndx++)
    {
      // for now I exclude the last phi bin 
      // of L1 
      // remove this when modified 
      // emulation data is available 
      if( cLinkId%12 == 6 || cLinkId%12 ==7 ) 
        if( cMemIndx >= 3 ) // for now do not compare edges of L1 
          continue;

      std::cout << "Memory#" 
        << cMemIndx 
        << "\n";
      bool cTruncated=false;
      int cErCnt = compareMemWithFile<DTCStubMemory>(hMemories[cMemIndx], cInputStreams[cMemIndx], cEvId, "DTCStubMemory", cTruncated);
      cTotalErrCnt += cErCnt;
    }

    // reset input file stream back to the start 
    cLinkDataStream.clear();
    cLinkDataStream.seekg (0, ios::beg);
  }

  // place point back to start 
  for( size_t cMemIndx = 0; cMemIndx < cTotalNMems; cMemIndx++)
  {
    cInputStreams[cMemIndx].close();
  }
  cLinkDataStream.close();

  return cTotalErrCnt;
}
