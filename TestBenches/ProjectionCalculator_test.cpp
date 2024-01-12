// Test bench for ProjectionCalculator
#include "ProjectionCalculatorTop.h"

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
  #define TOP_FUNC_ ProjectionCalculator_L1L2C
#endif

// #if !defined SEED_
//   #define SEED_ L3L4_
// #endif
// #if !defined ITC_
//   #define ITC_ A_
// #endif
// #if !defined MODULE_
//   #define MODULE_ TP_L3L4A_
// #endif
// #if !defined TOP_FUNC_
//   #define TOP_FUNC_ ProjectionCalculator_L3L4A
// #endif


const int nevents = 1;  //number of events to run

using namespace std;

int main()
{

 std::cout<<"Module name:" << module_name[MODULE_]<<std::endl;
//
  TBHelper tb(std::string("TP/") + module_name[MODULE_]);
  // error counts

  int err = 0;

    // open input files from emulation
  auto &fin_tpar = tb.files("TrackletParameters*");
  auto &fout_tproj = tb.files("TrackletProjections*");
  const auto &tproj_names = tb.fileNames("TrackletProjections*");

  // input memory 
  TrackletParameterMemory trackletParameters;
  
  // output memories 
  TrackletProjectionMemory<BARRELPS> tproj_barrel_ps[TC::N_PROJOUT_BARRELPS];
  TrackletProjectionMemory<BARREL2S> tproj_barrel_2s[TC::N_PROJOUT_BARREL2S];
  TrackletProjectionMemory<DISK> tproj_disk[TC::N_PROJOUT_DISK];

  // print the input files loaded
  std::cout << "Loaded the input files:\n";

  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // TODO: move loop over tracklet parameters from module to testbench 

    // read event and write to memories
    writeMemFromFile<TrackletParameterMemory>(trackletParameters, fin_tpar.at(0), ievt);

    // clear all output memories before starting
    //tpar.clear();
    for (unsigned i = 0; i < TC::N_PROJOUT_BARRELPS; i++)
      tproj_barrel_ps[i].clear();
    for (unsigned i = 0; i < TC::N_PROJOUT_BARREL2S; i++)
      tproj_barrel_2s[i].clear();
    for (unsigned i = 0; i < TC::N_PROJOUT_DISK; i++)
      tproj_disk[i].clear();

    cout << "Done with clear" << endl;

    // bx
    BXType bx = ievt;
    BXType bx_o;

    // Unit Under Test
    std::cout << "Entries:"<<trackletParameters.getEntries(bx) << std::endl;

    for (int ipar=0; ipar < trackletParameters.getEntries(bx); ipar++) {
      TOP_FUNC_(bx, bx_o, trackletParameters.read_mem(bx,ipar), ipar, tproj_barrel_ps, tproj_barrel_2s, tproj_disk);
    }

    cout << "Done with TOP_FUNC" << endl;

    bool truncation = false;

    // compare the computed outputs with the expected ones
    for (unsigned i = 0; i < tproj_names.size(); i++) {
      const auto &tproj_name = tproj_names.at(i);
      auto &fout = fout_tproj.at(i);
      if (tproj_name.find("_D1PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK>>(tproj_disk[TC::D1PHIA], fout, ievt,
                                                       "\nTrackletProjection (D1PHIA)", truncation);
      else if (tproj_name.find("_D1PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIB], fout, ievt,
                                                       "\nTrackletProjection (D1PHIB)", truncation);
      else if (tproj_name.find("_D1PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHIC], fout, ievt,
                                                       "\nTrackletProjection (D1PHIC)", truncation);
      else if (tproj_name.find("_D1PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D1PHID], fout, ievt,
                                                       "\nTrackletProjection (D1PHID)", truncation);
      else if (tproj_name.find("_D2PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIA], fout, ievt,
                                                       "\nTrackletProjection (D2PHIA)", truncation);
      else if (tproj_name.find("_D2PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIB], fout, ievt,
                                                       "\nTrackletProjection (D2PHIB)", truncation);
      else if (tproj_name.find("_D2PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHIC], fout, ievt,
                                                       "\nTrackletProjection (D2PHIC)", truncation);
      else if (tproj_name.find("_D2PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D2PHID], fout, ievt,
                                                       "\nTrackletProjection (D2PHID)", truncation);
      else if (tproj_name.find("_D3PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHIA], fout, ievt,
                                                       "\nTrackletProjection (D3PHIA)", truncation);
      else if (tproj_name.find("_D3PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHIB], fout, ievt,
                                                       "\nTrackletProjection (D3PHIB)", truncation);
      else if (tproj_name.find("_D3PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHIC], fout, ievt,
                                                       "\nTrackletProjection (D3PHIC)", truncation);
      else if (tproj_name.find("_D3PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D3PHID], fout, ievt,
                                                       "\nTrackletProjection (D3PHID)", truncation);
      else if (tproj_name.find("_D4PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHIA], fout, ievt,
                                                       "\nTrackletProjection (D4PHIA)", truncation);
      else if (tproj_name.find("_D4PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHIB], fout, ievt,
                                                       "\nTrackletProjection (D4PHIB)", truncation);
      else if (tproj_name.find("_D4PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHIC], fout, ievt,
                                                       "\nTrackletProjection (D4PHIC)", truncation);
      else if (tproj_name.find("_D4PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<DISK> >(tproj_disk[TC::D4PHID], fout, ievt,
                                                       "\nTrackletProjection (D4PHID)", truncation);
      else if (tproj_name.find("_L1PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIA], fout, ievt,
                                                       "\nTrackletProjection (L1PHIA)", truncation);
      else if (tproj_name.find("_L1PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIB], fout, ievt,
                                                       "\nTrackletProjection (L1PHIB)", truncation);
      else if (tproj_name.find("_L1PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIC], fout, ievt,
                                                       "\nTrackletProjection (L1PHIC)", truncation);
      else if (tproj_name.find("_L1PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHID], fout, ievt,
                                                       "\nTrackletProjection (L1PHID)", truncation);
      else if (tproj_name.find("_L1PHIE") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIE], fout, ievt,
                                                       "\nTrackletProjection (L1PHIE)", truncation);
      else if (tproj_name.find("_L1PHIF") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIF], fout, ievt,
                                                       "\nTrackletProjection (L1PHIF)", truncation);
      else if (tproj_name.find("_L1PHIG") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIG], fout, ievt,
                                                       "\nTrackletProjection (L1PHIG)", truncation);
      else if (tproj_name.find("_L1PHIH") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L1PHIH], fout, ievt,
                                                       "\nTrackletProjection (L1PHIH)", truncation);
      else if (tproj_name.find("_L2PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIA], fout, ievt,
                                                       "\nTrackletProjection (L2PHIA)", truncation);
      else if (tproj_name.find("_L2PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIB], fout, ievt,
                                                       "\nTrackletProjection (L2PHIB)", truncation);
      else if (tproj_name.find("_L2PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHIC], fout, ievt,
                                                       "\nTrackletProjection (L2PHIC)", truncation);
      else if (tproj_name.find("_L2PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L2PHID], fout, ievt,
                                                       "\nTrackletProjection (L2PHID)", truncation);
      else if (tproj_name.find("_L3PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHIA], fout, ievt,
                                                       "\nTrackletProjection (L3PHIA)", truncation);
      else if (tproj_name.find("_L3PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHIB], fout, ievt,
                                                       "\nTrackletProjection (L3PHIB)", truncation);
      else if (tproj_name.find("_L3PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHIC], fout, ievt,
                                                       "\nTrackletProjection (L3PHIC)", truncation);
      else if (tproj_name.find("_L3PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARRELPS> >(tproj_barrel_ps[TC::L3PHID], fout, ievt,
                                                       "\nTrackletProjection (L3PHID)", truncation);
      else if (tproj_name.find("_L4PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHIA], fout, ievt,
                                                       "\nTrackletProjection (L4PHIA)", truncation);
      else if (tproj_name.find("_L4PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHIB], fout, ievt,
                                                       "\nTrackletProjection (L4PHIB)", truncation);
      else if (tproj_name.find("_L4PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHIC], fout, ievt,
                                                       "\nTrackletProjection (L4PHIC)", truncation);
      else if (tproj_name.find("_L4PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L4PHID], fout, ievt,
                                                       "\nTrackletProjection (L4PHID)", truncation);
      else if (tproj_name.find("_L5PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIA], fout, ievt,
                                                       "\nTrackletProjection (L5PHIA)", truncation);
      else if (tproj_name.find("_L5PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIB], fout, ievt,
                                                       "\nTrackletProjection (L5PHIB)", truncation);
      else if (tproj_name.find("_L5PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHIC], fout, ievt,
                                                       "\nTrackletProjection (L5PHIC)", truncation);
      else if (tproj_name.find("_L5PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L5PHID], fout, ievt,
                                                       "\nTrackletProjection (L5PHID)", truncation);
      else if (tproj_name.find("_L6PHIA") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIA], fout, ievt,
                                                       "\nTrackletProjection (L6PHIA)", truncation);
      else if (tproj_name.find("_L6PHIB") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIB], fout, ievt,
                                                       "\nTrackletProjection (L6PHIB)", truncation);
      else if (tproj_name.find("_L6PHIC") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHIC], fout, ievt,
                                                       "\nTrackletProjection (L6PHIC)", truncation);
      else if (tproj_name.find("_L6PHID") != string::npos)
        err += compareProjMemWithFile<TrackletProjectionMemory<BARREL2S> >(tproj_barrel_2s[TC::L6PHID], fout, ievt,
                                                       "\nTrackletProjection (L6PHID)", truncation);
    
    }
    
    cout << endl;

  } // end of event loop

  // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
  if (err > 255) err = 255;
  return err;

}
