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
#if !defined TOP_FUNC_
  #define TOP_FUNC_ MatchProcessor_L3PHIC
#endif

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // Define memory patterns
  const string trackletProjectionPattern = "TrackletProjections*";
  const string allProjectionPatternarray = "AllProj*";
  const string allStubPatternarray = "AllStub*";
  const string fullMatchPattern = "FullMatches*";

  const auto stubMemType = (MODULE_ >= MP_L1PHIA_ && MODULE_ <= MP_L3PHID_) ? BARRELPS : (MODULE_ > MP_D5PHID_) ? BARREL2S : (MODULE_ >= MP_D3PHIA_) ? DISK2S : DISKPS;
  const auto projMemType = (MODULE_ >= MP_L1PHIA_ && MODULE_ <= MP_L3PHID_) ? BARRELPS : (MODULE_ > MP_D5PHID_) ? BARREL2S : DISK;
  const auto fmProjMemType = (MODULE_ >= MP_L1PHIA_ && MODULE_) ? BARREL : DISK;
  TBHelper tb(std::string("MP/") + module_name[MODULE_]);

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  const auto nTrackletProjections = tb.nFiles(trackletProjectionPattern);
  vector<CandidateMatchMemory> tprojarray(nTrackletProjections);
  const auto nAllProjections = tb.nFiles(allProjectionPatternarray);
  vector<AllProjectionMemory<projMemType>> allproj(nAllProjections);
  const auto nAllStubs = tb.nFiles(allStubPatternarray);
  vector<AllStubMemory<stubMemType>> allstub(nAllStubs);

  // output memories
  const auto nFullMatches = tb.nFiles(fullMatchPattern);
  vector<FullMatchMemory<fmProjMemType> > fullmatcharray(nFullMatches);

  // print the input files loaded
  std::cout << "Loaded the input files:\n";
  for (unsigned i = 0; i < nTrackletProjections; i++)
    std::cout << "\t" << tb.fileNames(trackletProjectionPattern).at(i) << "\n";
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
    auto &fin_TrackletProjections = tb.files(trackletProjectionPattern);
    for (unsigned int i = 0; i < nTrackletProjections; i++)
      writeMemFromFile<CandidateMatchMemory>(tprojarray[i], fin_TrackletProjections.at(i), ievt);
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
    TOP_FUNC_(bx, tprojarray.data(), allstub.data(), allproj.data(), bx_out, fullmatcharray.data());

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
