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
  generic (
    DELAY : natural := 0
  );
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
  type t_DONE_LATCH is array(0 to DELAY-1) of std_logic;
  signal DONE_LATCH : t_DONE_LATCH := (others => '0');
  type t_BX_LATCH is array(0 to DELAY-1) of std_logic_vector(2 downto 0);
  signal BX_LATCH : t_BX_LATCH;
begin

START <= DONE_LATCH(DELAY-1);
BX <= BX_LATCH(DELAY-1);

procLatch : process(CLK)
begin

  if rising_edge(CLK) then

    for ii in 1 to DELAY-1 loop
      DONE_LATCH(ii) <= DONE_LATCH(ii-1);
      BX_LATCH(ii) <= BX_LATCH(ii-1);
    end loop;

    if (RESET = '1') then
      DONE_LATCH(0) <= '0';
    else
      DONE_LATCH(0) <= DONE;
    end if;
    BX_LATCH(0) <= BX_OUT;

  end if;

end process procLatch;

end behavior;
