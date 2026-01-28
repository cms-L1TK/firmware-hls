library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

library UNISIM;
use UNISIM.VComponents.all;


entity tf_cdc_360_240MHz is

port(
  clk_240MHz_i : std_logic;
  clk_360MHz_i : std_logic;
  din_i  : in lword;
  dout_o  : out lword
  );

end tf_cdc_360_240MHz;

architecture rtl of tf_cdc_360_240MHz is

-- DEMUX signals
signal din: lword := LWORD_NULL;
-- Signal for simulation purposes only
-- signal din_0: lword := LWORD_NULL;
-- Signals for DEMUX
signal din_1: lword := LWORD_NULL;
signal din_2: lword := LWORD_NULL;
signal din_3: lword := LWORD_NULL;
constant DEMUX_FACTOR_CDC_IN : integer:= 3;
signal cntr:  std_logic_vector( DEMUX_FACTOR_CDC_IN - 1  downto 0 ):= "001";

signal toggle : std_logic := '0';
signal sticky_valid : std_logic := '0';
signal valid_dly1_sticky  : std_logic := '0';


-- output
attribute dont_touch : string;

signal dout: lword := LWORD_NULL;
signal dout_1: lword := LWORD_NULL;
signal dout_2: lword := LWORD_NULL;
signal dout_3: lword := LWORD_NULL;
signal dout_1_reg0: lword := LWORD_NULL;
signal dout_2_reg0: lword := LWORD_NULL;
signal dout_1_reg1: lword := LWORD_NULL;
signal dout_2_reg1: lword := LWORD_NULL;

attribute dont_touch of din_1      : signal is "true";
attribute dont_touch of din_2      : signal is "true";
attribute dont_touch of din_3      : signal is "true";

attribute dont_touch of dout_1      : signal is "true";
attribute dont_touch of dout_2      : signal is "true";
attribute dont_touch of dout_3      : signal is "true";
attribute dont_touch of dout_1_reg0 : signal is "true";
attribute dont_touch of dout_2_reg0 : signal is "true";
attribute dont_touch of dout_1_reg1 : signal is "true";
attribute dont_touch of dout_2_reg1 : signal is "true";



begin

dout_o <= dout;

din_valid_sticky : FDRE
generic map (
    INIT => '0'
)
port map (
    Q  => sticky_valid,
    C  => clk_360MHz_i,
    CE => din.valid,
    D  => '1',
    R  => '0'
);



process ( clk_360MHz_i ) is
begin
if rising_edge( clk_360MHz_i ) then
  if din.valid = '1' or sticky_valid = '1'  then
    if cntr(DEMUX_FACTOR_CDC_IN  - 1) = '1'  then
      cntr <= "001";
    else
      cntr <= cntr(1 downto 0) & '0';
    end if;
  else
    cntr <= "001";
  end if;
end if;
end process;

-- Demux in clk 360 MHz domain
process ( clk_360MHz_i ) is
begin
if rising_edge( clk_360MHz_i ) then
--  din_0 <= din_i;
  din  <= din_i;
  if din.valid = '1' or sticky_valid = '1' then
    case cntr is
      when "001" =>
        din_1 <= din;
      when "010" =>
        din_2 <= din;
      when "100" =>
        din_3 <= din;
      when others =>
        null;
    end case;
else
   din_1 <= LWORD_NULL;
   din_2 <= LWORD_NULL;
   din_3 <= LWORD_NULL;
  end if;
end if;
end process;

--Move data to 240 MHz domain

process ( clk_240MHz_i ) is
begin
if rising_edge( clk_240MHz_i ) then

  dout_1 <= din_1;
  dout_2 <= din_2;

  dout_1_reg0 <= dout_1;
  dout_2_reg0 <= dout_2;

  dout_1_reg1 <= dout_1_reg0;
  dout_2_reg1 <= dout_2_reg0;


end if;
end process;

valid_dly_sticky : FDRE
generic map (
    INIT => '0'
)
port map (
    Q  => valid_dly1_sticky,
    C  => clk_240MHz_i,
    CE => dout_1_reg1.valid,
    D  => '1',
    R  => '0'
);

-- Demux in clk 240 MHz domain
process ( clk_240MHz_i ) is
begin
if rising_edge( clk_240MHz_i ) then
  if dout_1_reg1.valid = '1' or valid_dly1_sticky = '1' then
    if toggle = '0' then
      dout <= dout_1_reg1;
    else
      dout <= dout_2_reg1;
    end if;
    toggle <= not toggle; -- toggle only when valid
  else
   toggle <='0';
   dout <= LWORD_NULL;
  end if;
end if;
end process;

end rtl;
