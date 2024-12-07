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
  #define MODULE_ MP_D1PHIC_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ MatchProcessor_D1PHIC
#endif

const int nevents = 5;  //number of events to run

using namespace std;

int main()
{
  // Define memory patterns
  const string trackletProjectionPattern = "TrackletProjections_MPROJ*";
  const string allStubPatternarray = "AllStub*";
  const string vmStubPatternarray = "VMStubs_VMSME*";
  const string fullMatchPattern = "FullMatches*";

  const auto stubMemType   = (MODULE_ >= MP_L1PHIA_ && MODULE_ <= MP_L3PHID_) ? BARRELPS : (MODULE_ > MP_D5PHID_) ? BARREL2S : (MODULE_ >= MP_D3PHIA_) ? DISK2S : DISKPS;
  const auto vmStubMemType  = (MODULE_ >= MP_L1PHIA_ && MODULE_ <= MP_L3PHID_) ? BARRELPS : (MODULE_ > MP_D5PHID_) ? BARREL2S : DISK;
  const auto vmStubMemRZ  = (MODULE_ > MP_D5PHID_) ? kNbitsrzbinMPBarrel : kNbitsrzbinMPDisk;
  const auto tprojMemType  = (MODULE_ >= MP_L1PHIA_ && MODULE_ <= MP_L3PHID_) ? BARRELPS : (MODULE_ > MP_D5PHID_) ? BARREL2S : DISK;
  const auto fmProjMemType = (MODULE_ >= MP_L1PHIA_ && MODULE_) ? BARREL : DISK;
  TBHelper tb(std::string("MP/") + module_name[MODULE_]);

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  const auto nTrackletProjections = tb.nFiles(trackletProjectionPattern);
  vector<TrackletProjectionMemory<tprojMemType>> tprojarray(nTrackletProjections);
  const auto nAllStub = tb.nFiles(allStubPatternarray);
  vector<AllStubMemory<stubMemType>> allstub(nAllStub);
  const auto nVMStubs = tb.nFiles(vmStubPatternarray);
  VMStubMemory<vmStubMemType, vmStubMemRZ, kNbitsphibin, kNMatchEngines> vmstub; // barrel

  // output memories
  const auto nFullMatches = tb.nFiles(fullMatchPattern);
  vector<FullMatchMemory<fmProjMemType> > fullmatcharray(nFullMatches);

  // print the input files loaded
  std::cout << "Loaded the input files:\n";
  for (unsigned i = 0; i < nTrackletProjections; i++)
    std::cout << "\t" << tb.fileNames(trackletProjectionPattern).at(i) << "\n";
  for (unsigned i = 0; i < nAllStub; i++)
    std::cout << "\t" << tb.fileNames(allStubPatternarray).at(i) << "\n";
  for (unsigned i = 0; i < nVMStubs; i++)
    std::cout << "\t" << tb.fileNames(vmStubPatternarray).at(i) << "\n";
  for (unsigned i = 0; i < nFullMatches; i++)
    std::cout << "\t" << tb.fileNames(fullMatchPattern).at(i) << "\n";
  std::cout << std::endl;

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // bx
    BXType bx = ievt;
    BXType bx_out;


    // read event and write to memories
    auto &fin_TrackletProjections = tb.files(trackletProjectionPattern);
    for (unsigned int i = 0; i < nTrackletProjections; i++)
      writeMemFromFile<TrackletProjectionMemory<tprojMemType>>(tprojarray[i], fin_TrackletProjections.at(i), ievt);
    auto &fin_AllStub = tb.files(allStubPatternarray);
    for (unsigned int i = 0; i < nAllStub; i++)
      writeMemFromFile<AllStubMemory<stubMemType>>(allstub[i], fin_AllStub.at(i), ievt);
    auto &fin_VMStubs = tb.files(vmStubPatternarray);
    writeMemFromFile<VMStubMemory<vmStubMemType, vmStubMemRZ, kNbitsphibin, kNMatchEngines>>(vmstub, fin_VMStubs.at(0), ievt); // barrel

    // clear allarray, output memories before starting
    for (unsigned int i = 0; i < nFullMatches; i++)
      fullmatcharray[i].clear();

    // Unit Under Test
    TOP_FUNC_(bx, tprojarray.data(), vmstub, allstub.data(), bx_out, fullmatcharray.data());

    bool truncation = false;
    auto &fout_fullmatch = tb.files(fullMatchPattern);
    const auto &fullmatch_names = tb.fileNames(fullMatchPattern);
    
    // compare the computed outputs with the expected ones
    for (unsigned int i = 0; i < fullmatch_names.size(); i++) {
      auto &fout = fout_fullmatch.at(i);
      string label = "FullMatch " + to_string(i);
      err += compareMemWithFile<FullMatchMemory<fmProjMemType> >
        (fullmatcharray[i], fout, ievt, label, truncation);
    }
    
  } // end of event loop
  
  // This is necessary because HLS seems to only return an 8-bit error count,
  // so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;
  
}
