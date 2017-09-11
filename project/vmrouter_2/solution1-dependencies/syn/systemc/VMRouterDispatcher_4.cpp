#include "VMRouterDispatcher.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouterDispatcher::thread_allStubs_0_phi_V_address0() {
    allStubs_0_phi_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_1_reg_5534_pp0_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read())) {
        allStubs_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_phi_V_d0() {
    allStubs_0_phi_V_d0 = curPhi_V_reg_5572.read();
}

void VMRouterDispatcher::thread_allStubs_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
          !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0)))) {
        allStubs_0_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_pt_V_address0() {
    allStubs_0_pt_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_1_reg_5534_pp0_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read())) {
        allStubs_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_pt_V_d0() {
    allStubs_0_pt_V_d0 = redPt_V_reg_5582.read();
}

void VMRouterDispatcher::thread_allStubs_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
          !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0)))) {
        allStubs_0_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_r_V_address0() {
    allStubs_0_r_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_1_reg_5534_pp0_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read())) {
        allStubs_0_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_r_V_d0() {
    allStubs_0_r_V_d0 = curR_V_reg_5577.read();
}

void VMRouterDispatcher::thread_allStubs_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
          !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0)))) {
        allStubs_0_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_z_V_address0() {
    allStubs_0_z_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_1_reg_5534_pp0_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read())) {
        allStubs_0_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_0_z_V_d0() {
    allStubs_0_z_V_d0 = curZ_V_reg_5567.read();
}

void VMRouterDispatcher::thread_allStubs_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
          !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0)))) {
        allStubs_0_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_phi_V_address0() {
    allStubs_1_phi_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_6_reg_5629_pp1_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read())) {
        allStubs_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_phi_V_d0() {
    allStubs_1_phi_V_d0 = curPhi_V_1_reg_5667.read();
}

void VMRouterDispatcher::thread_allStubs_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read())))) {
        allStubs_1_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_pt_V_address0() {
    allStubs_1_pt_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_6_reg_5629_pp1_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read())) {
        allStubs_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_pt_V_d0() {
    allStubs_1_pt_V_d0 = redPt_V_1_reg_5677.read();
}

void VMRouterDispatcher::thread_allStubs_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read())))) {
        allStubs_1_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_r_V_address0() {
    allStubs_1_r_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_6_reg_5629_pp1_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read())) {
        allStubs_1_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_r_V_d0() {
    allStubs_1_r_V_d0 = curR_V_1_reg_5672.read();
}

void VMRouterDispatcher::thread_allStubs_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read())))) {
        allStubs_1_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_z_V_address0() {
    allStubs_1_z_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_6_reg_5629_pp1_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read())) {
        allStubs_1_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_1_z_V_d0() {
    allStubs_1_z_V_d0 = curZ_V_1_reg_5662.read();
}

void VMRouterDispatcher::thread_allStubs_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read())))) {
        allStubs_1_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_phi_V_address0() {
    allStubs_2_phi_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_3_reg_5724_pp2_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read())) {
        allStubs_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_phi_V_d0() {
    allStubs_2_phi_V_d0 = curPhi_V_2_reg_5762.read();
}

void VMRouterDispatcher::thread_allStubs_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read())))) {
        allStubs_2_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_pt_V_address0() {
    allStubs_2_pt_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_3_reg_5724_pp2_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read())) {
        allStubs_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_pt_V_d0() {
    allStubs_2_pt_V_d0 = redPt_V_2_reg_5772.read();
}

void VMRouterDispatcher::thread_allStubs_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read())))) {
        allStubs_2_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_r_V_address0() {
    allStubs_2_r_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_3_reg_5724_pp2_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read())) {
        allStubs_2_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_r_V_d0() {
    allStubs_2_r_V_d0 = curR_V_2_reg_5767.read();
}

void VMRouterDispatcher::thread_allStubs_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read())))) {
        allStubs_2_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_z_V_address0() {
    allStubs_2_z_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_3_reg_5724_pp2_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read())) {
        allStubs_2_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_2_z_V_d0() {
    allStubs_2_z_V_d0 = curZ_V_2_reg_5757.read();
}

void VMRouterDispatcher::thread_allStubs_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read())))) {
        allStubs_2_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_phi_V_address0() {
    allStubs_3_phi_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_5_reg_5819_pp3_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read())) {
        allStubs_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_phi_V_d0() {
    allStubs_3_phi_V_d0 = curPhi_V_3_reg_5857.read();
}

void VMRouterDispatcher::thread_allStubs_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read())))) {
        allStubs_3_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_pt_V_address0() {
    allStubs_3_pt_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_5_reg_5819_pp3_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read())) {
        allStubs_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_pt_V_d0() {
    allStubs_3_pt_V_d0 = redPt_V_3_reg_5867.read();
}

void VMRouterDispatcher::thread_allStubs_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read())))) {
        allStubs_3_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_r_V_address0() {
    allStubs_3_r_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_5_reg_5819_pp3_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read())) {
        allStubs_3_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_r_V_d0() {
    allStubs_3_r_V_d0 = curR_V_3_reg_5862.read();
}

void VMRouterDispatcher::thread_allStubs_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read())))) {
        allStubs_3_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_z_V_address0() {
    allStubs_3_z_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_5_reg_5819_pp3_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read())) {
        allStubs_3_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_3_z_V_d0() {
    allStubs_3_z_V_d0 = curZ_V_3_reg_5852.read();
}

void VMRouterDispatcher::thread_allStubs_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read())))) {
        allStubs_3_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_phi_V_address0() {
    allStubs_4_phi_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_8_reg_5914_pp4_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read())) {
        allStubs_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_phi_V_d0() {
    allStubs_4_phi_V_d0 = curPhi_V_4_reg_5952.read();
}

void VMRouterDispatcher::thread_allStubs_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read())))) {
        allStubs_4_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_pt_V_address0() {
    allStubs_4_pt_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_8_reg_5914_pp4_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read())) {
        allStubs_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_pt_V_d0() {
    allStubs_4_pt_V_d0 = redPt_V_4_reg_5962.read();
}

void VMRouterDispatcher::thread_allStubs_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read())))) {
        allStubs_4_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_r_V_address0() {
    allStubs_4_r_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_8_reg_5914_pp4_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read())) {
        allStubs_4_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_r_V_d0() {
    allStubs_4_r_V_d0 = curR_V_4_reg_5957.read();
}

void VMRouterDispatcher::thread_allStubs_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read())))) {
        allStubs_4_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_z_V_address0() {
    allStubs_4_z_V_address0 =  (sc_lv<6>) (ap_reg_ppstg_p_8_reg_5914_pp4_iter1.read());
}

void VMRouterDispatcher::thread_allStubs_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read())) {
        allStubs_4_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_allStubs_4_z_V_d0() {
    allStubs_4_z_V_d0 = curZ_V_4_reg_5947.read();
}

void VMRouterDispatcher::thread_allStubs_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read())))) {
        allStubs_4_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_done() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st26_fsm_10.read())) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st26_fsm_10.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_1826() {
    ap_sig_1826 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(1, 1));
}

void VMRouterDispatcher::thread_ap_sig_1846() {
    ap_sig_1846 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(3, 3));
}

void VMRouterDispatcher::thread_ap_sig_1866() {
    ap_sig_1866 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(5, 5));
}

void VMRouterDispatcher::thread_ap_sig_1886() {
    ap_sig_1886 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(7, 7));
}

void VMRouterDispatcher::thread_ap_sig_1906() {
    ap_sig_1906 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(9, 9));
}

void VMRouterDispatcher::thread_ap_sig_2185() {
    ap_sig_2185 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(2, 2));
}

void VMRouterDispatcher::thread_ap_sig_2245() {
    ap_sig_2245 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(4, 4));
}

void VMRouterDispatcher::thread_ap_sig_2305() {
    ap_sig_2305 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(6, 6));
}

void VMRouterDispatcher::thread_ap_sig_2365() {
    ap_sig_2365 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(8, 8));
}

void VMRouterDispatcher::thread_ap_sig_26() {
    ap_sig_26 = esl_seteq<1,1,1>(ap_CS_fsm.read().range(0, 0), ap_const_lv1_1);
}

void VMRouterDispatcher::thread_ap_sig_3471() {
    ap_sig_3471 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(10, 10));
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_pp0_stg0_fsm_1() {
    if (ap_sig_1826.read()) {
        ap_sig_cseq_ST_pp0_stg0_fsm_1 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp0_stg0_fsm_1 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_pp1_stg0_fsm_3() {
    if (ap_sig_1846.read()) {
        ap_sig_cseq_ST_pp1_stg0_fsm_3 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp1_stg0_fsm_3 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_pp2_stg0_fsm_5() {
    if (ap_sig_1866.read()) {
        ap_sig_cseq_ST_pp2_stg0_fsm_5 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp2_stg0_fsm_5 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_pp3_stg0_fsm_7() {
    if (ap_sig_1886.read()) {
        ap_sig_cseq_ST_pp3_stg0_fsm_7 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp3_stg0_fsm_7 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_pp4_stg0_fsm_9() {
    if (ap_sig_1906.read()) {
        ap_sig_cseq_ST_pp4_stg0_fsm_9 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp4_stg0_fsm_9 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_st11_fsm_4() {
    if (ap_sig_2245.read()) {
        ap_sig_cseq_ST_st11_fsm_4 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st11_fsm_4 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_st16_fsm_6() {
    if (ap_sig_2305.read()) {
        ap_sig_cseq_ST_st16_fsm_6 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st16_fsm_6 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_st1_fsm_0() {
    if (ap_sig_26.read()) {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_st21_fsm_8() {
    if (ap_sig_2365.read()) {
        ap_sig_cseq_ST_st21_fsm_8 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st21_fsm_8 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_st26_fsm_10() {
    if (ap_sig_3471.read()) {
        ap_sig_cseq_ST_st26_fsm_10 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st26_fsm_10 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_ap_sig_cseq_ST_st6_fsm_2() {
    if (ap_sig_2185.read()) {
        ap_sig_cseq_ST_st6_fsm_2 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st6_fsm_2 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write = ap_reg_ppstg_p_7_reg_4174_pp4_iter1.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write = ap_reg_ppstg_p_4_reg_4151_pp3_iter1.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write = ap_reg_ppstg_p_2_reg_4128_pp2_iter1.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write = ap_reg_ppstg_p_0_reg_4105_pp1_iter1.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write = ap_reg_ppstg_p_s_reg_4082_pp0_iter1.read();
    } else {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_index_V_write = "XXXXXX";
    }
}

void VMRouterDispatcher::thread_grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write = redPhi_V_4_reg_5973.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write = redPhi_V_3_reg_5878.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write = redPhi_V_2_reg_5783.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write = redPhi_V_1_reg_5688.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write = redPhi_V_reg_5593.read();
    } else {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_phi_V_write =  (sc_lv<3>) ("XXX");
    }
}

void VMRouterDispatcher::thread_grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write = redPt_V_4_reg_5962.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write = redPt_V_3_reg_5867.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write = redPt_V_2_reg_5772.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write = redPt_V_1_reg_5677.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write = redPt_V_reg_5582.read();
    } else {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_pt_V_write =  (sc_lv<3>) ("XXX");
    }
}

void VMRouterDispatcher::thread_grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write = redR_V_4_reg_5978.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write = redR_V_3_reg_5883.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write = redR_V_2_reg_5788.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write = redR_V_1_reg_5693.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write = redR_V_reg_5598.read();
    } else {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_r_V_write =  (sc_lv<2>) ("XX");
    }
}

void VMRouterDispatcher::thread_grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write = redZ_V_4_reg_5968.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write = redZ_V_3_reg_5873.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write = redZ_V_2_reg_5778.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
                 esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write = redZ_V_1_reg_5683.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0)) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
                 !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
                 esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())))) {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write = redZ_V_reg_5588.read();
    } else {
        grp_VMRouterDispatcher_AddStub_fu_4197_HLSReducedStubLayer_z_V_write =  (sc_lv<4>) ("XXXX");
    }
}

void VMRouterDispatcher::thread_i_0_i1_cast_fu_4465_p1() {
    i_0_i1_cast_fu_4465_p1 = esl_zext<32,7>(i_0_i1_reg_4094.read());
}

void VMRouterDispatcher::thread_i_0_i2_cast8_fu_4678_p1() {
    i_0_i2_cast8_fu_4678_p1 = esl_zext<32,7>(i_0_i2_reg_4117.read());
}

void VMRouterDispatcher::thread_i_0_i3_cast6_fu_4891_p1() {
    i_0_i3_cast6_fu_4891_p1 = esl_zext<32,7>(i_0_i3_reg_4140.read());
}

void VMRouterDispatcher::thread_i_0_i6_cast4_fu_5104_p1() {
    i_0_i6_cast4_fu_5104_p1 = esl_zext<32,7>(i_0_i6_reg_4163.read());
}

void VMRouterDispatcher::thread_i_0_i_cast2_fu_5317_p1() {
    i_0_i_cast2_fu_5317_p1 = esl_zext<32,7>(i_0_i_reg_4186.read());
}

void VMRouterDispatcher::thread_i_1_fu_4695_p2() {
    i_1_fu_4695_p2 = (!i_0_i2_reg_4117.read().is_01() || !ap_const_lv7_1.is_01())? sc_lv<7>(): (sc_biguint<7>(i_0_i2_reg_4117.read()) + sc_biguint<7>(ap_const_lv7_1));
}

void VMRouterDispatcher::thread_i_2_fu_4908_p2() {
    i_2_fu_4908_p2 = (!i_0_i3_reg_4140.read().is_01() || !ap_const_lv7_1.is_01())? sc_lv<7>(): (sc_biguint<7>(i_0_i3_reg_4140.read()) + sc_biguint<7>(ap_const_lv7_1));
}

void VMRouterDispatcher::thread_i_3_fu_5121_p2() {
    i_3_fu_5121_p2 = (!i_0_i6_reg_4163.read().is_01() || !ap_const_lv7_1.is_01())? sc_lv<7>(): (sc_biguint<7>(i_0_i6_reg_4163.read()) + sc_biguint<7>(ap_const_lv7_1));
}

void VMRouterDispatcher::thread_i_4_fu_5334_p2() {
    i_4_fu_5334_p2 = (!i_0_i_reg_4186.read().is_01() || !ap_const_lv7_1.is_01())? sc_lv<7>(): (sc_biguint<7>(i_0_i_reg_4186.read()) + sc_biguint<7>(ap_const_lv7_1));
}

void VMRouterDispatcher::thread_i_fu_4482_p2() {
    i_fu_4482_p2 = (!i_0_i1_reg_4094.read().is_01() || !ap_const_lv7_1.is_01())? sc_lv<7>(): (sc_biguint<7>(i_0_i1_reg_4094.read()) + sc_biguint<7>(ap_const_lv7_1));
}

void VMRouterDispatcher::thread_index_V_1_fu_4672_p2() {
    index_V_1_fu_4672_p2 = (!p_0_phi_fu_4109_p4.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(p_0_phi_fu_4109_p4.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_index_V_2_fu_4885_p2() {
    index_V_2_fu_4885_p2 = (!p_2_phi_fu_4132_p4.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(p_2_phi_fu_4132_p4.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_index_V_3_fu_5098_p2() {
    index_V_3_fu_5098_p2 = (!p_4_phi_fu_4155_p4.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(p_4_phi_fu_4155_p4.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_index_V_4_fu_5311_p2() {
    index_V_4_fu_5311_p2 = (!p_7_phi_fu_4178_p4.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(p_7_phi_fu_4178_p4.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_index_V_fu_4459_p2() {
    index_V_fu_4459_p2 = (!p_s_phi_fu_4086_p4.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(p_s_phi_fu_4086_p4.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_nPH1Z1_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH1Z1_0_V_o = tmp_7_fu_4593_p2.read();
    } else {
        nPH1Z1_0_V_o = nPH1Z1_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z1_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH1Z1_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z1_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z1_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH1Z1_1_V_o = tmp_19_fu_4806_p2.read();
    } else {
        nPH1Z1_1_V_o = nPH1Z1_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z1_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH1Z1_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z1_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z1_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH1Z1_2_V_o = tmp_29_fu_5019_p2.read();
    } else {
        nPH1Z1_2_V_o = nPH1Z1_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z1_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH1Z1_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z1_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z1_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH1Z1_3_V_o = tmp_40_fu_5232_p2.read();
    } else {
        nPH1Z1_3_V_o = nPH1Z1_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z1_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH1Z1_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z1_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z1_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH1Z1_4_V_o = tmp_48_fu_5445_p2.read();
    } else {
        nPH1Z1_4_V_o = nPH1Z1_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z1_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH1Z1_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z1_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z1_V_load1_fu_4584_p1() {
    nPH1Z1_V_load1_fu_4584_p1 = esl_zext<64,6>(nPH1Z1_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH1Z2_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH1Z2_0_V_o = tmp_3_fu_4657_p2.read();
    } else {
        nPH1Z2_0_V_o = nPH1Z2_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z2_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH1Z2_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z2_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z2_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH1Z2_1_V_o = tmp_12_fu_4870_p2.read();
    } else {
        nPH1Z2_1_V_o = nPH1Z2_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z2_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH1Z2_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z2_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z2_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH1Z2_2_V_o = tmp_23_fu_5083_p2.read();
    } else {
        nPH1Z2_2_V_o = nPH1Z2_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z2_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH1Z2_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z2_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z2_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH1Z2_3_V_o = tmp_33_fu_5296_p2.read();
    } else {
        nPH1Z2_3_V_o = nPH1Z2_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z2_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH1Z2_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z2_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z2_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH1Z2_4_V_o = tmp_44_fu_5509_p2.read();
    } else {
        nPH1Z2_4_V_o = nPH1Z2_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH1Z2_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH1Z2_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH1Z2_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH1Z2_V_load1_fu_4648_p1() {
    nPH1Z2_V_load1_fu_4648_p1 = esl_zext<64,6>(nPH1Z2_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH2Z1_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH2Z1_0_V_o = tmp_9_fu_4577_p2.read();
    } else {
        nPH2Z1_0_V_o = nPH2Z1_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z1_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH2Z1_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z1_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z1_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH2Z1_1_V_o = tmp_20_fu_4790_p2.read();
    } else {
        nPH2Z1_1_V_o = nPH2Z1_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z1_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH2Z1_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z1_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z1_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH2Z1_2_V_o = tmp_30_fu_5003_p2.read();
    } else {
        nPH2Z1_2_V_o = nPH2Z1_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z1_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH2Z1_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z1_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z1_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH2Z1_3_V_o = tmp_41_fu_5216_p2.read();
    } else {
        nPH2Z1_3_V_o = nPH2Z1_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z1_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH2Z1_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z1_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z1_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH2Z1_4_V_o = tmp_49_fu_5429_p2.read();
    } else {
        nPH2Z1_4_V_o = nPH2Z1_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z1_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH2Z1_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z1_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z1_V_load_fu_4568_p1() {
    nPH2Z1_V_load_fu_4568_p1 = esl_zext<64,6>(nPH2Z1_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH2Z2_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH2Z2_0_V_o = tmp_4_fu_4641_p2.read();
    } else {
        nPH2Z2_0_V_o = nPH2Z2_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z2_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH2Z2_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z2_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z2_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH2Z2_1_V_o = tmp_16_fu_4854_p2.read();
    } else {
        nPH2Z2_1_V_o = nPH2Z2_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z2_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH2Z2_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z2_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z2_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH2Z2_2_V_o = tmp_24_fu_5067_p2.read();
    } else {
        nPH2Z2_2_V_o = nPH2Z2_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z2_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH2Z2_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z2_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z2_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH2Z2_3_V_o = tmp_34_fu_5280_p2.read();
    } else {
        nPH2Z2_3_V_o = nPH2Z2_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z2_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH2Z2_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z2_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z2_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH2Z2_4_V_o = tmp_45_fu_5493_p2.read();
    } else {
        nPH2Z2_4_V_o = nPH2Z2_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH2Z2_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH2Z2_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH2Z2_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH2Z2_V_load_fu_4632_p1() {
    nPH2Z2_V_load_fu_4632_p1 = esl_zext<64,6>(nPH2Z2_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH3Z1_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH3Z1_0_V_o = tmp_10_fu_4561_p2.read();
    } else {
        nPH3Z1_0_V_o = nPH3Z1_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z1_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH3Z1_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z1_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z1_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH3Z1_1_V_o = tmp_21_fu_4774_p2.read();
    } else {
        nPH3Z1_1_V_o = nPH3Z1_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z1_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH3Z1_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z1_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z1_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH3Z1_2_V_o = tmp_31_fu_4987_p2.read();
    } else {
        nPH3Z1_2_V_o = nPH3Z1_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z1_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH3Z1_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z1_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z1_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH3Z1_3_V_o = tmp_42_fu_5200_p2.read();
    } else {
        nPH3Z1_3_V_o = nPH3Z1_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z1_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH3Z1_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z1_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z1_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH3Z1_4_V_o = tmp_50_fu_5413_p2.read();
    } else {
        nPH3Z1_4_V_o = nPH3Z1_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z1_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH3Z1_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z1_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z1_V_load1_fu_4552_p1() {
    nPH3Z1_V_load1_fu_4552_p1 = esl_zext<64,6>(nPH3Z1_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH3Z2_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH3Z2_0_V_o = tmp_5_fu_4625_p2.read();
    } else {
        nPH3Z2_0_V_o = nPH3Z2_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z2_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH3Z2_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z2_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z2_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH3Z2_1_V_o = tmp_17_fu_4838_p2.read();
    } else {
        nPH3Z2_1_V_o = nPH3Z2_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z2_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH3Z2_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z2_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z2_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH3Z2_2_V_o = tmp_27_fu_5051_p2.read();
    } else {
        nPH3Z2_2_V_o = nPH3Z2_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z2_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH3Z2_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z2_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z2_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH3Z2_3_V_o = tmp_38_fu_5264_p2.read();
    } else {
        nPH3Z2_3_V_o = nPH3Z2_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z2_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH3Z2_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z2_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z2_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH3Z2_4_V_o = tmp_46_fu_5477_p2.read();
    } else {
        nPH3Z2_4_V_o = nPH3Z2_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH3Z2_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH3Z2_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH3Z2_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH3Z2_V_load1_fu_4616_p1() {
    nPH3Z2_V_load1_fu_4616_p1 = esl_zext<64,6>(nPH3Z2_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH4Z1_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH4Z1_0_V_o = tmp_11_fu_4545_p2.read();
    } else {
        nPH4Z1_0_V_o = nPH4Z1_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z1_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()))) {
        nPH4Z1_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z1_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z1_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH4Z1_1_V_o = tmp_22_fu_4758_p2.read();
    } else {
        nPH4Z1_1_V_o = nPH4Z1_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z1_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()))) {
        nPH4Z1_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z1_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z1_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH4Z1_2_V_o = tmp_32_fu_4971_p2.read();
    } else {
        nPH4Z1_2_V_o = nPH4Z1_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z1_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()))) {
        nPH4Z1_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z1_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z1_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH4Z1_3_V_o = tmp_43_fu_5184_p2.read();
    } else {
        nPH4Z1_3_V_o = nPH4Z1_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z1_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()))) {
        nPH4Z1_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z1_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z1_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH4Z1_4_V_o = tmp_51_fu_5397_p2.read();
    } else {
        nPH4Z1_4_V_o = nPH4Z1_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z1_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()))) {
        nPH4Z1_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z1_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z1_V_load_fu_4536_p1() {
    nPH4Z1_V_load_fu_4536_p1 = esl_zext<64,6>(nPH4Z1_0_V_i.read());
}

void VMRouterDispatcher::thread_nPH4Z2_0_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH4Z2_0_V_o = tmp_6_fu_4609_p2.read();
    } else {
        nPH4Z2_0_V_o = nPH4Z2_0_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z2_0_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()))) {
        nPH4Z2_0_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z2_0_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z2_1_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH4Z2_1_V_o = tmp_18_fu_4822_p2.read();
    } else {
        nPH4Z2_1_V_o = nPH4Z2_1_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z2_1_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()))) {
        nPH4Z2_1_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z2_1_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z2_2_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH4Z2_2_V_o = tmp_28_fu_5035_p2.read();
    } else {
        nPH4Z2_2_V_o = nPH4Z2_2_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z2_2_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()))) {
        nPH4Z2_2_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z2_2_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z2_3_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH4Z2_3_V_o = tmp_39_fu_5248_p2.read();
    } else {
        nPH4Z2_3_V_o = nPH4Z2_3_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z2_3_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()))) {
        nPH4Z2_3_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z2_3_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z2_4_V_o() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH4Z2_4_V_o = tmp_47_fu_5461_p2.read();
    } else {
        nPH4Z2_4_V_o = nPH4Z2_4_V_i.read();
    }
}

void VMRouterDispatcher::thread_nPH4Z2_4_V_o_ap_vld() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
         esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()))) {
        nPH4Z2_4_V_o_ap_vld = ap_const_logic_1;
    } else {
        nPH4Z2_4_V_o_ap_vld = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_nPH4Z2_V_load_fu_4600_p1() {
    nPH4Z2_V_load_fu_4600_p1 = esl_zext<64,6>(nPH4Z2_0_V_i.read());
}

void VMRouterDispatcher::thread_newIndex10_fu_4978_p1() {
    newIndex10_fu_4978_p1 = esl_zext<64,6>(nPH3Z1_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex11_fu_4962_p1() {
    newIndex11_fu_4962_p1 = esl_zext<64,6>(nPH4Z1_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex12_fu_5074_p1() {
    newIndex12_fu_5074_p1 = esl_zext<64,6>(nPH1Z2_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex13_fu_5058_p1() {
    newIndex13_fu_5058_p1 = esl_zext<64,6>(nPH2Z2_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex14_fu_5042_p1() {
    newIndex14_fu_5042_p1 = esl_zext<64,6>(nPH3Z2_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex15_fu_5026_p1() {
    newIndex15_fu_5026_p1 = esl_zext<64,6>(nPH4Z2_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex16_fu_5223_p1() {
    newIndex16_fu_5223_p1 = esl_zext<64,6>(nPH1Z1_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex17_fu_5207_p1() {
    newIndex17_fu_5207_p1 = esl_zext<64,6>(nPH2Z1_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex18_fu_5191_p1() {
    newIndex18_fu_5191_p1 = esl_zext<64,6>(nPH3Z1_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex19_fu_5175_p1() {
    newIndex19_fu_5175_p1 = esl_zext<64,6>(nPH4Z1_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex1_fu_4781_p1() {
    newIndex1_fu_4781_p1 = esl_zext<64,6>(nPH2Z1_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex20_fu_5287_p1() {
    newIndex20_fu_5287_p1 = esl_zext<64,6>(nPH1Z2_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex21_fu_5271_p1() {
    newIndex21_fu_5271_p1 = esl_zext<64,6>(nPH2Z2_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex22_fu_5255_p1() {
    newIndex22_fu_5255_p1 = esl_zext<64,6>(nPH3Z2_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex23_fu_5239_p1() {
    newIndex23_fu_5239_p1 = esl_zext<64,6>(nPH4Z2_3_V_i.read());
}

void VMRouterDispatcher::thread_newIndex24_fu_5436_p1() {
    newIndex24_fu_5436_p1 = esl_zext<64,6>(nPH1Z1_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex25_fu_5420_p1() {
    newIndex25_fu_5420_p1 = esl_zext<64,6>(nPH2Z1_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex26_fu_5404_p1() {
    newIndex26_fu_5404_p1 = esl_zext<64,6>(nPH3Z1_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex27_fu_5388_p1() {
    newIndex27_fu_5388_p1 = esl_zext<64,6>(nPH4Z1_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex28_fu_5500_p1() {
    newIndex28_fu_5500_p1 = esl_zext<64,6>(nPH1Z2_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex29_fu_5484_p1() {
    newIndex29_fu_5484_p1 = esl_zext<64,6>(nPH2Z2_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex2_fu_4765_p1() {
    newIndex2_fu_4765_p1 = esl_zext<64,6>(nPH3Z1_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex30_fu_5468_p1() {
    newIndex30_fu_5468_p1 = esl_zext<64,6>(nPH3Z2_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex31_fu_5452_p1() {
    newIndex31_fu_5452_p1 = esl_zext<64,6>(nPH4Z2_4_V_i.read());
}

void VMRouterDispatcher::thread_newIndex3_fu_4749_p1() {
    newIndex3_fu_4749_p1 = esl_zext<64,6>(nPH4Z1_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex4_fu_4861_p1() {
    newIndex4_fu_4861_p1 = esl_zext<64,6>(nPH1Z2_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex5_fu_4845_p1() {
    newIndex5_fu_4845_p1 = esl_zext<64,6>(nPH2Z2_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex6_fu_4829_p1() {
    newIndex6_fu_4829_p1 = esl_zext<64,6>(nPH3Z2_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex7_fu_4813_p1() {
    newIndex7_fu_4813_p1 = esl_zext<64,6>(nPH4Z2_1_V_i.read());
}

void VMRouterDispatcher::thread_newIndex8_fu_5010_p1() {
    newIndex8_fu_5010_p1 = esl_zext<64,6>(nPH1Z1_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex9_fu_4994_p1() {
    newIndex9_fu_4994_p1 = esl_zext<64,6>(nPH2Z1_2_V_i.read());
}

void VMRouterDispatcher::thread_newIndex_fu_4797_p1() {
    newIndex_fu_4797_p1 = esl_zext<64,6>(nPH1Z1_1_V_i.read());
}

void VMRouterDispatcher::thread_p_0_phi_fu_4109_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_reg_5625.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_reg_5616.read()))) {
        p_0_phi_fu_4109_p4 = index_V_1_reg_5620.read();
    } else {
        p_0_phi_fu_4109_p4 = p_0_reg_4105.read();
    }
}

void VMRouterDispatcher::thread_p_1_fu_4474_p1() {
    p_1_fu_4474_p1 = esl_zext<64,6>(p_s_phi_fu_4086_p4.read());
}

void VMRouterDispatcher::thread_p_2_phi_fu_4132_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_reg_5720.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_reg_5711.read()))) {
        p_2_phi_fu_4132_p4 = index_V_2_reg_5715.read();
    } else {
        p_2_phi_fu_4132_p4 = p_2_reg_4128.read();
    }
}

void VMRouterDispatcher::thread_p_3_fu_4900_p1() {
    p_3_fu_4900_p1 = esl_zext<64,6>(p_2_phi_fu_4132_p4.read());
}

void VMRouterDispatcher::thread_p_4_phi_fu_4155_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_reg_5815.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_reg_5806.read()))) {
        p_4_phi_fu_4155_p4 = index_V_3_reg_5810.read();
    } else {
        p_4_phi_fu_4155_p4 = p_4_reg_4151.read();
    }
}

void VMRouterDispatcher::thread_p_5_fu_5113_p1() {
    p_5_fu_5113_p1 = esl_zext<64,6>(p_4_phi_fu_4155_p4.read());
}

void VMRouterDispatcher::thread_p_6_fu_4687_p1() {
    p_6_fu_4687_p1 = esl_zext<64,6>(p_0_phi_fu_4109_p4.read());
}

void VMRouterDispatcher::thread_p_7_phi_fu_4178_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_reg_5910.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_reg_5901.read()))) {
        p_7_phi_fu_4178_p4 = index_V_4_reg_5905.read();
    } else {
        p_7_phi_fu_4178_p4 = p_7_reg_4174.read();
    }
}

void VMRouterDispatcher::thread_p_8_fu_5326_p1() {
    p_8_fu_5326_p1 = esl_zext<64,6>(p_7_phi_fu_4178_p4.read());
}

void VMRouterDispatcher::thread_p_s_phi_fu_4086_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()) && 
         !esl_seteq<1,1,1>(tmp_1_reg_5530.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_reg_5521.read()))) {
        p_s_phi_fu_4086_p4 = index_V_reg_5525.read();
    } else {
        p_s_phi_fu_4086_p4 = p_s_reg_4082.read();
    }
}

void VMRouterDispatcher::thread_stubsInLayer_0_phi_V_address0() {
    stubsInLayer_0_phi_V_address0 =  (sc_lv<6>) (p_1_fu_4474_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_0_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()))) {
        stubsInLayer_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_0_pt_V_address0() {
    stubsInLayer_0_pt_V_address0 =  (sc_lv<6>) (p_1_fu_4474_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()))) {
        stubsInLayer_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_0_r_V_address0() {
    stubsInLayer_0_r_V_address0 =  (sc_lv<6>) (p_1_fu_4474_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()))) {
        stubsInLayer_0_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_0_z_V_address0() {
    stubsInLayer_0_z_V_address0 =  (sc_lv<6>) (p_1_fu_4474_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()))) {
        stubsInLayer_0_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_1_phi_V_address0() {
    stubsInLayer_1_phi_V_address0 =  (sc_lv<6>) (p_6_fu_4687_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_1_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()))) {
        stubsInLayer_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_1_pt_V_address0() {
    stubsInLayer_1_pt_V_address0 =  (sc_lv<6>) (p_6_fu_4687_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_1_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()))) {
        stubsInLayer_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_1_r_V_address0() {
    stubsInLayer_1_r_V_address0 =  (sc_lv<6>) (p_6_fu_4687_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_1_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()))) {
        stubsInLayer_1_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_1_z_V_address0() {
    stubsInLayer_1_z_V_address0 =  (sc_lv<6>) (p_6_fu_4687_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_1_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()))) {
        stubsInLayer_1_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_2_phi_V_address0() {
    stubsInLayer_2_phi_V_address0 =  (sc_lv<6>) (p_3_fu_4900_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_2_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()))) {
        stubsInLayer_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_2_pt_V_address0() {
    stubsInLayer_2_pt_V_address0 =  (sc_lv<6>) (p_3_fu_4900_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_2_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()))) {
        stubsInLayer_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_2_r_V_address0() {
    stubsInLayer_2_r_V_address0 =  (sc_lv<6>) (p_3_fu_4900_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_2_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()))) {
        stubsInLayer_2_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_2_z_V_address0() {
    stubsInLayer_2_z_V_address0 =  (sc_lv<6>) (p_3_fu_4900_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_2_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()))) {
        stubsInLayer_2_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_3_phi_V_address0() {
    stubsInLayer_3_phi_V_address0 =  (sc_lv<6>) (p_5_fu_5113_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_3_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()))) {
        stubsInLayer_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_3_pt_V_address0() {
    stubsInLayer_3_pt_V_address0 =  (sc_lv<6>) (p_5_fu_5113_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()))) {
        stubsInLayer_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_3_r_V_address0() {
    stubsInLayer_3_r_V_address0 =  (sc_lv<6>) (p_5_fu_5113_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()))) {
        stubsInLayer_3_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_3_z_V_address0() {
    stubsInLayer_3_z_V_address0 =  (sc_lv<6>) (p_5_fu_5113_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()))) {
        stubsInLayer_3_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_4_phi_V_address0() {
    stubsInLayer_4_phi_V_address0 =  (sc_lv<6>) (p_8_fu_5326_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_4_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()))) {
        stubsInLayer_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_4_pt_V_address0() {
    stubsInLayer_4_pt_V_address0 =  (sc_lv<6>) (p_8_fu_5326_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()))) {
        stubsInLayer_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_4_r_V_address0() {
    stubsInLayer_4_r_V_address0 =  (sc_lv<6>) (p_8_fu_5326_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()))) {
        stubsInLayer_4_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_stubsInLayer_4_z_V_address0() {
    stubsInLayer_4_z_V_address0 =  (sc_lv<6>) (p_8_fu_5326_p1.read());
}

void VMRouterDispatcher::thread_stubsInLayer_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()))) {
        stubsInLayer_4_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_tmp_10_fu_4561_p2() {
    tmp_10_fu_4561_p2 = (!nPH3Z1_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z1_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_11_fu_4545_p2() {
    tmp_11_fu_4545_p2 = (!nPH4Z1_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z1_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_12_fu_4870_p2() {
    tmp_12_fu_4870_p2 = (!nPH1Z2_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z2_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_13_fu_4664_p3() {
    tmp_13_fu_4664_p3 = i_0_i2_reg_4117.read().range(6, 6);
}

void VMRouterDispatcher::thread_tmp_15_fu_4895_p2() {
    tmp_15_fu_4895_p2 = (!i_0_i3_cast6_fu_4891_p1.read().is_01() || !nStubs_2.read().is_01())? sc_lv<1>(): (sc_bigint<32>(i_0_i3_cast6_fu_4891_p1.read()) < sc_bigint<32>(nStubs_2.read()));
}

void VMRouterDispatcher::thread_tmp_16_fu_4854_p2() {
    tmp_16_fu_4854_p2 = (!nPH2Z2_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z2_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_17_fu_4838_p2() {
    tmp_17_fu_4838_p2 = (!nPH3Z2_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z2_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_18_fu_4822_p2() {
    tmp_18_fu_4822_p2 = (!nPH4Z2_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z2_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_19_fu_4806_p2() {
    tmp_19_fu_4806_p2 = (!nPH1Z1_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z1_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_1_fu_4469_p2() {
    tmp_1_fu_4469_p2 = (!i_0_i1_cast_fu_4465_p1.read().is_01() || !nStubs_0.read().is_01())? sc_lv<1>(): (sc_bigint<32>(i_0_i1_cast_fu_4465_p1.read()) < sc_bigint<32>(nStubs_0.read()));
}

void VMRouterDispatcher::thread_tmp_20_fu_4790_p2() {
    tmp_20_fu_4790_p2 = (!nPH2Z1_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z1_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_21_fu_4774_p2() {
    tmp_21_fu_4774_p2 = (!nPH3Z1_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z1_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_22_fu_4758_p2() {
    tmp_22_fu_4758_p2 = (!nPH4Z1_1_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z1_1_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_23_fu_5083_p2() {
    tmp_23_fu_5083_p2 = (!nPH1Z2_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z2_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_24_fu_5067_p2() {
    tmp_24_fu_5067_p2 = (!nPH2Z2_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z2_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_26_fu_5108_p2() {
    tmp_26_fu_5108_p2 = (!i_0_i6_cast4_fu_5104_p1.read().is_01() || !nStubs_3.read().is_01())? sc_lv<1>(): (sc_bigint<32>(i_0_i6_cast4_fu_5104_p1.read()) < sc_bigint<32>(nStubs_3.read()));
}

void VMRouterDispatcher::thread_tmp_27_fu_5051_p2() {
    tmp_27_fu_5051_p2 = (!nPH3Z2_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z2_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_28_fu_5035_p2() {
    tmp_28_fu_5035_p2 = (!nPH4Z2_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z2_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_29_fu_5019_p2() {
    tmp_29_fu_5019_p2 = (!nPH1Z1_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z1_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_30_fu_5003_p2() {
    tmp_30_fu_5003_p2 = (!nPH2Z1_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z1_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_31_fu_4987_p2() {
    tmp_31_fu_4987_p2 = (!nPH3Z1_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z1_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_32_fu_4971_p2() {
    tmp_32_fu_4971_p2 = (!nPH4Z1_2_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z1_2_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_33_fu_5296_p2() {
    tmp_33_fu_5296_p2 = (!nPH1Z2_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z2_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_34_fu_5280_p2() {
    tmp_34_fu_5280_p2 = (!nPH2Z2_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z2_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_35_fu_4877_p3() {
    tmp_35_fu_4877_p3 = i_0_i3_reg_4140.read().range(6, 6);
}

void VMRouterDispatcher::thread_tmp_37_fu_5321_p2() {
    tmp_37_fu_5321_p2 = (!i_0_i_cast2_fu_5317_p1.read().is_01() || !nStubs_4.read().is_01())? sc_lv<1>(): (sc_bigint<32>(i_0_i_cast2_fu_5317_p1.read()) < sc_bigint<32>(nStubs_4.read()));
}

void VMRouterDispatcher::thread_tmp_38_fu_5264_p2() {
    tmp_38_fu_5264_p2 = (!nPH3Z2_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z2_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_39_fu_5248_p2() {
    tmp_39_fu_5248_p2 = (!nPH4Z2_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z2_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_3_fu_4657_p2() {
    tmp_3_fu_4657_p2 = (!nPH1Z2_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z2_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_40_fu_5232_p2() {
    tmp_40_fu_5232_p2 = (!nPH1Z1_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z1_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_41_fu_5216_p2() {
    tmp_41_fu_5216_p2 = (!nPH2Z1_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z1_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_42_fu_5200_p2() {
    tmp_42_fu_5200_p2 = (!nPH3Z1_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z1_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_43_fu_5184_p2() {
    tmp_43_fu_5184_p2 = (!nPH4Z1_3_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z1_3_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_44_fu_5509_p2() {
    tmp_44_fu_5509_p2 = (!nPH1Z2_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z2_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_45_fu_5493_p2() {
    tmp_45_fu_5493_p2 = (!nPH2Z2_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z2_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_46_fu_5477_p2() {
    tmp_46_fu_5477_p2 = (!nPH3Z2_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z2_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_47_fu_5461_p2() {
    tmp_47_fu_5461_p2 = (!nPH4Z2_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z2_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_48_fu_5445_p2() {
    tmp_48_fu_5445_p2 = (!nPH1Z1_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z1_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_49_fu_5429_p2() {
    tmp_49_fu_5429_p2 = (!nPH2Z1_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z1_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_4_fu_4641_p2() {
    tmp_4_fu_4641_p2 = (!nPH2Z2_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z2_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_50_fu_5413_p2() {
    tmp_50_fu_5413_p2 = (!nPH3Z1_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z1_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_51_fu_5397_p2() {
    tmp_51_fu_5397_p2 = (!nPH4Z1_4_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z1_4_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_55_fu_5090_p3() {
    tmp_55_fu_5090_p3 = i_0_i6_reg_4163.read().range(6, 6);
}

void VMRouterDispatcher::thread_tmp_57_fu_5303_p3() {
    tmp_57_fu_5303_p3 = i_0_i_reg_4186.read().range(6, 6);
}

void VMRouterDispatcher::thread_tmp_5_fu_4625_p2() {
    tmp_5_fu_4625_p2 = (!nPH3Z2_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z2_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_6_fu_4609_p2() {
    tmp_6_fu_4609_p2 = (!nPH4Z2_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z2_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_7_fu_4593_p2() {
    tmp_7_fu_4593_p2 = (!nPH1Z1_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z1_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_9_fu_4577_p2() {
    tmp_9_fu_4577_p2 = (!nPH2Z1_0_V_i.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z1_0_V_i.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher::thread_tmp_fu_4451_p3() {
    tmp_fu_4451_p3 = i_0_i1_reg_4094.read().range(6, 6);
}

void VMRouterDispatcher::thread_tmp_s_fu_4682_p2() {
    tmp_s_fu_4682_p2 = (!i_0_i2_cast8_fu_4678_p1.read().is_01() || !nStubs_1.read().is_01())? sc_lv<1>(): (sc_bigint<32>(i_0_i2_cast8_fu_4678_p1.read()) < sc_bigint<32>(nStubs_1.read()));
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_index_V_address0() {
    vmStubsPH1Z1_0_index_V_address0 =  (sc_lv<6>) (nPH1Z1_V_load1_fu_4584_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_index_V_d0() {
    vmStubsPH1Z1_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH1Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_phi_V_address0() {
    vmStubsPH1Z1_0_phi_V_address0 =  (sc_lv<6>) (nPH1Z1_V_load1_fu_4584_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_phi_V_d0() {
    vmStubsPH1Z1_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH1Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_pt_V_address0() {
    vmStubsPH1Z1_0_pt_V_address0 =  (sc_lv<6>) (nPH1Z1_V_load1_fu_4584_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_pt_V_d0() {
    vmStubsPH1Z1_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH1Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_r_V_address0() {
    vmStubsPH1Z1_0_r_V_address0 =  (sc_lv<6>) (nPH1Z1_V_load1_fu_4584_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_r_V_d0() {
    vmStubsPH1Z1_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH1Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_z_V_address0() {
    vmStubsPH1Z1_0_z_V_address0 =  (sc_lv<6>) (nPH1Z1_V_load1_fu_4584_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_z_V_d0() {
    vmStubsPH1Z1_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH1Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_index_V_address0() {
    vmStubsPH1Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex_fu_4797_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_index_V_d0() {
    vmStubsPH1Z1_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH1Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_phi_V_address0() {
    vmStubsPH1Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex_fu_4797_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_phi_V_d0() {
    vmStubsPH1Z1_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH1Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_pt_V_address0() {
    vmStubsPH1Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex_fu_4797_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_pt_V_d0() {
    vmStubsPH1Z1_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH1Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_r_V_address0() {
    vmStubsPH1Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex_fu_4797_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_r_V_d0() {
    vmStubsPH1Z1_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH1Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_z_V_address0() {
    vmStubsPH1Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex_fu_4797_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_z_V_d0() {
    vmStubsPH1Z1_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH1Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_index_V_address0() {
    vmStubsPH1Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex8_fu_5010_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_index_V_d0() {
    vmStubsPH1Z1_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH1Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_phi_V_address0() {
    vmStubsPH1Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex8_fu_5010_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_phi_V_d0() {
    vmStubsPH1Z1_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH1Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_pt_V_address0() {
    vmStubsPH1Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex8_fu_5010_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_pt_V_d0() {
    vmStubsPH1Z1_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH1Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_r_V_address0() {
    vmStubsPH1Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex8_fu_5010_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_r_V_d0() {
    vmStubsPH1Z1_2_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH1Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_z_V_address0() {
    vmStubsPH1Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex8_fu_5010_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_z_V_d0() {
    vmStubsPH1Z1_2_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH1Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_index_V_address0() {
    vmStubsPH1Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex16_fu_5223_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_index_V_d0() {
    vmStubsPH1Z1_3_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH1Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_phi_V_address0() {
    vmStubsPH1Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex16_fu_5223_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_phi_V_d0() {
    vmStubsPH1Z1_3_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH1Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_pt_V_address0() {
    vmStubsPH1Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex16_fu_5223_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_pt_V_d0() {
    vmStubsPH1Z1_3_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH1Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_r_V_address0() {
    vmStubsPH1Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex16_fu_5223_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_r_V_d0() {
    vmStubsPH1Z1_3_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH1Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_z_V_address0() {
    vmStubsPH1Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex16_fu_5223_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_z_V_d0() {
    vmStubsPH1Z1_3_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH1Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_index_V_address0() {
    vmStubsPH1Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex24_fu_5436_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_index_V_d0() {
    vmStubsPH1Z1_4_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH1Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_phi_V_address0() {
    vmStubsPH1Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex24_fu_5436_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_phi_V_d0() {
    vmStubsPH1Z1_4_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH1Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_pt_V_address0() {
    vmStubsPH1Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex24_fu_5436_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_pt_V_d0() {
    vmStubsPH1Z1_4_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH1Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_r_V_address0() {
    vmStubsPH1Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex24_fu_5436_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_r_V_d0() {
    vmStubsPH1Z1_4_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH1Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_z_V_address0() {
    vmStubsPH1Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex24_fu_5436_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_z_V_d0() {
    vmStubsPH1Z1_4_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH1Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_index_V_address0() {
    vmStubsPH1Z2_0_index_V_address0 =  (sc_lv<6>) (nPH1Z2_V_load1_fu_4648_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_index_V_d0() {
    vmStubsPH1Z2_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH1Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_phi_V_address0() {
    vmStubsPH1Z2_0_phi_V_address0 =  (sc_lv<6>) (nPH1Z2_V_load1_fu_4648_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_phi_V_d0() {
    vmStubsPH1Z2_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH1Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_pt_V_address0() {
    vmStubsPH1Z2_0_pt_V_address0 =  (sc_lv<6>) (nPH1Z2_V_load1_fu_4648_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_pt_V_d0() {
    vmStubsPH1Z2_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH1Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_r_V_address0() {
    vmStubsPH1Z2_0_r_V_address0 =  (sc_lv<6>) (nPH1Z2_V_load1_fu_4648_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_r_V_d0() {
    vmStubsPH1Z2_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH1Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_z_V_address0() {
    vmStubsPH1Z2_0_z_V_address0 =  (sc_lv<6>) (nPH1Z2_V_load1_fu_4648_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_z_V_d0() {
    vmStubsPH1Z2_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH1Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_index_V_address0() {
    vmStubsPH1Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex4_fu_4861_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_index_V_d0() {
    vmStubsPH1Z2_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH1Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_phi_V_address0() {
    vmStubsPH1Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex4_fu_4861_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_phi_V_d0() {
    vmStubsPH1Z2_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH1Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_pt_V_address0() {
    vmStubsPH1Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex4_fu_4861_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_pt_V_d0() {
    vmStubsPH1Z2_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH1Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_r_V_address0() {
    vmStubsPH1Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex4_fu_4861_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_r_V_d0() {
    vmStubsPH1Z2_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH1Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_z_V_address0() {
    vmStubsPH1Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex4_fu_4861_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH1Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_z_V_d0() {
    vmStubsPH1Z2_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH1Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_index_V_address0() {
    vmStubsPH1Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex12_fu_5074_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_index_V_d0() {
    vmStubsPH1Z2_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH1Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_phi_V_address0() {
    vmStubsPH1Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex12_fu_5074_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_phi_V_d0() {
    vmStubsPH1Z2_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH1Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_pt_V_address0() {
    vmStubsPH1Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex12_fu_5074_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_pt_V_d0() {
    vmStubsPH1Z2_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH1Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_r_V_address0() {
    vmStubsPH1Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex12_fu_5074_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_r_V_d0() {
    vmStubsPH1Z2_2_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH1Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_z_V_address0() {
    vmStubsPH1Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex12_fu_5074_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH1Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_z_V_d0() {
    vmStubsPH1Z2_2_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH1Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_index_V_address0() {
    vmStubsPH1Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex20_fu_5287_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_index_V_d0() {
    vmStubsPH1Z2_3_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH1Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_phi_V_address0() {
    vmStubsPH1Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex20_fu_5287_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_phi_V_d0() {
    vmStubsPH1Z2_3_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH1Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_pt_V_address0() {
    vmStubsPH1Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex20_fu_5287_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_pt_V_d0() {
    vmStubsPH1Z2_3_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH1Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_r_V_address0() {
    vmStubsPH1Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex20_fu_5287_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_r_V_d0() {
    vmStubsPH1Z2_3_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH1Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_z_V_address0() {
    vmStubsPH1Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex20_fu_5287_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH1Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_z_V_d0() {
    vmStubsPH1Z2_3_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH1Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_index_V_address0() {
    vmStubsPH1Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex28_fu_5500_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_index_V_d0() {
    vmStubsPH1Z2_4_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH1Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_phi_V_address0() {
    vmStubsPH1Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex28_fu_5500_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_phi_V_d0() {
    vmStubsPH1Z2_4_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH1Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_pt_V_address0() {
    vmStubsPH1Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex28_fu_5500_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_pt_V_d0() {
    vmStubsPH1Z2_4_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH1Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_r_V_address0() {
    vmStubsPH1Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex28_fu_5500_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_r_V_d0() {
    vmStubsPH1Z2_4_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH1Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_z_V_address0() {
    vmStubsPH1Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex28_fu_5500_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH1Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_z_V_d0() {
    vmStubsPH1Z2_4_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH1Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_0, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH1Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_index_V_address0() {
    vmStubsPH2Z1_0_index_V_address0 =  (sc_lv<6>) (nPH2Z1_V_load_fu_4568_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_index_V_d0() {
    vmStubsPH2Z1_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH2Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_phi_V_address0() {
    vmStubsPH2Z1_0_phi_V_address0 =  (sc_lv<6>) (nPH2Z1_V_load_fu_4568_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_phi_V_d0() {
    vmStubsPH2Z1_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH2Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_pt_V_address0() {
    vmStubsPH2Z1_0_pt_V_address0 =  (sc_lv<6>) (nPH2Z1_V_load_fu_4568_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_pt_V_d0() {
    vmStubsPH2Z1_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH2Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_r_V_address0() {
    vmStubsPH2Z1_0_r_V_address0 =  (sc_lv<6>) (nPH2Z1_V_load_fu_4568_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_r_V_d0() {
    vmStubsPH2Z1_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH2Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_z_V_address0() {
    vmStubsPH2Z1_0_z_V_address0 =  (sc_lv<6>) (nPH2Z1_V_load_fu_4568_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_z_V_d0() {
    vmStubsPH2Z1_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH2Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_index_V_address0() {
    vmStubsPH2Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex1_fu_4781_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_index_V_d0() {
    vmStubsPH2Z1_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH2Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_phi_V_address0() {
    vmStubsPH2Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex1_fu_4781_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_phi_V_d0() {
    vmStubsPH2Z1_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH2Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_pt_V_address0() {
    vmStubsPH2Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex1_fu_4781_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_pt_V_d0() {
    vmStubsPH2Z1_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH2Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_r_V_address0() {
    vmStubsPH2Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex1_fu_4781_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_r_V_d0() {
    vmStubsPH2Z1_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH2Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_z_V_address0() {
    vmStubsPH2Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex1_fu_4781_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_z_V_d0() {
    vmStubsPH2Z1_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH2Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_index_V_address0() {
    vmStubsPH2Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex9_fu_4994_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_index_V_d0() {
    vmStubsPH2Z1_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH2Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_phi_V_address0() {
    vmStubsPH2Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex9_fu_4994_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_phi_V_d0() {
    vmStubsPH2Z1_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH2Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_pt_V_address0() {
    vmStubsPH2Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex9_fu_4994_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_pt_V_d0() {
    vmStubsPH2Z1_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH2Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_r_V_address0() {
    vmStubsPH2Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex9_fu_4994_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_r_V_d0() {
    vmStubsPH2Z1_2_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH2Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_z_V_address0() {
    vmStubsPH2Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex9_fu_4994_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_z_V_d0() {
    vmStubsPH2Z1_2_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH2Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_index_V_address0() {
    vmStubsPH2Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex17_fu_5207_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_index_V_d0() {
    vmStubsPH2Z1_3_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH2Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_phi_V_address0() {
    vmStubsPH2Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex17_fu_5207_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_phi_V_d0() {
    vmStubsPH2Z1_3_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH2Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_pt_V_address0() {
    vmStubsPH2Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex17_fu_5207_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_pt_V_d0() {
    vmStubsPH2Z1_3_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH2Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_r_V_address0() {
    vmStubsPH2Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex17_fu_5207_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_r_V_d0() {
    vmStubsPH2Z1_3_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH2Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_z_V_address0() {
    vmStubsPH2Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_5207_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_z_V_d0() {
    vmStubsPH2Z1_3_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH2Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_index_V_address0() {
    vmStubsPH2Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex25_fu_5420_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_index_V_d0() {
    vmStubsPH2Z1_4_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH2Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_phi_V_address0() {
    vmStubsPH2Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex25_fu_5420_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_phi_V_d0() {
    vmStubsPH2Z1_4_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH2Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_pt_V_address0() {
    vmStubsPH2Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex25_fu_5420_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_pt_V_d0() {
    vmStubsPH2Z1_4_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH2Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_r_V_address0() {
    vmStubsPH2Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex25_fu_5420_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_r_V_d0() {
    vmStubsPH2Z1_4_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH2Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_z_V_address0() {
    vmStubsPH2Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex25_fu_5420_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_z_V_d0() {
    vmStubsPH2Z1_4_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH2Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_index_V_address0() {
    vmStubsPH2Z2_0_index_V_address0 =  (sc_lv<6>) (nPH2Z2_V_load_fu_4632_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_index_V_d0() {
    vmStubsPH2Z2_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH2Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_phi_V_address0() {
    vmStubsPH2Z2_0_phi_V_address0 =  (sc_lv<6>) (nPH2Z2_V_load_fu_4632_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_phi_V_d0() {
    vmStubsPH2Z2_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH2Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_pt_V_address0() {
    vmStubsPH2Z2_0_pt_V_address0 =  (sc_lv<6>) (nPH2Z2_V_load_fu_4632_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_pt_V_d0() {
    vmStubsPH2Z2_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH2Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_r_V_address0() {
    vmStubsPH2Z2_0_r_V_address0 =  (sc_lv<6>) (nPH2Z2_V_load_fu_4632_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_r_V_d0() {
    vmStubsPH2Z2_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH2Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_z_V_address0() {
    vmStubsPH2Z2_0_z_V_address0 =  (sc_lv<6>) (nPH2Z2_V_load_fu_4632_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_z_V_d0() {
    vmStubsPH2Z2_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH2Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_index_V_address0() {
    vmStubsPH2Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex5_fu_4845_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_index_V_d0() {
    vmStubsPH2Z2_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH2Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_phi_V_address0() {
    vmStubsPH2Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex5_fu_4845_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_phi_V_d0() {
    vmStubsPH2Z2_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH2Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_pt_V_address0() {
    vmStubsPH2Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex5_fu_4845_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_pt_V_d0() {
    vmStubsPH2Z2_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH2Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_r_V_address0() {
    vmStubsPH2Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex5_fu_4845_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_r_V_d0() {
    vmStubsPH2Z2_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH2Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_z_V_address0() {
    vmStubsPH2Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex5_fu_4845_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH2Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_z_V_d0() {
    vmStubsPH2Z2_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH2Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_index_V_address0() {
    vmStubsPH2Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex13_fu_5058_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_index_V_d0() {
    vmStubsPH2Z2_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH2Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_phi_V_address0() {
    vmStubsPH2Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex13_fu_5058_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_phi_V_d0() {
    vmStubsPH2Z2_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH2Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_pt_V_address0() {
    vmStubsPH2Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex13_fu_5058_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_pt_V_d0() {
    vmStubsPH2Z2_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH2Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_r_V_address0() {
    vmStubsPH2Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex13_fu_5058_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_r_V_d0() {
    vmStubsPH2Z2_2_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH2Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_z_V_address0() {
    vmStubsPH2Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex13_fu_5058_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH2Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_z_V_d0() {
    vmStubsPH2Z2_2_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH2Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_index_V_address0() {
    vmStubsPH2Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex21_fu_5271_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_index_V_d0() {
    vmStubsPH2Z2_3_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH2Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_phi_V_address0() {
    vmStubsPH2Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex21_fu_5271_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_phi_V_d0() {
    vmStubsPH2Z2_3_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH2Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_pt_V_address0() {
    vmStubsPH2Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex21_fu_5271_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_pt_V_d0() {
    vmStubsPH2Z2_3_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH2Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_r_V_address0() {
    vmStubsPH2Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_5271_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_r_V_d0() {
    vmStubsPH2Z2_3_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH2Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_z_V_address0() {
    vmStubsPH2Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex21_fu_5271_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH2Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_z_V_d0() {
    vmStubsPH2Z2_3_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH2Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_index_V_address0() {
    vmStubsPH2Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex29_fu_5484_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_index_V_d0() {
    vmStubsPH2Z2_4_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH2Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_phi_V_address0() {
    vmStubsPH2Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex29_fu_5484_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_phi_V_d0() {
    vmStubsPH2Z2_4_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH2Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_pt_V_address0() {
    vmStubsPH2Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex29_fu_5484_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_pt_V_d0() {
    vmStubsPH2Z2_4_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH2Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_r_V_address0() {
    vmStubsPH2Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex29_fu_5484_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_r_V_d0() {
    vmStubsPH2Z2_4_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH2Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_z_V_address0() {
    vmStubsPH2Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex29_fu_5484_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH2Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_z_V_d0() {
    vmStubsPH2Z2_4_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH2Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_1, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH2Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_index_V_address0() {
    vmStubsPH3Z1_0_index_V_address0 =  (sc_lv<6>) (nPH3Z1_V_load1_fu_4552_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_index_V_d0() {
    vmStubsPH3Z1_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH3Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_phi_V_address0() {
    vmStubsPH3Z1_0_phi_V_address0 =  (sc_lv<6>) (nPH3Z1_V_load1_fu_4552_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_phi_V_d0() {
    vmStubsPH3Z1_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH3Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_pt_V_address0() {
    vmStubsPH3Z1_0_pt_V_address0 =  (sc_lv<6>) (nPH3Z1_V_load1_fu_4552_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_pt_V_d0() {
    vmStubsPH3Z1_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH3Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_r_V_address0() {
    vmStubsPH3Z1_0_r_V_address0 =  (sc_lv<6>) (nPH3Z1_V_load1_fu_4552_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_r_V_d0() {
    vmStubsPH3Z1_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH3Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_z_V_address0() {
    vmStubsPH3Z1_0_z_V_address0 =  (sc_lv<6>) (nPH3Z1_V_load1_fu_4552_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_z_V_d0() {
    vmStubsPH3Z1_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH3Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_index_V_address0() {
    vmStubsPH3Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex2_fu_4765_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_index_V_d0() {
    vmStubsPH3Z1_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH3Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_phi_V_address0() {
    vmStubsPH3Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex2_fu_4765_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_phi_V_d0() {
    vmStubsPH3Z1_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH3Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_pt_V_address0() {
    vmStubsPH3Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex2_fu_4765_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_pt_V_d0() {
    vmStubsPH3Z1_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH3Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_r_V_address0() {
    vmStubsPH3Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex2_fu_4765_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_r_V_d0() {
    vmStubsPH3Z1_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH3Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_z_V_address0() {
    vmStubsPH3Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex2_fu_4765_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_z_V_d0() {
    vmStubsPH3Z1_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH3Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_index_V_address0() {
    vmStubsPH3Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex10_fu_4978_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_index_V_d0() {
    vmStubsPH3Z1_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH3Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_phi_V_address0() {
    vmStubsPH3Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex10_fu_4978_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_phi_V_d0() {
    vmStubsPH3Z1_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH3Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_pt_V_address0() {
    vmStubsPH3Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex10_fu_4978_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_pt_V_d0() {
    vmStubsPH3Z1_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH3Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_r_V_address0() {
    vmStubsPH3Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex10_fu_4978_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_r_V_d0() {
    vmStubsPH3Z1_2_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH3Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_z_V_address0() {
    vmStubsPH3Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex10_fu_4978_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_z_V_d0() {
    vmStubsPH3Z1_2_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH3Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_index_V_address0() {
    vmStubsPH3Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex18_fu_5191_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_index_V_d0() {
    vmStubsPH3Z1_3_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH3Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_phi_V_address0() {
    vmStubsPH3Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex18_fu_5191_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_phi_V_d0() {
    vmStubsPH3Z1_3_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH3Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_pt_V_address0() {
    vmStubsPH3Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex18_fu_5191_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_pt_V_d0() {
    vmStubsPH3Z1_3_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH3Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_r_V_address0() {
    vmStubsPH3Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex18_fu_5191_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_r_V_d0() {
    vmStubsPH3Z1_3_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH3Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_z_V_address0() {
    vmStubsPH3Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex18_fu_5191_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_z_V_d0() {
    vmStubsPH3Z1_3_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read())))) {
        vmStubsPH3Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_index_V_address0() {
    vmStubsPH3Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex26_fu_5404_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_index_V_d0() {
    vmStubsPH3Z1_4_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH3Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_phi_V_address0() {
    vmStubsPH3Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex26_fu_5404_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_phi_V_d0() {
    vmStubsPH3Z1_4_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH3Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_pt_V_address0() {
    vmStubsPH3Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex26_fu_5404_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_pt_V_d0() {
    vmStubsPH3Z1_4_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH3Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_r_V_address0() {
    vmStubsPH3Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex26_fu_5404_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_r_V_d0() {
    vmStubsPH3Z1_4_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH3Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_z_V_address0() {
    vmStubsPH3Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex26_fu_5404_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_z_V_d0() {
    vmStubsPH3Z1_4_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read())))) {
        vmStubsPH3Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_index_V_address0() {
    vmStubsPH3Z2_0_index_V_address0 =  (sc_lv<6>) (nPH3Z2_V_load1_fu_4616_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_index_V_d0() {
    vmStubsPH3Z2_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH3Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_phi_V_address0() {
    vmStubsPH3Z2_0_phi_V_address0 =  (sc_lv<6>) (nPH3Z2_V_load1_fu_4616_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_phi_V_d0() {
    vmStubsPH3Z2_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH3Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_pt_V_address0() {
    vmStubsPH3Z2_0_pt_V_address0 =  (sc_lv<6>) (nPH3Z2_V_load1_fu_4616_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_pt_V_d0() {
    vmStubsPH3Z2_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH3Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_r_V_address0() {
    vmStubsPH3Z2_0_r_V_address0 =  (sc_lv<6>) (nPH3Z2_V_load1_fu_4616_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_r_V_d0() {
    vmStubsPH3Z2_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH3Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_z_V_address0() {
    vmStubsPH3Z2_0_z_V_address0 =  (sc_lv<6>) (nPH3Z2_V_load1_fu_4616_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_z_V_d0() {
    vmStubsPH3Z2_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read())))) {
        vmStubsPH3Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_index_V_address0() {
    vmStubsPH3Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex6_fu_4829_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_index_V_d0() {
    vmStubsPH3Z2_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH3Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_phi_V_address0() {
    vmStubsPH3Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex6_fu_4829_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_phi_V_d0() {
    vmStubsPH3Z2_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH3Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_pt_V_address0() {
    vmStubsPH3Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex6_fu_4829_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_pt_V_d0() {
    vmStubsPH3Z2_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH3Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_r_V_address0() {
    vmStubsPH3Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex6_fu_4829_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_r_V_d0() {
    vmStubsPH3Z2_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH3Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_z_V_address0() {
    vmStubsPH3Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex6_fu_4829_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH3Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_z_V_d0() {
    vmStubsPH3Z2_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read())))) {
        vmStubsPH3Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_index_V_address0() {
    vmStubsPH3Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex14_fu_5042_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_index_V_d0() {
    vmStubsPH3Z2_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH3Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_phi_V_address0() {
    vmStubsPH3Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex14_fu_5042_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_phi_V_d0() {
    vmStubsPH3Z2_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH3Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_pt_V_address0() {
    vmStubsPH3Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex14_fu_5042_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_pt_V_d0() {
    vmStubsPH3Z2_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH3Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_r_V_address0() {
    vmStubsPH3Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex14_fu_5042_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_r_V_d0() {
    vmStubsPH3Z2_2_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH3Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_z_V_address0() {
    vmStubsPH3Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex14_fu_5042_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH3Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_z_V_d0() {
    vmStubsPH3Z2_2_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read())))) {
        vmStubsPH3Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_index_V_address0() {
    vmStubsPH3Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex22_fu_5255_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_index_V_d0() {
    vmStubsPH3Z2_3_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH3Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_phi_V_address0() {
    vmStubsPH3Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex22_fu_5255_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_phi_V_d0() {
    vmStubsPH3Z2_3_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH3Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_pt_V_address0() {
    vmStubsPH3Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex22_fu_5255_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_pt_V_d0() {
    vmStubsPH3Z2_3_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH3Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_r_V_address0() {
    vmStubsPH3Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex22_fu_5255_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_r_V_d0() {
    vmStubsPH3Z2_3_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH3Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_z_V_address0() {
    vmStubsPH3Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex22_fu_5255_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read())) {
        vmStubsPH3Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_z_V_d0() {
    vmStubsPH3Z2_3_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2.read())))) {
        vmStubsPH3Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_index_V_address0() {
    vmStubsPH3Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex30_fu_5468_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_index_V_d0() {
    vmStubsPH3Z2_4_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH3Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_phi_V_address0() {
    vmStubsPH3Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex30_fu_5468_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_phi_V_d0() {
    vmStubsPH3Z2_4_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH3Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_pt_V_address0() {
    vmStubsPH3Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex30_fu_5468_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_pt_V_d0() {
    vmStubsPH3Z2_4_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH3Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_r_V_address0() {
    vmStubsPH3Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex30_fu_5468_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_r_V_d0() {
    vmStubsPH3Z2_4_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH3Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_z_V_address0() {
    vmStubsPH3Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex30_fu_5468_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read())) {
        vmStubsPH3Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_z_V_d0() {
    vmStubsPH3Z2_4_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH3Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_2, ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2.read())))) {
        vmStubsPH3Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_index_V_address0() {
    vmStubsPH4Z1_0_index_V_address0 =  (sc_lv<6>) (nPH4Z1_V_load_fu_4536_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_index_V_d0() {
    vmStubsPH4Z1_0_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH4Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_phi_V_address0() {
    vmStubsPH4Z1_0_phi_V_address0 =  (sc_lv<6>) (nPH4Z1_V_load_fu_4536_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_phi_V_d0() {
    vmStubsPH4Z1_0_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH4Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_pt_V_address0() {
    vmStubsPH4Z1_0_pt_V_address0 =  (sc_lv<6>) (nPH4Z1_V_load_fu_4536_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_pt_V_d0() {
    vmStubsPH4Z1_0_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH4Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_r_V_address0() {
    vmStubsPH4Z1_0_r_V_address0 =  (sc_lv<6>) (nPH4Z1_V_load_fu_4536_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_r_V_d0() {
    vmStubsPH4Z1_0_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH4Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_z_V_address0() {
    vmStubsPH4Z1_0_z_V_address0 =  (sc_lv<6>) (nPH4Z1_V_load_fu_4536_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_z_V_d0() {
    vmStubsPH4Z1_0_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2.read())))) {
        vmStubsPH4Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_index_V_address0() {
    vmStubsPH4Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex3_fu_4749_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH4Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_index_V_d0() {
    vmStubsPH4Z1_1_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH4Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_phi_V_address0() {
    vmStubsPH4Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex3_fu_4749_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH4Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_phi_V_d0() {
    vmStubsPH4Z1_1_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH4Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_pt_V_address0() {
    vmStubsPH4Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex3_fu_4749_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH4Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_pt_V_d0() {
    vmStubsPH4Z1_1_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH4Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_r_V_address0() {
    vmStubsPH4Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex3_fu_4749_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH4Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_r_V_d0() {
    vmStubsPH4Z1_1_r_V_d0 = reg_4319.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH4Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_z_V_address0() {
    vmStubsPH4Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex3_fu_4749_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read())) {
        vmStubsPH4Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_z_V_d0() {
    vmStubsPH4Z1_1_z_V_d0 = reg_4231.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2.read())))) {
        vmStubsPH4Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_index_V_address0() {
    vmStubsPH4Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex11_fu_4962_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH4Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_index_V_d0() {
    vmStubsPH4Z1_2_index_V_d0 = reg_4407.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH4Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_phi_V_address0() {
    vmStubsPH4Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex11_fu_4962_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH4Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_phi_V_d0() {
    vmStubsPH4Z1_2_phi_V_d0 = reg_4275.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH4Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_pt_V_address0() {
    vmStubsPH4Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex11_fu_4962_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH4Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_pt_V_d0() {
    vmStubsPH4Z1_2_pt_V_d0 = reg_4363.read();
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2.read()) && 
          esl_seteq<1,2,2>(ap_const_lv2_3, ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2.read())))) {
        vmStubsPH4Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_r_V_address0() {
    vmStubsPH4Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex11_fu_4962_p1.read());
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read())) {
        vmStubsPH4Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher::thread_vmStubsPH4Z1_2_r_V_d0() {
    vmStubsPH4Z1_2_r_V_d0 = reg_4319.read();
}

}

