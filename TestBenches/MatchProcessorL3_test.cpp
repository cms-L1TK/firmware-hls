// ProjectionRouter test bench
#include "MatchProcessorTopL3.h"
#include "CandidateMatchMemory.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
#include "VMStubMEMemory.h"
#include "FileReadUtility.h"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


const int nevents = 1;  // number of events to run

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
  static AllStubMemory<BARRELPS>        allstub;
  static AllProjectionMemory<BARRELPS>  allproj;

  VMStubMEMemory<BARRELPS,3> inputvmstubs1;
  VMStubMEMemory<BARRELPS,3> inputvmstubs2;
  VMStubMEMemory<BARRELPS,3> inputvmstubs3;
  VMStubMEMemory<BARRELPS,3> inputvmstubs4;
  VMStubMEMemory<BARRELPS,3> inputvmstubs5;
  VMStubMEMemory<BARRELPS,3> inputvmstubs6;
  VMStubMEMemory<BARRELPS,3> inputvmstubs7;
  VMStubMEMemory<BARRELPS,3> inputvmstubs8;

  // declare output memory array to be filled by hls simulation
  static FullMatchMemory<BARREL> fullmatch1;
  static FullMatchMemory<BARREL> fullmatch2;
  static FullMatchMemory<BARREL> fullmatch3;
  static FullMatchMemory<BARREL> fullmatch4;
  static FullMatchMemory<BARREL> fullmatch5;
  static FullMatchMemory<BARREL> fullmatch6;
  static FullMatchMemory<BARREL> fullmatch7;
  static FullMatchMemory<BARREL> fullmatch8;

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
  ifstream fin_as;
  ifstream fin_ap;

  if (not openDataFile(fin_tproj1, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L1L2F_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj2, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L1L2G_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj3, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L1L2H_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj4, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L1L2I_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj5, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L1L2J_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj6, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L5L6B_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj7, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L5L6C_L3PHIC_04.dat")) return -1;
  if (not openDataFile(fin_tproj8, "PR/PR_L3PHIC/TrackletProjections_TPROJ_L5L6D_L3PHIC_04.dat")) return -1;

  ifstream fin_vmstub1, fin_vmstub2, fin_vmstub3, fin_vmstub4, fin_vmstub5, fin_vmstub6, fin_vmstub7, fin_vmstub8;
  bool validvmstub1 = openDataFile(fin_vmstub1,"MP/MP_L3PHIC17/VMStubs_VMSME_L3PHIC17n1_04.dat");
  bool validvmstub2 = openDataFile(fin_vmstub2,"MP/MP_L3PHIC18/VMStubs_VMSME_L3PHIC18n1_04.dat");
  bool validvmstub3 = openDataFile(fin_vmstub3,"MP/MP_L3PHIC19/VMStubs_VMSME_L3PHIC19n1_04.dat");
  bool validvmstub4 = openDataFile(fin_vmstub4,"MP/MP_L3PHIC20/VMStubs_VMSME_L3PHIC20n1_04.dat");
  bool validvmstub5 = openDataFile(fin_vmstub5,"MP/MP_L3PHIC21/VMStubs_VMSME_L3PHIC21n1_04.dat");
  bool validvmstub6 = openDataFile(fin_vmstub6,"MP/MP_L3PHIC22/VMStubs_VMSME_L3PHIC22n1_04.dat");
  bool validvmstub7 = openDataFile(fin_vmstub7,"MP/MP_L3PHIC23/VMStubs_VMSME_L3PHIC23n1_04.dat");
  bool validvmstub8 = openDataFile(fin_vmstub8,"MP/MP_L3PHIC24/VMStubs_VMSME_L3PHIC24n1_04.dat");
  if (not validvmstub1) return -1;
  if (not validvmstub2) return -1;
  if (not validvmstub3) return -1;
  if (not validvmstub4) return -1;
  if (not validvmstub5) return -1;
  if (not validvmstub6) return -1;
  if (not validvmstub7) return -1;
  if (not validvmstub8) return -1;

  if (not openDataFile(fin_as,"MC/MC_L3PHIC/AllStubs_AS_L3PHICn6_04.dat")) return -1;
  if (not openDataFile(fin_ap,"MC/MC_L3PHIC/AllProj_AP_L3PHIC_04.dat")) return -1;

  // open file(s) with reference results
  ifstream fout_fm1;
  ifstream fout_fm2;
  ifstream fout_fm3;
  ifstream fout_fm4;
  ifstream fout_fm5;
  ifstream fout_fm6;
  ifstream fout_fm7;

  if (not openDataFile(fout_fm1,"MC/MC_L3PHIC/FullMatches_FM_L1L2_L3PHIC_04.dat")) return -1;
  //if (not openDataFile(fout_fm2,"MC/MC_L1PHIC/FullMatches_FM_L3L4_L1PHIC_04.dat")) return -1;
  if (not openDataFile(fout_fm3,"MC/MC_L3PHIC/FullMatches_FM_L5L6_L3PHIC_04.dat")) return -1;
  //if (not openDataFile(fout_fm4,"MC/MC_L1PHIC/FullMatches_FM_D1D2_L1PHIC_04.dat")) return -1;
  //if (not openDataFile(fout_fm5,"MC/MC_L1PHIC/FullMatches_FM_D3D4_L1PHIC_04.dat")) return -1;
  //if (not openDataFile(fout_fm6,"")) return -1;
  //if (not openDataFile(fout_fm7,"MC/MC_L1PHIC/FullMatches_FM_L2D1_L1PHIC_04.dat")) return -1;

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj1, fin_tproj1, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj2, fin_tproj2, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj3, fin_tproj3, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj4, fin_tproj4, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj5, fin_tproj5, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj6, fin_tproj6, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj7, fin_tproj7, ievt);
    writeMemFromFile<TrackletProjectionMemory<BARRELPS> >(tproj8, fin_tproj8, ievt);
    writeMemFromFile<AllStubMemory<BARRELPS> >(allstub, fin_as, ievt);
    writeMemFromFile<AllProjectionMemory<BARRELPS> >(allproj, fin_ap, ievt);

    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs1, fin_vmstub1, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs2, fin_vmstub2, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs3, fin_vmstub3, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs4, fin_vmstub4, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs5, fin_vmstub5, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs6, fin_vmstub6, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs7, fin_vmstub7, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS,3> >(inputvmstubs8, fin_vmstub8, ievt);

    //set bunch crossing
    BXType bx=ievt;
    BXType bx_out;

    int noutcandmatch = 0;

    // Unit Under Test
    MatchProcessorTopL3(bx,
                        &tproj1, &tproj2, &tproj3, &tproj4,
                        &tproj5, &tproj6, &tproj7, &tproj8,
                        &inputvmstubs1, &inputvmstubs2, &inputvmstubs3, &inputvmstubs4,
                        &inputvmstubs5, &inputvmstubs6, &inputvmstubs7, &inputvmstubs8,
                        &allstub, &allproj,
                        bx_out,
                        &fullmatch1, &fullmatch2, &fullmatch3, &fullmatch4,
                        &fullmatch5, &fullmatch6, &fullmatch7, &fullmatch8);

    // compare the computed outputs with the expected ones for the candidate 
    // matches
    bool truncation = true;

    /*
    std::cout << "mem content" << std::endl;
    std::cout << "fullmatch1" << std::endl;
    fullmatch1.print_mem();
    std::cout << "fullmatch2" << std::endl;
    fullmatch2.print_mem();
    std::cout << "fullmatch3" << std::endl;
    fullmatch3.print_mem();
    std::cout << "fullmatch4" << std::endl;
    fullmatch4.print_mem();
    std::cout << "fullmatch5" << std::endl;
    fullmatch5.print_mem();
    std::cout << "fullmatch6" << std::endl;
    fullmatch6.print_mem();
    std::cout << "fullmatch7" << std::endl;
    fullmatch7.print_mem();
    std::cout << "fullmatch8" << std::endl;
    fullmatch8.print_mem();
    */
    // compare the computed outputs with the expected ones 
    //std::cout << "FM: L1L2 seeding" << std::endl;
    err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch1, fout_fm1, ievt, "FullMatch", truncation);
    //std::cout << "FM: L3L4 seeding" << std::endl;
    //err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch2, fout_fm2, ievt, "FullMatch", truncation);
    //std::cout << "FM: L5L6 seeding" << std::endl;
    err_count += compareMemWithFile<FullMatchMemory<BARREL> >(fullmatch3, fout_fm3, ievt, "FullMatch", truncation);
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
  fin_vmstub1.close();
  fin_vmstub2.close();
  fin_vmstub3.close();
  fin_vmstub4.close();
  fin_vmstub5.close();
  fin_vmstub6.close();
  fin_vmstub7.close();
  fin_vmstub8.close();

  fout_fm1.close();
  fout_fm2.close();
  fout_fm3.close();
  fout_fm4.close();
  fout_fm5.close();
  fout_fm6.close();
  fout_fm7.close();

  return err_count;

}
