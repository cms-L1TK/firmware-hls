#ifndef TrackletAlgorithm_TracktoFeature_H__
#define TrackletAlgorithm_TracktoFeature_H__

#include "ap_fixed.h"
#include "BDT.h"
#include "parameters.h"
#include "TrackQualityMemory.h"

void FeatureTransform(const TTTrack& Track, input_arr_t transformed_features) {

    //Proper track parameter representations tbc
    //All track parameters are shown here through strictly only some are needed for this particular model

    ap_int<15>      InvR        = Track.getInvR();
    ap_int<12>      Phi         = Track.getPhi();
    ap_int<16>      TanL        = Track.getTanL();
    ap_int<12>      Z0          = Track.getZ0();
    ap_fixed<13,5>  D0          = Track.getD0();
    ap_uint<4>      Chi2rphi    = Track.getChi2rphi();
    ap_uint<4>      Chi2rz      = Track.getChi2rz();
    ap_uint<3>      BendChi2    = Track.getBendChi2();
    ap_uint<7>      HitPattern  = Track.getHitPattern();
    ap_uint<3>      MVATQ       = Track.getMVATQ();
    ap_uint<6>      MVAres      = Track.getMVAres();
    ap_uint<1>      TkValid     = Track.getTkValid();

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
