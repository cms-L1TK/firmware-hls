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

  constant CLK_PERIOD           : time    := 25.0 ns;       --! 40 MHz
  constant DEBUG                : boolean := False;      --! Debug off/on

  -- Paths of data files specified relative to Vivado project's xsim directory.
  -- e.g. IntegrationTests/PRMEMC/script/Work/Work.sim/sim_1/behav/xsim/
  constant memPrintsDir         : string := "../../../../../MemPrints/";
  constant dataOutDir           : string := "../../../../../dataOut/";

  -- File directories and the start of the file names that memories have in common
  -- Input files
  constant FILE_IN_AS_36        : string := memPrintsDir&"Stubs/AllStubs_";
  constant FILE_IN_MPAR_73      : string := memPrintsDir&"TrackletParameters/TrackletParameters_";
  -- Output files
  constant FILE_OUT_AS_36       : string := dataOutDir;
  constant FILE_OUT_VMSME_16    : string := dataOutDir;
  constant FILE_OUT_VMSME_17    : string := dataOutDir;
  constant FILE_OUT_MPAR_73     : string := dataOutDir;
  constant FILE_OUT_MPROJ_60    : string := dataOutDir;
  constant FILE_OUT_MPROJ_58    : string := dataOutDir;
  constant FILE_OUT_MPROJ_59    : string := dataOutDir;
  constant FILE_OUT_FM_52       : string := dataOutDir;
  constant FILE_OUT_FM_55       : string := dataOutDir;
  constant FILE_OUT_TW_113      : string := dataOutDir;
  constant FILE_OUT_DW_49       : string := dataOutDir;
  constant FILE_OUT_BW_46       : string := dataOutDir;
  -- Debug output files to check input was correctly read.
  constant FILE_OUT_AS_debug    : string := dataOutDir;
  constant FILE_OUT_MPAR_debug  : string := dataOutDir;

  -- File name endings
  constant inputFileNameEnding  : string := "_04.dat"; -- 04 specifies the nonant/sector the testvectors represent
  constant outputFileNameEnding : string := ".txt";
  constant debugFileNameEnding  : string := ".debug.txt";

constant FILE_OUT_TF          : string := dataOutDir&"TF_";
  -- ########################### Signals ###########################
  -- ### UUT signals ###
  signal clk                        : std_logic := '0';
  signal clk240                     : std_logic;
  signal clk360                     : std_logic;
  signal locked                     : std_logic;
  signal reset                      : std_logic := '1';
  signal PC_start                   : std_logic := '0';
  signal PC_idle                    : std_logic := '0';
  signal PC_ready                   : std_logic := '0';
  signal PC_bx_in                   : std_logic_vector(2 downto 0) := (others => '1');
  signal VMSMER_bx_out              : std_logic_vector(2 downto 0) := (others => '1');
  signal VMSMER_bx_out_vld          : std_logic := '0';
  signal VMSMER_done                : std_logic := '0';
  signal PC_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal PC_bx_out_vld              : std_logic := '0';
  signal PC_done                    : std_logic := '0';
  signal MP_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal MP_bx_out_vld              : std_logic := '0';
  signal MP_done                    : std_logic := '0';
  signal TB_bx_out                  : std_logic_vector(2 downto 0) := (others => '1');
  signal TB_bx_out_vld              : std_logic := '0';
  signal TB_done                    : std_logic := '0';
  signal TB_AAAA_last_track         : std_logic := '0';
  signal TB_AAAA_last_track_vld     : std_logic := '0';
  signal TB_BBBB_last_track         : std_logic := '0';
  signal TB_BBBB_last_track_vld     : std_logic := '0';

  -- Signals matching ports of top-level VHDL
  signal AS_L1PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIEin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIEin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIEin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIFin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIFin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIFin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIGin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIGin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIGin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIHin_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIHin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIHin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHIAin_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHIAin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHIAin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHIBin_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHIBin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHIBin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHICin_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHICin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHICin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHIDin_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHIDin_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHIDin_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIEn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIEn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIEn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIFn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIFn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIFn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIGn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIGn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIGn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L1PHIHn2_wea            : t_AS_36_1b           := '0';
  signal AS_L1PHIHn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L1PHIHn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L2PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_L2PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L2PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L3PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_L3PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L3PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L4PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_L4PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L4PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L5PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_L5PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L5PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_L6PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_L6PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_L6PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D1PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_D1PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D1PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D2PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_D2PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D2PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D3PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_D3PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D3PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D4PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_D4PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D4PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHIAn2_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHIAn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHIAn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHIBn2_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHIBn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHIBn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHICn2_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHICn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHICn2_din            : t_AS_36_DATA         := (others => '0');
  signal AS_D5PHIDn2_wea            : t_AS_36_1b           := '0';
  signal AS_D5PHIDn2_writeaddr      : t_AS_36_ADDR         := (others => '0');
  signal AS_D5PHIDn2_din            : t_AS_36_DATA         := (others => '0');
  signal VMSME_L1PHIAn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIAn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIAn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHIBn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIBn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIBn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHICn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHICn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHICn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHIDn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIDn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIDn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHIEn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIEn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIEn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHIFn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIFn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIFn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHIGn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIGn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIGn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L1PHIHn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L1PHIHn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L1PHIHn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L2PHIAn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L2PHIAn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L2PHIAn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L2PHIBn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L2PHIBn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L2PHIBn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L2PHICn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L2PHICn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L2PHICn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L2PHIDn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L2PHIDn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L2PHIDn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L3PHIAn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L3PHIAn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L3PHIAn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L3PHIBn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L3PHIBn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L3PHIBn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L3PHICn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L3PHICn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L3PHICn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L3PHIDn2_wea         : t_VMSME_16_1b        := '0';
  signal VMSME_L3PHIDn2_writeaddr   : t_VMSME_16_ADDR      := (others => '0');
  signal VMSME_L3PHIDn2_din         : t_VMSME_16_DATA      := (others => '0');
  signal VMSME_L4PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L4PHIAn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L4PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L4PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L4PHIBn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L4PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L4PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L4PHICn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L4PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L4PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L4PHIDn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L4PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L5PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L5PHIAn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L5PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L5PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L5PHIBn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L5PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L5PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L5PHICn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L5PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L5PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L5PHIDn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L5PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L6PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L6PHIAn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L6PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L6PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L6PHIBn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L6PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L6PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L6PHICn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L6PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_L6PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_L6PHIDn2_writeaddr   : t_VMSME_17_ADDR      := (others => '0');
  signal VMSME_L6PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D1PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D1PHIAn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D1PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D1PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D1PHIBn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D1PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D1PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D1PHICn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D1PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D1PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D1PHIDn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D1PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D2PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D2PHIAn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D2PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D2PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D2PHIBn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D2PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D2PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D2PHICn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D2PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D2PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D2PHIDn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D2PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D3PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D3PHIAn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D3PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D3PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D3PHIBn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D3PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D3PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D3PHICn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D3PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D3PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D3PHIDn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D3PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D4PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D4PHIAn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D4PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D4PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D4PHIBn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D4PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D4PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D4PHICn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D4PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D4PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D4PHIDn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D4PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D5PHIAn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D5PHIAn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D5PHIAn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D5PHIBn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D5PHIBn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D5PHIBn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D5PHICn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D5PHICn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D5PHICn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal VMSME_D5PHIDn2_wea         : t_VMSME_17_1b        := '0';
  signal VMSME_D5PHIDn2_writeaddr   : t_VMSME_17_ADDRDISK  := (others => '0');
  signal VMSME_D5PHIDn2_din         : t_VMSME_17_DATA      := (others => '0');
  signal MPAR_L1L2ABCin_wea         : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2ABCin_writeaddr   : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2ABCin_din         : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2DEin_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2DEin_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2DEin_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2Fin_wea           : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2Fin_writeaddr     : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2Fin_din           : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2Gin_wea           : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2Gin_writeaddr     : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2Gin_din           : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2HIin_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2HIin_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2HIin_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2JKLin_wea         : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2JKLin_writeaddr   : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2JKLin_din         : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L2L3ABCDin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_L2L3ABCDin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L2L3ABCDin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L3L4ABin_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L3L4ABin_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L3L4ABin_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L3L4CDin_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L3L4CDin_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L3L4CDin_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L5L6ABCDin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_L5L6ABCDin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L5L6ABCDin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_D1D2ABCDin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_D1D2ABCDin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_D1D2ABCDin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_D3D4ABCDin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_D3D4ABCDin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_D3D4ABCDin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1D1ABCDin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_L1D1ABCDin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1D1ABCDin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1D1EFGHin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_L1D1EFGHin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1D1EFGHin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L2D1ABCDin_wea        : t_MPAR_73_1b         := '0';
  signal MPAR_L2D1ABCDin_writeaddr  : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L2D1ABCDin_din        : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2ABC_wea           : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2ABC_writeaddr     : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2ABC_din           : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2DE_wea            : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2DE_writeaddr      : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2DE_din            : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2F_wea             : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2F_writeaddr       : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2F_din             : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2G_wea             : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2G_writeaddr       : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2G_din             : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2HI_wea            : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2HI_writeaddr      : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2HI_din            : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1L2JKL_wea           : t_MPAR_73_1b         := '0';
  signal MPAR_L1L2JKL_writeaddr     : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1L2JKL_din           : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L2L3ABCD_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L2L3ABCD_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L2L3ABCD_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L3L4AB_wea            : t_MPAR_73_1b         := '0';
  signal MPAR_L3L4AB_writeaddr      : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L3L4AB_din            : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L3L4CD_wea            : t_MPAR_73_1b         := '0';
  signal MPAR_L3L4CD_writeaddr      : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L3L4CD_din            : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L5L6ABCD_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L5L6ABCD_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L5L6ABCD_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_D1D2ABCD_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_D1D2ABCD_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_D1D2ABCD_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_D3D4ABCD_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_D3D4ABCD_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_D3D4ABCD_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1D1ABCD_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L1D1ABCD_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1D1ABCD_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L1D1EFGH_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L1D1EFGH_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L1D1EFGH_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPAR_L2D1ABCD_wea          : t_MPAR_73_1b         := '0';
  signal MPAR_L2D1ABCD_writeaddr    : t_MPAR_73_ADDR       := (others => '0');
  signal MPAR_L2D1ABCD_din          : t_MPAR_73_DATA       := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIA_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L1PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIA_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIB_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L1PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIB_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIC_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L1PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIC_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L1PHID_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L1PHID_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L1PHID_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L1PHID_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIE_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIE_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIE_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIE_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIE_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIE_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIE_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIE_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIE_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIE_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIE_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIE_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIE_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIE_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIE_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIF_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIF_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIF_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L1PHIF_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIF_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIF_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIF_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIF_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIF_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIF_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIF_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIF_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIF_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIF_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIF_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIG_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIG_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIG_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIG_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L1PHIG_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIG_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIG_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIG_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIG_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIG_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIG_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIG_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIG_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIG_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIG_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIG_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIG_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIG_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIH_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2L3ABCD_L1PHIH_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L1PHIH_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIH_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L1PHIH_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L1PHIH_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIH_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L1PHIH_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L1PHIH_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIH_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L1PHIH_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L1PHIH_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIH_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D3D4ABCD_L1PHIH_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_L1PHIH_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIH_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L2D1ABCD_L1PHIH_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_L1PHIH_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L2PHIA_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L2PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L2PHIA_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L2PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L2PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L2PHIB_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L2PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L2PHIB_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L2PHIB_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L2PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L2PHIB_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L2PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L2PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L2PHIC_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4AB_L2PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L2PHIC_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L2PHIC_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L2PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L2PHIC_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L2PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L2PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L2PHID_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L3L4CD_L2PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L2PHID_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L2PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L2PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_D1D2ABCD_L2PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_L2PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L3PHIA_wea   : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2ABC_L3PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L3PHIA_din   : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L3PHIA_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2DE_L3PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L3PHIA_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHIA_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L3PHIA_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHIA_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L3PHIB_wea   : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2ABC_L3PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L3PHIB_din   : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L3PHIB_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2DE_L3PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L3PHIB_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2F_L3PHIB_wea     : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2F_L3PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L3PHIB_din     : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2G_L3PHIB_wea     : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2G_L3PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L3PHIB_din     : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L3PHIB_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2HI_L3PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L3PHIB_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHIB_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L3PHIB_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHIB_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L3PHIC_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2DE_L3PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L3PHIC_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2F_L3PHIC_wea     : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2F_L3PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L3PHIC_din     : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2G_L3PHIC_wea     : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2G_L3PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L3PHIC_din     : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L3PHIC_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2HI_L3PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L3PHIC_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L3PHIC_wea   : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2JKL_L3PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L3PHIC_din   : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHIC_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L3PHIC_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHIC_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L3PHID_wea    : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2HI_L3PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L3PHID_din    : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L3PHID_wea   : t_MPROJ_60_1b        := '0';
  signal MPROJ_L1L2JKL_L3PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L3PHID_din   : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHID_wea  : t_MPROJ_60_1b        := '0';
  signal MPROJ_L5L6ABCD_L3PHID_writeaddr: t_MPROJ_60_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L3PHID_din  : t_MPROJ_60_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L4PHIA_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2ABC_L4PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L4PHIA_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L4PHIA_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L4PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L4PHIA_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L4PHIA_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L4PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L4PHIA_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHIA_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L4PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHIA_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHIA_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L5L6ABCD_L4PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHIA_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L4PHIB_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2ABC_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L4PHIB_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L4PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L4PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L4PHIB_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L4PHIB_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L4PHIB_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L4PHIB_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L4PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L4PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHIB_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHIB_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHIB_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L5L6ABCD_L4PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHIB_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L4PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L4PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L4PHIC_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L4PHIC_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L4PHIC_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L4PHIC_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L4PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L4PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L4PHIC_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2JKL_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L4PHIC_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHIC_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHIC_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHIC_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L5L6ABCD_L4PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHIC_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L4PHID_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L4PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L4PHID_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L4PHID_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L4PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L4PHID_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L4PHID_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2JKL_L4PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L4PHID_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHID_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L4PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L4PHID_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHID_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L5L6ABCD_L4PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L5L6ABCD_L4PHID_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L5PHIA_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2ABC_L5PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L5PHIA_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L5PHIA_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L5PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L5PHIA_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L5PHIA_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L5PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L5PHIA_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHIA_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L5PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHIA_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L5PHIA_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4AB_L5PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L5PHIA_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L5PHIB_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2ABC_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L5PHIB_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L5PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L5PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L5PHIB_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L5PHIB_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L5PHIB_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L5PHIB_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L5PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L5PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHIB_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHIB_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L5PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4AB_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L5PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L5PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4CD_L5PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L5PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L5PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L5PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L5PHIC_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L5PHIC_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L5PHIC_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L5PHIC_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L5PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L5PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L5PHIC_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2JKL_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L5PHIC_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHIC_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHIC_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L5PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4AB_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L5PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L5PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4CD_L5PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L5PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L5PHID_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L5PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L5PHID_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L5PHID_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L5PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L5PHID_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L5PHID_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2JKL_L5PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L5PHID_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHID_wea  : t_MPROJ_58_1b        := '0';
  signal MPROJ_L2L3ABCD_L5PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_L5PHID_din  : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L5PHID_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4CD_L5PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L5PHID_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L6PHIA_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2ABC_L6PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L6PHIA_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L6PHIA_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L6PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L6PHIA_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L6PHIA_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L6PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L6PHIA_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L6PHIA_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4AB_L6PHIA_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L6PHIA_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_L6PHIB_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2ABC_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_L6PHIB_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L6PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L6PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L6PHIB_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L6PHIB_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L6PHIB_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L6PHIB_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L6PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L6PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L6PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4AB_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L6PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L6PHIB_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4CD_L6PHIB_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L6PHIB_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2DE_L6PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2DE_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_L6PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2F_L6PHIC_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2F_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2F_L6PHIC_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L6PHIC_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L6PHIC_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L6PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L6PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L6PHIC_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2JKL_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L6PHIC_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4AB_L6PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4AB_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_L6PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L6PHIC_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4CD_L6PHIC_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L6PHIC_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2G_L6PHID_wea     : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2G_L6PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2G_L6PHID_din     : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2HI_L6PHID_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2HI_L6PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_L6PHID_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_L6PHID_wea   : t_MPROJ_58_1b        := '0';
  signal MPROJ_L1L2JKL_L6PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_L6PHID_din   : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L3L4CD_L6PHID_wea    : t_MPROJ_58_1b        := '0';
  signal MPROJ_L3L4CD_L6PHID_writeaddr: t_MPROJ_58_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_L6PHID_din    : t_MPROJ_58_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D1PHIA_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D1PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D1PHIA_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D1PHIA_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D1PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D1PHIA_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D1PHIA_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D1PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D1PHIA_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D1PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4AB_D1PHIA_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4AB_D1PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_D1PHIA_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D1PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D1PHIB_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D1PHIB_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D1PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D1PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D1PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D1PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D1PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D1PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D1PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D1PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4AB_D1PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4AB_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_D1PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4CD_D1PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4CD_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_D1PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D1PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D1PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D1PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D1PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D1PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D1PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D1PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D1PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D1PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D1PHIC_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D1PHIC_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4AB_D1PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4AB_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_D1PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4CD_D1PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4CD_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_D1PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D1PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D1PHID_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D1PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D1PHID_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D1PHID_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D1PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D1PHID_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D1PHID_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D1PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D1PHID_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D1PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D1PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4CD_D1PHID_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4CD_D1PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_D1PHID_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D1PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D1PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D2PHIA_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D2PHIA_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D2PHIA_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D2PHIA_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D2PHIA_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D2PHIA_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4AB_D2PHIA_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4AB_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_D2PHIA_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D2PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D2PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D2PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D2PHIB_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D2PHIB_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D2PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D2PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D2PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D2PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D2PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D2PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D2PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D2PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4AB_D2PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4AB_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_D2PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4CD_D2PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4CD_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_D2PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D2PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D2PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D2PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D2PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D2PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D2PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D2PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D2PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D2PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D2PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D2PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D2PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D2PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D2PHIC_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D2PHIC_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4AB_D2PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4AB_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4AB_D2PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4CD_D2PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4CD_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_D2PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D2PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D2PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D2PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D2PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D2PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D2PHID_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D2PHID_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D2PHID_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D2PHID_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D2PHID_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D2PHID_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D2PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L3L4CD_D2PHID_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L3L4CD_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L3L4CD_D2PHID_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D2PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D2PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D2PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D2PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D2PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D3PHIA_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D3PHIA_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D3PHIA_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D3PHIA_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D3PHIA_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D3PHIA_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D3PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D3PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D3PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D3PHIB_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D3PHIB_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D3PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D3PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D3PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D3PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D3PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D3PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D3PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D3PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D3PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D3PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D3PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D3PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D3PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D3PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D3PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D3PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D3PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D3PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D3PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D3PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D3PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D3PHIC_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D3PHIC_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D3PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D3PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D3PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D3PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D3PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D3PHID_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D3PHID_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D3PHID_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D3PHID_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D3PHID_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D3PHID_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D3PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D3PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D3PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D3PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D3PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D3PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D4PHIA_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D4PHIA_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D4PHIA_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D4PHIA_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D4PHIA_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D4PHIA_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D4PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D4PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D4PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2ABC_D4PHIB_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2ABC_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2ABC_D4PHIB_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D4PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D4PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D4PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D4PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D4PHIB_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D4PHIB_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D4PHIB_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D4PHIB_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D4PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D4PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D4PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D4PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D4PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2DE_D4PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2DE_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2DE_D4PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2F_D4PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2F_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2F_D4PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D4PHIC_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D4PHIC_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D4PHIC_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D4PHIC_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D4PHIC_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D4PHIC_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D4PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D4PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D4PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D4PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D4PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2G_D4PHID_wea     : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2G_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2G_D4PHID_din     : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2HI_D4PHID_wea    : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2HI_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2HI_D4PHID_din    : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1L2JKL_D4PHID_wea   : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1L2JKL_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1L2JKL_D4PHID_din   : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2L3ABCD_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2L3ABCD_D4PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D4PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D4PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D4PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L2D1ABCD_D4PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L2D1ABCD_D4PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D5PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D5PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D5PHIA_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D5PHIA_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D5PHIA_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D5PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D5PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D5PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D5PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D5PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D5PHIB_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D5PHIB_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D5PHIB_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D5PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D5PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1ABCD_D5PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1ABCD_D5PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1ABCD_D5PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D5PHIC_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D5PHIC_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D5PHIC_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D1D2ABCD_D5PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D1D2ABCD_D5PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_D3D4ABCD_D5PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_D3D4ABCD_D5PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal MPROJ_L1D1EFGH_D5PHID_wea  : t_MPROJ_59_1b        := '0';
  signal MPROJ_L1D1EFGH_D5PHID_writeaddr: t_MPROJ_59_ADDR      := (others => '0');
  signal MPROJ_L1D1EFGH_D5PHID_din  : t_MPROJ_59_DATA      := (others => '0');
  signal FM_AAAA_L1PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHID_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHID_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHIE_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIE_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIE_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIE_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIE_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIE_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHIF_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIF_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIF_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIF_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIF_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIF_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHIG_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIG_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIG_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIG_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIG_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIG_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L1PHIH_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L1PHIH_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L1PHIH_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L1PHIH_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L1PHIH_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L1PHIH_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L2PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L2PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L2PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L2PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L2PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L2PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L2PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L2PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L2PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L2PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L2PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L2PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L2PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L2PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L2PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L2PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L2PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L2PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L2PHID_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L2PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L2PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L2PHID_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L2PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L2PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L3PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L3PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L3PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L3PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L3PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L3PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L3PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L3PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L3PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L3PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L3PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L3PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L3PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L3PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L3PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L3PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L3PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L3PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L3PHID_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L3PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L3PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L3PHID_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L3PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L3PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L4PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L4PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L4PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L4PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L4PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L4PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L4PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L4PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L4PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L4PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L4PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L4PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L4PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L4PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L4PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L4PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L4PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L4PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L4PHID_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L4PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L4PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L4PHID_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L4PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L4PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L5PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L5PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L5PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L5PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L5PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L5PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L5PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L5PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L5PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L5PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L5PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L5PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L5PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L5PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L5PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L5PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L5PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L5PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L5PHID_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L5PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L5PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L5PHID_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L5PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L5PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L6PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L6PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L6PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L6PHIA_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L6PHIA_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L6PHIA_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L6PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L6PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L6PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L6PHIB_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L6PHIB_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L6PHIB_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L6PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L6PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L6PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L6PHIC_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L6PHIC_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L6PHIC_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_L6PHID_wea         : t_FM_52_1b           := '0';
  signal FM_AAAA_L6PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_AAAA_L6PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_BBBB_L6PHID_wea         : t_FM_52_1b           := '0';
  signal FM_BBBB_L6PHID_writeaddr   : t_FM_52_ADDR         := (others => '0');
  signal FM_BBBB_L6PHID_din         : t_FM_52_DATA         := (others => '0');
  signal FM_AAAA_D1PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D1PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D1PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D1PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D1PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D1PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D1PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D1PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D1PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D1PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D1PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D1PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D1PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D1PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D1PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D1PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D1PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D1PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D1PHID_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D1PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D1PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D1PHID_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D1PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D1PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D2PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D2PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D2PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D2PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D2PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D2PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D2PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D2PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D2PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D2PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D2PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D2PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D2PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D2PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D2PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D2PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D2PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D2PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D2PHID_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D2PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D2PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D2PHID_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D2PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D2PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D3PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D3PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D3PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D3PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D3PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D3PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D3PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D3PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D3PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D3PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D3PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D3PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D3PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D3PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D3PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D3PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D3PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D3PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D3PHID_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D3PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D3PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D3PHID_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D3PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D3PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D4PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D4PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D4PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D4PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D4PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D4PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D4PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D4PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D4PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D4PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D4PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D4PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D4PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D4PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D4PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D4PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D4PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D4PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D4PHID_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D4PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D4PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D4PHID_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D4PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D4PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D5PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D5PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D5PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D5PHIA_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D5PHIA_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D5PHIA_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D5PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D5PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D5PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D5PHIB_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D5PHIB_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D5PHIB_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D5PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D5PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D5PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D5PHIC_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D5PHIC_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D5PHIC_din         : t_FM_55_DATA         := (others => '0');
  signal FM_AAAA_D5PHID_wea         : t_FM_55_1b           := '0';
  signal FM_AAAA_D5PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_AAAA_D5PHID_din         : t_FM_55_DATA         := (others => '0');
  signal FM_BBBB_D5PHID_wea         : t_FM_55_1b           := '0';
  signal FM_BBBB_D5PHID_writeaddr   : t_FM_55_ADDR         := (others => '0');
  signal FM_BBBB_D5PHID_din         : t_FM_55_DATA         := (others => '0');
  signal TW_AAAA_stream_A_write     : t_TW_113_1b          := '0';
  signal TW_AAAA_stream_A_full_neg  : t_TW_113_1b          := '0';
  signal TW_AAAA_stream_AV_din      : t_TW_113_DATA        := (others => '0');
  signal TW_BBBB_stream_A_write     : t_TW_113_1b          := '0';
  signal TW_BBBB_stream_A_full_neg  : t_TW_113_1b          := '0';
  signal TW_BBBB_stream_AV_din      : t_TW_113_DATA        := (others => '0');
  signal DW_AAAA_D1_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_AAAA_D1_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_AAAA_D1_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_AAAA_D2_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_AAAA_D2_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_AAAA_D2_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_AAAA_D3_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_AAAA_D3_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_AAAA_D3_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_AAAA_D4_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_AAAA_D4_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_AAAA_D4_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_AAAA_D5_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_AAAA_D5_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_AAAA_D5_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_BBBB_D1_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_BBBB_D1_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_BBBB_D1_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_BBBB_D2_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_BBBB_D2_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_BBBB_D2_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_BBBB_D3_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_BBBB_D3_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_BBBB_D3_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_BBBB_D4_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_BBBB_D4_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_BBBB_D4_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal DW_BBBB_D5_stream_A_write  : t_DW_49_1b           := '0';
  signal DW_BBBB_D5_stream_A_full_neg: t_DW_49_1b           := '0';
  signal DW_BBBB_D5_stream_AV_din   : t_DW_49_DATA         := (others => '0');
  signal BW_AAAA_L1_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_AAAA_L1_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_AAAA_L1_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_AAAA_L2_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_AAAA_L2_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_AAAA_L2_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_AAAA_L3_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_AAAA_L3_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_AAAA_L3_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_AAAA_L4_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_AAAA_L4_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_AAAA_L4_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_AAAA_L5_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_AAAA_L5_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_AAAA_L5_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_AAAA_L6_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_AAAA_L6_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_AAAA_L6_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_BBBB_L1_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_BBBB_L1_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_BBBB_L1_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_BBBB_L2_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_BBBB_L2_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_BBBB_L2_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_BBBB_L3_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_BBBB_L3_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_BBBB_L3_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_BBBB_L4_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_BBBB_L4_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_BBBB_L4_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_BBBB_L5_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_BBBB_L5_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_BBBB_L5_stream_AV_din   : t_BW_46_DATA         := (others => '0');
  signal BW_BBBB_L6_stream_A_write  : t_BW_46_1b           := '0';
  signal BW_BBBB_L6_stream_A_full_neg: t_BW_46_1b           := '0';
  signal BW_BBBB_L6_stream_AV_din   : t_BW_46_DATA         := (others => '0');

  -- Indicates that writing of the initial memories of the first event has started.
  signal START_FIRST_WRITE : std_logic := '0';
  signal START_MPAR_L1L2ABCin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2DEin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2Fin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2Gin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2HIin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2JKLin : t_MPAR_73_1b := '0';
  signal START_MPAR_L2L3ABCDin : t_MPAR_73_1b := '0';
  signal START_MPAR_L3L4ABin : t_MPAR_73_1b := '0';
  signal START_MPAR_L3L4CDin : t_MPAR_73_1b := '0';
  signal START_MPAR_L5L6ABCDin : t_MPAR_73_1b := '0';
  signal START_MPAR_D1D2ABCDin : t_MPAR_73_1b := '0';
  signal START_MPAR_D3D4ABCDin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1D1ABCDin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1D1EFGHin : t_MPAR_73_1b := '0';
  signal START_MPAR_L2D1ABCDin : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2ABC : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2DE : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2F : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2G : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2HI : t_MPAR_73_1b := '0';
  signal START_MPAR_L1L2JKL : t_MPAR_73_1b := '0';
  signal START_MPAR_L2L3ABCD : t_MPAR_73_1b := '0';
  signal START_MPAR_L3L4AB : t_MPAR_73_1b := '0';
  signal START_MPAR_L3L4CD : t_MPAR_73_1b := '0';
  signal START_MPAR_L5L6ABCD : t_MPAR_73_1b := '0';
  signal START_MPAR_D1D2ABCD : t_MPAR_73_1b := '0';
  signal START_MPAR_D3D4ABCD : t_MPAR_73_1b := '0';
  signal START_MPAR_L1D1ABCD : t_MPAR_73_1b := '0';
  signal START_MPAR_L1D1EFGH : t_MPAR_73_1b := '0';
  signal START_MPAR_L2D1ABCD : t_MPAR_73_1b := '0';

  component clk_wiz_240_360
  port
   (
    clk    : in     std_logic;
    clk240 : out std_logic;
    clk360 : out std_logic;
    locked : out std_logic
   );
  end component;

begin

--! @brief Make clock ---------------------------------------
  clk <= not clk after CLK_PERIOD/2.0;
  clk_wiz_240_360_0 : clk_wiz_240_360
     port map (
     clk    => clk,
     clk240 => clk240,
     clk360 => clk360,
     locked => locked
   );

  -- Get signals from input .txt files

    readAS_L1PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIAin_writeaddr,
      DATA            => AS_L1PHIAin_din,
      START => open,
      WRITE_EN        => AS_L1PHIAin_wea
    );
    readAS_L1PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIBin_writeaddr,
      DATA            => AS_L1PHIBin_din,
      START => open,
      WRITE_EN        => AS_L1PHIBin_wea
    );
    readAS_L1PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHICin_writeaddr,
      DATA            => AS_L1PHICin_din,
      START => open,
      WRITE_EN        => AS_L1PHICin_wea
    );
    readAS_L1PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIDin_writeaddr,
      DATA            => AS_L1PHIDin_din,
      START => open,
      WRITE_EN        => AS_L1PHIDin_wea
    );
    readAS_L1PHIEin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIEn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIEin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIEin_writeaddr,
      DATA            => AS_L1PHIEin_din,
      START => open,
      WRITE_EN        => AS_L1PHIEin_wea
    );
    readAS_L1PHIFin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIFn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIFin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIFin_writeaddr,
      DATA            => AS_L1PHIFin_din,
      START => open,
      WRITE_EN        => AS_L1PHIFin_wea
    );
    readAS_L1PHIGin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIGn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIGin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIGin_writeaddr,
      DATA            => AS_L1PHIGin_din,
      START => open,
      WRITE_EN        => AS_L1PHIGin_wea
    );
    readAS_L1PHIHin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L1PHIHn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L1PHIHin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L1PHIHin_writeaddr,
      DATA            => AS_L1PHIHin_din,
      START => open,
      WRITE_EN        => AS_L1PHIHin_wea
    );
    readAS_L2PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L2PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L2PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L2PHIAin_writeaddr,
      DATA            => AS_L2PHIAin_din,
      START => open,
      WRITE_EN        => AS_L2PHIAin_wea
    );
    readAS_L2PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L2PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L2PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L2PHIBin_writeaddr,
      DATA            => AS_L2PHIBin_din,
      START => open,
      WRITE_EN        => AS_L2PHIBin_wea
    );
    readAS_L2PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L2PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L2PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L2PHICin_writeaddr,
      DATA            => AS_L2PHICin_din,
      START => open,
      WRITE_EN        => AS_L2PHICin_wea
    );
    readAS_L2PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L2PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L2PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L2PHIDin_writeaddr,
      DATA            => AS_L2PHIDin_din,
      START => open,
      WRITE_EN        => AS_L2PHIDin_wea
    );
    readAS_L3PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L3PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L3PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L3PHIAin_writeaddr,
      DATA            => AS_L3PHIAin_din,
      START => open,
      WRITE_EN        => AS_L3PHIAin_wea
    );
    readAS_L3PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L3PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L3PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L3PHIBin_writeaddr,
      DATA            => AS_L3PHIBin_din,
      START => open,
      WRITE_EN        => AS_L3PHIBin_wea
    );
    readAS_L3PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L3PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L3PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L3PHICin_writeaddr,
      DATA            => AS_L3PHICin_din,
      START => open,
      WRITE_EN        => AS_L3PHICin_wea
    );
    readAS_L3PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L3PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L3PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L3PHIDin_writeaddr,
      DATA            => AS_L3PHIDin_din,
      START => open,
      WRITE_EN        => AS_L3PHIDin_wea
    );
    readAS_L4PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L4PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L4PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L4PHIAin_writeaddr,
      DATA            => AS_L4PHIAin_din,
      START => open,
      WRITE_EN        => AS_L4PHIAin_wea
    );
    readAS_L4PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L4PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L4PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L4PHIBin_writeaddr,
      DATA            => AS_L4PHIBin_din,
      START => open,
      WRITE_EN        => AS_L4PHIBin_wea
    );
    readAS_L4PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L4PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L4PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L4PHICin_writeaddr,
      DATA            => AS_L4PHICin_din,
      START => open,
      WRITE_EN        => AS_L4PHICin_wea
    );
    readAS_L4PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L4PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L4PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L4PHIDin_writeaddr,
      DATA            => AS_L4PHIDin_din,
      START => open,
      WRITE_EN        => AS_L4PHIDin_wea
    );
    readAS_L5PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L5PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L5PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L5PHIAin_writeaddr,
      DATA            => AS_L5PHIAin_din,
      START => open,
      WRITE_EN        => AS_L5PHIAin_wea
    );
    readAS_L5PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L5PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L5PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L5PHIBin_writeaddr,
      DATA            => AS_L5PHIBin_din,
      START => open,
      WRITE_EN        => AS_L5PHIBin_wea
    );
    readAS_L5PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L5PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L5PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L5PHICin_writeaddr,
      DATA            => AS_L5PHICin_din,
      START => open,
      WRITE_EN        => AS_L5PHICin_wea
    );
    readAS_L5PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L5PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L5PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L5PHIDin_writeaddr,
      DATA            => AS_L5PHIDin_din,
      START => open,
      WRITE_EN        => AS_L5PHIDin_wea
    );
    readAS_L6PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L6PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L6PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L6PHIAin_writeaddr,
      DATA            => AS_L6PHIAin_din,
      START => open,
      WRITE_EN        => AS_L6PHIAin_wea
    );
    readAS_L6PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L6PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L6PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L6PHIBin_writeaddr,
      DATA            => AS_L6PHIBin_din,
      START => open,
      WRITE_EN        => AS_L6PHIBin_wea
    );
    readAS_L6PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L6PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L6PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L6PHICin_writeaddr,
      DATA            => AS_L6PHICin_din,
      START => open,
      WRITE_EN        => AS_L6PHICin_wea
    );
    readAS_L6PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_L6PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_L6PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_L6PHIDin_writeaddr,
      DATA            => AS_L6PHIDin_din,
      START => open,
      WRITE_EN        => AS_L6PHIDin_wea
    );
    readAS_D1PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D1PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D1PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D1PHIAin_writeaddr,
      DATA            => AS_D1PHIAin_din,
      START => open,
      WRITE_EN        => AS_D1PHIAin_wea
    );
    readAS_D1PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D1PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D1PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D1PHIBin_writeaddr,
      DATA            => AS_D1PHIBin_din,
      START => open,
      WRITE_EN        => AS_D1PHIBin_wea
    );
    readAS_D1PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D1PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D1PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D1PHICin_writeaddr,
      DATA            => AS_D1PHICin_din,
      START => open,
      WRITE_EN        => AS_D1PHICin_wea
    );
    readAS_D1PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D1PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D1PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D1PHIDin_writeaddr,
      DATA            => AS_D1PHIDin_din,
      START => open,
      WRITE_EN        => AS_D1PHIDin_wea
    );
    readAS_D2PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D2PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D2PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D2PHIAin_writeaddr,
      DATA            => AS_D2PHIAin_din,
      START => open,
      WRITE_EN        => AS_D2PHIAin_wea
    );
    readAS_D2PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D2PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D2PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D2PHIBin_writeaddr,
      DATA            => AS_D2PHIBin_din,
      START => open,
      WRITE_EN        => AS_D2PHIBin_wea
    );
    readAS_D2PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D2PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D2PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D2PHICin_writeaddr,
      DATA            => AS_D2PHICin_din,
      START => open,
      WRITE_EN        => AS_D2PHICin_wea
    );
    readAS_D2PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D2PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D2PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D2PHIDin_writeaddr,
      DATA            => AS_D2PHIDin_din,
      START => open,
      WRITE_EN        => AS_D2PHIDin_wea
    );
    readAS_D3PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D3PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D3PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D3PHIAin_writeaddr,
      DATA            => AS_D3PHIAin_din,
      START => open,
      WRITE_EN        => AS_D3PHIAin_wea
    );
    readAS_D3PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D3PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D3PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D3PHIBin_writeaddr,
      DATA            => AS_D3PHIBin_din,
      START => open,
      WRITE_EN        => AS_D3PHIBin_wea
    );
    readAS_D3PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D3PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D3PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D3PHICin_writeaddr,
      DATA            => AS_D3PHICin_din,
      START => open,
      WRITE_EN        => AS_D3PHICin_wea
    );
    readAS_D3PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D3PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D3PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D3PHIDin_writeaddr,
      DATA            => AS_D3PHIDin_din,
      START => open,
      WRITE_EN        => AS_D3PHIDin_wea
    );
    readAS_D4PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D4PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D4PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D4PHIAin_writeaddr,
      DATA            => AS_D4PHIAin_din,
      START => open,
      WRITE_EN        => AS_D4PHIAin_wea
    );
    readAS_D4PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D4PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D4PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D4PHIBin_writeaddr,
      DATA            => AS_D4PHIBin_din,
      START => open,
      WRITE_EN        => AS_D4PHIBin_wea
    );
    readAS_D4PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D4PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D4PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D4PHICin_writeaddr,
      DATA            => AS_D4PHICin_din,
      START => open,
      WRITE_EN        => AS_D4PHICin_wea
    );
    readAS_D4PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D4PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D4PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D4PHIDin_writeaddr,
      DATA            => AS_D4PHIDin_din,
      START => open,
      WRITE_EN        => AS_D4PHIDin_wea
    );
    readAS_D5PHIAin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D5PHIAn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D5PHIAin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D5PHIAin_writeaddr,
      DATA            => AS_D5PHIAin_din,
      START => open,
      WRITE_EN        => AS_D5PHIAin_wea
    );
    readAS_D5PHIBin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D5PHIBn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D5PHIBin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D5PHIBin_writeaddr,
      DATA            => AS_D5PHIBin_din,
      START => open,
      WRITE_EN        => AS_D5PHIBin_wea
    );
    readAS_D5PHICin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D5PHICn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D5PHICin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D5PHICin_writeaddr,
      DATA            => AS_D5PHICin_din,
      START => open,
      WRITE_EN        => AS_D5PHICin_wea
    );
    readAS_D5PHIDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_AS_36&"AS_D5PHIDn1"&inputFileNameEnding,
      RAM_WIDTH       => 36,
      NUM_PAGES       => 8,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_AS_36&"AS_D5PHIDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => AS_D5PHIDin_writeaddr,
      DATA            => AS_D5PHIDin_din,
      START => open,
      WRITE_EN        => AS_D5PHIDin_wea
    );
    readMPAR_L1L2ABCin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1L2ABC"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1L2ABCin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1L2ABCin_writeaddr,
      DATA            => MPAR_L1L2ABCin_din,
      START           => START_MPAR_L1L2ABCin,
      WRITE_EN        => MPAR_L1L2ABCin_wea
    );
    readMPAR_L1L2DEin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1L2DE"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1L2DEin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1L2DEin_writeaddr,
      DATA            => MPAR_L1L2DEin_din,
      START           => START_MPAR_L1L2DEin,
      WRITE_EN        => MPAR_L1L2DEin_wea
    );
    readMPAR_L1L2Fin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1L2F"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1L2Fin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1L2Fin_writeaddr,
      DATA            => MPAR_L1L2Fin_din,
      START           => START_MPAR_L1L2Fin,
      WRITE_EN        => MPAR_L1L2Fin_wea
    );
    readMPAR_L1L2Gin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1L2G"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1L2Gin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1L2Gin_writeaddr,
      DATA            => MPAR_L1L2Gin_din,
      START           => START_MPAR_L1L2Gin,
      WRITE_EN        => MPAR_L1L2Gin_wea
    );
    readMPAR_L1L2HIin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1L2HI"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1L2HIin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1L2HIin_writeaddr,
      DATA            => MPAR_L1L2HIin_din,
      START           => START_MPAR_L1L2HIin,
      WRITE_EN        => MPAR_L1L2HIin_wea
    );
    readMPAR_L1L2JKLin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1L2JKL"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1L2JKLin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1L2JKLin_writeaddr,
      DATA            => MPAR_L1L2JKLin_din,
      START           => START_MPAR_L1L2JKLin,
      WRITE_EN        => MPAR_L1L2JKLin_wea
    );
    readMPAR_L2L3ABCDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L2L3ABCD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L2L3ABCDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L2L3ABCDin_writeaddr,
      DATA            => MPAR_L2L3ABCDin_din,
      START           => START_MPAR_L2L3ABCDin,
      WRITE_EN        => MPAR_L2L3ABCDin_wea
    );
    readMPAR_L3L4ABin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L3L4AB"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L3L4ABin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L3L4ABin_writeaddr,
      DATA            => MPAR_L3L4ABin_din,
      START           => START_MPAR_L3L4ABin,
      WRITE_EN        => MPAR_L3L4ABin_wea
    );
    readMPAR_L3L4CDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L3L4CD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L3L4CDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L3L4CDin_writeaddr,
      DATA            => MPAR_L3L4CDin_din,
      START           => START_MPAR_L3L4CDin,
      WRITE_EN        => MPAR_L3L4CDin_wea
    );
    readMPAR_L5L6ABCDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L5L6ABCD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L5L6ABCDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L5L6ABCDin_writeaddr,
      DATA            => MPAR_L5L6ABCDin_din,
      START           => START_MPAR_L5L6ABCDin,
      WRITE_EN        => MPAR_L5L6ABCDin_wea
    );
    readMPAR_D1D2ABCDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_D1D2ABCD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_D1D2ABCDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_D1D2ABCDin_writeaddr,
      DATA            => MPAR_D1D2ABCDin_din,
      START           => START_MPAR_D1D2ABCDin,
      WRITE_EN        => MPAR_D1D2ABCDin_wea
    );
    readMPAR_D3D4ABCDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_D3D4ABCD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_D3D4ABCDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_D3D4ABCDin_writeaddr,
      DATA            => MPAR_D3D4ABCDin_din,
      START           => START_MPAR_D3D4ABCDin,
      WRITE_EN        => MPAR_D3D4ABCDin_wea
    );
    readMPAR_L1D1ABCDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1D1ABCD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1D1ABCDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1D1ABCDin_writeaddr,
      DATA            => MPAR_L1D1ABCDin_din,
      START           => START_MPAR_L1D1ABCDin,
      WRITE_EN        => MPAR_L1D1ABCDin_wea
    );
    readMPAR_L1D1EFGHin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L1D1EFGH"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L1D1EFGHin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L1D1EFGHin_writeaddr,
      DATA            => MPAR_L1D1EFGHin_din,
      START           => START_MPAR_L1D1EFGHin,
      WRITE_EN        => MPAR_L1D1EFGHin_wea
    );
    readMPAR_L2D1ABCDin : entity work.FileReader
  generic map (
      FILE_NAME       => FILE_IN_MPAR_73&"MPAR_L2D1ABCD"&inputFileNameEnding,
      RAM_WIDTH       => 73,
      NUM_PAGES       => 8,
      NUM_TPAGES      => 4,
      NUM_BINS        => 4,
      DEBUG           => true,
      FILE_NAME_DEBUG => FILE_OUT_MPAR_73&"MPAR_L2D1ABCDin_debug"&debugFileNameEnding
    )
    port map (
      CLK             => CLK240,
      LOCKED          => LOCKED,
      ADDR            => MPAR_L2D1ABCDin_writeaddr,
      DATA            => MPAR_L2D1ABCDin_din,
      START           => START_MPAR_L2D1ABCDin,
      WRITE_EN        => MPAR_L2D1ABCDin_wea
    );
  -- As all MPAR signals start together, take first one, to determine when
  -- first event starts being written to first memory in chain.
  START_FIRST_WRITE <= START_MPAR_L1L2ABCin;

  procStart : process(CLK240)
    -- Process to start first module in chain & generate its BX counter input.
    -- Also releases reset flag.
    constant CLK_RESET : natural := 5; -- Any low number OK.
    variable CLK_COUNT : natural := 2; -- Magic adjustment (ryd)
    variable EVENT_COUNT : integer := -1;
    variable v_line : line; -- Line for debug
  begin

    if START_FIRST_WRITE = '1' then
      if rising_edge(CLK240) then
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
        clk240                     => clk240,
        clk360                     => clk240, -- Using 240-MHz clock until CDC is integrated
        reset                      => reset,
        PC_start                   => PC_start,
        PC_bx_in                   => PC_bx_in,
        TB_bx_out                  => TB_bx_out,
        TB_bx_out_vld              => TB_bx_out_vld,
        TB_done                    => TB_done,
        TB_AAAA_last_track         => TB_AAAA_last_track,
        TB_AAAA_last_track_vld     => TB_AAAA_last_track_vld,
        TB_BBBB_last_track         => TB_BBBB_last_track,
        TB_BBBB_last_track_vld     => TB_BBBB_last_track_vld,
        -- Input data
        AS_L1PHIAin_wea            => AS_L1PHIAin_wea,
        AS_L1PHIAin_writeaddr      => AS_L1PHIAin_writeaddr,
        AS_L1PHIAin_din            => AS_L1PHIAin_din,
        AS_L1PHIBin_wea            => AS_L1PHIBin_wea,
        AS_L1PHIBin_writeaddr      => AS_L1PHIBin_writeaddr,
        AS_L1PHIBin_din            => AS_L1PHIBin_din,
        AS_L1PHICin_wea            => AS_L1PHICin_wea,
        AS_L1PHICin_writeaddr      => AS_L1PHICin_writeaddr,
        AS_L1PHICin_din            => AS_L1PHICin_din,
        AS_L1PHIDin_wea            => AS_L1PHIDin_wea,
        AS_L1PHIDin_writeaddr      => AS_L1PHIDin_writeaddr,
        AS_L1PHIDin_din            => AS_L1PHIDin_din,
        AS_L1PHIEin_wea            => AS_L1PHIEin_wea,
        AS_L1PHIEin_writeaddr      => AS_L1PHIEin_writeaddr,
        AS_L1PHIEin_din            => AS_L1PHIEin_din,
        AS_L1PHIFin_wea            => AS_L1PHIFin_wea,
        AS_L1PHIFin_writeaddr      => AS_L1PHIFin_writeaddr,
        AS_L1PHIFin_din            => AS_L1PHIFin_din,
        AS_L1PHIGin_wea            => AS_L1PHIGin_wea,
        AS_L1PHIGin_writeaddr      => AS_L1PHIGin_writeaddr,
        AS_L1PHIGin_din            => AS_L1PHIGin_din,
        AS_L1PHIHin_wea            => AS_L1PHIHin_wea,
        AS_L1PHIHin_writeaddr      => AS_L1PHIHin_writeaddr,
        AS_L1PHIHin_din            => AS_L1PHIHin_din,
        AS_L2PHIAin_wea            => AS_L2PHIAin_wea,
        AS_L2PHIAin_writeaddr      => AS_L2PHIAin_writeaddr,
        AS_L2PHIAin_din            => AS_L2PHIAin_din,
        AS_L2PHIBin_wea            => AS_L2PHIBin_wea,
        AS_L2PHIBin_writeaddr      => AS_L2PHIBin_writeaddr,
        AS_L2PHIBin_din            => AS_L2PHIBin_din,
        AS_L2PHICin_wea            => AS_L2PHICin_wea,
        AS_L2PHICin_writeaddr      => AS_L2PHICin_writeaddr,
        AS_L2PHICin_din            => AS_L2PHICin_din,
        AS_L2PHIDin_wea            => AS_L2PHIDin_wea,
        AS_L2PHIDin_writeaddr      => AS_L2PHIDin_writeaddr,
        AS_L2PHIDin_din            => AS_L2PHIDin_din,
        AS_L3PHIAin_wea            => AS_L3PHIAin_wea,
        AS_L3PHIAin_writeaddr      => AS_L3PHIAin_writeaddr,
        AS_L3PHIAin_din            => AS_L3PHIAin_din,
        AS_L3PHIBin_wea            => AS_L3PHIBin_wea,
        AS_L3PHIBin_writeaddr      => AS_L3PHIBin_writeaddr,
        AS_L3PHIBin_din            => AS_L3PHIBin_din,
        AS_L3PHICin_wea            => AS_L3PHICin_wea,
        AS_L3PHICin_writeaddr      => AS_L3PHICin_writeaddr,
        AS_L3PHICin_din            => AS_L3PHICin_din,
        AS_L3PHIDin_wea            => AS_L3PHIDin_wea,
        AS_L3PHIDin_writeaddr      => AS_L3PHIDin_writeaddr,
        AS_L3PHIDin_din            => AS_L3PHIDin_din,
        AS_L4PHIAin_wea            => AS_L4PHIAin_wea,
        AS_L4PHIAin_writeaddr      => AS_L4PHIAin_writeaddr,
        AS_L4PHIAin_din            => AS_L4PHIAin_din,
        AS_L4PHIBin_wea            => AS_L4PHIBin_wea,
        AS_L4PHIBin_writeaddr      => AS_L4PHIBin_writeaddr,
        AS_L4PHIBin_din            => AS_L4PHIBin_din,
        AS_L4PHICin_wea            => AS_L4PHICin_wea,
        AS_L4PHICin_writeaddr      => AS_L4PHICin_writeaddr,
        AS_L4PHICin_din            => AS_L4PHICin_din,
        AS_L4PHIDin_wea            => AS_L4PHIDin_wea,
        AS_L4PHIDin_writeaddr      => AS_L4PHIDin_writeaddr,
        AS_L4PHIDin_din            => AS_L4PHIDin_din,
        AS_L5PHIAin_wea            => AS_L5PHIAin_wea,
        AS_L5PHIAin_writeaddr      => AS_L5PHIAin_writeaddr,
        AS_L5PHIAin_din            => AS_L5PHIAin_din,
        AS_L5PHIBin_wea            => AS_L5PHIBin_wea,
        AS_L5PHIBin_writeaddr      => AS_L5PHIBin_writeaddr,
        AS_L5PHIBin_din            => AS_L5PHIBin_din,
        AS_L5PHICin_wea            => AS_L5PHICin_wea,
        AS_L5PHICin_writeaddr      => AS_L5PHICin_writeaddr,
        AS_L5PHICin_din            => AS_L5PHICin_din,
        AS_L5PHIDin_wea            => AS_L5PHIDin_wea,
        AS_L5PHIDin_writeaddr      => AS_L5PHIDin_writeaddr,
        AS_L5PHIDin_din            => AS_L5PHIDin_din,
        AS_L6PHIAin_wea            => AS_L6PHIAin_wea,
        AS_L6PHIAin_writeaddr      => AS_L6PHIAin_writeaddr,
        AS_L6PHIAin_din            => AS_L6PHIAin_din,
        AS_L6PHIBin_wea            => AS_L6PHIBin_wea,
        AS_L6PHIBin_writeaddr      => AS_L6PHIBin_writeaddr,
        AS_L6PHIBin_din            => AS_L6PHIBin_din,
        AS_L6PHICin_wea            => AS_L6PHICin_wea,
        AS_L6PHICin_writeaddr      => AS_L6PHICin_writeaddr,
        AS_L6PHICin_din            => AS_L6PHICin_din,
        AS_L6PHIDin_wea            => AS_L6PHIDin_wea,
        AS_L6PHIDin_writeaddr      => AS_L6PHIDin_writeaddr,
        AS_L6PHIDin_din            => AS_L6PHIDin_din,
        AS_D1PHIAin_wea            => AS_D1PHIAin_wea,
        AS_D1PHIAin_writeaddr      => AS_D1PHIAin_writeaddr,
        AS_D1PHIAin_din            => AS_D1PHIAin_din,
        AS_D1PHIBin_wea            => AS_D1PHIBin_wea,
        AS_D1PHIBin_writeaddr      => AS_D1PHIBin_writeaddr,
        AS_D1PHIBin_din            => AS_D1PHIBin_din,
        AS_D1PHICin_wea            => AS_D1PHICin_wea,
        AS_D1PHICin_writeaddr      => AS_D1PHICin_writeaddr,
        AS_D1PHICin_din            => AS_D1PHICin_din,
        AS_D1PHIDin_wea            => AS_D1PHIDin_wea,
        AS_D1PHIDin_writeaddr      => AS_D1PHIDin_writeaddr,
        AS_D1PHIDin_din            => AS_D1PHIDin_din,
        AS_D2PHIAin_wea            => AS_D2PHIAin_wea,
        AS_D2PHIAin_writeaddr      => AS_D2PHIAin_writeaddr,
        AS_D2PHIAin_din            => AS_D2PHIAin_din,
        AS_D2PHIBin_wea            => AS_D2PHIBin_wea,
        AS_D2PHIBin_writeaddr      => AS_D2PHIBin_writeaddr,
        AS_D2PHIBin_din            => AS_D2PHIBin_din,
        AS_D2PHICin_wea            => AS_D2PHICin_wea,
        AS_D2PHICin_writeaddr      => AS_D2PHICin_writeaddr,
        AS_D2PHICin_din            => AS_D2PHICin_din,
        AS_D2PHIDin_wea            => AS_D2PHIDin_wea,
        AS_D2PHIDin_writeaddr      => AS_D2PHIDin_writeaddr,
        AS_D2PHIDin_din            => AS_D2PHIDin_din,
        AS_D3PHIAin_wea            => AS_D3PHIAin_wea,
        AS_D3PHIAin_writeaddr      => AS_D3PHIAin_writeaddr,
        AS_D3PHIAin_din            => AS_D3PHIAin_din,
        AS_D3PHIBin_wea            => AS_D3PHIBin_wea,
        AS_D3PHIBin_writeaddr      => AS_D3PHIBin_writeaddr,
        AS_D3PHIBin_din            => AS_D3PHIBin_din,
        AS_D3PHICin_wea            => AS_D3PHICin_wea,
        AS_D3PHICin_writeaddr      => AS_D3PHICin_writeaddr,
        AS_D3PHICin_din            => AS_D3PHICin_din,
        AS_D3PHIDin_wea            => AS_D3PHIDin_wea,
        AS_D3PHIDin_writeaddr      => AS_D3PHIDin_writeaddr,
        AS_D3PHIDin_din            => AS_D3PHIDin_din,
        AS_D4PHIAin_wea            => AS_D4PHIAin_wea,
        AS_D4PHIAin_writeaddr      => AS_D4PHIAin_writeaddr,
        AS_D4PHIAin_din            => AS_D4PHIAin_din,
        AS_D4PHIBin_wea            => AS_D4PHIBin_wea,
        AS_D4PHIBin_writeaddr      => AS_D4PHIBin_writeaddr,
        AS_D4PHIBin_din            => AS_D4PHIBin_din,
        AS_D4PHICin_wea            => AS_D4PHICin_wea,
        AS_D4PHICin_writeaddr      => AS_D4PHICin_writeaddr,
        AS_D4PHICin_din            => AS_D4PHICin_din,
        AS_D4PHIDin_wea            => AS_D4PHIDin_wea,
        AS_D4PHIDin_writeaddr      => AS_D4PHIDin_writeaddr,
        AS_D4PHIDin_din            => AS_D4PHIDin_din,
        AS_D5PHIAin_wea            => AS_D5PHIAin_wea,
        AS_D5PHIAin_writeaddr      => AS_D5PHIAin_writeaddr,
        AS_D5PHIAin_din            => AS_D5PHIAin_din,
        AS_D5PHIBin_wea            => AS_D5PHIBin_wea,
        AS_D5PHIBin_writeaddr      => AS_D5PHIBin_writeaddr,
        AS_D5PHIBin_din            => AS_D5PHIBin_din,
        AS_D5PHICin_wea            => AS_D5PHICin_wea,
        AS_D5PHICin_writeaddr      => AS_D5PHICin_writeaddr,
        AS_D5PHICin_din            => AS_D5PHICin_din,
        AS_D5PHIDin_wea            => AS_D5PHIDin_wea,
        AS_D5PHIDin_writeaddr      => AS_D5PHIDin_writeaddr,
        AS_D5PHIDin_din            => AS_D5PHIDin_din,
        MPAR_L1L2ABCin_wea         => MPAR_L1L2ABCin_wea,
        MPAR_L1L2ABCin_writeaddr   => MPAR_L1L2ABCin_writeaddr,
        MPAR_L1L2ABCin_din         => MPAR_L1L2ABCin_din,
        MPAR_L1L2DEin_wea          => MPAR_L1L2DEin_wea,
        MPAR_L1L2DEin_writeaddr    => MPAR_L1L2DEin_writeaddr,
        MPAR_L1L2DEin_din          => MPAR_L1L2DEin_din,
        MPAR_L1L2Fin_wea           => MPAR_L1L2Fin_wea,
        MPAR_L1L2Fin_writeaddr     => MPAR_L1L2Fin_writeaddr,
        MPAR_L1L2Fin_din           => MPAR_L1L2Fin_din,
        MPAR_L1L2Gin_wea           => MPAR_L1L2Gin_wea,
        MPAR_L1L2Gin_writeaddr     => MPAR_L1L2Gin_writeaddr,
        MPAR_L1L2Gin_din           => MPAR_L1L2Gin_din,
        MPAR_L1L2HIin_wea          => MPAR_L1L2HIin_wea,
        MPAR_L1L2HIin_writeaddr    => MPAR_L1L2HIin_writeaddr,
        MPAR_L1L2HIin_din          => MPAR_L1L2HIin_din,
        MPAR_L1L2JKLin_wea         => MPAR_L1L2JKLin_wea,
        MPAR_L1L2JKLin_writeaddr   => MPAR_L1L2JKLin_writeaddr,
        MPAR_L1L2JKLin_din         => MPAR_L1L2JKLin_din,
        MPAR_L2L3ABCDin_wea        => MPAR_L2L3ABCDin_wea,
        MPAR_L2L3ABCDin_writeaddr  => MPAR_L2L3ABCDin_writeaddr,
        MPAR_L2L3ABCDin_din        => MPAR_L2L3ABCDin_din,
        MPAR_L3L4ABin_wea          => MPAR_L3L4ABin_wea,
        MPAR_L3L4ABin_writeaddr    => MPAR_L3L4ABin_writeaddr,
        MPAR_L3L4ABin_din          => MPAR_L3L4ABin_din,
        MPAR_L3L4CDin_wea          => MPAR_L3L4CDin_wea,
        MPAR_L3L4CDin_writeaddr    => MPAR_L3L4CDin_writeaddr,
        MPAR_L3L4CDin_din          => MPAR_L3L4CDin_din,
        MPAR_L5L6ABCDin_wea        => MPAR_L5L6ABCDin_wea,
        MPAR_L5L6ABCDin_writeaddr  => MPAR_L5L6ABCDin_writeaddr,
        MPAR_L5L6ABCDin_din        => MPAR_L5L6ABCDin_din,
        MPAR_D1D2ABCDin_wea        => MPAR_D1D2ABCDin_wea,
        MPAR_D1D2ABCDin_writeaddr  => MPAR_D1D2ABCDin_writeaddr,
        MPAR_D1D2ABCDin_din        => MPAR_D1D2ABCDin_din,
        MPAR_D3D4ABCDin_wea        => MPAR_D3D4ABCDin_wea,
        MPAR_D3D4ABCDin_writeaddr  => MPAR_D3D4ABCDin_writeaddr,
        MPAR_D3D4ABCDin_din        => MPAR_D3D4ABCDin_din,
        MPAR_L1D1ABCDin_wea        => MPAR_L1D1ABCDin_wea,
        MPAR_L1D1ABCDin_writeaddr  => MPAR_L1D1ABCDin_writeaddr,
        MPAR_L1D1ABCDin_din        => MPAR_L1D1ABCDin_din,
        MPAR_L1D1EFGHin_wea        => MPAR_L1D1EFGHin_wea,
        MPAR_L1D1EFGHin_writeaddr  => MPAR_L1D1EFGHin_writeaddr,
        MPAR_L1D1EFGHin_din        => MPAR_L1D1EFGHin_din,
        MPAR_L2D1ABCDin_wea        => MPAR_L2D1ABCDin_wea,
        MPAR_L2D1ABCDin_writeaddr  => MPAR_L2D1ABCDin_writeaddr,
        MPAR_L2D1ABCDin_din        => MPAR_L2D1ABCDin_din,
        -- Output data
        TW_AAAA_stream_AV_din      => TW_AAAA_stream_AV_din,
        TW_AAAA_stream_A_full_neg  => TW_AAAA_stream_A_full_neg,
        TW_AAAA_stream_A_write     => TW_AAAA_stream_A_write,
        TW_BBBB_stream_AV_din      => TW_BBBB_stream_AV_din,
        TW_BBBB_stream_A_full_neg  => TW_BBBB_stream_A_full_neg,
        TW_BBBB_stream_A_write     => TW_BBBB_stream_A_write,
        DW_AAAA_D1_stream_AV_din   => DW_AAAA_D1_stream_AV_din,
        DW_AAAA_D1_stream_A_full_neg=> DW_AAAA_D1_stream_A_full_neg,
        DW_AAAA_D1_stream_A_write  => DW_AAAA_D1_stream_A_write,
        DW_AAAA_D2_stream_AV_din   => DW_AAAA_D2_stream_AV_din,
        DW_AAAA_D2_stream_A_full_neg=> DW_AAAA_D2_stream_A_full_neg,
        DW_AAAA_D2_stream_A_write  => DW_AAAA_D2_stream_A_write,
        DW_AAAA_D3_stream_AV_din   => DW_AAAA_D3_stream_AV_din,
        DW_AAAA_D3_stream_A_full_neg=> DW_AAAA_D3_stream_A_full_neg,
        DW_AAAA_D3_stream_A_write  => DW_AAAA_D3_stream_A_write,
        DW_AAAA_D4_stream_AV_din   => DW_AAAA_D4_stream_AV_din,
        DW_AAAA_D4_stream_A_full_neg=> DW_AAAA_D4_stream_A_full_neg,
        DW_AAAA_D4_stream_A_write  => DW_AAAA_D4_stream_A_write,
        DW_AAAA_D5_stream_AV_din   => DW_AAAA_D5_stream_AV_din,
        DW_AAAA_D5_stream_A_full_neg=> DW_AAAA_D5_stream_A_full_neg,
        DW_AAAA_D5_stream_A_write  => DW_AAAA_D5_stream_A_write,
        DW_BBBB_D1_stream_AV_din   => DW_BBBB_D1_stream_AV_din,
        DW_BBBB_D1_stream_A_full_neg=> DW_BBBB_D1_stream_A_full_neg,
        DW_BBBB_D1_stream_A_write  => DW_BBBB_D1_stream_A_write,
        DW_BBBB_D2_stream_AV_din   => DW_BBBB_D2_stream_AV_din,
        DW_BBBB_D2_stream_A_full_neg=> DW_BBBB_D2_stream_A_full_neg,
        DW_BBBB_D2_stream_A_write  => DW_BBBB_D2_stream_A_write,
        DW_BBBB_D3_stream_AV_din   => DW_BBBB_D3_stream_AV_din,
        DW_BBBB_D3_stream_A_full_neg=> DW_BBBB_D3_stream_A_full_neg,
        DW_BBBB_D3_stream_A_write  => DW_BBBB_D3_stream_A_write,
        DW_BBBB_D4_stream_AV_din   => DW_BBBB_D4_stream_AV_din,
        DW_BBBB_D4_stream_A_full_neg=> DW_BBBB_D4_stream_A_full_neg,
        DW_BBBB_D4_stream_A_write  => DW_BBBB_D4_stream_A_write,
        DW_BBBB_D5_stream_AV_din   => DW_BBBB_D5_stream_AV_din,
        DW_BBBB_D5_stream_A_full_neg=> DW_BBBB_D5_stream_A_full_neg,
        DW_BBBB_D5_stream_A_write  => DW_BBBB_D5_stream_A_write,
        BW_AAAA_L1_stream_AV_din   => BW_AAAA_L1_stream_AV_din,
        BW_AAAA_L1_stream_A_full_neg=> BW_AAAA_L1_stream_A_full_neg,
        BW_AAAA_L1_stream_A_write  => BW_AAAA_L1_stream_A_write,
        BW_AAAA_L2_stream_AV_din   => BW_AAAA_L2_stream_AV_din,
        BW_AAAA_L2_stream_A_full_neg=> BW_AAAA_L2_stream_A_full_neg,
        BW_AAAA_L2_stream_A_write  => BW_AAAA_L2_stream_A_write,
        BW_AAAA_L3_stream_AV_din   => BW_AAAA_L3_stream_AV_din,
        BW_AAAA_L3_stream_A_full_neg=> BW_AAAA_L3_stream_A_full_neg,
        BW_AAAA_L3_stream_A_write  => BW_AAAA_L3_stream_A_write,
        BW_AAAA_L4_stream_AV_din   => BW_AAAA_L4_stream_AV_din,
        BW_AAAA_L4_stream_A_full_neg=> BW_AAAA_L4_stream_A_full_neg,
        BW_AAAA_L4_stream_A_write  => BW_AAAA_L4_stream_A_write,
        BW_AAAA_L5_stream_AV_din   => BW_AAAA_L5_stream_AV_din,
        BW_AAAA_L5_stream_A_full_neg=> BW_AAAA_L5_stream_A_full_neg,
        BW_AAAA_L5_stream_A_write  => BW_AAAA_L5_stream_A_write,
        BW_AAAA_L6_stream_AV_din   => BW_AAAA_L6_stream_AV_din,
        BW_AAAA_L6_stream_A_full_neg=> BW_AAAA_L6_stream_A_full_neg,
        BW_AAAA_L6_stream_A_write  => BW_AAAA_L6_stream_A_write,
        BW_BBBB_L1_stream_AV_din   => BW_BBBB_L1_stream_AV_din,
        BW_BBBB_L1_stream_A_full_neg=> BW_BBBB_L1_stream_A_full_neg,
        BW_BBBB_L1_stream_A_write  => BW_BBBB_L1_stream_A_write,
        BW_BBBB_L2_stream_AV_din   => BW_BBBB_L2_stream_AV_din,
        BW_BBBB_L2_stream_A_full_neg=> BW_BBBB_L2_stream_A_full_neg,
        BW_BBBB_L2_stream_A_write  => BW_BBBB_L2_stream_A_write,
        BW_BBBB_L3_stream_AV_din   => BW_BBBB_L3_stream_AV_din,
        BW_BBBB_L3_stream_A_full_neg=> BW_BBBB_L3_stream_A_full_neg,
        BW_BBBB_L3_stream_A_write  => BW_BBBB_L3_stream_A_write,
        BW_BBBB_L4_stream_AV_din   => BW_BBBB_L4_stream_AV_din,
        BW_BBBB_L4_stream_A_full_neg=> BW_BBBB_L4_stream_A_full_neg,
        BW_BBBB_L4_stream_A_write  => BW_BBBB_L4_stream_A_write,
        BW_BBBB_L5_stream_AV_din   => BW_BBBB_L5_stream_AV_din,
        BW_BBBB_L5_stream_A_full_neg=> BW_BBBB_L5_stream_A_full_neg,
        BW_BBBB_L5_stream_A_write  => BW_BBBB_L5_stream_A_write,
        BW_BBBB_L6_stream_AV_din   => BW_BBBB_L6_stream_AV_din,
        BW_BBBB_L6_stream_A_full_neg=> BW_BBBB_L6_stream_A_full_neg,
        BW_BBBB_L6_stream_A_write  => BW_BBBB_L6_stream_A_write
      );
  end generate sectorProc;

  sectorProcFull : if INST_TOP_TF = 1 generate
  begin
    uut : entity work.SectorProcessorFull
      port map(
        clk240                     => clk240,
        clk360                     => clk240, -- Using 240-MHz clock until CDC is integrated
        reset                      => reset,
        PC_start                   => PC_start,
        PC_bx_in                   => PC_bx_in,
        TB_bx_out                  => TB_bx_out,
        TB_bx_out_vld              => TB_bx_out_vld,
        TB_done                    => TB_done,
        TB_AAAA_last_track         => TB_AAAA_last_track,
        TB_AAAA_last_track_vld     => TB_AAAA_last_track_vld,
        TB_BBBB_last_track         => TB_BBBB_last_track,
        TB_BBBB_last_track_vld     => TB_BBBB_last_track_vld,
        -- Debug control signals
        VMSMER_bx_out              => VMSMER_bx_out,
        VMSMER_bx_out_vld          => VMSMER_bx_out_vld,
        VMSMER_done                => VMSMER_done,
        PC_bx_out                  => PC_bx_out,
        PC_bx_out_vld              => PC_bx_out_vld,
        PC_done                    => PC_done,
        MP_bx_out                  => MP_bx_out,
        MP_bx_out_vld              => MP_bx_out_vld,
        MP_done                    => MP_done,
        -- Input data
        AS_L1PHIAin_wea            => AS_L1PHIAin_wea,
        AS_L1PHIAin_writeaddr      => AS_L1PHIAin_writeaddr,
        AS_L1PHIAin_din            => AS_L1PHIAin_din,
        AS_L1PHIBin_wea            => AS_L1PHIBin_wea,
        AS_L1PHIBin_writeaddr      => AS_L1PHIBin_writeaddr,
        AS_L1PHIBin_din            => AS_L1PHIBin_din,
        AS_L1PHICin_wea            => AS_L1PHICin_wea,
        AS_L1PHICin_writeaddr      => AS_L1PHICin_writeaddr,
        AS_L1PHICin_din            => AS_L1PHICin_din,
        AS_L1PHIDin_wea            => AS_L1PHIDin_wea,
        AS_L1PHIDin_writeaddr      => AS_L1PHIDin_writeaddr,
        AS_L1PHIDin_din            => AS_L1PHIDin_din,
        AS_L1PHIEin_wea            => AS_L1PHIEin_wea,
        AS_L1PHIEin_writeaddr      => AS_L1PHIEin_writeaddr,
        AS_L1PHIEin_din            => AS_L1PHIEin_din,
        AS_L1PHIFin_wea            => AS_L1PHIFin_wea,
        AS_L1PHIFin_writeaddr      => AS_L1PHIFin_writeaddr,
        AS_L1PHIFin_din            => AS_L1PHIFin_din,
        AS_L1PHIGin_wea            => AS_L1PHIGin_wea,
        AS_L1PHIGin_writeaddr      => AS_L1PHIGin_writeaddr,
        AS_L1PHIGin_din            => AS_L1PHIGin_din,
        AS_L1PHIHin_wea            => AS_L1PHIHin_wea,
        AS_L1PHIHin_writeaddr      => AS_L1PHIHin_writeaddr,
        AS_L1PHIHin_din            => AS_L1PHIHin_din,
        AS_L2PHIAin_wea            => AS_L2PHIAin_wea,
        AS_L2PHIAin_writeaddr      => AS_L2PHIAin_writeaddr,
        AS_L2PHIAin_din            => AS_L2PHIAin_din,
        AS_L2PHIBin_wea            => AS_L2PHIBin_wea,
        AS_L2PHIBin_writeaddr      => AS_L2PHIBin_writeaddr,
        AS_L2PHIBin_din            => AS_L2PHIBin_din,
        AS_L2PHICin_wea            => AS_L2PHICin_wea,
        AS_L2PHICin_writeaddr      => AS_L2PHICin_writeaddr,
        AS_L2PHICin_din            => AS_L2PHICin_din,
        AS_L2PHIDin_wea            => AS_L2PHIDin_wea,
        AS_L2PHIDin_writeaddr      => AS_L2PHIDin_writeaddr,
        AS_L2PHIDin_din            => AS_L2PHIDin_din,
        AS_L3PHIAin_wea            => AS_L3PHIAin_wea,
        AS_L3PHIAin_writeaddr      => AS_L3PHIAin_writeaddr,
        AS_L3PHIAin_din            => AS_L3PHIAin_din,
        AS_L3PHIBin_wea            => AS_L3PHIBin_wea,
        AS_L3PHIBin_writeaddr      => AS_L3PHIBin_writeaddr,
        AS_L3PHIBin_din            => AS_L3PHIBin_din,
        AS_L3PHICin_wea            => AS_L3PHICin_wea,
        AS_L3PHICin_writeaddr      => AS_L3PHICin_writeaddr,
        AS_L3PHICin_din            => AS_L3PHICin_din,
        AS_L3PHIDin_wea            => AS_L3PHIDin_wea,
        AS_L3PHIDin_writeaddr      => AS_L3PHIDin_writeaddr,
        AS_L3PHIDin_din            => AS_L3PHIDin_din,
        AS_L4PHIAin_wea            => AS_L4PHIAin_wea,
        AS_L4PHIAin_writeaddr      => AS_L4PHIAin_writeaddr,
        AS_L4PHIAin_din            => AS_L4PHIAin_din,
        AS_L4PHIBin_wea            => AS_L4PHIBin_wea,
        AS_L4PHIBin_writeaddr      => AS_L4PHIBin_writeaddr,
        AS_L4PHIBin_din            => AS_L4PHIBin_din,
        AS_L4PHICin_wea            => AS_L4PHICin_wea,
        AS_L4PHICin_writeaddr      => AS_L4PHICin_writeaddr,
        AS_L4PHICin_din            => AS_L4PHICin_din,
        AS_L4PHIDin_wea            => AS_L4PHIDin_wea,
        AS_L4PHIDin_writeaddr      => AS_L4PHIDin_writeaddr,
        AS_L4PHIDin_din            => AS_L4PHIDin_din,
        AS_L5PHIAin_wea            => AS_L5PHIAin_wea,
        AS_L5PHIAin_writeaddr      => AS_L5PHIAin_writeaddr,
        AS_L5PHIAin_din            => AS_L5PHIAin_din,
        AS_L5PHIBin_wea            => AS_L5PHIBin_wea,
        AS_L5PHIBin_writeaddr      => AS_L5PHIBin_writeaddr,
        AS_L5PHIBin_din            => AS_L5PHIBin_din,
        AS_L5PHICin_wea            => AS_L5PHICin_wea,
        AS_L5PHICin_writeaddr      => AS_L5PHICin_writeaddr,
        AS_L5PHICin_din            => AS_L5PHICin_din,
        AS_L5PHIDin_wea            => AS_L5PHIDin_wea,
        AS_L5PHIDin_writeaddr      => AS_L5PHIDin_writeaddr,
        AS_L5PHIDin_din            => AS_L5PHIDin_din,
        AS_L6PHIAin_wea            => AS_L6PHIAin_wea,
        AS_L6PHIAin_writeaddr      => AS_L6PHIAin_writeaddr,
        AS_L6PHIAin_din            => AS_L6PHIAin_din,
        AS_L6PHIBin_wea            => AS_L6PHIBin_wea,
        AS_L6PHIBin_writeaddr      => AS_L6PHIBin_writeaddr,
        AS_L6PHIBin_din            => AS_L6PHIBin_din,
        AS_L6PHICin_wea            => AS_L6PHICin_wea,
        AS_L6PHICin_writeaddr      => AS_L6PHICin_writeaddr,
        AS_L6PHICin_din            => AS_L6PHICin_din,
        AS_L6PHIDin_wea            => AS_L6PHIDin_wea,
        AS_L6PHIDin_writeaddr      => AS_L6PHIDin_writeaddr,
        AS_L6PHIDin_din            => AS_L6PHIDin_din,
        AS_D1PHIAin_wea            => AS_D1PHIAin_wea,
        AS_D1PHIAin_writeaddr      => AS_D1PHIAin_writeaddr,
        AS_D1PHIAin_din            => AS_D1PHIAin_din,
        AS_D1PHIBin_wea            => AS_D1PHIBin_wea,
        AS_D1PHIBin_writeaddr      => AS_D1PHIBin_writeaddr,
        AS_D1PHIBin_din            => AS_D1PHIBin_din,
        AS_D1PHICin_wea            => AS_D1PHICin_wea,
        AS_D1PHICin_writeaddr      => AS_D1PHICin_writeaddr,
        AS_D1PHICin_din            => AS_D1PHICin_din,
        AS_D1PHIDin_wea            => AS_D1PHIDin_wea,
        AS_D1PHIDin_writeaddr      => AS_D1PHIDin_writeaddr,
        AS_D1PHIDin_din            => AS_D1PHIDin_din,
        AS_D2PHIAin_wea            => AS_D2PHIAin_wea,
        AS_D2PHIAin_writeaddr      => AS_D2PHIAin_writeaddr,
        AS_D2PHIAin_din            => AS_D2PHIAin_din,
        AS_D2PHIBin_wea            => AS_D2PHIBin_wea,
        AS_D2PHIBin_writeaddr      => AS_D2PHIBin_writeaddr,
        AS_D2PHIBin_din            => AS_D2PHIBin_din,
        AS_D2PHICin_wea            => AS_D2PHICin_wea,
        AS_D2PHICin_writeaddr      => AS_D2PHICin_writeaddr,
        AS_D2PHICin_din            => AS_D2PHICin_din,
        AS_D2PHIDin_wea            => AS_D2PHIDin_wea,
        AS_D2PHIDin_writeaddr      => AS_D2PHIDin_writeaddr,
        AS_D2PHIDin_din            => AS_D2PHIDin_din,
        AS_D3PHIAin_wea            => AS_D3PHIAin_wea,
        AS_D3PHIAin_writeaddr      => AS_D3PHIAin_writeaddr,
        AS_D3PHIAin_din            => AS_D3PHIAin_din,
        AS_D3PHIBin_wea            => AS_D3PHIBin_wea,
        AS_D3PHIBin_writeaddr      => AS_D3PHIBin_writeaddr,
        AS_D3PHIBin_din            => AS_D3PHIBin_din,
        AS_D3PHICin_wea            => AS_D3PHICin_wea,
        AS_D3PHICin_writeaddr      => AS_D3PHICin_writeaddr,
        AS_D3PHICin_din            => AS_D3PHICin_din,
        AS_D3PHIDin_wea            => AS_D3PHIDin_wea,
        AS_D3PHIDin_writeaddr      => AS_D3PHIDin_writeaddr,
        AS_D3PHIDin_din            => AS_D3PHIDin_din,
        AS_D4PHIAin_wea            => AS_D4PHIAin_wea,
        AS_D4PHIAin_writeaddr      => AS_D4PHIAin_writeaddr,
        AS_D4PHIAin_din            => AS_D4PHIAin_din,
        AS_D4PHIBin_wea            => AS_D4PHIBin_wea,
        AS_D4PHIBin_writeaddr      => AS_D4PHIBin_writeaddr,
        AS_D4PHIBin_din            => AS_D4PHIBin_din,
        AS_D4PHICin_wea            => AS_D4PHICin_wea,
        AS_D4PHICin_writeaddr      => AS_D4PHICin_writeaddr,
        AS_D4PHICin_din            => AS_D4PHICin_din,
        AS_D4PHIDin_wea            => AS_D4PHIDin_wea,
        AS_D4PHIDin_writeaddr      => AS_D4PHIDin_writeaddr,
        AS_D4PHIDin_din            => AS_D4PHIDin_din,
        AS_D5PHIAin_wea            => AS_D5PHIAin_wea,
        AS_D5PHIAin_writeaddr      => AS_D5PHIAin_writeaddr,
        AS_D5PHIAin_din            => AS_D5PHIAin_din,
        AS_D5PHIBin_wea            => AS_D5PHIBin_wea,
        AS_D5PHIBin_writeaddr      => AS_D5PHIBin_writeaddr,
        AS_D5PHIBin_din            => AS_D5PHIBin_din,
        AS_D5PHICin_wea            => AS_D5PHICin_wea,
        AS_D5PHICin_writeaddr      => AS_D5PHICin_writeaddr,
        AS_D5PHICin_din            => AS_D5PHICin_din,
        AS_D5PHIDin_wea            => AS_D5PHIDin_wea,
        AS_D5PHIDin_writeaddr      => AS_D5PHIDin_writeaddr,
        AS_D5PHIDin_din            => AS_D5PHIDin_din,
        MPAR_L1L2ABCin_wea         => MPAR_L1L2ABCin_wea,
        MPAR_L1L2ABCin_writeaddr   => MPAR_L1L2ABCin_writeaddr,
        MPAR_L1L2ABCin_din         => MPAR_L1L2ABCin_din,
        MPAR_L1L2DEin_wea          => MPAR_L1L2DEin_wea,
        MPAR_L1L2DEin_writeaddr    => MPAR_L1L2DEin_writeaddr,
        MPAR_L1L2DEin_din          => MPAR_L1L2DEin_din,
        MPAR_L1L2Fin_wea           => MPAR_L1L2Fin_wea,
        MPAR_L1L2Fin_writeaddr     => MPAR_L1L2Fin_writeaddr,
        MPAR_L1L2Fin_din           => MPAR_L1L2Fin_din,
        MPAR_L1L2Gin_wea           => MPAR_L1L2Gin_wea,
        MPAR_L1L2Gin_writeaddr     => MPAR_L1L2Gin_writeaddr,
        MPAR_L1L2Gin_din           => MPAR_L1L2Gin_din,
        MPAR_L1L2HIin_wea          => MPAR_L1L2HIin_wea,
        MPAR_L1L2HIin_writeaddr    => MPAR_L1L2HIin_writeaddr,
        MPAR_L1L2HIin_din          => MPAR_L1L2HIin_din,
        MPAR_L1L2JKLin_wea         => MPAR_L1L2JKLin_wea,
        MPAR_L1L2JKLin_writeaddr   => MPAR_L1L2JKLin_writeaddr,
        MPAR_L1L2JKLin_din         => MPAR_L1L2JKLin_din,
        MPAR_L2L3ABCDin_wea        => MPAR_L2L3ABCDin_wea,
        MPAR_L2L3ABCDin_writeaddr  => MPAR_L2L3ABCDin_writeaddr,
        MPAR_L2L3ABCDin_din        => MPAR_L2L3ABCDin_din,
        MPAR_L3L4ABin_wea          => MPAR_L3L4ABin_wea,
        MPAR_L3L4ABin_writeaddr    => MPAR_L3L4ABin_writeaddr,
        MPAR_L3L4ABin_din          => MPAR_L3L4ABin_din,
        MPAR_L3L4CDin_wea          => MPAR_L3L4CDin_wea,
        MPAR_L3L4CDin_writeaddr    => MPAR_L3L4CDin_writeaddr,
        MPAR_L3L4CDin_din          => MPAR_L3L4CDin_din,
        MPAR_L5L6ABCDin_wea        => MPAR_L5L6ABCDin_wea,
        MPAR_L5L6ABCDin_writeaddr  => MPAR_L5L6ABCDin_writeaddr,
        MPAR_L5L6ABCDin_din        => MPAR_L5L6ABCDin_din,
        MPAR_D1D2ABCDin_wea        => MPAR_D1D2ABCDin_wea,
        MPAR_D1D2ABCDin_writeaddr  => MPAR_D1D2ABCDin_writeaddr,
        MPAR_D1D2ABCDin_din        => MPAR_D1D2ABCDin_din,
        MPAR_D3D4ABCDin_wea        => MPAR_D3D4ABCDin_wea,
        MPAR_D3D4ABCDin_writeaddr  => MPAR_D3D4ABCDin_writeaddr,
        MPAR_D3D4ABCDin_din        => MPAR_D3D4ABCDin_din,
        MPAR_L1D1ABCDin_wea        => MPAR_L1D1ABCDin_wea,
        MPAR_L1D1ABCDin_writeaddr  => MPAR_L1D1ABCDin_writeaddr,
        MPAR_L1D1ABCDin_din        => MPAR_L1D1ABCDin_din,
        MPAR_L1D1EFGHin_wea        => MPAR_L1D1EFGHin_wea,
        MPAR_L1D1EFGHin_writeaddr  => MPAR_L1D1EFGHin_writeaddr,
        MPAR_L1D1EFGHin_din        => MPAR_L1D1EFGHin_din,
        MPAR_L2D1ABCDin_wea        => MPAR_L2D1ABCDin_wea,
        MPAR_L2D1ABCDin_writeaddr  => MPAR_L2D1ABCDin_writeaddr,
        MPAR_L2D1ABCDin_din        => MPAR_L2D1ABCDin_din,
        -- Debug output data
        VMSME_L1PHIAn2_wea         => VMSME_L1PHIAn2_wea,
        VMSME_L1PHIAn2_writeaddr   => VMSME_L1PHIAn2_writeaddr,
        VMSME_L1PHIAn2_din         => VMSME_L1PHIAn2_din,
        VMSME_L1PHIBn2_wea         => VMSME_L1PHIBn2_wea,
        VMSME_L1PHIBn2_writeaddr   => VMSME_L1PHIBn2_writeaddr,
        VMSME_L1PHIBn2_din         => VMSME_L1PHIBn2_din,
        VMSME_L1PHICn2_wea         => VMSME_L1PHICn2_wea,
        VMSME_L1PHICn2_writeaddr   => VMSME_L1PHICn2_writeaddr,
        VMSME_L1PHICn2_din         => VMSME_L1PHICn2_din,
        VMSME_L1PHIDn2_wea         => VMSME_L1PHIDn2_wea,
        VMSME_L1PHIDn2_writeaddr   => VMSME_L1PHIDn2_writeaddr,
        VMSME_L1PHIDn2_din         => VMSME_L1PHIDn2_din,
        VMSME_L1PHIEn2_wea         => VMSME_L1PHIEn2_wea,
        VMSME_L1PHIEn2_writeaddr   => VMSME_L1PHIEn2_writeaddr,
        VMSME_L1PHIEn2_din         => VMSME_L1PHIEn2_din,
        VMSME_L1PHIFn2_wea         => VMSME_L1PHIFn2_wea,
        VMSME_L1PHIFn2_writeaddr   => VMSME_L1PHIFn2_writeaddr,
        VMSME_L1PHIFn2_din         => VMSME_L1PHIFn2_din,
        VMSME_L1PHIGn2_wea         => VMSME_L1PHIGn2_wea,
        VMSME_L1PHIGn2_writeaddr   => VMSME_L1PHIGn2_writeaddr,
        VMSME_L1PHIGn2_din         => VMSME_L1PHIGn2_din,
        VMSME_L1PHIHn2_wea         => VMSME_L1PHIHn2_wea,
        VMSME_L1PHIHn2_writeaddr   => VMSME_L1PHIHn2_writeaddr,
        VMSME_L1PHIHn2_din         => VMSME_L1PHIHn2_din,
        VMSME_L2PHIAn2_wea         => VMSME_L2PHIAn2_wea,
        VMSME_L2PHIAn2_writeaddr   => VMSME_L2PHIAn2_writeaddr,
        VMSME_L2PHIAn2_din         => VMSME_L2PHIAn2_din,
        VMSME_L2PHIBn2_wea         => VMSME_L2PHIBn2_wea,
        VMSME_L2PHIBn2_writeaddr   => VMSME_L2PHIBn2_writeaddr,
        VMSME_L2PHIBn2_din         => VMSME_L2PHIBn2_din,
        VMSME_L2PHICn2_wea         => VMSME_L2PHICn2_wea,
        VMSME_L2PHICn2_writeaddr   => VMSME_L2PHICn2_writeaddr,
        VMSME_L2PHICn2_din         => VMSME_L2PHICn2_din,
        VMSME_L2PHIDn2_wea         => VMSME_L2PHIDn2_wea,
        VMSME_L2PHIDn2_writeaddr   => VMSME_L2PHIDn2_writeaddr,
        VMSME_L2PHIDn2_din         => VMSME_L2PHIDn2_din,
        VMSME_L3PHIAn2_wea         => VMSME_L3PHIAn2_wea,
        VMSME_L3PHIAn2_writeaddr   => VMSME_L3PHIAn2_writeaddr,
        VMSME_L3PHIAn2_din         => VMSME_L3PHIAn2_din,
        VMSME_L3PHIBn2_wea         => VMSME_L3PHIBn2_wea,
        VMSME_L3PHIBn2_writeaddr   => VMSME_L3PHIBn2_writeaddr,
        VMSME_L3PHIBn2_din         => VMSME_L3PHIBn2_din,
        VMSME_L3PHICn2_wea         => VMSME_L3PHICn2_wea,
        VMSME_L3PHICn2_writeaddr   => VMSME_L3PHICn2_writeaddr,
        VMSME_L3PHICn2_din         => VMSME_L3PHICn2_din,
        VMSME_L3PHIDn2_wea         => VMSME_L3PHIDn2_wea,
        VMSME_L3PHIDn2_writeaddr   => VMSME_L3PHIDn2_writeaddr,
        VMSME_L3PHIDn2_din         => VMSME_L3PHIDn2_din,
        VMSME_L4PHIAn2_wea         => VMSME_L4PHIAn2_wea,
        VMSME_L4PHIAn2_writeaddr   => VMSME_L4PHIAn2_writeaddr,
        VMSME_L4PHIAn2_din         => VMSME_L4PHIAn2_din,
        VMSME_L4PHIBn2_wea         => VMSME_L4PHIBn2_wea,
        VMSME_L4PHIBn2_writeaddr   => VMSME_L4PHIBn2_writeaddr,
        VMSME_L4PHIBn2_din         => VMSME_L4PHIBn2_din,
        VMSME_L4PHICn2_wea         => VMSME_L4PHICn2_wea,
        VMSME_L4PHICn2_writeaddr   => VMSME_L4PHICn2_writeaddr,
        VMSME_L4PHICn2_din         => VMSME_L4PHICn2_din,
        VMSME_L4PHIDn2_wea         => VMSME_L4PHIDn2_wea,
        VMSME_L4PHIDn2_writeaddr   => VMSME_L4PHIDn2_writeaddr,
        VMSME_L4PHIDn2_din         => VMSME_L4PHIDn2_din,
        VMSME_L5PHIAn2_wea         => VMSME_L5PHIAn2_wea,
        VMSME_L5PHIAn2_writeaddr   => VMSME_L5PHIAn2_writeaddr,
        VMSME_L5PHIAn2_din         => VMSME_L5PHIAn2_din,
        VMSME_L5PHIBn2_wea         => VMSME_L5PHIBn2_wea,
        VMSME_L5PHIBn2_writeaddr   => VMSME_L5PHIBn2_writeaddr,
        VMSME_L5PHIBn2_din         => VMSME_L5PHIBn2_din,
        VMSME_L5PHICn2_wea         => VMSME_L5PHICn2_wea,
        VMSME_L5PHICn2_writeaddr   => VMSME_L5PHICn2_writeaddr,
        VMSME_L5PHICn2_din         => VMSME_L5PHICn2_din,
        VMSME_L5PHIDn2_wea         => VMSME_L5PHIDn2_wea,
        VMSME_L5PHIDn2_writeaddr   => VMSME_L5PHIDn2_writeaddr,
        VMSME_L5PHIDn2_din         => VMSME_L5PHIDn2_din,
        VMSME_L6PHIAn2_wea         => VMSME_L6PHIAn2_wea,
        VMSME_L6PHIAn2_writeaddr   => VMSME_L6PHIAn2_writeaddr,
        VMSME_L6PHIAn2_din         => VMSME_L6PHIAn2_din,
        VMSME_L6PHIBn2_wea         => VMSME_L6PHIBn2_wea,
        VMSME_L6PHIBn2_writeaddr   => VMSME_L6PHIBn2_writeaddr,
        VMSME_L6PHIBn2_din         => VMSME_L6PHIBn2_din,
        VMSME_L6PHICn2_wea         => VMSME_L6PHICn2_wea,
        VMSME_L6PHICn2_writeaddr   => VMSME_L6PHICn2_writeaddr,
        VMSME_L6PHICn2_din         => VMSME_L6PHICn2_din,
        VMSME_L6PHIDn2_wea         => VMSME_L6PHIDn2_wea,
        VMSME_L6PHIDn2_writeaddr   => VMSME_L6PHIDn2_writeaddr,
        VMSME_L6PHIDn2_din         => VMSME_L6PHIDn2_din,
        VMSME_D1PHIAn2_wea         => VMSME_D1PHIAn2_wea,
        VMSME_D1PHIAn2_writeaddr   => VMSME_D1PHIAn2_writeaddr,
        VMSME_D1PHIAn2_din         => VMSME_D1PHIAn2_din,
        VMSME_D1PHIBn2_wea         => VMSME_D1PHIBn2_wea,
        VMSME_D1PHIBn2_writeaddr   => VMSME_D1PHIBn2_writeaddr,
        VMSME_D1PHIBn2_din         => VMSME_D1PHIBn2_din,
        VMSME_D1PHICn2_wea         => VMSME_D1PHICn2_wea,
        VMSME_D1PHICn2_writeaddr   => VMSME_D1PHICn2_writeaddr,
        VMSME_D1PHICn2_din         => VMSME_D1PHICn2_din,
        VMSME_D1PHIDn2_wea         => VMSME_D1PHIDn2_wea,
        VMSME_D1PHIDn2_writeaddr   => VMSME_D1PHIDn2_writeaddr,
        VMSME_D1PHIDn2_din         => VMSME_D1PHIDn2_din,
        VMSME_D2PHIAn2_wea         => VMSME_D2PHIAn2_wea,
        VMSME_D2PHIAn2_writeaddr   => VMSME_D2PHIAn2_writeaddr,
        VMSME_D2PHIAn2_din         => VMSME_D2PHIAn2_din,
        VMSME_D2PHIBn2_wea         => VMSME_D2PHIBn2_wea,
        VMSME_D2PHIBn2_writeaddr   => VMSME_D2PHIBn2_writeaddr,
        VMSME_D2PHIBn2_din         => VMSME_D2PHIBn2_din,
        VMSME_D2PHICn2_wea         => VMSME_D2PHICn2_wea,
        VMSME_D2PHICn2_writeaddr   => VMSME_D2PHICn2_writeaddr,
        VMSME_D2PHICn2_din         => VMSME_D2PHICn2_din,
        VMSME_D2PHIDn2_wea         => VMSME_D2PHIDn2_wea,
        VMSME_D2PHIDn2_writeaddr   => VMSME_D2PHIDn2_writeaddr,
        VMSME_D2PHIDn2_din         => VMSME_D2PHIDn2_din,
        VMSME_D3PHIAn2_wea         => VMSME_D3PHIAn2_wea,
        VMSME_D3PHIAn2_writeaddr   => VMSME_D3PHIAn2_writeaddr,
        VMSME_D3PHIAn2_din         => VMSME_D3PHIAn2_din,
        VMSME_D3PHIBn2_wea         => VMSME_D3PHIBn2_wea,
        VMSME_D3PHIBn2_writeaddr   => VMSME_D3PHIBn2_writeaddr,
        VMSME_D3PHIBn2_din         => VMSME_D3PHIBn2_din,
        VMSME_D3PHICn2_wea         => VMSME_D3PHICn2_wea,
        VMSME_D3PHICn2_writeaddr   => VMSME_D3PHICn2_writeaddr,
        VMSME_D3PHICn2_din         => VMSME_D3PHICn2_din,
        VMSME_D3PHIDn2_wea         => VMSME_D3PHIDn2_wea,
        VMSME_D3PHIDn2_writeaddr   => VMSME_D3PHIDn2_writeaddr,
        VMSME_D3PHIDn2_din         => VMSME_D3PHIDn2_din,
        VMSME_D4PHIAn2_wea         => VMSME_D4PHIAn2_wea,
        VMSME_D4PHIAn2_writeaddr   => VMSME_D4PHIAn2_writeaddr,
        VMSME_D4PHIAn2_din         => VMSME_D4PHIAn2_din,
        VMSME_D4PHIBn2_wea         => VMSME_D4PHIBn2_wea,
        VMSME_D4PHIBn2_writeaddr   => VMSME_D4PHIBn2_writeaddr,
        VMSME_D4PHIBn2_din         => VMSME_D4PHIBn2_din,
        VMSME_D4PHICn2_wea         => VMSME_D4PHICn2_wea,
        VMSME_D4PHICn2_writeaddr   => VMSME_D4PHICn2_writeaddr,
        VMSME_D4PHICn2_din         => VMSME_D4PHICn2_din,
        VMSME_D4PHIDn2_wea         => VMSME_D4PHIDn2_wea,
        VMSME_D4PHIDn2_writeaddr   => VMSME_D4PHIDn2_writeaddr,
        VMSME_D4PHIDn2_din         => VMSME_D4PHIDn2_din,
        VMSME_D5PHIAn2_wea         => VMSME_D5PHIAn2_wea,
        VMSME_D5PHIAn2_writeaddr   => VMSME_D5PHIAn2_writeaddr,
        VMSME_D5PHIAn2_din         => VMSME_D5PHIAn2_din,
        VMSME_D5PHIBn2_wea         => VMSME_D5PHIBn2_wea,
        VMSME_D5PHIBn2_writeaddr   => VMSME_D5PHIBn2_writeaddr,
        VMSME_D5PHIBn2_din         => VMSME_D5PHIBn2_din,
        VMSME_D5PHICn2_wea         => VMSME_D5PHICn2_wea,
        VMSME_D5PHICn2_writeaddr   => VMSME_D5PHICn2_writeaddr,
        VMSME_D5PHICn2_din         => VMSME_D5PHICn2_din,
        VMSME_D5PHIDn2_wea         => VMSME_D5PHIDn2_wea,
        VMSME_D5PHIDn2_writeaddr   => VMSME_D5PHIDn2_writeaddr,
        VMSME_D5PHIDn2_din         => VMSME_D5PHIDn2_din,
        MPROJ_L2L3ABCD_L1PHIA_wea  => MPROJ_L2L3ABCD_L1PHIA_wea,
        MPROJ_L2L3ABCD_L1PHIA_writeaddr=> MPROJ_L2L3ABCD_L1PHIA_writeaddr,
        MPROJ_L2L3ABCD_L1PHIA_din  => MPROJ_L2L3ABCD_L1PHIA_din,
        MPROJ_L3L4AB_L1PHIA_wea    => MPROJ_L3L4AB_L1PHIA_wea,
        MPROJ_L3L4AB_L1PHIA_writeaddr=> MPROJ_L3L4AB_L1PHIA_writeaddr,
        MPROJ_L3L4AB_L1PHIA_din    => MPROJ_L3L4AB_L1PHIA_din,
        MPROJ_L5L6ABCD_L1PHIA_wea  => MPROJ_L5L6ABCD_L1PHIA_wea,
        MPROJ_L5L6ABCD_L1PHIA_writeaddr=> MPROJ_L5L6ABCD_L1PHIA_writeaddr,
        MPROJ_L5L6ABCD_L1PHIA_din  => MPROJ_L5L6ABCD_L1PHIA_din,
        MPROJ_D1D2ABCD_L1PHIA_wea  => MPROJ_D1D2ABCD_L1PHIA_wea,
        MPROJ_D1D2ABCD_L1PHIA_writeaddr=> MPROJ_D1D2ABCD_L1PHIA_writeaddr,
        MPROJ_D1D2ABCD_L1PHIA_din  => MPROJ_D1D2ABCD_L1PHIA_din,
        MPROJ_D3D4ABCD_L1PHIA_wea  => MPROJ_D3D4ABCD_L1PHIA_wea,
        MPROJ_D3D4ABCD_L1PHIA_writeaddr=> MPROJ_D3D4ABCD_L1PHIA_writeaddr,
        MPROJ_D3D4ABCD_L1PHIA_din  => MPROJ_D3D4ABCD_L1PHIA_din,
        MPROJ_L2D1ABCD_L1PHIA_wea  => MPROJ_L2D1ABCD_L1PHIA_wea,
        MPROJ_L2D1ABCD_L1PHIA_writeaddr=> MPROJ_L2D1ABCD_L1PHIA_writeaddr,
        MPROJ_L2D1ABCD_L1PHIA_din  => MPROJ_L2D1ABCD_L1PHIA_din,
        MPROJ_L2L3ABCD_L1PHIB_wea  => MPROJ_L2L3ABCD_L1PHIB_wea,
        MPROJ_L2L3ABCD_L1PHIB_writeaddr=> MPROJ_L2L3ABCD_L1PHIB_writeaddr,
        MPROJ_L2L3ABCD_L1PHIB_din  => MPROJ_L2L3ABCD_L1PHIB_din,
        MPROJ_L3L4AB_L1PHIB_wea    => MPROJ_L3L4AB_L1PHIB_wea,
        MPROJ_L3L4AB_L1PHIB_writeaddr=> MPROJ_L3L4AB_L1PHIB_writeaddr,
        MPROJ_L3L4AB_L1PHIB_din    => MPROJ_L3L4AB_L1PHIB_din,
        MPROJ_L5L6ABCD_L1PHIB_wea  => MPROJ_L5L6ABCD_L1PHIB_wea,
        MPROJ_L5L6ABCD_L1PHIB_writeaddr=> MPROJ_L5L6ABCD_L1PHIB_writeaddr,
        MPROJ_L5L6ABCD_L1PHIB_din  => MPROJ_L5L6ABCD_L1PHIB_din,
        MPROJ_D1D2ABCD_L1PHIB_wea  => MPROJ_D1D2ABCD_L1PHIB_wea,
        MPROJ_D1D2ABCD_L1PHIB_writeaddr=> MPROJ_D1D2ABCD_L1PHIB_writeaddr,
        MPROJ_D1D2ABCD_L1PHIB_din  => MPROJ_D1D2ABCD_L1PHIB_din,
        MPROJ_D3D4ABCD_L1PHIB_wea  => MPROJ_D3D4ABCD_L1PHIB_wea,
        MPROJ_D3D4ABCD_L1PHIB_writeaddr=> MPROJ_D3D4ABCD_L1PHIB_writeaddr,
        MPROJ_D3D4ABCD_L1PHIB_din  => MPROJ_D3D4ABCD_L1PHIB_din,
        MPROJ_L2D1ABCD_L1PHIB_wea  => MPROJ_L2D1ABCD_L1PHIB_wea,
        MPROJ_L2D1ABCD_L1PHIB_writeaddr=> MPROJ_L2D1ABCD_L1PHIB_writeaddr,
        MPROJ_L2D1ABCD_L1PHIB_din  => MPROJ_L2D1ABCD_L1PHIB_din,
        MPROJ_L2L3ABCD_L1PHIC_wea  => MPROJ_L2L3ABCD_L1PHIC_wea,
        MPROJ_L2L3ABCD_L1PHIC_writeaddr=> MPROJ_L2L3ABCD_L1PHIC_writeaddr,
        MPROJ_L2L3ABCD_L1PHIC_din  => MPROJ_L2L3ABCD_L1PHIC_din,
        MPROJ_L3L4AB_L1PHIC_wea    => MPROJ_L3L4AB_L1PHIC_wea,
        MPROJ_L3L4AB_L1PHIC_writeaddr=> MPROJ_L3L4AB_L1PHIC_writeaddr,
        MPROJ_L3L4AB_L1PHIC_din    => MPROJ_L3L4AB_L1PHIC_din,
        MPROJ_L5L6ABCD_L1PHIC_wea  => MPROJ_L5L6ABCD_L1PHIC_wea,
        MPROJ_L5L6ABCD_L1PHIC_writeaddr=> MPROJ_L5L6ABCD_L1PHIC_writeaddr,
        MPROJ_L5L6ABCD_L1PHIC_din  => MPROJ_L5L6ABCD_L1PHIC_din,
        MPROJ_D1D2ABCD_L1PHIC_wea  => MPROJ_D1D2ABCD_L1PHIC_wea,
        MPROJ_D1D2ABCD_L1PHIC_writeaddr=> MPROJ_D1D2ABCD_L1PHIC_writeaddr,
        MPROJ_D1D2ABCD_L1PHIC_din  => MPROJ_D1D2ABCD_L1PHIC_din,
        MPROJ_D3D4ABCD_L1PHIC_wea  => MPROJ_D3D4ABCD_L1PHIC_wea,
        MPROJ_D3D4ABCD_L1PHIC_writeaddr=> MPROJ_D3D4ABCD_L1PHIC_writeaddr,
        MPROJ_D3D4ABCD_L1PHIC_din  => MPROJ_D3D4ABCD_L1PHIC_din,
        MPROJ_L2D1ABCD_L1PHIC_wea  => MPROJ_L2D1ABCD_L1PHIC_wea,
        MPROJ_L2D1ABCD_L1PHIC_writeaddr=> MPROJ_L2D1ABCD_L1PHIC_writeaddr,
        MPROJ_L2D1ABCD_L1PHIC_din  => MPROJ_L2D1ABCD_L1PHIC_din,
        MPROJ_L2L3ABCD_L1PHID_wea  => MPROJ_L2L3ABCD_L1PHID_wea,
        MPROJ_L2L3ABCD_L1PHID_writeaddr=> MPROJ_L2L3ABCD_L1PHID_writeaddr,
        MPROJ_L2L3ABCD_L1PHID_din  => MPROJ_L2L3ABCD_L1PHID_din,
        MPROJ_L3L4AB_L1PHID_wea    => MPROJ_L3L4AB_L1PHID_wea,
        MPROJ_L3L4AB_L1PHID_writeaddr=> MPROJ_L3L4AB_L1PHID_writeaddr,
        MPROJ_L3L4AB_L1PHID_din    => MPROJ_L3L4AB_L1PHID_din,
        MPROJ_L3L4CD_L1PHID_wea    => MPROJ_L3L4CD_L1PHID_wea,
        MPROJ_L3L4CD_L1PHID_writeaddr=> MPROJ_L3L4CD_L1PHID_writeaddr,
        MPROJ_L3L4CD_L1PHID_din    => MPROJ_L3L4CD_L1PHID_din,
        MPROJ_L5L6ABCD_L1PHID_wea  => MPROJ_L5L6ABCD_L1PHID_wea,
        MPROJ_L5L6ABCD_L1PHID_writeaddr=> MPROJ_L5L6ABCD_L1PHID_writeaddr,
        MPROJ_L5L6ABCD_L1PHID_din  => MPROJ_L5L6ABCD_L1PHID_din,
        MPROJ_D1D2ABCD_L1PHID_wea  => MPROJ_D1D2ABCD_L1PHID_wea,
        MPROJ_D1D2ABCD_L1PHID_writeaddr=> MPROJ_D1D2ABCD_L1PHID_writeaddr,
        MPROJ_D1D2ABCD_L1PHID_din  => MPROJ_D1D2ABCD_L1PHID_din,
        MPROJ_D3D4ABCD_L1PHID_wea  => MPROJ_D3D4ABCD_L1PHID_wea,
        MPROJ_D3D4ABCD_L1PHID_writeaddr=> MPROJ_D3D4ABCD_L1PHID_writeaddr,
        MPROJ_D3D4ABCD_L1PHID_din  => MPROJ_D3D4ABCD_L1PHID_din,
        MPROJ_L2D1ABCD_L1PHID_wea  => MPROJ_L2D1ABCD_L1PHID_wea,
        MPROJ_L2D1ABCD_L1PHID_writeaddr=> MPROJ_L2D1ABCD_L1PHID_writeaddr,
        MPROJ_L2D1ABCD_L1PHID_din  => MPROJ_L2D1ABCD_L1PHID_din,
        MPROJ_L2L3ABCD_L1PHIE_wea  => MPROJ_L2L3ABCD_L1PHIE_wea,
        MPROJ_L2L3ABCD_L1PHIE_writeaddr=> MPROJ_L2L3ABCD_L1PHIE_writeaddr,
        MPROJ_L2L3ABCD_L1PHIE_din  => MPROJ_L2L3ABCD_L1PHIE_din,
        MPROJ_L3L4AB_L1PHIE_wea    => MPROJ_L3L4AB_L1PHIE_wea,
        MPROJ_L3L4AB_L1PHIE_writeaddr=> MPROJ_L3L4AB_L1PHIE_writeaddr,
        MPROJ_L3L4AB_L1PHIE_din    => MPROJ_L3L4AB_L1PHIE_din,
        MPROJ_L3L4CD_L1PHIE_wea    => MPROJ_L3L4CD_L1PHIE_wea,
        MPROJ_L3L4CD_L1PHIE_writeaddr=> MPROJ_L3L4CD_L1PHIE_writeaddr,
        MPROJ_L3L4CD_L1PHIE_din    => MPROJ_L3L4CD_L1PHIE_din,
        MPROJ_L5L6ABCD_L1PHIE_wea  => MPROJ_L5L6ABCD_L1PHIE_wea,
        MPROJ_L5L6ABCD_L1PHIE_writeaddr=> MPROJ_L5L6ABCD_L1PHIE_writeaddr,
        MPROJ_L5L6ABCD_L1PHIE_din  => MPROJ_L5L6ABCD_L1PHIE_din,
        MPROJ_D1D2ABCD_L1PHIE_wea  => MPROJ_D1D2ABCD_L1PHIE_wea,
        MPROJ_D1D2ABCD_L1PHIE_writeaddr=> MPROJ_D1D2ABCD_L1PHIE_writeaddr,
        MPROJ_D1D2ABCD_L1PHIE_din  => MPROJ_D1D2ABCD_L1PHIE_din,
        MPROJ_D3D4ABCD_L1PHIE_wea  => MPROJ_D3D4ABCD_L1PHIE_wea,
        MPROJ_D3D4ABCD_L1PHIE_writeaddr=> MPROJ_D3D4ABCD_L1PHIE_writeaddr,
        MPROJ_D3D4ABCD_L1PHIE_din  => MPROJ_D3D4ABCD_L1PHIE_din,
        MPROJ_L2D1ABCD_L1PHIE_wea  => MPROJ_L2D1ABCD_L1PHIE_wea,
        MPROJ_L2D1ABCD_L1PHIE_writeaddr=> MPROJ_L2D1ABCD_L1PHIE_writeaddr,
        MPROJ_L2D1ABCD_L1PHIE_din  => MPROJ_L2D1ABCD_L1PHIE_din,
        MPROJ_L2L3ABCD_L1PHIF_wea  => MPROJ_L2L3ABCD_L1PHIF_wea,
        MPROJ_L2L3ABCD_L1PHIF_writeaddr=> MPROJ_L2L3ABCD_L1PHIF_writeaddr,
        MPROJ_L2L3ABCD_L1PHIF_din  => MPROJ_L2L3ABCD_L1PHIF_din,
        MPROJ_L3L4AB_L1PHIF_wea    => MPROJ_L3L4AB_L1PHIF_wea,
        MPROJ_L3L4AB_L1PHIF_writeaddr=> MPROJ_L3L4AB_L1PHIF_writeaddr,
        MPROJ_L3L4AB_L1PHIF_din    => MPROJ_L3L4AB_L1PHIF_din,
        MPROJ_L3L4CD_L1PHIF_wea    => MPROJ_L3L4CD_L1PHIF_wea,
        MPROJ_L3L4CD_L1PHIF_writeaddr=> MPROJ_L3L4CD_L1PHIF_writeaddr,
        MPROJ_L3L4CD_L1PHIF_din    => MPROJ_L3L4CD_L1PHIF_din,
        MPROJ_L5L6ABCD_L1PHIF_wea  => MPROJ_L5L6ABCD_L1PHIF_wea,
        MPROJ_L5L6ABCD_L1PHIF_writeaddr=> MPROJ_L5L6ABCD_L1PHIF_writeaddr,
        MPROJ_L5L6ABCD_L1PHIF_din  => MPROJ_L5L6ABCD_L1PHIF_din,
        MPROJ_D1D2ABCD_L1PHIF_wea  => MPROJ_D1D2ABCD_L1PHIF_wea,
        MPROJ_D1D2ABCD_L1PHIF_writeaddr=> MPROJ_D1D2ABCD_L1PHIF_writeaddr,
        MPROJ_D1D2ABCD_L1PHIF_din  => MPROJ_D1D2ABCD_L1PHIF_din,
        MPROJ_D3D4ABCD_L1PHIF_wea  => MPROJ_D3D4ABCD_L1PHIF_wea,
        MPROJ_D3D4ABCD_L1PHIF_writeaddr=> MPROJ_D3D4ABCD_L1PHIF_writeaddr,
        MPROJ_D3D4ABCD_L1PHIF_din  => MPROJ_D3D4ABCD_L1PHIF_din,
        MPROJ_L2D1ABCD_L1PHIF_wea  => MPROJ_L2D1ABCD_L1PHIF_wea,
        MPROJ_L2D1ABCD_L1PHIF_writeaddr=> MPROJ_L2D1ABCD_L1PHIF_writeaddr,
        MPROJ_L2D1ABCD_L1PHIF_din  => MPROJ_L2D1ABCD_L1PHIF_din,
        MPROJ_L2L3ABCD_L1PHIG_wea  => MPROJ_L2L3ABCD_L1PHIG_wea,
        MPROJ_L2L3ABCD_L1PHIG_writeaddr=> MPROJ_L2L3ABCD_L1PHIG_writeaddr,
        MPROJ_L2L3ABCD_L1PHIG_din  => MPROJ_L2L3ABCD_L1PHIG_din,
        MPROJ_L3L4CD_L1PHIG_wea    => MPROJ_L3L4CD_L1PHIG_wea,
        MPROJ_L3L4CD_L1PHIG_writeaddr=> MPROJ_L3L4CD_L1PHIG_writeaddr,
        MPROJ_L3L4CD_L1PHIG_din    => MPROJ_L3L4CD_L1PHIG_din,
        MPROJ_L5L6ABCD_L1PHIG_wea  => MPROJ_L5L6ABCD_L1PHIG_wea,
        MPROJ_L5L6ABCD_L1PHIG_writeaddr=> MPROJ_L5L6ABCD_L1PHIG_writeaddr,
        MPROJ_L5L6ABCD_L1PHIG_din  => MPROJ_L5L6ABCD_L1PHIG_din,
        MPROJ_D1D2ABCD_L1PHIG_wea  => MPROJ_D1D2ABCD_L1PHIG_wea,
        MPROJ_D1D2ABCD_L1PHIG_writeaddr=> MPROJ_D1D2ABCD_L1PHIG_writeaddr,
        MPROJ_D1D2ABCD_L1PHIG_din  => MPROJ_D1D2ABCD_L1PHIG_din,
        MPROJ_D3D4ABCD_L1PHIG_wea  => MPROJ_D3D4ABCD_L1PHIG_wea,
        MPROJ_D3D4ABCD_L1PHIG_writeaddr=> MPROJ_D3D4ABCD_L1PHIG_writeaddr,
        MPROJ_D3D4ABCD_L1PHIG_din  => MPROJ_D3D4ABCD_L1PHIG_din,
        MPROJ_L2D1ABCD_L1PHIG_wea  => MPROJ_L2D1ABCD_L1PHIG_wea,
        MPROJ_L2D1ABCD_L1PHIG_writeaddr=> MPROJ_L2D1ABCD_L1PHIG_writeaddr,
        MPROJ_L2D1ABCD_L1PHIG_din  => MPROJ_L2D1ABCD_L1PHIG_din,
        MPROJ_L2L3ABCD_L1PHIH_wea  => MPROJ_L2L3ABCD_L1PHIH_wea,
        MPROJ_L2L3ABCD_L1PHIH_writeaddr=> MPROJ_L2L3ABCD_L1PHIH_writeaddr,
        MPROJ_L2L3ABCD_L1PHIH_din  => MPROJ_L2L3ABCD_L1PHIH_din,
        MPROJ_L3L4CD_L1PHIH_wea    => MPROJ_L3L4CD_L1PHIH_wea,
        MPROJ_L3L4CD_L1PHIH_writeaddr=> MPROJ_L3L4CD_L1PHIH_writeaddr,
        MPROJ_L3L4CD_L1PHIH_din    => MPROJ_L3L4CD_L1PHIH_din,
        MPROJ_L5L6ABCD_L1PHIH_wea  => MPROJ_L5L6ABCD_L1PHIH_wea,
        MPROJ_L5L6ABCD_L1PHIH_writeaddr=> MPROJ_L5L6ABCD_L1PHIH_writeaddr,
        MPROJ_L5L6ABCD_L1PHIH_din  => MPROJ_L5L6ABCD_L1PHIH_din,
        MPROJ_D1D2ABCD_L1PHIH_wea  => MPROJ_D1D2ABCD_L1PHIH_wea,
        MPROJ_D1D2ABCD_L1PHIH_writeaddr=> MPROJ_D1D2ABCD_L1PHIH_writeaddr,
        MPROJ_D1D2ABCD_L1PHIH_din  => MPROJ_D1D2ABCD_L1PHIH_din,
        MPROJ_D3D4ABCD_L1PHIH_wea  => MPROJ_D3D4ABCD_L1PHIH_wea,
        MPROJ_D3D4ABCD_L1PHIH_writeaddr=> MPROJ_D3D4ABCD_L1PHIH_writeaddr,
        MPROJ_D3D4ABCD_L1PHIH_din  => MPROJ_D3D4ABCD_L1PHIH_din,
        MPROJ_L2D1ABCD_L1PHIH_wea  => MPROJ_L2D1ABCD_L1PHIH_wea,
        MPROJ_L2D1ABCD_L1PHIH_writeaddr=> MPROJ_L2D1ABCD_L1PHIH_writeaddr,
        MPROJ_L2D1ABCD_L1PHIH_din  => MPROJ_L2D1ABCD_L1PHIH_din,
        MPROJ_L3L4AB_L2PHIA_wea    => MPROJ_L3L4AB_L2PHIA_wea,
        MPROJ_L3L4AB_L2PHIA_writeaddr=> MPROJ_L3L4AB_L2PHIA_writeaddr,
        MPROJ_L3L4AB_L2PHIA_din    => MPROJ_L3L4AB_L2PHIA_din,
        MPROJ_L5L6ABCD_L2PHIA_wea  => MPROJ_L5L6ABCD_L2PHIA_wea,
        MPROJ_L5L6ABCD_L2PHIA_writeaddr=> MPROJ_L5L6ABCD_L2PHIA_writeaddr,
        MPROJ_L5L6ABCD_L2PHIA_din  => MPROJ_L5L6ABCD_L2PHIA_din,
        MPROJ_D1D2ABCD_L2PHIA_wea  => MPROJ_D1D2ABCD_L2PHIA_wea,
        MPROJ_D1D2ABCD_L2PHIA_writeaddr=> MPROJ_D1D2ABCD_L2PHIA_writeaddr,
        MPROJ_D1D2ABCD_L2PHIA_din  => MPROJ_D1D2ABCD_L2PHIA_din,
        MPROJ_L3L4AB_L2PHIB_wea    => MPROJ_L3L4AB_L2PHIB_wea,
        MPROJ_L3L4AB_L2PHIB_writeaddr=> MPROJ_L3L4AB_L2PHIB_writeaddr,
        MPROJ_L3L4AB_L2PHIB_din    => MPROJ_L3L4AB_L2PHIB_din,
        MPROJ_L3L4CD_L2PHIB_wea    => MPROJ_L3L4CD_L2PHIB_wea,
        MPROJ_L3L4CD_L2PHIB_writeaddr=> MPROJ_L3L4CD_L2PHIB_writeaddr,
        MPROJ_L3L4CD_L2PHIB_din    => MPROJ_L3L4CD_L2PHIB_din,
        MPROJ_L5L6ABCD_L2PHIB_wea  => MPROJ_L5L6ABCD_L2PHIB_wea,
        MPROJ_L5L6ABCD_L2PHIB_writeaddr=> MPROJ_L5L6ABCD_L2PHIB_writeaddr,
        MPROJ_L5L6ABCD_L2PHIB_din  => MPROJ_L5L6ABCD_L2PHIB_din,
        MPROJ_D1D2ABCD_L2PHIB_wea  => MPROJ_D1D2ABCD_L2PHIB_wea,
        MPROJ_D1D2ABCD_L2PHIB_writeaddr=> MPROJ_D1D2ABCD_L2PHIB_writeaddr,
        MPROJ_D1D2ABCD_L2PHIB_din  => MPROJ_D1D2ABCD_L2PHIB_din,
        MPROJ_L3L4AB_L2PHIC_wea    => MPROJ_L3L4AB_L2PHIC_wea,
        MPROJ_L3L4AB_L2PHIC_writeaddr=> MPROJ_L3L4AB_L2PHIC_writeaddr,
        MPROJ_L3L4AB_L2PHIC_din    => MPROJ_L3L4AB_L2PHIC_din,
        MPROJ_L3L4CD_L2PHIC_wea    => MPROJ_L3L4CD_L2PHIC_wea,
        MPROJ_L3L4CD_L2PHIC_writeaddr=> MPROJ_L3L4CD_L2PHIC_writeaddr,
        MPROJ_L3L4CD_L2PHIC_din    => MPROJ_L3L4CD_L2PHIC_din,
        MPROJ_L5L6ABCD_L2PHIC_wea  => MPROJ_L5L6ABCD_L2PHIC_wea,
        MPROJ_L5L6ABCD_L2PHIC_writeaddr=> MPROJ_L5L6ABCD_L2PHIC_writeaddr,
        MPROJ_L5L6ABCD_L2PHIC_din  => MPROJ_L5L6ABCD_L2PHIC_din,
        MPROJ_D1D2ABCD_L2PHIC_wea  => MPROJ_D1D2ABCD_L2PHIC_wea,
        MPROJ_D1D2ABCD_L2PHIC_writeaddr=> MPROJ_D1D2ABCD_L2PHIC_writeaddr,
        MPROJ_D1D2ABCD_L2PHIC_din  => MPROJ_D1D2ABCD_L2PHIC_din,
        MPROJ_L3L4CD_L2PHID_wea    => MPROJ_L3L4CD_L2PHID_wea,
        MPROJ_L3L4CD_L2PHID_writeaddr=> MPROJ_L3L4CD_L2PHID_writeaddr,
        MPROJ_L3L4CD_L2PHID_din    => MPROJ_L3L4CD_L2PHID_din,
        MPROJ_L5L6ABCD_L2PHID_wea  => MPROJ_L5L6ABCD_L2PHID_wea,
        MPROJ_L5L6ABCD_L2PHID_writeaddr=> MPROJ_L5L6ABCD_L2PHID_writeaddr,
        MPROJ_L5L6ABCD_L2PHID_din  => MPROJ_L5L6ABCD_L2PHID_din,
        MPROJ_D1D2ABCD_L2PHID_wea  => MPROJ_D1D2ABCD_L2PHID_wea,
        MPROJ_D1D2ABCD_L2PHID_writeaddr=> MPROJ_D1D2ABCD_L2PHID_writeaddr,
        MPROJ_D1D2ABCD_L2PHID_din  => MPROJ_D1D2ABCD_L2PHID_din,
        MPROJ_L1L2ABC_L3PHIA_wea   => MPROJ_L1L2ABC_L3PHIA_wea,
        MPROJ_L1L2ABC_L3PHIA_writeaddr=> MPROJ_L1L2ABC_L3PHIA_writeaddr,
        MPROJ_L1L2ABC_L3PHIA_din   => MPROJ_L1L2ABC_L3PHIA_din,
        MPROJ_L1L2DE_L3PHIA_wea    => MPROJ_L1L2DE_L3PHIA_wea,
        MPROJ_L1L2DE_L3PHIA_writeaddr=> MPROJ_L1L2DE_L3PHIA_writeaddr,
        MPROJ_L1L2DE_L3PHIA_din    => MPROJ_L1L2DE_L3PHIA_din,
        MPROJ_L5L6ABCD_L3PHIA_wea  => MPROJ_L5L6ABCD_L3PHIA_wea,
        MPROJ_L5L6ABCD_L3PHIA_writeaddr=> MPROJ_L5L6ABCD_L3PHIA_writeaddr,
        MPROJ_L5L6ABCD_L3PHIA_din  => MPROJ_L5L6ABCD_L3PHIA_din,
        MPROJ_L1L2ABC_L3PHIB_wea   => MPROJ_L1L2ABC_L3PHIB_wea,
        MPROJ_L1L2ABC_L3PHIB_writeaddr=> MPROJ_L1L2ABC_L3PHIB_writeaddr,
        MPROJ_L1L2ABC_L3PHIB_din   => MPROJ_L1L2ABC_L3PHIB_din,
        MPROJ_L1L2DE_L3PHIB_wea    => MPROJ_L1L2DE_L3PHIB_wea,
        MPROJ_L1L2DE_L3PHIB_writeaddr=> MPROJ_L1L2DE_L3PHIB_writeaddr,
        MPROJ_L1L2DE_L3PHIB_din    => MPROJ_L1L2DE_L3PHIB_din,
        MPROJ_L1L2F_L3PHIB_wea     => MPROJ_L1L2F_L3PHIB_wea,
        MPROJ_L1L2F_L3PHIB_writeaddr=> MPROJ_L1L2F_L3PHIB_writeaddr,
        MPROJ_L1L2F_L3PHIB_din     => MPROJ_L1L2F_L3PHIB_din,
        MPROJ_L1L2G_L3PHIB_wea     => MPROJ_L1L2G_L3PHIB_wea,
        MPROJ_L1L2G_L3PHIB_writeaddr=> MPROJ_L1L2G_L3PHIB_writeaddr,
        MPROJ_L1L2G_L3PHIB_din     => MPROJ_L1L2G_L3PHIB_din,
        MPROJ_L1L2HI_L3PHIB_wea    => MPROJ_L1L2HI_L3PHIB_wea,
        MPROJ_L1L2HI_L3PHIB_writeaddr=> MPROJ_L1L2HI_L3PHIB_writeaddr,
        MPROJ_L1L2HI_L3PHIB_din    => MPROJ_L1L2HI_L3PHIB_din,
        MPROJ_L5L6ABCD_L3PHIB_wea  => MPROJ_L5L6ABCD_L3PHIB_wea,
        MPROJ_L5L6ABCD_L3PHIB_writeaddr=> MPROJ_L5L6ABCD_L3PHIB_writeaddr,
        MPROJ_L5L6ABCD_L3PHIB_din  => MPROJ_L5L6ABCD_L3PHIB_din,
        MPROJ_L1L2DE_L3PHIC_wea    => MPROJ_L1L2DE_L3PHIC_wea,
        MPROJ_L1L2DE_L3PHIC_writeaddr=> MPROJ_L1L2DE_L3PHIC_writeaddr,
        MPROJ_L1L2DE_L3PHIC_din    => MPROJ_L1L2DE_L3PHIC_din,
        MPROJ_L1L2F_L3PHIC_wea     => MPROJ_L1L2F_L3PHIC_wea,
        MPROJ_L1L2F_L3PHIC_writeaddr=> MPROJ_L1L2F_L3PHIC_writeaddr,
        MPROJ_L1L2F_L3PHIC_din     => MPROJ_L1L2F_L3PHIC_din,
        MPROJ_L1L2G_L3PHIC_wea     => MPROJ_L1L2G_L3PHIC_wea,
        MPROJ_L1L2G_L3PHIC_writeaddr=> MPROJ_L1L2G_L3PHIC_writeaddr,
        MPROJ_L1L2G_L3PHIC_din     => MPROJ_L1L2G_L3PHIC_din,
        MPROJ_L1L2HI_L3PHIC_wea    => MPROJ_L1L2HI_L3PHIC_wea,
        MPROJ_L1L2HI_L3PHIC_writeaddr=> MPROJ_L1L2HI_L3PHIC_writeaddr,
        MPROJ_L1L2HI_L3PHIC_din    => MPROJ_L1L2HI_L3PHIC_din,
        MPROJ_L1L2JKL_L3PHIC_wea   => MPROJ_L1L2JKL_L3PHIC_wea,
        MPROJ_L1L2JKL_L3PHIC_writeaddr=> MPROJ_L1L2JKL_L3PHIC_writeaddr,
        MPROJ_L1L2JKL_L3PHIC_din   => MPROJ_L1L2JKL_L3PHIC_din,
        MPROJ_L5L6ABCD_L3PHIC_wea  => MPROJ_L5L6ABCD_L3PHIC_wea,
        MPROJ_L5L6ABCD_L3PHIC_writeaddr=> MPROJ_L5L6ABCD_L3PHIC_writeaddr,
        MPROJ_L5L6ABCD_L3PHIC_din  => MPROJ_L5L6ABCD_L3PHIC_din,
        MPROJ_L1L2HI_L3PHID_wea    => MPROJ_L1L2HI_L3PHID_wea,
        MPROJ_L1L2HI_L3PHID_writeaddr=> MPROJ_L1L2HI_L3PHID_writeaddr,
        MPROJ_L1L2HI_L3PHID_din    => MPROJ_L1L2HI_L3PHID_din,
        MPROJ_L1L2JKL_L3PHID_wea   => MPROJ_L1L2JKL_L3PHID_wea,
        MPROJ_L1L2JKL_L3PHID_writeaddr=> MPROJ_L1L2JKL_L3PHID_writeaddr,
        MPROJ_L1L2JKL_L3PHID_din   => MPROJ_L1L2JKL_L3PHID_din,
        MPROJ_L5L6ABCD_L3PHID_wea  => MPROJ_L5L6ABCD_L3PHID_wea,
        MPROJ_L5L6ABCD_L3PHID_writeaddr=> MPROJ_L5L6ABCD_L3PHID_writeaddr,
        MPROJ_L5L6ABCD_L3PHID_din  => MPROJ_L5L6ABCD_L3PHID_din,
        MPROJ_L1L2ABC_L4PHIA_wea   => MPROJ_L1L2ABC_L4PHIA_wea,
        MPROJ_L1L2ABC_L4PHIA_writeaddr=> MPROJ_L1L2ABC_L4PHIA_writeaddr,
        MPROJ_L1L2ABC_L4PHIA_din   => MPROJ_L1L2ABC_L4PHIA_din,
        MPROJ_L1L2DE_L4PHIA_wea    => MPROJ_L1L2DE_L4PHIA_wea,
        MPROJ_L1L2DE_L4PHIA_writeaddr=> MPROJ_L1L2DE_L4PHIA_writeaddr,
        MPROJ_L1L2DE_L4PHIA_din    => MPROJ_L1L2DE_L4PHIA_din,
        MPROJ_L1L2F_L4PHIA_wea     => MPROJ_L1L2F_L4PHIA_wea,
        MPROJ_L1L2F_L4PHIA_writeaddr=> MPROJ_L1L2F_L4PHIA_writeaddr,
        MPROJ_L1L2F_L4PHIA_din     => MPROJ_L1L2F_L4PHIA_din,
        MPROJ_L2L3ABCD_L4PHIA_wea  => MPROJ_L2L3ABCD_L4PHIA_wea,
        MPROJ_L2L3ABCD_L4PHIA_writeaddr=> MPROJ_L2L3ABCD_L4PHIA_writeaddr,
        MPROJ_L2L3ABCD_L4PHIA_din  => MPROJ_L2L3ABCD_L4PHIA_din,
        MPROJ_L5L6ABCD_L4PHIA_wea  => MPROJ_L5L6ABCD_L4PHIA_wea,
        MPROJ_L5L6ABCD_L4PHIA_writeaddr=> MPROJ_L5L6ABCD_L4PHIA_writeaddr,
        MPROJ_L5L6ABCD_L4PHIA_din  => MPROJ_L5L6ABCD_L4PHIA_din,
        MPROJ_L1L2ABC_L4PHIB_wea   => MPROJ_L1L2ABC_L4PHIB_wea,
        MPROJ_L1L2ABC_L4PHIB_writeaddr=> MPROJ_L1L2ABC_L4PHIB_writeaddr,
        MPROJ_L1L2ABC_L4PHIB_din   => MPROJ_L1L2ABC_L4PHIB_din,
        MPROJ_L1L2DE_L4PHIB_wea    => MPROJ_L1L2DE_L4PHIB_wea,
        MPROJ_L1L2DE_L4PHIB_writeaddr=> MPROJ_L1L2DE_L4PHIB_writeaddr,
        MPROJ_L1L2DE_L4PHIB_din    => MPROJ_L1L2DE_L4PHIB_din,
        MPROJ_L1L2F_L4PHIB_wea     => MPROJ_L1L2F_L4PHIB_wea,
        MPROJ_L1L2F_L4PHIB_writeaddr=> MPROJ_L1L2F_L4PHIB_writeaddr,
        MPROJ_L1L2F_L4PHIB_din     => MPROJ_L1L2F_L4PHIB_din,
        MPROJ_L1L2G_L4PHIB_wea     => MPROJ_L1L2G_L4PHIB_wea,
        MPROJ_L1L2G_L4PHIB_writeaddr=> MPROJ_L1L2G_L4PHIB_writeaddr,
        MPROJ_L1L2G_L4PHIB_din     => MPROJ_L1L2G_L4PHIB_din,
        MPROJ_L1L2HI_L4PHIB_wea    => MPROJ_L1L2HI_L4PHIB_wea,
        MPROJ_L1L2HI_L4PHIB_writeaddr=> MPROJ_L1L2HI_L4PHIB_writeaddr,
        MPROJ_L1L2HI_L4PHIB_din    => MPROJ_L1L2HI_L4PHIB_din,
        MPROJ_L2L3ABCD_L4PHIB_wea  => MPROJ_L2L3ABCD_L4PHIB_wea,
        MPROJ_L2L3ABCD_L4PHIB_writeaddr=> MPROJ_L2L3ABCD_L4PHIB_writeaddr,
        MPROJ_L2L3ABCD_L4PHIB_din  => MPROJ_L2L3ABCD_L4PHIB_din,
        MPROJ_L5L6ABCD_L4PHIB_wea  => MPROJ_L5L6ABCD_L4PHIB_wea,
        MPROJ_L5L6ABCD_L4PHIB_writeaddr=> MPROJ_L5L6ABCD_L4PHIB_writeaddr,
        MPROJ_L5L6ABCD_L4PHIB_din  => MPROJ_L5L6ABCD_L4PHIB_din,
        MPROJ_L1L2DE_L4PHIC_wea    => MPROJ_L1L2DE_L4PHIC_wea,
        MPROJ_L1L2DE_L4PHIC_writeaddr=> MPROJ_L1L2DE_L4PHIC_writeaddr,
        MPROJ_L1L2DE_L4PHIC_din    => MPROJ_L1L2DE_L4PHIC_din,
        MPROJ_L1L2F_L4PHIC_wea     => MPROJ_L1L2F_L4PHIC_wea,
        MPROJ_L1L2F_L4PHIC_writeaddr=> MPROJ_L1L2F_L4PHIC_writeaddr,
        MPROJ_L1L2F_L4PHIC_din     => MPROJ_L1L2F_L4PHIC_din,
        MPROJ_L1L2G_L4PHIC_wea     => MPROJ_L1L2G_L4PHIC_wea,
        MPROJ_L1L2G_L4PHIC_writeaddr=> MPROJ_L1L2G_L4PHIC_writeaddr,
        MPROJ_L1L2G_L4PHIC_din     => MPROJ_L1L2G_L4PHIC_din,
        MPROJ_L1L2HI_L4PHIC_wea    => MPROJ_L1L2HI_L4PHIC_wea,
        MPROJ_L1L2HI_L4PHIC_writeaddr=> MPROJ_L1L2HI_L4PHIC_writeaddr,
        MPROJ_L1L2HI_L4PHIC_din    => MPROJ_L1L2HI_L4PHIC_din,
        MPROJ_L1L2JKL_L4PHIC_wea   => MPROJ_L1L2JKL_L4PHIC_wea,
        MPROJ_L1L2JKL_L4PHIC_writeaddr=> MPROJ_L1L2JKL_L4PHIC_writeaddr,
        MPROJ_L1L2JKL_L4PHIC_din   => MPROJ_L1L2JKL_L4PHIC_din,
        MPROJ_L2L3ABCD_L4PHIC_wea  => MPROJ_L2L3ABCD_L4PHIC_wea,
        MPROJ_L2L3ABCD_L4PHIC_writeaddr=> MPROJ_L2L3ABCD_L4PHIC_writeaddr,
        MPROJ_L2L3ABCD_L4PHIC_din  => MPROJ_L2L3ABCD_L4PHIC_din,
        MPROJ_L5L6ABCD_L4PHIC_wea  => MPROJ_L5L6ABCD_L4PHIC_wea,
        MPROJ_L5L6ABCD_L4PHIC_writeaddr=> MPROJ_L5L6ABCD_L4PHIC_writeaddr,
        MPROJ_L5L6ABCD_L4PHIC_din  => MPROJ_L5L6ABCD_L4PHIC_din,
        MPROJ_L1L2G_L4PHID_wea     => MPROJ_L1L2G_L4PHID_wea,
        MPROJ_L1L2G_L4PHID_writeaddr=> MPROJ_L1L2G_L4PHID_writeaddr,
        MPROJ_L1L2G_L4PHID_din     => MPROJ_L1L2G_L4PHID_din,
        MPROJ_L1L2HI_L4PHID_wea    => MPROJ_L1L2HI_L4PHID_wea,
        MPROJ_L1L2HI_L4PHID_writeaddr=> MPROJ_L1L2HI_L4PHID_writeaddr,
        MPROJ_L1L2HI_L4PHID_din    => MPROJ_L1L2HI_L4PHID_din,
        MPROJ_L1L2JKL_L4PHID_wea   => MPROJ_L1L2JKL_L4PHID_wea,
        MPROJ_L1L2JKL_L4PHID_writeaddr=> MPROJ_L1L2JKL_L4PHID_writeaddr,
        MPROJ_L1L2JKL_L4PHID_din   => MPROJ_L1L2JKL_L4PHID_din,
        MPROJ_L2L3ABCD_L4PHID_wea  => MPROJ_L2L3ABCD_L4PHID_wea,
        MPROJ_L2L3ABCD_L4PHID_writeaddr=> MPROJ_L2L3ABCD_L4PHID_writeaddr,
        MPROJ_L2L3ABCD_L4PHID_din  => MPROJ_L2L3ABCD_L4PHID_din,
        MPROJ_L5L6ABCD_L4PHID_wea  => MPROJ_L5L6ABCD_L4PHID_wea,
        MPROJ_L5L6ABCD_L4PHID_writeaddr=> MPROJ_L5L6ABCD_L4PHID_writeaddr,
        MPROJ_L5L6ABCD_L4PHID_din  => MPROJ_L5L6ABCD_L4PHID_din,
        MPROJ_L1L2ABC_L5PHIA_wea   => MPROJ_L1L2ABC_L5PHIA_wea,
        MPROJ_L1L2ABC_L5PHIA_writeaddr=> MPROJ_L1L2ABC_L5PHIA_writeaddr,
        MPROJ_L1L2ABC_L5PHIA_din   => MPROJ_L1L2ABC_L5PHIA_din,
        MPROJ_L1L2DE_L5PHIA_wea    => MPROJ_L1L2DE_L5PHIA_wea,
        MPROJ_L1L2DE_L5PHIA_writeaddr=> MPROJ_L1L2DE_L5PHIA_writeaddr,
        MPROJ_L1L2DE_L5PHIA_din    => MPROJ_L1L2DE_L5PHIA_din,
        MPROJ_L1L2F_L5PHIA_wea     => MPROJ_L1L2F_L5PHIA_wea,
        MPROJ_L1L2F_L5PHIA_writeaddr=> MPROJ_L1L2F_L5PHIA_writeaddr,
        MPROJ_L1L2F_L5PHIA_din     => MPROJ_L1L2F_L5PHIA_din,
        MPROJ_L2L3ABCD_L5PHIA_wea  => MPROJ_L2L3ABCD_L5PHIA_wea,
        MPROJ_L2L3ABCD_L5PHIA_writeaddr=> MPROJ_L2L3ABCD_L5PHIA_writeaddr,
        MPROJ_L2L3ABCD_L5PHIA_din  => MPROJ_L2L3ABCD_L5PHIA_din,
        MPROJ_L3L4AB_L5PHIA_wea    => MPROJ_L3L4AB_L5PHIA_wea,
        MPROJ_L3L4AB_L5PHIA_writeaddr=> MPROJ_L3L4AB_L5PHIA_writeaddr,
        MPROJ_L3L4AB_L5PHIA_din    => MPROJ_L3L4AB_L5PHIA_din,
        MPROJ_L1L2ABC_L5PHIB_wea   => MPROJ_L1L2ABC_L5PHIB_wea,
        MPROJ_L1L2ABC_L5PHIB_writeaddr=> MPROJ_L1L2ABC_L5PHIB_writeaddr,
        MPROJ_L1L2ABC_L5PHIB_din   => MPROJ_L1L2ABC_L5PHIB_din,
        MPROJ_L1L2DE_L5PHIB_wea    => MPROJ_L1L2DE_L5PHIB_wea,
        MPROJ_L1L2DE_L5PHIB_writeaddr=> MPROJ_L1L2DE_L5PHIB_writeaddr,
        MPROJ_L1L2DE_L5PHIB_din    => MPROJ_L1L2DE_L5PHIB_din,
        MPROJ_L1L2F_L5PHIB_wea     => MPROJ_L1L2F_L5PHIB_wea,
        MPROJ_L1L2F_L5PHIB_writeaddr=> MPROJ_L1L2F_L5PHIB_writeaddr,
        MPROJ_L1L2F_L5PHIB_din     => MPROJ_L1L2F_L5PHIB_din,
        MPROJ_L1L2G_L5PHIB_wea     => MPROJ_L1L2G_L5PHIB_wea,
        MPROJ_L1L2G_L5PHIB_writeaddr=> MPROJ_L1L2G_L5PHIB_writeaddr,
        MPROJ_L1L2G_L5PHIB_din     => MPROJ_L1L2G_L5PHIB_din,
        MPROJ_L1L2HI_L5PHIB_wea    => MPROJ_L1L2HI_L5PHIB_wea,
        MPROJ_L1L2HI_L5PHIB_writeaddr=> MPROJ_L1L2HI_L5PHIB_writeaddr,
        MPROJ_L1L2HI_L5PHIB_din    => MPROJ_L1L2HI_L5PHIB_din,
        MPROJ_L2L3ABCD_L5PHIB_wea  => MPROJ_L2L3ABCD_L5PHIB_wea,
        MPROJ_L2L3ABCD_L5PHIB_writeaddr=> MPROJ_L2L3ABCD_L5PHIB_writeaddr,
        MPROJ_L2L3ABCD_L5PHIB_din  => MPROJ_L2L3ABCD_L5PHIB_din,
        MPROJ_L3L4AB_L5PHIB_wea    => MPROJ_L3L4AB_L5PHIB_wea,
        MPROJ_L3L4AB_L5PHIB_writeaddr=> MPROJ_L3L4AB_L5PHIB_writeaddr,
        MPROJ_L3L4AB_L5PHIB_din    => MPROJ_L3L4AB_L5PHIB_din,
        MPROJ_L3L4CD_L5PHIB_wea    => MPROJ_L3L4CD_L5PHIB_wea,
        MPROJ_L3L4CD_L5PHIB_writeaddr=> MPROJ_L3L4CD_L5PHIB_writeaddr,
        MPROJ_L3L4CD_L5PHIB_din    => MPROJ_L3L4CD_L5PHIB_din,
        MPROJ_L1L2DE_L5PHIC_wea    => MPROJ_L1L2DE_L5PHIC_wea,
        MPROJ_L1L2DE_L5PHIC_writeaddr=> MPROJ_L1L2DE_L5PHIC_writeaddr,
        MPROJ_L1L2DE_L5PHIC_din    => MPROJ_L1L2DE_L5PHIC_din,
        MPROJ_L1L2F_L5PHIC_wea     => MPROJ_L1L2F_L5PHIC_wea,
        MPROJ_L1L2F_L5PHIC_writeaddr=> MPROJ_L1L2F_L5PHIC_writeaddr,
        MPROJ_L1L2F_L5PHIC_din     => MPROJ_L1L2F_L5PHIC_din,
        MPROJ_L1L2G_L5PHIC_wea     => MPROJ_L1L2G_L5PHIC_wea,
        MPROJ_L1L2G_L5PHIC_writeaddr=> MPROJ_L1L2G_L5PHIC_writeaddr,
        MPROJ_L1L2G_L5PHIC_din     => MPROJ_L1L2G_L5PHIC_din,
        MPROJ_L1L2HI_L5PHIC_wea    => MPROJ_L1L2HI_L5PHIC_wea,
        MPROJ_L1L2HI_L5PHIC_writeaddr=> MPROJ_L1L2HI_L5PHIC_writeaddr,
        MPROJ_L1L2HI_L5PHIC_din    => MPROJ_L1L2HI_L5PHIC_din,
        MPROJ_L1L2JKL_L5PHIC_wea   => MPROJ_L1L2JKL_L5PHIC_wea,
        MPROJ_L1L2JKL_L5PHIC_writeaddr=> MPROJ_L1L2JKL_L5PHIC_writeaddr,
        MPROJ_L1L2JKL_L5PHIC_din   => MPROJ_L1L2JKL_L5PHIC_din,
        MPROJ_L2L3ABCD_L5PHIC_wea  => MPROJ_L2L3ABCD_L5PHIC_wea,
        MPROJ_L2L3ABCD_L5PHIC_writeaddr=> MPROJ_L2L3ABCD_L5PHIC_writeaddr,
        MPROJ_L2L3ABCD_L5PHIC_din  => MPROJ_L2L3ABCD_L5PHIC_din,
        MPROJ_L3L4AB_L5PHIC_wea    => MPROJ_L3L4AB_L5PHIC_wea,
        MPROJ_L3L4AB_L5PHIC_writeaddr=> MPROJ_L3L4AB_L5PHIC_writeaddr,
        MPROJ_L3L4AB_L5PHIC_din    => MPROJ_L3L4AB_L5PHIC_din,
        MPROJ_L3L4CD_L5PHIC_wea    => MPROJ_L3L4CD_L5PHIC_wea,
        MPROJ_L3L4CD_L5PHIC_writeaddr=> MPROJ_L3L4CD_L5PHIC_writeaddr,
        MPROJ_L3L4CD_L5PHIC_din    => MPROJ_L3L4CD_L5PHIC_din,
        MPROJ_L1L2G_L5PHID_wea     => MPROJ_L1L2G_L5PHID_wea,
        MPROJ_L1L2G_L5PHID_writeaddr=> MPROJ_L1L2G_L5PHID_writeaddr,
        MPROJ_L1L2G_L5PHID_din     => MPROJ_L1L2G_L5PHID_din,
        MPROJ_L1L2HI_L5PHID_wea    => MPROJ_L1L2HI_L5PHID_wea,
        MPROJ_L1L2HI_L5PHID_writeaddr=> MPROJ_L1L2HI_L5PHID_writeaddr,
        MPROJ_L1L2HI_L5PHID_din    => MPROJ_L1L2HI_L5PHID_din,
        MPROJ_L1L2JKL_L5PHID_wea   => MPROJ_L1L2JKL_L5PHID_wea,
        MPROJ_L1L2JKL_L5PHID_writeaddr=> MPROJ_L1L2JKL_L5PHID_writeaddr,
        MPROJ_L1L2JKL_L5PHID_din   => MPROJ_L1L2JKL_L5PHID_din,
        MPROJ_L2L3ABCD_L5PHID_wea  => MPROJ_L2L3ABCD_L5PHID_wea,
        MPROJ_L2L3ABCD_L5PHID_writeaddr=> MPROJ_L2L3ABCD_L5PHID_writeaddr,
        MPROJ_L2L3ABCD_L5PHID_din  => MPROJ_L2L3ABCD_L5PHID_din,
        MPROJ_L3L4CD_L5PHID_wea    => MPROJ_L3L4CD_L5PHID_wea,
        MPROJ_L3L4CD_L5PHID_writeaddr=> MPROJ_L3L4CD_L5PHID_writeaddr,
        MPROJ_L3L4CD_L5PHID_din    => MPROJ_L3L4CD_L5PHID_din,
        MPROJ_L1L2ABC_L6PHIA_wea   => MPROJ_L1L2ABC_L6PHIA_wea,
        MPROJ_L1L2ABC_L6PHIA_writeaddr=> MPROJ_L1L2ABC_L6PHIA_writeaddr,
        MPROJ_L1L2ABC_L6PHIA_din   => MPROJ_L1L2ABC_L6PHIA_din,
        MPROJ_L1L2DE_L6PHIA_wea    => MPROJ_L1L2DE_L6PHIA_wea,
        MPROJ_L1L2DE_L6PHIA_writeaddr=> MPROJ_L1L2DE_L6PHIA_writeaddr,
        MPROJ_L1L2DE_L6PHIA_din    => MPROJ_L1L2DE_L6PHIA_din,
        MPROJ_L1L2F_L6PHIA_wea     => MPROJ_L1L2F_L6PHIA_wea,
        MPROJ_L1L2F_L6PHIA_writeaddr=> MPROJ_L1L2F_L6PHIA_writeaddr,
        MPROJ_L1L2F_L6PHIA_din     => MPROJ_L1L2F_L6PHIA_din,
        MPROJ_L3L4AB_L6PHIA_wea    => MPROJ_L3L4AB_L6PHIA_wea,
        MPROJ_L3L4AB_L6PHIA_writeaddr=> MPROJ_L3L4AB_L6PHIA_writeaddr,
        MPROJ_L3L4AB_L6PHIA_din    => MPROJ_L3L4AB_L6PHIA_din,
        MPROJ_L1L2ABC_L6PHIB_wea   => MPROJ_L1L2ABC_L6PHIB_wea,
        MPROJ_L1L2ABC_L6PHIB_writeaddr=> MPROJ_L1L2ABC_L6PHIB_writeaddr,
        MPROJ_L1L2ABC_L6PHIB_din   => MPROJ_L1L2ABC_L6PHIB_din,
        MPROJ_L1L2DE_L6PHIB_wea    => MPROJ_L1L2DE_L6PHIB_wea,
        MPROJ_L1L2DE_L6PHIB_writeaddr=> MPROJ_L1L2DE_L6PHIB_writeaddr,
        MPROJ_L1L2DE_L6PHIB_din    => MPROJ_L1L2DE_L6PHIB_din,
        MPROJ_L1L2F_L6PHIB_wea     => MPROJ_L1L2F_L6PHIB_wea,
        MPROJ_L1L2F_L6PHIB_writeaddr=> MPROJ_L1L2F_L6PHIB_writeaddr,
        MPROJ_L1L2F_L6PHIB_din     => MPROJ_L1L2F_L6PHIB_din,
        MPROJ_L1L2G_L6PHIB_wea     => MPROJ_L1L2G_L6PHIB_wea,
        MPROJ_L1L2G_L6PHIB_writeaddr=> MPROJ_L1L2G_L6PHIB_writeaddr,
        MPROJ_L1L2G_L6PHIB_din     => MPROJ_L1L2G_L6PHIB_din,
        MPROJ_L1L2HI_L6PHIB_wea    => MPROJ_L1L2HI_L6PHIB_wea,
        MPROJ_L1L2HI_L6PHIB_writeaddr=> MPROJ_L1L2HI_L6PHIB_writeaddr,
        MPROJ_L1L2HI_L6PHIB_din    => MPROJ_L1L2HI_L6PHIB_din,
        MPROJ_L3L4AB_L6PHIB_wea    => MPROJ_L3L4AB_L6PHIB_wea,
        MPROJ_L3L4AB_L6PHIB_writeaddr=> MPROJ_L3L4AB_L6PHIB_writeaddr,
        MPROJ_L3L4AB_L6PHIB_din    => MPROJ_L3L4AB_L6PHIB_din,
        MPROJ_L3L4CD_L6PHIB_wea    => MPROJ_L3L4CD_L6PHIB_wea,
        MPROJ_L3L4CD_L6PHIB_writeaddr=> MPROJ_L3L4CD_L6PHIB_writeaddr,
        MPROJ_L3L4CD_L6PHIB_din    => MPROJ_L3L4CD_L6PHIB_din,
        MPROJ_L1L2DE_L6PHIC_wea    => MPROJ_L1L2DE_L6PHIC_wea,
        MPROJ_L1L2DE_L6PHIC_writeaddr=> MPROJ_L1L2DE_L6PHIC_writeaddr,
        MPROJ_L1L2DE_L6PHIC_din    => MPROJ_L1L2DE_L6PHIC_din,
        MPROJ_L1L2F_L6PHIC_wea     => MPROJ_L1L2F_L6PHIC_wea,
        MPROJ_L1L2F_L6PHIC_writeaddr=> MPROJ_L1L2F_L6PHIC_writeaddr,
        MPROJ_L1L2F_L6PHIC_din     => MPROJ_L1L2F_L6PHIC_din,
        MPROJ_L1L2G_L6PHIC_wea     => MPROJ_L1L2G_L6PHIC_wea,
        MPROJ_L1L2G_L6PHIC_writeaddr=> MPROJ_L1L2G_L6PHIC_writeaddr,
        MPROJ_L1L2G_L6PHIC_din     => MPROJ_L1L2G_L6PHIC_din,
        MPROJ_L1L2HI_L6PHIC_wea    => MPROJ_L1L2HI_L6PHIC_wea,
        MPROJ_L1L2HI_L6PHIC_writeaddr=> MPROJ_L1L2HI_L6PHIC_writeaddr,
        MPROJ_L1L2HI_L6PHIC_din    => MPROJ_L1L2HI_L6PHIC_din,
        MPROJ_L1L2JKL_L6PHIC_wea   => MPROJ_L1L2JKL_L6PHIC_wea,
        MPROJ_L1L2JKL_L6PHIC_writeaddr=> MPROJ_L1L2JKL_L6PHIC_writeaddr,
        MPROJ_L1L2JKL_L6PHIC_din   => MPROJ_L1L2JKL_L6PHIC_din,
        MPROJ_L3L4AB_L6PHIC_wea    => MPROJ_L3L4AB_L6PHIC_wea,
        MPROJ_L3L4AB_L6PHIC_writeaddr=> MPROJ_L3L4AB_L6PHIC_writeaddr,
        MPROJ_L3L4AB_L6PHIC_din    => MPROJ_L3L4AB_L6PHIC_din,
        MPROJ_L3L4CD_L6PHIC_wea    => MPROJ_L3L4CD_L6PHIC_wea,
        MPROJ_L3L4CD_L6PHIC_writeaddr=> MPROJ_L3L4CD_L6PHIC_writeaddr,
        MPROJ_L3L4CD_L6PHIC_din    => MPROJ_L3L4CD_L6PHIC_din,
        MPROJ_L1L2G_L6PHID_wea     => MPROJ_L1L2G_L6PHID_wea,
        MPROJ_L1L2G_L6PHID_writeaddr=> MPROJ_L1L2G_L6PHID_writeaddr,
        MPROJ_L1L2G_L6PHID_din     => MPROJ_L1L2G_L6PHID_din,
        MPROJ_L1L2HI_L6PHID_wea    => MPROJ_L1L2HI_L6PHID_wea,
        MPROJ_L1L2HI_L6PHID_writeaddr=> MPROJ_L1L2HI_L6PHID_writeaddr,
        MPROJ_L1L2HI_L6PHID_din    => MPROJ_L1L2HI_L6PHID_din,
        MPROJ_L1L2JKL_L6PHID_wea   => MPROJ_L1L2JKL_L6PHID_wea,
        MPROJ_L1L2JKL_L6PHID_writeaddr=> MPROJ_L1L2JKL_L6PHID_writeaddr,
        MPROJ_L1L2JKL_L6PHID_din   => MPROJ_L1L2JKL_L6PHID_din,
        MPROJ_L3L4CD_L6PHID_wea    => MPROJ_L3L4CD_L6PHID_wea,
        MPROJ_L3L4CD_L6PHID_writeaddr=> MPROJ_L3L4CD_L6PHID_writeaddr,
        MPROJ_L3L4CD_L6PHID_din    => MPROJ_L3L4CD_L6PHID_din,
        MPROJ_L1L2ABC_D1PHIA_wea   => MPROJ_L1L2ABC_D1PHIA_wea,
        MPROJ_L1L2ABC_D1PHIA_writeaddr=> MPROJ_L1L2ABC_D1PHIA_writeaddr,
        MPROJ_L1L2ABC_D1PHIA_din   => MPROJ_L1L2ABC_D1PHIA_din,
        MPROJ_L1L2DE_D1PHIA_wea    => MPROJ_L1L2DE_D1PHIA_wea,
        MPROJ_L1L2DE_D1PHIA_writeaddr=> MPROJ_L1L2DE_D1PHIA_writeaddr,
        MPROJ_L1L2DE_D1PHIA_din    => MPROJ_L1L2DE_D1PHIA_din,
        MPROJ_L1L2F_D1PHIA_wea     => MPROJ_L1L2F_D1PHIA_wea,
        MPROJ_L1L2F_D1PHIA_writeaddr=> MPROJ_L1L2F_D1PHIA_writeaddr,
        MPROJ_L1L2F_D1PHIA_din     => MPROJ_L1L2F_D1PHIA_din,
        MPROJ_L2L3ABCD_D1PHIA_wea  => MPROJ_L2L3ABCD_D1PHIA_wea,
        MPROJ_L2L3ABCD_D1PHIA_writeaddr=> MPROJ_L2L3ABCD_D1PHIA_writeaddr,
        MPROJ_L2L3ABCD_D1PHIA_din  => MPROJ_L2L3ABCD_D1PHIA_din,
        MPROJ_L3L4AB_D1PHIA_wea    => MPROJ_L3L4AB_D1PHIA_wea,
        MPROJ_L3L4AB_D1PHIA_writeaddr=> MPROJ_L3L4AB_D1PHIA_writeaddr,
        MPROJ_L3L4AB_D1PHIA_din    => MPROJ_L3L4AB_D1PHIA_din,
        MPROJ_D3D4ABCD_D1PHIA_wea  => MPROJ_D3D4ABCD_D1PHIA_wea,
        MPROJ_D3D4ABCD_D1PHIA_writeaddr=> MPROJ_D3D4ABCD_D1PHIA_writeaddr,
        MPROJ_D3D4ABCD_D1PHIA_din  => MPROJ_D3D4ABCD_D1PHIA_din,
        MPROJ_L1L2ABC_D1PHIB_wea   => MPROJ_L1L2ABC_D1PHIB_wea,
        MPROJ_L1L2ABC_D1PHIB_writeaddr=> MPROJ_L1L2ABC_D1PHIB_writeaddr,
        MPROJ_L1L2ABC_D1PHIB_din   => MPROJ_L1L2ABC_D1PHIB_din,
        MPROJ_L1L2DE_D1PHIB_wea    => MPROJ_L1L2DE_D1PHIB_wea,
        MPROJ_L1L2DE_D1PHIB_writeaddr=> MPROJ_L1L2DE_D1PHIB_writeaddr,
        MPROJ_L1L2DE_D1PHIB_din    => MPROJ_L1L2DE_D1PHIB_din,
        MPROJ_L1L2F_D1PHIB_wea     => MPROJ_L1L2F_D1PHIB_wea,
        MPROJ_L1L2F_D1PHIB_writeaddr=> MPROJ_L1L2F_D1PHIB_writeaddr,
        MPROJ_L1L2F_D1PHIB_din     => MPROJ_L1L2F_D1PHIB_din,
        MPROJ_L1L2G_D1PHIB_wea     => MPROJ_L1L2G_D1PHIB_wea,
        MPROJ_L1L2G_D1PHIB_writeaddr=> MPROJ_L1L2G_D1PHIB_writeaddr,
        MPROJ_L1L2G_D1PHIB_din     => MPROJ_L1L2G_D1PHIB_din,
        MPROJ_L1L2HI_D1PHIB_wea    => MPROJ_L1L2HI_D1PHIB_wea,
        MPROJ_L1L2HI_D1PHIB_writeaddr=> MPROJ_L1L2HI_D1PHIB_writeaddr,
        MPROJ_L1L2HI_D1PHIB_din    => MPROJ_L1L2HI_D1PHIB_din,
        MPROJ_L2L3ABCD_D1PHIB_wea  => MPROJ_L2L3ABCD_D1PHIB_wea,
        MPROJ_L2L3ABCD_D1PHIB_writeaddr=> MPROJ_L2L3ABCD_D1PHIB_writeaddr,
        MPROJ_L2L3ABCD_D1PHIB_din  => MPROJ_L2L3ABCD_D1PHIB_din,
        MPROJ_L3L4AB_D1PHIB_wea    => MPROJ_L3L4AB_D1PHIB_wea,
        MPROJ_L3L4AB_D1PHIB_writeaddr=> MPROJ_L3L4AB_D1PHIB_writeaddr,
        MPROJ_L3L4AB_D1PHIB_din    => MPROJ_L3L4AB_D1PHIB_din,
        MPROJ_L3L4CD_D1PHIB_wea    => MPROJ_L3L4CD_D1PHIB_wea,
        MPROJ_L3L4CD_D1PHIB_writeaddr=> MPROJ_L3L4CD_D1PHIB_writeaddr,
        MPROJ_L3L4CD_D1PHIB_din    => MPROJ_L3L4CD_D1PHIB_din,
        MPROJ_D3D4ABCD_D1PHIB_wea  => MPROJ_D3D4ABCD_D1PHIB_wea,
        MPROJ_D3D4ABCD_D1PHIB_writeaddr=> MPROJ_D3D4ABCD_D1PHIB_writeaddr,
        MPROJ_D3D4ABCD_D1PHIB_din  => MPROJ_D3D4ABCD_D1PHIB_din,
        MPROJ_L1L2DE_D1PHIC_wea    => MPROJ_L1L2DE_D1PHIC_wea,
        MPROJ_L1L2DE_D1PHIC_writeaddr=> MPROJ_L1L2DE_D1PHIC_writeaddr,
        MPROJ_L1L2DE_D1PHIC_din    => MPROJ_L1L2DE_D1PHIC_din,
        MPROJ_L1L2F_D1PHIC_wea     => MPROJ_L1L2F_D1PHIC_wea,
        MPROJ_L1L2F_D1PHIC_writeaddr=> MPROJ_L1L2F_D1PHIC_writeaddr,
        MPROJ_L1L2F_D1PHIC_din     => MPROJ_L1L2F_D1PHIC_din,
        MPROJ_L1L2G_D1PHIC_wea     => MPROJ_L1L2G_D1PHIC_wea,
        MPROJ_L1L2G_D1PHIC_writeaddr=> MPROJ_L1L2G_D1PHIC_writeaddr,
        MPROJ_L1L2G_D1PHIC_din     => MPROJ_L1L2G_D1PHIC_din,
        MPROJ_L1L2HI_D1PHIC_wea    => MPROJ_L1L2HI_D1PHIC_wea,
        MPROJ_L1L2HI_D1PHIC_writeaddr=> MPROJ_L1L2HI_D1PHIC_writeaddr,
        MPROJ_L1L2HI_D1PHIC_din    => MPROJ_L1L2HI_D1PHIC_din,
        MPROJ_L1L2JKL_D1PHIC_wea   => MPROJ_L1L2JKL_D1PHIC_wea,
        MPROJ_L1L2JKL_D1PHIC_writeaddr=> MPROJ_L1L2JKL_D1PHIC_writeaddr,
        MPROJ_L1L2JKL_D1PHIC_din   => MPROJ_L1L2JKL_D1PHIC_din,
        MPROJ_L2L3ABCD_D1PHIC_wea  => MPROJ_L2L3ABCD_D1PHIC_wea,
        MPROJ_L2L3ABCD_D1PHIC_writeaddr=> MPROJ_L2L3ABCD_D1PHIC_writeaddr,
        MPROJ_L2L3ABCD_D1PHIC_din  => MPROJ_L2L3ABCD_D1PHIC_din,
        MPROJ_L3L4AB_D1PHIC_wea    => MPROJ_L3L4AB_D1PHIC_wea,
        MPROJ_L3L4AB_D1PHIC_writeaddr=> MPROJ_L3L4AB_D1PHIC_writeaddr,
        MPROJ_L3L4AB_D1PHIC_din    => MPROJ_L3L4AB_D1PHIC_din,
        MPROJ_L3L4CD_D1PHIC_wea    => MPROJ_L3L4CD_D1PHIC_wea,
        MPROJ_L3L4CD_D1PHIC_writeaddr=> MPROJ_L3L4CD_D1PHIC_writeaddr,
        MPROJ_L3L4CD_D1PHIC_din    => MPROJ_L3L4CD_D1PHIC_din,
        MPROJ_D3D4ABCD_D1PHIC_wea  => MPROJ_D3D4ABCD_D1PHIC_wea,
        MPROJ_D3D4ABCD_D1PHIC_writeaddr=> MPROJ_D3D4ABCD_D1PHIC_writeaddr,
        MPROJ_D3D4ABCD_D1PHIC_din  => MPROJ_D3D4ABCD_D1PHIC_din,
        MPROJ_L1L2G_D1PHID_wea     => MPROJ_L1L2G_D1PHID_wea,
        MPROJ_L1L2G_D1PHID_writeaddr=> MPROJ_L1L2G_D1PHID_writeaddr,
        MPROJ_L1L2G_D1PHID_din     => MPROJ_L1L2G_D1PHID_din,
        MPROJ_L1L2HI_D1PHID_wea    => MPROJ_L1L2HI_D1PHID_wea,
        MPROJ_L1L2HI_D1PHID_writeaddr=> MPROJ_L1L2HI_D1PHID_writeaddr,
        MPROJ_L1L2HI_D1PHID_din    => MPROJ_L1L2HI_D1PHID_din,
        MPROJ_L1L2JKL_D1PHID_wea   => MPROJ_L1L2JKL_D1PHID_wea,
        MPROJ_L1L2JKL_D1PHID_writeaddr=> MPROJ_L1L2JKL_D1PHID_writeaddr,
        MPROJ_L1L2JKL_D1PHID_din   => MPROJ_L1L2JKL_D1PHID_din,
        MPROJ_L2L3ABCD_D1PHID_wea  => MPROJ_L2L3ABCD_D1PHID_wea,
        MPROJ_L2L3ABCD_D1PHID_writeaddr=> MPROJ_L2L3ABCD_D1PHID_writeaddr,
        MPROJ_L2L3ABCD_D1PHID_din  => MPROJ_L2L3ABCD_D1PHID_din,
        MPROJ_L3L4CD_D1PHID_wea    => MPROJ_L3L4CD_D1PHID_wea,
        MPROJ_L3L4CD_D1PHID_writeaddr=> MPROJ_L3L4CD_D1PHID_writeaddr,
        MPROJ_L3L4CD_D1PHID_din    => MPROJ_L3L4CD_D1PHID_din,
        MPROJ_D3D4ABCD_D1PHID_wea  => MPROJ_D3D4ABCD_D1PHID_wea,
        MPROJ_D3D4ABCD_D1PHID_writeaddr=> MPROJ_D3D4ABCD_D1PHID_writeaddr,
        MPROJ_D3D4ABCD_D1PHID_din  => MPROJ_D3D4ABCD_D1PHID_din,
        MPROJ_L1L2ABC_D2PHIA_wea   => MPROJ_L1L2ABC_D2PHIA_wea,
        MPROJ_L1L2ABC_D2PHIA_writeaddr=> MPROJ_L1L2ABC_D2PHIA_writeaddr,
        MPROJ_L1L2ABC_D2PHIA_din   => MPROJ_L1L2ABC_D2PHIA_din,
        MPROJ_L1L2DE_D2PHIA_wea    => MPROJ_L1L2DE_D2PHIA_wea,
        MPROJ_L1L2DE_D2PHIA_writeaddr=> MPROJ_L1L2DE_D2PHIA_writeaddr,
        MPROJ_L1L2DE_D2PHIA_din    => MPROJ_L1L2DE_D2PHIA_din,
        MPROJ_L1L2F_D2PHIA_wea     => MPROJ_L1L2F_D2PHIA_wea,
        MPROJ_L1L2F_D2PHIA_writeaddr=> MPROJ_L1L2F_D2PHIA_writeaddr,
        MPROJ_L1L2F_D2PHIA_din     => MPROJ_L1L2F_D2PHIA_din,
        MPROJ_L2L3ABCD_D2PHIA_wea  => MPROJ_L2L3ABCD_D2PHIA_wea,
        MPROJ_L2L3ABCD_D2PHIA_writeaddr=> MPROJ_L2L3ABCD_D2PHIA_writeaddr,
        MPROJ_L2L3ABCD_D2PHIA_din  => MPROJ_L2L3ABCD_D2PHIA_din,
        MPROJ_L3L4AB_D2PHIA_wea    => MPROJ_L3L4AB_D2PHIA_wea,
        MPROJ_L3L4AB_D2PHIA_writeaddr=> MPROJ_L3L4AB_D2PHIA_writeaddr,
        MPROJ_L3L4AB_D2PHIA_din    => MPROJ_L3L4AB_D2PHIA_din,
        MPROJ_D3D4ABCD_D2PHIA_wea  => MPROJ_D3D4ABCD_D2PHIA_wea,
        MPROJ_D3D4ABCD_D2PHIA_writeaddr=> MPROJ_D3D4ABCD_D2PHIA_writeaddr,
        MPROJ_D3D4ABCD_D2PHIA_din  => MPROJ_D3D4ABCD_D2PHIA_din,
        MPROJ_L1D1ABCD_D2PHIA_wea  => MPROJ_L1D1ABCD_D2PHIA_wea,
        MPROJ_L1D1ABCD_D2PHIA_writeaddr=> MPROJ_L1D1ABCD_D2PHIA_writeaddr,
        MPROJ_L1D1ABCD_D2PHIA_din  => MPROJ_L1D1ABCD_D2PHIA_din,
        MPROJ_L2D1ABCD_D2PHIA_wea  => MPROJ_L2D1ABCD_D2PHIA_wea,
        MPROJ_L2D1ABCD_D2PHIA_writeaddr=> MPROJ_L2D1ABCD_D2PHIA_writeaddr,
        MPROJ_L2D1ABCD_D2PHIA_din  => MPROJ_L2D1ABCD_D2PHIA_din,
        MPROJ_L1L2ABC_D2PHIB_wea   => MPROJ_L1L2ABC_D2PHIB_wea,
        MPROJ_L1L2ABC_D2PHIB_writeaddr=> MPROJ_L1L2ABC_D2PHIB_writeaddr,
        MPROJ_L1L2ABC_D2PHIB_din   => MPROJ_L1L2ABC_D2PHIB_din,
        MPROJ_L1L2DE_D2PHIB_wea    => MPROJ_L1L2DE_D2PHIB_wea,
        MPROJ_L1L2DE_D2PHIB_writeaddr=> MPROJ_L1L2DE_D2PHIB_writeaddr,
        MPROJ_L1L2DE_D2PHIB_din    => MPROJ_L1L2DE_D2PHIB_din,
        MPROJ_L1L2F_D2PHIB_wea     => MPROJ_L1L2F_D2PHIB_wea,
        MPROJ_L1L2F_D2PHIB_writeaddr=> MPROJ_L1L2F_D2PHIB_writeaddr,
        MPROJ_L1L2F_D2PHIB_din     => MPROJ_L1L2F_D2PHIB_din,
        MPROJ_L1L2G_D2PHIB_wea     => MPROJ_L1L2G_D2PHIB_wea,
        MPROJ_L1L2G_D2PHIB_writeaddr=> MPROJ_L1L2G_D2PHIB_writeaddr,
        MPROJ_L1L2G_D2PHIB_din     => MPROJ_L1L2G_D2PHIB_din,
        MPROJ_L1L2HI_D2PHIB_wea    => MPROJ_L1L2HI_D2PHIB_wea,
        MPROJ_L1L2HI_D2PHIB_writeaddr=> MPROJ_L1L2HI_D2PHIB_writeaddr,
        MPROJ_L1L2HI_D2PHIB_din    => MPROJ_L1L2HI_D2PHIB_din,
        MPROJ_L2L3ABCD_D2PHIB_wea  => MPROJ_L2L3ABCD_D2PHIB_wea,
        MPROJ_L2L3ABCD_D2PHIB_writeaddr=> MPROJ_L2L3ABCD_D2PHIB_writeaddr,
        MPROJ_L2L3ABCD_D2PHIB_din  => MPROJ_L2L3ABCD_D2PHIB_din,
        MPROJ_L3L4AB_D2PHIB_wea    => MPROJ_L3L4AB_D2PHIB_wea,
        MPROJ_L3L4AB_D2PHIB_writeaddr=> MPROJ_L3L4AB_D2PHIB_writeaddr,
        MPROJ_L3L4AB_D2PHIB_din    => MPROJ_L3L4AB_D2PHIB_din,
        MPROJ_L3L4CD_D2PHIB_wea    => MPROJ_L3L4CD_D2PHIB_wea,
        MPROJ_L3L4CD_D2PHIB_writeaddr=> MPROJ_L3L4CD_D2PHIB_writeaddr,
        MPROJ_L3L4CD_D2PHIB_din    => MPROJ_L3L4CD_D2PHIB_din,
        MPROJ_D3D4ABCD_D2PHIB_wea  => MPROJ_D3D4ABCD_D2PHIB_wea,
        MPROJ_D3D4ABCD_D2PHIB_writeaddr=> MPROJ_D3D4ABCD_D2PHIB_writeaddr,
        MPROJ_D3D4ABCD_D2PHIB_din  => MPROJ_D3D4ABCD_D2PHIB_din,
        MPROJ_L1D1ABCD_D2PHIB_wea  => MPROJ_L1D1ABCD_D2PHIB_wea,
        MPROJ_L1D1ABCD_D2PHIB_writeaddr=> MPROJ_L1D1ABCD_D2PHIB_writeaddr,
        MPROJ_L1D1ABCD_D2PHIB_din  => MPROJ_L1D1ABCD_D2PHIB_din,
        MPROJ_L1D1EFGH_D2PHIB_wea  => MPROJ_L1D1EFGH_D2PHIB_wea,
        MPROJ_L1D1EFGH_D2PHIB_writeaddr=> MPROJ_L1D1EFGH_D2PHIB_writeaddr,
        MPROJ_L1D1EFGH_D2PHIB_din  => MPROJ_L1D1EFGH_D2PHIB_din,
        MPROJ_L2D1ABCD_D2PHIB_wea  => MPROJ_L2D1ABCD_D2PHIB_wea,
        MPROJ_L2D1ABCD_D2PHIB_writeaddr=> MPROJ_L2D1ABCD_D2PHIB_writeaddr,
        MPROJ_L2D1ABCD_D2PHIB_din  => MPROJ_L2D1ABCD_D2PHIB_din,
        MPROJ_L1L2DE_D2PHIC_wea    => MPROJ_L1L2DE_D2PHIC_wea,
        MPROJ_L1L2DE_D2PHIC_writeaddr=> MPROJ_L1L2DE_D2PHIC_writeaddr,
        MPROJ_L1L2DE_D2PHIC_din    => MPROJ_L1L2DE_D2PHIC_din,
        MPROJ_L1L2F_D2PHIC_wea     => MPROJ_L1L2F_D2PHIC_wea,
        MPROJ_L1L2F_D2PHIC_writeaddr=> MPROJ_L1L2F_D2PHIC_writeaddr,
        MPROJ_L1L2F_D2PHIC_din     => MPROJ_L1L2F_D2PHIC_din,
        MPROJ_L1L2G_D2PHIC_wea     => MPROJ_L1L2G_D2PHIC_wea,
        MPROJ_L1L2G_D2PHIC_writeaddr=> MPROJ_L1L2G_D2PHIC_writeaddr,
        MPROJ_L1L2G_D2PHIC_din     => MPROJ_L1L2G_D2PHIC_din,
        MPROJ_L1L2HI_D2PHIC_wea    => MPROJ_L1L2HI_D2PHIC_wea,
        MPROJ_L1L2HI_D2PHIC_writeaddr=> MPROJ_L1L2HI_D2PHIC_writeaddr,
        MPROJ_L1L2HI_D2PHIC_din    => MPROJ_L1L2HI_D2PHIC_din,
        MPROJ_L1L2JKL_D2PHIC_wea   => MPROJ_L1L2JKL_D2PHIC_wea,
        MPROJ_L1L2JKL_D2PHIC_writeaddr=> MPROJ_L1L2JKL_D2PHIC_writeaddr,
        MPROJ_L1L2JKL_D2PHIC_din   => MPROJ_L1L2JKL_D2PHIC_din,
        MPROJ_L2L3ABCD_D2PHIC_wea  => MPROJ_L2L3ABCD_D2PHIC_wea,
        MPROJ_L2L3ABCD_D2PHIC_writeaddr=> MPROJ_L2L3ABCD_D2PHIC_writeaddr,
        MPROJ_L2L3ABCD_D2PHIC_din  => MPROJ_L2L3ABCD_D2PHIC_din,
        MPROJ_L3L4AB_D2PHIC_wea    => MPROJ_L3L4AB_D2PHIC_wea,
        MPROJ_L3L4AB_D2PHIC_writeaddr=> MPROJ_L3L4AB_D2PHIC_writeaddr,
        MPROJ_L3L4AB_D2PHIC_din    => MPROJ_L3L4AB_D2PHIC_din,
        MPROJ_L3L4CD_D2PHIC_wea    => MPROJ_L3L4CD_D2PHIC_wea,
        MPROJ_L3L4CD_D2PHIC_writeaddr=> MPROJ_L3L4CD_D2PHIC_writeaddr,
        MPROJ_L3L4CD_D2PHIC_din    => MPROJ_L3L4CD_D2PHIC_din,
        MPROJ_D3D4ABCD_D2PHIC_wea  => MPROJ_D3D4ABCD_D2PHIC_wea,
        MPROJ_D3D4ABCD_D2PHIC_writeaddr=> MPROJ_D3D4ABCD_D2PHIC_writeaddr,
        MPROJ_D3D4ABCD_D2PHIC_din  => MPROJ_D3D4ABCD_D2PHIC_din,
        MPROJ_L1D1ABCD_D2PHIC_wea  => MPROJ_L1D1ABCD_D2PHIC_wea,
        MPROJ_L1D1ABCD_D2PHIC_writeaddr=> MPROJ_L1D1ABCD_D2PHIC_writeaddr,
        MPROJ_L1D1ABCD_D2PHIC_din  => MPROJ_L1D1ABCD_D2PHIC_din,
        MPROJ_L1D1EFGH_D2PHIC_wea  => MPROJ_L1D1EFGH_D2PHIC_wea,
        MPROJ_L1D1EFGH_D2PHIC_writeaddr=> MPROJ_L1D1EFGH_D2PHIC_writeaddr,
        MPROJ_L1D1EFGH_D2PHIC_din  => MPROJ_L1D1EFGH_D2PHIC_din,
        MPROJ_L2D1ABCD_D2PHIC_wea  => MPROJ_L2D1ABCD_D2PHIC_wea,
        MPROJ_L2D1ABCD_D2PHIC_writeaddr=> MPROJ_L2D1ABCD_D2PHIC_writeaddr,
        MPROJ_L2D1ABCD_D2PHIC_din  => MPROJ_L2D1ABCD_D2PHIC_din,
        MPROJ_L1L2G_D2PHID_wea     => MPROJ_L1L2G_D2PHID_wea,
        MPROJ_L1L2G_D2PHID_writeaddr=> MPROJ_L1L2G_D2PHID_writeaddr,
        MPROJ_L1L2G_D2PHID_din     => MPROJ_L1L2G_D2PHID_din,
        MPROJ_L1L2HI_D2PHID_wea    => MPROJ_L1L2HI_D2PHID_wea,
        MPROJ_L1L2HI_D2PHID_writeaddr=> MPROJ_L1L2HI_D2PHID_writeaddr,
        MPROJ_L1L2HI_D2PHID_din    => MPROJ_L1L2HI_D2PHID_din,
        MPROJ_L1L2JKL_D2PHID_wea   => MPROJ_L1L2JKL_D2PHID_wea,
        MPROJ_L1L2JKL_D2PHID_writeaddr=> MPROJ_L1L2JKL_D2PHID_writeaddr,
        MPROJ_L1L2JKL_D2PHID_din   => MPROJ_L1L2JKL_D2PHID_din,
        MPROJ_L2L3ABCD_D2PHID_wea  => MPROJ_L2L3ABCD_D2PHID_wea,
        MPROJ_L2L3ABCD_D2PHID_writeaddr=> MPROJ_L2L3ABCD_D2PHID_writeaddr,
        MPROJ_L2L3ABCD_D2PHID_din  => MPROJ_L2L3ABCD_D2PHID_din,
        MPROJ_L3L4CD_D2PHID_wea    => MPROJ_L3L4CD_D2PHID_wea,
        MPROJ_L3L4CD_D2PHID_writeaddr=> MPROJ_L3L4CD_D2PHID_writeaddr,
        MPROJ_L3L4CD_D2PHID_din    => MPROJ_L3L4CD_D2PHID_din,
        MPROJ_D3D4ABCD_D2PHID_wea  => MPROJ_D3D4ABCD_D2PHID_wea,
        MPROJ_D3D4ABCD_D2PHID_writeaddr=> MPROJ_D3D4ABCD_D2PHID_writeaddr,
        MPROJ_D3D4ABCD_D2PHID_din  => MPROJ_D3D4ABCD_D2PHID_din,
        MPROJ_L1D1EFGH_D2PHID_wea  => MPROJ_L1D1EFGH_D2PHID_wea,
        MPROJ_L1D1EFGH_D2PHID_writeaddr=> MPROJ_L1D1EFGH_D2PHID_writeaddr,
        MPROJ_L1D1EFGH_D2PHID_din  => MPROJ_L1D1EFGH_D2PHID_din,
        MPROJ_L2D1ABCD_D2PHID_wea  => MPROJ_L2D1ABCD_D2PHID_wea,
        MPROJ_L2D1ABCD_D2PHID_writeaddr=> MPROJ_L2D1ABCD_D2PHID_writeaddr,
        MPROJ_L2D1ABCD_D2PHID_din  => MPROJ_L2D1ABCD_D2PHID_din,
        MPROJ_L1L2ABC_D3PHIA_wea   => MPROJ_L1L2ABC_D3PHIA_wea,
        MPROJ_L1L2ABC_D3PHIA_writeaddr=> MPROJ_L1L2ABC_D3PHIA_writeaddr,
        MPROJ_L1L2ABC_D3PHIA_din   => MPROJ_L1L2ABC_D3PHIA_din,
        MPROJ_L1L2DE_D3PHIA_wea    => MPROJ_L1L2DE_D3PHIA_wea,
        MPROJ_L1L2DE_D3PHIA_writeaddr=> MPROJ_L1L2DE_D3PHIA_writeaddr,
        MPROJ_L1L2DE_D3PHIA_din    => MPROJ_L1L2DE_D3PHIA_din,
        MPROJ_L1L2F_D3PHIA_wea     => MPROJ_L1L2F_D3PHIA_wea,
        MPROJ_L1L2F_D3PHIA_writeaddr=> MPROJ_L1L2F_D3PHIA_writeaddr,
        MPROJ_L1L2F_D3PHIA_din     => MPROJ_L1L2F_D3PHIA_din,
        MPROJ_L2L3ABCD_D3PHIA_wea  => MPROJ_L2L3ABCD_D3PHIA_wea,
        MPROJ_L2L3ABCD_D3PHIA_writeaddr=> MPROJ_L2L3ABCD_D3PHIA_writeaddr,
        MPROJ_L2L3ABCD_D3PHIA_din  => MPROJ_L2L3ABCD_D3PHIA_din,
        MPROJ_D1D2ABCD_D3PHIA_wea  => MPROJ_D1D2ABCD_D3PHIA_wea,
        MPROJ_D1D2ABCD_D3PHIA_writeaddr=> MPROJ_D1D2ABCD_D3PHIA_writeaddr,
        MPROJ_D1D2ABCD_D3PHIA_din  => MPROJ_D1D2ABCD_D3PHIA_din,
        MPROJ_L1D1ABCD_D3PHIA_wea  => MPROJ_L1D1ABCD_D3PHIA_wea,
        MPROJ_L1D1ABCD_D3PHIA_writeaddr=> MPROJ_L1D1ABCD_D3PHIA_writeaddr,
        MPROJ_L1D1ABCD_D3PHIA_din  => MPROJ_L1D1ABCD_D3PHIA_din,
        MPROJ_L2D1ABCD_D3PHIA_wea  => MPROJ_L2D1ABCD_D3PHIA_wea,
        MPROJ_L2D1ABCD_D3PHIA_writeaddr=> MPROJ_L2D1ABCD_D3PHIA_writeaddr,
        MPROJ_L2D1ABCD_D3PHIA_din  => MPROJ_L2D1ABCD_D3PHIA_din,
        MPROJ_L1L2ABC_D3PHIB_wea   => MPROJ_L1L2ABC_D3PHIB_wea,
        MPROJ_L1L2ABC_D3PHIB_writeaddr=> MPROJ_L1L2ABC_D3PHIB_writeaddr,
        MPROJ_L1L2ABC_D3PHIB_din   => MPROJ_L1L2ABC_D3PHIB_din,
        MPROJ_L1L2DE_D3PHIB_wea    => MPROJ_L1L2DE_D3PHIB_wea,
        MPROJ_L1L2DE_D3PHIB_writeaddr=> MPROJ_L1L2DE_D3PHIB_writeaddr,
        MPROJ_L1L2DE_D3PHIB_din    => MPROJ_L1L2DE_D3PHIB_din,
        MPROJ_L1L2F_D3PHIB_wea     => MPROJ_L1L2F_D3PHIB_wea,
        MPROJ_L1L2F_D3PHIB_writeaddr=> MPROJ_L1L2F_D3PHIB_writeaddr,
        MPROJ_L1L2F_D3PHIB_din     => MPROJ_L1L2F_D3PHIB_din,
        MPROJ_L1L2G_D3PHIB_wea     => MPROJ_L1L2G_D3PHIB_wea,
        MPROJ_L1L2G_D3PHIB_writeaddr=> MPROJ_L1L2G_D3PHIB_writeaddr,
        MPROJ_L1L2G_D3PHIB_din     => MPROJ_L1L2G_D3PHIB_din,
        MPROJ_L1L2HI_D3PHIB_wea    => MPROJ_L1L2HI_D3PHIB_wea,
        MPROJ_L1L2HI_D3PHIB_writeaddr=> MPROJ_L1L2HI_D3PHIB_writeaddr,
        MPROJ_L1L2HI_D3PHIB_din    => MPROJ_L1L2HI_D3PHIB_din,
        MPROJ_L2L3ABCD_D3PHIB_wea  => MPROJ_L2L3ABCD_D3PHIB_wea,
        MPROJ_L2L3ABCD_D3PHIB_writeaddr=> MPROJ_L2L3ABCD_D3PHIB_writeaddr,
        MPROJ_L2L3ABCD_D3PHIB_din  => MPROJ_L2L3ABCD_D3PHIB_din,
        MPROJ_D1D2ABCD_D3PHIB_wea  => MPROJ_D1D2ABCD_D3PHIB_wea,
        MPROJ_D1D2ABCD_D3PHIB_writeaddr=> MPROJ_D1D2ABCD_D3PHIB_writeaddr,
        MPROJ_D1D2ABCD_D3PHIB_din  => MPROJ_D1D2ABCD_D3PHIB_din,
        MPROJ_L1D1ABCD_D3PHIB_wea  => MPROJ_L1D1ABCD_D3PHIB_wea,
        MPROJ_L1D1ABCD_D3PHIB_writeaddr=> MPROJ_L1D1ABCD_D3PHIB_writeaddr,
        MPROJ_L1D1ABCD_D3PHIB_din  => MPROJ_L1D1ABCD_D3PHIB_din,
        MPROJ_L1D1EFGH_D3PHIB_wea  => MPROJ_L1D1EFGH_D3PHIB_wea,
        MPROJ_L1D1EFGH_D3PHIB_writeaddr=> MPROJ_L1D1EFGH_D3PHIB_writeaddr,
        MPROJ_L1D1EFGH_D3PHIB_din  => MPROJ_L1D1EFGH_D3PHIB_din,
        MPROJ_L2D1ABCD_D3PHIB_wea  => MPROJ_L2D1ABCD_D3PHIB_wea,
        MPROJ_L2D1ABCD_D3PHIB_writeaddr=> MPROJ_L2D1ABCD_D3PHIB_writeaddr,
        MPROJ_L2D1ABCD_D3PHIB_din  => MPROJ_L2D1ABCD_D3PHIB_din,
        MPROJ_L1L2DE_D3PHIC_wea    => MPROJ_L1L2DE_D3PHIC_wea,
        MPROJ_L1L2DE_D3PHIC_writeaddr=> MPROJ_L1L2DE_D3PHIC_writeaddr,
        MPROJ_L1L2DE_D3PHIC_din    => MPROJ_L1L2DE_D3PHIC_din,
        MPROJ_L1L2F_D3PHIC_wea     => MPROJ_L1L2F_D3PHIC_wea,
        MPROJ_L1L2F_D3PHIC_writeaddr=> MPROJ_L1L2F_D3PHIC_writeaddr,
        MPROJ_L1L2F_D3PHIC_din     => MPROJ_L1L2F_D3PHIC_din,
        MPROJ_L1L2G_D3PHIC_wea     => MPROJ_L1L2G_D3PHIC_wea,
        MPROJ_L1L2G_D3PHIC_writeaddr=> MPROJ_L1L2G_D3PHIC_writeaddr,
        MPROJ_L1L2G_D3PHIC_din     => MPROJ_L1L2G_D3PHIC_din,
        MPROJ_L1L2HI_D3PHIC_wea    => MPROJ_L1L2HI_D3PHIC_wea,
        MPROJ_L1L2HI_D3PHIC_writeaddr=> MPROJ_L1L2HI_D3PHIC_writeaddr,
        MPROJ_L1L2HI_D3PHIC_din    => MPROJ_L1L2HI_D3PHIC_din,
        MPROJ_L1L2JKL_D3PHIC_wea   => MPROJ_L1L2JKL_D3PHIC_wea,
        MPROJ_L1L2JKL_D3PHIC_writeaddr=> MPROJ_L1L2JKL_D3PHIC_writeaddr,
        MPROJ_L1L2JKL_D3PHIC_din   => MPROJ_L1L2JKL_D3PHIC_din,
        MPROJ_L2L3ABCD_D3PHIC_wea  => MPROJ_L2L3ABCD_D3PHIC_wea,
        MPROJ_L2L3ABCD_D3PHIC_writeaddr=> MPROJ_L2L3ABCD_D3PHIC_writeaddr,
        MPROJ_L2L3ABCD_D3PHIC_din  => MPROJ_L2L3ABCD_D3PHIC_din,
        MPROJ_D1D2ABCD_D3PHIC_wea  => MPROJ_D1D2ABCD_D3PHIC_wea,
        MPROJ_D1D2ABCD_D3PHIC_writeaddr=> MPROJ_D1D2ABCD_D3PHIC_writeaddr,
        MPROJ_D1D2ABCD_D3PHIC_din  => MPROJ_D1D2ABCD_D3PHIC_din,
        MPROJ_L1D1ABCD_D3PHIC_wea  => MPROJ_L1D1ABCD_D3PHIC_wea,
        MPROJ_L1D1ABCD_D3PHIC_writeaddr=> MPROJ_L1D1ABCD_D3PHIC_writeaddr,
        MPROJ_L1D1ABCD_D3PHIC_din  => MPROJ_L1D1ABCD_D3PHIC_din,
        MPROJ_L1D1EFGH_D3PHIC_wea  => MPROJ_L1D1EFGH_D3PHIC_wea,
        MPROJ_L1D1EFGH_D3PHIC_writeaddr=> MPROJ_L1D1EFGH_D3PHIC_writeaddr,
        MPROJ_L1D1EFGH_D3PHIC_din  => MPROJ_L1D1EFGH_D3PHIC_din,
        MPROJ_L2D1ABCD_D3PHIC_wea  => MPROJ_L2D1ABCD_D3PHIC_wea,
        MPROJ_L2D1ABCD_D3PHIC_writeaddr=> MPROJ_L2D1ABCD_D3PHIC_writeaddr,
        MPROJ_L2D1ABCD_D3PHIC_din  => MPROJ_L2D1ABCD_D3PHIC_din,
        MPROJ_L1L2G_D3PHID_wea     => MPROJ_L1L2G_D3PHID_wea,
        MPROJ_L1L2G_D3PHID_writeaddr=> MPROJ_L1L2G_D3PHID_writeaddr,
        MPROJ_L1L2G_D3PHID_din     => MPROJ_L1L2G_D3PHID_din,
        MPROJ_L1L2HI_D3PHID_wea    => MPROJ_L1L2HI_D3PHID_wea,
        MPROJ_L1L2HI_D3PHID_writeaddr=> MPROJ_L1L2HI_D3PHID_writeaddr,
        MPROJ_L1L2HI_D3PHID_din    => MPROJ_L1L2HI_D3PHID_din,
        MPROJ_L1L2JKL_D3PHID_wea   => MPROJ_L1L2JKL_D3PHID_wea,
        MPROJ_L1L2JKL_D3PHID_writeaddr=> MPROJ_L1L2JKL_D3PHID_writeaddr,
        MPROJ_L1L2JKL_D3PHID_din   => MPROJ_L1L2JKL_D3PHID_din,
        MPROJ_L2L3ABCD_D3PHID_wea  => MPROJ_L2L3ABCD_D3PHID_wea,
        MPROJ_L2L3ABCD_D3PHID_writeaddr=> MPROJ_L2L3ABCD_D3PHID_writeaddr,
        MPROJ_L2L3ABCD_D3PHID_din  => MPROJ_L2L3ABCD_D3PHID_din,
        MPROJ_D1D2ABCD_D3PHID_wea  => MPROJ_D1D2ABCD_D3PHID_wea,
        MPROJ_D1D2ABCD_D3PHID_writeaddr=> MPROJ_D1D2ABCD_D3PHID_writeaddr,
        MPROJ_D1D2ABCD_D3PHID_din  => MPROJ_D1D2ABCD_D3PHID_din,
        MPROJ_L1D1EFGH_D3PHID_wea  => MPROJ_L1D1EFGH_D3PHID_wea,
        MPROJ_L1D1EFGH_D3PHID_writeaddr=> MPROJ_L1D1EFGH_D3PHID_writeaddr,
        MPROJ_L1D1EFGH_D3PHID_din  => MPROJ_L1D1EFGH_D3PHID_din,
        MPROJ_L2D1ABCD_D3PHID_wea  => MPROJ_L2D1ABCD_D3PHID_wea,
        MPROJ_L2D1ABCD_D3PHID_writeaddr=> MPROJ_L2D1ABCD_D3PHID_writeaddr,
        MPROJ_L2D1ABCD_D3PHID_din  => MPROJ_L2D1ABCD_D3PHID_din,
        MPROJ_L1L2ABC_D4PHIA_wea   => MPROJ_L1L2ABC_D4PHIA_wea,
        MPROJ_L1L2ABC_D4PHIA_writeaddr=> MPROJ_L1L2ABC_D4PHIA_writeaddr,
        MPROJ_L1L2ABC_D4PHIA_din   => MPROJ_L1L2ABC_D4PHIA_din,
        MPROJ_L1L2DE_D4PHIA_wea    => MPROJ_L1L2DE_D4PHIA_wea,
        MPROJ_L1L2DE_D4PHIA_writeaddr=> MPROJ_L1L2DE_D4PHIA_writeaddr,
        MPROJ_L1L2DE_D4PHIA_din    => MPROJ_L1L2DE_D4PHIA_din,
        MPROJ_L1L2F_D4PHIA_wea     => MPROJ_L1L2F_D4PHIA_wea,
        MPROJ_L1L2F_D4PHIA_writeaddr=> MPROJ_L1L2F_D4PHIA_writeaddr,
        MPROJ_L1L2F_D4PHIA_din     => MPROJ_L1L2F_D4PHIA_din,
        MPROJ_L2L3ABCD_D4PHIA_wea  => MPROJ_L2L3ABCD_D4PHIA_wea,
        MPROJ_L2L3ABCD_D4PHIA_writeaddr=> MPROJ_L2L3ABCD_D4PHIA_writeaddr,
        MPROJ_L2L3ABCD_D4PHIA_din  => MPROJ_L2L3ABCD_D4PHIA_din,
        MPROJ_D1D2ABCD_D4PHIA_wea  => MPROJ_D1D2ABCD_D4PHIA_wea,
        MPROJ_D1D2ABCD_D4PHIA_writeaddr=> MPROJ_D1D2ABCD_D4PHIA_writeaddr,
        MPROJ_D1D2ABCD_D4PHIA_din  => MPROJ_D1D2ABCD_D4PHIA_din,
        MPROJ_L1D1ABCD_D4PHIA_wea  => MPROJ_L1D1ABCD_D4PHIA_wea,
        MPROJ_L1D1ABCD_D4PHIA_writeaddr=> MPROJ_L1D1ABCD_D4PHIA_writeaddr,
        MPROJ_L1D1ABCD_D4PHIA_din  => MPROJ_L1D1ABCD_D4PHIA_din,
        MPROJ_L2D1ABCD_D4PHIA_wea  => MPROJ_L2D1ABCD_D4PHIA_wea,
        MPROJ_L2D1ABCD_D4PHIA_writeaddr=> MPROJ_L2D1ABCD_D4PHIA_writeaddr,
        MPROJ_L2D1ABCD_D4PHIA_din  => MPROJ_L2D1ABCD_D4PHIA_din,
        MPROJ_L1L2ABC_D4PHIB_wea   => MPROJ_L1L2ABC_D4PHIB_wea,
        MPROJ_L1L2ABC_D4PHIB_writeaddr=> MPROJ_L1L2ABC_D4PHIB_writeaddr,
        MPROJ_L1L2ABC_D4PHIB_din   => MPROJ_L1L2ABC_D4PHIB_din,
        MPROJ_L1L2DE_D4PHIB_wea    => MPROJ_L1L2DE_D4PHIB_wea,
        MPROJ_L1L2DE_D4PHIB_writeaddr=> MPROJ_L1L2DE_D4PHIB_writeaddr,
        MPROJ_L1L2DE_D4PHIB_din    => MPROJ_L1L2DE_D4PHIB_din,
        MPROJ_L1L2F_D4PHIB_wea     => MPROJ_L1L2F_D4PHIB_wea,
        MPROJ_L1L2F_D4PHIB_writeaddr=> MPROJ_L1L2F_D4PHIB_writeaddr,
        MPROJ_L1L2F_D4PHIB_din     => MPROJ_L1L2F_D4PHIB_din,
        MPROJ_L1L2G_D4PHIB_wea     => MPROJ_L1L2G_D4PHIB_wea,
        MPROJ_L1L2G_D4PHIB_writeaddr=> MPROJ_L1L2G_D4PHIB_writeaddr,
        MPROJ_L1L2G_D4PHIB_din     => MPROJ_L1L2G_D4PHIB_din,
        MPROJ_L1L2HI_D4PHIB_wea    => MPROJ_L1L2HI_D4PHIB_wea,
        MPROJ_L1L2HI_D4PHIB_writeaddr=> MPROJ_L1L2HI_D4PHIB_writeaddr,
        MPROJ_L1L2HI_D4PHIB_din    => MPROJ_L1L2HI_D4PHIB_din,
        MPROJ_L2L3ABCD_D4PHIB_wea  => MPROJ_L2L3ABCD_D4PHIB_wea,
        MPROJ_L2L3ABCD_D4PHIB_writeaddr=> MPROJ_L2L3ABCD_D4PHIB_writeaddr,
        MPROJ_L2L3ABCD_D4PHIB_din  => MPROJ_L2L3ABCD_D4PHIB_din,
        MPROJ_D1D2ABCD_D4PHIB_wea  => MPROJ_D1D2ABCD_D4PHIB_wea,
        MPROJ_D1D2ABCD_D4PHIB_writeaddr=> MPROJ_D1D2ABCD_D4PHIB_writeaddr,
        MPROJ_D1D2ABCD_D4PHIB_din  => MPROJ_D1D2ABCD_D4PHIB_din,
        MPROJ_L1D1ABCD_D4PHIB_wea  => MPROJ_L1D1ABCD_D4PHIB_wea,
        MPROJ_L1D1ABCD_D4PHIB_writeaddr=> MPROJ_L1D1ABCD_D4PHIB_writeaddr,
        MPROJ_L1D1ABCD_D4PHIB_din  => MPROJ_L1D1ABCD_D4PHIB_din,
        MPROJ_L1D1EFGH_D4PHIB_wea  => MPROJ_L1D1EFGH_D4PHIB_wea,
        MPROJ_L1D1EFGH_D4PHIB_writeaddr=> MPROJ_L1D1EFGH_D4PHIB_writeaddr,
        MPROJ_L1D1EFGH_D4PHIB_din  => MPROJ_L1D1EFGH_D4PHIB_din,
        MPROJ_L2D1ABCD_D4PHIB_wea  => MPROJ_L2D1ABCD_D4PHIB_wea,
        MPROJ_L2D1ABCD_D4PHIB_writeaddr=> MPROJ_L2D1ABCD_D4PHIB_writeaddr,
        MPROJ_L2D1ABCD_D4PHIB_din  => MPROJ_L2D1ABCD_D4PHIB_din,
        MPROJ_L1L2DE_D4PHIC_wea    => MPROJ_L1L2DE_D4PHIC_wea,
        MPROJ_L1L2DE_D4PHIC_writeaddr=> MPROJ_L1L2DE_D4PHIC_writeaddr,
        MPROJ_L1L2DE_D4PHIC_din    => MPROJ_L1L2DE_D4PHIC_din,
        MPROJ_L1L2F_D4PHIC_wea     => MPROJ_L1L2F_D4PHIC_wea,
        MPROJ_L1L2F_D4PHIC_writeaddr=> MPROJ_L1L2F_D4PHIC_writeaddr,
        MPROJ_L1L2F_D4PHIC_din     => MPROJ_L1L2F_D4PHIC_din,
        MPROJ_L1L2G_D4PHIC_wea     => MPROJ_L1L2G_D4PHIC_wea,
        MPROJ_L1L2G_D4PHIC_writeaddr=> MPROJ_L1L2G_D4PHIC_writeaddr,
        MPROJ_L1L2G_D4PHIC_din     => MPROJ_L1L2G_D4PHIC_din,
        MPROJ_L1L2HI_D4PHIC_wea    => MPROJ_L1L2HI_D4PHIC_wea,
        MPROJ_L1L2HI_D4PHIC_writeaddr=> MPROJ_L1L2HI_D4PHIC_writeaddr,
        MPROJ_L1L2HI_D4PHIC_din    => MPROJ_L1L2HI_D4PHIC_din,
        MPROJ_L1L2JKL_D4PHIC_wea   => MPROJ_L1L2JKL_D4PHIC_wea,
        MPROJ_L1L2JKL_D4PHIC_writeaddr=> MPROJ_L1L2JKL_D4PHIC_writeaddr,
        MPROJ_L1L2JKL_D4PHIC_din   => MPROJ_L1L2JKL_D4PHIC_din,
        MPROJ_L2L3ABCD_D4PHIC_wea  => MPROJ_L2L3ABCD_D4PHIC_wea,
        MPROJ_L2L3ABCD_D4PHIC_writeaddr=> MPROJ_L2L3ABCD_D4PHIC_writeaddr,
        MPROJ_L2L3ABCD_D4PHIC_din  => MPROJ_L2L3ABCD_D4PHIC_din,
        MPROJ_D1D2ABCD_D4PHIC_wea  => MPROJ_D1D2ABCD_D4PHIC_wea,
        MPROJ_D1D2ABCD_D4PHIC_writeaddr=> MPROJ_D1D2ABCD_D4PHIC_writeaddr,
        MPROJ_D1D2ABCD_D4PHIC_din  => MPROJ_D1D2ABCD_D4PHIC_din,
        MPROJ_L1D1ABCD_D4PHIC_wea  => MPROJ_L1D1ABCD_D4PHIC_wea,
        MPROJ_L1D1ABCD_D4PHIC_writeaddr=> MPROJ_L1D1ABCD_D4PHIC_writeaddr,
        MPROJ_L1D1ABCD_D4PHIC_din  => MPROJ_L1D1ABCD_D4PHIC_din,
        MPROJ_L1D1EFGH_D4PHIC_wea  => MPROJ_L1D1EFGH_D4PHIC_wea,
        MPROJ_L1D1EFGH_D4PHIC_writeaddr=> MPROJ_L1D1EFGH_D4PHIC_writeaddr,
        MPROJ_L1D1EFGH_D4PHIC_din  => MPROJ_L1D1EFGH_D4PHIC_din,
        MPROJ_L2D1ABCD_D4PHIC_wea  => MPROJ_L2D1ABCD_D4PHIC_wea,
        MPROJ_L2D1ABCD_D4PHIC_writeaddr=> MPROJ_L2D1ABCD_D4PHIC_writeaddr,
        MPROJ_L2D1ABCD_D4PHIC_din  => MPROJ_L2D1ABCD_D4PHIC_din,
        MPROJ_L1L2G_D4PHID_wea     => MPROJ_L1L2G_D4PHID_wea,
        MPROJ_L1L2G_D4PHID_writeaddr=> MPROJ_L1L2G_D4PHID_writeaddr,
        MPROJ_L1L2G_D4PHID_din     => MPROJ_L1L2G_D4PHID_din,
        MPROJ_L1L2HI_D4PHID_wea    => MPROJ_L1L2HI_D4PHID_wea,
        MPROJ_L1L2HI_D4PHID_writeaddr=> MPROJ_L1L2HI_D4PHID_writeaddr,
        MPROJ_L1L2HI_D4PHID_din    => MPROJ_L1L2HI_D4PHID_din,
        MPROJ_L1L2JKL_D4PHID_wea   => MPROJ_L1L2JKL_D4PHID_wea,
        MPROJ_L1L2JKL_D4PHID_writeaddr=> MPROJ_L1L2JKL_D4PHID_writeaddr,
        MPROJ_L1L2JKL_D4PHID_din   => MPROJ_L1L2JKL_D4PHID_din,
        MPROJ_L2L3ABCD_D4PHID_wea  => MPROJ_L2L3ABCD_D4PHID_wea,
        MPROJ_L2L3ABCD_D4PHID_writeaddr=> MPROJ_L2L3ABCD_D4PHID_writeaddr,
        MPROJ_L2L3ABCD_D4PHID_din  => MPROJ_L2L3ABCD_D4PHID_din,
        MPROJ_D1D2ABCD_D4PHID_wea  => MPROJ_D1D2ABCD_D4PHID_wea,
        MPROJ_D1D2ABCD_D4PHID_writeaddr=> MPROJ_D1D2ABCD_D4PHID_writeaddr,
        MPROJ_D1D2ABCD_D4PHID_din  => MPROJ_D1D2ABCD_D4PHID_din,
        MPROJ_L1D1EFGH_D4PHID_wea  => MPROJ_L1D1EFGH_D4PHID_wea,
        MPROJ_L1D1EFGH_D4PHID_writeaddr=> MPROJ_L1D1EFGH_D4PHID_writeaddr,
        MPROJ_L1D1EFGH_D4PHID_din  => MPROJ_L1D1EFGH_D4PHID_din,
        MPROJ_L2D1ABCD_D4PHID_wea  => MPROJ_L2D1ABCD_D4PHID_wea,
        MPROJ_L2D1ABCD_D4PHID_writeaddr=> MPROJ_L2D1ABCD_D4PHID_writeaddr,
        MPROJ_L2D1ABCD_D4PHID_din  => MPROJ_L2D1ABCD_D4PHID_din,
        MPROJ_D1D2ABCD_D5PHIA_wea  => MPROJ_D1D2ABCD_D5PHIA_wea,
        MPROJ_D1D2ABCD_D5PHIA_writeaddr=> MPROJ_D1D2ABCD_D5PHIA_writeaddr,
        MPROJ_D1D2ABCD_D5PHIA_din  => MPROJ_D1D2ABCD_D5PHIA_din,
        MPROJ_D3D4ABCD_D5PHIA_wea  => MPROJ_D3D4ABCD_D5PHIA_wea,
        MPROJ_D3D4ABCD_D5PHIA_writeaddr=> MPROJ_D3D4ABCD_D5PHIA_writeaddr,
        MPROJ_D3D4ABCD_D5PHIA_din  => MPROJ_D3D4ABCD_D5PHIA_din,
        MPROJ_L1D1ABCD_D5PHIA_wea  => MPROJ_L1D1ABCD_D5PHIA_wea,
        MPROJ_L1D1ABCD_D5PHIA_writeaddr=> MPROJ_L1D1ABCD_D5PHIA_writeaddr,
        MPROJ_L1D1ABCD_D5PHIA_din  => MPROJ_L1D1ABCD_D5PHIA_din,
        MPROJ_D1D2ABCD_D5PHIB_wea  => MPROJ_D1D2ABCD_D5PHIB_wea,
        MPROJ_D1D2ABCD_D5PHIB_writeaddr=> MPROJ_D1D2ABCD_D5PHIB_writeaddr,
        MPROJ_D1D2ABCD_D5PHIB_din  => MPROJ_D1D2ABCD_D5PHIB_din,
        MPROJ_D3D4ABCD_D5PHIB_wea  => MPROJ_D3D4ABCD_D5PHIB_wea,
        MPROJ_D3D4ABCD_D5PHIB_writeaddr=> MPROJ_D3D4ABCD_D5PHIB_writeaddr,
        MPROJ_D3D4ABCD_D5PHIB_din  => MPROJ_D3D4ABCD_D5PHIB_din,
        MPROJ_L1D1ABCD_D5PHIB_wea  => MPROJ_L1D1ABCD_D5PHIB_wea,
        MPROJ_L1D1ABCD_D5PHIB_writeaddr=> MPROJ_L1D1ABCD_D5PHIB_writeaddr,
        MPROJ_L1D1ABCD_D5PHIB_din  => MPROJ_L1D1ABCD_D5PHIB_din,
        MPROJ_L1D1EFGH_D5PHIB_wea  => MPROJ_L1D1EFGH_D5PHIB_wea,
        MPROJ_L1D1EFGH_D5PHIB_writeaddr=> MPROJ_L1D1EFGH_D5PHIB_writeaddr,
        MPROJ_L1D1EFGH_D5PHIB_din  => MPROJ_L1D1EFGH_D5PHIB_din,
        MPROJ_D1D2ABCD_D5PHIC_wea  => MPROJ_D1D2ABCD_D5PHIC_wea,
        MPROJ_D1D2ABCD_D5PHIC_writeaddr=> MPROJ_D1D2ABCD_D5PHIC_writeaddr,
        MPROJ_D1D2ABCD_D5PHIC_din  => MPROJ_D1D2ABCD_D5PHIC_din,
        MPROJ_D3D4ABCD_D5PHIC_wea  => MPROJ_D3D4ABCD_D5PHIC_wea,
        MPROJ_D3D4ABCD_D5PHIC_writeaddr=> MPROJ_D3D4ABCD_D5PHIC_writeaddr,
        MPROJ_D3D4ABCD_D5PHIC_din  => MPROJ_D3D4ABCD_D5PHIC_din,
        MPROJ_L1D1ABCD_D5PHIC_wea  => MPROJ_L1D1ABCD_D5PHIC_wea,
        MPROJ_L1D1ABCD_D5PHIC_writeaddr=> MPROJ_L1D1ABCD_D5PHIC_writeaddr,
        MPROJ_L1D1ABCD_D5PHIC_din  => MPROJ_L1D1ABCD_D5PHIC_din,
        MPROJ_L1D1EFGH_D5PHIC_wea  => MPROJ_L1D1EFGH_D5PHIC_wea,
        MPROJ_L1D1EFGH_D5PHIC_writeaddr=> MPROJ_L1D1EFGH_D5PHIC_writeaddr,
        MPROJ_L1D1EFGH_D5PHIC_din  => MPROJ_L1D1EFGH_D5PHIC_din,
        MPROJ_D1D2ABCD_D5PHID_wea  => MPROJ_D1D2ABCD_D5PHID_wea,
        MPROJ_D1D2ABCD_D5PHID_writeaddr=> MPROJ_D1D2ABCD_D5PHID_writeaddr,
        MPROJ_D1D2ABCD_D5PHID_din  => MPROJ_D1D2ABCD_D5PHID_din,
        MPROJ_D3D4ABCD_D5PHID_wea  => MPROJ_D3D4ABCD_D5PHID_wea,
        MPROJ_D3D4ABCD_D5PHID_writeaddr=> MPROJ_D3D4ABCD_D5PHID_writeaddr,
        MPROJ_D3D4ABCD_D5PHID_din  => MPROJ_D3D4ABCD_D5PHID_din,
        MPROJ_L1D1EFGH_D5PHID_wea  => MPROJ_L1D1EFGH_D5PHID_wea,
        MPROJ_L1D1EFGH_D5PHID_writeaddr=> MPROJ_L1D1EFGH_D5PHID_writeaddr,
        MPROJ_L1D1EFGH_D5PHID_din  => MPROJ_L1D1EFGH_D5PHID_din,
        FM_AAAA_L1PHIA_wea         => FM_AAAA_L1PHIA_wea,
        FM_AAAA_L1PHIA_writeaddr   => FM_AAAA_L1PHIA_writeaddr,
        FM_AAAA_L1PHIA_din         => FM_AAAA_L1PHIA_din,
        FM_BBBB_L1PHIA_wea         => FM_BBBB_L1PHIA_wea,
        FM_BBBB_L1PHIA_writeaddr   => FM_BBBB_L1PHIA_writeaddr,
        FM_BBBB_L1PHIA_din         => FM_BBBB_L1PHIA_din,
        FM_AAAA_L1PHIB_wea         => FM_AAAA_L1PHIB_wea,
        FM_AAAA_L1PHIB_writeaddr   => FM_AAAA_L1PHIB_writeaddr,
        FM_AAAA_L1PHIB_din         => FM_AAAA_L1PHIB_din,
        FM_BBBB_L1PHIB_wea         => FM_BBBB_L1PHIB_wea,
        FM_BBBB_L1PHIB_writeaddr   => FM_BBBB_L1PHIB_writeaddr,
        FM_BBBB_L1PHIB_din         => FM_BBBB_L1PHIB_din,
        FM_AAAA_L1PHIC_wea         => FM_AAAA_L1PHIC_wea,
        FM_AAAA_L1PHIC_writeaddr   => FM_AAAA_L1PHIC_writeaddr,
        FM_AAAA_L1PHIC_din         => FM_AAAA_L1PHIC_din,
        FM_BBBB_L1PHIC_wea         => FM_BBBB_L1PHIC_wea,
        FM_BBBB_L1PHIC_writeaddr   => FM_BBBB_L1PHIC_writeaddr,
        FM_BBBB_L1PHIC_din         => FM_BBBB_L1PHIC_din,
        FM_AAAA_L1PHID_wea         => FM_AAAA_L1PHID_wea,
        FM_AAAA_L1PHID_writeaddr   => FM_AAAA_L1PHID_writeaddr,
        FM_AAAA_L1PHID_din         => FM_AAAA_L1PHID_din,
        FM_BBBB_L1PHID_wea         => FM_BBBB_L1PHID_wea,
        FM_BBBB_L1PHID_writeaddr   => FM_BBBB_L1PHID_writeaddr,
        FM_BBBB_L1PHID_din         => FM_BBBB_L1PHID_din,
        FM_AAAA_L1PHIE_wea         => FM_AAAA_L1PHIE_wea,
        FM_AAAA_L1PHIE_writeaddr   => FM_AAAA_L1PHIE_writeaddr,
        FM_AAAA_L1PHIE_din         => FM_AAAA_L1PHIE_din,
        FM_BBBB_L1PHIE_wea         => FM_BBBB_L1PHIE_wea,
        FM_BBBB_L1PHIE_writeaddr   => FM_BBBB_L1PHIE_writeaddr,
        FM_BBBB_L1PHIE_din         => FM_BBBB_L1PHIE_din,
        FM_AAAA_L1PHIF_wea         => FM_AAAA_L1PHIF_wea,
        FM_AAAA_L1PHIF_writeaddr   => FM_AAAA_L1PHIF_writeaddr,
        FM_AAAA_L1PHIF_din         => FM_AAAA_L1PHIF_din,
        FM_BBBB_L1PHIF_wea         => FM_BBBB_L1PHIF_wea,
        FM_BBBB_L1PHIF_writeaddr   => FM_BBBB_L1PHIF_writeaddr,
        FM_BBBB_L1PHIF_din         => FM_BBBB_L1PHIF_din,
        FM_AAAA_L1PHIG_wea         => FM_AAAA_L1PHIG_wea,
        FM_AAAA_L1PHIG_writeaddr   => FM_AAAA_L1PHIG_writeaddr,
        FM_AAAA_L1PHIG_din         => FM_AAAA_L1PHIG_din,
        FM_BBBB_L1PHIG_wea         => FM_BBBB_L1PHIG_wea,
        FM_BBBB_L1PHIG_writeaddr   => FM_BBBB_L1PHIG_writeaddr,
        FM_BBBB_L1PHIG_din         => FM_BBBB_L1PHIG_din,
        FM_AAAA_L1PHIH_wea         => FM_AAAA_L1PHIH_wea,
        FM_AAAA_L1PHIH_writeaddr   => FM_AAAA_L1PHIH_writeaddr,
        FM_AAAA_L1PHIH_din         => FM_AAAA_L1PHIH_din,
        FM_BBBB_L1PHIH_wea         => FM_BBBB_L1PHIH_wea,
        FM_BBBB_L1PHIH_writeaddr   => FM_BBBB_L1PHIH_writeaddr,
        FM_BBBB_L1PHIH_din         => FM_BBBB_L1PHIH_din,
        FM_AAAA_L2PHIA_wea         => FM_AAAA_L2PHIA_wea,
        FM_AAAA_L2PHIA_writeaddr   => FM_AAAA_L2PHIA_writeaddr,
        FM_AAAA_L2PHIA_din         => FM_AAAA_L2PHIA_din,
        FM_BBBB_L2PHIA_wea         => FM_BBBB_L2PHIA_wea,
        FM_BBBB_L2PHIA_writeaddr   => FM_BBBB_L2PHIA_writeaddr,
        FM_BBBB_L2PHIA_din         => FM_BBBB_L2PHIA_din,
        FM_AAAA_L2PHIB_wea         => FM_AAAA_L2PHIB_wea,
        FM_AAAA_L2PHIB_writeaddr   => FM_AAAA_L2PHIB_writeaddr,
        FM_AAAA_L2PHIB_din         => FM_AAAA_L2PHIB_din,
        FM_BBBB_L2PHIB_wea         => FM_BBBB_L2PHIB_wea,
        FM_BBBB_L2PHIB_writeaddr   => FM_BBBB_L2PHIB_writeaddr,
        FM_BBBB_L2PHIB_din         => FM_BBBB_L2PHIB_din,
        FM_AAAA_L2PHIC_wea         => FM_AAAA_L2PHIC_wea,
        FM_AAAA_L2PHIC_writeaddr   => FM_AAAA_L2PHIC_writeaddr,
        FM_AAAA_L2PHIC_din         => FM_AAAA_L2PHIC_din,
        FM_BBBB_L2PHIC_wea         => FM_BBBB_L2PHIC_wea,
        FM_BBBB_L2PHIC_writeaddr   => FM_BBBB_L2PHIC_writeaddr,
        FM_BBBB_L2PHIC_din         => FM_BBBB_L2PHIC_din,
        FM_AAAA_L2PHID_wea         => FM_AAAA_L2PHID_wea,
        FM_AAAA_L2PHID_writeaddr   => FM_AAAA_L2PHID_writeaddr,
        FM_AAAA_L2PHID_din         => FM_AAAA_L2PHID_din,
        FM_BBBB_L2PHID_wea         => FM_BBBB_L2PHID_wea,
        FM_BBBB_L2PHID_writeaddr   => FM_BBBB_L2PHID_writeaddr,
        FM_BBBB_L2PHID_din         => FM_BBBB_L2PHID_din,
        FM_AAAA_L3PHIA_wea         => FM_AAAA_L3PHIA_wea,
        FM_AAAA_L3PHIA_writeaddr   => FM_AAAA_L3PHIA_writeaddr,
        FM_AAAA_L3PHIA_din         => FM_AAAA_L3PHIA_din,
        FM_BBBB_L3PHIA_wea         => FM_BBBB_L3PHIA_wea,
        FM_BBBB_L3PHIA_writeaddr   => FM_BBBB_L3PHIA_writeaddr,
        FM_BBBB_L3PHIA_din         => FM_BBBB_L3PHIA_din,
        FM_AAAA_L3PHIB_wea         => FM_AAAA_L3PHIB_wea,
        FM_AAAA_L3PHIB_writeaddr   => FM_AAAA_L3PHIB_writeaddr,
        FM_AAAA_L3PHIB_din         => FM_AAAA_L3PHIB_din,
        FM_BBBB_L3PHIB_wea         => FM_BBBB_L3PHIB_wea,
        FM_BBBB_L3PHIB_writeaddr   => FM_BBBB_L3PHIB_writeaddr,
        FM_BBBB_L3PHIB_din         => FM_BBBB_L3PHIB_din,
        FM_AAAA_L3PHIC_wea         => FM_AAAA_L3PHIC_wea,
        FM_AAAA_L3PHIC_writeaddr   => FM_AAAA_L3PHIC_writeaddr,
        FM_AAAA_L3PHIC_din         => FM_AAAA_L3PHIC_din,
        FM_BBBB_L3PHIC_wea         => FM_BBBB_L3PHIC_wea,
        FM_BBBB_L3PHIC_writeaddr   => FM_BBBB_L3PHIC_writeaddr,
        FM_BBBB_L3PHIC_din         => FM_BBBB_L3PHIC_din,
        FM_AAAA_L3PHID_wea         => FM_AAAA_L3PHID_wea,
        FM_AAAA_L3PHID_writeaddr   => FM_AAAA_L3PHID_writeaddr,
        FM_AAAA_L3PHID_din         => FM_AAAA_L3PHID_din,
        FM_BBBB_L3PHID_wea         => FM_BBBB_L3PHID_wea,
        FM_BBBB_L3PHID_writeaddr   => FM_BBBB_L3PHID_writeaddr,
        FM_BBBB_L3PHID_din         => FM_BBBB_L3PHID_din,
        FM_AAAA_L4PHIA_wea         => FM_AAAA_L4PHIA_wea,
        FM_AAAA_L4PHIA_writeaddr   => FM_AAAA_L4PHIA_writeaddr,
        FM_AAAA_L4PHIA_din         => FM_AAAA_L4PHIA_din,
        FM_BBBB_L4PHIA_wea         => FM_BBBB_L4PHIA_wea,
        FM_BBBB_L4PHIA_writeaddr   => FM_BBBB_L4PHIA_writeaddr,
        FM_BBBB_L4PHIA_din         => FM_BBBB_L4PHIA_din,
        FM_AAAA_L4PHIB_wea         => FM_AAAA_L4PHIB_wea,
        FM_AAAA_L4PHIB_writeaddr   => FM_AAAA_L4PHIB_writeaddr,
        FM_AAAA_L4PHIB_din         => FM_AAAA_L4PHIB_din,
        FM_BBBB_L4PHIB_wea         => FM_BBBB_L4PHIB_wea,
        FM_BBBB_L4PHIB_writeaddr   => FM_BBBB_L4PHIB_writeaddr,
        FM_BBBB_L4PHIB_din         => FM_BBBB_L4PHIB_din,
        FM_AAAA_L4PHIC_wea         => FM_AAAA_L4PHIC_wea,
        FM_AAAA_L4PHIC_writeaddr   => FM_AAAA_L4PHIC_writeaddr,
        FM_AAAA_L4PHIC_din         => FM_AAAA_L4PHIC_din,
        FM_BBBB_L4PHIC_wea         => FM_BBBB_L4PHIC_wea,
        FM_BBBB_L4PHIC_writeaddr   => FM_BBBB_L4PHIC_writeaddr,
        FM_BBBB_L4PHIC_din         => FM_BBBB_L4PHIC_din,
        FM_AAAA_L4PHID_wea         => FM_AAAA_L4PHID_wea,
        FM_AAAA_L4PHID_writeaddr   => FM_AAAA_L4PHID_writeaddr,
        FM_AAAA_L4PHID_din         => FM_AAAA_L4PHID_din,
        FM_BBBB_L4PHID_wea         => FM_BBBB_L4PHID_wea,
        FM_BBBB_L4PHID_writeaddr   => FM_BBBB_L4PHID_writeaddr,
        FM_BBBB_L4PHID_din         => FM_BBBB_L4PHID_din,
        FM_AAAA_L5PHIA_wea         => FM_AAAA_L5PHIA_wea,
        FM_AAAA_L5PHIA_writeaddr   => FM_AAAA_L5PHIA_writeaddr,
        FM_AAAA_L5PHIA_din         => FM_AAAA_L5PHIA_din,
        FM_BBBB_L5PHIA_wea         => FM_BBBB_L5PHIA_wea,
        FM_BBBB_L5PHIA_writeaddr   => FM_BBBB_L5PHIA_writeaddr,
        FM_BBBB_L5PHIA_din         => FM_BBBB_L5PHIA_din,
        FM_AAAA_L5PHIB_wea         => FM_AAAA_L5PHIB_wea,
        FM_AAAA_L5PHIB_writeaddr   => FM_AAAA_L5PHIB_writeaddr,
        FM_AAAA_L5PHIB_din         => FM_AAAA_L5PHIB_din,
        FM_BBBB_L5PHIB_wea         => FM_BBBB_L5PHIB_wea,
        FM_BBBB_L5PHIB_writeaddr   => FM_BBBB_L5PHIB_writeaddr,
        FM_BBBB_L5PHIB_din         => FM_BBBB_L5PHIB_din,
        FM_AAAA_L5PHIC_wea         => FM_AAAA_L5PHIC_wea,
        FM_AAAA_L5PHIC_writeaddr   => FM_AAAA_L5PHIC_writeaddr,
        FM_AAAA_L5PHIC_din         => FM_AAAA_L5PHIC_din,
        FM_BBBB_L5PHIC_wea         => FM_BBBB_L5PHIC_wea,
        FM_BBBB_L5PHIC_writeaddr   => FM_BBBB_L5PHIC_writeaddr,
        FM_BBBB_L5PHIC_din         => FM_BBBB_L5PHIC_din,
        FM_AAAA_L5PHID_wea         => FM_AAAA_L5PHID_wea,
        FM_AAAA_L5PHID_writeaddr   => FM_AAAA_L5PHID_writeaddr,
        FM_AAAA_L5PHID_din         => FM_AAAA_L5PHID_din,
        FM_BBBB_L5PHID_wea         => FM_BBBB_L5PHID_wea,
        FM_BBBB_L5PHID_writeaddr   => FM_BBBB_L5PHID_writeaddr,
        FM_BBBB_L5PHID_din         => FM_BBBB_L5PHID_din,
        FM_AAAA_L6PHIA_wea         => FM_AAAA_L6PHIA_wea,
        FM_AAAA_L6PHIA_writeaddr   => FM_AAAA_L6PHIA_writeaddr,
        FM_AAAA_L6PHIA_din         => FM_AAAA_L6PHIA_din,
        FM_BBBB_L6PHIA_wea         => FM_BBBB_L6PHIA_wea,
        FM_BBBB_L6PHIA_writeaddr   => FM_BBBB_L6PHIA_writeaddr,
        FM_BBBB_L6PHIA_din         => FM_BBBB_L6PHIA_din,
        FM_AAAA_L6PHIB_wea         => FM_AAAA_L6PHIB_wea,
        FM_AAAA_L6PHIB_writeaddr   => FM_AAAA_L6PHIB_writeaddr,
        FM_AAAA_L6PHIB_din         => FM_AAAA_L6PHIB_din,
        FM_BBBB_L6PHIB_wea         => FM_BBBB_L6PHIB_wea,
        FM_BBBB_L6PHIB_writeaddr   => FM_BBBB_L6PHIB_writeaddr,
        FM_BBBB_L6PHIB_din         => FM_BBBB_L6PHIB_din,
        FM_AAAA_L6PHIC_wea         => FM_AAAA_L6PHIC_wea,
        FM_AAAA_L6PHIC_writeaddr   => FM_AAAA_L6PHIC_writeaddr,
        FM_AAAA_L6PHIC_din         => FM_AAAA_L6PHIC_din,
        FM_BBBB_L6PHIC_wea         => FM_BBBB_L6PHIC_wea,
        FM_BBBB_L6PHIC_writeaddr   => FM_BBBB_L6PHIC_writeaddr,
        FM_BBBB_L6PHIC_din         => FM_BBBB_L6PHIC_din,
        FM_AAAA_L6PHID_wea         => FM_AAAA_L6PHID_wea,
        FM_AAAA_L6PHID_writeaddr   => FM_AAAA_L6PHID_writeaddr,
        FM_AAAA_L6PHID_din         => FM_AAAA_L6PHID_din,
        FM_BBBB_L6PHID_wea         => FM_BBBB_L6PHID_wea,
        FM_BBBB_L6PHID_writeaddr   => FM_BBBB_L6PHID_writeaddr,
        FM_BBBB_L6PHID_din         => FM_BBBB_L6PHID_din,
        FM_AAAA_D1PHIA_wea         => FM_AAAA_D1PHIA_wea,
        FM_AAAA_D1PHIA_writeaddr   => FM_AAAA_D1PHIA_writeaddr,
        FM_AAAA_D1PHIA_din         => FM_AAAA_D1PHIA_din,
        FM_BBBB_D1PHIA_wea         => FM_BBBB_D1PHIA_wea,
        FM_BBBB_D1PHIA_writeaddr   => FM_BBBB_D1PHIA_writeaddr,
        FM_BBBB_D1PHIA_din         => FM_BBBB_D1PHIA_din,
        FM_AAAA_D1PHIB_wea         => FM_AAAA_D1PHIB_wea,
        FM_AAAA_D1PHIB_writeaddr   => FM_AAAA_D1PHIB_writeaddr,
        FM_AAAA_D1PHIB_din         => FM_AAAA_D1PHIB_din,
        FM_BBBB_D1PHIB_wea         => FM_BBBB_D1PHIB_wea,
        FM_BBBB_D1PHIB_writeaddr   => FM_BBBB_D1PHIB_writeaddr,
        FM_BBBB_D1PHIB_din         => FM_BBBB_D1PHIB_din,
        FM_AAAA_D1PHIC_wea         => FM_AAAA_D1PHIC_wea,
        FM_AAAA_D1PHIC_writeaddr   => FM_AAAA_D1PHIC_writeaddr,
        FM_AAAA_D1PHIC_din         => FM_AAAA_D1PHIC_din,
        FM_BBBB_D1PHIC_wea         => FM_BBBB_D1PHIC_wea,
        FM_BBBB_D1PHIC_writeaddr   => FM_BBBB_D1PHIC_writeaddr,
        FM_BBBB_D1PHIC_din         => FM_BBBB_D1PHIC_din,
        FM_AAAA_D1PHID_wea         => FM_AAAA_D1PHID_wea,
        FM_AAAA_D1PHID_writeaddr   => FM_AAAA_D1PHID_writeaddr,
        FM_AAAA_D1PHID_din         => FM_AAAA_D1PHID_din,
        FM_BBBB_D1PHID_wea         => FM_BBBB_D1PHID_wea,
        FM_BBBB_D1PHID_writeaddr   => FM_BBBB_D1PHID_writeaddr,
        FM_BBBB_D1PHID_din         => FM_BBBB_D1PHID_din,
        FM_AAAA_D2PHIA_wea         => FM_AAAA_D2PHIA_wea,
        FM_AAAA_D2PHIA_writeaddr   => FM_AAAA_D2PHIA_writeaddr,
        FM_AAAA_D2PHIA_din         => FM_AAAA_D2PHIA_din,
        FM_BBBB_D2PHIA_wea         => FM_BBBB_D2PHIA_wea,
        FM_BBBB_D2PHIA_writeaddr   => FM_BBBB_D2PHIA_writeaddr,
        FM_BBBB_D2PHIA_din         => FM_BBBB_D2PHIA_din,
        FM_AAAA_D2PHIB_wea         => FM_AAAA_D2PHIB_wea,
        FM_AAAA_D2PHIB_writeaddr   => FM_AAAA_D2PHIB_writeaddr,
        FM_AAAA_D2PHIB_din         => FM_AAAA_D2PHIB_din,
        FM_BBBB_D2PHIB_wea         => FM_BBBB_D2PHIB_wea,
        FM_BBBB_D2PHIB_writeaddr   => FM_BBBB_D2PHIB_writeaddr,
        FM_BBBB_D2PHIB_din         => FM_BBBB_D2PHIB_din,
        FM_AAAA_D2PHIC_wea         => FM_AAAA_D2PHIC_wea,
        FM_AAAA_D2PHIC_writeaddr   => FM_AAAA_D2PHIC_writeaddr,
        FM_AAAA_D2PHIC_din         => FM_AAAA_D2PHIC_din,
        FM_BBBB_D2PHIC_wea         => FM_BBBB_D2PHIC_wea,
        FM_BBBB_D2PHIC_writeaddr   => FM_BBBB_D2PHIC_writeaddr,
        FM_BBBB_D2PHIC_din         => FM_BBBB_D2PHIC_din,
        FM_AAAA_D2PHID_wea         => FM_AAAA_D2PHID_wea,
        FM_AAAA_D2PHID_writeaddr   => FM_AAAA_D2PHID_writeaddr,
        FM_AAAA_D2PHID_din         => FM_AAAA_D2PHID_din,
        FM_BBBB_D2PHID_wea         => FM_BBBB_D2PHID_wea,
        FM_BBBB_D2PHID_writeaddr   => FM_BBBB_D2PHID_writeaddr,
        FM_BBBB_D2PHID_din         => FM_BBBB_D2PHID_din,
        FM_AAAA_D3PHIA_wea         => FM_AAAA_D3PHIA_wea,
        FM_AAAA_D3PHIA_writeaddr   => FM_AAAA_D3PHIA_writeaddr,
        FM_AAAA_D3PHIA_din         => FM_AAAA_D3PHIA_din,
        FM_BBBB_D3PHIA_wea         => FM_BBBB_D3PHIA_wea,
        FM_BBBB_D3PHIA_writeaddr   => FM_BBBB_D3PHIA_writeaddr,
        FM_BBBB_D3PHIA_din         => FM_BBBB_D3PHIA_din,
        FM_AAAA_D3PHIB_wea         => FM_AAAA_D3PHIB_wea,
        FM_AAAA_D3PHIB_writeaddr   => FM_AAAA_D3PHIB_writeaddr,
        FM_AAAA_D3PHIB_din         => FM_AAAA_D3PHIB_din,
        FM_BBBB_D3PHIB_wea         => FM_BBBB_D3PHIB_wea,
        FM_BBBB_D3PHIB_writeaddr   => FM_BBBB_D3PHIB_writeaddr,
        FM_BBBB_D3PHIB_din         => FM_BBBB_D3PHIB_din,
        FM_AAAA_D3PHIC_wea         => FM_AAAA_D3PHIC_wea,
        FM_AAAA_D3PHIC_writeaddr   => FM_AAAA_D3PHIC_writeaddr,
        FM_AAAA_D3PHIC_din         => FM_AAAA_D3PHIC_din,
        FM_BBBB_D3PHIC_wea         => FM_BBBB_D3PHIC_wea,
        FM_BBBB_D3PHIC_writeaddr   => FM_BBBB_D3PHIC_writeaddr,
        FM_BBBB_D3PHIC_din         => FM_BBBB_D3PHIC_din,
        FM_AAAA_D3PHID_wea         => FM_AAAA_D3PHID_wea,
        FM_AAAA_D3PHID_writeaddr   => FM_AAAA_D3PHID_writeaddr,
        FM_AAAA_D3PHID_din         => FM_AAAA_D3PHID_din,
        FM_BBBB_D3PHID_wea         => FM_BBBB_D3PHID_wea,
        FM_BBBB_D3PHID_writeaddr   => FM_BBBB_D3PHID_writeaddr,
        FM_BBBB_D3PHID_din         => FM_BBBB_D3PHID_din,
        FM_AAAA_D4PHIA_wea         => FM_AAAA_D4PHIA_wea,
        FM_AAAA_D4PHIA_writeaddr   => FM_AAAA_D4PHIA_writeaddr,
        FM_AAAA_D4PHIA_din         => FM_AAAA_D4PHIA_din,
        FM_BBBB_D4PHIA_wea         => FM_BBBB_D4PHIA_wea,
        FM_BBBB_D4PHIA_writeaddr   => FM_BBBB_D4PHIA_writeaddr,
        FM_BBBB_D4PHIA_din         => FM_BBBB_D4PHIA_din,
        FM_AAAA_D4PHIB_wea         => FM_AAAA_D4PHIB_wea,
        FM_AAAA_D4PHIB_writeaddr   => FM_AAAA_D4PHIB_writeaddr,
        FM_AAAA_D4PHIB_din         => FM_AAAA_D4PHIB_din,
        FM_BBBB_D4PHIB_wea         => FM_BBBB_D4PHIB_wea,
        FM_BBBB_D4PHIB_writeaddr   => FM_BBBB_D4PHIB_writeaddr,
        FM_BBBB_D4PHIB_din         => FM_BBBB_D4PHIB_din,
        FM_AAAA_D4PHIC_wea         => FM_AAAA_D4PHIC_wea,
        FM_AAAA_D4PHIC_writeaddr   => FM_AAAA_D4PHIC_writeaddr,
        FM_AAAA_D4PHIC_din         => FM_AAAA_D4PHIC_din,
        FM_BBBB_D4PHIC_wea         => FM_BBBB_D4PHIC_wea,
        FM_BBBB_D4PHIC_writeaddr   => FM_BBBB_D4PHIC_writeaddr,
        FM_BBBB_D4PHIC_din         => FM_BBBB_D4PHIC_din,
        FM_AAAA_D4PHID_wea         => FM_AAAA_D4PHID_wea,
        FM_AAAA_D4PHID_writeaddr   => FM_AAAA_D4PHID_writeaddr,
        FM_AAAA_D4PHID_din         => FM_AAAA_D4PHID_din,
        FM_BBBB_D4PHID_wea         => FM_BBBB_D4PHID_wea,
        FM_BBBB_D4PHID_writeaddr   => FM_BBBB_D4PHID_writeaddr,
        FM_BBBB_D4PHID_din         => FM_BBBB_D4PHID_din,
        FM_AAAA_D5PHIA_wea         => FM_AAAA_D5PHIA_wea,
        FM_AAAA_D5PHIA_writeaddr   => FM_AAAA_D5PHIA_writeaddr,
        FM_AAAA_D5PHIA_din         => FM_AAAA_D5PHIA_din,
        FM_BBBB_D5PHIA_wea         => FM_BBBB_D5PHIA_wea,
        FM_BBBB_D5PHIA_writeaddr   => FM_BBBB_D5PHIA_writeaddr,
        FM_BBBB_D5PHIA_din         => FM_BBBB_D5PHIA_din,
        FM_AAAA_D5PHIB_wea         => FM_AAAA_D5PHIB_wea,
        FM_AAAA_D5PHIB_writeaddr   => FM_AAAA_D5PHIB_writeaddr,
        FM_AAAA_D5PHIB_din         => FM_AAAA_D5PHIB_din,
        FM_BBBB_D5PHIB_wea         => FM_BBBB_D5PHIB_wea,
        FM_BBBB_D5PHIB_writeaddr   => FM_BBBB_D5PHIB_writeaddr,
        FM_BBBB_D5PHIB_din         => FM_BBBB_D5PHIB_din,
        FM_AAAA_D5PHIC_wea         => FM_AAAA_D5PHIC_wea,
        FM_AAAA_D5PHIC_writeaddr   => FM_AAAA_D5PHIC_writeaddr,
        FM_AAAA_D5PHIC_din         => FM_AAAA_D5PHIC_din,
        FM_BBBB_D5PHIC_wea         => FM_BBBB_D5PHIC_wea,
        FM_BBBB_D5PHIC_writeaddr   => FM_BBBB_D5PHIC_writeaddr,
        FM_BBBB_D5PHIC_din         => FM_BBBB_D5PHIC_din,
        FM_AAAA_D5PHID_wea         => FM_AAAA_D5PHID_wea,
        FM_AAAA_D5PHID_writeaddr   => FM_AAAA_D5PHID_writeaddr,
        FM_AAAA_D5PHID_din         => FM_AAAA_D5PHID_din,
        FM_BBBB_D5PHID_wea         => FM_BBBB_D5PHID_wea,
        FM_BBBB_D5PHID_writeaddr   => FM_BBBB_D5PHID_writeaddr,
        FM_BBBB_D5PHID_din         => FM_BBBB_D5PHID_din,
        -- Output data
        TW_AAAA_stream_AV_din      => TW_AAAA_stream_AV_din,
        TW_AAAA_stream_A_full_neg  => TW_AAAA_stream_A_full_neg,
        TW_AAAA_stream_A_write     => TW_AAAA_stream_A_write,
        TW_BBBB_stream_AV_din      => TW_BBBB_stream_AV_din,
        TW_BBBB_stream_A_full_neg  => TW_BBBB_stream_A_full_neg,
        TW_BBBB_stream_A_write     => TW_BBBB_stream_A_write,
        DW_AAAA_D1_stream_AV_din   => DW_AAAA_D1_stream_AV_din,
        DW_AAAA_D1_stream_A_full_neg=> DW_AAAA_D1_stream_A_full_neg,
        DW_AAAA_D1_stream_A_write  => DW_AAAA_D1_stream_A_write,
        DW_AAAA_D2_stream_AV_din   => DW_AAAA_D2_stream_AV_din,
        DW_AAAA_D2_stream_A_full_neg=> DW_AAAA_D2_stream_A_full_neg,
        DW_AAAA_D2_stream_A_write  => DW_AAAA_D2_stream_A_write,
        DW_AAAA_D3_stream_AV_din   => DW_AAAA_D3_stream_AV_din,
        DW_AAAA_D3_stream_A_full_neg=> DW_AAAA_D3_stream_A_full_neg,
        DW_AAAA_D3_stream_A_write  => DW_AAAA_D3_stream_A_write,
        DW_AAAA_D4_stream_AV_din   => DW_AAAA_D4_stream_AV_din,
        DW_AAAA_D4_stream_A_full_neg=> DW_AAAA_D4_stream_A_full_neg,
        DW_AAAA_D4_stream_A_write  => DW_AAAA_D4_stream_A_write,
        DW_AAAA_D5_stream_AV_din   => DW_AAAA_D5_stream_AV_din,
        DW_AAAA_D5_stream_A_full_neg=> DW_AAAA_D5_stream_A_full_neg,
        DW_AAAA_D5_stream_A_write  => DW_AAAA_D5_stream_A_write,
        DW_BBBB_D1_stream_AV_din   => DW_BBBB_D1_stream_AV_din,
        DW_BBBB_D1_stream_A_full_neg=> DW_BBBB_D1_stream_A_full_neg,
        DW_BBBB_D1_stream_A_write  => DW_BBBB_D1_stream_A_write,
        DW_BBBB_D2_stream_AV_din   => DW_BBBB_D2_stream_AV_din,
        DW_BBBB_D2_stream_A_full_neg=> DW_BBBB_D2_stream_A_full_neg,
        DW_BBBB_D2_stream_A_write  => DW_BBBB_D2_stream_A_write,
        DW_BBBB_D3_stream_AV_din   => DW_BBBB_D3_stream_AV_din,
        DW_BBBB_D3_stream_A_full_neg=> DW_BBBB_D3_stream_A_full_neg,
        DW_BBBB_D3_stream_A_write  => DW_BBBB_D3_stream_A_write,
        DW_BBBB_D4_stream_AV_din   => DW_BBBB_D4_stream_AV_din,
        DW_BBBB_D4_stream_A_full_neg=> DW_BBBB_D4_stream_A_full_neg,
        DW_BBBB_D4_stream_A_write  => DW_BBBB_D4_stream_A_write,
        DW_BBBB_D5_stream_AV_din   => DW_BBBB_D5_stream_AV_din,
        DW_BBBB_D5_stream_A_full_neg=> DW_BBBB_D5_stream_A_full_neg,
        DW_BBBB_D5_stream_A_write  => DW_BBBB_D5_stream_A_write,
        BW_AAAA_L1_stream_AV_din   => BW_AAAA_L1_stream_AV_din,
        BW_AAAA_L1_stream_A_full_neg=> BW_AAAA_L1_stream_A_full_neg,
        BW_AAAA_L1_stream_A_write  => BW_AAAA_L1_stream_A_write,
        BW_AAAA_L2_stream_AV_din   => BW_AAAA_L2_stream_AV_din,
        BW_AAAA_L2_stream_A_full_neg=> BW_AAAA_L2_stream_A_full_neg,
        BW_AAAA_L2_stream_A_write  => BW_AAAA_L2_stream_A_write,
        BW_AAAA_L3_stream_AV_din   => BW_AAAA_L3_stream_AV_din,
        BW_AAAA_L3_stream_A_full_neg=> BW_AAAA_L3_stream_A_full_neg,
        BW_AAAA_L3_stream_A_write  => BW_AAAA_L3_stream_A_write,
        BW_AAAA_L4_stream_AV_din   => BW_AAAA_L4_stream_AV_din,
        BW_AAAA_L4_stream_A_full_neg=> BW_AAAA_L4_stream_A_full_neg,
        BW_AAAA_L4_stream_A_write  => BW_AAAA_L4_stream_A_write,
        BW_AAAA_L5_stream_AV_din   => BW_AAAA_L5_stream_AV_din,
        BW_AAAA_L5_stream_A_full_neg=> BW_AAAA_L5_stream_A_full_neg,
        BW_AAAA_L5_stream_A_write  => BW_AAAA_L5_stream_A_write,
        BW_AAAA_L6_stream_AV_din   => BW_AAAA_L6_stream_AV_din,
        BW_AAAA_L6_stream_A_full_neg=> BW_AAAA_L6_stream_A_full_neg,
        BW_AAAA_L6_stream_A_write  => BW_AAAA_L6_stream_A_write,
        BW_BBBB_L1_stream_AV_din   => BW_BBBB_L1_stream_AV_din,
        BW_BBBB_L1_stream_A_full_neg=> BW_BBBB_L1_stream_A_full_neg,
        BW_BBBB_L1_stream_A_write  => BW_BBBB_L1_stream_A_write,
        BW_BBBB_L2_stream_AV_din   => BW_BBBB_L2_stream_AV_din,
        BW_BBBB_L2_stream_A_full_neg=> BW_BBBB_L2_stream_A_full_neg,
        BW_BBBB_L2_stream_A_write  => BW_BBBB_L2_stream_A_write,
        BW_BBBB_L3_stream_AV_din   => BW_BBBB_L3_stream_AV_din,
        BW_BBBB_L3_stream_A_full_neg=> BW_BBBB_L3_stream_A_full_neg,
        BW_BBBB_L3_stream_A_write  => BW_BBBB_L3_stream_A_write,
        BW_BBBB_L4_stream_AV_din   => BW_BBBB_L4_stream_AV_din,
        BW_BBBB_L4_stream_A_full_neg=> BW_BBBB_L4_stream_A_full_neg,
        BW_BBBB_L4_stream_A_write  => BW_BBBB_L4_stream_A_write,
        BW_BBBB_L5_stream_AV_din   => BW_BBBB_L5_stream_AV_din,
        BW_BBBB_L5_stream_A_full_neg=> BW_BBBB_L5_stream_A_full_neg,
        BW_BBBB_L5_stream_A_write  => BW_BBBB_L5_stream_A_write,
        BW_BBBB_L6_stream_AV_din   => BW_BBBB_L6_stream_AV_din,
        BW_BBBB_L6_stream_A_full_neg=> BW_BBBB_L6_stream_A_full_neg,
        BW_BBBB_L6_stream_A_write  => BW_BBBB_L6_stream_A_write
      );
  end generate sectorProcFull;

  -- Write signals to output .txt files

  writeIntermediateRAMs : if INST_TOP_TF = 1 generate
  begin

    -- This writes signals going to intermediate memories in chain.

  end generate writeIntermediateRAMs;


  -- Write memories from end of chain.

    writeTW_AAAA : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_TW_113&"TW_AAAA"&outputFileNameEnding,
      FIFO_WIDTH=> 113
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (TW_AAAA_stream_A_write and TW_AAAA_stream_AV_din(112)),
      FULL_NEG  => TW_AAAA_stream_A_full_neg,
      DATA      => TW_AAAA_stream_AV_din
    );
    writeTW_BBBB : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_TW_113&"TW_BBBB"&outputFileNameEnding,
      FIFO_WIDTH=> 113
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (TW_BBBB_stream_A_write and TW_BBBB_stream_AV_din(112)),
      FULL_NEG  => TW_BBBB_stream_A_full_neg,
      DATA      => TW_BBBB_stream_AV_din
    );
-- Code for TrackBuilder to write TF concatenated track+stub data.
-- (Needed to compare with emData/).
writeTF_AAAA_634 : entity work.FileWriterFIFO
generic map (
  FILE_NAME  => FILE_OUT_TF&"AAAA"&outputFileNameEnding,
  FIFO_WIDTH  => 634
)
port map (
  CLK => CLK,
  DONE => TB_DONE,
  WRITE_EN => (TW_AAAA_stream_A_write and TW_AAAA_stream_AV_din(112)),
  FULL_NEG => TW_AAAA_stream_A_full_neg,
  DATA => TW_AAAA_stream_AV_din&BW_AAAA_L1_stream_AV_din&BW_AAAA_L2_stream_AV_din&BW_AAAA_L3_stream_AV_din&BW_AAAA_L4_stream_AV_din&BW_AAAA_L5_stream_AV_din&BW_AAAA_L6_stream_AV_din&DW_AAAA_D1_stream_AV_din&DW_AAAA_D2_stream_AV_din&DW_AAAA_D3_stream_AV_din&DW_AAAA_D4_stream_AV_din&DW_AAAA_D5_stream_AV_din
);
-- Code for TrackBuilder to write TF concatenated track+stub data.
-- (Needed to compare with emData/).
writeTF_BBBB_634 : entity work.FileWriterFIFO
generic map (
  FILE_NAME  => FILE_OUT_TF&"BBBB"&outputFileNameEnding,
  FIFO_WIDTH  => 634
)
port map (
  CLK => CLK,
  DONE => TB_DONE,
  WRITE_EN => (TW_BBBB_stream_A_write and TW_BBBB_stream_AV_din(112)),
  FULL_NEG => TW_BBBB_stream_A_full_neg,
  DATA => TW_BBBB_stream_AV_din&BW_BBBB_L1_stream_AV_din&BW_BBBB_L2_stream_AV_din&BW_BBBB_L3_stream_AV_din&BW_BBBB_L4_stream_AV_din&BW_BBBB_L5_stream_AV_din&BW_BBBB_L6_stream_AV_din&DW_BBBB_D1_stream_AV_din&DW_BBBB_D2_stream_AV_din&DW_BBBB_D3_stream_AV_din&DW_BBBB_D4_stream_AV_din&DW_BBBB_D5_stream_AV_din
);
    writeDW_AAAA_D1 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_AAAA_D1"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_AAAA_D1_stream_A_write and DW_AAAA_D1_stream_AV_din(48)),
      FULL_NEG  => DW_AAAA_D1_stream_A_full_neg,
      DATA      => DW_AAAA_D1_stream_AV_din
    );
    writeDW_AAAA_D2 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_AAAA_D2"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_AAAA_D2_stream_A_write and DW_AAAA_D2_stream_AV_din(48)),
      FULL_NEG  => DW_AAAA_D2_stream_A_full_neg,
      DATA      => DW_AAAA_D2_stream_AV_din
    );
    writeDW_AAAA_D3 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_AAAA_D3"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_AAAA_D3_stream_A_write and DW_AAAA_D3_stream_AV_din(48)),
      FULL_NEG  => DW_AAAA_D3_stream_A_full_neg,
      DATA      => DW_AAAA_D3_stream_AV_din
    );
    writeDW_AAAA_D4 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_AAAA_D4"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_AAAA_D4_stream_A_write and DW_AAAA_D4_stream_AV_din(48)),
      FULL_NEG  => DW_AAAA_D4_stream_A_full_neg,
      DATA      => DW_AAAA_D4_stream_AV_din
    );
    writeDW_AAAA_D5 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_AAAA_D5"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_AAAA_D5_stream_A_write and DW_AAAA_D5_stream_AV_din(48)),
      FULL_NEG  => DW_AAAA_D5_stream_A_full_neg,
      DATA      => DW_AAAA_D5_stream_AV_din
    );
    writeDW_BBBB_D1 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_BBBB_D1"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_BBBB_D1_stream_A_write and DW_BBBB_D1_stream_AV_din(48)),
      FULL_NEG  => DW_BBBB_D1_stream_A_full_neg,
      DATA      => DW_BBBB_D1_stream_AV_din
    );
    writeDW_BBBB_D2 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_BBBB_D2"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_BBBB_D2_stream_A_write and DW_BBBB_D2_stream_AV_din(48)),
      FULL_NEG  => DW_BBBB_D2_stream_A_full_neg,
      DATA      => DW_BBBB_D2_stream_AV_din
    );
    writeDW_BBBB_D3 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_BBBB_D3"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_BBBB_D3_stream_A_write and DW_BBBB_D3_stream_AV_din(48)),
      FULL_NEG  => DW_BBBB_D3_stream_A_full_neg,
      DATA      => DW_BBBB_D3_stream_AV_din
    );
    writeDW_BBBB_D4 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_BBBB_D4"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_BBBB_D4_stream_A_write and DW_BBBB_D4_stream_AV_din(48)),
      FULL_NEG  => DW_BBBB_D4_stream_A_full_neg,
      DATA      => DW_BBBB_D4_stream_AV_din
    );
    writeDW_BBBB_D5 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_DW_49&"DW_BBBB_D5"&outputFileNameEnding,
      FIFO_WIDTH=> 49
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (DW_BBBB_D5_stream_A_write and DW_BBBB_D5_stream_AV_din(48)),
      FULL_NEG  => DW_BBBB_D5_stream_A_full_neg,
      DATA      => DW_BBBB_D5_stream_AV_din
    );
    writeBW_AAAA_L1 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_AAAA_L1"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_AAAA_L1_stream_A_write and BW_AAAA_L1_stream_AV_din(45)),
      FULL_NEG  => BW_AAAA_L1_stream_A_full_neg,
      DATA      => BW_AAAA_L1_stream_AV_din
    );
    writeBW_AAAA_L2 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_AAAA_L2"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_AAAA_L2_stream_A_write and BW_AAAA_L2_stream_AV_din(45)),
      FULL_NEG  => BW_AAAA_L2_stream_A_full_neg,
      DATA      => BW_AAAA_L2_stream_AV_din
    );
    writeBW_AAAA_L3 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_AAAA_L3"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_AAAA_L3_stream_A_write and BW_AAAA_L3_stream_AV_din(45)),
      FULL_NEG  => BW_AAAA_L3_stream_A_full_neg,
      DATA      => BW_AAAA_L3_stream_AV_din
    );
    writeBW_AAAA_L4 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_AAAA_L4"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_AAAA_L4_stream_A_write and BW_AAAA_L4_stream_AV_din(45)),
      FULL_NEG  => BW_AAAA_L4_stream_A_full_neg,
      DATA      => BW_AAAA_L4_stream_AV_din
    );
    writeBW_AAAA_L5 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_AAAA_L5"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_AAAA_L5_stream_A_write and BW_AAAA_L5_stream_AV_din(45)),
      FULL_NEG  => BW_AAAA_L5_stream_A_full_neg,
      DATA      => BW_AAAA_L5_stream_AV_din
    );
    writeBW_AAAA_L6 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_AAAA_L6"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_AAAA_L6_stream_A_write and BW_AAAA_L6_stream_AV_din(45)),
      FULL_NEG  => BW_AAAA_L6_stream_A_full_neg,
      DATA      => BW_AAAA_L6_stream_AV_din
    );
    writeBW_BBBB_L1 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_BBBB_L1"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_BBBB_L1_stream_A_write and BW_BBBB_L1_stream_AV_din(45)),
      FULL_NEG  => BW_BBBB_L1_stream_A_full_neg,
      DATA      => BW_BBBB_L1_stream_AV_din
    );
    writeBW_BBBB_L2 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_BBBB_L2"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_BBBB_L2_stream_A_write and BW_BBBB_L2_stream_AV_din(45)),
      FULL_NEG  => BW_BBBB_L2_stream_A_full_neg,
      DATA      => BW_BBBB_L2_stream_AV_din
    );
    writeBW_BBBB_L3 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_BBBB_L3"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_BBBB_L3_stream_A_write and BW_BBBB_L3_stream_AV_din(45)),
      FULL_NEG  => BW_BBBB_L3_stream_A_full_neg,
      DATA      => BW_BBBB_L3_stream_AV_din
    );
    writeBW_BBBB_L4 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_BBBB_L4"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_BBBB_L4_stream_A_write and BW_BBBB_L4_stream_AV_din(45)),
      FULL_NEG  => BW_BBBB_L4_stream_A_full_neg,
      DATA      => BW_BBBB_L4_stream_AV_din
    );
    writeBW_BBBB_L5 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_BBBB_L5"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_BBBB_L5_stream_A_write and BW_BBBB_L5_stream_AV_din(45)),
      FULL_NEG  => BW_BBBB_L5_stream_A_full_neg,
      DATA      => BW_BBBB_L5_stream_AV_din
    );
    writeBW_BBBB_L6 : entity work.FileWriterFIFO
    generic map (
      FILE_NAME => FILE_OUT_BW_46&"BW_BBBB_L6"&outputFileNameEnding,
      FIFO_WIDTH=> 46
    )
    port map (
      CLK       => CLK240,
      DONE      => TB_DONE,
      WRITE_EN  => (BW_BBBB_L6_stream_A_write and BW_BBBB_L6_stream_AV_din(45)),
      FULL_NEG  => BW_BBBB_L6_stream_A_full_neg,
      DATA      => BW_BBBB_L6_stream_AV_din
    );

end behaviour;
