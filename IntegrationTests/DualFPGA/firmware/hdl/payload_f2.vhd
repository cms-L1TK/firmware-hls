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
  signal AS_signals : std_logic_vector(48*37 - 1 downto 0);
  signal MTPAR_signals : std_logic_vector(15*76 - 1 downto 0);
  signal bx_out : std_logic_vector(2 downto 0);
  
  signal AS_L1PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHIEn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHIFn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHIGn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L1PHIHn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L2PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L2PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L2PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L2PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L3PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L3PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L3PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L3PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L4PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L4PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L4PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L4PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L5PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L5PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L5PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L5PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L6PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L6PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L6PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_L6PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D1PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D1PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D1PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D1PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D2PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D2PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D2PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D2PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D3PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D3PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D3PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D3PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D4PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D4PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D4PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D4PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D5PHIAn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D5PHIBn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D5PHICn1_stream_V_dout : std_logic_vector(36 downto 0);
  signal AS_D5PHIDn1_stream_V_dout : std_logic_vector(36 downto 0);

  signal MTPAR_L5L6ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_L2L3ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_L3L4AB_stream_V_dout   : std_logic_vector(75 downto 0);
  signal MTPAR_L3L4CD_stream_V_dout   : std_logic_vector(75 downto 0);
  signal MTPAR_L2D1ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_L1D1ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_L1D1EFGH_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_D1D2ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_D3D4ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_L1L2ABCD_stream_V_dout : std_logic_vector(75 downto 0);
  signal MTPAR_L1L2JLK_stream_V_dout  : std_logic_vector(75 downto 0);
  signal MTPAR_L1L2DF_stream_V_dout   : std_logic_vector(75 downto 0);
  signal MTPAR_L1L2GI_stream_V_dout   : std_logic_vector(75 downto 0);
  signal MTPAR_L1L2E_stream_V_dout    : std_logic_vector(75 downto 0);
  signal MTPAR_L1L2H_stream_V_dout    : std_logic_vector(75 downto 0);

  signal d11_start : std_logic_vector(0 downto 0);
  signal d11_last : std_logic_vector(0 downto 0);
  signal d11_valid : std_logic_vector(0 downto 0);
  signal d11_start_of_orbit : std_logic_vector(0 downto 0);
  
begin

  -- This example code sends 156-word-long TMUX18 packets (i.e. same packet length as track finder output)
  -- with channel index, packet index, and word index embedded in the data word
  gen : for i in N_REGION * 4 - 1 downto 0 generate

    -- Index of word within a packet
    signal word_index : std_logic_vector(7 downto 0) := x"00";
    -- Index of packet within an orbit
    signal packet_index : std_logic_vector(8 downto 0) := "000000000";

  begin

    process (clk_p)
    begin
      if rising_edge(clk_p) then
        -- Reset counters on receiving BC0 from TCDS
        if (ctrs(i/4).bctr = x"000") and (ctrs(i/4).pctr = "0000") then
          word_index <= x"00";
          packet_index <= "000000000";
        -- Reset word index and increment packet index every 162 clock cycles (TMUX18: 18BX * 9 clocks/BX)
        elsif word_index = x"A1" then
          word_index <= x"00";
          packet_index <= std_logic_vector(unsigned(packet_index) + 1);
        else
          word_index <= std_logic_vector(unsigned(word_index) + 1);
        end if;
      end if;
    end process;

    -- Set valid high for full duration of packet
    q(i).valid <= '1' when word_index <= x"9B" else '0'; --x"9B" -> x"66"
    -- Start & last are only high for first & last clock cycle of packet
    q(i).start <= '1' when word_index = x"00" else '0';
    q(i).last <= '1' when word_index = x"9B" else '0'; --x"9B" -> x"66"

    -- Start of orbit is high in the first clock cycle of the first packet in orbit - though in final system this should instead
    -- be high in the first clock cycle of the packet containing the data from BX0 (or BXn in time slice n of a TMUX system)
    q(i).start_of_orbit <= '1' when ((word_index = x"00") and (packet_index = "000000000")) else '0';

    -- Data word: Bits 63 to 32 = channel index; bits 31 to 16 = packet index; bits 15 to 0 = word index.
    --q(i).data(63 downto 32) <= std_logic_vector(to_unsigned(i, 32));
    --q(i).data(31 downto 16) <= "0000000" & packet_index;
    --q(i).data(15 downto 0) <= x"00" & word_index;

  end generate gen;

  --process (clk_p)
  --begin
    --if rising_edge(clk_p) then
      AS_signals(63 + 0*64 downto 0*64) <= d(59).data(63 downto 0);
      AS_signals(63 + 1*64 downto 1*64) <= d(58).data(63 downto 0);
      AS_signals(63 + 2*64 downto 2*64) <= d(57).data(63 downto 0);
      AS_signals(63 + 3*64 downto 3*64) <= d(56).data(63 downto 0);
      AS_signals(63 + 4*64 downto 4*64) <= d(55).data(63 downto 0);
      AS_signals(63 + 5*64 downto 5*64) <= d(54).data(63 downto 0);
      AS_signals(63 + 6*64 downto 6*64) <= d(53).data(63 downto 0);
      AS_signals(63 + 7*64 downto 7*64) <= d(52).data(63 downto 0);
      AS_signals(63 + 8*64 downto 8*64) <= d(51).data(63 downto 0);
      AS_signals(63 + 9*64 downto 9*64) <= d(50).data(63 downto 0);
      AS_signals(63 + 10*64 downto 10*64) <= d(49).data(63 downto 0);
      AS_signals(63 + 11*64 downto 11*64) <= d(48).data(63 downto 0);
    
      AS_signals(63 + 12*64 downto 12*64) <= d(43).data(63 downto 0);
      AS_signals(63 + 13*64 downto 13*64) <= d(42).data(63 downto 0);
      AS_signals(63 + 14*64 downto 14*64) <= d(41).data(63 downto 0);
      AS_signals(63 + 15*64 downto 15*64) <= d(40).data(63 downto 0);
      AS_signals(63 + 16*64 downto 16*64) <= d(39).data(63 downto 0);
      AS_signals(63 + 17*64 downto 17*64) <= d(38).data(63 downto 0);
      AS_signals(63 + 18*64 downto 18*64) <= d(37).data(63 downto 0);
      AS_signals(63 + 19*64 downto 19*64) <= d(36).data(63 downto 0);
      AS_signals(63 + 20*64 downto 20*64) <= d(35).data(63 downto 0);
      AS_signals(63 + 21*64 downto 21*64) <= d(34).data(63 downto 0);
      AS_signals(63 + 22*64 downto 22*64) <= d(33).data(63 downto 0);
      AS_signals(63 + 23*64 downto 23*64) <= d(32).data(63 downto 0);
      AS_signals(63 + 24*64 downto 24*64) <= d(31).data(63 downto 0);
      AS_signals(63 + 25*64 downto 25*64) <= d(30).data(63 downto 0);
      AS_signals(63 + 26*64 downto 26*64) <= d(29).data(63 downto 0);
      AS_signals((63 + 27*64 - 16) downto 27*64) <= d(28).data((63 - 16) downto 0);

      MTPAR_signals(63 + 0*64 downto 0*64) <= d(27).data(63 downto 0);
      MTPAR_signals(63 + 1*64 downto 1*64) <= d(26).data(63 downto 0);
      MTPAR_signals(63 + 2*64 downto 2*64) <= d(25).data(63 downto 0);
      MTPAR_signals(63 + 3*64 downto 3*64) <= d(24).data(63 downto 0);
      MTPAR_signals(63 + 4*64 downto 4*64) <= d(23).data(63 downto 0);
      MTPAR_signals(63 + 5*64 downto 5*64) <= d(22).data(63 downto 0);
      MTPAR_signals(63 + 6*64 downto 6*64) <= d(21).data(63 downto 0);
      MTPAR_signals(63 + 7*64 downto 7*64) <= d(20).data(63 downto 0);
      MTPAR_signals(63 + 8*64 downto 8*64) <= d(19).data(63 downto 0);
      MTPAR_signals(63 + 9*64 downto 9*64) <= d(18).data(63 downto 0);
      MTPAR_signals(63 + 10*64 downto 10*64) <= d(17).data(63 downto 0);
      MTPAR_signals(63 + 11*64 downto 11*64) <= d(16).data(63 downto 0);
      MTPAR_signals(63 + 12*64 downto 12*64) <= d(15).data(63 downto 0);
      MTPAR_signals(63 + 13*64 downto 13*64) <= d(14).data(63 downto 0);
      MTPAR_signals(63 + 14*64 downto 14*64) <= d(13).data(63 downto 0);
      MTPAR_signals(63 + 15*64 downto 15*64) <= d(12).data(63 downto 0);
      MTPAR_signals(63 + 16*64 downto 16*64) <= d(11).data(63 downto 0);
      MTPAR_signals(63 + 17*64 - 12 downto 17*64) <= d(10).data(63 - 12 downto 0);
    
      bx_out <= d(9).data(2 downto 0);
      
      --reassemble sector processor signals
      AS_L1PHIAn1_stream_V_dout <= AS_signals(36 downto 0);
      AS_L1PHIBn1_stream_V_dout <= AS_signals(36 + 1*37 downto 1*37);
      AS_L1PHICn1_stream_V_dout <= AS_signals(36 + 2*37 downto 2*37);
      AS_L1PHIDn1_stream_V_dout <= AS_signals(36 + 3*37 downto 3*37);
      AS_L1PHIEn1_stream_V_dout <= AS_signals(36 + 4*37 downto 4*37);
      AS_L1PHIFn1_stream_V_dout <= AS_signals(36 + 5*37 downto 5*37);
      AS_L1PHIGn1_stream_V_dout <= AS_signals(36 + 6*37 downto 6*37);
      AS_L1PHIHn1_stream_V_dout <= AS_signals(36 + 7*37 downto 7*37);
      AS_L2PHIAn1_stream_V_dout <= AS_signals(36 + 8*37 downto 8*37);
      AS_L2PHIBn1_stream_V_dout <= AS_signals(36 + 9*37 downto 9*37);
      AS_L2PHICn1_stream_V_dout <= AS_signals(36 + 10*37 downto 10*37);
      AS_L2PHIDn1_stream_V_dout <= AS_signals(36 + 11*37 downto 11*37);
      AS_L3PHIAn1_stream_V_dout <= AS_signals(36 + 12*37 downto 12*37);
      AS_L3PHIBn1_stream_V_dout <= AS_signals(36 + 13*37 downto 13*37);
      AS_L3PHICn1_stream_V_dout <= AS_signals(36 + 14*37 downto 14*37);
      AS_L3PHIDn1_stream_V_dout <= AS_signals(36 + 15*37 downto 15*37);
      AS_L4PHIAn1_stream_V_dout <= AS_signals(36 + 16*37 downto 16*37);
      AS_L4PHIBn1_stream_V_dout <= AS_signals(36 + 17*37 downto 17*37);
      AS_L4PHICn1_stream_V_dout <= AS_signals(36 + 18*37 downto 18*37);
      AS_L4PHIDn1_stream_V_dout <= AS_signals(36 + 19*37 downto 19*37);
      AS_L5PHIAn1_stream_V_dout <= AS_signals(36 + 20*37 downto 20*37);
      AS_L5PHIBn1_stream_V_dout <= AS_signals(36 + 21*37 downto 21*37);
      AS_L5PHICn1_stream_V_dout <= AS_signals(36 + 22*37 downto 22*37);
      AS_L5PHIDn1_stream_V_dout <= AS_signals(36 + 23*37 downto 23*37);
      AS_L6PHIAn1_stream_V_dout <= AS_signals(36 + 24*37 downto 24*37);
      AS_L6PHIBn1_stream_V_dout <= AS_signals(36 + 25*37 downto 25*37);
      AS_L6PHICn1_stream_V_dout <= AS_signals(36 + 26*37 downto 26*37);
      AS_L6PHIDn1_stream_V_dout <= AS_signals(36 + 27*37 downto 27*37);
      AS_D1PHIAn1_stream_V_dout <= AS_signals(36 + 28*37 downto 28*37);
      AS_D1PHIBn1_stream_V_dout <= AS_signals(36 + 29*37 downto 29*37);
      AS_D1PHICn1_stream_V_dout <= AS_signals(36 + 30*37 downto 30*37);
      AS_D1PHIDn1_stream_V_dout <= AS_signals(36 + 31*37 downto 31*37);
      AS_D2PHIAn1_stream_V_dout <= AS_signals(36 + 32*37 downto 32*37);
      AS_D2PHIBn1_stream_V_dout <= AS_signals(36 + 33*37 downto 33*37);
      AS_D2PHICn1_stream_V_dout <= AS_signals(36 + 34*37 downto 34*37);
      AS_D2PHIDn1_stream_V_dout <= AS_signals(36 + 35*37 downto 35*37);
      AS_D3PHIAn1_stream_V_dout <= AS_signals(36 + 36*37 downto 36*37);
      AS_D3PHIBn1_stream_V_dout <= AS_signals(36 + 37*37 downto 37*37);
      AS_D3PHICn1_stream_V_dout <= AS_signals(36 + 38*37 downto 38*37);
      AS_D3PHIDn1_stream_V_dout <= AS_signals(36 + 39*37 downto 39*37);
      AS_D4PHIAn1_stream_V_dout <= AS_signals(36 + 40*37 downto 40*37);
      AS_D4PHIBn1_stream_V_dout <= AS_signals(36 + 41*37 downto 41*37);
      AS_D4PHICn1_stream_V_dout <= AS_signals(36 + 42*37 downto 42*37);
      AS_D4PHIDn1_stream_V_dout <= AS_signals(36 + 43*37 downto 43*37);
      AS_D5PHIAn1_stream_V_dout <= AS_signals(36 + 44*37 downto 44*37);
      AS_D5PHIBn1_stream_V_dout <= AS_signals(36 + 45*37 downto 45*37);
      AS_D5PHICn1_stream_V_dout <= AS_signals(36 + 46*37 downto 46*37);
      AS_D5PHIDn1_stream_V_dout <= AS_signals(36 + 47*37 downto 47*37);

      MTPAR_L5L6ABCD_stream_V_dout <= MTPAR_signals(75 downto 0);
      MTPAR_L2L3ABCD_stream_V_dout <= MTPAR_signals(75 + 76*1 downto 76*1);
      MTPAR_L3L4AB_stream_V_dout   <= MTPAR_signals(75 + 76*2 downto 76*2);
      MTPAR_L3L4CD_stream_V_dout   <= MTPAR_signals(75 + 76*3 downto 76*3);
      MTPAR_L2D1ABCD_stream_V_dout <= MTPAR_signals(75 + 76*4 downto 76*4);
      MTPAR_L1D1ABCD_stream_V_dout <= MTPAR_signals(75 + 76*5 downto 76*5);
      MTPAR_L1D1EFGH_stream_V_dout <= MTPAR_signals(75 + 76*6 downto 76*6);
      MTPAR_D1D2ABCD_stream_V_dout <= MTPAR_signals(75 + 76*7 downto 76*7);
      MTPAR_D3D4ABCD_stream_V_dout <= MTPAR_signals(75 + 76*8 downto 76*8);
      MTPAR_L1L2ABCD_stream_V_dout <= MTPAR_signals(75 + 76*9 downto 76*9);
      MTPAR_L1L2JLK_stream_V_dout  <= MTPAR_signals(75 + 76*10 downto 76*10);
      MTPAR_L1L2DF_stream_V_dout   <= MTPAR_signals(75 + 76*11 downto 76*11);
      MTPAR_L1L2GI_stream_V_dout   <= MTPAR_signals(75 + 76*12 downto 76*12);
      MTPAR_L1L2E_stream_V_dout    <= MTPAR_signals(75 + 76*13 downto 76*13);
      MTPAR_L1L2H_stream_V_dout    <= MTPAR_signals(75 + 76*14 downto 76*14);

  --This block of code is to be used when someone generates the corresponding vio in the vivado gui
  --vio_0 : entity work.vio_0
  --      port map(
  --        clk => clk,
  --        probe_in0 => AS_L1PHIAn1_stream_V_dout,
  --        probe_in1 => AS_L1PHIBn1_stream_V_dout,
  --        probe_in2 => AS_L1PHICn1_stream_V_dout,
  --        probe_in3 => AS_L1PHIDn1_stream_V_dout,
  --        probe_in4 => AS_L3PHIAn1_stream_V_dout,
  --        probe_in5 => AS_L5PHIDn1_stream_V_dout,
  --        probe_in6 => AS_L6PHICn1_stream_V_dout,
  --        probe_in7 => AS_D1PHIAn1_stream_V_dout,
  --        probe_in8 => AS_D2PHIAn1_stream_V_dout,
  --        probe_in9 => AS_D4PHIDn1_stream_V_dout,
  --        probe_in10 => MTPAR_L5L6ABCD_stream_V_dout,
  --        probe_in11 => MTPAR_L2L3ABCD_stream_V_dout,
  --        probe_in12 => MTPAR_L3L4AB_stream_V_dout,
  --        probe_in13 => MTPAR_L3L4CD_stream_V_dout,
  --        probe_in14 => MTPAR_D1D2ABCD_stream_V_dout,
  --        probe_in15 => MTPAR_L1L2H_stream_V_dout,
  --        probe_in16 => clk40
  --      );

    d11_start(0) <= d(11).start;
    d11_last(0) <= d(11).last;
    d11_valid(0) <= d(11).valid;
    d11_start_of_orbit <= d(11).start_of_orbit;
  
    ila_0 : entity work.ila_0
      port map(
        clk => clk_p,
        probe0 => AS_L1PHIAn1_stream_V_dout,
        probe1 => AS_L1PHICn1_stream_V_dout,
        probe2 => AS_L6PHICn1_stream_V_dout,
        probe3 => AS_D4PHIDn1_stream_V_dout,
        probe4 => MTPAR_L5L6ABCD_stream_V_dout,
        probe5 => MTPAR_L3L4AB_stream_V_dout,
        probe6 => MTPAR_D1D2ABCD_stream_V_dout,
        probe7 => MTPAR_L1L2H_stream_V_dout,
        probe8 => d11_start,
        probe9 => d11_last,
        probe10 => d11_valid,
        probe11=>d11_start_of_orbit
      );
  
  --ipb_out.ipb_rdata <= AS_L1PHIAn1_stream_V_dout;
  
    --end if;
  --end process
       
end rtl;
