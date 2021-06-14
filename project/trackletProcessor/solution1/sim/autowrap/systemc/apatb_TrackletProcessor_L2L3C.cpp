// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->
    template< int ASType > struct AllStubInner;
    template<> struct AllStubInner<0> {
        ap_uint<51> data_;
       } ;

          template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR > struct MemoryTemplate;
          template<> struct MemoryTemplate<AllStubInner<0>, 3, 7> {
              AllStubInner<0 > dataarray_[8][128];
              ap_uint<7> nentries_[8];
             } ;

                template< int ASType > struct AllStub;
                template<> struct AllStub<0> {
                    ap_uint<36> data_;
                   } ;

                      template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR > struct MemoryTemplate;
                      template<> struct MemoryTemplate<AllStub<0>, 3, 7> {
                          AllStub<0 > dataarray_[8][128];
                          ap_uint<7> nentries_[8];
                         } ;

                            template< int VMSTEOType > struct VMStubTEOuter;
                            template<> struct VMStubTEOuter<0> {
                                ap_uint<16> data_;
                               } ;

                                  template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR ,unsigned int NBIT_BIN ,unsigned int NCOPY > struct MemoryTemplateBinnedCM;
                                  template<> struct MemoryTemplateBinnedCM<VMStubTEOuter<0>, 1, 10, 6, 2> {
                                      VMStubTEOuter<0 > dataarray_[2][2][1024];
                                      ap_uint<8> binmask8_[2][8];
                                      ap_uint<32> nentries8_[2][8];
                                     } ;

                                        typedef struct TrackletParameters {
                                            ap_uint<70> data_;
                                           } TrackletParameters;

                                              template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR > struct MemoryTemplate;
                                              template<> struct MemoryTemplate<TrackletParameters, 3, 7> {
                                                  TrackletParameters dataarray_[8][128];
                                                  ap_uint<7> nentries_[8];
                                                 } ;

                                                    template< int TProjType > struct TrackletProjection;
                                                    template<> struct TrackletProjection<0> {
                                                        ap_uint<60> data_;
                                                       } ;

                                                          template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR > struct MemoryTemplate;
                                                          template<> struct MemoryTemplate<TrackletProjection<0>, 1, 7> {
                                                              TrackletProjection<0 > dataarray_[2][128];
                                                              ap_uint<7> nentries_[2];
                                                             } ;

                                                                template< int TProjType > struct TrackletProjection;
                                                                template<> struct TrackletProjection<1> {
                                                                    ap_uint<58> data_;
                                                                   } ;

                                                                      template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR > struct MemoryTemplate;
                                                                      template<> struct MemoryTemplate<TrackletProjection<1>, 1, 7> {
                                                                          TrackletProjection<1 > dataarray_[2][128];
                                                                          ap_uint<7> nentries_[2];
                                                                         } ;

                                                                            template< int TProjType > struct TrackletProjection;
                                                                            template<> struct TrackletProjection<6> {
                                                                                ap_uint<59> data_;
                                                                               } ;

                                                                                  template< typename DataType ,unsigned int NBIT_BX ,unsigned int NBIT_ADDR > struct MemoryTemplate;
                                                                                  template<> struct MemoryTemplate<TrackletProjection<6>, 1, 7> {
                                                                                      TrackletProjection<6 > dataarray_[2][128];
                                                                                      ap_uint<7> nentries_[2];
                                                                                     } ;



// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "bx_V"
#define AUTOTB_TVIN_bx_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_bx_V.dat"
// wrapc file define: "lut_V"
#define AUTOTB_TVIN_lut_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_lut_V.dat"
// wrapc file define: "regionlut_V"
#define AUTOTB_TVIN_regionlut_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_regionlut_V.dat"
// wrapc file define: "innerStubs_dataarray_data_V"
#define AUTOTB_TVIN_innerStubs_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_dataarray_data_V.dat"
// wrapc file define: "innerStubs_0_nentries_0_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_0_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_0_V.dat"
// wrapc file define: "innerStubs_0_nentries_1_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_1_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_1_V.dat"
// wrapc file define: "innerStubs_0_nentries_2_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_2_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_2_V.dat"
// wrapc file define: "innerStubs_0_nentries_3_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_3_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_3_V.dat"
// wrapc file define: "innerStubs_0_nentries_4_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_4_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_4_V.dat"
// wrapc file define: "innerStubs_0_nentries_5_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_5_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_5_V.dat"
// wrapc file define: "innerStubs_0_nentries_6_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_6_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_6_V.dat"
// wrapc file define: "innerStubs_0_nentries_7_V"
#define AUTOTB_TVIN_innerStubs_0_nentries_7_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_0_nentries_7_V.dat"
// wrapc file define: "innerStubs_1_nentries_0_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_0_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_0_V.dat"
// wrapc file define: "innerStubs_1_nentries_1_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_1_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_1_V.dat"
// wrapc file define: "innerStubs_1_nentries_2_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_2_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_2_V.dat"
// wrapc file define: "innerStubs_1_nentries_3_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_3_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_3_V.dat"
// wrapc file define: "innerStubs_1_nentries_4_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_4_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_4_V.dat"
// wrapc file define: "innerStubs_1_nentries_5_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_5_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_5_V.dat"
// wrapc file define: "innerStubs_1_nentries_6_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_6_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_6_V.dat"
// wrapc file define: "innerStubs_1_nentries_7_V"
#define AUTOTB_TVIN_innerStubs_1_nentries_7_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_1_nentries_7_V.dat"
// wrapc file define: "innerStubs_2_nentries_0_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_0_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_0_V.dat"
// wrapc file define: "innerStubs_2_nentries_1_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_1_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_1_V.dat"
// wrapc file define: "innerStubs_2_nentries_2_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_2_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_2_V.dat"
// wrapc file define: "innerStubs_2_nentries_3_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_3_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_3_V.dat"
// wrapc file define: "innerStubs_2_nentries_4_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_4_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_4_V.dat"
// wrapc file define: "innerStubs_2_nentries_5_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_5_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_5_V.dat"
// wrapc file define: "innerStubs_2_nentries_6_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_6_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_6_V.dat"
// wrapc file define: "innerStubs_2_nentries_7_V"
#define AUTOTB_TVIN_innerStubs_2_nentries_7_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_innerStubs_2_nentries_7_V.dat"
// wrapc file define: "outerStubs_dataarray_data_V"
#define AUTOTB_TVIN_outerStubs_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerStubs_dataarray_data_V.dat"
// wrapc file define: "outerVMStubs_dataarray_data_V_0"
#define AUTOTB_TVIN_outerVMStubs_dataarray_data_V_0  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_dataarray_data_V_0.dat"
// wrapc file define: "outerVMStubs_dataarray_data_V_1"
#define AUTOTB_TVIN_outerVMStubs_dataarray_data_V_1  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_dataarray_data_V_1.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_0"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_0  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_0.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_1"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_1  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_1.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_2"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_2  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_2.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_3"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_3  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_3.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_4"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_4  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_4.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_5"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_5  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_5.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_6"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_6  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_6.dat"
// wrapc file define: "outerVMStubs_binmask8_V_0_7"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_0_7  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_0_7.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_0"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_0  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_0.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_1"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_1  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_1.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_2"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_2  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_2.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_3"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_3  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_3.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_4"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_4  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_4.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_5"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_5  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_5.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_6"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_6  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_6.dat"
// wrapc file define: "outerVMStubs_binmask8_V_1_7"
#define AUTOTB_TVIN_outerVMStubs_binmask8_V_1_7  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_binmask8_V_1_7.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_0"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_0  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_0.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_1"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_1  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_1.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_2"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_2  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_2.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_3"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_3  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_3.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_4"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_4  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_4.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_5"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_5  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_5.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_6"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_6  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_6.dat"
// wrapc file define: "outerVMStubs_nentries8_V_0_7"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_0_7  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_0_7.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_0"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_0  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_0.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_1"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_1  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_1.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_2"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_2  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_2.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_3"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_3  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_3.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_4"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_4  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_4.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_5"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_5  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_5.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_6"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_6  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_6.dat"
// wrapc file define: "outerVMStubs_nentries8_V_1_7"
#define AUTOTB_TVIN_outerVMStubs_nentries8_V_1_7  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_outerVMStubs_nentries8_V_1_7.dat"
// wrapc file define: "trackletParameters_dataarray_data_V"
#define AUTOTB_TVOUT_trackletParameters_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_trackletParameters_dataarray_data_V.dat"
#define AUTOTB_TVIN_trackletParameters_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_trackletParameters_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_ps_3_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_ps_3_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_3_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_ps_3_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_3_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_ps_4_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_ps_4_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_4_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_ps_4_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_4_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_ps_5_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_ps_5_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_5_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_ps_5_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_5_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_ps_6_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_ps_6_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_6_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_ps_6_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_ps_6_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_2s_1_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_2s_1_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_1_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_2s_1_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_1_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_2s_2_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_2s_2_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_2_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_2s_2_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_2_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_2s_3_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_2s_3_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_3_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_2s_3_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_3_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_2s_5_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_2s_5_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_5_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_2s_5_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_5_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_2s_6_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_2s_6_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_6_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_2s_6_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_6_dataarray_data_V.dat"
// wrapc file define: "projout_barrel_2s_7_dataarray_data_V"
#define AUTOTB_TVOUT_projout_barrel_2s_7_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_7_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_barrel_2s_7_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_barrel_2s_7_dataarray_data_V.dat"
// wrapc file define: "projout_disk_1_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_1_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_1_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_1_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_1_dataarray_data_V.dat"
// wrapc file define: "projout_disk_2_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_2_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_2_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_2_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_2_dataarray_data_V.dat"
// wrapc file define: "projout_disk_3_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_3_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_3_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_3_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_3_dataarray_data_V.dat"
// wrapc file define: "projout_disk_5_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_5_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_5_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_5_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_5_dataarray_data_V.dat"
// wrapc file define: "projout_disk_6_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_6_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_6_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_6_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_6_dataarray_data_V.dat"
// wrapc file define: "projout_disk_7_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_7_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_7_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_7_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_7_dataarray_data_V.dat"
// wrapc file define: "projout_disk_9_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_9_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_9_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_9_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_9_dataarray_data_V.dat"
// wrapc file define: "projout_disk_10_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_10_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_10_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_10_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_10_dataarray_data_V.dat"
// wrapc file define: "projout_disk_11_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_11_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_11_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_11_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_11_dataarray_data_V.dat"
// wrapc file define: "projout_disk_13_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_13_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_13_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_13_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_13_dataarray_data_V.dat"
// wrapc file define: "projout_disk_14_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_14_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_14_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_14_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_14_dataarray_data_V.dat"
// wrapc file define: "projout_disk_15_dataarray_data_V"
#define AUTOTB_TVOUT_projout_disk_15_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvout_projout_disk_15_dataarray_data_V.dat"
#define AUTOTB_TVIN_projout_disk_15_dataarray_data_V  "../tv/cdatafile/c.TrackletProcessor_L2L3C.autotvin_projout_disk_15_dataarray_data_V.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "trackletParameters_dataarray_data_V"
#define AUTOTB_TVOUT_PC_trackletParameters_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_trackletParameters_dataarray_data_V.dat"
// tvout file define: "projout_barrel_ps_3_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_ps_3_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_3_dataarray_data_V.dat"
// tvout file define: "projout_barrel_ps_4_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_ps_4_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_4_dataarray_data_V.dat"
// tvout file define: "projout_barrel_ps_5_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_ps_5_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_5_dataarray_data_V.dat"
// tvout file define: "projout_barrel_ps_6_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_ps_6_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_ps_6_dataarray_data_V.dat"
// tvout file define: "projout_barrel_2s_1_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_2s_1_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_1_dataarray_data_V.dat"
// tvout file define: "projout_barrel_2s_2_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_2s_2_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_2_dataarray_data_V.dat"
// tvout file define: "projout_barrel_2s_3_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_2s_3_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_3_dataarray_data_V.dat"
// tvout file define: "projout_barrel_2s_5_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_2s_5_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_5_dataarray_data_V.dat"
// tvout file define: "projout_barrel_2s_6_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_2s_6_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_6_dataarray_data_V.dat"
// tvout file define: "projout_barrel_2s_7_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_barrel_2s_7_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_barrel_2s_7_dataarray_data_V.dat"
// tvout file define: "projout_disk_1_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_1_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_1_dataarray_data_V.dat"
// tvout file define: "projout_disk_2_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_2_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_2_dataarray_data_V.dat"
// tvout file define: "projout_disk_3_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_3_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_3_dataarray_data_V.dat"
// tvout file define: "projout_disk_5_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_5_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_5_dataarray_data_V.dat"
// tvout file define: "projout_disk_6_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_6_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_6_dataarray_data_V.dat"
// tvout file define: "projout_disk_7_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_7_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_7_dataarray_data_V.dat"
// tvout file define: "projout_disk_9_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_9_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_9_dataarray_data_V.dat"
// tvout file define: "projout_disk_10_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_10_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_10_dataarray_data_V.dat"
// tvout file define: "projout_disk_11_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_11_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_11_dataarray_data_V.dat"
// tvout file define: "projout_disk_13_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_13_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_13_dataarray_data_V.dat"
// tvout file define: "projout_disk_14_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_14_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_14_dataarray_data_V.dat"
// tvout file define: "projout_disk_15_dataarray_data_V"
#define AUTOTB_TVOUT_PC_projout_disk_15_dataarray_data_V  "../tv/rtldatafile/rtl.TrackletProcessor_L2L3C.autotvout_projout_disk_15_dataarray_data_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			bx_V_depth = 0;
			lut_V_depth = 0;
			regionlut_V_depth = 0;
			innerStubs_dataarray_data_V_depth = 0;
			innerStubs_0_nentries_0_V_depth = 0;
			innerStubs_0_nentries_1_V_depth = 0;
			innerStubs_0_nentries_2_V_depth = 0;
			innerStubs_0_nentries_3_V_depth = 0;
			innerStubs_0_nentries_4_V_depth = 0;
			innerStubs_0_nentries_5_V_depth = 0;
			innerStubs_0_nentries_6_V_depth = 0;
			innerStubs_0_nentries_7_V_depth = 0;
			innerStubs_1_nentries_0_V_depth = 0;
			innerStubs_1_nentries_1_V_depth = 0;
			innerStubs_1_nentries_2_V_depth = 0;
			innerStubs_1_nentries_3_V_depth = 0;
			innerStubs_1_nentries_4_V_depth = 0;
			innerStubs_1_nentries_5_V_depth = 0;
			innerStubs_1_nentries_6_V_depth = 0;
			innerStubs_1_nentries_7_V_depth = 0;
			innerStubs_2_nentries_0_V_depth = 0;
			innerStubs_2_nentries_1_V_depth = 0;
			innerStubs_2_nentries_2_V_depth = 0;
			innerStubs_2_nentries_3_V_depth = 0;
			innerStubs_2_nentries_4_V_depth = 0;
			innerStubs_2_nentries_5_V_depth = 0;
			innerStubs_2_nentries_6_V_depth = 0;
			innerStubs_2_nentries_7_V_depth = 0;
			outerStubs_dataarray_data_V_depth = 0;
			outerVMStubs_dataarray_data_V_0_depth = 0;
			outerVMStubs_dataarray_data_V_1_depth = 0;
			outerVMStubs_binmask8_V_0_0_depth = 0;
			outerVMStubs_binmask8_V_0_1_depth = 0;
			outerVMStubs_binmask8_V_0_2_depth = 0;
			outerVMStubs_binmask8_V_0_3_depth = 0;
			outerVMStubs_binmask8_V_0_4_depth = 0;
			outerVMStubs_binmask8_V_0_5_depth = 0;
			outerVMStubs_binmask8_V_0_6_depth = 0;
			outerVMStubs_binmask8_V_0_7_depth = 0;
			outerVMStubs_binmask8_V_1_0_depth = 0;
			outerVMStubs_binmask8_V_1_1_depth = 0;
			outerVMStubs_binmask8_V_1_2_depth = 0;
			outerVMStubs_binmask8_V_1_3_depth = 0;
			outerVMStubs_binmask8_V_1_4_depth = 0;
			outerVMStubs_binmask8_V_1_5_depth = 0;
			outerVMStubs_binmask8_V_1_6_depth = 0;
			outerVMStubs_binmask8_V_1_7_depth = 0;
			outerVMStubs_nentries8_V_0_0_depth = 0;
			outerVMStubs_nentries8_V_0_1_depth = 0;
			outerVMStubs_nentries8_V_0_2_depth = 0;
			outerVMStubs_nentries8_V_0_3_depth = 0;
			outerVMStubs_nentries8_V_0_4_depth = 0;
			outerVMStubs_nentries8_V_0_5_depth = 0;
			outerVMStubs_nentries8_V_0_6_depth = 0;
			outerVMStubs_nentries8_V_0_7_depth = 0;
			outerVMStubs_nentries8_V_1_0_depth = 0;
			outerVMStubs_nentries8_V_1_1_depth = 0;
			outerVMStubs_nentries8_V_1_2_depth = 0;
			outerVMStubs_nentries8_V_1_3_depth = 0;
			outerVMStubs_nentries8_V_1_4_depth = 0;
			outerVMStubs_nentries8_V_1_5_depth = 0;
			outerVMStubs_nentries8_V_1_6_depth = 0;
			outerVMStubs_nentries8_V_1_7_depth = 0;
			trackletParameters_dataarray_data_V_depth = 0;
			projout_barrel_ps_3_dataarray_data_V_depth = 0;
			projout_barrel_ps_4_dataarray_data_V_depth = 0;
			projout_barrel_ps_5_dataarray_data_V_depth = 0;
			projout_barrel_ps_6_dataarray_data_V_depth = 0;
			projout_barrel_2s_1_dataarray_data_V_depth = 0;
			projout_barrel_2s_2_dataarray_data_V_depth = 0;
			projout_barrel_2s_3_dataarray_data_V_depth = 0;
			projout_barrel_2s_5_dataarray_data_V_depth = 0;
			projout_barrel_2s_6_dataarray_data_V_depth = 0;
			projout_barrel_2s_7_dataarray_data_V_depth = 0;
			projout_disk_1_dataarray_data_V_depth = 0;
			projout_disk_2_dataarray_data_V_depth = 0;
			projout_disk_3_dataarray_data_V_depth = 0;
			projout_disk_5_dataarray_data_V_depth = 0;
			projout_disk_6_dataarray_data_V_depth = 0;
			projout_disk_7_dataarray_data_V_depth = 0;
			projout_disk_9_dataarray_data_V_depth = 0;
			projout_disk_10_dataarray_data_V_depth = 0;
			projout_disk_11_dataarray_data_V_depth = 0;
			projout_disk_13_dataarray_data_V_depth = 0;
			projout_disk_14_dataarray_data_V_depth = 0;
			projout_disk_15_dataarray_data_V_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{bx_V " << bx_V_depth << "}\n";
			total_list << "{lut_V " << lut_V_depth << "}\n";
			total_list << "{regionlut_V " << regionlut_V_depth << "}\n";
			total_list << "{innerStubs_dataarray_data_V " << innerStubs_dataarray_data_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_0_V " << innerStubs_0_nentries_0_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_1_V " << innerStubs_0_nentries_1_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_2_V " << innerStubs_0_nentries_2_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_3_V " << innerStubs_0_nentries_3_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_4_V " << innerStubs_0_nentries_4_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_5_V " << innerStubs_0_nentries_5_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_6_V " << innerStubs_0_nentries_6_V_depth << "}\n";
			total_list << "{innerStubs_0_nentries_7_V " << innerStubs_0_nentries_7_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_0_V " << innerStubs_1_nentries_0_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_1_V " << innerStubs_1_nentries_1_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_2_V " << innerStubs_1_nentries_2_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_3_V " << innerStubs_1_nentries_3_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_4_V " << innerStubs_1_nentries_4_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_5_V " << innerStubs_1_nentries_5_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_6_V " << innerStubs_1_nentries_6_V_depth << "}\n";
			total_list << "{innerStubs_1_nentries_7_V " << innerStubs_1_nentries_7_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_0_V " << innerStubs_2_nentries_0_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_1_V " << innerStubs_2_nentries_1_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_2_V " << innerStubs_2_nentries_2_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_3_V " << innerStubs_2_nentries_3_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_4_V " << innerStubs_2_nentries_4_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_5_V " << innerStubs_2_nentries_5_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_6_V " << innerStubs_2_nentries_6_V_depth << "}\n";
			total_list << "{innerStubs_2_nentries_7_V " << innerStubs_2_nentries_7_V_depth << "}\n";
			total_list << "{outerStubs_dataarray_data_V " << outerStubs_dataarray_data_V_depth << "}\n";
			total_list << "{outerVMStubs_dataarray_data_V_0 " << outerVMStubs_dataarray_data_V_0_depth << "}\n";
			total_list << "{outerVMStubs_dataarray_data_V_1 " << outerVMStubs_dataarray_data_V_1_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_0 " << outerVMStubs_binmask8_V_0_0_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_1 " << outerVMStubs_binmask8_V_0_1_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_2 " << outerVMStubs_binmask8_V_0_2_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_3 " << outerVMStubs_binmask8_V_0_3_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_4 " << outerVMStubs_binmask8_V_0_4_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_5 " << outerVMStubs_binmask8_V_0_5_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_6 " << outerVMStubs_binmask8_V_0_6_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_0_7 " << outerVMStubs_binmask8_V_0_7_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_0 " << outerVMStubs_binmask8_V_1_0_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_1 " << outerVMStubs_binmask8_V_1_1_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_2 " << outerVMStubs_binmask8_V_1_2_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_3 " << outerVMStubs_binmask8_V_1_3_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_4 " << outerVMStubs_binmask8_V_1_4_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_5 " << outerVMStubs_binmask8_V_1_5_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_6 " << outerVMStubs_binmask8_V_1_6_depth << "}\n";
			total_list << "{outerVMStubs_binmask8_V_1_7 " << outerVMStubs_binmask8_V_1_7_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_0 " << outerVMStubs_nentries8_V_0_0_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_1 " << outerVMStubs_nentries8_V_0_1_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_2 " << outerVMStubs_nentries8_V_0_2_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_3 " << outerVMStubs_nentries8_V_0_3_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_4 " << outerVMStubs_nentries8_V_0_4_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_5 " << outerVMStubs_nentries8_V_0_5_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_6 " << outerVMStubs_nentries8_V_0_6_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_0_7 " << outerVMStubs_nentries8_V_0_7_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_0 " << outerVMStubs_nentries8_V_1_0_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_1 " << outerVMStubs_nentries8_V_1_1_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_2 " << outerVMStubs_nentries8_V_1_2_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_3 " << outerVMStubs_nentries8_V_1_3_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_4 " << outerVMStubs_nentries8_V_1_4_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_5 " << outerVMStubs_nentries8_V_1_5_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_6 " << outerVMStubs_nentries8_V_1_6_depth << "}\n";
			total_list << "{outerVMStubs_nentries8_V_1_7 " << outerVMStubs_nentries8_V_1_7_depth << "}\n";
			total_list << "{trackletParameters_dataarray_data_V " << trackletParameters_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_ps_3_dataarray_data_V " << projout_barrel_ps_3_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_ps_4_dataarray_data_V " << projout_barrel_ps_4_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_ps_5_dataarray_data_V " << projout_barrel_ps_5_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_ps_6_dataarray_data_V " << projout_barrel_ps_6_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_2s_1_dataarray_data_V " << projout_barrel_2s_1_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_2s_2_dataarray_data_V " << projout_barrel_2s_2_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_2s_3_dataarray_data_V " << projout_barrel_2s_3_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_2s_5_dataarray_data_V " << projout_barrel_2s_5_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_2s_6_dataarray_data_V " << projout_barrel_2s_6_dataarray_data_V_depth << "}\n";
			total_list << "{projout_barrel_2s_7_dataarray_data_V " << projout_barrel_2s_7_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_1_dataarray_data_V " << projout_disk_1_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_2_dataarray_data_V " << projout_disk_2_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_3_dataarray_data_V " << projout_disk_3_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_5_dataarray_data_V " << projout_disk_5_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_6_dataarray_data_V " << projout_disk_6_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_7_dataarray_data_V " << projout_disk_7_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_9_dataarray_data_V " << projout_disk_9_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_10_dataarray_data_V " << projout_disk_10_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_11_dataarray_data_V " << projout_disk_11_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_13_dataarray_data_V " << projout_disk_13_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_14_dataarray_data_V " << projout_disk_14_dataarray_data_V_depth << "}\n";
			total_list << "{projout_disk_15_dataarray_data_V " << projout_disk_15_dataarray_data_V_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int bx_V_depth;
		int lut_V_depth;
		int regionlut_V_depth;
		int innerStubs_dataarray_data_V_depth;
		int innerStubs_0_nentries_0_V_depth;
		int innerStubs_0_nentries_1_V_depth;
		int innerStubs_0_nentries_2_V_depth;
		int innerStubs_0_nentries_3_V_depth;
		int innerStubs_0_nentries_4_V_depth;
		int innerStubs_0_nentries_5_V_depth;
		int innerStubs_0_nentries_6_V_depth;
		int innerStubs_0_nentries_7_V_depth;
		int innerStubs_1_nentries_0_V_depth;
		int innerStubs_1_nentries_1_V_depth;
		int innerStubs_1_nentries_2_V_depth;
		int innerStubs_1_nentries_3_V_depth;
		int innerStubs_1_nentries_4_V_depth;
		int innerStubs_1_nentries_5_V_depth;
		int innerStubs_1_nentries_6_V_depth;
		int innerStubs_1_nentries_7_V_depth;
		int innerStubs_2_nentries_0_V_depth;
		int innerStubs_2_nentries_1_V_depth;
		int innerStubs_2_nentries_2_V_depth;
		int innerStubs_2_nentries_3_V_depth;
		int innerStubs_2_nentries_4_V_depth;
		int innerStubs_2_nentries_5_V_depth;
		int innerStubs_2_nentries_6_V_depth;
		int innerStubs_2_nentries_7_V_depth;
		int outerStubs_dataarray_data_V_depth;
		int outerVMStubs_dataarray_data_V_0_depth;
		int outerVMStubs_dataarray_data_V_1_depth;
		int outerVMStubs_binmask8_V_0_0_depth;
		int outerVMStubs_binmask8_V_0_1_depth;
		int outerVMStubs_binmask8_V_0_2_depth;
		int outerVMStubs_binmask8_V_0_3_depth;
		int outerVMStubs_binmask8_V_0_4_depth;
		int outerVMStubs_binmask8_V_0_5_depth;
		int outerVMStubs_binmask8_V_0_6_depth;
		int outerVMStubs_binmask8_V_0_7_depth;
		int outerVMStubs_binmask8_V_1_0_depth;
		int outerVMStubs_binmask8_V_1_1_depth;
		int outerVMStubs_binmask8_V_1_2_depth;
		int outerVMStubs_binmask8_V_1_3_depth;
		int outerVMStubs_binmask8_V_1_4_depth;
		int outerVMStubs_binmask8_V_1_5_depth;
		int outerVMStubs_binmask8_V_1_6_depth;
		int outerVMStubs_binmask8_V_1_7_depth;
		int outerVMStubs_nentries8_V_0_0_depth;
		int outerVMStubs_nentries8_V_0_1_depth;
		int outerVMStubs_nentries8_V_0_2_depth;
		int outerVMStubs_nentries8_V_0_3_depth;
		int outerVMStubs_nentries8_V_0_4_depth;
		int outerVMStubs_nentries8_V_0_5_depth;
		int outerVMStubs_nentries8_V_0_6_depth;
		int outerVMStubs_nentries8_V_0_7_depth;
		int outerVMStubs_nentries8_V_1_0_depth;
		int outerVMStubs_nentries8_V_1_1_depth;
		int outerVMStubs_nentries8_V_1_2_depth;
		int outerVMStubs_nentries8_V_1_3_depth;
		int outerVMStubs_nentries8_V_1_4_depth;
		int outerVMStubs_nentries8_V_1_5_depth;
		int outerVMStubs_nentries8_V_1_6_depth;
		int outerVMStubs_nentries8_V_1_7_depth;
		int trackletParameters_dataarray_data_V_depth;
		int projout_barrel_ps_3_dataarray_data_V_depth;
		int projout_barrel_ps_4_dataarray_data_V_depth;
		int projout_barrel_ps_5_dataarray_data_V_depth;
		int projout_barrel_ps_6_dataarray_data_V_depth;
		int projout_barrel_2s_1_dataarray_data_V_depth;
		int projout_barrel_2s_2_dataarray_data_V_depth;
		int projout_barrel_2s_3_dataarray_data_V_depth;
		int projout_barrel_2s_5_dataarray_data_V_depth;
		int projout_barrel_2s_6_dataarray_data_V_depth;
		int projout_barrel_2s_7_dataarray_data_V_depth;
		int projout_disk_1_dataarray_data_V_depth;
		int projout_disk_2_dataarray_data_V_depth;
		int projout_disk_3_dataarray_data_V_depth;
		int projout_disk_5_dataarray_data_V_depth;
		int projout_disk_6_dataarray_data_V_depth;
		int projout_disk_7_dataarray_data_V_depth;
		int projout_disk_9_dataarray_data_V_depth;
		int projout_disk_10_dataarray_data_V_depth;
		int projout_disk_11_dataarray_data_V_depth;
		int projout_disk_13_dataarray_data_V_depth;
		int projout_disk_14_dataarray_data_V_depth;
		int projout_disk_15_dataarray_data_V_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void TrackletProcessor_L2L3C (
const ap_uint<3> bx,
const ap_uint<10> lut[2048],
const ap_uint<8> regionlut[2048],
const MemoryTemplate<AllStubInner<0 >, 3, 7 > innerStubs[3],
const MemoryTemplate<AllStub<0 >, 3, 7 >* outerStubs,
const MemoryTemplateBinnedCM<VMStubTEOuter<0 >, 1, 10, 6, 2 > outerVMStubs,
MemoryTemplate<TrackletParameters, 3, 7 >* trackletParameters,
MemoryTemplate<TrackletProjection<0 >, 1, 7 > projout_barrel_ps[16],
MemoryTemplate<TrackletProjection<1 >, 1, 7 > projout_barrel_2s[12],
MemoryTemplate<TrackletProjection<6 >, 1, 7 > projout_disk[16]);

void AESL_WRAP_TrackletProcessor_L2L3C (
const ap_uint<3> bx,
const ap_uint<10> lut[2048],
const ap_uint<8> regionlut[2048],
const MemoryTemplate<AllStubInner<0 >, 3, 7 > innerStubs[3],
const MemoryTemplate<AllStub<0 >, 3, 7 >* outerStubs,
const MemoryTemplateBinnedCM<VMStubTEOuter<0 >, 1, 10, 6, 2 > outerVMStubs,
MemoryTemplate<TrackletParameters, 3, 7 >* trackletParameters,
MemoryTemplate<TrackletProjection<0 >, 1, 7 > projout_barrel_ps[16],
MemoryTemplate<TrackletProjection<1 >, 1, 7 > projout_barrel_2s[12],
MemoryTemplate<TrackletProjection<6 >, 1, 7 > projout_disk[16])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "trackletParameters_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_trackletParameters_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_trackletParameters_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_trackletParameters_dataarray_data_V, AESL_token); // data

			sc_bv<70> *trackletParameters_dataarray_data_V_pc_buffer = new sc_bv<70>[1024];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'trackletParameters_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'trackletParameters_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					trackletParameters_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_trackletParameters_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_trackletParameters_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: trackletParameters_dataarray_data_V
				{
					// bitslice(69, 0)
					// {
						// celement: trackletParameters.dataarray_.data_.V(69, 0)
						// {
							sc_lv<70>* trackletParameters_dataarray__data__V_lv0_0_7_1_lv1_0_127_1 = new sc_lv<70>[1024];
						// }
					// }

					// bitslice(69, 0)
					{
						int hls_map_index = 0;
						// celement: trackletParameters.dataarray_.data_.V(69, 0)
						{
							// carray: (0) => (7) @ (1)
							for (int i_0 = 0; i_0 <= 7; i_0 += 1)
							{
								// carray: (0) => (127) @ (1)
								for (int i_1 = 0; i_1 <= 127; i_1 += 1)
								{
									if (&(trackletParameters->dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
									{
										trackletParameters_dataarray__data__V_lv0_0_7_1_lv1_0_127_1[hls_map_index].range(69, 0) = sc_bv<70>(trackletParameters_dataarray_data_V_pc_buffer[hls_map_index].range(69, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(69, 0)
					{
						int hls_map_index = 0;
						// celement: trackletParameters.dataarray_.data_.V(69, 0)
						{
							// carray: (0) => (7) @ (1)
							for (int i_0 = 0; i_0 <= 7; i_0 += 1)
							{
								// carray: (0) => (127) @ (1)
								for (int i_1 = 0; i_1 <= 127; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : trackletParameters->dataarray_[i_0][i_1].data_
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : trackletParameters->dataarray_[0][0].data_
									// output_left_conversion : trackletParameters->dataarray_[i_0][i_1].data_
									// output_type_conversion : (trackletParameters_dataarray__data__V_lv0_0_7_1_lv1_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(trackletParameters->dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
									{
										trackletParameters->dataarray_[i_0][i_1].data_ = (trackletParameters_dataarray__data__V_lv0_0_7_1_lv1_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] trackletParameters_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_ps_3_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_3_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_3_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_3_dataarray_data_V, AESL_token); // data

			sc_bv<60> *projout_barrel_ps_3_dataarray_data_V_pc_buffer = new sc_bv<60>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_3_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_3_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_ps_3_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_3_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_ps_3_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_ps_3_dataarray_data_V
				{
					// bitslice(59, 0)
					// {
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						// {
							sc_lv<60>* projout_barrel_ps_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<60>[256];
						// }
					// }

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(59, 0) = sc_bv<60>(projout_barrel_ps_3_dataarray_data_V_pc_buffer[hls_map_index].range(59, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_ps[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_ps_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_ps_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_ps_3_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_ps_4_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_4_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_4_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_4_dataarray_data_V, AESL_token); // data

			sc_bv<60> *projout_barrel_ps_4_dataarray_data_V_pc_buffer = new sc_bv<60>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_4_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_4_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_ps_4_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_4_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_ps_4_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_ps_4_dataarray_data_V
				{
					// bitslice(59, 0)
					// {
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						// {
							sc_lv<60>* projout_barrel_ps_dataarray__data__V_lv0_4_4_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<60>[256];
						// }
					// }

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (4) => (4) @ (2)
							for (int i_0 = 4; i_0 <= 4; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps_dataarray__data__V_lv0_4_4_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(59, 0) = sc_bv<60>(projout_barrel_ps_4_dataarray_data_V_pc_buffer[hls_map_index].range(59, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (4) => (4) @ (2)
							for (int i_0 = 4; i_0 <= 4; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_ps[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_ps_dataarray__data__V_lv0_4_4_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_ps_dataarray__data__V_lv0_4_4_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_ps_4_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_ps_5_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_5_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_5_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_5_dataarray_data_V, AESL_token); // data

			sc_bv<60> *projout_barrel_ps_5_dataarray_data_V_pc_buffer = new sc_bv<60>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_5_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_5_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_ps_5_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_5_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_ps_5_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_ps_5_dataarray_data_V
				{
					// bitslice(59, 0)
					// {
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						// {
							sc_lv<60>* projout_barrel_ps_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<60>[256];
						// }
					// }

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (5) => (5) @ (2)
							for (int i_0 = 5; i_0 <= 5; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(59, 0) = sc_bv<60>(projout_barrel_ps_5_dataarray_data_V_pc_buffer[hls_map_index].range(59, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (5) => (5) @ (2)
							for (int i_0 = 5; i_0 <= 5; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_ps[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_ps_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_ps_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_ps_5_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_ps_6_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_6_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_6_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_6_dataarray_data_V, AESL_token); // data

			sc_bv<60> *projout_barrel_ps_6_dataarray_data_V_pc_buffer = new sc_bv<60>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_6_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_ps_6_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_ps_6_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_ps_6_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_ps_6_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_ps_6_dataarray_data_V
				{
					// bitslice(59, 0)
					// {
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						// {
							sc_lv<60>* projout_barrel_ps_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<60>[256];
						// }
					// }

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (6) => (6) @ (2)
							for (int i_0 = 6; i_0 <= 6; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(59, 0) = sc_bv<60>(projout_barrel_ps_6_dataarray_data_V_pc_buffer[hls_map_index].range(59, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(59, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
						{
							// carray: (6) => (6) @ (2)
							for (int i_0 = 6; i_0 <= 6; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_ps[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_ps_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_ps_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_ps_6_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_2s_1_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_1_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_1_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_1_dataarray_data_V, AESL_token); // data

			sc_bv<58> *projout_barrel_2s_1_dataarray_data_V_pc_buffer = new sc_bv<58>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_1_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_1_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_2s_1_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_1_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_2s_1_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_2s_1_dataarray_data_V
				{
					// bitslice(57, 0)
					// {
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						// {
							sc_lv<58>* projout_barrel_2s_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<58>[256];
						// }
					// }

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(57, 0) = sc_bv<58>(projout_barrel_2s_1_dataarray_data_V_pc_buffer[hls_map_index].range(57, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_2s[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_2s_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_2s_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_2s_1_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_2s_2_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_2_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_2_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_2_dataarray_data_V, AESL_token); // data

			sc_bv<58> *projout_barrel_2s_2_dataarray_data_V_pc_buffer = new sc_bv<58>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_2_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_2_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_2s_2_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_2_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_2s_2_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_2s_2_dataarray_data_V
				{
					// bitslice(57, 0)
					// {
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						// {
							sc_lv<58>* projout_barrel_2s_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<58>[256];
						// }
					// }

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(57, 0) = sc_bv<58>(projout_barrel_2s_2_dataarray_data_V_pc_buffer[hls_map_index].range(57, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_2s[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_2s_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_2s_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_2s_2_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_2s_3_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_3_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_3_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_3_dataarray_data_V, AESL_token); // data

			sc_bv<58> *projout_barrel_2s_3_dataarray_data_V_pc_buffer = new sc_bv<58>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_3_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_3_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_2s_3_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_3_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_2s_3_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_2s_3_dataarray_data_V
				{
					// bitslice(57, 0)
					// {
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						// {
							sc_lv<58>* projout_barrel_2s_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<58>[256];
						// }
					// }

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(57, 0) = sc_bv<58>(projout_barrel_2s_3_dataarray_data_V_pc_buffer[hls_map_index].range(57, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_2s[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_2s_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_2s_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_2s_3_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_2s_5_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_5_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_5_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_5_dataarray_data_V, AESL_token); // data

			sc_bv<58> *projout_barrel_2s_5_dataarray_data_V_pc_buffer = new sc_bv<58>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_5_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_5_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_2s_5_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_5_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_2s_5_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_2s_5_dataarray_data_V
				{
					// bitslice(57, 0)
					// {
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						// {
							sc_lv<58>* projout_barrel_2s_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<58>[256];
						// }
					// }

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (5) => (5) @ (2)
							for (int i_0 = 5; i_0 <= 5; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(57, 0) = sc_bv<58>(projout_barrel_2s_5_dataarray_data_V_pc_buffer[hls_map_index].range(57, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (5) => (5) @ (2)
							for (int i_0 = 5; i_0 <= 5; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_2s[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_2s_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_2s_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_2s_5_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_2s_6_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_6_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_6_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_6_dataarray_data_V, AESL_token); // data

			sc_bv<58> *projout_barrel_2s_6_dataarray_data_V_pc_buffer = new sc_bv<58>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_6_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_6_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_2s_6_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_6_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_2s_6_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_2s_6_dataarray_data_V
				{
					// bitslice(57, 0)
					// {
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						// {
							sc_lv<58>* projout_barrel_2s_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<58>[256];
						// }
					// }

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (6) => (6) @ (2)
							for (int i_0 = 6; i_0 <= 6; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(57, 0) = sc_bv<58>(projout_barrel_2s_6_dataarray_data_V_pc_buffer[hls_map_index].range(57, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (6) => (6) @ (2)
							for (int i_0 = 6; i_0 <= 6; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_2s[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_2s_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_2s_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_2s_6_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_barrel_2s_7_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_7_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_7_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_7_dataarray_data_V, AESL_token); // data

			sc_bv<58> *projout_barrel_2s_7_dataarray_data_V_pc_buffer = new sc_bv<58>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_7_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_barrel_2s_7_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_barrel_2s_7_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_barrel_2s_7_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_barrel_2s_7_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_barrel_2s_7_dataarray_data_V
				{
					// bitslice(57, 0)
					// {
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						// {
							sc_lv<58>* projout_barrel_2s_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<58>[256];
						// }
					// }

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (7) => (7) @ (2)
							for (int i_0 = 7; i_0 <= 7; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(57, 0) = sc_bv<58>(projout_barrel_2s_7_dataarray_data_V_pc_buffer[hls_map_index].range(57, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(57, 0)
					{
						int hls_map_index = 0;
						// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
						{
							// carray: (7) => (7) @ (2)
							for (int i_0 = 7; i_0 <= 7; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_barrel_2s[0].dataarray_[0][0].data_
										// output_left_conversion : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_barrel_2s_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_ = (projout_barrel_2s_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_barrel_2s_7_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_1_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_1_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_1_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_1_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_1_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_1_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_1_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_1_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_1_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_1_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_1_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_1_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_1_1_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_1_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_2_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_2_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_2_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_2_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_2_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_2_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_2_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_2_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_2_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_2_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_2_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_2_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_2_2_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_2_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_3_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_3_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_3_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_3_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_3_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_3_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_3_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_3_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_3_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_3_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_3_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_3_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_3_3_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_3_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_5_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_5_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_5_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_5_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_5_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_5_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_5_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_5_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_5_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_5_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_5_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (5) => (5) @ (2)
							for (int i_0 = 5; i_0 <= 5; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_5_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (5) => (5) @ (2)
							for (int i_0 = 5; i_0 <= 5; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_5_5_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_5_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_6_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_6_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_6_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_6_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_6_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_6_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_6_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_6_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_6_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_6_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_6_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (6) => (6) @ (2)
							for (int i_0 = 6; i_0 <= 6; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_6_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (6) => (6) @ (2)
							for (int i_0 = 6; i_0 <= 6; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_6_6_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_6_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_7_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_7_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_7_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_7_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_7_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_7_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_7_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_7_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_7_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_7_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_7_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (7) => (7) @ (2)
							for (int i_0 = 7; i_0 <= 7; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_7_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (7) => (7) @ (2)
							for (int i_0 = 7; i_0 <= 7; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_7_7_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_7_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_9_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_9_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_9_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_9_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_9_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_9_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_9_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_9_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_9_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_9_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_9_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_9_9_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (9) => (9) @ (2)
							for (int i_0 = 9; i_0 <= 9; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_9_9_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_9_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (9) => (9) @ (2)
							for (int i_0 = 9; i_0 <= 9; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_9_9_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_9_9_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_9_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_10_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_10_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_10_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_10_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_10_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_10_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_10_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_10_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_10_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_10_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_10_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_10_10_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (10) => (10) @ (2)
							for (int i_0 = 10; i_0 <= 10; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_10_10_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_10_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (10) => (10) @ (2)
							for (int i_0 = 10; i_0 <= 10; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_10_10_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_10_10_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_10_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_11_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_11_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_11_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_11_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_11_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_11_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_11_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_11_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_11_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_11_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_11_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_11_11_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (11) => (11) @ (2)
							for (int i_0 = 11; i_0 <= 11; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_11_11_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_11_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (11) => (11) @ (2)
							for (int i_0 = 11; i_0 <= 11; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_11_11_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_11_11_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_11_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_13_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_13_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_13_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_13_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_13_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_13_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_13_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_13_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_13_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_13_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_13_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_13_13_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (13) => (13) @ (2)
							for (int i_0 = 13; i_0 <= 13; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_13_13_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_13_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (13) => (13) @ (2)
							for (int i_0 = 13; i_0 <= 13; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_13_13_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_13_13_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_13_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_14_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_14_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_14_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_14_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_14_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_14_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_14_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_14_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_14_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_14_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_14_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_14_14_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (14) => (14) @ (2)
							for (int i_0 = 14; i_0 <= 14; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_14_14_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_14_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (14) => (14) @ (2)
							for (int i_0 = 14; i_0 <= 14; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_14_14_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_14_14_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_14_dataarray_data_V_pc_buffer;
		}

		// output port post check: "projout_disk_15_dataarray_data_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_15_dataarray_data_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_15_dataarray_data_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_15_dataarray_data_V, AESL_token); // data

			sc_bv<59> *projout_disk_15_dataarray_data_V_pc_buffer = new sc_bv<59>[256];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_15_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'projout_disk_15_dataarray_data_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					projout_disk_15_dataarray_data_V_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_projout_disk_15_dataarray_data_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_projout_disk_15_dataarray_data_V))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: projout_disk_15_dataarray_data_V
				{
					// bitslice(58, 0)
					// {
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						// {
							sc_lv<59>* projout_disk_dataarray__data__V_lv0_15_15_2_lv1_0_1_1_lv2_0_127_1 = new sc_lv<59>[256];
						// }
					// }

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (15) => (15) @ (2)
							for (int i_0 = 15; i_0 <= 15; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk_dataarray__data__V_lv0_15_15_2_lv1_0_1_1_lv2_0_127_1[hls_map_index].range(58, 0) = sc_bv<59>(projout_disk_15_dataarray_data_V_pc_buffer[hls_map_index].range(58, 0));
											hls_map_index++;
										}
									}
								}
							}
						}
					}

					// bitslice(58, 0)
					{
						int hls_map_index = 0;
						// celement: projout_disk.dataarray_.data_.V(58, 0)
						{
							// carray: (15) => (15) @ (2)
							for (int i_0 = 15; i_0 <= 15; i_0 += 2)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// carray: (0) => (127) @ (1)
									for (int i_2 = 0; i_2 <= 127; i_2 += 1)
									{
										// sub                    : i_0 i_1 i_2
										// ori_name               : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// sub_1st_elem           : 0 0 0
										// ori_name_1st_elem      : projout_disk[0].dataarray_[0][0].data_
										// output_left_conversion : projout_disk[i_0].dataarray_[i_1][i_2].data_
										// output_type_conversion : (projout_disk_dataarray__data__V_lv0_15_15_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str()
										if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
										{
											projout_disk[i_0].dataarray_[i_1][i_2].data_ = (projout_disk_dataarray__data__V_lv0_15_15_2_lv1_0_1_1_lv2_0_127_1[hls_map_index]).to_string(SC_BIN).c_str();
											hls_map_index++;
										}
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] projout_disk_15_dataarray_data_V_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "bx_V"
		char* tvin_bx_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_bx_V);

		// "lut_V"
		char* tvin_lut_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_lut_V);

		// "regionlut_V"
		char* tvin_regionlut_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_regionlut_V);

		// "innerStubs_dataarray_data_V"
		char* tvin_innerStubs_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_dataarray_data_V);

		// "innerStubs_0_nentries_0_V"
		char* tvin_innerStubs_0_nentries_0_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_0_V);

		// "innerStubs_0_nentries_1_V"
		char* tvin_innerStubs_0_nentries_1_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_1_V);

		// "innerStubs_0_nentries_2_V"
		char* tvin_innerStubs_0_nentries_2_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_2_V);

		// "innerStubs_0_nentries_3_V"
		char* tvin_innerStubs_0_nentries_3_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_3_V);

		// "innerStubs_0_nentries_4_V"
		char* tvin_innerStubs_0_nentries_4_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_4_V);

		// "innerStubs_0_nentries_5_V"
		char* tvin_innerStubs_0_nentries_5_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_5_V);

		// "innerStubs_0_nentries_6_V"
		char* tvin_innerStubs_0_nentries_6_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_6_V);

		// "innerStubs_0_nentries_7_V"
		char* tvin_innerStubs_0_nentries_7_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_0_nentries_7_V);

		// "innerStubs_1_nentries_0_V"
		char* tvin_innerStubs_1_nentries_0_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_0_V);

		// "innerStubs_1_nentries_1_V"
		char* tvin_innerStubs_1_nentries_1_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_1_V);

		// "innerStubs_1_nentries_2_V"
		char* tvin_innerStubs_1_nentries_2_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_2_V);

		// "innerStubs_1_nentries_3_V"
		char* tvin_innerStubs_1_nentries_3_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_3_V);

		// "innerStubs_1_nentries_4_V"
		char* tvin_innerStubs_1_nentries_4_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_4_V);

		// "innerStubs_1_nentries_5_V"
		char* tvin_innerStubs_1_nentries_5_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_5_V);

		// "innerStubs_1_nentries_6_V"
		char* tvin_innerStubs_1_nentries_6_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_6_V);

		// "innerStubs_1_nentries_7_V"
		char* tvin_innerStubs_1_nentries_7_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_1_nentries_7_V);

		// "innerStubs_2_nentries_0_V"
		char* tvin_innerStubs_2_nentries_0_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_0_V);

		// "innerStubs_2_nentries_1_V"
		char* tvin_innerStubs_2_nentries_1_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_1_V);

		// "innerStubs_2_nentries_2_V"
		char* tvin_innerStubs_2_nentries_2_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_2_V);

		// "innerStubs_2_nentries_3_V"
		char* tvin_innerStubs_2_nentries_3_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_3_V);

		// "innerStubs_2_nentries_4_V"
		char* tvin_innerStubs_2_nentries_4_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_4_V);

		// "innerStubs_2_nentries_5_V"
		char* tvin_innerStubs_2_nentries_5_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_5_V);

		// "innerStubs_2_nentries_6_V"
		char* tvin_innerStubs_2_nentries_6_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_6_V);

		// "innerStubs_2_nentries_7_V"
		char* tvin_innerStubs_2_nentries_7_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_innerStubs_2_nentries_7_V);

		// "outerStubs_dataarray_data_V"
		char* tvin_outerStubs_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerStubs_dataarray_data_V);

		// "outerVMStubs_dataarray_data_V_0"
		char* tvin_outerVMStubs_dataarray_data_V_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_0);

		// "outerVMStubs_dataarray_data_V_1"
		char* tvin_outerVMStubs_dataarray_data_V_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_1);

		// "outerVMStubs_binmask8_V_0_0"
		char* tvin_outerVMStubs_binmask8_V_0_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_0);

		// "outerVMStubs_binmask8_V_0_1"
		char* tvin_outerVMStubs_binmask8_V_0_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_1);

		// "outerVMStubs_binmask8_V_0_2"
		char* tvin_outerVMStubs_binmask8_V_0_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_2);

		// "outerVMStubs_binmask8_V_0_3"
		char* tvin_outerVMStubs_binmask8_V_0_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_3);

		// "outerVMStubs_binmask8_V_0_4"
		char* tvin_outerVMStubs_binmask8_V_0_4 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_4);

		// "outerVMStubs_binmask8_V_0_5"
		char* tvin_outerVMStubs_binmask8_V_0_5 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_5);

		// "outerVMStubs_binmask8_V_0_6"
		char* tvin_outerVMStubs_binmask8_V_0_6 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_6);

		// "outerVMStubs_binmask8_V_0_7"
		char* tvin_outerVMStubs_binmask8_V_0_7 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_7);

		// "outerVMStubs_binmask8_V_1_0"
		char* tvin_outerVMStubs_binmask8_V_1_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_0);

		// "outerVMStubs_binmask8_V_1_1"
		char* tvin_outerVMStubs_binmask8_V_1_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_1);

		// "outerVMStubs_binmask8_V_1_2"
		char* tvin_outerVMStubs_binmask8_V_1_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_2);

		// "outerVMStubs_binmask8_V_1_3"
		char* tvin_outerVMStubs_binmask8_V_1_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_3);

		// "outerVMStubs_binmask8_V_1_4"
		char* tvin_outerVMStubs_binmask8_V_1_4 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_4);

		// "outerVMStubs_binmask8_V_1_5"
		char* tvin_outerVMStubs_binmask8_V_1_5 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_5);

		// "outerVMStubs_binmask8_V_1_6"
		char* tvin_outerVMStubs_binmask8_V_1_6 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_6);

		// "outerVMStubs_binmask8_V_1_7"
		char* tvin_outerVMStubs_binmask8_V_1_7 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_7);

		// "outerVMStubs_nentries8_V_0_0"
		char* tvin_outerVMStubs_nentries8_V_0_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_0);

		// "outerVMStubs_nentries8_V_0_1"
		char* tvin_outerVMStubs_nentries8_V_0_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_1);

		// "outerVMStubs_nentries8_V_0_2"
		char* tvin_outerVMStubs_nentries8_V_0_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_2);

		// "outerVMStubs_nentries8_V_0_3"
		char* tvin_outerVMStubs_nentries8_V_0_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_3);

		// "outerVMStubs_nentries8_V_0_4"
		char* tvin_outerVMStubs_nentries8_V_0_4 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_4);

		// "outerVMStubs_nentries8_V_0_5"
		char* tvin_outerVMStubs_nentries8_V_0_5 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_5);

		// "outerVMStubs_nentries8_V_0_6"
		char* tvin_outerVMStubs_nentries8_V_0_6 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_6);

		// "outerVMStubs_nentries8_V_0_7"
		char* tvin_outerVMStubs_nentries8_V_0_7 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_7);

		// "outerVMStubs_nentries8_V_1_0"
		char* tvin_outerVMStubs_nentries8_V_1_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_0);

		// "outerVMStubs_nentries8_V_1_1"
		char* tvin_outerVMStubs_nentries8_V_1_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_1);

		// "outerVMStubs_nentries8_V_1_2"
		char* tvin_outerVMStubs_nentries8_V_1_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_2);

		// "outerVMStubs_nentries8_V_1_3"
		char* tvin_outerVMStubs_nentries8_V_1_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_3);

		// "outerVMStubs_nentries8_V_1_4"
		char* tvin_outerVMStubs_nentries8_V_1_4 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_4);

		// "outerVMStubs_nentries8_V_1_5"
		char* tvin_outerVMStubs_nentries8_V_1_5 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_5);

		// "outerVMStubs_nentries8_V_1_6"
		char* tvin_outerVMStubs_nentries8_V_1_6 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_6);

		// "outerVMStubs_nentries8_V_1_7"
		char* tvin_outerVMStubs_nentries8_V_1_7 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_7);

		// "trackletParameters_dataarray_data_V"
		char* tvin_trackletParameters_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_trackletParameters_dataarray_data_V);
		char* tvout_trackletParameters_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_trackletParameters_dataarray_data_V);

		// "projout_barrel_ps_3_dataarray_data_V"
		char* tvin_projout_barrel_ps_3_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_ps_3_dataarray_data_V);
		char* tvout_projout_barrel_ps_3_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_ps_3_dataarray_data_V);

		// "projout_barrel_ps_4_dataarray_data_V"
		char* tvin_projout_barrel_ps_4_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_ps_4_dataarray_data_V);
		char* tvout_projout_barrel_ps_4_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_ps_4_dataarray_data_V);

		// "projout_barrel_ps_5_dataarray_data_V"
		char* tvin_projout_barrel_ps_5_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_ps_5_dataarray_data_V);
		char* tvout_projout_barrel_ps_5_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_ps_5_dataarray_data_V);

		// "projout_barrel_ps_6_dataarray_data_V"
		char* tvin_projout_barrel_ps_6_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_ps_6_dataarray_data_V);
		char* tvout_projout_barrel_ps_6_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_ps_6_dataarray_data_V);

		// "projout_barrel_2s_1_dataarray_data_V"
		char* tvin_projout_barrel_2s_1_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_2s_1_dataarray_data_V);
		char* tvout_projout_barrel_2s_1_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_2s_1_dataarray_data_V);

		// "projout_barrel_2s_2_dataarray_data_V"
		char* tvin_projout_barrel_2s_2_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_2s_2_dataarray_data_V);
		char* tvout_projout_barrel_2s_2_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_2s_2_dataarray_data_V);

		// "projout_barrel_2s_3_dataarray_data_V"
		char* tvin_projout_barrel_2s_3_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_2s_3_dataarray_data_V);
		char* tvout_projout_barrel_2s_3_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_2s_3_dataarray_data_V);

		// "projout_barrel_2s_5_dataarray_data_V"
		char* tvin_projout_barrel_2s_5_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_2s_5_dataarray_data_V);
		char* tvout_projout_barrel_2s_5_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_2s_5_dataarray_data_V);

		// "projout_barrel_2s_6_dataarray_data_V"
		char* tvin_projout_barrel_2s_6_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_2s_6_dataarray_data_V);
		char* tvout_projout_barrel_2s_6_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_2s_6_dataarray_data_V);

		// "projout_barrel_2s_7_dataarray_data_V"
		char* tvin_projout_barrel_2s_7_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_barrel_2s_7_dataarray_data_V);
		char* tvout_projout_barrel_2s_7_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_barrel_2s_7_dataarray_data_V);

		// "projout_disk_1_dataarray_data_V"
		char* tvin_projout_disk_1_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_1_dataarray_data_V);
		char* tvout_projout_disk_1_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_1_dataarray_data_V);

		// "projout_disk_2_dataarray_data_V"
		char* tvin_projout_disk_2_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_2_dataarray_data_V);
		char* tvout_projout_disk_2_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_2_dataarray_data_V);

		// "projout_disk_3_dataarray_data_V"
		char* tvin_projout_disk_3_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_3_dataarray_data_V);
		char* tvout_projout_disk_3_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_3_dataarray_data_V);

		// "projout_disk_5_dataarray_data_V"
		char* tvin_projout_disk_5_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_5_dataarray_data_V);
		char* tvout_projout_disk_5_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_5_dataarray_data_V);

		// "projout_disk_6_dataarray_data_V"
		char* tvin_projout_disk_6_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_6_dataarray_data_V);
		char* tvout_projout_disk_6_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_6_dataarray_data_V);

		// "projout_disk_7_dataarray_data_V"
		char* tvin_projout_disk_7_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_7_dataarray_data_V);
		char* tvout_projout_disk_7_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_7_dataarray_data_V);

		// "projout_disk_9_dataarray_data_V"
		char* tvin_projout_disk_9_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_9_dataarray_data_V);
		char* tvout_projout_disk_9_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_9_dataarray_data_V);

		// "projout_disk_10_dataarray_data_V"
		char* tvin_projout_disk_10_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_10_dataarray_data_V);
		char* tvout_projout_disk_10_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_10_dataarray_data_V);

		// "projout_disk_11_dataarray_data_V"
		char* tvin_projout_disk_11_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_11_dataarray_data_V);
		char* tvout_projout_disk_11_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_11_dataarray_data_V);

		// "projout_disk_13_dataarray_data_V"
		char* tvin_projout_disk_13_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_13_dataarray_data_V);
		char* tvout_projout_disk_13_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_13_dataarray_data_V);

		// "projout_disk_14_dataarray_data_V"
		char* tvin_projout_disk_14_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_14_dataarray_data_V);
		char* tvout_projout_disk_14_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_14_dataarray_data_V);

		// "projout_disk_15_dataarray_data_V"
		char* tvin_projout_disk_15_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_projout_disk_15_dataarray_data_V);
		char* tvout_projout_disk_15_dataarray_data_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_projout_disk_15_dataarray_data_V);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_bx_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_bx_V, tvin_bx_V);

		sc_bv<3> bx_V_tvin_wrapc_buffer;

		// RTL Name: bx_V
		{
			// bitslice(2, 0)
			{
				// celement: bx.V(2, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : bx
						// sub_1st_elem          : 
						// ori_name_1st_elem     : bx
						// regulate_c_name       : bx_V
						// input_type_conversion : (bx).to_string(2).c_str()
						if (&(bx) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<3> bx_V_tmp_mem;
							bx_V_tmp_mem = (bx).to_string(2).c_str();
							bx_V_tvin_wrapc_buffer.range(2, 0) = bx_V_tmp_mem.range(2, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_bx_V, "%s\n", (bx_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_bx_V, tvin_bx_V);
		}

		tcl_file.set_num(1, &tcl_file.bx_V_depth);
		sprintf(tvin_bx_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_bx_V, tvin_bx_V);

		// [[transaction]]
		sprintf(tvin_lut_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_lut_V, tvin_lut_V);

		sc_bv<10>* lut_V_tvin_wrapc_buffer = new sc_bv<10>[2048];

		// RTL Name: lut_V
		{
			// bitslice(9, 0)
			{
				int hls_map_index = 0;
				// celement: lut.V(9, 0)
				{
					// carray: (0) => (2047) @ (1)
					for (int i_0 = 0; i_0 <= 2047; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : lut[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : lut[0]
						// regulate_c_name       : lut_V
						// input_type_conversion : (lut[i_0]).to_string(2).c_str()
						if (&(lut[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<10> lut_V_tmp_mem;
							lut_V_tmp_mem = (lut[i_0]).to_string(2).c_str();
							lut_V_tvin_wrapc_buffer[hls_map_index].range(9, 0) = lut_V_tmp_mem.range(9, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 2048; i++)
		{
			sprintf(tvin_lut_V, "%s\n", (lut_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_lut_V, tvin_lut_V);
		}

		tcl_file.set_num(2048, &tcl_file.lut_V_depth);
		sprintf(tvin_lut_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_lut_V, tvin_lut_V);

		// release memory allocation
		delete [] lut_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_regionlut_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_regionlut_V, tvin_regionlut_V);

		sc_bv<8>* regionlut_V_tvin_wrapc_buffer = new sc_bv<8>[2048];

		// RTL Name: regionlut_V
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: regionlut.V(7, 0)
				{
					// carray: (0) => (2047) @ (1)
					for (int i_0 = 0; i_0 <= 2047; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : regionlut[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : regionlut[0]
						// regulate_c_name       : regionlut_V
						// input_type_conversion : (regionlut[i_0]).to_string(2).c_str()
						if (&(regionlut[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> regionlut_V_tmp_mem;
							regionlut_V_tmp_mem = (regionlut[i_0]).to_string(2).c_str();
							regionlut_V_tvin_wrapc_buffer[hls_map_index].range(7, 0) = regionlut_V_tmp_mem.range(7, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 2048; i++)
		{
			sprintf(tvin_regionlut_V, "%s\n", (regionlut_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_regionlut_V, tvin_regionlut_V);
		}

		tcl_file.set_num(2048, &tcl_file.regionlut_V_depth);
		sprintf(tvin_regionlut_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_regionlut_V, tvin_regionlut_V);

		// release memory allocation
		delete [] regionlut_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_dataarray_data_V, tvin_innerStubs_dataarray_data_V);

		sc_bv<51>* innerStubs_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<51>[3072];

		// RTL Name: innerStubs_dataarray_data_V
		{
			// bitslice(50, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.dataarray_.data_.V(50, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (7) @ (1)
						for (int i_1 = 0; i_1 <= 7; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : innerStubs[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : innerStubs[0].dataarray_[0][0].data_
								// regulate_c_name       : innerStubs_dataarray__data__V
								// input_type_conversion : (innerStubs[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(innerStubs[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<51> innerStubs_dataarray__data__V_tmp_mem;
									innerStubs_dataarray__data__V_tmp_mem = (innerStubs[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									innerStubs_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(50, 0) = innerStubs_dataarray__data__V_tmp_mem.range(50, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 3072; i++)
		{
			sprintf(tvin_innerStubs_dataarray_data_V, "%s\n", (innerStubs_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_dataarray_data_V, tvin_innerStubs_dataarray_data_V);
		}

		tcl_file.set_num(3072, &tcl_file.innerStubs_dataarray_data_V_depth);
		sprintf(tvin_innerStubs_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_dataarray_data_V, tvin_innerStubs_dataarray_data_V);

		// release memory allocation
		delete [] innerStubs_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_0_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_0_V, tvin_innerStubs_0_nentries_0_V);

		sc_bv<7>* innerStubs_0_nentries_0_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_0_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_0_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_0_V, "%s\n", (innerStubs_0_nentries_0_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_0_V, tvin_innerStubs_0_nentries_0_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_0_V_depth);
		sprintf(tvin_innerStubs_0_nentries_0_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_0_V, tvin_innerStubs_0_nentries_0_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_0_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_1_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_1_V, tvin_innerStubs_0_nentries_1_V);

		sc_bv<7>* innerStubs_0_nentries_1_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_1_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_1_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_1_V, "%s\n", (innerStubs_0_nentries_1_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_1_V, tvin_innerStubs_0_nentries_1_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_1_V_depth);
		sprintf(tvin_innerStubs_0_nentries_1_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_1_V, tvin_innerStubs_0_nentries_1_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_1_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_2_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_2_V, tvin_innerStubs_0_nentries_2_V);

		sc_bv<7>* innerStubs_0_nentries_2_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_2_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_2_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_2_V, "%s\n", (innerStubs_0_nentries_2_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_2_V, tvin_innerStubs_0_nentries_2_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_2_V_depth);
		sprintf(tvin_innerStubs_0_nentries_2_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_2_V, tvin_innerStubs_0_nentries_2_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_2_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_3_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_3_V, tvin_innerStubs_0_nentries_3_V);

		sc_bv<7>* innerStubs_0_nentries_3_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_3_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_3_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_3_V, "%s\n", (innerStubs_0_nentries_3_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_3_V, tvin_innerStubs_0_nentries_3_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_3_V_depth);
		sprintf(tvin_innerStubs_0_nentries_3_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_3_V, tvin_innerStubs_0_nentries_3_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_3_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_4_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_4_V, tvin_innerStubs_0_nentries_4_V);

		sc_bv<7>* innerStubs_0_nentries_4_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_4_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_4_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_4_V, "%s\n", (innerStubs_0_nentries_4_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_4_V, tvin_innerStubs_0_nentries_4_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_4_V_depth);
		sprintf(tvin_innerStubs_0_nentries_4_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_4_V, tvin_innerStubs_0_nentries_4_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_4_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_5_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_5_V, tvin_innerStubs_0_nentries_5_V);

		sc_bv<7>* innerStubs_0_nentries_5_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_5_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_5_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_5_V, "%s\n", (innerStubs_0_nentries_5_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_5_V, tvin_innerStubs_0_nentries_5_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_5_V_depth);
		sprintf(tvin_innerStubs_0_nentries_5_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_5_V, tvin_innerStubs_0_nentries_5_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_5_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_6_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_6_V, tvin_innerStubs_0_nentries_6_V);

		sc_bv<7>* innerStubs_0_nentries_6_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_6_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_6_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_6_V, "%s\n", (innerStubs_0_nentries_6_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_6_V, tvin_innerStubs_0_nentries_6_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_6_V_depth);
		sprintf(tvin_innerStubs_0_nentries_6_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_6_V, tvin_innerStubs_0_nentries_6_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_6_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_0_nentries_7_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_7_V, tvin_innerStubs_0_nentries_7_V);

		sc_bv<7>* innerStubs_0_nentries_7_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_0_nentries_7_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_0_nentries_7_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_0_nentries_7_V, "%s\n", (innerStubs_0_nentries_7_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_7_V, tvin_innerStubs_0_nentries_7_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_0_nentries_7_V_depth);
		sprintf(tvin_innerStubs_0_nentries_7_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_0_nentries_7_V, tvin_innerStubs_0_nentries_7_V);

		// release memory allocation
		delete [] innerStubs_0_nentries_7_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_0_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_0_V, tvin_innerStubs_1_nentries_0_V);

		sc_bv<7>* innerStubs_1_nentries_0_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_0_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_0_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_0_V, "%s\n", (innerStubs_1_nentries_0_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_0_V, tvin_innerStubs_1_nentries_0_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_0_V_depth);
		sprintf(tvin_innerStubs_1_nentries_0_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_0_V, tvin_innerStubs_1_nentries_0_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_0_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_1_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_1_V, tvin_innerStubs_1_nentries_1_V);

		sc_bv<7>* innerStubs_1_nentries_1_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_1_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_1_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_1_V, "%s\n", (innerStubs_1_nentries_1_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_1_V, tvin_innerStubs_1_nentries_1_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_1_V_depth);
		sprintf(tvin_innerStubs_1_nentries_1_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_1_V, tvin_innerStubs_1_nentries_1_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_1_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_2_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_2_V, tvin_innerStubs_1_nentries_2_V);

		sc_bv<7>* innerStubs_1_nentries_2_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_2_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_2_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_2_V, "%s\n", (innerStubs_1_nentries_2_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_2_V, tvin_innerStubs_1_nentries_2_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_2_V_depth);
		sprintf(tvin_innerStubs_1_nentries_2_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_2_V, tvin_innerStubs_1_nentries_2_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_2_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_3_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_3_V, tvin_innerStubs_1_nentries_3_V);

		sc_bv<7>* innerStubs_1_nentries_3_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_3_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_3_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_3_V, "%s\n", (innerStubs_1_nentries_3_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_3_V, tvin_innerStubs_1_nentries_3_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_3_V_depth);
		sprintf(tvin_innerStubs_1_nentries_3_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_3_V, tvin_innerStubs_1_nentries_3_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_3_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_4_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_4_V, tvin_innerStubs_1_nentries_4_V);

		sc_bv<7>* innerStubs_1_nentries_4_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_4_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_4_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_4_V, "%s\n", (innerStubs_1_nentries_4_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_4_V, tvin_innerStubs_1_nentries_4_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_4_V_depth);
		sprintf(tvin_innerStubs_1_nentries_4_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_4_V, tvin_innerStubs_1_nentries_4_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_4_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_5_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_5_V, tvin_innerStubs_1_nentries_5_V);

		sc_bv<7>* innerStubs_1_nentries_5_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_5_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_5_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_5_V, "%s\n", (innerStubs_1_nentries_5_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_5_V, tvin_innerStubs_1_nentries_5_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_5_V_depth);
		sprintf(tvin_innerStubs_1_nentries_5_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_5_V, tvin_innerStubs_1_nentries_5_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_5_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_6_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_6_V, tvin_innerStubs_1_nentries_6_V);

		sc_bv<7>* innerStubs_1_nentries_6_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_6_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_6_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_6_V, "%s\n", (innerStubs_1_nentries_6_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_6_V, tvin_innerStubs_1_nentries_6_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_6_V_depth);
		sprintf(tvin_innerStubs_1_nentries_6_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_6_V, tvin_innerStubs_1_nentries_6_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_6_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_1_nentries_7_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_7_V, tvin_innerStubs_1_nentries_7_V);

		sc_bv<7>* innerStubs_1_nentries_7_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_1_nentries_7_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_1_nentries_7_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_1_nentries_7_V, "%s\n", (innerStubs_1_nentries_7_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_7_V, tvin_innerStubs_1_nentries_7_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_1_nentries_7_V_depth);
		sprintf(tvin_innerStubs_1_nentries_7_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_1_nentries_7_V, tvin_innerStubs_1_nentries_7_V);

		// release memory allocation
		delete [] innerStubs_1_nentries_7_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_0_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_0_V, tvin_innerStubs_2_nentries_0_V);

		sc_bv<7>* innerStubs_2_nentries_0_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_0_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_0_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_0_V, "%s\n", (innerStubs_2_nentries_0_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_0_V, tvin_innerStubs_2_nentries_0_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_0_V_depth);
		sprintf(tvin_innerStubs_2_nentries_0_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_0_V, tvin_innerStubs_2_nentries_0_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_0_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_1_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_1_V, tvin_innerStubs_2_nentries_1_V);

		sc_bv<7>* innerStubs_2_nentries_1_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_1_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_1_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_1_V, "%s\n", (innerStubs_2_nentries_1_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_1_V, tvin_innerStubs_2_nentries_1_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_1_V_depth);
		sprintf(tvin_innerStubs_2_nentries_1_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_1_V, tvin_innerStubs_2_nentries_1_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_1_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_2_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_2_V, tvin_innerStubs_2_nentries_2_V);

		sc_bv<7>* innerStubs_2_nentries_2_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_2_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_2_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_2_V, "%s\n", (innerStubs_2_nentries_2_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_2_V, tvin_innerStubs_2_nentries_2_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_2_V_depth);
		sprintf(tvin_innerStubs_2_nentries_2_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_2_V, tvin_innerStubs_2_nentries_2_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_2_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_3_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_3_V, tvin_innerStubs_2_nentries_3_V);

		sc_bv<7>* innerStubs_2_nentries_3_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_3_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_3_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_3_V, "%s\n", (innerStubs_2_nentries_3_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_3_V, tvin_innerStubs_2_nentries_3_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_3_V_depth);
		sprintf(tvin_innerStubs_2_nentries_3_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_3_V, tvin_innerStubs_2_nentries_3_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_3_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_4_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_4_V, tvin_innerStubs_2_nentries_4_V);

		sc_bv<7>* innerStubs_2_nentries_4_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_4_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_4_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_4_V, "%s\n", (innerStubs_2_nentries_4_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_4_V, tvin_innerStubs_2_nentries_4_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_4_V_depth);
		sprintf(tvin_innerStubs_2_nentries_4_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_4_V, tvin_innerStubs_2_nentries_4_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_4_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_5_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_5_V, tvin_innerStubs_2_nentries_5_V);

		sc_bv<7>* innerStubs_2_nentries_5_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_5_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_5_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_5_V, "%s\n", (innerStubs_2_nentries_5_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_5_V, tvin_innerStubs_2_nentries_5_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_5_V_depth);
		sprintf(tvin_innerStubs_2_nentries_5_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_5_V, tvin_innerStubs_2_nentries_5_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_5_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_6_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_6_V, tvin_innerStubs_2_nentries_6_V);

		sc_bv<7>* innerStubs_2_nentries_6_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_6_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_6_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_6_V, "%s\n", (innerStubs_2_nentries_6_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_6_V, tvin_innerStubs_2_nentries_6_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_6_V_depth);
		sprintf(tvin_innerStubs_2_nentries_6_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_6_V, tvin_innerStubs_2_nentries_6_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_6_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_innerStubs_2_nentries_7_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_7_V, tvin_innerStubs_2_nentries_7_V);

		sc_bv<7>* innerStubs_2_nentries_7_V_tvin_wrapc_buffer = new sc_bv<7>[1];

		// RTL Name: innerStubs_2_nentries_7_V
		{
			// bitslice(6, 0)
			{
				int hls_map_index = 0;
				// celement: innerStubs.nentries_.V(6, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : innerStubs[i_0].nentries_[i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : innerStubs[0].nentries_[0]
							// regulate_c_name       : innerStubs_nentries__V
							// input_type_conversion : (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str()
							if (&(innerStubs[0].nentries_[0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<7> innerStubs_nentries__V_tmp_mem;
								innerStubs_nentries__V_tmp_mem = (innerStubs[i_0].nentries_[i_1]).to_string(2).c_str();
								innerStubs_2_nentries_7_V_tvin_wrapc_buffer[hls_map_index].range(6, 0) = innerStubs_nentries__V_tmp_mem.range(6, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_innerStubs_2_nentries_7_V, "%s\n", (innerStubs_2_nentries_7_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_7_V, tvin_innerStubs_2_nentries_7_V);
		}

		tcl_file.set_num(1, &tcl_file.innerStubs_2_nentries_7_V_depth);
		sprintf(tvin_innerStubs_2_nentries_7_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_innerStubs_2_nentries_7_V, tvin_innerStubs_2_nentries_7_V);

		// release memory allocation
		delete [] innerStubs_2_nentries_7_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerStubs_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerStubs_dataarray_data_V, tvin_outerStubs_dataarray_data_V);

		sc_bv<36>* outerStubs_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<36>[1024];

		// RTL Name: outerStubs_dataarray_data_V
		{
			// bitslice(35, 0)
			{
				int hls_map_index = 0;
				// celement: outerStubs.dataarray_.data_.V(35, 0)
				{
					// carray: (0) => (7) @ (1)
					for (int i_0 = 0; i_0 <= 7; i_0 += 1)
					{
						// carray: (0) => (127) @ (1)
						for (int i_1 = 0; i_1 <= 127; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerStubs->dataarray_[i_0][i_1].data_
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerStubs->dataarray_[0][0].data_
							// regulate_c_name       : outerStubs_dataarray__data__V
							// input_type_conversion : (outerStubs->dataarray_[i_0][i_1].data_).to_string(2).c_str()
							if (&(outerStubs->dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<36> outerStubs_dataarray__data__V_tmp_mem;
								outerStubs_dataarray__data__V_tmp_mem = (outerStubs->dataarray_[i_0][i_1].data_).to_string(2).c_str();
								outerStubs_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(35, 0) = outerStubs_dataarray__data__V_tmp_mem.range(35, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1024; i++)
		{
			sprintf(tvin_outerStubs_dataarray_data_V, "%s\n", (outerStubs_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerStubs_dataarray_data_V, tvin_outerStubs_dataarray_data_V);
		}

		tcl_file.set_num(1024, &tcl_file.outerStubs_dataarray_data_V_depth);
		sprintf(tvin_outerStubs_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerStubs_dataarray_data_V, tvin_outerStubs_dataarray_data_V);

		// release memory allocation
		delete [] outerStubs_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_dataarray_data_V_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_0, tvin_outerVMStubs_dataarray_data_V_0);

		sc_bv<16>* outerVMStubs_dataarray_data_V_0_tvin_wrapc_buffer = new sc_bv<16>[2048];

		// RTL Name: outerVMStubs_dataarray_data_V_0
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.dataarray_.data_.V(15, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (1023) @ (1)
							for (int i_2 = 0; i_2 <= 1023; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : outerVMStubs.dataarray_[i_0][i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : outerVMStubs.dataarray_[0][0][0].data_
								// regulate_c_name       : outerVMStubs_dataarray__data__V
								// input_type_conversion : (outerVMStubs.dataarray_[i_0][i_1][i_2].data_).to_string(2).c_str()
								if (&(outerVMStubs.dataarray_[0][0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<16> outerVMStubs_dataarray__data__V_tmp_mem;
									outerVMStubs_dataarray__data__V_tmp_mem = (outerVMStubs.dataarray_[i_0][i_1][i_2].data_).to_string(2).c_str();
									outerVMStubs_dataarray_data_V_0_tvin_wrapc_buffer[hls_map_index].range(15, 0) = outerVMStubs_dataarray__data__V_tmp_mem.range(15, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 2048; i++)
		{
			sprintf(tvin_outerVMStubs_dataarray_data_V_0, "%s\n", (outerVMStubs_dataarray_data_V_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_0, tvin_outerVMStubs_dataarray_data_V_0);
		}

		tcl_file.set_num(2048, &tcl_file.outerVMStubs_dataarray_data_V_0_depth);
		sprintf(tvin_outerVMStubs_dataarray_data_V_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_0, tvin_outerVMStubs_dataarray_data_V_0);

		// release memory allocation
		delete [] outerVMStubs_dataarray_data_V_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_dataarray_data_V_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_1, tvin_outerVMStubs_dataarray_data_V_1);

		sc_bv<16>* outerVMStubs_dataarray_data_V_1_tvin_wrapc_buffer = new sc_bv<16>[2048];

		// RTL Name: outerVMStubs_dataarray_data_V_1
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.dataarray_.data_.V(15, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (1023) @ (1)
							for (int i_2 = 0; i_2 <= 1023; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : outerVMStubs.dataarray_[i_0][i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : outerVMStubs.dataarray_[0][0][0].data_
								// regulate_c_name       : outerVMStubs_dataarray__data__V
								// input_type_conversion : (outerVMStubs.dataarray_[i_0][i_1][i_2].data_).to_string(2).c_str()
								if (&(outerVMStubs.dataarray_[0][0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<16> outerVMStubs_dataarray__data__V_tmp_mem;
									outerVMStubs_dataarray__data__V_tmp_mem = (outerVMStubs.dataarray_[i_0][i_1][i_2].data_).to_string(2).c_str();
									outerVMStubs_dataarray_data_V_1_tvin_wrapc_buffer[hls_map_index].range(15, 0) = outerVMStubs_dataarray__data__V_tmp_mem.range(15, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 2048; i++)
		{
			sprintf(tvin_outerVMStubs_dataarray_data_V_1, "%s\n", (outerVMStubs_dataarray_data_V_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_1, tvin_outerVMStubs_dataarray_data_V_1);
		}

		tcl_file.set_num(2048, &tcl_file.outerVMStubs_dataarray_data_V_1_depth);
		sprintf(tvin_outerVMStubs_dataarray_data_V_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_dataarray_data_V_1, tvin_outerVMStubs_dataarray_data_V_1);

		// release memory allocation
		delete [] outerVMStubs_dataarray_data_V_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_0, tvin_outerVMStubs_binmask8_V_0_0);

		sc_bv<8>* outerVMStubs_binmask8_V_0_0_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_0
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_0_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_0, "%s\n", (outerVMStubs_binmask8_V_0_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_0, tvin_outerVMStubs_binmask8_V_0_0);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_0_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_0, tvin_outerVMStubs_binmask8_V_0_0);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_1, tvin_outerVMStubs_binmask8_V_0_1);

		sc_bv<8>* outerVMStubs_binmask8_V_0_1_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_1
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_1_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_1, "%s\n", (outerVMStubs_binmask8_V_0_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_1, tvin_outerVMStubs_binmask8_V_0_1);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_1_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_1, tvin_outerVMStubs_binmask8_V_0_1);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_2, tvin_outerVMStubs_binmask8_V_0_2);

		sc_bv<8>* outerVMStubs_binmask8_V_0_2_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_2
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_2_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_2, "%s\n", (outerVMStubs_binmask8_V_0_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_2, tvin_outerVMStubs_binmask8_V_0_2);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_2_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_2, tvin_outerVMStubs_binmask8_V_0_2);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_3, tvin_outerVMStubs_binmask8_V_0_3);

		sc_bv<8>* outerVMStubs_binmask8_V_0_3_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_3
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_3_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_3, "%s\n", (outerVMStubs_binmask8_V_0_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_3, tvin_outerVMStubs_binmask8_V_0_3);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_3_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_3, tvin_outerVMStubs_binmask8_V_0_3);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_3_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_4, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_4, tvin_outerVMStubs_binmask8_V_0_4);

		sc_bv<8>* outerVMStubs_binmask8_V_0_4_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_4
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_4_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_4, "%s\n", (outerVMStubs_binmask8_V_0_4_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_4, tvin_outerVMStubs_binmask8_V_0_4);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_4_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_4, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_4, tvin_outerVMStubs_binmask8_V_0_4);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_4_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_5, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_5, tvin_outerVMStubs_binmask8_V_0_5);

		sc_bv<8>* outerVMStubs_binmask8_V_0_5_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_5
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_5_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_5, "%s\n", (outerVMStubs_binmask8_V_0_5_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_5, tvin_outerVMStubs_binmask8_V_0_5);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_5_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_5, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_5, tvin_outerVMStubs_binmask8_V_0_5);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_5_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_6, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_6, tvin_outerVMStubs_binmask8_V_0_6);

		sc_bv<8>* outerVMStubs_binmask8_V_0_6_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_6
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_6_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_6, "%s\n", (outerVMStubs_binmask8_V_0_6_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_6, tvin_outerVMStubs_binmask8_V_0_6);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_6_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_6, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_6, tvin_outerVMStubs_binmask8_V_0_6);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_6_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_0_7, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_7, tvin_outerVMStubs_binmask8_V_0_7);

		sc_bv<8>* outerVMStubs_binmask8_V_0_7_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_0_7
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_0_7_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_0_7, "%s\n", (outerVMStubs_binmask8_V_0_7_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_7, tvin_outerVMStubs_binmask8_V_0_7);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_0_7_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_0_7, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_0_7, tvin_outerVMStubs_binmask8_V_0_7);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_0_7_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_0, tvin_outerVMStubs_binmask8_V_1_0);

		sc_bv<8>* outerVMStubs_binmask8_V_1_0_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_0
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_0_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_0, "%s\n", (outerVMStubs_binmask8_V_1_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_0, tvin_outerVMStubs_binmask8_V_1_0);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_0_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_0, tvin_outerVMStubs_binmask8_V_1_0);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_1, tvin_outerVMStubs_binmask8_V_1_1);

		sc_bv<8>* outerVMStubs_binmask8_V_1_1_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_1
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_1_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_1, "%s\n", (outerVMStubs_binmask8_V_1_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_1, tvin_outerVMStubs_binmask8_V_1_1);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_1_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_1, tvin_outerVMStubs_binmask8_V_1_1);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_2, tvin_outerVMStubs_binmask8_V_1_2);

		sc_bv<8>* outerVMStubs_binmask8_V_1_2_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_2
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_2_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_2, "%s\n", (outerVMStubs_binmask8_V_1_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_2, tvin_outerVMStubs_binmask8_V_1_2);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_2_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_2, tvin_outerVMStubs_binmask8_V_1_2);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_3, tvin_outerVMStubs_binmask8_V_1_3);

		sc_bv<8>* outerVMStubs_binmask8_V_1_3_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_3
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_3_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_3, "%s\n", (outerVMStubs_binmask8_V_1_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_3, tvin_outerVMStubs_binmask8_V_1_3);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_3_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_3, tvin_outerVMStubs_binmask8_V_1_3);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_3_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_4, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_4, tvin_outerVMStubs_binmask8_V_1_4);

		sc_bv<8>* outerVMStubs_binmask8_V_1_4_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_4
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_4_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_4, "%s\n", (outerVMStubs_binmask8_V_1_4_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_4, tvin_outerVMStubs_binmask8_V_1_4);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_4_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_4, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_4, tvin_outerVMStubs_binmask8_V_1_4);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_4_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_5, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_5, tvin_outerVMStubs_binmask8_V_1_5);

		sc_bv<8>* outerVMStubs_binmask8_V_1_5_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_5
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_5_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_5, "%s\n", (outerVMStubs_binmask8_V_1_5_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_5, tvin_outerVMStubs_binmask8_V_1_5);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_5_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_5, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_5, tvin_outerVMStubs_binmask8_V_1_5);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_5_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_6, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_6, tvin_outerVMStubs_binmask8_V_1_6);

		sc_bv<8>* outerVMStubs_binmask8_V_1_6_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_6
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_6_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_6, "%s\n", (outerVMStubs_binmask8_V_1_6_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_6, tvin_outerVMStubs_binmask8_V_1_6);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_6_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_6, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_6, tvin_outerVMStubs_binmask8_V_1_6);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_6_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_binmask8_V_1_7, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_7, tvin_outerVMStubs_binmask8_V_1_7);

		sc_bv<8>* outerVMStubs_binmask8_V_1_7_tvin_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: outerVMStubs_binmask8_V_1_7
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.binmask8_.V(7, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.binmask8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.binmask8_[0][0]
							// regulate_c_name       : outerVMStubs_binmask8__V
							// input_type_conversion : (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.binmask8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<8> outerVMStubs_binmask8__V_tmp_mem;
								outerVMStubs_binmask8__V_tmp_mem = (outerVMStubs.binmask8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_binmask8_V_1_7_tvin_wrapc_buffer[hls_map_index].range(7, 0) = outerVMStubs_binmask8__V_tmp_mem.range(7, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_binmask8_V_1_7, "%s\n", (outerVMStubs_binmask8_V_1_7_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_7, tvin_outerVMStubs_binmask8_V_1_7);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_binmask8_V_1_7_depth);
		sprintf(tvin_outerVMStubs_binmask8_V_1_7, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_binmask8_V_1_7, tvin_outerVMStubs_binmask8_V_1_7);

		// release memory allocation
		delete [] outerVMStubs_binmask8_V_1_7_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_0, tvin_outerVMStubs_nentries8_V_0_0);

		sc_bv<32>* outerVMStubs_nentries8_V_0_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_0, "%s\n", (outerVMStubs_nentries8_V_0_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_0, tvin_outerVMStubs_nentries8_V_0_0);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_0_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_0, tvin_outerVMStubs_nentries8_V_0_0);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_1, tvin_outerVMStubs_nentries8_V_0_1);

		sc_bv<32>* outerVMStubs_nentries8_V_0_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_1, "%s\n", (outerVMStubs_nentries8_V_0_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_1, tvin_outerVMStubs_nentries8_V_0_1);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_1_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_1, tvin_outerVMStubs_nentries8_V_0_1);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_2, tvin_outerVMStubs_nentries8_V_0_2);

		sc_bv<32>* outerVMStubs_nentries8_V_0_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_2, "%s\n", (outerVMStubs_nentries8_V_0_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_2, tvin_outerVMStubs_nentries8_V_0_2);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_2_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_2, tvin_outerVMStubs_nentries8_V_0_2);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_3, tvin_outerVMStubs_nentries8_V_0_3);

		sc_bv<32>* outerVMStubs_nentries8_V_0_3_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_3_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_3, "%s\n", (outerVMStubs_nentries8_V_0_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_3, tvin_outerVMStubs_nentries8_V_0_3);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_3_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_3, tvin_outerVMStubs_nentries8_V_0_3);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_3_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_4, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_4, tvin_outerVMStubs_nentries8_V_0_4);

		sc_bv<32>* outerVMStubs_nentries8_V_0_4_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_4
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_4_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_4, "%s\n", (outerVMStubs_nentries8_V_0_4_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_4, tvin_outerVMStubs_nentries8_V_0_4);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_4_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_4, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_4, tvin_outerVMStubs_nentries8_V_0_4);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_4_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_5, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_5, tvin_outerVMStubs_nentries8_V_0_5);

		sc_bv<32>* outerVMStubs_nentries8_V_0_5_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_5
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_5_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_5, "%s\n", (outerVMStubs_nentries8_V_0_5_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_5, tvin_outerVMStubs_nentries8_V_0_5);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_5_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_5, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_5, tvin_outerVMStubs_nentries8_V_0_5);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_5_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_6, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_6, tvin_outerVMStubs_nentries8_V_0_6);

		sc_bv<32>* outerVMStubs_nentries8_V_0_6_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_6
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_6_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_6, "%s\n", (outerVMStubs_nentries8_V_0_6_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_6, tvin_outerVMStubs_nentries8_V_0_6);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_6_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_6, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_6, tvin_outerVMStubs_nentries8_V_0_6);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_6_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_0_7, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_7, tvin_outerVMStubs_nentries8_V_0_7);

		sc_bv<32>* outerVMStubs_nentries8_V_0_7_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_0_7
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_0_7_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_0_7, "%s\n", (outerVMStubs_nentries8_V_0_7_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_7, tvin_outerVMStubs_nentries8_V_0_7);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_0_7_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_0_7, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_0_7, tvin_outerVMStubs_nentries8_V_0_7);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_0_7_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_0, tvin_outerVMStubs_nentries8_V_1_0);

		sc_bv<32>* outerVMStubs_nentries8_V_1_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_0, "%s\n", (outerVMStubs_nentries8_V_1_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_0, tvin_outerVMStubs_nentries8_V_1_0);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_0_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_0, tvin_outerVMStubs_nentries8_V_1_0);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_1, tvin_outerVMStubs_nentries8_V_1_1);

		sc_bv<32>* outerVMStubs_nentries8_V_1_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_1, "%s\n", (outerVMStubs_nentries8_V_1_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_1, tvin_outerVMStubs_nentries8_V_1_1);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_1_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_1, tvin_outerVMStubs_nentries8_V_1_1);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_2, tvin_outerVMStubs_nentries8_V_1_2);

		sc_bv<32>* outerVMStubs_nentries8_V_1_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_2, "%s\n", (outerVMStubs_nentries8_V_1_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_2, tvin_outerVMStubs_nentries8_V_1_2);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_2_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_2, tvin_outerVMStubs_nentries8_V_1_2);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_3, tvin_outerVMStubs_nentries8_V_1_3);

		sc_bv<32>* outerVMStubs_nentries8_V_1_3_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (3) => (3) @ (2)
						for (int i_1 = 3; i_1 <= 3; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_3_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_3, "%s\n", (outerVMStubs_nentries8_V_1_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_3, tvin_outerVMStubs_nentries8_V_1_3);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_3_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_3, tvin_outerVMStubs_nentries8_V_1_3);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_3_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_4, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_4, tvin_outerVMStubs_nentries8_V_1_4);

		sc_bv<32>* outerVMStubs_nentries8_V_1_4_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_4
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (4) => (4) @ (2)
						for (int i_1 = 4; i_1 <= 4; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_4_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_4, "%s\n", (outerVMStubs_nentries8_V_1_4_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_4, tvin_outerVMStubs_nentries8_V_1_4);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_4_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_4, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_4, tvin_outerVMStubs_nentries8_V_1_4);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_4_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_5, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_5, tvin_outerVMStubs_nentries8_V_1_5);

		sc_bv<32>* outerVMStubs_nentries8_V_1_5_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_5
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (5) => (5) @ (2)
						for (int i_1 = 5; i_1 <= 5; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_5_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_5, "%s\n", (outerVMStubs_nentries8_V_1_5_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_5, tvin_outerVMStubs_nentries8_V_1_5);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_5_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_5, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_5, tvin_outerVMStubs_nentries8_V_1_5);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_5_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_6, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_6, tvin_outerVMStubs_nentries8_V_1_6);

		sc_bv<32>* outerVMStubs_nentries8_V_1_6_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_6
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (6) => (6) @ (2)
						for (int i_1 = 6; i_1 <= 6; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_6_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_6, "%s\n", (outerVMStubs_nentries8_V_1_6_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_6, tvin_outerVMStubs_nentries8_V_1_6);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_6_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_6, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_6, tvin_outerVMStubs_nentries8_V_1_6);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_6_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_outerVMStubs_nentries8_V_1_7, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_7, tvin_outerVMStubs_nentries8_V_1_7);

		sc_bv<32>* outerVMStubs_nentries8_V_1_7_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: outerVMStubs_nentries8_V_1_7
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: outerVMStubs.nentries8_.V(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (7) => (7) @ (2)
						for (int i_1 = 7; i_1 <= 7; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : outerVMStubs.nentries8_[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : outerVMStubs.nentries8_[0][0]
							// regulate_c_name       : outerVMStubs_nentries8__V
							// input_type_conversion : (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str()
							if (&(outerVMStubs.nentries8_[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> outerVMStubs_nentries8__V_tmp_mem;
								outerVMStubs_nentries8__V_tmp_mem = (outerVMStubs.nentries8_[i_0][i_1]).to_string(2).c_str();
								outerVMStubs_nentries8_V_1_7_tvin_wrapc_buffer[hls_map_index].range(31, 0) = outerVMStubs_nentries8__V_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_outerVMStubs_nentries8_V_1_7, "%s\n", (outerVMStubs_nentries8_V_1_7_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_7, tvin_outerVMStubs_nentries8_V_1_7);
		}

		tcl_file.set_num(1, &tcl_file.outerVMStubs_nentries8_V_1_7_depth);
		sprintf(tvin_outerVMStubs_nentries8_V_1_7, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_outerVMStubs_nentries8_V_1_7, tvin_outerVMStubs_nentries8_V_1_7);

		// release memory allocation
		delete [] outerVMStubs_nentries8_V_1_7_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_trackletParameters_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_trackletParameters_dataarray_data_V, tvin_trackletParameters_dataarray_data_V);

		sc_bv<70>* trackletParameters_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<70>[1024];

		// RTL Name: trackletParameters_dataarray_data_V
		{
			// bitslice(69, 0)
			{
				int hls_map_index = 0;
				// celement: trackletParameters.dataarray_.data_.V(69, 0)
				{
					// carray: (0) => (7) @ (1)
					for (int i_0 = 0; i_0 <= 7; i_0 += 1)
					{
						// carray: (0) => (127) @ (1)
						for (int i_1 = 0; i_1 <= 127; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : trackletParameters->dataarray_[i_0][i_1].data_
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : trackletParameters->dataarray_[0][0].data_
							// regulate_c_name       : trackletParameters_dataarray__data__V
							// input_type_conversion : (trackletParameters->dataarray_[i_0][i_1].data_).to_string(2).c_str()
							if (&(trackletParameters->dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<70> trackletParameters_dataarray__data__V_tmp_mem;
								trackletParameters_dataarray__data__V_tmp_mem = (trackletParameters->dataarray_[i_0][i_1].data_).to_string(2).c_str();
								trackletParameters_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(69, 0) = trackletParameters_dataarray__data__V_tmp_mem.range(69, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1024; i++)
		{
			sprintf(tvin_trackletParameters_dataarray_data_V, "%s\n", (trackletParameters_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_trackletParameters_dataarray_data_V, tvin_trackletParameters_dataarray_data_V);
		}

		tcl_file.set_num(1024, &tcl_file.trackletParameters_dataarray_data_V_depth);
		sprintf(tvin_trackletParameters_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_trackletParameters_dataarray_data_V, tvin_trackletParameters_dataarray_data_V);

		// release memory allocation
		delete [] trackletParameters_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_ps_3_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_3_dataarray_data_V, tvin_projout_barrel_ps_3_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_3_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_3_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_3_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_ps_3_dataarray_data_V, "%s\n", (projout_barrel_ps_3_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_3_dataarray_data_V, tvin_projout_barrel_ps_3_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_3_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_ps_3_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_3_dataarray_data_V, tvin_projout_barrel_ps_3_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_3_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_ps_4_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_4_dataarray_data_V, tvin_projout_barrel_ps_4_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_4_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_4_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (4) => (4) @ (2)
					for (int i_0 = 4; i_0 <= 4; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_4_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_ps_4_dataarray_data_V, "%s\n", (projout_barrel_ps_4_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_4_dataarray_data_V, tvin_projout_barrel_ps_4_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_4_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_ps_4_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_4_dataarray_data_V, tvin_projout_barrel_ps_4_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_4_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_ps_5_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_5_dataarray_data_V, tvin_projout_barrel_ps_5_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_5_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_5_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (5) => (5) @ (2)
					for (int i_0 = 5; i_0 <= 5; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_5_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_ps_5_dataarray_data_V, "%s\n", (projout_barrel_ps_5_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_5_dataarray_data_V, tvin_projout_barrel_ps_5_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_5_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_ps_5_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_5_dataarray_data_V, tvin_projout_barrel_ps_5_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_5_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_ps_6_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_6_dataarray_data_V, tvin_projout_barrel_ps_6_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_6_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_6_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (6) => (6) @ (2)
					for (int i_0 = 6; i_0 <= 6; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_6_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_ps_6_dataarray_data_V, "%s\n", (projout_barrel_ps_6_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_6_dataarray_data_V, tvin_projout_barrel_ps_6_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_6_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_ps_6_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_ps_6_dataarray_data_V, tvin_projout_barrel_ps_6_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_6_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_2s_1_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_1_dataarray_data_V, tvin_projout_barrel_2s_1_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_1_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_1_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_1_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_2s_1_dataarray_data_V, "%s\n", (projout_barrel_2s_1_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_1_dataarray_data_V, tvin_projout_barrel_2s_1_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_1_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_2s_1_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_1_dataarray_data_V, tvin_projout_barrel_2s_1_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_1_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_2s_2_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_2_dataarray_data_V, tvin_projout_barrel_2s_2_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_2_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_2_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_2_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_2s_2_dataarray_data_V, "%s\n", (projout_barrel_2s_2_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_2_dataarray_data_V, tvin_projout_barrel_2s_2_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_2_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_2s_2_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_2_dataarray_data_V, tvin_projout_barrel_2s_2_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_2_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_2s_3_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_3_dataarray_data_V, tvin_projout_barrel_2s_3_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_3_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_3_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_3_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_2s_3_dataarray_data_V, "%s\n", (projout_barrel_2s_3_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_3_dataarray_data_V, tvin_projout_barrel_2s_3_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_3_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_2s_3_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_3_dataarray_data_V, tvin_projout_barrel_2s_3_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_3_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_2s_5_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_5_dataarray_data_V, tvin_projout_barrel_2s_5_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_5_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_5_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (5) => (5) @ (2)
					for (int i_0 = 5; i_0 <= 5; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_5_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_2s_5_dataarray_data_V, "%s\n", (projout_barrel_2s_5_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_5_dataarray_data_V, tvin_projout_barrel_2s_5_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_5_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_2s_5_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_5_dataarray_data_V, tvin_projout_barrel_2s_5_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_5_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_2s_6_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_6_dataarray_data_V, tvin_projout_barrel_2s_6_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_6_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_6_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (6) => (6) @ (2)
					for (int i_0 = 6; i_0 <= 6; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_6_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_2s_6_dataarray_data_V, "%s\n", (projout_barrel_2s_6_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_6_dataarray_data_V, tvin_projout_barrel_2s_6_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_6_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_2s_6_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_6_dataarray_data_V, tvin_projout_barrel_2s_6_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_6_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_barrel_2s_7_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_7_dataarray_data_V, tvin_projout_barrel_2s_7_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_7_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_7_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (7) => (7) @ (2)
					for (int i_0 = 7; i_0 <= 7; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_7_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_barrel_2s_7_dataarray_data_V, "%s\n", (projout_barrel_2s_7_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_7_dataarray_data_V, tvin_projout_barrel_2s_7_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_7_dataarray_data_V_depth);
		sprintf(tvin_projout_barrel_2s_7_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_barrel_2s_7_dataarray_data_V, tvin_projout_barrel_2s_7_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_7_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_1_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_1_dataarray_data_V, tvin_projout_disk_1_dataarray_data_V);

		sc_bv<59>* projout_disk_1_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_1_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_1_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_1_dataarray_data_V, "%s\n", (projout_disk_1_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_1_dataarray_data_V, tvin_projout_disk_1_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_1_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_1_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_1_dataarray_data_V, tvin_projout_disk_1_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_1_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_2_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_2_dataarray_data_V, tvin_projout_disk_2_dataarray_data_V);

		sc_bv<59>* projout_disk_2_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_2_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_2_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_2_dataarray_data_V, "%s\n", (projout_disk_2_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_2_dataarray_data_V, tvin_projout_disk_2_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_2_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_2_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_2_dataarray_data_V, tvin_projout_disk_2_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_2_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_3_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_3_dataarray_data_V, tvin_projout_disk_3_dataarray_data_V);

		sc_bv<59>* projout_disk_3_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_3_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_3_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_3_dataarray_data_V, "%s\n", (projout_disk_3_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_3_dataarray_data_V, tvin_projout_disk_3_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_3_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_3_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_3_dataarray_data_V, tvin_projout_disk_3_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_3_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_5_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_5_dataarray_data_V, tvin_projout_disk_5_dataarray_data_V);

		sc_bv<59>* projout_disk_5_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_5_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (5) => (5) @ (2)
					for (int i_0 = 5; i_0 <= 5; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_5_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_5_dataarray_data_V, "%s\n", (projout_disk_5_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_5_dataarray_data_V, tvin_projout_disk_5_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_5_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_5_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_5_dataarray_data_V, tvin_projout_disk_5_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_5_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_6_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_6_dataarray_data_V, tvin_projout_disk_6_dataarray_data_V);

		sc_bv<59>* projout_disk_6_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_6_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (6) => (6) @ (2)
					for (int i_0 = 6; i_0 <= 6; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_6_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_6_dataarray_data_V, "%s\n", (projout_disk_6_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_6_dataarray_data_V, tvin_projout_disk_6_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_6_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_6_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_6_dataarray_data_V, tvin_projout_disk_6_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_6_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_7_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_7_dataarray_data_V, tvin_projout_disk_7_dataarray_data_V);

		sc_bv<59>* projout_disk_7_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_7_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (7) => (7) @ (2)
					for (int i_0 = 7; i_0 <= 7; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_7_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_7_dataarray_data_V, "%s\n", (projout_disk_7_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_7_dataarray_data_V, tvin_projout_disk_7_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_7_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_7_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_7_dataarray_data_V, tvin_projout_disk_7_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_7_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_9_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_9_dataarray_data_V, tvin_projout_disk_9_dataarray_data_V);

		sc_bv<59>* projout_disk_9_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_9_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (9) => (9) @ (2)
					for (int i_0 = 9; i_0 <= 9; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_9_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_9_dataarray_data_V, "%s\n", (projout_disk_9_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_9_dataarray_data_V, tvin_projout_disk_9_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_9_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_9_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_9_dataarray_data_V, tvin_projout_disk_9_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_9_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_10_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_10_dataarray_data_V, tvin_projout_disk_10_dataarray_data_V);

		sc_bv<59>* projout_disk_10_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_10_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (10) => (10) @ (2)
					for (int i_0 = 10; i_0 <= 10; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_10_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_10_dataarray_data_V, "%s\n", (projout_disk_10_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_10_dataarray_data_V, tvin_projout_disk_10_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_10_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_10_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_10_dataarray_data_V, tvin_projout_disk_10_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_10_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_11_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_11_dataarray_data_V, tvin_projout_disk_11_dataarray_data_V);

		sc_bv<59>* projout_disk_11_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_11_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (11) => (11) @ (2)
					for (int i_0 = 11; i_0 <= 11; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_11_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_11_dataarray_data_V, "%s\n", (projout_disk_11_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_11_dataarray_data_V, tvin_projout_disk_11_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_11_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_11_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_11_dataarray_data_V, tvin_projout_disk_11_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_11_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_13_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_13_dataarray_data_V, tvin_projout_disk_13_dataarray_data_V);

		sc_bv<59>* projout_disk_13_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_13_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (13) => (13) @ (2)
					for (int i_0 = 13; i_0 <= 13; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_13_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_13_dataarray_data_V, "%s\n", (projout_disk_13_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_13_dataarray_data_V, tvin_projout_disk_13_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_13_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_13_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_13_dataarray_data_V, tvin_projout_disk_13_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_13_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_14_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_14_dataarray_data_V, tvin_projout_disk_14_dataarray_data_V);

		sc_bv<59>* projout_disk_14_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_14_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (14) => (14) @ (2)
					for (int i_0 = 14; i_0 <= 14; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_14_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_14_dataarray_data_V, "%s\n", (projout_disk_14_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_14_dataarray_data_V, tvin_projout_disk_14_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_14_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_14_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_14_dataarray_data_V, tvin_projout_disk_14_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_14_dataarray_data_V_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_projout_disk_15_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_projout_disk_15_dataarray_data_V, tvin_projout_disk_15_dataarray_data_V);

		sc_bv<59>* projout_disk_15_dataarray_data_V_tvin_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_15_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (15) => (15) @ (2)
					for (int i_0 = 15; i_0 <= 15; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_15_dataarray_data_V_tvin_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvin_projout_disk_15_dataarray_data_V, "%s\n", (projout_disk_15_dataarray_data_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_projout_disk_15_dataarray_data_V, tvin_projout_disk_15_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_15_dataarray_data_V_depth);
		sprintf(tvin_projout_disk_15_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_projout_disk_15_dataarray_data_V, tvin_projout_disk_15_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_15_dataarray_data_V_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		TrackletProcessor_L2L3C(bx, lut, regionlut, innerStubs, outerStubs, outerVMStubs, trackletParameters, projout_barrel_ps, projout_barrel_2s, projout_disk);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_trackletParameters_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_trackletParameters_dataarray_data_V, tvout_trackletParameters_dataarray_data_V);

		sc_bv<70>* trackletParameters_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<70>[1024];

		// RTL Name: trackletParameters_dataarray_data_V
		{
			// bitslice(69, 0)
			{
				int hls_map_index = 0;
				// celement: trackletParameters.dataarray_.data_.V(69, 0)
				{
					// carray: (0) => (7) @ (1)
					for (int i_0 = 0; i_0 <= 7; i_0 += 1)
					{
						// carray: (0) => (127) @ (1)
						for (int i_1 = 0; i_1 <= 127; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : trackletParameters->dataarray_[i_0][i_1].data_
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : trackletParameters->dataarray_[0][0].data_
							// regulate_c_name       : trackletParameters_dataarray__data__V
							// input_type_conversion : (trackletParameters->dataarray_[i_0][i_1].data_).to_string(2).c_str()
							if (&(trackletParameters->dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<70> trackletParameters_dataarray__data__V_tmp_mem;
								trackletParameters_dataarray__data__V_tmp_mem = (trackletParameters->dataarray_[i_0][i_1].data_).to_string(2).c_str();
								trackletParameters_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(69, 0) = trackletParameters_dataarray__data__V_tmp_mem.range(69, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1024; i++)
		{
			sprintf(tvout_trackletParameters_dataarray_data_V, "%s\n", (trackletParameters_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_trackletParameters_dataarray_data_V, tvout_trackletParameters_dataarray_data_V);
		}

		tcl_file.set_num(1024, &tcl_file.trackletParameters_dataarray_data_V_depth);
		sprintf(tvout_trackletParameters_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_trackletParameters_dataarray_data_V, tvout_trackletParameters_dataarray_data_V);

		// release memory allocation
		delete [] trackletParameters_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_ps_3_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_3_dataarray_data_V, tvout_projout_barrel_ps_3_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_3_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_3_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_3_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_ps_3_dataarray_data_V, "%s\n", (projout_barrel_ps_3_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_3_dataarray_data_V, tvout_projout_barrel_ps_3_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_3_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_ps_3_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_3_dataarray_data_V, tvout_projout_barrel_ps_3_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_3_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_ps_4_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_4_dataarray_data_V, tvout_projout_barrel_ps_4_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_4_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_4_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (4) => (4) @ (2)
					for (int i_0 = 4; i_0 <= 4; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_4_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_ps_4_dataarray_data_V, "%s\n", (projout_barrel_ps_4_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_4_dataarray_data_V, tvout_projout_barrel_ps_4_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_4_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_ps_4_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_4_dataarray_data_V, tvout_projout_barrel_ps_4_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_4_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_ps_5_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_5_dataarray_data_V, tvout_projout_barrel_ps_5_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_5_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_5_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (5) => (5) @ (2)
					for (int i_0 = 5; i_0 <= 5; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_5_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_ps_5_dataarray_data_V, "%s\n", (projout_barrel_ps_5_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_5_dataarray_data_V, tvout_projout_barrel_ps_5_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_5_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_ps_5_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_5_dataarray_data_V, tvout_projout_barrel_ps_5_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_5_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_ps_6_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_6_dataarray_data_V, tvout_projout_barrel_ps_6_dataarray_data_V);

		sc_bv<60>* projout_barrel_ps_6_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<60>[256];

		// RTL Name: projout_barrel_ps_6_dataarray_data_V
		{
			// bitslice(59, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_ps.dataarray_.data_.V(59, 0)
				{
					// carray: (6) => (6) @ (2)
					for (int i_0 = 6; i_0 <= 6; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_ps[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_ps_dataarray__data__V
								// input_type_conversion : (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_ps[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<60> projout_barrel_ps_dataarray__data__V_tmp_mem;
									projout_barrel_ps_dataarray__data__V_tmp_mem = (projout_barrel_ps[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_ps_6_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(59, 0) = projout_barrel_ps_dataarray__data__V_tmp_mem.range(59, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_ps_6_dataarray_data_V, "%s\n", (projout_barrel_ps_6_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_6_dataarray_data_V, tvout_projout_barrel_ps_6_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_ps_6_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_ps_6_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_ps_6_dataarray_data_V, tvout_projout_barrel_ps_6_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_ps_6_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_2s_1_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_1_dataarray_data_V, tvout_projout_barrel_2s_1_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_1_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_1_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_1_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_2s_1_dataarray_data_V, "%s\n", (projout_barrel_2s_1_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_1_dataarray_data_V, tvout_projout_barrel_2s_1_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_1_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_2s_1_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_1_dataarray_data_V, tvout_projout_barrel_2s_1_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_1_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_2s_2_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_2_dataarray_data_V, tvout_projout_barrel_2s_2_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_2_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_2_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_2_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_2s_2_dataarray_data_V, "%s\n", (projout_barrel_2s_2_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_2_dataarray_data_V, tvout_projout_barrel_2s_2_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_2_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_2s_2_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_2_dataarray_data_V, tvout_projout_barrel_2s_2_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_2_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_2s_3_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_3_dataarray_data_V, tvout_projout_barrel_2s_3_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_3_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_3_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_3_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_2s_3_dataarray_data_V, "%s\n", (projout_barrel_2s_3_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_3_dataarray_data_V, tvout_projout_barrel_2s_3_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_3_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_2s_3_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_3_dataarray_data_V, tvout_projout_barrel_2s_3_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_3_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_2s_5_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_5_dataarray_data_V, tvout_projout_barrel_2s_5_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_5_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_5_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (5) => (5) @ (2)
					for (int i_0 = 5; i_0 <= 5; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_5_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_2s_5_dataarray_data_V, "%s\n", (projout_barrel_2s_5_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_5_dataarray_data_V, tvout_projout_barrel_2s_5_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_5_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_2s_5_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_5_dataarray_data_V, tvout_projout_barrel_2s_5_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_5_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_2s_6_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_6_dataarray_data_V, tvout_projout_barrel_2s_6_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_6_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_6_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (6) => (6) @ (2)
					for (int i_0 = 6; i_0 <= 6; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_6_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_2s_6_dataarray_data_V, "%s\n", (projout_barrel_2s_6_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_6_dataarray_data_V, tvout_projout_barrel_2s_6_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_6_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_2s_6_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_6_dataarray_data_V, tvout_projout_barrel_2s_6_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_6_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_barrel_2s_7_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_7_dataarray_data_V, tvout_projout_barrel_2s_7_dataarray_data_V);

		sc_bv<58>* projout_barrel_2s_7_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<58>[256];

		// RTL Name: projout_barrel_2s_7_dataarray_data_V
		{
			// bitslice(57, 0)
			{
				int hls_map_index = 0;
				// celement: projout_barrel_2s.dataarray_.data_.V(57, 0)
				{
					// carray: (7) => (7) @ (2)
					for (int i_0 = 7; i_0 <= 7; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_barrel_2s[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_barrel_2s_dataarray__data__V
								// input_type_conversion : (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_barrel_2s[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<58> projout_barrel_2s_dataarray__data__V_tmp_mem;
									projout_barrel_2s_dataarray__data__V_tmp_mem = (projout_barrel_2s[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_barrel_2s_7_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(57, 0) = projout_barrel_2s_dataarray__data__V_tmp_mem.range(57, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_barrel_2s_7_dataarray_data_V, "%s\n", (projout_barrel_2s_7_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_7_dataarray_data_V, tvout_projout_barrel_2s_7_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_barrel_2s_7_dataarray_data_V_depth);
		sprintf(tvout_projout_barrel_2s_7_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_barrel_2s_7_dataarray_data_V, tvout_projout_barrel_2s_7_dataarray_data_V);

		// release memory allocation
		delete [] projout_barrel_2s_7_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_1_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_1_dataarray_data_V, tvout_projout_disk_1_dataarray_data_V);

		sc_bv<59>* projout_disk_1_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_1_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_1_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_1_dataarray_data_V, "%s\n", (projout_disk_1_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_1_dataarray_data_V, tvout_projout_disk_1_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_1_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_1_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_1_dataarray_data_V, tvout_projout_disk_1_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_1_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_2_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_2_dataarray_data_V, tvout_projout_disk_2_dataarray_data_V);

		sc_bv<59>* projout_disk_2_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_2_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_2_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_2_dataarray_data_V, "%s\n", (projout_disk_2_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_2_dataarray_data_V, tvout_projout_disk_2_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_2_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_2_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_2_dataarray_data_V, tvout_projout_disk_2_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_2_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_3_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_3_dataarray_data_V, tvout_projout_disk_3_dataarray_data_V);

		sc_bv<59>* projout_disk_3_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_3_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_3_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_3_dataarray_data_V, "%s\n", (projout_disk_3_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_3_dataarray_data_V, tvout_projout_disk_3_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_3_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_3_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_3_dataarray_data_V, tvout_projout_disk_3_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_3_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_5_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_5_dataarray_data_V, tvout_projout_disk_5_dataarray_data_V);

		sc_bv<59>* projout_disk_5_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_5_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (5) => (5) @ (2)
					for (int i_0 = 5; i_0 <= 5; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_5_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_5_dataarray_data_V, "%s\n", (projout_disk_5_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_5_dataarray_data_V, tvout_projout_disk_5_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_5_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_5_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_5_dataarray_data_V, tvout_projout_disk_5_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_5_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_6_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_6_dataarray_data_V, tvout_projout_disk_6_dataarray_data_V);

		sc_bv<59>* projout_disk_6_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_6_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (6) => (6) @ (2)
					for (int i_0 = 6; i_0 <= 6; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_6_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_6_dataarray_data_V, "%s\n", (projout_disk_6_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_6_dataarray_data_V, tvout_projout_disk_6_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_6_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_6_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_6_dataarray_data_V, tvout_projout_disk_6_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_6_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_7_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_7_dataarray_data_V, tvout_projout_disk_7_dataarray_data_V);

		sc_bv<59>* projout_disk_7_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_7_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (7) => (7) @ (2)
					for (int i_0 = 7; i_0 <= 7; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_7_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_7_dataarray_data_V, "%s\n", (projout_disk_7_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_7_dataarray_data_V, tvout_projout_disk_7_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_7_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_7_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_7_dataarray_data_V, tvout_projout_disk_7_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_7_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_9_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_9_dataarray_data_V, tvout_projout_disk_9_dataarray_data_V);

		sc_bv<59>* projout_disk_9_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_9_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (9) => (9) @ (2)
					for (int i_0 = 9; i_0 <= 9; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_9_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_9_dataarray_data_V, "%s\n", (projout_disk_9_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_9_dataarray_data_V, tvout_projout_disk_9_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_9_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_9_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_9_dataarray_data_V, tvout_projout_disk_9_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_9_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_10_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_10_dataarray_data_V, tvout_projout_disk_10_dataarray_data_V);

		sc_bv<59>* projout_disk_10_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_10_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (10) => (10) @ (2)
					for (int i_0 = 10; i_0 <= 10; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_10_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_10_dataarray_data_V, "%s\n", (projout_disk_10_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_10_dataarray_data_V, tvout_projout_disk_10_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_10_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_10_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_10_dataarray_data_V, tvout_projout_disk_10_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_10_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_11_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_11_dataarray_data_V, tvout_projout_disk_11_dataarray_data_V);

		sc_bv<59>* projout_disk_11_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_11_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (11) => (11) @ (2)
					for (int i_0 = 11; i_0 <= 11; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_11_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_11_dataarray_data_V, "%s\n", (projout_disk_11_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_11_dataarray_data_V, tvout_projout_disk_11_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_11_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_11_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_11_dataarray_data_V, tvout_projout_disk_11_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_11_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_13_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_13_dataarray_data_V, tvout_projout_disk_13_dataarray_data_V);

		sc_bv<59>* projout_disk_13_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_13_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (13) => (13) @ (2)
					for (int i_0 = 13; i_0 <= 13; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_13_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_13_dataarray_data_V, "%s\n", (projout_disk_13_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_13_dataarray_data_V, tvout_projout_disk_13_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_13_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_13_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_13_dataarray_data_V, tvout_projout_disk_13_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_13_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_14_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_14_dataarray_data_V, tvout_projout_disk_14_dataarray_data_V);

		sc_bv<59>* projout_disk_14_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_14_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (14) => (14) @ (2)
					for (int i_0 = 14; i_0 <= 14; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_14_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_14_dataarray_data_V, "%s\n", (projout_disk_14_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_14_dataarray_data_V, tvout_projout_disk_14_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_14_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_14_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_14_dataarray_data_V, tvout_projout_disk_14_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_14_dataarray_data_V_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_projout_disk_15_dataarray_data_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_15_dataarray_data_V, tvout_projout_disk_15_dataarray_data_V);

		sc_bv<59>* projout_disk_15_dataarray_data_V_tvout_wrapc_buffer = new sc_bv<59>[256];

		// RTL Name: projout_disk_15_dataarray_data_V
		{
			// bitslice(58, 0)
			{
				int hls_map_index = 0;
				// celement: projout_disk.dataarray_.data_.V(58, 0)
				{
					// carray: (15) => (15) @ (2)
					for (int i_0 = 15; i_0 <= 15; i_0 += 2)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// carray: (0) => (127) @ (1)
							for (int i_2 = 0; i_2 <= 127; i_2 += 1)
							{
								// sub                   : i_0 i_1 i_2
								// ori_name              : projout_disk[i_0].dataarray_[i_1][i_2].data_
								// sub_1st_elem          : 0 0 0
								// ori_name_1st_elem     : projout_disk[0].dataarray_[0][0].data_
								// regulate_c_name       : projout_disk_dataarray__data__V
								// input_type_conversion : (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str()
								if (&(projout_disk[0].dataarray_[0][0].data_) != NULL) // check the null address if the c port is array or others
								{
									sc_lv<59> projout_disk_dataarray__data__V_tmp_mem;
									projout_disk_dataarray__data__V_tmp_mem = (projout_disk[i_0].dataarray_[i_1][i_2].data_).to_string(2).c_str();
									projout_disk_15_dataarray_data_V_tvout_wrapc_buffer[hls_map_index].range(58, 0) = projout_disk_dataarray__data__V_tmp_mem.range(58, 0);
                                 			       hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 256; i++)
		{
			sprintf(tvout_projout_disk_15_dataarray_data_V, "%s\n", (projout_disk_15_dataarray_data_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_projout_disk_15_dataarray_data_V, tvout_projout_disk_15_dataarray_data_V);
		}

		tcl_file.set_num(256, &tcl_file.projout_disk_15_dataarray_data_V_depth);
		sprintf(tvout_projout_disk_15_dataarray_data_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_projout_disk_15_dataarray_data_V, tvout_projout_disk_15_dataarray_data_V);

		// release memory allocation
		delete [] projout_disk_15_dataarray_data_V_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "bx_V"
		delete [] tvin_bx_V;
		// release memory allocation: "lut_V"
		delete [] tvin_lut_V;
		// release memory allocation: "regionlut_V"
		delete [] tvin_regionlut_V;
		// release memory allocation: "innerStubs_dataarray_data_V"
		delete [] tvin_innerStubs_dataarray_data_V;
		// release memory allocation: "innerStubs_0_nentries_0_V"
		delete [] tvin_innerStubs_0_nentries_0_V;
		// release memory allocation: "innerStubs_0_nentries_1_V"
		delete [] tvin_innerStubs_0_nentries_1_V;
		// release memory allocation: "innerStubs_0_nentries_2_V"
		delete [] tvin_innerStubs_0_nentries_2_V;
		// release memory allocation: "innerStubs_0_nentries_3_V"
		delete [] tvin_innerStubs_0_nentries_3_V;
		// release memory allocation: "innerStubs_0_nentries_4_V"
		delete [] tvin_innerStubs_0_nentries_4_V;
		// release memory allocation: "innerStubs_0_nentries_5_V"
		delete [] tvin_innerStubs_0_nentries_5_V;
		// release memory allocation: "innerStubs_0_nentries_6_V"
		delete [] tvin_innerStubs_0_nentries_6_V;
		// release memory allocation: "innerStubs_0_nentries_7_V"
		delete [] tvin_innerStubs_0_nentries_7_V;
		// release memory allocation: "innerStubs_1_nentries_0_V"
		delete [] tvin_innerStubs_1_nentries_0_V;
		// release memory allocation: "innerStubs_1_nentries_1_V"
		delete [] tvin_innerStubs_1_nentries_1_V;
		// release memory allocation: "innerStubs_1_nentries_2_V"
		delete [] tvin_innerStubs_1_nentries_2_V;
		// release memory allocation: "innerStubs_1_nentries_3_V"
		delete [] tvin_innerStubs_1_nentries_3_V;
		// release memory allocation: "innerStubs_1_nentries_4_V"
		delete [] tvin_innerStubs_1_nentries_4_V;
		// release memory allocation: "innerStubs_1_nentries_5_V"
		delete [] tvin_innerStubs_1_nentries_5_V;
		// release memory allocation: "innerStubs_1_nentries_6_V"
		delete [] tvin_innerStubs_1_nentries_6_V;
		// release memory allocation: "innerStubs_1_nentries_7_V"
		delete [] tvin_innerStubs_1_nentries_7_V;
		// release memory allocation: "innerStubs_2_nentries_0_V"
		delete [] tvin_innerStubs_2_nentries_0_V;
		// release memory allocation: "innerStubs_2_nentries_1_V"
		delete [] tvin_innerStubs_2_nentries_1_V;
		// release memory allocation: "innerStubs_2_nentries_2_V"
		delete [] tvin_innerStubs_2_nentries_2_V;
		// release memory allocation: "innerStubs_2_nentries_3_V"
		delete [] tvin_innerStubs_2_nentries_3_V;
		// release memory allocation: "innerStubs_2_nentries_4_V"
		delete [] tvin_innerStubs_2_nentries_4_V;
		// release memory allocation: "innerStubs_2_nentries_5_V"
		delete [] tvin_innerStubs_2_nentries_5_V;
		// release memory allocation: "innerStubs_2_nentries_6_V"
		delete [] tvin_innerStubs_2_nentries_6_V;
		// release memory allocation: "innerStubs_2_nentries_7_V"
		delete [] tvin_innerStubs_2_nentries_7_V;
		// release memory allocation: "outerStubs_dataarray_data_V"
		delete [] tvin_outerStubs_dataarray_data_V;
		// release memory allocation: "outerVMStubs_dataarray_data_V_0"
		delete [] tvin_outerVMStubs_dataarray_data_V_0;
		// release memory allocation: "outerVMStubs_dataarray_data_V_1"
		delete [] tvin_outerVMStubs_dataarray_data_V_1;
		// release memory allocation: "outerVMStubs_binmask8_V_0_0"
		delete [] tvin_outerVMStubs_binmask8_V_0_0;
		// release memory allocation: "outerVMStubs_binmask8_V_0_1"
		delete [] tvin_outerVMStubs_binmask8_V_0_1;
		// release memory allocation: "outerVMStubs_binmask8_V_0_2"
		delete [] tvin_outerVMStubs_binmask8_V_0_2;
		// release memory allocation: "outerVMStubs_binmask8_V_0_3"
		delete [] tvin_outerVMStubs_binmask8_V_0_3;
		// release memory allocation: "outerVMStubs_binmask8_V_0_4"
		delete [] tvin_outerVMStubs_binmask8_V_0_4;
		// release memory allocation: "outerVMStubs_binmask8_V_0_5"
		delete [] tvin_outerVMStubs_binmask8_V_0_5;
		// release memory allocation: "outerVMStubs_binmask8_V_0_6"
		delete [] tvin_outerVMStubs_binmask8_V_0_6;
		// release memory allocation: "outerVMStubs_binmask8_V_0_7"
		delete [] tvin_outerVMStubs_binmask8_V_0_7;
		// release memory allocation: "outerVMStubs_binmask8_V_1_0"
		delete [] tvin_outerVMStubs_binmask8_V_1_0;
		// release memory allocation: "outerVMStubs_binmask8_V_1_1"
		delete [] tvin_outerVMStubs_binmask8_V_1_1;
		// release memory allocation: "outerVMStubs_binmask8_V_1_2"
		delete [] tvin_outerVMStubs_binmask8_V_1_2;
		// release memory allocation: "outerVMStubs_binmask8_V_1_3"
		delete [] tvin_outerVMStubs_binmask8_V_1_3;
		// release memory allocation: "outerVMStubs_binmask8_V_1_4"
		delete [] tvin_outerVMStubs_binmask8_V_1_4;
		// release memory allocation: "outerVMStubs_binmask8_V_1_5"
		delete [] tvin_outerVMStubs_binmask8_V_1_5;
		// release memory allocation: "outerVMStubs_binmask8_V_1_6"
		delete [] tvin_outerVMStubs_binmask8_V_1_6;
		// release memory allocation: "outerVMStubs_binmask8_V_1_7"
		delete [] tvin_outerVMStubs_binmask8_V_1_7;
		// release memory allocation: "outerVMStubs_nentries8_V_0_0"
		delete [] tvin_outerVMStubs_nentries8_V_0_0;
		// release memory allocation: "outerVMStubs_nentries8_V_0_1"
		delete [] tvin_outerVMStubs_nentries8_V_0_1;
		// release memory allocation: "outerVMStubs_nentries8_V_0_2"
		delete [] tvin_outerVMStubs_nentries8_V_0_2;
		// release memory allocation: "outerVMStubs_nentries8_V_0_3"
		delete [] tvin_outerVMStubs_nentries8_V_0_3;
		// release memory allocation: "outerVMStubs_nentries8_V_0_4"
		delete [] tvin_outerVMStubs_nentries8_V_0_4;
		// release memory allocation: "outerVMStubs_nentries8_V_0_5"
		delete [] tvin_outerVMStubs_nentries8_V_0_5;
		// release memory allocation: "outerVMStubs_nentries8_V_0_6"
		delete [] tvin_outerVMStubs_nentries8_V_0_6;
		// release memory allocation: "outerVMStubs_nentries8_V_0_7"
		delete [] tvin_outerVMStubs_nentries8_V_0_7;
		// release memory allocation: "outerVMStubs_nentries8_V_1_0"
		delete [] tvin_outerVMStubs_nentries8_V_1_0;
		// release memory allocation: "outerVMStubs_nentries8_V_1_1"
		delete [] tvin_outerVMStubs_nentries8_V_1_1;
		// release memory allocation: "outerVMStubs_nentries8_V_1_2"
		delete [] tvin_outerVMStubs_nentries8_V_1_2;
		// release memory allocation: "outerVMStubs_nentries8_V_1_3"
		delete [] tvin_outerVMStubs_nentries8_V_1_3;
		// release memory allocation: "outerVMStubs_nentries8_V_1_4"
		delete [] tvin_outerVMStubs_nentries8_V_1_4;
		// release memory allocation: "outerVMStubs_nentries8_V_1_5"
		delete [] tvin_outerVMStubs_nentries8_V_1_5;
		// release memory allocation: "outerVMStubs_nentries8_V_1_6"
		delete [] tvin_outerVMStubs_nentries8_V_1_6;
		// release memory allocation: "outerVMStubs_nentries8_V_1_7"
		delete [] tvin_outerVMStubs_nentries8_V_1_7;
		// release memory allocation: "trackletParameters_dataarray_data_V"
		delete [] tvout_trackletParameters_dataarray_data_V;
		delete [] tvin_trackletParameters_dataarray_data_V;
		// release memory allocation: "projout_barrel_ps_3_dataarray_data_V"
		delete [] tvout_projout_barrel_ps_3_dataarray_data_V;
		delete [] tvin_projout_barrel_ps_3_dataarray_data_V;
		// release memory allocation: "projout_barrel_ps_4_dataarray_data_V"
		delete [] tvout_projout_barrel_ps_4_dataarray_data_V;
		delete [] tvin_projout_barrel_ps_4_dataarray_data_V;
		// release memory allocation: "projout_barrel_ps_5_dataarray_data_V"
		delete [] tvout_projout_barrel_ps_5_dataarray_data_V;
		delete [] tvin_projout_barrel_ps_5_dataarray_data_V;
		// release memory allocation: "projout_barrel_ps_6_dataarray_data_V"
		delete [] tvout_projout_barrel_ps_6_dataarray_data_V;
		delete [] tvin_projout_barrel_ps_6_dataarray_data_V;
		// release memory allocation: "projout_barrel_2s_1_dataarray_data_V"
		delete [] tvout_projout_barrel_2s_1_dataarray_data_V;
		delete [] tvin_projout_barrel_2s_1_dataarray_data_V;
		// release memory allocation: "projout_barrel_2s_2_dataarray_data_V"
		delete [] tvout_projout_barrel_2s_2_dataarray_data_V;
		delete [] tvin_projout_barrel_2s_2_dataarray_data_V;
		// release memory allocation: "projout_barrel_2s_3_dataarray_data_V"
		delete [] tvout_projout_barrel_2s_3_dataarray_data_V;
		delete [] tvin_projout_barrel_2s_3_dataarray_data_V;
		// release memory allocation: "projout_barrel_2s_5_dataarray_data_V"
		delete [] tvout_projout_barrel_2s_5_dataarray_data_V;
		delete [] tvin_projout_barrel_2s_5_dataarray_data_V;
		// release memory allocation: "projout_barrel_2s_6_dataarray_data_V"
		delete [] tvout_projout_barrel_2s_6_dataarray_data_V;
		delete [] tvin_projout_barrel_2s_6_dataarray_data_V;
		// release memory allocation: "projout_barrel_2s_7_dataarray_data_V"
		delete [] tvout_projout_barrel_2s_7_dataarray_data_V;
		delete [] tvin_projout_barrel_2s_7_dataarray_data_V;
		// release memory allocation: "projout_disk_1_dataarray_data_V"
		delete [] tvout_projout_disk_1_dataarray_data_V;
		delete [] tvin_projout_disk_1_dataarray_data_V;
		// release memory allocation: "projout_disk_2_dataarray_data_V"
		delete [] tvout_projout_disk_2_dataarray_data_V;
		delete [] tvin_projout_disk_2_dataarray_data_V;
		// release memory allocation: "projout_disk_3_dataarray_data_V"
		delete [] tvout_projout_disk_3_dataarray_data_V;
		delete [] tvin_projout_disk_3_dataarray_data_V;
		// release memory allocation: "projout_disk_5_dataarray_data_V"
		delete [] tvout_projout_disk_5_dataarray_data_V;
		delete [] tvin_projout_disk_5_dataarray_data_V;
		// release memory allocation: "projout_disk_6_dataarray_data_V"
		delete [] tvout_projout_disk_6_dataarray_data_V;
		delete [] tvin_projout_disk_6_dataarray_data_V;
		// release memory allocation: "projout_disk_7_dataarray_data_V"
		delete [] tvout_projout_disk_7_dataarray_data_V;
		delete [] tvin_projout_disk_7_dataarray_data_V;
		// release memory allocation: "projout_disk_9_dataarray_data_V"
		delete [] tvout_projout_disk_9_dataarray_data_V;
		delete [] tvin_projout_disk_9_dataarray_data_V;
		// release memory allocation: "projout_disk_10_dataarray_data_V"
		delete [] tvout_projout_disk_10_dataarray_data_V;
		delete [] tvin_projout_disk_10_dataarray_data_V;
		// release memory allocation: "projout_disk_11_dataarray_data_V"
		delete [] tvout_projout_disk_11_dataarray_data_V;
		delete [] tvin_projout_disk_11_dataarray_data_V;
		// release memory allocation: "projout_disk_13_dataarray_data_V"
		delete [] tvout_projout_disk_13_dataarray_data_V;
		delete [] tvin_projout_disk_13_dataarray_data_V;
		// release memory allocation: "projout_disk_14_dataarray_data_V"
		delete [] tvout_projout_disk_14_dataarray_data_V;
		delete [] tvin_projout_disk_14_dataarray_data_V;
		// release memory allocation: "projout_disk_15_dataarray_data_V"
		delete [] tvout_projout_disk_15_dataarray_data_V;
		delete [] tvin_projout_disk_15_dataarray_data_V;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

