// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __TrackletProcessor_L2L3C_mul_mul_18s_17s_33_1_1__HH__
#define __TrackletProcessor_L2L3C_mul_mul_18s_17s_33_1_1__HH__
#include "ACMP_smul_ss.h"
#include <systemc>

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int dout_WIDTH>
SC_MODULE(TrackletProcessor_L2L3C_mul_mul_18s_17s_33_1_1) {
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    ACMP_smul_ss<ID, 1, din0_WIDTH, din1_WIDTH, dout_WIDTH> ACMP_smul_ss_U;

    SC_CTOR(TrackletProcessor_L2L3C_mul_mul_18s_17s_33_1_1):  ACMP_smul_ss_U ("ACMP_smul_ss_U") {
        ACMP_smul_ss_U.din0(din0);
        ACMP_smul_ss_U.din1(din1);
        ACMP_smul_ss_U.dout(dout);

    }

};

#endif //
