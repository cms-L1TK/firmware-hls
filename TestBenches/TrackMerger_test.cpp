// TrackMerger test bench
#include "TrackMergerTop.h"
#include "FileReadUtility.h"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

const int nevents = 100;

using namespace std;

int main(){
    //Error counter
    int err_count = 0;
    
  // Input memories
  TrackFitMemory inputTracks;

  // Output memories
  TrackFitMemory outputTracks;

  // Open input files
  ifstream fin_inputTracks("../../../../../emData/TM/TM_L1L2/TrackFit_BT_L1L2_04.dat");
  assert(fin_inputTracks.good());
  //ifstream fout_outputTracks("../../../../../emData/TM/TM_L1L2/TrackFit_BT_L1L2_04.dat");
  ifstream fout_outputTracks("../../../../../emData/TM/TM_L1L2/TrackFit_PT_L1L2_04.dat");
  assert(fout_outputTracks.good());

  // Loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    outputTracks.clear();

    // Read in next event from input
    writeArrayFromFile<TrackFiMemory> (inputTracks, fin_inputTracks, ievt);

    // Set bunch crossing
    BXType bx = ievt;

    // Unit under test
    TrackMergerTop(bx, inputTracks, outputTracks);

    // Comparing outputs
    err_count += compareMemWithFile<TrackFitMemory>(outputTracks, fout_outputTracks, ievt, "Tracks");

  }

  // Close files
  fin_inputTracks.close();
  fout_outputTracks.close();

  // Handling case of err%256 == 0 
  if (err_count > 255) err_count = 255;
  return err_count;

}
