#include "VMRouter.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouter::thread_vmStubsPH3Z2_8_inde_d0() {
    vmStubsPH3Z2_8_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH3Z2_8_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_86_fu_15152_p4.read(), ap_const_lv5_8))) {
        vmStubsPH3Z2_8_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_phi_s_address0() {
    vmStubsPH3Z2_8_phi_s_address0 =  (sc_lv<6>) (newIndex39_fu_16608_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_8_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_8_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_phi_s_d0() {
    vmStubsPH3Z2_8_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH3Z2_8_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_83_reg_18347.read(), ap_const_lv5_8))) {
        vmStubsPH3Z2_8_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_pt_V_address0() {
    vmStubsPH3Z2_8_pt_V_address0 =  (sc_lv<6>) (newIndex43_fu_16662_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_8_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_8_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_pt_V_d0() {
    vmStubsPH3Z2_8_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH3Z2_8_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_85_reg_18355.read(), ap_const_lv5_8))) {
        vmStubsPH3Z2_8_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_r_V_address0() {
    vmStubsPH3Z2_8_r_V_address0 =  (sc_lv<6>) (newIndex41_fu_16635_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_8_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_8_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_r_V_d0() {
    vmStubsPH3Z2_8_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH3Z2_8_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_84_reg_18351.read(), ap_const_lv5_8))) {
        vmStubsPH3Z2_8_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_z_V_address0() {
    vmStubsPH3Z2_8_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_16581_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_8_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_8_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_8_z_V_d0() {
    vmStubsPH3Z2_8_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH3Z2_8_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_82_reg_18343.read(), ap_const_lv5_8))) {
        vmStubsPH3Z2_8_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_8_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_inde_address0() {
    vmStubsPH3Z2_9_inde_address0 =  (sc_lv<6>) (newIndex45_fu_15167_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_9_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH3Z2_9_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_inde_d0() {
    vmStubsPH3Z2_9_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH3Z2_9_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_86_fu_15152_p4.read(), ap_const_lv5_9))) {
        vmStubsPH3Z2_9_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_phi_s_address0() {
    vmStubsPH3Z2_9_phi_s_address0 =  (sc_lv<6>) (newIndex39_fu_16608_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_9_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_9_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_phi_s_d0() {
    vmStubsPH3Z2_9_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH3Z2_9_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_83_reg_18347.read(), ap_const_lv5_9))) {
        vmStubsPH3Z2_9_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_pt_V_address0() {
    vmStubsPH3Z2_9_pt_V_address0 =  (sc_lv<6>) (newIndex43_fu_16662_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_9_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_9_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_pt_V_d0() {
    vmStubsPH3Z2_9_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH3Z2_9_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_85_reg_18355.read(), ap_const_lv5_9))) {
        vmStubsPH3Z2_9_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_r_V_address0() {
    vmStubsPH3Z2_9_r_V_address0 =  (sc_lv<6>) (newIndex41_fu_16635_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_9_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_9_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_r_V_d0() {
    vmStubsPH3Z2_9_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH3Z2_9_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_84_reg_18351.read(), ap_const_lv5_9))) {
        vmStubsPH3Z2_9_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_z_V_address0() {
    vmStubsPH3Z2_9_z_V_address0 =  (sc_lv<6>) (newIndex37_fu_16581_p1.read());
}

void VMRouter::thread_vmStubsPH3Z2_9_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH3Z2_9_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH3Z2_9_z_V_d0() {
    vmStubsPH3Z2_9_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH3Z2_9_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_82_reg_18343.read(), ap_const_lv5_9))) {
        vmStubsPH3Z2_9_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH3Z2_9_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_inde_address0() {
    vmStubsPH4Z1_0_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_0_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_0_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_inde_d0() {
    vmStubsPH4Z1_0_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_0_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_0))) {
        vmStubsPH4Z1_0_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_phi_s_address0() {
    vmStubsPH4Z1_0_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_0_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_0_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_phi_s_d0() {
    vmStubsPH4Z1_0_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_0_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_0))) {
        vmStubsPH4Z1_0_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_pt_V_address0() {
    vmStubsPH4Z1_0_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_pt_V_d0() {
    vmStubsPH4Z1_0_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_0_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_0))) {
        vmStubsPH4Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_r_V_address0() {
    vmStubsPH4Z1_0_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_r_V_d0() {
    vmStubsPH4Z1_0_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_0_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_0))) {
        vmStubsPH4Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_z_V_address0() {
    vmStubsPH4Z1_0_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_0_z_V_d0() {
    vmStubsPH4Z1_0_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_0_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_0))) {
        vmStubsPH4Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_ind_address0() {
    vmStubsPH4Z1_10_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_10_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_10_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_ind_d0() {
    vmStubsPH4Z1_10_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_10_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_A))) {
        vmStubsPH4Z1_10_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_phi_address0() {
    vmStubsPH4Z1_10_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_10_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_10_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_phi_d0() {
    vmStubsPH4Z1_10_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_10_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_A))) {
        vmStubsPH4Z1_10_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_pt_s_address0() {
    vmStubsPH4Z1_10_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_10_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_10_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_pt_s_d0() {
    vmStubsPH4Z1_10_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_10_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_A))) {
        vmStubsPH4Z1_10_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_r_V_address0() {
    vmStubsPH4Z1_10_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_10_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_10_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_r_V_d0() {
    vmStubsPH4Z1_10_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_10_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_A))) {
        vmStubsPH4Z1_10_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_z_V_address0() {
    vmStubsPH4Z1_10_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_10_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_10_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_10_z_V_d0() {
    vmStubsPH4Z1_10_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_10_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_A))) {
        vmStubsPH4Z1_10_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_10_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_ind_address0() {
    vmStubsPH4Z1_11_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_11_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_11_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_ind_d0() {
    vmStubsPH4Z1_11_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_11_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_B))) {
        vmStubsPH4Z1_11_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_phi_address0() {
    vmStubsPH4Z1_11_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_11_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_11_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_phi_d0() {
    vmStubsPH4Z1_11_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_11_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_B))) {
        vmStubsPH4Z1_11_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_pt_s_address0() {
    vmStubsPH4Z1_11_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_11_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_11_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_pt_s_d0() {
    vmStubsPH4Z1_11_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_11_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_B))) {
        vmStubsPH4Z1_11_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_r_V_address0() {
    vmStubsPH4Z1_11_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_11_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_11_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_r_V_d0() {
    vmStubsPH4Z1_11_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_11_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_B))) {
        vmStubsPH4Z1_11_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_z_V_address0() {
    vmStubsPH4Z1_11_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_11_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_11_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_11_z_V_d0() {
    vmStubsPH4Z1_11_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_11_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_B))) {
        vmStubsPH4Z1_11_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_11_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_ind_address0() {
    vmStubsPH4Z1_12_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_12_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_12_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_ind_d0() {
    vmStubsPH4Z1_12_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_12_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_C))) {
        vmStubsPH4Z1_12_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_phi_address0() {
    vmStubsPH4Z1_12_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_12_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_12_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_phi_d0() {
    vmStubsPH4Z1_12_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_12_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_C))) {
        vmStubsPH4Z1_12_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_pt_s_address0() {
    vmStubsPH4Z1_12_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_12_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_12_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_pt_s_d0() {
    vmStubsPH4Z1_12_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_12_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_C))) {
        vmStubsPH4Z1_12_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_r_V_address0() {
    vmStubsPH4Z1_12_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_12_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_12_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_r_V_d0() {
    vmStubsPH4Z1_12_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_12_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_C))) {
        vmStubsPH4Z1_12_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_z_V_address0() {
    vmStubsPH4Z1_12_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_12_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_12_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_12_z_V_d0() {
    vmStubsPH4Z1_12_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_12_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_C))) {
        vmStubsPH4Z1_12_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_12_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_ind_address0() {
    vmStubsPH4Z1_13_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_13_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_13_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_ind_d0() {
    vmStubsPH4Z1_13_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_13_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_D))) {
        vmStubsPH4Z1_13_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_phi_address0() {
    vmStubsPH4Z1_13_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_13_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_13_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_phi_d0() {
    vmStubsPH4Z1_13_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_13_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_D))) {
        vmStubsPH4Z1_13_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_pt_s_address0() {
    vmStubsPH4Z1_13_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_13_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_13_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_pt_s_d0() {
    vmStubsPH4Z1_13_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_13_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_D))) {
        vmStubsPH4Z1_13_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_r_V_address0() {
    vmStubsPH4Z1_13_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_13_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_13_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_r_V_d0() {
    vmStubsPH4Z1_13_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_13_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_D))) {
        vmStubsPH4Z1_13_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_z_V_address0() {
    vmStubsPH4Z1_13_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_13_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_13_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_13_z_V_d0() {
    vmStubsPH4Z1_13_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_13_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_D))) {
        vmStubsPH4Z1_13_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_13_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_ind_address0() {
    vmStubsPH4Z1_14_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_14_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_14_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_ind_d0() {
    vmStubsPH4Z1_14_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_14_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_E))) {
        vmStubsPH4Z1_14_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_phi_address0() {
    vmStubsPH4Z1_14_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_14_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_14_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_phi_d0() {
    vmStubsPH4Z1_14_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_14_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_E))) {
        vmStubsPH4Z1_14_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_pt_s_address0() {
    vmStubsPH4Z1_14_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_14_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_14_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_pt_s_d0() {
    vmStubsPH4Z1_14_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_14_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_E))) {
        vmStubsPH4Z1_14_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_r_V_address0() {
    vmStubsPH4Z1_14_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_14_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_14_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_r_V_d0() {
    vmStubsPH4Z1_14_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_14_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_E))) {
        vmStubsPH4Z1_14_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_z_V_address0() {
    vmStubsPH4Z1_14_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_14_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_14_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_14_z_V_d0() {
    vmStubsPH4Z1_14_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_14_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_E))) {
        vmStubsPH4Z1_14_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_14_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_ind_address0() {
    vmStubsPH4Z1_15_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_15_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_15_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_ind_d0() {
    vmStubsPH4Z1_15_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_15_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_F))) {
        vmStubsPH4Z1_15_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_phi_address0() {
    vmStubsPH4Z1_15_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_15_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_15_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_phi_d0() {
    vmStubsPH4Z1_15_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_15_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_F))) {
        vmStubsPH4Z1_15_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_pt_s_address0() {
    vmStubsPH4Z1_15_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_15_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_15_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_pt_s_d0() {
    vmStubsPH4Z1_15_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_15_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_F))) {
        vmStubsPH4Z1_15_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_r_V_address0() {
    vmStubsPH4Z1_15_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_15_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_15_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_r_V_d0() {
    vmStubsPH4Z1_15_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_15_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_F))) {
        vmStubsPH4Z1_15_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_z_V_address0() {
    vmStubsPH4Z1_15_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_15_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_15_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_15_z_V_d0() {
    vmStubsPH4Z1_15_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_15_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_F))) {
        vmStubsPH4Z1_15_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_15_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_ind_address0() {
    vmStubsPH4Z1_16_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_16_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_16_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_ind_d0() {
    vmStubsPH4Z1_16_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_16_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_10))) {
        vmStubsPH4Z1_16_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_phi_address0() {
    vmStubsPH4Z1_16_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_16_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_16_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_phi_d0() {
    vmStubsPH4Z1_16_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_16_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_10))) {
        vmStubsPH4Z1_16_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_pt_s_address0() {
    vmStubsPH4Z1_16_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_16_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_16_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_pt_s_d0() {
    vmStubsPH4Z1_16_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_16_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_10))) {
        vmStubsPH4Z1_16_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_r_V_address0() {
    vmStubsPH4Z1_16_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_16_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_16_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_r_V_d0() {
    vmStubsPH4Z1_16_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_16_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_10))) {
        vmStubsPH4Z1_16_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_z_V_address0() {
    vmStubsPH4Z1_16_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_16_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_16_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_16_z_V_d0() {
    vmStubsPH4Z1_16_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_16_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_10))) {
        vmStubsPH4Z1_16_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_16_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_ind_address0() {
    vmStubsPH4Z1_17_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_17_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_17_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_ind_d0() {
    vmStubsPH4Z1_17_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_17_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_17_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_phi_address0() {
    vmStubsPH4Z1_17_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_17_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_17_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_phi_d0() {
    vmStubsPH4Z1_17_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_17_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_17_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_pt_s_address0() {
    vmStubsPH4Z1_17_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_17_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_17_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_pt_s_d0() {
    vmStubsPH4Z1_17_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_17_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_17_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_r_V_address0() {
    vmStubsPH4Z1_17_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_17_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_17_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_r_V_d0() {
    vmStubsPH4Z1_17_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_17_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_17_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_z_V_address0() {
    vmStubsPH4Z1_17_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_17_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_17_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_17_z_V_d0() {
    vmStubsPH4Z1_17_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_17_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_17_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_17_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_ind_address0() {
    vmStubsPH4Z1_18_ind_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_18_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_18_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_ind_d0() {
    vmStubsPH4Z1_18_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_18_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_18_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_phi_address0() {
    vmStubsPH4Z1_18_phi_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_18_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_18_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_phi_d0() {
    vmStubsPH4Z1_18_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_18_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_18_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_pt_s_address0() {
    vmStubsPH4Z1_18_pt_s_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_18_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_18_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_pt_s_d0() {
    vmStubsPH4Z1_18_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_18_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_18_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_r_V_address0() {
    vmStubsPH4Z1_18_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_18_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_18_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_r_V_d0() {
    vmStubsPH4Z1_18_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_18_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_18_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_z_V_address0() {
    vmStubsPH4Z1_18_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_18_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_18_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_18_z_V_d0() {
    vmStubsPH4Z1_18_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_18_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_11))) {
        vmStubsPH4Z1_18_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_18_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_inde_address0() {
    vmStubsPH4Z1_1_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_1_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_1_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_inde_d0() {
    vmStubsPH4Z1_1_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_1_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_1))) {
        vmStubsPH4Z1_1_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_phi_s_address0() {
    vmStubsPH4Z1_1_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_1_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_1_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_phi_s_d0() {
    vmStubsPH4Z1_1_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_1_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_1))) {
        vmStubsPH4Z1_1_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_pt_V_address0() {
    vmStubsPH4Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_1_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_pt_V_d0() {
    vmStubsPH4Z1_1_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_1_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_1))) {
        vmStubsPH4Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_r_V_address0() {
    vmStubsPH4Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_1_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_r_V_d0() {
    vmStubsPH4Z1_1_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_1_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_1))) {
        vmStubsPH4Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_z_V_address0() {
    vmStubsPH4Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_1_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_1_z_V_d0() {
    vmStubsPH4Z1_1_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_1_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_1))) {
        vmStubsPH4Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_inde_address0() {
    vmStubsPH4Z1_2_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_2_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_2_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_inde_d0() {
    vmStubsPH4Z1_2_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_2_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_2))) {
        vmStubsPH4Z1_2_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_phi_s_address0() {
    vmStubsPH4Z1_2_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_2_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_2_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_phi_s_d0() {
    vmStubsPH4Z1_2_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_2_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_2))) {
        vmStubsPH4Z1_2_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_pt_V_address0() {
    vmStubsPH4Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_2_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_pt_V_d0() {
    vmStubsPH4Z1_2_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_2_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_2))) {
        vmStubsPH4Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_r_V_address0() {
    vmStubsPH4Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_2_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_r_V_d0() {
    vmStubsPH4Z1_2_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_2_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_2))) {
        vmStubsPH4Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_z_V_address0() {
    vmStubsPH4Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_2_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_2_z_V_d0() {
    vmStubsPH4Z1_2_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_2_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_2))) {
        vmStubsPH4Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_inde_address0() {
    vmStubsPH4Z1_3_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_3_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_3_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_inde_d0() {
    vmStubsPH4Z1_3_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_3_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_3))) {
        vmStubsPH4Z1_3_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_phi_s_address0() {
    vmStubsPH4Z1_3_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_3_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_3_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_phi_s_d0() {
    vmStubsPH4Z1_3_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_3_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_3))) {
        vmStubsPH4Z1_3_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_pt_V_address0() {
    vmStubsPH4Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_pt_V_d0() {
    vmStubsPH4Z1_3_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_3_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_3))) {
        vmStubsPH4Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_r_V_address0() {
    vmStubsPH4Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_r_V_d0() {
    vmStubsPH4Z1_3_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_3_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_3))) {
        vmStubsPH4Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_z_V_address0() {
    vmStubsPH4Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_3_z_V_d0() {
    vmStubsPH4Z1_3_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_3_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_3))) {
        vmStubsPH4Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_inde_address0() {
    vmStubsPH4Z1_4_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_4_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_4_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_inde_d0() {
    vmStubsPH4Z1_4_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_4_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_4))) {
        vmStubsPH4Z1_4_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_phi_s_address0() {
    vmStubsPH4Z1_4_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_4_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_4_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_phi_s_d0() {
    vmStubsPH4Z1_4_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_4_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_4))) {
        vmStubsPH4Z1_4_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_pt_V_address0() {
    vmStubsPH4Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_pt_V_d0() {
    vmStubsPH4Z1_4_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_4_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_4))) {
        vmStubsPH4Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_r_V_address0() {
    vmStubsPH4Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_r_V_d0() {
    vmStubsPH4Z1_4_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_4_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_4))) {
        vmStubsPH4Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_z_V_address0() {
    vmStubsPH4Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_4_z_V_d0() {
    vmStubsPH4Z1_4_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_4_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_4))) {
        vmStubsPH4Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_inde_address0() {
    vmStubsPH4Z1_5_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_5_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_5_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_inde_d0() {
    vmStubsPH4Z1_5_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_5_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_5))) {
        vmStubsPH4Z1_5_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_phi_s_address0() {
    vmStubsPH4Z1_5_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_5_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_5_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_phi_s_d0() {
    vmStubsPH4Z1_5_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_5_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_5))) {
        vmStubsPH4Z1_5_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_pt_V_address0() {
    vmStubsPH4Z1_5_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_5_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_5_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_pt_V_d0() {
    vmStubsPH4Z1_5_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_5_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_5))) {
        vmStubsPH4Z1_5_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_r_V_address0() {
    vmStubsPH4Z1_5_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_5_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_5_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_r_V_d0() {
    vmStubsPH4Z1_5_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_5_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_5))) {
        vmStubsPH4Z1_5_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_z_V_address0() {
    vmStubsPH4Z1_5_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_5_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_5_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_5_z_V_d0() {
    vmStubsPH4Z1_5_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_5_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_5))) {
        vmStubsPH4Z1_5_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_5_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_inde_address0() {
    vmStubsPH4Z1_6_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_6_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_6_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_inde_d0() {
    vmStubsPH4Z1_6_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_6_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_6))) {
        vmStubsPH4Z1_6_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_phi_s_address0() {
    vmStubsPH4Z1_6_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_6_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_6_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_phi_s_d0() {
    vmStubsPH4Z1_6_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_6_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_6))) {
        vmStubsPH4Z1_6_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_pt_V_address0() {
    vmStubsPH4Z1_6_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_6_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_6_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_pt_V_d0() {
    vmStubsPH4Z1_6_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_6_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_6))) {
        vmStubsPH4Z1_6_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_r_V_address0() {
    vmStubsPH4Z1_6_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_6_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_6_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_r_V_d0() {
    vmStubsPH4Z1_6_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_6_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_6))) {
        vmStubsPH4Z1_6_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_z_V_address0() {
    vmStubsPH4Z1_6_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_6_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_6_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_6_z_V_d0() {
    vmStubsPH4Z1_6_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_6_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_6))) {
        vmStubsPH4Z1_6_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_6_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_inde_address0() {
    vmStubsPH4Z1_7_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_7_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_7_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_inde_d0() {
    vmStubsPH4Z1_7_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_7_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_7))) {
        vmStubsPH4Z1_7_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_phi_s_address0() {
    vmStubsPH4Z1_7_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_7_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_7_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_phi_s_d0() {
    vmStubsPH4Z1_7_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_7_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_7))) {
        vmStubsPH4Z1_7_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_pt_V_address0() {
    vmStubsPH4Z1_7_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_7_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_7_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_pt_V_d0() {
    vmStubsPH4Z1_7_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_7_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_7))) {
        vmStubsPH4Z1_7_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_r_V_address0() {
    vmStubsPH4Z1_7_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_7_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_7_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_r_V_d0() {
    vmStubsPH4Z1_7_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_7_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_7))) {
        vmStubsPH4Z1_7_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_z_V_address0() {
    vmStubsPH4Z1_7_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_7_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_7_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_7_z_V_d0() {
    vmStubsPH4Z1_7_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_7_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_7))) {
        vmStubsPH4Z1_7_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_7_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_inde_address0() {
    vmStubsPH4Z1_8_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_8_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_8_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_inde_d0() {
    vmStubsPH4Z1_8_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_8_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_8))) {
        vmStubsPH4Z1_8_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_phi_s_address0() {
    vmStubsPH4Z1_8_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_8_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_8_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_phi_s_d0() {
    vmStubsPH4Z1_8_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_8_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_8))) {
        vmStubsPH4Z1_8_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_pt_V_address0() {
    vmStubsPH4Z1_8_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_8_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_8_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_pt_V_d0() {
    vmStubsPH4Z1_8_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_8_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_8))) {
        vmStubsPH4Z1_8_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_r_V_address0() {
    vmStubsPH4Z1_8_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_8_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_8_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_r_V_d0() {
    vmStubsPH4Z1_8_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_8_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_8))) {
        vmStubsPH4Z1_8_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_z_V_address0() {
    vmStubsPH4Z1_8_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_8_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_8_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_8_z_V_d0() {
    vmStubsPH4Z1_8_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_8_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_8))) {
        vmStubsPH4Z1_8_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_8_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_inde_address0() {
    vmStubsPH4Z1_9_inde_address0 =  (sc_lv<6>) (newIndex95_fu_14562_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_9_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z1_9_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_inde_d0() {
    vmStubsPH4Z1_9_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z1_9_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_149_fu_14547_p4.read(), ap_const_lv5_9))) {
        vmStubsPH4Z1_9_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_phi_s_address0() {
    vmStubsPH4Z1_9_phi_s_address0 =  (sc_lv<6>) (newIndex89_fu_16068_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_9_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_9_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_phi_s_d0() {
    vmStubsPH4Z1_9_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z1_9_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_108_reg_18207.read(), ap_const_lv5_9))) {
        vmStubsPH4Z1_9_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_pt_V_address0() {
    vmStubsPH4Z1_9_pt_V_address0 =  (sc_lv<6>) (newIndex93_fu_16122_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_9_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_9_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_pt_V_d0() {
    vmStubsPH4Z1_9_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z1_9_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_148_reg_18215.read(), ap_const_lv5_9))) {
        vmStubsPH4Z1_9_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_r_V_address0() {
    vmStubsPH4Z1_9_r_V_address0 =  (sc_lv<6>) (newIndex91_fu_16095_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_9_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_9_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_r_V_d0() {
    vmStubsPH4Z1_9_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z1_9_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_109_reg_18211.read(), ap_const_lv5_9))) {
        vmStubsPH4Z1_9_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_z_V_address0() {
    vmStubsPH4Z1_9_z_V_address0 =  (sc_lv<6>) (newIndex87_fu_16041_p1.read());
}

void VMRouter::thread_vmStubsPH4Z1_9_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z1_9_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z1_9_z_V_d0() {
    vmStubsPH4Z1_9_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z1_9_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,5,5>(tmp_107_reg_18203.read(), ap_const_lv5_9))) {
        vmStubsPH4Z1_9_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z1_9_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_inde_address0() {
    vmStubsPH4Z2_0_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_0_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_0_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_inde_d0() {
    vmStubsPH4Z2_0_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_0_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_0))) {
        vmStubsPH4Z2_0_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_phi_s_address0() {
    vmStubsPH4Z2_0_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_0_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_0_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_phi_s_d0() {
    vmStubsPH4Z2_0_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_0_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_0))) {
        vmStubsPH4Z2_0_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_pt_V_address0() {
    vmStubsPH4Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_pt_V_d0() {
    vmStubsPH4Z2_0_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_0_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_0))) {
        vmStubsPH4Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_r_V_address0() {
    vmStubsPH4Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_r_V_d0() {
    vmStubsPH4Z2_0_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_0_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_0))) {
        vmStubsPH4Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_z_V_address0() {
    vmStubsPH4Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_0_z_V_d0() {
    vmStubsPH4Z2_0_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_0_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_0))) {
        vmStubsPH4Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_ind_address0() {
    vmStubsPH4Z2_10_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_10_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_10_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_ind_d0() {
    vmStubsPH4Z2_10_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_10_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_A))) {
        vmStubsPH4Z2_10_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_phi_address0() {
    vmStubsPH4Z2_10_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_10_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_10_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_phi_d0() {
    vmStubsPH4Z2_10_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_10_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_A))) {
        vmStubsPH4Z2_10_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_pt_s_address0() {
    vmStubsPH4Z2_10_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_10_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_10_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_pt_s_d0() {
    vmStubsPH4Z2_10_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_10_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_A))) {
        vmStubsPH4Z2_10_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_r_V_address0() {
    vmStubsPH4Z2_10_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_10_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_10_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_r_V_d0() {
    vmStubsPH4Z2_10_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_10_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_A))) {
        vmStubsPH4Z2_10_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_z_V_address0() {
    vmStubsPH4Z2_10_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_10_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_10_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_10_z_V_d0() {
    vmStubsPH4Z2_10_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_10_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_A))) {
        vmStubsPH4Z2_10_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_10_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_ind_address0() {
    vmStubsPH4Z2_11_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_11_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_11_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_ind_d0() {
    vmStubsPH4Z2_11_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_11_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_B))) {
        vmStubsPH4Z2_11_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_phi_address0() {
    vmStubsPH4Z2_11_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_11_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_11_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_phi_d0() {
    vmStubsPH4Z2_11_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_11_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_B))) {
        vmStubsPH4Z2_11_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_pt_s_address0() {
    vmStubsPH4Z2_11_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_11_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_11_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_pt_s_d0() {
    vmStubsPH4Z2_11_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_11_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_B))) {
        vmStubsPH4Z2_11_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_r_V_address0() {
    vmStubsPH4Z2_11_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_11_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_11_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_r_V_d0() {
    vmStubsPH4Z2_11_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_11_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_B))) {
        vmStubsPH4Z2_11_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_z_V_address0() {
    vmStubsPH4Z2_11_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_11_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_11_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_11_z_V_d0() {
    vmStubsPH4Z2_11_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_11_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_B))) {
        vmStubsPH4Z2_11_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_11_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_ind_address0() {
    vmStubsPH4Z2_12_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_12_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_12_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_ind_d0() {
    vmStubsPH4Z2_12_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_12_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_C))) {
        vmStubsPH4Z2_12_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_phi_address0() {
    vmStubsPH4Z2_12_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_12_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_12_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_phi_d0() {
    vmStubsPH4Z2_12_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_12_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_C))) {
        vmStubsPH4Z2_12_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_pt_s_address0() {
    vmStubsPH4Z2_12_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_12_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_12_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_pt_s_d0() {
    vmStubsPH4Z2_12_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_12_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_C))) {
        vmStubsPH4Z2_12_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_r_V_address0() {
    vmStubsPH4Z2_12_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_12_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_12_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_r_V_d0() {
    vmStubsPH4Z2_12_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_12_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_C))) {
        vmStubsPH4Z2_12_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_z_V_address0() {
    vmStubsPH4Z2_12_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_12_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_12_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_12_z_V_d0() {
    vmStubsPH4Z2_12_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_12_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_C))) {
        vmStubsPH4Z2_12_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_12_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_ind_address0() {
    vmStubsPH4Z2_13_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_13_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_13_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_ind_d0() {
    vmStubsPH4Z2_13_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_13_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_D))) {
        vmStubsPH4Z2_13_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_phi_address0() {
    vmStubsPH4Z2_13_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_13_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_13_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_phi_d0() {
    vmStubsPH4Z2_13_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_13_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_D))) {
        vmStubsPH4Z2_13_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_pt_s_address0() {
    vmStubsPH4Z2_13_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_13_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_13_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_pt_s_d0() {
    vmStubsPH4Z2_13_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_13_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_D))) {
        vmStubsPH4Z2_13_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_r_V_address0() {
    vmStubsPH4Z2_13_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_13_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_13_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_r_V_d0() {
    vmStubsPH4Z2_13_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_13_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_D))) {
        vmStubsPH4Z2_13_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_z_V_address0() {
    vmStubsPH4Z2_13_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_13_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_13_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_13_z_V_d0() {
    vmStubsPH4Z2_13_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_13_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_D))) {
        vmStubsPH4Z2_13_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_13_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_ind_address0() {
    vmStubsPH4Z2_14_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_14_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_14_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_ind_d0() {
    vmStubsPH4Z2_14_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_14_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_E))) {
        vmStubsPH4Z2_14_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_phi_address0() {
    vmStubsPH4Z2_14_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_14_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_14_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_phi_d0() {
    vmStubsPH4Z2_14_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_14_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_E))) {
        vmStubsPH4Z2_14_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_pt_s_address0() {
    vmStubsPH4Z2_14_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_14_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_14_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_pt_s_d0() {
    vmStubsPH4Z2_14_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_14_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_E))) {
        vmStubsPH4Z2_14_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_r_V_address0() {
    vmStubsPH4Z2_14_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_14_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_14_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_r_V_d0() {
    vmStubsPH4Z2_14_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_14_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_E))) {
        vmStubsPH4Z2_14_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_z_V_address0() {
    vmStubsPH4Z2_14_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_14_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_14_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_14_z_V_d0() {
    vmStubsPH4Z2_14_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_14_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_E))) {
        vmStubsPH4Z2_14_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_14_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_ind_address0() {
    vmStubsPH4Z2_15_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_15_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_15_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_ind_d0() {
    vmStubsPH4Z2_15_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_15_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_F))) {
        vmStubsPH4Z2_15_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_phi_address0() {
    vmStubsPH4Z2_15_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_15_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_15_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_phi_d0() {
    vmStubsPH4Z2_15_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_15_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_F))) {
        vmStubsPH4Z2_15_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_pt_s_address0() {
    vmStubsPH4Z2_15_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_15_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_15_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_pt_s_d0() {
    vmStubsPH4Z2_15_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_15_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_F))) {
        vmStubsPH4Z2_15_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_r_V_address0() {
    vmStubsPH4Z2_15_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_15_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_15_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_r_V_d0() {
    vmStubsPH4Z2_15_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_15_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_F))) {
        vmStubsPH4Z2_15_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_z_V_address0() {
    vmStubsPH4Z2_15_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_15_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_15_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_15_z_V_d0() {
    vmStubsPH4Z2_15_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_15_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_F))) {
        vmStubsPH4Z2_15_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_15_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_ind_address0() {
    vmStubsPH4Z2_16_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_16_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_16_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_ind_d0() {
    vmStubsPH4Z2_16_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_16_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_10))) {
        vmStubsPH4Z2_16_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_phi_address0() {
    vmStubsPH4Z2_16_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_16_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_16_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_phi_d0() {
    vmStubsPH4Z2_16_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_16_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_10))) {
        vmStubsPH4Z2_16_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_pt_s_address0() {
    vmStubsPH4Z2_16_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_16_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_16_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_pt_s_d0() {
    vmStubsPH4Z2_16_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_16_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_10))) {
        vmStubsPH4Z2_16_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_r_V_address0() {
    vmStubsPH4Z2_16_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_16_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_16_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_r_V_d0() {
    vmStubsPH4Z2_16_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_16_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_10))) {
        vmStubsPH4Z2_16_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_z_V_address0() {
    vmStubsPH4Z2_16_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_16_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_16_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_16_z_V_d0() {
    vmStubsPH4Z2_16_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_16_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_10))) {
        vmStubsPH4Z2_16_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_16_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_ind_address0() {
    vmStubsPH4Z2_17_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_17_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_17_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_ind_d0() {
    vmStubsPH4Z2_17_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_17_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_17_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_phi_address0() {
    vmStubsPH4Z2_17_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_17_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_17_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_phi_d0() {
    vmStubsPH4Z2_17_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_17_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_17_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_pt_s_address0() {
    vmStubsPH4Z2_17_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_17_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_17_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_pt_s_d0() {
    vmStubsPH4Z2_17_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_17_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_17_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_r_V_address0() {
    vmStubsPH4Z2_17_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_17_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_17_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_r_V_d0() {
    vmStubsPH4Z2_17_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_17_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_17_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_z_V_address0() {
    vmStubsPH4Z2_17_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_17_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_17_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_17_z_V_d0() {
    vmStubsPH4Z2_17_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_17_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_17_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_17_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_ind_address0() {
    vmStubsPH4Z2_18_ind_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_18_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_18_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_ind_d0() {
    vmStubsPH4Z2_18_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_18_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_18_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_phi_address0() {
    vmStubsPH4Z2_18_phi_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_18_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_18_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_phi_d0() {
    vmStubsPH4Z2_18_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_18_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_18_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_pt_s_address0() {
    vmStubsPH4Z2_18_pt_s_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_18_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_18_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_pt_s_d0() {
    vmStubsPH4Z2_18_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_18_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_18_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_r_V_address0() {
    vmStubsPH4Z2_18_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_18_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_18_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_r_V_d0() {
    vmStubsPH4Z2_18_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_18_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_18_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_z_V_address0() {
    vmStubsPH4Z2_18_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_18_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_18_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_18_z_V_d0() {
    vmStubsPH4Z2_18_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_18_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_11))) {
        vmStubsPH4Z2_18_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_18_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_inde_address0() {
    vmStubsPH4Z2_1_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_1_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_1_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_inde_d0() {
    vmStubsPH4Z2_1_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_1_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_1))) {
        vmStubsPH4Z2_1_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_phi_s_address0() {
    vmStubsPH4Z2_1_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_1_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_1_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_phi_s_d0() {
    vmStubsPH4Z2_1_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_1_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_1))) {
        vmStubsPH4Z2_1_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_pt_V_address0() {
    vmStubsPH4Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_1_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_pt_V_d0() {
    vmStubsPH4Z2_1_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_1_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_1))) {
        vmStubsPH4Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_r_V_address0() {
    vmStubsPH4Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_1_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_r_V_d0() {
    vmStubsPH4Z2_1_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_1_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_1))) {
        vmStubsPH4Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_z_V_address0() {
    vmStubsPH4Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_1_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_1_z_V_d0() {
    vmStubsPH4Z2_1_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_1_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_1))) {
        vmStubsPH4Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_inde_address0() {
    vmStubsPH4Z2_2_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_2_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_2_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_inde_d0() {
    vmStubsPH4Z2_2_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_2_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_2))) {
        vmStubsPH4Z2_2_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_phi_s_address0() {
    vmStubsPH4Z2_2_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_2_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_2_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_phi_s_d0() {
    vmStubsPH4Z2_2_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_2_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_2))) {
        vmStubsPH4Z2_2_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_pt_V_address0() {
    vmStubsPH4Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_2_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_pt_V_d0() {
    vmStubsPH4Z2_2_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_2_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_2))) {
        vmStubsPH4Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_r_V_address0() {
    vmStubsPH4Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_2_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_r_V_d0() {
    vmStubsPH4Z2_2_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_2_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_2))) {
        vmStubsPH4Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_z_V_address0() {
    vmStubsPH4Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_2_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_2_z_V_d0() {
    vmStubsPH4Z2_2_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_2_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_2))) {
        vmStubsPH4Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_inde_address0() {
    vmStubsPH4Z2_3_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_3_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_3_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_inde_d0() {
    vmStubsPH4Z2_3_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_3_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_3))) {
        vmStubsPH4Z2_3_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_phi_s_address0() {
    vmStubsPH4Z2_3_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_3_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_3_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_phi_s_d0() {
    vmStubsPH4Z2_3_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_3_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_3))) {
        vmStubsPH4Z2_3_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_pt_V_address0() {
    vmStubsPH4Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_pt_V_d0() {
    vmStubsPH4Z2_3_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_3_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_3))) {
        vmStubsPH4Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_r_V_address0() {
    vmStubsPH4Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_r_V_d0() {
    vmStubsPH4Z2_3_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_3_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_3))) {
        vmStubsPH4Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_z_V_address0() {
    vmStubsPH4Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_3_z_V_d0() {
    vmStubsPH4Z2_3_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_3_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_3))) {
        vmStubsPH4Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_inde_address0() {
    vmStubsPH4Z2_4_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_4_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_4_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_inde_d0() {
    vmStubsPH4Z2_4_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_4_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_4))) {
        vmStubsPH4Z2_4_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_phi_s_address0() {
    vmStubsPH4Z2_4_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_4_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_4_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_phi_s_d0() {
    vmStubsPH4Z2_4_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_4_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_4))) {
        vmStubsPH4Z2_4_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_pt_V_address0() {
    vmStubsPH4Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_pt_V_d0() {
    vmStubsPH4Z2_4_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_4_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_4))) {
        vmStubsPH4Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_r_V_address0() {
    vmStubsPH4Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_r_V_d0() {
    vmStubsPH4Z2_4_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_4_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_4))) {
        vmStubsPH4Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_z_V_address0() {
    vmStubsPH4Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_4_z_V_d0() {
    vmStubsPH4Z2_4_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_4_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_4))) {
        vmStubsPH4Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_inde_address0() {
    vmStubsPH4Z2_5_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_5_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_5_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_inde_d0() {
    vmStubsPH4Z2_5_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_5_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_5))) {
        vmStubsPH4Z2_5_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_phi_s_address0() {
    vmStubsPH4Z2_5_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_5_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_5_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_phi_s_d0() {
    vmStubsPH4Z2_5_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_5_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_5))) {
        vmStubsPH4Z2_5_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_pt_V_address0() {
    vmStubsPH4Z2_5_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_5_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_5_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_pt_V_d0() {
    vmStubsPH4Z2_5_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_5_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_5))) {
        vmStubsPH4Z2_5_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_r_V_address0() {
    vmStubsPH4Z2_5_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_5_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_5_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_r_V_d0() {
    vmStubsPH4Z2_5_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_5_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_5))) {
        vmStubsPH4Z2_5_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_z_V_address0() {
    vmStubsPH4Z2_5_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_5_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_5_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_5_z_V_d0() {
    vmStubsPH4Z2_5_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_5_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_5))) {
        vmStubsPH4Z2_5_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_5_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_inde_address0() {
    vmStubsPH4Z2_6_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_6_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_6_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_inde_d0() {
    vmStubsPH4Z2_6_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_6_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_6))) {
        vmStubsPH4Z2_6_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_phi_s_address0() {
    vmStubsPH4Z2_6_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_6_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_6_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_phi_s_d0() {
    vmStubsPH4Z2_6_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_6_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_6))) {
        vmStubsPH4Z2_6_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_pt_V_address0() {
    vmStubsPH4Z2_6_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_6_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_6_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_pt_V_d0() {
    vmStubsPH4Z2_6_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_6_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_6))) {
        vmStubsPH4Z2_6_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_r_V_address0() {
    vmStubsPH4Z2_6_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_6_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_6_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_r_V_d0() {
    vmStubsPH4Z2_6_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_6_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_6))) {
        vmStubsPH4Z2_6_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_z_V_address0() {
    vmStubsPH4Z2_6_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_6_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_6_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_6_z_V_d0() {
    vmStubsPH4Z2_6_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_6_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_6))) {
        vmStubsPH4Z2_6_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_6_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_inde_address0() {
    vmStubsPH4Z2_7_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_7_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_7_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_inde_d0() {
    vmStubsPH4Z2_7_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_7_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_7))) {
        vmStubsPH4Z2_7_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_phi_s_address0() {
    vmStubsPH4Z2_7_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_7_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_7_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_phi_s_d0() {
    vmStubsPH4Z2_7_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_7_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_7))) {
        vmStubsPH4Z2_7_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_pt_V_address0() {
    vmStubsPH4Z2_7_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_7_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_7_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_pt_V_d0() {
    vmStubsPH4Z2_7_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_7_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_7))) {
        vmStubsPH4Z2_7_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_r_V_address0() {
    vmStubsPH4Z2_7_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_7_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_7_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_r_V_d0() {
    vmStubsPH4Z2_7_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_7_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_7))) {
        vmStubsPH4Z2_7_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_z_V_address0() {
    vmStubsPH4Z2_7_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_7_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_7_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_7_z_V_d0() {
    vmStubsPH4Z2_7_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_7_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_7))) {
        vmStubsPH4Z2_7_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_7_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_inde_address0() {
    vmStubsPH4Z2_8_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_8_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_8_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_inde_d0() {
    vmStubsPH4Z2_8_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_8_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_8))) {
        vmStubsPH4Z2_8_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_phi_s_address0() {
    vmStubsPH4Z2_8_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_8_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_8_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_phi_s_d0() {
    vmStubsPH4Z2_8_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_8_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_8))) {
        vmStubsPH4Z2_8_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_pt_V_address0() {
    vmStubsPH4Z2_8_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_8_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_8_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_pt_V_d0() {
    vmStubsPH4Z2_8_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_8_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_8))) {
        vmStubsPH4Z2_8_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_r_V_address0() {
    vmStubsPH4Z2_8_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_8_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_8_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_r_V_d0() {
    vmStubsPH4Z2_8_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_8_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_8))) {
        vmStubsPH4Z2_8_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_z_V_address0() {
    vmStubsPH4Z2_8_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_8_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_8_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_8_z_V_d0() {
    vmStubsPH4Z2_8_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_8_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_8))) {
        vmStubsPH4Z2_8_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_8_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_inde_address0() {
    vmStubsPH4Z2_9_inde_address0 =  (sc_lv<6>) (newIndex55_fu_15046_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_9_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH4Z2_9_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_inde_d0() {
    vmStubsPH4Z2_9_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH4Z2_9_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_91_fu_15031_p4.read(), ap_const_lv5_9))) {
        vmStubsPH4Z2_9_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_phi_s_address0() {
    vmStubsPH4Z2_9_phi_s_address0 =  (sc_lv<6>) (newIndex49_fu_16500_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_9_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_9_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_phi_s_d0() {
    vmStubsPH4Z2_9_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH4Z2_9_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_88_reg_18319.read(), ap_const_lv5_9))) {
        vmStubsPH4Z2_9_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_pt_V_address0() {
    vmStubsPH4Z2_9_pt_V_address0 =  (sc_lv<6>) (newIndex53_fu_16554_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_9_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_9_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_pt_V_d0() {
    vmStubsPH4Z2_9_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH4Z2_9_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_90_reg_18327.read(), ap_const_lv5_9))) {
        vmStubsPH4Z2_9_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_r_V_address0() {
    vmStubsPH4Z2_9_r_V_address0 =  (sc_lv<6>) (newIndex51_fu_16527_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_9_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_9_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_r_V_d0() {
    vmStubsPH4Z2_9_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH4Z2_9_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_89_reg_18323.read(), ap_const_lv5_9))) {
        vmStubsPH4Z2_9_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_z_V_address0() {
    vmStubsPH4Z2_9_z_V_address0 =  (sc_lv<6>) (newIndex47_fu_16473_p1.read());
}

void VMRouter::thread_vmStubsPH4Z2_9_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH4Z2_9_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH4Z2_9_z_V_d0() {
    vmStubsPH4Z2_9_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH4Z2_9_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_87_reg_18315.read(), ap_const_lv5_9))) {
        vmStubsPH4Z2_9_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH4Z2_9_z_V_we0 = ap_const_logic_0;
    }
}

}

