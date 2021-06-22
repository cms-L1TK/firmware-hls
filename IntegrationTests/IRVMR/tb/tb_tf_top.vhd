
--==========================================================================
-- CU Boulder
-------------------------------------------------------------------------------
--! @file
--! @brief Test bench for the track finding top using TextIO.
--! @author Robert Glein
--! @date 2020-05-18
--! Simplified & cleaned up
--! @author Ian Tomalin
--! @date 2021-05-30
--=============================================================================

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
architecture behavior of tb_tf_top is

  -- ########################### Constant Definitions ###########################
  -- ############ Please change the constants in this section ###################

  --=========================================================================
  -- Specify version of chain to run from TB:
  --    0 = SectorProcessor.vhd from python script.
  --    1 = SectorProcessorFull.vhd from python script (gives intermediate MemPrints).
  --    N.B. Change this also in makeProject.tcl !
  constant INST_TOP_TF   : integer := 1; 
  --=========================================================================

  constant CLK_PERIOD        : time    := 4 ns;       --! 250 MHz
  constant DEBUG             : boolean := false;      --! Debug off/on
  constant DL_DELAY       : integer := 0;          --! Number of BX delays (can be written early 8 pages) DO WE NEED A DELAY SINCE ONLY MEMORIES READ FROM FILE USES THEM?

  -- Paths of data files specified relative to Vivado project's xsim directory.
  -- e.g. IntegrationTests/IRVMR/script/Work/Work.sim/sim_1/behav/xsim/
  constant emDataDir  : string := "../../../../../../../../emData/MemPrints/";
  constant dataOutDir : string := "../../../../../dataOut/";

  -- File directories and the start of the file names that the memories have in common
  -- Input files
  constant FILE_IN_DL_39 : string := emDataDir&"InputStubs/Link_DL_";
  -- Output files
  constant FILE_OUT_IL_36 : string := dataOutDir&"IL_";
  constant FILE_OUT_AS_36 : string := dataOutDir&"AS_";
  constant FILE_OUT_VMSME_16 : string := dataOutDir&"VMSME_";
  constant FILE_OUT_VMSTE_22 : string := dataOutDir&"VMSTEI_";
  constant FILE_OUT_VMSTE_16 : string := dataOutDir&"VMSTEO_";
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_DL_debug : string := dataOutDir&"DL_";

  -- File name endings
  constant inputFileNameEnding : string := "_04.dat"; -- 04 specifies the nonant the testvectors represent
  constant outputFileNameEnding : string := ".txt";
  constant debugFileNameEnding : string := ".debug.txt";

  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk       : std_logic := '0';
  signal reset     : std_logic := '1';
  signal IR_start  : std_logic := '0';
  signal IR_idle   : std_logic := '0';
  signal IR_ready  : std_logic := '0';
  signal IR_bx_in  : std_logic_vector(2 downto 0) := (others => '1'); -- how many bx?
  signal IR_bx_out : std_logic_vector(2 downto 0) := (others => '1');
  signal IR_bx_out_vld : std_logic := '0';
  signal IR_done   : std_logic := '0';
  signal VMR_bx_out : std_logic_vector(2 downto 0) := (others => '1'); -- how many bx?
  signal VMR_bx_out_vld : std_logic := '0';
  signal VMR_done   : std_logic := '0';

  -- Signals matching ports of top-level VHDL
  signal DL_39_link_read             : t_arr_DL_39_1b       := (others => '0');
  signal DL_39_link_empty_neg        : t_arr_DL_39_1b       := (others => '0');
  signal DL_39_link_AV_dout          : t_arr_DL_39_DATA     := (others => (others => '0'));

  signal IL_36_mem_A_wea             : t_arr_IL_36_1b       := (others => '0');
  signal IL_36_mem_AV_writeaddr      : t_arr_IL_36_ADDR     := (others => (others => '0'));
  signal IL_36_mem_AV_din            : t_arr_IL_36_DATA     := (others => (others => '0'));
  
  signal AS_36_mem_A_enb             : t_arr_AS_36_1b       := (others => '0');
  signal AS_36_mem_AV_readaddr       : t_arr_AS_36_ADDR     := (others => (others => '0'));
  signal AS_36_mem_AV_dout           : t_arr_AS_36_DATA     := (others => (others => '0'));
  signal AS_36_mem_AAV_dout_nent     : t_arr_AS_36_NENT     := (others => (others => (others => '0')));
  signal VMSME_16_mem_A_enb          : t_arr_VMSME_16_1b    := (others => '0');
  signal VMSME_16_mem_AV_readaddr    : t_arr_VMSME_16_ADDR  := (others => (others => '0'));
  signal VMSME_16_mem_AV_dout        : t_arr_VMSME_16_DATA  := (others => (others => '0'));
  signal VMSME_16_mem_AAAV_dout_nent : t_arr_VMSME_16_NENT  := (others => (others => (others => (others => '0'))));
  signal VMSTE_16_mem_A_enb          : t_arr_VMSTE_16_1b    := (others => '0');
  signal VMSTE_16_mem_AV_readaddr    : t_arr_VMSTE_16_ADDR  := (others => (others => '0'));
  signal VMSTE_16_mem_AV_dout        : t_arr_VMSTE_16_DATA  := (others => (others => '0'));
  signal VMSTE_16_mem_AAAV_dout_nent : t_arr_VMSTE_16_NENT  := (others => (others => (others => (others => '0'))));
  signal VMSTE_22_mem_A_enb          : t_arr_VMSTE_22_1b    := (others => '0');
  signal VMSTE_22_mem_AV_readaddr    : t_arr_VMSTE_22_ADDR  := (others => (others => '0'));
  signal VMSTE_22_mem_AV_dout        : t_arr_VMSTE_22_DATA  := (others => (others => '0'));
  signal VMSTE_22_mem_AAV_dout_nent  : t_arr_VMSTE_22_NENT  := (others => (others => (others => '0')));

  -- Indicates that reading of DL of first event has started.
  signal START_FIRST_LINK : std_logic := '0';
  signal START_DL : t_arr_DL_39_1b := (others => '0');

begin

  --! @brief Make clock ---------------------------------------
  clk <= not clk after CLK_PERIOD/2;

  -- Get signals from input .txt files

  DL_39_loop : for var in enum_DL_39 generate
  begin
    readDL_39 : entity work.FileReaderToFIFO 
    generic map (
      FILE_NAME  => FILE_IN_DL_39&memory_enum_to_string(var)&inputFileNameEnding,
      DELAY      => DL_DELAY*MAX_ENTRIES,
      FIFO_WIDTH  => 39,
      DEBUG      => true,
      FILE_NAME_DEBUG => FILE_OUT_DL_debug&memory_enum_to_string(var)&debugFileNameEnding
    )
    port map (
      CLK => CLK,
      READ_SHIT => DL_39_link_read(var), -- needs to change??
      EMPTY_NEG => DL_39_link_empty_neg(var), -- needs to change??
      DATA => DL_39_link_AV_dout(var),
      START => START_DL(var)
    );
  end generate DL_39_loop;

  -- As all DL39 signals start together, take first one, to determine when 
  -- first event starts being read from the first link in the chain.
  START_FIRST_LINK <= START_DL(enum_DL_39'val(0));


  procStart : process(CLK)
    -- Process to start first module in chain & generate its BX counter input.
    -- Also releases reset flag.
    constant CLK_RESET : natural := 5; -- Any low number OK.
    variable CLK_COUNT : natural := 1;
    variable EVENT_COUNT : integer := 0;
    variable v_line : line; -- Line for debug
  begin

    if START_FIRST_LINK = '1' then
      if rising_edge(CLK) then

        IR_START <= '1';
        IR_BX_IN <= std_logic_vector(to_unsigned(EVENT_COUNT, IR_BX_IN'length));

        if (CLK_COUNT < MAX_ENTRIES) then
          CLK_COUNT := CLK_COUNT + 1;
        else
          CLK_COUNT := 1;
          EVENT_COUNT := EVENT_COUNT + 1;

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
        IR_start                   => IR_start,
        IR_bx_in                   => IR_bx_in,
        VMR_bx_out                 => VMR_bx_out,
        VMR_bx_out_vld             => VMR_bx_out_vld,
        VMR_done                   => VMR_done,
        -- Input data
        DL_39_link_AV_dout         => DL_39_link_AV_dout,
        DL_39_link_empty_neg       => DL_39_link_empty_neg,
        DL_39_link_read            => DL_39_link_read,
        -- Output data
        AS_36_mem_A_enb            => AS_36_mem_A_enb,
        AS_36_mem_AV_readaddr      => AS_36_mem_AV_readaddr,
        AS_36_mem_AV_dout          => AS_36_mem_AV_dout,
        VMSME_16_mem_A_enb         => VMSME_16_mem_A_enb,
        VMSME_16_mem_AV_readaddr   => VMSME_16_mem_AV_readaddr,
        VMSME_16_mem_AV_dout       => VMSME_16_mem_AV_dout,
        VMSME_16_mem_AAAV_dout_nent => VMSME_16_mem_AAAV_dout_nent,
        VMSTE_16_mem_A_enb         => VMSTE_16_mem_A_enb,
        VMSTE_16_mem_AV_readaddr   => VMSTE_16_mem_AV_readaddr,
        VMSTE_16_mem_AV_dout       => VMSTE_16_mem_AV_dout,
        VMSTE_16_mem_AAAV_dout_nent => VMSTE_16_mem_AAAV_dout_nent,
        VMSTE_22_mem_A_enb         => VMSTE_22_mem_A_enb,
        VMSTE_22_mem_AV_readaddr   => VMSTE_22_mem_AV_readaddr,
        VMSTE_22_mem_AV_dout       => VMSTE_22_mem_AV_dout,
        VMSTE_22_mem_AAV_dout_nent => VMSTE_22_mem_AAV_dout_nent
      );
  end generate sectorProc;


  sectorProcFull : if INST_TOP_TF = 1 generate
  begin
    uut : entity work.SectorProcessorFull
      port map(
        clk                        => clk,
        reset                      => reset,
        IR_start                   => IR_start,
        IR_bx_in                   => IR_bx_in,
        VMR_bx_out                 => VMR_bx_out,
        VMR_bx_out_vld             => VMR_bx_out_vld,
        VMR_done                   => VMR_done,
        -- Debug control signals
        IR_bx_out                  => IR_bx_out,
        IR_bx_out_vld              => IR_bx_out_vld,
        IR_done                    => IR_done,
        -- Input data
        DL_39_link_AV_dout         => DL_39_link_AV_dout,
        DL_39_link_empty_neg       => DL_39_link_empty_neg,
        DL_39_link_read            => DL_39_link_read,
        -- Debug output data
        IL_36_mem_A_wea            => IL_36_mem_A_wea,
        IL_36_mem_AV_writeaddr     => IL_36_mem_AV_writeaddr,
        IL_36_mem_AV_din           => IL_36_mem_AV_din,
        -- Output data
        AS_36_mem_A_enb            => AS_36_mem_A_enb,
        AS_36_mem_AV_readaddr      => AS_36_mem_AV_readaddr,
        AS_36_mem_AV_dout          => AS_36_mem_AV_dout,
        VMSME_16_mem_A_enb         => VMSME_16_mem_A_enb,
        VMSME_16_mem_AV_readaddr   => VMSME_16_mem_AV_readaddr,
        VMSME_16_mem_AV_dout       => VMSME_16_mem_AV_dout,
        VMSME_16_mem_AAAV_dout_nent => VMSME_16_mem_AAAV_dout_nent,
        VMSTE_16_mem_A_enb         => VMSTE_16_mem_A_enb,
        VMSTE_16_mem_AV_readaddr   => VMSTE_16_mem_AV_readaddr,
        VMSTE_16_mem_AV_dout       => VMSTE_16_mem_AV_dout,
        VMSTE_16_mem_AAAV_dout_nent => VMSTE_16_mem_AAAV_dout_nent,
        VMSTE_22_mem_A_enb         => VMSTE_22_mem_A_enb,
        VMSTE_22_mem_AV_readaddr   => VMSTE_22_mem_AV_readaddr,
        VMSTE_22_mem_AV_dout       => VMSTE_22_mem_AV_dout,
        VMSTE_22_mem_AAV_dout_nent => VMSTE_22_mem_AAV_dout_nent
      );
  end generate sectorProcFull;


  -- Write signals to output .txt files

  writeIntermediateRAMs : if INST_TOP_TF = 1 generate
  begin

    -- This writes signals going to intermediate memories in chain.

    IL_36_loop : for var in enum_IL_36 generate
    begin
      writeIL_36 : entity work.FileWriter 
      generic map (
        FILE_NAME  => FILE_OUT_IL_36&memory_enum_to_string(var)&outputFileNameEnding,
        RAM_WIDTH  => 36,
        NUM_PAGES  => 2
      )
      port map (
        CLK => CLK,
        ADDR => IL_36_mem_AV_writeaddr(var),
        DATA => IL_36_mem_AV_din(var),
        WRITE_EN => IL_36_mem_A_wea(var),
        START => IR_START,
        DONE => IR_DONE
      );
    end generate IL_36_loop;

  end generate writeIntermediateRAMs;


-- Write memories from end of chain.

  AS_36_loop : for var in enum_AS_36 generate
  begin
    writeAS_36 : entity work.FileWriterFromRAM 
    generic map (
      FILE_NAME  => FILE_OUT_AS_36&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH  => 36,
      NUM_PAGES  => 8
    )
    port map (
      CLK => CLK,
      DONE => VMR_DONE,
      NENT_ARR => AS_36_mem_AAV_dout_nent(var), -- always 0, will that cause issues in FileWriterFromRAM?
      ADDR => AS_36_mem_AV_readaddr(var),
      DATA => AS_36_mem_AV_dout(var),
      READ_EN => AS_36_mem_A_enb(var)
    );
  end generate AS_36_loop;

  VMSME_16_loop : for var in enum_VMSME_16 generate
  begin
    writeME_16 : entity work.FileWriterFromRAMBinned 
    generic map (
      FILE_NAME  => FILE_OUT_VMSME_16&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH  => 16,
      NUM_PAGES  => 8
    )
    port map (
      CLK => CLK,
      DONE => VMR_DONE,
      NENT_ARR => VMSME_16_mem_AAAV_dout_nent(var),
      ADDR => VMSME_16_mem_AV_readaddr(var),
      DATA => VMSME_16_mem_AV_dout(var),
      READ_EN => VMSME_16_mem_A_enb(var)
    );
  end generate VMSME_16_loop;

  VMSTE_22_loop : for var in enum_VMSTE_22 generate
  begin
    writeTE_22 : entity work.FileWriterFromRAM 
    generic map (
      FILE_NAME  => FILE_OUT_VMSTE_22&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH  => 22,
      NUM_PAGES  => 2
    )
    port map (
      CLK => CLK,
      DONE => VMR_DONE,
      NENT_ARR => VMSTE_22_mem_AAV_dout_nent(var),
      ADDR => VMSTE_22_mem_AV_readaddr(var),
      DATA => VMSTE_22_mem_AV_dout(var),
      READ_EN => VMSTE_22_mem_A_enb(var)
    );
  end generate VMSTE_22_loop;

  VMSTE_16_loop : for var in enum_VMSTE_16 generate
  begin
    writeTE_16 : entity work.FileWriterFromRAMBinned 
    generic map (
      FILE_NAME  => FILE_OUT_VMSTE_16&memory_enum_to_string(var)&outputFileNameEnding,
      RAM_WIDTH  => 16,
      NUM_PAGES  => 2
    )
    port map (
      CLK => CLK,
      DONE => VMR_DONE,
      NENT_ARR => VMSTE_16_mem_AAAV_dout_nent(var),
      ADDR => VMSTE_16_mem_AV_readaddr(var),
      DATA => VMSTE_16_mem_AV_dout(var),
      READ_EN => VMSTE_16_mem_A_enb(var)
    );
  end generate VMSTE_16_loop;

end behavior;
