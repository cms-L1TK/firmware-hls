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
  #define MODULE_ PR_L3PHIC_
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
#if MODULE_ == PR_L1PHIB_ || MODULE_ == PR_L2PHIB_ || MODULE_ == PR_L3PHIB_ || MODULE_ == PR_L1PHIC_ || MODULE_ == PR_L2PHIC_ || MODULE_ == PR_L3PHIC_
  const auto projMemType = BARRELPS;
#elif MODULE_ == PR_L4PHIB_ || MODULE_ == PR_L5PHIB_ || MODULE_ == PR_L6PHIB_ || MODULE_ == PR_L4PHIC_ || MODULE_ == PR_L5PHIC_ || MODULE_ == PR_L6PHIC_
  const auto projMemType = BARREL2S;
#else
  #error "Undefined Module"
#endif

#if MODULE_ == PR_L1PHIB_ || MODULE_ == PR_L2PHIB_ || MODULE_ == PR_L3PHIB_ || MODULE_ == PR_L4PHIB_ || MODULE_ == PR_L5PHIB_ || MODULE_ == PR_L6PHIB_ || MODULE_ == PR_L1PHIC_ || MODULE_ == PR_L2PHIC_ || MODULE_ == PR_L3PHIC_ || MODULE_ == PR_L4PHIC_ || MODULE_ == PR_L5PHIC_ || MODULE_ == PR_L6PHIC_
  const auto vmProjMemType = BARREL;
#else
  #error "Undefined Module"
#endif

#if MODULE_ == PR_L1PHIB_
  TBHelper tb("PR/PR_L1PHIB");
#elif MODULE_ == PR_L2PHIB_
  TBHelper tb("PR/PR_L2PHIB");
#elif MODULE_ == PR_L3PHIB_
  TBHelper tb("PR/PR_L3PHIB");
#elif MODULE_ == PR_L4PHIB_
  TBHelper tb("PR/PR_L4PHIB");
#elif MODULE_ == PR_L5PHIB_
  TBHelper tb("PR/PR_L5PHIB");
#elif MODULE_ == PR_L6PHIB_
  TBHelper tb("PR/PR_L6PHIB");
#elif MODULE_ == PR_L1PHIC_
  TBHelper tb("PR/PR_L1PHIC");
#elif MODULE_ == PR_L2PHIC_
  TBHelper tb("PR/PR_L2PHIC");
#elif MODULE_ == PR_L3PHIC_
  TBHelper tb("PR/PR_L3PHIC");
#elif MODULE_ == PR_L4PHIC_
  TBHelper tb("PR/PR_L4PHIC");
#elif MODULE_ == PR_L5PHIC_
  TBHelper tb("PR/PR_L5PHIC");
#elif MODULE_ == PR_L6PHIC_
  TBHelper tb("PR/PR_L6PHIC");
#else
  #error "Undefined Module"
#endif

  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  const auto nTrackletProjections = tb.nFiles(trackletProjectionPattern);
  vector<TrackletProjectionMemory<projMemType> > tprojarray(nTrackletProjections);

  // output memories
  AllProjectionMemory<projMemType> allproj;
  const auto nVMProjections = tb.nFiles(vmProjectionPattern);
  vector<VMProjectionMemory<vmProjMemType> > vmprojarray(nVMProjections);

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
#if MODULE_ == PR_L1PHIB_
    ProjectionRouterTop_L1PHIB(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L2PHIB_
    ProjectionRouterTop_L2PHIB(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L3PHIB_
    ProjectionRouterTop_L3PHIB(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L4PHIB_
    ProjectionRouterTop_L4PHIB(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L5PHIB_
    ProjectionRouterTop_L5PHIB(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L6PHIB_
    ProjectionRouterTop_L6PHIB(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L1PHIC_
    ProjectionRouterTop_L1PHIC(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L2PHIC_
    ProjectionRouterTop_L2PHIC(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L3PHIC_
    ProjectionRouterTop_L3PHIC(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L4PHIC_
    ProjectionRouterTop_L4PHIC(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L5PHIC_
    ProjectionRouterTop_L5PHIC(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#elif MODULE_ == PR_L6PHIC_
    ProjectionRouterTop_L6PHIC(bx, tprojarray.data(), bx_out, allproj, vmprojarray.data());
#else
  #error "Undefined PR"
#endif

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
