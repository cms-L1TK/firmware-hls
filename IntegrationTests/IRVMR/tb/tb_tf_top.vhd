
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
  -- ########################### Types ###########################
  -- Define type of array of strings for input/output file names.
  type t_str_arr_DL_39    is array(enum_DL_39)     of string(1 to 79);   -- WHAT HAPPENS IF THE STRINGS ARE NOT THE SAME LENGTH
  type t_str_arr_IL_36    is array(enum_IL_36)     of string(1 to 92);   -- WHAT ARE THESE NUMBERS??? Seems to be number of characters for emdata+directory
  type t_str_arr_AS_36    is array(enum_AS_36)     of string(1 to 74);
  type t_str_arr_VMSME_16 is array(enum_VMSME_16)  of string(1 to 81);
  type t_str_arr_VMSTE_22 is array(enum_VMSTE_22)  of string(1 to 81);
  type t_str_arr_VMSTE_16 is array(enum_VMSTE_16)  of string(1 to 81);


  -- Define type of array of strings for debug output file names. 
  type t_str_arr_DL_39_debug    is array(enum_DL_39)     of string(1 to 53); -- WTF WHY IS THE NUMBER DIFFERENT

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
  constant emDataDir  : string := "../../../../../../../../emData/MemPrints/"; -- 41 long
  constant dataOutDir : string := "../../../../../dataOut/"; -- 23 long

  -- Input files
  constant FILE_IN_DL_39 : t_str_arr_DL_39 := (
  emDataDir&"InputStubs/Link_DL_PS10G_3_A_04.dat", -- 35 long
  emDataDir&"InputStubs/Link_DL_negPS10G_3_A_04.dat"); -- 38 long

  -- Output files IR
  constant FILE_OUT_IL_36 : t_str_arr_IL_36 := (
  emDataDir&"InputStubs/InputStubs_IL_L2PHIA_PS10G_3_A_04.dat", -- 48 long
  emDataDir&"InputStubs/InputStubs_IL_L2PHIB_PS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_L2PHIC_PS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHIA_PS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHIB_PS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHIC_PS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHID_PS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_L2PHIA_negPS10G_3_A_04.dat", -- 51 long
  emDataDir&"InputStubs/InputStubs_IL_L2PHIB_negPS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_L2PHIC_negPS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHIA_negPS10G_3_A _04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHIB_negPS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHIC_negPS10G_3_A_04.dat",
  emDataDir&"InputStubs/InputStubs_IL_D2PHID_negPS10G_3_A_04.dat");

  -- Output files VMR
  constant FILE_OUT_AS_36 : t_str_arr_AS_36 := (
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn1_04.dat",
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn2_04.dat",
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn3_04.dat",
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn4_04.dat",
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn5_04.dat",
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn6_04.dat",
  emDataDir&"Stubs/AllStubs_AS_L2PHIAn7_04.dat"); -- 33 long

  constant FILE_OUT_VMSME_16 : t_str_arr_VMSME_16 := ( -- 40 long
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA1n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA2n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA3n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA4n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA5n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA6n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA7n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L2PHIA8n1_04.dat");

  constant FILE_OUT_VMSTE_22 : t_str_arr_VMSTE_22 := ( -- 40 long
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII1n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII1n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII2n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII2n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII2n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII3n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII3n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII3n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII4n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII4n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHII4n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX1n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX1n6_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX1n7_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX2n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX2n6_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX2n7_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIX2n8_04.dat");

  constant FILE_OUT_VMSTE_16 : t_str_arr_VMSTE_16 := ( -- 40 long
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA1n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA1n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA1n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA2n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA2n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA2n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA2n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA2n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA3n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA3n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA3n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA3n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA3n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA4n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA4n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA4n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA4n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA4n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA5n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA5n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA5n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA5n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA5n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA6n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA6n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA6n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA6n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA6n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA7n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA7n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA7n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA7n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA7n5_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA8n1_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA8n2_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA8n3_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA8n4_04.dat",
  emDataDir&"VMStubsTE/VMStubs_VMSTE_L2PHIA8n5_04.dat");

  -- Debug output files to check input was correctly read.
  constant FILE_OUT_DL_debug : t_str_arr_DL_39_debug := (
  dataOutDir&"Link_DL_PS10G_3_A.debug.txt",  
  dataOutDir&"Link_DL_negPS10G_3_A.debug.txt"); -- 30 long

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

  -- Indicates that writing of DL memories of first event has started.
  signal START_FIRST_WRITE : std_logic := '0';
  signal START_DL : t_arr_DL_39_1b := (others => '0');

begin

  --! @brief Make clock ---------------------------------------
  clk <= not clk after CLK_PERIOD/2;

  -- Get signals from input .txt files

  DL_39_loop : for var in enum_DL_39 generate
  begin
    readDL_39 : entity work.FileReader 
    generic map (
      FILE_NAME  => FILE_IN_DL_39(var),
      DELAY      => DL_DELAY*MAX_ENTRIES,
      RAM_WIDTH  => 39,
      NUM_PAGES  => 2,
      DEBUG      => true,
      FILE_NAME_DEBUG => FILE_OUT_DL_debug(var)
    )
    port map (
      CLK => CLK,
      ADDR => DL_39_link_read(var), -- needs to change
      DATA => DL_39_link_AV_dout(var),
      START => START_DL(var),
      WRITE_EN => DL_39_link_AV_dout(var) -- needs to change
    );
  end generate DL_39_loop;

  -- As all DL39 signals start together, take first one, to determine when 
  -- first event starts being written to first memory in chain.
  START_FIRST_WRITE <= START_DL(enum_DL_39'val(0));

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

          -- IR should start one TM period after time when first event starting being 
          -- written to first memory in chain, as it takes this long to write full event.
          IR_START <= '1';
          IR_BX_IN <= std_logic_vector(to_unsigned(EVENT_COUNT, IR_BX_IN'length));

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
        FILE_NAME  => FILE_OUT_IL_36(var),
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
      FILE_NAME  => FILE_OUT_AS_36(var),
      RAM_WIDTH  => 36,
      NUM_PAGES  => 8
    )
    port map (
      CLK => CLK,
      DONE => VMR_DONE,
      NENT_ARR => open,
      ADDR => AS_36_mem_AV_readaddr(var),
      DATA => AS_36_mem_AV_dout(var),
      READ_EN => AS_36_mem_A_enb(var)
    );
  end generate AS_36_loop;

  VMSME_16_loop : for var in enum_VMSME_16 generate
  begin
    writeME_16 : entity work.FileWriterFromRAM 
    generic map (
      FILE_NAME  => FILE_OUT_VMSME_16(var),
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
      FILE_NAME  => FILE_OUT_VMSTE_22(var),
      RAM_WIDTH  => 16,
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
    writeTE_16 : entity work.FileWriterFromRAM 
    generic map (
      FILE_NAME  => FILE_OUT_VMSTE_16(var),
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
