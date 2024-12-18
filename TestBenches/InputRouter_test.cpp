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



static const int kMaxNEvents = 100;  // max number of events to run

// map of dtc names and link ids 
using DtcMap = std::map< std::string, std::vector<uint8_t>> ;
using LnkDsc = std::pair< std::vector<uint8_t> , std::vector<BnWrd>>; 
using LnkPair = std::pair< std::string, LnkDsc>; 
using CablingMap = std::map< int,  LnkPair > ;
using namespace std;

CablingMap getMap( std::string pInputWiresMap )
{
  std::ifstream fin_wiring_map;
  if (not openDataFile(fin_wiring_map,pInputWiresMap)) 
  {
    std::cout << "Could not find file " 
      << pInputWiresMap << std::endl;
  }

  CablingMap cDtcMap;
  std::vector<std::string> cDtcNames;
  for(std::string cInputLine; getline( fin_wiring_map, cInputLine ); )
  {
    auto cStream = std::istringstream{cInputLine};
    std::string cToken;
    std::string cPrevToken = "";
    std::vector<std::string> cTokens;
    // read line 
    // and look for connections where 
    // VMR is the output 
    
    std::string cInputLink = "";
    std::string cVMRMemory = "";
    while (cStream >> cToken) 
    {
      if( cPrevToken.find("output") != std::string::npos 
        && cToken.find("VMR") != std::string::npos ) 
      {
        cVMRMemory=cToken;
      }
      if( cInputLink.empty() ) cInputLink = cToken;
      cPrevToken = cToken; 
    }

    // extract DTC name 
    // and detector region 
    if( !cInputLink.empty() && !cVMRMemory.empty() )
    {
      std::string cDetectorRegion="";
      std::string cDtcName="";

      //std::cout << cInputLink << "\t\t" << cVMRMemory << "\n";
      std::stringstream cLinkNameSS(cInputLink);
      char cSplitToken='_';
      std::string cPrevSubStr="";
      for(std::string cSubStr; getline( cLinkNameSS, cSubStr , cSplitToken ); )  
      {
        //std::cout << "\t..." << cSubStr << "\n";
        if( cPrevSubStr.find("IL") != std::string::npos  && cDetectorRegion.empty() )
          cDetectorRegion = cSubStr;

        if( cPrevSubStr.find(cDetectorRegion) != std::string::npos  && cDtcName.empty() && !cDetectorRegion.empty() )
          cDtcName = cSubStr;

        if ( cPrevSubStr.find(cDtcName) != std::string::npos && !cDtcName.empty() )
          cDtcName += "_" + cSubStr;
        
        cPrevSubStr = cSubStr;
      }
      cDtcName = cDtcName + "_" + cPrevSubStr; 
      // figure out detector layer 
      // figure out detector layer 
      std::string cLyrName  = cDetectorRegion.substr(0, cDetectorRegion.find("PHI")) ;
      uint8_t cLyr = std::stol(  cLyrName.substr(1, cLyrName.length()-1) , nullptr, 10 );
      uint8_t cLayerId = (cLyrName.substr(0,1).find("D") != std::string::npos)  ? (10 + cLyr): cLyr; 
      std::string cPhyName  = cDetectorRegion.substr(cDetectorRegion.find("PHI")+3, 1) ;
      uint8_t cPhyId = (char)(cPhyName[0]) - 'A';
      //std::cout << "\t\t" << cVMRMemory << "\t" << cDtcName << " - " << cDetectorRegion << " - Layer " << +cLayerId << " PhiBn " <<  cPhyName << "\n";
      auto cDtcIter = std::find(cDtcNames.begin(), cDtcNames.end(), cDtcName ) ;
      // detector region printout   
      if( cDtcIter == cDtcNames.end() || cDtcNames.empty() )
      {
        // push back dtc name
        std::cout << "DTC#" << +cDtcNames.size() << "\t" << cDtcName << "\n";
        cDtcNames.push_back( cDtcName );
        std::vector<uint8_t> cLyrs(0); cLyrs.push_back(cLayerId);
        BnWrd cBnWrd(0);cBnWrd.range( cPhyId, cPhyId) = 1; 
        std::vector<BnWrd> cBns; cBns.clear(); cBns.push_back(cBnWrd);
        LnkDsc cLnkDsc;
        cLnkDsc.first = cLyrs; cLnkDsc.second = cBns; 
        LnkPair cPair; 
        cPair.first = cDtcName; cPair.second = cLnkDsc;
        cDtcMap.insert(  std::make_pair(cDtcNames.size() -1 , cPair ) ) ; 
      }
      else
      {
          // map by name 
          auto cIndx = std::distance( cDtcNames.begin(), cDtcIter); 
          auto cIterator =  cDtcMap.find( cIndx );
          if( cIterator != cDtcMap.end() )
          {
            // check if layer is already there 
            auto cPair = cIterator->second; 
            auto cLnkDsc =  cPair.second; 
            auto cLyrs   =  cLnkDsc.first; 
            auto cNBns   =  cLnkDsc.second; 
            auto cLyrIter = std::find( cLyrs.begin(), cLyrs.end(), cLayerId ); 
            if( cLyrIter == cLyrs.end() )
            {
              // std::cout << " found a new layer readout by " <<  cDtcName << "\n";
              cIterator->second.second.first.push_back( cLayerId );
              BnWrd cBnWrd(0);cBnWrd.range( cPhyId, cPhyId) = 1; 
              cIterator->second.second.second.push_back( cBnWrd ); 
            }
            else
            {
              // std::cout << " adding a memory to layer " << cLayerId << "\n";
              cIterator->second.second.second[cNBns.size()-1].range(cPhyId,cPhyId) =1 ; 
            }
          }
      }
    }
  }
  // return map
  return cDtcMap;
}
// get cabling map 
// return link names from 
// wire.dat 
DtcMap getCablingMap( std::string pInputWiresMap )
{
  std::ifstream fin_wiring_map;
  if (not openDataFile(fin_wiring_map,pInputWiresMap)) 
  {
    std::cout << "Could not find file " 
      << pInputWiresMap << std::endl;
  }

  DtcMap cDtcMap;
  std::vector<std::string> cDtcNames;
  for(std::string cInputLine; getline( fin_wiring_map, cInputLine ); )
  {
    auto cStream = std::istringstream{cInputLine};
    std::string cToken;
    std::string cPrevToken = "";
    std::vector<std::string> cTokens;
    // read line 
    // and look for connections where 
    // VMR is the output 
    
    std::string cInputLink = "";
    std::string cVMRMemory = "";
    while (cStream >> cToken) 
    {
      if( cPrevToken.find("output") != std::string::npos 
        && cToken.find("VMR") != std::string::npos ) 
      {
        cVMRMemory=cToken;
      }
      if( cInputLink.empty() ) cInputLink = cToken;
      cPrevToken = cToken; 
    }

    // extract DTC name 
    // and detector region 
    if( !cInputLink.empty() && !cVMRMemory.empty() )
    {
      std::string cDetectorRegion="";
      std::string cDtcName="";

      //std::cout << cInputLink << "\t\t" << cVMRMemory << "\n";
      std::stringstream cLinkNameSS(cInputLink);
      char cSplitToken='_';
      std::string cPrevSubStr="";
      for(std::string cSubStr; getline( cLinkNameSS, cSubStr , cSplitToken ); )  
      {

        //std::cout << "\t..." << cSubStr << "\n";
        if( cPrevSubStr.find("IL") != std::string::npos  && cDetectorRegion.empty() )
          cDetectorRegion = cSubStr;

        if( cPrevSubStr.find(cDetectorRegion) != std::string::npos  && cDtcName.empty() && !cDetectorRegion.empty() )
          cDtcName = cSubStr;

        if ( cPrevSubStr.find(cDtcName) != std::string::npos && !cDtcName.empty() )
          cDtcName += "_" + cSubStr;
        
        cPrevSubStr = cSubStr;
      }
      cDtcName = cDtcName + "_" + cPrevSubStr; 
      // figure out detector layer 
      //std::cout << cInputLink << "\t\t" << cVMRMemory << "\t" << cDtcName << " - " << cDetectorRegion << "\n";
      // figure out detector layer 
      std::string cLyrName  = cDetectorRegion.substr(0, cDetectorRegion.find("PHI")) ;
      uint8_t cLyr = std::stol(  cLyrName.substr(1, cLyrName.length()-1) , nullptr, 10 );
      uint8_t cLayerId = (cLyrName.substr(0,1).find("D") != std::string::npos)  ? (10 + cLyr): cLyr; 
      auto cDtcIter = std::find(cDtcNames.begin(), cDtcNames.end(), cDtcName ) ;
      // detector region printout   
      if( cDtcIter == cDtcNames.end() || cDtcNames.empty() )
      {
        // push back dtc name
        std::cout << "DTC#" << +cDtcNames.size() << "\t" << cDtcName << "\n";
        cDtcNames.push_back( cDtcName );
        std::vector<uint8_t> cLyrs(0); cLyrs.push_back(cLayerId);
        cDtcMap.insert( std::make_pair( cDtcName , cLyrs) ); 
      }
      else
      {
          // map by name 
          auto cNameIterator =  cDtcMap.find( cDtcName );
          if( cNameIterator != cDtcMap.end() )
          {
            // check if layer is already there 
            auto cLyrIter = std::find(cNameIterator->second.begin(), cNameIterator->second.end(), cLayerId ); 
            if( cLyrIter == cNameIterator->second.end() )
            {
              cNameIterator->second.push_back( cLayerId );
            }
          }
      }
    }
  }
  // return map
  return cDtcMap;
}
std::vector<std::string> getLinkNames( CablingMap pDtcMap)
{
  std::vector<std::string> cLinkNames;
  for( auto cItem : pDtcMap )
  {
    cLinkNames.push_back( cItem.second.first );
  } 
  return cLinkNames;
}
// return name of dtc based on link id 
std::string getDTCName( CablingMap pDtcMap, int pLinkId )
{
  return pDtcMap[pLinkId].first;
}

// return layers based on link id 
std::vector<uint8_t> getLyrs( CablingMap pDtcMap, int pLinkId)
{
  return pDtcMap[pLinkId].second.first;
}

// return bn word 
BnWrd getBnWrd( CablingMap pDtcMap, int pLinkId, int pLyr )
{
  BnWrd cBnWrd(0);
  auto cLyrs = getLyrs( pDtcMap, pLinkId); 
  auto cLyrIter = std::find( cLyrs.begin(), cLyrs.end(), pLyr ); 
  if( cLyrIter == cLyrs.end() ) return cBnWrd; 

  auto cIndx = std::distance( cLyrs.begin() ,  cLyrIter );
  return pDtcMap[pLinkId].second.second[cIndx];
}
// return total number of memories filled based on link id 
uint8_t getNMemsPerLyr( CablingMap pDtcMap, int pLinkId, int pLyr )
{
  int cNmems = 0; 
  auto cBnWrd = getBnWrd( pDtcMap, pLinkId,  pLyr );
  for( size_t cPhiBn=0; cPhiBn<kMaxPhiBnsPrLyr; cPhiBn++)
  {
    cNmems += cBnWrd.range(cPhiBn,cPhiBn);
  }
  return cNmems;
}
uint8_t getNMems( CablingMap pDtcMap, int pLinkId )
{
  int cNmems = 0; 
  auto cLyrs = getLyrs( pDtcMap, pLinkId); 
  for( auto cLyr : cLyrs ) 
  {
    cNmems += getNMemsPerLyr(pDtcMap, pLinkId, cLyr);
  }
  return cNmems;
}

// return name of link file based on link id 
// link 
std::string getLinkName( CablingMap pDtcMap
  , int pLinkId
  , int pNonant= 4 )
{
  std::string cDtcName = getDTCName( pDtcMap, pLinkId ); 
  std::string cLinkName = "Link_DL_" + cDtcName + "_0" + std::to_string(pNonant); 
  return cLinkName;
}

std::string getMemPrintName( std::string pDtcName
  , int pNonant  
  , int pLyr 
  , int pPhiBn  ) 
{
  int cLyrCorr = (pLyr<11)? 0 : 10; 
  std::string cLyrId = (pLyr<11) ? "L" : "D";
  cLyrId += std::to_string(pLyr-cLyrCorr); 
    
  std::stringstream ss;
  ss << "PHI" ; 
  ss << static_cast<char>(int('A') + pPhiBn);
  ss << "_" << pDtcName << "_";
  ss << std::setw(2) << std::setfill('0') << pNonant;
  std::string cMemPrint = "InputStubs_IL_";
  cMemPrint += cLyrId + ss.str() + ".dat"; 
  return cMemPrint;
}

using DtcMemWrd = std::pair<int, ap_uint<kBINMAPwidth>>; 
// return number of phi bins 
// connectd to link 
DtcMemWrd getNMemories( CablingMap pDtcMap
  , int pLinkId
  , int pNonant= 4 )
{

  DtcMemWrd cDtcMemWrd;
  std::string cDtcName = getDTCName( pDtcMap, pLinkId ); 
  std::vector<uint8_t> cLyrs = getLyrs( pDtcMap , pLinkId );
  std::cout << "Found " << +cLyrs.size() << " layer(s) readout out by [DTC]" << cDtcName << "\n";
  std::vector<int> cNmems(cLyrs.size(),0);
  ap_uint<kBINMAPwidth> cLinkNPhiBns=0;
  int cOffst=0; 
  for( auto cLyr : cLyrs )
  {
    std::cout << "Looking for memories connected to layer " << +cLyr << "\n";
    auto cBnWrd  = getBnWrd( pDtcMap, pLinkId, cLyr );
    std::vector<int> cPhiBns(0);
    for( size_t cPhiBn=0; cPhiBn<kMaxPhiBnsPrLyr; cPhiBn++)
    {
      cLinkNPhiBns.range(cOffst+cPhiBn,cOffst+cPhiBn) = cBnWrd.range(cPhiBn,cPhiBn);
      if( cBnWrd.range(cPhiBn,cPhiBn) == 1 ) cPhiBns.push_back(cPhiBn);
      /*
      // re-construct file name 
      std::string cFileName = "InputStubs/"; 
      cFileName += getMemPrintName( cDtcName, pNonant, cLyr,  (int)cPhiBn);
      //std::cout << "\tLooking for memory print " << cFileName << "\n";
      std::ifstream fin_mem_prints;
      bool cPrintError=false;
      bool cFileFnd = openDataFile(fin_mem_prints,cFileName,cPrintError);
      if( cFileFnd ){ 
        fin_mem_prints.close();
        cLinkNPhiBns.range(cOffst+cPhiBn,cOffst+cPhiBn) = 1;
        std::cout << "\t\t.. " << cFileName << " Offset is " << cOffst << " : " << std::bitset<kBINMAPwidth>((int)cLinkNPhiBns) << "\n";
        cPhiBns.push_back(cPhiBn);
      }//if file exists
      */ 
    }//all possible phi bins 
    cOffst+= kSizeBinWord;
    int cNmemories=cPhiBns.size();
    auto cIndx= std::distance(cLyrs.begin(), std::find(cLyrs.begin(),cLyrs.end(),cLyr));
    cNmems[cIndx]=cNmemories;
  }
  cDtcMemWrd.first = std::accumulate(cNmems.begin(), cNmems.end(), 0);
  cDtcMemWrd.second = cLinkNPhiBns;
  return cDtcMemWrd;
}

using BnDscs = std::pair< std::vector<uint8_t>, std::vector<uint8_t>>;
BnDscs getBns( CablingMap pDtcMap
  , int pLinkId
  , int pNonant = 4 )
{

  BnDscs cWrd;
  std::string cDtcName = getDTCName( pDtcMap, pLinkId ); 
  std::vector<uint8_t> cLyrs = getLyrs( pDtcMap, pLinkId );
  std::vector<int> cNmems(cLyrs.size(),0);
  std::vector<uint8_t> cBns(0);
  std::vector<uint8_t> cIds(0);
  for( auto cLyr : cLyrs )
  {
    //std::cout << "Lyr:" << +cLyr << "\n";
    for( size_t cPhiBn=0; cPhiBn<kMaxPhiBnsPrLyr; cPhiBn++)
    {
      // re-construct file name 
      std::string cFileName = "InputStubs/"; 
      cFileName += getMemPrintName( cDtcName, pNonant, cLyr,  (int)cPhiBn);
      std::ifstream fin_mem_prints;
      bool cPrintError=false;
      bool cFileFnd = openDataFile(fin_mem_prints,cFileName,cPrintError);
      if( cFileFnd ){ 
        std::cout << cFileName << "\n";
        fin_mem_prints.close();
        cBns.push_back(cPhiBn);
        cIds.push_back(cLyr);
      }//if file exists 
    }//all possible phi bins 
  }//lyrs
  cWrd.first = cIds;
  cWrd.second = cBns;
  return cWrd;
}

// 3 bits for layer/disk id  --> 3 bits 
// 1 bit for barrel/disk --> 4 bits  
// up-to 4 layers/disks per DTC
// 16 bits per link
// then 3 bits 
// 1 bit to assign whether link is PS/2S 
// 3 bits to encode the number of layers readout by this DTC 
// 20 bits in total 
ap_uint<kLINKMAPwidth> getLnkWrd(CablingMap pDtcMap
  , int pLinkId)
{
  std::string cDtcName = getDTCName( pDtcMap, pLinkId ); 
  std::vector<uint8_t> cLyrs = getLyrs( pDtcMap, pLinkId );
  int cOffst=0; 
  ap_uint<kLINKMAPwidth> cLnkWrd=0;
  for( auto cLyr : cLyrs )
  {
    bool cIsBrl = (cLyr<11);
    int cLyrCorr = cIsBrl ? 0 : 10; 
    ap_uint<kSizeLinkWord> cWrd; 
    cWrd.range(0,0) =  (int)cIsBrl;
    cWrd.range(3,1) = cLyr-cLyrCorr;
    cLnkWrd.range(cOffst+kSizeLinkWord-1, cOffst) = (int)cWrd;
    cOffst+= kSizeLinkWord;
    std::cout << "Working - Lyr" << +cLyr << " isBrl " << (int)cIsBrl << " layer corr" << cLyrCorr << "\n";
  }
  bool cIs2S = ( cDtcName.find("2S") != std::string::npos  );
  cLnkWrd.range( kLINKMAPwidth-4,kLINKMAPwidth-4 ) = cIs2S ? 1 : 0 ;
  cLnkWrd.range( kLINKMAPwidth-1, kLINKMAPwidth-3) = cLyrs.size();
  return cLnkWrd;
}
void decodeLnkWrd(ap_uint<kLINKMAPwidth> pLnkWrd)
{
  unsigned int cNlyrs = pLnkWrd.range( kLINKMAPwidth-1, kLINKMAPwidth-1-(3-1));
  unsigned int cIs2S = pLnkWrd.range(kLINKMAPwidth-4,kLINKMAPwidth-4);
  std::cout << "LnkWrd 0x" 
    << std::hex  << int(pLnkWrd) << std::dec 
    << "\t..."
    << cNlyrs << " layers read-out...\t"
    << "Is2S bit is : " << cIs2S << "\n";
  int cOffst=0;
  for(size_t cLyrIndx=0; cLyrIndx < kMaxLyrsPerDTC; cLyrIndx++)
  {
    uint8_t cWrd=pLnkWrd.range(cOffst+kSizeLinkWord-1, cOffst);
    uint8_t cIsBrl=(cWrd&(0x1<<0))>>0;
    uint8_t cLyr=(cWrd&(0x7<<1))>>1;
    if( cLyrIndx < cNlyrs ) 
    {
      std::cout << "\t..LyrWrd#"
        << +cLyrIndx
        << " : 0x"
        << std::hex << +cWrd  << std::dec 
        << "\t\t..Lyr#" << +cLyr 
        << " , isBrl bit " << +cIsBrl << "\n";
    }
    cOffst+=kSizeLinkWord;
  }
}


// prepare file streams 
// containing data from 
// reference memories 
// produced by emulation 
void prepareInputStreams( ifstream * pInputStreams
  , CablingMap pDtcMap
  , int pLinkId 
  , int pNonant = 4 )
{
  // dtc name
  std::string cDtcName = getDTCName( pDtcMap, pLinkId );
  std::cout << "DTC " << cDtcName << " is link#" <<  pLinkId << std::endl;
  
  auto hLinkWord = getLnkWrd(pDtcMap,pLinkId);
  int cMemIndx=0;
  std::vector<uint8_t> cLyrs = getLyrs( pDtcMap , pLinkId );
  for(unsigned int cLyrIndx=0; cLyrIndx< cLyrs.size(); cLyrIndx++)
  {
    ap_uint<kSizeLinkWord> hWrd = hLinkWord.range(kSizeLinkWord*cLyrIndx+kSizeLinkWord-1,kSizeLinkWord*cLyrIndx);
    //if( hWrd == 0) continue;
    ap_uint<1> hIsBrl = hWrd.range(0, 0);
    ap_uint<3> hLyrId = hWrd.range(3, 1);
    // get phi bin 
    int cLyrCorr = (hIsBrl==1) ? 0 : 10; 
    auto cBnWrd  = getBnWrd( pDtcMap, pLinkId, cLyrs[cLyrIndx] );
    for( int cPhiBn=0; cPhiBn< kMaxPhiBnsPrLyr; cPhiBn++)
    {
      if( cBnWrd.range(cPhiBn,cPhiBn) == 0 ) continue;
      
      std::string cFileName = "InputStubs/"; 
      std::string cMemPrint = getMemPrintName( cDtcName, pNonant, hLyrId + cLyrCorr, cPhiBn ); 
      cFileName += cMemPrint;

      std::ifstream fin_mem_prints;
      bool cPrintError=false;
      bool cFileFnd = openDataFile(fin_mem_prints,cFileName,cPrintError);
      if( cFileFnd ){ 
        fin_mem_prints.close();
        std::cout << "\t..Loading stubs from .. " << cFileName 
          << " [Mem# " << +cMemIndx << "]\t"
          << "Layer# " << hLyrId 
          << "[Index=" << hLyrId << "]"
          << " barrel bit is set to "
          << +hIsBrl
          << "\n";
        openDataFile(pInputStreams[cMemIndx],cFileName); 
        cMemIndx++;
      }
    }
  }
}


// test bench starts here 
int main(int argc, char * argv[])
{
  //
  int cFirstBx = 0 ;
  // default values for test bench 
  int cLinkId = 12; 
  int cNonant=4;
  int cLastBx = 999;
  // if cmd line args are passed 
  // parse them and change defaults 
  if( argc > 1 )
  {
    std::cout << "Have passed " << +argc << " arguments to the IR test bench.\n";
    for( size_t cArgIndx=1; cArgIndx < (size_t)argc ; cArgIndx++)
    {
      std::string cArg = argv[cArgIndx];
      if( cArg.find("link") != std::string::npos ) 
      {
        cLinkId  = std::stol( cArg.substr( cArg.find(",")+1 , cArg.length()-1) , nullptr, 10 );
        std::cout << "Link id passed from cmd line is " << cLinkId << "\n";
      }
      if( cArg.find("tkNonant") != std::string::npos ) 
      {
        cNonant  = std::stol( cArg.substr( cArg.find(",")+1 , cArg.length()-1) , nullptr, 10 );
        std::cout << "Tk nonant passed from cmd line is " << cNonant << "\n";
      }
    }
  }
  int cTotalErrCnt=0;

  // allow for truncation memory check [i.e. missing entries can pass check]
  bool cTruncation=false;
  std::string cInputFile_Wires = "LUTsSplit/wires.dat";
  
  auto cMap = getMap( cInputFile_Wires ); 
  // for( uint8_t cLinkIndx=0; cLinkIndx < 20; cLinkIndx++)
  // {
  //   std::cout << "Link#" << +cLinkIndx << " : " << getDTCName( cMap, cLinkIndx ) << "\n";
  // }
  // return 0;
  
  std::string cDtcName = getDTCName( cMap, cLinkId );
  std::cout << "DTC " << cDtcName << " is link#" <<  cLinkId << std::endl;
  uint8_t     cTotalNmems = getNMems( cMap, cLinkId );
  std::cout << "Link#" << cLinkId << " fills " << +cTotalNmems << " output memories." << "\n";
  // link name
  std::string cLinkName = getLinkName( cMap, cLinkId , cNonant ); 
  std::string cBaseName  = "InputStubs/";
  std::string cInputFile_Link = cBaseName + cLinkName + ".dat";
  std::cout << "Input file for Link# " << cLinkId << " is " <<  cInputFile_Link << std::endl;
  // link word
  // auto cLnkWrd = kLinkAssignmentTable[cLinkId%12];
  auto cLnkWrd = getLnkWrd(cMap, cLinkId);
  std::cout << "Word encoding number of layers readout per link is 0x"
    <<  std::hex << int(cLnkWrd)  << std::dec
    <<  "\n";
  // print decoded word to screen 
  decodeLnkWrd(cLnkWrd); 
  
  auto cMemWrd = getNMemories( cMap, cLinkId, cNonant);
  std::cout << "Found " << +cMemWrd.first 
    << " memories connected to this link\t"
    << "Word encoding number of bins readout per link is 0x"
    <<  std::hex << int(cMemWrd.second)  << std::dec
    <<  "\n";
  // int cNmemories = kLinkNMemories[cLinkId%12]
  const unsigned int cNmemories = cMemWrd.first ;
  // ap_uint<kBINMAPwidth> cPhBnWord = kLinkNPhiBns[cLinkId%12];
  ap_uint<kBINMAPwidth> cPhBnWord = cMemWrd.second; 

  
  // prepare memories that will be filled 
  DTCStubMemory hMemories[cNmemories];
  
  // prepare input streams 
  // those are used to read 
  // reference memory prints 
  // from emulation 
  ifstream cInputStreams[cNmemories];
  prepareInputStreams( cInputStreams
    , cMap
    , cLinkId
    , cNonant );

  // prepare input stream 
  // used to read stubs arriving 
  // from the DTC on the link 
  // LINK_ file from 
  // emulation 
  std::ifstream cLinkDataStream;
  // check file exists 
  if( !openDataFile(cLinkDataStream,cInputFile_Link ) ) 
    return 1; 

  // now prepare inputs for IR 
  // ap_uint<kNBitsNLnks> hLinkId = cLinkId;
  // const ap_uint<kLINKMAPwidth> hLinkWord = cLnkWrd;
  // const ap_uint<kBINMAPwidth> hPhBnWord = cPhBnWord;
  //ap_uint<1> hIs2S = hLinkWord.range(kLINKMAPwidth-3,kLINKMAPwidth-4);
  const ap_uint<kNMEMwidth> hNmemories = cNmemories;
  
  std::cout << "IR Module for link#" 
      << +cLinkId
      << " Link Word is " 
      << std::bitset<kLINKMAPwidth>(cLnkWrd)
      << "\t"
      << std::hex
      << cLnkWrd 
      << std::dec
      << " Bin Word is "
      << std::hex 
      << cPhBnWord 
      << std::dec 
      << "\t connected to "
      << cNmemories 
      << " memories."
      << "\n";
  
  // bns 
  std::vector<int> nStubs(cNmemories,0);
  auto cBns= getBns( cMap
    , cLinkId
    , cNonant);
  for( int cEvId=0; cEvId < kMaxNEvents; cEvId++)
  {
    // only compare the ones I want 
    if( cEvId < cFirstBx || cEvId > cLastBx ) continue;
    
    std::cout << "Event#" << std::dec << +cEvId << "\n";
    // prepare input stub stream 
    ap_uint<kNBits_DTC> hInputStubs[kMaxProc];
    for( size_t cStubIndx=0; cStubIndx < kMaxProc; cStubIndx++)
      hInputStubs[cStubIndx]=ap_uint<kNBits_DTC>(0);
    writeArrayFromFile<ap_uint<kNBits_DTC>>(hInputStubs , cLinkDataStream, cEvId);
    
    // clear memories 
    for( unsigned int cIndx=0; cIndx < (unsigned int)hNmemories ; cIndx++)
    { 
       hMemories[cIndx].clear();
       hMemories[cIndx].setWriteBX(cEvId);
    }
    BXType hBx = cEvId&0x7;
    BXType hBx_o; 
    // make sure correct top level function is called for each link
    switch (cLinkId)  
    {
      case 0 : 
        InputRouterTop_IR_DTC_PS10G_1_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 1 : 
        InputRouterTop_IR_DTC_PS10G_1_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 2 :
        InputRouterTop_IR_DTC_PS10G_2_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 3 : 
        InputRouterTop_IR_DTC_PS10G_2_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 4 : 
        InputRouterTop_IR_DTC_PS10G_3_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 5 : 
        InputRouterTop_IR_DTC_PS10G_3_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 6 : 
        InputRouterTop_IR_DTC_PS10G_4_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 7 : 
        InputRouterTop_IR_DTC_PS10G_4_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 8 : 
        InputRouterTop_IR_DTC_PS_1_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 9 : 
        InputRouterTop_IR_DTC_PS_1_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 10 : 
        InputRouterTop_IR_DTC_PS_2_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 11 : 
        InputRouterTop_IR_DTC_PS_2_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 24 : 
        InputRouterTop_IR_DTC_2S_1_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 25 : 
        InputRouterTop_IR_DTC_2S_1_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 26: 
        InputRouterTop_IR_DTC_2S_2_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 27: 
        InputRouterTop_IR_DTC_2S_2_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 28 : 
        InputRouterTop_IR_DTC_2S_3_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 29 : 
        InputRouterTop_IR_DTC_2S_3_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 30 : 
        InputRouterTop_IR_DTC_2S_4_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 31 : 
        InputRouterTop_IR_DTC_2S_4_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 32 : 
        InputRouterTop_IR_DTC_2S_5_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 33 : 
        InputRouterTop_IR_DTC_2S_5_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 34 : 
        InputRouterTop_IR_DTC_2S_6_A( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
      case 35 : 
        InputRouterTop_IR_DTC_2S_6_B( hBx
          , cLnkWrd // input link LUT 
          , cPhBnWord  // n phi bins LUT 
          , hInputStubs // input stub stream 
          , hBx_o // output bx 
          , hMemories);
        break;
    } 
       

    // compare memories 
    std::cout << "Comparing memories for Link#"  << +cLinkId 
          << "\t event#" << +cEvId 
          << "\n";
    for( size_t cMemIndx = 0; cMemIndx < (unsigned int)hNmemories; cMemIndx++)
    {
      int cNstubsFound=0;
      std::cout << "Memory#" << +cMemIndx 
        << "\t reads out modules from layer " << +cBns.first[cMemIndx]  
        << "\t reads stubs from phi bin " << +cBns.second[cMemIndx] 
        << "\n";
      // for( size_t cIndx=0; cIndx < hMemories[cMemIndx].getDepth(); cIndx++)
      // {
      //   auto cEntry = hMemories[cMemIndx].read_mem(hBx,cIndx).raw();
      //   if( cEntry== 0 ) continue;
      //   // std::cout << "\t..Entry#" << +cIndx 
      //   //   << " entry " << std::bitset<kBRAMwidth>(cEntry)
      //   //   << " --- 0x" << std::hex << cEntry << std::dec 
      //   //   << " --- "
      //   //   << "\n" << std::dec ;
      //   cNstubsFound++;
      // }
      nStubs.at(cMemIndx) +=cNstubsFound;
      int cErCnt = compareMemWithFile<DTCStubMemory>(hMemories[cMemIndx], cInputStreams[cMemIndx], cEvId, "DTCStubMemory", cTruncation);
      std::cout << "#### this memory has " << cErCnt << " mismatches.\n";
      cTotalErrCnt += cErCnt;
    }

    // reset input file stream back to the start 
    cLinkDataStream.clear();
    cLinkDataStream.seekg (0, ios::beg);
  }
  // place point back to start 
  for( size_t cMemIndx = 0; cMemIndx < (unsigned int)hNmemories; cMemIndx++)
  {
    cInputStreams[cMemIndx].close();
  }
  cLinkDataStream.close();


  return cTotalErrCnt;
}
