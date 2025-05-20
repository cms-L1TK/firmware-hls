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
use work.memUtil_aux_pkg_f2.all;

entity tf_pipeline is
  generic (
    DELAY : natural := 2;
    USE_SRL : string := "no";
    EMP_WRAPPER : boolean := false;
    RAM_WIDTH : natural := 14;
    NUM_PAGES : natural := 2;
    PAGE_LENGTH : natural := PAGE_LENGTH;
    RAM_DEPTH : natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;

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
    bx : out std_logic_vector(2 downto 0);

    -- EMP wrapper interface
    f2_input_in : in t_f2_in := c_f2_in_init;
    f2_output_in : in t_f2_out := c_f2_out_init;
    f2_input_out : out t_f2_in;
    f2_output_out : out t_f2_out
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
  type t_f2_in_pipe is array(0 to DELAY - 1) of t_f2_in;
  type t_f2_out_pipe is array(0 to DELAY - 1) of t_f2_out;

  signal wea_pipe : t_wea_pipe := (others => '0');
  signal addra_pipe : t_addra_pipe := (others => (others => '0') );
  signal dina_pipe : t_dina_pipe := (others => (others => '0') );
  signal start_pipe : t_start_pipe := (others => '0');
  signal bx_pipe : t_bx_pipe := (others => (others => '0') );
  signal f2_in_pipe : t_f2_in_pipe := (others => c_f2_in_init);
  signal f2_out_pipe : t_f2_out_pipe := (others => c_f2_out_init);

  attribute shreg_extract : string;
  attribute shreg_extract of wea_pipe : signal is USE_SRL;
  attribute shreg_extract of addra_pipe : signal is USE_SRL;
  attribute shreg_extract of dina_pipe : signal is USE_SRL;
  attribute shreg_extract of start_pipe : signal is USE_SRL;
  attribute shreg_extract of bx_pipe : signal is USE_SRL;
  attribute shreg_extract of f2_in_pipe : signal is USE_SRL;
  attribute shreg_extract of f2_out_pipe : signal is USE_SRL;

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
      if done = '1' then
        start_pipe(0) <= done;
      end if;
      bx_pipe(0) <= bx_out;

    end if;

  end process;

  EMP_WRAPPER_0 : if EMP_WRAPPER generate

    f2_input_out <= f2_in_pipe(DELAY - 1);
    f2_output_out <= f2_out_pipe(DELAY - 1);

    PIPELINE_EMP_WRAPPER : process (clk) is
    begin
      if rising_edge(clk) then
        for ii in 1 to DELAY - 1 loop
          f2_in_pipe(ii) <= f2_in_pipe(ii - 1);
          f2_out_pipe(ii) <= f2_out_pipe(ii - 1);
        end loop;
        f2_in_pipe(0) <= f2_input_in;
        f2_out_pipe(0) <= f2_output_in;
      end if;
    end process;

  end generate EMP_WRAPPER_0;

end behavior;

--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! User packages
use work.tf_pkg.all;
use work.memUtil_aux_pkg_f2.all;

entity tf_auto_pipeline is
  generic (
    EMP_WRAPPER : boolean := false;
    RAM_WIDTH : natural := 14;
    NUM_PAGES : natural := 2;
    PAGE_LENGTH : natural := PAGE_LENGTH;
    RAM_DEPTH : natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;

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
    bx : out std_logic_vector(2 downto 0);

    -- EMP wrapper interface
    f2_input_in : in t_f2_in := c_f2_in_init;
    f2_output_in : in t_f2_out := c_f2_out_init;
    f2_input_out : out t_f2_in;
    f2_output_out : out t_f2_out
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
  signal f2_in_reg : t_f2_in := c_f2_in_init;
  signal f2_out_reg : t_f2_out := c_f2_out_init;

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
      if done = '1' then
        start_reg <= done;
      end if;
      bx_reg <= bx_out;

    end if;

  end process;

  EMP_WRAPPER_1 : if EMP_WRAPPER generate

    f2_input_out <= f2_in_reg;
    f2_output_out <= f2_out_reg;

    AUTO_PIPELINE_EMP_WRAPPER : process (clk) is
    begin
      if rising_edge(clk) then
        f2_in_reg <= f2_input_in;
        f2_out_reg <= f2_output_in;
      end if;
    end process;

  end generate EMP_WRAPPER_1;

end behavior;

--! Using the IEEE Library
library IEEE;
--! Using STD_LOGIC
use IEEE.STD_LOGIC_1164.all;
--! Using NUMERIC TYPES
use IEEE.NUMERIC_STD.all;
--! User packages
use work.tf_pkg.all;
use work.memUtil_aux_pkg_f2.all;

entity tf_pipeline_slr_xing is
  generic (
    AUTO_PIPELINE : boolean := false;
    NUM_SLR : natural := 2;
    DELAY : t_arr_1d_nat(0 to NUM_SLR - 1) := (others => 2);
    USE_SRL : t_arr_1d_bol(0 to NUM_SLR - 1) := (others => false);
    EMP_WRAPPER : boolean := false;
    RAM_WIDTH : natural := 14;
    NUM_PAGES : natural := 2;
    PAGE_LENGTH : natural := PAGE_LENGTH;
    RAM_DEPTH : natural := NUM_PAGES*PAGE_LENGTH
  );
  port (
    clk : in std_logic;

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
    bx : out std_logic_vector(2 downto 0);

    -- EMP wrapper interface
    f2_input_in : in t_f2_in := c_f2_in_init;
    f2_output_in : in t_f2_out := c_f2_out_init;
    f2_input_out : out t_f2_in;
    f2_output_out : out t_f2_out
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
  type t_f2_in_intra is array(0 to NUM_SLR) of t_f2_in;
  type t_f2_out_intra is array(0 to NUM_SLR) of t_f2_out;

  signal wea_intra : t_wea_intra := (others => '0');
  signal addra_intra : t_addra_intra := (others => (others => '0'));
  signal dina_intra : t_dina_intra := (others => (others => '0'));
  signal start_intra : t_start_intra := (others => '0');
  signal bx_intra : t_bx_intra := (others => (others => '0'));
  signal f2_in_intra : t_f2_in_intra := (others => c_f2_in_init);
  signal f2_out_intra : t_f2_out_intra := (others => c_f2_out_init);

begin

  wea_out <= wea_intra(NUM_SLR);
  addra_out <= addra_intra(NUM_SLR);
  dina_out <= dina_intra(NUM_SLR);
  start <= start_intra(NUM_SLR);
  bx <= bx_intra(NUM_SLR);
  f2_input_out <= f2_in_intra(NUM_SLR);
  f2_output_out <= f2_out_intra(NUM_SLR);

  PIPELINE_SLR_XING : for ii in 1 to NUM_SLR generate

    AUTO_PIPELINE_ON : if AUTO_PIPELINE generate

      AUTO_PIPELINE_MEM : entity work.tf_auto_pipeline
        generic map (
          EMP_WRAPPER => EMP_WRAPPER,
          RAM_WIDTH => RAM_WIDTH,
          NUM_PAGES => NUM_PAGES,
          PAGE_LENGTH => PAGE_LENGTH,
          RAM_DEPTH => RAM_DEPTH
        )
        port map (
          clk => clk,
          wea => wea_intra(ii - 1),
          addra => addra_intra(ii - 1),
          dina => dina_intra(ii - 1),
          wea_out => wea_intra(ii),
          addra_out => addra_intra(ii),
          dina_out => dina_intra(ii)
        );

      AUTO_PIPELINE_START_BX : entity work.tf_auto_pipeline
        generic map (
          EMP_WRAPPER => EMP_WRAPPER
        )
        port map (
          clk => clk,
          done => start_intra(ii - 1),
          bx_out => bx_intra(ii - 1),
          start => start_intra(ii),
          bx => bx_intra(ii)
        );

      AUTO_PIPELINE_EMP_WRAPPER : entity work.tf_auto_pipeline
        generic map (
          EMP_WRAPPER => EMP_WRAPPER
        )
        port map (
          clk => clk,
          f2_input_in => f2_in_intra(ii - 1),
          f2_output_in => f2_out_intra(ii - 1),
          f2_input_out => f2_in_intra(ii),
          f2_output_out => f2_out_intra(ii)
        );

    end generate AUTO_PIPELINE_ON;

    AUTO_PIPELINE_OFF : if not AUTO_PIPELINE generate

      USE_SRL_ON : if USE_SRL(ii - 1) generate

          PIPELINE_MEM : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "yes",
              EMP_WRAPPER => EMP_WRAPPER,
              RAM_WIDTH => RAM_WIDTH,
              NUM_PAGES => NUM_PAGES,
              PAGE_LENGTH => PAGE_LENGTH,
              RAM_DEPTH => RAM_DEPTH
            )
            port map (
              clk => clk,
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
              USE_SRL => "yes",
              EMP_WRAPPER => EMP_WRAPPER
            )
            port map (
              clk => clk,
              done => start_intra(ii - 1),
              bx_out => bx_intra(ii - 1),
              start => start_intra(ii),
              bx => bx_intra(ii)
            );

          PIPELINE_EMP_WRAPPER : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "yes",
              EMP_WRAPPER => EMP_WRAPPER
            )
            port map (
              clk => clk,
              f2_input_in => f2_in_intra(ii - 1),
              f2_output_in => f2_out_intra(ii - 1),
              f2_input_out => f2_in_intra(ii),
              f2_output_out => f2_out_intra(ii)
            );

      end generate USE_SRL_ON;

      USE_SRL_OFF : if not USE_SRL(ii - 1) generate

          PIPELINE_MEM : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "no",
              EMP_WRAPPER => EMP_WRAPPER,
              RAM_WIDTH => RAM_WIDTH,
              NUM_PAGES => NUM_PAGES,
              PAGE_LENGTH => PAGE_LENGTH,
              RAM_DEPTH => RAM_DEPTH
            )
            port map (
              clk => clk,
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
              USE_SRL => "no",
              EMP_WRAPPER => EMP_WRAPPER
            )
            port map (
              clk => clk,
              done => start_intra(ii - 1),
              bx_out => bx_intra(ii - 1),
              start => start_intra(ii),
              bx => bx_intra(ii)
            );

          PIPELINE_EMP_WRAPPER : entity work.tf_pipeline
            generic map (
              DELAY => DELAY(ii - 1),
              USE_SRL => "no",
              EMP_WRAPPER => EMP_WRAPPER
            )
            port map (
              clk => clk,
              f2_input_in => f2_in_intra(ii - 1),
              f2_output_in => f2_out_intra(ii - 1),
              f2_input_out => f2_in_intra(ii),
              f2_output_out => f2_out_intra(ii)
            );

      end generate USE_SRL_OFF;

    end generate AUTO_PIPELINE_OFF;

  end generate PIPELINE_SLR_XING;

  wea_intra(0) <= wea;
  addra_intra(0) <= addra;
  dina_intra(0) <= dina;
  start_intra(0) <= done;
  bx_intra(0) <= bx_out;
  f2_in_intra(0) <= f2_input_in;
  f2_out_intra(0) <= f2_output_in;

end behavior;
