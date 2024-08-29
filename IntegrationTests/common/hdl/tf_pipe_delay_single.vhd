--!
--! Module that implementes a delay line to be used when
--! writing to a memory. The delay module delays the write enable,
--! the address, and the data for a fixed number of clocks.
--!
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

entity tf_pipe_delay_single is
  generic (
    PAGE_LENGTH : natural := PAGE_LENGTH;
    DELAY : natural := 1;
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
end tf_pipe_delay_single;


architecture behavior of tf_pipe_delay_single is

  type t_wea_pipe is array (0 to DELAY - 1) of std_logic;
  type t_addra_pipe is array (0 to DELAY - 1) of std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
  type t_dina_pipe is array (0 to DELAY - 1) of std_logic_vector( RAM_WIDTH - 1 downto 0 );

  signal wea_pipe: t_wea_pipe := (others => '0');
  signal addra_pipe: t_addra_pipe := (others => (others => '0') );
  signal dina_pipe: t_dina_pipe := (others => (others => '0') );
begin

  tf_pipe_delay_1 : entity work.tf_pipe_delay
    generic map (
      PAGE_LENGTH     => PAGE_LENGTH,
      DELAY           => 1,
      RAM_WIDTH       => RAM_WIDTH,
      NUM_PAGES       => NUM_PAGES,
      RAM_DEPTH       => RAM_DEPTH
    )
    port map (
      clk             => clk,
      wea             => wea,
      addra           => addra,
      dina            => dina,
      wea_out         => wea_pipe(0),
      addra_out       => addra_pipe(0),
      dina_out        => dina_pipe(0)
    );

  gen_pipes : for ii in 1 to DELAY - 1 generate
  begin
    tf_pipe_delay_n : entity work.tf_pipe_delay
      generic map (
        PAGE_LENGTH     => PAGE_LENGTH,
        DELAY           => 1,
        RAM_WIDTH       => RAM_WIDTH,
        NUM_PAGES       => NUM_PAGES,
        RAM_DEPTH       => RAM_DEPTH
      )
      port map (
        clk             => clk,
        wea             => wea_pipe(ii-1),
        addra           => addra_pipe(ii-1),
        dina            => dina_pipe(ii-1),
        wea_out         => wea_pipe(ii),
        addra_out       => addra_pipe(ii),
        dina_out        => dina_pipe(ii)
      );
  end generate gen_pipes;

  wea_out <= wea_pipe(DELAY - 1);
  addra_out <= addra_pipe(DELAY - 1);
  dina_out <= dina_pipe(DELAY - 1);

end behavior;
