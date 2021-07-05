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

use work.tf_pkg.all;

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
    variable line_in : line;
    variable line_data : std_logic_vector(127 downto 0) := (others => '0'); -- A wide vector compared to any LUT width.
    variable hasComma : boolean := false;
    variable nCharSkip : natural := 0;
    variable rom_data : romType;
    variable addr : natural := 0;
  begin
    while not endfile(data_file) loop
      readline(data_file, line_in);
      -- Skip lines without hex numbers
      if (line_in'length >= 1) then
        -- Skip brackets at start & end of file.
        if (line_in.all(1 to 1) /= "{" and line_in.all(1 to 1) /= "}") then
          -- Check if line ends in comma, in which case drop comma.
          hasComma := (line_in.all(line_in'length to line_in'length) = ",");
          if hasComma then
            nCharSkip := 1;
          else
            nCharSkip := 0;
          end if;
          hread(line_in, line_data((line_in'length-nCharSkip)*4-1 downto 0));
          -- Truncate data word to desired width.
          rom_data(addr) := line_data(lut_width-1 downto 0);
          addr := addr + 1;
        end if;
      end if;
    end loop;
    return rom_data;
  end function;

  signal rom : romType := initRomFromFile;
  attribute syn_rom_style : string;
  attribute syn_rom_style of rom : signal is "select_rom";
  attribute ROM_STYLE : string;
  attribute ROM_STYLE of rom : signal is "distributed";
  
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
