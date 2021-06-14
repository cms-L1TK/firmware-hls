// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __TrackletProcessor_L2L3C_LUT_drinv_V_H__
#define __TrackletProcessor_L2L3C_LUT_drinv_V_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct TrackletProcessor_L2L3C_LUT_drinv_V_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 16;
  static const unsigned AddressRange = 512;
  static const unsigned AddressWidth = 9;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(TrackletProcessor_L2L3C_LUT_drinv_V_ram) {
        ram[0] = "0b0111111101000001";
        ram[1] = "0b0111111100000001";
        ram[2] = "0b0111111011000011";
        ram[3] = "0b0111111010000100";
        ram[4] = "0b0111111001000110";
        ram[5] = "0b0111111000000111";
        ram[6] = "0b0111110111001001";
        ram[7] = "0b0111110110001100";
        ram[8] = "0b0111110101001110";
        ram[9] = "0b0111110100010001";
        ram[10] = "0b0111110011010100";
        ram[11] = "0b0111110010010111";
        ram[12] = "0b0111110001011011";
        ram[13] = "0b0111110000011111";
        ram[14] = "0b0111101111100010";
        ram[15] = "0b0111101110100111";
        ram[16] = "0b0111101101101011";
        ram[17] = "0b0111101100110000";
        ram[18] = "0b0111101011110100";
        ram[19] = "0b0111101010111010";
        ram[20] = "0b0111101001111111";
        ram[21] = "0b0111101001000100";
        ram[22] = "0b0111101000001010";
        ram[23] = "0b0111100111010000";
        ram[24] = "0b0111100110010110";
        ram[25] = "0b0111100101011100";
        ram[26] = "0b0111100100100011";
        ram[27] = "0b0111100011101010";
        ram[28] = "0b0111100010110001";
        ram[29] = "0b0111100001111000";
        ram[30] = "0b0111100000111111";
        ram[31] = "0b0111100000000111";
        ram[32] = "0b0111011111001111";
        ram[33] = "0b0111011110010111";
        ram[34] = "0b0111011101011111";
        ram[35] = "0b0111011100101000";
        ram[36] = "0b0111011011110000";
        ram[37] = "0b0111011010111001";
        ram[38] = "0b0111011010000010";
        ram[39] = "0b0111011001001011";
        ram[40] = "0b0111011000010101";
        ram[41] = "0b0111010111011110";
        ram[42] = "0b0111010110101000";
        ram[43] = "0b0111010101110010";
        ram[44] = "0b0111010100111100";
        ram[45] = "0b0111010100000111";
        ram[46] = "0b0111010011010001";
        ram[47] = "0b0111010010011100";
        ram[48] = "0b0111010001100111";
        ram[49] = "0b0111010000110010";
        ram[50] = "0b0111001111111110";
        ram[51] = "0b0111001111001001";
        ram[52] = "0b0111001110010101";
        ram[53] = "0b0111001101100001";
        ram[54] = "0b0111001100101101";
        ram[55] = "0b0111001011111001";
        ram[56] = "0b0111001011000110";
        ram[57] = "0b0111001010010010";
        ram[58] = "0b0111001001011111";
        ram[59] = "0b0111001000101100";
        ram[60] = "0b0111000111111001";
        ram[61] = "0b0111000111000111";
        ram[62] = "0b0111000110010100";
        ram[63] = "0b0111000101100010";
        ram[64] = "0b0111000100110000";
        ram[65] = "0b0111000011111110";
        ram[66] = "0b0111000011001100";
        ram[67] = "0b0111000010011010";
        ram[68] = "0b0111000001101001";
        ram[69] = "0b0111000000111000";
        ram[70] = "0b0111000000000111";
        ram[71] = "0b0110111111010110";
        ram[72] = "0b0110111110100101";
        ram[73] = "0b0110111101110100";
        ram[74] = "0b0110111101000100";
        ram[75] = "0b0110111100010011";
        ram[76] = "0b0110111011100011";
        ram[77] = "0b0110111010110011";
        ram[78] = "0b0110111010000100";
        ram[79] = "0b0110111001010100";
        ram[80] = "0b0110111000100101";
        ram[81] = "0b0110110111110101";
        ram[82] = "0b0110110111000110";
        ram[83] = "0b0110110110010111";
        ram[84] = "0b0110110101101000";
        ram[85] = "0b0110110100111010";
        ram[86] = "0b0110110100001011";
        ram[87] = "0b0110110011011101";
        ram[88] = "0b0110110010101110";
        ram[89] = "0b0110110010000000";
        ram[90] = "0b0110110001010010";
        ram[91] = "0b0110110000100101";
        ram[92] = "0b0110101111110111";
        ram[93] = "0b0110101111001010";
        ram[94] = "0b0110101110011100";
        ram[95] = "0b0110101101101111";
        ram[96] = "0b0110101101000010";
        ram[97] = "0b0110101100010101";
        ram[98] = "0b0110101011101001";
        ram[99] = "0b0110101010111100";
        ram[100] = "0b0110101010010000";
        ram[101] = "0b0110101001100011";
        ram[102] = "0b0110101000110111";
        ram[103] = "0b0110101000001011";
        ram[104] = "0b0110100111011111";
        ram[105] = "0b0110100110110100";
        ram[106] = "0b0110100110001000";
        ram[107] = "0b0110100101011101";
        ram[108] = "0b0110100100110001";
        ram[109] = "0b0110100100000110";
        ram[110] = "0b0110100011011011";
        ram[111] = "0b0110100010110000";
        ram[112] = "0b0110100010000101";
        ram[113] = "0b0110100001011011";
        ram[114] = "0b0110100000110000";
        ram[115] = "0b0110100000000110";
        ram[116] = "0b0110011111011100";
        ram[117] = "0b0110011110110010";
        ram[118] = "0b0110011110001000";
        ram[119] = "0b0110011101011110";
        ram[120] = "0b0110011100110100";
        ram[121] = "0b0110011100001011";
        ram[122] = "0b0110011011100001";
        ram[123] = "0b0110011010111000";
        ram[124] = "0b0110011010001111";
        ram[125] = "0b0110011001100110";
        ram[126] = "0b0110011000111101";
        ram[127] = "0b0110011000010100";
        ram[128] = "0b0110010111101100";
        ram[129] = "0b0110010111000011";
        ram[130] = "0b0110010110011011";
        ram[131] = "0b0110010101110010";
        ram[132] = "0b0110010101001010";
        ram[133] = "0b0110010100100010";
        ram[134] = "0b0110010011111010";
        ram[135] = "0b0110010011010011";
        ram[136] = "0b0110010010101011";
        ram[137] = "0b0110010010000011";
        ram[138] = "0b0110010001011100";
        ram[139] = "0b0110010000110101";
        ram[140] = "0b0110010000001110";
        ram[141] = "0b0110001111100111";
        ram[142] = "0b0110001111000000";
        ram[143] = "0b0110001110011001";
        ram[144] = "0b0110001101110010";
        ram[145] = "0b0110001101001100";
        ram[146] = "0b0110001100100101";
        ram[147] = "0b0110001011111111";
        ram[148] = "0b0110001011011001";
        ram[149] = "0b0110001010110010";
        ram[150] = "0b0110001010001100";
        ram[151] = "0b0110001001100111";
        ram[152] = "0b0110001001000001";
        ram[153] = "0b0110001000011011";
        ram[154] = "0b0110000111110110";
        ram[155] = "0b0110000111010000";
        ram[156] = "0b0110000110101011";
        ram[157] = "0b0110000110000110";
        ram[158] = "0b0110000101100000";
        ram[159] = "0b0110000100111100";
        ram[160] = "0b0110000100010111";
        ram[161] = "0b0110000011110010";
        ram[162] = "0b0110000011001101";
        ram[163] = "0b0110000010101001";
        ram[164] = "0b0110000010000100";
        ram[165] = "0b0110000001100000";
        ram[166] = "0b0110000000111100";
        ram[167] = "0b0110000000011000";
        ram[168] = "0b0101111111110100";
        ram[169] = "0b0101111111010000";
        ram[170] = "0b0101111110101100";
        ram[171] = "0b0101111110001000";
        ram[172] = "0b0101111101100100";
        ram[173] = "0b0101111101000001";
        ram[174] = "0b0101111100011110";
        ram[175] = "0b0101111011111010";
        ram[176] = "0b0101111011010111";
        ram[177] = "0b0101111010110100";
        ram[178] = "0b0101111010010001";
        ram[179] = "0b0101111001101110";
        ram[180] = "0b0101111001001011";
        ram[181] = "0b0101111000101001";
        ram[182] = "0b0101111000000110";
        ram[183] = "0b0101110111100100";
        ram[184] = "0b0101110111000001";
        ram[185] = "0b0101110110011111";
        ram[186] = "0b0101110101111101";
        ram[187] = "0b0101110101011011";
        ram[188] = "0b0101110100111001";
        ram[189] = "0b0101110100010111";
        ram[190] = "0b0101110011110101";
        ram[191] = "0b0101110011010011";
        ram[192] = "0b0101110010110010";
        ram[193] = "0b0101110010010000";
        ram[194] = "0b0101110001101111";
        ram[195] = "0b0101110001001101";
        ram[196] = "0b0101110000101100";
        ram[197] = "0b0101110000001011";
        ram[198] = "0b0101101111101010";
        ram[199] = "0b0101101111001001";
        ram[200] = "0b0101101110101000";
        ram[201] = "0b0101101110000111";
        ram[202] = "0b0101101101100111";
        ram[203] = "0b0101101101000110";
        ram[204] = "0b0101101100100110";
        ram[205] = "0b0101101100000101";
        ram[206] = "0b0101101011100101";
        ram[207] = "0b0101101011000101";
        ram[208] = "0b0101101010100101";
        ram[209] = "0b0101101010000100";
        ram[210] = "0b0101101001100100";
        ram[211] = "0b0101101001000101";
        ram[212] = "0b0101101000100101";
        ram[213] = "0b0101101000000101";
        ram[214] = "0b0101100111100110";
        ram[215] = "0b0101100111000110";
        ram[216] = "0b0101100110100111";
        ram[217] = "0b0101100110000111";
        ram[218] = "0b0101100101101000";
        ram[219] = "0b0101100101001001";
        ram[220] = "0b0101100100101010";
        ram[221] = "0b0101100100001011";
        ram[222] = "0b0101100011101100";
        ram[223] = "0b0101100011001101";
        ram[224] = "0b0101100010101110";
        ram[225] = "0b0101100010001111";
        ram[226] = "0b0101100001110001";
        ram[227] = "0b0101100001010010";
        ram[228] = "0b0101100000110100";
        ram[229] = "0b0101100000010110";
        ram[230] = "0b0101011111110111";
        ram[231] = "0b0101011111011001";
        ram[232] = "0b0101011110111011";
        ram[233] = "0b0101011110011101";
        ram[234] = "0b0101011101111111";
        ram[235] = "0b0101011101100001";
        ram[236] = "0b0101011101000011";
        ram[237] = "0b0101011100100110";
        ram[238] = "0b0101011100001000";
        ram[239] = "0b0101011011101010";
        ram[240] = "0b0101011011001101";
        ram[241] = "0b0101011010110000";
        ram[242] = "0b0101011010010010";
        ram[243] = "0b0101011001110101";
        ram[244] = "0b0101011001011000";
        ram[245] = "0b0101011000111011";
        ram[246] = "0b0101011000011110";
        ram[247] = "0b0101011000000001";
        ram[248] = "0b0101010111100100";
        ram[249] = "0b0101010111000111";
        ram[250] = "0b0101010110101011";
        ram[251] = "0b0101010110001110";
        ram[252] = "0b0101010101110001";
        ram[253] = "0b0101010101010101";
        ram[254] = "0b0101010100111000";
        ram[255] = "0b0101010100011100";
        ram[256] = "0b1111110100001000";
        ram[257] = "0b1111110000001111";
        ram[258] = "0b1111101100011000";
        ram[259] = "0b1111101000100011";
        ram[260] = "0b1111100100101111";
        ram[261] = "0b1111100000111110";
        ram[262] = "0b1111011101001110";
        ram[263] = "0b1111011001100000";
        ram[264] = "0b1111010101110100";
        ram[265] = "0b1111010010001001";
        ram[266] = "0b1111001110100000";
        ram[267] = "0b1111001010111001";
        ram[268] = "0b1111000111010100";
        ram[269] = "0b1111000011110000";
        ram[270] = "0b1111000000001111";
        ram[271] = "0b1110111100101110";
        ram[272] = "0b1110111001010000";
        ram[273] = "0b1110110101110011";
        ram[274] = "0b1110110010010111";
        ram[275] = "0b1110101110111101";
        ram[276] = "0b1110101011100101";
        ram[277] = "0b1110101000001110";
        ram[278] = "0b1110100100111001";
        ram[279] = "0b1110100001100101";
        ram[280] = "0b1110011110010011";
        ram[281] = "0b1110011011000010";
        ram[282] = "0b1110010111110011";
        ram[283] = "0b1110010100100101";
        ram[284] = "0b1110010001011001";
        ram[285] = "0b1110001110001110";
        ram[286] = "0b1110001011000100";
        ram[287] = "0b1110000111111100";
        ram[288] = "0b1110000100110101";
        ram[289] = "0b1110000001110000";
        ram[290] = "0b1101111110101100";
        ram[291] = "0b1101111011101001";
        ram[292] = "0b1101111000100111";
        ram[293] = "0b1101110101100111";
        ram[294] = "0b1101110010101000";
        ram[295] = "0b1101101111101011";
        ram[296] = "0b1101101100101111";
        ram[297] = "0b1101101001110100";
        ram[298] = "0b1101100110111010";
        ram[299] = "0b1101100100000001";
        ram[300] = "0b1101100001001010";
        ram[301] = "0b1101011110010100";
        ram[302] = "0b1101011011011111";
        ram[303] = "0b1101011000101011";
        ram[304] = "0b1101010101111000";
        ram[305] = "0b1101010011000111";
        ram[306] = "0b1101010000010111";
        ram[307] = "0b1101001101101000";
        ram[308] = "0b1101001010111010";
        ram[309] = "0b1101001000001101";
        ram[310] = "0b1101000101100001";
        ram[311] = "0b1101000010110110";
        ram[312] = "0b1101000000001101";
        ram[313] = "0b1100111101100100";
        ram[314] = "0b1100111010111100";
        ram[315] = "0b1100111000010110";
        ram[316] = "0b1100110101110001";
        ram[317] = "0b1100110011001100";
        ram[318] = "0b1100110000101001";
        ram[319] = "0b1100101110000111";
        ram[320] = "0b1100101011100101";
        ram[321] = "0b1100101001000101";
        ram[322] = "0b1100100110100110";
        ram[323] = "0b1100100100000111";
        ram[324] = "0b1100100001101010";
        ram[325] = "0b1100011111001110";
        ram[326] = "0b1100011100110010";
        ram[327] = "0b1100011010011000";
        ram[328] = "0b1100010111111110";
        ram[329] = "0b1100010101100101";
        ram[330] = "0b1100010011001110";
        ram[331] = "0b1100010000110111";
        ram[332] = "0b1100001110100001";
        ram[333] = "0b1100001100001100";
        ram[334] = "0b1100001001111000";
        ram[335] = "0b1100000111100100";
        ram[336] = "0b1100000101010010";
        ram[337] = "0b1100000011000000";
        ram[338] = "0b1100000000110000";
        ram[339] = "0b1011111110100000";
        ram[340] = "0b1011111100010001";
        ram[341] = "0b1011111010000010";
        ram[342] = "0b1011110111110101";
        ram[343] = "0b1011110101101001";
        ram[344] = "0b1011110011011101";
        ram[345] = "0b1011110001010010";
        ram[346] = "0b1011101111001000";
        ram[347] = "0b1011101100111110";
        ram[348] = "0b1011101010110110";
        ram[349] = "0b1011101000101110";
        ram[350] = "0b1011100110100111";
        ram[351] = "0b1011100100100001";
        ram[352] = "0b1011100010011011";
        ram[353] = "0b1011100000010111";
        ram[354] = "0b1011011110010011";
        ram[355] = "0b1011011100001111";
        ram[356] = "0b1011011010001101";
        ram[357] = "0b1011011000001011";
        ram[358] = "0b1011010110001010";
        ram[359] = "0b1011010100001001";
        ram[360] = "0b1011010010001010";
        ram[361] = "0b1011010000001011";
        ram[362] = "0b1011001110001100";
        ram[363] = "0b1011001100001111";
        ram[364] = "0b1011001010010010";
        ram[365] = "0b1011001000010110";
        ram[366] = "0b1011000110011010";
        ram[367] = "0b1011000100011111";
        ram[368] = "0b1011000010100101";
        ram[369] = "0b1011000000101100";
        ram[370] = "0b1010111110110011";
        ram[371] = "0b1010111100111010";
        ram[372] = "0b1010111011000011";
        ram[373] = "0b1010111001001100";
        ram[374] = "0b1010110111010101";
        ram[375] = "0b1010110101100000";
        ram[376] = "0b1010110011101011";
        ram[377] = "0b1010110001110110";
        ram[378] = "0b1010110000000010";
        ram[379] = "0b1010101110001111";
        ram[380] = "0b1010101100011100";
        ram[381] = "0b1010101010101010";
        ram[382] = "0b1010101000111001";
        ram[383] = "0b1010100111001000";
        ram[384] = "0b1010100101010111";
        ram[385] = "0b1010100011101000";
        ram[386] = "0b1010100001111001";
        ram[387] = "0b1010100000001010";
        ram[388] = "0b1010011110011100";
        ram[389] = "0b1010011100101111";
        ram[390] = "0b1010011011000010";
        ram[391] = "0b1010011001010101";
        ram[392] = "0b1010010111101001";
        ram[393] = "0b1010010101111110";
        ram[394] = "0b1010010100010011";
        ram[395] = "0b1010010010101001";
        ram[396] = "0b1010010001000000";
        ram[397] = "0b1010001111010111";
        ram[398] = "0b1010001101101110";
        ram[399] = "0b1010001100000110";
        ram[400] = "0b1010001010011110";
        ram[401] = "0b1010001000110111";
        ram[402] = "0b1010000111010001";
        ram[403] = "0b1010000101101011";
        ram[404] = "0b1010000100000101";
        ram[405] = "0b1010000010100000";
        ram[406] = "0b1010000000111100";
        ram[407] = "0b1001111111011000";
        ram[408] = "0b1001111101110100";
        ram[409] = "0b1001111100010001";
        ram[410] = "0b1001111010101110";
        ram[411] = "0b1001111001001100";
        ram[412] = "0b1001110111101011";
        ram[413] = "0b1001110110001001";
        ram[414] = "0b1001110100101001";
        ram[415] = "0b1001110011001000";
        ram[416] = "0b1001110001101001";
        ram[417] = "0b1001110000001001";
        ram[418] = "0b1001101110101010";
        ram[419] = "0b1001101101001100";
        ram[420] = "0b1001101011101110";
        ram[421] = "0b1001101010010000";
        ram[422] = "0b1001101000110011";
        ram[423] = "0b1001100111010111";
        ram[424] = "0b1001100101111010";
        ram[425] = "0b1001100100011111";
        ram[426] = "0b1001100011000011";
        ram[427] = "0b1001100001101000";
        ram[428] = "0b1001100000001110";
        ram[429] = "0b1001011110110100";
        ram[430] = "0b1001011101011010";
        ram[431] = "0b1001011100000001";
        ram[432] = "0b1001011010101000";
        ram[433] = "0b1001011001001111";
        ram[434] = "0b1001010111110111";
        ram[435] = "0b1001010110100000";
        ram[436] = "0b1001010101001000";
        ram[437] = "0b1001010011110010";
        ram[438] = "0b1001010010011011";
        ram[439] = "0b1001010001000101";
        ram[440] = "0b1001001111101111";
        ram[441] = "0b1001001110011010";
        ram[442] = "0b1001001101000101";
        ram[443] = "0b1001001011110001";
        ram[444] = "0b1001001010011100";
        ram[445] = "0b1001001001001001";
        ram[446] = "0b1001000111110101";
        ram[447] = "0b1001000110100010";
        ram[448] = "0b1001000101010000";
        ram[449] = "0b1001000011111101";
        ram[450] = "0b1001000010101011";
        ram[451] = "0b1001000001011010";
        ram[452] = "0b1001000000001001";
        ram[453] = "0b1000111110111000";
        ram[454] = "0b1000111101100111";
        ram[455] = "0b1000111100010111";
        ram[456] = "0b1000111011000111";
        ram[457] = "0b1000111001111000";
        ram[458] = "0b1000111000101001";
        ram[459] = "0b1000110111011010";
        ram[460] = "0b1000110110001011";
        ram[461] = "0b1000110100111101";
        ram[462] = "0b1000110011110000";
        ram[463] = "0b1000110010100010";
        ram[464] = "0b1000110001010101";
        ram[465] = "0b1000110000001000";
        ram[466] = "0b1000101110111100";
        ram[467] = "0b1000101101110000";
        ram[468] = "0b1000101100100100";
        ram[469] = "0b1000101011011000";
        ram[470] = "0b1000101010001101";
        ram[471] = "0b1000101001000010";
        ram[472] = "0b1000100111111000";
        ram[473] = "0b1000100110101110";
        ram[474] = "0b1000100101100100";
        ram[475] = "0b1000100100011010";
        ram[476] = "0b1000100011010001";
        ram[477] = "0b1000100010001000";
        ram[478] = "0b1000100000111111";
        ram[479] = "0b1000011111110111";
        ram[480] = "0b1000011110101111";
        ram[481] = "0b1000011101100111";
        ram[482] = "0b1000011100100000";
        ram[483] = "0b1000011011011001";
        ram[484] = "0b1000011010010010";
        ram[485] = "0b1000011001001011";
        ram[486] = "0b1000011000000101";
        ram[487] = "0b1000010110111111";
        ram[488] = "0b1000010101111001";
        ram[489] = "0b1000010100110100";
        ram[490] = "0b1000010011101110";
        ram[491] = "0b1000010010101001";
        ram[492] = "0b1000010001100101";
        ram[493] = "0b1000010000100001";
        ram[494] = "0b1000001111011100";
        ram[495] = "0b1000001110011001";
        ram[496] = "0b1000001101010101";
        ram[497] = "0b1000001100010010";
        ram[498] = "0b1000001011001111";
        ram[499] = "0b1000001010001100";
        ram[500] = "0b1000001001001010";
        ram[501] = "0b1000001000001000";
        ram[502] = "0b1000000111000110";
        ram[503] = "0b1000000110000100";
        ram[504] = "0b1000000101000011";
        ram[505] = "0b1000000100000010";
        ram[506] = "0b1000000011000001";
        ram[507] = "0b1000000010000000";
        ram[508] = "0b1000000001000000";
        ram[509] = "0b1000000000000000";
        ram[510] = "0b0111111111000000";
        ram[511] = "0b0111111110000000";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(TrackletProcessor_L2L3C_LUT_drinv_V) {


static const unsigned DataWidth = 16;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


TrackletProcessor_L2L3C_LUT_drinv_V_ram* meminst;


SC_CTOR(TrackletProcessor_L2L3C_LUT_drinv_V) {
meminst = new TrackletProcessor_L2L3C_LUT_drinv_V_ram("TrackletProcessor_L2L3C_LUT_drinv_V_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~TrackletProcessor_L2L3C_LUT_drinv_V() {
    delete meminst;
}


};//endmodule
#endif
