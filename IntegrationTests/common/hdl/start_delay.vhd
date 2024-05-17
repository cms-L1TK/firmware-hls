--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity start_delay is
  port(
    clk       : in std_logic;                                      --! Clock
    start_in  : in std_logic;
    bx_in : in std_logic_vector(2 downto 0);
    start_out : out std_logic;
    bx_out : out std_logic_vector(2 downto 0)
);
end start_delay;

architecture rtl of start_delay is

  signal bx  : std_logic_vector(2 downto 0) := (others =>'0');        
  signal start  : std_logic := '0';        
    
  begin

    process(clk)
    begin  
      if rising_edge(clk) then
        bx_out <= bx;
        start_out <= start;
        bx <= bx_in;
        start <= start_in;
      end if;
    end process;
      
end rtl;

