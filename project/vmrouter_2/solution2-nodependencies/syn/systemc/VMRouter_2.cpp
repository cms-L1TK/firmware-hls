#include "VMRouter.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouter::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp0_exit_iter0_state2.read()))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter1 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0)) {
            if (esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp0_exit_iter0_state2.read())) {
                ap_enable_reg_pp0_iter1 = (ap_condition_pp0_exit_iter0_state2.read() ^ ap_const_logic_1);
            } else if (esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1)) {
                ap_enable_reg_pp0_iter1 = ap_enable_reg_pp0_iter0.read();
            }
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp0_iter2 = ap_enable_reg_pp0_iter1.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            ap_enable_reg_pp0_iter2 = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(tmp_198_fu_14003_p3.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(tmp_4_fu_14021_p2.read(), ap_const_lv1_1))) {
        i_reg_13544 = i_1_fu_14266_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        i_reg_13544 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0))) {
        nPH1Z1_V_fu_2090 = tmp_74_fu_14951_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH1Z1_V_fu_2090 = nPH1Z1_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH1Z2_V_fu_2074 = tmp_73_fu_15435_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH1Z2_V_fu_2074 = nPH1Z2_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1))) {
        nPH2Z1_V_fu_2086 = tmp_75_fu_14830_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH2Z1_V_fu_2086 = nPH2Z1_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH2Z2_V_fu_2070 = tmp_21_fu_15314_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH2Z2_V_fu_2070 = nPH2Z2_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2))) {
        nPH3Z1_V_fu_2082 = tmp_76_fu_14709_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH3Z1_V_fu_2082 = nPH3Z1_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH3Z2_V_fu_2066 = tmp_23_fu_15193_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH3Z2_V_fu_2066 = nPH3Z2_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3))) {
        nPH4Z1_V_fu_2078 = tmp_77_fu_14588_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH4Z1_V_fu_2078 = nPH4Z1_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH4Z2_V_fu_2062 = tmp_25_fu_15072_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        nPH4Z2_V_fu_2062 = nPH4Z2_V_read.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(tmp_198_reg_17498.read(), ap_const_lv1_0))) {
        op2_V_read_assign_reg_13380 = index_V_reg_17502.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        op2_V_read_assign_reg_13380 = ap_const_lv6_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0))) {
        ap_reg_pp0_iter1_tmp_199_reg_17511 = tmp_199_reg_17511.read();
        ap_reg_pp0_iter1_tmp_2_reg_17919 = tmp_2_reg_17919.read();
        ap_reg_pp0_iter1_tmp_3_reg_17923 = tmp_3_reg_17923.read();
        ap_reg_pp0_iter1_tmp_4_reg_17507 = tmp_4_reg_17507.read();
        ap_reg_pp0_iter1_tmp_5_reg_17927 = tmp_5_reg_17927.read();
        ap_reg_pp0_iter1_tmp_6_reg_17931 = tmp_6_reg_17931.read();
        tmp_198_reg_17498 = i_reg_13544.read().range(6, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_198_fu_14003_p3.read(), ap_const_lv1_0) && esl_seteq<1,1,1>(tmp_4_fu_14021_p2.read(), ap_const_lv1_1))) {
        arrayNo1_reg_17524 = sum1_fu_14077_p2.read().range(10, 6);
        arrayNo2_reg_17529 = sum2_fu_14120_p2.read().range(10, 6);
        arrayNo3_reg_17534 = sum3_fu_14163_p2.read().range(10, 6);
        arrayNo_reg_17519 = sum_fu_14034_p2.read().range(10, 6);
        tmp_199_reg_17511 = tmp_199_fu_14030_p1.read();
        tmp_2_reg_17919 = sum4_fu_14206_p2.read().range(10, 6);
        tmp_3_reg_17923 = sum5_fu_14221_p2.read().range(10, 6);
        tmp_5_reg_17927 = sum6_fu_14236_p2.read().range(10, 6);
        tmp_6_reg_17931 = sum7_fu_14251_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1))) {
        curPhi_V_reg_17964 = curPhi_V_fu_14328_p21.read();
        curR_V_reg_17988 = curR_V_fu_14372_p21.read();
        curZ_V_reg_17940 = curZ_V_fu_14284_p21.read();
        redPt_V_reg_18012 = redPt_V_fu_14416_p21.read();
        routePhi_V_reg_18187 = curPhi_V_fu_14328_p21.read().range(13, 12);
        routeZ_V_reg_18191 = curZ_V_fu_14284_p21.read().range(9, 9);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()))) {
        index_V_reg_17502 = index_V_fu_14011_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0))) {
        nPH1Z1_V_load_2_reg_18279 = nPH1Z1_V_fu_2090.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH1Z2_V_load_2_reg_18391 = nPH1Z2_V_fu_2074.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1))) {
        nPH2Z1_V_load_2_reg_18251 = nPH2Z1_V_fu_2086.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH2Z2_V_load_2_reg_18363 = nPH2Z2_V_fu_2070.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2))) {
        nPH3Z1_V_load_2_reg_18223 = nPH3Z1_V_fu_2082.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH3Z2_V_load_2_reg_18335 = nPH3Z2_V_fu_2066.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3))) {
        nPH4Z1_V_load_2_reg_18195 = nPH4Z1_V_fu_2078.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        nPH4Z2_V_load_2_reg_18307 = nPH4Z2_V_fu_2062.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1))) {
        tmp_100_reg_18271 = sum36_fu_14769_p2.read().range(10, 6);
        tmp_97_reg_18259 = sum33_fu_14724_p2.read().range(10, 6);
        tmp_98_reg_18263 = sum34_fu_14739_p2.read().range(10, 6);
        tmp_99_reg_18267 = sum35_fu_14754_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2))) {
        tmp_102_reg_18231 = sum38_fu_14603_p2.read().range(10, 6);
        tmp_103_reg_18235 = sum39_fu_14618_p2.read().range(10, 6);
        tmp_104_reg_18239 = sum40_fu_14633_p2.read().range(10, 6);
        tmp_105_reg_18243 = sum41_fu_14648_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3))) {
        tmp_107_reg_18203 = sum43_fu_14482_p2.read().range(10, 6);
        tmp_108_reg_18207 = sum44_fu_14497_p2.read().range(10, 6);
        tmp_109_reg_18211 = sum45_fu_14512_p2.read().range(10, 6);
        tmp_148_reg_18215 = sum46_fu_14527_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        tmp_10_reg_18411 = sum11_fu_15374_p2.read().range(10, 6);
        tmp_7_reg_18399 = sum8_fu_15329_p2.read().range(10, 6);
        tmp_8_reg_18403 = sum9_fu_15344_p2.read().range(10, 6);
        tmp_9_reg_18407 = sum10_fu_15359_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        tmp_151_reg_17263 = tmp_151_fu_13775_p1.read();
        tmp_152_reg_17268 = tmp_152_fu_13779_p1.read();
        tmp_153_reg_17273 = tmp_153_fu_13783_p1.read();
        tmp_154_reg_17278 = tmp_154_fu_13787_p1.read();
        tmp_155_reg_17283 = tmp_155_fu_13791_p1.read();
        tmp_156_reg_17288 = tmp_156_fu_13795_p1.read();
        tmp_157_reg_17293 = tmp_157_fu_13799_p1.read();
        tmp_158_reg_17298 = tmp_158_fu_13803_p1.read();
        tmp_159_reg_17303 = tmp_159_fu_13807_p1.read();
        tmp_160_reg_17308 = tmp_160_fu_13811_p1.read();
        tmp_161_reg_17313 = tmp_161_fu_13815_p1.read();
        tmp_162_reg_17318 = tmp_162_fu_13819_p1.read();
        tmp_163_reg_17323 = tmp_163_fu_13823_p1.read();
        tmp_164_reg_17328 = tmp_164_fu_13827_p1.read();
        tmp_165_reg_17333 = tmp_165_fu_13831_p1.read();
        tmp_166_reg_17338 = tmp_166_fu_13835_p1.read();
        tmp_167_reg_17343 = tmp_167_fu_13839_p1.read();
        tmp_168_reg_17348 = tmp_168_fu_13843_p1.read();
        tmp_169_reg_17353 = tmp_169_fu_13847_p1.read();
        tmp_170_reg_17358 = tmp_170_fu_13851_p1.read();
        tmp_171_reg_17363 = tmp_171_fu_13855_p1.read();
        tmp_172_reg_17368 = tmp_172_fu_13859_p1.read();
        tmp_173_reg_17373 = tmp_173_fu_13863_p1.read();
        tmp_174_reg_17378 = tmp_174_fu_13867_p1.read();
        tmp_175_reg_17383 = tmp_175_fu_13871_p1.read();
        tmp_176_reg_17388 = tmp_176_fu_13875_p1.read();
        tmp_177_reg_17393 = tmp_177_fu_13879_p1.read();
        tmp_178_reg_17398 = tmp_178_fu_13883_p1.read();
        tmp_179_reg_17403 = tmp_179_fu_13887_p1.read();
        tmp_180_reg_17408 = tmp_180_fu_13891_p1.read();
        tmp_181_reg_17413 = tmp_181_fu_13895_p1.read();
        tmp_182_reg_17418 = tmp_182_fu_13899_p1.read();
        tmp_183_reg_17423 = tmp_183_fu_13903_p1.read();
        tmp_184_reg_17428 = tmp_184_fu_13907_p1.read();
        tmp_185_reg_17433 = tmp_185_fu_13911_p1.read();
        tmp_186_reg_17438 = tmp_186_fu_13915_p1.read();
        tmp_187_reg_17443 = tmp_187_fu_13919_p1.read();
        tmp_188_reg_17448 = tmp_188_fu_13923_p1.read();
        tmp_189_reg_17453 = tmp_189_fu_13927_p1.read();
        tmp_190_reg_17458 = tmp_190_fu_13931_p1.read();
        tmp_191_reg_17463 = tmp_191_fu_13935_p1.read();
        tmp_192_reg_17468 = tmp_192_fu_13939_p1.read();
        tmp_193_reg_17473 = tmp_193_fu_13943_p1.read();
        tmp_194_reg_17478 = tmp_194_fu_13947_p1.read();
        tmp_195_reg_17483 = tmp_195_fu_13951_p1.read();
        tmp_196_reg_17488 = tmp_196_fu_13955_p1.read();
        tmp_197_reg_17493 = tmp_197_fu_13959_p1.read();
        tmp_20_reg_17023 = tmp_20_fu_13583_p1.read();
        tmp_22_reg_17028 = tmp_22_fu_13587_p1.read();
        tmp_24_reg_17033 = tmp_24_fu_13591_p1.read();
        tmp_27_reg_17038 = tmp_27_fu_13595_p1.read();
        tmp_28_reg_17043 = tmp_28_fu_13599_p1.read();
        tmp_29_reg_17048 = tmp_29_fu_13603_p1.read();
        tmp_30_reg_17053 = tmp_30_fu_13607_p1.read();
        tmp_31_reg_17058 = tmp_31_fu_13611_p1.read();
        tmp_32_reg_17063 = tmp_32_fu_13615_p1.read();
        tmp_33_reg_17068 = tmp_33_fu_13619_p1.read();
        tmp_34_reg_17073 = tmp_34_fu_13623_p1.read();
        tmp_35_reg_17078 = tmp_35_fu_13627_p1.read();
        tmp_36_reg_17083 = tmp_36_fu_13631_p1.read();
        tmp_37_reg_17088 = tmp_37_fu_13635_p1.read();
        tmp_38_reg_17093 = tmp_38_fu_13639_p1.read();
        tmp_39_reg_17098 = tmp_39_fu_13643_p1.read();
        tmp_40_reg_17103 = tmp_40_fu_13647_p1.read();
        tmp_41_reg_17108 = tmp_41_fu_13651_p1.read();
        tmp_42_reg_17113 = tmp_42_fu_13655_p1.read();
        tmp_43_reg_17118 = tmp_43_fu_13659_p1.read();
        tmp_44_reg_17123 = tmp_44_fu_13663_p1.read();
        tmp_45_reg_17128 = tmp_45_fu_13667_p1.read();
        tmp_46_reg_17133 = tmp_46_fu_13671_p1.read();
        tmp_47_reg_17138 = tmp_47_fu_13675_p1.read();
        tmp_48_reg_17143 = tmp_48_fu_13679_p1.read();
        tmp_49_reg_17148 = tmp_49_fu_13683_p1.read();
        tmp_50_reg_17153 = tmp_50_fu_13687_p1.read();
        tmp_51_reg_17158 = tmp_51_fu_13691_p1.read();
        tmp_52_reg_17163 = tmp_52_fu_13695_p1.read();
        tmp_53_reg_17168 = tmp_53_fu_13699_p1.read();
        tmp_54_reg_17173 = tmp_54_fu_13703_p1.read();
        tmp_55_reg_17178 = tmp_55_fu_13707_p1.read();
        tmp_56_reg_17183 = tmp_56_fu_13711_p1.read();
        tmp_57_reg_17188 = tmp_57_fu_13715_p1.read();
        tmp_58_reg_17193 = tmp_58_fu_13719_p1.read();
        tmp_59_reg_17198 = tmp_59_fu_13723_p1.read();
        tmp_60_reg_17203 = tmp_60_fu_13727_p1.read();
        tmp_61_reg_17208 = tmp_61_fu_13731_p1.read();
        tmp_62_reg_17213 = tmp_62_fu_13735_p1.read();
        tmp_63_reg_17218 = tmp_63_fu_13739_p1.read();
        tmp_64_reg_17223 = tmp_64_fu_13743_p1.read();
        tmp_65_reg_17228 = tmp_65_fu_13747_p1.read();
        tmp_66_reg_17233 = tmp_66_fu_13751_p1.read();
        tmp_67_reg_17238 = tmp_67_fu_13755_p1.read();
        tmp_68_reg_17243 = tmp_68_fu_13759_p1.read();
        tmp_69_reg_17248 = tmp_69_fu_13763_p1.read();
        tmp_70_reg_17253 = tmp_70_fu_13767_p1.read();
        tmp_71_reg_17258 = tmp_71_fu_13771_p1.read();
        tmp_reg_17018 = tmp_fu_13579_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_198_fu_14003_p3.read(), ap_const_lv1_0))) {
        tmp_4_reg_17507 = tmp_4_fu_14021_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_1) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        tmp_72_reg_18371 = sum13_fu_15208_p2.read().range(10, 6);
        tmp_78_reg_18375 = sum14_fu_15223_p2.read().range(10, 6);
        tmp_79_reg_18379 = sum15_fu_15238_p2.read().range(10, 6);
        tmp_80_reg_18383 = sum16_fu_15253_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_2) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        tmp_82_reg_18343 = sum18_fu_15087_p2.read().range(10, 6);
        tmp_83_reg_18347 = sum19_fu_15102_p2.read().range(10, 6);
        tmp_84_reg_18351 = sum20_fu_15117_p2.read().range(10, 6);
        tmp_85_reg_18355 = sum21_fu_15132_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_3) && esl_seteq<1,1,1>(ap_const_lv1_1, routeZ_V_fu_14470_p3.read()))) {
        tmp_87_reg_18315 = sum23_fu_14966_p2.read().range(10, 6);
        tmp_88_reg_18319 = sum24_fu_14981_p2.read().range(10, 6);
        tmp_89_reg_18323 = sum25_fu_14996_p2.read().range(10, 6);
        tmp_90_reg_18327 = sum26_fu_15011_p2.read().range(10, 6);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_4_reg_17507.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_14470_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_14460_p4.read(), ap_const_lv2_0))) {
        tmp_92_reg_18287 = sum28_fu_14845_p2.read().range(10, 6);
        tmp_93_reg_18291 = sum29_fu_14860_p2.read().range(10, 6);
        tmp_94_reg_18295 = sum30_fu_14875_p2.read().range(10, 6);
        tmp_95_reg_18299 = sum31_fu_14890_p2.read().range(10, 6);
    }
}

void VMRouter::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((!(esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_tran2to5_state2.read()) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else if (((esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
  esl_seteq<1,1,1>(ap_block_pp0_stage0_flag00011011.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(ap_const_boolean_1, ap_predicate_tran2to5_state2.read()) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_state5;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm = "XXX";
            break;
    }
}

}

