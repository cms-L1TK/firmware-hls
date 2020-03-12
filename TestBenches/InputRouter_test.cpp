// InputRouter Test
// Sarah.Storey@cern.ch for questions/comments 
#include "hls_stream.h"
#include "InputStubMemory.hh"
#include "InputRouter.hh"
#include "FileReadUtility.hh"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <bitset> 

using namespace std;

int main()
{
  #ifndef __SYNTHESIS__
    std::cout << "SYNTHESIS" << std::endl;
  #endif

  /*
  InputStub<BARREL2S> cBarrel2S;
  InputStub<BARRELPS> cBarrelPS;
  std::cout << "Total number of bits in barrel PS : " << cBarrelPS.kInputStubSize << std::endl;
  std::cout << "Total number of bits in barrel 2S : " << cBarrel2S.kInputStubSize << std::endl;

  InputStub<DISKPS> cDiskPS;
  InputStub<DISK2S> cDisk2S;
  std::cout << "Total number of bits in disk PS : " << cDiskPS.kInputStubSize << std::endl;
  std::cout << "Total number of bits in disk 2S : " << cDisk2S.kInputStubSize << std::endl;
  */

  

  // name is  : DTCtype[PS10G_PS5G_2S]_[DTC_number]_[which tracking nonant: each DTC reads out 2 tracking nonants]
  std::string cInputFile_LinkMap = "IL/dtclinklayerdisk.dat";
  std::map<int, std::pair<std::string ,std::vector<std::uint8_t>>>   cInputMap;
  // memory to store LUT for mapping of DTCs to layers/disks/etc. 
  // 3 bits for layer/disk id  --> 3 bits 
  // 1 bit for barrel/disk --> 4 bits  
  // 1 bit for PS/2S --> 5 bits  
  // up-to 4 layers/disks per DTC
  // 20 bits per link
  // 48 links to TF   
  // memory depth of 12 to store mapping for all input links 

  // memories for stubs 
  // PS barrel 
  InputStubMemory<BARRELPS> hMemory_L1; 
  InputStubMemory<BARRELPS> hMemory_L2;
  InputStubMemory<BARRELPS> hMemory_L3;
  // 2S barrel 
  InputStubMemory<BARREL2S> hMemory_L4; 
  InputStubMemory<BARREL2S> hMemory_L5;
  InputStubMemory<BARREL2S> hMemory_L6; 
  // PS endcap
  InputStubMemory<DISKPS> hMemoryPS_D1; 
  InputStubMemory<DISKPS> hMemoryPS_D2;
  InputStubMemory<DISKPS> hMemoryPS_D3; 
  // 2S endcap  
  InputStubMemory<DISK2S> hMemory2S_D1; 
  InputStubMemory<DISK2S> hMemory2S_D2;
  InputStubMemory<DISK2S> hMemory2S_D3; 
  
  std::cout << "Loading link map into memory .. will be used later" << std::endl;
  std::ifstream fin_il_map;
  if (not openDataFile(fin_il_map,cInputFile_LinkMap)) 
  {
    std::cout << "Could not find file " << cInputFile_LinkMap << std::endl;
    return 0;
  }
  std::cout << "Reading link map from file : " << cInputFile_LinkMap << std::endl;
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
        if( cToken.find("2S") != std::string::npos || cToken.find("PS") != std::string::npos ) 
        {
          if( cToken[0] == 'n')
            cInputMap[cLinkCounter].first = "IL/Link_" + cToken.substr(4, cToken.length()-3) + "_B.dat"; //Link_PS10G_1_A.dat
          else
            cInputMap[cLinkCounter].first = "IL/Link_" + cToken + "_A.dat" ; //Link_PS10G_1_A.dat
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
  auto cLinkIterator = cInputMap.begin();
  // store link map in memory
  // declare output memory arrays to be filled by hls simulation
  DTCMapMemory hLinkMap;
  size_t cIncrement=1;
  for(size_t cIndex=0; cIndex < cInputMap.size(); cIndex++)
  {
    ap_uint<kLINKMAPwidth> cMemoryWord = 0x0000;
    cLinkCounter = std::distance( cInputMap.begin(), cLinkIterator ); 
    uint32_t cWord = 0x00000000; 
    size_t cLayerCounter=0;
    bool cIs2S = ( cLinkIterator->second.first.find("2S") != std::string::npos  ); 
    for( auto cLayerId : cLinkIterator->second.second ) // layer id is either layer number or disk number 
    {
      auto cIsBarrel = (cLayerId<10); 
      cLayerId = (cLayerId < 10 ) ? cLayerId : (cLayerId-10);
      cWord  = cWord | ( ( (cLayerId << 2) | (cIs2S << 1 ) | cIsBarrel ) << 5*cLayerCounter );  
      cLayerCounter++;
    }
    //std::cout << "Link " << +cLinkCounter << " encoded word is " << std::bitset<kLINKMAPwidth>(cWord) << "\n";
    // for( size_t cLayerIndex=0 ; cLayerIndex < cLinkIterator->second.second.size(); cLayerIndex++ )
    // {
    //   ap_uint<5> cLayerEncoding = ( (cWord & (0x1F << cLayerIndex*5)) >> cLayerIndex*5 ); 
    //   ap_uint<1> cIsBarrel = ( cLayerEncoding & 0x01)  ; 
    //   ap_uint<1> cIs2S = ( cLayerEncoding & 0x02) >> 1; 
    //   ap_uint<3> cLayer = ( cLayerEncoding & 0x1C) >> 2;
    //   std::cout << "\t.. layer index " << +cLayerIndex << " word is " << std::bitset<5>(cLayerEncoding) << " ... which is layer " << +cLayer << " 2S bit is " << +cIs2S << " barrel bit is " << +cIsBarrel << "\n";
    // }  
    cMemoryWord = ap_uint<kLINKMAPwidth>( cWord);
    WriteMap(static_cast<int>(cIndex), cMemoryWord, &hLinkMap);
    cLinkIterator++;
  }
  
  
  // read files with stubs .. this is in the 'input' comparison [all c++ ... nothing to do with HLS for the moment]
  LINK cLinkId = 6;
  std::string cInputFile = cInputMap[static_cast<int>(cLinkId)].first;//"IL/Link_PS10G_1_A.dat";
  bool cIs2SDTC = ( cInputFile.find("2S") != std::string::npos  ); 
  std::ifstream fin_il;
  bool validil = openDataFile(fin_il,cInputFile); // what does this do? 
  if (not validil) 
  {
    std::cout << "Could not find file " << cInputFile << std::endl;
    return 0;
  }
  std::cout << "Read-back stubs from file : " << cInputFile << std::endl;

  
  // process the text file .. just regular c++ here 
  char cStubDelimeter = '|';
  char cStubEnd = ' ';
  int  cEventCounter=-1;
  std::string cBxLabel = "BX ";
  int cNevents = 1; 

  int cBxCounter;
  std::map<int, std::vector<std::string>>   cInputStubs;
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
      cInputStubs[cBxCounter].push_back( cInputLine.substr(0, cInputLine.find(cStubEnd)) );
      //cStubString.second = cInputLine.substr(0, cInputLine.find(cStubEnd));
      //cInputStubs.push_back( cStubString );
    }
  }


  // loop over stubs read from file 
  // hls variables start with h 
  BXType hBxCounter;
  // declare input stream to be used in hls simulation
  // note : By default, array variables are implemented as RAM [General arrays are implemented as RAMs for read-write access]
  // but this is not in the test bench 
  //If the data stored in the array is consumed or produced in a sequential manner, a more efficient communication mechanism is to use streaming data as specified by the STREAM pragma, where FIFOs are used instead of RAMs.
  hls::stream<ap_uint<kNBits_DTC> > hIputLink("InputLink_DTC");
  std::cout << "Maximum  number of stubs from one link : " << kMaxStubsFromLink << "\n";
  std::cout << "Encoding into memory connections for LinkId " << +(cLinkId) << " . The DTC connected to this link reads out " << +((cInputMap[cLinkId].second).size()) << " layers." << "\n";
  DTCMap cEncodedMap;
  ReadMap(cLinkId, hLinkMap, cEncodedMap);
  std::cout << "\nMemory word for this link is " << std::bitset<kLINKMAPwidth>(cEncodedMap.raw()) << "\n";

  auto cIterator = cInputStubs.begin();
  while( cIterator != cInputStubs.end() )
  {
    auto cEventCounter = std::distance( cInputStubs.begin(), cIterator ); 
    cBxCounter = cIterator->first;
    auto& cStubs = cIterator->second;

    if( cEventCounter < cNevents )
    {
      std::cout << " Event " << +cEventCounter << " [Bx = " << cBxCounter << "] found " << cStubs.size() << " stubs in input file.\n" ;
      BXType bx = cBxCounter&0x7;
      auto cStubIterator = cStubs.begin(); 
      for( auto cStubIterator = cStubs.begin(); cStubIterator < cStubs.end(); cStubIterator++)
      {
        auto cStubCounter = std::distance( cStubs.begin(), cStubIterator ); 
        auto& cStub = *cStubIterator;
        if( cStubCounter < kMaxStubsFromLink )
        {
          //if( cStubCounter%250 == 0 )
          //std::cout << " \t\t... Stub #" << +cStubCounter << " -- " << std::hex << ap_uint<kNBits_DTC>( cStub.c_str() ,2) << std::dec << "\n";
          //non blocking write into input stream 
          hIputLink.write_nb( ap_uint<kNBits_DTC>( cStub.c_str() ,2) );
        }
        else
        {
          if( cStubCounter == kMaxStubsFromLink) 
            std::cout << "Warning - truncation expected. Stubs from simulation [currently @ stub #" << +cStubCounter << "] exceed maximum allowed on this link.. not passing to input stream.\n";
        }
        // unit under test
        if( !cIs2SDTC )
          InputRouter(cLinkId, hLinkMap, bx, hIputLink, &hMemory_L1, &hMemory_L2, &hMemory_L3, &hMemoryPS_D1, &hMemoryPS_D2, &hMemoryPS_D3);
        else
          InputRouter(cLinkId, hLinkMap, bx, hIputLink, &hMemory_L4, &hMemory_L5, &hMemory_L6, &hMemory2S_D1, &hMemory2S_D2, &hMemory2S_D3);
      }
    }
    cIterator++;
  }
  
  // unit under test
  /*InputRouter(bx,inputlink,&inputstubs0,&inputstubs1,&inputstubs2,&inputstubs3,&inputstubs4,
                 &inputstubs5,&inputstubs6,&inputstubs7,&inputstubs8,&inputstubs9, true);*/

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