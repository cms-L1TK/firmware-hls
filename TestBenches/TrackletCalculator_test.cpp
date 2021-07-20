// Test bench for TrackletCalculator
#include "TrackletCalculatorTop.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

#include "Macros.h"
#include "FileReadUtility.h"
#include "Constants.h"

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined SEED_
  #define SEED_ L1L2_
#endif
#if !defined MODULE_
  #define MODULE_ TC_L1L2E_
#endif

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // these need to be customized according to the specific TC being tested
#if SEED_ == L1L2_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARRELPS;
  const string innerStubPattern = "AllStubs*_L1*";
  const string outerStubPattern = "AllStubs*_L2*";
#elif SEED_ == L3L4_
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "AllStubs*_L3*";
  const string outerStubPattern = "AllStubs*_L4*";
#elif SEED_ == L5L6_
  const auto InnerStubType = BARREL2S;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "AllStubs*_L5*";
  const string outerStubPattern = "AllStubs*_L6*";
#else
  #error "Undefined seed"
#endif
#if MODULE_ == TC_L1L2A_
  TBHelper tb("TC/TC_L1L2A");
#elif MODULE_ == TC_L1L2B_
  TBHelper tb("TC/TC_L1L2B");
#elif MODULE_ == TC_L1L2C_
  TBHelper tb("TC/TC_L1L2C");
#elif MODULE_ == TC_L1L2D_
  TBHelper tb("TC/TC_L1L2D");
#elif MODULE_ == TC_L1L2E_
  TBHelper tb("TC/TC_L1L2E");
#elif MODULE_ == TC_L1L2F_
  TBHelper tb("TC/TC_L1L2F");
#elif MODULE_ == TC_L1L2G_
  TBHelper tb("TC/TC_L1L2G");
#elif MODULE_ == TC_L1L2H_
  TBHelper tb("TC/TC_L1L2H");
#elif MODULE_ == TC_L1L2I_
  TBHelper tb("TC/TC_L1L2I");
#elif MODULE_ == TC_L1L2J_
  TBHelper tb("TC/TC_L1L2J");
#elif MODULE_ == TC_L1L2K_
  TBHelper tb("TC/TC_L1L2K");
#elif MODULE_ == TC_L1L2L_
  TBHelper tb("TC/TC_L1L2L");
#elif MODULE_ == TC_L3L4A_
  TBHelper tb("TC/TC_L3L4A");
#elif MODULE_ == TC_L3L4D_
  TBHelper tb("TC/TC_L3L4D");
#elif MODULE_ == TC_L5L6A_
  TBHelper tb("TC/TC_L5L6A");
#elif MODULE_ == TC_L5L6D_
  TBHelper tb("TC/TC_L5L6D");
#else
  #error "Undefined TC"
#endif

  // error counts
  int err = 0;

  // input memories
  const auto nStubPairMems = tb.nFiles("StubPairs*");
  const auto nInnerStubMems = tb.nFiles(innerStubPattern);
  const auto nOuterStubMems = tb.nFiles(outerStubPattern);
  vector<AllStubMemory<InnerStubType> > innerStubs(nInnerStubMems);
  vector<AllStubMemory<OuterStubType> > outerStubs(nOuterStubMems);
  vector<StubPairMemory> stubPairs(nStubPairMems);

  // output memories
  TrackletParameterMemory tpar;
  TrackletProjectionMemory<BARRELPS> tproj_barrel_ps[TC::N_PROJOUT_BARRELPS];
  TrackletProjectionMemory<BARREL2S> tproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
  TrackletProjectionMemory<DISK> tproj_disk[TC::N_PROJOUT_DISK];

  // open input files from emulation
  auto &fin_innerStubs = tb.files(innerStubPattern);
  auto &fin_outerStubs = tb.files(outerStubPattern);
  auto &fin_stubPairs = tb.files("StubPairs*");
  auto &fout_tpar = tb.files("TrackletParameters*");
  auto &fout_tproj = tb.files("TrackletProjections*");
  const auto &tproj_names = tb.fileNames("TrackletProjections*");

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    for (unsigned i = 0; i < nInnerStubMems; i++)
      writeMemFromFile<AllStubMemory<InnerStubType> >(innerStubs[i], fin_innerStubs.at(i), ievt);
    for (unsigned i = 0; i < nOuterStubMems; i++)
      writeMemFromFile<AllStubMemory<OuterStubType> >(outerStubs[i], fin_outerStubs.at(i), ievt);
    for (unsigned i = 0; i < nStubPairMems; i++)
      writeMemFromFile<StubPairMemory>(stubPairs[i], fin_stubPairs.at(i), ievt);

    // clear all output memories before starting
    tpar.clear();
    for (unsigned i = 0; i < TC::N_PROJOUT_BARRELPS; i++)
      tproj_barrel_ps[i].clear();
    for (unsigned i = 0; i < TC::N_PROJOUT_BARREL2S; i++)
      tproj_barrel_2s[i].clear();
    for (unsigned i = 0; i < TC::N_PROJOUT_DISK; i++)
      tproj_disk[i].clear();

    // bx
    BXType bx = ievt;
    BXType bx_o;

    // Unit Under Test
#if MODULE_ == TC_L1L2A_
    TrackletCalculator_L1L2A(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2B_
    TrackletCalculator_L1L2B(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2C_
    TrackletCalculator_L1L2C(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2D_
    TrackletCalculator_L1L2D(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2E_
    TrackletCalculator_L1L2E(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2F_
    TrackletCalculator_L1L2F(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2G_
    TrackletCalculator_L1L2G(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2H_
    TrackletCalculator_L1L2H(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2I_
    TrackletCalculator_L1L2I(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2J_
    TrackletCalculator_L1L2J(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2K_
    TrackletCalculator_L1L2K(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L1L2L_
    TrackletCalculator_L1L2L(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L3L4A_
    TrackletCalculator_L3L4A(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L3L4D_
    TrackletCalculator_L3L4D(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L5L6A_
    TrackletCalculator_L5L6A(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif MODULE_ == TC_L5L6D_
    TrackletCalculator_L5L6D(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#else
  #error "Undefined TC"
#endif

    bool truncation = false;

    // compare the computed outputs with the expected ones
    err += compareMemWithFile<TrackletParameterMemory>(tpar, fout_tpar.at(0), ievt,
                                                   "\nTrackletParameter", truncation);
    for (unsigned i = 0; i < tproj_names.size(); i++) {
      const auto &tproj_name = tproj_names.at(i);
      auto &fout = fout_tproj.at(i);
      if (tproj_name.find("_L1PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIA], fout, ievt,
                                                       "\nTrackletProjection (L1PHIA)", truncation);
      else if (tproj_name.find("_L1PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIB], fout, ievt,
                                                       "\nTrackletProjection (L1PHIB)", truncation);
      else if (tproj_name.find("_L1PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIC], fout, ievt,
                                                       "\nTrackletProjection (L1PHIC)", truncation);
      else if (tproj_name.find("_L1PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHID], fout, ievt,
                                                       "\nTrackletProjection (L1PHID)", truncation);
      else if (tproj_name.find("_L1PHIE") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIE], fout, ievt,
                                                       "\nTrackletProjection (L1PHIE)", truncation);
      else if (tproj_name.find("_L1PHIF") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIF], fout, ievt,
                                                       "\nTrackletProjection (L1PHIF)", truncation);
      else if (tproj_name.find("_L1PHIG") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIG], fout, ievt,
                                                       "\nTrackletProjection (L1PHIG)", truncation);
      else if (tproj_name.find("_L1PHIH") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIH], fout, ievt,
                                                       "\nTrackletProjection (L1PHIH)", truncation);
      else if (tproj_name.find("_L2PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIA], fout, ievt,
                                                       "\nTrackletProjection (L2PHIA)", truncation);
      else if (tproj_name.find("_L2PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIB], fout, ievt,
                                                       "\nTrackletProjection (L2PHIB)", truncation);
      else if (tproj_name.find("_L2PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIC], fout, ievt,
                                                       "\nTrackletProjection (L2PHIC)", truncation);
      else if (tproj_name.find("_L2PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHID], fout, ievt,
                                                       "\nTrackletProjection (L2PHID)", truncation);
      else if (tproj_name.find("_L3PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHIA], fout, ievt,
                                                       "\nTrackletProjection (L3PHIA)", truncation);
      else if (tproj_name.find("_L3PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHIB], fout, ievt,
                                                       "\nTrackletProjection (L3PHIB)", truncation);
      else if (tproj_name.find("_L3PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHIC], fout, ievt,
                                                       "\nTrackletProjection (L3PHIC)", truncation);
      else if (tproj_name.find("_L3PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHID], fout, ievt,
                                                       "\nTrackletProjection (L3PHID)", truncation);

      else if (tproj_name.find("_L4PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHIA], fout, ievt,
                                                       "\nTrackletProjection (L4PHIA)", truncation);
      else if (tproj_name.find("_L4PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHIB], fout, ievt,
                                                       "\nTrackletProjection (L4PHIB)", truncation);
      else if (tproj_name.find("_L4PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHIC], fout, ievt,
                                                       "\nTrackletProjection (L4PHIC)", truncation);
      else if (tproj_name.find("_L4PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHID], fout, ievt,
                                                       "\nTrackletProjection (L4PHID)", truncation);
      else if (tproj_name.find("_L5PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIA], fout, ievt,
                                                       "\nTrackletProjection (L5PHIA)", truncation);
      else if (tproj_name.find("_L5PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIB], fout, ievt,
                                                       "\nTrackletProjection (L5PHIB)", truncation);
      else if (tproj_name.find("_L5PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIC], fout, ievt,
                                                       "\nTrackletProjection (L5PHIC)", truncation);
      else if (tproj_name.find("_L5PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHID], fout, ievt,
                                                       "\nTrackletProjection (L5PHID)", truncation);
      else if (tproj_name.find("_L6PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIA], fout, ievt,
                                                       "\nTrackletProjection (L6PHIA)", truncation);
      else if (tproj_name.find("_L6PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIB], fout, ievt,
                                                       "\nTrackletProjection (L6PHIB)", truncation);
      else if (tproj_name.find("_L6PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIC], fout, ievt,
                                                       "\nTrackletProjection (L6PHIC)", truncation);
      else if (tproj_name.find("_L6PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHID], fout, ievt,
                                                       "\nTrackletProjection (L6PHID)", truncation);

      else if (tproj_name.find("_D1PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIA], fout, ievt,
                                                       "\nTrackletProjection (D1PHIA)", truncation);
      else if (tproj_name.find("_D1PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIB], fout, ievt,
                                                       "\nTrackletProjection (D1PHIB)", truncation);
      else if (tproj_name.find("_D1PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIC], fout, ievt,
                                                       "\nTrackletProjection (D1PHIC)", truncation);
      else if (tproj_name.find("_D1PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHID], fout, ievt,
                                                       "\nTrackletProjection (D1PHID)", truncation);
      else if (tproj_name.find("_D2PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIA], fout, ievt,
                                                       "\nTrackletProjection (D2PHIA)", truncation);
      else if (tproj_name.find("_D2PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIB], fout, ievt,
                                                       "\nTrackletProjection (D2PHIB)", truncation);
      else if (tproj_name.find("_D2PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIC], fout, ievt,
                                                       "\nTrackletProjection (D2PHIC)", truncation);
      else if (tproj_name.find("_D2PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHID], fout, ievt,
                                                       "\nTrackletProjection (D2PHID)", truncation);
      else if (tproj_name.find("_D3PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHIA], fout, ievt,
                                                       "\nTrackletProjection (D3PHIA)", truncation);
      else if (tproj_name.find("_D3PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHIB], fout, ievt,
                                                       "\nTrackletProjection (D3PHIB)", truncation);
      else if (tproj_name.find("_D3PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHIC], fout, ievt,
                                                       "\nTrackletProjection (D3PHIC)", truncation);
      else if (tproj_name.find("_D3PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHID], fout, ievt,
                                                       "\nTrackletProjection (D3PHID)", truncation);
      else if (tproj_name.find("_D4PHIA") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHIA], fout, ievt,
                                                       "\nTrackletProjection (D4PHIA)", truncation);
      else if (tproj_name.find("_D4PHIB") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHIB], fout, ievt,
                                                       "\nTrackletProjection (D4PHIB)", truncation);
      else if (tproj_name.find("_D4PHIC") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHIC], fout, ievt,
                                                       "\nTrackletProjection (D4PHIC)", truncation);
      else if (tproj_name.find("_D4PHID") != string::npos)
        err += compareMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHID], fout, ievt,
                                                       "\nTrackletProjection (D4PHID)", truncation);
    }
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
