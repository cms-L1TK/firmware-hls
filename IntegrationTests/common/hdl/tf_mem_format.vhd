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


entity vmstub16dout4 is
  port(
    datain : in std_logic_vector(63 downto 0);
    dataout0 : out std_logic_vector(15 downto 0);
    dataout1 : out std_logic_vector(15 downto 0);
    dataout2 : out std_logic_vector(15 downto 0);
    dataout3 : out std_logic_vector(15 downto 0)
);
  end vmstub16dout4;

architecture rtl of vmstub16dout4 is

  begin

    process(datain)
    begin  
      dataout0 <= datain(15 downto 0);
      dataout1 <= datain(31 downto 16);
      dataout2 <= datain(47 downto 32);
      dataout3 <= datain(63 downto 48);
    end process;
      
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub17dout5 is
  port(
    datain : in std_logic_vector(84 downto 0);
    dataout0 : out std_logic_vector(16 downto 0);
    dataout1 : out std_logic_vector(16 downto 0);
    dataout2 : out std_logic_vector(16 downto 0);
    dataout3 : out std_logic_vector(16 downto 0);
    dataout4 : out std_logic_vector(16 downto 0)
);
  end vmstub17dout5;

architecture rtl of vmstub17dout5 is

  begin

    process(datain)
    begin  
      dataout0 <= datain(16 downto 0);
      dataout1 <= datain(33 downto 17);
      dataout2 <= datain(50 downto 34);
      dataout3 <= datain(67 downto 51);
      dataout4 <= datain(84 downto 68);
    end process;
      
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub17dout4 is
  port(
    datain : in std_logic_vector(67 downto 0);
    dataout0 : out std_logic_vector(16 downto 0);
    dataout1 : out std_logic_vector(16 downto 0);
    dataout2 : out std_logic_vector(16 downto 0);
    dataout3 : out std_logic_vector(16 downto 0)
    );
  end vmstub17dout4;

architecture rtl of vmstub17dout4 is

  begin

    process(datain)
    begin  
      dataout0 <= datain(16 downto 0);
      dataout1 <= datain(33 downto 17);
      dataout2 <= datain(50 downto 34);
      dataout3 <= datain(67 downto 51);
    end process;
      
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub17dout3 is
  port(
    datain : in std_logic_vector(50 downto 0);
    dataout0 : out std_logic_vector(16 downto 0);
    dataout1 : out std_logic_vector(16 downto 0);
    dataout2 : out std_logic_vector(16 downto 0)
    );
  end vmstub17dout3;

architecture rtl of vmstub17dout3 is

  begin

    process(datain)
    begin  
      dataout0 <= datain(16 downto 0);
      dataout1 <= datain(33 downto 17);
      dataout2 <= datain(50 downto 34);
    end process;
      
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub2mask is
  port(
    datain : in std_logic_vector(64*2-1 downto 0);
    dataout0 : out t_arr64_1b;
    dataout1 : out t_arr64_1b
);

end vmstub2mask;

architecture rtl of vmstub2mask is

  begin

    process(datain)
      begin
        for i in 0 to 63 loop
          dataout0(i) <= datain(i);
          dataout1(i) <= datain(64+i);
        end loop;
    end process;
        
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub4mask is
  port(
    datain : in std_logic_vector(64*4-1 downto 0);
    dataout0 : out t_arr64_1b;
    dataout1 : out t_arr64_1b;
    dataout2 : out t_arr64_1b;
    dataout3 : out t_arr64_1b
);
  end vmstub4mask;

architecture rtl of vmstub4mask is

  begin

    process(datain)
      begin
        for i in 0 to 63 loop
          dataout0(i) <= datain(i);
          dataout1(i) <= datain(64+i);
          dataout2(i) <= datain(64*2+i);
          dataout3(i) <= datain(64*3+i);
        end loop;
    end process;
        
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub2maskdisk is
  port(
    datain : in std_logic_vector(128*2-1 downto 0);
    dataout0 : out t_arr128_1b;
    dataout1 : out t_arr128_1b
);
  end vmstub2maskdisk;

architecture rtl of vmstub2maskdisk is

  begin

    process(datain)
      begin
        for i in 0 to 127 loop
          dataout0(i) <= datain(i);
          dataout1(i) <= datain(128+i);
        end loop;
    end process;
        
end rtl;

--! Standard libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;


entity vmstub4maskdisk is
  port(
    datain : in std_logic_vector(128*4-1 downto 0);
    dataout0 : out t_arr128_1b;
    dataout1 : out t_arr128_1b;
    dataout2 : out t_arr128_1b;
    dataout3 : out t_arr128_1b
);
  end vmstub4maskdisk;

architecture rtl of vmstub4maskdisk is

  begin

    process(datain)
      begin
        for i in 0 to 127 loop
          dataout0(i) <= datain(i);
          dataout1(i) <= datain(128+i);
          dataout2(i) <= datain(128*2+i);
          dataout3(i) <= datain(128*3+i);
        end loop;
    end process;
        
end rtl;
