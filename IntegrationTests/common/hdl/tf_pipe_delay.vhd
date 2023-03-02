--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Writing to and from files
use IEEE.STD_LOGIC_TEXTIO.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! Writing to and from files
use STD.TEXTIO.all;

--! User packages
use work.tf_pkg.all;

entity tf_pipe_delay is
  generic (
    DELAY : natural := 6;
    RAM_WIDTH: natural := 14;
    NUM_PAGES: natural := 2;
    RAM_DEPTH: natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;
    wea: in std_logic;
    addra: in std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
    dina: in std_logic_vector( RAM_WIDTH - 1 downto 0 );
    wea_out: out std_logic;
    addra_out: out std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
    dina_out: out std_logic_vector( RAM_WIDTH - 1 downto 0 )
  ); 
end tf_pipe_delay;


architecture behavior of tf_pipe_delay is
  --attribute KEEP_HIERARCHY : string;
  --attribute KEEP_HIERARCHY of tf_pipe_delay: entity is "TRUE";
  --attribute DONT_TOUCH : string;
  --attribute DONT_TOUCH of tf_pipe_delay: entity is "TRUE";

  type t_wea_pipe is array (0 to DELAY - 1) of std_logic;
  type t_addra_pipe is array (0 to DELAY - 1) of std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
  type t_dina_pipe is array (0 to DELAY - 1) of std_logic_vector( RAM_WIDTH - 1 downto 0 );

  signal wea_pipe: t_wea_pipe := (others => '0');
  signal addra_pipe: t_addra_pipe := (others => (others => '0') );
  signal dina_pipe: t_dina_pipe := (others => (others => '0') );
begin

wea_out <= wea_pipe(DELAY - 1);
addra_out <= addra_pipe(DELAY - 1);
dina_out <= dina_pipe(DELAY - 1);

process ( clk ) is
begin

if rising_edge( clk ) then

  for ii in 1 to DELAY - 1 loop
    wea_pipe(ii) <= wea_pipe(ii - 1);
    addra_pipe(ii) <= addra_pipe(ii - 1);
    dina_pipe(ii) <= dina_pipe(ii - 1);
  end loop;

  wea_pipe(0) <= wea;
  addra_pipe(0) <= addra;
  dina_pipe(0) <= dina;

end if;
end process;

end behavior;
