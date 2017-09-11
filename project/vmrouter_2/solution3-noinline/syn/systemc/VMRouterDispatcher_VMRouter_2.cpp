#include "VMRouterDispatcher_VMRouter.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void VMRouterDispatcher_VMRouter::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_st1_fsm_0;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ppiten_pp0_it0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
             (!esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) || 
              (esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && 
               esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0))))) {
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
             !(!esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) || (esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && 
  esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0))))) {
            ap_reg_ppiten_pp0_it1 = ap_const_logic_1;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                     !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) || 
                    (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
                     (!esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) || 
                      (esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && 
                       esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0)))))) {
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
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()) && 
         esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && 
         !esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0))) {
        i_reg_3994 = i_1_fu_4364_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        i_reg_3994 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_0))) {
        nPH1Z1_V_fu_716 = tmp_3_fu_5009_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH1Z1_V_fu_716 = nPH1Z1_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_0) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        nPH1Z2_V_fu_700 = tmp_s_fu_5461_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH1Z2_V_fu_700 = nPH1Z2_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_1))) {
        nPH2Z1_V_fu_712 = tmp_5_fu_4896_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH2Z1_V_fu_712 = nPH2Z1_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_1) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        nPH2Z2_V_fu_696 = tmp_6_fu_5348_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH2Z2_V_fu_696 = nPH2Z2_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_2))) {
        nPH3Z1_V_fu_708 = tmp_9_fu_4783_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH3Z1_V_fu_708 = nPH3Z1_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_2) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        nPH3Z2_V_fu_692 = tmp_7_fu_5235_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH3Z2_V_fu_692 = nPH3Z2_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_3))) {
        nPH4Z1_V_fu_704 = tmp_10_fu_4670_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH4Z1_V_fu_704 = nPH4Z1_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && 
         esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_3) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        nPH4Z2_V_fu_688 = tmp_8_fu_5122_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        nPH4Z2_V_fu_688 = nPH4Z2_V.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()) && 
         !esl_seteq<1,1,1>(tmp_4_reg_6337.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(tmp_67_reg_6328.read(), ap_const_lv1_0))) {
        op2_V_read_assign_reg_3942 = index_V_reg_6332.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        op2_V_read_assign_reg_3942 = ap_const_lv6_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read())) {
        ap_reg_ppstg_arrayNo1_reg_6359_pp0_iter1 = arrayNo1_reg_6359.read();
        ap_reg_ppstg_arrayNo2_reg_6369_pp0_iter1 = arrayNo2_reg_6369.read();
        ap_reg_ppstg_arrayNo3_reg_6379_pp0_iter1 = arrayNo3_reg_6379.read();
        ap_reg_ppstg_arrayNo_reg_6349_pp0_iter1 = arrayNo_reg_6349.read();
        ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter1 = op2_V_read_assign_reg_3942.read();
        ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1 = tmp_4_reg_6337.read();
        ap_reg_ppstg_tmp_5_cast_reg_6341_pp0_iter1 = tmp_5_cast_reg_6341.read();
        tmp_67_reg_6328 = i_reg_3994.read().range(6, 6);
    }
    if (esl_seteq<1,1,1>(ap_true, ap_true)) {
        ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter2 = ap_reg_ppstg_op2_V_read_assign_reg_3942_pp0_iter1.read();
        ap_reg_ppstg_tmp_4_reg_6337_pp0_iter2 = ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_0))) {
        arrayNo10_cast_cast_reg_6770 = sum10_fu_4949_p2.read().range(8, 6);
        arrayNo11_cast_cast_reg_6779 = sum11_fu_4968_p2.read().range(8, 6);
        arrayNo12_cast_cast_reg_6788 = sum12_fu_4987_p2.read().range(8, 6);
        arrayNo8_cast_cast_reg_6752 = sum8_fu_4911_p2.read().range(8, 6);
        arrayNo9_cast_cast_reg_6761 = sum9_fu_4930_p2.read().range(8, 6);
        tmp_100_reg_6783 = tmp_100_fu_4983_p1.read();
        tmp_101_reg_6792 = tmp_101_fu_5002_p1.read();
        tmp_97_reg_6756 = tmp_97_fu_4926_p1.read();
        tmp_98_reg_6765 = tmp_98_fu_4945_p1.read();
        tmp_99_reg_6774 = tmp_99_fu_4964_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_1))) {
        arrayNo13_cast_cast_reg_6707 = sum13_fu_4798_p2.read().range(8, 6);
        arrayNo14_cast_cast_reg_6716 = sum14_fu_4817_p2.read().range(8, 6);
        arrayNo15_cast_cast_reg_6725 = sum15_fu_4836_p2.read().range(8, 6);
        arrayNo16_cast_cast_reg_6734 = sum16_fu_4855_p2.read().range(8, 6);
        arrayNo17_cast_cast_reg_6743 = sum17_fu_4874_p2.read().range(8, 6);
        tmp_102_reg_6711 = tmp_102_fu_4813_p1.read();
        tmp_103_reg_6720 = tmp_103_fu_4832_p1.read();
        tmp_104_reg_6729 = tmp_104_fu_4851_p1.read();
        tmp_105_reg_6738 = tmp_105_fu_4870_p1.read();
        tmp_106_reg_6747 = tmp_106_fu_4889_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_2))) {
        arrayNo18_cast_cast_reg_6662 = sum18_fu_4685_p2.read().range(8, 6);
        arrayNo19_cast_cast_reg_6671 = sum19_fu_4704_p2.read().range(8, 6);
        arrayNo20_cast_cast_reg_6680 = sum20_fu_4723_p2.read().range(8, 6);
        arrayNo21_cast_cast_reg_6689 = sum21_fu_4742_p2.read().range(8, 6);
        arrayNo22_cast_cast_reg_6698 = sum22_fu_4761_p2.read().range(8, 6);
        tmp_107_reg_6666 = tmp_107_fu_4700_p1.read();
        tmp_108_reg_6675 = tmp_108_fu_4719_p1.read();
        tmp_109_reg_6684 = tmp_109_fu_4738_p1.read();
        tmp_148_reg_6693 = tmp_148_fu_4757_p1.read();
        tmp_149_reg_6702 = tmp_149_fu_4776_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && !esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0))) {
        arrayNo1_reg_6359 = sum1_fu_4307_p2.read().range(8, 6);
        arrayNo2_reg_6369 = sum2_fu_4326_p2.read().range(8, 6);
        arrayNo3_reg_6379 = sum3_fu_4345_p2.read().range(8, 6);
        arrayNo_reg_6349 = sum_fu_4288_p2.read().range(8, 6);
        tmp_5_cast_reg_6341 = tmp_5_cast_fu_4284_p1.read();
        tmp_68_reg_6354 = tmp_68_fu_4303_p1.read();
        tmp_69_reg_6364 = tmp_69_fu_4322_p1.read();
        tmp_70_reg_6374 = tmp_70_fu_4341_p1.read();
        tmp_71_reg_6384 = tmp_71_fu_4360_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_3))) {
        arrayNo23_cast_cast_reg_6617 = sum23_fu_4572_p2.read().range(8, 6);
        arrayNo24_cast_cast_reg_6626 = sum24_fu_4591_p2.read().range(8, 6);
        arrayNo25_cast_cast_reg_6635 = sum25_fu_4610_p2.read().range(8, 6);
        arrayNo26_cast_cast_reg_6644 = sum26_fu_4629_p2.read().range(8, 6);
        arrayNo27_cast_cast_reg_6653 = sum27_fu_4648_p2.read().range(8, 6);
        tmp_150_reg_6621 = tmp_150_fu_4587_p1.read();
        tmp_151_reg_6630 = tmp_151_fu_4606_p1.read();
        tmp_152_reg_6639 = tmp_152_fu_4625_p1.read();
        tmp_153_reg_6648 = tmp_153_fu_4644_p1.read();
        tmp_154_reg_6657 = tmp_154_fu_4663_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_0) && !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        arrayNo28_cast_cast_reg_6932 = sum28_fu_5363_p2.read().range(8, 6);
        arrayNo29_cast_cast_reg_6941 = sum29_fu_5382_p2.read().range(8, 6);
        arrayNo30_cast_cast_reg_6950 = sum30_fu_5401_p2.read().range(8, 6);
        arrayNo31_cast_cast_reg_6959 = sum31_fu_5420_p2.read().range(8, 6);
        arrayNo32_cast_cast_reg_6968 = sum32_fu_5439_p2.read().range(8, 6);
        tmp_77_reg_6936 = tmp_77_fu_5378_p1.read();
        tmp_78_reg_6945 = tmp_78_fu_5397_p1.read();
        tmp_79_reg_6954 = tmp_79_fu_5416_p1.read();
        tmp_80_reg_6963 = tmp_80_fu_5435_p1.read();
        tmp_81_reg_6972 = tmp_81_fu_5454_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_1) && !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        arrayNo33_cast_cast_reg_6887 = sum33_fu_5250_p2.read().range(8, 6);
        arrayNo34_cast_cast_reg_6896 = sum34_fu_5269_p2.read().range(8, 6);
        arrayNo35_cast_cast_reg_6905 = sum35_fu_5288_p2.read().range(8, 6);
        arrayNo36_cast_cast_reg_6914 = sum36_fu_5307_p2.read().range(8, 6);
        arrayNo37_cast_cast_reg_6923 = sum37_fu_5326_p2.read().range(8, 6);
        tmp_82_reg_6891 = tmp_82_fu_5265_p1.read();
        tmp_83_reg_6900 = tmp_83_fu_5284_p1.read();
        tmp_84_reg_6909 = tmp_84_fu_5303_p1.read();
        tmp_85_reg_6918 = tmp_85_fu_5322_p1.read();
        tmp_86_reg_6927 = tmp_86_fu_5341_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_2) && !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        arrayNo38_cast_cast_reg_6842 = sum38_fu_5137_p2.read().range(8, 6);
        arrayNo39_cast_cast_reg_6851 = sum39_fu_5156_p2.read().range(8, 6);
        arrayNo40_cast_cast_reg_6860 = sum40_fu_5175_p2.read().range(8, 6);
        arrayNo41_cast_cast_reg_6869 = sum41_fu_5194_p2.read().range(8, 6);
        arrayNo42_cast_cast_reg_6878 = sum42_fu_5213_p2.read().range(8, 6);
        tmp_87_reg_6846 = tmp_87_fu_5152_p1.read();
        tmp_88_reg_6855 = tmp_88_fu_5171_p1.read();
        tmp_89_reg_6864 = tmp_89_fu_5190_p1.read();
        tmp_90_reg_6873 = tmp_90_fu_5209_p1.read();
        tmp_91_reg_6882 = tmp_91_fu_5228_p1.read();
    }
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read()) && esl_seteq<1,2,2>(routePhi_V_fu_4550_p4.read(), ap_const_lv2_3) && !esl_seteq<1,1,1>(ap_const_lv1_0, routeZ_V_fu_4560_p3.read()))) {
        arrayNo43_cast_cast_reg_6797 = sum43_fu_5024_p2.read().range(8, 6);
        arrayNo44_cast_cast_reg_6806 = sum44_fu_5043_p2.read().range(8, 6);
        arrayNo45_cast_cast_reg_6815 = sum45_fu_5062_p2.read().range(8, 6);
        arrayNo46_cast_cast_reg_6824 = sum46_fu_5081_p2.read().range(8, 6);
        arrayNo47_cast_cast_reg_6833 = sum47_fu_5100_p2.read().range(8, 6);
        tmp_92_reg_6801 = tmp_92_fu_5039_p1.read();
        tmp_93_reg_6810 = tmp_93_fu_5058_p1.read();
        tmp_94_reg_6819 = tmp_94_fu_5077_p1.read();
        tmp_95_reg_6828 = tmp_95_fu_5096_p1.read();
        tmp_96_reg_6837 = tmp_96_fu_5115_p1.read();
    }
    if (!esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_4_reg_6337_pp0_iter1.read())) {
        arrayNo4_cast_cast_reg_6573 = sum4_fu_4478_p2.read().range(8, 6);
        arrayNo5_cast_cast_reg_6582 = sum5_fu_4496_p2.read().range(8, 6);
        arrayNo6_cast_cast_reg_6591 = sum6_fu_4514_p2.read().range(8, 6);
        arrayNo7_cast_cast_reg_6600 = sum7_fu_4532_p2.read().range(8, 6);
        curPhi_V_reg_6504 = curPhi_V_fu_4430_p7.read();
        curR_V_reg_6514 = curR_V_fu_4446_p7.read();
        curZ_V_reg_6494 = curZ_V_fu_4414_p7.read();
        redPt_V_reg_6524 = redPt_V_fu_4462_p7.read();
        routePhi_V_reg_6609 = curPhi_V_fu_4430_p7.read().range(13, 12);
        routeZ_V_reg_6613 = curZ_V_fu_4414_p7.read().range(9, 9);
        tmp_72_reg_6577 = tmp_72_fu_4492_p1.read();
        tmp_73_reg_6586 = tmp_73_fu_4510_p1.read();
        tmp_74_reg_6595 = tmp_74_fu_4528_p1.read();
        tmp_75_reg_6604 = tmp_75_fu_4546_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()))) {
        index_V_reg_6332 = index_V_fu_4269_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && !esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0))) {
        tmp_20_reg_6093 = tmp_20_fu_4033_p1.read();
        tmp_21_reg_6098 = tmp_21_fu_4037_p1.read();
        tmp_22_reg_6103 = tmp_22_fu_4041_p1.read();
        tmp_23_reg_6108 = tmp_23_fu_4045_p1.read();
        tmp_24_reg_6113 = tmp_24_fu_4049_p1.read();
        tmp_25_reg_6118 = tmp_25_fu_4053_p1.read();
        tmp_26_reg_6123 = tmp_26_fu_4057_p1.read();
        tmp_27_reg_6128 = tmp_27_fu_4061_p1.read();
        tmp_28_reg_6133 = tmp_28_fu_4065_p1.read();
        tmp_29_reg_6138 = tmp_29_fu_4069_p1.read();
        tmp_30_reg_6143 = tmp_30_fu_4073_p1.read();
        tmp_31_reg_6148 = tmp_31_fu_4077_p1.read();
        tmp_32_reg_6153 = tmp_32_fu_4081_p1.read();
        tmp_33_reg_6158 = tmp_33_fu_4085_p1.read();
        tmp_34_reg_6163 = tmp_34_fu_4089_p1.read();
        tmp_35_reg_6168 = tmp_35_fu_4093_p1.read();
        tmp_36_reg_6173 = tmp_36_fu_4097_p1.read();
        tmp_37_reg_6178 = tmp_37_fu_4101_p1.read();
        tmp_38_reg_6183 = tmp_38_fu_4105_p1.read();
        tmp_39_reg_6188 = tmp_39_fu_4109_p1.read();
        tmp_40_reg_6193 = tmp_40_fu_4113_p1.read();
        tmp_41_reg_6198 = tmp_41_fu_4117_p1.read();
        tmp_42_reg_6203 = tmp_42_fu_4121_p1.read();
        tmp_43_reg_6208 = tmp_43_fu_4125_p1.read();
        tmp_44_reg_6213 = tmp_44_fu_4129_p1.read();
        tmp_45_reg_6218 = tmp_45_fu_4133_p1.read();
        tmp_46_reg_6223 = tmp_46_fu_4137_p1.read();
        tmp_47_reg_6228 = tmp_47_fu_4141_p1.read();
        tmp_48_reg_6233 = tmp_48_fu_4145_p1.read();
        tmp_49_reg_6238 = tmp_49_fu_4149_p1.read();
        tmp_50_reg_6243 = tmp_50_fu_4153_p1.read();
        tmp_51_reg_6248 = tmp_51_fu_4157_p1.read();
        tmp_52_reg_6253 = tmp_52_fu_4161_p1.read();
        tmp_53_reg_6258 = tmp_53_fu_4165_p1.read();
        tmp_54_reg_6263 = tmp_54_fu_4169_p1.read();
        tmp_55_reg_6268 = tmp_55_fu_4173_p1.read();
        tmp_56_reg_6273 = tmp_56_fu_4177_p1.read();
        tmp_57_reg_6278 = tmp_57_fu_4181_p1.read();
        tmp_58_reg_6283 = tmp_58_fu_4185_p1.read();
        tmp_59_reg_6288 = tmp_59_fu_4189_p1.read();
        tmp_60_reg_6293 = tmp_60_fu_4193_p1.read();
        tmp_61_reg_6298 = tmp_61_fu_4197_p1.read();
        tmp_62_reg_6303 = tmp_62_fu_4201_p1.read();
        tmp_63_reg_6308 = tmp_63_fu_4205_p1.read();
        tmp_64_reg_6313 = tmp_64_fu_4209_p1.read();
        tmp_65_reg_6318 = tmp_65_fu_4213_p1.read();
        tmp_66_reg_6323 = tmp_66_fu_4217_p1.read();
        tmp_reg_6088 = tmp_fu_4029_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp0_stg0_fsm_1.read()) && esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0))) {
        tmp_4_reg_6337 = tmp_4_fu_4279_p2.read();
    }
}

void VMRouterDispatcher_VMRouter::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if (!esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0)) {
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_1;
            } else {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            }
            break;
        case 2 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it3.read()) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it2.read())) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()) && (!esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) || 
  (esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && 
   esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read())))) {
                ap_NS_fsm = ap_ST_pp0_stg0_fsm_1;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it0.read()) && (!esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) || 
  (esl_seteq<1,1,1>(tmp_67_fu_4261_p3.read(), ap_const_lv1_0) && 
   esl_seteq<1,1,1>(tmp_4_fu_4279_p2.read(), ap_const_lv1_0))) && !esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp0_it1.read()))) {
                ap_NS_fsm = ap_ST_st6_fsm_2;
            } else {
                ap_NS_fsm = ap_ST_st6_fsm_2;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_st1_fsm_0;
            break;
        default : 
            ap_NS_fsm = "XXX";
            break;
    }
}

}

