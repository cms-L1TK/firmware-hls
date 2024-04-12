library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.ipbus.all;
use work.emp_data_types.all;
use work.emp_project_decl.all;

use work.emp_device_decl.all;
use work.emp_ttc_decl.all;

use work.emp_slink_types.all;

entity emp_payload is
  port(
    clk         : in  std_logic;        -- ipbus signals
    rst         : in  std_logic;
    ipb_in      : in  ipb_wbus;
    ipb_out     : out ipb_rbus;
    clk40       : in  std_logic;
    clk_payload : in  std_logic_vector(2 downto 0);
    rst_payload : in  std_logic_vector(2 downto 0);
    clk_p       : in  std_logic;        -- data clock
    rst_loc     : in  std_logic_vector(N_REGION - 1 downto 0);
    clken_loc   : in  std_logic_vector(N_REGION - 1 downto 0);
    ctrs        : in  ttc_stuff_array;
    bc0         : out std_logic;
    d           : in  ldata(4 * N_REGION - 1 downto 0);  -- data in
    q           : out ldata(4 * N_REGION - 1 downto 0);  -- data out
    gpio        : out std_logic_vector(29 downto 0);  -- IO to mezzanine connector
    gpio_en     : out std_logic_vector(29 downto 0);  -- IO to mezzanine connector (three-state enables)
    slink_q : out slink_input_data_quad_array(SLINK_MAX_QUADS-1 downto 0);
    backpressure : in std_logic_vector(SLINK_MAX_QUADS-1 downto 0)
    );

end emp_payload;

architecture rtl of emp_payload is

  signal AS_D5PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"0";
  signal AS_D5PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1";
  signal AS_D5PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2";
  signal AS_D5PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"3";
  signal AS_D4PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"4";
  signal AS_D4PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"5";
  signal AS_D4PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"6";
  signal AS_D4PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"7";
  signal AS_D3PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"8";
  signal AS_D3PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"9";
  signal AS_D3PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"A";
  signal AS_D3PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"B";
  signal AS_D2PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"C";
  signal AS_D2PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"D";
  signal AS_D2PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"E";
  signal AS_D2PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"F";
  signal AS_D1PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"10";
  signal AS_D1PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"11";
  signal AS_D1PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"12";
  signal AS_D1PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"13";
  signal AS_L6PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"14";
  signal AS_L6PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"15";
  signal AS_L6PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"16";
  signal AS_L6PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"17";
  signal AS_L5PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"18";
  signal AS_L5PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"19";
  signal AS_L5PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1A";
  signal AS_L5PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1B";
  signal AS_L4PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1C";
  signal AS_L4PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1D";
  signal AS_L4PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1E";
  signal AS_L4PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"1F";
  signal AS_L3PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"20";
  signal AS_L3PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"21";
  signal AS_L3PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"22";
  signal AS_L3PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"23";
  signal AS_L2PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"24";
  signal AS_L2PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"25";
  signal AS_L2PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"26";
  signal AS_L2PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"27";
  signal AS_L1PHIHn1_stream_V_dout : std_logic_vector(35 downto 0) := x"28";
  signal AS_L1PHIGn1_stream_V_dout : std_logic_vector(35 downto 0) := x"29";
  signal AS_L1PHIFn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2A";
  signal AS_L1PHIEn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2B";
  signal AS_L1PHIDn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2C";
  signal AS_L1PHICn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2D";
  signal AS_L1PHIBn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2E";
  signal AS_L1PHIAn1_stream_V_dout : std_logic_vector(35 downto 0) := x"2F";

  signal MTPAR_L1L2H_stream_V_dout    : std_logic_vector(74 downto 0) := x"30";
  signal MTPAR_L1L2E_stream_V_dout    : std_logic_vector(74 downto 0) := x"31";
  signal MTPAR_L1L2GI_stream_V_dout   : std_logic_vector(74 downto 0) := x"32";
  signal MTPAR_L1L2DF_stream_V_dout   : std_logic_vector(74 downto 0) := x"33";
  signal MTPAR_L1L2JLK_stream_V_dout  : std_logic_vector(74 downto 0) := x"34";
  signal MTPAR_L1L2ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"35";
  signal MTPAR_D3D4ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"36";
  signal MTPAR_D1D2ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"37";
  signal MTPAR_L1D1EFGH_stream_V_dout : std_logic_vector(74 downto 0) := x"38";
  signal MTPAR_L1D1ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"39";
  signal MTPAR_L2D1ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"3A";
  signal MTPAR_L3L4CD_stream_V_dout   : std_logic_vector(74 downto 0) := x"3B";
  signal MTPAR_L3L4AB_stream_V_dout   : std_logic_vector(74 downto 0) := x"3C";
  signal MTPAR_L2L3ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"3D";
  signal MTPAR_L5L6ABCD_stream_V_dout : std_logic_vector(74 downto 0) := x"3E";

  signal bx_out : std_logic_vector(2 downto 0) := "111";  
  
  constant dataword_length : integer := 64;
  constant n_interfpga_links : integer := 64;
  signal AS_counter : integer := 0;
  signal MTPAR_counter : integer := 0;
  signal AS_signals : std_logic_vector(dataword_length * 27 - 1 downto 0) := AS_D5PHIDn1_stream_V_dout &
                                                                             AS_D5PHICn1_stream_V_dout &
                                                                             AS_D5PHIBn1_stream_V_dout &
                                                                             AS_D5PHIAn1_stream_V_dout &
                                                                             AS_D4PHIDn1_stream_V_dout &
                                                                             AS_D4PHICn1_stream_V_dout &
                                                                             AS_D4PHIBn1_stream_V_dout &
                                                                             AS_D4PHIAn1_stream_V_dout &
                                                                             AS_D3PHIDn1_stream_V_dout &
                                                                             AS_D3PHICn1_stream_V_dout &
                                                                             AS_D3PHIBn1_stream_V_dout &
                                                                             AS_D3PHIAn1_stream_V_dout &
                                                                             AS_D2PHIDn1_stream_V_dout &
                                                                             AS_D2PHICn1_stream_V_dout &
                                                                             AS_D2PHIBn1_stream_V_dout &
                                                                             AS_D2PHIAn1_stream_V_dout &
                                                                             AS_D1PHIDn1_stream_V_dout &
                                                                             AS_D1PHICn1_stream_V_dout &
                                                                             AS_D1PHIBn1_stream_V_dout &
                                                                             AS_D1PHIAn1_stream_V_dout &
                                                                             AS_L6PHIDn1_stream_V_dout &
                                                                             AS_L6PHICn1_stream_V_dout &
                                                                             AS_L6PHIBn1_stream_V_dout &
                                                                             AS_L6PHIAn1_stream_V_dout &
                                                                             AS_L5PHIDn1_stream_V_dout &
                                                                             AS_L5PHICn1_stream_V_dout &
                                                                             AS_L5PHIBn1_stream_V_dout &
                                                                             AS_L5PHIAn1_stream_V_dout &
                                                                             AS_L4PHIDn1_stream_V_dout &
                                                                             AS_L4PHICn1_stream_V_dout &
                                                                             AS_L4PHIBn1_stream_V_dout &
                                                                             AS_L4PHIAn1_stream_V_dout &
                                                                             AS_L3PHIDn1_stream_V_dout &
                                                                             AS_L3PHICn1_stream_V_dout &
                                                                             AS_L3PHIBn1_stream_V_dout &
                                                                             AS_L3PHIAn1_stream_V_dout &
                                                                             AS_L2PHIDn1_stream_V_dout &
                                                                             AS_L2PHICn1_stream_V_dout &
                                                                             AS_L2PHIBn1_stream_V_dout &
                                                                             AS_L2PHIAn1_stream_V_dout &
                                                                             AS_L1PHIHn1_stream_V_dout &
                                                                             AS_L1PHIGn1_stream_V_dout &
                                                                             AS_L1PHIFn1_stream_V_dout &
                                                                             AS_L1PHIEn1_stream_V_dout &
                                                                             AS_L1PHIDn1_stream_V_dout &
                                                                             AS_L1PHICn1_stream_V_dout &
                                                                             AS_L1PHIBn1_stream_V_dout &
                                                                             AS_L1PHIAn1_stream_V_dout;
  
  signal MTPAR_signals : std_logic_vector(dataword_length * 18 - 1 downto 0) := MTPAR_L1L2H_stream_V_dout &
                                                                                MTPAR_L1L2E_stream_V_dout &
                                                                                MTPAR_L1L2GI_stream_V_dout &
                                                                                MTPAR_L1L2DF_stream_V_dout &
                                                                                MTPAR_L1L2JLK_stream_V_dout &
                                                                                MTPAR_L1L2ABCD_stream_V_dout &
                                                                                MTPAR_D3D4ABCD_stream_V_dout &
                                                                                MTPAR_D1D2ABCD_stream_V_dout &
                                                                                MTPAR_L1D1EFGH_stream_V_dout &
                                                                                MTPAR_L1D1ABCD_stream_V_dout &
                                                                                MTPAR_L2D1ABCD_stream_V_dout &
                                                                                MTPAR_L3L4CD_stream_V_dout &
                                                                                MTPAR_L3L4AB_stream_V_dout &
                                                                                MTPAR_L2L3ABCD_stream_V_dout &
                                                                                MTPAR_L5L6ABCD_stream_V_dout;

begin

  gen : for i in n_interfpga_links - 1 downto 0 generate

  begin
    --Quad0:  0, 1, 2, 3  Dummy
    --Quad1:  *4, 5, 6, 7
    --Quad2:  8, 9, 10,11
    --Quad3:  12,13,14,15
    --Quad4:  16,17,18,19 Dummy
    --Quad5:  20,21,22,23
    --Quad6:  24,25,26,27
    --Quad7:  28,29,30,31
    --Quad8:  32,33,34*,*35
    --Quad9:  36,37,38,39
    --Quad10: 40,41,42,43
    --Quad11: 44,45,46,47
    --Quad12: 48,49,50,51
    --Quad13: 52*,*53*,54,55
    --Quad14: 56,57,58,59
    --Quad15: 60,61,62,63 Dummy
    if (i<4) then
      
    elsif (i>11 and i<16) then

    elsif (i>59) then

    elsif (i>3 and i<35) then
      --9 64-bit channels exactly accomodates 16 of the 36-bit signals, since
      --there are 48 of the 36-bit signals, 27 64-bit channels will perfectly
      --accomodate all of the 36-bit signals
      q(i).data(63 downto 0) <= AS_signals(63 + AS_counter*64 downto 0 + AS_counter*64);
      AS_counter <= AS_counter + 1;

    elsif (i>34 and i<52) then
      --15 75-bit signals can be accomodated by 18 64-bit words, the final
      --64-bit word will only use 37 of the bits 
      q(i).data(63 downto 0) <= MTPAR_signals(63 + MTPAR_counter*64 downto 0 + MTPAR_counter*64);
      MTPAR_counter <= MTPAR_counter + 1;

    elsif i=52 then
      q(i).data(36 downto 0) <= MTPAR_signals(dataword_length * 18 - 1 downto dataword_length * 18 - 38);

    elsif i=53 then
      q(i).data(2 downto 0) <= bx_out;

    else
      AS_counter <= 0;
      MTPAR_counter <=0;
    end if;
      
  end generate gen;
    
end rtl;
