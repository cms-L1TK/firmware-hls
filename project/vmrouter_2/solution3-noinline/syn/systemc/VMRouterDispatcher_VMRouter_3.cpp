#include "VMRouterDispatcher_VMRouter.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouterDispatcher_VMRouter::thread_allStubs_0_phi_V_address0() {
    allStubs_0_phi_V_address0 =  (sc_lv<6>) (newIndex_fu_5480_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_phi_V_d0() {
    allStubs_0_phi_V_d0 = curPhi_V_reg_6504.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_0)))) {
        allStubs_0_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_pt_V_address0() {
    allStubs_0_pt_V_address0 =  (sc_lv<6>) (newIndex4_fu_5496_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_pt_V_d0() {
    allStubs_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_0)))) {
        allStubs_0_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_r_V_address0() {
    allStubs_0_r_V_address0 =  (sc_lv<6>) (newIndex2_fu_5488_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_0_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_r_V_d0() {
    allStubs_0_r_V_d0 = curR_V_reg_6514.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_0)))) {
        allStubs_0_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_z_V_address0() {
    allStubs_0_z_V_address0 =  (sc_lv<6>) (newIndex9_fu_5472_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_0_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_z_V_d0() {
    allStubs_0_z_V_d0 = curZ_V_reg_6494.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_0)))) {
        allStubs_0_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_phi_V_address0() {
    allStubs_1_phi_V_address0 =  (sc_lv<6>) (newIndex_fu_5480_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_phi_V_d0() {
    allStubs_1_phi_V_d0 = curPhi_V_reg_6504.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_1)))) {
        allStubs_1_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_pt_V_address0() {
    allStubs_1_pt_V_address0 =  (sc_lv<6>) (newIndex4_fu_5496_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_pt_V_d0() {
    allStubs_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_1)))) {
        allStubs_1_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_r_V_address0() {
    allStubs_1_r_V_address0 =  (sc_lv<6>) (newIndex2_fu_5488_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_1_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_r_V_d0() {
    allStubs_1_r_V_d0 = curR_V_reg_6514.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_1)))) {
        allStubs_1_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_z_V_address0() {
    allStubs_1_z_V_address0 =  (sc_lv<6>) (newIndex9_fu_5472_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_1_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_z_V_d0() {
    allStubs_1_z_V_d0 = curZ_V_reg_6494.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_1)))) {
        allStubs_1_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_phi_V_address0() {
    allStubs_2_phi_V_address0 =  (sc_lv<6>) (newIndex_fu_5480_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_phi_V_d0() {
    allStubs_2_phi_V_d0 = curPhi_V_reg_6504.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_2)))) {
        allStubs_2_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_pt_V_address0() {
    allStubs_2_pt_V_address0 =  (sc_lv<6>) (newIndex4_fu_5496_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_pt_V_d0() {
    allStubs_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_2)))) {
        allStubs_2_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_r_V_address0() {
    allStubs_2_r_V_address0 =  (sc_lv<6>) (newIndex2_fu_5488_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_2_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_r_V_d0() {
    allStubs_2_r_V_d0 = curR_V_reg_6514.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_2)))) {
        allStubs_2_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_z_V_address0() {
    allStubs_2_z_V_address0 =  (sc_lv<6>) (newIndex9_fu_5472_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_2_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_z_V_d0() {
    allStubs_2_z_V_d0 = curZ_V_reg_6494.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_2)))) {
        allStubs_2_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_phi_V_address0() {
    allStubs_3_phi_V_address0 =  (sc_lv<6>) (newIndex_fu_5480_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_phi_V_d0() {
    allStubs_3_phi_V_d0 = curPhi_V_reg_6504.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_3)))) {
        allStubs_3_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_pt_V_address0() {
    allStubs_3_pt_V_address0 =  (sc_lv<6>) (newIndex4_fu_5496_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_pt_V_d0() {
    allStubs_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_3)))) {
        allStubs_3_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_r_V_address0() {
    allStubs_3_r_V_address0 =  (sc_lv<6>) (newIndex2_fu_5488_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_3_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_r_V_d0() {
    allStubs_3_r_V_d0 = curR_V_reg_6514.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_3)))) {
        allStubs_3_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_z_V_address0() {
    allStubs_3_z_V_address0 =  (sc_lv<6>) (newIndex9_fu_5472_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_3_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_z_V_d0() {
    allStubs_3_z_V_d0 = curZ_V_reg_6494.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_3)))) {
        allStubs_3_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_phi_V_address0() {
    allStubs_4_phi_V_address0 =  (sc_lv<6>) (newIndex_fu_5480_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_phi_V_d0() {
    allStubs_4_phi_V_d0 = curPhi_V_reg_6504.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          !esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo5_cast_cast_reg_6582.read(), ap_const_lv3_3)))) {
        allStubs_4_phi_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_pt_V_address0() {
    allStubs_4_pt_V_address0 =  (sc_lv<6>) (newIndex4_fu_5496_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_pt_V_d0() {
    allStubs_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          !esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo7_cast_cast_reg_6600.read(), ap_const_lv3_3)))) {
        allStubs_4_pt_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_r_V_address0() {
    allStubs_4_r_V_address0 =  (sc_lv<6>) (newIndex2_fu_5488_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_4_r_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_r_V_d0() {
    allStubs_4_r_V_d0 = curR_V_reg_6514.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          !esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo6_cast_cast_reg_6591.read(), ap_const_lv3_3)))) {
        allStubs_4_r_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_z_V_address0() {
    allStubs_4_z_V_address0 =  (sc_lv<6>) (newIndex9_fu_5472_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        allStubs_4_z_V_ce0 = ap_const_logic_1;
    } else {
        allStubs_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_z_V_d0() {
    allStubs_4_z_V_d0 = curZ_V_reg_6494.read();
}

void VMRouterDispatcher_VMRouter::thread_allStubs_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          !esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo4_cast_cast_reg_6573.read(), ap_const_lv3_3)))) {
        allStubs_4_z_V_we0 = ap_const_logic_1;
    } else {
        allStubs_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read()))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_return_0() {
    ap_return_0 = nPH1Z1_V_fu_716.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_1() {
    ap_return_1 = nPH2Z1_V_fu_712.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_2() {
    ap_return_2 = nPH3Z1_V_fu_708.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_3() {
    ap_return_3 = nPH4Z1_V_fu_704.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_4() {
    ap_return_4 = nPH1Z2_V_fu_700.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_5() {
    ap_return_5 = nPH2Z2_V_fu_696.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_6() {
    ap_return_6 = nPH3Z2_V_fu_692.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_return_7() {
    ap_return_7 = nPH4Z2_V_fu_688.read();
}

void VMRouterDispatcher_VMRouter::thread_ap_sig_1759() {
    ap_sig_1759 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(1, 1));
}

void VMRouterDispatcher_VMRouter::thread_ap_sig_20() {
    ap_sig_20 = esl_seteq<1,1,1>(ap_CS_fsm.read().range(0, 0), ap_const_lv1_1);
}

void VMRouterDispatcher_VMRouter::thread_ap_sig_2502() {
    ap_sig_2502 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(2, 2));
}

void VMRouterDispatcher_VMRouter::thread_ap_sig_cseq_ST_pp0_stg0_fsm_1() {
    if (ap_sig_1759.read()) {
        ap_sig_cseq_ST_pp0_stg0_fsm_1 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp0_stg0_fsm_1 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_sig_cseq_ST_st1_fsm_0() {
    if (ap_sig_20.read()) {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_sig_cseq_ST_st6_fsm_2() {
    if (ap_sig_2502.read()) {
        ap_sig_cseq_ST_st6_fsm_2 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st6_fsm_2 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_curPhi_V_fu_4430_p6() {
    curPhi_V_fu_4430_p6 = esl_zext<64,3>(ap_reg_ppstg_arrayNo1_reg_6359_pp0_iter1.read());
}

void VMRouterDispatcher_VMRouter::thread_curR_V_fu_4446_p6() {
    curR_V_fu_4446_p6 = esl_zext<64,3>(ap_reg_ppstg_arrayNo2_reg_6369_pp0_iter1.read());
}

void VMRouterDispatcher_VMRouter::thread_curZ_V_fu_4414_p6() {
    curZ_V_fu_4414_p6 = esl_zext<64,3>(ap_reg_ppstg_arrayNo_reg_6349_pp0_iter1.read());
}

void VMRouterDispatcher_VMRouter::thread_i_1_fu_4364_p2() {
    i_1_fu_4364_p2 = (!i_reg_3994.read().is_01() || !ap_const_lv7_1.is_01())? sc_lv<7>(): (sc_biguint<7>(i_reg_3994.read()) + sc_biguint<7>(ap_const_lv7_1));
}

void VMRouterDispatcher_VMRouter::thread_i_cast3_fu_4275_p1() {
    i_cast3_fu_4275_p1 = esl_zext<32,7>(i_reg_3994.read());
}

void VMRouterDispatcher_VMRouter::thread_index_V_fu_4269_p2() {
    index_V_fu_4269_p2 = (!op2_V_read_assign_phi_fu_3986_p4.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(op2_V_read_assign_phi_fu_3986_p4.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_newIndex10_fu_5947_p1() {
    newIndex10_fu_5947_p1 = esl_zext<64,6>(tmp_79_reg_6954.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex11_fu_5955_p1() {
    newIndex11_fu_5955_p1 = esl_zext<64,6>(tmp_80_reg_6963.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex12_fu_5963_p1() {
    newIndex12_fu_5963_p1 = esl_zext<64,6>(tmp_81_reg_6972.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex13_fu_5891_p1() {
    newIndex13_fu_5891_p1 = esl_zext<64,6>(tmp_82_reg_6891.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex14_fu_5899_p1() {
    newIndex14_fu_5899_p1 = esl_zext<64,6>(tmp_83_reg_6900.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex15_fu_5907_p1() {
    newIndex15_fu_5907_p1 = esl_zext<64,6>(tmp_84_reg_6909.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex16_fu_5915_p1() {
    newIndex16_fu_5915_p1 = esl_zext<64,6>(tmp_85_reg_6918.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex17_fu_5771_p1() {
    newIndex17_fu_5771_p1 = esl_zext<64,6>(tmp_97_reg_6756.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex18_fu_5923_p1() {
    newIndex18_fu_5923_p1 = esl_zext<64,6>(tmp_86_reg_6927.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex19_fu_5779_p1() {
    newIndex19_fu_5779_p1 = esl_zext<64,6>(tmp_98_reg_6765.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex1_fu_4370_p1() {
    newIndex1_fu_4370_p1 = esl_zext<64,6>(tmp_68_reg_6354.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex20_fu_5851_p1() {
    newIndex20_fu_5851_p1 = esl_zext<64,6>(tmp_87_reg_6846.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex21_fu_5787_p1() {
    newIndex21_fu_5787_p1 = esl_zext<64,6>(tmp_99_reg_6774.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex22_fu_5859_p1() {
    newIndex22_fu_5859_p1 = esl_zext<64,6>(tmp_88_reg_6855.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex23_fu_5795_p1() {
    newIndex23_fu_5795_p1 = esl_zext<64,6>(tmp_100_reg_6783.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex24_fu_5867_p1() {
    newIndex24_fu_5867_p1 = esl_zext<64,6>(tmp_89_reg_6864.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex25_fu_5803_p1() {
    newIndex25_fu_5803_p1 = esl_zext<64,6>(tmp_101_reg_6792.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex26_fu_5875_p1() {
    newIndex26_fu_5875_p1 = esl_zext<64,6>(tmp_90_reg_6873.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex27_fu_5731_p1() {
    newIndex27_fu_5731_p1 = esl_zext<64,6>(tmp_102_reg_6711.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex28_fu_5883_p1() {
    newIndex28_fu_5883_p1 = esl_zext<64,6>(tmp_91_reg_6882.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex29_fu_5739_p1() {
    newIndex29_fu_5739_p1 = esl_zext<64,6>(tmp_103_reg_6720.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex2_fu_5488_p1() {
    newIndex2_fu_5488_p1 = esl_zext<64,6>(tmp_74_reg_6595.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex30_fu_5811_p1() {
    newIndex30_fu_5811_p1 = esl_zext<64,6>(tmp_92_reg_6801.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex31_fu_5747_p1() {
    newIndex31_fu_5747_p1 = esl_zext<64,6>(tmp_104_reg_6729.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex32_fu_5819_p1() {
    newIndex32_fu_5819_p1 = esl_zext<64,6>(tmp_93_reg_6810.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex33_fu_5755_p1() {
    newIndex33_fu_5755_p1 = esl_zext<64,6>(tmp_105_reg_6738.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex34_fu_5827_p1() {
    newIndex34_fu_5827_p1 = esl_zext<64,6>(tmp_94_reg_6819.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex35_fu_5763_p1() {
    newIndex35_fu_5763_p1 = esl_zext<64,6>(tmp_106_reg_6747.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex36_fu_5835_p1() {
    newIndex36_fu_5835_p1 = esl_zext<64,6>(tmp_95_reg_6828.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex37_fu_5691_p1() {
    newIndex37_fu_5691_p1 = esl_zext<64,6>(tmp_107_reg_6666.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex38_fu_5843_p1() {
    newIndex38_fu_5843_p1 = esl_zext<64,6>(tmp_96_reg_6837.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex39_fu_5699_p1() {
    newIndex39_fu_5699_p1 = esl_zext<64,6>(tmp_108_reg_6675.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex3_fu_4378_p1() {
    newIndex3_fu_4378_p1 = esl_zext<64,6>(tmp_69_reg_6364.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex40_fu_5707_p1() {
    newIndex40_fu_5707_p1 = esl_zext<64,6>(tmp_109_reg_6684.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex41_fu_5715_p1() {
    newIndex41_fu_5715_p1 = esl_zext<64,6>(tmp_148_reg_6693.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex42_fu_5723_p1() {
    newIndex42_fu_5723_p1 = esl_zext<64,6>(tmp_149_reg_6702.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex43_fu_5651_p1() {
    newIndex43_fu_5651_p1 = esl_zext<64,6>(tmp_150_reg_6621.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex44_fu_5659_p1() {
    newIndex44_fu_5659_p1 = esl_zext<64,6>(tmp_151_reg_6630.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex45_fu_5667_p1() {
    newIndex45_fu_5667_p1 = esl_zext<64,6>(tmp_152_reg_6639.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex46_fu_5675_p1() {
    newIndex46_fu_5675_p1 = esl_zext<64,6>(tmp_153_reg_6648.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex47_fu_5683_p1() {
    newIndex47_fu_5683_p1 = esl_zext<64,6>(tmp_154_reg_6657.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex4_fu_5496_p1() {
    newIndex4_fu_5496_p1 = esl_zext<64,6>(tmp_75_reg_6604.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex5_fu_4386_p1() {
    newIndex5_fu_4386_p1 = esl_zext<64,6>(tmp_70_reg_6374.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex6_fu_5931_p1() {
    newIndex6_fu_5931_p1 = esl_zext<64,6>(tmp_77_reg_6936.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex7_fu_4394_p1() {
    newIndex7_fu_4394_p1 = esl_zext<64,6>(tmp_71_reg_6384.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex8_fu_5939_p1() {
    newIndex8_fu_5939_p1 = esl_zext<64,6>(tmp_78_reg_6945.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex9_fu_5472_p1() {
    newIndex9_fu_5472_p1 = esl_zext<64,6>(tmp_72_reg_6577.read());
}

void VMRouterDispatcher_VMRouter::thread_newIndex_fu_5480_p1() {
    newIndex_fu_5480_p1 = esl_zext<64,6>(tmp_73_reg_6586.read());
}

void VMRouterDispatcher_VMRouter::thread_op2_V_read_assign_phi_fu_3986_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()) && 
         !esl_seteq<1,1,1>(tmp_4_reg_6337.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(tmp_67_reg_6328.read(), ap_const_lv1_0))) {
        op2_V_read_assign_phi_fu_3986_p4 = index_V_reg_6332.read();
    } else {
        op2_V_read_assign_phi_fu_3986_p4 = op2_V_read_assign_reg_3942.read();
    }
}

void VMRouterDispatcher_VMRouter::thread_redPt_V_fu_4462_p6() {
    redPt_V_fu_4462_p6 = esl_zext<64,3>(ap_reg_ppstg_arrayNo3_reg_6379_pp0_iter1.read());
}

void VMRouterDispatcher_VMRouter::thread_routePhi_V_fu_4550_p4() {
    routePhi_V_fu_4550_p4 = curPhi_V_fu_4430_p7.read().range(13, 12);
}

void VMRouterDispatcher_VMRouter::thread_routeZ_V_fu_4560_p3() {
    routeZ_V_fu_4560_p3 = curZ_V_fu_4414_p7.read().range(9, 9);
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_phi_V_address0() {
    stubsInLayer_0_phi_V_address0 =  (sc_lv<6>) (newIndex3_fu_4378_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_pt_V_address0() {
    stubsInLayer_0_pt_V_address0 =  (sc_lv<6>) (newIndex7_fu_4394_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_r_V_address0() {
    stubsInLayer_0_r_V_address0 =  (sc_lv<6>) (newIndex5_fu_4386_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_0_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_z_V_address0() {
    stubsInLayer_0_z_V_address0 =  (sc_lv<6>) (newIndex1_fu_4370_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_0_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_phi_V_address0() {
    stubsInLayer_1_phi_V_address0 =  (sc_lv<6>) (newIndex3_fu_4378_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_pt_V_address0() {
    stubsInLayer_1_pt_V_address0 =  (sc_lv<6>) (newIndex7_fu_4394_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_r_V_address0() {
    stubsInLayer_1_r_V_address0 =  (sc_lv<6>) (newIndex5_fu_4386_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_1_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_z_V_address0() {
    stubsInLayer_1_z_V_address0 =  (sc_lv<6>) (newIndex1_fu_4370_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_1_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_1_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_phi_V_address0() {
    stubsInLayer_2_phi_V_address0 =  (sc_lv<6>) (newIndex3_fu_4378_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_pt_V_address0() {
    stubsInLayer_2_pt_V_address0 =  (sc_lv<6>) (newIndex7_fu_4394_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_r_V_address0() {
    stubsInLayer_2_r_V_address0 =  (sc_lv<6>) (newIndex5_fu_4386_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_2_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_z_V_address0() {
    stubsInLayer_2_z_V_address0 =  (sc_lv<6>) (newIndex1_fu_4370_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_2_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_2_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_phi_V_address0() {
    stubsInLayer_3_phi_V_address0 =  (sc_lv<6>) (newIndex3_fu_4378_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_pt_V_address0() {
    stubsInLayer_3_pt_V_address0 =  (sc_lv<6>) (newIndex7_fu_4394_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_r_V_address0() {
    stubsInLayer_3_r_V_address0 =  (sc_lv<6>) (newIndex5_fu_4386_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_3_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_z_V_address0() {
    stubsInLayer_3_z_V_address0 =  (sc_lv<6>) (newIndex1_fu_4370_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_3_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_phi_V_address0() {
    stubsInLayer_4_phi_V_address0 =  (sc_lv<6>) (newIndex3_fu_4378_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_phi_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_pt_V_address0() {
    stubsInLayer_4_pt_V_address0 =  (sc_lv<6>) (newIndex7_fu_4394_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_r_V_address0() {
    stubsInLayer_4_r_V_address0 =  (sc_lv<6>) (newIndex5_fu_4386_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_4_r_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_z_V_address0() {
    stubsInLayer_4_z_V_address0 =  (sc_lv<6>) (newIndex1_fu_4370_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_stubsInLayer_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
        stubsInLayer_4_z_V_ce0 = ap_const_logic_1;
    } else {
        stubsInLayer_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_sum10_fu_4949_p2() {
    sum10_fu_4949_p2 = (!tmp_29_reg_6138.read().is_01() || !tmp_2_cast_fu_4907_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_29_reg_6138.read()) + sc_biguint<9>(tmp_2_cast_fu_4907_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum11_fu_4968_p2() {
    sum11_fu_4968_p2 = (!tmp_30_reg_6143.read().is_01() || !tmp_2_cast_fu_4907_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_30_reg_6143.read()) + sc_biguint<9>(tmp_2_cast_fu_4907_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum12_fu_4987_p2() {
    sum12_fu_4987_p2 = (!tmp_31_reg_6148.read().is_01() || !tmp_2_cast_fu_4907_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_31_reg_6148.read()) + sc_biguint<9>(tmp_2_cast_fu_4907_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum13_fu_4798_p2() {
    sum13_fu_4798_p2 = (!tmp_32_reg_6153.read().is_01() || !tmp_3_cast_fu_4794_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_32_reg_6153.read()) + sc_biguint<9>(tmp_3_cast_fu_4794_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum14_fu_4817_p2() {
    sum14_fu_4817_p2 = (!tmp_33_reg_6158.read().is_01() || !tmp_3_cast_fu_4794_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_33_reg_6158.read()) + sc_biguint<9>(tmp_3_cast_fu_4794_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum15_fu_4836_p2() {
    sum15_fu_4836_p2 = (!tmp_34_reg_6163.read().is_01() || !tmp_3_cast_fu_4794_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_34_reg_6163.read()) + sc_biguint<9>(tmp_3_cast_fu_4794_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum16_fu_4855_p2() {
    sum16_fu_4855_p2 = (!tmp_35_reg_6168.read().is_01() || !tmp_3_cast_fu_4794_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_35_reg_6168.read()) + sc_biguint<9>(tmp_3_cast_fu_4794_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum17_fu_4874_p2() {
    sum17_fu_4874_p2 = (!tmp_36_reg_6173.read().is_01() || !tmp_3_cast_fu_4794_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_36_reg_6173.read()) + sc_biguint<9>(tmp_3_cast_fu_4794_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum18_fu_4685_p2() {
    sum18_fu_4685_p2 = (!tmp_37_reg_6178.read().is_01() || !tmp_10_cast_fu_4681_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_37_reg_6178.read()) + sc_biguint<9>(tmp_10_cast_fu_4681_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum19_fu_4704_p2() {
    sum19_fu_4704_p2 = (!tmp_38_reg_6183.read().is_01() || !tmp_10_cast_fu_4681_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_38_reg_6183.read()) + sc_biguint<9>(tmp_10_cast_fu_4681_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum1_fu_4307_p2() {
    sum1_fu_4307_p2 = (!tmp_5_cast_fu_4284_p1.read().is_01() || !tmp_20_reg_6093.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_5_cast_fu_4284_p1.read()) + sc_biguint<9>(tmp_20_reg_6093.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum20_fu_4723_p2() {
    sum20_fu_4723_p2 = (!tmp_39_reg_6188.read().is_01() || !tmp_10_cast_fu_4681_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_39_reg_6188.read()) + sc_biguint<9>(tmp_10_cast_fu_4681_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum21_fu_4742_p2() {
    sum21_fu_4742_p2 = (!tmp_40_reg_6193.read().is_01() || !tmp_10_cast_fu_4681_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_40_reg_6193.read()) + sc_biguint<9>(tmp_10_cast_fu_4681_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum22_fu_4761_p2() {
    sum22_fu_4761_p2 = (!tmp_41_reg_6198.read().is_01() || !tmp_10_cast_fu_4681_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_41_reg_6198.read()) + sc_biguint<9>(tmp_10_cast_fu_4681_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum23_fu_4572_p2() {
    sum23_fu_4572_p2 = (!tmp_42_reg_6203.read().is_01() || !tmp_31_cast_fu_4568_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_42_reg_6203.read()) + sc_biguint<9>(tmp_31_cast_fu_4568_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum24_fu_4591_p2() {
    sum24_fu_4591_p2 = (!tmp_43_reg_6208.read().is_01() || !tmp_31_cast_fu_4568_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_43_reg_6208.read()) + sc_biguint<9>(tmp_31_cast_fu_4568_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum25_fu_4610_p2() {
    sum25_fu_4610_p2 = (!tmp_44_reg_6213.read().is_01() || !tmp_31_cast_fu_4568_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_44_reg_6213.read()) + sc_biguint<9>(tmp_31_cast_fu_4568_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum26_fu_4629_p2() {
    sum26_fu_4629_p2 = (!tmp_45_reg_6218.read().is_01() || !tmp_31_cast_fu_4568_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_45_reg_6218.read()) + sc_biguint<9>(tmp_31_cast_fu_4568_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum27_fu_4648_p2() {
    sum27_fu_4648_p2 = (!tmp_46_reg_6223.read().is_01() || !tmp_31_cast_fu_4568_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_46_reg_6223.read()) + sc_biguint<9>(tmp_31_cast_fu_4568_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum28_fu_5363_p2() {
    sum28_fu_5363_p2 = (!tmp_47_reg_6228.read().is_01() || !tmp_32_cast_fu_5359_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_47_reg_6228.read()) + sc_biguint<9>(tmp_32_cast_fu_5359_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum29_fu_5382_p2() {
    sum29_fu_5382_p2 = (!tmp_48_reg_6233.read().is_01() || !tmp_32_cast_fu_5359_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_48_reg_6233.read()) + sc_biguint<9>(tmp_32_cast_fu_5359_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum2_fu_4326_p2() {
    sum2_fu_4326_p2 = (!tmp_5_cast_fu_4284_p1.read().is_01() || !tmp_21_reg_6098.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_5_cast_fu_4284_p1.read()) + sc_biguint<9>(tmp_21_reg_6098.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum30_fu_5401_p2() {
    sum30_fu_5401_p2 = (!tmp_49_reg_6238.read().is_01() || !tmp_32_cast_fu_5359_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_49_reg_6238.read()) + sc_biguint<9>(tmp_32_cast_fu_5359_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum31_fu_5420_p2() {
    sum31_fu_5420_p2 = (!tmp_50_reg_6243.read().is_01() || !tmp_32_cast_fu_5359_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_50_reg_6243.read()) + sc_biguint<9>(tmp_32_cast_fu_5359_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum32_fu_5439_p2() {
    sum32_fu_5439_p2 = (!tmp_51_reg_6248.read().is_01() || !tmp_32_cast_fu_5359_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_51_reg_6248.read()) + sc_biguint<9>(tmp_32_cast_fu_5359_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum33_fu_5250_p2() {
    sum33_fu_5250_p2 = (!tmp_52_reg_6253.read().is_01() || !tmp_20_cast_fu_5246_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_52_reg_6253.read()) + sc_biguint<9>(tmp_20_cast_fu_5246_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum34_fu_5269_p2() {
    sum34_fu_5269_p2 = (!tmp_53_reg_6258.read().is_01() || !tmp_20_cast_fu_5246_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_53_reg_6258.read()) + sc_biguint<9>(tmp_20_cast_fu_5246_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum35_fu_5288_p2() {
    sum35_fu_5288_p2 = (!tmp_54_reg_6263.read().is_01() || !tmp_20_cast_fu_5246_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_54_reg_6263.read()) + sc_biguint<9>(tmp_20_cast_fu_5246_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum36_fu_5307_p2() {
    sum36_fu_5307_p2 = (!tmp_55_reg_6268.read().is_01() || !tmp_20_cast_fu_5246_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_55_reg_6268.read()) + sc_biguint<9>(tmp_20_cast_fu_5246_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum37_fu_5326_p2() {
    sum37_fu_5326_p2 = (!tmp_56_reg_6273.read().is_01() || !tmp_20_cast_fu_5246_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_56_reg_6273.read()) + sc_biguint<9>(tmp_20_cast_fu_5246_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum38_fu_5137_p2() {
    sum38_fu_5137_p2 = (!tmp_57_reg_6278.read().is_01() || !tmp_22_cast_fu_5133_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_57_reg_6278.read()) + sc_biguint<9>(tmp_22_cast_fu_5133_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum39_fu_5156_p2() {
    sum39_fu_5156_p2 = (!tmp_58_reg_6283.read().is_01() || !tmp_22_cast_fu_5133_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_58_reg_6283.read()) + sc_biguint<9>(tmp_22_cast_fu_5133_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum3_fu_4345_p2() {
    sum3_fu_4345_p2 = (!tmp_5_cast_fu_4284_p1.read().is_01() || !tmp_22_reg_6103.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_5_cast_fu_4284_p1.read()) + sc_biguint<9>(tmp_22_reg_6103.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum40_fu_5175_p2() {
    sum40_fu_5175_p2 = (!tmp_59_reg_6288.read().is_01() || !tmp_22_cast_fu_5133_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_59_reg_6288.read()) + sc_biguint<9>(tmp_22_cast_fu_5133_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum41_fu_5194_p2() {
    sum41_fu_5194_p2 = (!tmp_60_reg_6293.read().is_01() || !tmp_22_cast_fu_5133_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_60_reg_6293.read()) + sc_biguint<9>(tmp_22_cast_fu_5133_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum42_fu_5213_p2() {
    sum42_fu_5213_p2 = (!tmp_61_reg_6298.read().is_01() || !tmp_22_cast_fu_5133_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_61_reg_6298.read()) + sc_biguint<9>(tmp_22_cast_fu_5133_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum43_fu_5024_p2() {
    sum43_fu_5024_p2 = (!tmp_62_reg_6303.read().is_01() || !tmp_24_cast_fu_5020_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_62_reg_6303.read()) + sc_biguint<9>(tmp_24_cast_fu_5020_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum44_fu_5043_p2() {
    sum44_fu_5043_p2 = (!tmp_63_reg_6308.read().is_01() || !tmp_24_cast_fu_5020_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_63_reg_6308.read()) + sc_biguint<9>(tmp_24_cast_fu_5020_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum45_fu_5062_p2() {
    sum45_fu_5062_p2 = (!tmp_64_reg_6313.read().is_01() || !tmp_24_cast_fu_5020_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_64_reg_6313.read()) + sc_biguint<9>(tmp_24_cast_fu_5020_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum46_fu_5081_p2() {
    sum46_fu_5081_p2 = (!tmp_65_reg_6318.read().is_01() || !tmp_24_cast_fu_5020_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_65_reg_6318.read()) + sc_biguint<9>(tmp_24_cast_fu_5020_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum47_fu_5100_p2() {
    sum47_fu_5100_p2 = (!tmp_66_reg_6323.read().is_01() || !tmp_24_cast_fu_5020_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_66_reg_6323.read()) + sc_biguint<9>(tmp_24_cast_fu_5020_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum4_fu_4478_p2() {
    sum4_fu_4478_p2 = (!ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read().is_01() || !tmp_23_reg_6108.read().is_01())? sc_lv<9>(): (sc_biguint<9>(ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read()) + sc_biguint<9>(tmp_23_reg_6108.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum5_fu_4496_p2() {
    sum5_fu_4496_p2 = (!ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read().is_01() || !tmp_24_reg_6113.read().is_01())? sc_lv<9>(): (sc_biguint<9>(ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read()) + sc_biguint<9>(tmp_24_reg_6113.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum6_fu_4514_p2() {
    sum6_fu_4514_p2 = (!ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read().is_01() || !tmp_25_reg_6118.read().is_01())? sc_lv<9>(): (sc_biguint<9>(ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read()) + sc_biguint<9>(tmp_25_reg_6118.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum7_fu_4532_p2() {
    sum7_fu_4532_p2 = (!ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read().is_01() || !tmp_26_reg_6123.read().is_01())? sc_lv<9>(): (sc_biguint<9>(ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1.read()) + sc_biguint<9>(tmp_26_reg_6123.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum8_fu_4911_p2() {
    sum8_fu_4911_p2 = (!tmp_27_reg_6128.read().is_01() || !tmp_2_cast_fu_4907_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_27_reg_6128.read()) + sc_biguint<9>(tmp_2_cast_fu_4907_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum9_fu_4930_p2() {
    sum9_fu_4930_p2 = (!tmp_28_reg_6133.read().is_01() || !tmp_2_cast_fu_4907_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_28_reg_6133.read()) + sc_biguint<9>(tmp_2_cast_fu_4907_p1.read()));
}

void VMRouterDispatcher_VMRouter::thread_sum_fu_4288_p2() {
    sum_fu_4288_p2 = (!tmp_5_cast_fu_4284_p1.read().is_01() || !tmp_reg_6088.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_5_cast_fu_4284_p1.read()) + sc_biguint<9>(tmp_reg_6088.read()));
}

void VMRouterDispatcher_VMRouter::thread_tmp_100_fu_4983_p1() {
    tmp_100_fu_4983_p1 = sum11_fu_4968_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_101_fu_5002_p1() {
    tmp_101_fu_5002_p1 = sum12_fu_4987_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_102_fu_4813_p1() {
    tmp_102_fu_4813_p1 = sum13_fu_4798_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_103_fu_4832_p1() {
    tmp_103_fu_4832_p1 = sum14_fu_4817_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_104_fu_4851_p1() {
    tmp_104_fu_4851_p1 = sum15_fu_4836_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_105_fu_4870_p1() {
    tmp_105_fu_4870_p1 = sum16_fu_4855_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_106_fu_4889_p1() {
    tmp_106_fu_4889_p1 = sum17_fu_4874_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_107_fu_4700_p1() {
    tmp_107_fu_4700_p1 = sum18_fu_4685_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_108_fu_4719_p1() {
    tmp_108_fu_4719_p1 = sum19_fu_4704_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_109_fu_4738_p1() {
    tmp_109_fu_4738_p1 = sum20_fu_4723_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_10_cast_fu_4681_p1() {
    tmp_10_cast_fu_4681_p1 = esl_zext<9,6>(nPH3Z1_V_fu_708.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_10_fu_4670_p2() {
    tmp_10_fu_4670_p2 = (!nPH4Z1_V_fu_704.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z1_V_fu_704.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_148_fu_4757_p1() {
    tmp_148_fu_4757_p1 = sum21_fu_4742_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_149_fu_4776_p1() {
    tmp_149_fu_4776_p1 = sum22_fu_4761_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_150_fu_4587_p1() {
    tmp_150_fu_4587_p1 = sum23_fu_4572_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_151_fu_4606_p1() {
    tmp_151_fu_4606_p1 = sum24_fu_4591_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_152_fu_4625_p1() {
    tmp_152_fu_4625_p1 = sum25_fu_4610_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_153_fu_4644_p1() {
    tmp_153_fu_4644_p1 = sum26_fu_4629_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_154_fu_4663_p1() {
    tmp_154_fu_4663_p1 = sum27_fu_4648_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_20_cast_fu_5246_p1() {
    tmp_20_cast_fu_5246_p1 = esl_zext<9,6>(nPH2Z2_V_fu_696.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_20_fu_4033_p1() {
    tmp_20_fu_4033_p1 = tmp_11.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_21_fu_4037_p1() {
    tmp_21_fu_4037_p1 = tmp_12.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_22_cast_fu_5133_p1() {
    tmp_22_cast_fu_5133_p1 = esl_zext<9,6>(nPH3Z2_V_fu_692.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_22_fu_4041_p1() {
    tmp_22_fu_4041_p1 = tmp_13.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_23_fu_4045_p1() {
    tmp_23_fu_4045_p1 = tmp_14.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_24_cast_fu_5020_p1() {
    tmp_24_cast_fu_5020_p1 = esl_zext<9,6>(nPH4Z2_V_fu_688.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_24_fu_4049_p1() {
    tmp_24_fu_4049_p1 = tmp_15.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_25_fu_4053_p1() {
    tmp_25_fu_4053_p1 = tmp_16.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_26_fu_4057_p1() {
    tmp_26_fu_4057_p1 = tmp_17.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_27_fu_4061_p1() {
    tmp_27_fu_4061_p1 = tmp_18.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_28_fu_4065_p1() {
    tmp_28_fu_4065_p1 = tmp_19.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_29_fu_4069_p1() {
    tmp_29_fu_4069_p1 = tmp_110.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_2_cast_fu_4907_p1() {
    tmp_2_cast_fu_4907_p1 = esl_zext<9,6>(nPH1Z1_V_fu_716.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_30_fu_4073_p1() {
    tmp_30_fu_4073_p1 = tmp_111.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_31_cast_fu_4568_p1() {
    tmp_31_cast_fu_4568_p1 = esl_zext<9,6>(nPH4Z1_V_fu_704.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_31_fu_4077_p1() {
    tmp_31_fu_4077_p1 = tmp_112.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_32_cast_fu_5359_p1() {
    tmp_32_cast_fu_5359_p1 = esl_zext<9,6>(nPH1Z2_V_fu_700.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_32_fu_4081_p1() {
    tmp_32_fu_4081_p1 = tmp_113.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_33_fu_4085_p1() {
    tmp_33_fu_4085_p1 = tmp_114.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_34_fu_4089_p1() {
    tmp_34_fu_4089_p1 = tmp_115.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_35_fu_4093_p1() {
    tmp_35_fu_4093_p1 = tmp_116.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_36_fu_4097_p1() {
    tmp_36_fu_4097_p1 = tmp_117.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_37_fu_4101_p1() {
    tmp_37_fu_4101_p1 = tmp_118.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_38_fu_4105_p1() {
    tmp_38_fu_4105_p1 = tmp_119.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_39_fu_4109_p1() {
    tmp_39_fu_4109_p1 = tmp_120.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_3_cast_fu_4794_p1() {
    tmp_3_cast_fu_4794_p1 = esl_zext<9,6>(nPH2Z1_V_fu_712.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_3_fu_5009_p2() {
    tmp_3_fu_5009_p2 = (!nPH1Z1_V_fu_716.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z1_V_fu_716.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_40_fu_4113_p1() {
    tmp_40_fu_4113_p1 = tmp_121.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_41_fu_4117_p1() {
    tmp_41_fu_4117_p1 = tmp_122.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_42_fu_4121_p1() {
    tmp_42_fu_4121_p1 = tmp_123.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_43_fu_4125_p1() {
    tmp_43_fu_4125_p1 = tmp_124.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_44_fu_4129_p1() {
    tmp_44_fu_4129_p1 = tmp_125.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_45_fu_4133_p1() {
    tmp_45_fu_4133_p1 = tmp_126.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_46_fu_4137_p1() {
    tmp_46_fu_4137_p1 = tmp_127.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_47_fu_4141_p1() {
    tmp_47_fu_4141_p1 = tmp_128.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_48_fu_4145_p1() {
    tmp_48_fu_4145_p1 = tmp_129.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_49_fu_4149_p1() {
    tmp_49_fu_4149_p1 = tmp_130.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_4_fu_4279_p2() {
    tmp_4_fu_4279_p2 = (!i_cast3_fu_4275_p1.read().is_01() || !nStubs.read().is_01())? sc_lv<1>(): (sc_bigint<32>(i_cast3_fu_4275_p1.read()) < sc_bigint<32>(nStubs.read()));
}

void VMRouterDispatcher_VMRouter::thread_tmp_50_fu_4153_p1() {
    tmp_50_fu_4153_p1 = tmp_131.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_51_fu_4157_p1() {
    tmp_51_fu_4157_p1 = tmp_132.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_52_fu_4161_p1() {
    tmp_52_fu_4161_p1 = tmp_133.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_53_fu_4165_p1() {
    tmp_53_fu_4165_p1 = tmp_134.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_54_fu_4169_p1() {
    tmp_54_fu_4169_p1 = tmp_135.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_55_fu_4173_p1() {
    tmp_55_fu_4173_p1 = tmp_136.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_56_fu_4177_p1() {
    tmp_56_fu_4177_p1 = tmp_137.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_57_fu_4181_p1() {
    tmp_57_fu_4181_p1 = tmp_138.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_58_fu_4185_p1() {
    tmp_58_fu_4185_p1 = tmp_139.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_59_fu_4189_p1() {
    tmp_59_fu_4189_p1 = tmp_140.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_5_cast_fu_4284_p1() {
    tmp_5_cast_fu_4284_p1 = esl_zext<9,7>(i_reg_3994.read());
}

void VMRouterDispatcher_VMRouter::thread_tmp_5_fu_4896_p2() {
    tmp_5_fu_4896_p2 = (!nPH2Z1_V_fu_712.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z1_V_fu_712.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_60_fu_4193_p1() {
    tmp_60_fu_4193_p1 = tmp_141.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_61_fu_4197_p1() {
    tmp_61_fu_4197_p1 = tmp_142.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_62_fu_4201_p1() {
    tmp_62_fu_4201_p1 = tmp_143.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_63_fu_4205_p1() {
    tmp_63_fu_4205_p1 = tmp_144.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_64_fu_4209_p1() {
    tmp_64_fu_4209_p1 = tmp_145.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_65_fu_4213_p1() {
    tmp_65_fu_4213_p1 = tmp_146.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_66_fu_4217_p1() {
    tmp_66_fu_4217_p1 = tmp_147.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_67_fu_4261_p3() {
    tmp_67_fu_4261_p3 = i_reg_3994.read().range(6, 6);
}

void VMRouterDispatcher_VMRouter::thread_tmp_68_fu_4303_p1() {
    tmp_68_fu_4303_p1 = sum_fu_4288_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_69_fu_4322_p1() {
    tmp_69_fu_4322_p1 = sum1_fu_4307_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_6_fu_5348_p2() {
    tmp_6_fu_5348_p2 = (!nPH2Z2_V_fu_696.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH2Z2_V_fu_696.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_70_fu_4341_p1() {
    tmp_70_fu_4341_p1 = sum2_fu_4326_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_71_fu_4360_p1() {
    tmp_71_fu_4360_p1 = sum3_fu_4345_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_72_fu_4492_p1() {
    tmp_72_fu_4492_p1 = sum4_fu_4478_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_73_fu_4510_p1() {
    tmp_73_fu_4510_p1 = sum5_fu_4496_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_74_fu_4528_p1() {
    tmp_74_fu_4528_p1 = sum6_fu_4514_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_75_fu_4546_p1() {
    tmp_75_fu_4546_p1 = sum7_fu_4532_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_77_fu_5378_p1() {
    tmp_77_fu_5378_p1 = sum28_fu_5363_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_78_fu_5397_p1() {
    tmp_78_fu_5397_p1 = sum29_fu_5382_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_79_fu_5416_p1() {
    tmp_79_fu_5416_p1 = sum30_fu_5401_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_7_fu_5235_p2() {
    tmp_7_fu_5235_p2 = (!nPH3Z2_V_fu_692.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z2_V_fu_692.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_80_fu_5435_p1() {
    tmp_80_fu_5435_p1 = sum31_fu_5420_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_81_fu_5454_p1() {
    tmp_81_fu_5454_p1 = sum32_fu_5439_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_82_fu_5265_p1() {
    tmp_82_fu_5265_p1 = sum33_fu_5250_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_83_fu_5284_p1() {
    tmp_83_fu_5284_p1 = sum34_fu_5269_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_84_fu_5303_p1() {
    tmp_84_fu_5303_p1 = sum35_fu_5288_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_85_fu_5322_p1() {
    tmp_85_fu_5322_p1 = sum36_fu_5307_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_86_fu_5341_p1() {
    tmp_86_fu_5341_p1 = sum37_fu_5326_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_87_fu_5152_p1() {
    tmp_87_fu_5152_p1 = sum38_fu_5137_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_88_fu_5171_p1() {
    tmp_88_fu_5171_p1 = sum39_fu_5156_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_89_fu_5190_p1() {
    tmp_89_fu_5190_p1 = sum40_fu_5175_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_8_fu_5122_p2() {
    tmp_8_fu_5122_p2 = (!nPH4Z2_V_fu_688.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH4Z2_V_fu_688.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_90_fu_5209_p1() {
    tmp_90_fu_5209_p1 = sum41_fu_5194_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_91_fu_5228_p1() {
    tmp_91_fu_5228_p1 = sum42_fu_5213_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_92_fu_5039_p1() {
    tmp_92_fu_5039_p1 = sum43_fu_5024_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_93_fu_5058_p1() {
    tmp_93_fu_5058_p1 = sum44_fu_5043_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_94_fu_5077_p1() {
    tmp_94_fu_5077_p1 = sum45_fu_5062_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_95_fu_5096_p1() {
    tmp_95_fu_5096_p1 = sum46_fu_5081_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_96_fu_5115_p1() {
    tmp_96_fu_5115_p1 = sum47_fu_5100_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_97_fu_4926_p1() {
    tmp_97_fu_4926_p1 = sum8_fu_4911_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_98_fu_4945_p1() {
    tmp_98_fu_4945_p1 = sum9_fu_4930_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_99_fu_4964_p1() {
    tmp_99_fu_4964_p1 = sum10_fu_4949_p2.read().range(6-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_9_fu_4783_p2() {
    tmp_9_fu_4783_p2 = (!nPH3Z1_V_fu_708.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH3Z1_V_fu_708.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_tmp_fu_4029_p1() {
    tmp_fu_4029_p1 = tmp_1.read().range(9-1, 0);
}

void VMRouterDispatcher_VMRouter::thread_tmp_s_fu_5461_p2() {
    tmp_s_fu_5461_p2 = (!nPH1Z2_V_fu_700.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(nPH1Z2_V_fu_700.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_index_V_address0() {
    vmStubsPH1Z1_0_index_V_address0 =  (sc_lv<6>) (newIndex25_fu_5803_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_index_V_d0() {
    vmStubsPH1Z1_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_phi_V_address0() {
    vmStubsPH1Z1_0_phi_V_address0 =  (sc_lv<6>) (newIndex19_fu_5779_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_phi_V_d0() {
    vmStubsPH1Z1_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_pt_V_address0() {
    vmStubsPH1Z1_0_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_5795_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_pt_V_d0() {
    vmStubsPH1Z1_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_r_V_address0() {
    vmStubsPH1Z1_0_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_5787_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_r_V_d0() {
    vmStubsPH1Z1_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_z_V_address0() {
    vmStubsPH1Z1_0_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_5771_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_z_V_d0() {
    vmStubsPH1Z1_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_index_V_address0() {
    vmStubsPH1Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex25_fu_5803_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_index_V_d0() {
    vmStubsPH1Z1_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_phi_V_address0() {
    vmStubsPH1Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex19_fu_5779_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_phi_V_d0() {
    vmStubsPH1Z1_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_pt_V_address0() {
    vmStubsPH1Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_5795_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_pt_V_d0() {
    vmStubsPH1Z1_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_r_V_address0() {
    vmStubsPH1Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_5787_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_r_V_d0() {
    vmStubsPH1Z1_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_z_V_address0() {
    vmStubsPH1Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_5771_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_z_V_d0() {
    vmStubsPH1Z1_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_index_V_address0() {
    vmStubsPH1Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex25_fu_5803_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_index_V_d0() {
    vmStubsPH1Z1_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_phi_V_address0() {
    vmStubsPH1Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex19_fu_5779_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_phi_V_d0() {
    vmStubsPH1Z1_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_pt_V_address0() {
    vmStubsPH1Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_5795_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_pt_V_d0() {
    vmStubsPH1Z1_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_r_V_address0() {
    vmStubsPH1Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_5787_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_r_V_d0() {
    vmStubsPH1Z1_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_z_V_address0() {
    vmStubsPH1Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_5771_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_z_V_d0() {
    vmStubsPH1Z1_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_index_V_address0() {
    vmStubsPH1Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex25_fu_5803_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_index_V_d0() {
    vmStubsPH1Z1_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_phi_V_address0() {
    vmStubsPH1Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex19_fu_5779_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_phi_V_d0() {
    vmStubsPH1Z1_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_pt_V_address0() {
    vmStubsPH1Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_5795_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_pt_V_d0() {
    vmStubsPH1Z1_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_r_V_address0() {
    vmStubsPH1Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_5787_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_r_V_d0() {
    vmStubsPH1Z1_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_z_V_address0() {
    vmStubsPH1Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_5771_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_z_V_d0() {
    vmStubsPH1Z1_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_index_V_address0() {
    vmStubsPH1Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex25_fu_5803_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_index_V_d0() {
    vmStubsPH1Z1_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo12_cast_cast_reg_6788.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_phi_V_address0() {
    vmStubsPH1Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex19_fu_5779_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_phi_V_d0() {
    vmStubsPH1Z1_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo9_cast_cast_reg_6761.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_pt_V_address0() {
    vmStubsPH1Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_5795_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_pt_V_d0() {
    vmStubsPH1Z1_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo11_cast_cast_reg_6779.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_r_V_address0() {
    vmStubsPH1Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_5787_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_r_V_d0() {
    vmStubsPH1Z1_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo10_cast_cast_reg_6770.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_z_V_address0() {
    vmStubsPH1Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_5771_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_z_V_d0() {
    vmStubsPH1Z1_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo8_cast_cast_reg_6752.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_index_V_address0() {
    vmStubsPH1Z2_0_index_V_address0 =  (sc_lv<6>) (newIndex12_fu_5963_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_index_V_d0() {
    vmStubsPH1Z2_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_phi_V_address0() {
    vmStubsPH1Z2_0_phi_V_address0 =  (sc_lv<6>) (newIndex8_fu_5939_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_phi_V_d0() {
    vmStubsPH1Z2_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_pt_V_address0() {
    vmStubsPH1Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex11_fu_5955_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_pt_V_d0() {
    vmStubsPH1Z2_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_r_V_address0() {
    vmStubsPH1Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex10_fu_5947_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_r_V_d0() {
    vmStubsPH1Z2_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_z_V_address0() {
    vmStubsPH1Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex6_fu_5931_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_z_V_d0() {
    vmStubsPH1Z2_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_0)))) {
        vmStubsPH1Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_index_V_address0() {
    vmStubsPH1Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex12_fu_5963_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_index_V_d0() {
    vmStubsPH1Z2_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_phi_V_address0() {
    vmStubsPH1Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex8_fu_5939_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_phi_V_d0() {
    vmStubsPH1Z2_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_pt_V_address0() {
    vmStubsPH1Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex11_fu_5955_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_pt_V_d0() {
    vmStubsPH1Z2_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_r_V_address0() {
    vmStubsPH1Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex10_fu_5947_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_r_V_d0() {
    vmStubsPH1Z2_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_z_V_address0() {
    vmStubsPH1Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex6_fu_5931_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_z_V_d0() {
    vmStubsPH1Z2_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_1)))) {
        vmStubsPH1Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_index_V_address0() {
    vmStubsPH1Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex12_fu_5963_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_index_V_d0() {
    vmStubsPH1Z2_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_phi_V_address0() {
    vmStubsPH1Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex8_fu_5939_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_phi_V_d0() {
    vmStubsPH1Z2_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_pt_V_address0() {
    vmStubsPH1Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex11_fu_5955_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_pt_V_d0() {
    vmStubsPH1Z2_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_r_V_address0() {
    vmStubsPH1Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex10_fu_5947_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_r_V_d0() {
    vmStubsPH1Z2_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_z_V_address0() {
    vmStubsPH1Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex6_fu_5931_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_z_V_d0() {
    vmStubsPH1Z2_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_2)))) {
        vmStubsPH1Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_index_V_address0() {
    vmStubsPH1Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex12_fu_5963_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_index_V_d0() {
    vmStubsPH1Z2_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_phi_V_address0() {
    vmStubsPH1Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex8_fu_5939_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_phi_V_d0() {
    vmStubsPH1Z2_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_pt_V_address0() {
    vmStubsPH1Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex11_fu_5955_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_pt_V_d0() {
    vmStubsPH1Z2_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_r_V_address0() {
    vmStubsPH1Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex10_fu_5947_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_r_V_d0() {
    vmStubsPH1Z2_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_z_V_address0() {
    vmStubsPH1Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex6_fu_5931_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_z_V_d0() {
    vmStubsPH1Z2_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_index_V_address0() {
    vmStubsPH1Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex12_fu_5963_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_index_V_d0() {
    vmStubsPH1Z2_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo32_cast_cast_reg_6968.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_phi_V_address0() {
    vmStubsPH1Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex8_fu_5939_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_phi_V_d0() {
    vmStubsPH1Z2_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo29_cast_cast_reg_6941.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_pt_V_address0() {
    vmStubsPH1Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex11_fu_5955_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_pt_V_d0() {
    vmStubsPH1Z2_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo31_cast_cast_reg_6959.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_r_V_address0() {
    vmStubsPH1Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex10_fu_5947_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_r_V_d0() {
    vmStubsPH1Z2_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo30_cast_cast_reg_6950.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_z_V_address0() {
    vmStubsPH1Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex6_fu_5931_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH1Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_z_V_d0() {
    vmStubsPH1Z2_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH1Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_0) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo28_cast_cast_reg_6932.read(), ap_const_lv3_3)))) {
        vmStubsPH1Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_index_V_address0() {
    vmStubsPH2Z1_0_index_V_address0 =  (sc_lv<6>) (newIndex35_fu_5763_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_index_V_d0() {
    vmStubsPH2Z1_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_phi_V_address0() {
    vmStubsPH2Z1_0_phi_V_address0 =  (sc_lv<6>) (newIndex29_fu_5739_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_phi_V_d0() {
    vmStubsPH2Z1_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_pt_V_address0() {
    vmStubsPH2Z1_0_pt_V_address0 =  (sc_lv<6>) (newIndex33_fu_5755_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_pt_V_d0() {
    vmStubsPH2Z1_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_r_V_address0() {
    vmStubsPH2Z1_0_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_5747_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_r_V_d0() {
    vmStubsPH2Z1_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_z_V_address0() {
    vmStubsPH2Z1_0_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_5731_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_z_V_d0() {
    vmStubsPH2Z1_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_index_V_address0() {
    vmStubsPH2Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex35_fu_5763_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_index_V_d0() {
    vmStubsPH2Z1_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_phi_V_address0() {
    vmStubsPH2Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex29_fu_5739_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_phi_V_d0() {
    vmStubsPH2Z1_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_pt_V_address0() {
    vmStubsPH2Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex33_fu_5755_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_pt_V_d0() {
    vmStubsPH2Z1_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_r_V_address0() {
    vmStubsPH2Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_5747_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_r_V_d0() {
    vmStubsPH2Z1_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_z_V_address0() {
    vmStubsPH2Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_5731_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_z_V_d0() {
    vmStubsPH2Z1_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_index_V_address0() {
    vmStubsPH2Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex35_fu_5763_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_index_V_d0() {
    vmStubsPH2Z1_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_phi_V_address0() {
    vmStubsPH2Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex29_fu_5739_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_phi_V_d0() {
    vmStubsPH2Z1_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_pt_V_address0() {
    vmStubsPH2Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex33_fu_5755_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_pt_V_d0() {
    vmStubsPH2Z1_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_r_V_address0() {
    vmStubsPH2Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_5747_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_r_V_d0() {
    vmStubsPH2Z1_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_z_V_address0() {
    vmStubsPH2Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_5731_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_z_V_d0() {
    vmStubsPH2Z1_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_index_V_address0() {
    vmStubsPH2Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex35_fu_5763_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_index_V_d0() {
    vmStubsPH2Z1_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_phi_V_address0() {
    vmStubsPH2Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex29_fu_5739_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_phi_V_d0() {
    vmStubsPH2Z1_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_pt_V_address0() {
    vmStubsPH2Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex33_fu_5755_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_pt_V_d0() {
    vmStubsPH2Z1_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_r_V_address0() {
    vmStubsPH2Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_5747_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_r_V_d0() {
    vmStubsPH2Z1_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_z_V_address0() {
    vmStubsPH2Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_5731_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_z_V_d0() {
    vmStubsPH2Z1_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_index_V_address0() {
    vmStubsPH2Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex35_fu_5763_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_index_V_d0() {
    vmStubsPH2Z1_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo17_cast_cast_reg_6743.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_phi_V_address0() {
    vmStubsPH2Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex29_fu_5739_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_phi_V_d0() {
    vmStubsPH2Z1_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo14_cast_cast_reg_6716.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_pt_V_address0() {
    vmStubsPH2Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex33_fu_5755_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_pt_V_d0() {
    vmStubsPH2Z1_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo16_cast_cast_reg_6734.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_r_V_address0() {
    vmStubsPH2Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_5747_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_r_V_d0() {
    vmStubsPH2Z1_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo15_cast_cast_reg_6725.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_z_V_address0() {
    vmStubsPH2Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_5731_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_z_V_d0() {
    vmStubsPH2Z1_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo13_cast_cast_reg_6707.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_index_V_address0() {
    vmStubsPH2Z2_0_index_V_address0 =  (sc_lv<6>) (newIndex18_fu_5923_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_index_V_d0() {
    vmStubsPH2Z2_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_phi_V_address0() {
    vmStubsPH2Z2_0_phi_V_address0 =  (sc_lv<6>) (newIndex14_fu_5899_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_phi_V_d0() {
    vmStubsPH2Z2_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_pt_V_address0() {
    vmStubsPH2Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex16_fu_5915_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_pt_V_d0() {
    vmStubsPH2Z2_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_r_V_address0() {
    vmStubsPH2Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex15_fu_5907_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_r_V_d0() {
    vmStubsPH2Z2_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_z_V_address0() {
    vmStubsPH2Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex13_fu_5891_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_z_V_d0() {
    vmStubsPH2Z2_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_0)))) {
        vmStubsPH2Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_index_V_address0() {
    vmStubsPH2Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex18_fu_5923_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_index_V_d0() {
    vmStubsPH2Z2_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_phi_V_address0() {
    vmStubsPH2Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex14_fu_5899_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_phi_V_d0() {
    vmStubsPH2Z2_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_pt_V_address0() {
    vmStubsPH2Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex16_fu_5915_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_pt_V_d0() {
    vmStubsPH2Z2_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_r_V_address0() {
    vmStubsPH2Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex15_fu_5907_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_r_V_d0() {
    vmStubsPH2Z2_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_z_V_address0() {
    vmStubsPH2Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex13_fu_5891_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_z_V_d0() {
    vmStubsPH2Z2_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_1)))) {
        vmStubsPH2Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_index_V_address0() {
    vmStubsPH2Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex18_fu_5923_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_index_V_d0() {
    vmStubsPH2Z2_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_phi_V_address0() {
    vmStubsPH2Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex14_fu_5899_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_phi_V_d0() {
    vmStubsPH2Z2_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_pt_V_address0() {
    vmStubsPH2Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex16_fu_5915_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_pt_V_d0() {
    vmStubsPH2Z2_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_r_V_address0() {
    vmStubsPH2Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex15_fu_5907_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_r_V_d0() {
    vmStubsPH2Z2_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_z_V_address0() {
    vmStubsPH2Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex13_fu_5891_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_z_V_d0() {
    vmStubsPH2Z2_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_2)))) {
        vmStubsPH2Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_index_V_address0() {
    vmStubsPH2Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex18_fu_5923_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_index_V_d0() {
    vmStubsPH2Z2_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_phi_V_address0() {
    vmStubsPH2Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex14_fu_5899_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_phi_V_d0() {
    vmStubsPH2Z2_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_pt_V_address0() {
    vmStubsPH2Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex16_fu_5915_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_pt_V_d0() {
    vmStubsPH2Z2_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_r_V_address0() {
    vmStubsPH2Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex15_fu_5907_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_r_V_d0() {
    vmStubsPH2Z2_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_z_V_address0() {
    vmStubsPH2Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex13_fu_5891_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_z_V_d0() {
    vmStubsPH2Z2_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_index_V_address0() {
    vmStubsPH2Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex18_fu_5923_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_index_V_d0() {
    vmStubsPH2Z2_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo37_cast_cast_reg_6923.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_phi_V_address0() {
    vmStubsPH2Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex14_fu_5899_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_phi_V_d0() {
    vmStubsPH2Z2_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo34_cast_cast_reg_6896.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_pt_V_address0() {
    vmStubsPH2Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex16_fu_5915_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_pt_V_d0() {
    vmStubsPH2Z2_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo36_cast_cast_reg_6914.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_r_V_address0() {
    vmStubsPH2Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex15_fu_5907_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_r_V_d0() {
    vmStubsPH2Z2_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo35_cast_cast_reg_6905.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_z_V_address0() {
    vmStubsPH2Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex13_fu_5891_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH2Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_z_V_d0() {
    vmStubsPH2Z2_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH2Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_1) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo33_cast_cast_reg_6887.read(), ap_const_lv3_3)))) {
        vmStubsPH2Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_index_V_address0() {
    vmStubsPH3Z1_0_index_V_address0 =  (sc_lv<6>) (newIndex42_fu_5723_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_index_V_d0() {
    vmStubsPH3Z1_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_phi_V_address0() {
    vmStubsPH3Z1_0_phi_V_address0 =  (sc_lv<6>) (newIndex39_fu_5699_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_phi_V_d0() {
    vmStubsPH3Z1_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_pt_V_address0() {
    vmStubsPH3Z1_0_pt_V_address0 =  (sc_lv<6>) (newIndex41_fu_5715_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_pt_V_d0() {
    vmStubsPH3Z1_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_r_V_address0() {
    vmStubsPH3Z1_0_r_V_address0 =  (sc_lv<6>) (newIndex40_fu_5707_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_r_V_d0() {
    vmStubsPH3Z1_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_z_V_address0() {
    vmStubsPH3Z1_0_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_5691_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_z_V_d0() {
    vmStubsPH3Z1_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_index_V_address0() {
    vmStubsPH3Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex42_fu_5723_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_index_V_d0() {
    vmStubsPH3Z1_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_phi_V_address0() {
    vmStubsPH3Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex39_fu_5699_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_phi_V_d0() {
    vmStubsPH3Z1_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_pt_V_address0() {
    vmStubsPH3Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex41_fu_5715_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_pt_V_d0() {
    vmStubsPH3Z1_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_r_V_address0() {
    vmStubsPH3Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex40_fu_5707_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_r_V_d0() {
    vmStubsPH3Z1_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_z_V_address0() {
    vmStubsPH3Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_5691_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_z_V_d0() {
    vmStubsPH3Z1_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_index_V_address0() {
    vmStubsPH3Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex42_fu_5723_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_index_V_d0() {
    vmStubsPH3Z1_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_phi_V_address0() {
    vmStubsPH3Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex39_fu_5699_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_phi_V_d0() {
    vmStubsPH3Z1_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_pt_V_address0() {
    vmStubsPH3Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex41_fu_5715_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_pt_V_d0() {
    vmStubsPH3Z1_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_r_V_address0() {
    vmStubsPH3Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex40_fu_5707_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_r_V_d0() {
    vmStubsPH3Z1_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_z_V_address0() {
    vmStubsPH3Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_5691_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_z_V_d0() {
    vmStubsPH3Z1_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_index_V_address0() {
    vmStubsPH3Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex42_fu_5723_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_index_V_d0() {
    vmStubsPH3Z1_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_phi_V_address0() {
    vmStubsPH3Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex39_fu_5699_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_phi_V_d0() {
    vmStubsPH3Z1_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_pt_V_address0() {
    vmStubsPH3Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex41_fu_5715_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_pt_V_d0() {
    vmStubsPH3Z1_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_r_V_address0() {
    vmStubsPH3Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex40_fu_5707_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_r_V_d0() {
    vmStubsPH3Z1_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_z_V_address0() {
    vmStubsPH3Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_5691_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_z_V_d0() {
    vmStubsPH3Z1_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_index_V_address0() {
    vmStubsPH3Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex42_fu_5723_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_index_V_d0() {
    vmStubsPH3Z1_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo22_cast_cast_reg_6698.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_phi_V_address0() {
    vmStubsPH3Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex39_fu_5699_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_phi_V_d0() {
    vmStubsPH3Z1_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo19_cast_cast_reg_6671.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_pt_V_address0() {
    vmStubsPH3Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex41_fu_5715_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_pt_V_d0() {
    vmStubsPH3Z1_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo21_cast_cast_reg_6689.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_r_V_address0() {
    vmStubsPH3Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex40_fu_5707_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_r_V_d0() {
    vmStubsPH3Z1_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo20_cast_cast_reg_6680.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_z_V_address0() {
    vmStubsPH3Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_5691_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_z_V_d0() {
    vmStubsPH3Z1_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo18_cast_cast_reg_6662.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_index_V_address0() {
    vmStubsPH3Z2_0_index_V_address0 =  (sc_lv<6>) (newIndex28_fu_5883_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_index_V_d0() {
    vmStubsPH3Z2_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_phi_V_address0() {
    vmStubsPH3Z2_0_phi_V_address0 =  (sc_lv<6>) (newIndex22_fu_5859_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_phi_V_d0() {
    vmStubsPH3Z2_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_pt_V_address0() {
    vmStubsPH3Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex26_fu_5875_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_pt_V_d0() {
    vmStubsPH3Z2_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_r_V_address0() {
    vmStubsPH3Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex24_fu_5867_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_r_V_d0() {
    vmStubsPH3Z2_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_z_V_address0() {
    vmStubsPH3Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex20_fu_5851_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_z_V_d0() {
    vmStubsPH3Z2_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_0)))) {
        vmStubsPH3Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_index_V_address0() {
    vmStubsPH3Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex28_fu_5883_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_index_V_d0() {
    vmStubsPH3Z2_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_phi_V_address0() {
    vmStubsPH3Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex22_fu_5859_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_phi_V_d0() {
    vmStubsPH3Z2_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_pt_V_address0() {
    vmStubsPH3Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex26_fu_5875_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_pt_V_d0() {
    vmStubsPH3Z2_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_r_V_address0() {
    vmStubsPH3Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex24_fu_5867_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_r_V_d0() {
    vmStubsPH3Z2_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_z_V_address0() {
    vmStubsPH3Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex20_fu_5851_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_z_V_d0() {
    vmStubsPH3Z2_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_1)))) {
        vmStubsPH3Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_index_V_address0() {
    vmStubsPH3Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex28_fu_5883_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_index_V_d0() {
    vmStubsPH3Z2_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_phi_V_address0() {
    vmStubsPH3Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex22_fu_5859_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_phi_V_d0() {
    vmStubsPH3Z2_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_pt_V_address0() {
    vmStubsPH3Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex26_fu_5875_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_pt_V_d0() {
    vmStubsPH3Z2_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_r_V_address0() {
    vmStubsPH3Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex24_fu_5867_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_r_V_d0() {
    vmStubsPH3Z2_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_z_V_address0() {
    vmStubsPH3Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex20_fu_5851_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_z_V_d0() {
    vmStubsPH3Z2_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_2)))) {
        vmStubsPH3Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_index_V_address0() {
    vmStubsPH3Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex28_fu_5883_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_index_V_d0() {
    vmStubsPH3Z2_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_phi_V_address0() {
    vmStubsPH3Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex22_fu_5859_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_phi_V_d0() {
    vmStubsPH3Z2_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_pt_V_address0() {
    vmStubsPH3Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex26_fu_5875_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_pt_V_d0() {
    vmStubsPH3Z2_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_r_V_address0() {
    vmStubsPH3Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex24_fu_5867_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_r_V_d0() {
    vmStubsPH3Z2_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_z_V_address0() {
    vmStubsPH3Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex20_fu_5851_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_z_V_d0() {
    vmStubsPH3Z2_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_index_V_address0() {
    vmStubsPH3Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex28_fu_5883_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_index_V_d0() {
    vmStubsPH3Z2_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo42_cast_cast_reg_6878.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_phi_V_address0() {
    vmStubsPH3Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex22_fu_5859_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_phi_V_d0() {
    vmStubsPH3Z2_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo39_cast_cast_reg_6851.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_pt_V_address0() {
    vmStubsPH3Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex26_fu_5875_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_pt_V_d0() {
    vmStubsPH3Z2_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo41_cast_cast_reg_6869.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_r_V_address0() {
    vmStubsPH3Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex24_fu_5867_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_r_V_d0() {
    vmStubsPH3Z2_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo40_cast_cast_reg_6860.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_z_V_address0() {
    vmStubsPH3Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex20_fu_5851_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH3Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_z_V_d0() {
    vmStubsPH3Z2_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH3Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_2) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo38_cast_cast_reg_6842.read(), ap_const_lv3_3)))) {
        vmStubsPH3Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_index_V_address0() {
    vmStubsPH4Z1_0_index_V_address0 =  (sc_lv<6>) (newIndex47_fu_5683_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_index_V_d0() {
    vmStubsPH4Z1_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z1_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_phi_V_address0() {
    vmStubsPH4Z1_0_phi_V_address0 =  (sc_lv<6>) (newIndex44_fu_5659_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_phi_V_d0() {
    vmStubsPH4Z1_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z1_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_pt_V_address0() {
    vmStubsPH4Z1_0_pt_V_address0 =  (sc_lv<6>) (newIndex46_fu_5675_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_pt_V_d0() {
    vmStubsPH4Z1_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_r_V_address0() {
    vmStubsPH4Z1_0_r_V_address0 =  (sc_lv<6>) (newIndex45_fu_5667_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_r_V_d0() {
    vmStubsPH4Z1_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_z_V_address0() {
    vmStubsPH4Z1_0_z_V_address0 =  (sc_lv<6>) (newIndex43_fu_5651_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_z_V_d0() {
    vmStubsPH4Z1_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_index_V_address0() {
    vmStubsPH4Z1_1_index_V_address0 =  (sc_lv<6>) (newIndex47_fu_5683_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_index_V_d0() {
    vmStubsPH4Z1_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z1_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_phi_V_address0() {
    vmStubsPH4Z1_1_phi_V_address0 =  (sc_lv<6>) (newIndex44_fu_5659_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_phi_V_d0() {
    vmStubsPH4Z1_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z1_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_pt_V_address0() {
    vmStubsPH4Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex46_fu_5675_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_pt_V_d0() {
    vmStubsPH4Z1_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_r_V_address0() {
    vmStubsPH4Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex45_fu_5667_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_r_V_d0() {
    vmStubsPH4Z1_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_z_V_address0() {
    vmStubsPH4Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex43_fu_5651_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_z_V_d0() {
    vmStubsPH4Z1_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_index_V_address0() {
    vmStubsPH4Z1_2_index_V_address0 =  (sc_lv<6>) (newIndex47_fu_5683_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_index_V_ce0 = ap_const_logic_0;
    }
}

}

