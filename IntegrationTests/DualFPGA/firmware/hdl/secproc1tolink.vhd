library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f1.all;

entity secproc1tolink is
  port(
    clk                    : in std_logic;
    rst                    : in std_logic;
    TP_bx_out              : in std_logic_vector(2 downto 0);
    AS_37_stream_V_dout    : in t_arr_AS_37_DATA;
    MTPAR_76_stream_V_dout : in t_arr_MTPAR_76_DATA;
    q                      : out ldata(4 * N_REGION - 1 downto 0)
    );

end secproc1tolink;

architecture rtl of secproc1tolink is

  signal bx_out : std_logic_vector(2 downto 0) := "111";  
  
  constant dataword_length : integer := 64;
  constant n_interfpga_links : integer := 64;
  signal AS_counter : integer := 0;
  signal MTPAR_counter : integer := 0;
  signal AS_signals : std_logic_vector(dataword_length * 28 - 1 downto 0);
  signal MTPAR_signals : std_logic_vector(dataword_length * 18 - 1 downto 0);

begin

  AS_signals(1775 downto 0) <= AS_37_stream_V_dout(L1PHIAn1) &
                               AS_37_stream_V_dout(L1PHIBn1) &
                               AS_37_stream_V_dout(L1PHICn1) &
                               AS_37_stream_V_dout(L1PHIDn1) &
                               AS_37_stream_V_dout(L1PHIEn1) &
                               AS_37_stream_V_dout(L1PHIFn1) &
                               AS_37_stream_V_dout(L1PHIGn1) &
                               AS_37_stream_V_dout(L1PHIHn1) &
                               AS_37_stream_V_dout(L2PHIAn1) &
                               AS_37_stream_V_dout(L2PHIBn1) &
                               AS_37_stream_V_dout(L2PHICn1) &
                               AS_37_stream_V_dout(L2PHIDn1) &
                               AS_37_stream_V_dout(L3PHIAn1) &
                               AS_37_stream_V_dout(L3PHIBn1) &
                               AS_37_stream_V_dout(L3PHICn1) &
                               AS_37_stream_V_dout(L3PHIDn1) &
                               AS_37_stream_V_dout(L4PHIAn1) &
                               AS_37_stream_V_dout(L4PHIBn1) &
                               AS_37_stream_V_dout(L4PHICn1) &
                               AS_37_stream_V_dout(L4PHIDn1) &
                               AS_37_stream_V_dout(L5PHIAn1) &
                               AS_37_stream_V_dout(L5PHIBn1) &
                               AS_37_stream_V_dout(L5PHICn1) &
                               AS_37_stream_V_dout(L5PHIDn1) &
                               AS_37_stream_V_dout(L6PHIAn1) &
                               AS_37_stream_V_dout(L6PHIBn1) &
                               AS_37_stream_V_dout(L6PHICn1) &
                               AS_37_stream_V_dout(L6PHIDn1) &
                               AS_37_stream_V_dout(D1PHIAn1) &
                               AS_37_stream_V_dout(D1PHIBn1) &
                               AS_37_stream_V_dout(D1PHICn1) &
                               AS_37_stream_V_dout(D1PHIDn1) &
                               AS_37_stream_V_dout(D2PHIAn1) &
                               AS_37_stream_V_dout(D2PHIBn1) &
                               AS_37_stream_V_dout(D2PHICn1) &
                               AS_37_stream_V_dout(D2PHIDn1) &
                               AS_37_stream_V_dout(D3PHIAn1) &
                               AS_37_stream_V_dout(D3PHIBn1) &
                               AS_37_stream_V_dout(D3PHICn1) &
                               AS_37_stream_V_dout(D3PHIDn1) &
                               AS_37_stream_V_dout(D4PHIAn1) &
                               AS_37_stream_V_dout(D4PHIBn1) &
                               AS_37_stream_V_dout(D4PHICn1) &
                               AS_37_stream_V_dout(D4PHIDn1) &
                               AS_37_stream_V_dout(D5PHIAn1) &
                               AS_37_stream_V_dout(D5PHIBn1) &
                               AS_37_stream_V_dout(D5PHICn1) &
                               AS_37_stream_V_dout(D5PHIDn1);

  MTPAR_signals(1139 downto 0) <= MTPAR_76_stream_V_dout(L1L2ABC) &
                                  MTPAR_76_stream_V_dout(L1L2DF) &
                                  MTPAR_76_stream_V_dout(L1L2E) &
                                  MTPAR_76_stream_V_dout(L1L2GI) &
                                  MTPAR_76_stream_V_dout(L1L2H) &
                                  MTPAR_76_stream_V_dout(L1L2JLK) &
                                  MTPAR_76_stream_V_dout(L2L3ABCD) &
                                  MTPAR_76_stream_V_dout(L3L4AB) &
                                  MTPAR_76_stream_V_dout(L3L4CD) &
                                  MTPAR_76_stream_V_dout(L5L6ABCD) &
                                  MTPAR_76_stream_V_dout(D1D2ABCD) &
                                  MTPAR_76_stream_V_dout(D3D4ABCD) &
                                  MTPAR_76_stream_V_dout(L1D1ABCD) &
                                  MTPAR_76_stream_V_dout(L1D1EFGH) &
                                  MTPAR_76_stream_V_dout(L2D1ABCD);
  
  --debugging just send some signals for now -MO
  q(4).data <= AS_signals(63 downto 0);
  q(5).data <= AS_signals(127 downto 64);
  q(6).data <= AS_signals(191 downto 128);
  q(7).data <= AS_signals(255 downto 192);

  q(8).data <= MTPAR_signals(63 downto 0);
  q(9).data <= MTPAR_signals(127 downto 64);
  q(10).data <= MTPAR_signals(191 downto 128);
  q(11).data <= MTPAR_signals(255 downto 192);

  --gen : for i in n_interfpga_links - 1 downto 0 generate

  --begin
  --  --Quad0:  0, 1, 2, 3  Dummy
  --  --Quad1:  *4, 5, 6, 7
  --  --Quad2:  8, 9, 10,11
  --  --Quad3:  12,13,14,15
  --  --Quad4:  16,17,18,19 Dummy
  --  --Quad5:  20,21,22,23
  --  --Quad6:  24,25,26,27
  --  --Quad7:  28,29,30,31
  --  --Quad8:  32,33,34*,*35
  --  --Quad9:  36,37,38,39
  --  --Quad10: 40,41,42,43
  --  --Quad11: 44,45,46,47
  --  --Quad12: 48,49,50,51
  --  --Quad13: 52*,*53*,54,55
  --  --Quad14: 56,57,58,59
  --  --Quad15: 60,61,62,63 Dummy
  --  if (i<4) then
  --    
  --  elsif (i>11 and i<16) then

  --  elsif (i>59) then

  --  elsif (i>3 and i<35) then
  --    --9 64-bit channels exactly accomodates 16 of the 36-bit signals, since
  --    --there are 48 of the 36-bit signals, 27 64-bit channels will perfectly
  --    --accomodate all of the 36-bit signals
  --    q(i).data(63 downto 0) <= AS_signals(63 + AS_counter*64 downto 0 + AS_counter*64);
  --    AS_counter <= AS_counter + 1;

  --  elsif (i>34 and i<52) then
  --    --15 75-bit signals can be accomodated by 18 64-bit words, the final
  --    --64-bit word will only use 37 of the bits 
  --    q(i).data(63 downto 0) <= MTPAR_signals(63 + MTPAR_counter*64 downto 0 + MTPAR_counter*64);
  --    MTPAR_counter <= MTPAR_counter + 1;

  --  elsif i=52 then
  --    q(i).data(36 downto 0) <= MTPAR_signals(dataword_length * 18 - 1 downto dataword_length * 18 - 38);

  --  elsif i=53 then
  --    q(i).data(2 downto 0) <= bx_out;
  --    
  --end generate gen;
    
end rtl;
