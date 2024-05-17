--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity start_delay1 is
  port(
    clk       : in std_logic;                                      --! Clock
    start_in  : in std_logic;
    start_out : out std_logic
);
end start_delay1;

architecture rtl of start_delay1 is

  signal start  : std_logic := '0';        
    
  begin

    process(clk)
    begin  
      start_out <= start;
      start <= start_in;
    end process;
      
end rtl;

