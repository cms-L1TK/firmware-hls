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
    q(i).valid <= '1' when word_index <= x"9B" else '0';
    -- Start & last are only high for first & last clock cycle of packet
    q(i).start <= '1' when word_index = x"00" else '0';
    q(i).last <= '1' when word_index = x"9B" else '0';

    -- Start of orbit is high in the first clock cycle of the first packet in orbit - though in final system this should instead
    -- be high in the first clock cycle of the packet containing the data from BX0 (or BXn in time slice n of a TMUX system)
    q(i).start_of_orbit <= '1' when ((word_index = x"00") and (packet_index = "000000000")) else '0';

    -- Data word: Bits 63 to 32 = channel index; bits 31 to 16 = packet index; bits 15 to 0 = word index.
    q(i).data(63 downto 32) <= std_logic_vector(to_unsigned(i, 32));
    q(i).data(31 downto 16) <= "0000000" & packet_index;
    q(i).data(15 downto 0) <= x"00" & word_index;

  end generate gen;

end rtl;
