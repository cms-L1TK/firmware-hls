// InputRouter Test
// Sarah.Storey@cern.ch for questions/comments 
#include "hls_stream.h"
#include "InputStubMemory.hh"
#include "FileReadUtility.hh"

// #include "InputRouter.cc"
#include "InputRouterTop.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <bitset> 

using namespace std;

// map of input links  [per DTC ]
using LinkMap = std::map<int, std::pair<std::string ,std::vector<std::uint8_t>>> ; 
//map of input stubs [ per Bx ]
using InputStubs = std::map<int, std::vector<std::string>> ; 

// get link information 
// memory to store LUT for mapping of DTCs to layers/disks/etc. 
// 3 bits for layer/disk id  --> 3 bits 
// 1 bit for barrel/disk --> 4 bits  
// up-to 4 layers/disks per DTC
// 16 bits per link
// then 2 bits 
// 1 bit to assign whether link is PS/2S 
// 1 bit if it is connected to the very first layer of the tracker or not 
// 18 bits in total per link .. 
// so can fit all links into a BRAM 12 deep ( 36 bits wide )
// for the moment I store them one link per word 
// (so a 36 bit wide bram , 24 deep can be used) 
void getLinkInfo(LinkMap pInputMap, int pLinkId, 
  ap_uint<kLINKMAPwidth>& pLinkWord, std::string& pLinkName )
{
  // read files with stubs .. this is in the 'input' comparison [all c++ ... nothing to do with HLS for the moment]
  // figure out DTC map encoding for this link 
  pLinkWord = 0x0000;
  uint32_t cWord = 0x00000000; 
  bool cIs2S = ( pInputMap[static_cast<int>(pLinkId)].first.find("2S") != std::string::npos  ); 
  auto cLayerIterator = pInputMap[static_cast<int>(pLinkId)].second.begin();
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
    
    cLayerIterator++;
  }
  cWord = cWord | (cFirstLayer << 17) | (cIs2S << 16);
  pLinkWord = ap_uint<kLINKMAPwidth>( cWord);
  std::cout  << "DTC " << pInputMap[static_cast<int>(pLinkId)].first << " Link " << +pLinkId << " -- DTC map encoded word is " << std::bitset<kLINKMAPwidth>(pLinkWord) << "\n";
  pLinkName = pInputMap[static_cast<int>(pLinkId)].first;//"IL/Link_PS10G_1_A.dat";
}
// get stubs from file 
bool getStubs(std::string pInputFile , InputStubs& pInputStubs)
{
  std::ifstream fin_il;
  bool validil = openDataFile(fin_il,pInputFile); // what does this do? 
  if (not validil) 
  {
    std::cout << "Could not find file " << pInputFile << std::endl;
    return false;
  }
  std::cout << "Read-back stubs from file : " << pInputFile << std::endl;

  
  // process the text file .. just regular c++ here 
  char cStubDelimeter = '|';
  char cStubEnd = ' ';
  int  cEventCounter=-1;
  std::string cBxLabel = "BX ";
  int cNevents = 1; 

  int cBxCounter;
  for(std::string cInputLine; getline( fin_il, cInputLine ); )
  {
    if( cInputLine.find("Event") != std::string::npos ) 
    {
      //cStubString.first = cInputLine.substr(cInputLine.find(cBxLabel)+cBxLabel.length(), 3 ) ;
      cBxCounter = std::stoi( cInputLine.substr(cInputLine.find(cBxLabel)+cBxLabel.length(), 3 ) , nullptr,2 );
      cEventCounter++;
    }
    else
    {
      // clean up string to access stub from this event 
      cInputLine.erase( std::remove(cInputLine.begin(), cInputLine.end(), cStubDelimeter), cInputLine.end() );
      pInputStubs[cBxCounter].push_back( cInputLine.substr(0, cInputLine.find(cStubEnd)) );
      //cStubString.second = cInputLine.substr(0, cInputLine.find(cStubEnd));
      //cInputStubs.push_back( cStubString );
    }
  }
  return true;
}

int main()
{
  #ifndef __SYNTHESIS__
    std::cout << "SYNTHESIS" << std::endl;
  #endif

 
  // name is  : 
  // DTCtype[PS10G_PS5G_2S]
  // _[DTC_number]
  // _[which tracking nonant: each DTC reads out 2 tracking nonants]
  std::string cInputFile_LinkMap = "IL/dtclinklayerdisk.dat";
  std::map<int, std::pair<std::string ,std::vector<std::uint8_t>>> cInputMap;
  std::cout << "Loading link map into memory .. will be used later" <<std::endl;
  std::ifstream fin_il_map;
  if (not openDataFile(fin_il_map,cInputFile_LinkMap)) 
  {
    std::cout << "Could not find file " 
      << cInputFile_LinkMap << std::endl;
    return 0;
  }
  std::cout << "Reading link map from file : " 
    << cInputFile_LinkMap << std::endl;
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
          if( cToken[0] == 'n')
          {
            //Link_PS10G_1_A.dat
            cInputMap[cLinkCounter].first = cToken.substr(4, cToken.length()-3); 
            cInputMap[cLinkCounter].first += "_B";
          }
          else
            cInputMap[cLinkCounter].first = cToken + "_A" ; //Link_PS10G_1_A.dat
          std::cout << "Link name : " << cInputMap[cLinkCounter].first << "\n";
        }
      }
      else
      {
        auto cLayerId = std::stoi( cToken);
        if(cLayerId != -1 )
          cInputMap[cLinkCounter].second.push_back( cLayerId );
      }
    }
    cLinkCounter++;
  }
  std::cout << "Mapped out " << +cInputMap.size() << " links." << std::endl;
  

  // memories for stubs 
  // PS memories 
  StubsBarrelPS hBarrelPS;
  StubsDiskPS hDiskPS;
  // 2S memories 
  StubsBarrel2S hBarrel2S;
  StubsDisk2S hDisk2S;

  // test memories .... 
  // in total we have 32 input stub memories for 2S 'stubs'
  IRMemory hMemories2S[kTotal2Smemories]; 
  // in total we have 36 input stub memories for PS 'stubs'
  IRMemory hMemoriesPS[kTotalPSmemories]; 

  // figure out DTC map encoding for this link 
  int cLinkId = 18 ; // PS_10G_1 (neg)
  ap_uint<kLINKMAPwidth> cLinkWord = 0x0000;
  std::string cDTCname = "";
  getLinkInfo(cInputMap, cLinkId, cLinkWord, cDTCname);
  std::string cLinkFile = "IL/IL_" + cDTCname + "/Link_" + cDTCname + ".dat" ;
  std::cout << "DTC name from CMSSW " 
    << cDTCname << " input file is " 
    << cLinkFile << "\n";
  
  // get stubs 
  InputStubs cInputStubs;
  getStubs(cLinkFile , cInputStubs);
  int cBxSelected = 0; 
  for( int cBx = cBxSelected ; cBx < cBxSelected+1 ; cBx++)
  {
    // declare input stream to be used in hls simulation
    hls::stream<ap_uint<kNBits_DTC>> hInputLink;

    // push stubs into stub word vector for this bx 
    std::vector<ap_uint<kNBits_DTC>> cStubWords;
    BXType hBxCounter = cBx&0x7;
    std::cout << "Bx " << hBxCounter << "\n";

    auto& cStubs = cInputStubs[cBx];
    size_t cSize = kMaxStubsFromLink;
    if ( cInputStubs[cBx].size() < kMaxStubsFromLink )
      cSize = cInputStubs[cBx].size();
    ap_uint<kNBits_DTC> *cStubArray = new ap_uint<kNBits_DTC>[cSize];
    for( auto cStubIter = cStubs.begin(); cStubIter < cStubs.end(); cStubIter++)
    {
      auto cStubCounter = std::distance( cStubs.begin(), cStubIter ); 
      auto& cStub = *cStubIter;
      if( cStubCounter < kMaxStubsFromLink )
      {
        // if( cStubCounter%25 == 0 )
        //   std::cout << " \t\t... Stub #" << +cStubCounter 
        //     << " -- " << std::hex << ap_uint<kNBits_DTC>( cStub.c_str() ,2) 
        //     << std::dec << "\n";
        cStubArray[cStubCounter] = ap_uint<kNBits_DTC>( cStub.c_str() ,2) ; 
        hInputLink.write_nb(cStubArray[cStubCounter]);
      }
      else
      {
        if( cStubCounter == kMaxStubsFromLink) 
          std::cout << "Warning - truncation expected!" 
            << "Stubs from simulation [currently @ stub #" << +cStubCounter 
            << "] exceed maximum allowed on this link.."
            << " not passing to input stream.\n";
      }
    }
    // this figures out which memories to write to all by itself
    // .. but its maybe not very elegant 
    // InputRouterGeneric(hBxCounter, (int)cSize , cStubArray, 
    // cLinkWord, hMemoriesPS , hMemories2S);

    // this writes to either the PS or the 2S memories 
    ap_uint<1> cIs2S;
    is2S(cLinkWord, cIs2S);
    if( !cIs2S)
    {
      InputRouterPS(hBxCounter, hInputLink, cLinkWord, hBarrelPS, hDiskPS);
    }
    else
    {
      InputRouter2S(hBxCounter, hInputLink, cLinkWord, hBarrel2S, hDisk2S);
    }
  }
  // to-do : comparison against emulation 

  // Barrel : A, B, C, D 
  // Regions : 0, 1 , 2 ,3 
  //std::vector<std::vector<InputStubMemory>> cStubs(4,vector<int>(20));
  //std::vector<InputStubMemory<BARRELPS>> cStubs; 
  
  // // define nevents
  // int nevents = 1;

  // // error counter
  // int err_count = 0;

  // // declare input stream to be used in hls simulation
  // hls::stream<ap_uint<38> > inputlink;

  // // declare output memory arrays to be filled by hls simulation
  // InputStubMemory<BARRELPS> inputstubs0;
  // InputStubMemory<BARRELPS> inputstubs1;
  // InputStubMemory<BARRELPS> inputstubs2;
  // InputStubMemory<BARRELPS> inputstubs3;
  // InputStubMemory<BARRELPS> inputstubs4;
  // InputStubMemory<BARRELPS> inputstubs5;
  // InputStubMemory<BARRELPS> inputstubs6;
  // InputStubMemory<BARRELPS> inputstubs7;
  // InputStubMemory<BARRELPS> inputstubs8;
  // InputStubMemory<BARRELPS> inputstubs9;

  // // open file with input to unit
  // ifstream fin_il;
  // bool validil = openDataFile(fin_il,"IL/IL_PS10G_1_B/Link_PS10G_1_B.dat");
  // if (not validil) return -1;

  // // open files with reference results
  // ifstream fin_is0;
  // bool validis0 = openDataFile(fin_is0,"IL/IL_PS10G_1_B/InputStubs_IL_L1PHIE_PS10G_1_B_04.dat");
  // if (not validis0) return -1;

  // ifstream fin_is1;
  // bool validis1 = openDataFile(fin_is1,"IL/IL_PS10G_1_B/InputStubs_IL_L1PHIF_PS10G_1_B_04.dat");
  // if (not validis1) return -1;

  // ifstream fin_is2;
  // bool validis2 = openDataFile(fin_is2,"IL/IL_PS10G_1_B/InputStubs_IL_L1PHIG_PS10G_1_B_04.dat");
  // if (not validis2) return -1;

  // ifstream fin_is3;
  // bool validis3 = openDataFile(fin_is3,"IL/IL_PS10G_1_B/InputStubs_IL_L1PHIH_PS10G_1_B_04.dat");
  // if (not validis3) return -1;

  // ifstream fin_is4;
  // bool validis4 = openDataFile(fin_is4,"IL/IL_PS10G_1_B/InputStubs_IL_D2PHIC_PS10G_1_B_04.dat");
  // if (not validis4) return -1;

  // ifstream fin_is5;
  // bool validis5 = openDataFile(fin_is5,"IL/IL_PS10G_1_B/InputStubs_IL_D2PHID_PS10G_1_B_04.dat");
  // if (not validis5) return -1;

  // ifstream fin_is6;
  // bool validis6 = openDataFile(fin_is6,"IL/IL_PS10G_1_B/InputStubs_IL_D4PHIC_PS10G_1_B_04.dat");
  // if (not validis6) return -1;

  // ifstream fin_is7;
  // bool validis7 = openDataFile(fin_is7,"IL/IL_PS10G_1_B/InputStubs_IL_D4PHID_PS10G_1_B_04.dat");
  // if (not validis7) return -1;
  
  // std::string line;
  // std::string teststring;
  // ap_uint<38> test;
  // getline(fin_il,line);

  // // loop over events
  // for (int ievt=0; ievt<nevents; ievt++)
  // {
  //   cout << "Event: " << dec << ievt << endl;

  //   // Write stream from file
  //   while (getline(fin_il,line))
  //   {
  //     if (line.find("Event") != std::string::npos) break;
  //     teststring = "";
  //     for (int i=0; i<line.length(); i++)
  //     {
  //       if (line[i] != '|')
  //       {
  //         teststring += line[i];
  //       }
  //       if (line[i] == ' ')
  //       {
  //         break;
  //       }
  //     }
  //     test = ap_uint<38>(teststring.c_str(),2);
  //     inputlink.write_nb(test);
  //   }

  //   // set bunch crossing
  //   BXType bx=ievt&0x7;

  //   // unit under test
  //   InputRouter(bx,inputlink,&inputstubs0,&inputstubs1,&inputstubs2,&inputstubs3,&inputstubs4,
  //                  &inputstubs5,&inputstubs6,&inputstubs7,&inputstubs8,&inputstubs9, true);

  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs0,fin_is0,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs1,fin_is1,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs2,fin_is2,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs3,fin_is3,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs4,fin_is4,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs5,fin_is5,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs6,fin_is6,ievt,"InputStub");
  //   err_count += compareMemWithFile<InputStubMemory<BARRELPS> >(inputstubs7,fin_is7,ievt,"InputStub");

  // } // end of event loop

  // // close files
  // fin_is0.close();
  // fin_is1.close();
  // fin_is2.close();
  // fin_is3.close();
  // fin_is4.close();
  // fin_is5.close();
  // fin_is6.close();
  // fin_is7.close();

  //return err_count;
  return 0;
}