#include "VMRouterDispatcher.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouterDispatcher::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_st1_fsm_0;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp0_it0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
             (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) || 
              (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && 
               esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read()))))) {
            ap_reg_ppiten_pp0_it0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                    !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
            ap_reg_ppiten_pp0_it0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp0_it1 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
             !(!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) || (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read()))))) {
            ap_reg_ppiten_pp0_it1 = ap_const_logic_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                     !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
                     (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) || 
                      (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && 
                       esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read())))))) {
            ap_reg_ppiten_pp0_it1 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp0_it2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp0_it2 = ap_reg_ppiten_pp0_it1.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp0_it3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp0_it3 = ap_reg_ppiten_pp0_it2.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                    !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
            ap_reg_ppiten_pp0_it3 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp1_it0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
             (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) || 
              (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && 
               esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read()))))) {
            ap_reg_ppiten_pp1_it0 = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read())) {
            ap_reg_ppiten_pp1_it0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp1_it1 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
             !(!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) || (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read()))))) {
            ap_reg_ppiten_pp1_it1 = ap_const_logic_1;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read()) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
                     (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) || 
                      (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && 
                       esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read())))))) {
            ap_reg_ppiten_pp1_it1 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp1_it2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp1_it2 = ap_reg_ppiten_pp1_it1.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp1_it3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp1_it3 = ap_reg_ppiten_pp1_it2.read();
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read())) {
            ap_reg_ppiten_pp1_it3 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp2_it0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
             (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) || 
              (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && 
               esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read()))))) {
            ap_reg_ppiten_pp2_it0 = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st11_fsm_4.read())) {
            ap_reg_ppiten_pp2_it0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp2_it1 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
             !(!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) || (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read()))))) {
            ap_reg_ppiten_pp2_it1 = ap_const_logic_1;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st11_fsm_4.read()) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
                     (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) || 
                      (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && 
                       esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read())))))) {
            ap_reg_ppiten_pp2_it1 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp2_it2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp2_it2 = ap_reg_ppiten_pp2_it1.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp2_it3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp2_it3 = ap_reg_ppiten_pp2_it2.read();
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st11_fsm_4.read())) {
            ap_reg_ppiten_pp2_it3 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp3_it0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
             (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) || 
              (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && 
               esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read()))))) {
            ap_reg_ppiten_pp3_it0 = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st16_fsm_6.read())) {
            ap_reg_ppiten_pp3_it0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp3_it1 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
             !(!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) || (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read()))))) {
            ap_reg_ppiten_pp3_it1 = ap_const_logic_1;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st16_fsm_6.read()) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
                     (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) || 
                      (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && 
                       esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read())))))) {
            ap_reg_ppiten_pp3_it1 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp3_it2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp3_it2 = ap_reg_ppiten_pp3_it1.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp3_it3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp3_it3 = ap_reg_ppiten_pp3_it2.read();
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st16_fsm_6.read())) {
            ap_reg_ppiten_pp3_it3 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp4_it0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
             (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) || 
              (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && 
               esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read()))))) {
            ap_reg_ppiten_pp4_it0 = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_8.read())) {
            ap_reg_ppiten_pp4_it0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp4_it1 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
             !(!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) || (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read()))))) {
            ap_reg_ppiten_pp4_it1 = ap_const_logic_1;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_8.read()) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
                     (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) || 
                      (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && 
                       esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read())))))) {
            ap_reg_ppiten_pp4_it1 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp4_it2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp4_it2 = ap_reg_ppiten_pp4_it1.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp4_it3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_true, ap_true)) {
            ap_reg_ppiten_pp4_it3 = ap_reg_ppiten_pp4_it2.read();
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_8.read())) {
            ap_reg_ppiten_pp4_it3 = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read()))) {
        i_0_i1_reg_4094 = i_fu_4482_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        i_0_i1_reg_4094 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read()))) {
        i_0_i2_reg_4117 = i_1_fu_4695_p2.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read())) {
        i_0_i2_reg_4117 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read()))) {
        i_0_i3_reg_4140 = i_2_fu_4908_p2.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st11_fsm_4.read())) {
        i_0_i3_reg_4140 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read()))) {
        i_0_i6_reg_4163 = i_3_fu_5121_p2.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st16_fsm_6.read())) {
        i_0_i6_reg_4163 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read()))) {
        i_0_i_reg_4186 = i_4_fu_5334_p2.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_8.read())) {
        i_0_i_reg_4186 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_reg_5625.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_reg_5616.read()))) {
        p_0_reg_4105 = index_V_1_reg_5620.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st6_fsm_2.read())) {
        p_0_reg_4105 = ap_const_lv6_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_reg_5720.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_reg_5711.read()))) {
        p_2_reg_4128 = index_V_2_reg_5715.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st11_fsm_4.read())) {
        p_2_reg_4128 = ap_const_lv6_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_reg_5815.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_reg_5806.read()))) {
        p_4_reg_4151 = index_V_3_reg_5810.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st16_fsm_6.read())) {
        p_4_reg_4151 = ap_const_lv6_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_reg_5910.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_reg_5901.read()))) {
        p_7_reg_4174 = index_V_4_reg_5905.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_8.read())) {
        p_7_reg_4174 = ap_const_lv6_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()) && 
         !esl_seteq<1,1,1>(tmp_1_reg_5530.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, tmp_reg_5521.read()))) {
        p_s_reg_4082 = index_V_reg_5525.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        p_s_reg_4082 = ap_const_lv6_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read())) {
        ap_reg_ppstg_p_0_reg_4105_pp1_iter1 = p_0_reg_4105.read();
        ap_reg_ppstg_p_6_reg_5629_pp1_iter1 = p_6_reg_5629.read();
        ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1 = tmp_s_reg_5625.read();
        tmp_13_reg_5616 = i_0_i2_reg_4117.read().range(6, 6);
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read())) {
        ap_reg_ppstg_p_1_reg_5534_pp0_iter1 = p_1_reg_5534.read();
        ap_reg_ppstg_p_s_reg_4082_pp0_iter1 = p_s_reg_4082.read();
        ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1 = tmp_1_reg_5530.read();
        tmp_reg_5521 = i_0_i1_reg_4094.read().range(6, 6);
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read())) {
        ap_reg_ppstg_p_2_reg_4128_pp2_iter1 = p_2_reg_4128.read();
        ap_reg_ppstg_p_3_reg_5724_pp2_iter1 = p_3_reg_5724.read();
        ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1 = tmp_15_reg_5720.read();
        tmp_35_reg_5711 = i_0_i3_reg_4140.read().range(6, 6);
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read())) {
        ap_reg_ppstg_p_4_reg_4151_pp3_iter1 = p_4_reg_4151.read();
        ap_reg_ppstg_p_5_reg_5819_pp3_iter1 = p_5_reg_5819.read();
        ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1 = tmp_26_reg_5815.read();
        tmp_55_reg_5806 = i_0_i6_reg_4163.read().range(6, 6);
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read())) {
        ap_reg_ppstg_p_7_reg_4174_pp4_iter1 = p_7_reg_4174.read();
        ap_reg_ppstg_p_8_reg_5914_pp4_iter1 = p_8_reg_5914.read();
        ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1 = tmp_37_reg_5910.read();
        tmp_57_reg_5901 = i_0_i_reg_4186.read().range(6, 6);
    }
    if (esl_seteq<1,1,1>(ap_true, ap_true)) {
        ap_reg_ppstg_routePhi_V_1_reg_5698_pp1_iter2 = routePhi_V_1_reg_5698.read();
        ap_reg_ppstg_routePhi_V_2_reg_5793_pp2_iter2 = routePhi_V_2_reg_5793.read();
        ap_reg_ppstg_routePhi_V_3_reg_5888_pp3_iter2 = routePhi_V_3_reg_5888.read();
        ap_reg_ppstg_routePhi_V_4_reg_5983_pp4_iter2 = routePhi_V_4_reg_5983.read();
        ap_reg_ppstg_routePhi_V_reg_5603_pp0_iter2 = routePhi_V_reg_5603.read();
        ap_reg_ppstg_routeZ_V_1_reg_5702_pp1_iter2 = routeZ_V_1_reg_5702.read();
        ap_reg_ppstg_routeZ_V_2_reg_5797_pp2_iter2 = routeZ_V_2_reg_5797.read();
        ap_reg_ppstg_routeZ_V_3_reg_5892_pp3_iter2 = routeZ_V_3_reg_5892.read();
        ap_reg_ppstg_routeZ_V_4_reg_5987_pp4_iter2 = routeZ_V_4_reg_5987.read();
        ap_reg_ppstg_routeZ_V_reg_5607_pp0_iter2 = routeZ_V_reg_5607.read();
        ap_reg_ppstg_tmp_15_reg_5720_pp2_iter2 = ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read();
        ap_reg_ppstg_tmp_1_reg_5530_pp0_iter2 = ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read();
        ap_reg_ppstg_tmp_26_reg_5815_pp3_iter2 = ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read();
        ap_reg_ppstg_tmp_37_reg_5910_pp4_iter2 = ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read();
        ap_reg_ppstg_tmp_s_reg_5625_pp1_iter2 = ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_reg_5625.read()))) {
        curPhi_V_1_reg_5667 = stubsInLayer_1_phi_V_q0.read();
        curR_V_1_reg_5672 = stubsInLayer_1_r_V_q0.read();
        curZ_V_1_reg_5662 = stubsInLayer_1_z_V_q0.read();
        redPhi_V_1_reg_5688 = stubsInLayer_1_phi_V_q0.read().range(11, 9);
        redPt_V_1_reg_5677 = stubsInLayer_1_pt_V_q0.read();
        redR_V_1_reg_5693 = stubsInLayer_1_r_V_q0.read().range(6, 5);
        redZ_V_1_reg_5683 = stubsInLayer_1_z_V_q0.read().range(8, 5);
        routePhi_V_1_reg_5698 = stubsInLayer_1_phi_V_q0.read().range(13, 12);
        routeZ_V_1_reg_5702 = stubsInLayer_1_z_V_q0.read().range(9, 9);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_reg_5720.read()))) {
        curPhi_V_2_reg_5762 = stubsInLayer_2_phi_V_q0.read();
        curR_V_2_reg_5767 = stubsInLayer_2_r_V_q0.read();
        curZ_V_2_reg_5757 = stubsInLayer_2_z_V_q0.read();
        redPhi_V_2_reg_5783 = stubsInLayer_2_phi_V_q0.read().range(11, 9);
        redPt_V_2_reg_5772 = stubsInLayer_2_pt_V_q0.read();
        redR_V_2_reg_5788 = stubsInLayer_2_r_V_q0.read().range(6, 5);
        redZ_V_2_reg_5778 = stubsInLayer_2_z_V_q0.read().range(8, 5);
        routePhi_V_2_reg_5793 = stubsInLayer_2_phi_V_q0.read().range(13, 12);
        routeZ_V_2_reg_5797 = stubsInLayer_2_z_V_q0.read().range(9, 9);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_reg_5815.read()))) {
        curPhi_V_3_reg_5857 = stubsInLayer_3_phi_V_q0.read();
        curR_V_3_reg_5862 = stubsInLayer_3_r_V_q0.read();
        curZ_V_3_reg_5852 = stubsInLayer_3_z_V_q0.read();
        redPhi_V_3_reg_5878 = stubsInLayer_3_phi_V_q0.read().range(11, 9);
        redPt_V_3_reg_5867 = stubsInLayer_3_pt_V_q0.read();
        redR_V_3_reg_5883 = stubsInLayer_3_r_V_q0.read().range(6, 5);
        redZ_V_3_reg_5873 = stubsInLayer_3_z_V_q0.read().range(8, 5);
        routePhi_V_3_reg_5888 = stubsInLayer_3_phi_V_q0.read().range(13, 12);
        routeZ_V_3_reg_5892 = stubsInLayer_3_z_V_q0.read().range(9, 9);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_reg_5910.read()))) {
        curPhi_V_4_reg_5952 = stubsInLayer_4_phi_V_q0.read();
        curR_V_4_reg_5957 = stubsInLayer_4_r_V_q0.read();
        curZ_V_4_reg_5947 = stubsInLayer_4_z_V_q0.read();
        redPhi_V_4_reg_5973 = stubsInLayer_4_phi_V_q0.read().range(11, 9);
        redPt_V_4_reg_5962 = stubsInLayer_4_pt_V_q0.read();
        redR_V_4_reg_5978 = stubsInLayer_4_r_V_q0.read().range(6, 5);
        redZ_V_4_reg_5968 = stubsInLayer_4_z_V_q0.read().range(8, 5);
        routePhi_V_4_reg_5983 = stubsInLayer_4_phi_V_q0.read().range(13, 12);
        routeZ_V_4_reg_5987 = stubsInLayer_4_z_V_q0.read().range(9, 9);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && !esl_seteq<1,1,1>(tmp_1_reg_5530.read(), ap_const_lv1_0))) {
        curPhi_V_reg_5572 = stubsInLayer_0_phi_V_q0.read();
        curR_V_reg_5577 = stubsInLayer_0_r_V_q0.read();
        curZ_V_reg_5567 = stubsInLayer_0_z_V_q0.read();
        redPhi_V_reg_5593 = stubsInLayer_0_phi_V_q0.read().range(11, 9);
        redPt_V_reg_5582 = stubsInLayer_0_pt_V_q0.read();
        redR_V_reg_5598 = stubsInLayer_0_r_V_q0.read().range(6, 5);
        redZ_V_reg_5588 = stubsInLayer_0_z_V_q0.read().range(8, 5);
        routePhi_V_reg_5603 = stubsInLayer_0_phi_V_q0.read().range(13, 12);
        routeZ_V_reg_5607 = stubsInLayer_0_z_V_q0.read().range(9, 9);
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()))) {
        index_V_1_reg_5620 = index_V_1_fu_4672_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()))) {
        index_V_2_reg_5715 = index_V_2_fu_4885_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()))) {
        index_V_3_reg_5810 = index_V_3_fu_5098_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()))) {
        index_V_4_reg_5905 = index_V_4_fu_5311_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()))) {
        index_V_reg_5525 = index_V_fu_4459_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read()))) {
        p_1_reg_5534 = p_1_fu_4474_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read()))) {
        p_3_reg_5724 = p_3_fu_4900_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read()))) {
        p_5_reg_5819 = p_5_fu_5113_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read()))) {
        p_6_reg_5629 = p_6_fu_4687_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && !esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read()))) {
        p_8_reg_5914 = p_8_fu_5326_p1.read();
    }
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read()) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_3) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_2) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_1) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
  !esl_seteq<1,1,1>(ap_reg_ppstg_tmp_1_reg_5530_pp0_iter1.read(), ap_const_lv1_0) && 
  esl_seteq<1,2,2>(routePhi_V_reg_5603.read(), ap_const_lv2_0) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_reg_5607.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_1_reg_5698.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_1_reg_5698.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_1_reg_5698.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_s_reg_5625_pp1_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_1_reg_5698.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_1_reg_5702.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_2_reg_5793.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_2_reg_5793.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_2_reg_5793.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_15_reg_5720_pp2_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_2_reg_5793.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_2_reg_5797.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_3_reg_5888.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_3_reg_5888.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_3_reg_5888.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_26_reg_5815_pp3_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_3_reg_5888.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_3_reg_5892.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_3, routePhi_V_4_reg_5983.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_2, routePhi_V_4_reg_5983.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_1, routePhi_V_4_reg_5983.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_37_reg_5910_pp4_iter1.read()) && 
  esl_seteq<1,2,2>(ap_const_lv2_0, routePhi_V_4_reg_5983.read()) && 
  !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_4_reg_5987.read())))) {
        reg_4231 = grp_VMRouterDispatcher_AddStub_fu_4197_ap_return_0.read();
        reg_4275 = grp_VMRouterDispatcher_AddStub_fu_4197_ap_return_1.read();
        reg_4319 = grp_VMRouterDispatcher_AddStub_fu_4197_ap_return_2.read();
        reg_4363 = grp_VMRouterDispatcher_AddStub_fu_4197_ap_return_3.read();
        reg_4407 = grp_VMRouterDispatcher_AddStub_fu_4197_ap_return_4.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_5.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()))) {
        tmp_15_reg_5720 = tmp_15_fu_4895_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()))) {
        tmp_1_reg_5530 = tmp_1_fu_4469_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp3_stg0_fsm_7.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()))) {
        tmp_26_reg_5815 = tmp_26_fu_5108_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_9.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()))) {
        tmp_37_reg_5910 = tmp_37_fu_5321_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp1_stg0_fsm_3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()))) {
        tmp_s_reg_5625 = tmp_s_fu_4682_p2.read();
    }
}

void VMRouterDispatcher::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if (!esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) {
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_1;
            } else {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            }
            break;
        case 2 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read())) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read())))) {
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_1;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_fu_4451_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_1_fu_4469_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
                ap_NS_fsm = ap_ST_st6_fsm_2;
            } else {
                ap_NS_fsm = ap_ST_st6_fsm_2;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_pp1_stg0_fsm_3;
            break;
        case 8 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it3.read()) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it2.read())) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it1.read())))) {
                ap_NS_fsm = ap_ST_pp1_stg0_fsm_3;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_13_fu_4664_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_s_fu_4682_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp1_it1.read()))) {
                ap_NS_fsm = ap_ST_st11_fsm_4;
            } else {
                ap_NS_fsm = ap_ST_st11_fsm_4;
            }
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_pp2_stg0_fsm_5;
            break;
        case 32 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it3.read()) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it2.read())) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read())))) {
                ap_NS_fsm = ap_ST_pp2_stg0_fsm_5;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_35_fu_4877_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_15_fu_4895_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()))) {
                ap_NS_fsm = ap_ST_st16_fsm_6;
            } else {
                ap_NS_fsm = ap_ST_st16_fsm_6;
            }
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_pp3_stg0_fsm_7;
            break;
        case 128 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it3.read()) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it2.read())) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it1.read())))) {
                ap_NS_fsm = ap_ST_pp3_stg0_fsm_7;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_55_fu_5090_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_26_fu_5108_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp3_it1.read()))) {
                ap_NS_fsm = ap_ST_st21_fsm_8;
            } else {
                ap_NS_fsm = ap_ST_st21_fsm_8;
            }
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_pp4_stg0_fsm_9;
            break;
        case 512 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it3.read()) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it2.read())) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read())))) {
                ap_NS_fsm = ap_ST_pp4_stg0_fsm_9;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) || 
  (esl_seteq<1,1,1>(ap_const_lv1_0, tmp_57_fu_5303_p3.read()) && 
   esl_seteq<1,1,1>(ap_const_lv1_0, tmp_37_fu_5321_p2.read()))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()))) {
                ap_NS_fsm = ap_ST_st26_fsm_10;
            } else {
                ap_NS_fsm = ap_ST_st26_fsm_10;
            }
            break;
        case 1024 : 
            ap_NS_fsm = ap_ST_st1_fsm_0;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<11>) ("XXXXXXXXXXX");
            break;
    }
}

}

