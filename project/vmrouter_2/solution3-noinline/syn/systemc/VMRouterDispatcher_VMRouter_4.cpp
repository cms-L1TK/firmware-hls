#include "VMRouterDispatcher_VMRouter.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_index_V_d0() {
    vmStubsPH4Z1_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z1_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_phi_V_address0() {
    vmStubsPH4Z1_2_phi_V_address0 =  (sc_lv<6>) (newIndex44_fu_5659_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_phi_V_d0() {
    vmStubsPH4Z1_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z1_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_pt_V_address0() {
    vmStubsPH4Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex46_fu_5675_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_pt_V_d0() {
    vmStubsPH4Z1_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_r_V_address0() {
    vmStubsPH4Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex45_fu_5667_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_r_V_d0() {
    vmStubsPH4Z1_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_z_V_address0() {
    vmStubsPH4Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex43_fu_5651_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_z_V_d0() {
    vmStubsPH4Z1_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_index_V_address0() {
    vmStubsPH4Z1_3_index_V_address0 =  (sc_lv<6>) (newIndex47_fu_5683_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_index_V_d0() {
    vmStubsPH4Z1_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_phi_V_address0() {
    vmStubsPH4Z1_3_phi_V_address0 =  (sc_lv<6>) (newIndex44_fu_5659_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_phi_V_d0() {
    vmStubsPH4Z1_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_pt_V_address0() {
    vmStubsPH4Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex46_fu_5675_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_pt_V_d0() {
    vmStubsPH4Z1_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_r_V_address0() {
    vmStubsPH4Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex45_fu_5667_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_r_V_d0() {
    vmStubsPH4Z1_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_z_V_address0() {
    vmStubsPH4Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex43_fu_5651_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_z_V_d0() {
    vmStubsPH4Z1_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_index_V_address0() {
    vmStubsPH4Z1_4_index_V_address0 =  (sc_lv<6>) (newIndex47_fu_5683_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_index_V_d0() {
    vmStubsPH4Z1_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo27_cast_cast_reg_6653.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_phi_V_address0() {
    vmStubsPH4Z1_4_phi_V_address0 =  (sc_lv<6>) (newIndex44_fu_5659_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_phi_V_d0() {
    vmStubsPH4Z1_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo24_cast_cast_reg_6626.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_pt_V_address0() {
    vmStubsPH4Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex46_fu_5675_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_pt_V_d0() {
    vmStubsPH4Z1_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo26_cast_cast_reg_6644.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_r_V_address0() {
    vmStubsPH4Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex45_fu_5667_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_r_V_d0() {
    vmStubsPH4Z1_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo25_cast_cast_reg_6635.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_z_V_address0() {
    vmStubsPH4Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex43_fu_5651_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_z_V_d0() {
    vmStubsPH4Z1_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z1_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo23_cast_cast_reg_6617.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_index_V_address0() {
    vmStubsPH4Z2_0_index_V_address0 =  (sc_lv<6>) (newIndex38_fu_5843_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_0_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_index_V_d0() {
    vmStubsPH4Z2_0_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z2_0_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_phi_V_address0() {
    vmStubsPH4Z2_0_phi_V_address0 =  (sc_lv<6>) (newIndex32_fu_5819_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_0_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_phi_V_d0() {
    vmStubsPH4Z2_0_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z2_0_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_pt_V_address0() {
    vmStubsPH4Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex36_fu_5835_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_pt_V_d0() {
    vmStubsPH4Z2_0_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_r_V_address0() {
    vmStubsPH4Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex34_fu_5827_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_r_V_d0() {
    vmStubsPH4Z2_0_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_z_V_address0() {
    vmStubsPH4Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex30_fu_5811_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_z_V_d0() {
    vmStubsPH4Z2_0_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_0_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_0)))) {
        vmStubsPH4Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_index_V_address0() {
    vmStubsPH4Z2_1_index_V_address0 =  (sc_lv<6>) (newIndex38_fu_5843_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_1_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_index_V_d0() {
    vmStubsPH4Z2_1_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z2_1_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_phi_V_address0() {
    vmStubsPH4Z2_1_phi_V_address0 =  (sc_lv<6>) (newIndex32_fu_5819_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_1_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_phi_V_d0() {
    vmStubsPH4Z2_1_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z2_1_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_pt_V_address0() {
    vmStubsPH4Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex36_fu_5835_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_pt_V_d0() {
    vmStubsPH4Z2_1_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_r_V_address0() {
    vmStubsPH4Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex34_fu_5827_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_r_V_d0() {
    vmStubsPH4Z2_1_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_z_V_address0() {
    vmStubsPH4Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex30_fu_5811_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_z_V_d0() {
    vmStubsPH4Z2_1_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_1_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_1)))) {
        vmStubsPH4Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_index_V_address0() {
    vmStubsPH4Z2_2_index_V_address0 =  (sc_lv<6>) (newIndex38_fu_5843_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_2_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_index_V_d0() {
    vmStubsPH4Z2_2_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z2_2_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_phi_V_address0() {
    vmStubsPH4Z2_2_phi_V_address0 =  (sc_lv<6>) (newIndex32_fu_5819_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_2_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_phi_V_d0() {
    vmStubsPH4Z2_2_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z2_2_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_pt_V_address0() {
    vmStubsPH4Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex36_fu_5835_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_pt_V_d0() {
    vmStubsPH4Z2_2_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_r_V_address0() {
    vmStubsPH4Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex34_fu_5827_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_r_V_d0() {
    vmStubsPH4Z2_2_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_z_V_address0() {
    vmStubsPH4Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex30_fu_5811_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_z_V_d0() {
    vmStubsPH4Z2_2_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_2_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_2)))) {
        vmStubsPH4Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_index_V_address0() {
    vmStubsPH4Z2_3_index_V_address0 =  (sc_lv<6>) (newIndex38_fu_5843_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_3_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_index_V_d0() {
    vmStubsPH4Z2_3_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_3_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_phi_V_address0() {
    vmStubsPH4Z2_3_phi_V_address0 =  (sc_lv<6>) (newIndex32_fu_5819_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_3_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_phi_V_d0() {
    vmStubsPH4Z2_3_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_3_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_pt_V_address0() {
    vmStubsPH4Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex36_fu_5835_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_pt_V_d0() {
    vmStubsPH4Z2_3_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_r_V_address0() {
    vmStubsPH4Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex34_fu_5827_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_r_V_d0() {
    vmStubsPH4Z2_3_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_z_V_address0() {
    vmStubsPH4Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex30_fu_5811_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_z_V_d0() {
    vmStubsPH4Z2_3_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_3_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_index_V_address0() {
    vmStubsPH4Z2_4_index_V_address0 =  (sc_lv<6>) (newIndex38_fu_5843_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_index_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_4_index_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_index_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_index_V_d0() {
    vmStubsPH4Z2_4_index_V_d0 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_index_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo47_cast_cast_reg_6833.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_4_index_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_index_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_phi_V_address0() {
    vmStubsPH4Z2_4_phi_V_address0 =  (sc_lv<6>) (newIndex32_fu_5819_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_phi_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_4_phi_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_phi_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_phi_V_d0() {
    vmStubsPH4Z2_4_phi_V_d0 = curPhi_V_reg_6504.read().range(11, 9);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_phi_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo44_cast_cast_reg_6806.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_4_phi_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_phi_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_pt_V_address0() {
    vmStubsPH4Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex36_fu_5835_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_pt_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_pt_V_d0() {
    vmStubsPH4Z2_4_pt_V_d0 = redPt_V_reg_6524.read();
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_pt_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo46_cast_cast_reg_6824.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_r_V_address0() {
    vmStubsPH4Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex34_fu_5827_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_r_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_r_V_d0() {
    vmStubsPH4Z2_4_r_V_d0 = curR_V_reg_6514.read().range(6, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_r_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo45_cast_cast_reg_6815.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_z_V_address0() {
    vmStubsPH4Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex30_fu_5811_p1.read());
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_z_V_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read())) {
        vmStubsPH4Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_z_V_d0() {
    vmStubsPH4Z2_4_z_V_d0 = curZ_V_reg_6494.read().range(8, 5);
}

void VMRouterDispatcher_VMRouter::thread_vmStubsPH4Z2_4_z_V_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2.read()) && 
          esl_seteq<1,2,2>(routePhi_V_reg_6609.read(), ap_const_lv2_3) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_6613.read()) && 
          !esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_0) && 
          !esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(arrayNo43_cast_cast_reg_6797.read(), ap_const_lv3_3)))) {
        vmStubsPH4Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

}

