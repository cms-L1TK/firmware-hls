--!
--! Module that implementes a delay line to be used when
--! writing to a memory. The delay module delays the write enable,
--! the address, and the data for a fixed number of clocks.
--!
--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! User packages
use work.tf_pkg.all;

entity tf_pipeline is
  generic (
    DELAY : natural := 2;
    USE_SRL : string := "no";
    RAM_WIDTH : natural := 14;
    NUM_PAGES : natural := 2;
    PAGE_LENGTH : natural := PAGE_LENGTH;
    RAM_DEPTH : natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;
    reset : in std_logic;

    -- Memory interface
    wea : in std_logic := '0';
    addra : in std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 ) := (others => '0');
    dina : in std_logic_vector( RAM_WIDTH - 1 downto 0 ) := (others => '0');
    wea_out : out std_logic;
    addra_out : out std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
    dina_out : out std_logic_vector( RAM_WIDTH - 1 downto 0 );

    -- Start/BX signals
    done : in std_logic := '0';
    bx_out : in std_logic_vector(2 downto 0) := (others => '0');
    start : out std_logic;
    bx : out std_logic_vector(2 downto 0)
  );
end tf_pipeline;

architecture behavior of tf_pipeline is

  attribute dont_touch : string;
  attribute dont_touch of behavior : architecture is "yes";

  type t_wea_pipe is array (0 to DELAY - 1) of std_logic;
  type t_addra_pipe is array (0 to DELAY - 1) of std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
  type t_dina_pipe is array (0 to DELAY - 1) of std_logic_vector( RAM_WIDTH - 1 downto 0 );
  type t_start_pipe is array(0 to DELAY - 1) of std_logic;
  type t_bx_pipe is array(0 to DELAY - 1) of std_logic_vector(2 downto 0);

  signal wea_pipe : t_wea_pipe := (others => '0');
  signal addra_pipe : t_addra_pipe := (others => (others => '0') );
  signal dina_pipe : t_dina_pipe := (others => (others => '0') );
  signal start_pipe : t_start_pipe := (others => '0');
  signal bx_pipe : t_bx_pipe := (others => (others => '0') );

  attribute shreg_extract : string;
  attribute shreg_extract of wea_pipe : signal is USE_SRL;
  attribute shreg_extract of addra_pipe : signal is USE_SRL;
  attribute shreg_extract of dina_pipe : signal is USE_SRL;
  attribute shreg_extract of start_pipe : signal is USE_SRL;
  attribute shreg_extract of bx_pipe : signal is USE_SRL;

begin

  wea_out <= wea_pipe(DELAY - 1);
  addra_out <= addra_pipe(DELAY - 1);
  dina_out <= dina_pipe(DELAY - 1);
  start <= start_pipe(DELAY - 1);
  bx <= bx_pipe(DELAY - 1);

  PIPELINE : process (clk) is
  begin

    if rising_edge(clk) then

      for ii in 1 to DELAY - 1 loop
        wea_pipe(ii) <= wea_pipe(ii - 1);
        addra_pipe(ii) <= addra_pipe(ii - 1);
        dina_pipe(ii) <= dina_pipe(ii - 1);
        start_pipe(ii) <= start_pipe(ii - 1);
        bx_pipe(ii) <= bx_pipe(ii - 1);
      end loop;

      wea_pipe(0) <= wea;
      addra_pipe(0) <= addra;
      dina_pipe(0) <= dina;
      if reset = '1' then
        start_pipe(0) <= '0';
      elsif done = '1' then
        start_pipe(0) <= done;
      end if;
      bx_pipe(0) <= bx_out;

    end if;

  end process;

end behavior;

--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! User packages
use work.tf_pkg.all;

entity tf_auto_pipeline is
  generic (
    RAM_WIDTH : natural := 14;
    NUM_PAGES : natural := 2;
    PAGE_LENGTH : natural := PAGE_LENGTH;
    RAM_DEPTH : natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;
    reset : in std_logic;

    -- Memory interface
    wea : in std_logic := '0';
    addra : in std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 ) := (others => '0');
    dina : in std_logic_vector( RAM_WIDTH - 1 downto 0 ) := (others => '0');
    wea_out : out std_logic;
    addra_out : out std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
    dina_out : out std_logic_vector( RAM_WIDTH - 1 downto 0 );

    -- Start/BX signals
    done : in std_logic := '0';
    bx_out : in std_logic_vector(2 downto 0) := (others => '0');
    start : out std_logic;
    bx : out std_logic_vector(2 downto 0)
  );
end tf_auto_pipeline;

architecture behavior of tf_auto_pipeline is

  attribute dont_touch : string;
  attribute dont_touch of behavior : architecture is "yes";

  signal wea_reg : std_logic := '0';
  signal addra_reg : std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 ) := (others => '0');
  signal dina_reg : std_logic_vector( RAM_WIDTH - 1 downto 0 ) := (others => '0');
  signal start_reg : std_logic := '0';
  signal bx_reg : std_logic_vector(2 downto 0) := (others => '0');

begin

  wea_out <= wea_reg;
  addra_out <= addra_reg;
  dina_out <= dina_reg;
  start <= start_reg;
  bx <= bx_reg;

  AUTO_PIPELINE : process (clk) is
  begin

    if rising_edge(clk) then

      wea_reg <= wea;
      addra_reg <= addra;
      dina_reg <= dina;
      if reset = '1' then
        start_reg <= '0';
      elsif done = '1' then
        start_reg <= done;
      end if;
      bx_reg <= bx_out;

    end if;

  end process;

end behavior;

--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! User packages
use work.tf_pkg.all;

entity tf_pipeline_slr_xing is
  generic (
    AUTO_PIPELINE : boolean := false;
    NUM_SLR : natural := 2;
    DELAY : t_arr_1d_nat(0 to NUM_SLR - 1) := (others => 2);
    USE_SRL : t_arr_1d_bol(0 to NUM_SLR - 1) := (others => false);
    RAM_WIDTH : natural := 14;
    NUM_PAGES : natural := 2;
    PAGE_LENGTH : natural := PAGE_LENGTH;
    RAM_DEPTH : natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;
    reset : in std_logic;

    -- Memory interface
    wea : in std_logic := '0';
    addra : in std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 ) := (others => '0');
    dina : in std_logic_vector( RAM_WIDTH - 1 downto 0 ) := (others => '0');
    wea_out : out std_logic;
    addra_out : out std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
    dina_out : out std_logic_vector( RAM_WIDTH - 1 downto 0 );

    -- Start/BX signals
    done : in std_logic := '0';
    bx_out : in std_logic_vector(2 downto 0) := (others => '0');
    start : out std_logic;
    bx : out std_logic_vector(2 downto 0)
  );
end tf_pipeline_slr_xing;

architecture behavior of tf_pipeline_slr_xing is

  attribute dont_touch : string;
  attribute dont_touch of behavior : architecture is "yes";

  type t_wea_intra is array (0 to NUM_SLR) of std_logic;
  type t_addra_intra is array (0 to NUM_SLR) of std_logic_vector( clogb2(RAM_DEPTH) - 1 downto 0 );
  type t_dina_intra is array (0 to NUM_SLR) of std_logic_vector( RAM_WIDTH - 1 downto 0 );
  type t_start_intra is array(0 to NUM_SLR) of std_logic;
  type t_bx_intra is array(0 to NUM_SLR) of std_logic_vector(2 downto 0);

  signal wea_intra : t_wea_intra := (others => '0');
  signal addra_intra : t_addra_intra := (others => (others => '0'));
  signal dina_intra : t_dina_intra := (others => (others => '0'));
  signal start_intra : t_start_intra := (others => '0');
  signal bx_intra : t_bx_intra := (others => (others => '0'));

begin

  wea_out <= wea_intra(NUM_SLR);
  addra_out <= addra_intra(NUM_SLR);
  dina_out <= dina_intra(NUM_SLR);
  start <= start_intra(NUM_SLR);
  bx <= bx_intra(NUM_SLR);

  PIPELINE_SLR_XING : for ii in 1 to NUM_SLR generate

    AUTO_PIPELINE_ON : if AUTO_PIPELINE generate

      AUTO_PIPELINE_MEM : entity work.tf_auto_pipeline
        generic map (
          RAM_WIDTH => RAM_WIDTH,
          NUM_PAGES => NUM_PAGES,
          PAGE_LENGTH => PAGE_LENGTH,
          RAM_DEPTH => RAM_DEPTH
        )
        port map (
          clk => clk,
          reset => reset,
          wea => wea_intra(ii - 1),
          addra => addra_intra(ii - 1),
          dina => dina_intra(ii - 1),
          wea_out => wea_intra(ii),
          addra_out => addra_intra(ii),
          dina_out => dina_intra(ii)
        );

      AUTO_PIPELINE_START_BX : entity work.tf_auto_pipeline
        port map (
          clk => clk,
          reset => reset,
          done => start_intra(ii - 1),
          bx_out => bx_intra(ii - 1),
          start => start_intra(ii),
          bx => bx_intra(ii)
        );

    end generate AUTO_PIPELINE_ON;

    AUTO_PIPELINE_OFF : if not AUTO_PIPELINE generate

      USE_SRL_ON : if USE_SRL(ii - 1) generate

          PIPELINE_MEM : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "yes",
              RAM_WIDTH => RAM_WIDTH,
              NUM_PAGES => NUM_PAGES,
              PAGE_LENGTH => PAGE_LENGTH,
              RAM_DEPTH => RAM_DEPTH
            )
            port map (
              clk => clk,
              reset => reset,
              wea => wea_intra(ii - 1),
              addra => addra_intra(ii - 1),
              dina => dina_intra(ii - 1),
              wea_out => wea_intra(ii),
              addra_out => addra_intra(ii),
              dina_out => dina_intra(ii)
            );

          PIPELINE_START_BX : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "yes"
            )
            port map (
              clk => clk,
              reset => reset,
              done => start_intra(ii - 1),
              bx_out => bx_intra(ii - 1),
              start => start_intra(ii),
              bx => bx_intra(ii)
            );

      end generate USE_SRL_ON;

      USE_SRL_OFF : if not USE_SRL(ii - 1) generate

          PIPELINE_MEM : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "no",
              RAM_WIDTH => RAM_WIDTH,
              NUM_PAGES => NUM_PAGES,
              PAGE_LENGTH => PAGE_LENGTH,
              RAM_DEPTH => RAM_DEPTH
            )
            port map (
              clk => clk,
              reset => reset,
              wea => wea_intra(ii - 1),
              addra => addra_intra(ii - 1),
              dina => dina_intra(ii - 1),
              wea_out => wea_intra(ii),
              addra_out => addra_intra(ii),
              dina_out => dina_intra(ii)
            );

          PIPELINE_START_BX : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "no"
            )
            port map (
              clk => clk,
              reset => reset,
              done => start_intra(ii - 1),
              bx_out => bx_intra(ii - 1),
              start => start_intra(ii),
              bx => bx_intra(ii)
            );

      end generate USE_SRL_OFF;

    end generate AUTO_PIPELINE_OFF;

  end generate PIPELINE_SLR_XING;

  wea_intra(0) <= wea;
  addra_intra(0) <= addra;
  dina_intra(0) <= dina;
  start_intra(0) <= done;
  bx_intra(0) <= bx_out;

end behavior;
