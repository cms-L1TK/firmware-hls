
--==========================================================================
-- CU Boulder
-------------------------------------------------------------------------------
--! @file
--! @brief Test bench for the track finding top using TextIO.
--! @author Robert Glein
--! @date 2020-05-18
--! @version v.1.0
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
  type t_str_arr_TPROJ_60 is array(enum_TPROJ_60)  of string(1 to 106); 
  type t_str_arr_VMSME_16 is array(enum_VMSME_16)  of string(1 to 82);  
  type t_str_arr_AS_36    is array(enum_AS_36)     of string(1 to 74); 
  type t_str_arr_VMP_24   is array(enum_VMPROJ_24) of string(1 to 42);  
  type t_str_arr_AP_60    is array(enum_AP_60)     of string(1 to 36); 
  type t_str_arr_CM_14    is array(enum_CM_14)     of string(1 to 38); 
  type t_str_arr_FM_52    is array(enum_FM_52)     of string(1 to 41); 
  -- Define type of array of strings for debug output file names.
  type t_str_arr_TPROJ_60_debug is array(enum_TPROJ_60)  of string(1 to 51); 
  type t_str_arr_VMSME_16_debug is array(enum_VMSME_16)  of string(1 to 47);  
  type t_str_arr_AS_36_debug    is array(enum_AS_36)     of string(1 to 42); 

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
  constant TPROJ_DELAY       : integer := 0;          --! Number of BX delays (can be written early 8 pages)
  constant VMSME_DELAY       : integer := 1;          --! Number of BX delays (can be written early 8 pages)
  constant AS_DELAY          : integer := 2;          --! Number of BX delays (can be written early 8 pages)
  constant MEM_READ_DELAY    : integer := 2;          --! Number of memory read delay
  -- Paths of data files specified relative to Vivado project's xsim directory. 
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant emDataDir  : string := "../../../../../../../../emData/MemPrints/";
  constant dataOutDir : string := "../../../../../dataOut/";

  -- Input files
  constant FILE_IN_TPROJ : t_str_arr_TPROJ_60 := (
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L1L2F_L3PHIC_04.dat",
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L1L2G_L3PHIC_04.dat",
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L1L2H_L3PHIC_04.dat",
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L1L2I_L3PHIC_04.dat",  
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L1L2J_L3PHIC_04.dat",
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L5L6B_L3PHIC_04.dat",
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L5L6C_L3PHIC_04.dat",  
  emDataDir&"TrackletProjections/TrackletProjections_TPROJ_L5L6D_L3PHIC_04.dat");    
  -- Input files
  constant FILE_IN_VMSME : t_str_arr_VMSME_16 := (
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC17n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC18n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC19n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC20n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC21n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC22n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC23n1_04.dat",
  emDataDir&"VMStubsME/VMStubs_VMSME_L3PHIC24n1_04.dat");

  -- Input files (N.B. bizarre initialization method, due to VHDL issue with arrays of dim=1)
  constant FILE_IN_AS : t_str_arr_AS_36 := (L3PHICn6 =>
  emDataDir&"Stubs/AllStubs_AS_L3PHICn6_04.dat");

  -- Output files
  constant FILE_OUT_VMP : t_str_arr_VMP_24 := ( 
  dataOutDir&"VMPROJ_L3PHIC17.txt",
  dataOutDir&"VMPROJ_L3PHIC18.txt",
  dataOutDir&"VMPROJ_L3PHIC19.txt",
  dataOutDir&"VMPROJ_L3PHIC20.txt",
  dataOutDir&"VMPROJ_L3PHIC21.txt",
  dataOutDir&"VMPROJ_L3PHIC22.txt",
  dataOutDir&"VMPROJ_L3PHIC23.txt",
  dataOutDir&"VMPROJ_L3PHIC24.txt");
  -- Output files (N.B. bizarre initialization method, due to VHDL issue with arrays of dim=1)
  constant FILE_OUT_AP : t_str_arr_AP_60 := (L3PHIC =>
  dataOutDir&"AP_L3PHIC.txt");
  -- Output files
  constant FILE_OUT_CM  : t_str_arr_CM_14 :=  (
  dataOutDir&"CM_L3PHIC17.txt",
  dataOutDir&"CM_L3PHIC18.txt",
  dataOutDir&"CM_L3PHIC19.txt",
  dataOutDir&"CM_L3PHIC20.txt",
  dataOutDir&"CM_L3PHIC21.txt",
  dataOutDir&"CM_L3PHIC22.txt",
  dataOutDir&"CM_L3PHIC23.txt",
  dataOutDir&"CM_L3PHIC24.txt");
  -- Output files
  constant FILE_OUT_FM : t_str_arr_FM_52 :=  (
  dataOutDir&"FM_L1L2_L3PHIC.txt", 
  dataOutDir&"FM_L5L6_L3PHIC.txt");

  -- Debug output files to check input was correctly read.
  constant FILE_OUT_TPROJ_debug : t_str_arr_TPROJ_60_debug := (
  dataOutDir&"TPROJ_L1L2F_L3PHIC.debug.txt",  
  dataOutDir&"TPROJ_L1L2G_L3PHIC.debug.txt",
  dataOutDir&"TPROJ_L1L2H_L3PHIC.debug.txt",
  dataOutDir&"TPROJ_L1L2I_L3PHIC.debug.txt",
  dataOutDir&"TPROJ_L1L2J_L3PHIC.debug.txt",
  dataOutDir&"TPROJ_L5L6B_L3PHIC.debug.txt",
  dataOutDir&"TPROJ_L5L6C_L3PHIC.debug.txt",
  dataOutDir&"TPROJ_L5L6D_L3PHIC.debug.txt");
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_VMSME_debug : t_str_arr_VMSME_16_debug := (
  dataOutDir&"VMSME_L3PHIC17.debug.txt",  
  dataOutDir&"VMSME_L3PHIC18.debug.txt",  
  dataOutDir&"VMSME_L3PHIC19.debug.txt",  
  dataOutDir&"VMSME_L3PHIC20.debug.txt",  
  dataOutDir&"VMSME_L3PHIC21.debug.txt",  
  dataOutDir&"VMSME_L3PHIC22.debug.txt",  
  dataOutDir&"VMSME_L3PHIC23.debug.txt",  
  dataOutDir&"VMSME_L3PHIC24.debug.txt");
  -- Debug output files to check input was correctly read.
  -- (N.B. bizarre initialization method, due to VHDL issue with arrays of dim=1)
  constant FILE_OUT_AS_debug : t_str_arr_AS_36_debug := (L3PHICn6 =>
  dataOutDir&"AS_L3PHIC.debug.txt");

  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk       : std_logic := '0';
  signal reset     : std_logic := '1';
  signal PR_start  : std_logic := '0';
  signal PR_idle   : std_logic := '0';
  signal PR_ready  : std_logic := '0';
  signal PR_bx_in  : std_logic_vector(2 downto 0) := (others => '1');
  signal PR_bx_out : std_logic_vector(2 downto 0) := (others => '1');
  signal PR_bx_out_vld : std_logic := '0';
  signal PR_done   : std_logic := '0';
  signal ME_bx_out : std_logic_vector(2 downto 0) := (others => '1');
  signal ME_bx_out_vld : std_logic := '0';
  signal ME_done   : std_logic := '0';
  signal MC_bx_out : std_logic_vector(2 downto 0) := (others => '1');
  signal MC_bx_out_vld : std_logic := '0';
  signal MC_done   : std_logic := '0';

  -- Signals matching ports of top-level VHDL
  signal TPROJ_60_mem_A_wea        : t_arr_TPROJ_60_1b    := (others => '0');
  signal TPROJ_60_mem_AV_writeaddr : t_arr_TPROJ_60_ADDR  := (others => (others => '0'));
  signal TPROJ_60_mem_AV_din       : t_arr_TPROJ_60_DATA  := (others => (others => '0'));
  signal VMSME_16_mem_A_wea        : t_arr_VMSME_16_1b    := (others => '0');
  signal VMSME_16_mem_AV_writeaddr : t_arr_VMSME_16_ADDR  := (others => (others => '0'));
  signal VMSME_16_mem_AV_din       : t_arr_VMSME_16_DATA  := (others => (others => '0'));
  signal AS_36_mem_A_wea           : t_arr_AS_36_1b       := (others => '0');
  signal AS_36_mem_AV_writeaddr    : t_arr_AS_36_ADDR     := (others => (others => '0'));
  signal AS_36_mem_AV_din          : t_arr_AS_36_DATA     := (others => (others => '0'));
  signal VMPROJ_24_mem_A_wea       : t_arr_VMPROJ_24_1b   := (others => '0');
  signal VMPROJ_24_mem_AV_writeaddr: t_arr_VMPROJ_24_ADDR := (others => (others => '0'));
  signal VMPROJ_24_mem_AV_din      : t_arr_VMPROJ_24_DATA := (others => (others => '0'));
  signal CM_14_mem_A_wea           : t_arr_CM_14_1b       := (others => '0');
  signal CM_14_mem_AV_writeaddr    : t_arr_CM_14_ADDR     := (others => (others => '0'));
  signal CM_14_mem_AV_din          : t_arr_CM_14_DATA     := (others => (others => '0'));
  signal AP_60_mem_A_wea           : t_arr_AP_60_1b       := (others => '0');
  signal AP_60_mem_AV_writeaddr    : t_arr_AP_60_ADDR     := (others => (others => '0'));
  signal AP_60_mem_AV_din          : t_arr_AP_60_DATA     := (others => (others => '0'));
  signal FM_52_mem_A_enb           : t_arr_FM_52_1b       := (others => '0');
  signal FM_52_mem_AV_readaddr     : t_arr_FM_52_ADDR     := (others => (others => '0'));
  signal FM_52_mem_AV_dout         : t_arr_FM_52_DATA     := (others => (others => '0'));
  signal FM_52_mem_AAV_dout_nent   : t_arr_FM_52_NENT     := (others => (others => (others => '0')));

  -- Indicates that writing of TPROJ memories of first event has started.
  signal START_FIRST_WRITE : std_logic := '0';
  signal START_TPROJ : t_arr_TPROJ_60_1b := (others => '0');

begin

  --! @brief Make clock ---------------------------------------
  clk <= not clk after CLK_PERIOD/2;

  -- Get signals from input .txt files

  TPROJ_60_loop : for var in enum_TPROJ_60 generate
  begin
    readTPROJ_60 : entity work.FileReader 
    generic map (
      FILE_NAME  => FILE_IN_TPROJ(var),
      DELAY      => TPROJ_DELAY*MAX_ENTRIES,
      RAM_WIDTH  => 60,
      NUM_PAGES  => 2,
      DEBUG      => true,
      FILE_NAME_DEBUG => FILE_OUT_TPROJ_debug(var)
    )
    port map (
      CLK => CLK,
      ADDR => TPROJ_60_mem_AV_writeaddr(var),
      DATA => TPROJ_60_mem_AV_din(var),
      START => START_TPROJ(var),
      WRITE_EN => TPROJ_60_mem_A_wea(var)
    );
  end generate TPROJ_60_loop;

  -- As all TPPROJ signals start together, take first one, to determine when 
  -- first event starts being written to first memory in chain.
  START_FIRST_WRITE <= START_TPROJ(enum_TPROJ_60'val(0));


  VMSME_16_loop : for var in enum_VMSME_16 generate
  begin
    readVMSME_16 : entity work.FileReader 
    generic map (
      FILE_NAME  => FILE_IN_VMSME(var),
      DELAY      => VMSME_DELAY*MAX_ENTRIES,
      RAM_WIDTH  => 16,
      NUM_PAGES  => 8,
      NUM_BINS   => 8,
      DEBUG      => true,
      FILE_NAME_DEBUG => FILE_OUT_VMSME_debug(var)
    )
    port map (
      CLK => CLK,
      ADDR => VMSME_16_mem_AV_writeaddr(var),
      DATA => VMSME_16_mem_AV_din(var),
      START => open,
      WRITE_EN => VMSME_16_mem_A_wea(var)
    );
  end generate VMSME_16_loop;

  AS_36_loop : for var in enum_AS_36 generate
  begin
    readAS_36 : entity work.FileReader 
    generic map (
      FILE_NAME  => FILE_IN_AS(var),
      DELAY      => AS_DELAY*MAX_ENTRIES,
      RAM_WIDTH  => 36,
      NUM_PAGES  => 8,
      DEBUG      => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_debug(var)
    )
    port map (
      CLK => CLK,
      ADDR => AS_36_mem_AV_writeaddr(var),
      DATA => AS_36_mem_AV_din(var),
      START => open,
      WRITE_EN => AS_36_mem_A_wea(var)
    );
  end generate AS_36_loop;


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

          -- PR should start one TM period after time when first event starting being 
          -- written to first memory in chain, as it takes this long to write full event.
          PR_START <= '1';
          PR_BX_IN <= std_logic_vector(to_unsigned(EVENT_COUNT, PR_BX_IN'length));

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
        PR_start                   => PR_start,
        PR_bx_in                   => PR_bx_in,
        MC_bx_out                  => MC_bx_out,
        MC_bx_out_vld              => MC_bx_out_vld,
        MC_done                    => MC_done,
        TPROJ_60_mem_A_wea         => TPROJ_60_mem_A_wea,
        TPROJ_60_mem_AV_writeaddr  => TPROJ_60_mem_AV_writeaddr,
        TPROJ_60_mem_AV_din        => TPROJ_60_mem_AV_din,
        VMSME_16_mem_A_wea         => VMSME_16_mem_A_wea,
        VMSME_16_mem_AV_writeaddr  => VMSME_16_mem_AV_writeaddr,
        VMSME_16_mem_AV_din        => VMSME_16_mem_AV_din,
        AS_36_mem_A_wea            => AS_36_mem_A_wea,
        AS_36_mem_AV_writeaddr     => AS_36_mem_AV_writeaddr,
        AS_36_mem_AV_din           => AS_36_mem_AV_din,
        FM_52_mem_A_enb            => FM_52_mem_A_enb,
        FM_52_mem_AV_readaddr      => FM_52_mem_AV_readaddr,
        FM_52_mem_AV_dout          => FM_52_mem_AV_dout,
        FM_52_mem_AAV_dout_nent    => FM_52_mem_AAV_dout_nent
      );
  end generate sectorProc;


  sectorProcFull : if INST_TOP_TF = 1 generate
  begin
    uut : entity work.SectorProcessorFull
      port map(
        clk                        => clk,
        reset                      => reset,
        PR_start                   => PR_start,
        PR_bx_in                   => PR_bx_in,
        MC_bx_out                  => MC_bx_out,
        MC_bx_out_vld              => MC_bx_out_vld,
        MC_done                    => MC_done,
        -- Debug control signals
        PR_bx_out                  => PR_bx_out,
        PR_bx_out_vld              => PR_bx_out_vld,
        PR_done                    => PR_done,
        ME_bx_out                  => ME_bx_out,
        ME_bx_out_vld              => ME_bx_out_vld,
        ME_done                    => ME_done,
        -- Input data
        TPROJ_60_mem_A_wea         => TPROJ_60_mem_A_wea,
        TPROJ_60_mem_AV_writeaddr  => TPROJ_60_mem_AV_writeaddr,
        TPROJ_60_mem_AV_din        => TPROJ_60_mem_AV_din,
        VMSME_16_mem_A_wea         => VMSME_16_mem_A_wea,
        VMSME_16_mem_AV_writeaddr  => VMSME_16_mem_AV_writeaddr,
        VMSME_16_mem_AV_din        => VMSME_16_mem_AV_din,
        AS_36_mem_A_wea            => AS_36_mem_A_wea,
        AS_36_mem_AV_writeaddr     => AS_36_mem_AV_writeaddr,
        AS_36_mem_AV_din           => AS_36_mem_AV_din,
        -- Debug output data
        VMPROJ_24_mem_A_wea        => VMPROJ_24_mem_A_wea,
        VMPROJ_24_mem_AV_writeaddr => VMPROJ_24_mem_AV_writeaddr,
        VMPROJ_24_mem_AV_din       => VMPROJ_24_mem_AV_din,
        CM_14_mem_A_wea            => CM_14_mem_A_wea,
        CM_14_mem_AV_writeaddr     => CM_14_mem_AV_writeaddr,
        CM_14_mem_AV_din           => CM_14_mem_AV_din,
        AP_60_mem_A_wea            => AP_60_mem_A_wea,
        AP_60_mem_AV_writeaddr     => AP_60_mem_AV_writeaddr,
        AP_60_mem_AV_din           => AP_60_mem_AV_din,
        -- Output data
        FM_52_mem_A_enb            => FM_52_mem_A_enb,
        FM_52_mem_AV_readaddr      => FM_52_mem_AV_readaddr,
        FM_52_mem_AV_dout          => FM_52_mem_AV_dout,
        FM_52_mem_AAV_dout_nent    => FM_52_mem_AAV_dout_nent
      );
  end generate sectorProcFull;


  --! @brief TextIO process for writing the FM output ---------------------------------------
  --! @details Read memory outputs (from last HLS module in the chain) and write it to files including headers.
  -- TODO: Replace with write procedures (e.g. like CM) but take MEM_READ_DELAY into account because it is the read port
  write_result_FM : process
    file     file_out_L1L2 : text open WRITE_MODE is FILE_OUT_FM(L1L2_L3PHIC); -- Text - a file of character strings
    file     file_out_L5L6 : text open WRITE_MODE is FILE_OUT_FM(L5L6_L3PHIC); -- Text - a file of character strings
    variable v_line   : line;                                        -- Line - one string from a text
    variable v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d : std_logic_vector(MEM_READ_DELAY-1 downto 0) := (others => '0'); -- Delay vector
    variable v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d : std_logic_vector(MEM_READ_DELAY-1 downto 0) := (others => '0'); -- Delay vector
  begin
    -- Write file header
    write(v_line, string'("time"), right, 20); write(v_line, string'("BX#"), right, 4);
    write(v_line, string'("reset"), right, 6);
    write(v_line, string'("n_ent_p0"), right, 9); write(v_line, string'("n_ent_p1"), right, 9); write(v_line, string'("enb"), right, 4);
    write(v_line, string'("readaddr"), right, 9);  write(v_line, string'("FM_L1L2_L3PHIC_dataarray_data_V_dout"), right, 37);
    write(v_line, string'("MC_done"), right, 9);  write(v_line, string'("MC_bx_out_vld"), right, 14); write(v_line, string'("MC_bx_out"), right, 10);
    writeline (file_out_L1L2, v_line); -- Write line
    write(v_line, string'("time"), right, 20); write(v_line, string'("BX#"), right, 4);
    write(v_line, string'("reset"), right, 6);
    write(v_line, string'("n_ent_p0"), right, 9); write(v_line, string'("n_ent_p1"), right, 9); write(v_line, string'("enb"), right, 4);
    write(v_line, string'("readaddr"), right, 9);  write(v_line, string'("FM_L5L6_L3PHIC_dataarray_data_V_dout"), right, 37);
    write(v_line, string'("MC_done"), right, 9);  write(v_line, string'("MC_bx_out_vld"), right, 14); write(v_line, string'("MC_bx_out"), right, 10);
    writeline (file_out_L5L6, v_line); -- Write line

    wait until rising_edge(clk) and MC_done = '1'; -- Wait for first result
    l_BX : for v_bx_cnt in 0 to MAX_EVENTS-1 loop -- 0 to 99
      -- FIX: This is buggy. As mem read takes 2 clks, it will lose last 2 samples
      --      per event.
      l_addr : for addr in 0 to MAX_ENTRIES-1 loop 
        if (addr <= MAX_ENTRIES-1) then -- w/o MEM_READ_DELAY
          if (v_bx_cnt mod 2)=0 then -- 1. page
            if (addr < (to_integer(unsigned(FM_52_mem_AAV_dout_nent(L1L2_L3PHIC)(0))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_52_mem_A_enb(L1L2_L3PHIC) <= '1';
            else
              FM_52_mem_A_enb(L1L2_L3PHIC) <= '0';
            end if;
            if (addr < (to_integer(unsigned(FM_52_mem_AAV_dout_nent(L5L6_L3PHIC)(0))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_52_mem_A_enb(L5L6_L3PHIC) <= '1';
            else
              FM_52_mem_A_enb(L5L6_L3PHIC) <= '0';
            end if;
          else                       -- 2. page
            if (addr < (to_integer(unsigned(FM_52_mem_AAV_dout_nent(L1L2_L3PHIC)(1))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_52_mem_A_enb(L1L2_L3PHIC) <= '1';
            else
              FM_52_mem_A_enb(L1L2_L3PHIC) <= '0';
            end if;
            if (addr < (to_integer(unsigned(FM_52_mem_AAV_dout_nent(L5L6_L3PHIC)(1))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_52_mem_A_enb(L5L6_L3PHIC) <= '1';
            else
              FM_52_mem_A_enb(L5L6_L3PHIC) <= '0';
            end if;
          end if;
        end if;
        FM_52_mem_AV_readaddr(L1L2_L3PHIC) <= std_logic_vector(to_unsigned(addr+(PAGE_LENGTH*(v_bx_cnt mod 2)), FM_52_mem_AV_readaddr(L1L2_L3PHIC)'length));
         FM_52_mem_AV_readaddr(L5L6_L3PHIC) <= std_logic_vector(to_unsigned(addr+(PAGE_LENGTH*(v_bx_cnt mod 2)), FM_52_mem_AV_readaddr(L5L6_L3PHIC)'length));

        v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d :=  v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-2 downto 0) & FM_52_mem_A_enb(L1L2_L3PHIC); -- Required delay
        v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d :=  v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-2 downto 0) & FM_52_mem_A_enb(L5L6_L3PHIC); -- Required delay

        -- Repeat this multiple times to go through all simulation delta-times.
        wait for 0 ns; -- Update signals
        wait for 0 ns; -- Update signals
        wait for 0 ns; -- Update signals
        wait for 0 ns; -- Update signals
        wait for 0 ns; -- Update signals
        -- Other writes ---------------------------------------
        if (addr >= MEM_READ_DELAY) then -- Take read delay into account
          write(v_line, NOW, right, 20); -- NOW = current simulation time
          write(v_line, v_bx_cnt, right, 4);
          --write(v_line, string'("0x"), right, 4); hwrite(v_line, std_logic_vector(to_unsigned(addr,10)), right, 3);
          write(v_line, string'("0b"), right, 5);   write(v_line, reset, right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_52_mem_AAV_dout_nent(L1L2_L3PHIC)(0), right, 2);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_52_mem_AAV_dout_nent(L1L2_L3PHIC)(1), right, 2);
          write(v_line, string'("0b"), right, 3);   write(v_line, v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1), right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, std_logic_vector(unsigned( FM_52_mem_AV_readaddr(L1L2_L3PHIC))-to_unsigned(MEM_READ_DELAY,FM_52_mem_AV_readaddr(L1L2_L3PHIC)'length)), right, 2);
          if (v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1)='1') then -- Only write if enable (delayed): Switch off in complete read out mode
            write(v_line, string'("0x"), right, 25); hwrite(v_line, FM_52_mem_AV_dout(L1L2_L3PHIC), right, 12);
          else
            write(v_line, string'("0x"), right, 25);  write(v_line, string'("000000000000"), right, 12);
          end if;
          write(v_line, string'("0b"), right, 8);   write(v_line, MC_done, right, 1);
          write(v_line, string'("0b"), right, 13);  write(v_line, MC_bx_out_vld, right, 1);
          write(v_line, string'("0x"), right, 9);  hwrite(v_line, MC_bx_out, right, 1);
          writeline (file_out_L1L2, v_line); -- Write line
          write(v_line, NOW, right, 20); -- NOW = current simulation time
          write(v_line, v_bx_cnt, right, 4);
          --write(v_line, string'("0x"), right, 4); hwrite(v_line, std_logic_vector(to_unsigned(addr,10)), right, 3);
          write(v_line, string'("0b"), right, 5);   write(v_line, reset, right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_52_mem_AAV_dout_nent(L5L6_L3PHIC)(0), right, 2);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_52_mem_AAV_dout_nent(L5L6_L3PHIC)(1), right, 2);
          write(v_line, string'("0b"), right, 3);   write(v_line, v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1), right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, std_logic_vector(unsigned( FM_52_mem_AV_readaddr(L5L6_L3PHIC))-to_unsigned(MEM_READ_DELAY, FM_52_mem_AV_readaddr(L5L6_L3PHIC)'length)), right, 2);
          if (v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1)='1') then -- Only write if enable (delayed): Switch off in complete read out mode
            write(v_line, string'("0x"), right, 27); hwrite(v_line,  FM_52_mem_AV_dout(L5L6_L3PHIC), right, 12);
          else
            write(v_line, string'("0x"), right, 27);  write(v_line, string'("000000000000"), right, 12);
          end if;
          write(v_line, string'("0b"), right, 8);   write(v_line, MC_done, right, 1);
          write(v_line, string'("0b"), right, 13);  write(v_line, MC_bx_out_vld, right, 1);
          write(v_line, string'("0x"), right, 9);  hwrite(v_line, MC_bx_out, right, 1);
          writeline (file_out_L5L6, v_line); -- Write line
        end if;
        if (DEBUG=true and v_bx_cnt<=5 and addr<=10) then write(v_line, string'("v_bx_cnt: ")); write(v_line, v_bx_cnt); write(v_line, string'("   FM_L1L2_L3PHIC readaddr: ")); hwrite(v_line, FM_52_mem_AV_readaddr(L1L2_L3PHIC)); write(v_line, string'(", dout: ")); hwrite(v_line, FM_52_mem_AV_dout(L1L2_L3PHIC)); writeline(output, v_line); end if;
        wait until rising_edge(clk); -- Main time control
      end loop l_addr;
    end loop l_BX;
    file_close(file_out_L1L2);
    file_close(file_out_L5L6);
    -- Normal termination of simulation. All done.
    assert false report "Simulation finished!" severity FAILURE;
  end process write_result_FM;


  fileOutput : if INST_TOP_TF = 1 generate
    --! @brief TextIO process for writing the output of intermediate memories in chain ---------------------------------------
    --! @details Read input signals to intermediate memories in chain,
    --!          and write them to file using processes.
    write_result_AP : process
      variable v_bx_cnt      : integer       := -1; --! BX counter
    begin
      wait until PR_start = '1'; -- Wait to start
      write_header_line(FILE_OUT_AP(L3PHIC), "AP_L3PHIC_dataarray_data_V_din", 8);
      -- Loops over all events and all valid entries within each event.
      l_BX : while v_bx_cnt <= MAX_EVENTS-1 loop
        if (AP_60_mem_AV_writeaddr(L3PHIC)(6 downto 0) = b"000_0000") and
           (AP_60_mem_A_wea(L3PHIC) = '1') then -- Start new event assuming all addr behave the same
          v_bx_cnt := v_bx_cnt + 1;
        end if;
        if (AP_60_mem_A_wea(L3PHIC)='1') then -- Only write valid data
          write_emData_line_8p(reset, v_bx_cnt, PR_done, PR_bx_out, PR_bx_out_vld, FILE_OUT_AP(L3PHIC), "AP_L3PHIC_dataarray_data_V_din",
                               AP_60_mem_AV_din(L3PHIC), AP_60_mem_A_wea(L3PHIC), AP_60_mem_AV_writeaddr(L3PHIC),
                               (others => (others => '0')), (others => '0') );
        end if;
        wait for CLK_PERIOD; -- Main time control
      end loop l_BX;
      wait;
    end process write_result_AP;

    --! @brief TextIO process for writting the output ---------------------------------------
    write_result_VMP : process
      variable v_bx_cnt      : integer       := -1; --! BX counter
      constant myarray2_8b   : t_arr2_8b := (others => (others => '0')); -- Temporary array to avoid sim error
      constant myarray2_1b   : t_arr2_1b := (others => '0'); -- Temporary array to avoid sim error
      variable v_addr_d1     : t_arr_VMPROJ_24_ADDR := (others => (others => '0')); -- Delayed address
    begin
      wait until PR_start = '1'; -- Wait to start
      l_copies_header : for cp in enum_VMPROJ_24 loop
        write_header_line(FILE_OUT_VMP(cp), "VMPROJ_L3PHIC17to24_dataarray_data_V_din", 2);
      end loop l_copies_header;
      -- Loops over all events and all valid entries within each event.
      l_BX : while v_bx_cnt <= MAX_EVENTS-1 loop
        if (VMPROJ_24_mem_AV_writeaddr(enum_VMPROJ_24'val(0))(6 downto 0) = b"000_0000") and
           v_addr_d1(enum_VMPROJ_24'val(0))(7) /= VMPROJ_24_mem_AV_writeaddr(enum_VMPROJ_24'val(0))(7) then -- Start new event assuming all addr behave the same
          v_bx_cnt := v_bx_cnt + 1;
        end if;
        l_copies : for cp in enum_VMPROJ_24 loop 
          if (VMPROJ_24_mem_A_wea(cp)='1') then -- Only write valid data
            write_emData_line_2p(reset, v_bx_cnt, PR_done, PR_bx_out, PR_bx_out_vld, FILE_OUT_VMP(cp), "VMPROJ_L3PHIC17to24_dataarray_data_V_din",
                                 VMPROJ_24_mem_AV_din(cp), VMPROJ_24_mem_A_wea(cp), VMPROJ_24_mem_AV_writeaddr(cp),
                                 myarray2_8b, myarray2_1b );
          end if;
        end loop l_copies;
        v_addr_d1 := VMPROJ_24_mem_AV_writeaddr; -- Delay the address
        wait for CLK_PERIOD; -- Main time control
      end loop l_BX;
      wait;
    end process write_result_VMP;

    --! @brief TextIO process for writting the output ---------------------------------------
    --! @details Read additional memory outputs (from intermediate HLS modules in the chain) and
    --!         write it to files using procedures.
    write_result_CM : process
      variable v_bx_cnt    : integer       := -1; --! BX counter
      constant myarray2_8b : t_arr2_8b := (others => (others => '0')); -- Temporary array to avoid sim error
      constant myarray2_1b : t_arr2_1b := (others => '0'); -- Temporary array to avoid sim error
      variable v_addr_d1   : t_arr_CM_14_ADDR := (others => (others => '0')); -- Delayed address
    begin
      wait until PR_done = '1'; -- Wait to start = ME_start
      l_copies_header : for cp in enum_CM_14 loop 
        write_header_line(FILE_OUT_CM(cp), "CM_L3PHIC17to24_dataarray_data_V_din", 2);
      end loop l_copies_header;
      -- Loops over all events and all valid entries within each event.
      l_BX : while v_bx_cnt <= MAX_EVENTS-1 loop
        if (CM_14_mem_AV_writeaddr(enum_CM_14'val(0))(6 downto 0) = b"000_0000") and
           v_addr_d1(enum_CM_14'val(0))(7) /= CM_14_mem_AV_writeaddr(enum_CM_14'val(0))(7) then -- Start new event assuming all addr behave the same
          v_bx_cnt := v_bx_cnt + 1;
        end if;
        l_copies : for cp in enum_CM_14 loop
          if (CM_14_mem_A_wea(cp)='1') then
           write_emData_line_2p(reset, v_bx_cnt, ME_done, ME_bx_out, ME_bx_out_vld, FILE_OUT_CM(cp), "CM_L3PHIC17to24_dataarray_data_V_din",
                                 CM_14_mem_AV_din(cp), CM_14_mem_A_wea(cp),  CM_14_mem_AV_writeaddr(cp),
                                 myarray2_8b, myarray2_1b );
          end if;
        end loop l_copies;
        v_addr_d1 :=  CM_14_mem_AV_writeaddr; -- Delay the address
        wait for CLK_PERIOD; -- Main time control
      end loop l_BX;
      wait;
    end process write_result_CM;
  end generate fileOutput;

end behavior;
