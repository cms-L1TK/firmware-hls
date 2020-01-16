// InputRouter Test
#include "hls_stream.h"
#include "InputStubMemory.hh"
#include "InputRouter.hh"
#include "FileReadUtility.hh"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{

  InputStub<BARREL2S> cBarrel2S;
  InputStub<BARRELPS> cBarrelPS;
  std::cout << "Total number of bits in barrel PS : " << cBarrelPS.kInputStubSize << std::endl;
  std::cout << "Total number of bits in barrel 2S : " << cBarrel2S.kInputStubSize << std::endl;

  InputStub<DISKPS> cDiskPS;
  InputStub<DISK2S> cDisk2S;
  std::cout << "Total number of bits in disk PS : " << cDiskPS.kInputStubSize << std::endl;
  std::cout << "Total number of bits in disk 2S : " << cDisk2S.kInputStubSize << std::endl;

  // read files with stubs .. this is in the 'input' comparison [all c++ ... nothing to do with HLS for the moment]
  std::ifstream fin_il;
  std::string cInputFile = "IL/IL_PS10G_1_B/Link_PS10G_1_B.dat";
  bool validil = openDataFile(fin_il,cInputFile); // what does this do? 
  if (not validil) 
  {
    std::cout << "Could not find file " << cInputFile << std::endl;
    return 0;
  }
  std::cout << "Read-back stubs from file : " << cInputFile << std::endl;

  // hls variables start with h 
  BXType hBxCounter;
  // declare input stream to be used in hls simulation
  // note : By default, array variables are implemented as RAM [General arrays are implemented as RAMs for read-write access]
  // but this is not in the test bench 
  //If the data stored in the array is consumed or produced in a sequential manner, a more efficient communication mechanism is to use streaming data as specified by the STREAM pragma, where FIFOs are used instead of RAMs.
  hls::stream<ap_uint<38> > hIputLink;
  
  // process the text file .. just regular c++ here 
  char cStubDelimeter = '|';
  char cStubEnd = ' ';
  int  cEventCounter=-1;
  std::string cBxLabel = "BX ";
  int cNevents = 1; 
  for(std::string cInputLine; getline( fin_il, cInputLine ); )
  {
    if( cEventCounter == cNevents)
      continue;

    if( cInputLine.find("Event") != std::string::npos ) 
    {
      auto cBxString = cInputLine.substr(cInputLine.find(cBxLabel)+cBxLabel.length(), 3 ) ;
      hBxCounter = BXType(cBxString.c_str(),2);
      cEventCounter++;
    }
    else
    {
      // clean up string to access stub from this event 
      cInputLine.erase( std::remove(cInputLine.begin(), cInputLine.end(), cStubDelimeter), cInputLine.end() );
      auto cStubString = cInputLine.substr(0, cInputLine.find(cStubEnd));
      std::cout << "Event " << cEventCounter << " -- read stub from Bx " <<  hBxCounter << " from text file : " << cStubString << " \n"; 
      //hIputLink.write_nb( ap_uint<38>( cInputLine.substr(0, cInputLine.find(cStubEnd)).c_str() ,2) );
    }
  }

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
