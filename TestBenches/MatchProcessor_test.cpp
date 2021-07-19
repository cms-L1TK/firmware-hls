// Test bench for MatchProcessor
#include "MatchProcessorTop.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <iterator>

#include "Macros.h"
#include "FileReadUtility.h"
#include "Constants.h"

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined MODULE_
  #define MODULE_ MP_L3PHIC_
#endif

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // Define memory patterns
  const string trackletProjectionPattern = "TrackletProjections*";
  const string vmStubPattern = "VMStubs*";
  const string allStubPattern = "AllStubs*";
  const string fullMatchPattern = "FullMatches*";

  // Define region according to which layer is being tested
#if MODULE_ == MP_L1PHIB_ || MODULE_ == MP_L2PHIB_ || MODULE_ == MP_L3PHIB_ || MODULE_ == MP_L1PHIC_ || MODULE_ == MP_L2PHIC_ || MODULE_ == MP_L3PHIC_
  const auto trackletMemType = BARRELPS;
  const auto vmStubMemType = BARRELPS;
  const auto stubMemType = BARRELPS;
#elif MODULE_ == MP_L4PHIB_ || MODULE_ == MP_L5PHIB_ || MODULE_ == MP_L6PHIB_ || MODULE_ == MP_L4PHIC_ || MODULE_ == MP_L5PHIC_ || MODULE_ == MP_L6PHIC_
  const auto trackletMemType = BARREL2S;
  const auto vmStubMemType = BARREL2S;
  const auto stubMemType = BARREL2S;
#else
  #error "Undefined Module"
#endif

#if MODULE_ == MP_L1PHIB_ || MODULE_ == MP_L2PHIB_ || MODULE_ == MP_L3PHIB_ || MODULE_ == MP_L4PHIB_ || MODULE_ == MP_L5PHIB_ || MODULE_ == MP_L6PHIB_ || MODULE_ == MP_L1PHIC_ || MODULE_ == MP_L2PHIC_ || MODULE_ == MP_L3PHIC_ || MODULE_ == MP_L4PHIC_ || MODULE_ == MP_L5PHIC_ || MODULE_ == MP_L6PHIC_
  const auto vmProjMemType = BARREL;
#else
  #error "Undefined Module"
#endif

/* FIXME replace after generator top is merged
#if MODULE_ == MP_L1PHIB_
  TBHelper tb("MP/MP_L1PHIB");
#elif MODULE_ == MP_L2PHIB_
  TBHelper tb("MP/MP_L2PHIB");
#elif MODULE_ == MP_L3PHIB_
  TBHelper tb("MP/MP_L3PHIB");
#elif MODULE_ == MP_L4PHIB_
  TBHelper tb("MP/MP_L4PHIB");
#elif MODULE_ == MP_L5PHIB_
  TBHelper tb("MP/MP_L5PHIB");
#elif MODULE_ == MP_L6PHIB_
  TBHelper tb("MP/MP_L6PHIB");
#elif MODULE_ == MP_L1PHIC_
  TBHelper tb("MP/MP_L1PHIC");
#elif MODULE_ == MP_L2PHIC_
  TBHelper tb("MP/MP_L2PHIC");
*/
#if MODULE_ == MP_L3PHIC_
  TBHelper tb("MP/MP_L3PHIC");
/*
#elif MODULE_ == MP_L4PHIC_
  TBHelper tb("MP/MP_L4PHIC");
#elif MODULE_ == MP_L5PHIC_
  TBHelper tb("MP/MP_L5PHIC");
#elif MODULE_ == MP_L6PHIC_
  TBHelper tb("MP/MP_L6PHIC");
*/
#else
  #error "Undefined Module"
#endif

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  const auto nTrackletProjection = tb.nFiles(trackletProjectionPattern);
  vector<TrackletProjectionMemory<trackletMemType>> tprojarray(nTrackletProjection);
  const auto nAllStubs = tb.nFiles(allStubPattern);
  vector<AllStubMemory<stubMemType>> allstubarray(nAllStubs);
  const auto nVMStubs = tb.nFiles(vmStubPattern);
  vector<VMStubMEMemoryCM<vmStubMemType, 3, 3, kNMatchEngines>> vmstubarray(nVMStubs);

  // output memories
  const auto nFullMatches = tb.nFiles(fullMatchPattern);
  vector<FullMatchMemory<vmProjMemType> > fullmatcharray(nFullMatches);

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    auto &fin_trackletProjection = tb.files(trackletProjectionPattern);
    for (unsigned int i = 0; i < nTrackletProjection; i++)
      writeMemFromFile<TrackletProjectionMemory<trackletMemType>>(tprojarray[i], fin_trackletProjection.at(i), ievt);
    auto &fin_VMStubs = tb.files(vmStubPattern);
    for (unsigned int i = 0; i < nVMStubs; i++)
      writeMemFromFile<VMStubMEMemoryCM<vmStubMemType, 3, 3, kNMatchEngines>>(vmstubarray[i], fin_VMStubs.at(i), ievt);
    auto &fin_AllStubs = tb.files(allStubPattern);
    for (unsigned int i = 0; i < nAllStubs; i++)
      writeMemFromFile<AllStubMemory<stubMemType>>(allstubarray[i], fin_AllStubs.at(i), ievt);

    // clear allarray, output memories before starting
    for (unsigned int i = 0; i < nFullMatches; i++)
      fullmatcharray[i].clear();

    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
/* FIXME replace after generator top is merged
#if MODULE_ == MP_L1PHIB_
    MatchProcessor_L1PHIB(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L2PHIB_
    MatchProcessor_L2PHIB(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L3PHIB_
    MatchProcessor_L3PHIB(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L4PHIB_
    MatchProcessor_L4PHIB(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L5PHIB_
    MatchProcessor_L5PHIB(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L6PHIB_
    MatchProcessor_L6PHIB(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L1PHIC_
    MatchProcessor_L1PHIC(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L2PHIC_
    MatchProcessor_L2PHIC(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
*/
#if MODULE_ == MP_L3PHIC_
    MatchProcessor_L3PHIC(bx, tprojarray.data(), vmstubarray[0], &allstubarray[0], bx_out, fullmatcharray.data());
/*
#elif MODULE_ == MP_L4PHIC_
    MatchProcessor_L4PHIC(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L5PHIC_
    MatchProcessor_L5PHIC(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MP_L6PHIC_
    MatchProcessor_L6PHIC(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());
*/
#else
  #error "Undefined MP"
#endif

    bool truncation = false;
    auto &fout_fullmatch = tb.files(fullMatchPattern);
    const auto &fullmatch_names = tb.fileNames(fullMatchPattern);
    
    // compare the computed outputs with the expected ones
    for (unsigned int i = 0; i < fullmatch_names.size(); i++) {
      const auto &fullmatch_name = fullmatch_names.at(i);
      auto &fout = fout_fullmatch.at(i);
      string label = "FullMatch " + to_string(i);
      err += compareMemWithFile<FullMatchMemory<vmProjMemType> >
        (fullmatcharray[i], fout, ievt, label, truncation);
    }
    
  } // end of event loop
  
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
//  cout << "Module actually has " << err << " errors." << endl;
//  return 0;
  return err;
  
}
