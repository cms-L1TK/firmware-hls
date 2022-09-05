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
  constant INST_TOP_TF          : integer := 0;
  --=========================================================================

  constant CLK_PERIOD           : time    := 4 ns;       --! 250 MHz
  constant DEBUG                : boolean := false;      --! Debug off/on
  constant DL_DELAY             : integer := 0;          --! Number of BX delays

  -- Paths of data files specified relative to Vivado project's xsim directory.
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant memPrintsDir         : string := "../../../../../MemPrints/";
  constant dataOutDir           : string := "../../../../../dataOut/";

  -- File directories and the start of the file names that memories have in common
  -- Input files
  constant FILE_IN_DL           : string := memPrintsDir&"InputStubs/Link_DL_";
  -- Output files
  constant FILE_OUT_IL_36       : string := dataOutDir&"IL_";
  constant FILE_OUT_AS_36       : string := dataOutDir&"AS_";
  constant FILE_OUT_VMSME_16    : string := dataOutDir&"VMSME_";
  constant FILE_OUT_VMSME_17    : string := dataOutDir&"VMSME_";
  constant FILE_OUT_VMSTE_22    : string := dataOutDir&"VMSTE_";
  constant FILE_OUT_VMSTE_23    : string := dataOutDir&"VMSTE_";
  constant FILE_OUT_VMSTE_16    : string := dataOutDir&"VMSTE_";
  constant FILE_OUT_VMSTE_17    : string := dataOutDir&"VMSTE_";
  constant FILE_OUT_SP_14       : string := dataOutDir&"SP_";
  constant FILE_OUT_TPROJ_58    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPROJ_60    : string := dataOutDir&"TPROJ_";
  constant FILE_OUT_TPAR_70     : string := dataOutDir&"TPAR_";
  constant FILE_OUT_VMPROJ_24   : string := dataOutDir&"VMPROJ_";
  constant FILE_OUT_AP_60       : string := dataOutDir&"AP_";
  constant FILE_OUT_AP_58       : string := dataOutDir&"AP_";
  constant FILE_OUT_CM_14       : string := dataOutDir&"CM_";
  constant FILE_OUT_FM_52       : string := dataOutDir&"FM_";
  constant FILE_OUT_TW_84       : string := dataOutDir&"TW_";
  constant FILE_OUT_BW_46       : string := dataOutDir&"BW_";
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_DL_debug    : string := dataOutDir&"DL_";

  -- File name endings
  constant inputFileNameEnding  : string := "_04.dat"; -- 04 specifies the nonant/sector the testvectors represent
  constant outputFileNameEnding : string := ".txt";
  constant debugFileNameEnding  : string := ".debug.txt";

  -- A bodge for TrackBuilder to write TF_464 concatenated track+stub data.
  -- (Needed to compare with emData/).
  constant FILE_OUT_TF_464      : string := dataOutDir&"TF_";
  -- Empty field in the output from FT_L1L2 corresponding to disk matches
  constant emptyDiskStub : std_logic_vector(48 downto 0) := (others => '0');

  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk                        : std_logic := '0';
  signal reset                      : std_logic := '1';
  signal IR_start                   : std_logic := '0';
  signal IR_idle                    : std_logic := '0';
  signal IR_ready                   : std_logic := '0';
  signal IR_bx_in                   : std_logic_vector(2 downto 0) := (others => '1');
  signal IR_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal IR_bx_out_vld              : std_logic := '0';
  signal IR_done                    : std_logic := '0';
  signal VMR_bx_out                 : std_logic_vector(2 downto 0) := (others => '1');
  signal VMR_bx_out_vld             : std_logic := '0';
  signal VMR_done                   : std_logic := '0';
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
  signal DL_39_link_read            : t_arr_DL_39_1b       := (others => '0');
  signal DL_39_link_empty_neg       : t_arr_DL_39_1b       := (others => '0');
  signal DL_39_link_AV_dout         : t_arr_DL_39_DATA     := (others => (others => '0'));
  signal IL_36_mem_A_wea            : t_arr_IL_36_1b       := (others => '0');
  signal IL_36_mem_AV_writeaddr     : t_arr_IL_36_ADDR     := (others => (others => '0'));
  signal IL_36_mem_AV_din           : t_arr_IL_36_DATA     := (others => (others => '0'));
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
  signal VMSTE_23_mem_A_wea         : t_arr_VMSTE_23_1b    := (others => '0');
  signal VMSTE_23_mem_AV_writeaddr  : t_arr_VMSTE_23_ADDR  := (others => (others => '0'));
  signal VMSTE_23_mem_AV_din        : t_arr_VMSTE_23_DATA  := (others => (others => '0'));
  signal VMSTE_16_mem_A_wea         : t_arr_VMSTE_16_1b    := (others => '0');
  signal VMSTE_16_mem_AV_writeaddr  : t_arr_VMSTE_16_ADDR  := (others => (others => '0'));
  signal VMSTE_16_mem_AV_din        : t_arr_VMSTE_16_DATA  := (others => (others => '0'));
  signal VMSTE_17_mem_A_wea         : t_arr_VMSTE_17_1b    := (others => '0');
  signal VMSTE_17_mem_AV_writeaddr  : t_arr_VMSTE_17_ADDR  := (others => (others => '0'));
  signal VMSTE_17_mem_AV_din        : t_arr_VMSTE_17_DATA  := (others => (others => '0'));
  signal SP_14_mem_A_wea            : t_arr_SP_14_1b       := (others => '0');
  signal SP_14_mem_AV_writeaddr     : t_arr_SP_14_ADDR     := (others => (others => '0'));
  signal SP_14_mem_AV_din           : t_arr_SP_14_DATA     := (others => (others => '0'));
  signal TPROJ_58_mem_A_wea         : t_arr_TPROJ_58_1b    := (others => '0');
  signal TPROJ_58_mem_AV_writeaddr  : t_arr_TPROJ_58_ADDR  := (others => (others => '0'));
  signal TPROJ_58_mem_AV_din        : t_arr_TPROJ_58_DATA  := (others => (others => '0'));
  signal TPROJ_60_mem_A_wea         : t_arr_TPROJ_60_1b    := (others => '0');
  signal TPROJ_60_mem_AV_writeaddr  : t_arr_TPROJ_60_ADDR  := (others => (others => '0'));
  signal TPROJ_60_mem_AV_din        : t_arr_TPROJ_60_DATA  := (others => (others => '0'));
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
  signal TW_84_stream_A_write       : t_arr_TW_84_1b       := (others => '0');
  signal TW_84_stream_A_full_neg    : t_arr_TW_84_1b       := (others => '0');
  signal TW_84_stream_AV_din        : t_arr_TW_84_DATA     := (others => (others => '0'));
  signal BW_46_stream_A_write       : t_arr_BW_46_1b       := (others => '0');
  signal BW_46_stream_A_full_neg    : t_arr_BW_46_1b       := (others => '0');
  signal BW_46_stream_AV_din        : t_arr_BW_46_DATA     := (others => (others => '0'));

  -- Indicates that reading of DL of first event has started.
  signal START_FIRST_LINK : std_logic := '0';
  signal START_DL : t_arr_DL_39_1b := (others => '0');

begin

--! @brief Make clock ---------------------------------------
  clk <= not clk after CLK_PERIOD/2;

  -- Get signals from input .txt files

  DL_39_loop : for var in enum_DL_39 generate
  begin
    readDL_39 : entity work.FileReaderFIFO
  generic map (
      FILE_NAME       => FILE_IN_DL&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => DL_DELAY*MAX_ENTRIES,
      FIFO_WIDTH      => 39,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_DL_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      READ_EN         => DL_39_link_read(var),
      DATA            => DL_39_link_AV_dout(var),
      START           => START_DL(var),
      EMPTY_NEG       => DL_39_link_empty_neg(var)
    );
  end generate DL_39_loop;

  -- As all DL signals start together, take first one, to determine when
  -- first event starts being read from the first link in the chain.
  START_FIRST_LINK <= START_DL(enum_DL_39'val(0));

  procStart : process(CLK)
    -- Process to start first module in chain & generate its BX counter input.
    -- Also releases reset flag.
    constant CLK_RESET : natural := 5; -- Any low number OK.
    variable CLK_COUNT : natural := MAX_ENTRIES - CLK_RESET;
    variable EVENT_COUNT : integer := -1;
    variable v_line : line; -- Line for debug
  begin

    if START_FIRST_LINK = '1' then
      if rising_edge(CLK) then
        if (CLK_COUNT < MAX_ENTRIES) then
          CLK_COUNT := CLK_COUNT + 1;
        else
          CLK_COUNT := 1;
          EVENT_COUNT := EVENT_COUNT + 1;

          IR_START <= '1';
          IR_BX_IN <= std_logic_vector(to_unsigned(EVENT_COUNT, IR_BX_IN'length));

          write(v_line, string'("=== Processing event ")); write(v_line,EVENT_COUNT); write(v_line, string'(" at SIM time ")); write(v_line, NOW); writeline(output, v_line);
        end if;
        -- Releae
        if (CLK_COUNT = MAX_ENTRIES) then
          RESET <= '0';
        end if;
      end if;
    end if;
  end process procStart;

  -- ########################### Instantiation ###########################
  -- Instantiate the Unit Under Test (UUT)

  assert (INST_TOP_TF = 0) report "SectorProcessorFull is not yet supported." severity failure;

  sectorProc : if INST_TOP_TF = 0 generate
  begin
    uut : entity work.SectorProcessor
      port map(
        clk                        => clk,
        reset                      => reset,
        IR_start                   => IR_start,
        IR_bx_in                   => IR_bx_in,
        FT_bx_out                  => FT_bx_out,
        FT_bx_out_vld              => FT_bx_out_vld,
        FT_done                    => FT_done,
        -- Input data
        DL_39_link_AV_dout         => DL_39_link_AV_dout,
        DL_39_link_empty_neg       => DL_39_link_empty_neg,
        DL_39_link_read            => DL_39_link_read,
        -- Output data
        TW_84_stream_AV_din        => TW_84_stream_AV_din,
        TW_84_stream_A_full_neg    => TW_84_stream_A_full_neg,
        TW_84_stream_A_write       => TW_84_stream_A_write,
        BW_46_stream_AV_din        => BW_46_stream_AV_din,
        BW_46_stream_A_full_neg    => BW_46_stream_A_full_neg,
        BW_46_stream_A_write       => BW_46_stream_A_write
      );
  end generate sectorProc;

  -- Write memories from end of chain.

  TW_84_loop : for var in enum_TW_84 generate
  begin
    writeTW_84 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_TW_84&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH=> 84
    )
    port map (
      CLK       => CLK,
      DONE      => FT_DONE,
      WRITE_EN  => TW_84_stream_A_write(var),
      FULL_NEG  => TW_84_stream_A_full_neg(var),
      DATA      => TW_84_stream_AV_din(var)
    );
  end generate TW_84_loop;

  -- A bodge for TrackBuilder to write TF_464 concatenated track+stub data.
  -- (Needed to compare with emData/).
  TF_464_loop : for var in enum_TW_84 generate
  begin
    writeTF_464 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME  => FILE_OUT_TF_464&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH  => 464
    )
    port map (
      CLK => CLK,
      DONE => FT_DONE,
      WRITE_EN => TW_84_stream_A_write(var),
      FULL_NEG => TW_84_stream_A_full_neg(var),
      DATA => TW_84_stream_AV_din(var)&BW_46_stream_AV_din(L1L2_L3)&BW_46_stream_AV_din(L1L2_L4)&BW_46_stream_AV_din
(L1L2_L5)&BW_46_stream_AV_din(L1L2_L6)&emptyDiskStub&emptyDiskStub&emptyDiskStub&emptyDiskStub
    );
  end generate TF_464_loop;

  BW_46_loop : for var in enum_BW_46 generate
  begin
    writeBW_46 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK,
      DONE      => FT_DONE,
      WRITE_EN  => BW_46_stream_A_write(var),
      FULL_NEG  => BW_46_stream_A_full_neg(var),
      DATA      => BW_46_stream_AV_din(var)
    );
  end generate BW_46_loop;


end behaviour;
