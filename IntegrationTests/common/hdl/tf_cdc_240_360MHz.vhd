library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

entity tf_cdc_240_360MHz is

port(
  clk_240MHz_i : std_logic;
  clk_360MHz_i : std_logic;
  din_i  : in lword;
  dout_o  : out lword
  );

end tf_cdc_240_360MHz;

architecture rtl of tf_cdc_240_360MHz is

constant number_of_channels : integer := 4 * N_REGION;
constant number_of_frames  : integer  := 162;
type t_state is ( reset, wordA, wordB );
signal state: t_state := reset;

signal valid: std_logic := '0';

signal sr: std_logic_vector( 0 to number_of_frames - 1 ) := ( others => '0' );

signal din: lword := LWORD_NULL;
signal dout: lword := LWORD_NULL;


begin

dout_o <= dout;

process ( clk_240MHz_i ) is
begin
if rising_edge( clk_240MHz_i ) then

  din <= din_i;

end if;
end process;


process ( clk_360MHz_i ) is
begin
if rising_edge( clk_360MHz_i ) then

  valid <= din_i.valid;
  sr <= '0' & sr( sr'low to sr'high - 1 );

  -- state
  state <= t_state'low;
  if state /= t_state'high then
    state <= t_state'val( t_state'pos( state ) + 1 );
  end if;

  -- cdc

  dout <= din;
  if state = reset then
    dout <= LWORD_NULL;
  else
    dout.strobe <= valid ;
  end if;
end if;
end process;

end rtl;
