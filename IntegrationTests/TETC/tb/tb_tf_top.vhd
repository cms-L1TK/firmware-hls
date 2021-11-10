--! Standard library
library ieee;
--! Standard package
use ieee.std_logic_1164.all;
--! Signed/unsigned calculations
use ieee.numeric_std.all;
--! Math real
use ieee.math_real.all;
--! TextIO
use ieee.std_logic_textio.all;
--! Standard functions
library std;
--! Standard TextIO functions
use std.textio.all;

--! Xilinx library
library unisim;
--! Xilinx package
use unisim.vcomponents.all;

--! User packages
use work.tf_pkg.all;
use work.memUtil_pkg.all;

--! @brief TB
entity tb_tf_top is
end tb_tf_top;

--! @brief TB
architecture behaviour of tb_tf_top is

  -- ########################### Constant Definitions ###########################
  -- ############ Please change the constants in this section ###################

  --=========================================================================
  -- Specify version of chain to run from TB:
  --    0 = SectorProcessor.vhd from python script.
  --    1 = SectorProcessorFull.vhd from python script (gives intermediate MemPrints).
  --    N.B. Change this also in makeProject.tcl !
  constant INST_TOP_TF          : integer := 1; 
  --=========================================================================

  constant CLK_PERIOD           : time    := 4 ns;       --! 250 MHz
  constant DEBUG                : boolean := false;      --! Debug off/on
  constant AS_DELAY             : integer := 1;          --! Number of BX delays
  constant VMSTE_DELAY          : integer := 0;          --! Number of BX delays

  -- Paths of data files specified relative to Vivado project's xsim directory.
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant emDataDir            : string := "../../../../../MemPrints/";
  constant dataOutDir           : string := "../../../../../dataOut/";

  -- File directories and the start of the file names that memories have in common
  -- Input files
  constant FILE_IN_AS           : string := emDataDir&"Stubs/AllStubs_AS_";
  constant FILE_IN_VMSTE        : string := emDataDir&"VMStubsTE/VMStubs_VMSTE_";
  -- Output files
  constant FILE_OUT_SP_14       : string := dataOutDir&"SP_";
  constant FILE_OUT_TPROJ_60    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPROJ_58    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPROJ_59    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPAR_70     : string := dataOutDir&"TPAR_";
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_AS_debug    : string := dataOutDir&"AS_";
  constant FILE_OUT_VMSTE_debug : string := dataOutDir&"VMSTE_";

  -- File name endings
  constant inputFileNameEnding  : string := "_04.dat"; -- 04 specifies the nonant/sector the testvectors represent
  constant outputFileNameEnding : string := ".txt";
  constant debugFileNameEnding  : string := ".debug.txt";


  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk                        : std_logic := '0';
  signal reset                      : std_logic := '1';
  signal TE_start                   : std_logic := '0';
  signal TE_idle                    : std_logic := '0';
  signal TE_ready                   : std_logic := '0';
  signal TE_bx_in                   : std_logic_vector(2 downto 0) := (others => '1');
  signal TE_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal TE_bx_out_vld              : std_logic := '0';
  signal TE_done                    : std_logic := '0';
  signal TC_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal TC_bx_out_vld              : std_logic := '0';
  signal TC_done                    : std_logic := '0';

  -- Signals matching ports of top-level VHDL
  signal AS_36_mem_A_wea            : t_arr_AS_36_1b       := (others => '0');
  signal AS_36_mem_AV_writeaddr     : t_arr_AS_36_ADDR     := (others => (others => '0'));
  signal AS_36_mem_AV_din           : t_arr_AS_36_DATA     := (others => (others => '0'));
  signal VMSTE_22_mem_A_wea         : t_arr_VMSTE_22_1b    := (others => '0');
  signal VMSTE_22_mem_AV_writeaddr  : t_arr_VMSTE_22_ADDR  := (others => (others => '0'));
  signal VMSTE_22_mem_AV_din        : t_arr_VMSTE_22_DATA  := (others => (others => '0'));
  signal VMSTE_16_mem_A_wea         : t_arr_VMSTE_16_1b    := (others => '0');
  signal VMSTE_16_mem_AV_writeaddr  : t_arr_VMSTE_16_ADDR  := (others => (others => '0'));
  signal VMSTE_16_mem_AV_din        : t_arr_VMSTE_16_DATA  := (others => (others => '0'));
  signal SP_14_mem_A_wea            : t_arr_SP_14_1b       := (others => '0');
  signal SP_14_mem_AV_writeaddr     : t_arr_SP_14_ADDR     := (others => (others => '0'));
  signal SP_14_mem_AV_din           : t_arr_SP_14_DATA     := (others => (others => '0'));
  signal TPROJ_60_mem_A_enb         : t_arr_TPROJ_60_1b    := (others => '0');
  signal TPROJ_60_mem_AV_readaddr   : t_arr_TPROJ_60_ADDR  := (others => (others => '0'));
  signal TPROJ_60_mem_AV_dout       : t_arr_TPROJ_60_DATA  := (others => (others => '0'));
  signal TPROJ_60_mem_AAV_dout_nent : t_arr_TPROJ_60_NENT  := (others => (others => (others => '0'))); -- (#page)
  signal TPROJ_58_mem_A_enb         : t_arr_TPROJ_58_1b    := (others => '0');
  signal TPROJ_58_mem_AV_readaddr   : t_arr_TPROJ_58_ADDR  := (others => (others => '0'));
  signal TPROJ_58_mem_AV_dout       : t_arr_TPROJ_58_DATA  := (others => (others => '0'));
  signal TPROJ_58_mem_AAV_dout_nent : t_arr_TPROJ_58_NENT  := (others => (others => (others => '0'))); -- (#page)
  signal TPROJ_59_mem_A_enb         : t_arr_TPROJ_59_1b    := (others => '0');
  signal TPROJ_59_mem_AV_readaddr   : t_arr_TPROJ_59_ADDR  := (others => (others => '0'));
  signal TPROJ_59_mem_AV_dout       : t_arr_TPROJ_59_DATA  := (others => (others => '0'));
  signal TPROJ_59_mem_AAV_dout_nent : t_arr_TPROJ_59_NENT  := (others => (others => (others => '0'))); -- (#page)
  signal TPAR_70_mem_A_enb          : t_arr_TPAR_70_1b     := (others => '0');
  signal TPAR_70_mem_AV_readaddr    : t_arr_TPAR_70_ADDR   := (others => (others => '0'));
  signal TPAR_70_mem_AV_dout        : t_arr_TPAR_70_DATA   := (others => (others => '0'));
  signal TPAR_70_mem_AAV_dout_nent  : t_arr_TPAR_70_NENT   := (others => (others => (others => '0'))); -- (#page)

  -- Indicates that writing of the initial memories of the first event has started.
  signal START_FIRST_WRITE : std_logic := '0';
  signal START_VMSTE : t_arr_VMSTE_22_1b := (others => '0');

begin

--! @brief Make clock ---------------------------------------
  clk <= not clk after CLK_PERIOD/2;

  -- Get signals from input .txt files

  AS_36_loop : for var in enum_AS_36 generate
  begin
    readAS_36 : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => AS_DELAY*MAX_ENTRIES,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      ADDR            => AS_36_mem_AV_writeaddr(var),
      DATA            => AS_36_mem_AV_din(var),
      START => open,
      WRITE_EN        => AS_36_mem_A_wea(var)
    );
  end generate AS_36_loop;

  VMSTE_22_loop : for var in enum_VMSTE_22 generate
  begin
    readVMSTE_22 : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_VMSTE&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => VMSTE_DELAY*MAX_ENTRIES,
      RAM_WIDTH       => 22,
      NUM_PAGES       => 2,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_VMSTE_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      ADDR            => VMSTE_22_mem_AV_writeaddr(var),
      DATA            => VMSTE_22_mem_AV_din(var),
      START           => START_VMSTE(var),
      WRITE_EN        => VMSTE_22_mem_A_wea(var)
    );
  end generate VMSTE_22_loop;

  -- As all VMSTE signals start together, take first one, to determine when
  -- first event starts being written to first memory in chain.
  START_FIRST_WRITE <= START_VMSTE(enum_VMSTE_22'val(0));

  VMSTE_16_loop : for var in enum_VMSTE_16 generate
  begin
    readVMSTE_16 : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_VMSTE&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => VMSTE_DELAY*MAX_ENTRIES,
      RAM_WIDTH       => 16,
      NUM_PAGES       => 2,
      NUM_BINS        => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_VMSTE_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      ADDR            => VMSTE_16_mem_AV_writeaddr(var),
      DATA            => VMSTE_16_mem_AV_din(var),
      START => open,
      WRITE_EN        => VMSTE_16_mem_A_wea(var)
    );
  end generate VMSTE_16_loop;

  procStart : process(CLK)
    -- Process to start first module in chain & generate its BX counter input.
    -- Also releases reset flag.
    constant CLK_RESET : natural := 5; -- Any low number OK.
    variable CLK_COUNT : natural := 1;
    variable EVENT_COUNT : integer := -1;
    variable v_line : line; -- Line for debug
  begin

    if START_FIRST_WRITE= '1' then
      if rising_edge(CLK) then
        if (CLK_COUNT < MAX_ENTRIES) then
          CLK_COUNT := CLK_COUNT + 1;
        else
          CLK_COUNT := 1;
          EVENT_COUNT := EVENT_COUNT + 1;

          -- TE should start one TM period after time when first event starting being 
          -- written to first memory in chain, as it takes this long to write full event.
          TE_START <= '1';
          TE_BX_IN <= std_logic_vector(to_unsigned(EVENT_COUNT, TE_BX_IN'length));

          write(v_line, string'("=== Processing event ")); write(v_line,EVENT_COUNT); write(v_line, string'(" at SIM time ")); write(v_line, NOW); writeline(output, v_line);
        end if;
        -- Releae
        if (CLK_COUNT = CLK_RESET) then 
          RESET <= '0';
        end if;
      end if;
    end if;
  end process procStart;

  -- ########################### Instantiation ###########################
  -- Instantiate the Unit Under Test (UUT)

  sectorProc : if INST_TOP_TF = 0 generate
  begin
    uut : entity work.SectorProcessor
      port map(
        clk                        => clk,
        reset                      => reset,
        TE_start                   => TE_start,
        TE_bx_in                   => TE_bx_in,
        TC_bx_out                  => TC_bx_out,
        TC_bx_out_vld              => TC_bx_out_vld,
        TC_done                    => TC_done,
        -- Input data
        AS_36_mem_A_wea            => AS_36_mem_A_wea,
        AS_36_mem_AV_writeaddr     => AS_36_mem_AV_writeaddr,
        AS_36_mem_AV_din           => AS_36_mem_AV_din,
        VMSTE_22_mem_A_wea         => VMSTE_22_mem_A_wea,
        VMSTE_22_mem_AV_writeaddr  => VMSTE_22_mem_AV_writeaddr,
        VMSTE_22_mem_AV_din        => VMSTE_22_mem_AV_din,
        VMSTE_16_mem_A_wea         => VMSTE_16_mem_A_wea,
        VMSTE_16_mem_AV_writeaddr  => VMSTE_16_mem_AV_writeaddr,
        VMSTE_16_mem_AV_din        => VMSTE_16_mem_AV_din,
        -- Output data
        TPROJ_60_mem_A_enb         => TPROJ_60_mem_A_enb,
        TPROJ_60_mem_AV_readaddr   => TPROJ_60_mem_AV_readaddr,
        TPROJ_60_mem_AV_dout       => TPROJ_60_mem_AV_dout,
        TPROJ_60_mem_AAV_dout_nent => TPROJ_60_mem_AAV_dout_nent,
        TPROJ_58_mem_A_enb         => TPROJ_58_mem_A_enb,
        TPROJ_58_mem_AV_readaddr   => TPROJ_58_mem_AV_readaddr,
        TPROJ_58_mem_AV_dout       => TPROJ_58_mem_AV_dout,
        TPROJ_58_mem_AAV_dout_nent => TPROJ_58_mem_AAV_dout_nent,
        TPROJ_59_mem_A_enb         => TPROJ_59_mem_A_enb,
        TPROJ_59_mem_AV_readaddr   => TPROJ_59_mem_AV_readaddr,
        TPROJ_59_mem_AV_dout       => TPROJ_59_mem_AV_dout,
        TPROJ_59_mem_AAV_dout_nent => TPROJ_59_mem_AAV_dout_nent,
        TPAR_70_mem_A_enb          => TPAR_70_mem_A_enb,
        TPAR_70_mem_AV_readaddr    => TPAR_70_mem_AV_readaddr,
        TPAR_70_mem_AV_dout        => TPAR_70_mem_AV_dout,
        TPAR_70_mem_AAV_dout_nent  => TPAR_70_mem_AAV_dout_nent
      );
  end generate sectorProc;

  sectorProcFull : if INST_TOP_TF = 1 generate
  begin
    uut : entity work.SectorProcessorFull
      port map(
        clk                        => clk,
        reset                      => reset,
        TE_start                   => TE_start,
        TE_bx_in                   => TE_bx_in,
        TC_bx_out                  => TC_bx_out,
        TC_bx_out_vld              => TC_bx_out_vld,
        TC_done                    => TC_done,
        -- Debug control signals
        TE_bx_out                  => TE_bx_out,
        TE_bx_out_vld              => TE_bx_out_vld,
        TE_done                    => TE_done,
        -- Input data
        AS_36_mem_A_wea            => AS_36_mem_A_wea,
        AS_36_mem_AV_writeaddr     => AS_36_mem_AV_writeaddr,
        AS_36_mem_AV_din           => AS_36_mem_AV_din,
        VMSTE_22_mem_A_wea         => VMSTE_22_mem_A_wea,
        VMSTE_22_mem_AV_writeaddr  => VMSTE_22_mem_AV_writeaddr,
        VMSTE_22_mem_AV_din        => VMSTE_22_mem_AV_din,
        VMSTE_16_mem_A_wea         => VMSTE_16_mem_A_wea,
        VMSTE_16_mem_AV_writeaddr  => VMSTE_16_mem_AV_writeaddr,
        VMSTE_16_mem_AV_din        => VMSTE_16_mem_AV_din,
        -- Debug output data
        SP_14_mem_A_wea            => SP_14_mem_A_wea,
        SP_14_mem_AV_writeaddr     => SP_14_mem_AV_writeaddr,
        SP_14_mem_AV_din           => SP_14_mem_AV_din,
        -- Output data
        TPROJ_60_mem_A_enb         => TPROJ_60_mem_A_enb,
        TPROJ_60_mem_AV_readaddr   => TPROJ_60_mem_AV_readaddr,
        TPROJ_60_mem_AV_dout       => TPROJ_60_mem_AV_dout,
        TPROJ_60_mem_AAV_dout_nent => TPROJ_60_mem_AAV_dout_nent,
        TPROJ_58_mem_A_enb         => TPROJ_58_mem_A_enb,
        TPROJ_58_mem_AV_readaddr   => TPROJ_58_mem_AV_readaddr,
        TPROJ_58_mem_AV_dout       => TPROJ_58_mem_AV_dout,
        TPROJ_58_mem_AAV_dout_nent => TPROJ_58_mem_AAV_dout_nent,
        TPROJ_59_mem_A_enb         => TPROJ_59_mem_A_enb,
        TPROJ_59_mem_AV_readaddr   => TPROJ_59_mem_AV_readaddr,
        TPROJ_59_mem_AV_dout       => TPROJ_59_mem_AV_dout,
        TPROJ_59_mem_AAV_dout_nent => TPROJ_59_mem_AAV_dout_nent,
        TPAR_70_mem_A_enb          => TPAR_70_mem_A_enb,
        TPAR_70_mem_AV_readaddr    => TPAR_70_mem_AV_readaddr,
        TPAR_70_mem_AV_dout        => TPAR_70_mem_AV_dout,
        TPAR_70_mem_AAV_dout_nent  => TPAR_70_mem_AAV_dout_nent
      );
  end generate sectorProcFull;

  -- Write signals to output .txt files

  writeIntermediateRAMs : if INST_TOP_TF = 1 generate
  begin

    -- This writes signals going to intermediate memories in chain.

    SP_14_loop : for var in enum_SP_14 generate
    begin
      writeSP_14 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_SP_14&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 14,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => SP_14_mem_AV_writeaddr(var),
        DATA      => SP_14_mem_AV_din(var),
        WRITE_EN  => SP_14_mem_A_wea(var),
        START     => TE_START,
        DONE      => TE_DONE
      );
    end generate SP_14_loop;

  end generate writeIntermediateRAMs;


  -- Write memories from end of chain.

  TPROJ_60_loop : for var in enum_TPROJ_60 generate
  begin
    writeTPROJ_60 : entity work.FileWriterFromRAM
    generic map (
      FILE_NAME => FILE_OUT_TPROJ_60&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH => 60,
      NUM_PAGES => 2
    )
    port map (
      CLK       => CLK,
      ADDR      => TPROJ_60_mem_AV_readaddr(var),
      DATA      => TPROJ_60_mem_AV_dout(var),
      READ_EN   => TPROJ_60_mem_A_enb(var),
      NENT_ARR  => TPROJ_60_mem_AAV_dout_nent(var),
      DONE      => TC_DONE
    );
  end generate TPROJ_60_loop;

  TPROJ_58_loop : for var in enum_TPROJ_58 generate
  begin
    writeTPROJ_58 : entity work.FileWriterFromRAM
    generic map (
      FILE_NAME => FILE_OUT_TPROJ_58&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH => 58,
      NUM_PAGES => 2
    )
    port map (
      CLK       => CLK,
      ADDR      => TPROJ_58_mem_AV_readaddr(var),
      DATA      => TPROJ_58_mem_AV_dout(var),
      READ_EN   => TPROJ_58_mem_A_enb(var),
      NENT_ARR  => TPROJ_58_mem_AAV_dout_nent(var),
      DONE      => TC_DONE
    );
  end generate TPROJ_58_loop;

  TPROJ_59_loop : for var in enum_TPROJ_59 generate
  begin
    writeTPROJ_59 : entity work.FileWriterFromRAM
    generic map (
      FILE_NAME => FILE_OUT_TPROJ_59&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH => 59,
      NUM_PAGES => 2
    )
    port map (
      CLK       => CLK,
      ADDR      => TPROJ_59_mem_AV_readaddr(var),
      DATA      => TPROJ_59_mem_AV_dout(var),
      READ_EN   => TPROJ_59_mem_A_enb(var),
      NENT_ARR  => TPROJ_59_mem_AAV_dout_nent(var),
      DONE      => TC_DONE
    );
  end generate TPROJ_59_loop;

  TPAR_70_loop : for var in enum_TPAR_70 generate
  begin
    writeTPAR_70 : entity work.FileWriterFromRAM
    generic map (
      FILE_NAME => FILE_OUT_TPAR_70&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH => 70,
      NUM_PAGES => 8
    )
    port map (
      CLK       => CLK,
      ADDR      => TPAR_70_mem_AV_readaddr(var),
      DATA      => TPAR_70_mem_AV_dout(var),
      READ_EN   => TPAR_70_mem_A_enb(var),
      NENT_ARR  => TPAR_70_mem_AAV_dout_nent(var),
      DONE      => TC_DONE
    );
  end generate TPAR_70_loop;


end behaviour;
