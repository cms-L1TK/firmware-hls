-------------------------------------------------------------------------------
-- Counter to count clock cycles between two successive ap_done pulses
-- And compare the number of counts with latency_expected.
-- If not equal, error signal is raised for one clock cycle, error is asserted if in
-- simulation and not muted, error_sticky flag will stay raised until reset.
-- Serves as a sanity check to check latency of one or more HLS modules in
-- simulation or on chip.
-- Rui Zou
-------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_misc.all;


entity latency_monitor is

  generic (
    latency_expected    :integer := 108;
    max_value  : integer          := 255;
    mute       : boolean := false);
  port (
    reset      : in std_logic;
    clk        : in  std_logic;
    ap_done        : in std_logic;
    error         : out std_logic := '0';
    error_sticky        : out std_logic := '0'
    );

end entity latency_monitor;

architecture behavioral of latency_monitor is
  signal latency_count : integer range 0 to max_value:= 1;
  signal latency : integer range 0 to max_value:=latency_expected;
  signal count_start : std_logic := '0';
begin  -- architecture behavioral

  latency_counter : process (clk)
  begin  -- process counting clockcycles in between ap_done
    if rising_edge(clk) then  -- rising clock edge
      if (reset = '1')  then
        latency <= latency_expected;
        latency_count <= 1;
        error <= '0';
        error_sticky <= '0';
        count_start <= '0';
      else
        if (error = '1') then
          error_sticky <= '1';
        end if;
        if (ap_done = '1') then
          count_start <= '1';
          latency_count <= 1;
          if (count_start = '1') then
            latency <= latency_count;
            if not (latency = latency_expected) then
                error <= '1';
                assert mute report "Latency is not the expected value!" severity error;
            end if;
          end if;
        else
          error <= '0';
          if (count_start = '1') then
            latency_count <= latency_count +1;
          end if;
        end if; -- if (ap_done = '1')
      end if; -- if (reset = '1')
    end if; -- if rising_edge
  end process latency_counter;

end architecture behavioral;

