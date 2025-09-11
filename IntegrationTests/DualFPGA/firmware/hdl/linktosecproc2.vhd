library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f2.all;

entity linktosecproc2 is
  port(
    clk                : in std_logic;
    d                  : in ldata(4 * N_REGION - 1 downto 0);
    AS_36_link_data    : out t_arr_AS_36_37b;
    MPAR_73_link_data  : out t_arr_MTPAR_73_76b;
    bx_link_data       : out std_logic_vector(2 downto 0);
    ctl_link_data      : out std_logic_vector(60 downto 0);
    AS_36_link_valid   : out t_arr_AS_36_1b;
    MPAR_73_link_valid : out t_arr_MTPAR_73_1b;
    bx_link_valid      : out std_logic
    );

end linktosecproc2;

architecture rtl of linktosecproc2 is

  signal AS_signals       : std_logic_vector(48*37 - 1 downto 0);
  signal MTPAR_signals    : std_logic_vector(15*76 - 1 downto 0);

begin

  --Quad0:  0, 1, 2, 3  Dummy
  --Quad1:  4, 5, 6, 7
  --Quad2:  8, 9, *10*,*11
  --Quad3:  12,13,14,15
  --Quad4:  16,17,18,19
  --Quad5:  20,21,22,23
  --Quad6:  24,25,26,27
  --Quad7:  28*,*29,30,31
  --Quad8:  32,33,34,35
  --Quad9:  36,37,38,39
  --Quad10: 40,41,42,43
  --Quad11: 44,45,46,47 Dummy
  --Quad12: 48,49,50,51
  --Quad13: 52,53,54,55
  --Quad14: 56,57,58,59*
  --Quad15: 60,61,62,63 Dummy

  AS_signals(63 + 0*64 downto 0 + 0*64) <= d(59).data(63 downto 0);
  AS_signals(63 + 1*64 downto 0 + 1*64) <= d(58).data(63 downto 0);
  AS_signals(63 + 2*64 downto 0 + 2*64) <= d(57).data(63 downto 0);
  AS_signals(63 + 3*64 downto 0 + 3*64) <= d(56).data(63 downto 0);
  AS_signals(63 + 4*64 downto 0 + 4*64) <= d(55).data(63 downto 0);
  AS_signals(63 + 5*64 downto 0 + 5*64) <= d(54).data(63 downto 0);
  AS_signals(63 + 6*64 downto 0 + 6*64) <= d(53).data(63 downto 0);
  AS_signals(63 + 7*64 downto 0 + 7*64) <= d(52).data(63 downto 0);
  AS_signals(63 + 8*64 downto 0 + 8*64) <= d(51).data(63 downto 0);
  AS_signals(63 + 9*64 downto 0 + 9*64) <= d(50).data(63 downto 0);
  AS_signals(63 + 10*64 downto 0 + 10*64) <= d(49).data(63 downto 0);
  AS_signals(63 + 11*64 downto 0 + 11*64) <= d(48).data(63 downto 0);
  
  AS_signals(63 + 12*64 downto 0 + 12*64) <= d(43).data(63 downto 0);
  AS_signals(63 + 13*64 downto 0 + 13*64) <= d(42).data(63 downto 0);
  AS_signals(63 + 14*64 downto 0 + 14*64) <= d(41).data(63 downto 0);
  AS_signals(63 + 15*64 downto 0 + 15*64) <= d(40).data(63 downto 0);
  AS_signals(63 + 16*64 downto 0 + 16*64) <= d(39).data(63 downto 0);
  AS_signals(63 + 17*64 downto 0 + 17*64) <= d(38).data(63 downto 0);
  AS_signals(63 + 18*64 downto 0 + 18*64) <= d(37).data(63 downto 0);
  AS_signals(63 + 19*64 downto 0 + 19*64) <= d(36).data(63 downto 0);
  AS_signals(63 + 20*64 downto 0 + 20*64) <= d(35).data(63 downto 0);
  AS_signals(63 + 21*64 downto 0 + 21*64) <= d(34).data(63 downto 0);
  AS_signals(63 + 22*64 downto 0 + 22*64) <= d(33).data(63 downto 0);
  AS_signals(63 + 23*64 downto 0 + 23*64) <= d(32).data(63 downto 0);
  AS_signals(63 + 24*64 downto 0 + 24*64) <= d(31).data(63 downto 0);
  AS_signals(63 + 25*64 downto 0 + 25*64) <= d(30).data(63 downto 0);
  AS_signals(63 + 26*64 downto 0 + 26*64) <= d(29).data(63 downto 0);
  AS_signals(63 + 27*64 - 16 downto 0 + 27*64) <= d(28).data(63 - 16 downto 0);

  MTPAR_signals(63 + 0*64 downto 0 + 0*64) <= d(27).data(63 downto 0);
  MTPAR_signals(63 + 1*64 downto 0 + 1*64) <= d(26).data(63 downto 0);
  MTPAR_signals(63 + 2*64 downto 0 + 2*64) <= d(25).data(63 downto 0);
  MTPAR_signals(63 + 3*64 downto 0 + 3*64) <= d(24).data(63 downto 0);
  MTPAR_signals(63 + 4*64 downto 0 + 4*64) <= d(23).data(63 downto 0);
  MTPAR_signals(63 + 5*64 downto 0 + 5*64) <= d(22).data(63 downto 0);
  MTPAR_signals(63 + 6*64 downto 0 + 6*64) <= d(21).data(63 downto 0);
  MTPAR_signals(63 + 7*64 downto 0 + 7*64) <= d(20).data(63 downto 0);
  MTPAR_signals(63 + 8*64 downto 0 + 8*64) <= d(19).data(63 downto 0);
  MTPAR_signals(63 + 9*64 downto 0 + 9*64) <= d(18).data(63 downto 0);
  MTPAR_signals(63 + 10*64 downto 0 + 10*64) <= d(17).data(63 downto 0);
  MTPAR_signals(63 + 11*64 downto 0 + 11*64) <= d(16).data(63 downto 0);
  MTPAR_signals(63 + 12*64 downto 0 + 12*64) <= d(15).data(63 downto 0);
  MTPAR_signals(63 + 13*64 downto 0 + 13*64) <= d(14).data(63 downto 0);
  MTPAR_signals(63 + 14*64 downto 0 + 14*64) <= d(13).data(63 downto 0);
  MTPAR_signals(63 + 15*64 downto 0 + 15*64) <= d(12).data(63 downto 0);
  MTPAR_signals(63 + 16*64 downto 0 + 16*64) <= d(11).data(63 downto 0);
  MTPAR_signals(63 + 17*64 - 12 downto 0 + 17*64) <= d(10).data(63 - 12 downto 0);

  AS_36_link_data(L1PHIAn1) <= AS_signals(36 downto 0);
  AS_36_link_data(L1PHIBn1) <= AS_signals(73 downto 37);
  AS_36_link_data(L1PHICn1) <= AS_signals(110 downto 74);
  AS_36_link_data(L1PHIDn1) <= AS_signals(147 downto 111);
  AS_36_link_data(L1PHIEn1) <= AS_signals(184 downto 148);
  AS_36_link_data(L1PHIFn1) <= AS_signals(221 downto 185);
  AS_36_link_data(L1PHIGn1) <= AS_signals(258 downto 222);
  AS_36_link_data(L1PHIHn1) <= AS_signals(295 downto 259);
  AS_36_link_data(L2PHIAn1) <= AS_signals(332 downto 296);
  AS_36_link_data(L2PHIBn1) <= AS_signals(369 downto 333);
  AS_36_link_data(L2PHICn1) <= AS_signals(406 downto 370);
  AS_36_link_data(L2PHIDn1) <= AS_signals(443 downto 407);
  AS_36_link_data(L3PHIAn1) <= AS_signals(480 downto 444);
  AS_36_link_data(L3PHIBn1) <= AS_signals(517 downto 481);
  AS_36_link_data(L3PHICn1) <= AS_signals(554 downto 518);
  AS_36_link_data(L3PHIDn1) <= AS_signals(591 downto 555);
  AS_36_link_data(L4PHIAn1) <= AS_signals(628 downto 592);
  AS_36_link_data(L4PHIBn1) <= AS_signals(665 downto 629);
  AS_36_link_data(L4PHICn1) <= AS_signals(702 downto 666);
  AS_36_link_data(L4PHIDn1) <= AS_signals(739 downto 703);
  AS_36_link_data(L5PHIAn1) <= AS_signals(776 downto 740);
  AS_36_link_data(L5PHIBn1) <= AS_signals(813 downto 777);
  AS_36_link_data(L5PHICn1) <= AS_signals(850 downto 814);
  AS_36_link_data(L5PHIDn1) <= AS_signals(887 downto 851);
  AS_36_link_data(L6PHIAn1) <= AS_signals(924 downto 888);
  AS_36_link_data(L6PHIBn1) <= AS_signals(961 downto 925);
  AS_36_link_data(L6PHICn1) <= AS_signals(998 downto 962);
  AS_36_link_data(L6PHIDn1) <= AS_signals(1035 downto 999);
  AS_36_link_data(D1PHIAn1) <= AS_signals(1072 downto 1036);
  AS_36_link_data(D1PHIBn1) <= AS_signals(1109 downto 1073);
  AS_36_link_data(D1PHICn1) <= AS_signals(1146 downto 1110);
  AS_36_link_data(D1PHIDn1) <= AS_signals(1183 downto 1147);
  AS_36_link_data(D2PHIAn1) <= AS_signals(1220 downto 1184);
  AS_36_link_data(D2PHIBn1) <= AS_signals(1257 downto 1221);
  AS_36_link_data(D2PHICn1) <= AS_signals(1294 downto 1258);
  AS_36_link_data(D2PHIDn1) <= AS_signals(1331 downto 1295);
  AS_36_link_data(D3PHIAn1) <= AS_signals(1368 downto 1332);
  AS_36_link_data(D3PHIBn1) <= AS_signals(1405 downto 1369);
  AS_36_link_data(D3PHICn1) <= AS_signals(1442 downto 1406);
  AS_36_link_data(D3PHIDn1) <= AS_signals(1479 downto 1443);
  AS_36_link_data(D4PHIAn1) <= AS_signals(1516 downto 1480);
  AS_36_link_data(D4PHIBn1) <= AS_signals(1553 downto 1517);
  AS_36_link_data(D4PHICn1) <= AS_signals(1590 downto 1554);
  AS_36_link_data(D4PHIDn1) <= AS_signals(1627 downto 1591);
  AS_36_link_data(D5PHIAn1) <= AS_signals(1664 downto 1628);
  AS_36_link_data(D5PHIBn1) <= AS_signals(1701 downto 1665);
  AS_36_link_data(D5PHICn1) <= AS_signals(1738 downto 1702);
  AS_36_link_data(D5PHIDn1) <= AS_signals(1775 downto 1739);

  --Note that since some AS words are built from data on multiple input links, 
  --only the valid from the first input is used
  AS_36_link_valid(L1PHIAn1) <= d(59).valid;
  AS_36_link_valid(L1PHIBn1) <= d(59).valid;
  AS_36_link_valid(L1PHICn1) <= d(58).valid;
  AS_36_link_valid(L1PHIDn1) <= d(58).valid;
  AS_36_link_valid(L1PHIEn1) <= d(57).valid;
  AS_36_link_valid(L1PHIFn1) <= d(57).valid;
  AS_36_link_valid(L1PHIGn1) <= d(56).valid;
  AS_36_link_valid(L1PHIHn1) <= d(55).valid;
  AS_36_link_valid(L2PHIAn1) <= d(55).valid;
  AS_36_link_valid(L2PHIBn1) <= d(54).valid;
  AS_36_link_valid(L2PHICn1) <= d(54).valid;
  AS_36_link_valid(L2PHIDn1) <= d(53).valid;
  AS_36_link_valid(L3PHIAn1) <= d(53).valid;
  AS_36_link_valid(L3PHIBn1) <= d(52).valid;
  AS_36_link_valid(L3PHICn1) <= d(51).valid;
  AS_36_link_valid(L3PHIDn1) <= d(51).valid;
  AS_36_link_valid(L4PHIAn1) <= d(50).valid;
  AS_36_link_valid(L4PHIBn1) <= d(50).valid;
  AS_36_link_valid(L4PHICn1) <= d(49).valid;
  AS_36_link_valid(L4PHIDn1) <= d(49).valid;
  AS_36_link_valid(L5PHIAn1) <= d(48).valid;
  AS_36_link_valid(L5PHIBn1) <= d(43).valid;
  AS_36_link_valid(L5PHICn1) <= d(43).valid;
  AS_36_link_valid(L5PHIDn1) <= d(42).valid;
  AS_36_link_valid(L6PHIAn1) <= d(42).valid;
  AS_36_link_valid(L6PHIBn1) <= d(41).valid;
  AS_36_link_valid(L6PHICn1) <= d(40).valid;
  AS_36_link_valid(L6PHIDn1) <= d(40).valid;
  AS_36_link_valid(D1PHIAn1) <= d(39).valid;
  AS_36_link_valid(D1PHIBn1) <= d(39).valid;
  AS_36_link_valid(D1PHICn1) <= d(38).valid;
  AS_36_link_valid(D1PHIDn1) <= d(38).valid;
  AS_36_link_valid(D2PHIAn1) <= d(37).valid;
  AS_36_link_valid(D2PHIBn1) <= d(36).valid;
  AS_36_link_valid(D2PHICn1) <= d(36).valid;
  AS_36_link_valid(D2PHIDn1) <= d(35).valid;
  AS_36_link_valid(D3PHIAn1) <= d(35).valid;
  AS_36_link_valid(D3PHIBn1) <= d(34).valid;
  AS_36_link_valid(D3PHICn1) <= d(34).valid;
  AS_36_link_valid(D3PHIDn1) <= d(33).valid;
  AS_36_link_valid(D4PHIAn1) <= d(32).valid;
  AS_36_link_valid(D4PHIBn1) <= d(32).valid;
  AS_36_link_valid(D4PHICn1) <= d(31).valid;
  AS_36_link_valid(D4PHIDn1) <= d(31).valid;
  AS_36_link_valid(D5PHIAn1) <= d(30).valid;
  AS_36_link_valid(D5PHIBn1) <= d(29).valid;
  AS_36_link_valid(D5PHICn1) <= d(29).valid;
  AS_36_link_valid(D5PHIDn1) <= d(28).valid;

  MPAR_73_link_data(L1L2ABC)  <= MTPAR_signals(75 downto 0);
  MPAR_73_link_data(L1L2DE)   <= MTPAR_signals(151 downto 76);
  MPAR_73_link_data(L1L2F)    <= MTPAR_signals(227 downto 152);
  MPAR_73_link_data(L1L2G)    <= MTPAR_signals(303 downto 228);
  MPAR_73_link_data(L1L2HI)   <= MTPAR_signals(379 downto 304);
  MPAR_73_link_data(L1L2JKL)  <= MTPAR_signals(455 downto 380);
  MPAR_73_link_data(L2L3ABCD) <= MTPAR_signals(531 downto 456);
  MPAR_73_link_data(L3L4AB)   <= MTPAR_signals(607 downto 532);
  MPAR_73_link_data(L3L4CD)   <= MTPAR_signals(683 downto 608);
  MPAR_73_link_data(L5L6ABCD) <= MTPAR_signals(759 downto 684);
  MPAR_73_link_data(D1D2ABCD) <= MTPAR_signals(835 downto 760);
  MPAR_73_link_data(D3D4ABCD) <= MTPAR_signals(911 downto 836);
  MPAR_73_link_data(L1D1ABCD) <= MTPAR_signals(987 downto 912);
  MPAR_73_link_data(L1D1EFGH) <= MTPAR_signals(1063 downto 988);
  MPAR_73_link_data(L2D1ABCD) <= MTPAR_signals(1139 downto 1064);

  MPAR_73_link_valid(L1L2ABC)  <= d(27).valid;
  MPAR_73_link_valid(L1L2DE)   <= d(26).valid;
  MPAR_73_link_valid(L1L2F)    <= d(25).valid;
  MPAR_73_link_valid(L1L2G)    <= d(24).valid;
  MPAR_73_link_valid(L1L2HI)   <= d(23).valid;
  MPAR_73_link_valid(L1L2JKL)  <= d(22).valid;
  MPAR_73_link_valid(L2L3ABCD) <= d(20).valid;
  MPAR_73_link_valid(L3L4AB)   <= d(19).valid;
  MPAR_73_link_valid(L3L4CD)   <= d(18).valid;
  MPAR_73_link_valid(L5L6ABCD) <= d(17).valid;
  MPAR_73_link_valid(D1D2ABCD) <= d(16).valid;
  MPAR_73_link_valid(D3D4ABCD) <= d(14).valid;
  MPAR_73_link_valid(L1D1ABCD) <= d(13).valid;
  MPAR_73_link_valid(L1D1EFGH) <= d(12).valid;
  MPAR_73_link_valid(L2D1ABCD) <= d(11).valid;

  bx_link_data <= d(9).data(2 downto 0);
  ctl_link_data <= d(9).data(63 downto 3);
  bx_link_valid <= d(9).valid;
    
end rtl;
