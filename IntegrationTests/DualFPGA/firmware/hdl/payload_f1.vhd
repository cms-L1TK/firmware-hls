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

  signal AS_D5PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000000";
  signal AS_D5PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000001";
  signal AS_D5PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000002";
  signal AS_D5PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000003";
  signal AS_D4PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000004";
  signal AS_D4PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000005";
  signal AS_D4PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000006";
  signal AS_D4PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000007";
  signal AS_D3PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000008";
  signal AS_D3PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000009";
  signal AS_D3PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000000A";
  signal AS_D3PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000000B";
  signal AS_D2PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000000C";
  signal AS_D2PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000000D";
  signal AS_D2PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000000E";
  signal AS_D2PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000000F";
  signal AS_D1PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000010";
  signal AS_D1PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000011";
  signal AS_D1PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000012";
  signal AS_D1PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000013";
  signal AS_L6PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000014";
  signal AS_L6PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000015";
  signal AS_L6PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000016";
  signal AS_L6PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000017";
  signal AS_L5PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000018";
  signal AS_L5PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000019";
  signal AS_L5PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000001A";
  signal AS_L5PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000001B";
  signal AS_L4PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000001C";
  signal AS_L4PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000001D";
  signal AS_L4PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000001E";
  signal AS_L4PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000001F";
  signal AS_L3PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000020";
  signal AS_L3PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000021";
  signal AS_L3PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000022";
  signal AS_L3PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000023";
  signal AS_L2PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000024";
  signal AS_L2PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000025";
  signal AS_L2PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000026";
  signal AS_L2PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000027";
  signal AS_L1PHIHn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000028";
  signal AS_L1PHIGn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"000000029";
  signal AS_L1PHIFn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000002A";
  signal AS_L1PHIEn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000002B";
  signal AS_L1PHIDn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000002C";
  signal AS_L1PHICn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000002D";
  signal AS_L1PHIBn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000002E";
  signal AS_L1PHIAn1_stream_V_dout : std_logic_vector(36 downto 0) := "1" & x"00000002F";
  
  signal MTPAR_L1L2H_stream_V_dout    : std_logic_vector(75 downto 0) := x"1000000000000000030";
  signal MTPAR_L1L2E_stream_V_dout    : std_logic_vector(75 downto 0) := x"1000000000000000031";
  signal MTPAR_L1L2GI_stream_V_dout   : std_logic_vector(75 downto 0) := x"1000000000000000032";
  signal MTPAR_L1L2DF_stream_V_dout   : std_logic_vector(75 downto 0) := x"1000000000000000033";
  signal MTPAR_L1L2JLK_stream_V_dout  : std_logic_vector(75 downto 0) := x"1000000000000000034";
  signal MTPAR_L1L2ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"1000000000000000035";
  signal MTPAR_D3D4ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"1000000000000000036";
  signal MTPAR_D1D2ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"1000000000000000037";
  signal MTPAR_L1D1EFGH_stream_V_dout : std_logic_vector(75 downto 0) := x"1000000000000000038";
  signal MTPAR_L1D1ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"1000000000000000039";
  signal MTPAR_L2D1ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"100000000000000003A";
  signal MTPAR_L3L4CD_stream_V_dout   : std_logic_vector(75 downto 0) := x"100000000000000003B";
  signal MTPAR_L3L4AB_stream_V_dout   : std_logic_vector(75 downto 0) := x"100000000000000003C";
  signal MTPAR_L2L3ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"100000000000000003D";
  signal MTPAR_L5L6ABCD_stream_V_dout : std_logic_vector(75 downto 0) := x"100000000000000003E";

  signal bx_out : std_logic_vector(2 downto 0) := "111";  
  
  constant dataword_length : integer := 64;
  constant n_interfpga_links : integer := 64;
  signal AS_counter : integer := 0;
  signal MTPAR_counter : integer := 0;
  signal AS_signals : std_logic_vector(48*37 - 1 downto 0) := AS_D5PHIDn1_stream_V_dout &
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
  
  signal MTPAR_signals : std_logic_vector(76*15 - 1 downto 0) := MTPAR_L1L2H_stream_V_dout &
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
      --48 37bit signals can be accomodated by 28 64bit signals, this will leave
      --16 empty bits in the last data word
      q(4).data(63 downto 0) <= AS_signals((63 + 0*64) downto 0);
      q(5).data(63 downto 0) <= AS_signals((63 + 1*64) downto 1*64);
      q(6).data(63 downto 0) <= AS_signals((63 + 2*64) downto 2*64);
      q(7).data(63 downto 0) <= AS_signals((63 + 3*64) downto 3*64);
      q(8).data(63 downto 0) <= AS_signals((63 + 4*64) downto 4*64);
      q(9).data(63 downto 0) <= AS_signals((63 + 5*64) downto 5*64);
      q(10).data(63 downto 0) <= AS_signals((63 + 6*64) downto 6*64);
      q(11).data(63 downto 0) <= AS_signals((63 + 7*64) downto 7*64);
      q(12).data(63 downto 0) <= AS_signals((63 + 8*64) downto 8*64);
      q(13).data(63 downto 0) <= AS_signals((63 + 9*64) downto 9*64);
      q(14).data(63 downto 0) <= AS_signals((63 + 10*64) downto 10*64);
      q(15).data(63 downto 0) <= AS_signals((63 + 11*64) downto 11*64);
    
      q(20).data(63 downto 0) <= AS_signals((63 + 12*64) downto 12*64);
      q(21).data(63 downto 0) <= AS_signals((63 + 13*64) downto 13*64);
      q(22).data(63 downto 0) <= AS_signals((63 + 14*64) downto 14*64);
      q(23).data(63 downto 0) <= AS_signals((63 + 15*64) downto 15*64);
      q(24).data(63 downto 0) <= AS_signals((63 + 16*64) downto 16*64);
      q(25).data(63 downto 0) <= AS_signals((63 + 17*64) downto 17*64);
      q(26).data(63 downto 0) <= AS_signals((63 + 18*64) downto 18*64);
      q(27).data(63 downto 0) <= AS_signals((63 + 19*64) downto 19*64);
      q(28).data(63 downto 0) <= AS_signals((63 + 20*64) downto 20*64);
      q(29).data(63 downto 0) <= AS_signals((63 + 21*64) downto 21*64);
      q(30).data(63 downto 0) <= AS_signals((63 + 22*64) downto 22*64);
      q(31).data(63 downto 0) <= AS_signals((63 + 23*64) downto 23*64);
      q(32).data(63 downto 0) <= AS_signals((63 + 24*64) downto 24*64);
      q(33).data(63 downto 0) <= AS_signals((63 + 25*64) downto 25*64);
      q(34).data(63 downto 0) <= AS_signals((63 + 26*64) downto 26*64);
      q(35).data(63 downto 0) <= x"0000" & AS_signals((63 + 27*64 - 16) downto 27*64);

      --15 76bit signals can be accomodated by 18 64bit signals, this will leave
      --12 empty bits in the last data word
      q(36).data(63 downto 0) <= MTPAR_signals((63 + 0*64) downto 0*64);
      q(37).data(63 downto 0) <= MTPAR_signals((63 + 1*64) downto 1*64);
      q(38).data(63 downto 0) <= MTPAR_signals((63 + 2*64) downto 2*64);
      q(39).data(63 downto 0) <= MTPAR_signals((63 + 3*64) downto 3*64);
      q(40).data(63 downto 0) <= MTPAR_signals((63 + 4*64) downto 4*64);
      q(41).data(63 downto 0) <= MTPAR_signals((63 + 5*64) downto 5*64);
      q(42).data(63 downto 0) <= MTPAR_signals((63 + 6*64) downto 6*64);
      q(43).data(63 downto 0) <= MTPAR_signals((63 + 7*64) downto 7*64);
      q(44).data(63 downto 0) <= MTPAR_signals((63 + 8*64) downto 8*64);
      q(45).data(63 downto 0) <= MTPAR_signals((63 + 9*64) downto 9*64);
      q(46).data(63 downto 0) <= MTPAR_signals((63 + 10*64) downto 10*64);
      q(47).data(63 downto 0) <= MTPAR_signals((63 + 11*64) downto 11*64);
      q(48).data(63 downto 0) <= MTPAR_signals((63 + 12*64) downto 12*64);
      q(49).data(63 downto 0) <= MTPAR_signals((63 + 13*64) downto 13*64);
      q(50).data(63 downto 0) <= MTPAR_signals((63 + 14*64) downto 14*64);
      q(51).data(63 downto 0) <= MTPAR_signals((63 + 15*64) downto 15*64);
      q(52).data(63 downto 0) <= MTPAR_signals((63 + 16*64) downto 16*64);
      q(53).data(63 downto 0) <= x"000" & MTPAR_signals((63 + 17*64 - 12) downto (17*64));
    
      q(54).data(63 downto 0) <= x"000000000000000" & "0" & bx_out;
    --end if;
  --end process;
  
end rtl;
