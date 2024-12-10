// Test bench for TrackletCalculator
#include "TrackletProcessorTop.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

#include "Macros.h"
#include "FileReadUtility.h"
#include "Constants.h"

#define A_ 0
#define B_ 1
#define C_ 2
#define D_ 3
#define E_ 4
#define F_ 5
#define G_ 6
#define H_ 7
#define I_ 8
#define J_ 9
#define K_ 10
#define L_ 11
// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined SEED_
  #define SEED_ L1L2_
#endif
#if !defined ITC_
  #define ITC_ C_
#endif
#if !defined MODULE_
  #define MODULE_ TP_L1L2C_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ TrackletProcessor_L1L2C
#endif


const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
// these need to be customized according to the specific TP being tested
#if SEED_ == L1L2_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARRELPS;
  const string innerStubPattern = "AllInnerStubs*_L1*";
  const string outerStubPattern = "AllStubs*_L2*";
  const int NCOPY=5;
#elif SEED_ == L2L3_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARRELPS;
  const string innerStubPattern = "AllInnerStubs*_L2*";
  const string outerStubPattern = "AllStubs*_L3*";
  const int NCOPY=2;
#elif SEED_ == L3L4_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "AllInnerStubs*_L3*";
  const string outerStubPattern = "AllStubs*_L4*";
  const int NCOPY=5;
#elif SEED_ == L5L6_
  const auto InnerStubType = BARREL2S;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "AllInnerStubs*_L5*";
  const string outerStubPattern = "AllStubs*_L6*";
  const int NCOPY=3;
#elif SEED_ == L1D1_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = DISK;
  const string innerStubPattern = "AllInnerStubs*_L1*";
  const string outerStubPattern = "AllStubs*_D1*";
  const int NCOPY=3;
#elif SEED_ == L2D1_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = DISK;
  const string innerStubPattern = "AllInnerStubs*_L2*";
  const string outerStubPattern = "AllStubs*_D1*";
  const int NCOPY=3;
#elif SEED_ == D1D2_
  const auto InnerStubType = DISK;
  const auto OuterStubType = DISK;
  const string innerStubPattern = "AllInnerStubs*_D1*";
  const string outerStubPattern = "AllStubs*_D2*";
  const int NCOPY=3;
#elif SEED_ == D3D4_
  const auto InnerStubType = DISK;
  const auto OuterStubType = DISK;
  const string innerStubPattern = "AllInnerStubs*_D3*";
  const string outerStubPattern = "AllStubs*_D4*";
  const int NCOPY=2;
#else
  #error "Undefined seed"
#endif
std::cout<<module_name[MODULE_];
//
  TBHelper tb(std::string("TP/") + module_name[MODULE_]);
  // error counts

  int err = 0;

  // input memories
  const auto nOuterVMStubMems = tb.nFiles("VMStubs*");
  const auto nInnerStubMems = tb.nFiles(innerStubPattern);
  const auto nOuterStubMems = tb.nFiles(outerStubPattern);
  vector<AllStubInnerMemory<InnerStubType> > innerStubs(nInnerStubMems);
  vector<AllStubMemory<OuterStubType> > outerStubs(nOuterStubMems);
  vector<VMStubMemory<OuterStubType, kNbitsrzbin, kNbitsphibin, NCOPY, true> > outervmStubs(nOuterVMStubMems);

  // output memories
  TrackletParameterMemory tpar;
  TrackletProjectionMemory<BARRELPS> tproj_barrel_ps[TP::N_PROJOUT_BARRELPS];
  TrackletProjectionMemory<BARREL2S> tproj_barrel_2s[TP::N_PROJOUT_BARREL2S];
  TrackletProjectionMemory<DISK> tproj_disk[TP::N_PROJOUT_DISK];

  // open input files from emulation
  auto &fin_innerStubs = tb.files(innerStubPattern);
  auto &fin_outerStubs = tb.files(outerStubPattern);
  auto &fin_outervmStubs = tb.files("VMStubs*");
  auto &fout_tpar = tb.files("TrackletParameters*");
  // print the input files loaded
  std::cout << "Loaded the input files:\n";
  for (unsigned i = 0; i < nInnerStubMems; i++)
    std::cout << "\t" << tb.fileNames(innerStubPattern).at(i) << "\n";
  for (unsigned i = 0; i < nOuterStubMems; i++)
    std::cout << "\t" << tb.fileNames(outerStubPattern).at(i) << "\n";
  for (unsigned i = 0; i < nOuterVMStubMems; i++)
    std::cout << "\t" << tb.fileNames("VMStubs*").at(i) << "\n";
  std::cout << std::endl;

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    for (unsigned i = 0; i < nInnerStubMems; i++)
      writeMemFromFile<AllStubInnerMemory<InnerStubType> >(innerStubs[i], fin_innerStubs.at(i), ievt);
    for (unsigned i = 0; i < nOuterStubMems; i++)
      writeMemFromFile<AllStubMemory<OuterStubType> >(outerStubs[i], fin_outerStubs.at(i), ievt);
    for (unsigned i = 0; i < nOuterVMStubMems; i++)
      writeMemFromFile<VMStubMemory<OuterStubType, kNbitsrzbin, kNbitsphibin, NCOPY, true>>(outervmStubs[i], fin_outervmStubs.at(i), ievt);

    // clear all output memories before starting
    tpar.clear();
    tpar.setWriteBX(ievt);
    for (unsigned i = 0; i < TP::N_PROJOUT_BARRELPS; i++) {
      tproj_barrel_ps[i].clear();
      tproj_barrel_ps[i].setWriteBX(ievt);
    }
    for (unsigned i = 0; i < TP::N_PROJOUT_BARREL2S; i++) {
      tproj_barrel_2s[i].clear();
      tproj_barrel_2s[i].setWriteBX(ievt);
    }
    for (unsigned i = 0; i < TP::N_PROJOUT_DISK; i++) {
      tproj_disk[i].clear();
      tproj_disk[i].setWriteBX(ievt);
    }

    // bx
    BXType bx = ievt;
    BXType bx_o;

    // Unit Under Test
    TOP_FUNC_(bx, bx_o, innerStubs.data(), outerStubs.data(), outervmStubs.data(),  &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);

    bool truncation = false;

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackletParameterMemory>(tpar, fout_tpar.at(0), ievt,
                                                   "\nTrackletParameter", truncation);
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
