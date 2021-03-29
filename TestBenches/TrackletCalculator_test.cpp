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
#if !defined __SEED__
  #define __SEED__ __L1L2__
#endif
#if !defined __MODULE__
  #define __MODULE__ __TC_L1L2E__
#endif

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // these need to be customized according to the specific TC being tested
#if __SEED__ == __L1L2__
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARRELPS;
  const string innerStubPattern = "AllStubs*_L1*";
  const string outerStubPattern = "AllStubs*_L2*";
#elif __SEED__ == __L3L4__
  const auto InnerStubType = BARRELPS;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "AllStubs*_L3*";
  const string outerStubPattern = "AllStubs*_L4*";
#elif __SEED__ == __L5L6__
  const auto InnerStubType = BARREL2S;
  const auto OuterStubType = BARREL2S;
  const string innerStubPattern = "AllStubs*_L5*";
  const string outerStubPattern = "AllStubs*_L6*";
#else
  #error "Undefined seed"
#endif
#if __MODULE__ == __TC_L1L2A__
  TBHelper tb("TC/TC_L1L2A");
#elif __MODULE__ == __TC_L1L2B__
  TBHelper tb("TC/TC_L1L2B");
#elif __MODULE__ == __TC_L1L2C__
  TBHelper tb("TC/TC_L1L2C");
#elif __MODULE__ == __TC_L1L2D__
  TBHelper tb("TC/TC_L1L2D");
#elif __MODULE__ == __TC_L1L2E__
  TBHelper tb("TC/TC_L1L2E");
#elif __MODULE__ == __TC_L1L2F__
  TBHelper tb("TC/TC_L1L2F");
#elif __MODULE__ == __TC_L1L2G__
  TBHelper tb("TC/TC_L1L2G");
#elif __MODULE__ == __TC_L1L2H__
  TBHelper tb("TC/TC_L1L2H");
#elif __MODULE__ == __TC_L1L2I__
  TBHelper tb("TC/TC_L1L2I");
#elif __MODULE__ == __TC_L1L2J__
  TBHelper tb("TC/TC_L1L2J");
#elif __MODULE__ == __TC_L1L2K__
  TBHelper tb("TC/TC_L1L2K");
#elif __MODULE__ == __TC_L1L2L__
  TBHelper tb("TC/TC_L1L2L");
#elif __MODULE__ == __TC_L3L4A__
  TBHelper tb("TC/TC_L3L4A");
#elif __MODULE__ == __TC_L3L4B__
  TBHelper tb("TC/TC_L3L4B");
#elif __MODULE__ == __TC_L3L4C__
  TBHelper tb("TC/TC_L3L4C");
#elif __MODULE__ == __TC_L3L4D__
  TBHelper tb("TC/TC_L3L4D");
#elif __MODULE__ == __TC_L3L4E__
  TBHelper tb("TC/TC_L3L4E");
#elif __MODULE__ == __TC_L3L4F__
  TBHelper tb("TC/TC_L3L4F");
#elif __MODULE__ == __TC_L3L4G__
  TBHelper tb("TC/TC_L3L4G");
#elif __MODULE__ == __TC_L3L4H__
  TBHelper tb("TC/TC_L3L4H");
#elif __MODULE__ == __TC_L5L6A__
  TBHelper tb("TC/TC_L5L6A");
#elif __MODULE__ == __TC_L5L6D__
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

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    auto &fin_innerStubs = tb.files(innerStubPattern);
    auto &fin_outerStubs = tb.files(outerStubPattern);
    auto &fin_stubPairs = tb.files("StubPairs*");
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
#if __MODULE__ == __TC_L1L2A__
    TrackletCalculator_L1L2A(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2B__
    TrackletCalculator_L1L2B(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2C__
    TrackletCalculator_L1L2C(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2D__
    TrackletCalculator_L1L2D(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2E__
    TrackletCalculator_L1L2E(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2F__
    TrackletCalculator_L1L2F(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2G__
    TrackletCalculator_L1L2G(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2H__
    TrackletCalculator_L1L2H(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2I__
    TrackletCalculator_L1L2I(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2J__
    TrackletCalculator_L1L2J(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2K__
    TrackletCalculator_L1L2K(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L1L2L__
    TrackletCalculator_L1L2L(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4A__
    TrackletCalculator_L3L4A(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4B__
    TrackletCalculator_L3L4B(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4C__
    TrackletCalculator_L3L4C(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4D__
    TrackletCalculator_L3L4D(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4E__
    TrackletCalculator_L3L4E(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4F__
    TrackletCalculator_L3L4F(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4G__
    TrackletCalculator_L3L4G(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L3L4H__
    TrackletCalculator_L3L4H(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L5L6A__
    TrackletCalculator_L5L6A(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#elif __MODULE__ == __TC_L5L6D__
    TrackletCalculator_L5L6D(bx, innerStubs.data(), outerStubs.data(), stubPairs.data(), bx_o, &tpar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
#else
  #error "Undefined TC"
#endif

    bool truncation = false;
    auto &fout_tpar = tb.files("TrackletParameters*");
    auto &fout_tproj = tb.files("TrackletProjections*");
    const auto &tproj_names = tb.fileNames("TrackletProjections*");

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
    }
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
