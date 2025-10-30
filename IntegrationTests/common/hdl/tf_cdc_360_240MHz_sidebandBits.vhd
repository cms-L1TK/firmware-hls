library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;
use work.hybrid_data_types.all;

library UNISIM;
use UNISIM.VComponents.all;


entity tf_cdc_360_240MHz_sideband_bits is

port(
  clk_240MHz_i : std_logic;
  clk_360MHz_i : std_logic;
  din_i  : in t_packet;
  dout_o  : out t_packet
  );

end tf_cdc_360_240MHz_sideband_bits;

architecture rtl of tf_cdc_360_240MHz_sideband_bits is

-- DEMUX signals
signal din: t_packet := (others => '0');
-- Signal for simulation purposes only
-- signal din_0: t_packet := (others => '0');
-- Signals for DEMUX
signal din_1: t_packet := (others => '0');
signal din_2: t_packet := (others => '0');
signal din_3: t_packet := (others => '0');
constant DEMUX_FACTOR_CDC_IN : integer:= 3;
signal cntr:  std_logic_vector( DEMUX_FACTOR_CDC_IN - 1  downto 0 ):= "001";
signal cntr_240MHz:  std_logic_vector( DEMUX_FACTOR_CDC_IN - 1  downto 0 ):= "001";

-- output
attribute dont_touch : string;

signal dout: t_packet := (others => '0');
signal dout_1: t_packet := (others => '0');
signal dout_2: t_packet := (others => '0');
signal dout_3: t_packet := (others => '0');
signal dout_1_reg0: t_packet := (others => '0');
signal dout_2_reg0: t_packet := (others => '0');
signal dout_3_reg0: t_packet := (others => '0');
signal dout_1_reg1: t_packet := (others => '0');
signal dout_2_reg1: t_packet := (others => '0');
signal dout_3_reg1: t_packet := (others => '0');
signal sticky_valid : std_logic := '0';
signal sticky_valid_240 : std_logic := '0';
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
attribute dont_touch of dout_3_reg1 : signal is "true";



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
  if din.valid = '1' or sticky_valid = '1' then
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
end if;
end process;

--Move data to 240 MHz domain

process ( clk_240MHz_i ) is
begin
if rising_edge( clk_240MHz_i ) then

  dout_1 <= din_1;
  dout_2 <= din_2;
  dout_3 <= din_3;

  dout_1_reg0 <= dout_1;
  dout_2_reg0 <= dout_2;
  dout_3_reg0 <= dout_3;

  dout_1_reg1 <= dout_1_reg0;
  dout_2_reg1 <= dout_2_reg0;
  dout_3_reg1 <= dout_3_reg0;


end if;
end process;

dout_valid_sticky : FDRE
generic map (
    INIT => '0'
)
port map (
    Q  => sticky_valid_240,
    C  => clk_240MHz_i,
    CE => dout_1.valid,
    D  => '1',
    R  => '0'
);


-- Counter
process ( clk_240MHz_i ) is
begin
if rising_edge( clk_240MHz_i ) then
  if dout_1.valid = '1' or sticky_valid = '1' then
    if cntr_240MHz(DEMUX_FACTOR_CDC_IN  - 1) = '1'  then
      cntr_240MHz <= "001";
    else
      cntr_240MHz <= cntr_240MHz(1 downto 0) & '0';
    end if;
  else
    cntr_240MHz <= "001";
  end if;
end if;
end process;


-- Demux in clk 240 MHz domain
process ( clk_240MHz_i ) is
begin
if rising_edge( clk_240MHz_i ) then
  case cntr_240MHz is
    when "001" =>
--      if dout_1.valid = '0' then
--        dout <= (others => '0');
--      else
        dout <= dout_1_reg1;
--      end if;
    when "010" =>
      dout <= dout_2_reg1;
    when "100" =>
      dout <= dout_3_reg1;
    when others =>
      dout <= (others => '0');
  end case;

end if;

end process;


end rtl;
