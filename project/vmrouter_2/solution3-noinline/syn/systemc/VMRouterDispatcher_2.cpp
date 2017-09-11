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
        ap_reg_grp_VMRouterDispatcher_VMRouter_fu_1144_ap_start = ap_const_logic_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
              !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) || 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st3_fsm_2.read()) || 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st5_fsm_4.read()) || 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st7_fsm_6.read()) || 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st9_fsm_8.read()))) {
            ap_reg_grp_VMRouterDispatcher_VMRouter_fu_1144_ap_start = ap_const_logic_1;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_VMRouterDispatcher_VMRouter_fu_1144_ap_ready.read())) {
            ap_reg_grp_VMRouterDispatcher_VMRouter_fu_1144_ap_start = ap_const_logic_0;
        }
    }
}

void VMRouterDispatcher::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if (!esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) {
                ap_NS_fsm = ap_ST_st2_fsm_1;
            } else {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            }
            break;
        case 2 : 
            if (!esl_seteq<1,1,1>(ap_const_logic_0, grp_VMRouterDispatcher_VMRouter_fu_1144_ap_done.read())) {
                ap_NS_fsm = ap_ST_st3_fsm_2;
            } else {
                ap_NS_fsm = ap_ST_st2_fsm_1;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_st4_fsm_3;
            break;
        case 8 : 
            if (!esl_seteq<1,1,1>(ap_const_logic_0, grp_VMRouterDispatcher_VMRouter_fu_1144_ap_done.read())) {
                ap_NS_fsm = ap_ST_st5_fsm_4;
            } else {
                ap_NS_fsm = ap_ST_st4_fsm_3;
            }
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_st6_fsm_5;
            break;
        case 32 : 
            if (!esl_seteq<1,1,1>(ap_const_logic_0, grp_VMRouterDispatcher_VMRouter_fu_1144_ap_done.read())) {
                ap_NS_fsm = ap_ST_st7_fsm_6;
            } else {
                ap_NS_fsm = ap_ST_st6_fsm_5;
            }
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_st8_fsm_7;
            break;
        case 128 : 
            if (!esl_seteq<1,1,1>(ap_const_logic_0, grp_VMRouterDispatcher_VMRouter_fu_1144_ap_done.read())) {
                ap_NS_fsm = ap_ST_st9_fsm_8;
            } else {
                ap_NS_fsm = ap_ST_st8_fsm_7;
            }
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_st10_fsm_9;
            break;
        case 512 : 
            if (!esl_seteq<1,1,1>(ap_const_logic_0, grp_VMRouterDispatcher_VMRouter_fu_1144_ap_done.read())) {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            } else {
                ap_NS_fsm = ap_ST_st10_fsm_9;
            }
            break;
        default : 
            ap_NS_fsm =  (sc_lv<10>) ("XXXXXXXXXX");
            break;
    }
}

}

