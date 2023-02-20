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
  #define MODULE_ MC_L1PHIC_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ MatchCalculator_L1PHIC
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

  const auto stubMemType = (MODULE_ >= MC_L1PHIA_ && MODULE_ <= MC_L3PHID_) ? BARRELPS : (MODULE_ > MC_D5PHID_) ? BARREL2S : (MODULE_ >= MC_D3PHIA_) ? DISK2S : DISKPS;
  const auto projMemType = (MODULE_ >= MC_L1PHIA_ && MODULE_ <= MC_L3PHID_) ? BARRELPS : (MODULE_ > MC_D5PHID_) ? BARREL2S : DISK;
  const auto fmProjMemType = (MODULE_ >= MC_L1PHIA_ && MODULE_) ? BARREL : DISK;
  TBHelper tb(std::string("MC/") + module_name[MODULE_]);

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
  vector<FullMatchMemory<fmProjMemType> > fullmatcharray(nFullMatches);

  // print the input files loaded
  std::cout << "Loaded the input files:\n";
  for (unsigned i = 0; i < nCandidateMatches; i++)
    std::cout << "\t" << tb.fileNames(candidateMatchPattern).at(i) << "\n";
  for (unsigned i = 0; i < nAllProjections; i++)
    std::cout << "\t" << tb.fileNames(allProjectionPatternarray).at(i) << "\n";
  for (unsigned i = 0; i < nAllStubs; i++)
    std::cout << "\t" << tb.fileNames(allStubPatternarray).at(i) << "\n";
  for (unsigned i = 0; i < nFullMatches; i++)
    std::cout << "\t" << tb.fileNames(fullMatchPattern).at(i) << "\n";
  std::cout << std::endl;

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
    TOP_FUNC_(bx, cmatcharray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());

    bool truncation = false;
    auto &fout_fullmatch = tb.files(fullMatchPattern);
    const auto &fullmatch_names = tb.fileNames(fullMatchPattern);
    
    // compare the computed outputs with the expected ones
    for (unsigned int i = 0; i < fullmatch_names.size(); i++) {
      const auto &fullmatch_name = fullmatch_names.at(i);
      auto &fout = fout_fullmatch.at(i);
      string label = "FullMatch " + to_string(i);
      err += compareMemWithFile<FullMatchMemory<fmProjMemType> >
        (fullmatcharray[i], fout, ievt, label, truncation);
    }
    
  } // end of event loop
  
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
//  cout << "Module actually has " << err << " errors." << endl;
//  return 0;
  return err;
  
}
