template<int seed, int innerphi, int outerphi, unsigned int depth>
void readBendInnerTable(ap_uint<1> table[depth]){

  if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIC19/TE_L5PHIC9_L6PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::R12 && outerphi==TE::W13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIR12_D1PHIW13/TE_L1PHIR12_D1PHIW13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B6 && outerphi==TE::B6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB6_D2PHIB6/TE_D1PHIB6_D2PHIB6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHID25/TE_L5PHID13_L6PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Z5 && outerphi==TE::X4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIZ5_D1PHIX4/TE_L1PHIZ5_D1PHIX4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C9 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC9_L4PHIC21/TE_L3PHIC9_L4PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIA7/TE_L5PHIA4_L6PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Y4 && outerphi==TE::X4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIY4_D1PHIX4/TE_L1PHIY4_D1PHIX4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D13 && outerphi==TE::D14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID13_D4PHID14/TE_D3PHID13_D4PHID14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA2/TE_L5PHIA2_L6PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D15 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID15_L6PHID29/TE_L5PHID15_L6PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C12 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC12_L2PHIB13/TE_L1PHIC12_L2PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G25 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG25_L2PHIC24/TE_L1PHIG25_L2PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A1 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA1_L6PHIA4/TE_L5PHIA1_L6PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C11 && outerphi==TE::C11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC11_D2PHIC11/TE_D1PHIC11_D2PHIC11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D14 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID14_L2PHIB15/TE_L1PHID14_L2PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHID28/TE_L5PHID13_L6PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::W7 && outerphi==TE::Y7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIW7_D1PHIY7/TE_L1PHIW7_D1PHIY7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Q10 && outerphi==TE::Z9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIQ10_D1PHIZ9/TE_L1PHIQ10_D1PHIZ9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIC17/TE_L5PHIB8_L6PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E19 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE19_L2PHIC21/TE_L1PHIE19_L2PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIC20/TE_L5PHIC9_L6PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B5 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB5_L2PHIA6/TE_L1PHIB5_L2PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::W7 && outerphi==TE::W15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIW7_D1PHIW15/TE_L2PHIW7_D1PHIW15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::X2 && outerphi==TE::X3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIX2_D1PHIX3/TE_L1PHIX2_D1PHIX3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A4 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA4_L2PHIA4/TE_L1PHIA4_L2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHIC24/TE_L5PHIC12_L6PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F21 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF21_L2PHIC22/TE_L1PHIF21_L2PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHID27/TE_L5PHID13_L6PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIA7/TE_L5PHIB5_L6PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E20 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE20_L2PHIC22/TE_L1PHIE20_L2PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H30 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH30_L2PHID29/TE_L1PHIH30_L2PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G26 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG26_L2PHID26/TE_L1PHIG26_L2PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A2 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA2_D2PHIA2/TE_D1PHIA2_D2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::W8 && outerphi==TE::Z9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIW8_D1PHIZ9/TE_L1PHIW8_D1PHIZ9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B6 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB6_L4PHIB14/TE_L3PHIB6_L4PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A3 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA3_L2PHIA5/TE_L1PHIA3_L2PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::S13 && outerphi==TE::Z12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIS13_D1PHIZ12/TE_L1PHIS13_D1PHIZ12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C12 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC12_L4PHIC23/TE_L3PHIC12_L4PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A1 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA1_L6PHIA5/TE_L5PHIA1_L6PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Q9 && outerphi==TE::Y8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIQ9_D1PHIY8/TE_L1PHIQ9_D1PHIY8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B6 && outerphi==TE::B7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB6_D4PHIB7/TE_D3PHIB6_D4PHIB7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y3 && outerphi==TE::Y5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY3_D1PHIY5/TE_L2PHIY3_D1PHIY5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D14 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID14_L4PHID29/TE_L3PHID14_L4PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIC17/TE_L5PHIB7_L6PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIA7/TE_L5PHIA3_L6PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C9 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC9_L2PHIB11/TE_L1PHIC9_L2PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F24 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF24_L2PHID26/TE_L1PHIF24_L2PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D13 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID13_L4PHID27/TE_L3PHID13_L4PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B6 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB6_L4PHIB10/TE_L3PHIB6_L4PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F23 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF23_L2PHID25/TE_L1PHIF23_L2PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D15 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID15_L6PHID31/TE_L5PHID15_L6PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E18 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE18_L2PHIC20/TE_L1PHIE18_L2PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D15 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID15_L2PHIB14/TE_L1PHID15_L2PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B8 && outerphi==TE::C9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB8_D2PHIC9/TE_D1PHIB8_D2PHIC9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIA6/TE_L5PHIA3_L6PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D15 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID15_L2PHIC17/TE_L1PHID15_L2PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A2 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA2_L2PHIA1/TE_L1PHIA2_L2PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID30/TE_L5PHID14_L6PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B8 && outerphi==TE::B7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB8_D4PHIB7/TE_D3PHIB8_D4PHIB7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C10 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC10_L4PHIC19/TE_L3PHIC10_L4PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D16 && outerphi==TE::D15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID16_D2PHID15/TE_D1PHID16_D2PHID15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D16 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID16_L2PHIC17/TE_L1PHID16_L2PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::W8 && outerphi==TE::Y7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIW8_D1PHIY7/TE_L1PHIW8_D1PHIY7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z5 && outerphi==TE::Z9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ5_D1PHIZ9/TE_L2PHIZ5_D1PHIZ9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::R11 && outerphi==TE::Z10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIR11_D1PHIZ10/TE_L1PHIR11_D1PHIZ10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C9 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC9_L2PHIA7/TE_L1PHIC9_L2PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C10 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC10_L2PHIA8/TE_L1PHIC10_L2PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H30 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH30_L2PHID31/TE_L1PHIH30_L2PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C11 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC11_L2PHIB11/TE_L1PHIC11_L2PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIB15/TE_L5PHIB8_L6PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A1 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA1_L4PHIA1/TE_L3PHIA1_L4PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D15 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID15_L4PHID29/TE_L3PHID15_L4PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B7 && outerphi==TE::B8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB7_D2PHIB8/TE_D1PHIB7_D2PHIB8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D14 && outerphi==TE::D13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID14_D4PHID13/TE_D3PHID14_D4PHID13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H31 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH31_L2PHID30/TE_L1PHIH31_L2PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H31 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH31_L2PHID29/TE_L1PHIH31_L2PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F21 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF21_L2PHIC19/TE_L1PHIF21_L2PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA5/TE_L5PHIA2_L6PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D13 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID13_L2PHIB13/TE_L1PHID13_L2PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIA3/TE_L5PHIA3_L6PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G26 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG26_L2PHID25/TE_L1PHIG26_L2PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A3 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA3_L4PHIA6/TE_L3PHIA3_L4PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E20 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE20_L2PHIC18/TE_L1PHIE20_L2PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Z5 && outerphi==TE::Y5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIZ5_D1PHIY5/TE_L1PHIZ5_D1PHIY5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIC18/TE_L5PHIB8_L6PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A3 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA3_D4PHIA4/TE_D3PHIA3_D4PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D15 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID15_L4PHID28/TE_L3PHID15_L4PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D14 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID14_L4PHID28/TE_L3PHID14_L4PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::W8 && outerphi==TE::Y8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIW8_D1PHIY8/TE_L1PHIW8_D1PHIY8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D16 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID16_L2PHIB16/TE_L1PHID16_L2PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A4 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA4_L4PHIB9/TE_L3PHIA4_L4PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC19/TE_L5PHIC10_L6PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::T16 && outerphi==TE::W16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIT16_D1PHIW16/TE_L1PHIT16_D1PHIW16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA4/TE_L5PHIA2_L6PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::W7 && outerphi==TE::W14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIW7_D1PHIW14/TE_L2PHIW7_D1PHIW14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B8 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB8_L4PHIB16/TE_L3PHIB8_L4PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C12 && outerphi==TE::D13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC12_D4PHID13/TE_D3PHIC12_D4PHID13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C10 && outerphi==TE::C9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC10_D4PHIC9/TE_D3PHIC10_D4PHIC9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B7 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB7_L4PHIB12/TE_L3PHIB7_L4PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIA5/TE_L5PHIA4_L6PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A2 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA2_D4PHIA2/TE_D3PHIA2_D4PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y3 && outerphi==TE::Y6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY3_D1PHIY6/TE_L2PHIY3_D1PHIY6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Z6 && outerphi==TE::Y6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIZ6_D1PHIY6/TE_L1PHIZ6_D1PHIY6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIC22/TE_L5PHIC9_L6PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D13 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID13_L4PHID28/TE_L3PHID13_L4PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID25/TE_L5PHID14_L6PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::T15 && outerphi==TE::W15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIT15_D1PHIW15/TE_L1PHIT15_D1PHIW15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B6 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB6_L4PHIB13/TE_L3PHIB6_L4PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A2 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA2_D2PHIA1/TE_D1PHIA2_D2PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F23 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF23_L2PHIC24/TE_L1PHIF23_L2PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B7 && outerphi==TE::B6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB7_D4PHIB6/TE_D3PHIB7_D4PHIB6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB11/TE_L5PHIB6_L6PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B7 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB7_L4PHIB15/TE_L3PHIB7_L4PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G27 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG27_L2PHID28/TE_L1PHIG27_L2PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::S13 && outerphi==TE::W13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIS13_D1PHIW13/TE_L1PHIS13_D1PHIW13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X1 && outerphi==TE::X2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX1_D1PHIX2/TE_L2PHIX1_D1PHIX2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y4 && outerphi==TE::Y7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY4_D1PHIY7/TE_L2PHIY4_D1PHIY7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B5 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB5_D4PHIA4/TE_D3PHIB5_D4PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F21 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF21_L2PHIC23/TE_L1PHIF21_L2PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Y3 && outerphi==TE::X2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIY3_D1PHIX2/TE_L1PHIY3_D1PHIX2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B8 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB8_L4PHIB14/TE_L3PHIB8_L4PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIB15/TE_L5PHIC9_L6PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E17 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE17_L2PHIC19/TE_L1PHIE17_L2PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB13/TE_L5PHIB6_L6PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C10 && outerphi==TE::C9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC10_D2PHIC9/TE_D1PHIC10_D2PHIC9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F24 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF24_L2PHIC24/TE_L1PHIF24_L2PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C10 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC10_L4PHIC21/TE_L3PHIC10_L4PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C10 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC10_L4PHIC18/TE_L3PHIC10_L4PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G27 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG27_L2PHID26/TE_L1PHIG27_L2PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D16 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID16_L6PHID32/TE_L5PHID16_L6PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C10 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC10_L4PHIC23/TE_L3PHIC10_L4PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A4 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA4_L2PHIA6/TE_L1PHIA4_L2PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D14 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID14_L2PHIB16/TE_L1PHID14_L2PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Y4 && outerphi==TE::X3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIY4_D1PHIX3/TE_L1PHIY4_D1PHIX3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHID25/TE_L5PHIC12_L6PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIA5/TE_L5PHIA3_L6PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A2 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA2_L4PHIA2/TE_L3PHIA2_L4PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A4 && outerphi==TE::B5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA4_D4PHIB5/TE_D3PHIA4_D4PHIB5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B5 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB5_L2PHIA5/TE_L1PHIB5_L2PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G26 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG26_L2PHIC24/TE_L1PHIG26_L2PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E18 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE18_L2PHIC19/TE_L1PHIE18_L2PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIB9/TE_L5PHIA4_L6PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B8 && outerphi==TE::B7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB8_D2PHIB7/TE_D1PHIB8_D2PHIB7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIA8/TE_L5PHIB5_L6PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIB12/TE_L5PHIB7_L6PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H30 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH30_L2PHID30/TE_L1PHIH30_L2PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHID29/TE_L5PHID13_L6PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A4 && outerphi==TE::B5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA4_D2PHIB5/TE_D1PHIA4_D2PHIB5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB12/TE_L5PHIB6_L6PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G25 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG25_L2PHID26/TE_L1PHIG25_L2PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A3 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA3_D2PHIA4/TE_D1PHIA3_D2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D15 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID15_L2PHIB15/TE_L1PHID15_L2PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D14 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID14_L2PHIB12/TE_L1PHID14_L2PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB16/TE_L5PHIB6_L6PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::W8 && outerphi==TE::W16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIW8_D1PHIW16/TE_L2PHIW8_D1PHIW16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z5 && outerphi==TE::Z12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ5_D1PHIZ12/TE_L2PHIZ5_D1PHIZ12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B8 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB8_L2PHIA8/TE_L1PHIB8_L2PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C10 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC10_L2PHIB11/TE_L1PHIC10_L2PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E19 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE19_L2PHIC20/TE_L1PHIE19_L2PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIC21/TE_L5PHIC9_L6PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::S14 && outerphi==TE::W15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIS14_D1PHIW15/TE_L1PHIS14_D1PHIW15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F22 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF22_L2PHIC20/TE_L1PHIF22_L2PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H32 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH32_L2PHID30/TE_L1PHIH32_L2PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B5 && outerphi==TE::B6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB5_D4PHIB6/TE_D3PHIB5_D4PHIB6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G28 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG28_L2PHID28/TE_L1PHIG28_L2PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B8 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB8_L4PHIC19/TE_L3PHIB8_L4PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B7 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB7_L2PHIA6/TE_L1PHIB7_L2PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::W7 && outerphi==TE::W13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIW7_D1PHIW13/TE_L2PHIW7_D1PHIW13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z6 && outerphi==TE::W13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ6_D1PHIW13/TE_L2PHIZ6_D1PHIW13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X2 && outerphi==TE::X4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX2_D1PHIX4/TE_L2PHIX2_D1PHIX4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B8 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB8_L4PHIC18/TE_L3PHIB8_L4PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C12 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC12_L4PHID25/TE_L3PHIC12_L4PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C11 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC11_L2PHIB13/TE_L1PHIC11_L2PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B6 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB6_L2PHIA5/TE_L1PHIB6_L2PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A1 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA1_D4PHIA1/TE_D3PHIA1_D4PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D16 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID16_L6PHID31/TE_L5PHID16_L6PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C9 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC9_L2PHIB10/TE_L1PHIC9_L2PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Z6 && outerphi==TE::Y7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIZ6_D1PHIY7/TE_L1PHIZ6_D1PHIY7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C12 && outerphi==TE::C12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC12_D2PHIC12/TE_D1PHIC12_D2PHIC12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H31 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH31_L2PHID32/TE_L1PHIH31_L2PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G28 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG28_L2PHID27/TE_L1PHIG28_L2PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H30 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH30_L2PHID32/TE_L1PHIH30_L2PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C9 && outerphi==TE::B8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC9_D2PHIB8/TE_D1PHIC9_D2PHIB8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X2 && outerphi==TE::Y5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX2_D1PHIY5/TE_L2PHIX2_D1PHIY5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D14 && outerphi==TE::D15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID14_D4PHID15/TE_D3PHID14_D4PHID15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC21/TE_L5PHIC10_L6PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y3 && outerphi==TE::Y7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY3_D1PHIY7/TE_L2PHIY3_D1PHIY7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C12 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC12_L4PHID26/TE_L3PHIC12_L4PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G28 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG28_L2PHID29/TE_L1PHIG28_L2PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A4 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA4_L2PHIA3/TE_L1PHIA4_L2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D16 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID16_L4PHID30/TE_L3PHID16_L4PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A1 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA1_D2PHIA1/TE_D1PHIA1_D2PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D13 && outerphi==TE::D13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID13_D4PHID13/TE_D3PHID13_D4PHID13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B5 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB5_L2PHIA4/TE_L1PHIB5_L2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C11 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC11_L4PHID25/TE_L3PHIC11_L4PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID31/TE_L5PHID14_L6PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID29/TE_L5PHID14_L6PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A4 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA4_L4PHIB10/TE_L3PHIA4_L4PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C12 && outerphi==TE::D13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC12_D2PHID13/TE_D1PHIC12_D2PHID13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::X2 && outerphi==TE::X2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIX2_D1PHIX2/TE_L1PHIX2_D1PHIX2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIB16/TE_L5PHIB7_L6PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E17 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE17_L2PHIB15/TE_L1PHIE17_L2PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIA8/TE_L5PHIA4_L6PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIB12/TE_L5PHIA4_L6PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D15 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID15_L6PHID32/TE_L5PHID15_L6PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA6/TE_L5PHIA2_L6PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D14 && outerphi==TE::D15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID14_D2PHID15/TE_D1PHID14_D2PHID15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C11 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC11_L4PHIC24/TE_L3PHIC11_L4PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHID25/TE_L5PHIC11_L6PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B5 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB5_L4PHIB9/TE_L3PHIB5_L4PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H32 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH32_L2PHID31/TE_L1PHIH32_L2PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A2 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA2_D4PHIA3/TE_D3PHIA2_D4PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E19 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE19_L2PHIC19/TE_L1PHIE19_L2PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F24 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF24_L2PHID25/TE_L1PHIF24_L2PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::S14 && outerphi==TE::W13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIS14_D1PHIW13/TE_L1PHIS14_D1PHIW13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC18/TE_L5PHIC10_L6PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F24 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF24_L2PHIC23/TE_L1PHIF24_L2PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C10 && outerphi==TE::C11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC10_D4PHIC11/TE_D3PHIC10_D4PHIC11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D15 && outerphi==TE::D16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID15_D2PHID16/TE_D1PHID15_D2PHID16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::W8 && outerphi==TE::W15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIW8_D1PHIW15/TE_L2PHIW8_D1PHIW15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C11 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC11_L4PHIC23/TE_L3PHIC11_L4PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H29 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH29_L2PHID29/TE_L1PHIH29_L2PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A1 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA1_L6PHIA1/TE_L5PHIA1_L6PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A3 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA3_D4PHIA3/TE_D3PHIA3_D4PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C11 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC11_L4PHIC20/TE_L3PHIC11_L4PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C11 && outerphi==TE::C11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC11_D4PHIC11/TE_D3PHIC11_D4PHIC11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D14 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID14_L4PHID27/TE_L3PHID14_L4PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHID28/TE_L5PHIC12_L6PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D13 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID13_L2PHIB11/TE_L1PHID13_L2PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z6 && outerphi==TE::W14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ6_D1PHIW14/TE_L2PHIZ6_D1PHIW14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C12 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC12_L2PHIB14/TE_L1PHIC12_L2PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Y3 && outerphi==TE::X3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIY3_D1PHIX3/TE_L1PHIY3_D1PHIX3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H31 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH31_L2PHID31/TE_L1PHIH31_L2PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y4 && outerphi==TE::Y8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY4_D1PHIY8/TE_L2PHIY4_D1PHIY8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A1 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA1_L6PHIA3/TE_L5PHIA1_L6PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H30 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH30_L2PHID28/TE_L1PHIH30_L2PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Z5 && outerphi==TE::Y6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIZ5_D1PHIY6/TE_L1PHIZ5_D1PHIY6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A2 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA2_D4PHIA1/TE_D3PHIA2_D4PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::T15 && outerphi==TE::W16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIT15_D1PHIW16/TE_L1PHIT15_D1PHIW16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B7 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB7_L4PHIB16/TE_L3PHIB7_L4PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C10 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC10_L4PHIC22/TE_L3PHIC10_L4PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B7 && outerphi==TE::B6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB7_D2PHIB6/TE_D1PHIB7_D2PHIB6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B8 && outerphi==TE::C9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB8_D4PHIC9/TE_D3PHIB8_D4PHIC9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F22 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF22_L2PHIC22/TE_L1PHIF22_L2PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C9 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC9_L2PHIA8/TE_L1PHIC9_L2PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D15 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID15_L4PHID30/TE_L3PHID15_L4PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F21 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF21_L2PHIC20/TE_L1PHIF21_L2PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIB10/TE_L5PHIB5_L6PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIB11/TE_L5PHIA4_L6PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F23 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF23_L2PHIC23/TE_L1PHIF23_L2PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B6 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB6_L4PHIB15/TE_L3PHIB6_L4PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C12 && outerphi==TE::C12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC12_D4PHIC12/TE_D3PHIC12_D4PHIC12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIC19/TE_L5PHIB8_L6PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID26/TE_L5PHID14_L6PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B6 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB6_L2PHIA4/TE_L1PHIB6_L2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G26 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG26_L2PHID27/TE_L1PHIG26_L2PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F21 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF21_L2PHIC21/TE_L1PHIF21_L2PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::T15 && outerphi==TE::W14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIT15_D1PHIW14/TE_L1PHIT15_D1PHIW14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H32 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH32_L2PHID32/TE_L1PHIH32_L2PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Y4 && outerphi==TE::Y5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIY4_D1PHIY5/TE_L1PHIY4_D1PHIY5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C12 && outerphi==TE::C11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC12_D4PHIC11/TE_D3PHIC12_D4PHIC11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D16 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID16_L2PHIC18/TE_L1PHID16_L2PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHIC20/TE_L5PHIC11_L6PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C9 && outerphi==TE::C10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC9_D2PHIC10/TE_D1PHIC9_D2PHIC10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B6 && outerphi==TE::B6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB6_D4PHIB6/TE_D3PHIB6_D4PHIB6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C11 && outerphi==TE::C12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC11_D2PHIC12/TE_D1PHIC11_D2PHIC12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D15 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID15_L6PHID30/TE_L5PHID15_L6PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B5 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB5_D2PHIA4/TE_D1PHIB5_D2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C11 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC11_L2PHIB10/TE_L1PHIC11_L2PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B5 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB5_L4PHIB10/TE_L3PHIB5_L4PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C9 && outerphi==TE::B8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC9_D4PHIB8/TE_D3PHIC9_D4PHIB8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIB15/TE_L5PHIB7_L6PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G27 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG27_L2PHID25/TE_L1PHIG27_L2PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E20 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE20_L2PHIC20/TE_L1PHIE20_L2PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B5 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB5_L4PHIB12/TE_L3PHIB5_L4PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A3 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA3_L4PHIA8/TE_L3PHIA3_L4PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B6 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB6_L4PHIB11/TE_L3PHIB6_L4PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y4 && outerphi==TE::Z10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY4_D1PHIZ10/TE_L2PHIY4_D1PHIZ10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B7 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB7_L2PHIB9/TE_L1PHIB7_L2PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D13 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID13_L4PHIC24/TE_L3PHID13_L4PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D14 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID14_L2PHIB13/TE_L1PHID14_L2PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A4 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA4_L2PHIA2/TE_L1PHIA4_L2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C9 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC9_L4PHIC17/TE_L3PHIC9_L4PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D15 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID15_L2PHIB13/TE_L1PHID15_L2PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C9 && outerphi==TE::C10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC9_D4PHIC10/TE_D3PHIC9_D4PHIC10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::W7 && outerphi==TE::W16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIW7_D1PHIW16/TE_L2PHIW7_D1PHIW16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y4 && outerphi==TE::Z9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY4_D1PHIZ9/TE_L2PHIY4_D1PHIZ9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A4 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA4_D4PHIA4/TE_D3PHIA4_D4PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C9 && outerphi==TE::C9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC9_D4PHIC9/TE_D3PHIC9_D4PHIC9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B5 && outerphi==TE::B5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB5_D2PHIB5/TE_D1PHIB5_D2PHIB5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A1 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA1_L2PHIA3/TE_L1PHIA1_L2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D15 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID15_L6PHID28/TE_L5PHID15_L6PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIC20/TE_L5PHIB8_L6PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E17 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE17_L2PHIB16/TE_L1PHIE17_L2PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D14 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID14_L4PHID31/TE_L3PHID14_L4PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID28/TE_L5PHID14_L6PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHIC24/TE_L5PHIC11_L6PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A3 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA3_L2PHIA2/TE_L1PHIA3_L2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::W7 && outerphi==TE::Y6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIW7_D1PHIY6/TE_L1PHIW7_D1PHIY6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB15/TE_L5PHIB6_L6PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::R11 && outerphi==TE::Z11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIR11_D1PHIZ11/TE_L1PHIR11_D1PHIZ11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F23 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF23_L2PHIC22/TE_L1PHIF23_L2PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D14 && outerphi==TE::D13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID14_D2PHID13/TE_D1PHID14_D2PHID13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A4 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA4_L4PHIB11/TE_L3PHIA4_L4PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C12 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC12_L4PHIC22/TE_L3PHIC12_L4PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHIC19/TE_L5PHIC11_L6PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D13 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID13_L2PHIB14/TE_L1PHID13_L2PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIB13/TE_L5PHIB7_L6PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::T16 && outerphi==TE::W15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIT16_D1PHIW15/TE_L1PHIT16_D1PHIW15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHID27/TE_L5PHIC12_L6PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D15 && outerphi==TE::D16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID15_D4PHID16/TE_D3PHID15_D4PHID16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C9 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC9_L4PHIB16/TE_L3PHIC9_L4PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B8 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB8_L2PHIB9/TE_L1PHIB8_L2PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G28 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG28_L2PHID30/TE_L1PHIG28_L2PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G27 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG27_L2PHID29/TE_L1PHIG27_L2PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C12 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC12_L4PHIC24/TE_L3PHIC12_L4PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B6 && outerphi==TE::B7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB6_D2PHIB7/TE_D1PHIB6_D2PHIB7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F22 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF22_L2PHIC21/TE_L1PHIF22_L2PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C9 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC9_L2PHIB9/TE_L1PHIC9_L2PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB10/TE_L5PHIB6_L6PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A3 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA3_L4PHIA4/TE_L3PHIA3_L4PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D13 && outerphi==TE::C12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID13_D2PHIC12/TE_D1PHID13_D2PHIC12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A4 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA4_D4PHIA3/TE_D3PHIA4_D4PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C10 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC10_L2PHIB10/TE_L1PHIC10_L2PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A1 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA1_L6PHIA6/TE_L5PHIA1_L6PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A1 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA1_L6PHIA2/TE_L5PHIA1_L6PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G27 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG27_L2PHID27/TE_L1PHIG27_L2PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIB16/TE_L5PHIB8_L6PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIB9/TE_L5PHIA3_L6PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A2 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA2_D2PHIA3/TE_D1PHIA2_D2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A3 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA3_L2PHIA3/TE_L1PHIA3_L2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Q10 && outerphi==TE::Z11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIQ10_D1PHIZ11/TE_L1PHIQ10_D1PHIZ11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B5 && outerphi==TE::B6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB5_D2PHIB6/TE_D1PHIB5_D2PHIB6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIA8/TE_L5PHIA3_L6PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B6 && outerphi==TE::B5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB6_D4PHIB5/TE_D3PHIB6_D4PHIB5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F22 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF22_L2PHIC24/TE_L1PHIF22_L2PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIB14/TE_L5PHIB8_L6PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B7 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB7_L4PHIB13/TE_L3PHIB7_L4PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B8 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB8_L4PHIB15/TE_L3PHIB8_L4PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A1 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA1_D4PHIA2/TE_D3PHIA1_D4PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C10 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC10_L2PHIB9/TE_L1PHIC10_L2PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D14 && outerphi==TE::D14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID14_D4PHID14/TE_D3PHID14_D4PHID14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::R12 && outerphi==TE::Z11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIR12_D1PHIZ11/TE_L1PHIR12_D1PHIZ11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H29 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH29_L2PHID30/TE_L1PHIH29_L2PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X2 && outerphi==TE::X3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX2_D1PHIX3/TE_L2PHIX2_D1PHIX3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::X1 && outerphi==TE::X1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIX1_D1PHIX1/TE_L1PHIX1_D1PHIX1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z5 && outerphi==TE::Z11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ5_D1PHIZ11/TE_L2PHIZ5_D1PHIZ11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D15 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID15_L2PHIB16/TE_L1PHID15_L2PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D15 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID15_L4PHID31/TE_L3PHID15_L4PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A3 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA3_L4PHIB9/TE_L3PHIA3_L4PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E19 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE19_L2PHIC18/TE_L1PHIE19_L2PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIB11/TE_L5PHIB7_L6PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C10 && outerphi==TE::C11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC10_D2PHIC11/TE_D1PHIC10_D2PHIC11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID27/TE_L5PHID14_L6PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::X1 && outerphi==TE::X2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIX1_D1PHIX2/TE_L1PHIX1_D1PHIX2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E20 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE20_L2PHIC21/TE_L1PHIE20_L2PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B7 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB7_L4PHIC17/TE_L3PHIB7_L4PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C9 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC9_L4PHIC18/TE_L3PHIC9_L4PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIB13/TE_L5PHIB5_L6PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z6 && outerphi==TE::Z11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ6_D1PHIZ11/TE_L2PHIZ6_D1PHIZ11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D14 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID14_L2PHIB14/TE_L1PHID14_L2PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHID26/TE_L5PHID13_L6PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D15 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID15_L4PHID32/TE_L3PHID15_L4PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B8 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB8_L2PHIA6/TE_L1PHIB8_L2PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::S13 && outerphi==TE::W14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIS13_D1PHIW14/TE_L1PHIS13_D1PHIW14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHIC21/TE_L5PHIC12_L6PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC23/TE_L5PHIC10_L6PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A4 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA4_L2PHIA5/TE_L1PHIA4_L2PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H29 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH29_L2PHID31/TE_L1PHIH29_L2PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B7 && outerphi==TE::B7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB7_D4PHIB7/TE_D3PHIB7_D4PHIB7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A2 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA2_L4PHIA3/TE_L3PHIA2_L4PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F24 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF24_L2PHIC22/TE_L1PHIF24_L2PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B6 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB6_L2PHIA8/TE_L1PHIB6_L2PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC20/TE_L5PHIC10_L6PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIB14/TE_L5PHIB5_L6PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B5 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB5_L2PHIA7/TE_L1PHIB5_L2PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D16 && outerphi==TE::D15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID16_D4PHID15/TE_D3PHID16_D4PHID15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D14 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID14_L4PHID30/TE_L3PHID14_L4PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A3 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA3_D2PHIA3/TE_D1PHIA3_D2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B5 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB5_L2PHIA3/TE_L1PHIB5_L2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C11 && outerphi==TE::C12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC11_D4PHIC12/TE_D3PHIC11_D4PHIC12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B5 && outerphi==TE::B5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB5_D4PHIB5/TE_D3PHIB5_D4PHIB5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHID26/TE_L5PHIC12_L6PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIC18/TE_L5PHIC9_L6PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B8 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB8_L4PHIC17/TE_L3PHIB8_L4PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA1/TE_L5PHIA2_L6PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIB14/TE_L5PHIB7_L6PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B5 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB5_L4PHIB13/TE_L3PHIB5_L4PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A3 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA3_D2PHIA2/TE_D1PHIA3_D2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA3/TE_L5PHIA2_L6PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B8 && outerphi==TE::B8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB8_D2PHIB8/TE_D1PHIB8_D2PHIB8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X1 && outerphi==TE::X1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX1_D1PHIX1/TE_L2PHIX1_D1PHIX1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G25 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG25_L2PHID27/TE_L1PHIG25_L2PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A1 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA1_D2PHIA2/TE_D1PHIA1_D2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B8 && outerphi==TE::B13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB8_L6PHIB13/TE_L5PHIB8_L6PHIB13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC22/TE_L5PHIC10_L6PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C9 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC9_L4PHIC20/TE_L3PHIC9_L4PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z5 && outerphi==TE::Z10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ5_D1PHIZ10/TE_L2PHIZ5_D1PHIZ10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B6 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB6_L2PHIA6/TE_L1PHIB6_L2PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E17 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE17_L2PHIC18/TE_L1PHIE17_L2PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C9 && outerphi==TE::C9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC9_D2PHIC9/TE_D1PHIC9_D2PHIC9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D15 && outerphi==TE::D14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID15_D4PHID14/TE_D3PHID15_D4PHID14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIA4/TE_L5PHIA3_L6PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHIC23/TE_L5PHIC12_L6PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A1 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA1_L4PHIA3/TE_L3PHIA1_L4PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D13 && outerphi==TE::D13) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID13_D2PHID13/TE_D1PHID13_D2PHID13_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIB16/TE_L5PHIC9_L6PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B6 && outerphi==TE::B5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB6_D2PHIB5/TE_D1PHIB6_D2PHIB5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A1 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA1_L2PHIA2/TE_L1PHIA1_L2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E17 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE17_L2PHIC17/TE_L1PHIE17_L2PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C11 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC11_L4PHIC22/TE_L3PHIC11_L4PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E18 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE18_L2PHIC18/TE_L1PHIE18_L2PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C11 && outerphi==TE::C10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC11_D2PHIC10/TE_D1PHIC11_D2PHIC10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D16 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID16_L6PHID30/TE_L5PHID16_L6PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C12 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC12_L2PHIB12/TE_L1PHIC12_L2PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::R11 && outerphi==TE::Z12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIR11_D1PHIZ12/TE_L1PHIR11_D1PHIZ12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X1 && outerphi==TE::X3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX1_D1PHIX3/TE_L2PHIX1_D1PHIX3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A4 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA4_D2PHIA4/TE_D1PHIA4_D2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIB10/TE_L5PHIA4_L6PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Q9 && outerphi==TE::Z9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIQ9_D1PHIZ9/TE_L1PHIQ9_D1PHIZ9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D16 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID16_L4PHID32/TE_L3PHID16_L4PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C10 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC10_L2PHIB12/TE_L1PHIC10_L2PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::R12 && outerphi==TE::Z12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIR12_D1PHIZ12/TE_L1PHIR12_D1PHIZ12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA7/TE_L5PHIA2_L6PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C12 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC12_L2PHIB10/TE_L1PHIC12_L2PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D14 && outerphi==TE::D14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID14_D2PHID14/TE_D1PHID14_D2PHID14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D13 && outerphi==TE::C12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID13_D4PHIC12/TE_D3PHID13_D4PHIC12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::X2 && outerphi==TE::X1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIX2_D1PHIX1/TE_L1PHIX2_D1PHIX1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D14 && outerphi==TE::D32) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID14_L6PHID32/TE_L5PHID14_L6PHID32_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHIC22/TE_L5PHIC11_L6PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G25 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG25_L2PHID25/TE_L1PHIG25_L2PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C10 && outerphi==TE::C10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC10_D2PHIC10/TE_D1PHIC10_D2PHIC10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B7 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB7_L2PHIA5/TE_L1PHIB7_L2PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A3 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA3_L4PHIA7/TE_L3PHIA3_L4PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A1 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA1_L4PHIA4/TE_L3PHIA1_L4PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHID26/TE_L5PHIC11_L6PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHIC21/TE_L5PHIC11_L6PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D15 && outerphi==TE::D15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID15_D2PHID15/TE_D1PHID15_D2PHID15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Q9 && outerphi==TE::Z10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIQ9_D1PHIZ10/TE_L1PHIQ9_D1PHIZ10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B8 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB8_L2PHIB10/TE_L1PHIB8_L2PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C11 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC11_L4PHIC21/TE_L3PHIC11_L4PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D16 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID16_L2PHIB15/TE_L1PHID16_L2PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A2 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA2_L2PHIA2/TE_L1PHIA2_L2PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E18 && outerphi==TE::B16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE18_L2PHIB16/TE_L1PHIE18_L2PHIB16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A3 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA3_L2PHIA4/TE_L1PHIA3_L2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D13 && outerphi==TE::D25) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID13_L4PHID25/TE_L3PHID13_L4PHID25_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Q10 && outerphi==TE::Z10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIQ10_D1PHIZ10/TE_L1PHIQ10_D1PHIZ10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::C12 && outerphi==TE::C11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIC12_D2PHIC11/TE_D1PHIC12_D2PHIC11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A1 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA1_L4PHIA2/TE_L3PHIA1_L4PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B6 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB6_L4PHIB12/TE_L3PHIB6_L4PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D13 && outerphi==TE::D14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID13_D2PHID14/TE_D1PHID13_D2PHID14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::A4 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIA4_D2PHIA3/TE_D1PHIA4_D2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC17/TE_L5PHIC10_L6PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C11 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC11_L6PHIC23/TE_L5PHIC11_L6PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C11 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC11_L2PHIB9/TE_L1PHIC11_L2PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H29 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH29_L2PHID27/TE_L1PHIH29_L2PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F23 && outerphi==TE::C21) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF23_L2PHIC21/TE_L1PHIF23_L2PHIC21_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X2 && outerphi==TE::Y6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX2_D1PHIY6/TE_L2PHIX2_D1PHIY6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C11 && outerphi==TE::C10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC11_D4PHIC10/TE_D3PHIC11_D4PHIC10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B7 && outerphi==TE::B8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB7_D4PHIB8/TE_D3PHIB7_D4PHIB8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHIC23/TE_L5PHID13_L6PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D13 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID13_L4PHID29/TE_L3PHID13_L4PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A1 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA1_L2PHIA1/TE_L1PHIA1_L2PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D15 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID15_L6PHID27/TE_L5PHID15_L6PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G26 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG26_L2PHID28/TE_L1PHIG26_L2PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B6 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB6_L2PHIA7/TE_L1PHIB6_L2PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D13 && outerphi==TE::B15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID13_L2PHIB15/TE_L1PHID13_L2PHIB15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D13 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID13_L4PHID26/TE_L3PHID13_L4PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Z6 && outerphi==TE::Z12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIZ6_D1PHIZ12/TE_L2PHIZ6_D1PHIZ12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B8 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB8_L2PHIA7/TE_L1PHIB8_L2PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B7 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB7_L2PHIA8/TE_L1PHIB7_L2PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A4 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA4_L4PHIA6/TE_L3PHIA4_L4PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::F22 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIF22_L2PHIC23/TE_L1PHIF22_L2PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::B7 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIB7_L2PHIA7/TE_L1PHIB7_L2PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D15 && outerphi==TE::D14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID15_D2PHID14/TE_D1PHID15_D2PHID14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A2 && outerphi==TE::A3) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA2_L2PHIA3/TE_L1PHIA2_L2PHIA3_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A4 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA4_L4PHIA7/TE_L3PHIA4_L4PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D16 && outerphi==TE::D16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID16_D4PHID16/TE_D3PHID16_D4PHID16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G25 && outerphi==TE::C23) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG25_L2PHIC23/TE_L1PHIG25_L2PHIC23_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E19 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE19_L2PHIC17/TE_L1PHIE19_L2PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C12 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC12_L2PHIB11/TE_L1PHIC12_L2PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A2 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA2_L4PHIA5/TE_L3PHIA2_L4PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIB9/TE_L5PHIB5_L6PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::G28 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIG28_L2PHID26/TE_L1PHIG28_L2PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C9 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC9_L6PHIC17/TE_L5PHIC9_L6PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A4 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA4_L4PHIA8/TE_L3PHIA4_L4PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D16 && outerphi==TE::D31) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID16_L4PHID31/TE_L3PHID16_L4PHID31_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB14/TE_L5PHIB6_L6PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D16 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID16_L2PHIB14/TE_L1PHID16_L2PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIB11/TE_L5PHIB5_L6PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::W7 && outerphi==TE::Y8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIW7_D1PHIY8/TE_L1PHIW7_D1PHIY8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B6 && outerphi==TE::B9) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB6_L6PHIB9/TE_L5PHIB6_L6PHIB9_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::D30) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHID30/TE_L5PHID13_L6PHID30_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Z6 && outerphi==TE::Y5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIZ6_D1PHIY5/TE_L1PHIZ6_D1PHIY5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::C11 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIC11_L2PHIB12/TE_L1PHIC11_L2PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::S14 && outerphi==TE::W14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIS14_D1PHIW14/TE_L1PHIS14_D1PHIW14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::B7 && outerphi==TE::B7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHIB7_D2PHIB7/TE_D1PHIB7_D2PHIB7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::D13 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHID13_L2PHIB12/TE_L1PHID13_L2PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D1D2 && innerphi==TE::D16 && outerphi==TE::D16) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D1PHID16_D2PHID16/TE_D1PHID16_D2PHID16_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A3 && outerphi==TE::A1) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA3_L2PHIA1/TE_L1PHIA3_L2PHIA1_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::A2 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIA2_L2PHIA4/TE_L1PHIA2_L2PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C10 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC10_L6PHIC24/TE_L5PHIC10_L6PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A2 && outerphi==TE::A4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA2_L4PHIA4/TE_L3PHIA2_L4PHIA4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B5 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB5_L4PHIA8/TE_L3PHIB5_L4PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::B8 && outerphi==TE::B8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIB8_D4PHIB8/TE_D3PHIB8_D4PHIB8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::H29 && outerphi==TE::D28) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIH29_L2PHID28/TE_L1PHIH29_L2PHID28_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D16 && outerphi==TE::D29) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID16_L6PHID29/TE_L5PHID16_L6PHID29_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A3 && outerphi==TE::B10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA3_L6PHIB10/TE_L5PHIA3_L6PHIB10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::D15 && outerphi==TE::D15) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHID15_D4PHID15/TE_D3PHID15_D4PHID15_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::Y3 && outerphi==TE::Y8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIY3_D1PHIY8/TE_L2PHIY3_D1PHIY8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A2 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA2_L4PHIA6/TE_L3PHIA2_L4PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::A3 && outerphi==TE::A2) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIA3_D4PHIA2/TE_D3PHIA3_D4PHIA2_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E18 && outerphi==TE::C17) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B7 && outerphi==TE::B14) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB7_L4PHIB14/TE_L3PHIB7_L4PHIB14_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1D1 && innerphi==TE::Y3 && outerphi==TE::X4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIY3_D1PHIX4/TE_L1PHIY3_D1PHIX4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B7 && outerphi==TE::C18) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB7_L6PHIC18/TE_L5PHIB7_L6PHIC18_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::B5 && outerphi==TE::B12) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIB5_L6PHIB12/TE_L5PHIB5_L6PHIB12_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::D14 && outerphi==TE::D26) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHID14_L4PHID26/TE_L3PHID14_L4PHID26_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::D13 && outerphi==TE::C24) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHID13_L6PHIC24/TE_L5PHID13_L6PHIC24_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A4 && outerphi==TE::A6) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA4_L6PHIA6/TE_L5PHIA4_L6PHIA6_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::C12 && outerphi==TE::C22) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIC12_L6PHIC22/TE_L5PHIC12_L6PHIC22_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::D3D4 && innerphi==TE::C10 && outerphi==TE::C10) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_D3PHIC10_D4PHIC10/TE_D3PHIC10_D4PHIC10_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C12 && outerphi==TE::D27) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC12_L4PHID27/TE_L3PHIC12_L4PHID27_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L1L2 && innerphi==TE::E20 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L1PHIE20_L2PHIC19/TE_L1PHIE20_L2PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A2 && outerphi==TE::A7) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA2_L4PHIA7/TE_L3PHIA2_L4PHIA7_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::B5 && outerphi==TE::B11) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIB5_L4PHIB11/TE_L3PHIB5_L4PHIB11_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L5L6 && innerphi==TE::A2 && outerphi==TE::A8) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L5PHIA2_L6PHIA8/TE_L5PHIA2_L6PHIA8_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A3 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA3_L4PHIA5/TE_L3PHIA3_L4PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::A1 && outerphi==TE::A5) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIA1_L4PHIA5/TE_L3PHIA1_L4PHIA5_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C9 && outerphi==TE::C19) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC9_L4PHIC19/TE_L3PHIC9_L4PHIC19_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L3L4 && innerphi==TE::C10 && outerphi==TE::C20) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L3PHIC10_L4PHIC20/TE_L3PHIC10_L4PHIC20_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }

  } else if(seed==TE::L2D1 && innerphi==TE::X1 && outerphi==TE::X4) {
    ap_uint<1> tmp[] =
#include "../emData/TE/TE_L2PHIX1_D1PHIX4/TE_L2PHIX1_D1PHIX4_stubptinnercut.tab"
    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }
  }

}
