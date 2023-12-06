// Preprocessor macros used only in C test benches
#ifndef __SYNTHESIS__

#ifndef TestBenches_Macros_h
#define TestBenches_Macros_h

// currently defined seeds
#define L1L2_ 0
#define L2L3_ 1
#define L3L4_ 2
#define L5L6_ 3
#define D1D2_ 4
#define D3D4_ 5
#define L1D1_ 6
#define L2D1_ 7

// X-Macro format based upon:
//  https://stackoverflow.com/questions/11714325/how-to-get-enum-item-name-from-its-value
//  https://www.geeksforgeeks.org/x-macros-in-c/

// processing modules in the current wiring (indices [0, 1112])
#define MODULES \
X(FT_D1D2_, "FT_D1D2") \
X(FT_D3D4_, "FT_D3D4") \
X(FT_L1D1_, "FT_L1D1") \
X(FT_L1L2_, "FT_L1L2") \
X(FT_L2D1_, "FT_L2D1") \
X(FT_L2L3_, "FT_L2L3") \
X(FT_L3L4_, "FT_L3L4") \
X(FT_L5L6_, "FT_L5L6") \
X(IR_2S_1_A_, "IR_2S_1_A") \
X(IR_2S_1_B_, "IR_2S_1_B") \
X(IR_2S_2_A_, "IR_2S_2_A") \
X(IR_2S_2_B_, "IR_2S_2_B") \
X(IR_2S_3_A_, "IR_2S_3_A") \
X(IR_2S_3_B_, "IR_2S_3_B") \
X(IR_2S_4_A_, "IR_2S_4_A") \
X(IR_2S_4_B_, "IR_2S_4_B") \
X(IR_2S_5_A_, "IR_2S_5_A") \
X(IR_2S_5_B_, "IR_2S_5_B") \
X(IR_2S_6_A_, "IR_2S_6_A") \
X(IR_2S_6_B_, "IR_2S_6_B") \
X(IR_neg2S_1_A_, "IR_neg2S_1_A") \
X(IR_neg2S_1_B_, "IR_neg2S_1_B") \
X(IR_neg2S_2_A_, "IR_neg2S_2_A") \
X(IR_neg2S_2_B_, "IR_neg2S_2_B") \
X(IR_neg2S_3_A_, "IR_neg2S_3_A") \
X(IR_neg2S_3_B_, "IR_neg2S_3_B") \
X(IR_neg2S_4_A_, "IR_neg2S_4_A") \
X(IR_neg2S_4_B_, "IR_neg2S_4_B") \
X(IR_neg2S_5_A_, "IR_neg2S_5_A") \
X(IR_neg2S_5_B_, "IR_neg2S_5_B") \
X(IR_neg2S_6_A_, "IR_neg2S_6_A") \
X(IR_neg2S_6_B_, "IR_neg2S_6_B") \
X(IR_negPS10G_1_A_, "IR_negPS10G_1_A") \
X(IR_negPS10G_1_B_, "IR_negPS10G_1_B") \
X(IR_negPS10G_2_A_, "IR_negPS10G_2_A") \
X(IR_negPS10G_2_B_, "IR_negPS10G_2_B") \
X(IR_negPS10G_3_A_, "IR_negPS10G_3_A") \
X(IR_negPS10G_3_B_, "IR_negPS10G_3_B") \
X(IR_negPS10G_4_A_, "IR_negPS10G_4_A") \
X(IR_negPS10G_4_B_, "IR_negPS10G_4_B") \
X(IR_negPS_1_A_, "IR_negPS_1_A") \
X(IR_negPS_1_B_, "IR_negPS_1_B") \
X(IR_negPS_2_A_, "IR_negPS_2_A") \
X(IR_negPS_2_B_, "IR_negPS_2_B") \
X(IR_PS10G_1_A_, "IR_PS10G_1_A") \
X(IR_PS10G_1_B_, "IR_PS10G_1_B") \
X(IR_PS10G_2_A_, "IR_PS10G_2_A") \
X(IR_PS10G_2_B_, "IR_PS10G_2_B") \
X(IR_PS10G_3_A_, "IR_PS10G_3_A") \
X(IR_PS10G_3_B_, "IR_PS10G_3_B") \
X(IR_PS10G_4_A_, "IR_PS10G_4_A") \
X(IR_PS10G_4_B_, "IR_PS10G_4_B") \
X(IR_PS_1_A_, "IR_PS_1_A") \
X(IR_PS_1_B_, "IR_PS_1_B") \
X(IR_PS_2_A_, "IR_PS_2_A") \
X(IR_PS_2_B_, "IR_PS_2_B") \
X(PD_, "PD") \
X(VMR_D1PHIA_, "VMR_D1PHIA") \
X(VMR_D1PHIB_, "VMR_D1PHIB") \
X(VMR_D1PHIC_, "VMR_D1PHIC") \
X(VMR_D1PHID_, "VMR_D1PHID") \
X(VMR_D2PHIA_, "VMR_D2PHIA") \
X(VMR_D2PHIB_, "VMR_D2PHIB") \
X(VMR_D2PHIC_, "VMR_D2PHIC") \
X(VMR_D2PHID_, "VMR_D2PHID") \
X(VMR_D3PHIA_, "VMR_D3PHIA") \
X(VMR_D3PHIB_, "VMR_D3PHIB") \
X(VMR_D3PHIC_, "VMR_D3PHIC") \
X(VMR_D3PHID_, "VMR_D3PHID") \
X(VMR_D4PHIA_, "VMR_D4PHIA") \
X(VMR_D4PHIB_, "VMR_D4PHIB") \
X(VMR_D4PHIC_, "VMR_D4PHIC") \
X(VMR_D4PHID_, "VMR_D4PHID") \
X(VMR_D5PHIA_, "VMR_D5PHIA") \
X(VMR_D5PHIB_, "VMR_D5PHIB") \
X(VMR_D5PHIC_, "VMR_D5PHIC") \
X(VMR_D5PHID_, "VMR_D5PHID") \
X(VMR_L1PHIA_, "VMR_L1PHIA") \
X(VMR_L1PHIB_, "VMR_L1PHIB") \
X(VMR_L1PHIC_, "VMR_L1PHIC") \
X(VMR_L1PHID_, "VMR_L1PHID") \
X(VMR_L1PHIE_, "VMR_L1PHIE") \
X(VMR_L1PHIF_, "VMR_L1PHIF") \
X(VMR_L1PHIG_, "VMR_L1PHIG") \
X(VMR_L1PHIH_, "VMR_L1PHIH") \
X(VMR_L2PHIA_, "VMR_L2PHIA") \
X(VMR_L2PHIB_, "VMR_L2PHIB") \
X(VMR_L2PHIC_, "VMR_L2PHIC") \
X(VMR_L2PHID_, "VMR_L2PHID") \
X(VMR_L3PHIA_, "VMR_L3PHIA") \
X(VMR_L3PHIB_, "VMR_L3PHIB") \
X(VMR_L3PHIC_, "VMR_L3PHIC") \
X(VMR_L3PHID_, "VMR_L3PHID") \
X(VMR_L4PHIA_, "VMR_L4PHIA") \
X(VMR_L4PHIB_, "VMR_L4PHIB") \
X(VMR_L4PHIC_, "VMR_L4PHIC") \
X(VMR_L4PHID_, "VMR_L4PHID") \
X(VMR_L5PHIA_, "VMR_L5PHIA") \
X(VMR_L5PHIB_, "VMR_L5PHIB") \
X(VMR_L5PHIC_, "VMR_L5PHIC") \
X(VMR_L5PHID_, "VMR_L5PHID") \
X(VMR_L6PHIA_, "VMR_L6PHIA") \
X(VMR_L6PHIB_, "VMR_L6PHIB") \
X(VMR_L6PHIC_, "VMR_L6PHIC") \
X(VMR_L6PHID_, "VMR_L6PHID") \
X(TP_D1D2A_, "TP_D1D2A") \
X(TP_D1D2B_, "TP_D1D2B") \
X(TP_D1D2C_, "TP_D1D2C") \
X(TP_D1D2D_, "TP_D1D2D") \
X(TP_D3D4A_, "TP_D3D4A") \
X(TP_D3D4B_, "TP_D3D4B") \
X(TP_D3D4C_, "TP_D3D4C") \
X(TP_D3D4D_, "TP_D3D4D") \
X(TP_L1D1A_, "TP_L1D1A") \
X(TP_L1D1B_, "TP_L1D1B") \
X(TP_L1D1C_, "TP_L1D1C") \
X(TP_L1D1D_, "TP_L1D1D") \
X(TP_L1D1E_, "TP_L1D1E") \
X(TP_L1D1F_, "TP_L1D1F") \
X(TP_L1D1G_, "TP_L1D1G") \
X(TP_L1D1H_, "TP_L1D1H") \
X(TP_L1L2A_, "TP_L1L2A") \
X(TP_L1L2B_, "TP_L1L2B") \
X(TP_L1L2C_, "TP_L1L2C") \
X(TP_L1L2D_, "TP_L1L2D") \
X(TP_L1L2E_, "TP_L1L2E") \
X(TP_L1L2F_, "TP_L1L2F") \
X(TP_L1L2G_, "TP_L1L2G") \
X(TP_L1L2H_, "TP_L1L2H") \
X(TP_L1L2I_, "TP_L1L2I") \
X(TP_L1L2J_, "TP_L1L2J") \
X(TP_L1L2K_, "TP_L1L2K") \
X(TP_L1L2L_, "TP_L1L2L") \
X(TP_L2D1A_, "TP_L2D1A") \
X(TP_L2D1B_, "TP_L2D1B") \
X(TP_L2D1C_, "TP_L2D1C") \
X(TP_L2D1D_, "TP_L2D1D") \
X(TP_L2L3A_, "TP_L2L3A") \
X(TP_L2L3B_, "TP_L2L3B") \
X(TP_L2L3C_, "TP_L2L3C") \
X(TP_L2L3D_, "TP_L2L3D") \
X(TP_L3L4A_, "TP_L3L4A") \
X(TP_L3L4B_, "TP_L3L4B") \
X(TP_L3L4C_, "TP_L3L4C") \
X(TP_L3L4D_, "TP_L3L4D") \
X(TP_L5L6A_, "TP_L5L6A") \
X(TP_L5L6B_, "TP_L5L6B") \
X(TP_L5L6C_, "TP_L5L6C") \
X(TP_L5L6D_, "TP_L5L6D") \
X(MP_D1PHIA_, "MP_D1PHIA") \
X(MP_D1PHIB_, "MP_D1PHIB") \
X(MP_D1PHIC_, "MP_D1PHIC") \
X(MP_D1PHID_, "MP_D1PHID") \
X(MP_D2PHIA_, "MP_D2PHIA") \
X(MP_D2PHIB_, "MP_D2PHIB") \
X(MP_D2PHIC_, "MP_D2PHIC") \
X(MP_D2PHID_, "MP_D2PHID") \
X(MP_D3PHIA_, "MP_D3PHIA") \
X(MP_D3PHIB_, "MP_D3PHIB") \
X(MP_D3PHIC_, "MP_D3PHIC") \
X(MP_D3PHID_, "MP_D3PHID") \
X(MP_D4PHIA_, "MP_D4PHIA") \
X(MP_D4PHIB_, "MP_D4PHIB") \
X(MP_D4PHIC_, "MP_D4PHIC") \
X(MP_D4PHID_, "MP_D4PHID") \
X(MP_D5PHIA_, "MP_D5PHIA") \
X(MP_D5PHIB_, "MP_D5PHIB") \
X(MP_D5PHIC_, "MP_D5PHIC") \
X(MP_D5PHID_, "MP_D5PHID") \
X(MP_L1PHIA_, "MP_L1PHIA") \
X(MP_L1PHIB_, "MP_L1PHIB") \
X(MP_L1PHIC_, "MP_L1PHIC") \
X(MP_L1PHID_, "MP_L1PHID") \
X(MP_L1PHIE_, "MP_L1PHIE") \
X(MP_L1PHIF_, "MP_L1PHIF") \
X(MP_L1PHIG_, "MP_L1PHIG") \
X(MP_L1PHIH_, "MP_L1PHIH") \
X(MP_L2PHIA_, "MP_L2PHIA") \
X(MP_L2PHIB_, "MP_L2PHIB") \
X(MP_L2PHIC_, "MP_L2PHIC") \
X(MP_L2PHID_, "MP_L2PHID") \
X(MP_L3PHIA_, "MP_L3PHIA") \
X(MP_L3PHIB_, "MP_L3PHIB") \
X(MP_L3PHIC_, "MP_L3PHIC") \
X(MP_L3PHID_, "MP_L3PHID") \
X(MP_L4PHIA_, "MP_L4PHIA") \
X(MP_L4PHIB_, "MP_L4PHIB") \
X(MP_L4PHIC_, "MP_L4PHIC") \
X(MP_L4PHID_, "MP_L4PHID") \
X(MP_L5PHIA_, "MP_L5PHIA") \
X(MP_L5PHIB_, "MP_L5PHIB") \
X(MP_L5PHIC_, "MP_L5PHIC") \
X(MP_L5PHID_, "MP_L5PHID") \
X(MP_L6PHIA_, "MP_L6PHIA") \
X(MP_L6PHIB_, "MP_L6PHIB") \
X(MP_L6PHIC_, "MP_L6PHIC") \
X(MP_L6PHID_, "MP_L6PHID")

#define X(module, name) module,
enum Module : size_t
{
    MODULES
};
#undef X

#define X(module, name) name,
char const *module_name[] =
{
    MODULES
};
#undef X

#endif // TestBenches_Macros_h

#endif // __SYNTHESIS__
