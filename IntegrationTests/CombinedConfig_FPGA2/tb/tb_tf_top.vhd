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
  constant VMSME_DELAY          : integer := 1;          --! Number of BX delays
  constant MPAR_DELAY           : integer := 0;          --! Number of BX delays

  -- Paths of data files specified relative to Vivado project's xsim directory.
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant memPrintsDir         : string := "../../../../../MemPrints/";
  constant dataOutDir           : string := "../../../../../dataOut/";

  -- File directories and the start of the file names that memories have in common
  -- Input files
  constant FILE_IN_AS           : string := memPrintsDir&"Stubs/AllStubs_AS_";
  constant FILE_IN_VMSME        : string := memPrintsDir&"VMStubsME/VMStubs_VMSME_";
  constant FILE_IN_MPAR         : string := memPrintsDir&"TrackletParameters/TrackletParameters_MPAR_";
  -- Output files
  constant FILE_OUT_MPROJ_60    : string := dataOutDir&"MPROJ_";
  constant FILE_OUT_MPROJ_58    : string := dataOutDir&"MPROJ_";
  constant FILE_OUT_MPROJ_59    : string := dataOutDir&"MPROJ_";
  constant FILE_OUT_FM_52       : string := dataOutDir&"FM_";
  constant FILE_OUT_FM_55       : string := dataOutDir&"FM_";
  constant FILE_OUT_TW_98       : string := dataOutDir&"TW_";
  constant FILE_OUT_DW_49       : string := dataOutDir&"DW_";
  constant FILE_OUT_BW_46       : string := dataOutDir&"BW_";
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_AS_debug    : string := dataOutDir&"AS_";
  constant FILE_OUT_VMSME_debug : string := dataOutDir&"VMSME_";
  constant FILE_OUT_MPAR_debug  : string := dataOutDir&"MPAR_";

  -- File name endings
  constant inputFileNameEnding  : string := "_04.dat"; -- 04 specifies the nonant/sector the testvectors represent
  constant outputFileNameEnding : string := ".txt";
  constant debugFileNameEnding  : string := ".debug.txt";

  -- A bodge for TrackBuilder to write TF concatenated track+stub data.
  -- (Needed to compare with emData/).
  constant FILE_OUT_TF          : string := dataOutDir&"TF_";
  -- Empty field in the output from barrel-only TrackBuilders corresponding to
  -- disk matches
  constant emptyDiskStub : std_logic_vector(48 downto 0) := (others => '0');

  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk                        : std_logic := '0';
  signal reset                      : std_logic := '1';
  signal PC_start                   : std_logic := '0';
  signal PC_idle                    : std_logic := '0';
  signal PC_ready                   : std_logic := '0';
  signal PC_bx_in                   : std_logic_vector(2 downto 0) := (others => '1');
  signal PC_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal PC_bx_out_vld              : std_logic := '0';
  signal PC_done                    : std_logic := '0';
  signal MP_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal MP_bx_out_vld              : std_logic := '0';
  signal MP_done                    : std_logic := '0';
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
  signal MPAR_70_mem_A_wea          : t_arr_MPAR_70_1b     := (others => '0');
  signal MPAR_70_mem_AV_writeaddr   : t_arr_MPAR_70_ADDR   := (others => (others => '0'));
  signal MPAR_70_mem_AV_din         : t_arr_MPAR_70_DATA   := (others => (others => '0'));
  signal MPROJ_60_mem_A_wea         : t_arr_MPROJ_60_1b    := (others => '0');
  signal MPROJ_60_mem_AV_writeaddr  : t_arr_MPROJ_60_ADDR  := (others => (others => '0'));
  signal MPROJ_60_mem_AV_din        : t_arr_MPROJ_60_DATA  := (others => (others => '0'));
  signal MPROJ_58_mem_A_wea         : t_arr_MPROJ_58_1b    := (others => '0');
  signal MPROJ_58_mem_AV_writeaddr  : t_arr_MPROJ_58_ADDR  := (others => (others => '0'));
  signal MPROJ_58_mem_AV_din        : t_arr_MPROJ_58_DATA  := (others => (others => '0'));
  signal MPROJ_59_mem_A_wea         : t_arr_MPROJ_59_1b    := (others => '0');
  signal MPROJ_59_mem_AV_writeaddr  : t_arr_MPROJ_59_ADDR  := (others => (others => '0'));
  signal MPROJ_59_mem_AV_din        : t_arr_MPROJ_59_DATA  := (others => (others => '0'));
  signal FM_52_mem_A_wea            : t_arr_FM_52_1b       := (others => '0');
  signal FM_52_mem_AV_writeaddr     : t_arr_FM_52_ADDR     := (others => (others => '0'));
  signal FM_52_mem_AV_din           : t_arr_FM_52_DATA     := (others => (others => '0'));
  signal FM_55_mem_A_wea            : t_arr_FM_55_1b       := (others => '0');
  signal FM_55_mem_AV_writeaddr     : t_arr_FM_55_ADDR     := (others => (others => '0'));
  signal FM_55_mem_AV_din           : t_arr_FM_55_DATA     := (others => (others => '0'));
  signal TW_98_stream_A_write       : t_arr_TW_98_1b       := (others => '0');
  signal TW_98_stream_A_full_neg    : t_arr_TW_98_1b       := (others => '0');
  signal TW_98_stream_AV_din        : t_arr_TW_98_DATA     := (others => (others => '0'));
  signal DW_49_stream_A_write       : t_arr_DW_49_1b       := (others => '0');
  signal DW_49_stream_A_full_neg    : t_arr_DW_49_1b       := (others => '0');
  signal DW_49_stream_AV_din        : t_arr_DW_49_DATA     := (others => (others => '0'));
  signal BW_46_stream_A_write       : t_arr_BW_46_1b       := (others => '0');
  signal BW_46_stream_A_full_neg    : t_arr_BW_46_1b       := (others => '0');
  signal BW_46_stream_AV_din        : t_arr_BW_46_DATA     := (others => (others => '0'));

  -- Indicates that writing of the initial memories of the first event has started.
  signal START_FIRST_WRITE : std_logic := '0';
  signal START_MPAR : t_arr_MPAR_70_1b := (others => '0');

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
      NUM_PAGES       => 4,
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
      NUM_PAGES       => 4,
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

  MPAR_70_loop : for var in enum_MPAR_70 generate
  begin
    readMPAR_70 : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY           => MPAR_DELAY*MAX_ENTRIES,
      RAM_WIDTH       => 70,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK             => CLK,
      ADDR            => MPAR_70_mem_AV_writeaddr(var),
      DATA            => MPAR_70_mem_AV_din(var),
      START           => START_MPAR(var),
      WRITE_EN        => MPAR_70_mem_A_wea(var)
    );
  end generate MPAR_70_loop;

  -- As all MPAR signals start together, take first one, to determine when
  -- first event starts being written to first memory in chain.
  START_FIRST_WRITE <= START_MPAR(enum_MPAR_70'val(0));

  procStart : process(CLK)
    -- Process to start first module in chain & generate its BX counter input.
    -- Also releases reset flag.
    constant CLK_RESET : natural := 5; -- Any low number OK.
    variable CLK_COUNT : natural := 1;
    variable EVENT_COUNT : integer := -1;
    variable v_line : line; -- Line for debug
  begin

    if START_FIRST_WRITE = '1' then
      if rising_edge(CLK) then
        if (CLK_COUNT < MAX_ENTRIES) then
          CLK_COUNT := CLK_COUNT + 1;
        else
          CLK_COUNT := 1;
          EVENT_COUNT := EVENT_COUNT + 1;

          -- PC should start one TM period after time when first event starting being 
          -- written to first memory in chain, as it takes this long to write full event.
          PC_START <= '1';
          PC_BX_IN <= std_logic_vector(to_unsigned(EVENT_COUNT, PC_BX_IN'length));

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
        PC_start                   => PC_start,
        PC_bx_in                   => PC_bx_in,
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
        MPAR_70_mem_A_wea          => MPAR_70_mem_A_wea,
        MPAR_70_mem_AV_writeaddr   => MPAR_70_mem_AV_writeaddr,
        MPAR_70_mem_AV_din         => MPAR_70_mem_AV_din,
        -- Output data
        TW_98_stream_AV_din        => TW_98_stream_AV_din,
        TW_98_stream_A_full_neg    => TW_98_stream_A_full_neg,
        TW_98_stream_A_write       => TW_98_stream_A_write,
        DW_49_stream_AV_din        => DW_49_stream_AV_din,
        DW_49_stream_A_full_neg    => DW_49_stream_A_full_neg,
        DW_49_stream_A_write       => DW_49_stream_A_write,
        BW_46_stream_AV_din        => BW_46_stream_AV_din,
        BW_46_stream_A_full_neg    => BW_46_stream_A_full_neg,
        BW_46_stream_A_write       => BW_46_stream_A_write
      );
  end generate sectorProc;

  sectorProcFull : if INST_TOP_TF = 1 generate
  begin
    uut : entity work.SectorProcessorFull
      port map(
        clk                        => clk,
        reset                      => reset,
        PC_start                   => PC_start,
        PC_bx_in                   => PC_bx_in,
        FT_bx_out                  => FT_bx_out,
        FT_bx_out_vld              => FT_bx_out_vld,
        FT_done                    => FT_done,
        -- Debug control signals
        PC_bx_out                  => PC_bx_out,
        PC_bx_out_vld              => PC_bx_out_vld,
        PC_done                    => PC_done,
        MP_bx_out                  => MP_bx_out,
        MP_bx_out_vld              => MP_bx_out_vld,
        MP_done                    => MP_done,
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
        MPAR_70_mem_A_wea          => MPAR_70_mem_A_wea,
        MPAR_70_mem_AV_writeaddr   => MPAR_70_mem_AV_writeaddr,
        MPAR_70_mem_AV_din         => MPAR_70_mem_AV_din,
        -- Debug output data
        MPROJ_60_mem_A_wea         => MPROJ_60_mem_A_wea,
        MPROJ_60_mem_AV_writeaddr  => MPROJ_60_mem_AV_writeaddr,
        MPROJ_60_mem_AV_din        => MPROJ_60_mem_AV_din,
        MPROJ_58_mem_A_wea         => MPROJ_58_mem_A_wea,
        MPROJ_58_mem_AV_writeaddr  => MPROJ_58_mem_AV_writeaddr,
        MPROJ_58_mem_AV_din        => MPROJ_58_mem_AV_din,
        MPROJ_59_mem_A_wea         => MPROJ_59_mem_A_wea,
        MPROJ_59_mem_AV_writeaddr  => MPROJ_59_mem_AV_writeaddr,
        MPROJ_59_mem_AV_din        => MPROJ_59_mem_AV_din,
        FM_52_mem_A_wea            => FM_52_mem_A_wea,
        FM_52_mem_AV_writeaddr     => FM_52_mem_AV_writeaddr,
        FM_52_mem_AV_din           => FM_52_mem_AV_din,
        FM_55_mem_A_wea            => FM_55_mem_A_wea,
        FM_55_mem_AV_writeaddr     => FM_55_mem_AV_writeaddr,
        FM_55_mem_AV_din           => FM_55_mem_AV_din,
        -- Output data
        TW_98_stream_AV_din        => TW_98_stream_AV_din,
        TW_98_stream_A_full_neg    => TW_98_stream_A_full_neg,
        TW_98_stream_A_write       => TW_98_stream_A_write,
        DW_49_stream_AV_din        => DW_49_stream_AV_din,
        DW_49_stream_A_full_neg    => DW_49_stream_A_full_neg,
        DW_49_stream_A_write       => DW_49_stream_A_write,
        BW_46_stream_AV_din        => BW_46_stream_AV_din,
        BW_46_stream_A_full_neg    => BW_46_stream_A_full_neg,
        BW_46_stream_A_write       => BW_46_stream_A_write
      );
  end generate sectorProcFull;

  -- Write signals to output .txt files

  writeIntermediateRAMs : if INST_TOP_TF = 1 generate
  begin

    -- This writes signals going to intermediate memories in chain.

    MPROJ_60_loop : for var in enum_MPROJ_60 generate
    begin
      writeMPROJ_60 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_MPROJ_60&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 60,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => MPROJ_60_mem_AV_writeaddr(var),
        DATA      => MPROJ_60_mem_AV_din(var),
        WRITE_EN  => MPROJ_60_mem_A_wea(var),
        START     => PC_START,
        DONE      => PC_DONE
      );
    end generate MPROJ_60_loop;

    MPROJ_58_loop : for var in enum_MPROJ_58 generate
    begin
      writeMPROJ_58 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_MPROJ_58&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 58,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => MPROJ_58_mem_AV_writeaddr(var),
        DATA      => MPROJ_58_mem_AV_din(var),
        WRITE_EN  => MPROJ_58_mem_A_wea(var),
        START     => PC_START,
        DONE      => PC_DONE
      );
    end generate MPROJ_58_loop;

    MPROJ_59_loop : for var in enum_MPROJ_59 generate
    begin
      writeMPROJ_59 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_MPROJ_59&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 59,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => MPROJ_59_mem_AV_writeaddr(var),
        DATA      => MPROJ_59_mem_AV_din(var),
        WRITE_EN  => MPROJ_59_mem_A_wea(var),
        START     => PC_START,
        DONE      => PC_DONE
      );
    end generate MPROJ_59_loop;

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
        START     => PC_DONE,
        DONE      => MP_DONE
      );
    end generate FM_52_loop;

    FM_55_loop : for var in enum_FM_55 generate
    begin
      writeFM_55 : entity work.FileWriter
      generic map (
        FILE_NAME => FILE_OUT_FM_55&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH => 55,
        NUM_PAGES => 2
      )
      port map (
        CLK       => CLK,
        ADDR      => FM_55_mem_AV_writeaddr(var),
        DATA      => FM_55_mem_AV_din(var),
        WRITE_EN  => FM_55_mem_A_wea(var),
        START     => PC_DONE,
        DONE      => MP_DONE
      );
    end generate FM_55_loop;

  end generate writeIntermediateRAMs;


  -- Write memories from end of chain.

  TW_98_loop : for var in enum_TW_98 generate
  begin
    writeTW_98 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_TW_98&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH=> 98
    )
    port map (
      CLK       => CLK,
      DONE      => FT_DONE,
      WRITE_EN  => TW_98_stream_A_write(var),
      FULL_NEG  => TW_98_stream_A_full_neg(var),
      DATA      => TW_98_stream_AV_din(var)
    );
  end generate TW_98_loop;

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L1L2.
  -- (Needed to compare with emData/).
  writeTF_L1L2_464 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(L1L2)&outputFileNameEnding,
    FIFO_WIDTH  => 478
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_98_stream_A_write(L1L2),
    FULL_NEG => TW_98_stream_A_full_neg(L1L2),
    DATA => TW_98_stream_AV_din(L1L2)&BW_46_stream_AV_din(L1L2_L3)&BW_46_stream_AV_din(L1L2_L4)&BW_46_stream_AV_din(L1L2_L5)&BW_46_stream_AV_din(L1L2_L6)&emptyDiskStub&emptyDiskStub&emptyDiskStub&emptyDiskStub
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L2L3.
  -- (Needed to compare with emData/).
  writeTF_L2L3_418 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(L2L3)&outputFileNameEnding,
    FIFO_WIDTH  => 432
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_98_stream_A_write(L2L3),
    FULL_NEG => TW_98_stream_A_full_neg(L2L3),
    DATA => TW_98_stream_AV_din(L2L3)&BW_46_stream_AV_din(L2L3_L1)&BW_46_stream_AV_din(L2L3_L4)&BW_46_stream_AV_din(L2L3_L5)&emptyDiskStub&emptyDiskStub&emptyDiskStub&emptyDiskStub
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L3L4.
  -- (Needed to compare with emData/).
  writeTF_L3L4_366 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(L3L4)&outputFileNameEnding,
    FIFO_WIDTH  => 380
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_98_stream_A_write(L3L4),
    FULL_NEG => TW_98_stream_A_full_neg(L3L4),
    DATA => TW_98_stream_AV_din(L3L4)&BW_46_stream_AV_din(L3L4_L1)&BW_46_stream_AV_din(L3L4_L2)&BW_46_stream_AV_din(L3L4_L5)&BW_46_stream_AV_din(L3L4_L6)&emptyDiskStub&emptyDiskStub
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L5L6.
  -- (Needed to compare with emData/).
  writeTF_L5L6_268 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(L5L6)&outputFileNameEnding,
    FIFO_WIDTH  => 282
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_98_stream_A_write(L5L6),
    FULL_NEG => TW_98_stream_A_full_neg(L5L6),
    DATA => TW_98_stream_AV_din(L5L6)&BW_46_stream_AV_din(L5L6_L1)&BW_46_stream_AV_din(L5L6_L2)&BW_46_stream_AV_din(L5L6_L3)&BW_46_stream_AV_din(L5L6_L4)
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L1L2.
  -- (Needed to compare with emData/).
  writeTF_D1D2_277 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(D1D2)&outputFileNameEnding,
    FIFO_WIDTH  => 277
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_84_stream_A_write(D1D2),
    FULL_NEG => TW_84_stream_A_full_neg(D1D2),
    DATA => TW_84_stream_AV_din(D1D2)&BW_46_stream_AV_din(D1D2_L1)&BW_49_stream_AV_din(D1D2_D3)&BW_49_stream_AV_din(D1D2_D4)&BW_49_stream_AV_din(D1D2_D5)
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L1L2.
  -- (Needed to compare with emData/).
  writeTF_D3D4_277 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(D3D4)&outputFileNameEnding,
    FIFO_WIDTH  => 277
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_84_stream_A_write(D3D4),
    FULL_NEG => TW_84_stream_A_full_neg(D3D4),
    DATA => TW_84_stream_AV_din(D3D4)&BW_46_stream_AV_din(D3D4_L1)&BW_49_stream_AV_din(D3D4_D1)&BW_49_stream_AV_din(D3D4_D2)&BW_49_stream_AV_din(D3D4_D5)
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L1L2.
  -- (Needed to compare with emData/).
  writeTF_L1D1_326 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(L1D1)&outputFileNameEnding,
    FIFO_WIDTH  => 326
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_84_stream_A_write(L1D1),
    FULL_NEG => TW_84_stream_A_full_neg(L1D1),
    DATA => TW_84_stream_AV_din(L1D1)&BW_49_stream_AV_din(L1D1_D2)&BW_49_stream_AV_din(L1D1_D3)&BW_49_stream_AV_din(L1D1_D4)&BW_49_stream_AV_din(L1D1_D5)
  );

  -- A bodge for TrackBuilder to write TF concatenated track+stub data for L1L2.
  -- (Needed to compare with emData/).
  writeTF_L2D1_326 : entity work.FileWriterFIFO
  generic map (
    FILE_NAME  => FILE_OUT_TF&memory_enum_to_string(L2D1)&outputFileNameEnding,
    FIFO_WIDTH  => 326
  )
  port map (
    CLK => CLK,
    DONE => FT_DONE,
    WRITE_EN => TW_84_stream_A_write(L2D1),
    FULL_NEG => TW_84_stream_A_full_neg(L2D1),
    DATA => TW_84_stream_AV_din(L2D1)&BW_46_stream_AV_din(L2D1_L1)&BW_49_stream_AV_din(L2D1_D2)&BW_49_stream_AV_din(L2D1_D3)&BW_49_stream_AV_din(L2D1_D4)&BW_49_stream_AV_din(L2D1_D5)
  );

  DW_49_loop : for var in enum_DW_49 generate
  begin
    writeDW_49 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&memory_enum_to_string(var)&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK,
      DONE      => FT_DONE,
      WRITE_EN  => DW_49_stream_A_write(var),
      FULL_NEG  => DW_49_stream_A_full_neg(var),
      DATA      => DW_49_stream_AV_din(var)
    );
  end generate DW_49_loop;

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
