// ProjectionRouter test bench
#include "MatchProcessorTopL3.h"
#include "CandidateMatchMemory.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
#include "VMStubMEMemoryCM.h"
#include "FileReadUtility.h"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

const int nevents = 100;  // number of events to run

using namespace std;



int main() {
  // error counter
  int err_count = 0;

  // input memories
  static TrackletProjectionMemory<BARRELPS> tproj1;
  static TrackletProjectionMemory<BARRELPS> tproj2;
  static TrackletProjectionMemory<BARRELPS> tproj3;
  static TrackletProjectionMemory<BARRELPS> tproj4;
  static TrackletProjectionMemory<BARRELPS> tproj5;
  static TrackletProjectionMemory<BARRELPS> tproj6;
  static TrackletProjectionMemory<BARRELPS> tproj7;
  static TrackletProjectionMemory<BARRELPS> tproj8;
  static TrackletProjectionMemory<BARRELPS> tproj9;
  static TrackletProjectionMemory<BARRELPS> tproj10;
  static AllStubMemory<BARRELPS>        allstub;

  VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines> inputvmstubs;

  // declare output memory array to be filled by hls simulation
  static FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies];

  ap_uint<8>* valid;

  // open input files
  cout << "Open files..." << endl;

  ifstream fin_tproj1;
  ifstream fin_tproj2;
  ifstream fin_tproj3;
  ifstream fin_tproj4;
  ifstream fin_tproj5;
  ifstream fin_tproj6;
  ifstream fin_tproj7;
  ifstream fin_tproj8;
  ifstream fin_tproj9;
  ifstream fin_tproj10;
  ifstream fin_as;
  //ifstream fout_ap;

  if (not openDataFile(fin_tproj1, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2E_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj2, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2F_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj3, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2G_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj4, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2H_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj5, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2I_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj6, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2J_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj7, "MP_L3PHIC/TrackletProjections_TPROJ_L1L2K_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj8, "MP_L3PHIC/TrackletProjections_TPROJ_L5L6B_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj9, "MP_L3PHIC/TrackletProjections_TPROJ_L5L6C_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj10, "MP_L3PHIC/TrackletProjections_TPROJ_L5L6D_L3PHIC_04.dat")) return -1;

  ifstream fin_vmstub;

  bool validvmstub = openDataFile(fin_vmstub,"MP_L3PHIC/VMStubs_VMSME_L3PHICn1_04.dat");
  if (not validvmstub) return -1;

  if (not openDataFile(fin_as,"MP_L3PHIC/AllStubs_AS_L3PHICn1_04.dat")) return -1;

  // open file(s) with reference results
  ifstream fout_fm1;
  ifstream fout_fm2;
  ifstream fout_fm3;
  ifstream fout_fm4;
  ifstream fout_fm5;
  ifstream fout_fm6;
  ifstream fout_fm7;

  if (not openDataFile(fout_fm1,"MP_L3PHIC/FullMatches_FM_L1L2_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fout_fm3,"MP_L3PHIC/FullMatches_FM_L5L6_L3PHIC_04.dat")) return -1;

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    fullmatch[0].clear();
//    fullmatch[1].clear();
//    fullmatch[2].clear();
    fullmatch[3].clear();
//    fullmatch[4].clear();
//    fullmatch[5].clear();
//    fullmatch[6].clear();
//    fullmatch[7].clear();

    // read event and write to memories
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj1, fin_tproj1, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj2, fin_tproj2, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj3, fin_tproj3, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj4, fin_tproj4, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj5, fin_tproj5, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj6, fin_tproj6, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj7, fin_tproj7, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj8, fin_tproj8, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj9, fin_tproj9, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj10, fin_tproj10, ievt);
    writeMemFromFile<AllStubMemory<BARRELPS> >(allstub, fin_as, ievt);

    writeMemFromFile<VMStubMEMemoryCM<BARRELPS, 3, 3, kNMatchEngines> >(inputvmstubs, fin_vmstub, ievt);

    //set bunch crossing
    BXType bx=ievt;
    BXType bx_out;

    int noutcandmatch = 0;

    // Unit Under Test
    MatchProcessorTopL3(bx,
                        &tproj1, &tproj2, &tproj3, &tproj4,
                        &tproj5, &tproj6, &tproj7, &tproj8,
			&tproj9, &tproj10,
                        inputvmstubs,
                        &allstub,
                        bx_out,
                        fullmatch);

    // compare the computed outputs with the expected ones for the candidate 
    // matches
    bool truncation = false;

    // compare the computed outputs with the expected ones 
    std::cout << "FM: L1L2 seeding" << std::endl;
    compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch[0], fout_fm1, ievt, "FullMatch", truncation);
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch[0], fout_fm1, ievt, "FullMatch", truncation); //FIXME
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch[0], fout_fm1, ievt, "FullMatch", truncation);
    //std::cout << "FM: L3L4 seeding" << std::endl;
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch2, fout_fm2, ievt, "FullMatch", truncation);
    std::cout << "FM: L5L6 seeding" << std::endl;
    compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch[3], fout_fm3, ievt, "FullMatch", truncation);
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch[3], fout_fm3, ievt, "FullMatch", truncation); //FIXME
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch[2], fout_fm3, ievt, "FullMatch", truncation);
    //std::cout << "FM: D1D2 seeding" << std::endl;
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch4, fout_fm4, ievt, "FullMatch", truncation);
    //std::cout << "FM: D3D4 seeding" << std::endl;
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch5, fout_fm5, ievt, "FullMatch", truncation);
    //std::cout << "FM: L1D1 seeding" << std::endl;
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch6, fout_fm6, ievt, "FullMatch", truncation);
    //std::cout << "FM: L2D1 seeding" << std::endl;
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch7, fout_fm7, ievt, "FullMatch", truncation);
    

  }  // end of event loop
  
  // close files
  fin_tproj1.close();
  fin_tproj2.close();
  fin_tproj3.close();
  fin_tproj4.close();
  fin_tproj5.close();
  fin_tproj6.close();
  fin_tproj7.close();
  fin_tproj8.close();
  fin_vmstub.close();

  fout_fm1.close();
  fout_fm2.close();
  fout_fm3.close();
  fout_fm4.close();
  fout_fm5.close();
  fout_fm6.close();
  fout_fm7.close();

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err_count > 255) err_count = 255;
  return err_count;

}
