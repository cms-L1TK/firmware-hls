// Test bench for MatchCalculator
#include "MatchCalculatorTop.h"

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
  #define MODULE_ MC_L3PHIC_
#endif

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // Define memory patterns
  const string candidateMatchPattern = "CandidateMatches*";
  const string allProjectionPatternarray = "AllProj*";
  const string allStubPatternarray = "AllStub*";
  const string fullMatchPattern = "FullMatches*";

  // Define region according to which layer is being tested
#if MODULE_ == MC_L1PHIB_ || MODULE_ == MC_L2PHIB_ || MODULE_ == MC_L3PHIB_ || MODULE_ == MC_L1PHIC_ || MODULE_ == MC_L2PHIC_ || MODULE_ == MC_L3PHIC_
  const auto projMemType = BARRELPS;
  const auto stubMemType = BARRELPS;
#elif MODULE_ == MC_L4PHIB_ || MODULE_ == MC_L5PHIB_ || MODULE_ == MC_L6PHIB_ || MODULE_ == MC_L4PHIC_ || MODULE_ == MC_L5PHIC_ || MODULE_ == MC_L6PHIC_
  const auto projMemType = BARREL2S;
  const auto stubMemType = BARREL2S;
#else
  #error "Undefined Module"
#endif

#if MODULE_ == MC_L1PHIB_ || MODULE_ == MC_L2PHIB_ || MODULE_ == MC_L3PHIB_ || MODULE_ == MC_L4PHIB_ || MODULE_ == MC_L5PHIB_ || MODULE_ == MC_L6PHIB_ || MODULE_ == MC_L1PHIC_ || MODULE_ == MC_L2PHIC_ || MODULE_ == MC_L3PHIC_ || MODULE_ == MC_L4PHIC_ || MODULE_ == MC_L5PHIC_ || MODULE_ == MC_L6PHIC_
  const auto vmProjMemType = BARREL;
#else
  #error "Undefined Module"
#endif

#if MODULE_ == MC_L1PHIB_
  TBHelper tb("MC/MC_L1PHIB");
#elif MODULE_ == MC_L2PHIB_
  TBHelper tb("MC/MC_L2PHIB");
#elif MODULE_ == MC_L3PHIB_
  TBHelper tb("MC/MC_L3PHIB");
#elif MODULE_ == MC_L4PHIB_
  TBHelper tb("MC/MC_L4PHIB");
#elif MODULE_ == MC_L5PHIB_
  TBHelper tb("MC/MC_L5PHIB");
#elif MODULE_ == MC_L6PHIB_
  TBHelper tb("MC/MC_L6PHIB");
#elif MODULE_ == MC_L1PHIC_
  TBHelper tb("MC/MC_L1PHIC");
#elif MODULE_ == MC_L2PHIC_
  TBHelper tb("MC/MC_L2PHIC");
#elif MODULE_ == MC_L3PHIC_
  TBHelper tb("MC/MC_L3PHIC");
#elif MODULE_ == MC_L4PHIC_
  TBHelper tb("MC/MC_L4PHIC");
#elif MODULE_ == MC_L5PHIC_
  TBHelper tb("MC/MC_L5PHIC");
#elif MODULE_ == MC_L6PHIC_
  TBHelper tb("MC/MC_L6PHIC");
#else
  #error "Undefined Module"
#endif

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  const auto nCandidateMatches = tb.nFiles(candidateMatchPattern);
  vector<CandidateMatchMemory> cmatcharray(nCandidateMatches);
  const auto nAllProjections = tb.nFiles(allProjectionPatternarray);
  vector<AllProjectionMemory<projMemType>> allproj(nAllProjections);
  const auto nAllStubs = tb.nFiles(allStubPatternarray);
  vector<AllStubMemory<stubMemType>> allstub(nAllStubs);

  // output memories
  const auto nFullMatches = tb.nFiles(fullMatchPattern);
  vector<FullMatchMemory<vmProjMemType> > fullmatcharray(nFullMatches);

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    auto &fin_CandidateMatches = tb.files(candidateMatchPattern);
    for (unsigned int i = 0; i < nCandidateMatches; i++)
      writeMemFromFile<CandidateMatchMemory>(cmatcharray[i], fin_CandidateMatches.at(i), ievt);
    auto &fin_AllProjections = tb.files(allProjectionPatternarray);
    for (unsigned int i = 0; i < nAllProjections; i++)
      writeMemFromFile<AllProjectionMemory<projMemType>>(allproj[i], fin_AllProjections.at(i), ievt);
    auto &fin_AllStubs = tb.files(allStubPatternarray);
    for (unsigned int i = 0; i < nAllStubs; i++)
      writeMemFromFile<AllStubMemory<stubMemType>>(allstub[i], fin_AllStubs.at(i), ievt);

    // clear allarray, output memories before starting
    for (unsigned int i = 0; i < nFullMatches; i++)
      fullmatcharray[i].clear();

    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
#if MODULE_ == MC_L1PHIB_
    MatchCalculator_L1PHIB(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L2PHIB_
    MatchCalculator_L2PHIB(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L3PHIB_
    MatchCalculator_L3PHIB(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L4PHIB_
    MatchCalculator_L4PHIB(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L5PHIB_
    MatchCalculator_L5PHIB(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L6PHIB_
    MatchCalculator_L6PHIB(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L1PHIC_
    MatchCalculator_L1PHIC(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L2PHIC_
    MatchCalculator_L2PHIC(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L3PHIC_
    MatchCalculator_L3PHIC(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L4PHIC_
    MatchCalculator_L4PHIC(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L5PHIC_
    MatchCalculator_L5PHIC(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#elif MODULE_ == MC_L6PHIC_
    MatchCalculator_L6PHIC(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());
#else
  #error "Undefined MC"
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
