library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

use work.memUtil_pkg.all;
use work.memUtil_aux_pkg_f1.all;
use work.hybrid_data_types.all;

entity secproc1tolink is
  port(
    clk                    : in std_logic;
    rst                    : in std_logic;
    TP_bx_out              : in std_logic_vector(2 downto 0);
    AS_37_stream_V_dout    : in t_arr_AS_37_DATA;
    MPAR_76_stream_V_dout  : in t_arr_MPAR_76_DATA;
    node_packet            : in t_packet;
    q                      : out ldata(4 * N_REGION - 1 downto 0)
    );

end secproc1tolink;

architecture rtl of secproc1tolink is
  
  constant dataword_length : integer := 64;
  constant n_interfpga_links : integer := 64;
  signal AS_counter : integer := 0;
  signal MPAR_counter : integer := 0;
  signal AS_signals : std_logic_vector(dataword_length * 28 - 1 downto 0);
  signal MPAR_signals : std_logic_vector(dataword_length * 18 - 1 downto 0);
  signal sr : t_packets( PAYLOAD_LATENCY - 1 downto 0 ) := ( others => ( others => '0' ) );

begin

  AS_signals(1775 downto 0) <= AS_37_stream_V_dout(D5PHIDn1) &
                               AS_37_stream_V_dout(D5PHICn1) &
                               AS_37_stream_V_dout(D5PHIBn1) &
                               AS_37_stream_V_dout(D5PHIAn1) &
                               AS_37_stream_V_dout(D4PHIDn1) &
                               AS_37_stream_V_dout(D4PHICn1) &
                               AS_37_stream_V_dout(D4PHIBn1) &
                               AS_37_stream_V_dout(D4PHIAn1) &
                               AS_37_stream_V_dout(D3PHIDn1) &
                               AS_37_stream_V_dout(D3PHICn1) &
                               AS_37_stream_V_dout(D3PHIBn1) &
                               AS_37_stream_V_dout(D3PHIAn1) &
                               AS_37_stream_V_dout(D2PHIDn1) &
                               AS_37_stream_V_dout(D2PHICn1) &
                               AS_37_stream_V_dout(D2PHIBn1) &
                               AS_37_stream_V_dout(D2PHIAn1) &
                               AS_37_stream_V_dout(D1PHIDn1) &
                               AS_37_stream_V_dout(D1PHICn1) &
                               AS_37_stream_V_dout(D1PHIBn1) &
                               AS_37_stream_V_dout(D1PHIAn1) &
                               AS_37_stream_V_dout(L6PHIDn1) &
                               AS_37_stream_V_dout(L6PHICn1) &
                               AS_37_stream_V_dout(L6PHIBn1) &
                               AS_37_stream_V_dout(L6PHIAn1) &
                               AS_37_stream_V_dout(L5PHIDn1) &
                               AS_37_stream_V_dout(L5PHICn1) &
                               AS_37_stream_V_dout(L5PHIBn1) &
                               AS_37_stream_V_dout(L5PHIAn1) &
                               AS_37_stream_V_dout(L4PHIDn1) &
                               AS_37_stream_V_dout(L4PHICn1) &
                               AS_37_stream_V_dout(L4PHIBn1) &
                               AS_37_stream_V_dout(L4PHIAn1) &
                               AS_37_stream_V_dout(L3PHIDn1) &
                               AS_37_stream_V_dout(L3PHICn1) &
                               AS_37_stream_V_dout(L3PHIBn1) &
                               AS_37_stream_V_dout(L3PHIAn1) &
                               AS_37_stream_V_dout(L2PHIDn1) &
                               AS_37_stream_V_dout(L2PHICn1) &
                               AS_37_stream_V_dout(L2PHIBn1) &
                               AS_37_stream_V_dout(L2PHIAn1) &
                               AS_37_stream_V_dout(L1PHIHn1) &
                               AS_37_stream_V_dout(L1PHIGn1) &
                               AS_37_stream_V_dout(L1PHIFn1) &
                               AS_37_stream_V_dout(L1PHIEn1) &
                               AS_37_stream_V_dout(L1PHIDn1) &
                               AS_37_stream_V_dout(L1PHICn1) &
                               AS_37_stream_V_dout(L1PHIBn1) &
                               AS_37_stream_V_dout(L1PHIAn1);

  MPAR_signals(1139 downto 0) <= MPAR_76_stream_V_dout(L2D1ABCD) &
                                 MPAR_76_stream_V_dout(L1D1EFGH) &
                                 MPAR_76_stream_V_dout(L1D1ABCD) &
                                 MPAR_76_stream_V_dout(D3D4ABCD) &
                                 MPAR_76_stream_V_dout(D1D2ABCD) &
                                 MPAR_76_stream_V_dout(L5L6ABCD) &
                                 MPAR_76_stream_V_dout(L3L4CD) &
                                 MPAR_76_stream_V_dout(L3L4AB) &
                                 MPAR_76_stream_V_dout(L2L3ABCD) &
                                 MPAR_76_stream_V_dout(L1L2JKL) &
                                 MPAR_76_stream_V_dout(L1L2HI) &
                                 MPAR_76_stream_V_dout(L1L2G) &
                                 MPAR_76_stream_V_dout(L1L2F) &
                                 MPAR_76_stream_V_dout(L1L2DE) &
                                 MPAR_76_stream_V_dout(L1L2ABC);

  process( clk ) is
  begin
  if rising_edge( clk ) then
    sr <= sr( sr'high - 1 downto 0 ) & node_packet;
  end if;
  end process;
  
  q(4).data(63 downto 0) <= AS_signals(63 + 0*64 downto 0 + 0*64);
  q(5).data(63 downto 0) <= AS_signals(63 + 1*64 downto 0 + 1*64);
  q(6).data(63 downto 0) <= AS_signals(63 + 2*64 downto 0 + 2*64);
  q(7).data(63 downto 0) <= AS_signals(63 + 3*64 downto 0 + 3*64);
  q(8).data(63 downto 0) <= AS_signals(63 + 4*64 downto 0 + 4*64);
  q(9).data(63 downto 0) <= AS_signals(63 + 5*64 downto 0 + 5*64);
  q(10).data(63 downto 0) <= AS_signals(63 + 6*64 downto 0 + 6*64);
  q(11).data(63 downto 0) <= AS_signals(63 + 7*64 downto 0 + 7*64);
  q(12).data(63 downto 0) <= AS_signals(63 + 8*64 downto 0 + 8*64);
  q(13).data(63 downto 0) <= AS_signals(63 + 9*64 downto 0 + 9*64);
  q(14).data(63 downto 0) <= AS_signals(63 + 10*64 downto 0 + 10*64);
  q(15).data(63 downto 0) <= AS_signals(63 + 11*64 downto 0 + 11*64);
  
  q(20).data(63 downto 0) <= AS_signals(63 + 12*64 downto 0 + 12*64);
  q(21).data(63 downto 0) <= AS_signals(63 + 13*64 downto 0 + 13*64);
  q(22).data(63 downto 0) <= AS_signals(63 + 14*64 downto 0 + 14*64);
  q(23).data(63 downto 0) <= AS_signals(63 + 15*64 downto 0 + 15*64);
  q(24).data(63 downto 0) <= AS_signals(63 + 16*64 downto 0 + 16*64);
  q(25).data(63 downto 0) <= AS_signals(63 + 17*64 downto 0 + 17*64);
  q(26).data(63 downto 0) <= AS_signals(63 + 18*64 downto 0 + 18*64);
  q(27).data(63 downto 0) <= AS_signals(63 + 19*64 downto 0 + 19*64);
  q(28).data(63 downto 0) <= AS_signals(63 + 20*64 downto 0 + 20*64);
  q(29).data(63 downto 0) <= AS_signals(63 + 21*64 downto 0 + 21*64);
  q(30).data(63 downto 0) <= AS_signals(63 + 22*64 downto 0 + 22*64);
  q(31).data(63 downto 0) <= AS_signals(63 + 23*64 downto 0 + 23*64);
  q(32).data(63 downto 0) <= AS_signals(63 + 24*64 downto 0 + 24*64);
  q(33).data(63 downto 0) <= AS_signals(63 + 25*64 downto 0 + 25*64);
  q(34).data(63 downto 0) <= AS_signals(63 + 26*64 downto 0 + 26*64);
  q(35).data(63 - 16 downto 0) <= AS_signals(63 + 27*64 - 16 downto 0 + 27*64);
  q(35).data(63 downto 63-15) <= (others => '0');

  --although we are just sending this to FPGA2, FPGA2 uses the control signals
  --to determine its outputs control signals, so we should synchronize these
  control_signals1 : for i in 4 to 15 generate
    q(i).start_of_orbit <= sr(sr'high).start_of_orbit;
    q(i).start <= sr(sr'high).start;
    q(i).last <= sr(sr'high).last;
    q(i).valid <= sr(sr'high).valid;
  end generate;
  control_signals2 : for i in 20 to 54 generate
    q(i).start_of_orbit <= sr(sr'high).start_of_orbit;
    q(i).start <= sr(sr'high).start;
    q(i).last <= sr(sr'high).last;
    q(i).valid <= sr(sr'high).valid;
  end generate;

  --15 76bit signals can be accomodated by 18 64bit signals, this will leave
  --12 empty bits in the last data word
  q(36).data(63 downto 0) <= MPAR_signals(63 + 0*64 downto 0 + 0*64);
  q(37).data(63 downto 0) <= MPAR_signals(63 + 1*64 downto 0 + 1*64);
  q(38).data(63 downto 0) <= MPAR_signals(63 + 2*64 downto 0 + 2*64);
  q(39).data(63 downto 0) <= MPAR_signals(63 + 3*64 downto 0 + 3*64);
  q(40).data(63 downto 0) <= MPAR_signals(63 + 4*64 downto 0 + 4*64);
  q(41).data(63 downto 0) <= MPAR_signals(63 + 5*64 downto 0 + 5*64);
  q(42).data(63 downto 0) <= MPAR_signals(63 + 6*64 downto 0 + 6*64);
  q(43).data(63 downto 0) <= MPAR_signals(63 + 7*64 downto 0 + 7*64);
  q(44).data(63 downto 0) <= MPAR_signals(63 + 8*64 downto 0 + 8*64);
  q(45).data(63 downto 0) <= MPAR_signals(63 + 9*64 downto 0 + 9*64);
  q(46).data(63 downto 0) <= MPAR_signals(63 + 10*64 downto 0 + 10*64);
  q(47).data(63 downto 0) <= MPAR_signals(63 + 11*64 downto 0 + 11*64);
  q(48).data(63 downto 0) <= MPAR_signals(63 + 12*64 downto 0 + 12*64);
  q(49).data(63 downto 0) <= MPAR_signals(63 + 13*64 downto 0 + 13*64);
  q(50).data(63 downto 0) <= MPAR_signals(63 + 14*64 downto 0 + 14*64);
  q(51).data(63 downto 0) <= MPAR_signals(63 + 15*64 downto 0 + 15*64);
  q(52).data(63 downto 0) <= MPAR_signals(63 + 16*64 downto 0 + 16*64);
  q(53).data(63 - 12 downto 0) <= MPAR_signals(63 + 17*64 - 12 downto 0 + 17*64);
  q(53).data(63 downto 63-11) <= (others => '0');
  
  q(54).data(2 downto 0) <= TP_bx_out;
  q(54).data(63 downto 3) <= (others => '0');
    
end rtl;
