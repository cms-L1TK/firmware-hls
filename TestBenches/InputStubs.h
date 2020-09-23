#include "FileReadUtility.h"
#include "InputRouterTop.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <map>

//
static const int kMaxLyrsPerDTC = 4; 
// link assignment table 

// TO-BE fixed :  need this added to emData 
static const ap_uint<kLINKMAPwidth> kLinkAssignmentTable[] =
{
  0x500b9, 0x3000b, 0x3000d, 0x5006d, 
  0x50082, 0x500a4, 0x60843, 0x8a623, 
  0x20005, 0x60a62, 0x40047, 0x40087
};

// LUT with phi corrections to the nominal radius. Only used by layers.
// Values are determined by the radius and the bend of the stub.
static const int kPhiCorrtable_L1[] =
#include "../emData/MemPrints/Tables/VMPhiCorrL1.txt"
;
static const int kPhiCorrtable_L2[] =
#include "../emData/MemPrints/Tables/VMPhiCorrL2.txt"
;
static const int kPhiCorrtable_L3[] =
#include "../emData/MemPrints/Tables/VMPhiCorrL3.txt"
;
static const int kPhiCorrtable_L4[] =
#include "../emData/MemPrints/Tables/VMPhiCorrL4.txt"
;
static const int kPhiCorrtable_L5[] =
#include "../emData/MemPrints/Tables/VMPhiCorrL5.txt"
;
static const int kPhiCorrtable_L6[] =
#include "../emData/MemPrints/Tables/VMPhiCorrL6.txt"
;

using namespace std;

// map of input links  [per DTC ]
using LinkMap = std::map<int, std::pair<std::string ,std::vector<std::uint8_t>>> ; 
//map of input stubs [ per Bx ]
using InputStubs = std::map<int, std::vector<std::string>> ; 
//vector of stubs 
using Stubs = std::vector<std::bitset<kNBits_DTC>>; 
// DTC layer map 
typedef std::map<int, std::vector<int>> TkMap;

// create link map
// map is 
// link id [key]
// DTC name [from dtclinklayer]
// then a list of encoded layers 
void createLinkMap(std::string pInputFile_LinkMap, int pDTCsplit, LinkMap& pLinkMap ) 
{
  std::string cBaseName  = "Link_";
  //std::cout << "Loading link map into memory .. will be used later" <<std::endl;
  std::ifstream fin_il_map;
  if (not openDataFile(fin_il_map,pInputFile_LinkMap)) 
  {
    std::cout << "Could not find file " 
      << pInputFile_LinkMap << std::endl;
  }
  // std::cout << "Reading link map from file : " 
  //   << pInputFile_LinkMap << std::endl;
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
          //if( cToken[0] == 'n')
          //{
            //Link_PS10G_1_A.dat
            //pLinkMap[cLinkCounter].first = cBaseName + cToken.substr(4, cToken.length()-3); 
            //pLinkMap[cLinkCounter].first += "_B";
          //}
          //else
            //pLinkMap[cLinkCounter].first = cBaseName + cToken + "_A" ; //Link_PS10G_1_A.dat
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
  //std::cout << "Mapped out " << +pLinkMap.size() << " links." << std::endl;
  
}


// get DTC layer map 
TkMap getLyrLinkMap( std::string pInputCablingMap )
{
	TkMap cMap; 
	TkMap cLyrMap; 

	std::ifstream fin_cblng_map;
	if (not openDataFile(fin_cblng_map,pInputCablingMap)) 
	{
		std::cout << "Could not find file " 
	  	<< pInputCablingMap << std::endl;
	}
	else
	{
		std::vector<int> cTkLyrs; cTkLyrs.clear();
		int cLnkCntr=0;
		// loop over lines from file 
		// so I can figure out which layers are readout by
		// which links 
		for(std::string cInputLine; getline( fin_cblng_map, cInputLine ); )
		{
			auto cStream = std::istringstream{cInputLine};
			std::string cToken;
			while (cStream >> cToken) 
			{
				bool cIsAlNum =true;
				for( auto cChar : cToken )
					cIsAlNum = cIsAlNum && std::isalnum(cChar);
				if( cIsAlNum ) // input link name 
				{
					auto cLyrId = std::stoi( cToken);
			        if(cLyrId != -1 )
			        {
			        	cMap[cLnkCntr].push_back( cLyrId );
			        	if( std::find( cTkLyrs.begin(), cTkLyrs.end(), cLyrId ) == cTkLyrs.end() ) 
			        		cTkLyrs.push_back( cLyrId );
			        }
				}// lyrs 
			}// parse line 
			cLnkCntr++;
		}// lines in cabling map 

		// sort tk layers 
		std::sort(cTkLyrs.begin(), cTkLyrs.end());
		// assign links from DTCs to layers 
		for( auto cTkLyr : cTkLyrs )
		{
			for( auto cItm : cMap )
		  	{
		  		auto cLyrs = cItm.second; 
		  		// std::cout << +cLyrs.size()
		  		// 	<< " layer(s) connected to link " 
		  		// 	<< cItm.first 
		  		// 	<< "\n";
		  		for( auto cLyr : cLyrs ) 
		  		{
		  			if( cLyr != cTkLyr )
		  				continue;
		  			// first .. check if layer is already in map 
		  			auto cInMap = cLyrMap.find(cLyr); 
		  			if( cInMap == cLyrMap.end() )
		  			{
		  				cLyrMap[cLyr].clear();
		  				cLyrMap[cLyr].push_back( cItm.first );
		  			}
		  			else 
		  			{
		  				auto cFound = std::find( cLyrMap[cLyr].begin() , cLyrMap[cLyr].end(), cItm.first );
		  				if( cFound == cLyrMap[cLyr].end() )
		  					cLyrMap[cLyr].push_back(  cItm.first  );
		  			}
		  		}
		  	} // link loop 
		}// lyr loop 
  	}//valid file 
	return cLyrMap;
}


// get link id from map .. 
void getLinkId(LinkMap pInputMap, std::string pDTC, int &pLinkId)
{
  bool cFound=false;
  auto cMapIterator = pInputMap.begin();
  do
  {
    auto cDTCname = (*cMapIterator).second.first;
    auto cLayers = (*cMapIterator).second.second;
    if( cDTCname.find(pDTC) != std::string::npos  ) 
      cFound=true;
    else
      cMapIterator++;
  }while(!cFound && cMapIterator != pInputMap.end());
  assert( cFound ); 
  pLinkId = (cFound)? (*cMapIterator).first : -1;  
}

// get link information 
// memory to store LUT for mapping of DTCs to layers/disks/etc. 
// 3 bits for layer/disk id  --> 3 bits 
// 1 bit for barrel/disk --> 4 bits  
// up-to 4 layers/disks per DTC
// 16 bits per link
// then 3 bits 
// 1 bit to assign whether link is PS/2S 
// 3 bits to encode the number of layers readout by this DTC 
// 20 bits in total 
void getLinkInfo(LinkMap pInputMap, int pLinkId, 
  ap_uint<kLINKMAPwidth>& pLinkWord)
{
  // read files with stubs .. this is in the 'input' comparison [all c++ ... nothing to do with HLS for the moment]
  // figure out DTC map encoding for this link 
  pLinkWord = 0x0000;
  uint32_t cWord = 0x00000000; 
  int cIs2S = ( pInputMap[static_cast<int>(pLinkId)].first.find("2S") != std::string::npos  ) ? 1 : 0 ; 
  auto cLayerIterator = pInputMap[static_cast<int>(pLinkId)].second.begin();
  int cNLyrs=0;
  bool cFirstLayer=false;
  while( cLayerIterator <  pInputMap[static_cast<int>(pLinkId)].second.end() ) // layer id is either layer number or disk number 
  {
    auto cLayerCounter = std::distance( pInputMap[static_cast<int>(pLinkId)].second.begin(), cLayerIterator ); 
    size_t cLayerId =  *cLayerIterator;

    auto cIsBarrel = (cLayerId<10); 
    cLayerId = (cLayerId < 10 ) ? cLayerId : (cLayerId-10);
    cWord  = cWord | ( ( (cLayerId << 1) | cIsBarrel ) << 4*cLayerCounter );  
    if( cLayerId == 1 && cIsBarrel == 1) // first barrel layer is special ...
      cFirstLayer = true;
    cNLyrs++;
    cLayerIterator++;
  }
  cWord = (cNLyrs << 17) | ( cIs2S << 16) | cWord ;
  pLinkWord = ap_uint<kLINKMAPwidth>( cWord);
  if( IR_DEBUG )
  {
    std::cout  << "DTC " << pInputMap[static_cast<int>(pLinkId)].first 
      << " Link " << +pLinkId
      << " -- DTC map encoded word is " 
      << std::bitset<kLINKMAPwidth>(pLinkWord) 
      << " -- "
      << std::hex 
      << +pLinkWord 
      << std::dec 
      << " Is2S bit is set to " << +cIs2S
      << " which is " << +(pLinkWord.range(kLINKMAPwidth-1,kLINKMAPwidth-3))
      << " layers"
      << "\n";
  }
}


// get stubs from emulation file 
// get stubs from file 
bool getStubs(std::string pDTC , InputStubs& pInputStubs)
{
  std::string cBaseName  = "emData/MemPrints/InputStubs/";
  //std::string cBaseName  = "emData/MemPrints/InputStubs/Link_";
  std::string cInputFile = cBaseName + pDTC + ".dat";
  pInputStubs.clear();
  std::ifstream fin_il;
  bool validil = openDataFile(fin_il,cInputFile); // what does this do? 
  if (not validil) 
  {
    std::cout << "Could not find file " << cInputFile << std::endl;
    return false;
  }
  if( IR_DEBUG ) std::cout << "Read-back stubs from file : " << cInputFile << std::endl;
  
  // process the text file .. just regular c++ here 
  char cStubDelimeter = '|';
  char cStubEnd = ' ';
  int  cEventCounter=-1;
  std::string cBxLabel = "BX ";
  int cNevents = 1; 
  int cModBx = -1;
  int cBxCounter=0;
  for(std::string cInputLine; getline( fin_il, cInputLine ); )
  {
    if( cInputLine.find("Event") != std::string::npos ) 
    {
		//cStubString.first = cInputLine.substr(cInputLine.find(cBxLabel)+cBxLabel.length(), 3 ) ;
		cBxCounter = std::stoi( cInputLine.substr(cInputLine.find(cBxLabel)+cBxLabel.length(), 3 ) , nullptr,2 );
		cEventCounter++;
		cModBx++;
	}
    else
    {
      // clean up string to access stub from this event 
      cInputLine.erase( std::remove(cInputLine.begin(), cInputLine.end(), cStubDelimeter), cInputLine.end() );
      pInputStubs[cModBx].push_back( cInputLine.substr(0, cInputLine.find(cStubEnd)) );
      //cStubString.second = cInputLine.substr(0, cInputLine.find(cStubEnd));
      //cInputStubs.push_back( cStubString );
    }
  }
  return true;
}

// get stubs for bx 
void readStubs(std::string pLinkFile, int pBxSelected, ap_uint<kNBits_DTC> *pStubs) 
{
  // get stubs + fill memories with IR process 
  InputStubs cInputStubs;
  getStubs(pLinkFile , cInputStubs);
  for( int cBx = pBxSelected ; cBx < pBxSelected+1 ; cBx++)
  {
    auto& cStubs = cInputStubs[cBx];
    for( auto cStubIter = cStubs.begin(); cStubIter < cStubs.end(); cStubIter++)
    {
    	auto cStubCounter = std::distance( cStubs.begin(), cStubIter ); 
      	auto& cStub = *cStubIter;
      	pStubs[cStubCounter]=ap_uint<kNBits_DTC>( std::bitset<kNBits_DTC>( cStub.c_str() ).to_ulong()) ;
    }
  }
}

// compare memory with emulation 
std::string getMemPrint(std::string pDTC
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

std::string getDTCName( int pLinkId
	, int pDTCsplit = 0 
	, std::string pInputFile_LinkMap = "emData/dtclinklayerdisk.dat")
{
	
	std::string cBaseName = "Link_"; 
	std::string cLinkName = getLinkName( pLinkId, pDTCsplit, pInputFile_LinkMap);
	std::string cDTCName  = cLinkName.substr(cLinkName.find(cBaseName)+cBaseName.length(), cLinkName.length() - cBaseName.length()) ; 
	return cDTCName;
}

// fill from input files 
void fillInputStubs(ap_uint<kNBits_DTC> *pStubs 
, int pLinkId
, int pBxSelected 
, int pDTCsplit = 0 
, std::string pInputFile_LinkMap = "emData/dtclinklayerdisk.dat")
{

	// get link Id 
	std::string cLinkName = getLinkName( pLinkId, pDTCsplit , pInputFile_LinkMap); 
	std::cout << "Link " << cLinkName << " is link#" <<  pLinkId << std::endl;

	// // first prepare array 
	for( int cIndx=0; cIndx < kMaxStubsFromLink; cIndx++)
	{
		pStubs[cIndx]=ap_uint<kNBits_DTC>(0);
	}
	// then fill array with 
	// stubs from emulation 
	// for a given Bx [Event# in the file from emulatin]
	readStubs( cLinkName , pBxSelected, pStubs ) ;
}

// process stubs 
void procInputRouter(DTCStubMemory *hMemories
  , int pLinkId 
  , int pBxSelected 
  , ap_uint<kNBits_DTC> *pStubs )
{

	ap_uint<6> hLinkId(pLinkId);
	ap_uint<kLINKMAPwidth> hLinkWord = 0x00;
	hLinkWord = kLinkAssignmentTable[hLinkId%12];
	ap_uint<1> hIs2S = hLinkWord.range(kLINKMAPwidth-3,kLINKMAPwidth-4);
	std::cout << "Link Word is " 
	<< std::bitset<kLINKMAPwidth>(hLinkWord)
	<< "\t"
	<< std::hex
	<< hLinkWord 
	<< std::dec
	<< "\n";

	// BxId  
	BXType hBx = pBxSelected&0x7;

	InputRouterTop( hBx
		, hLinkId 
		, kLinkAssignmentTable
		, kPhiCorrtable_L1 
		, kPhiCorrtable_L2
		, kPhiCorrtable_L3
		, kPhiCorrtable_L4
		, kPhiCorrtable_L5
		, kPhiCorrtable_L6
		, pStubs 
		, hMemories);
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
		ap_uint<4> hWrd = hLinkWord.range(4*cLyrIndx+3,4*cLyrIndx);
		if( hWrd == 0) continue;
		ap_uint<1> hIsBrl = hWrd.range(1,0);
		ap_uint<3> hLyrId = hWrd.range(3,1);
		// then over phi bins
		int cNPhiBns = ( (hIs2S==0) && hLyrId==1 && hIsBrl) ? 8 : 4; 
		for( int cPhiBn=0; cPhiBn<cNPhiBns; cPhiBn++)
		{
			std::string cMemPrint = getMemPrint(cDTCName ,cLyrIndx, cPhiBn, pNonant, hLinkWord);
			if( !cMemPrint.empty() )
			{
        std::cout << "Loading stubs from .. " << cMemPrint << "\n";
				openDataFile(pInputStreams[cMemIndx],cMemPrint); 
			}
			cMemIndx++;
		}
	}
}

// check HLS against emulation 
template< class DataType, int nMemories>
int verifyHLS( int pBxId 
  , DataType* hMemories
  , DataType* hRefMemories
  , bool pTruncated=false )
{

  BXType hBx = pBxId&0x7;
  int cTotalErrorCount=0;
  std::vector<int> cErrorCount(0);
  for(int cMemIndx=0; cMemIndx< nMemories; cMemIndx++)
  {
    if( hRefMemories[cMemIndx].getEntries(hBx) == 0  ) continue;

    std::cout << dec 
      << "Comparing stubs from memory#" 
      << +cMemIndx 
      << " found "
      << +hMemories[cMemIndx].getEntries(hBx) 
      << " entries in memory produced by the HLS...and "
      << +hRefMemories[cMemIndx].getEntries(hBx) 
      << " entries in memory produced by emulation.\n";

    int cNerrors = compareMems<DTCStubMemory,16>(hRefMemories[cMemIndx], hMemories[cMemIndx] , pBxId  , "DTCStubMemory" , pTruncated );
    cErrorCount.push_back( cNerrors );
  }//lyrs
  cTotalErrorCount += std::accumulate(cErrorCount.begin(), cErrorCount.end(), 0);
  return cTotalErrorCount;
}


// pInputFile_LinkMap dtc link layer map 
// pDTCsplit - which half of the cabling nonant 
// pNonant - which cabling nonant 
int simInputRouter(DTCStubMemory *hMemories
  , bool& pTruncated
  , int pLinkId = 0 
  , std::string pInputFile_LinkMap = "emData/dtclinklayerdisk.dat"
  , int pFirstBx = 0 
  , int pLastBx = 12
  , int pDTCsplit = 0 
  , int pNonant = 4  )
{

  // prepare input streams 
  ifstream cInputStreams[kNIRMemories];
  prepareInputStreams( cInputStreams
	  , pLinkId
	  , pDTCsplit
	  , pNonant 
	  , pInputFile_LinkMap );

  
  // declare reference memories 
  DTCStubMemory hRefMems[kNIRMemories]; 
  // declare reference memories that are 
  // checked against inputs 
  // these will be used to verify the HLS 
  DTCStubMemory hVrfRefMems[kNIRMemories]; 
  // book keeping 
  std::vector<int> cErrorCount(0);
  std::vector<int> cPhiMissing(0);
  std::vector<int> cMemIndxMissing(0);
  // loop over events 
  for( int cBxId=pFirstBx; cBxId < pLastBx ; cBxId++)
  {
    // BxId  
    BXType hBx = cBxId&0x7;

    std::cout << "Processing input router , Bx# " << +cBxId << "\n";
    // get stubs from input file 
    ap_uint<kNBits_DTC> cStubs[kMaxStubsFromLink];
    fillInputStubs(cStubs, pLinkId,  cBxId 
    	, pDTCsplit
    	, pInputFile_LinkMap );

    // fill reference memories
    for( int cMemIndx=0; cMemIndx < kNIRMemories; cMemIndx++ )
    {
      if( !cInputStreams[cMemIndx].is_open() ) continue; 
      
      getFromFile<DTCStubMemory,2>(hRefMems[cMemIndx], cInputStreams[cMemIndx] ,cBxId );
      // reset input file stream back to the start 
      cInputStreams[cMemIndx].clear();
      cInputStreams[cMemIndx].seekg (0, ios::beg);
    }
    
    // process 
    procInputRouter(hMemories , pLinkId  , cBxId , cStubs ); 

    // check if all these entries are in the emulated memory  
    // also appear in the file with the input stubs 
    for( int cMemIndx=0; cMemIndx < kNIRMemories; cMemIndx++ )
    {
      if( hRefMems[cMemIndx].getEntries(hBx) == 0 ) continue; 
      
      // clear memory 
      hVrfRefMems[cMemIndx].clear(hBx);
      for( int cIndx=0; cIndx <  hRefMems[cMemIndx].getEntries(hBx); cIndx++ ) 
      {
        auto cRaw = hRefMems[cMemIndx].read_mem(hBx, cIndx).raw();
        ap_uint<1> cFound=0;
        for( auto cStub : cStubs ) 
        {
          if( cStub == 0x00 ) continue;
          if( cStub.range(kBRAMwidth-1,0) == cRaw ){
            cFound=1;
            std::stringstream ss;
            ss << hex << (long long)(cStub.range(kBRAMwidth-1,0)) << dec ;
            if( IR_DEBUG )
            {
              std::cout << hex << cStub.range(kBRAMwidth-1,0)
                << " "
                << ss.str() 
                << std::dec << "\n";
            }
            hVrfRefMems[cMemIndx].write_mem(hBx, ss.str());
          } 
        } 
        if( cFound == 0  && cMemIndx < 8  )
        {
          AllStub<BARRELPS> hStub( cRaw );
          cPhiMissing.push_back( hStub.getPhi() );
          cMemIndxMissing.push_back( cMemIndx );
        }
      }// loop over memory entries  from emulation reference 
      if( IR_DEBUG )
      {
        std::cout << "Mem#" << +cMemIndx 
         << " has been filled with " << +hRefMems[cMemIndx].getEntries(hBx)
         << " in emulator...."
         << " reference used for comparison has " 
         << +hVrfRefMems[cMemIndx].getEntries(hBx)
         << " entries. This has been checked against input!!! \n";
      }
    }
    
    // verify HLS  
    int cNerrors = verifyHLS<DTCStubMemory, kNIRMemories>( cBxId ,hMemories
      , hVrfRefMems, pTruncated ); 
    cErrorCount.push_back( cNerrors );
  }// loop over Bx Ids 
    
  // close streams
  for( int cMemIndx = 0 ; cMemIndx < kNIRMemories ; cMemIndx ++ )
  {
  	if( !cInputStreams[cMemIndx].is_open() ) continue;
  	cInputStreams[cMemIndx].close();
  }

  // report missing stubs [ref vs. input ]  
  if(IR_DEBUG)
  {
    int cIndx=0;
    for(auto cMissing : cPhiMissing )
    {
      std::cout <<  std::dec 
        << " Missing Barrel PS stub, layer 1 with phi value "
        << cMissing << " from emulated memory#" 
        << +cMemIndxMissing[cIndx] 
        << " which is phi bin " 
        << cMissing/(16383./8.) << "\n";
      cIndx++;  
    }
  }
  // return error count 
  return std::accumulate(cErrorCount.begin(), cErrorCount.end(), 0);  
}