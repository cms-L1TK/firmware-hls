-------------------------------------------------------------------------------
-- LUT (ROM) with configurable data width and depth
-- Rui Zou (rz393@cornell.edu)
-- Initialized via lut_file (.dat)
-------------------------------------------------------------------------------

library ieee ;
use ieee.std_logic_1164.all;
use ieee.numeric_Std.all;
use ieee.math_real.all;
library std;
use std.textio.all;

use work.tf_pkg.all;

entity tf_lut is
  generic (lut_file  : string := "lut.dat";
           lut_width : integer := 1;
           lut_depth : integer := 256;
           RAM_PERFORMANCE : string := "HIGH_PERFORMANCE" --! Select "HIGH_PERFORMANCE" (2 clk latency) or "LOW_LATENCY" (1 clk latency)
  );
  port (
    clk  : in std_logic;
    ce   : in std_logic;
    addr : in std_logic_vector(clogb2(lut_depth)-1 downto 0);
    dout : out std_logic_vector(lut_width-1 downto 0)
  );
end entity tf_lut;

architecture behavioral of tf_lut is
  type romType is array(0 to lut_depth-1) of std_logic_vector(lut_width-1 downto 0);

  impure function initRomFromFile return romType is
    file data_file : text open read_mode is lut_file;
    variable line_in : line;
    -- Determines number of 4*chars needed to be read from lut_file
    -- to correspond to specified LUT width.
    constant lut_width_4 : integer := 4*integer(ceil(real(lut_width)/4.0));
    variable line_data : std_logic_vector(lut_width_4-1 downto 0) := (others => '0'); 
    variable rom_data : romType;
  begin
    -- N.B. line_in.all is not supported by synthesis.

    -- Skip first line (just a bracket).
    readline(data_file, line_in);

    for I in romType'range loop
      readline(data_file, line_in);
      -- This avoid reading the final comma that appears on some lines.
      hread(line_in, line_data);
      -- Truncate data word to desired width.
      rom_data(I) := line_data(lut_width-1 downto 0);
    end loop;
    return rom_data;
  end function;

  signal rom : romType := initRomFromFile;
  signal dout_tmp : std_logic_vector(lut_width-1 downto 0) := (others => '0');
  attribute syn_rom_style : string;
  attribute syn_rom_style of rom : signal is "select_rom";
  attribute ROM_STYLE : string;
  attribute ROM_STYLE of rom : signal is "distributed";
  
begin
                                                  
  process (clk)
  begin
    if (rising_edge(clk)) then
      if (ce = '1') then 
        dout_tmp <= rom(to_integer(unsigned(addr)));
      end if;
    end if;
  end process;

-- The following code generates HIGH_PERFORMANCE (use output register) or LOW_LATENCY (no output register)
MODE : if (RAM_PERFORMANCE = "LOW_LATENCY") generate -- no_output_register; 1 clock cycle read latency at the cost of a longer clock-to-out timing
  dout <= dout_tmp;
else generate -- output_register; 2 clock cycle read latency with improve clock-to-out timing
  process(clk)
  begin
    if rising_edge(clk) then
      dout <= dout_tmp;
    end if;
  end process;
end generate MODE;


end architecture behavioral;      
