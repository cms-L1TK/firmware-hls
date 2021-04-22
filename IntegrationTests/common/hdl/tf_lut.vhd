-------------------------------------------------------------------------------
-- LUT (ROM) with configurable data width and depth
-- Rui Zou (rz393@cornell.edu)
-- Initialized via lut_file (.dat)
-------------------------------------------------------------------------------

library ieee ;
use ieee.std_logic_1164.all;
use ieee.numeric_Std.all;
library std ;
use std.textio.all;

entity tf_lut is
  generic (lut_file : string := "lut.dat";
           lut_width   : integer := 1;
           lut_depth    : integer := 256);
  port (
    clk : in std_logic;
    ce : in std_logic;
    addr : in std_logic_vector(clogb2(lut_depth)-1 downto 0);
    dout : out std_logic_vector(lut_width-1 downto 0)
    );
end entity tf_lut;

architecture behavioral of tf_lut is
  type romType is array(0 to lut_depth-1) of std_logic_vector(lut_width-1 downto 0);
  impure function initRomFromFile return romType is
    file data_file : text open read_mode is lut_file;
    variable data_fileLine : line;
    variable ROM : romType;
  begin
    for I in romType'range loop
      readline(data_file, data_fileLine);
      hread(data_fileLine, ROM(I));
    end loop;
    return ROM;
  end initRomFromFile;
  signal rom : romType := initRomFromFile;

  attribute syn_rom_style : string;
  attribute syn_rom_style of mem : signal is "select_rom";
  attribute ROM_STYLE : string;
  attribute ROM_STYLE of mem : signal is "distributed";
  
begin
                                                  
  process (clk)
  begin
    if (rising_edge(clk)) then
      if (ce = '1') then 
        dout <= rom(to_integer(unsigned(addr)));
      end if;
    end if;
  end process;
end architecture behavioral;      
