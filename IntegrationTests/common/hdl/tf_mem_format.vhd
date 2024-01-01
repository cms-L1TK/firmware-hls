--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub16dout5 is
  port(
    datain : in std_logic_vector(79 downto 0);
    dataout0 : out std_logic_vector(15 downto 0);
    dataout1 : out std_logic_vector(15 downto 0);
    dataout2 : out std_logic_vector(15 downto 0);
    dataout3 : out std_logic_vector(15 downto 0);
    dataout4 : out std_logic_vector(15 downto 0)
);
  end vmstub16dout5;

architecture rtl of vmstub16dout5 is

  begin

    process(datain)
    begin  
      dataout0 <= datain(15 downto 0);
      dataout1 <= datain(31 downto 16);
      dataout2 <= datain(47 downto 32);
      dataout3 <= datain(63 downto 48);
      dataout4 <= datain(79 downto 64);
    end process;
      
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub16mask is
  port(
    datain : in std_logic_vector(64*2-1 downto 0);
    dataout0 : out t_arr64_1b;
    dataout1 : out t_arr64_1b
);
  end vmstub16mask;

architecture rtl of vmstub16mask is

  begin

    process(datain)
      begin
        for i in 0 to 63 loop
          dataout0(i) <= datain(i);
          dataout1(i) <= datain(64+i);
        end loop;
    end process;
        
end rtl;
