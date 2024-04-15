-- dummy project for testing
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

  constant dataword_length : integer := 64;
  constant n_interfpga_links : integer := 64;
  signal AS_signals : std_logic_vector(dataword_length * 27 - 1 downto 0);
  signal MTPAR_signals : std_logic_vector(dataword_length * 18 - 1 downto 0);
  signal bx_out : std_logic_vector(2 downto 0);
  
begin

  --gen : for i in n_interfpga_links - 1 downto 0 generate

  --begin
    --How exactly do these connect to the 1st fpga: 4,5,6,7 to 56,57,58,59 or 59,58,57,56
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

    MTPAR_signals(63 + 0*64 downto 0 + 0*64) <= d(28).data(63 downto 0);
    MTPAR_signals(63 + 1*64 downto 0 + 1*64) <= d(27).data(63 downto 0);
    MTPAR_signals(63 + 2*64 downto 0 + 2*64) <= d(26).data(63 downto 0);
    MTPAR_signals(63 + 3*64 downto 0 + 3*64) <= d(25).data(63 downto 0);
    MTPAR_signals(63 + 4*64 downto 0 + 4*64) <= d(24).data(63 downto 0);
    MTPAR_signals(63 + 5*64 downto 0 + 5*64) <= d(23).data(63 downto 0);
    MTPAR_signals(63 + 6*64 downto 0 + 6*64) <= d(22).data(63 downto 0);
    MTPAR_signals(63 + 7*64 downto 0 + 7*64) <= d(21).data(63 downto 0);
    MTPAR_signals(63 + 8*64 downto 0 + 8*64) <= d(20).data(63 downto 0);
    MTPAR_signals(63 + 9*64 downto 0 + 9*64) <= d(19).data(63 downto 0);
    MTPAR_signals(63 + 10*64 downto 0 + 10*64) <= d(18).data(63 downto 0);
    MTPAR_signals(63 + 11*64 downto 0 + 11*64) <= d(17).data(63 downto 0);
    MTPAR_signals(63 + 12*64 downto 0 + 12*64) <= d(16).data(63 downto 0);
    MTPAR_signals(63 + 13*64 downto 0 + 13*64) <= d(15).data(63 downto 0);
    MTPAR_signals(63 + 14*64 downto 0 + 14*64) <= d(14).data(63 downto 0);
    MTPAR_signals(63 + 15*64 downto 0 + 15*64) <= d(13).data(63 downto 0);
    MTPAR_signals(63 + 16*64 downto 0 + 16*64) <= d(12).data(63 downto 0);
    MTPAR_signals(63 + 17*64 downto 0 + 17*64) <= d(11).data(63 downto 0);
    
    bx_out <= d(10).data(2 downto 0);
    
    --if (i<4) then

    --elsif (i<44 and i>47) then

    --elsif (i>59) then

    --elsif (i>28) then
      --9 64-bit channels exactly accomodates 16 of the 36-bit signals, since
      --there are 48 of the 36-bit signals, 27 64-bit channels will perfectly
      --accomodate all of the 36-bit signals
      --AS_signals(63 + AS_counter*64 downto 0 + AS_counter*64) <= d(i).data(63 downto 0);
      --AS_counter <= AS_counter + 1;

    --elsif (i<29 and i>11) then
      --15 75-bit signals can be accomodated by 18 64-bit words, the final
      --64-bit word will only use 37 of the bits
      --MTPAR_signals(63 + MTPAR_counter*64 downto 0 + MTPAR_counter*64) <= d(i).data(63 downto 0);
      --MTPAR_counter <= MTPAR_counter + 1;
      
    --elsif (i=11) then
      --MTPAR_signals(dataword_length * 18 - 1 downto dataword_length * 18 - 38) <= d(i).data(36 downto 0);
      
    --elsif (i=10) then
      --bx_out <= d(i).data(2 downto 0);

    --else
      --AS_counter <= 0;
      --MTPAR_counter <= 0;
    --end if;
      
  --end generate gen;

end rtl;
