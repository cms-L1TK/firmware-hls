#ifndef TrackQuality_TracktoFeature_H__
#define TrackQuality_TracktoFeature_H__

#include "ap_fixed.h"
#include "BDT.h"
#include "parameters.h"
#include "TrackQualityMemory.h"

void FeatureTransform(const TTTrack& Track, input_arr_t transformed_features) {

    //Proper track parameter representations tbc
    //All track parameters are shown here through strictly only some are needed for this particular model

    auto      InvR        = Track.getInvR();
    auto      Phi         = Track.getPhi();
    auto      TanL        = Track.getTanL();
    auto      Z0          = Track.getZ0();
    auto      D0          = Track.getD0();
    auto      Chi2rphi    = Track.getChi2rphi();
    auto      Chi2rz      = Track.getChi2rz();
    auto      BendChi2    = Track.getBendChi2();
    auto      HitPattern  = Track.getHitPattern();
    auto      MVATQ       = Track.getMVATQ();
    auto      MVAres      = Track.getMVAres();
    auto      TkValid     = Track.getTkValid();

    ap_uint<3> NStub = 0;
    ap_uint<3> tmp_trk_nlaymiss_interior = 0;

    //n_stub calculation

    for (int i = 6; i >= 0; i--) {
     int k = HitPattern >> i;
     if (k & 1)
       NStub ++;
    }

    //n_lay miss calculation TODO verify
    //int lay_i = 0;
    
    //bool seq = false;
    //int nbits = floor(log2(HitPattern)) + 1; //calc num of bits req for num
    //for (int i = 0; i < nbits; i++) {
    //  lay_i = ((1 << i) & HitPattern) >> i;  //0 or 1 in ith bit (right to left)
    //if (lay_i && !seq)
    //  seq = true;  //sequence starts when first 1 found
    //if (!lay_i && seq)
    //  tmp_trk_nlaymiss_interior++;
    //}

    //Shift features to be in line with expected size
    transformed_features[0] = BendChi2*16;
    transformed_features[1] = Chi2rphi*8;
    transformed_features[2] = Chi2rz*8;
    transformed_features[3] = NStub*16;
    transformed_features[4] = InvR/256;
    transformed_features[5] = TanL/512;
    transformed_features[6] = Z0/32;
}


#endif
