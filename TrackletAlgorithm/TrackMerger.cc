#include "TrackMerger.h"

void TrackMerger(const BXType bx, TrackFitMemory inputTracks, TrackFitMemory &outputTracks){
    ap_uint<kNBits_MemAddr> addr;
    for(ap_uint<kNBits_MemAddr> addr = 0; addr < inputTracks.getEntries(bx); addr++){
        auto track = inputTracks.read_mem(bx, addr);
         outputTracks.write_mem(bx, track, addr);
         
    }



    // Comparison module
    //count stubs in common, looking at stubs with smallest phi residual


    // if there are > 3 stubs in common, merge tracks into single track

    // assign helix params according to best seed type


}