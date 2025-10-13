library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

use work.emp_data_types.all;
use work.emp_project_decl.all;
use work.emp_device_decl.all;

entity tf_cdc_240_360MHz_wr is

port(
  clk_240MHz_i : std_logic;
  clk_360MHz_i : std_logic;
  din_i  : in ldata(4 * N_REGION - 1 downto 0);
  dout_o  : out ldata(4 * N_REGION - 1 downto 0)
  );

end tf_cdc_240_360MHz_wr;

architecture rtl of tf_cdc_240_360MHz_wr is

constant number_of_channels : integer := 4 * N_REGION;

begin

GEN_INPUT_CHANNELS : for i in 0 to number_of_channels - 1 generate
 tf_cdc_240_360MHz_1 : entity  work.tf_cdc_240_360MHz
    port map (
      clk_240MHz_i => clk_240MHz_i,
      clk_360MHz_i => clk_360MHz_i,
      din_i  =>  din_i(i),
      dout_o  =>  dout_o(i)
      );
end generate;

end rtl;
