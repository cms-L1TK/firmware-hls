// Test bench for ProjectionRouter
#include "ProjectionRouterTop.h"

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
  #define MODULE_ PR_L6PHIA_
#endif
#if !defined TOP_FUNC_
  #define TOP_FUNC_ ProjectionRouterTop_L6PHIA
#endif

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{
  // Define memory patterns
  const string trackletProjectionPattern = "TrackletProjections*";
  const string allProjectionPattern = "AllProj*";
  const string vmProjectionPattern = "VMProjections*";

  // Define region according to which layer is being tested
  assert(MODULE_ >= PR_L1PHIA_ && MODULE_ <= PR_L6PHID_); // Select for PR modules
  const auto projMemType = (MODULE_ >= PR_L1PHIA_ && MODULE_ <= PR_L3PHID_) ? BARRELPS : BARREL2S;
  const auto vmProjMemType = BARREL;
  TBHelper tb(std::string("PR/") + module_name[MODULE_]);

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  const auto nTrackletProjections = tb.nFiles(trackletProjectionPattern);
  vector<TrackletProjectionMemory<projMemType> > tprojarray(nTrackletProjections);

  // output memories
  AllProjectionMemory<projMemType> allproj;
  const auto nAllProjections = tb.nFiles(allProjectionPattern);
  const auto nVMProjections = tb.nFiles(vmProjectionPattern);
  vector<VMProjectionMemory<vmProjMemType> > vmprojarray(nVMProjections);

  // print the input files loaded
  std::cout << "Loaded the input files:\n";
  for (unsigned i = 0; i < nTrackletProjections; i++)
    std::cout << "\t" << tb.fileNames(trackletProjectionPattern).at(i) << "\n";
  for (unsigned i = 0; i < nVMProjections; i++)
    std::cout << "\t" << tb.fileNames(vmProjectionPattern).at(i) << "\n";
  for (unsigned i = 0; i < nAllProjections; i++)
    std::cout << "\t" << tb.fileNames(allProjectionPattern).at(i) << "\n";
  std::cout << std::endl;

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    auto &fin_TrackletProjections = tb.files(trackletProjectionPattern);
    for (unsigned int i = 0; i < nTrackletProjections; i++)
      writeMemFromFile<TrackletProjectionMemory<projMemType> >(tprojarray[i], fin_TrackletProjections.at(i), ievt);

    // clear all output memories before starting
    allproj.clear();
    for (unsigned int i = 0; i < nVMProjections; i++)
      vmprojarray[i].clear();

    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    TOP_FUNC_(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());

    bool truncation = false;
    auto &fout_aproj = tb.files(allProjectionPattern);
    auto &fout_vmproj = tb.files(vmProjectionPattern);
    const auto &vmproj_names = tb.fileNames(vmProjectionPattern);
    
    // compare the computed outputs with the expected ones
    // AllProjection
    err += compareMemWithFile<AllProjectionMemory<projMemType> >(allproj, fout_aproj.at(0), ievt, "AllProjection", truncation);

    for (unsigned int i = 0; i < vmproj_names.size(); i++) {
      const auto &vmproj_name = vmproj_names.at(i);
      auto &fout = fout_vmproj.at(i);
      string label = "VMProjection " + to_string(i);
      err += compareMemWithFile<VMProjectionMemory<vmProjMemType> >
        (vmprojarray[i], fout, ievt, label, truncation);
    }
    
  } // end of event loop
  
  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
//  cout << "Module actually has " << err << " errors." << endl;
//  return 0;
  return err;
  
}
