--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Writing to and from files
use IEEE.STD_LOGIC_TEXTIO.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! Writing to and from files
use STD.TEXTIO.all;

--! User packages
use work.tf_pkg.all;

-- ==================================================================
--  Create START signal of a module in the L1 tracking chain
--  by latching DONE signal of the previous module in the chain.
-- ==================================================================

entity CreateStartSignal is
  port (
    CLK   : in  std_logic;
    RESET : in  std_logic;
    DONE  : in  std_logic; --! Done signal of last algo module in chain
    BX_OUT  : in  std_logic_vector(2 downto 0);
    START : out std_logic;  --! Start signal of next algo module in chain
    BX : out std_logic_vector(2 downto 0)
  ); 
end CreateStartSignal;


architecture behavior of CreateStartSignal is
  signal DONE_LATCH : std_logic := '0';
  signal BX_LATCH : std_logic_vector(2 downto 0);
begin

START <= DONE_LATCH; --! Latch goes high 1 clk after "done", so need OR of both.
BX <= BX_LATCH;

procLatch : process(CLK)
begin

  if rising_edge(CLK) then

    if DONE = '1' then
      DONE_LATCH <= DONE;
      BX_LATCH <= BX_OUT;
    end if;

    if (RESET = '1') then
      DONE_LATCH <= '0';
    end if;

  end if;

end process procLatch;

end behavior;
