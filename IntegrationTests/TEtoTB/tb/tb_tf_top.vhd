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
  constant VMSME_DELAY          : integer := 3;          --! Number of BX delays
  constant VMSTE_DELAY          : integer := 0;          --! Number of BX delays

  -- Paths of data files specified relative to Vivado project's xsim directory.
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant emDataDir            : string := "../../../../../../../../emData/MemPrints/";
  constant dataOutDir           : string := "../../../../../dataOut/";

  -- File directories and the start of the file names that memories have in common
  -- Input files
  constant FILE_IN_AS           : string := emDataDir&"Stubs/AllStubs_AS_";
  constant FILE_IN_VMSME        : string := emDataDir&"VMStubsME/VMStubs_VMSME_";
  constant FILE_IN_VMSTE        : string := emDataDir&"VMStubsTE/VMStubs_VMSTE_";
  -- Output files
  constant FILE_OUT_SP_14       : string := dataOutDir&"SP_";
  constant FILE_OUT_TPROJ_60    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPROJ_58    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPAR_70     : string := dataOutDir&"TPAR_";
  constant FILE_OUT_VMPROJ_24   : string := dataOutDir&"VMPROJ_";
  constant FILE_OUT_AP_60       : string := dataOutDir&"AP_";
  constant FILE_OUT_AP_58       : string := dataOutDir&"AP_";
  constant FILE_OUT_CM_14       : string := dataOutDir&"CM_";
  constant FILE_OUT_FM_52       : string := dataOutDir&"FM_";
  constant FILE_OUT_TW_84       : string := dataOutDir&"TW_";
  constant FILE_OUT_BW_46       : string := dataOutDir&"BW_";
  constant FILE_OUT_TF_464      : string := dataOutDir&"TF_";
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_AS_debug    : string := dataOutDir&"AS_";
  constant FILE_OUT_VMSME_debug : string := dataOutDir&"VMSME_";
  constant FILE_OUT_VMSTE_debug : string := dataOutDir&"VMSTE_";

  -- File name endings
  constant inputFileNameEnding  : string := "_04.dat"; -- 04 specifies the nonant/sector the testvectors represent
  constant outputFileNameEnding : string := ".txt";
  constant debugFileNameEnding  : string := ".debug.txt";

  -- Empty field in the output from FT_L1L2 corresponding to disk matches
  constant emptyDiskStub : std_logic_vector(48 downto 0) := (others => '0');

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
  signal PR_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal PR_bx_out_vld              : std_logic := '0';
  signal PR_done                    : std_logic := '0';
  signal ME_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal ME_bx_out_vld              : std_logic := '0';
  signal ME_done                    : std_logic := '0';
  signal MC_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal MC_bx_out_vld              : std_logic := '0';
  signal MC_done                    : std_logic := '0';
  signal FT_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal FT_bx_out_vld              : std_logic := '0';
  signal FT_done                    : std_logic := '0';

  -- Signals matching ports of top-level VHDL
  signal AS_36_mem_A_wea            : t_arr_AS_36_1b       := (others => '0');
  signal AS_36_mem_AV_writeaddr     : t_arr_AS_36_ADDR     := (others => (others => '0'));
  signal AS_36_mem_AV_din           : t_arr_AS_36_DATA     := (others => (others => '0'));
  signal VMSME_16_mem_A_wea         : t_arr_VMSME_16_1b    := (others => '0');
  signal VMSME_16_mem_AV_writeaddr  : t_arr_VMSME_16_ADDR  := (others => (others => '0'));
  signal VMSME_16_mem_AV_din        : t_arr_VMSME_16_DATA  := (others => (others => '0'));
  signal VMSME_17_mem_A_wea         : t_arr_VMSME_17_1b    := (others => '0');
  signal VMSME_17_mem_AV_writeaddr  : t_arr_VMSME_17_ADDR  := (others => (others => '0'));
  signal VMSME_17_mem_AV_din        : t_arr_VMSME_17_DATA  := (others => (others => '0'));
  signal VMSTE_22_mem_A_wea         : t_arr_VMSTE_22_1b    := (others => '0');
  signal VMSTE_22_mem_AV_writeaddr  : t_arr_VMSTE_22_ADDR  := (others => (others => '0'));
  signal VMSTE_22_mem_AV_din        : t_arr_VMSTE_22_DATA  := (others => (others => '0'));
  signal VMSTE_16_mem_A_wea         : t_arr_VMSTE_16_1b    := (others => '0');
  signal VMSTE_16_mem_AV_writeaddr  : t_arr_VMSTE_16_ADDR  := (others => (others => '0'));
  signal VMSTE_16_mem_AV_din        : t_arr_VMSTE_16_DATA  := (others => (others => '0'));
  signal SP_14_mem_A_wea            : t_arr_SP_14_1b       := (others => '0');
  signal SP_14_mem_AV_writeaddr     : t_arr_SP_14_ADDR     := (others => (others => '0'));
  signal SP_14_mem_AV_din           : t_arr_SP_14_DATA     := (others => (others => '0'));
  signal TPROJ_60_mem_A_wea         : t_arr_TPROJ_60_1b    := (others => '0');
  signal TPROJ_60_mem_AV_writeaddr  : t_arr_TPROJ_60_ADDR  := (others => (others => '0'));
  signal TPROJ_60_mem_AV_din        : t_arr_TPROJ_60_DATA  := (others => (others => '0'));
  signal TPROJ_58_mem_A_wea         : t_arr_TPROJ_58_1b    := (others => '0');
  signal TPROJ_58_mem_AV_writeaddr  : t_arr_TPROJ_58_ADDR  := (others => (others => '0'));
  signal TPROJ_58_mem_AV_din        : t_arr_TPROJ_58_DATA  := (others => (others => '0'));
  signal TPAR_70_mem_A_wea          : t_arr_TPAR_70_1b     := (others => '0');
  signal TPAR_70_mem_AV_writeaddr   : t_arr_TPAR_70_ADDR   := (others => (others => '0'));
  signal TPAR_70_mem_AV_din         : t_arr_TPAR_70_DATA   := (others => (others => '0'));
  signal VMPROJ_24_mem_A_wea        : t_arr_VMPROJ_24_1b   := (others => '0');
  signal VMPROJ_24_mem_AV_writeaddr : t_arr_VMPROJ_24_ADDR := (others => (others => '0'));
  signal VMPROJ_24_mem_AV_din       : t_arr_VMPROJ_24_DATA := (others => (others => '0'));
  signal AP_60_mem_A_wea            : t_arr_AP_60_1b       := (others => '0');
  signal AP_60_mem_AV_writeaddr     : t_arr_AP_60_ADDR     := (others => (others => '0'));
  signal AP_60_mem_AV_din           : t_arr_AP_60_DATA     := (others => (others => '0'));
  signal AP_58_mem_A_wea            : t_arr_AP_58_1b       := (others => '0');
  signal AP_58_mem_AV_writeaddr     : t_arr_AP_58_ADDR     := (others => (others => '0'));
  signal AP_58_mem_AV_din           : t_arr_AP_58_DATA     := (others => (others => '0'));
  signal CM_14_mem_A_wea            : t_arr_CM_14_1b       := (others => '0');
  signal CM_14_mem_AV_writeaddr     : t_arr_CM_14_ADDR     := (others => (others => '0'));
  signal CM_14_mem_AV_din           : t_arr_CM_14_DATA     := (others => (others => '0'));
  signal FM_52_mem_A_wea            : t_arr_FM_52_1b       := (others => '0');
  signal FM_52_mem_AV_writeaddr     : t_arr_FM_52_ADDR     := (others => (others => '0'));
  signal FM_52_mem_AV_din           : t_arr_FM_52_DATA     := (others => (others => '0'));
  signal BW_46_stream_AV_din        : t_arr_BW_46_DATA     := (others => (others => '0'));
  signal BW_46_stream_A_full_neg    : t_arr_BW_46_1b       := (others => '0');
  signal BW_46_stream_A_write       : t_arr_BW_46_1b       := (others => '0');
  signal TW_84_stream_AV_din        : t_arr_TW_84_DATA     := (others => (others => '0'));
  signal TW_84_stream_A_full_neg    : t_arr_TW_84_1b       := (others => '0');
  signal TW_84_stream_A_write       : t_arr_TW_84_1b       := (others => '0');

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

  VMSME_16_loop : for var in enum_VMSME_16 generate
  begin
    readVMSME_16 : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_VMSME&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => VMSME_DELAY*MAX_ENTRIES,
      RAM_WIDTH       => 16,
      NUM_PAGES       => 8,
      NUM_BINS        => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_VMSME_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      ADDR            => VMSME_16_mem_AV_writeaddr(var),
      DATA            => VMSME_16_mem_AV_din(var),
      START => open,
      WRITE_EN        => VMSME_16_mem_A_wea(var)
    );
  end generate VMSME_16_loop;

  VMSME_17_loop : for var in enum_VMSME_17 generate
  begin
    readVMSME_17 : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_VMSME&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => VMSME_DELAY*MAX_ENTRIES,
      RAM_WIDTH       => 17,
      NUM_PAGES       => 8,
      NUM_BINS        => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_VMSME_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      ADDR            => VMSME_17_mem_AV_writeaddr(var),
      DATA            => VMSME_17_mem_AV_din(var),
      START => open,
      WRITE_EN        => VMSME_17_mem_A_wea(var)
    );
  end generate VMSME_17_loop;

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
        FT_bx_out                  => FT_bx_out,
        FT_bx_out_vld              => FT_bx_out_vld,
        FT_done                    => FT_done,
        -- Input data
        AS_36_mem_A_wea            => AS_36_mem_A_wea,
        AS_36_mem_AV_writeaddr     => AS_36_mem_AV_writeaddr,
        AS_36_mem_AV_din           => AS_36_mem_AV_din,
        VMSME_16_mem_A_wea         => VMSME_16_mem_A_wea,
        VMSME_16_mem_AV_writeaddr  => VMSME_16_mem_AV_writeaddr,
        VMSME_16_mem_AV_din        => VMSME_16_mem_AV_din,
        VMSME_17_mem_A_wea         => VMSME_17_mem_A_wea,
        VMSME_17_mem_AV_writeaddr  => VMSME_17_mem_AV_writeaddr,
        VMSME_17_mem_AV_din        => VMSME_17_mem_AV_din,
        VMSTE_22_mem_A_wea         => VMSTE_22_mem_A_wea,
        VMSTE_22_mem_AV_writeaddr  => VMSTE_22_mem_AV_writeaddr,
        VMSTE_22_mem_AV_din        => VMSTE_22_mem_AV_din,
        VMSTE_16_mem_A_wea         => VMSTE_16_mem_A_wea,
        VMSTE_16_mem_AV_writeaddr  => VMSTE_16_mem_AV_writeaddr,
        VMSTE_16_mem_AV_din        => VMSTE_16_mem_AV_din,
        -- Output data
        BW_46_stream_AV_din        => BW_46_stream_AV_din,
        BW_46_stream_A_full_neg    => BW_46_stream_A_full_neg,
        BW_46_stream_A_write       => BW_46_stream_A_write,
        TW_84_stream_AV_din        => TW_84_stream_AV_din,
        TW_84_stream_A_full_neg    => TW_84_stream_A_full_neg,
        TW_84_stream_A_write       => TW_84_stream_A_write
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
        FT_bx_out                  => FT_bx_out,
        FT_bx_out_vld              => FT_bx_out_vld,
        FT_done                    => FT_done,
        -- Debug control signals
        TE_bx_out                  => TE_bx_out,
        TE_bx_out_vld              => TE_bx_out_vld,
        TE_done                    => TE_done,
        TC_bx_out                  => TC_bx_out,
        TC_bx_out_vld              => TC_bx_out_vld,
        TC_done                    => TC_done,
        PR_bx_out                  => PR_bx_out,
        PR_bx_out_vld              => PR_bx_out_vld,
        PR_done                    => PR_done,
        ME_bx_out                  => ME_bx_out,
        ME_bx_out_vld              => ME_bx_out_vld,
        ME_done                    => ME_done,
        MC_bx_out                  => MC_bx_out,
        MC_bx_out_vld              => MC_bx_out_vld,
        MC_done                    => MC_done,
        -- Input data
        AS_36_mem_A_wea            => AS_36_mem_A_wea,
        AS_36_mem_AV_writeaddr     => AS_36_mem_AV_writeaddr,
        AS_36_mem_AV_din           => AS_36_mem_AV_din,
        VMSME_16_mem_A_wea         => VMSME_16_mem_A_wea,
        VMSME_16_mem_AV_writeaddr  => VMSME_16_mem_AV_writeaddr,
        VMSME_16_mem_AV_din        => VMSME_16_mem_AV_din,
        VMSME_17_mem_A_wea         => VMSME_17_mem_A_wea,
        VMSME_17_mem_AV_writeaddr  => VMSME_17_mem_AV_writeaddr,
        VMSME_17_mem_AV_din        => VMSME_17_mem_AV_din,
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
        TPROJ_60_mem_A_wea         => TPROJ_60_mem_A_wea,
        TPROJ_60_mem_AV_writeaddr  => TPROJ_60_mem_AV_writeaddr,
        TPROJ_60_mem_AV_din        => TPROJ_60_mem_AV_din,
        TPROJ_58_mem_A_wea         => TPROJ_58_mem_A_wea,
        TPROJ_58_mem_AV_writeaddr  => TPROJ_58_mem_AV_writeaddr,
        TPROJ_58_mem_AV_din        => TPROJ_58_mem_AV_din,
        TPAR_70_mem_A_wea          => TPAR_70_mem_A_wea,
        TPAR_70_mem_AV_writeaddr   => TPAR_70_mem_AV_writeaddr,
        TPAR_70_mem_AV_din         => TPAR_70_mem_AV_din,
        VMPROJ_24_mem_A_wea        => VMPROJ_24_mem_A_wea,
        VMPROJ_24_mem_AV_writeaddr => VMPROJ_24_mem_AV_writeaddr,
        VMPROJ_24_mem_AV_din       => VMPROJ_24_mem_AV_din,
        AP_60_mem_A_wea            => AP_60_mem_A_wea,
        AP_60_mem_AV_writeaddr     => AP_60_mem_AV_writeaddr,
        AP_60_mem_AV_din           => AP_60_mem_AV_din,
        AP_58_mem_A_wea            => AP_58_mem_A_wea,
        AP_58_mem_AV_writeaddr     => AP_58_mem_AV_writeaddr,
        AP_58_mem_AV_din           => AP_58_mem_AV_din,
        CM_14_mem_A_wea            => CM_14_mem_A_wea,
        CM_14_mem_AV_writeaddr     => CM_14_mem_AV_writeaddr,
        CM_14_mem_AV_din           => CM_14_mem_AV_din,
        FM_52_mem_A_wea            => FM_52_mem_A_wea,
        FM_52_mem_AV_writeaddr     => FM_52_mem_AV_writeaddr,
        FM_52_mem_AV_din           => FM_52_mem_AV_din,
        -- Output data
        BW_46_stream_AV_din        => BW_46_stream_AV_din,
        BW_46_stream_A_full_neg    => BW_46_stream_A_full_neg,
        BW_46_stream_A_write       => BW_46_stream_A_write,
        TW_84_stream_AV_din        => TW_84_stream_AV_din,
        TW_84_stream_A_full_neg    => TW_84_stream_A_full_neg,
        TW_84_stream_A_write       => TW_84_stream_A_write
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

    TPROJ_60_loop : for var in enum_TPROJ_60 generate
    begin
      writeTPROJ_60 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_TPROJ_60&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 60,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => TPROJ_60_mem_AV_writeaddr(var),
        DATA      => TPROJ_60_mem_AV_din(var),
        WRITE_EN  => TPROJ_60_mem_A_wea(var),
        START     => TE_DONE,
        DONE      => TC_DONE
      );
    end generate TPROJ_60_loop;

    TPROJ_58_loop : for var in enum_TPROJ_58 generate
    begin
      writeTPROJ_58 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_TPROJ_58&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 58,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => TPROJ_58_mem_AV_writeaddr(var),
        DATA      => TPROJ_58_mem_AV_din(var),
        WRITE_EN  => TPROJ_58_mem_A_wea(var),
        START     => TE_DONE,
        DONE      => TC_DONE
      );
    end generate TPROJ_58_loop;

    TPAR_70_loop : for var in enum_TPAR_70 generate
    begin
      writeTPAR_70 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_TPAR_70&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 70,
        NUM_PAGES => 8
      )
      port map (
        CLK       => CLK,
        ADDR      => TPAR_70_mem_AV_writeaddr(var),
        DATA      => TPAR_70_mem_AV_din(var),
        WRITE_EN  => TPAR_70_mem_A_wea(var),
        START     => TE_DONE,
        DONE      => TC_DONE
      );
    end generate TPAR_70_loop;

    VMPROJ_24_loop : for var in enum_VMPROJ_24 generate
    begin
      writeVMPROJ_24 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_VMPROJ_24&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 24,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => VMPROJ_24_mem_AV_writeaddr(var),
        DATA      => VMPROJ_24_mem_AV_din(var),
        WRITE_EN  => VMPROJ_24_mem_A_wea(var),
        START     => TC_DONE,
        DONE      => PR_DONE
      );
    end generate VMPROJ_24_loop;

    AP_60_loop : for var in enum_AP_60 generate
    begin
      writeAP_60 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_AP_60&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 60,
        NUM_PAGES => 8
      )
      port map (
        CLK       => CLK,
        ADDR      => AP_60_mem_AV_writeaddr(var),
        DATA      => AP_60_mem_AV_din(var),
        WRITE_EN  => AP_60_mem_A_wea(var),
        START     => TC_DONE,
        DONE      => PR_DONE
      );
    end generate AP_60_loop;

    AP_58_loop : for var in enum_AP_58 generate
    begin
      writeAP_58 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_AP_58&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 58,
        NUM_PAGES => 8
      )
      port map (
        CLK       => CLK,
        ADDR      => AP_58_mem_AV_writeaddr(var),
        DATA      => AP_58_mem_AV_din(var),
        WRITE_EN  => AP_58_mem_A_wea(var),
        START     => TC_DONE,
        DONE      => PR_DONE
      );
    end generate AP_58_loop;

    CM_14_loop : for var in enum_CM_14 generate
    begin
      writeCM_14 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_CM_14&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 14,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => CM_14_mem_AV_writeaddr(var),
        DATA      => CM_14_mem_AV_din(var),
        WRITE_EN  => CM_14_mem_A_wea(var),
        START     => PR_DONE,
        DONE      => ME_DONE
      );
    end generate CM_14_loop;

    FM_52_loop : for var in enum_FM_52 generate
    begin
      writeFM_52 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_FM_52&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 52,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => FM_52_mem_AV_writeaddr(var),
        DATA      => FM_52_mem_AV_din(var),
        WRITE_EN  => FM_52_mem_A_wea(var),
        START     => ME_DONE,
        DONE      => MC_DONE
      );
    end generate FM_52_loop;

  end generate writeIntermediateRAMs;


  -- Write memories from end of chain.

  TW_84_loop : for var in enum_TW_84 generate
  begin
    writeTW_84 : entity work.FileWriterFIFO 
    generic map (
      FILE_NAME  => FILE_OUT_TW_84&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH  => 84
    )
    port map (
      CLK => CLK,
      START => MC_DONE,
      DONE => FT_DONE,
      WRITE_EN => TW_84_stream_A_write(var),
      FULL_NEG => TW_84_stream_A_full_neg(var),
      DATA => TW_84_stream_AV_din(var)
    );
  end generate TW_84_loop;

  BW_46_loop : for var in enum_BW_46 generate
  begin
    writeBW_46 : entity work.FileWriterFIFO 
    generic map (
      FILE_NAME  => FILE_OUT_BW_46&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH  => 46
    )
    port map (
      CLK => CLK,
      START => MC_DONE,
      DONE => FT_DONE,
      WRITE_EN => BW_46_stream_A_write(var),
      FULL_NEG => BW_46_stream_A_full_neg(var),
      DATA => BW_46_stream_AV_din(var)
    );
  end generate BW_46_loop;

  TF_464_loop : for var in enum_TW_84 generate
  begin
    writeTF_464 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME  => FILE_OUT_TF_464&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH  => 464
    )
    port map (
      CLK => CLK,
      START => MC_DONE,
      DONE => FT_DONE,
      WRITE_EN => TW_84_stream_A_write(var),
      FULL_NEG => TW_84_stream_A_full_neg(var),
      DATA => TW_84_stream_AV_din(var)&BW_46_stream_AV_din(L1L2_L3)&BW_46_stream_AV_din(L1L2_L4)&BW_46_stream_AV_din(L1L2_L5)&BW_46_stream_AV_din(L1L2_L6)&emptyDiskStub&emptyDiskStub&emptyDiskStub&emptyDiskStub
    );
  end generate TF_464_loop;


end behaviour;
