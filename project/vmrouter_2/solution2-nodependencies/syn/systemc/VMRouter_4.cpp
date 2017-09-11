#include "VMRouter.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouter::thread_vmStubsPH1Z1_3_inde_d0() {
    vmStubsPH1Z1_3_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_3_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_3))) {
        vmStubsPH1Z1_3_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_phi_s_address0() {
    vmStubsPH1Z1_3_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_3_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_3_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_phi_s_d0() {
    vmStubsPH1Z1_3_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_3_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_3))) {
        vmStubsPH1Z1_3_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_pt_V_address0() {
    vmStubsPH1Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_pt_V_d0() {
    vmStubsPH1Z1_3_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_3_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_3))) {
        vmStubsPH1Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_r_V_address0() {
    vmStubsPH1Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_r_V_d0() {
    vmStubsPH1Z1_3_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_3_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_3))) {
        vmStubsPH1Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_z_V_address0() {
    vmStubsPH1Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_3_z_V_d0() {
    vmStubsPH1Z1_3_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_3_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_3))) {
        vmStubsPH1Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_inde_address0() {
    vmStubsPH1Z1_4_inde_address0 =  (sc_lv<6>) (newIndex65_fu_14925_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_4_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z1_4_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_inde_d0() {
    vmStubsPH1Z1_4_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_4_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_4))) {
        vmStubsPH1Z1_4_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_phi_s_address0() {
    vmStubsPH1Z1_4_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_4_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_4_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_phi_s_d0() {
    vmStubsPH1Z1_4_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_4_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_4))) {
        vmStubsPH1Z1_4_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_pt_V_address0() {
    vmStubsPH1Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_pt_V_d0() {
    vmStubsPH1Z1_4_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_4_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_4))) {
        vmStubsPH1Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_r_V_address0() {
    vmStubsPH1Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_r_V_d0() {
    vmStubsPH1Z1_4_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_4_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_4))) {
        vmStubsPH1Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_z_V_address0() {
    vmStubsPH1Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_4_z_V_d0() {
    vmStubsPH1Z1_4_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_4_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_4))) {
        vmStubsPH1Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_inde_address0() {
    vmStubsPH1Z1_5_inde_address0 =  (sc_lv<6>) (newIndex65_fu_14925_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_5_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z1_5_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_inde_d0() {
    vmStubsPH1Z1_5_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_5_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_5))) {
        vmStubsPH1Z1_5_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_phi_s_address0() {
    vmStubsPH1Z1_5_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_5_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_5_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_phi_s_d0() {
    vmStubsPH1Z1_5_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_5_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_5))) {
        vmStubsPH1Z1_5_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_pt_V_address0() {
    vmStubsPH1Z1_5_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_5_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_5_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_pt_V_d0() {
    vmStubsPH1Z1_5_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_5_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_5))) {
        vmStubsPH1Z1_5_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_r_V_address0() {
    vmStubsPH1Z1_5_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_5_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_5_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_r_V_d0() {
    vmStubsPH1Z1_5_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_5_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_5))) {
        vmStubsPH1Z1_5_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_z_V_address0() {
    vmStubsPH1Z1_5_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_5_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_5_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_5_z_V_d0() {
    vmStubsPH1Z1_5_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_5_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_5))) {
        vmStubsPH1Z1_5_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_5_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_inde_address0() {
    vmStubsPH1Z1_6_inde_address0 =  (sc_lv<6>) (newIndex65_fu_14925_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_6_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z1_6_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_inde_d0() {
    vmStubsPH1Z1_6_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_6_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_6))) {
        vmStubsPH1Z1_6_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_phi_s_address0() {
    vmStubsPH1Z1_6_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_6_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_6_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_phi_s_d0() {
    vmStubsPH1Z1_6_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_6_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_6))) {
        vmStubsPH1Z1_6_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_pt_V_address0() {
    vmStubsPH1Z1_6_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_6_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_6_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_pt_V_d0() {
    vmStubsPH1Z1_6_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_6_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_6))) {
        vmStubsPH1Z1_6_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_r_V_address0() {
    vmStubsPH1Z1_6_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_6_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_6_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_r_V_d0() {
    vmStubsPH1Z1_6_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_6_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_6))) {
        vmStubsPH1Z1_6_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_z_V_address0() {
    vmStubsPH1Z1_6_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_6_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_6_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_6_z_V_d0() {
    vmStubsPH1Z1_6_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_6_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_6))) {
        vmStubsPH1Z1_6_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_6_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_inde_address0() {
    vmStubsPH1Z1_7_inde_address0 =  (sc_lv<6>) (newIndex65_fu_14925_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_7_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z1_7_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_inde_d0() {
    vmStubsPH1Z1_7_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_7_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_7))) {
        vmStubsPH1Z1_7_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_phi_s_address0() {
    vmStubsPH1Z1_7_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_7_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_7_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_phi_s_d0() {
    vmStubsPH1Z1_7_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_7_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_7))) {
        vmStubsPH1Z1_7_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_pt_V_address0() {
    vmStubsPH1Z1_7_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_7_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_7_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_pt_V_d0() {
    vmStubsPH1Z1_7_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_7_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_7))) {
        vmStubsPH1Z1_7_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_r_V_address0() {
    vmStubsPH1Z1_7_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_7_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_7_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_r_V_d0() {
    vmStubsPH1Z1_7_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_7_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_7))) {
        vmStubsPH1Z1_7_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_z_V_address0() {
    vmStubsPH1Z1_7_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_7_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_7_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_7_z_V_d0() {
    vmStubsPH1Z1_7_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_7_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_7))) {
        vmStubsPH1Z1_7_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_7_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_inde_address0() {
    vmStubsPH1Z1_8_inde_address0 =  (sc_lv<6>) (newIndex65_fu_14925_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_8_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z1_8_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_inde_d0() {
    vmStubsPH1Z1_8_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_8_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_8))) {
        vmStubsPH1Z1_8_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_phi_s_address0() {
    vmStubsPH1Z1_8_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_8_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_8_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_phi_s_d0() {
    vmStubsPH1Z1_8_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_8_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_8))) {
        vmStubsPH1Z1_8_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_pt_V_address0() {
    vmStubsPH1Z1_8_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_8_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_8_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_pt_V_d0() {
    vmStubsPH1Z1_8_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_8_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_8))) {
        vmStubsPH1Z1_8_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_r_V_address0() {
    vmStubsPH1Z1_8_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_8_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_8_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_r_V_d0() {
    vmStubsPH1Z1_8_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_8_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_8))) {
        vmStubsPH1Z1_8_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_z_V_address0() {
    vmStubsPH1Z1_8_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_8_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_8_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_8_z_V_d0() {
    vmStubsPH1Z1_8_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_8_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_8))) {
        vmStubsPH1Z1_8_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_8_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_inde_address0() {
    vmStubsPH1Z1_9_inde_address0 =  (sc_lv<6>) (newIndex65_fu_14925_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_9_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z1_9_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_inde_d0() {
    vmStubsPH1Z1_9_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z1_9_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_96_fu_14910_p4.read(), ap_const_lv5_9))) {
        vmStubsPH1Z1_9_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_phi_s_address0() {
    vmStubsPH1Z1_9_phi_s_address0 =  (sc_lv<6>) (newIndex59_fu_16392_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_9_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_9_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_phi_s_d0() {
    vmStubsPH1Z1_9_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z1_9_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_93_reg_18291.read(), ap_const_lv5_9))) {
        vmStubsPH1Z1_9_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_pt_V_address0() {
    vmStubsPH1Z1_9_pt_V_address0 =  (sc_lv<6>) (newIndex63_fu_16446_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_9_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_9_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_pt_V_d0() {
    vmStubsPH1Z1_9_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z1_9_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_95_reg_18299.read(), ap_const_lv5_9))) {
        vmStubsPH1Z1_9_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_r_V_address0() {
    vmStubsPH1Z1_9_r_V_address0 =  (sc_lv<6>) (newIndex61_fu_16419_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_9_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_9_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_r_V_d0() {
    vmStubsPH1Z1_9_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z1_9_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_94_reg_18295.read(), ap_const_lv5_9))) {
        vmStubsPH1Z1_9_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_z_V_address0() {
    vmStubsPH1Z1_9_z_V_address0 =  (sc_lv<6>) (newIndex57_fu_16365_p1.read());
}

void VMRouter::thread_vmStubsPH1Z1_9_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z1_9_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z1_9_z_V_d0() {
    vmStubsPH1Z1_9_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z1_9_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,5,5>(tmp_92_reg_18287.read(), ap_const_lv5_9))) {
        vmStubsPH1Z1_9_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z1_9_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_inde_address0() {
    vmStubsPH1Z2_0_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_0_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_0_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_inde_d0() {
    vmStubsPH1Z2_0_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_0_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_0))) {
        vmStubsPH1Z2_0_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_phi_s_address0() {
    vmStubsPH1Z2_0_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_0_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_0_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_phi_s_d0() {
    vmStubsPH1Z2_0_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_0_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_0))) {
        vmStubsPH1Z2_0_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_pt_V_address0() {
    vmStubsPH1Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_pt_V_d0() {
    vmStubsPH1Z2_0_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_0_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_0))) {
        vmStubsPH1Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_r_V_address0() {
    vmStubsPH1Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_r_V_d0() {
    vmStubsPH1Z2_0_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_0_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_0))) {
        vmStubsPH1Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_z_V_address0() {
    vmStubsPH1Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_0_z_V_d0() {
    vmStubsPH1Z2_0_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_0_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_0))) {
        vmStubsPH1Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_ind_address0() {
    vmStubsPH1Z2_10_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_10_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_10_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_ind_d0() {
    vmStubsPH1Z2_10_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_10_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_A))) {
        vmStubsPH1Z2_10_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_phi_address0() {
    vmStubsPH1Z2_10_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_10_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_10_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_phi_d0() {
    vmStubsPH1Z2_10_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_10_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_A))) {
        vmStubsPH1Z2_10_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_pt_s_address0() {
    vmStubsPH1Z2_10_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_10_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_10_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_pt_s_d0() {
    vmStubsPH1Z2_10_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_10_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_A))) {
        vmStubsPH1Z2_10_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_r_V_address0() {
    vmStubsPH1Z2_10_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_10_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_10_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_r_V_d0() {
    vmStubsPH1Z2_10_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_10_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_A))) {
        vmStubsPH1Z2_10_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_z_V_address0() {
    vmStubsPH1Z2_10_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_10_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_10_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_10_z_V_d0() {
    vmStubsPH1Z2_10_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_10_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_A))) {
        vmStubsPH1Z2_10_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_10_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_ind_address0() {
    vmStubsPH1Z2_11_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_11_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_11_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_ind_d0() {
    vmStubsPH1Z2_11_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_11_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_B))) {
        vmStubsPH1Z2_11_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_phi_address0() {
    vmStubsPH1Z2_11_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_11_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_11_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_phi_d0() {
    vmStubsPH1Z2_11_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_11_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_B))) {
        vmStubsPH1Z2_11_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_pt_s_address0() {
    vmStubsPH1Z2_11_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_11_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_11_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_pt_s_d0() {
    vmStubsPH1Z2_11_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_11_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_B))) {
        vmStubsPH1Z2_11_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_r_V_address0() {
    vmStubsPH1Z2_11_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_11_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_11_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_r_V_d0() {
    vmStubsPH1Z2_11_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_11_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_B))) {
        vmStubsPH1Z2_11_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_z_V_address0() {
    vmStubsPH1Z2_11_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_11_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_11_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_11_z_V_d0() {
    vmStubsPH1Z2_11_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_11_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_B))) {
        vmStubsPH1Z2_11_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_11_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_ind_address0() {
    vmStubsPH1Z2_12_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_12_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_12_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_ind_d0() {
    vmStubsPH1Z2_12_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_12_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_C))) {
        vmStubsPH1Z2_12_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_phi_address0() {
    vmStubsPH1Z2_12_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_12_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_12_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_phi_d0() {
    vmStubsPH1Z2_12_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_12_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_C))) {
        vmStubsPH1Z2_12_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_pt_s_address0() {
    vmStubsPH1Z2_12_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_12_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_12_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_pt_s_d0() {
    vmStubsPH1Z2_12_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_12_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_C))) {
        vmStubsPH1Z2_12_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_r_V_address0() {
    vmStubsPH1Z2_12_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_12_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_12_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_r_V_d0() {
    vmStubsPH1Z2_12_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_12_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_C))) {
        vmStubsPH1Z2_12_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_z_V_address0() {
    vmStubsPH1Z2_12_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_12_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_12_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_12_z_V_d0() {
    vmStubsPH1Z2_12_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_12_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_C))) {
        vmStubsPH1Z2_12_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_12_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_ind_address0() {
    vmStubsPH1Z2_13_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_13_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_13_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_ind_d0() {
    vmStubsPH1Z2_13_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_13_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_D))) {
        vmStubsPH1Z2_13_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_phi_address0() {
    vmStubsPH1Z2_13_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_13_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_13_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_phi_d0() {
    vmStubsPH1Z2_13_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_13_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_D))) {
        vmStubsPH1Z2_13_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_pt_s_address0() {
    vmStubsPH1Z2_13_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_13_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_13_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_pt_s_d0() {
    vmStubsPH1Z2_13_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_13_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_D))) {
        vmStubsPH1Z2_13_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_r_V_address0() {
    vmStubsPH1Z2_13_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_13_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_13_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_r_V_d0() {
    vmStubsPH1Z2_13_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_13_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_D))) {
        vmStubsPH1Z2_13_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_z_V_address0() {
    vmStubsPH1Z2_13_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_13_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_13_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_13_z_V_d0() {
    vmStubsPH1Z2_13_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_13_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_D))) {
        vmStubsPH1Z2_13_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_13_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_ind_address0() {
    vmStubsPH1Z2_14_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_14_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_14_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_ind_d0() {
    vmStubsPH1Z2_14_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_14_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_E))) {
        vmStubsPH1Z2_14_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_phi_address0() {
    vmStubsPH1Z2_14_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_14_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_14_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_phi_d0() {
    vmStubsPH1Z2_14_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_14_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_E))) {
        vmStubsPH1Z2_14_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_pt_s_address0() {
    vmStubsPH1Z2_14_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_14_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_14_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_pt_s_d0() {
    vmStubsPH1Z2_14_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_14_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_E))) {
        vmStubsPH1Z2_14_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_r_V_address0() {
    vmStubsPH1Z2_14_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_14_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_14_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_r_V_d0() {
    vmStubsPH1Z2_14_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_14_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_E))) {
        vmStubsPH1Z2_14_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_z_V_address0() {
    vmStubsPH1Z2_14_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_14_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_14_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_14_z_V_d0() {
    vmStubsPH1Z2_14_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_14_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_E))) {
        vmStubsPH1Z2_14_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_14_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_ind_address0() {
    vmStubsPH1Z2_15_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_15_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_15_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_ind_d0() {
    vmStubsPH1Z2_15_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_15_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_F))) {
        vmStubsPH1Z2_15_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_phi_address0() {
    vmStubsPH1Z2_15_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_15_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_15_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_phi_d0() {
    vmStubsPH1Z2_15_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_15_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_F))) {
        vmStubsPH1Z2_15_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_pt_s_address0() {
    vmStubsPH1Z2_15_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_15_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_15_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_pt_s_d0() {
    vmStubsPH1Z2_15_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_15_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_F))) {
        vmStubsPH1Z2_15_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_r_V_address0() {
    vmStubsPH1Z2_15_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_15_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_15_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_r_V_d0() {
    vmStubsPH1Z2_15_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_15_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_F))) {
        vmStubsPH1Z2_15_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_z_V_address0() {
    vmStubsPH1Z2_15_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_15_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_15_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_15_z_V_d0() {
    vmStubsPH1Z2_15_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_15_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_F))) {
        vmStubsPH1Z2_15_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_15_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_ind_address0() {
    vmStubsPH1Z2_16_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_16_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_16_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_ind_d0() {
    vmStubsPH1Z2_16_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_16_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_10))) {
        vmStubsPH1Z2_16_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_phi_address0() {
    vmStubsPH1Z2_16_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_16_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_16_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_phi_d0() {
    vmStubsPH1Z2_16_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_16_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_10))) {
        vmStubsPH1Z2_16_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_pt_s_address0() {
    vmStubsPH1Z2_16_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_16_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_16_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_pt_s_d0() {
    vmStubsPH1Z2_16_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_16_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_10))) {
        vmStubsPH1Z2_16_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_r_V_address0() {
    vmStubsPH1Z2_16_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_16_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_16_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_r_V_d0() {
    vmStubsPH1Z2_16_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_16_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_10))) {
        vmStubsPH1Z2_16_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_z_V_address0() {
    vmStubsPH1Z2_16_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_16_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_16_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_16_z_V_d0() {
    vmStubsPH1Z2_16_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_16_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_10))) {
        vmStubsPH1Z2_16_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_16_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_ind_address0() {
    vmStubsPH1Z2_17_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_17_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_17_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_ind_d0() {
    vmStubsPH1Z2_17_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_17_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_17_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_phi_address0() {
    vmStubsPH1Z2_17_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_17_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_17_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_phi_d0() {
    vmStubsPH1Z2_17_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_17_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_17_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_pt_s_address0() {
    vmStubsPH1Z2_17_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_17_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_17_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_pt_s_d0() {
    vmStubsPH1Z2_17_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_17_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_17_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_r_V_address0() {
    vmStubsPH1Z2_17_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_17_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_17_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_r_V_d0() {
    vmStubsPH1Z2_17_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_17_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_17_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_z_V_address0() {
    vmStubsPH1Z2_17_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_17_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_17_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_17_z_V_d0() {
    vmStubsPH1Z2_17_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_17_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_17_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_17_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_ind_address0() {
    vmStubsPH1Z2_18_ind_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_18_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_18_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_ind_d0() {
    vmStubsPH1Z2_18_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_18_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_18_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_phi_address0() {
    vmStubsPH1Z2_18_phi_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_18_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_18_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_phi_d0() {
    vmStubsPH1Z2_18_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_18_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_18_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_pt_s_address0() {
    vmStubsPH1Z2_18_pt_s_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_18_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_18_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_pt_s_d0() {
    vmStubsPH1Z2_18_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_18_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_18_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_r_V_address0() {
    vmStubsPH1Z2_18_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_18_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_18_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_r_V_d0() {
    vmStubsPH1Z2_18_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_18_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_18_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_z_V_address0() {
    vmStubsPH1Z2_18_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_18_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_18_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_18_z_V_d0() {
    vmStubsPH1Z2_18_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_18_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_11))) {
        vmStubsPH1Z2_18_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_18_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_inde_address0() {
    vmStubsPH1Z2_1_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_1_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_1_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_inde_d0() {
    vmStubsPH1Z2_1_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_1_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_1))) {
        vmStubsPH1Z2_1_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_phi_s_address0() {
    vmStubsPH1Z2_1_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_1_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_1_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_phi_s_d0() {
    vmStubsPH1Z2_1_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_1_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_1))) {
        vmStubsPH1Z2_1_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_pt_V_address0() {
    vmStubsPH1Z2_1_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_1_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_pt_V_d0() {
    vmStubsPH1Z2_1_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_1_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_1))) {
        vmStubsPH1Z2_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_r_V_address0() {
    vmStubsPH1Z2_1_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_1_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_r_V_d0() {
    vmStubsPH1Z2_1_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_1_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_1))) {
        vmStubsPH1Z2_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_z_V_address0() {
    vmStubsPH1Z2_1_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_1_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_1_z_V_d0() {
    vmStubsPH1Z2_1_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_1_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_1))) {
        vmStubsPH1Z2_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_inde_address0() {
    vmStubsPH1Z2_2_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_2_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_2_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_inde_d0() {
    vmStubsPH1Z2_2_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_2_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_2))) {
        vmStubsPH1Z2_2_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_phi_s_address0() {
    vmStubsPH1Z2_2_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_2_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_2_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_phi_s_d0() {
    vmStubsPH1Z2_2_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_2_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_2))) {
        vmStubsPH1Z2_2_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_pt_V_address0() {
    vmStubsPH1Z2_2_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_2_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_pt_V_d0() {
    vmStubsPH1Z2_2_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_2_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_2))) {
        vmStubsPH1Z2_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_r_V_address0() {
    vmStubsPH1Z2_2_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_2_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_r_V_d0() {
    vmStubsPH1Z2_2_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_2_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_2))) {
        vmStubsPH1Z2_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_z_V_address0() {
    vmStubsPH1Z2_2_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_2_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_2_z_V_d0() {
    vmStubsPH1Z2_2_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_2_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_2))) {
        vmStubsPH1Z2_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_inde_address0() {
    vmStubsPH1Z2_3_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_3_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_3_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_inde_d0() {
    vmStubsPH1Z2_3_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_3_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_3))) {
        vmStubsPH1Z2_3_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_phi_s_address0() {
    vmStubsPH1Z2_3_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_3_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_3_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_phi_s_d0() {
    vmStubsPH1Z2_3_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_3_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_3))) {
        vmStubsPH1Z2_3_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_pt_V_address0() {
    vmStubsPH1Z2_3_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_pt_V_d0() {
    vmStubsPH1Z2_3_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_3_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_3))) {
        vmStubsPH1Z2_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_r_V_address0() {
    vmStubsPH1Z2_3_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_r_V_d0() {
    vmStubsPH1Z2_3_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_3_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_3))) {
        vmStubsPH1Z2_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_z_V_address0() {
    vmStubsPH1Z2_3_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_3_z_V_d0() {
    vmStubsPH1Z2_3_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_3_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_3))) {
        vmStubsPH1Z2_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_inde_address0() {
    vmStubsPH1Z2_4_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_4_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_4_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_inde_d0() {
    vmStubsPH1Z2_4_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_4_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_4))) {
        vmStubsPH1Z2_4_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_phi_s_address0() {
    vmStubsPH1Z2_4_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_4_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_4_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_phi_s_d0() {
    vmStubsPH1Z2_4_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_4_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_4))) {
        vmStubsPH1Z2_4_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_pt_V_address0() {
    vmStubsPH1Z2_4_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_pt_V_d0() {
    vmStubsPH1Z2_4_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_4_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_4))) {
        vmStubsPH1Z2_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_r_V_address0() {
    vmStubsPH1Z2_4_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_r_V_d0() {
    vmStubsPH1Z2_4_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_4_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_4))) {
        vmStubsPH1Z2_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_z_V_address0() {
    vmStubsPH1Z2_4_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_4_z_V_d0() {
    vmStubsPH1Z2_4_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_4_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_4))) {
        vmStubsPH1Z2_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_inde_address0() {
    vmStubsPH1Z2_5_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_5_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_5_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_inde_d0() {
    vmStubsPH1Z2_5_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_5_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_5))) {
        vmStubsPH1Z2_5_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_phi_s_address0() {
    vmStubsPH1Z2_5_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_5_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_5_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_phi_s_d0() {
    vmStubsPH1Z2_5_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_5_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_5))) {
        vmStubsPH1Z2_5_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_pt_V_address0() {
    vmStubsPH1Z2_5_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_5_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_5_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_pt_V_d0() {
    vmStubsPH1Z2_5_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_5_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_5))) {
        vmStubsPH1Z2_5_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_r_V_address0() {
    vmStubsPH1Z2_5_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_5_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_5_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_r_V_d0() {
    vmStubsPH1Z2_5_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_5_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_5))) {
        vmStubsPH1Z2_5_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_z_V_address0() {
    vmStubsPH1Z2_5_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_5_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_5_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_5_z_V_d0() {
    vmStubsPH1Z2_5_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_5_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_5))) {
        vmStubsPH1Z2_5_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_5_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_inde_address0() {
    vmStubsPH1Z2_6_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_6_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_6_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_inde_d0() {
    vmStubsPH1Z2_6_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_6_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_6))) {
        vmStubsPH1Z2_6_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_phi_s_address0() {
    vmStubsPH1Z2_6_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_6_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_6_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_phi_s_d0() {
    vmStubsPH1Z2_6_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_6_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_6))) {
        vmStubsPH1Z2_6_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_pt_V_address0() {
    vmStubsPH1Z2_6_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_6_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_6_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_pt_V_d0() {
    vmStubsPH1Z2_6_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_6_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_6))) {
        vmStubsPH1Z2_6_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_r_V_address0() {
    vmStubsPH1Z2_6_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_6_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_6_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_r_V_d0() {
    vmStubsPH1Z2_6_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_6_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_6))) {
        vmStubsPH1Z2_6_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_z_V_address0() {
    vmStubsPH1Z2_6_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_6_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_6_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_6_z_V_d0() {
    vmStubsPH1Z2_6_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_6_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_6))) {
        vmStubsPH1Z2_6_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_6_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_inde_address0() {
    vmStubsPH1Z2_7_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_7_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_7_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_inde_d0() {
    vmStubsPH1Z2_7_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_7_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_7))) {
        vmStubsPH1Z2_7_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_phi_s_address0() {
    vmStubsPH1Z2_7_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_7_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_7_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_phi_s_d0() {
    vmStubsPH1Z2_7_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_7_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_7))) {
        vmStubsPH1Z2_7_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_pt_V_address0() {
    vmStubsPH1Z2_7_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_7_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_7_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_pt_V_d0() {
    vmStubsPH1Z2_7_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_7_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_7))) {
        vmStubsPH1Z2_7_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_r_V_address0() {
    vmStubsPH1Z2_7_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_7_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_7_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_r_V_d0() {
    vmStubsPH1Z2_7_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_7_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_7))) {
        vmStubsPH1Z2_7_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_z_V_address0() {
    vmStubsPH1Z2_7_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_7_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_7_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_7_z_V_d0() {
    vmStubsPH1Z2_7_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_7_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_7))) {
        vmStubsPH1Z2_7_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_7_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_inde_address0() {
    vmStubsPH1Z2_8_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_8_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_8_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_inde_d0() {
    vmStubsPH1Z2_8_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_8_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_8))) {
        vmStubsPH1Z2_8_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_phi_s_address0() {
    vmStubsPH1Z2_8_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_8_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_8_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_phi_s_d0() {
    vmStubsPH1Z2_8_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_8_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_8))) {
        vmStubsPH1Z2_8_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_pt_V_address0() {
    vmStubsPH1Z2_8_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_8_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_8_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_pt_V_d0() {
    vmStubsPH1Z2_8_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_8_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_8))) {
        vmStubsPH1Z2_8_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_r_V_address0() {
    vmStubsPH1Z2_8_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_8_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_8_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_r_V_d0() {
    vmStubsPH1Z2_8_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_8_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_8))) {
        vmStubsPH1Z2_8_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_z_V_address0() {
    vmStubsPH1Z2_8_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_8_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_8_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_8_z_V_d0() {
    vmStubsPH1Z2_8_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_8_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_8))) {
        vmStubsPH1Z2_8_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_8_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_inde_address0() {
    vmStubsPH1Z2_9_inde_address0 =  (sc_lv<6>) (newIndex25_fu_15409_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_9_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH1Z2_9_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_inde_d0() {
    vmStubsPH1Z2_9_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH1Z2_9_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_26_fu_15394_p4.read(), ap_const_lv5_9))) {
        vmStubsPH1Z2_9_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_phi_s_address0() {
    vmStubsPH1Z2_9_phi_s_address0 =  (sc_lv<6>) (newIndex19_fu_16824_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_9_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_9_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_phi_s_d0() {
    vmStubsPH1Z2_9_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH1Z2_9_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_8_reg_18403.read(), ap_const_lv5_9))) {
        vmStubsPH1Z2_9_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_pt_V_address0() {
    vmStubsPH1Z2_9_pt_V_address0 =  (sc_lv<6>) (newIndex23_fu_16878_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_9_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_9_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_pt_V_d0() {
    vmStubsPH1Z2_9_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH1Z2_9_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_10_reg_18411.read(), ap_const_lv5_9))) {
        vmStubsPH1Z2_9_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_r_V_address0() {
    vmStubsPH1Z2_9_r_V_address0 =  (sc_lv<6>) (newIndex21_fu_16851_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_9_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_9_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_r_V_d0() {
    vmStubsPH1Z2_9_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH1Z2_9_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_9_reg_18407.read(), ap_const_lv5_9))) {
        vmStubsPH1Z2_9_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_z_V_address0() {
    vmStubsPH1Z2_9_z_V_address0 =  (sc_lv<6>) (newIndex17_fu_16797_p1.read());
}

void VMRouter::thread_vmStubsPH1Z2_9_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH1Z2_9_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH1Z2_9_z_V_d0() {
    vmStubsPH1Z2_9_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH1Z2_9_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_7_reg_18399.read(), ap_const_lv5_9))) {
        vmStubsPH1Z2_9_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH1Z2_9_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_inde_address0() {
    vmStubsPH2Z1_0_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_0_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_0_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_inde_d0() {
    vmStubsPH2Z1_0_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_0_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_0))) {
        vmStubsPH2Z1_0_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_phi_s_address0() {
    vmStubsPH2Z1_0_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_0_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_0_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_phi_s_d0() {
    vmStubsPH2Z1_0_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_0_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_0))) {
        vmStubsPH2Z1_0_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_pt_V_address0() {
    vmStubsPH2Z1_0_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_pt_V_d0() {
    vmStubsPH2Z1_0_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_0_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_0))) {
        vmStubsPH2Z1_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_r_V_address0() {
    vmStubsPH2Z1_0_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_r_V_d0() {
    vmStubsPH2Z1_0_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_0_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_0))) {
        vmStubsPH2Z1_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_z_V_address0() {
    vmStubsPH2Z1_0_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_0_z_V_d0() {
    vmStubsPH2Z1_0_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_0_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_0))) {
        vmStubsPH2Z1_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_ind_address0() {
    vmStubsPH2Z1_10_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_10_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_10_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_ind_d0() {
    vmStubsPH2Z1_10_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_10_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_A))) {
        vmStubsPH2Z1_10_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_phi_address0() {
    vmStubsPH2Z1_10_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_10_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_10_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_phi_d0() {
    vmStubsPH2Z1_10_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_10_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_A))) {
        vmStubsPH2Z1_10_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_pt_s_address0() {
    vmStubsPH2Z1_10_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_10_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_10_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_pt_s_d0() {
    vmStubsPH2Z1_10_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_10_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_A))) {
        vmStubsPH2Z1_10_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_r_V_address0() {
    vmStubsPH2Z1_10_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_10_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_10_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_r_V_d0() {
    vmStubsPH2Z1_10_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_10_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_A))) {
        vmStubsPH2Z1_10_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_z_V_address0() {
    vmStubsPH2Z1_10_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_10_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_10_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_10_z_V_d0() {
    vmStubsPH2Z1_10_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_10_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_A))) {
        vmStubsPH2Z1_10_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_10_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_ind_address0() {
    vmStubsPH2Z1_11_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_11_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_11_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_ind_d0() {
    vmStubsPH2Z1_11_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_11_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_B))) {
        vmStubsPH2Z1_11_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_phi_address0() {
    vmStubsPH2Z1_11_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_11_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_11_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_phi_d0() {
    vmStubsPH2Z1_11_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_11_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_B))) {
        vmStubsPH2Z1_11_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_pt_s_address0() {
    vmStubsPH2Z1_11_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_11_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_11_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_pt_s_d0() {
    vmStubsPH2Z1_11_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_11_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_B))) {
        vmStubsPH2Z1_11_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_r_V_address0() {
    vmStubsPH2Z1_11_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_11_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_11_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_r_V_d0() {
    vmStubsPH2Z1_11_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_11_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_B))) {
        vmStubsPH2Z1_11_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_z_V_address0() {
    vmStubsPH2Z1_11_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_11_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_11_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_11_z_V_d0() {
    vmStubsPH2Z1_11_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_11_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_B))) {
        vmStubsPH2Z1_11_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_11_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_ind_address0() {
    vmStubsPH2Z1_12_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_12_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_12_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_ind_d0() {
    vmStubsPH2Z1_12_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_12_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_C))) {
        vmStubsPH2Z1_12_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_phi_address0() {
    vmStubsPH2Z1_12_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_12_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_12_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_phi_d0() {
    vmStubsPH2Z1_12_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_12_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_C))) {
        vmStubsPH2Z1_12_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_pt_s_address0() {
    vmStubsPH2Z1_12_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_12_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_12_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_pt_s_d0() {
    vmStubsPH2Z1_12_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_12_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_C))) {
        vmStubsPH2Z1_12_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_r_V_address0() {
    vmStubsPH2Z1_12_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_12_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_12_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_r_V_d0() {
    vmStubsPH2Z1_12_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_12_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_C))) {
        vmStubsPH2Z1_12_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_z_V_address0() {
    vmStubsPH2Z1_12_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_12_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_12_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_12_z_V_d0() {
    vmStubsPH2Z1_12_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_12_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_C))) {
        vmStubsPH2Z1_12_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_12_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_ind_address0() {
    vmStubsPH2Z1_13_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_13_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_13_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_ind_d0() {
    vmStubsPH2Z1_13_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_13_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_D))) {
        vmStubsPH2Z1_13_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_phi_address0() {
    vmStubsPH2Z1_13_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_13_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_13_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_phi_d0() {
    vmStubsPH2Z1_13_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_13_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_D))) {
        vmStubsPH2Z1_13_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_pt_s_address0() {
    vmStubsPH2Z1_13_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_13_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_13_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_pt_s_d0() {
    vmStubsPH2Z1_13_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_13_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_D))) {
        vmStubsPH2Z1_13_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_r_V_address0() {
    vmStubsPH2Z1_13_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_13_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_13_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_r_V_d0() {
    vmStubsPH2Z1_13_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_13_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_D))) {
        vmStubsPH2Z1_13_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_z_V_address0() {
    vmStubsPH2Z1_13_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_13_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_13_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_13_z_V_d0() {
    vmStubsPH2Z1_13_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_13_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_D))) {
        vmStubsPH2Z1_13_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_13_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_ind_address0() {
    vmStubsPH2Z1_14_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_14_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_14_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_ind_d0() {
    vmStubsPH2Z1_14_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_14_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_E))) {
        vmStubsPH2Z1_14_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_phi_address0() {
    vmStubsPH2Z1_14_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_14_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_14_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_phi_d0() {
    vmStubsPH2Z1_14_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_14_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_E))) {
        vmStubsPH2Z1_14_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_pt_s_address0() {
    vmStubsPH2Z1_14_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_14_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_14_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_pt_s_d0() {
    vmStubsPH2Z1_14_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_14_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_E))) {
        vmStubsPH2Z1_14_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_r_V_address0() {
    vmStubsPH2Z1_14_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_14_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_14_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_r_V_d0() {
    vmStubsPH2Z1_14_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_14_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_E))) {
        vmStubsPH2Z1_14_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_z_V_address0() {
    vmStubsPH2Z1_14_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_14_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_14_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_14_z_V_d0() {
    vmStubsPH2Z1_14_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_14_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_E))) {
        vmStubsPH2Z1_14_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_14_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_ind_address0() {
    vmStubsPH2Z1_15_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_15_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_15_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_ind_d0() {
    vmStubsPH2Z1_15_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_15_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_F))) {
        vmStubsPH2Z1_15_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_phi_address0() {
    vmStubsPH2Z1_15_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_15_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_15_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_phi_d0() {
    vmStubsPH2Z1_15_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_15_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_F))) {
        vmStubsPH2Z1_15_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_pt_s_address0() {
    vmStubsPH2Z1_15_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_15_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_15_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_pt_s_d0() {
    vmStubsPH2Z1_15_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_15_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_F))) {
        vmStubsPH2Z1_15_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_r_V_address0() {
    vmStubsPH2Z1_15_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_15_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_15_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_r_V_d0() {
    vmStubsPH2Z1_15_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_15_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_F))) {
        vmStubsPH2Z1_15_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_z_V_address0() {
    vmStubsPH2Z1_15_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_15_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_15_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_15_z_V_d0() {
    vmStubsPH2Z1_15_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_15_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_F))) {
        vmStubsPH2Z1_15_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_15_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_ind_address0() {
    vmStubsPH2Z1_16_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_16_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_16_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_ind_d0() {
    vmStubsPH2Z1_16_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_16_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_10))) {
        vmStubsPH2Z1_16_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_phi_address0() {
    vmStubsPH2Z1_16_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_16_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_16_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_phi_d0() {
    vmStubsPH2Z1_16_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_16_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_10))) {
        vmStubsPH2Z1_16_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_pt_s_address0() {
    vmStubsPH2Z1_16_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_16_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_16_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_pt_s_d0() {
    vmStubsPH2Z1_16_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_16_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_10))) {
        vmStubsPH2Z1_16_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_r_V_address0() {
    vmStubsPH2Z1_16_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_16_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_16_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_r_V_d0() {
    vmStubsPH2Z1_16_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_16_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_10))) {
        vmStubsPH2Z1_16_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_z_V_address0() {
    vmStubsPH2Z1_16_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_16_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_16_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_16_z_V_d0() {
    vmStubsPH2Z1_16_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_16_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_10))) {
        vmStubsPH2Z1_16_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_16_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_ind_address0() {
    vmStubsPH2Z1_17_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_17_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_17_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_ind_d0() {
    vmStubsPH2Z1_17_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_17_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_17_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_phi_address0() {
    vmStubsPH2Z1_17_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_17_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_17_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_phi_d0() {
    vmStubsPH2Z1_17_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_17_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_17_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_pt_s_address0() {
    vmStubsPH2Z1_17_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_17_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_17_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_pt_s_d0() {
    vmStubsPH2Z1_17_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_17_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_17_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_r_V_address0() {
    vmStubsPH2Z1_17_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_17_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_17_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_r_V_d0() {
    vmStubsPH2Z1_17_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_17_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_17_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_z_V_address0() {
    vmStubsPH2Z1_17_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_17_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_17_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_17_z_V_d0() {
    vmStubsPH2Z1_17_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_17_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_17_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_17_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_ind_address0() {
    vmStubsPH2Z1_18_ind_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_18_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_18_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_ind_d0() {
    vmStubsPH2Z1_18_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_18_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_18_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_phi_address0() {
    vmStubsPH2Z1_18_phi_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_18_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_18_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_phi_d0() {
    vmStubsPH2Z1_18_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_18_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_18_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_pt_s_address0() {
    vmStubsPH2Z1_18_pt_s_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_18_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_18_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_pt_s_d0() {
    vmStubsPH2Z1_18_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_18_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_18_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_r_V_address0() {
    vmStubsPH2Z1_18_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_18_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_18_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_r_V_d0() {
    vmStubsPH2Z1_18_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_18_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_18_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_z_V_address0() {
    vmStubsPH2Z1_18_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_18_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_18_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_18_z_V_d0() {
    vmStubsPH2Z1_18_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_18_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_0) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_1) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_2) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_3) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_4) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_5) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_6) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_7) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_8) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_9) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_A) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_B) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_C) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_D) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_E) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_F) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_10) && 
         !esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_11))) {
        vmStubsPH2Z1_18_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_18_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_inde_address0() {
    vmStubsPH2Z1_1_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_1_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_1_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_inde_d0() {
    vmStubsPH2Z1_1_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_1_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_1))) {
        vmStubsPH2Z1_1_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_phi_s_address0() {
    vmStubsPH2Z1_1_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_1_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_1_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_phi_s_d0() {
    vmStubsPH2Z1_1_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_1_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_1))) {
        vmStubsPH2Z1_1_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_pt_V_address0() {
    vmStubsPH2Z1_1_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_1_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_1_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_pt_V_d0() {
    vmStubsPH2Z1_1_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_1_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_1))) {
        vmStubsPH2Z1_1_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_r_V_address0() {
    vmStubsPH2Z1_1_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_1_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_1_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_r_V_d0() {
    vmStubsPH2Z1_1_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_1_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_1))) {
        vmStubsPH2Z1_1_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_z_V_address0() {
    vmStubsPH2Z1_1_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_1_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_1_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_1_z_V_d0() {
    vmStubsPH2Z1_1_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_1_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_1))) {
        vmStubsPH2Z1_1_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_1_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_inde_address0() {
    vmStubsPH2Z1_2_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_2_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_2_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_inde_d0() {
    vmStubsPH2Z1_2_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_2_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_2))) {
        vmStubsPH2Z1_2_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_phi_s_address0() {
    vmStubsPH2Z1_2_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_2_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_2_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_phi_s_d0() {
    vmStubsPH2Z1_2_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_2_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_2))) {
        vmStubsPH2Z1_2_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_pt_V_address0() {
    vmStubsPH2Z1_2_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_2_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_2_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_pt_V_d0() {
    vmStubsPH2Z1_2_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_2_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_2))) {
        vmStubsPH2Z1_2_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_r_V_address0() {
    vmStubsPH2Z1_2_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_2_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_2_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_r_V_d0() {
    vmStubsPH2Z1_2_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_2_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_2))) {
        vmStubsPH2Z1_2_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_z_V_address0() {
    vmStubsPH2Z1_2_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_2_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_2_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_2_z_V_d0() {
    vmStubsPH2Z1_2_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_2_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_2))) {
        vmStubsPH2Z1_2_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_2_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_inde_address0() {
    vmStubsPH2Z1_3_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_3_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_3_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_inde_d0() {
    vmStubsPH2Z1_3_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_3_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_3))) {
        vmStubsPH2Z1_3_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_phi_s_address0() {
    vmStubsPH2Z1_3_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_3_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_3_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_phi_s_d0() {
    vmStubsPH2Z1_3_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_3_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_3))) {
        vmStubsPH2Z1_3_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_pt_V_address0() {
    vmStubsPH2Z1_3_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_3_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_3_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_pt_V_d0() {
    vmStubsPH2Z1_3_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_3_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_3))) {
        vmStubsPH2Z1_3_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_r_V_address0() {
    vmStubsPH2Z1_3_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_3_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_3_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_r_V_d0() {
    vmStubsPH2Z1_3_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_3_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_3))) {
        vmStubsPH2Z1_3_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_z_V_address0() {
    vmStubsPH2Z1_3_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_3_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_3_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_3_z_V_d0() {
    vmStubsPH2Z1_3_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_3_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_3))) {
        vmStubsPH2Z1_3_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_3_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_inde_address0() {
    vmStubsPH2Z1_4_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_4_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_4_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_inde_d0() {
    vmStubsPH2Z1_4_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_4_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_4))) {
        vmStubsPH2Z1_4_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_phi_s_address0() {
    vmStubsPH2Z1_4_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_4_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_4_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_phi_s_d0() {
    vmStubsPH2Z1_4_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_4_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_4))) {
        vmStubsPH2Z1_4_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_pt_V_address0() {
    vmStubsPH2Z1_4_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_4_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_4_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_pt_V_d0() {
    vmStubsPH2Z1_4_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_4_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_4))) {
        vmStubsPH2Z1_4_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_r_V_address0() {
    vmStubsPH2Z1_4_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_4_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_4_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_r_V_d0() {
    vmStubsPH2Z1_4_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_4_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_4))) {
        vmStubsPH2Z1_4_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_z_V_address0() {
    vmStubsPH2Z1_4_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_4_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_4_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_4_z_V_d0() {
    vmStubsPH2Z1_4_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_4_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_4))) {
        vmStubsPH2Z1_4_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_4_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_inde_address0() {
    vmStubsPH2Z1_5_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_5_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_5_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_inde_d0() {
    vmStubsPH2Z1_5_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_5_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_5))) {
        vmStubsPH2Z1_5_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_phi_s_address0() {
    vmStubsPH2Z1_5_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_5_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_5_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_phi_s_d0() {
    vmStubsPH2Z1_5_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_5_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_5))) {
        vmStubsPH2Z1_5_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_pt_V_address0() {
    vmStubsPH2Z1_5_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_5_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_5_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_pt_V_d0() {
    vmStubsPH2Z1_5_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_5_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_5))) {
        vmStubsPH2Z1_5_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_r_V_address0() {
    vmStubsPH2Z1_5_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_5_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_5_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_r_V_d0() {
    vmStubsPH2Z1_5_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_5_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_5))) {
        vmStubsPH2Z1_5_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_z_V_address0() {
    vmStubsPH2Z1_5_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_5_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_5_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_5_z_V_d0() {
    vmStubsPH2Z1_5_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_5_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_5))) {
        vmStubsPH2Z1_5_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_5_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_inde_address0() {
    vmStubsPH2Z1_6_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_6_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_6_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_inde_d0() {
    vmStubsPH2Z1_6_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_6_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_6))) {
        vmStubsPH2Z1_6_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_phi_s_address0() {
    vmStubsPH2Z1_6_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_6_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_6_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_phi_s_d0() {
    vmStubsPH2Z1_6_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_6_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_6))) {
        vmStubsPH2Z1_6_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_pt_V_address0() {
    vmStubsPH2Z1_6_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_6_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_6_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_pt_V_d0() {
    vmStubsPH2Z1_6_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_6_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_6))) {
        vmStubsPH2Z1_6_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_r_V_address0() {
    vmStubsPH2Z1_6_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_6_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_6_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_r_V_d0() {
    vmStubsPH2Z1_6_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_6_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_6))) {
        vmStubsPH2Z1_6_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_z_V_address0() {
    vmStubsPH2Z1_6_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_6_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_6_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_6_z_V_d0() {
    vmStubsPH2Z1_6_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_6_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_6))) {
        vmStubsPH2Z1_6_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_6_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_inde_address0() {
    vmStubsPH2Z1_7_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_7_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_7_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_inde_d0() {
    vmStubsPH2Z1_7_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_7_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_7))) {
        vmStubsPH2Z1_7_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_phi_s_address0() {
    vmStubsPH2Z1_7_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_7_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_7_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_phi_s_d0() {
    vmStubsPH2Z1_7_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_7_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_7))) {
        vmStubsPH2Z1_7_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_pt_V_address0() {
    vmStubsPH2Z1_7_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_7_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_7_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_pt_V_d0() {
    vmStubsPH2Z1_7_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_7_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_7))) {
        vmStubsPH2Z1_7_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_r_V_address0() {
    vmStubsPH2Z1_7_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_7_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_7_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_r_V_d0() {
    vmStubsPH2Z1_7_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_7_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_7))) {
        vmStubsPH2Z1_7_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_z_V_address0() {
    vmStubsPH2Z1_7_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_7_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_7_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_7_z_V_d0() {
    vmStubsPH2Z1_7_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_7_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_7))) {
        vmStubsPH2Z1_7_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_7_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_inde_address0() {
    vmStubsPH2Z1_8_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_8_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_8_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_inde_d0() {
    vmStubsPH2Z1_8_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_8_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_8))) {
        vmStubsPH2Z1_8_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_phi_s_address0() {
    vmStubsPH2Z1_8_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_8_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_8_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_phi_s_d0() {
    vmStubsPH2Z1_8_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_8_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_8))) {
        vmStubsPH2Z1_8_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_pt_V_address0() {
    vmStubsPH2Z1_8_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_8_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_8_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_pt_V_d0() {
    vmStubsPH2Z1_8_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_8_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_8))) {
        vmStubsPH2Z1_8_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_r_V_address0() {
    vmStubsPH2Z1_8_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_8_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_8_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_r_V_d0() {
    vmStubsPH2Z1_8_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_8_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_8))) {
        vmStubsPH2Z1_8_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_z_V_address0() {
    vmStubsPH2Z1_8_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_8_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_8_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_8_z_V_d0() {
    vmStubsPH2Z1_8_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_8_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_8))) {
        vmStubsPH2Z1_8_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_8_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_inde_address0() {
    vmStubsPH2Z1_9_inde_address0 =  (sc_lv<6>) (newIndex75_fu_14804_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_9_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z1_9_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_inde_d0() {
    vmStubsPH2Z1_9_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z1_9_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_101_fu_14789_p4.read(), ap_const_lv5_9))) {
        vmStubsPH2Z1_9_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_phi_s_address0() {
    vmStubsPH2Z1_9_phi_s_address0 =  (sc_lv<6>) (newIndex69_fu_16284_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_9_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_9_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_phi_s_d0() {
    vmStubsPH2Z1_9_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z1_9_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_98_reg_18263.read(), ap_const_lv5_9))) {
        vmStubsPH2Z1_9_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_pt_V_address0() {
    vmStubsPH2Z1_9_pt_V_address0 =  (sc_lv<6>) (newIndex73_fu_16338_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_9_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_9_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_pt_V_d0() {
    vmStubsPH2Z1_9_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z1_9_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_100_reg_18271.read(), ap_const_lv5_9))) {
        vmStubsPH2Z1_9_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_r_V_address0() {
    vmStubsPH2Z1_9_r_V_address0 =  (sc_lv<6>) (newIndex71_fu_16311_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_9_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_9_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_r_V_d0() {
    vmStubsPH2Z1_9_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z1_9_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_99_reg_18267.read(), ap_const_lv5_9))) {
        vmStubsPH2Z1_9_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_z_V_address0() {
    vmStubsPH2Z1_9_z_V_address0 =  (sc_lv<6>) (newIndex67_fu_16257_p1.read());
}

void VMRouter::thread_vmStubsPH2Z1_9_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z1_9_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z1_9_z_V_d0() {
    vmStubsPH2Z1_9_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z1_9_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,5,5>(tmp_97_reg_18259.read(), ap_const_lv5_9))) {
        vmStubsPH2Z1_9_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z1_9_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_inde_address0() {
    vmStubsPH2Z2_0_inde_address0 =  (sc_lv<6>) (newIndex35_fu_15288_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_0_inde_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z2_0_inde_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_inde_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_inde_d0() {
    vmStubsPH2Z2_0_inde_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z2_0_inde_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_81_fu_15273_p4.read(), ap_const_lv5_0))) {
        vmStubsPH2Z2_0_inde_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_inde_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_phi_s_address0() {
    vmStubsPH2Z2_0_phi_s_address0 =  (sc_lv<6>) (newIndex29_fu_16716_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_0_phi_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_0_phi_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_phi_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_phi_s_d0() {
    vmStubsPH2Z2_0_phi_s_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z2_0_phi_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_78_reg_18375.read(), ap_const_lv5_0))) {
        vmStubsPH2Z2_0_phi_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_phi_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_pt_V_address0() {
    vmStubsPH2Z2_0_pt_V_address0 =  (sc_lv<6>) (newIndex33_fu_16770_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_0_pt_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_0_pt_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_pt_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_pt_V_d0() {
    vmStubsPH2Z2_0_pt_V_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z2_0_pt_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_80_reg_18383.read(), ap_const_lv5_0))) {
        vmStubsPH2Z2_0_pt_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_pt_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_r_V_address0() {
    vmStubsPH2Z2_0_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_16743_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_0_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_0_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_r_V_d0() {
    vmStubsPH2Z2_0_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z2_0_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_79_reg_18379.read(), ap_const_lv5_0))) {
        vmStubsPH2Z2_0_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_z_V_address0() {
    vmStubsPH2Z2_0_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_16689_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_0_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_0_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_0_z_V_d0() {
    vmStubsPH2Z2_0_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z2_0_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_72_reg_18371.read(), ap_const_lv5_0))) {
        vmStubsPH2Z2_0_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_0_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_ind_address0() {
    vmStubsPH2Z2_10_ind_address0 =  (sc_lv<6>) (newIndex35_fu_15288_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_10_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z2_10_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_ind_d0() {
    vmStubsPH2Z2_10_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z2_10_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_81_fu_15273_p4.read(), ap_const_lv5_A))) {
        vmStubsPH2Z2_10_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_phi_address0() {
    vmStubsPH2Z2_10_phi_address0 =  (sc_lv<6>) (newIndex29_fu_16716_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_10_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_10_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_phi_d0() {
    vmStubsPH2Z2_10_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z2_10_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_78_reg_18375.read(), ap_const_lv5_A))) {
        vmStubsPH2Z2_10_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_pt_s_address0() {
    vmStubsPH2Z2_10_pt_s_address0 =  (sc_lv<6>) (newIndex33_fu_16770_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_10_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_10_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_pt_s_d0() {
    vmStubsPH2Z2_10_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z2_10_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_80_reg_18383.read(), ap_const_lv5_A))) {
        vmStubsPH2Z2_10_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_r_V_address0() {
    vmStubsPH2Z2_10_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_16743_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_10_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_10_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_r_V_d0() {
    vmStubsPH2Z2_10_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z2_10_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_79_reg_18379.read(), ap_const_lv5_A))) {
        vmStubsPH2Z2_10_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_z_V_address0() {
    vmStubsPH2Z2_10_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_16689_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_10_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_10_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_10_z_V_d0() {
    vmStubsPH2Z2_10_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z2_10_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_72_reg_18371.read(), ap_const_lv5_A))) {
        vmStubsPH2Z2_10_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_10_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_ind_address0() {
    vmStubsPH2Z2_11_ind_address0 =  (sc_lv<6>) (newIndex35_fu_15288_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_11_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z2_11_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_ind_d0() {
    vmStubsPH2Z2_11_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z2_11_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_81_fu_15273_p4.read(), ap_const_lv5_B))) {
        vmStubsPH2Z2_11_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_phi_address0() {
    vmStubsPH2Z2_11_phi_address0 =  (sc_lv<6>) (newIndex29_fu_16716_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_11_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_11_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_phi_d0() {
    vmStubsPH2Z2_11_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z2_11_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_78_reg_18375.read(), ap_const_lv5_B))) {
        vmStubsPH2Z2_11_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_pt_s_address0() {
    vmStubsPH2Z2_11_pt_s_address0 =  (sc_lv<6>) (newIndex33_fu_16770_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_11_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_11_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_pt_s_d0() {
    vmStubsPH2Z2_11_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z2_11_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_80_reg_18383.read(), ap_const_lv5_B))) {
        vmStubsPH2Z2_11_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_r_V_address0() {
    vmStubsPH2Z2_11_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_16743_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_11_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_11_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_r_V_d0() {
    vmStubsPH2Z2_11_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z2_11_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_79_reg_18379.read(), ap_const_lv5_B))) {
        vmStubsPH2Z2_11_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_z_V_address0() {
    vmStubsPH2Z2_11_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_16689_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_11_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_11_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_11_z_V_d0() {
    vmStubsPH2Z2_11_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z2_11_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_72_reg_18371.read(), ap_const_lv5_B))) {
        vmStubsPH2Z2_11_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_11_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_ind_address0() {
    vmStubsPH2Z2_12_ind_address0 =  (sc_lv<6>) (newIndex35_fu_15288_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_12_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z2_12_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_ind_d0() {
    vmStubsPH2Z2_12_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z2_12_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_81_fu_15273_p4.read(), ap_const_lv5_C))) {
        vmStubsPH2Z2_12_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_phi_address0() {
    vmStubsPH2Z2_12_phi_address0 =  (sc_lv<6>) (newIndex29_fu_16716_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_12_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_12_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_phi_d0() {
    vmStubsPH2Z2_12_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z2_12_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_78_reg_18375.read(), ap_const_lv5_C))) {
        vmStubsPH2Z2_12_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_pt_s_address0() {
    vmStubsPH2Z2_12_pt_s_address0 =  (sc_lv<6>) (newIndex33_fu_16770_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_12_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_12_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_pt_s_d0() {
    vmStubsPH2Z2_12_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z2_12_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_80_reg_18383.read(), ap_const_lv5_C))) {
        vmStubsPH2Z2_12_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_r_V_address0() {
    vmStubsPH2Z2_12_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_16743_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_12_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_12_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_r_V_d0() {
    vmStubsPH2Z2_12_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z2_12_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_79_reg_18379.read(), ap_const_lv5_C))) {
        vmStubsPH2Z2_12_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_z_V_address0() {
    vmStubsPH2Z2_12_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_16689_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_12_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_12_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_12_z_V_d0() {
    vmStubsPH2Z2_12_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z2_12_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_72_reg_18371.read(), ap_const_lv5_C))) {
        vmStubsPH2Z2_12_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_12_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_ind_address0() {
    vmStubsPH2Z2_13_ind_address0 =  (sc_lv<6>) (newIndex35_fu_15288_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_13_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z2_13_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_ind_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_ind_d0() {
    vmStubsPH2Z2_13_ind_d0 = op2_V_read_assign_reg_13380.read();
}

void VMRouter::thread_vmStubsPH2Z2_13_ind_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,5,5>(tmp_81_fu_15273_p4.read(), ap_const_lv5_D))) {
        vmStubsPH2Z2_13_ind_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_ind_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_phi_address0() {
    vmStubsPH2Z2_13_phi_address0 =  (sc_lv<6>) (newIndex29_fu_16716_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_13_phi_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_13_phi_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_phi_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_phi_d0() {
    vmStubsPH2Z2_13_phi_d0 = curPhi_V_reg_17964.read().range(11, 9);
}

void VMRouter::thread_vmStubsPH2Z2_13_phi_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_78_reg_18375.read(), ap_const_lv5_D))) {
        vmStubsPH2Z2_13_phi_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_phi_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_pt_s_address0() {
    vmStubsPH2Z2_13_pt_s_address0 =  (sc_lv<6>) (newIndex33_fu_16770_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_13_pt_s_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_13_pt_s_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_pt_s_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_pt_s_d0() {
    vmStubsPH2Z2_13_pt_s_d0 = redPt_V_reg_18012.read();
}

void VMRouter::thread_vmStubsPH2Z2_13_pt_s_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_80_reg_18383.read(), ap_const_lv5_D))) {
        vmStubsPH2Z2_13_pt_s_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_pt_s_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_r_V_address0() {
    vmStubsPH2Z2_13_r_V_address0 =  (sc_lv<6>) (newIndex31_fu_16743_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_13_r_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_13_r_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_r_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_r_V_d0() {
    vmStubsPH2Z2_13_r_V_d0 = curR_V_reg_17988.read().range(6, 5);
}

void VMRouter::thread_vmStubsPH2Z2_13_r_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_79_reg_18379.read(), ap_const_lv5_D))) {
        vmStubsPH2Z2_13_r_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_r_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_z_V_address0() {
    vmStubsPH2Z2_13_z_V_address0 =  (sc_lv<6>) (newIndex27_fu_16689_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_13_z_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()))) {
        vmStubsPH2Z2_13_z_V_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_z_V_ce0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_13_z_V_d0() {
    vmStubsPH2Z2_13_z_V_d0 = curZ_V_reg_17940.read().range(8, 5);
}

void VMRouter::thread_vmStubsPH2Z2_13_z_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_reg_pp0_iter1_tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,2,2>(routePhi_V_reg_18187.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_reg_18191.read()) && 
         esl_seteq<1,5,5>(tmp_72_reg_18371.read(), ap_const_lv5_D))) {
        vmStubsPH2Z2_13_z_V_we0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_13_z_V_we0 = ap_const_logic_0;
    }
}

void VMRouter::thread_vmStubsPH2Z2_14_ind_address0() {
    vmStubsPH2Z2_14_ind_address0 =  (sc_lv<6>) (newIndex35_fu_15288_p1.read());
}

void VMRouter::thread_vmStubsPH2Z2_14_ind_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        vmStubsPH2Z2_14_ind_ce0 = ap_const_logic_1;
    } else {
        vmStubsPH2Z2_14_ind_ce0 = ap_const_logic_0;
    }
}

}

