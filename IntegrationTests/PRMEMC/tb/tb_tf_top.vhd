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



--! @brief TB
entity tb_tf_top is
end tb_tf_top;

--! @brief TB
architecture behavior of tb_tf_top is
  -- ########################### Types ###########################
  type t_str_array_TPROJ is array(natural range <>) of string(1 to 106); --! String array
  type t_str_array_VMSME is array(natural range <>) of string(1 to 82);  --! String array
  type t_str_array_VMP   is array(natural range <>) of string(1 to 42);  --! String array
  type t_str_array_CM    is array(natural range <>) of string(1 to 38);  --! String array
  type t_str_array_FM    is array(natural range <>) of string(1 to 41);  --! String array
  type t_arr_1d_1d_int    is array(natural range <>) of t_arr_1d_int(0 to MAX_EVENTS-1);                      --! 1x1D array of int
  type t_arr_1d_2d_int    is array(natural range <>) of t_arr_2d_int(0 to MAX_EVENTS-1,0 to N_MEM_BINS-1);    --! 1x2D array of int
  type t_arr_1d_2d_slv_2p is array(natural range <>) of t_arr_2d_slv(0 to MAX_EVENTS-1,0 to 2*PAGE_OFFSET-1); --! 1x2D array of slv
  type t_arr_1d_2d_slv_8p is array(natural range <>) of t_arr_2d_slv(0 to MAX_EVENTS-1,0 to 8*PAGE_OFFSET-1); --! 1x2D array of slv

  -- ########################### Constant Definitions ###########################
  -- ############ Please change the constants in this section ###################
  constant N_ME_IN_CHAIN     : integer := 8; --! Number of match engines in chain
  constant INST_TOP_TF       : integer := 1;          --! Instantiate top_tf or others
                                                      --! 0: Generated SectorProcessor chain
                                                      --! 1: top_tf_full (intermediate MemPrints)
  constant CLK_PERIOD        : time    := 4 ns;       --! 250 MHz
  constant DEBUG             : boolean := true;       --! Debug off/on
  constant VMSME_DELAY       : integer := 1-1;        --! Number of BX delays (can be written early 8 pages)
  constant AS_DELAY          : integer := 2-1;        --! Number of BX delays (can be written early 8 pages)
  constant MEM_READ_DELAY    : integer := 2;          --! Number of memory read delay
  -- Paths of data files specified relative to Vivado project's xsim directory. 
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant FILE_IN_TPROJ : t_str_array_TPROJ(0 to N_ME_IN_CHAIN-1) := ("../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L1L2F_L3PHIC_04.dat", --! Input files
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L1L2G_L3PHIC_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L1L2H_L3PHIC_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L1L2I_L3PHIC_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L1L2J_L3PHIC_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L5L6B_L3PHIC_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L5L6C_L3PHIC_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/TrackletProjections/TrackletProjections_TPROJ_L5L6D_L3PHIC_04.dat" );
  constant FILE_IN_VMSME : t_str_array_VMSME(0 to N_ME_IN_CHAIN-1) := ("../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC17n1_04.dat", --! Input files
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC18n1_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC19n1_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC20n1_04.dat", -- Used by lastest ME HLS c(o)sim
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC21n1_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC22n1_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC23n1_04.dat",
                                                                       "../../../../../../../../emData/MemPrints/VMStubsME/VMStubs_VMSME_L3PHIC24n1_04.dat" );
  constant FILE_IN_AS        : string := "../../../../../../../../emData/MemPrints/Stubs/AllStubs_AS_L3PHICn6_04.dat"; --! Input file
  constant FILE_OUT_VMP      : t_str_array_VMP(0 to N_ME_IN_CHAIN-1) := ("../../../../../dataOut/VMPROJ_L3PHIC17.txt", --! Output file for VMP
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC18.txt",
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC19.txt",
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC20.txt",
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC21.txt",
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC22.txt",
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC23.txt",
                                                                         "../../../../../dataOut/VMPROJ_L3PHIC24.txt" );
  constant FILE_OUT_AP       : string := "../../../../../dataOut/AP_L3PHIC.txt";  --! Output file for AP
  constant FILE_OUT_CM       : t_str_array_CM(0 to N_ME_IN_CHAIN-1) :=  ("../../../../../dataOut/CM_L3PHIC17.txt", --! Output file for CM
                                                                         "../../../../../dataOut/CM_L3PHIC18.txt",
                                                                         "../../../../../dataOut/CM_L3PHIC19.txt",
                                                                         "../../../../../dataOut/CM_L3PHIC20.txt",
                                                                         "../../../../../dataOut/CM_L3PHIC21.txt",
                                                                         "../../../../../dataOut/CM_L3PHIC22.txt",
                                                                         "../../../../../dataOut/CM_L3PHIC23.txt",
                                                                         "../../../../../dataOut/CM_L3PHIC24.txt" );
  constant FILE_OUT_FM       : t_str_array_FM(0 to 1) :=  ("../../../../../dataOut/FM_L1L2_L3PHIC.txt", --! Output file for FM
                                                           "../../../../../dataOut/FM_L5L6_L3PHIC.txt" );

  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk       : std_logic := '0';
  signal reset     : std_logic := '1';
  signal PR_start  : std_logic := '0';
  signal PR_idle   : std_logic;
  signal PR_ready  : std_logic;
  signal PR_bx_in  : std_logic_vector(2 downto 0) := (others => '0');
  -- For TrackletProjections memories
  signal TPROJ_L3PHIC_dataarray_data_V_wea       : t_arr8_1b   := (others => '0');
  signal TPROJ_L3PHIC_dataarray_data_V_writeaddr : t_arr8_8b   := (others => (others => '0'));
  signal TPROJ_L3PHIC_dataarray_data_V_din       : t_arr8_60b  := (others => (others => '0'));
  -- For VMStubME memories
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_wea       : t_arr8_1b  := (others => '0');
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr : t_arr8_10b  := (others => (others => '0'));
  signal VMSME_L3PHIC17to24n1_dataarray_data_V_din       : t_arr8_13b := (others => (others => '0'));
  -- For AllStubs memories
  signal AS_L3PHICn4_dataarray_data_V_wea       : std_logic                     := '0';
  signal AS_L3PHICn4_dataarray_data_V_writeaddr : std_logic_vector(9 downto 0)  := (others => '0');
  signal AS_L3PHICn4_dataarray_data_V_din       : std_logic_vector(35 downto 0) := (others => '0');
  -- FullMatches output
  signal FM_L1L2_L3PHIC_dataarray_data_V_enb      : std_logic                     := '0';
  signal FM_L1L2_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0)  := (others => '0');
  signal FM_L1L2_L3PHIC_dataarray_data_V_dout     : std_logic_vector(44 downto 0);
  signal FM_L1L2_L3PHIC_nentries_V_dout : t_arr2_7b;
  signal FM_L5L6_L3PHIC_dataarray_data_V_enb      : std_logic                     := '0';
  signal FM_L5L6_L3PHIC_dataarray_data_V_readaddr : std_logic_vector(7 downto 0)  := (others => '0');
  signal FM_L5L6_L3PHIC_dataarray_data_V_dout     : std_logic_vector(44 downto 0);
  signal FM_L5L6_L3PHIC_nentries_V_dout : t_arr2_7b;
  -- MatchCalculator outputs
  signal MC_bx_out     : std_logic_vector(2 downto 0);
  signal MC_bx_out_vld : std_logic;
  signal MC_done       : std_logic;
  -- ### Other signals ###
  signal TPROJ_L3PHICn4_data_arr            : t_arr_1d_2d_slv_2p(0 to N_ME_IN_CHAIN-1);
  signal TPROJ_L3PHICn4_n_entries_arr       : t_arr_1d_1d_int(0 to N_ME_IN_CHAIN-1);
  signal VMSME_L3PHIC17to24n1_data_arr      : t_arr_1d_2d_slv_8p(0 to N_ME_IN_CHAIN-1);
  signal VMSME_L3PHIC17to24n1_n_entries_arr : t_arr_1d_2d_int(0 to N_ME_IN_CHAIN-1);
  signal AS_L3PHICn4_data_arr               : t_arr_2d_slv(0 to MAX_EVENTS-1,0 to 8*PAGE_OFFSET-1);
  signal AS_L3PHICn4_n_entries_arr          : t_arr_1d_int(0 to MAX_EVENTS-1);
  signal bx_cnt                             : integer := 0; -- BX counter
  signal page_cnt2                          : integer := 0; -- Page counter
  signal page_cnt8                          : integer := 0; -- Page counter
  -- ### Signals for top_tf_full only (VHDL does not support conditional signal declaration) ###
  -- ProjectionRouter outputs
  signal PR_done       : std_logic := '0';
  signal PR_bx_out     : std_logic_vector(2 downto 0);
  signal PR_bx_out_vld : std_logic;
  -- AllProjection output
  signal AP_L3PHIC_dataarray_data_V_wea       : std_logic;
  signal AP_L3PHIC_dataarray_data_V_writeaddr : std_logic_vector(9 downto 0);
  signal AP_L3PHIC_dataarray_data_V_din       : std_logic_vector(59 downto 0);
  -- VMProjection output
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_wea       : t_arr8_1b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr : t_arr8_8b;
  signal VMPROJ_L3PHIC17to24_dataarray_data_V_din       : t_arr8_21b;
  -- MatchEngine output
  signal ME_bx_out     : t_arr8_3b;
  signal ME_bx_out_vld : t_arr8_1b;
  signal ME_all_done   : std_logic := '0';
  -- CandidateMatch output
  signal CM_L3PHIC17to24_dataarray_data_V_wea       : t_arr8_1b;
  signal CM_L3PHIC17to24_dataarray_data_V_writeaddr : t_arr8_8b;
  signal CM_L3PHIC17to24_dataarray_data_V_din       : t_arr8_14b;


begin

  -- ########################### Processes ###########################

  --! @brief Clock process ---------------------------------------
  CLK_process : process
  begin
    clk <= '1';
    wait for CLK_PERIOD/2;
    clk <= '0';
    wait for CLK_PERIOD/2;
  end process CLK_process;

  --! @brief Read emData process ---------------------------------------
  --! @details Read all emData from files and store it in big memory arrays as
  --!         input for the UUT. Memory intensive but fast.
  read_data : process
    variable v_TPROJ_L3PHICn4_data_arr            : t_arr_1d_2d_slv_2p(0 to N_ME_IN_CHAIN-1);
    variable v_TPROJ_L3PHICn4_n_entries_arr       : t_arr_1d_1d_int(0 to N_ME_IN_CHAIN-1);
    variable v_VMSME_L3PHIC17to24n1_data_arr      : t_arr_1d_2d_slv_8p(0 to N_ME_IN_CHAIN-1);
    variable v_VMSME_L3PHIC17to24n1_n_entries_arr : t_arr_1d_2d_int(0 to N_ME_IN_CHAIN-1);
    variable v_AS_L3PHICn4_data_arr               : t_arr_2d_slv(0 to MAX_EVENTS-1,0 to N_ME_IN_CHAIN*PAGE_OFFSET-1);
    variable v_AS_L3PHICn4_n_entries_arr          : t_arr_1d_int(0 to MAX_EVENTS-1);
    variable v_line_in : line; -- Line for debug
  begin
    -- TPROJ
    l_TPROJ_read : for i in 0 to N_ME_IN_CHAIN-1 loop
      read_emData_2p (FILE_IN_TPROJ(i), v_TPROJ_L3PHICn4_data_arr(i), v_TPROJ_L3PHICn4_n_entries_arr(i));
      if DEBUG=true then write(v_line_in, string'("TPROJ_i: ")); write(v_line_in, i); write(v_line_in, string'(";   v_TPROJ_L3PHICn4_data_arr(i)(0,0): ")); hwrite(v_line_in, v_TPROJ_L3PHICn4_data_arr(i)(0,0)); writeline(output, v_line_in); end if;
      if DEBUG=true then write(v_line_in, string'("TPROJ_i: ")); write(v_line_in, i); write(v_line_in, string'(";   v_TPROJ_L3PHICn4_n_entries_arr(i)(0): ")); write(v_line_in, v_TPROJ_L3PHICn4_n_entries_arr(i)(0)); writeline(output, v_line_in); end if;
    end loop l_TPROJ_read;
    if DEBUG=true then write(v_line_in, string'("v_TPROJ_L3PHICn4_data_arr(0)(99,0+128): ")); hwrite(v_line_in, v_TPROJ_L3PHICn4_data_arr(0)(99,0+128)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_TPROJ_L3PHICn4_data_arr(0)(99,3+128): ")); hwrite(v_line_in, v_TPROJ_L3PHICn4_data_arr(0)(99,3+128)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_TPROJ_L3PHICn4_n_entries_arr(0)(99): "));   write(v_line_in, v_TPROJ_L3PHICn4_n_entries_arr(0)(99)); writeline(output, v_line_in); end if;
    -- VMSME
    l_VMSME_read : for i in 0 to N_ME_IN_CHAIN-1 loop
      read_emData_8p_bin (FILE_IN_VMSME(i), v_VMSME_L3PHIC17to24n1_data_arr(i), v_VMSME_L3PHIC17to24n1_n_entries_arr(i));
      if DEBUG=true then write(v_line_in, string'("VMSME_i: ")); write(v_line_in, i); write(v_line_in, string'(";   v_VMSME_L3PHIC17to24n1_data_arr(i)(0,0): ")); hwrite(v_line_in, v_VMSME_L3PHIC17to24n1_data_arr(i)(0,0)); writeline(output, v_line_in); end if;
      if DEBUG=true then write(v_line_in, string'("VMSME_i: ")); write(v_line_in, i); write(v_line_in, string'(";   v_VMSME_L3PHIC17to24n1_n_entries_arr(i)(0,0): ")); write(v_line_in, v_VMSME_L3PHIC17to24n1_n_entries_arr(i)(0,0)); writeline(output, v_line_in); end if;
    end loop l_VMSME_read;
    if DEBUG=true then write(v_line_in, string'("v_VMSME_L3PHIC17to24n1_data_arr(0)(99,3*PAGE_OFFSET+7*N_ENTRIES_PER_MEM_BINS): ")); hwrite(v_line_in, v_VMSME_L3PHIC17to24n1_data_arr(0)(99,3*PAGE_OFFSET+7*N_ENTRIES_PER_MEM_BINS)); writeline(output, v_line_in); end if;
      if DEBUG=true then write(v_line_in, string'("v_VMSME_L3PHIC17to24n1_n_entries_arr(0)(99,7): ")); write(v_line_in, v_VMSME_L3PHIC17to24n1_n_entries_arr(0)(99,7)); writeline(output, v_line_in); end if;
    l_VMSME_debug0 : for i in 0 to 64 loop -- until last utilized addr
      if DEBUG=true then write(v_line_in, string'("addr: ")); write(v_line_in, i); write(v_line_in, string'(";   v_VMSME_L3PHIC17to24n1_data_arr(0)(0,addr): ")); hwrite(v_line_in, v_VMSME_L3PHIC17to24n1_data_arr(0)(0,i)); writeline(output, v_line_in); end if;
    end loop l_VMSME_debug0;
    l_VMSME_debug9 : for i in 1*PAGE_OFFSET to 1*PAGE_OFFSET+(5*16+1) loop -- until last utilized addr
      if DEBUG=true then write(v_line_in, string'("addr: ")); write(v_line_in, i); write(v_line_in, string'(";   v_VMSME_L3PHIC17to24n1_data_arr(6)(9,addr): ")); hwrite(v_line_in, v_VMSME_L3PHIC17to24n1_data_arr(6)(9,i)); writeline(output, v_line_in); end if;
    end loop l_VMSME_debug9;
    l_VMSME_debug23 : for i in 7*PAGE_OFFSET to 7*PAGE_OFFSET+(6*16+4) loop -- until last utilized addr
      if DEBUG=true then write(v_line_in, string'("addr: ")); write(v_line_in, i); write(v_line_in, string'(";   v_VMSME_L3PHIC17to24n1_data_arr(4)(23,addr): ")); hwrite(v_line_in, v_VMSME_L3PHIC17to24n1_data_arr(4)(23,i)); writeline(output, v_line_in); end if;
    end loop l_VMSME_debug23;
    l_VMSME_debug99 : for i in 3*PAGE_OFFSET to 3*PAGE_OFFSET+(7*16) loop -- until last utilized addr
      if DEBUG=true then write(v_line_in, string'("addr: ")); write(v_line_in, i); write(v_line_in, string'(";   v_VMSME_L3PHIC17to24n1_data_arr(0)(99,addr): ")); hwrite(v_line_in, v_VMSME_L3PHIC17to24n1_data_arr(0)(99,i)); writeline(output, v_line_in); end if;
    end loop l_VMSME_debug99;
    -- AS
    read_emData_8p (FILE_IN_AS, v_AS_L3PHICn4_data_arr, v_AS_L3PHICn4_n_entries_arr);
    if DEBUG=true then write(v_line_in, string'("v_AS_L3PHICn4_data_arr(0,0): "));         hwrite(v_line_in, v_AS_L3PHICn4_data_arr(0,0)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_AS_L3PHICn4_data_arr(0,71): "));        hwrite(v_line_in, v_AS_L3PHICn4_data_arr(0,71)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_AS_L3PHICn4_n_entries_arr(0): "));       write(v_line_in, v_AS_L3PHICn4_n_entries_arr(0)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_AS_L3PHICn4_data_arr(99,0+128*3): "));  hwrite(v_line_in, v_AS_L3PHICn4_data_arr(99,0+128*3)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_AS_L3PHICn4_data_arr(99,35+128*3): ")); hwrite(v_line_in, v_AS_L3PHICn4_data_arr(99,35+128*3)); writeline(output, v_line_in); end if;
    if DEBUG=true then write(v_line_in, string'("v_AS_L3PHICn4_n_entries_arr(99): "));      write(v_line_in, v_AS_L3PHICn4_n_entries_arr(99)); writeline(output, v_line_in); end if;
    -- Map variables to signals
    TPROJ_L3PHICn4_data_arr            <= v_TPROJ_L3PHICn4_data_arr;
    TPROJ_L3PHICn4_n_entries_arr       <= v_TPROJ_L3PHICn4_n_entries_arr;
    VMSME_L3PHIC17to24n1_data_arr      <= v_VMSME_L3PHIC17to24n1_data_arr;
    VMSME_L3PHIC17to24n1_n_entries_arr <= v_VMSME_L3PHIC17to24n1_n_entries_arr;
    AS_L3PHICn4_data_arr               <= v_AS_L3PHICn4_data_arr;
    AS_L3PHICn4_n_entries_arr          <= v_AS_L3PHICn4_n_entries_arr;
    wait;
  end process read_data;

  --! @brief Playback process ---------------------------------------
  --! @details Generate additional input signals and align memory arrays access
  --!         for playback to the memory modules of the HLS processing modules.
  --! @EventCnt=-1: PR_start=0, write TPROJ page1,
  --! @EventCnt=0:  PR_start=1, write TPROJ page2, write VMSME page1
  --! @EventCnt=1:  PR_start=1, write TPROJ page1, write VMSME page2, write AS page1
  --! @EventCnt=2:  PR_start=1, write TPROJ page2, write VMSME page3, write AS page2
  --! @EventCnt=3:  PR_start=1, write TPROJ page1, write VMSME page4, write AS page3
  --! ...
  playback : process
    variable v_page_cnt2_d0            : integer := 0; -- Page counter 
    variable v_page_cnt2_d1            : integer := 0; -- Page counter delayed by one
    variable v_page_cnt8               : integer := 0; -- Page counter
    variable v_VMSME_n_entries_bin     : t_arr_1d_int(0 to N_ME_IN_CHAIN-1) := (others => 0); -- Number of VMSME entries per bin
    variable v_VMSME_n_entries_bin_cnt : t_arr_1d_int(0 to N_ME_IN_CHAIN-1) := (others => 0); -- Counter of VMSME entries per bin
    variable v_bin_cnt                 : t_arr_1d_int(0 to N_ME_IN_CHAIN-1) := (others => 0); -- Bin counter
    variable v_last_bin                : boolean := false; -- Last bin tag
    variable v_line_in : line; -- Line for debug
  begin
    wait for CLK_PERIOD; -- Let the read process finish
    reset <= '0';           -- Reset cycle
    l_BX : for v_bx_cnt in -1 to MAX_EVENTS+10 loop -- -1 (to write the first memories before starting) to 110 (+10 to let later modules and write finish)
      bx_cnt         <= v_bx_cnt;       -- Update the signal
      v_page_cnt2_d0 := v_bx_cnt mod 2;          -- mod 2
      v_page_cnt2_d1 := (v_bx_cnt+1) mod 2;      -- mod 2
      v_page_cnt8    := v_bx_cnt mod N_MEM_BINS; -- mod 8
      page_cnt2      <= v_page_cnt2_d0; -- Update the signal
      page_cnt8      <= v_page_cnt8;    -- Update the signal
      v_bin_cnt      := (others => 0);
      v_VMSME_n_entries_bin_cnt := (others => 0);
      PR_bx_in <= std_logic_vector(to_unsigned(v_bx_cnt, PR_bx_in'length));
      l_addr : for addr in 0 to MAX_ENTRIES-1 loop -- 0 to 107
        l_copies : for cp in 0 to N_ME_IN_CHAIN-1 loop -- 0 to 7 -- Unable to assign arrays directly
          v_last_bin := false; -- Default assigment
          -- TPROJ
          if (v_bx_cnt<MAX_EVENTS-1) then -- Start early
            TPROJ_L3PHIC_dataarray_data_V_wea <= (others => '1');
            TPROJ_L3PHIC_dataarray_data_V_writeaddr(cp) <= std_logic_vector(to_unsigned(addr+PAGE_OFFSET*v_page_cnt2_d1, TPROJ_L3PHIC_dataarray_data_V_writeaddr(0)'length));
            TPROJ_L3PHIC_dataarray_data_V_din(cp)       <= TPROJ_L3PHICn4_data_arr(cp)(v_bx_cnt+1,addr+PAGE_OFFSET*v_page_cnt2_d1) (TPROJ_L3PHIC_dataarray_data_V_din(0)'length-1 downto 0);
          end if;
          -- VMSME & PR_start
          --PR_start <= '0'; -- Default assigment
          if (v_bx_cnt>=VMSME_DELAY and v_bx_cnt<MAX_EVENTS) then -- Start after delay of BXs
            PR_start <= '1';
            VMSME_L3PHIC17to24n1_dataarray_data_V_wea(cp) <= '1';                                     -- Default assigment
            if v_bin_cnt(cp)<=N_MEM_BINS-1 then -- Valid bin
              v_VMSME_n_entries_bin(cp) := VMSME_L3PHIC17to24n1_n_entries_arr(cp)(v_bx_cnt-VMSME_DELAY,v_bin_cnt(cp));
            end if;
            l_bin_empty : while (v_VMSME_n_entries_bin(cp)<=0) loop -- Bin empty
              v_bin_cnt(cp)             := v_bin_cnt(cp) +1; -- Skip empty bin
              if v_bin_cnt(cp)<=N_MEM_BINS-1 then -- Valid bin
                v_VMSME_n_entries_bin(cp) := VMSME_L3PHIC17to24n1_n_entries_arr(cp)(v_bx_cnt-VMSME_DELAY,v_bin_cnt(cp));
              else
                v_bin_cnt(cp) := N_MEM_BINS;
                exit;
              end if;
            end loop l_bin_empty;
            if v_bin_cnt(cp)<=N_MEM_BINS-1 then -- Valid bin
              VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(cp) <=                            std_logic_vector(to_unsigned((v_bin_cnt(cp)*N_ENTRIES_PER_MEM_BINS+v_VMSME_n_entries_bin_cnt(cp)) + (PAGE_OFFSET*((v_page_cnt8-VMSME_DELAY) mod N_MEM_BINS)), VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(0)'length));
              VMSME_L3PHIC17to24n1_dataarray_data_V_din(cp)       <= VMSME_L3PHIC17to24n1_data_arr(cp)(v_bx_cnt-VMSME_DELAY, (v_bin_cnt(cp)*N_ENTRIES_PER_MEM_BINS+v_VMSME_n_entries_bin_cnt(cp)) + (PAGE_OFFSET*((v_page_cnt8-VMSME_DELAY) mod N_MEM_BINS))) (VMSME_L3PHIC17to24n1_dataarray_data_V_din(0)'length-1 downto 0);
              if (DEBUG=true and ((v_bx_cnt=9 and cp=6) or (v_bx_cnt=23 and cp=4))) then write(v_line_in, string'("v_bx_cnt: ")); write(v_line_in, v_bx_cnt); write(v_line_in, string'(";   cp: ")); write(v_line_in, cp); writeline(output, v_line_in); end if;
              if (DEBUG=true and ((v_bx_cnt=9 and cp=6) or (v_bx_cnt=23 and cp=4))) then write(v_line_in, string'("VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(cp): ")); write(v_line_in, ((v_bin_cnt(cp)*N_ENTRIES_PER_MEM_BINS+v_VMSME_n_entries_bin_cnt(cp)) + (PAGE_OFFSET*((v_page_cnt8-VMSME_DELAY) mod N_MEM_BINS)))); writeline(output, v_line_in); end if;
              if (DEBUG=true and ((v_bx_cnt=9 and cp=6) or (v_bx_cnt=23 and cp=4))) then write(v_line_in, string'("VMSME_L3PHIC17to24n1_dataarray_data_V_din(cp): ")); hwrite(v_line_in, VMSME_L3PHIC17to24n1_data_arr(cp)(v_bx_cnt-VMSME_DELAY, (v_bin_cnt(cp)*N_ENTRIES_PER_MEM_BINS+v_VMSME_n_entries_bin_cnt(cp)) + (PAGE_OFFSET*((v_page_cnt8-VMSME_DELAY) mod N_MEM_BINS))) (VMSME_L3PHIC17to24n1_dataarray_data_V_din(0)'length-1 downto 0)); writeline(output, v_line_in); end if;
              if (DEBUG=true and ((v_bx_cnt=9 and cp=6) or (v_bx_cnt=23 and cp=4))) then write(v_line_in, string'("v_VMSME_n_entries_bin_cnt(cp): ")); write(v_line_in, v_VMSME_n_entries_bin_cnt(cp)); write(v_line_in, string'(";   v_VMSME_n_entries_bin(cp): ")); write(v_line_in, v_VMSME_n_entries_bin(cp)); write(v_line_in, string'(";   v_bin_cnt(cp): ")); write(v_line_in, v_bin_cnt(cp)); writeline(output, v_line_in); end if;
            end if;
            --if DEBUG=true then assert (addr>1 or v_bx_cnt>0) report "addr = " & integer'image(addr) & ";   cp = " & integer'image(addr) & ";   v_bin_cnt(0) = " & integer'image(v_bin_cnt(0)) & ";   v_VMSME_n_entries_bin_cnt(cp) = " & integer'image(v_VMSME_n_entries_bin_cnt(cp)) & ";   waddr = " & integer'image((v_bin_cnt(0)*N_ENTRIES_PER_MEM_BINS+v_VMSME_n_entries_bin_cnt(cp)) + (PAGE_OFFSET*((v_page_cnt8-VMSME_DELAY) mod N_MEM_BINS))) severity note; end if;
            if v_VMSME_n_entries_bin_cnt(cp)>=v_VMSME_n_entries_bin(cp)-1 then -- End of bin entries
              if (v_bin_cnt(cp)=N_MEM_BINS-1) then -- Last bin
                v_last_bin := true;
              end if;
              v_bin_cnt(cp)                 := v_bin_cnt(cp) +1;
              v_VMSME_n_entries_bin_cnt(cp) := 0;
              if (v_bin_cnt(cp)>=N_MEM_BINS) then
                v_bin_cnt(cp)               := N_MEM_BINS; -- End of write for this addr
              end if;
            else
              v_VMSME_n_entries_bin_cnt(cp) := v_VMSME_n_entries_bin_cnt(cp) +1;
            end if;
            if v_bin_cnt(cp)>N_MEM_BINS-1 then -- Invalid bin
              v_bin_cnt(cp) := N_MEM_BINS; 
              if v_last_bin=false then
                VMSME_L3PHIC17to24n1_dataarray_data_V_wea(cp) <= '0';
              end if;
            end if;
          end if;
          -- AS
          if (v_bx_cnt>=AS_DELAY and v_bx_cnt<MAX_EVENTS-1) then -- Start after delay of BXs
            AS_L3PHICn4_dataarray_data_V_wea <= '1';
            AS_L3PHICn4_dataarray_data_V_writeaddr  <= std_logic_vector(to_unsigned(addr+(PAGE_OFFSET*((v_page_cnt8-AS_DELAY) mod N_MEM_BINS)),AS_L3PHICn4_dataarray_data_V_writeaddr'length));
            AS_L3PHICn4_dataarray_data_V_din        <= AS_L3PHICn4_data_arr(v_bx_cnt-AS_DELAY,addr+(PAGE_OFFSET*((v_page_cnt8-AS_DELAY) mod N_MEM_BINS))) (AS_L3PHICn4_dataarray_data_V_din'length-1 downto 0); 
          end if;
        end loop l_copies;
        wait for CLK_PERIOD; -- Main time control
        --if DEBUG=true then assert (v_bx_cnt>0) report "addr = " & integer'image(addr) & ";   VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(0) = " & integer'image(to_integer(unsigned(VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(0)))) severity note; end if;
      end loop l_addr;
    end loop l_BX;
    wait for CLK_PERIOD;
  end process playback;


  --! @brief TextIO process for writting the output ---------------------------------------
  --! @details Read memory outputs (from last HLS module in the chain) and write it to files including headers.
  -- TODO: Replace with write procedures (e.g. like CM) but take MEM_READ_DELAY into account because it is the read port
  write_result : process
    file     file_out_L1L2 : text open WRITE_MODE is FILE_OUT_FM(0); -- Text - a file of character strings
    file     file_out_L5L6 : text open WRITE_MODE is FILE_OUT_FM(1); -- Text - a file of character strings
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
    wait until rising_edge(MC_done); -- Wait for first result
    l_BX : for v_bx_cnt in 0 to MAX_EVENTS-1 loop -- 0 to 99
      l_addr : for addr in 0 to MAX_ENTRIES-1+MEM_READ_DELAY loop -- 0 to 109
        if (addr <= MAX_ENTRIES-1) then -- w/o MEM_READ_DELAY
          if (v_bx_cnt mod 2)=0 then -- 1. page
            if (addr < (to_integer(unsigned(FM_L1L2_L3PHIC_nentries_V_dout(0))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_L1L2_L3PHIC_dataarray_data_V_enb <= '1';
            else
              FM_L1L2_L3PHIC_dataarray_data_V_enb <= '0';
            end if;
            if (addr < (to_integer(unsigned(FM_L5L6_L3PHIC_nentries_V_dout(0))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_L5L6_L3PHIC_dataarray_data_V_enb <= '1';
            else
              FM_L5L6_L3PHIC_dataarray_data_V_enb <= '0';
            end if;
          else                       -- 2. page
            if (addr < (to_integer(unsigned(FM_L1L2_L3PHIC_nentries_V_dout(1))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_L1L2_L3PHIC_dataarray_data_V_enb <= '1';
            else
              FM_L1L2_L3PHIC_dataarray_data_V_enb <= '0';
            end if;
            if (addr < (to_integer(unsigned(FM_L5L6_L3PHIC_nentries_V_dout(1))))) then -- Only read number of entries: Switch off in complete read out mode
              FM_L5L6_L3PHIC_dataarray_data_V_enb <= '1';
            else
              FM_L5L6_L3PHIC_dataarray_data_V_enb <= '0';
            end if;
          end if;
        end if;
        FM_L1L2_L3PHIC_dataarray_data_V_readaddr <= std_logic_vector(to_unsigned(addr+(PAGE_OFFSET*(v_bx_cnt mod 2)),FM_L1L2_L3PHIC_dataarray_data_V_readaddr'length));
        FM_L5L6_L3PHIC_dataarray_data_V_readaddr <= std_logic_vector(to_unsigned(addr+(PAGE_OFFSET*(v_bx_cnt mod 2)),FM_L5L6_L3PHIC_dataarray_data_V_readaddr'length));
        wait for 0 ns; -- Update signals
        -- Other writes ---------------------------------------
        if (addr >= MEM_READ_DELAY) then -- Take read dealy into account
          write(v_line, NOW, right, 20); -- NOW = current simulation time
          write(v_line, v_bx_cnt, right, 4);
          --write(v_line, string'("0x"), right, 4); hwrite(v_line, std_logic_vector(to_unsigned(addr,10)), right, 3);
          write(v_line, string'("0b"), right, 5);   write(v_line, reset, right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_L1L2_L3PHIC_nentries_V_dout(0), right, 2);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_L1L2_L3PHIC_nentries_V_dout(1), right, 2);
          write(v_line, string'("0b"), right, 3);   write(v_line, v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1), right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, std_logic_vector(unsigned(FM_L1L2_L3PHIC_dataarray_data_V_readaddr)-to_unsigned(MEM_READ_DELAY,FM_L1L2_L3PHIC_dataarray_data_V_readaddr'length)), right, 2);
          if (v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1)='1') then -- Only write if enable (delayed): Switch off in complete read out mode
            write(v_line, string'("0x"), right, 25); hwrite(v_line, FM_L1L2_L3PHIC_dataarray_data_V_dout, right, 12);
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
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_L5L6_L3PHIC_nentries_V_dout(0), right, 2);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, FM_L5L6_L3PHIC_nentries_V_dout(1), right, 2);
          write(v_line, string'("0b"), right, 3);   write(v_line, v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1), right, 1);
          write(v_line, string'("0x"), right, 7);  hwrite(v_line, std_logic_vector(unsigned(FM_L5L6_L3PHIC_dataarray_data_V_readaddr)-to_unsigned(MEM_READ_DELAY,FM_L5L6_L3PHIC_dataarray_data_V_readaddr'length)), right, 2);
          if (v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-1)='1') then -- Only write if enable (delayed): Switch off in complete read out mode
            write(v_line, string'("0x"), right, 27); hwrite(v_line, FM_L5L6_L3PHIC_dataarray_data_V_dout, right, 12);
          else
            write(v_line, string'("0x"), right, 27);  write(v_line, string'("000000000000"), right, 12);
          end if;
          write(v_line, string'("0b"), right, 8);   write(v_line, MC_done, right, 1);
          write(v_line, string'("0b"), right, 13);  write(v_line, MC_bx_out_vld, right, 1);
          write(v_line, string'("0x"), right, 9);  hwrite(v_line, MC_bx_out, right, 1);
          writeline (file_out_L5L6, v_line); -- Write line
        end if;
        v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d :=  v_FM_L1L2_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-2 downto 0) & FM_L1L2_L3PHIC_dataarray_data_V_enb; -- Required delay
        v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d :=  v_FM_L5L6_L3PHIC_dataarray_data_V_enb_d(MEM_READ_DELAY-2 downto 0) & FM_L5L6_L3PHIC_dataarray_data_V_enb; -- Required delay
        if (DEBUG=true and v_bx_cnt<=5 and addr<=10) then write(v_line, string'("v_bx_cnt: ")); write(v_line, v_bx_cnt); write(v_line, string'("   FM_L1L2_L3PHIC readaddr: ")); hwrite(v_line, FM_L1L2_L3PHIC_dataarray_data_V_readaddr); write(v_line, string'(", dout: ")); hwrite(v_line, FM_L1L2_L3PHIC_dataarray_data_V_dout); writeline(output, v_line); end if;
        wait for CLK_PERIOD; -- Main time control
      end loop l_addr;
    end loop l_BX;
    file_close(file_out_L1L2);
    file_close(file_out_L5L6);
    assert false report "Simulation finished!" severity FAILURE;
  end process write_result;

  -- ########################### Instantiation ###########################
  -- Instantiate the Unit Under Test (UUT)
  i_tf_top_full : if INST_TOP_TF = 1 generate
    uut : entity work.tf_top_full
      port map(
        clk       => clk,
        reset     => reset,
        PR_start  => PR_start,
        PR_idle   => PR_idle,
        PR_ready  => PR_ready,
        PR_bx_in  => PR_bx_in,
        -- TrackletProjections input
        TPROJ_L3PHIC_dataarray_data_V_wea       => TPROJ_L3PHIC_dataarray_data_V_wea,
        TPROJ_L3PHIC_dataarray_data_V_writeaddr => TPROJ_L3PHIC_dataarray_data_V_writeaddr,
        TPROJ_L3PHIC_dataarray_data_V_din       => TPROJ_L3PHIC_dataarray_data_V_din,
        -- VMStubsME input
        VMSME_L3PHIC17to24n1_dataarray_data_V_wea       => VMSME_L3PHIC17to24n1_dataarray_data_V_wea,
        VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr,
        VMSME_L3PHIC17to24n1_dataarray_data_V_din       => VMSME_L3PHIC17to24n1_dataarray_data_V_din,
        -- AllStubs input
        AS_L3PHICn4_dataarray_data_V_wea       => AS_L3PHICn4_dataarray_data_V_wea,
        AS_L3PHICn4_dataarray_data_V_writeaddr => AS_L3PHICn4_dataarray_data_V_writeaddr,
        AS_L3PHICn4_dataarray_data_V_din       => AS_L3PHICn4_dataarray_data_V_din,
        -- VMProjection output
        VMPROJ_L3PHIC17to24_dataarray_data_V_wea       => VMPROJ_L3PHIC17to24_dataarray_data_V_wea,
        VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr => VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr,
        VMPROJ_L3PHIC17to24_dataarray_data_V_din       => VMPROJ_L3PHIC17to24_dataarray_data_V_din,
        -- AllProjection output
        AP_L3PHIC_dataarray_data_V_wea       => AP_L3PHIC_dataarray_data_V_wea,
        AP_L3PHIC_dataarray_data_V_writeaddr => AP_L3PHIC_dataarray_data_V_writeaddr,
        AP_L3PHIC_dataarray_data_V_din       => AP_L3PHIC_dataarray_data_V_din,
        -- ProjectionRouter output
        PR_bx_out     => PR_bx_out,
        PR_bx_out_vld => PR_bx_out_vld,
        PR_done       => PR_done,
        -- CandidateMatch output
        CM_L3PHIC17to24_dataarray_data_V_wea       => CM_L3PHIC17to24_dataarray_data_V_wea,
        CM_L3PHIC17to24_dataarray_data_V_writeaddr => CM_L3PHIC17to24_dataarray_data_V_writeaddr,
        CM_L3PHIC17to24_dataarray_data_V_din       => CM_L3PHIC17to24_dataarray_data_V_din,
        -- MatchEngine output
        ME_bx_out     => ME_bx_out,
        ME_bx_out_vld => ME_bx_out_vld,
        ME_all_done   => ME_all_done,
        -- FullMatches output
        FM_L1L2_L3PHIC_dataarray_data_V_enb      => FM_L1L2_L3PHIC_dataarray_data_V_enb,
        FM_L1L2_L3PHIC_dataarray_data_V_readaddr => FM_L1L2_L3PHIC_dataarray_data_V_readaddr,
        FM_L1L2_L3PHIC_dataarray_data_V_dout     => FM_L1L2_L3PHIC_dataarray_data_V_dout,
        FM_L1L2_L3PHIC_nentries_V_dout           => FM_L1L2_L3PHIC_nentries_V_dout,
        FM_L5L6_L3PHIC_dataarray_data_V_enb      => FM_L5L6_L3PHIC_dataarray_data_V_enb,
        FM_L5L6_L3PHIC_dataarray_data_V_readaddr => FM_L5L6_L3PHIC_dataarray_data_V_readaddr,
        FM_L5L6_L3PHIC_dataarray_data_V_dout     => FM_L5L6_L3PHIC_dataarray_data_V_dout,
        FM_L5L6_L3PHIC_nentries_V_dout           => FM_L5L6_L3PHIC_nentries_V_dout,
        -- MatchCalculator output
        MC_bx_out     => MC_bx_out,
        MC_bx_out_vld => MC_bx_out_vld,
        MC_done       => MC_done );
    --! @brief TextIO process for writting the output ---------------------------------------
    --! @details Read additional memory outputs (from intermediate HLS modules in the chain) and
    --!         write it to files using procedures.
    write_result_AP : process
      variable v_bx_cnt      : integer       := -1; --! BX counter
    begin
      wait until PR_start = '1'; -- Wait to start
      write_header_line(FILE_OUT_AP, "AP_L3PHIC_dataarray_data_V_din", 8);
      l_BX : while v_bx_cnt <= MAX_EVENTS-1 loop
        if (AP_L3PHIC_dataarray_data_V_writeaddr(6 downto 0) = b"000_0000") and
           (AP_L3PHIC_dataarray_data_V_wea = '1') then -- Start new event assuming all addr behave the same
          v_bx_cnt := v_bx_cnt + 1;
        end if;
        if (AP_L3PHIC_dataarray_data_V_wea='1') then -- Only write valid data
          write_emData_line_8p(reset, v_bx_cnt, PR_done, PR_bx_out, PR_bx_out_vld, FILE_OUT_AP, "AP_L3PHIC_dataarray_data_V_din",
                               AP_L3PHIC_dataarray_data_V_din, AP_L3PHIC_dataarray_data_V_wea, AP_L3PHIC_dataarray_data_V_writeaddr,
                               (others => (others => '0')), (others => '0') );
        end if;
        wait for CLK_PERIOD; -- Main time control
      end loop l_BX;
      wait;
    end process write_result_AP;
    --! @brief TextIO process for writting the output ---------------------------------------
    write_result_VMP : process
      variable v_bx_cnt      : integer       := -1; --! BX counter
      variable myarray2_8b   : t_arr2_8b := (others => (others => '0')); -- Temporary array to avoid sim error
      variable myarray2_1b   : t_arr2_1b := (others => '0'); -- Temporary array to avoid sim error
      variable v_addr_d1     : t_arr8_8b := (others => (others => '0')); -- Delayed address
    begin
      wait until PR_start = '1'; -- Wait to start
      l_copies_header : for cp in 0 to N_ME_IN_CHAIN-1 loop -- 0 to 7
        write_header_line(FILE_OUT_VMP(cp), "VMPROJ_L3PHIC17to24_dataarray_data_V_din", 2);
      end loop l_copies_header;
      l_BX : while v_bx_cnt <= MAX_EVENTS-1 loop
        if (VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(0)(6 downto 0) = b"000_0000") and
           v_addr_d1(0)(7) /= VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(0)(7) then -- Start new event assuming all addr behave the same
          v_bx_cnt := v_bx_cnt + 1;
        end if;
        l_copies : for cp in 0 to N_ME_IN_CHAIN-1 loop -- 0 to 7
          if (VMPROJ_L3PHIC17to24_dataarray_data_V_wea(cp)='1') then -- Only write valid data
            write_emData_line_2p(reset, v_bx_cnt, PR_done, PR_bx_out, PR_bx_out_vld, FILE_OUT_VMP(cp), "VMPROJ_L3PHIC17to24_dataarray_data_V_din",
                                 VMPROJ_L3PHIC17to24_dataarray_data_V_din(cp), VMPROJ_L3PHIC17to24_dataarray_data_V_wea(cp), VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr(cp),
                                 myarray2_8b, myarray2_1b );
          end if;
        end loop l_copies;
        v_addr_d1 := VMPROJ_L3PHIC17to24_dataarray_data_V_writeaddr; -- Delay the address
        wait for CLK_PERIOD; -- Main time control
      end loop l_BX;
      wait;
    end process write_result_VMP;
    --! @brief TextIO process for writting the output ---------------------------------------
    --! @details Read additional memory outputs (from intermediate HLS modules in the chain) and
    --!         write it to files using procedures.
    write_result_CM : process
      variable v_bx_cnt    : integer       := -1; --! BX counter
      variable myarray2_8b : t_arr2_8b := (others => (others => '0')); -- Temporary array to avoid sim error
      variable myarray2_1b : t_arr2_1b := (others => '0'); -- Temporary array to avoid sim error
      variable v_addr_d1   : t_arr8_8b := (others => (others => '0')); -- Delayed address
    begin
      wait until PR_done = '1'; -- Wait to start = ME_start
      l_copies_header : for cp in 0 to N_ME_IN_CHAIN-1 loop -- 0 to 7
        write_header_line(FILE_OUT_CM(cp), "CM_L3PHIC17to24_dataarray_data_V_din", 2);
      end loop l_copies_header;
      l_BX : while v_bx_cnt <= MAX_EVENTS-1 loop
        if (CM_L3PHIC17to24_dataarray_data_V_writeaddr(0)(6 downto 0) = b"000_0000") and
           v_addr_d1(0)(7) /= CM_L3PHIC17to24_dataarray_data_V_writeaddr(0)(7) then -- Start new event assuming all addr behave the same
          v_bx_cnt := v_bx_cnt + 1;
        end if;
        l_copies : for cp in 0 to N_ME_IN_CHAIN-1 loop -- 0 to 7
          if (CM_L3PHIC17to24_dataarray_data_V_wea(cp)='1') then
           write_emData_line_2p(reset, v_bx_cnt, ME_all_done, ME_bx_out(cp), ME_bx_out_vld(cp), FILE_OUT_CM(cp), "CM_L3PHIC17to24_dataarray_data_V_din",
                                 CM_L3PHIC17to24_dataarray_data_V_din(cp), CM_L3PHIC17to24_dataarray_data_V_wea(cp), CM_L3PHIC17to24_dataarray_data_V_writeaddr(cp),
                                 myarray2_8b, myarray2_1b );
          end if;
        end loop l_copies;
        v_addr_d1 := CM_L3PHIC17to24_dataarray_data_V_writeaddr; -- Delay the address
        wait for CLK_PERIOD; -- Main time control
      end loop l_BX;
      wait;
    end process write_result_CM;
  end generate;

  i_others : if INST_TOP_TF = 0 generate
    uut : entity work.SectorProcessor
      port map(
        clk                        => clk,
        reset                      => reset,
        ProjectionRouter_start     => PR_start,
        bx_in_ProjectionRouter     => PR_bx_in,
        bx_out_MatchCalculator     => MC_bx_out,
        bx_out_MatchCalculator_vld => MC_bx_out_vld,
        MatchCalculator_done       => MC_done,
        TPROJ_L1L2F_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(0),
        TPROJ_L1L2F_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(0),
        TPROJ_L1L2F_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(0),
        TPROJ_L1L2G_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(1),
        TPROJ_L1L2G_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(1),
        TPROJ_L1L2G_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(1),
        TPROJ_L1L2H_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(2),
        TPROJ_L1L2H_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(2),
        TPROJ_L1L2H_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(2),
        TPROJ_L1L2I_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(3),
        TPROJ_L1L2I_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(3),
        TPROJ_L1L2I_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(3),
        TPROJ_L1L2J_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(4),
        TPROJ_L1L2J_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(4),
        TPROJ_L1L2J_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(4),
        TPROJ_L5L6B_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(5),
        TPROJ_L5L6B_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(5),
        TPROJ_L5L6B_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(5),
        TPROJ_L5L6C_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(6),
        TPROJ_L5L6C_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(6),
        TPROJ_L5L6C_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(6),
        TPROJ_L5L6D_L3PHIC_dataarray_data_V_wea       =>           TPROJ_L3PHIC_dataarray_data_V_wea(7),
        TPROJ_L5L6D_L3PHIC_dataarray_data_V_writeaddr =>     TPROJ_L3PHIC_dataarray_data_V_writeaddr(7),
        TPROJ_L5L6D_L3PHIC_dataarray_data_V_din       =>           TPROJ_L3PHIC_dataarray_data_V_din(7),
        VMSME_L3PHIC17n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(0),
        VMSME_L3PHIC17n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(0),
        VMSME_L3PHIC17n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(0),
        VMSME_L3PHIC18n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(1),
        VMSME_L3PHIC18n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(1),
        VMSME_L3PHIC18n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(1),
        VMSME_L3PHIC19n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(2),
        VMSME_L3PHIC19n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(2),
        VMSME_L3PHIC19n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(2),
        VMSME_L3PHIC20n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(3),
        VMSME_L3PHIC20n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(3),
        VMSME_L3PHIC20n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(3),
        VMSME_L3PHIC21n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(4),
        VMSME_L3PHIC21n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(4),
        VMSME_L3PHIC21n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(4),
        VMSME_L3PHIC22n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(5),
        VMSME_L3PHIC22n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(5),
        VMSME_L3PHIC22n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(5),
        VMSME_L3PHIC23n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(6),
        VMSME_L3PHIC23n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(6),
        VMSME_L3PHIC23n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(6),
        VMSME_L3PHIC24n1_dataarray_data_V_wea       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_wea(7),
        VMSME_L3PHIC24n1_dataarray_data_V_writeaddr => VMSME_L3PHIC17to24n1_dataarray_data_V_writeaddr(7),
        VMSME_L3PHIC24n1_dataarray_data_V_din       =>       VMSME_L3PHIC17to24n1_dataarray_data_V_din(7),
        AS_L3PHICn6_dataarray_data_V_wea       => AS_L3PHICn4_dataarray_data_V_wea,
        AS_L3PHICn6_dataarray_data_V_writeaddr => AS_L3PHICn4_dataarray_data_V_writeaddr,
        AS_L3PHICn6_dataarray_data_V_din       => AS_L3PHICn4_dataarray_data_V_din,
        FM_L1L2_L3PHIC_dataarray_data_V_enb      => FM_L1L2_L3PHIC_dataarray_data_V_enb,
        FM_L1L2_L3PHIC_dataarray_data_V_readaddr => FM_L1L2_L3PHIC_dataarray_data_V_readaddr,
        FM_L1L2_L3PHIC_dataarray_data_V_dout     => FM_L1L2_L3PHIC_dataarray_data_V_dout,
        FM_L1L2_L3PHIC_nentries_VV_dout          => FM_L1L2_L3PHIC_nentries_V_dout,
        FM_L5L6_L3PHIC_dataarray_data_V_enb      => FM_L5L6_L3PHIC_dataarray_data_V_enb,
        FM_L5L6_L3PHIC_dataarray_data_V_readaddr => FM_L5L6_L3PHIC_dataarray_data_V_readaddr,
        FM_L5L6_L3PHIC_dataarray_data_V_dout     => FM_L5L6_L3PHIC_dataarray_data_V_dout,
        FM_L5L6_L3PHIC_nentries_VV_dout          => FM_L5L6_L3PHIC_nentries_V_dout   );
  end generate;


end behavior;
